package com.lenovo.lps.sus.p003a.p004a.p006b;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;

/* JADX INFO: renamed from: com.lenovo.lps.sus.a.a.b.c */
/* JADX INFO: loaded from: classes.dex */
public class C0084c {
    /* JADX INFO: renamed from: a */
    public static String m261a(String str) {
        try {
            return new String(m264a(str.getBytes()), "ASCII");
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException("ASCII is not supported!", e);
        }
    }

    /* JADX INFO: renamed from: a */
    public static String m262a(String str, String str2) {
        try {
            try {
                return new String(m264a(str.getBytes(str2)), "ASCII");
            } catch (UnsupportedEncodingException e) {
                throw new RuntimeException("ASCII is not supported!", e);
            }
        } catch (UnsupportedEncodingException e2) {
            throw new RuntimeException("Unsupported charset: " + str2, e2);
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m263a(InputStream inputStream, OutputStream outputStream) throws IOException {
        byte[] bArr = new byte[1024];
        while (true) {
            int i = inputStream.read(bArr);
            if (i == -1) {
                return;
            } else {
                outputStream.write(bArr, 0, i);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m264a(byte[] bArr) {
        return m268c(bArr);
    }

    /* JADX INFO: renamed from: b */
    public static String m265b(String str) {
        try {
            return new String(m267b(str.getBytes("ASCII")));
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException("ASCII is not supported!", e);
        }
    }

    /* JADX INFO: renamed from: b */
    public static String m266b(String str, String str2) {
        try {
            try {
                return new String(m267b(str.getBytes("ASCII")), str2);
            } catch (UnsupportedEncodingException e) {
                throw new RuntimeException("Unsupported charset: " + str2, e);
            }
        } catch (UnsupportedEncodingException e2) {
            throw new RuntimeException("ASCII is not supported!", e2);
        }
    }

    /* JADX INFO: renamed from: b */
    public static byte[] m267b(byte[] bArr) {
        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(bArr);
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
        try {
            try {
                m263a(new C0082a(byteArrayInputStream), byteArrayOutputStream);
                try {
                    byteArrayInputStream.close();
                    try {
                        byteArrayOutputStream.close();
                        return byteArrayOutputStream.toByteArray();
                    } catch (IOException e) {
                        throw new RuntimeException("Close IO error", e);
                    }
                } catch (IOException e2) {
                    throw new RuntimeException("Close IO error", e2);
                }
            } catch (Throwable th) {
                try {
                    byteArrayInputStream.close();
                    try {
                        byteArrayOutputStream.close();
                        throw th;
                    } catch (IOException e3) {
                        throw new RuntimeException("Close IO error", e3);
                    }
                } catch (IOException e4) {
                    throw new RuntimeException("Close IO error", e4);
                }
            }
        } catch (IOException e5) {
            throw new RuntimeException("Unexpected I/O error", e5);
        }
    }

    /* JADX INFO: renamed from: c */
    private static byte[] m268c(byte[] bArr) {
        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(bArr);
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
        try {
            try {
                C0083b c0083b = new C0083b(byteArrayOutputStream);
                m263a(byteArrayInputStream, c0083b);
                c0083b.m260a();
                try {
                    byteArrayInputStream.close();
                    try {
                        byteArrayOutputStream.close();
                        return byteArrayOutputStream.toByteArray();
                    } catch (IOException e) {
                        throw new RuntimeException("Close IO error", e);
                    }
                } catch (IOException e2) {
                    throw new RuntimeException("Close IO error", e2);
                }
            } catch (IOException e3) {
                throw new RuntimeException("Unexpected I/O error", e3);
            }
        } catch (Throwable th) {
            try {
                byteArrayInputStream.close();
                try {
                    byteArrayOutputStream.close();
                    throw th;
                } catch (IOException e4) {
                    throw new RuntimeException("Close IO error", e4);
                }
            } catch (IOException e5) {
                throw new RuntimeException("Close IO error", e5);
            }
        }
    }
}
