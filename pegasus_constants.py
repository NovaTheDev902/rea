"""Verified constants extracted from Ghidra-reversed Pegasus/Graphite samples.

Source of truth: Spyware_Research/other/Graphite/core/pegasus_config.h and
graphite_core.h (reversed from C4 binary + CVE advisories). Do not
substitute or invent values; these mirror the reversed binaries.
"""

# Memory / hardware (BCM4387 coexistence SRAM)
SRAM_BASE = 0x102000
IOMMU_BOUNDARY = 0x1173FF
SRAM_SPAN = 0x5400

def sram_in_window(addr: int) -> bool:
    return SRAM_BASE <= addr <= IOMMU_BOUNDARY

# AMR / CoreAudio code constants
MAX_LEGAL_PITCH_LAG = 143
KNOWN_GLITCH_LAG = 248
OVERFLOW_BYTES = 210
VIOLATION_COUNT = 189
EXPLOIT_FRAME_TYPE = 7

# C2 endpoints recovered from raw sockaddr_in (big-endian) in .data
C2_ENDPOINTS = {
    "hid_exfil": "107.195.166.114",
    "telemetry": "136.133.187.184",
    "syslog": "207.135.206.181",
    "ipc_internal": "246.48.148.156",
    "boot_loopback": "244.25.215.0",
}

# Persistence facts (CVE-2026-20700 SSV dyld-slice)
DSC_PATH_PREFIX = "/system_logs.logarchive/dsc/"
SSV_SEAL_LOCATION = "/System/Library/Caches/com.apple.dyld/"
UUID_BYTES = 16

KNOWN_BAD_SHA256 = [
    "d93d48802aa3ccefa74ae09a6a86eafa7554490d884c00b531a9bfe81981fb06",
    "ac746508938646c0cfae3f1d33f15bae718efbc7f0972426c41555e02e6f9770",
    "38a723210c18e81de8f33db79cfe8bae050a98d9d2eacdeb4f35dabbf7bd0cee",
    "869f9771ea1f9b6bf7adbd2663d71dbc041fafcbf68e878542c8639a6ba23066",
]

# CVE ids from reversed samples
CVE_AUDIO_RCE = "CVE-2025-31200"   # CoreAudio AMR heap corruption (iOS <= 18.4)
CVE_KERNEL_ESCAPE = "CVE-2025-31201"  # AppleBCMWLAN AMPDU subframe confusion
CVE_ZOMBIE_BYPASS = "CVE-2026-20700"  # SSV dyld-slice persistence
CVE_UNIVERSAL_RCE = "CVE-2019-3568"   # WhatsApp VOIP heap overflow
CVE_LINKED_DEVICE = "CVE-2025-55177"  # WhatsApp linked-device sync
CVE_IMAGEIO = "CVE-2025-43300"        # ImageIO DNG OOB write

# Phase state machine (mirrors Engine::advanceTo)
PHASES = ["dormant", "entry_detected", "kernel_locked", "hardware_pivoted",
          "modules_running", "exfil_active", "terminal"]

LEGAL_TRANSITIONS = {
    "entry_detected": {"dormant"},
    "kernel_locked": {"entry_detected"},
    "hardware_pivoted": {"kernel_locked", "entry_detected"},  # entry_detected only if no HW
    "modules_running": {"hardware_pivoted", "kernel_locked"},
    "exfil_active": {"modules_running"},  # or zombie seeded
    "terminal": set(PHASES),
}
