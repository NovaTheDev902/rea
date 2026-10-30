# TODO

## Done
- [x] All 12 Python modules present and compiling
- [x] Subfoldered tests/, docs/, payloads/, scripts/, native build artifacts
- [x] Native Rust core built (PTT/WEBP added)
- [x] `native_wrapper.py` exposes craft_ptt/craft_webp
- [x] `poc_payloads.py` uses native payloads
- [x] `final_check.py` / `final_verify.py` pass
- [x] DNG SOF3 marker verified
- [x] Repaired C++ `graphite_core.cpp` undefined `buffer` references
- [x] Android `CMakeLists.txt` no longer references missing `rtcp_exploit.cpp`
- [x] iOS Xcode project has shared scheme + exported header + ImageIO import
- [x] Ported Lara/DarkSword iOS kernel-exploit chain (headers, Swift, ObjC, kexploit) into framework/ios/lara
- [x] Ported Pegasus jadx non-support Java sources for all 3 samples into framework/src/android/samples
- [x] Ported Predator exploit chain (22 files) into framework/src/predator (all Python compiles)
- [x] Ported Coruna native framework (50 files) and Pegasus ghidra listings (0 missing basenames)
- [x] All source_files.csv non-Java basenames now present in report

## Remaining native work
- [x] iOS/macOS delivery path (CVE-2025-55177) in framework/ios (Lara chain ported + integrated)
- [x] Android NDK PTT/WEBP wiring in framework/android
- [x] Repair C header (graphite_core.h namespace) for legacy build (C core now compiles and exports PTT/WEBP)
- [x] Add Rust core to CI (cargo build)  (already in workflow; verified)
- [ ] Implement live fetch against real pywhats session (needs device session)
