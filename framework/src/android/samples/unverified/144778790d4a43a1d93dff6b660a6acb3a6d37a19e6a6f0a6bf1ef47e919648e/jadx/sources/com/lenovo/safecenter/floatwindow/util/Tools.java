package com.lenovo.safecenter.floatwindow.util;

import android.app.ActivityManager;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Build;
import android.util.DisplayMetrics;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.shortcut.ShortcutActivity;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class Tools {

    /* JADX INFO: renamed from: a */
    private Context f3590a;

    public Tools(Context context) {
        this.f3590a = context;
    }

    public static int getDisplayWidth(Context context) {
        DisplayMetrics displayMetrics = context.getApplicationContext().getResources().getDisplayMetrics();
        return displayMetrics.widthPixels;
    }

    public static int getDisplayHeight(Context context) {
        DisplayMetrics displayMetrics2 = context.getApplicationContext().getResources().getDisplayMetrics();
        int height = displayMetrics2.heightPixels;
        return height;
    }

    public int getUeageSize(String totalstr1, String totalstr2) {
        int local01 = stringtoInt(totalstr1);
        int local02 = stringtoInt(totalstr2);
        return local01 - local02;
    }

    public String getTotalMemory() {
        long initial_memory = 0;
        try {
            FileReader localFileReader = new FileReader("/proc/meminfo");
            BufferedReader localBufferedReader = new BufferedReader(localFileReader, 8192);
            String str2 = localBufferedReader.readLine();
            if (str2 != null) {
                String[] arrayOfString = str2.split("\\s+");
                initial_memory = Integer.valueOf(arrayOfString[1]).intValue() / 1024;
            }
            localBufferedReader.close();
        } catch (IOException e) {
        }
        return String.valueOf(initial_memory);
    }

    public int stringtoInt(String string) {
        String str2 = string.replace("MB", "").replace("%", "");
        return str2.indexOf(".") != -1 ? Integer.valueOf(str2.substring(0, str2.indexOf("."))).intValue() : Integer.valueOf(str2.trim()).intValue();
    }

    public String inttostring(int mem) {
        return String.valueOf(mem) + "MB";
    }

    public int getUeageRate(String totalstr1, String totalstr2) {
        float local01 = stringtoInt(totalstr1);
        float local02 = stringtoInt(totalstr2);
        float d = (local01 - local02) / local01;
        int b = Math.round(100.0f * d);
        return b;
    }

    public int getUeageRate1(String totalstr1, String totalstr2) {
        float local01 = stringtoInt(totalstr1);
        float local02 = stringtoInt(totalstr2);
        float d = local02 / local01;
        int b = Math.round(100.0f * d);
        return b;
    }

    public String getAvailMemory() {
        ActivityManager.MemoryInfo mi = new ActivityManager.MemoryInfo();
        ActivityManager activityManager = (ActivityManager) this.f3590a.getSystemService("activity");
        activityManager.getMemoryInfo(mi);
        return String.valueOf(mi.availMem / 1048576);
    }

    public static void createFloatwindowShortCut(Context context, int iconResId, int appnameResId) {
        if (!hasfFloatwindowShortcut(context)) {
            Intent intent = new Intent("com.android.launcher.action.INSTALL_SHORTCUT");
            intent.putExtra("duplicate", false);
            intent.putExtra("android.intent.extra.shortcut.NAME", context.getString(C0415R.string.switcher_app_name));
            intent.putExtra("android.intent.extra.shortcut.ICON_RESOURCE", Intent.ShortcutIconResource.fromContext(context.getApplicationContext(), iconResId));
            intent.putExtra("android.intent.extra.shortcut.INTENT", new Intent(context.getApplicationContext(), (Class<?>) ShortcutActivity.class));
            context.sendBroadcast(intent);
        }
    }

    public static boolean hasfFloatwindowShortcut(Context context) {
        String uriStr;
        if (Build.VERSION.SDK_INT < 8) {
            uriStr = "content://com.android.launcher.settings/favorites?notify=true";
        } else {
            uriStr = "content://com.android.launcher2.settings/favorites?notify=true";
        }
        Uri CONTENT_URI = Uri.parse(uriStr);
        Cursor cursor = context.getContentResolver().query(CONTENT_URI, null, " iconPackage=? and iconResource=? ", new String[]{TrafficStatsService.PACKAGE_NAME, "com.lenovo.safecenter:drawable/shortcut_app_icon"}, null);
        if (cursor == null || cursor.getCount() <= 0) {
            return false;
        }
        return true;
    }
}
