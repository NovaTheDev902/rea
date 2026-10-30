package com.lenovo.performancecenter.service.object;

import android.graphics.Bitmap;

/* JADX INFO: loaded from: classes.dex */
public class AppBean implements Comparable<AppBean> {

    /* JADX INFO: renamed from: a */
    private CharSequence f1920a;

    /* JADX INFO: renamed from: b */
    private String f1921b;

    /* JADX INFO: renamed from: c */
    private String f1922c;

    /* JADX INFO: renamed from: d */
    private String f1923d;

    /* JADX INFO: renamed from: e */
    private String f1924e;

    /* JADX INFO: renamed from: f */
    private String f1925f;

    /* JADX INFO: renamed from: g */
    private Bitmap f1926g;

    /* JADX INFO: renamed from: h */
    private boolean f1927h;

    /* JADX INFO: renamed from: i */
    private boolean f1928i;

    /* JADX INFO: renamed from: j */
    private boolean f1929j;

    /* JADX INFO: renamed from: k */
    private boolean f1930k;

    /* JADX INFO: renamed from: l */
    private long f1931l;

    public CharSequence getAppName() {
        return this.f1920a;
    }

    public void setAppName(CharSequence appName) {
        this.f1920a = appName;
    }

    public String getAppPath() {
        return this.f1921b;
    }

    public void setAppPath(String appPath) {
        this.f1921b = appPath;
    }

    public boolean canMove() {
        return this.f1930k;
    }

    public void setcanMove(boolean canMove) {
        this.f1930k = canMove;
    }

    public long getappLongSize() {
        return this.f1931l;
    }

    public void setappLongSize(long appLongSize) {
        this.f1931l = appLongSize;
    }

    public boolean isIntalled() {
        return this.f1927h;
    }

    public void setIntalled(boolean isIntalled) {
        this.f1927h = isIntalled;
    }

    public boolean isChecked() {
        return this.f1928i;
    }

    public void setChecked(boolean isChecked) {
        this.f1928i = isChecked;
    }

    public boolean isInSdcard() {
        return this.f1929j;
    }

    public void setInSdcard(boolean inSdcard) {
        this.f1929j = inSdcard;
    }

    public String getAppSize() {
        return this.f1923d;
    }

    public void setAppSize(String appSize) {
        this.f1923d = appSize;
    }

    public String getPkgName() {
        return this.f1922c;
    }

    public void setPkgName(String pkgName) {
        this.f1922c = pkgName;
    }

    public Bitmap getAppIcon() {
        return this.f1926g;
    }

    public void setAppIcon(Bitmap appIcon) {
        this.f1926g = appIcon;
    }

    public String getAppVersionName() {
        return this.f1924e;
    }

    public void setAppVersionName(String appVersionName) {
        this.f1924e = appVersionName;
    }

    public String getAppVersionCode() {
        return this.f1925f;
    }

    public void setAppVersionCode(String appVersionCode) {
        this.f1925f = appVersionCode;
    }

    public String toString() {
        return "AppBean [appName=" + ((Object) this.f1920a) + ", isIntalled=" + this.f1927h + ", pkgName=" + this.f1922c + ", appSize=" + this.f1923d + ", appVersionName=" + this.f1924e + ", appVersionCode=" + this.f1925f + ", appPath=" + this.f1921b + "]";
    }

    @Override // java.lang.Comparable
    public int compareTo(AppBean another) {
        if (new Long(another.getappLongSize()).intValue() > new Long(getappLongSize()).intValue()) {
            return 1;
        }
        return new Long(another.getappLongSize()).intValue() == new Long(getappLongSize()).intValue() ? 0 : -1;
    }
}
