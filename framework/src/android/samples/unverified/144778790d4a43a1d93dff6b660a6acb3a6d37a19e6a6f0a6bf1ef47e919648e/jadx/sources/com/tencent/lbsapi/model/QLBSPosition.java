package com.tencent.lbsapi.model;

/* JADX INFO: loaded from: classes.dex */
public class QLBSPosition {

    /* JADX INFO: renamed from: a */
    private String f6001a = "";

    /* JADX INFO: renamed from: b */
    private String f6002b = "";

    /* JADX INFO: renamed from: c */
    private String f6003c = "";

    /* JADX INFO: renamed from: d */
    private String f6004d = "";

    /* JADX INFO: renamed from: e */
    private String f6005e = "";

    /* JADX INFO: renamed from: f */
    private String f6006f = "";

    /* JADX INFO: renamed from: g */
    private QLBSGPSInfo f6007g = null;

    /* JADX INFO: renamed from: h */
    private int f6008h = 0;

    public String getCity() {
        return this.f6002b;
    }

    public String getDistrict() {
        return this.f6003c;
    }

    public QLBSGPSInfo getGps() {
        return this.f6007g;
    }

    public String getPremises() {
        return this.f6006f;
    }

    public String getProvince() {
        return this.f6001a;
    }

    public int getRange() {
        return this.f6008h;
    }

    public String getRoad() {
        return this.f6005e;
    }

    public String getTown() {
        return this.f6004d;
    }

    public void setCity(String str) {
        this.f6002b = str;
    }

    public void setDistrict(String str) {
        this.f6003c = str;
    }

    public void setGps(QLBSGPSInfo qLBSGPSInfo) {
        this.f6007g = qLBSGPSInfo;
    }

    public void setPremises(String str) {
        this.f6006f = str;
    }

    public void setProvince(String str) {
        this.f6001a = str;
    }

    public void setRange(int i) {
        this.f6008h = i;
    }

    public void setRoad(String str) {
        this.f6005e = str;
    }

    public void setTown(String str) {
        this.f6004d = str;
    }
}
