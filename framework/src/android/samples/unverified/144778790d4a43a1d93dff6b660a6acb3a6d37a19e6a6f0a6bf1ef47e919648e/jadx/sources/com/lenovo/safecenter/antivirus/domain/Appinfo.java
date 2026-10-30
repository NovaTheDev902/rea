package com.lenovo.safecenter.antivirus.domain;

/* JADX INFO: loaded from: classes.dex */
public class Appinfo {

    /* JADX INFO: renamed from: a */
    private String f2997a;

    /* JADX INFO: renamed from: b */
    private String f2998b;

    /* JADX INFO: renamed from: c */
    private String f2999c;

    /* JADX INFO: renamed from: d */
    private String f3000d;

    /* JADX INFO: renamed from: e */
    private String f3001e;

    /* JADX INFO: renamed from: f */
    private int f3002f;

    public int getPathKey() {
        return this.f3002f;
    }

    public void setPathKey(int pathKey) {
        this.f3002f = pathKey;
    }

    public Appinfo(String pkgName, String mD5, String sHA1, String filesize, String appname) {
        this.f2997a = pkgName;
        this.f2998b = mD5;
        this.f2999c = sHA1;
        this.f3000d = filesize;
        this.f3001e = appname;
    }

    public Appinfo() {
    }

    public String getPkgName() {
        return this.f2997a;
    }

    public void setPkgName(String pkgName) {
        this.f2997a = pkgName;
    }

    public String getMD5() {
        return this.f2998b;
    }

    public void setMD5(String mD5) {
        this.f2998b = mD5;
    }

    public String getSHA1() {
        return this.f2999c;
    }

    public void setSHA1(String sHA1) {
        this.f2999c = sHA1;
    }

    public String getFilesize() {
        return this.f3000d;
    }

    public void setFilesize(String filesize) {
        this.f3000d = filesize;
    }

    public String getAppname() {
        return this.f3001e;
    }

    public void setAppname(String appname) {
        this.f3001e = appname;
    }
}
