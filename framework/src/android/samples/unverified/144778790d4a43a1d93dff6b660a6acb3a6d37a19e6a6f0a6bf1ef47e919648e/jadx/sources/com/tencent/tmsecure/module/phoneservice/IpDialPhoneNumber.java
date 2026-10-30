package com.tencent.tmsecure.module.phoneservice;

import java.io.Serializable;

/* JADX INFO: loaded from: classes.dex */
public final class IpDialPhoneNumber implements Serializable {

    /* JADX INFO: renamed from: c */
    private static final long f6179c = 1;

    /* JADX INFO: renamed from: a */
    String f6180a;

    /* JADX INFO: renamed from: b */
    String f6181b;

    public IpDialPhoneNumber() {
        this.f6180a = "";
        this.f6181b = "";
    }

    public IpDialPhoneNumber(IpDialPhoneNumber ipDialPhoneNumber) {
        this(ipDialPhoneNumber.f6180a, ipDialPhoneNumber.f6181b);
    }

    public IpDialPhoneNumber(String str, String str2) {
        this.f6180a = str;
        this.f6181b = str2;
    }

    public final String getName() {
        return this.f6180a;
    }

    public final String getPhoneNumber() {
        return this.f6181b;
    }

    public final void setName(String str) {
        this.f6180a = str;
    }

    public final void setNamePhoneNumber(IpDialPhoneNumber ipDialPhoneNumber) {
        this.f6180a = ipDialPhoneNumber.f6180a;
        this.f6181b = ipDialPhoneNumber.f6181b;
    }

    public final void setPhoneNumber(String str) {
        this.f6181b = str;
    }
}
