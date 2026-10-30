#include "engine.h"

namespace pegasus {

void Engine::advanceTo(Phase p) {
    // Transition rules mirror the real infection chain:
    //  - kernel cannot be locked before an entry glitch is seen
    //  - hardware pivot needs kernel R/W (skippable on boards without BCM4387)
    //  - modules need either kernel/hardware, or a seeded zombie slice to run quietly
    bool legal = false;
    switch (p) {
        case Phase::EntryDetected:   legal = (phase_ == Phase::Dormant); break;
        case Phase::KernelLocked:    legal = (phase_ == Phase::EntryDetected); break;
        case Phase::HardwarePivoted: legal = (phase_ == Phase::KernelLocked && hardwareAvailable_) ||
                                             (phase_ == Phase::EntryDetected && !hardwareAvailable_); break;
        case Phase::ModulesRunning:  legal = (phase_ == Phase::HardwarePivoted) ||
                                             (phase_ == Phase::KernelLocked); break;
        case Phase::ExfilActive:     legal = isExfilReady(); break;
        case Phase::Terminal:        legal = true; break;
        default:                     legal = false; break;
    }

    if (!legal) {
        bus_.emit({{"engine.transition_rejected", "target=" + std::string(phaseName(p))}});
        return;
    }

    phase_ = p;
    bus_.emit({{"engine.phase", "entered=" + std::string(phaseName(p))}});
}

} // namespace pegasus
