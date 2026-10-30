package com.lenovo.performancecenter.performance;

import android.graphics.Bitmap;

/* JADX INFO: loaded from: classes.dex */
public class AppInfo {
    public Bitmap appIcon;
    public String appName;
    public boolean canRemove;
    public int flag;
    public boolean isTitle;
    public boolean isUserApp;
    public int memory;
    public String pkgName;
    public String procName;
    public int state;
    public String title;

    public AppInfo(boolean isTitle, boolean isUserApp, String title) {
        this.isUserApp = isUserApp;
        this.isTitle = isTitle;
        this.title = title;
    }

    public AppInfo(String pkgName, String appName, String procName, Bitmap appIcon, int state, int flag) {
        this.pkgName = pkgName;
        this.appName = appName;
        this.procName = procName;
        this.appIcon = appIcon;
        this.state = state;
        this.flag = flag;
    }
}
