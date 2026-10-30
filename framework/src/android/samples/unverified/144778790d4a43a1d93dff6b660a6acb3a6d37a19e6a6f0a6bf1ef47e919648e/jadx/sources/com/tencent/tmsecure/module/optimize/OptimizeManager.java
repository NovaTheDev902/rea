package com.tencent.tmsecure.module.optimize;

import android.content.Context;
import android.content.pm.PackageManager;
import com.tencent.tmsecure.common.BaseManager;
import java.util.ArrayList;
import java.util.List;
import tms.C1259eh;
import tms.C1260ei;
import tms.C1261ej;
import tms.C1262ek;

/* JADX INFO: loaded from: classes.dex */
public final class OptimizeManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1262ek f6132a;

    /* JADX INFO: renamed from: b */
    private C1259eh f6133b;

    /* JADX INFO: renamed from: c */
    private C1261ej f6134c;

    /* JADX INFO: renamed from: d */
    private C1260ei f6135d;

    public final boolean closeProcess(String str) throws PackageManager.NameNotFoundException {
        if (isExpired()) {
            return false;
        }
        return this.f6132a.m3226a(str);
    }

    public final boolean closeProcess(String str, boolean z, boolean z2) throws PackageManager.NameNotFoundException {
        if (isExpired()) {
            return false;
        }
        return this.f6132a.m3227a(str, z, z2);
    }

    public final boolean closeProcess(List<String> list) throws PackageManager.NameNotFoundException {
        if (isExpired()) {
            return false;
        }
        return this.f6132a.m3228a(list);
    }

    public final boolean closeProcess(List<String> list, boolean z, boolean z2) throws PackageManager.NameNotFoundException {
        while (!isExpired()) {
        }
        return false;
    }

    public final ArrayList<ProcessEntity> getAllRunningProcess(boolean z) {
        return isExpired() ? new ArrayList<>() : this.f6132a.m3225a(z);
    }

    public final synchronized IAutoBootHelper getAutoBootHelper() {
        IAutoBootHelper iAutoBootHelperM3224a;
        if (isExpired()) {
            if (this.f6133b == null) {
                this.f6133b = new C1259eh();
            }
            iAutoBootHelperM3224a = this.f6133b;
        } else {
            iAutoBootHelperM3224a = this.f6132a.m3224a();
        }
        return iAutoBootHelperM3224a;
    }

    public final synchronized ICpuHelper getCpuHelper() {
        ICpuHelper iCpuHelperM3231c;
        ICpuHelper iCpuHelperM3231c2 = this.f6132a.m3231c();
        if (isExpired()) {
            if (this.f6135d == null) {
                this.f6135d = new C1260ei(iCpuHelperM3231c2);
            }
            iCpuHelperM3231c = this.f6135d;
        } else {
            iCpuHelperM3231c = this.f6132a.m3231c();
        }
        return iCpuHelperM3231c;
    }

    public final synchronized IMemoryHelper getMemoryHelper() {
        IMemoryHelper iMemoryHelperM3230b;
        IMemoryHelper iMemoryHelperM3230b2 = this.f6132a.m3230b();
        if (isExpired()) {
            if (this.f6134c == null) {
                this.f6134c = new C1261ej(iMemoryHelperM3230b2);
            }
            iMemoryHelperM3230b = this.f6134c;
        } else {
            iMemoryHelperM3230b = this.f6132a.m3230b();
        }
        return iMemoryHelperM3230b;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6132a = new C1262ek();
        this.f6132a.onCreate(context);
        setImpl(this.f6132a);
    }
}
