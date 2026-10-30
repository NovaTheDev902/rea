package com.tencent.tmsecure.module.tools;

/* JADX INFO: loaded from: classes.dex */
public interface IPackageChangedListener {
    void onPackageAdded(String str);

    void onPackageReinstall(String str);

    void onPackageRemoved(String str);
}
