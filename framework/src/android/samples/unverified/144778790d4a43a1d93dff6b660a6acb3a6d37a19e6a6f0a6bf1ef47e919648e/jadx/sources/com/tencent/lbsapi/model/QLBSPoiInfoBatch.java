package com.tencent.lbsapi.model;

import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class QLBSPoiInfoBatch {

    /* JADX INFO: renamed from: a */
    private List f5998a = new ArrayList();

    /* JADX INFO: renamed from: b */
    private int f5999b = 0;

    /* JADX INFO: renamed from: c */
    private QLBSGPSInfo f6000c = null;

    public QLBSGPSInfo getGpsInfo() {
        return this.f6000c;
    }

    public List getPoiList() {
        return this.f5998a;
    }

    public int getTotalNum() {
        return this.f5999b;
    }

    public void setGpsInfo(QLBSGPSInfo qLBSGPSInfo) {
        this.f6000c = qLBSGPSInfo;
    }

    public void setPoiList(List list) {
        this.f5998a = list;
    }

    public void setTotalNum(int i) {
        this.f5999b = i;
    }
}
