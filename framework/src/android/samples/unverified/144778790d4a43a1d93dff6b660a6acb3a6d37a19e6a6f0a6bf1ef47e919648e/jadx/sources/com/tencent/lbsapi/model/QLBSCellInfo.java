package com.tencent.lbsapi.model;

/* JADX INFO: loaded from: classes.dex */
public class QLBSCellInfo {

    /* JADX INFO: renamed from: a */
    private int f5981a;

    /* JADX INFO: renamed from: b */
    private int f5982b;

    /* JADX INFO: renamed from: c */
    private int f5983c;

    /* JADX INFO: renamed from: d */
    private int f5984d;

    public QLBSCellInfo() {
    }

    public QLBSCellInfo(int i, int i2, int i3, int i4) {
        this.f5982b = i;
        this.f5981a = i2;
        this.f5983c = i3;
        this.f5984d = i4;
    }

    public int getCellid() {
        return this.f5984d;
    }

    public int getLac() {
        return this.f5983c;
    }

    public int getMcc() {
        return this.f5981a;
    }

    public int getMnc() {
        return this.f5982b;
    }

    public void setCellid(int i) {
        this.f5984d = i;
    }

    public void setLac(int i) {
        this.f5983c = i;
    }

    public void setMcc(int i) {
        this.f5981a = i;
    }

    public void setMnc(int i) {
        this.f5982b = i;
    }
}
