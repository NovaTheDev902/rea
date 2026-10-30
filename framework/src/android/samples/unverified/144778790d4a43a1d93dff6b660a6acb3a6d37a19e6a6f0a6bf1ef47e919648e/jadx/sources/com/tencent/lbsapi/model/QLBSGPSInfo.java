package com.tencent.lbsapi.model;

/* JADX INFO: loaded from: classes.dex */
public class QLBSGPSInfo {
    public static final int GPS_MARS = 1;
    public static final int GPS_WGS84 = 0;
    public static final int GPS_WGS_REAL = 2;

    /* JADX INFO: renamed from: a */
    private int f5985a = 900000000;

    /* JADX INFO: renamed from: b */
    private int f5986b = 900000000;

    /* JADX INFO: renamed from: c */
    private int f5987c = 900000000;

    /* JADX INFO: renamed from: d */
    private int f5988d = 0;

    public QLBSGPSInfo() {
    }

    public QLBSGPSInfo(int i, int i2, int i3, int i4) {
        setLat(i);
        setLon(i2);
        setAlt(i3);
        setType(i4);
    }

    public double getAlt() {
        return ((double) this.f5987c) / 1000000.0d;
    }

    public double getLat() {
        return ((double) this.f5985a) / 1000000.0d;
    }

    public double getLon() {
        return ((double) this.f5986b) / 1000000.0d;
    }

    public int getType() {
        return this.f5988d;
    }

    public void setAlt(int i) {
        this.f5987c = i;
    }

    public void setLat(int i) {
        this.f5985a = i;
    }

    public void setLon(int i) {
        this.f5986b = i;
    }

    public void setType(int i) {
        this.f5988d = i;
    }
}
