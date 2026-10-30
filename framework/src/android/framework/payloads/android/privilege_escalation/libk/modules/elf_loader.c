/*
 * libk in-memory ELF loader / GOT patcher
 * Ghidra: FUN_00015174 (orchestrator), FUN_00014f8c (section load),
 *         FUN_00014eb0 (dynsym/dynstr), FUN_000150a4 (sym lookup)
 *
 * Used when hook target must be resolved via ELF dynamic relocations
 * instead of dlopen/dlsym alone.
 */

#include "strings.h"

#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LIBK_LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LIBK_LOG_TAG, __VA_ARGS__)

typedef struct {
    void   *base;
    size_t  size;
    Elf32_Ehdr *ehdr;
    Elf32_Shdr *shdr;
    const char *shstr;
} elf_map_t;

static int map_elf_file(const char *path, elf_map_t *out)
{
    int fd;
    struct stat st;
    void *map;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return -1;

    if (fstat(fd, &st) != 0) {
        close(fd);
        return -1;
    }

    map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
    if (map == MAP_FAILED)
        return -1;

    out->base = map;
    out->size = st.st_size;
    out->ehdr = (Elf32_Ehdr *)map;
    out->shdr = (Elf32_Shdr *)((char *)map + out->ehdr->e_shoff);
    out->shstr = (const char *)map + out->shdr[out->ehdr->e_shstrndx].sh_offset;
    return 0;
}

static void unmap_elf(elf_map_t *em)
{
    if (em->base)
        munmap(em->base, em->size);
    em->base = NULL;
}

/*
 * Ghidra FUN_00015174: open lib, load dynamic section (index 0xb),
 * find relocation for symbol index param_3, mprotect region param_2,
 * patch GOT/reloc slot with param_4 (hook address).
 */
int elf_patch_reloc(const char *lib_path, void *loaded_base, unsigned sym_index,
                    void *hook_addr, void **original_out)
{
    elf_map_t em;
    unsigned i;
    Elf32_Dyn *dyn;
    Elf32_Rel *rel;
    size_t rel_count;
    Elf32_Sym *dynsym;
    const char *dynstr;
    int rc = -1;

    if (map_elf_file(lib_path, &em) != 0)
        return -1;

    /* Walk section headers for .dynamic — Ghidra uses sh_index 0xb */
    dyn = NULL;
    for (i = 0; i < em.ehdr->e_shnum; i++) {
        if (em.shdr[i].sh_type == SHT_DYNAMIC) {
            dyn = (Elf32_Dyn *)((char *)em.base + em.shdr[i].sh_offset);
            break;
        }
    }

    if (!dyn) {
        unmap_elf(&em);
        return -1;
    }

    dynsym = NULL;
    dynstr = NULL;
    rel = NULL;
    rel_count = 0;

    for (; dyn->d_tag != DT_NULL; dyn++) {
        if (dyn->d_tag == DT_SYMTAB)
            dynsym = (Elf32_Sym *)((char *)loaded_base + dyn->d_un.d_ptr);
        else if (dyn->d_tag == DT_STRTAB)
            dynstr = (const char *)((char *)loaded_base + dyn->d_un.d_ptr);
        else if (dyn->d_tag == DT_REL)
            rel = (Elf32_Rel *)((char *)loaded_base + dyn->d_un.d_ptr);
        else if (dyn->d_tag == DT_RELSZ)
            rel_count = dyn->d_un.d_val / sizeof(Elf32_Rel);
    }

    if (!rel || !dynsym || !dynstr) {
        unmap_elf(&em);
        return -1;
    }

    for (i = 0; i < rel_count; i++) {
        unsigned sym = ELF32_R_SYM(rel[i].r_info);
        if (sym != sym_index)
            continue;

        void **slot = (void **)((char *)loaded_base + rel[i].r_offset);
        if (mprotect((void *)((uintptr_t)slot & ~0xfff), 0x1000, PROT_READ | PROT_WRITE) != 0)
            break;

        if (original_out)
            *original_out = *slot;
        *slot = hook_addr;
        LOGI("patched reloc sym=%u slot=%p -> %p", sym_index, slot, hook_addr);
        rc = 0;
        break;
    }

    unmap_elf(&em);
    return rc;
}
