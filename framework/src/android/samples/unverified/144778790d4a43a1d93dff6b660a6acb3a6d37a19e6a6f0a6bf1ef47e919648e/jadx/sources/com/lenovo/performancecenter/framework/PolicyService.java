package com.lenovo.performancecenter.framework;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.Binder;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.text.format.Formatter;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.performance.ScanApplicationInfo;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class PolicyService extends Service {

    /* JADX INFO: renamed from: a */
    private ScanApplicationInfo f1644a;

    /* JADX INFO: renamed from: b */
    private final IBinder f1645b = new LocalBinder();

    /* JADX INFO: renamed from: c */
    private Handler f1646c = new Handler() { // from class: com.lenovo.performancecenter.framework.PolicyService.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    PolicyService.m580a(PolicyService.this, msg.arg1, msg.arg2);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m580a(PolicyService x0, int x1, int x2) {
        if (x1 == 0) {
            return;
        }
        Toast toast = new Toast(x0);
        View viewInflate = LayoutInflater.from(x0).inflate(C0415R.layout.toast, (ViewGroup) null);
        ((TextView) viewInflate.findViewById(C0415R.id.toast_title)).setText(x0.getString(C0415R.string.auto_clean_notifycation, new Object[]{Integer.valueOf(x1), Formatter.formatFileSize(x0, x2)}));
        toast.setDuration(0);
        toast.setView(viewInflate);
        toast.show();
    }

    public class LocalBinder extends Binder {
        public LocalBinder() {
        }

        public PolicyService getService() {
            return PolicyService.this;
        }
    }

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
        Log.i("PolicyService", "PolicyService : onCreate");
    }

    @Override // android.app.Service
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.i("PolicyService", "PolicyService : onStartCommand");
        this.f1644a = ScanApplicationInfo.getSingleton(this, this.f1646c);
        return super.onStartCommand(intent, flags, startId);
    }

    @Override // android.app.Service
    public void onStart(Intent intent, int startId) {
        super.onStart(intent, startId);
        Log.i("PolicyService", "PolicyService : onStart");
    }

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        Log.i("PolicyService", "PolicyService : onBind");
        if (this.f1644a == null) {
            this.f1644a = ScanApplicationInfo.getSingleton(this, this.f1646c);
        }
        return this.f1645b;
    }

    @Override // android.app.Service
    public boolean onUnbind(Intent intent) {
        Log.i("PolicyService", "PolicyService : onUnbind");
        return super.onUnbind(intent);
    }

    @Override // android.app.Service
    public void onRebind(Intent intent) {
        super.onRebind(intent);
        Log.i("PolicyService", "PolicyService : onRebind");
    }

    public void updateConfiguration(String key, Object value, Context context) {
        this.f1644a.updateConfiguration(key, value, context);
    }

    @Override // android.app.Service
    public void onDestroy() {
        this.f1644a.stopPolicyTask(this);
        ScanApplicationInfo.releaseInstance();
        this.f1644a = null;
        Log.i("PolicyService", "PolicyService : onDestroy");
        try {
            startService(new Intent(this, (Class<?>) PolicyService.class));
        } catch (Exception e) {
            e.printStackTrace();
        }
        super.onDestroy();
    }
}
