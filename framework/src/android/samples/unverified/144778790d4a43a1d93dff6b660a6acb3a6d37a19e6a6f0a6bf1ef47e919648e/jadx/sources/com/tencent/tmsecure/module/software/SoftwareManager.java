package com.tencent.tmsecure.module.software;

import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageManager;
import com.tencent.tmsecure.common.BaseManager;
import java.io.File;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import tms.C1307gl;

/* JADX INFO: loaded from: classes.dex */
public final class SoftwareManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1307gl f6230a;

    public final boolean canMoveToSdcard(String str, boolean z) {
        if (isExpired()) {
            return false;
        }
        return this.f6230a.m3406a(str, z);
    }

    public final void clearUsageInfo() {
        if (isExpired()) {
            return;
        }
        this.f6230a.m3402a();
    }

    public final AppEntity getApkInfo(AppEntity appEntity, int i) {
        return isExpired() ? new AppEntity() : this.f6230a.m3407b(appEntity, i);
    }

    public final AppEntity getApkInfo(String str, int i) {
        return isExpired() ? new AppEntity() : this.f6230a.m3412c(str, i);
    }

    public final ArrayList<AppEntity> getApkList(File file, String[] strArr, boolean z, int i) {
        return isExpired() ? new ArrayList<>() : this.f6230a.m3398a(file, strArr, z, i);
    }

    public final ArrayList<AppEntity> getApkList(File file, String[] strArr, boolean z, int i, boolean z2) {
        return isExpired() ? new ArrayList<>() : this.f6230a.m3399a(file, strArr, z, i, z2);
    }

    public final ArrayList<AppEntity> getApkListFromSDCard(String[] strArr, boolean z, int i) {
        return isExpired() ? new ArrayList<>() : this.f6230a.m3401a(strArr, z, i);
    }

    public final AppEntity getAppInfo(AppEntity appEntity, int i) {
        return isExpired() ? new AppEntity() : this.f6230a.m3395a(appEntity, i);
    }

    public final AppEntity getAppInfo(String str, int i) {
        return isExpired() ? new AppEntity() : this.f6230a.m3408b(str, i);
    }

    public final int getAppVersionStatus(String str, int i) {
        if (isExpired()) {
            return -2;
        }
        return this.f6230a.m3394a(str, i);
    }

    public final ArrayList<AppEntity> getAppsCanMovable(int i, int i2, boolean z) {
        return isExpired() ? new ArrayList<>() : this.f6230a.m3397a(i, i2, z);
    }

    public final ArrayList<AppEntity> getInstalledApp(int i, int i2) {
        return isExpired() ? new ArrayList<>() : this.f6230a.m3396a(i, i2);
    }

    public final SoftwareUseageInfo getUseageInfo(String str) {
        return isExpired() ? new SoftwareUseageInfo("", new Date(), new Date(), 0) : this.f6230a.m3419i(str);
    }

    public final ArrayList<SoftwareUseageInfo> getUseageInfo(List<String> list) {
        return isExpired() ? new ArrayList<>() : this.f6230a.m3400a(list);
    }

    public final void goToInstalledAppDetails(String str) {
        if (isExpired()) {
            return;
        }
        this.f6230a.m3414d(str);
    }

    public final void installApp(File file) {
        if (isExpired()) {
            return;
        }
        this.f6230a.m3403a(file);
    }

    public final void installApp(String str, Activity activity, int i) {
        if (isExpired()) {
            return;
        }
        this.f6230a.m3404a(str, activity, i);
    }

    public final boolean installAppSilently(String str) {
        if (isExpired()) {
            return false;
        }
        return this.f6230a.m3411b(str);
    }

    public final boolean isInstalledSdcard(String str) {
        if (isExpired()) {
            return false;
        }
        return this.f6230a.m3416f(str);
    }

    public final boolean isPackageInstalled(String str) {
        if (isExpired()) {
            return false;
        }
        return this.f6230a.m3405a(str);
    }

    public final boolean movePackageToExternal(String str) throws PackageManager.NameNotFoundException {
        if (isExpired()) {
            return false;
        }
        return this.f6230a.m3418h(str);
    }

    public final boolean movePackageToInteranl(String str) throws PackageManager.NameNotFoundException {
        if (isExpired()) {
            return false;
        }
        return this.f6230a.m3417g(str);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6230a = new C1307gl();
        this.f6230a.onCreate(context);
        setImpl(this.f6230a);
    }

    public final boolean packageHasActiveAdmins(String str) {
        return this.f6230a.m3420j(str);
    }

    public final void refleshUsageInfo() {
        if (isExpired()) {
            return;
        }
        this.f6230a.m3409b();
    }

    public final boolean startUpApp(String str) {
        if (isExpired()) {
            return false;
        }
        return this.f6230a.m3415e(str);
    }

    public final void uninstallApp(String str, Activity activity, int i) {
        if (isExpired()) {
            return;
        }
        this.f6230a.m3410b(str, activity, i);
    }

    public final boolean uninstallAppSilently(String str) {
        if (isExpired()) {
            return false;
        }
        return this.f6230a.m3413c(str);
    }
}
