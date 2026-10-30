package com.lenovo.safecenter.antivirus.domain;

import android.content.pm.ApplicationInfo;

/* JADX INFO: loaded from: classes.dex */
public class ScanInfo {

    /* JADX INFO: renamed from: a */
    private String f3017a;

    /* JADX INFO: renamed from: b */
    private String f3018b;

    /* JADX INFO: renamed from: c */
    private boolean f3019c;

    /* JADX INFO: renamed from: d */
    private ApplicationInfo f3020d;

    public ApplicationInfo getAppInfo() {
        return this.f3020d;
    }

    public void setAppInfo(ApplicationInfo appInfo) {
        this.f3020d = appInfo;
    }

    public ScanInfo() {
        this.f3019c = false;
    }

    public ScanInfo(ApplicationInfo appInfo, boolean isVirus) {
        this.f3019c = false;
        this.f3020d = appInfo;
        this.f3019c = isVirus;
    }

    public ScanInfo(String packageName, String label, boolean isVirus) {
        this.f3019c = false;
        this.f3017a = packageName;
        this.f3018b = label;
        this.f3019c = isVirus;
    }

    public String getPackageName() {
        return this.f3017a;
    }

    public void setPackageName(String packageName) {
        this.f3017a = packageName;
    }

    public String getSoftName() {
        return this.f3018b;
    }

    public void setLabel(String label) {
        this.f3018b = label;
    }

    public boolean isVirus() {
        return this.f3019c;
    }

    public void setVirus(boolean isVirus) {
        this.f3019c = isVirus;
    }
}
