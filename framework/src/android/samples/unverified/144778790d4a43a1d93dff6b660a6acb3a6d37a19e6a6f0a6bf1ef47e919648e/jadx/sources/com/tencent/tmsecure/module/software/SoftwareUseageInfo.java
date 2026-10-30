package com.tencent.tmsecure.module.software;

import com.lenovo.lps.sus.p008c.C0092c;
import java.util.Date;

/* JADX INFO: loaded from: classes.dex */
public final class SoftwareUseageInfo {
    public Date mFirstDate;
    public Date mLastDate;
    public String mPkgname;
    public int mUseCount;

    private SoftwareUseageInfo() {
    }

    public SoftwareUseageInfo(String str, Date date, Date date2, int i) {
        this.mPkgname = str;
        this.mFirstDate = date;
        this.mLastDate = date2;
        this.mUseCount = i;
    }

    public static SoftwareUseageInfo fromString(String str) {
        String[] strArrSplit = str.trim().split(C0092c.f1284O);
        SoftwareUseageInfo softwareUseageInfo = new SoftwareUseageInfo();
        softwareUseageInfo.mPkgname = strArrSplit[0];
        softwareUseageInfo.mFirstDate = new Date(Long.parseLong(strArrSplit[1]));
        softwareUseageInfo.mLastDate = new Date(Long.parseLong(strArrSplit[2]));
        softwareUseageInfo.mUseCount = Integer.parseInt(strArrSplit[3]);
        return softwareUseageInfo;
    }

    public static String getString(SoftwareUseageInfo softwareUseageInfo) {
        StringBuilder sb = new StringBuilder();
        sb.append(softwareUseageInfo.mPkgname + C0092c.f1284O);
        sb.append(softwareUseageInfo.mFirstDate.getTime() + C0092c.f1284O);
        sb.append(softwareUseageInfo.mLastDate.getTime() + C0092c.f1284O);
        sb.append(softwareUseageInfo.mUseCount);
        return sb.toString();
    }
}
