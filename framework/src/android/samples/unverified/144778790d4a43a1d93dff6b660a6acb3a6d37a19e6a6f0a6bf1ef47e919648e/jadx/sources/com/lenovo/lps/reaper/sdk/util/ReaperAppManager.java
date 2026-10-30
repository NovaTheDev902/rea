package com.lenovo.lps.reaper.sdk.util;

import android.app.Activity;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class ReaperAppManager {

    /* JADX INFO: renamed from: b */
    private static ReaperAppManager f1198b = new ReaperAppManager();

    /* JADX INFO: renamed from: c */
    private Activity f1200c;

    /* JADX INFO: renamed from: d */
    private int f1201d;

    /* JADX INFO: renamed from: e */
    private int f1202e;

    /* JADX INFO: renamed from: a */
    private ArrayList<Activity> f1199a = new ArrayList<>();

    /* JADX INFO: renamed from: f */
    private Map<String, Long> f1203f = new HashMap();

    /* JADX INFO: renamed from: g */
    private boolean f1204g = false;

    public static ReaperAppManager getInstance() {
        return f1198b;
    }

    public void setTrackerInitialized(boolean isInitialized) {
        this.f1204g = isInitialized;
    }

    public boolean isTrackerInitialized() {
        return this.f1204g;
    }

    public Activity getFirstActivity() {
        return this.f1200c;
    }

    public void setFirstActivity(Activity firstActivity) {
        this.f1200c = firstActivity;
    }

    public boolean noMoreActivity() {
        return this.f1199a.isEmpty();
    }

    public void add(Activity activity) {
        this.f1199a.add(activity);
    }

    public boolean remove(Activity activity) {
        return this.f1199a.remove(activity);
    }

    public void setRecentTrackedPageview(String name) {
        this.f1203f.put(name, Long.valueOf(System.currentTimeMillis()));
    }

    public Map<String, Long> getPageViewTimeMap() {
        return this.f1203f;
    }

    public int getCurrentActivitySeqNumber() {
        return this.f1201d;
    }

    public void addCurrentActivitySeqNumber() {
        this.f1201d++;
    }

    public void resetCurrentActivitySeqNumber() {
        this.f1201d = 0;
    }

    public int getCurrentUserActionSeqNumber() {
        return this.f1202e;
    }

    public void addCurrentUserActionSeqNumber() {
        this.f1202e++;
    }

    public void resetCurrentUserActionSeqNumber() {
        this.f1202e = 0;
    }
}
