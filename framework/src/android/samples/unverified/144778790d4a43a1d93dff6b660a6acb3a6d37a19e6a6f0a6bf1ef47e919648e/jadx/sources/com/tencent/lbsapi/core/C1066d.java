package com.tencent.lbsapi.core;

import android.os.Environment;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.security.MessageDigest;
import java.util.Calendar;

/* JADX INFO: renamed from: com.tencent.lbsapi.core.d */
/* JADX INFO: loaded from: classes.dex */
public class C1066d {
    /* JADX INFO: renamed from: a */
    public static long m2549a() {
        Calendar calendar = Calendar.getInstance();
        calendar.set(1970, 0, 1, 8, 0, 0);
        return (Calendar.getInstance().getTimeInMillis() - calendar.getTimeInMillis()) / 1000;
    }

    /* JADX WARN: Code duplicated, block: B:37:0x002e A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:54:? A[SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    public static Object m2550a(byte[] bArr) throws Throwable {
        ObjectInputStream objectInputStream;
        Throwable th;
        Object object = null;
        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(bArr);
        try {
            objectInputStream = new ObjectInputStream(byteArrayInputStream);
            try {
                try {
                    object = objectInputStream.readObject();
                    try {
                        byteArrayInputStream.close();
                    } catch (IOException e) {
                    }
                    try {
                        objectInputStream.close();
                    } catch (IOException e2) {
                    }
                } catch (Exception e3) {
                    e = e3;
                    e.printStackTrace();
                    try {
                        byteArrayInputStream.close();
                    } catch (IOException e4) {
                    }
                    if (objectInputStream != null) {
                        try {
                            objectInputStream.close();
                        } catch (IOException e5) {
                        }
                    }
                }
            } catch (Throwable th2) {
                th = th2;
                try {
                    byteArrayInputStream.close();
                } catch (IOException e6) {
                }
                if (objectInputStream != null) {
                    throw th;
                }
                try {
                    objectInputStream.close();
                    throw th;
                } catch (IOException e7) {
                    throw th;
                }
            }
        } catch (Exception e8) {
            e = e8;
            objectInputStream = null;
        } catch (Throwable th3) {
            objectInputStream = null;
            th = th3;
            byteArrayInputStream.close();
            if (objectInputStream != null) {
                throw th;
            }
            objectInputStream.close();
            throw th;
        }
        return object;
    }

    /* JADX WARN: Code duplicated, block: B:33:0x0040 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    public static void m2551a(String str, byte[] bArr) throws Throwable {
        FileOutputStream fileOutputStream;
        FileOutputStream fileOutputStream2 = null;
        try {
            fileOutputStream = new FileOutputStream(Environment.getExternalStorageDirectory() + "//" + str);
            try {
                try {
                    fileOutputStream.write(bArr);
                    try {
                        fileOutputStream.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } catch (Exception e2) {
                    e = e2;
                    e.printStackTrace();
                    if (fileOutputStream != null) {
                        try {
                            fileOutputStream.close();
                        } catch (IOException e3) {
                            e3.printStackTrace();
                        }
                    }
                }
            } catch (Throwable th) {
                th = th;
                fileOutputStream2 = fileOutputStream;
                if (fileOutputStream2 != null) {
                    try {
                        fileOutputStream2.close();
                    } catch (IOException e4) {
                        e4.printStackTrace();
                    }
                }
                throw th;
            }
        } catch (Exception e5) {
            e = e5;
            fileOutputStream = null;
        } catch (Throwable th2) {
            th = th2;
            if (fileOutputStream2 != null) {
                fileOutputStream2.close();
            }
            throw th;
        }
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m2552a(JceStruct jceStruct) {
        JceOutputStream jceOutputStream = new JceOutputStream();
        jceStruct.writeTo(jceOutputStream);
        return jceOutputStream.toByteArray();
    }

    /* JADX WARN: Code duplicated, block: B:48:0x0033 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:55:? A[SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    public static byte[] m2553a(Object obj) throws Throwable {
        ObjectOutputStream objectOutputStream;
        Throwable th;
        byte[] byteArray = null;
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream(4096);
        try {
            try {
                objectOutputStream = new ObjectOutputStream(byteArrayOutputStream);
                try {
                    objectOutputStream.writeObject(obj);
                    byteArray = byteArrayOutputStream.toByteArray();
                    try {
                        byteArrayOutputStream.close();
                    } catch (IOException e) {
                    }
                    try {
                        objectOutputStream.close();
                    } catch (IOException e2) {
                    }
                } catch (IOException e3) {
                    e = e3;
                    e.printStackTrace();
                    try {
                        byteArrayOutputStream.close();
                    } catch (IOException e4) {
                    }
                    if (objectOutputStream != null) {
                        try {
                            objectOutputStream.close();
                        } catch (IOException e5) {
                        }
                    }
                }
            } catch (Throwable th2) {
                th = th2;
                try {
                    byteArrayOutputStream.close();
                } catch (IOException e6) {
                }
                if (objectOutputStream != null) {
                    throw th;
                }
                try {
                    objectOutputStream.close();
                    throw th;
                } catch (IOException e7) {
                    throw th;
                }
            }
        } catch (IOException e8) {
            e = e8;
            objectOutputStream = null;
        } catch (Throwable th3) {
            objectOutputStream = null;
            th = th3;
            byteArrayOutputStream.close();
            if (objectOutputStream != null) {
                throw th;
            }
            objectOutputStream.close();
            throw th;
        }
        return byteArray;
    }

    /* JADX WARN: Code duplicated, block: B:38:0x0059 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r2v1, types: [java.lang.String] */
    /* JADX WARN: Type inference failed for: r2v10 */
    /* JADX WARN: Type inference failed for: r2v11 */
    /* JADX WARN: Type inference failed for: r2v12 */
    /* JADX WARN: Type inference failed for: r2v2 */
    /* JADX WARN: Type inference failed for: r2v4, types: [java.io.FileInputStream] */
    /* JADX WARN: Type inference failed for: r2v5 */
    /* JADX WARN: Type inference failed for: r2v7 */
    /* JADX WARN: Type inference failed for: r2v9 */
    /* JADX INFO: renamed from: a */
    public static byte[] m2554a(String str) throws Throwable {
        Throwable th;
        FileInputStream fileInputStream;
        byte[] bArr = null;
        ?? r2 = "//";
        File file = new File(Environment.getExternalStorageDirectory() + "//" + str);
        if (file.exists()) {
            byte[] bArr2 = new byte[(int) (file.length() + 200)];
            try {
                try {
                    fileInputStream = new FileInputStream(file);
                    try {
                        fileInputStream.read(bArr2);
                        try {
                            fileInputStream.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                        bArr = bArr2;
                        r2 = fileInputStream;
                    } catch (Exception e2) {
                        e = e2;
                        e.printStackTrace();
                        r2 = fileInputStream;
                        if (fileInputStream != null) {
                            try {
                                fileInputStream.close();
                                r2 = fileInputStream;
                            } catch (IOException e3) {
                                e3.printStackTrace();
                                r2 = fileInputStream;
                            }
                        }
                    }
                } catch (Throwable th2) {
                    th = th2;
                    if (r2 != 0) {
                        try {
                            r2.close();
                        } catch (IOException e4) {
                            e4.printStackTrace();
                        }
                    }
                    throw th;
                }
            } catch (Exception e5) {
                e = e5;
                fileInputStream = null;
            } catch (Throwable th3) {
                r2 = 0;
                th = th3;
                if (r2 != 0) {
                    r2.close();
                }
                throw th;
            }
        }
        return bArr;
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m2555a(byte[] bArr, String str, String str2) {
        String str3 = str + m2558c(str2);
        try {
            MessageDigest messageDigest = MessageDigest.getInstance("MD5");
            messageDigest.update(str3.getBytes());
            byte[] bArrDigest = messageDigest.digest();
            char[] cArr = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            char[] cArr2 = new char[bArrDigest.length * 2];
            int i = 0;
            for (byte b : bArrDigest) {
                int i2 = i + 1;
                cArr2[i] = cArr[(b >> 4) & 15];
                i = i2 + 1;
                cArr2[i2] = cArr[b & 15];
            }
            return new C1065c().m2548b(bArr, bArrDigest);
        } catch (Exception e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: b */
    public static void m2556b(String str) {
        File file = new File(Environment.getExternalStorageDirectory() + "//" + str);
        if (file.exists()) {
            file.delete();
        }
    }

    /* JADX INFO: renamed from: b */
    public static byte[] m2557b(byte[] bArr, String str, String str2) {
        String str3 = str + m2558c(str2);
        try {
            MessageDigest messageDigest = MessageDigest.getInstance("MD5");
            messageDigest.update(str3.getBytes());
            byte[] bArrDigest = messageDigest.digest();
            char[] cArr = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            char[] cArr2 = new char[bArrDigest.length * 2];
            int i = 0;
            for (byte b : bArrDigest) {
                int i2 = i + 1;
                cArr2[i] = cArr[(b >> 4) & 15];
                i = i2 + 1;
                cArr2[i2] = cArr[b & 15];
            }
            return new C1065c().m2546a(bArr, bArrDigest);
        } catch (Exception e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: c */
    public static String m2558c(String str) {
        char[] cArr = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        try {
            byte[] bytes = str.getBytes();
            MessageDigest messageDigest = MessageDigest.getInstance("MD5");
            messageDigest.update(bytes);
            byte[] bArrDigest = messageDigest.digest();
            char[] cArr2 = new char[bArrDigest.length * 2];
            int i = 0;
            for (byte b : bArrDigest) {
                int i2 = i + 1;
                cArr2[i] = cArr[(b >> 4) & 15];
                i = i2 + 1;
                cArr2[i2] = cArr[b & 15];
            }
            return new String(cArr2);
        } catch (Exception e) {
            return "";
        }
    }
}
