package com.lenovo.safecenter.broadcast;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.provider.Settings;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.newview.FirstHarssActivity;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class HarassLogBroadcast extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    private AppDatabase f3400a;

    /* JADX INFO: renamed from: b */
    private SharedPreferences f3401b;

    public void showFirstHarass(Context context) {
        if (Const.getHarassCount(context, 1) == 0 && Const.getHarassCount(context, 0) == 1) {
            Intent intent = new Intent(context, (Class<?>) FirstHarssActivity.class);
            intent.addFlags(268435456);
            context.startActivity(intent);
        }
    }

    /* JADX WARN: Type inference failed for: r2v9, types: [com.lenovo.safecenter.broadcast.HarassLogBroadcast$1] */
    @Override // android.content.BroadcastReceiver
    public void onReceive(final Context context, Intent intent) {
        if (intent.getAction().equals("ACTION_BLACK_MESSAGE")) {
            this.f3400a = new AppDatabase(context);
            this.f3401b = PreferenceManager.getDefaultSharedPreferences(context);
            this.f3400a.isLogFull(context, AppDatabase.DB_LOG_HARASS);
            Const.saveHarassLogsCount(context);
            String stringExtra = intent.getStringExtra("black_address");
            String stringExtra2 = intent.getStringExtra("black_body");
            String stringExtra3 = intent.getStringExtra("black_date");
            String stringExtra4 = intent.getStringExtra("black_type");
            int i = intent.getExtras().getInt("fromtype");
            SafeLog safeLog = new SafeLog();
            safeLog.logSelected = 0;
            safeLog.number = stringExtra;
            safeLog.content = stringExtra2;
            safeLog.time = stringExtra3;
            safeLog.fromtype = i;
            safeLog.type = "0";
            safeLog.isUpload = 0;
            safeLog.mms_type = stringExtra4;
            safeLog.hassee = 1;
            this.f3400a.insertHarassLog(safeLog);
            this.f3400a.close();
            context.sendBroadcast(new Intent("com.lenovo.antispam.notify"));
            Const.lastSafeLogs.put(AppDatabase.HARASS_SMS, safeLog);
            if (Settings.System.getInt(context.getContentResolver(), "guest_mode_on", 0) == 0 && this.f3401b.getBoolean("harassLog_preference", true)) {
                SafeCenterService.harass_msg_count++;
                Const.saveHarassLogsCount(context);
                TrackEvent.reportInterceptGarbageSMS();
                MyUtils.showNotification(context, 256, 4);
            }
            try {
                if (Const.getHarassCount(context, 0) == 0) {
                    SharedPreferences mDefaultPreference = PreferenceManager.getDefaultSharedPreferences(context);
                    SharedPreferences.Editor editor = mDefaultPreference.edit();
                    editor.putInt("total_harass_sms", this.f3400a.getHarassLogCount("0")).commit();
                } else {
                    Const.saveHarassCount(context, 0);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            showFirstHarass(context);
        }
        if (intent.getAction().equals("ACTION_BLACK_PHONE")) {
            this.f3400a = new AppDatabase(context);
            String number = intent.getStringExtra("black_address");
            String date = intent.getStringExtra("black_date");
            SafeLog safeLog2 = new SafeLog();
            safeLog2.number = number;
            safeLog2.logSelected = 0;
            safeLog2.time = date;
            safeLog2.type = DatabaseTables.SYSTEM_MARK;
            safeLog2.isUpload = 0;
            safeLog2.hassee = 1;
            this.f3400a.insertHarassLog(safeLog2);
            this.f3400a.close();
        }
        if (intent.getAction().equals("com.lenovo.antivirus.notify")) {
            final String pkgName = intent.getStringExtra("packageName");
            final String type = intent.getStringExtra("virustype");
            final String appName = intent.getStringExtra("pname");
            if (appName != null) {
                new Thread() { // from class: com.lenovo.safecenter.broadcast.HarassLogBroadcast.1
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        if (type == null) {
                            MyUtils.showScanVirusNotification(context, "0", pkgName, C0092c.f1282M + appName + "\" ");
                        } else {
                            MyUtils.showScanVirusNotification(context, type, pkgName, C0092c.f1282M + appName + "\" ");
                        }
                        MyUtils.cancelNotification(context, MyUtils.VIRUS_NOTI_ID);
                    }
                }.start();
            }
        }
    }
}
