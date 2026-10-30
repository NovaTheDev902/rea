package com.lenovo.performancecenter.coreui.util;

import android.app.ActivityManager;
import android.content.Context;
import android.os.Build;
import android.os.Handler;
import android.util.Log;
import com.lenovo.performancecenter.performance.BootSpeedActivity;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.utils.Untils;
import com.lenovo.safecenter.utils.WflUtils;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class RootPassage {
    public static final String CMD_CC = " -cc ";
    public static final String CMD_FS = " -fs ";
    public static File cmdFile;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ String m563a(ArrayList x0, String x1) {
        StringBuffer stringBuffer = new StringBuffer();
        if (x0 != null) {
            Object[] objArr = new Object[5];
            objArr[0] = "/system/bin";
            objArr[1] = "app_process";
            objArr[2] = "/system/bin";
            objArr[3] = "com.lenovo.safecenter.LFS";
            StringBuffer stringBuffer2 = new StringBuffer();
            int size = x0.size();
            for (int i = 0; i < size; i++) {
                String str = (String) x0.get(i);
                if (str != null && !"".equals(str)) {
                    if (i > 0) {
                        stringBuffer2.append(Untils.PAUSE);
                    }
                    stringBuffer2.append(str);
                }
            }
            objArr[4] = x1 + " " + ((Object) stringBuffer2);
            stringBuffer.append(String.format("%s/%s %s %s %s", objArr));
        }
        return stringBuffer.toString();
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m564a(Context x0, String x1) {
        String str = "am force-stop " + x1 + "\n";
        Log.i("KillSingle", System.currentTimeMillis() + " command == " + str);
        Log.i("KillSingle", System.currentTimeMillis() + " CMDHelper.socketClient result == " + CMDHelper.exeCmd(x0, str));
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m565a(Context x0, ArrayList x1) {
        StringBuffer stringBuffer = new StringBuffer();
        Iterator it = x1.iterator();
        while (it.hasNext()) {
            stringBuffer.append("am force-stop " + ((String) it.next()) + "\n");
        }
        String string = stringBuffer.toString();
        Log.i("KILLALL", System.currentTimeMillis() + " command == " + string);
        Log.i("KILLALL", System.currentTimeMillis() + " CMDHelper.socketClient result == " + CMDHelper.exeCmd(x0, string));
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ void m567b(String x0, String x1, Context x2) {
        Log.i("KillSingle", System.currentTimeMillis() + " cmd1==" + x0 + " cmd2==" + x1);
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append(x0).append("\n");
        stringBuffer.append(x1).append("\n");
        String string = stringBuffer.toString();
        Log.i("KillSingle", System.currentTimeMillis() + " command == " + string);
        Log.i("KillSingle", System.currentTimeMillis() + " CMDHelper.socketClient result == " + CMDHelper.exeCmd(x2, string));
    }

    public static void execRootCmd(final Handler handler, final ArrayList<String> pkgNameList, final String flag, final Context context) {
        if (pkgNameList.size() != 0 && " -fs ".equals(flag)) {
            if (!WflUtils.isRoot()) {
                ActivityManager activityManager = (ActivityManager) context.getSystemService("activity");
                for (String pkgName : pkgNameList) {
                    activityManager.killBackgroundProcesses(pkgName);
                }
                if (handler != null) {
                    handler.sendEmptyMessage(6);
                    return;
                }
                return;
            }
            new Thread(new Runnable() { // from class: com.lenovo.performancecenter.coreui.util.RootPassage.1
                @Override // java.lang.Runnable
                public final void run() {
                    Log.i("KILLALL", "Build.VERSION.SDK_INT == " + Build.VERSION.SDK_INT);
                    if (Build.VERSION.SDK_INT < 17) {
                        RootPassage.m568c(RootPassage.exportLenovo(context), RootPassage.m563a(pkgNameList, flag), context);
                    } else {
                        RootPassage.m565a(context, pkgNameList);
                    }
                    if (handler != null) {
                        handler.sendEmptyMessage(6);
                    }
                }
            }).start();
        }
    }

    public static void execRootCmd(final String pkgName, final String flag, final Context context) {
        if (pkgName != null && !"".equals(pkgName) && " -fs ".equals(flag)) {
            if (!WflUtils.isRoot()) {
                ActivityManager activityManager = (ActivityManager) context.getSystemService("activity");
                activityManager.killBackgroundProcesses(pkgName);
            } else {
                new Thread(new Runnable() { // from class: com.lenovo.performancecenter.coreui.util.RootPassage.2
                    @Override // java.lang.Runnable
                    public final void run() {
                        Log.i("KillSingle", "Build.VERSION.SDK_INT == " + Build.VERSION.SDK_INT);
                        if (Build.VERSION.SDK_INT >= 17) {
                            RootPassage.m564a(context, pkgName);
                            return;
                        }
                        String strExportLenovo = RootPassage.exportLenovo(context);
                        String strAppProssLenovo = RootPassage.appProssLenovo(pkgName, flag);
                        Context context2 = context;
                        String str = pkgName;
                        RootPassage.m567b(strExportLenovo, strAppProssLenovo, context2);
                    }
                }).start();
            }
        }
    }

    public static void execRootCmdInJar(final String pkgName, final String flag, final Context context) {
        if (pkgName != null && !"".equals(pkgName) && flag != null && !"".equals(flag)) {
            new Thread(new Runnable() { // from class: com.lenovo.performancecenter.coreui.util.RootPassage.3
                @Override // java.lang.Runnable
                public final void run() {
                    try {
                        String strExportLenovo = RootPassage.exportLenovo(context);
                        String strAppProssLenovo = RootPassage.appProssLenovo(pkgName, flag);
                        Context context2 = context;
                        String str = pkgName;
                        RootPassage.m567b(strExportLenovo, strAppProssLenovo, context2);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }

    public static void setComponentAbleBoot(final Context context, final HashMap<String[], int[]> cns) {
        Log.i(BootSpeedActivity.TAG, System.currentTimeMillis() + " setComponentAbleBoot");
        new Thread(new Runnable() { // from class: com.lenovo.performancecenter.coreui.util.RootPassage.4
            @Override // java.lang.Runnable
            public final void run() {
                String able;
                StringBuffer buffer = new StringBuffer();
                for (Map.Entry<String[], int[]> entry : cns.entrySet()) {
                    if (entry.getValue()[0] != -1) {
                        if (entry.getValue()[0] == 1) {
                            able = "enable";
                        } else if (entry.getValue()[0] == 2) {
                            able = "disable";
                        }
                        String command = "pm " + able + " " + entry.getKey()[0] + CookieSpec.PATH_DELIM + entry.getKey()[1] + "\n";
                        buffer.append(command);
                    }
                }
                String shbuffer = buffer.toString();
                Log.i(BootSpeedActivity.TAG, System.currentTimeMillis() + " command == " + shbuffer);
                boolean result = CMDHelper.exeCmd(context, shbuffer);
                Log.i(BootSpeedActivity.TAG, System.currentTimeMillis() + " result == " + result);
            }
        }).start();
    }

    public static void setComponentAbleBoot(final Context context, final String[] component, final int state) {
        Log.i(BootSpeedActivity.TAG, System.currentTimeMillis() + " setComponentAbleBoot");
        new Thread(new Runnable() { // from class: com.lenovo.performancecenter.coreui.util.RootPassage.5
            @Override // java.lang.Runnable
            public final void run() {
                StringBuffer buffer = new StringBuffer();
                String able = "enable";
                if (state == 1) {
                    able = "enable";
                } else if (state == 2) {
                    able = "disable";
                }
                String command = "pm " + able + " " + component[0] + CookieSpec.PATH_DELIM + component[1] + "\n";
                buffer.append(command);
                String shbuffer = buffer.toString();
                Log.i(BootSpeedActivity.TAG, System.currentTimeMillis() + " command == " + shbuffer);
                boolean result = CMDHelper.exeCmd(context, shbuffer);
                Log.i(BootSpeedActivity.TAG, System.currentTimeMillis() + " result == " + result);
            }
        }).start();
    }

    public static String exportLenovo(Context context) {
        File nbFile = context.getFileStreamPath("nb.jar");
        if (nbFile == null || !nbFile.exists()) {
            return "";
        }
        String nbPath = nbFile.getAbsolutePath();
        String command = String.format("export CLASSPATH=%s\n", nbPath);
        return command;
    }

    public static String appProssLenovo(String paramString, String flag) {
        Object[] arrayOfObject = {"/system/bin", "app_process", "/system/bin", "com.lenovo.safecenter.LFS", flag + paramString};
        return String.format("%s/%s %s %s %s\n", arrayOfObject);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: c */
    public static void m568c(String cmd1, String cmd2, Context context) {
        Log.i("KILLALL", System.currentTimeMillis() + " cmd1==" + cmd1 + " cmd2==" + cmd2);
        StringBuffer buffer = new StringBuffer();
        buffer.append(cmd1).append("\n");
        buffer.append(cmd2).append("\n");
        String shbuffer = buffer.toString();
        Log.i("KILLALL", System.currentTimeMillis() + " command == " + shbuffer);
        boolean result = CMDHelper.exeCmd(context, shbuffer);
        Log.i("KILLALL", System.currentTimeMillis() + " CMDHelper.socketClient result == " + result);
    }

    public static void clearnNotification(String packageName, Context context) {
        m568c(exportLenovo(context), appProssLenovo(packageName, " -nc "), context);
    }
}
