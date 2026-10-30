package com.lenovo.safecenter.antivirus.utils;

import android.content.Context;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.OutputStream;
import java.security.Key;
import java.util.Properties;
import javax.crypto.Cipher;

/* JADX INFO: loaded from: classes.dex */
public class PropertiesUtil {

    /* JADX INFO: renamed from: c */
    private static String f3092c = "leskey.key";

    /* JADX INFO: renamed from: d */
    private static String f3093d = "lesprop.dat";

    /* JADX INFO: renamed from: e */
    private static PropertiesUtil f3094e;

    /* JADX INFO: renamed from: a */
    private Properties f3095a;

    /* JADX INFO: renamed from: b */
    private Context f3096b;

    private PropertiesUtil(Context context) throws Throwable {
        this.f3096b = context;
        try {
            Cipher cipher = Cipher.getInstance("AES");
            File file = new File(this.f3096b.getFilesDir().getAbsolutePath() + File.separator + f3092c);
            if (!file.exists()) {
                m1329a(file);
            }
            FileInputStream fileInputStream = new FileInputStream(file);
            ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
            Key key = (Key) objectInputStream.readObject();
            objectInputStream.close();
            fileInputStream.close();
            cipher.init(2, key);
            File file2 = new File(this.f3096b.getFilesDir().getAbsolutePath() + File.separator + f3093d);
            if (!file2.exists()) {
                m1329a(file2);
            }
            FileInputStream fileInputStream2 = new FileInputStream(file2);
            ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
            m1330a(fileInputStream2, byteArrayOutputStream);
            byte[] bArrDoFinal = cipher.doFinal(byteArrayOutputStream.toByteArray());
            fileInputStream2.close();
            byteArrayOutputStream.close();
            Properties properties = new Properties();
            properties.load(new ByteArrayInputStream(bArrDoFinal));
            this.f3095a = properties;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static synchronized PropertiesUtil getInstance(Context context) {
        if (f3094e == null) {
            f3094e = new PropertiesUtil(context);
        }
        return f3094e;
    }

    public String getValue(String key) {
        if (this.f3095a != null) {
            return this.f3095a.getProperty(key);
        }
        return null;
    }

    /* JADX INFO: renamed from: a */
    private static void m1330a(InputStream ips, OutputStream ops) throws Exception {
        byte[] buf = new byte[1024];
        int len = ips.read(buf);
        while (len != -1) {
            ops.write(buf, 0, len);
            len = ips.read(buf);
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1329a(File fileInFilesDir) throws Throwable {
        InputStream is = null;
        FileOutputStream fos = null;
        try {
            try {
                is = this.f3096b.getAssets().open(fileInFilesDir.getName());
                fileInFilesDir.createNewFile();
                FileOutputStream fos2 = new FileOutputStream(fileInFilesDir);
                try {
                    byte[] buf = new byte[1024];
                    while (true) {
                        int len = is.read(buf);
                        if (len == -1) {
                            break;
                        } else {
                            fos2.write(buf, 0, len);
                        }
                    }
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                    try {
                        fos2.close();
                    } catch (IOException e2) {
                        e2.printStackTrace();
                    }
                } catch (IOException e3) {
                    e = e3;
                    fos = fos2;
                    e.printStackTrace();
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e4) {
                            e4.printStackTrace();
                        }
                    }
                    if (fos != null) {
                        try {
                            fos.close();
                        } catch (IOException e5) {
                            e5.printStackTrace();
                        }
                    }
                } catch (Throwable th) {
                    th = th;
                    fos = fos2;
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e6) {
                            e6.printStackTrace();
                        }
                    }
                    if (fos != null) {
                        try {
                            fos.close();
                        } catch (IOException e7) {
                            e7.printStackTrace();
                        }
                    }
                    throw th;
                }
            } catch (IOException e8) {
                e = e8;
            }
        } catch (Throwable th2) {
            th = th2;
        }
    }
}
