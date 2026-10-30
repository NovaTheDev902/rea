package com.tencent.lbsapi;

import android.content.Context;
import com.tencent.lbsapi.core.C1072j;
import com.tencent.lbsapi.model.QLBSCellInfo;
import com.tencent.lbsapi.model.QLBSGPSInfo;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class QLBSService {
    public static final int POI_CATEGORY_ALL = 0;
    public static final int POI_CATEGORY_BANK = 250000;
    public static final int POI_CATEGORY_BEAUTY = 170000;
    public static final int POI_CATEGORY_CAR = 190000;
    public static final int POI_CATEGORY_CULTURE = 230000;
    public static final int POI_CATEGORY_ESTATE = 280000;
    public static final int POI_CATEGORY_FOOD = 100000;
    public static final int POI_CATEGORY_HEALTH = 200000;
    public static final int POI_CATEGORY_HOTEL = 210000;
    public static final int POI_CATEGORY_INFRA = 270000;
    public static final int POI_CATEGORY_PLACE = 260000;
    public static final int POI_CATEGORY_POI_COM = 110000;
    public static final int POI_CATEGORY_POI_ENTM = 160000;
    public static final int POI_CATEGORY_POI_ORG = 120000;
    public static final int POI_CATEGORY_POI_SERVICE = 140000;
    public static final int POI_CATEGORY_POI_SHOPPING = 130000;
    public static final int POI_CATEGORY_SCHOOL = 240000;
    public static final int POI_CATEGORY_SPORT = 180000;
    public static final int POI_CATEGORY_TOUR = 220000;
    public static final int POI_SORT_BY_DISTANCE = 0;
    public static final int POI_SORT_BY_HOT = 1;
    public static final int UIN_EMAIL = 1;
    public static final int UIN_MOBILE = 2;
    public static final int UIN_QQ = 0;

    /* JADX INFO: renamed from: a */
    private C1072j f5895a;

    public QLBSService(Context context, QLBSNotification qLBSNotification, String str, String str2, String str3) {
        this.f5895a = null;
        this.f5895a = new C1072j(context, qLBSNotification, str, str2, str3);
    }

    public int getCarrierId() {
        return this.f5895a.m2572e();
    }

    public QLBSCellInfo getCellInfo() {
        return this.f5895a.m2573f();
    }

    public byte[] getDeviceData() {
        return this.f5895a.m2570c();
    }

    public QLBSGPSInfo getGps() {
        return this.f5895a.m2576i();
    }

    public QLBSCellInfo getSingleCellInfo() {
        return this.f5895a.m2574g();
    }

    public ArrayList getWifi() {
        return this.f5895a.m2575h();
    }

    public boolean isGpsEnabled() {
        return this.f5895a.m2571d();
    }

    public void release() {
        this.f5895a.m2562a();
        this.f5895a = null;
    }

    public boolean requestGetCurrentPosition(int i, String str, int i2) {
        return this.f5895a.m2565a(i, str, i2);
    }

    public boolean requestGetNearPoiList(int i, String str, int i2, int i3, int i4, int i5, ArrayList arrayList, int i6) {
        return this.f5895a.m2567a(i, str, i2, i3, i4, i5, arrayList, i6);
    }

    public boolean requestSearchNearPoiList(int i, String str, int i2, int i3, int i4, int i5, String str2, ArrayList arrayList) {
        return this.f5895a.m2566a(i, str, i2, i3, i4, i5, str2, arrayList);
    }

    public void setGpsEnabled(boolean z) {
        this.f5895a.m2564a(z);
    }

    public void setWifiEnabled(boolean z) {
        this.f5895a.m2569b(z);
    }

    public void startLocation(int i) {
        this.f5895a.m2563a(i);
    }

    public void stopLocation() {
        this.f5895a.m2568b();
    }
}
