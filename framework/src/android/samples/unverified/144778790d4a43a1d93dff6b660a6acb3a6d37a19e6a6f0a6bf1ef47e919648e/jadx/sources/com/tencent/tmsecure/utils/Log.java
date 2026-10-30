package com.tencent.tmsecure.utils;

import android.os.Environment;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import tms.C1321hj;
import tms.C1322hk;
import tms.InterfaceC1317hd;

/* JADX INFO: loaded from: classes.dex */
public final class Log {

    /* JADX INFO: renamed from: a */
    static final String f6272a = "QQPimSecure";

    /* JADX INFO: renamed from: b */
    static final String f6273b = "/sdcard/qqpimsecure_debug.txt";

    /* JADX INFO: renamed from: c */
    private static boolean f6274c = true;

    /* JADX INFO: renamed from: d */
    private static InterfaceC1317hd f6275d = new C1321hj();

    /* JADX INFO: renamed from: e */
    public static void m2634e(String str, Object obj) {
        if (obj == null) {
            android.util.Log.e(str, "log message is null");
        } else if (obj instanceof Exception) {
            ((Exception) obj).printStackTrace();
        } else {
            f6275d.mo3503b(str, obj.toString());
        }
    }

    /* JADX INFO: renamed from: f */
    public static void m2635f(String str, Object obj) {
        if (obj == null) {
            android.util.Log.e(str, "log message is null");
        } else {
            f6275d.mo3504c(str, obj.toString());
        }
    }

    /* JADX INFO: renamed from: i */
    public static void m2636i(String str, Object obj) {
        if (obj == null) {
            android.util.Log.e(str, "log message is null");
        } else {
            f6275d.mo3502a(str, obj.toString());
        }
    }

    public static boolean isEnable() {
        return f6274c;
    }

    public static void setLogEnable(boolean z) {
        f6274c = z;
        if (f6274c) {
            f6275d = new C1321hj();
        } else {
            f6275d = new C1322hk();
        }
    }

    public static void writeLog(String str) {
        FileOutputStream fileOutputStream;
        FileOutputStream fileOutputStream2 = null;
        try {
            try {
                if ("mounted".equals(Environment.getExternalStorageState())) {
                    File file = new File(f6273b);
                    if (!file.exists()) {
                        file.createNewFile();
                    }
                    fileOutputStream = new FileOutputStream(file, true);
                    try {
                        fileOutputStream.write(str.getBytes());
                    } catch (FileNotFoundException e) {
                        e = e;
                        fileOutputStream2 = fileOutputStream;
                        android.util.Log.e(f6272a, "file not found");
                        e.printStackTrace();
                        if (fileOutputStream2 != null) {
                            try {
                                fileOutputStream2.close();
                                return;
                            } catch (IOException e2) {
                                e = e2;
                                e.printStackTrace();
                            }
                        }
                        return;
                    } catch (IOException e3) {
                        e = e3;
                        fileOutputStream2 = fileOutputStream;
                        android.util.Log.e(f6272a, "io exception");
                        e.printStackTrace();
                        if (fileOutputStream2 != null) {
                            try {
                                fileOutputStream2.close();
                                return;
                            } catch (IOException e4) {
                                e = e4;
                                e.printStackTrace();
                            }
                        }
                        return;
                    } catch (Exception e5) {
                        e = e5;
                        fileOutputStream2 = fileOutputStream;
                        android.util.Log.e(f6272a, "runtime error");
                        e.printStackTrace();
                        if (fileOutputStream2 != null) {
                            try {
                                fileOutputStream2.close();
                                return;
                            } catch (IOException e6) {
                                e = e6;
                                e.printStackTrace();
                            }
                        }
                        return;
                    } catch (Throwable th) {
                        th = th;
                        fileOutputStream2 = fileOutputStream;
                        if (fileOutputStream2 != null) {
                            try {
                                fileOutputStream2.close();
                            } catch (IOException e7) {
                                e7.printStackTrace();
                            }
                        }
                        throw th;
                    }
                } else {
                    fileOutputStream = null;
                }
                if (fileOutputStream != null) {
                    try {
                        fileOutputStream.close();
                    } catch (IOException e8) {
                        e = e8;
                        e.printStackTrace();
                    }
                }
            } catch (Throwable th2) {
                th = th2;
            }
        } catch (FileNotFoundException e9) {
            e = e9;
        } catch (IOException e10) {
            e = e10;
        } catch (Exception e11) {
            e = e11;
        }
    }
}
