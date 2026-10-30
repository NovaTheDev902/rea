package com.lenovo.lps.sus.p008c;

import android.os.StatFs;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: renamed from: com.lenovo.lps.sus.c.b */
/* JADX INFO: loaded from: classes.dex */
public class C0091b {

    /* JADX INFO: renamed from: a */
    List f1269a;

    public C0091b() throws Throwable {
        m322c();
    }

    /* JADX WARN: Code duplicated, block: B:31:0x00de A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:32:0x00e0 A[Catch: IOException -> 0x00e4, TRY_LEAVE, TryCatch #6 {IOException -> 0x00e4, blocks: (B:30:0x00db, B:32:0x00e0), top: B:52:0x00db }] */
    /* JADX WARN: Code duplicated, block: B:52:0x00db A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    private static void m319a(InterfaceC0097h interfaceC0097h) throws Throwable {
        BufferedReader bufferedReader;
        FileReader fileReader;
        FileReader fileReader2 = null;
        File file = new File("/system/etc/vold.fstab");
        if (!file.exists()) {
            return;
        }
        try {
            fileReader = new FileReader(file);
            try {
                bufferedReader = new BufferedReader(fileReader);
                try {
                    for (String line = bufferedReader.readLine(); line != null; line = bufferedReader.readLine()) {
                        if (line.startsWith("dev_mount")) {
                            String str = line.split("\\s")[2];
                            StatFs statFs = new StatFs(str);
                            if (statFs.getAvailableBlocks() > 0) {
                                C0093d c0093d = new C0093d();
                                c0093d.f1367d = statFs.getAvailableBlocks();
                                c0093d.f1366c = (Long.parseLong(new StringBuilder().append(statFs.getAvailableBlocks()).toString()) * Long.parseLong(new StringBuilder().append(statFs.getBlockSize()).toString())) / Long.parseLong("1024");
                                c0093d.f1365b = (Long.parseLong(new StringBuilder().append(statFs.getBlockCount()).toString()) * Long.parseLong(new StringBuilder().append(statFs.getBlockSize()).toString())) / Long.parseLong("1024");
                                c0093d.f1364a = str;
                                interfaceC0097h.mo404a(c0093d);
                            }
                        }
                    }
                    try {
                        fileReader.close();
                        bufferedReader.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } catch (Exception e2) {
                    e = e2;
                    fileReader2 = fileReader;
                    try {
                        e.printStackTrace();
                        if (fileReader2 != null) {
                            try {
                                fileReader2.close();
                            } catch (IOException e3) {
                                e3.printStackTrace();
                                return;
                            }
                        }
                        if (bufferedReader != null) {
                            bufferedReader.close();
                        }
                    } catch (Throwable th) {
                        th = th;
                        fileReader = fileReader2;
                        if (fileReader != null) {
                            try {
                                fileReader.close();
                                if (bufferedReader != null) {
                                    bufferedReader.close();
                                }
                            } catch (IOException e4) {
                                e4.printStackTrace();
                                throw th;
                            }
                        } else if (bufferedReader != null) {
                            bufferedReader.close();
                        }
                        throw th;
                    }
                } catch (Throwable th2) {
                    th = th2;
                    if (fileReader != null) {
                        fileReader.close();
                        if (bufferedReader != null) {
                            bufferedReader.close();
                        }
                    } else if (bufferedReader != null) {
                        bufferedReader.close();
                    }
                    throw th;
                }
            } catch (Exception e5) {
                e = e5;
                bufferedReader = null;
                fileReader2 = fileReader;
            } catch (Throwable th3) {
                th = th3;
                bufferedReader = null;
            }
        } catch (Exception e6) {
            e = e6;
            bufferedReader = null;
        } catch (Throwable th4) {
            th = th4;
            bufferedReader = null;
            fileReader = null;
        }
    }

    /* JADX INFO: renamed from: a */
    public int m320a() {
        if (this.f1269a == null) {
            return 0;
        }
        return this.f1269a.size();
    }

    /* JADX INFO: renamed from: b */
    public List m321b() {
        return this.f1269a;
    }

    /* JADX INFO: renamed from: c */
    public void m322c() throws Throwable {
        ArrayList arrayList = new ArrayList();
        m319a(new C0095f(this, arrayList));
        this.f1269a = arrayList;
    }
}
