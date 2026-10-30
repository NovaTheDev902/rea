package com.lenovo.lps.sus.control;

import android.content.pm.IPackageInstallObserver;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.i */
/* JADX INFO: loaded from: classes.dex */
final class C0121i extends IPackageInstallObserver.Stub {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C0136x f1478a;

    C0121i(C0136x c0136x) {
        this.f1478a = c0136x;
    }

    public final void packageInstalled(String str, int i) {
        this.f1478a.f1541c = false;
        this.f1478a.f1542d = true;
        this.f1478a.f1547i = Integer.valueOf(i);
        C0098i.m409a(C0092c.f1339b, "InstallThread 2 packageInstalled,mySilenceInstallResultCode=" + this.f1478a.f1547i);
    }
}
