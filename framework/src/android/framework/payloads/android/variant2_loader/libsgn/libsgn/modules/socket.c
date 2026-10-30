/*
 * libsgn socket module — raw socket send/receive with optional XOR
 * Ghidra: do_socket_send @ 0x0001236a, do_socket_receive @ 0x000123e8,
 *         socket_connect @ 0x000122f0
 */

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

#define LIBSGN_XOR_BYTE         0xad
#define LIBSGN_RECV_POLL_MS     5000
#define LIBSGN_RECV_POLL_RETRIES 3
#define LIBSGN_SEND_ZERO_RETRIES 8

int socket_connect(int *out_fd, const char *host, unsigned port)
{
    struct sockaddr_in addr;
    int fd;
    if (!out_fd || !host) return 0;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd <= 0) return 0;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons((unsigned short)port);
    addr.sin_addr.s_addr = inet_addr(host);
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
        close(fd); return 0;
    }
    *out_fd = fd;
    return 1;
}

int do_socket_send(int fd, const void *buf, size_t len, int xor_body)
{
    unsigned char *wired;
    size_t i, remain;
    int zero_streak;
    ssize_t n;
    if (fd <= 0 || !buf) return 0;
    wired = malloc(len);
    if (!wired) return 0;
    for (i = 0; i < len; i++)
        wired[i] = ((const unsigned char *)buf)[i] ^ (xor_body ? LIBSGN_XOR_BYTE : 0);
    remain = len; zero_streak = 0;
    while ((int)remain > 0) {
        n = send(fd, wired + (len - remain), remain, 0);
        if (n < 0) { free(wired); return 0; }
        if (n == 0) {
            if (++zero_streak > LIBSGN_SEND_ZERO_RETRIES - 1) { free(wired); return 0; }
        } else { zero_streak = 0; }
        remain -= (size_t)n;
    }
    free(wired);
    return 1;
}

int do_socket_receive(int fd, void *buf, size_t len, int xor_body)
{
    size_t remain, i;
    int tries, pr;
    ssize_t n;
    struct pollfd pfd;
    if (fd <= 0 || !buf) return 0;
    memset(buf, 0, len);
    remain = len;
    while ((int)remain > 0) {
        pfd.fd = fd; pfd.events = POLLIN; pfd.revents = 0;
        tries = LIBSGN_RECV_POLL_RETRIES;
        do {
            pr = poll(&pfd, 1, LIBSGN_RECV_POLL_MS);
            if ((pfd.revents & POLLIN) != 0) break;
            if (--tries == 0 || pr < 1) {
                if (xor_body) for (i = 0; i < (len - remain); i++)
                    ((unsigned char *)buf)[i] ^= LIBSGN_XOR_BYTE;
                return 0;
            }
        } while (1);
        n = recv(fd, (unsigned char *)buf + (len - remain), remain, 0);
        if (n <= 0) {
            if (xor_body) for (i = 0; i < (len - remain); i++)
                ((unsigned char *)buf)[i] ^= LIBSGN_XOR_BYTE;
            return 0;
        }
        remain -= (size_t)n;
    }
    if (xor_body) for (i = 0; i < len; i++)
        ((unsigned char *)buf)[i] ^= LIBSGN_XOR_BYTE;
    return 1;
}
