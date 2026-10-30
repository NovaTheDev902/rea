package com.lenovo.lps.reaper.sdk;

import android.app.TabActivity;
import android.os.Bundle;
import com.lenovo.lps.reaper.sdk.util.ReaperAppManager;

/* JADX INFO: loaded from: classes.dex */
public class ReaperTabActivity extends TabActivity {

    /* JADX INFO: renamed from: a */
    private ReaperAppManager f1102a = ReaperAppManager.getInstance();

    /* JADX INFO: renamed from: b */
    private AnalyticsTracker f1103b = AnalyticsTracker.getInstance();

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (this.f1102a.getFirstActivity() == null) {
            this.f1103b.initialize(this);
            this.f1102a.setFirstActivity(this);
        }
        this.f1102a.add(this);
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f1103b.trackResume(this);
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onPause() {
        this.f1103b.trackPause(this);
        super.onPause();
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        this.f1102a.remove(this);
        if (equals(this.f1102a.getFirstActivity())) {
            this.f1102a.setFirstActivity(null);
        }
    }
}
