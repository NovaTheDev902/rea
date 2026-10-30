package com.tencent.lbsapi.model;

/* JADX INFO: loaded from: classes.dex */
public class QLBSWifiInfo {

    /* JADX INFO: renamed from: a */
    private String f6009a;

    /* JADX INFO: renamed from: b */
    private String f6010b;

    /* JADX INFO: renamed from: c */
    private int f6011c;

    public QLBSWifiInfo(String str, String str2, int i) {
        this.f6009a = str;
        this.f6010b = str2;
        this.f6011c = i;
    }

    public int getLevel() {
        return this.f6011c;
    }

    public String getMac() {
        return this.f6010b;
    }

    public String getName() {
        return this.f6009a;
    }

    public void setLevel(int i) {
        this.f6011c = i;
    }

    public void setMac(String str) {
        this.f6010b = str;
    }

    public void setName(String str) {
        this.f6009a = str;
    }
}
