package com.tencent.tmsecure.module.qscanner;

import android.content.Context;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import tms.C1336v;

/* JADX INFO: loaded from: classes.dex */
public class CertChecker {

    /* JADX INFO: renamed from: a */
    private static final String f6216a = "trustcerts.dat";

    /* JADX INFO: renamed from: b */
    private static final String f6217b = "label_tc";

    /* JADX INFO: renamed from: c */
    private Context f6218c;

    /* JADX INFO: renamed from: d */
    private List<ApkKey> f6219d;

    public CertChecker(Context context) {
        this.f6218c = context;
        C1336v.m3577a(this.f6218c, f6216a, (String) null);
        this.f6219d = (List) C1336v.m3587b(this.f6218c, f6217b, f6216a);
        if (this.f6219d == null) {
            this.f6219d = new ArrayList();
        }
    }

    public QScanResult checkCert(QScanResult qScanResult) {
        for (ApkKey apkKey : this.f6219d) {
            ApkKey apkKey2 = qScanResult.apkkey;
            if (apkKey2.pkgName.equals(apkKey.pkgName) && !apkKey2.certMd5.equals(apkKey.certMd5) && qScanResult.type != 3) {
                qScanResult.type = 8;
                qScanResult.advice = 1;
            }
        }
        return qScanResult;
    }

    public int getApkClass(String str) {
        Iterator<ApkKey> it = this.f6219d.iterator();
        while (it.hasNext()) {
            if (it.next().pkgName.equals(str)) {
                return 1;
            }
        }
        return 0;
    }
}
