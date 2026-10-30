package com.tencent.tmsecure.module.phoneservice;

import java.io.Serializable;

/* JADX INFO: loaded from: classes.dex */
public final class IpDialProvinceCity implements Serializable {

    /* JADX INFO: renamed from: c */
    private static final long f6184c = 1;

    /* JADX INFO: renamed from: a */
    String f6185a;

    /* JADX INFO: renamed from: b */
    String f6186b;

    public IpDialProvinceCity() {
        this.f6185a = "";
        this.f6186b = "";
    }

    public IpDialProvinceCity(IpDialProvinceCity ipDialProvinceCity) {
        this(ipDialProvinceCity.f6185a, ipDialProvinceCity.f6186b);
    }

    public IpDialProvinceCity(String str, String str2) {
        this.f6185a = str == null ? "" : str;
        this.f6186b = str2 == null ? "" : str2;
    }

    public final String getCity() {
        return this.f6186b;
    }

    public final String getProvince() {
        return this.f6185a;
    }

    public final void setCity(String str) {
        if (str != null) {
            this.f6186b = str;
        }
    }

    public final void setProvince(String str) {
        if (str != null) {
            this.f6185a = str;
        }
    }

    public final void setProvinceCity(IpDialProvinceCity ipDialProvinceCity) {
        if (ipDialProvinceCity != null) {
            setProvince(ipDialProvinceCity.f6185a);
            setCity(ipDialProvinceCity.f6186b);
        }
    }
}
