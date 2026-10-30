/*
 * libsgn HTTP + raw sockets
 * Ghidra: do_socket_* @ 0x0000236a / 0x000023e8
 *         http_* @ 0x000025fc … 0x0000285c
 */

#include "http.h"
#include "strings.h"

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <poll.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

static const void *find_bytes(const void *hay, size_t hay_n,
                              const void *needle, size_t needle_n)
{
    const unsigned char *p = hay;
    size_t i;

    if (needle_n == 0 || hay_n < needle_n)
        return NULL;
    for (i = 0; i + needle_n <= hay_n; i++) {
        if (memcmp(p + i, needle, needle_n) == 0)
            return p + i;
    }
    return NULL;
}

int socket_connect(int *out_fd, const char *host, unsigned port)
{
    struct sockaddr_in addr;
    int fd;

    if (!out_fd || !host)
        return 0;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    *out_fd = fd;
    if (fd <= 0)
        return 0;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons((unsigned short)port);
    addr.sin_addr.s_addr = inet_addr(host);
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) != 0)
        return 0;
    return 1;
}

int socket_disconnect(int *fd)
{
    if (fd && *fd > 0)
        close(*fd);
    if (fd)
        *fd = 0;
    return 1;
}

int do_socket_send(int fd, const void *buf, size_t len, int xor_body)
{
    unsigned char *wired;
    unsigned char key;
    size_t i;
    size_t remain;
    int zero_streak;
    ssize_t n;

    if (fd <= 0 || !buf)
        return 0;
    wired = malloc(len);
    if (!wired)
        return 0;

    key = xor_body ? (unsigned char)LIBSGN_XOR_BYTE : 0;
    for (i = 0; i < len; i++)
        wired[i] = ((const unsigned char *)buf)[i] ^ key;

    remain = len;
    zero_streak = 0;
    while ((int)remain > 0) {
        n = send(fd, wired + (len - remain), remain, 0);
        if (n < 0) {
            free(wired);
            return 0;
        }
        if (n == 0) {
            zero_streak++;
            if (zero_streak > LIBSGN_SEND_ZERO_RETRIES - 1) {
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

int do_socket_receive(int fd, void *buf, size_t len, int xor_body)
{
    size_t remain;
    int tries;
    ssize_t n;
    size_t i;
    struct pollfd pfd;

    if (fd <= 0 || !buf)
        return 0;

    memset(buf, 0, len);
    remain = len;
    while ((int)remain > 0) {
        pfd.fd = fd;
        pfd.events = POLLIN;
        pfd.revents = 0;
        tries = LIBSGN_RECV_POLL_RETRIES;
        for (;;) {
            int pr;

            errno = 0;
            pr = poll(&pfd, 1, LIBSGN_RECV_POLL_MS);
            if ((pfd.revents & POLLIN) != 0)
                break;
            tries--;
            if (tries == 0)
                return 0;
            if (pr < 1)
                return 0;
        }
        errno = 0;
        n = recv(pfd.fd, (unsigned char *)buf + (len - remain), remain, 0);
        if (n < 1)
            return 0;
        remain -= (size_t)n;
    }

    if (xor_body) {
        for (i = 0; i < len; i++)
            ((unsigned char *)buf)[i] ^= (unsigned char)LIBSGN_XOR_BYTE;
    }
    return 1;
}

int http_get_string_attribute(const void *hdr, size_t hdr_len,
                              const char *name, char *out, int out_max)
{
    const unsigned char *hit;
    const unsigned char *eol;
    size_t name_len;
    size_t value_len;

    if (!hdr || !name || !out || out_max <= 0)
        return 0;

    name_len = strlen(name);
    hit = find_bytes(hdr, hdr_len, name, name_len);
    if (!hit)
        return 0;

    eol = find_bytes(hit, (size_t)((const unsigned char *)hdr + hdr_len - hit),
                     LIBSGN_HDR_CRLF, 2);
    if (!eol)
        return 0;

    value_len = (size_t)(eol - (hit + name_len));
    if ((int)value_len >= out_max)
        return 0;

    memcpy(out, hit + name_len, value_len);
    out[value_len] = '\0';
    return 1;
}

int http_get_int_attribute(const void *hdr, size_t hdr_len,
                           const char *name, long *out)
{
    char tmp[50];

    if (!out)
        return 0;
    memset(tmp, 0, sizeof(tmp));
    if (!http_get_string_attribute(hdr, hdr_len, name, tmp, 50))
        return 0;
    errno = 0;
    *out = strtol(tmp, NULL, 10);
    return errno == 0;
}

int http_receive_header(int fd, void **out_hdr, int *out_len)
{
    unsigned char *hdr;
    unsigned char *grown;
    char byte[1];
    int cap_blocks;
    int used;
    unsigned match;
    const char *end = LIBSGN_HDR_END;

    if (!out_hdr || !out_len)
        return 0;
    *out_hdr = NULL;
    *out_len = 0;

    hdr = malloc(LIBSGN_HTTP_LINE);
    if (!hdr)
        return 0;

    cap_blocks = 1;
    used = 0;
    match = 0;
    for (;;) {
        if (!do_socket_receive(fd, byte, 1, 0)) {
            free(hdr);
            return 0;
        }
        if (used + 1 > cap_blocks * LIBSGN_HTTP_LINE) {
            cap_blocks++;
            grown = realloc(hdr, (size_t)cap_blocks * LIBSGN_HTTP_LINE);
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
        if (match >= 4)
            break;
    }
    *out_hdr = hdr;
    *out_len = used;
    return 1;
}

int http_receive_payload(int fd, void **out_body, size_t *out_len)
{
    void *hdr = NULL;
    int hdr_len = 0;
    long content_len = 0;
    void *body = NULL;
    int ok = 0;

    if (!out_body || !out_len)
        return 0;
    *out_body = NULL;
    *out_len = 0;

    if (http_receive_header(fd, &hdr, &hdr_len) == 1 &&
        http_get_int_attribute(hdr, (size_t)hdr_len, LIBSGN_CONTENT_LENGTH,
                               &content_len) == 1 &&
        content_len >= 0) {
        body = malloc((size_t)content_len);
        if (body)
            ok = do_socket_receive(fd, body, (size_t)content_len, 0);
    }

    if (hdr)
        free(hdr);

    if (!ok) {
        free(body);
        return 0;
    }
    *out_body = body;
    *out_len = (size_t)content_len;
    return 1;
}

int http_send_request_with_get(const char *gi_hex, const char *bf_hex,
                               const char *host, int fd)
{
    char line[LIBSGN_HTTP_LINE];

    memset(line, 0, sizeof(line));
    snprintf(line, sizeof(line), LIBSGN_GET_ADINFO, gi_hex, bf_hex, host);
    return do_socket_send(fd, line, strlen(line), 0);
}

int http_send_response_with_post(const char *gi_hex, const char *bf_hex,
                                 const char *host, const void *body,
                                 size_t body_len, int fd)
{
    char line[LIBSGN_HTTP_LINE];
    size_t hdr_len;
    unsigned char *wired;
    size_t i;
    int ok;

    memset(line, 0, sizeof(line));
    hdr_len = (size_t)snprintf(line, sizeof(line), LIBSGN_POST_ADINFO,
                               gi_hex, bf_hex, (unsigned)body_len, host);
    wired = malloc(hdr_len + body_len);
    if (!wired)
        return 0;

    memcpy(wired, line, hdr_len);
    if (body_len > 0 && body)
        memcpy(wired + hdr_len, body, body_len);
    for (i = 0; i < body_len; i++)
        wired[hdr_len + i] ^= (unsigned char)LIBSGN_XOR_BYTE;

    ok = do_socket_send(fd, wired, hdr_len + body_len, 0);
    free(wired);
    return ok;
}
