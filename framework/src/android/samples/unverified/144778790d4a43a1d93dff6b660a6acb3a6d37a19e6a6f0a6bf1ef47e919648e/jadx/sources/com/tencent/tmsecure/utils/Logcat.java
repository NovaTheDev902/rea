package com.tencent.tmsecure.utils;

import com.tencent.tmsecure.common.TMSApplication;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import tms.C1336v;

/* JADX INFO: loaded from: classes.dex */
public final class Logcat {

    /* JADX INFO: renamed from: a */
    private static final String f6276a = "logcat";

    public static void clear() {
        ScriptHelper.runScript("logcat -c");
    }

    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r2v8, types: [java.util.Iterator] */
    public static synchronized ArrayList<String> filter(String str, String str2, String... strArr) {
        ArrayList<String> arrayList;
        DataInputStream dataInputStream;
        StringBuilder sb = new StringBuilder();
        File file = new File(TMSApplication.getApplicaionContext().getCacheDir(), f6276a);
        C1336v.m3583a(file);
        String[] strArr2 = new String[2];
        Object[] objArr = new Object[4];
        objArr[0] = f6276a;
        if (str2 == null) {
            str2 = "-v time";
        }
        objArr[1] = str2;
        objArr[2] = file.getAbsolutePath();
        objArr[3] = str;
        strArr2[0] = String.format("%s -d %s -f %s -s %s:I", objArr);
        strArr2[1] = "chmod 777 " + file.getAbsolutePath();
        ScriptHelper.runScript(sb, strArr2);
        try {
            Thread.sleep(500L);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        arrayList = new ArrayList<>();
        if (file.exists() && file.canRead()) {
            ArrayList arrayList2 = new ArrayList();
            DataInputStream it = 0;
            DataInputStream dataInputStream2 = null;
            try {
                try {
                    try {
                        dataInputStream = new DataInputStream(new FileInputStream(file));
                        while (true) {
                            try {
                                String line = dataInputStream.readLine();
                                if (line == null) {
                                    break;
                                }
                                arrayList2.add(line);
                            } catch (FileNotFoundException e2) {
                                e = e2;
                                e.printStackTrace();
                                if (dataInputStream != null) {
                                    try {
                                        dataInputStream.close();
                                    } catch (IOException e3) {
                                        e3.printStackTrace();
                                    }
                                }
                            } catch (IOException e4) {
                                e = e4;
                                dataInputStream2 = dataInputStream;
                                e.printStackTrace();
                                if (dataInputStream2 != null) {
                                    try {
                                        dataInputStream2.close();
                                    } catch (IOException e5) {
                                        e5.printStackTrace();
                                    }
                                }
                            }
                        }
                        if (dataInputStream != null) {
                            try {
                                dataInputStream.close();
                            } catch (IOException e6) {
                                e6.printStackTrace();
                            }
                        }
                    } catch (Throwable th) {
                        th = th;
                        if (it != 0) {
                            try {
                                it.close();
                            } catch (IOException e7) {
                                e7.printStackTrace();
                            }
                        }
                        throw th;
                    }
                } catch (FileNotFoundException e8) {
                    e = e8;
                    dataInputStream = null;
                } catch (IOException e9) {
                    e = e9;
                }
                it = arrayList2.iterator();
                while (it.hasNext()) {
                    String str3 = (String) it.next();
                    for (String str4 : strArr) {
                        if (str3.contains(str4)) {
                            arrayList.add(str3);
                            break;
                        }
                    }
                }
            } catch (Throwable th2) {
                th = th2;
                it = strArr2;
            }
        }
        return arrayList;
    }

    public static void redirect(File file) {
        ScriptHelper.runScript("logcat -f " + file.toString());
    }
}
