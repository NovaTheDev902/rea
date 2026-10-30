package com.lenovo.safecenter.utils;

import android.util.Log;
import java.io.DataOutputStream;

/* JADX INFO: loaded from: classes.dex */
public class RootPassage {
    public static final String CMD_CC = " -cc ";
    public static final String CMD_FS = " -fs ";
    public static DataOutputStream mOutputStream;
    public static Process mProcess;

    public static boolean rootCmd(String cmd) {
        boolean z = false;
        try {
            DataOutputStream os = Const.mOutputStream;
            if (os == null) {
                Log.i("RootPassage", "rootCmd()...os=null---->cmd=" + cmd);
            } else {
                os.writeBytes(cmd + "\n");
                os.flush();
                z = true;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return z;
    }

    public static boolean appPross(String paramString, String flag) {
        Object[] arrayOfObject = {"/system/bin", "app_process", "/system/bin", "com.lenovo.safecenter.LFS", flag + paramString};
        String str = String.format("%s/%s %s %s %s\n", arrayOfObject);
        return rootCmd(str);
    }
}
