package com.lenovo.safecenter.antivirus.domain;

import android.content.pm.ApplicationInfo;

/* JADX INFO: loaded from: classes.dex */
public class CommonFile {

    /* JADX INFO: renamed from: a */
    private ApplicationInfo f3003a;

    /* JADX INFO: renamed from: b */
    private boolean f3004b;

    /* JADX INFO: renamed from: c */
    private String f3005c;

    /* JADX INFO: renamed from: d */
    private boolean f3006d;

    /* JADX INFO: renamed from: e */
    private boolean f3007e;
    public Appinfo virusInfo;

    public ApplicationInfo getApplicationInfo() {
        return this.f3003a;
    }

    public void setApplicationInfo(ApplicationInfo applicationInfo) {
        this.f3003a = applicationInfo;
    }

    public boolean isApk() {
        return this.f3004b;
    }

    public void setApk(boolean isApk) {
        this.f3004b = isApk;
    }

    public String getFilePath() {
        return this.f3005c;
    }

    public void setFilePath(String filePath) {
        this.f3005c = filePath;
    }

    public boolean isSD() {
        return this.f3007e;
    }

    public void setSD(boolean isSD) {
        this.f3007e = isSD;
    }

    public boolean isVirus() {
        return this.f3006d;
    }

    public void setVirus(boolean isVirus) {
        this.f3006d = isVirus;
    }

    public Appinfo getVirusInfo() {
        return this.virusInfo;
    }

    public void setVirusInfo(Appinfo virusInfo) {
        this.virusInfo = virusInfo;
    }
}
