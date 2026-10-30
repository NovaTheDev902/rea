/* pegasus_phase.cpp - Phase state machine reversed from Graphite core engine. */
#include "pegasus_phase.h"
#include <string>

namespace pegasus {

const char* phaseName(Phase p) {
    switch (p) {
        case Phase::Dormant: return "dormant";
        case Phase::EntryDetected: return "entry_detected";
        case Phase::KernelLocked: return "kernel_locked";
        case Phase::HardwarePivoted: return "hardware_pivoted";
        case Phase::ModulesRunning: return "modules_running";
        case Phase::ExfilActive: return "exfil_active";
        default: return "terminal";
    }
}

Engine::Engine(bool hardwareAvailable) : hardwareAvailable_(hardwareAvailable) {}

bool Engine::isExfilReady() const {
    return phase_ == Phase::ModulesRunning || zombieSeeded_;
}

void Engine::advanceTo(Phase p) {
    bool legal = false;
    switch (p) {
        case Phase::EntryDetected: legal = (phase_ == Phase::Dormant); break;
        case Phase::KernelLocked: legal = (phase_ == Phase::EntryDetected); break;
        case Phase::HardwarePivoted:
            legal = (phase_ == Phase::KernelLocked && hardwareAvailable_) ||
                    (phase_ == Phase::EntryDetected && !hardwareAvailable_); break;
        case Phase::ModulesRunning:
            legal = (phase_ == Phase::HardwarePivoted) || (phase_ == Phase::KernelLocked); break;
        case Phase::ExfilActive: legal = isExfilReady(); break;
        case Phase::Terminal: legal = true; break;
        default: legal = false; break;
    }
    if (!legal) return;
    phase_ = p;
}

} // namespace pegasus