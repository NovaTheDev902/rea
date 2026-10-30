package com.tencent.tmsecure.module.network;

import android.text.TextUtils;

/* JADX INFO: loaded from: classes.dex */
public final class TrafficEntity {
    public String mPkg;
    public long mLastUpValue = 0;
    public long mLastDownValue = 0;
    public long mMobileUpValue = 0;
    public long mMobileDownValue = 0;
    public long mWIFIUpValue = 0;
    public long mWIFIDownValue = 0;

    public static TrafficEntity fromString(String str) {
        if (TextUtils.isEmpty(str)) {
            return null;
        }
        TrafficEntity trafficEntity = new TrafficEntity();
        String[] strArrSplit = str.trim().split("[,:]");
        trafficEntity.mPkg = strArrSplit[0];
        trafficEntity.mLastUpValue = Long.parseLong(strArrSplit[1]);
        trafficEntity.mLastDownValue = Long.parseLong(strArrSplit[2]);
        trafficEntity.mMobileUpValue = Long.parseLong(strArrSplit[3]);
        trafficEntity.mMobileDownValue = Long.parseLong(strArrSplit[4]);
        trafficEntity.mWIFIUpValue = Long.parseLong(strArrSplit[5]);
        trafficEntity.mWIFIDownValue = Long.parseLong(strArrSplit[6]);
        return trafficEntity;
    }

    public static String toString(TrafficEntity trafficEntity) {
        return String.format("%s,%s,%s,%s,%s,%s,%s", trafficEntity.mPkg, Long.valueOf(trafficEntity.mLastUpValue), Long.valueOf(trafficEntity.mLastDownValue), Long.valueOf(trafficEntity.mMobileUpValue), Long.valueOf(trafficEntity.mMobileDownValue), Long.valueOf(trafficEntity.mWIFIUpValue), Long.valueOf(trafficEntity.mWIFIDownValue));
    }
}
