package com.lenovo.safecenter.systeminfo.entity;

/* JADX INFO: loaded from: classes.dex */
public class ItemModel {
    public static final int ITEM_STYLE_HEADER = 0;
    public static final int ITEM_STYLE_MIDDLE = 1;

    /* JADX INFO: renamed from: a */
    private String f5607a = null;

    /* JADX INFO: renamed from: b */
    private int f5608b = 1;

    public String getHeaderLabel() {
        return this.f5607a;
    }

    public int getItemStyle() {
        return this.f5608b;
    }

    public void setHeaderLabel(String paramString) {
        this.f5607a = paramString;
    }

    public void setItemStyle(int paramInt) {
        this.f5608b = paramInt;
    }
}
