package com.lenovo.safecenter.systeminfo.entity;

/* JADX INFO: loaded from: classes.dex */
public class PhoneInfoItem {

    /* JADX INFO: renamed from: a */
    private int f5613a;

    /* JADX INFO: renamed from: b */
    private String f5614b;

    public PhoneInfoItem() {
    }

    public PhoneInfoItem(int iconRes, String info) {
        this.f5613a = iconRes;
        this.f5614b = info;
    }

    public int getIconRes() {
        return this.f5613a;
    }

    public void setIconRes(int iconRes) {
        this.f5613a = iconRes;
    }

    public String getInfo() {
        return this.f5614b;
    }

    public void setInfo(String info) {
        this.f5614b = info;
    }
}
