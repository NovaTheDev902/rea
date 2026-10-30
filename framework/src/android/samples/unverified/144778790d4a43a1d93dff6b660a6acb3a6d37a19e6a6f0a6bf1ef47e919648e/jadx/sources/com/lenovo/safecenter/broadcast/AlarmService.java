package com.lenovo.safecenter.broadcast;

import android.app.Service;
import android.content.Intent;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.IBinder;
import com.lenovo.safecenter.C0415R;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class AlarmService extends Service {

    /* JADX INFO: renamed from: a */
    private MediaPlayer f3387a;

    /* JADX INFO: renamed from: b */
    private AudioManager f3388b;

    /* JADX INFO: renamed from: c */
    private boolean f3389c = false;

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
        this.f3387a = MediaPlayer.create(this, C0415R.raw.alarm);
        this.f3388b = (AudioManager) getSystemService("audio");
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.broadcast.AlarmService$1] */
    @Override // android.app.Service
    public void onStart(Intent intent, int startId) {
        super.onStart(intent, startId);
        this.f3389c = true;
        new Thread() { // from class: com.lenovo.safecenter.broadcast.AlarmService.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                while (AlarmService.this.f3389c) {
                    AlarmService.this.f3388b.setStreamVolume(3, AlarmService.this.f3388b.getStreamMaxVolume(3), 0);
                    try {
                        Thread.sleep(1000L);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }.start();
        if (this.f3387a != null) {
            this.f3387a.stop();
            try {
                this.f3387a.prepare();
            } catch (IOException e) {
            } catch (IllegalStateException e2) {
            }
            this.f3387a.setLooping(true);
            this.f3387a.start();
        }
    }

    @Override // android.app.Service
    public void onDestroy() {
        super.onDestroy();
        if (this.f3387a != null) {
            this.f3387a.stop();
            this.f3387a.release();
        }
        this.f3389c = false;
    }
}
