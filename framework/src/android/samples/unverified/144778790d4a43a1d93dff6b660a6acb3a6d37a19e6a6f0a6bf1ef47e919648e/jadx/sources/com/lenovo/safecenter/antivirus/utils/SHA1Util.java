package com.lenovo.safecenter.antivirus.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/* JADX INFO: loaded from: classes.dex */
public class SHA1Util {
    protected static char[] hexDigits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    protected static MessageDigest messagedigest;

    static {
        messagedigest = null;
        try {
            messagedigest = MessageDigest.getInstance("SHA-1");
        } catch (NoSuchAlgorithmException nsaex) {
            System.err.println(SHA1Util.class.getName() + "初始化失败，MessageDigest不支持MD5Util。");
            nsaex.printStackTrace();
        }
    }

    public static String getFileMD5String(File file) throws IOException {
        return getFileSha1(file);
    }

    public static String getMD5String(String s) {
        return getMD5String(s.getBytes());
    }

    public static String getMD5String(byte[] bytes) {
        messagedigest.update(bytes);
        return m1331a(messagedigest.digest());
    }

    /* JADX INFO: renamed from: a */
    private static String m1331a(byte[] bytes) {
        int length = bytes.length;
        StringBuffer stringBuffer = new StringBuffer(length * 2);
        int i = length + 0;
        for (int i2 = 0; i2 < i; i2++) {
            byte b = bytes[i2];
            char c = hexDigits[(b & 240) >> 4];
            char c2 = hexDigits[b & 15];
            stringBuffer.append(c);
            stringBuffer.append(c2);
        }
        return stringBuffer.toString();
    }

    public static boolean checkPassword(String password, String md5PwdStr) {
        String s = getMD5String(password);
        return s.equals(md5PwdStr);
    }

    public static void main(String[] args) throws IOException {
        long begin = System.currentTimeMillis();
        String md5 = getMD5String("我爱你");
        long end = System.currentTimeMillis();
        System.out.println("sha1:" + md5 + " time:" + ((end - begin) / 1000) + "s");
    }

    public static String getFileSha1(File path) throws Throwable {
        FileInputStream in = null;
        try {
            try {
                FileInputStream in2 = new FileInputStream(path);
                try {
                    byte[] buffer = new byte[5242880];
                    while (true) {
                        int len = in2.read(buffer);
                        if (len <= 0) {
                            break;
                        }
                        messagedigest.update(buffer, 0, len);
                    }
                    String strM1331a = m1331a(messagedigest.digest());
                    try {
                        in2.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    return strM1331a;
                } catch (Exception e2) {
                    e = e2;
                    in = in2;
                    e.printStackTrace();
                    if (in != null) {
                        try {
                            in.close();
                        } catch (IOException e3) {
                            e3.printStackTrace();
                        }
                    }
                    return null;
                } catch (OutOfMemoryError e4) {
                    e = e4;
                    in = in2;
                    e.printStackTrace();
                    if (in != null) {
                        try {
                            in.close();
                        } catch (IOException e5) {
                            e5.printStackTrace();
                        }
                    }
                    return null;
                } catch (Throwable th) {
                    th = th;
                    in = in2;
                    if (in != null) {
                        try {
                            in.close();
                        } catch (IOException e6) {
                            e6.printStackTrace();
                        }
                    }
                    throw th;
                }
            } catch (Throwable th2) {
                th = th2;
            }
        } catch (Exception e7) {
            e = e7;
        } catch (OutOfMemoryError e8) {
            e = e8;
        }
    }
}
