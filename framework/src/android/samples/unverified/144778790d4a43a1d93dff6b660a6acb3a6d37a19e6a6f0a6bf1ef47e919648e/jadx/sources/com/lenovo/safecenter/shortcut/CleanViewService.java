package com.lenovo.safecenter.shortcut;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class CleanViewService extends Service {

    /* JADX INFO: renamed from: a */
    private ClearnView f5332a;

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
        Log.i("CleanViewService", "---> onCreate");
    }

    @Override // android.app.Service
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.i("CleanViewService", "---> onStartCommand");
        TrackEvent.reportClickOneKeyEndTaskInShortcut();
        if (intent != null) {
            try {
                intent.setSourceBounds(intent.getSourceBounds());
            } catch (Exception e) {
                e.printStackTrace();
                Log.i("CleanViewService", "Bounds Exception " + e);
            }
            try {
                this.f5332a = new ClearnView(getApplicationContext());
                ViewManager.addView(getApplicationContext(), intent.getSourceBounds(), this.f5332a);
            } catch (Exception e2) {
                e2.printStackTrace();
                Log.i("CleanViewService", " doClearn Ex!" + e2);
            }
        }
        return super.onStartCommand(intent, flags, startId);
    }

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        Log.i("CleanViewService", "---> onBind");
        return null;
    }

    @Override // android.app.Service
    public void onDestroy() {
        Log.i("CleanViewService", "---> onDestroy");
        super.onDestroy();
    }
}
