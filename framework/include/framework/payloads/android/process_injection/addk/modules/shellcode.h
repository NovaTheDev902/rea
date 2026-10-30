/* addk inject shellcode — Ghidra _inject_start_s @ 0xaa9c
 *
 * Executed in remote IME process after ptrace sets PC to mapped region.
 * Global pointers patched by inject_process before poke_text:
 *   _dlopen_addr_s, _dlopen_param1_s, _dlopen_param2_s
 *   _dlsym_addr_s, _dlsym_param2_s, _inject_function_param_s
 *   _saved_r0_pc_s
 *
 * Lab rebuild: assemble ARM32 from this logic; bytes live in reassembled.c @ 0xaa9c.
 */

#ifndef ADDK_SHELLCODE_H
#define ADDK_SHELLCODE_H

/* Remote stub pseudocode (matches Ghidra decompile) */
static inline void inject_stub_pseudocode(void)
{
    /*
     * handle = dlopen(library_path, RTLD_NOW);
     * if (handle) {
     *     fn = dlsym(handle, symbol_name);
     *     fn(inject_param);   // McAfee: "test" passed to init path
     * }
     * return saved_r0_pc;     // restore original register state
     */
}

#define ADDK_SHELLCODE_SIZE 0x400

#endif
