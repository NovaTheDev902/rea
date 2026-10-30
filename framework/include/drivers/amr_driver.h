#pragma once
#include "../core/pegasus_config.h"
#include <vector>
#include <deque>
#include <functional>

namespace pegasus {

// ============================================================================
// AMR Driver — Phase 1 Entry Point (CVE-2025-31200)
// Emulates AudioConverterService decoding of an incoming iMessage AMR clip.
// Validated facts:
//   * FT=7 frames are the unstable multi-frame type carrying the payload
//   * pitch lag legal max 143 (TS 26.090 ranges); dumps show glitch value up to 248
//   * LSF coefficients + codebook indices participate in violation count
//   * ~210-byte heap overflow corrupts adjacent AudioConverterService objects,
//     handing the kernel bridge a controlled pointer drift target
//   * decoder keeps frame-history state (frames depend on previous frames)
// ============================================================================
class AMRDriver {
public:
    using OverflowCallback = std::function<void(int glitchLag)>;

    explicit AMRDriver(EventBus& bus, OverflowCallback cb);

    // Feed one raw bitstream frame. `ft` is frame type (0-15), data[0] = pitch lag bits,
    // data[1..10] = LSF quantization codes. Returns false if the frame decoded cleanly.
    bool feed(int ft, const std::vector<int>& data);

    [[nodiscard]] int violatedFrames()  const { return violated_; }
    [[nodiscard]] int totalViolations() const { return violations_; }

private:
    struct HistoryEntry {
        int pitchLag;
        double averageLsf;
    };

    // Validates each decoding parameter against legal ranges (TS 26.090).
    // Returns the count of illegal parameters found in this frame.
    int validateParameters(int pitchLag, const std::vector<int>& lsfCodes);

    EventBus& bus_;
    OverflowCallback cb_;
    std::deque<HistoryEntry> history_;   // AMR frames depend on previous-frame state
    int violated_ = 0;                    // consecutive violating FT=7 frames seen
    int violations_ = 0;                  // cumulative illegal parameter count (dump: 189 / 50 frames)
};

} // namespace pegasus
