package com.lenovo.safecenter.floatwindow.view;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.provider.Settings;
import android.view.WindowManager;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class FloatwindowCache extends Activity {
    public static FloatwindowCache instance;

    /* JADX WARN: Type inference failed for: r5v10, types: [com.lenovo.safecenter.floatwindow.view.FloatwindowCache$1] */
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        setContentView(C0415R.layout.assist_floatwindow_cache);
        instance = this;
        Bundle bundle = getIntent().getExtras();
        boolean autoFlag = bundle.getBoolean("autoFlag");
        int value = bundle.getInt("value");
        WindowManager.LayoutParams brightnessParams = getWindow().getAttributes();
        if (!autoFlag) {
            Settings.System.putInt(getContentResolver(), "screen_brightness_mode", 0);
            Settings.System.putInt(getContentResolver(), "screen_brightness", value);
            brightnessParams.screenBrightness = value / 255.0f;
        } else {
            Settings.System.putInt(getContentResolver(), "screen_brightness_mode", 1);
            brightnessParams.screenBrightness = -1.0f;
        }
        getWindow().setAttributes(brightnessParams);
        getWindow().setAttributes(brightnessParams);
        Intent i = new Intent();
        i.setAction("com.lenovo.safecenter.lightChanges");
        sendBroadcast(i);
        new Thread() { // from class: com.lenovo.safecenter.floatwindow.view.FloatwindowCache.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    sleep(100L);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                FloatwindowCache.this.finish();
            }
        }.start();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }
}
