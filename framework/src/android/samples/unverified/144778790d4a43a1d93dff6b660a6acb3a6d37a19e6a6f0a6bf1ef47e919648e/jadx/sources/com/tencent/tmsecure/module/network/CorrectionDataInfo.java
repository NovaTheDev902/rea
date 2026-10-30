package com.tencent.tmsecure.module.network;

/* JADX INFO: loaded from: classes.dex */
public final class CorrectionDataInfo {

    /* JADX INFO: renamed from: a */
    private String f6099a = "";

    /* JADX INFO: renamed from: b */
    private String f6100b = "";

    public CorrectionDataInfo() {
    }

    public CorrectionDataInfo(String str, String str2) {
        setAddress(str);
        setMessage(str2);
    }

    public final String getAddress() {
        return this.f6099a;
    }

    public final String getMessage() {
        return this.f6100b;
    }

    public final void setAddress(String str) {
        if (str == null) {
            str = "";
        }
        this.f6099a = str;
    }

    public final void setMessage(String str) {
        if (str == null) {
            str = "";
        }
        this.f6100b = str;
    }
}
