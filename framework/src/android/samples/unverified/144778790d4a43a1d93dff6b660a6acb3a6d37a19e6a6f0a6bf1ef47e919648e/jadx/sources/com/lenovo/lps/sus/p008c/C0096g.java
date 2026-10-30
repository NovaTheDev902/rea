package com.lenovo.lps.sus.p008c;

import android.os.Environment;
import android.os.StatFs;
import java.io.File;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: com.lenovo.lps.sus.c.g */
/* JADX INFO: loaded from: classes.dex */
public class C0096g {
    /* JADX INFO: renamed from: a */
    public static boolean m405a() {
        return Environment.getExternalStorageState().equals("mounted") || new C0091b().m320a() > 0;
    }

    /* JADX INFO: renamed from: b */
    public static String m406b() {
        List<C0093d> listM321b = new C0091b().m321b();
        if (listM321b == null || listM321b.size() == 0) {
            if (Environment.getExternalStorageDirectory() == null) {
                return null;
            }
            return Environment.getExternalStorageDirectory().getAbsolutePath();
        }
        for (C0093d c0093d : listM321b) {
            if (c0093d.f1366c / 1024 > 10) {
                return c0093d.f1364a;
            }
        }
        return ((C0093d) listM321b.get(0)).f1364a;
    }

    /* JADX INFO: renamed from: c */
    public static long m407c() {
        List listM321b = new C0091b().m321b();
        if (listM321b == null || listM321b.size() == 0) {
            return m408d();
        }
        long j = 0;
        Iterator it = listM321b.iterator();
        while (true) {
            long j2 = j;
            if (!it.hasNext()) {
                return j2;
            }
            j = j2 + ((C0093d) it.next()).f1366c;
        }
    }

    /* JADX INFO: renamed from: d */
    public static long m408d() {
        try {
            File externalStorageDirectory = Environment.getExternalStorageDirectory();
            if (externalStorageDirectory != null) {
                StatFs statFs = new StatFs(externalStorageDirectory.getPath());
                return (((long) statFs.getAvailableBlocks()) * ((long) statFs.getBlockSize())) / 1024;
            }
        } catch (Exception e) {
        }
        return 0L;
    }
}
