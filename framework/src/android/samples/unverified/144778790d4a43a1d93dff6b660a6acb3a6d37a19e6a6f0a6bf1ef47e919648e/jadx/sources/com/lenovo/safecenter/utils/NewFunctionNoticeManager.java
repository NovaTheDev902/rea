package com.lenovo.safecenter.utils;

import android.content.Context;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.text.TextUtils;
import android.util.Log;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.systeminfo.p011ui.activity.DailyTools;

/* JADX INFO: loaded from: classes.dex */
public class NewFunctionNoticeManager {
    public static final String ACTION_APP_USENET_CONTROL = "action_app_usenet_contorl";
    public static final String ACTION_GUESTMODE = "action_guestmode";
    public static final String ACTION_KIDMODE = "action_kidmode";
    public static final String TYPE_TOOLS = "type_tools";
    public static final String TYPE_TRAFFIC_MONITOR = "type_traffic_monitor";

    public static void init(Context context) {
        m2393a(context, TYPE_TRAFFIC_MONITOR);
        m2393a(context, TYPE_TOOLS);
        if (DailyTools.isShowKidmode(context)) {
            m2394a(context, TYPE_TOOLS, ACTION_KIDMODE);
        }
        if (TrafficStatsService.nacServerIsExist()) {
            m2394a(context, TYPE_TOOLS, ACTION_GUESTMODE);
        }
    }

    public static boolean hasContentInType(Context context, String type) {
        Log.i("wu0wu", "hasContentInType content=" + getContentForType(context, type) + ",type=" + type);
        return !TextUtils.isEmpty(getContentForType(context, type));
    }

    public static String getContentForType(Context context, String type) {
        SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(context);
        return sp.getString(type, "");
    }

    public static void removeActionToType(Context context, String type, String action) {
        SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(context);
        String content = sp.getString(type, "");
        Log.i("wu0wu", "start removeActionToType content=" + content);
        if (!TextUtils.isEmpty(content)) {
            String[] items = content.split(C0092c.f1284O);
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < items.length; i++) {
                if (!action.equals(items[i])) {
                    sb.append(items[i]).append(C0092c.f1284O);
                }
            }
            sp.edit().remove(type).putString(type, sb.toString()).commit();
        }
        Log.i("wu0wu", "end removeActionToType content=" + sp.getString(type, ""));
    }

    public static boolean hasActionInType(Context context, String type, String action) {
        SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(context);
        String content = sp.getString(type, "");
        if (TextUtils.isEmpty(content)) {
            return false;
        }
        return content.contains(action);
    }

    /* JADX INFO: renamed from: a */
    private static void m2393a(Context context, String type) {
        SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(context);
        sp.edit().remove(type).commit();
    }

    /* JADX INFO: renamed from: a */
    private static void m2394a(Context context, String type, String action) {
        SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(context);
        String content = sp.getString(type, "");
        StringBuffer sb = new StringBuffer();
        sb.append(content).append(action).append(C0092c.f1284O);
        sp.edit().remove(type).putString(type, sb.toString()).commit();
    }
}
