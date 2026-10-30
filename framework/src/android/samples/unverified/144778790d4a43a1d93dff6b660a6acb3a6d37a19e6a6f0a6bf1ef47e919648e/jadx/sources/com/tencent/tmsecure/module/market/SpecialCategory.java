package com.tencent.tmsecure.module.market;

import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class SpecialCategory {
    public CategoryEx categoryEx;
    public ArrayList<SoftSimpleInfoEx> softSimpleInfoExList;

    public CategoryEx getCategoryEx() {
        return this.categoryEx;
    }

    public ArrayList<SoftSimpleInfoEx> getSoftSimpleInfoExList() {
        return this.softSimpleInfoExList;
    }

    public void setCategoryEx(CategoryEx categoryEx) {
        this.categoryEx = categoryEx;
    }

    public void setSoftSimpleInfoExList(ArrayList<SoftSimpleInfoEx> arrayList) {
        this.softSimpleInfoExList = arrayList;
    }
}
