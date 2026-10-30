package com.lenovo.performancecenter.service.object;

/* JADX INFO: loaded from: classes.dex */
public class UsedAppInfo {
    public int memroy;
    public String packageName;

    public UsedAppInfo(String packageName, int memory) {
        this.packageName = packageName;
        this.memroy = memory;
    }
}
