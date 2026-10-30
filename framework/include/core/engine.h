#pragma once
#include "pegasus_config.h"
#include <functional>
#include <string_view>

namespace pegasus {

enum class Phase {
    Dormant,          // waiting for zero-click delivery (iMessage channel)
    EntryDetected,    // AMR decoder saw the illegal bitstream
    KernelLocked,     // full kernel R/W via AppleBCMWLAN drift
    HardwarePivoted,  // BCM4387 SRAM write succeeded; BT controller armed
    ModulesRunning,   // capture/telemetry modules live and observing
    ExfilActive,      // C2 stream pushing collected data out
    Terminal          // implant torn down or zombie slice re-seeded
};

inline std::string_view phaseName(Phase p) {
    switch (p) {
        case Phase::Dormant:         return "dormant";
        case Phase::EntryDetected:   return "entry_detected";
        case Phase::KernelLocked:    return "kernel_locked";
        case Phase::HardwarePivoted: return "hardware_pivoted";
        case Phase::ModulesRunning:  return "modules_running";
        case Phase::ExfilActive:     return "exfil_active";
        default:                     return "terminal";
    }
}

// ============================================================================
// PegasusEngine - the "Brain". Runs the full phase state machine.
// The transition table mirrors the verified infection chain; every accepted /
// rejected transition is emitted to the EventBus for telemetry and logs.
// ============================================================================
class Engine {
public:
    explicit Engine(EventBus& bus) : bus_(bus) {}

    void advanceTo(Phase p);
    [[nodiscard]] Phase current() const { return phase_; }

    // Board / campaign properties that change which transitions are legal.
    void setHardwareAvailable(bool b)     { hardwareAvailable_ = b; }
    void markZombieSeeded(bool b)         { zombieSeeded_ = b; }
    bool isExfilReady() const             { return phase_ == Phase::ModulesRunning || zombieSeeded_; }

private:
    EventBus& bus_;
    Phase phase_ = Phase::Dormant;
    bool hardwareAvailable_ = true;
    bool zombieSeeded_ = false;
};

} // namespace pegasus
