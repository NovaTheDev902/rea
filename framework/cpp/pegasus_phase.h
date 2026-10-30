/* pegasus_phase.h - Phase state machine reversed from Graphite core engine.
 * Source: Spyware_Research/other/Graphite/core/engine.{h,cpp}. */
#pragma once
#include <string_view>

namespace pegasus {

enum class Phase { Dormant, EntryDetected, KernelLocked, HardwarePivoted,
                   ModulesRunning, ExfilActive, Terminal };

const char* phaseName(Phase p);

class Engine {
public:
    explicit Engine(bool hardwareAvailable = true);
    void advanceTo(Phase p);
    Phase current() const { return phase_; }
    void setHardwareAvailable(bool b) { hardwareAvailable_ = b; }
    void markZombieSeeded(bool b) { zombieSeeded_ = b; }
    bool isExfilReady() const;
private:
    Phase phase_ = Phase::Dormant;
    bool hardwareAvailable_ = true;
    bool zombieSeeded_ = false;
};

} // namespace pegasus