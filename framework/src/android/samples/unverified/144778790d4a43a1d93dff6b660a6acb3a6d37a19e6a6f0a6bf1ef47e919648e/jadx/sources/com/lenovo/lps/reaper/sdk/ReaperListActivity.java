package com.lenovo.lps.reaper.sdk;

import android.app.ListActivity;
import android.os.Bundle;
import com.lenovo.lps.reaper.sdk.util.ReaperAppManager;

/* JADX INFO: loaded from: classes.dex */
public class ReaperListActivity extends ListActivity {

    /* JADX INFO: renamed from: a */
    private ReaperAppManager f1100a = ReaperAppManager.getInstance();

    /* JADX INFO: renamed from: b */
    private AnalyticsTracker f1101b = AnalyticsTracker.getInstance();

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (this.f1100a.getFirstActivity() == null) {
            this.f1101b.initialize(this);
            this.f1100a.setFirstActivity(this);
        }
        this.f1100a.add(this);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f1101b.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        this.f1101b.trackPause(this);
        super.onPause();
    }

    @Override // android.app.ListActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        this.f1100a.remove(this);
        if (equals(this.f1100a.getFirstActivity())) {
            this.f1100a.setFirstActivity(null);
        }
    }
}
