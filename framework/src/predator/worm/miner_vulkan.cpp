/**
 * JinWoo Android NDK Vulkan miner stub
 * Build with CMake + Vulkan loader on device.
 */
#include <stdint.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "JW-AND-NDK", __VA_ARGS__)

static volatile int g_running = 0;
static float g_throttle = 0.4f;

#ifdef __cplusplus
extern "C" {
#endif

void nativeStartMiner(float throttle) {
    g_throttle = throttle;
    g_running = 1;
    LOGI("nativeStartMiner throttle=%.2f (Vulkan compute placeholder)", throttle);
    /* Real impl: create VkInstance/Device, sha256 compute pipeline, submit forever while g_running */
}

void nativeStopMiner(void) {
    g_running = 0;
    LOGI("nativeStopMiner");
}

double nativeHashrate(void) {
    return 30.0 * (double)g_throttle;
}

#ifdef __cplusplus
}
#endif
