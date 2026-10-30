package com.lenovo.safecenter.floatwindow.shortcut;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.view.FloatWindow;
import com.lenovo.safecenter.utils.TrackEvent;
import com.tencent.tmsecure.module.update.UpdateConfig;

/* JADX INFO: loaded from: classes.dex */
public class ShortcutActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private Context f3573a;

    /* JADX INFO: renamed from: b */
    private FloatWindow f3574b;

    /* JADX INFO: renamed from: c */
    private C0559a f3575c;

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f3573a = this;
        if (this.f3575c == null) {
            this.f3575c = new C0559a(this, (byte) 0);
            IntentFilter intentFilter = new IntentFilter();
            intentFilter.addAction("com.lenovo.safecenter.floatwindow.closewindow");
            intentFilter.addAction("android.intent.action.SCREEN_OFF");
            intentFilter.addAction("com.lenovo.safecenter.floatwindow.delwindow");
            registerReceiver(this.f3575c, intentFilter);
        }
        if ("android.intent.action.CREATE_SHORTCUT".equals(getIntent().getAction())) {
            Intent localIntent1 = new Intent("android.intent.action.MAIN");
            localIntent1.addFlags(268435456);
            localIntent1.addFlags(UpdateConfig.UPDATE_FLAG_ALL);
            localIntent1.setClass(this, ShortcutActivity.class);
            Intent localIntent2 = new Intent("com.android.launcher.action.INSTALL_SHORTCUT");
            localIntent2.putExtra("android.intent.extra.shortcut.NAME", getResources().getString(C0415R.string.switcher_app_name));
            localIntent2.putExtra("android.intent.extra.shortcut.ICON_RESOURCE", Intent.ShortcutIconResource.fromContext(this, C0415R.drawable.shortcut_app_icon));
            localIntent2.putExtra("duplicate", true);
            localIntent2.putExtra("android.intent.extra.shortcut.INTENT", localIntent1);
            sendBroadcast(localIntent2);
            finish();
            return;
        }
        if (FloatWindow.instanceFloatWindow != null) {
            FloatWindow.instanceFloatWindow = null;
        }
        this.f3574b = new FloatWindow(this);
        this.f3574b.showFloatWindow();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.floatwindow.shortcut.ShortcutActivity$a */
    private class C0559a extends BroadcastReceiver {
        private C0559a() {
        }

        /* synthetic */ C0559a(ShortcutActivity x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if ("com.lenovo.safecenter.floatwindow.closewindow".equals(intent.getAction())) {
                ShortcutActivity.this.finish();
            }
            if ("android.intent.action.SCREEN_OFF".equals(intent.getAction()) && ShortcutActivity.this.f3574b != null) {
                ShortcutActivity.this.f3574b.delFloatWindow();
            }
            if ("com.lenovo.safecenter.floatwindow.delwindow".equals(intent.getAction()) && ShortcutActivity.this.f3574b != null) {
                ShortcutActivity.this.f3574b.delFloatWindow();
            }
        }
    }

    @Override // android.app.Activity
    public void onDestroy() {
        super.onDestroy();
        if (this.f3575c != null) {
            unregisterReceiver(this.f3575c);
        }
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
