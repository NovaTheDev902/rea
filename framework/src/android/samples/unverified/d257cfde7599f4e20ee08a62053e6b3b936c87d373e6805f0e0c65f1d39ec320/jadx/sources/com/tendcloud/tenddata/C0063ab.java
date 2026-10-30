package com.tendcloud.tenddata;

import android.content.Context;
import android.telephony.gsm.GsmCellLocation;
import java.io.File;

/* JADX INFO: renamed from: com.tendcloud.tenddata.ab */
/* JADX INFO: loaded from: classes.dex */
class C0063ab {
    private C0063ab() {
    }

    /* JADX INFO: renamed from: a */
    static long m52a(Context context) {
        try {
            return context.getPackageManager().getPackageInfo(context.getPackageName(), 64).firstInstallTime;
        } catch (Exception e) {
            return -1L;
        }
    }

    /* JADX INFO: renamed from: a */
    static long m53a(GsmCellLocation gsmCellLocation) {
        try {
            return gsmCellLocation.getPsc();
        } catch (Exception e) {
            return -1L;
        }
    }

    /* JADX INFO: renamed from: a */
    static void m54a(File file) {
        file.setReadable(true, false);
    }

    /* JADX INFO: renamed from: b */
    static long m55b(Context context) {
        try {
            return context.getPackageManager().getPackageInfo(context.getPackageName(), 64).lastUpdateTime;
        } catch (Exception e) {
            return -1L;
        }
    }
}
