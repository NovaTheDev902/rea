package com.lenovo.safecenter.adskill;

import android.content.Context;
import android.util.Log;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.safecenter.support.CMDHelper;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class FileUtils {
    public static final String MD5 = ".md5";
    public static final String XML = ".xml";

    public static synchronized boolean isExist(String path) {
        return new File(path).exists();
    }

    public static synchronized boolean mkdirs(String path) {
        return new File(path).mkdirs();
    }

    public static synchronized void CopyFile(String src, String dir) {
        try {
            File emptyFile = new File(src);
            if (emptyFile.length() <= 0) {
                Log.i("CopyFile", "emptyFile.length===" + emptyFile.length());
                boolean bool = new File(dir).createNewFile();
                Log.i("CopyFile", "emptyFile.length  bool===" + bool);
            } else {
                FileInputStream fin = new FileInputStream(new File(src));
                FileOutputStream fout = new FileOutputStream(new File(dir));
                byte[] buffer = new byte[fin.available()];
                while (fin.read(buffer) != -1) {
                    fout.write(buffer);
                }
                fin.close();
                fout.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static synchronized boolean cpAssetsFile(Context context, String from, String to, boolean isReplace) {
        boolean z = false;
        synchronized (FileUtils.class) {
            boolean res = false;
            String path = to.substring(0, to.lastIndexOf(CookieSpec.PATH_DELIM) + 1);
            if (!isExist(path)) {
                mkdirs(path);
            }
            if (isReplace || !isExist(to)) {
                try {
                    InputStream is = context.getAssets().open(from);
                    BufferedReader br = new BufferedReader(new InputStreamReader(is));
                    BufferedWriter bw = new BufferedWriter(new FileWriter(to));
                    StringBuffer sb = new StringBuffer();
                    boolean fistLine = true;
                    while (true) {
                        String line = br.readLine();
                        if (line == null) {
                            break;
                        }
                        if (fistLine) {
                            fistLine = false;
                        } else {
                            bw.newLine();
                            sb.append("\n");
                        }
                        bw.write(line);
                        sb.append(line);
                    }
                    bw.close();
                    br.close();
                    is.close();
                    res = isExist(to);
                } catch (IOException e) {
                }
                z = res;
            }
        }
        return z;
    }

    public static synchronized boolean writeFile(String path, String text) {
        try {
            if (isExist(path)) {
                deleteFile(path);
            }
            BufferedWriter bw = new BufferedWriter(new FileWriter(path));
            bw.write(text);
            bw.close();
        } catch (IOException e) {
        }
        return isExist(path);
    }

    public static synchronized String readFile(String path) {
        String res;
        res = null;
        if (isExist(path)) {
            try {
                BufferedInputStream bf = new BufferedInputStream(new FileInputStream(path));
                byte[] data = new byte[bf.available()];
                bf.read(data);
                res = new String(data);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return res;
    }

    public static synchronized String getMD5Str(String str) {
        StringBuffer md5StrBuff;
        byte[] byteArray = null;
        try {
            MessageDigest messageDigest = MessageDigest.getInstance("MD5");
            messageDigest.reset();
            messageDigest.update(str.getBytes(InterfaceC0079b.f1213a));
            byteArray = messageDigest.digest();
        } catch (UnsupportedEncodingException e) {
        } catch (NoSuchAlgorithmException e2) {
        }
        md5StrBuff = new StringBuffer();
        if (byteArray != null) {
            for (int i = 0; i < byteArray.length; i++) {
                if (Integer.toHexString(byteArray[i] & 255).length() == 1) {
                    md5StrBuff.append("0").append(Integer.toHexString(byteArray[i] & 255));
                } else {
                    md5StrBuff.append(Integer.toHexString(byteArray[i] & 255));
                }
            }
        }
        return md5StrBuff.toString();
    }

    public static synchronized int getListLenght(String root) {
        int length;
        try {
            length = new File(root).list().length;
        } catch (Exception e) {
            length = 0;
        }
        return length;
    }

    public static synchronized boolean mkMD5File(String name) {
        boolean res;
        res = false;
        try {
            String path = name + XML;
            BufferedReader br = new BufferedReader(new FileReader(path));
            String text = readFile(path);
            String md5Name = name + MD5;
            if (isExist(md5Name)) {
                deleteFile(md5Name);
            }
            res = writeFile(md5Name, getMD5Str(text));
            br.close();
        } catch (FileNotFoundException e) {
        } catch (IOException e2) {
        }
        return res;
    }

    public static synchronized boolean deleteFile(String path) {
        return new File(path).delete();
    }

    /* JADX WARN: Code duplicated, block: B:19:0x000f A[EXC_TOP_SPLITTER, SYNTHETIC] */
    public static synchronized boolean cpAssetsFileBySocketClient(Context context, String from, String to, String shPath, boolean isReplace) {
        boolean z;
        boolean res = false;
        if (!isReplace) {
            try {
                if (isExist(to)) {
                    z = false;
                } else {
                    try {
                        StringBuffer buffer = new StringBuffer();
                        String systemDev = CMDHelper.getMountDate(context);
                        buffer.append("mount -o remount,rw " + systemDev + " /system \n").append("chmod 666 " + from + "\n").append("cat " + from + " >" + to + "\n");
                        res = CMDHelper.exeCmd(context, shPath);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    z = res;
                }
            } catch (Throwable th) {
                throw th;
            }
        } else {
            StringBuffer buffer2 = new StringBuffer();
            String systemDev2 = CMDHelper.getMountDate(context);
            buffer2.append("mount -o remount,rw " + systemDev2 + " /system \n").append("chmod 666 " + from + "\n").append("cat " + from + " >" + to + "\n");
            res = CMDHelper.exeCmd(context, shPath);
            z = res;
        }
        return z;
    }
}
