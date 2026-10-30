package com.tencent.tmsecure.module.qscanner;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.ArrayList;
import java.util.List;
import tms.C1306gi;

/* JADX INFO: loaded from: classes.dex */
public final class QScannerManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1306gi f6228a;

    public static String getVirusBaseVersion(Context context) {
        return C1306gi.m3360a(context);
    }

    public final void cancelScan() {
        if (isExpired()) {
            return;
        }
        this.f6228a.m3387f();
    }

    public final ArrayList<QScanResultEntity> cloudScan(ArrayList<QScanResultEntity> arrayList, QScanListener qScanListener) {
        return isExpired() ? new ArrayList<>() : this.f6228a.m3376a(arrayList, qScanListener);
    }

    public final void continueScan() {
        if (isExpired()) {
            return;
        }
        this.f6228a.m3386e();
    }

    public final void freeScanner() {
        if (isExpired()) {
            return;
        }
        this.f6228a.m3382b();
    }

    public final int getApkClass(String str) {
        if (isExpired() || this.f6228a == null) {
            return 0;
        }
        return this.f6228a.m3373a(str);
    }

    public final void initScanner() {
        if (isExpired()) {
            return;
        }
        this.f6228a.m3378a();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6228a = new C1306gi();
        this.f6228a.onCreate(context);
        setImpl(this.f6228a);
    }

    public final void pauseScan() {
        if (isExpired()) {
            return;
        }
        this.f6228a.m3385d();
    }

    public final ArrayList<QScanResultEntity> scanApks(List<String> list, QScanListener qScanListener, boolean z) {
        return isExpired() ? new ArrayList<>() : this.f6228a.m3381b(list, qScanListener, z);
    }

    public final ArrayList<QScanResultEntity> scanGlobal(QScanListener qScanListener, boolean z) {
        return isExpired() ? new ArrayList<>() : this.f6228a.m3383c(qScanListener, z);
    }

    public final ArrayList<QScanResultEntity> scanGlobal(QScanListener qScanListener, boolean z, boolean z2) {
        return isExpired() ? new ArrayList<>() : this.f6228a.m3380b(qScanListener, z, z2);
    }

    public final ArrayList<QScanResultEntity> scanInstalledPackages(QScanListener qScanListener, boolean z) {
        return isExpired() ? new ArrayList<>() : this.f6228a.m3374a(qScanListener, z);
    }

    public final ArrayList<QScanResultEntity> scanPackages(List<String> list, QScanListener qScanListener, boolean z) {
        return isExpired() ? new ArrayList<>() : this.f6228a.m3377a(list, qScanListener, z);
    }

    public final ArrayList<QScanResultEntity> scanSdcardApks(QScanListener qScanListener, boolean z) {
        return isExpired() ? new ArrayList<>() : this.f6228a.m3379b(qScanListener, z);
    }

    public final ArrayList<QScanResultEntity> scanSdcardApks(QScanListener qScanListener, boolean z, boolean z2) {
        return isExpired() ? new ArrayList<>() : this.f6228a.m3375a(qScanListener, z, z2);
    }
}
