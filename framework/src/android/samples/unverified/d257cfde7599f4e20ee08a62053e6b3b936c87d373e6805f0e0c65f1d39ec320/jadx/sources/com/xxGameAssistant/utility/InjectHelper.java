package com.xxGameAssistant.utility;

import android.annotation.SuppressLint;
import android.content.Context;
import java.io.PrintWriter;

/* JADX INFO: loaded from: classes.dex */
@SuppressLint({"SdCardPath"})
public class InjectHelper {
    private static String mGameMode = "DEFAULT";
    static final String targetFuncName = "kick";

    public static void setGameMode(String gameMode) {
        mGameMode = gameMode;
    }

    public static void executeCmd(Context context, String packageName) {
        try {
            String baseExeDir = NativeFileInstaller.getCacheDir(context);
            String baseSODir = NativeFileInstaller.getSODir(context);
            String executableFileName = String.valueOf(baseExeDir) + "/inject";
            String targetSOFileName = String.valueOf(baseSODir) + "/libghost.so";
            Process rootProcess = Runtime.getRuntime().exec("su");
            PrintWriter printWriter = new PrintWriter(rootProcess.getOutputStream());
            StringBuilder strBuilder = new StringBuilder();
            strBuilder.append(executableFileName);
            strBuilder.append(" " + packageName);
            strBuilder.append(" " + targetSOFileName);
            strBuilder.append(" kick");
            strBuilder.append(" " + mGameMode);
            printWriter.print(strBuilder.toString());
            printWriter.flush();
            printWriter.close();
            rootProcess.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
