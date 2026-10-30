package com.lenovo.safecenter.utils;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import com.lenovo.safecenter.net.support.InitializeService;
import com.lenovo.safecenter.utils.updateLab.AutoUpdateLabManager;
import java.text.SimpleDateFormat;

/* JADX INFO: loaded from: classes.dex */
public class AlarmManageUtils {
    /* JADX INFO: renamed from: a */
    private static AlarmManager m2348a(Context c) {
        return (AlarmManager) c.getSystemService("alarm");
    }

    public static void noticeUpdateLab(Context c) {
        long triggerTime;
        if (AutoUpdateLabManager.isAutoUpdate(c)) {
            AlarmManager alarmManager = (AlarmManager) c.getSystemService("alarm");
            Intent intent = new Intent();
            intent.setAction(Const.ACTION_BROADCAST_NOTICE_UPDATE_LAB);
            PendingIntent pendingIntent = PendingIntent.getBroadcast(c, 0, intent, 0);
            int mode = AutoUpdateLabManager.getAutoUpdateMode(c);
            Log.i("wu0wu", "auto update mode=" + mode);
            if (System.currentTimeMillis() > WflUtils.getTriggerTime(12, 0, 0)) {
                Log.i("wu0wu", "triggerTime<currentTime");
                triggerTime = WflUtils.getTriggerTime(12, 0, 0) + 86400000;
            } else {
                triggerTime = WflUtils.getTriggerTime(12, 0, 0);
            }
            if (mode == 1) {
                alarmManager.setRepeating(0, triggerTime, 86400000L, pendingIntent);
            } else if (mode == 2) {
                alarmManager.setRepeating(0, triggerTime, 604800000L, pendingIntent);
            }
            Log.i("wu0wu", "auto update start time=" + WflUtils.convertLongTime2DateFormat(Long.valueOf(triggerTime), new SimpleDateFormat("yyyy-MM-dd-HH:mm:ss")));
        }
    }

    public static void cancelNoticeUpdateLab(Context c) {
        AlarmManager am = m2348a(c);
        Intent i = new Intent();
        i.setAction(Const.ACTION_BROADCAST_NOTICE_UPDATE_LAB);
        PendingIntent pendingIntent = PendingIntent.getBroadcast(c, 0, i, 0);
        am.cancel(pendingIntent);
    }

    public static void noticeTrafficStats(Context c) {
        Intent intent = new Intent(c, (Class<?>) InitializeService.class);
        PendingIntent pendingIntent = PendingIntent.getService(c, 0, intent, 0);
        AlarmManager am = m2348a(c);
        am.setRepeating(1, System.currentTimeMillis(), 60000L, pendingIntent);
    }

    public static void cancelNoticeTrafficStats(Context c) {
        AlarmManager am = m2348a(c);
        Intent i = new Intent(c, (Class<?>) InitializeService.class);
        PendingIntent pendingIntent = PendingIntent.getService(c, 0, i, 0);
        am.cancel(pendingIntent);
    }
}
