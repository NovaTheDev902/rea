package com.lenovo.lps.sus.control;

import android.content.pm.IPackageInstallObserver;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.g */
/* JADX INFO: loaded from: classes.dex */
final class C0119g extends IPackageInstallObserver.Stub {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C0136x f1476a;

    C0119g(C0136x c0136x) {
        this.f1476a = c0136x;
    }

    public final void packageInstalled(String str, int i) {
        this.f1476a.f1542d = true;
        this.f1476a.f1547i = Integer.valueOf(i);
        C0098i.m409a(C0092c.f1339b, "InstallThread 1 packageInstalled,mySilenceInstallResultCode=" + this.f1476a.f1547i);
    }
}
