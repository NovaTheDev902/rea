#ifndef LIBSGN_HTTP_H
#define LIBSGN_HTTP_H

#include <stddef.h>

/* socket_connect @ 0x000022f0 / socket_disconnect @ 0x00002354 */
int socket_connect(int *out_fd, const char *host, unsigned port);
int socket_disconnect(int *fd);

/* do_socket_send @ 0x0000236a — xor_body != 0 applies XOR 0xad */
int do_socket_send(int fd, const void *buf, size_t len, int xor_body);

/* do_socket_receive @ 0x000023e8 — xor_body != 0 applies XOR 0xad */
int do_socket_receive(int fd, void *buf, size_t len, int xor_body);

/* http_get_string_attribute @ 0x000025fc */
int http_get_string_attribute(const void *hdr, size_t hdr_len,
                              const char *name, char *out, int out_max);

/* http_get_int_attribute @ 0x0000265c */
int http_get_int_attribute(const void *hdr, size_t hdr_len,
                           const char *name, long *out);

/* http_receive_header @ 0x000026c8 — caller frees *out_hdr */
int http_receive_header(int fd, void **out_hdr, int *out_len);

/* http_receive_payload @ 0x00002768 — caller frees *out_body */
int http_receive_payload(int fd, void **out_body, size_t *out_len);

/* http_send_request_with_get @ 0x000027f4 */
int http_send_request_with_get(const char *gi_hex, const char *bf_hex,
                               const char *host, int fd);

/* http_send_response_with_post @ 0x0000285c — body XOR 0xad */
int http_send_response_with_post(const char *gi_hex, const char *bf_hex,
                                 const char *host, const void *body,
                                 size_t body_len, int fd);

#endif
