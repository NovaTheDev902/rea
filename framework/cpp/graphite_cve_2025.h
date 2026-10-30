// graphite_cve_2025.h - WhatsApp & WhatsApp-adjacent Zero-Day CVEs (2025-2026)
// Extracted from Spyware_Research/other/Graphite/CVEs/

#ifndef GRAPHITE_CVE_2025_H
#define GRAPHITE_CVE_2025_H

#include <stdint.h>
#include <stddef.h>

#ifdef _WIN32
    #define CVE_EXPORT __declspec(dllexport)
#else
    #define CVE_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

// CVE-2025-27363 - FreeType PDF heap overflow
CVE_EXPORT size_t cve_2025_27363_craft_pdf(uint8_t* buffer, size_t buffer_size);

// CVE-2025-43529 - WebKit DFG UAF  
CVE_EXPORT size_t cve_2025_43529_craft_js(uint8_t* buffer, size_t buffer_size);

// CVE-2025-14174 - ANGLE OOB
CVE_EXPORT size_t cve_2025_14174_craft_angle(uint8_t* buffer, size_t buffer_size);

// CVE-2026-0865 - WhatsApp zero-click (2026)
CVE_EXPORT size_t cve_2026_0865_craft_whatsapp(uint8_t* buffer, size_t buffer_size);

// CVE-2026-28897 - iOS buffer overflow (2026)
CVE_EXPORT size_t cve_2026_28897_craft_ios(uint8_t* buffer, size_t buffer_size);

#ifdef __cplusplus
}
#endif

#endif
