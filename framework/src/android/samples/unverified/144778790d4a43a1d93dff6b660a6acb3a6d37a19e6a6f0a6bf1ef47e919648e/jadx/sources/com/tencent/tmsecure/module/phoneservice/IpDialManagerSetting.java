package com.tencent.tmsecure.module.phoneservice;

import java.io.Serializable;

/* JADX INFO: loaded from: classes.dex */
public final class IpDialManagerSetting implements Serializable {

    /* JADX INFO: renamed from: f */
    private static final long f6173f = 1;

    /* JADX INFO: renamed from: a */
    int f6174a;

    /* JADX INFO: renamed from: b */
    public String f6175b;

    /* JADX INFO: renamed from: c */
    IpDialProvinceCity f6176c;

    /* JADX INFO: renamed from: d */
    IpDialProvinceCityList f6177d;

    /* JADX INFO: renamed from: e */
    IpDialPhoneNumberList f6178e;

    public IpDialManagerSetting() {
        this.f6174a = 2;
        this.f6175b = "";
        this.f6176c = new IpDialProvinceCity();
        this.f6177d = new IpDialProvinceCityList();
        this.f6178e = new IpDialPhoneNumberList();
    }

    public IpDialManagerSetting(IpDialManagerSetting ipDialManagerSetting) {
        this();
        copyFrom(ipDialManagerSetting);
    }

    public final void copyFrom(IpDialManagerSetting ipDialManagerSetting) {
        if (ipDialManagerSetting != null) {
            this.f6174a = ipDialManagerSetting.f6174a;
            setIpHeader(ipDialManagerSetting.f6175b);
            setLocalPhoneLocation(ipDialManagerSetting.f6176c);
            setExcludedAreaList(ipDialManagerSetting.f6177d);
            setExcludedPhoneNumberList(ipDialManagerSetting.f6178e);
        }
    }

    public final IpDialProvinceCityList getExcludedAreaList() {
        return new IpDialProvinceCityList(this.f6177d);
    }

    public final IpDialPhoneNumberList getExcludedPhoneNumberList() {
        return new IpDialPhoneNumberList(this.f6178e);
    }

    public final int getIpDialMode() {
        return this.f6174a;
    }

    public final String getIpHeader() {
        return this.f6175b;
    }

    public final IpDialProvinceCity getLocalPhoneLocation() {
        return new IpDialProvinceCity(this.f6176c);
    }

    public final void setExcludedAreaList(IpDialProvinceCityList ipDialProvinceCityList) {
        this.f6177d.copyFrom(ipDialProvinceCityList);
    }

    public final void setExcludedPhoneNumberList(IpDialPhoneNumberList ipDialPhoneNumberList) {
        this.f6178e.copyFrom(ipDialPhoneNumberList);
    }

    public final void setIpDialMode(int i) {
        this.f6174a = i;
    }

    public final void setIpHeader(String str) {
        if (str != null) {
            this.f6175b = str;
        }
    }

    public final void setLocalPhoneLocation(IpDialProvinceCity ipDialProvinceCity) {
        this.f6176c.setProvinceCity(ipDialProvinceCity);
    }
}
