#!/bin/bash
# build_all.sh - Build all native components
# Usage: ./build_all.sh [cpp|ios|android|all]

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(dirname "$SCRIPT_DIR")"

build_cpp() {
    echo "[*] Building C++ components..."
    cd "$SCRIPT_DIR/cpp"
    if command -v g++ &> /dev/null; then
        g++ -std=c++17 -Wall -Wextra -O2 -o rtcp_exploit rtcp_exploit.cpp
        ./rtcp_exploit
        echo "[+] C++ build successful"
    elif command -v cl &> /dev/null; then
        cl /std:c++17 /EHsc /O2 /Fe:rtcp_exploit.exe rtcp_exploit.cpp
        rtcp_exploit.exe
        echo "[+] C++ build successful (MSVC)"
    else
        echo "[-] No C++ compiler found"
        return 1
    fi
}

build_java() {
    echo "[*] Building Java components..."
    cd "$SCRIPT_DIR/android"
    javac GraphiteExploit.java
    java GraphiteExploit
    echo "[+] Java build successful"
}

build_ios() {
    echo "[*] Building iOS components..."
    if command -v xcodebuild &> /dev/null; then
        cd "$SCRIPT_DIR/ios"
        xcodebuild -project GraphiteExploit.xcodeproj \
            -scheme GraphiteExploit \
            -sdk iphoneos \
            -configuration Release \
            build
        echo "[+] iOS build successful"
    else
        echo "[-] Xcode not available (macOS required)"
        return 1
    fi
}

build_android() {
    echo "[*] Building Android components..."
    if [ -n "$ANDROID_NDK" ]; then
        cd "$SCRIPT_DIR/android"
        mkdir -p build && cd build
        cmake .. -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
            -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-24
        make
        echo "[+] Android NDK build successful"
    else
        echo "[-] ANDROID_NDK not set"
        return 1
    fi
}

case "${1:-all}" in
    cpp) build_cpp ;;
    java) build_java ;;
    ios) build_ios ;;
    android) build_android ;;
    all)
        build_cpp
        build_java
        echo "[*] Native builds complete (iOS/Android require macOS/NDK)"
        ;;
    *)
        echo "Usage: $0 [cpp|java|ios|android|all]"
        exit 1
        ;;
esac
