package com.lenovo.safecenter.shortcut;

import android.app.Notification;
import android.app.PendingIntent;
import android.app.Service;
import android.appwidget.AppWidgetManager;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.IBinder;
import android.widget.RemoteViews;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class WidgetUpdateService extends Service {
    public static final int DATA_STATE_CHANGE = 2;
    public static final int REMAINTIME_CHANGE = 0;
    public static final int SHOW_BATTERY_CHANGE = 4;
    public static final int SHOW_MODE_CHANGE = 5;
    public static final int SIM_STATE_CHANGE = 3;
    public static final String TAG = "WidgetUpdateService";
    public static final int WIFI_STATE_CHANGE = 1;

    /* JADX INFO: renamed from: a */
    private C0972a f5382a;

    /* JADX INFO: renamed from: b */
    private RemoteViews f5383b;

    /* JADX INFO: renamed from: c */
    private int f5384c;

    public void refresh(int flag) {
        if (this.f5383b == null) {
            this.f5383b = m2224a();
        }
        m2226b(this.f5383b);
        m2225a(this.f5383b);
    }

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
        startForeground(0, new Notification());
        this.f5382a = new C0972a();
        IntentFilter filter = new IntentFilter();
        filter.addAction("com.lenovo.safecenter.ONEKEY_WIDGET_REFRESH");
        registerReceiver(this.f5382a, filter);
    }

    @Override // android.app.Service
    public void onDestroy() {
        if (this.f5382a != null) {
            unregisterReceiver(this.f5382a);
            this.f5382a = null;
        }
        super.onDestroy();
    }

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override // android.app.Service
    public int onStartCommand(Intent intent, int flags, int startId) {
        showRemoteView();
        return super.onStartCommand(intent, 1, startId);
    }

    public void showRemoteView() {
        if (this.f5383b == null) {
            this.f5383b = m2224a();
        }
        m2226b(this.f5383b);
        m2225a(this.f5383b);
    }

    /* JADX INFO: renamed from: a */
    private void m2225a(RemoteViews remoteViews) {
        ComponentName componentName = new ComponentName(getApplicationContext(), (Class<?>) WidgetProvider.class);
        AppWidgetManager appWidgetManager = AppWidgetManager.getInstance(getApplicationContext());
        appWidgetManager.updateAppWidget(componentName, remoteViews);
    }

    /* JADX INFO: renamed from: b */
    private void m2226b(RemoteViews remoteViews) {
        this.f5384c = C0415R.drawable.onkey_shutcut_green;
        remoteViews.setImageViewResource(C0415R.id.bkg_image, this.f5384c);
    }

    /* JADX INFO: renamed from: a */
    private RemoteViews m2224a() {
        RemoteViews remoteViews = new RemoteViews(getPackageName(), C0415R.layout.widget_onekey);
        Intent intent = new Intent("android.intent.action.MAIN");
        intent.putExtra(ClearnView.ONEKEY_LAUNCHER, ClearnView.ONEKEY_WIDGET);
        intent.setComponent(new ComponentName(getApplicationContext(), (Class<?>) CleanViewService.class));
        remoteViews.setOnClickPendingIntent(C0415R.id.widget_onekey, PendingIntent.getService(this, 0, intent, 0));
        return remoteViews;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.shortcut.WidgetUpdateService$a */
    class C0972a extends BroadcastReceiver {
        C0972a() {
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if (action.equals("com.lenovo.safecenter.ONEKEY_WIDGET_REFRESH")) {
                WidgetUpdateService.this.refresh(0);
            }
        }
    }
}
