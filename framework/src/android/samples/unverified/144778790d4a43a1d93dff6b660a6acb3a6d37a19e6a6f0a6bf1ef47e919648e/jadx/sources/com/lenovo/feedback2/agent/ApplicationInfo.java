package com.lenovo.feedback2.agent;

/* JADX INFO: loaded from: classes.dex */
public class ApplicationInfo {

    /* JADX INFO: renamed from: a */
    private String f923a;

    /* JADX INFO: renamed from: b */
    private int f924b;

    /* JADX INFO: renamed from: c */
    private String f925c;

    /* JADX INFO: renamed from: d */
    private String f926d;

    public String getAppName() {
        return this.f926d;
    }

    public void setAppName(String appName) {
        this.f926d = appName;
    }

    public String getPackageName() {
        return this.f923a;
    }

    public void setPackageName(String packageName) {
        this.f923a = packageName;
    }

    public int getVersionCode() {
        return this.f924b;
    }

    public void setVersionCode(int versionCode) {
        this.f924b = versionCode;
    }

    public String getVersionName() {
        return this.f925c;
    }

    public void setVersionName(String versionName) {
        this.f925c = versionName;
    }
}
