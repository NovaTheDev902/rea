package com.lenovo.safecenter.systeminfo.entity;

import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ListModel<T> {
    public static final int STYLE_FOOTER = 1;
    public static final int STYLE_HEADER_FOOTER = 0;

    /* JADX INFO: renamed from: a */
    private boolean f5609a;

    /* JADX INFO: renamed from: b */
    private List<T> f5610b;

    /* JADX INFO: renamed from: c */
    private String f5611c;

    /* JADX INFO: renamed from: d */
    private int f5612d;

    public ListModel(List<T> paramList, String paramString, int paramInt) {
        this.f5609a = true;
        this.f5611c = null;
        this.f5612d = 1;
        this.f5610b = paramList;
        this.f5611c = paramString;
        this.f5612d = paramInt;
    }

    public ListModel(List<T> dataList, String headerText, int style, boolean showListNum) {
        this.f5609a = true;
        this.f5611c = null;
        this.f5612d = 1;
        this.f5610b = dataList;
        this.f5611c = headerText;
        this.f5612d = style;
        this.f5609a = showListNum;
    }

    public List<T> getDataList() {
        return this.f5610b;
    }

    public String getHeaderLabel() {
        return this.f5611c;
    }

    public List<ItemModel> getItemModelList() {
        if (this.f5612d == 0) {
            ArrayList arrayList = new ArrayList();
            String str = this.f5611c + (this.f5609a ? "(" + this.f5610b.size() + ")" : "");
            if (this.f5610b.size() > 0) {
                ItemModel itemModel = new ItemModel();
                if (this.f5611c != null) {
                    itemModel.setHeaderLabel(str);
                }
                itemModel.setItemStyle(0);
                arrayList.add(itemModel);
            }
            return arrayList;
        }
        return getListMiddle();
    }

    public List<ItemModel> getListMiddle() {
        ArrayList arrayList = new ArrayList();
        for (T t : this.f5610b) {
            ItemModel itemModel = new ItemModel();
            itemModel.setHeaderLabel(t.getContextMenuName());
            arrayList.add(itemModel);
        }
        return arrayList;
    }

    public int getStyle() {
        return this.f5612d;
    }

    public boolean isShowListNumber() {
        return this.f5609a;
    }

    public void setDataList(List<T> paramList) {
        this.f5610b = paramList;
    }

    public void setHeaderLabel(String paramString) {
        this.f5611c = paramString;
    }

    public void setShowListNumber(boolean paramBoolean) {
        this.f5609a = paramBoolean;
    }

    public void setStyle(int paramInt) {
        this.f5612d = paramInt;
    }
}
