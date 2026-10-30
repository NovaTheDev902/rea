package com.tencent.lbsapi.model;

/* JADX INFO: loaded from: classes.dex */
public class QLBSPoiInfo {

    /* JADX INFO: renamed from: a */
    private String f5989a;

    /* JADX INFO: renamed from: b */
    private int f5990b;

    /* JADX INFO: renamed from: c */
    private String f5991c;

    /* JADX INFO: renamed from: d */
    private String f5992d;

    /* JADX INFO: renamed from: e */
    private long f5993e;

    /* JADX INFO: renamed from: f */
    private int f5994f;

    /* JADX INFO: renamed from: g */
    private QLBSGPSInfo f5995g = null;

    /* JADX INFO: renamed from: h */
    private int f5996h;

    /* JADX INFO: renamed from: i */
    private int f5997i;

    public QLBSPoiInfo(String str, int i, String str2, String str3, long j, int i2, int i3, int i4) {
        this.f5989a = null;
        this.f5990b = 0;
        this.f5991c = null;
        this.f5992d = null;
        this.f5993e = 0L;
        this.f5994f = 0;
        this.f5996h = 0;
        this.f5997i = 0;
        this.f5989a = str;
        this.f5990b = i;
        this.f5991c = str2;
        this.f5992d = str3;
        this.f5993e = j;
        this.f5994f = i2;
        this.f5996h = i3;
        this.f5997i = i4;
    }

    public String getAddress() {
        return this.f5992d;
    }

    public int getDistance() {
        return this.f5996h;
    }

    public int getDistrictCode() {
        return this.f5994f;
    }

    public int getHotValue() {
        return this.f5997i;
    }

    public QLBSGPSInfo getMarsGps() {
        return this.f5995g;
    }

    public String getName() {
        return this.f5989a;
    }

    public long getPoiId() {
        return this.f5993e;
    }

    public int getType() {
        return this.f5990b;
    }

    public String getTypeName() {
        return this.f5991c;
    }

    public void setAddress(String str) {
        this.f5992d = str;
    }

    public void setDistance(int i) {
        this.f5996h = i;
    }

    public void setDistrictCode(int i) {
        this.f5994f = i;
    }

    public void setHotValue(int i) {
        this.f5997i = i;
    }

    public void setMarsGps(QLBSGPSInfo qLBSGPSInfo) {
        this.f5995g = qLBSGPSInfo;
    }

    public void setName(String str) {
        this.f5989a = str;
    }

    public void setPoiID(long j) {
        this.f5993e = j;
    }

    public void setType(int i) {
        this.f5990b = i;
    }

    public void setTypeName(String str) {
        this.f5991c = str;
    }
}
