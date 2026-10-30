package com.lenovo.safecenter.antivirus.domain;

/* JADX INFO: loaded from: classes.dex */
public class Virus {

    /* JADX INFO: renamed from: a */
    private String f3021a;

    /* JADX INFO: renamed from: b */
    private String f3022b;

    /* JADX INFO: renamed from: c */
    private boolean f3023c;

    /* JADX INFO: renamed from: d */
    private String f3024d;

    /* JADX INFO: renamed from: e */
    private String f3025e;

    /* JADX INFO: renamed from: f */
    private int f3026f;

    /* JADX INFO: renamed from: g */
    private boolean f3027g;

    /* JADX INFO: renamed from: h */
    private String f3028h;

    public String getVirusDesc() {
        return this.f3025e;
    }

    public void setVirusDesc(String virusDesc) {
        this.f3025e = virusDesc;
    }

    public Virus() {
    }

    public Virus(String packageName, String appName, boolean operate) {
        this.f3021a = packageName;
        this.f3022b = appName;
        this.f3023c = operate;
    }

    public String getPackageName() {
        return this.f3021a;
    }

    public void setPackageName(String packageName) {
        this.f3021a = packageName;
    }

    public String getAppName() {
        return this.f3022b;
    }

    public void setAppName(String appName) {
        this.f3022b = appName;
    }

    public boolean isOperate() {
        return this.f3023c;
    }

    public void setOperate(boolean operate) {
        this.f3023c = operate;
    }

    public String getVirusName() {
        return this.f3024d;
    }

    public void setVirusName(String virusName) {
        this.f3024d = virusName;
    }

    public int getType() {
        return this.f3026f;
    }

    public void setType(int type) {
        this.f3026f = type;
    }

    public boolean isSD() {
        return this.f3027g;
    }

    public void setSD(boolean isSD) {
        this.f3027g = isSD;
    }

    public String getFilePath() {
        return this.f3028h;
    }

    public void setFilePath(String filePath) {
        this.f3028h = filePath;
    }
}
