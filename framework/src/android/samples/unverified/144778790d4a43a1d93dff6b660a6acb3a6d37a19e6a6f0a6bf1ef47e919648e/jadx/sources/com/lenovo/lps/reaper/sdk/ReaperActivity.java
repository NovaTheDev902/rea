package com.lenovo.lps.reaper.sdk;

import android.app.Activity;
import android.os.Bundle;
import com.lenovo.lps.reaper.sdk.util.ReaperAppManager;

/* JADX INFO: loaded from: classes.dex */
public class ReaperActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private ReaperAppManager f1098a = ReaperAppManager.getInstance();

    /* JADX INFO: renamed from: b */
    private AnalyticsTracker f1099b = AnalyticsTracker.getInstance();

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (this.f1098a.getFirstActivity() == null) {
            this.f1099b.initialize(this);
            this.f1098a.setFirstActivity(this);
        }
        this.f1098a.add(this);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f1099b.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        this.f1099b.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        this.f1098a.remove(this);
        if (equals(this.f1098a.getFirstActivity())) {
            this.f1098a.setFirstActivity(null);
        }
    }
}
