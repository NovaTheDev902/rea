package com.lenovo.safecenter.net.support;

import android.app.AlarmManager;
import android.app.AlertDialog;
import android.app.PendingIntent;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.ConnectivityManager;
import android.net.INetworkStatsService;
import android.net.NetworkStats;
import android.net.NetworkTemplate;
import android.net.TrafficStats;
import android.os.Build;
import android.os.Handler;
import android.os.Message;
import android.os.ServiceManager;
import android.preference.PreferenceManager;
import android.provider.MultiSIMUtils;
import android.provider.Settings;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import android.text.format.Formatter;
import android.util.Log;
import android.util.TypedValue;
import android.widget.Toast;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.data.SaveData;
import com.lenovo.safecenter.mmsutils.Wbxml;
import com.lenovo.safecenter.net.LowLevelNetFilter;
import com.lenovo.safecenter.net.NetFilter;
import com.lenovo.safecenter.net.TrafficDailog;
import com.lenovo.safecenter.net.TrafficStatistics;
import com.lenovo.safecenter.net.cache.NetCache;
import com.lenovo.safecenter.net.cache.NetConstant;
import com.lenovo.safecenter.net.correct.TrafficCorrectSetting;
import com.lenovo.safecenter.net.doublemode.DoubleCardUtil;
import com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.WflUtils;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import org.apache.commons.httpclient.cookie.CookiePolicy;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class TrafficStatsService {
    public static final int ANDROID_CORE_UID = 10001;
    public static final int ANDROID_MEDIA_UID = 10013;
    public static final int ANDROID_MEDIA_UID2 = 1013;
    public static final int ANDROID_PHONE_UID = 1001;
    public static final String CMD_PATH = "/data/data/com.lenovo.safecenter/files/nac.sh";
    public static final String CORRECT_ACTION_RTC_SIM = "com.lenovo.safecenter.correct.traffic.SIM.service.RTC";
    public static final String CORRECT_ACTION_RTC_SIM2 = "com.lenovo.safecenter.correct.traffic.SIM2.service.RTC";
    public static final String DATE = "date";
    public static final String DB_NAME = "trafficstats.db";
    public static final int ICS_MUTI = 12;
    public static final int ICS_SINGLE = 10;
    public static final long INTERVALTIME = 86400000;
    public static final int LOW_ICS_SINGLE = 11;
    public static final String NOTICE_TRAFFIC_ACTION_RTC = "com.lenovo.safecenter.notice.traffic.ui.service.RTC";
    public static final int OPEN_PHONE = 13;
    public static final int OPERATOR_CDMA = 2;
    public static final int OPERATOR_M = 0;
    public static final int OPERATOR_UN = 1;
    public static final int OPERATOR_UNKONWN = 8;
    public static final String PACKAGE_NAME = "com.lenovo.safecenter";
    public static final String TOTAL = "total";
    public static final String TRAFFIC = "traffic";
    public static final int TRAFFIC_DAY_WARN_ID = 15;
    public static final int TRAFFIC_DAY_WARN_ID_SIM2 = 23;
    public static final int TRAFFIC_NOTI_TYPE_DAILY_OUT = 22;
    public static final int TRAFFIC_WARN_ID = 9;
    public static final int TRAFFIC_WARN_ID_SIM2 = 24;
    public static final int UNINSTALL_MODE = 16;

    /* JADX INFO: renamed from: a */
    private TrafficStatsSQLiteOpenHelper f4742a;

    /* JADX INFO: renamed from: b */
    private SharedPreferences f4743b;

    /* JADX INFO: renamed from: c */
    private SharedPreferences.Editor f4744c;

    /* JADX INFO: renamed from: d */
    private Context f4745d;
    public static int TRAFFIC_CHILDVIEW_WIDTH = 45;
    public static int BAR_MAXHEIGHT = 60;

    /* JADX INFO: renamed from: e */
    private static boolean f4737e = true;

    /* JADX INFO: renamed from: f */
    private static TrafficStatsService f4738f = null;

    /* JADX INFO: renamed from: g */
    private static ExecutorService f4739g = Executors.newSingleThreadExecutor();
    public static boolean canCorrect = true;

    /* JADX INFO: renamed from: h */
    private static final Handler f4740h = new Handler() { // from class: com.lenovo.safecenter.net.support.TrafficStatsService.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    boolean unused = TrafficStatsService.f4737e = true;
                    break;
                case Wbxml.EXT_I_2 /* 66 */:
                    Utils.setCanCorrectFlag(Const.mContext, true);
                    Log.i(SecurityService.TAG, "touch here and cancorrect = " + Utils.getCanCorrectFlag(Const.mContext));
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: i */
    private static int f4741i = -1;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m1961a(TrafficStatsService x0) {
        long jCurrentTimeMillis = System.currentTimeMillis() - x0.f4743b.getLong("last_save_daily_data_time", 0L);
        if (jCurrentTimeMillis >= 7200000) {
            return true;
        }
        if (jCurrentTimeMillis <= 0) {
            x0.m1968d();
        }
        return false;
    }

    public static synchronized TrafficStatsService getInstance(Context context) {
        if (f4738f == null) {
            f4738f = new TrafficStatsService(context);
        }
        return f4738f;
    }

    public static ExecutorService getExecutorService() {
        return f4739g;
    }

    public static void statsTrafficMobileInLimit(final Context context) {
        getExecutorService().execute(new Thread() { // from class: com.lenovo.safecenter.net.support.TrafficStatsService.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                boolean isCast = false;
                if (NetCache.is_net_flush_cast) {
                    isCast = true;
                    TrafficStatsService.statsTrafficMobile(context);
                    NetCache.is_net_flush_cast = false;
                }
                if (TrafficStatsService.f4737e && !isCast) {
                    boolean unused = TrafficStatsService.f4737e = false;
                    TrafficStatsService.statsTrafficMobile(context);
                    Message msg = new Message();
                    msg.what = 0;
                    TrafficStatsService.f4740h.sendMessageDelayed(msg, 60000L);
                }
                TrafficStatsService service = TrafficStatsService.getInstance(context);
                if (TrafficStatsService.m1961a(service)) {
                    service.insertDayTrafficDate(context);
                    service.m1968d();
                    Log.i("letraffic1", "insertDayTrafficDate =" + System.currentTimeMillis());
                }
            }
        });
    }

    /* JADX WARN: Code duplicated, block: B:102:0x03d6  */
    public static void statsTrafficMobile(Context context) {
        long jLongValue;
        long jStatsSettingUiMonthTrafficLowLevel;
        long jM1953a;
        long jM1963b;
        int trafficMode = getTrafficMode(context);
        switch (trafficMode) {
            case 10:
                String simSubscriberId = getImsiInfo(context).sim1IMSI;
                NetworkTemplate template = NetworkTemplate.buildTemplateMobileAll(simSubscriberId);
                Object netWorkStatsService = getNetWorkStatsService();
                Log.i("forzajuve", Thread.currentThread().getName() + "====>TrafficUtils doStats()  start...");
                m1959a(simSubscriberId, (String) null, context);
                if (TextUtils.isEmpty(simSubscriberId)) {
                    jM1953a = Const.getTodayUsedTraffic();
                    jM1963b = Const.getMonthUsedTraffic();
                } else {
                    jM1953a = m1953a(netWorkStatsService, template);
                    jM1963b = m1963b(netWorkStatsService, template);
                }
                if (!TextUtils.isEmpty(simSubscriberId)) {
                    String[] strArrQueryTrafficCheck = getInstance(context).queryTrafficCheck(simSubscriberId);
                    if (!TextUtils.isEmpty(strArrQueryTrafficCheck[0]) && WflUtils.isInTheSameMonth(System.currentTimeMillis(), Long.valueOf(strArrQueryTrafficCheck[0]).longValue()) && checkCorrectTime(System.currentTimeMillis(), Long.valueOf(strArrQueryTrafficCheck[0]).longValue())) {
                        Log.i("testtrafficbug", "touch sim if begin " + jM1963b + ",trafficCheckDatas[1] = " + strArrQueryTrafficCheck[1]);
                        jM1963b += Long.valueOf(strArrQueryTrafficCheck[1]).longValue();
                        Log.i("testtrafficbug", "touch sim if end " + jM1963b + ",trafficCheckDatas[1] = " + strArrQueryTrafficCheck[1]);
                    }
                }
                if (jM1963b < 0) {
                    jM1963b = m1963b(netWorkStatsService, template) < 0 ? 0L : m1963b(netWorkStatsService, template);
                }
                boolean z = !"-1".equals(Const.getMonthLimitTraffic());
                long jLongValue2 = Long.valueOf(Const.getMonthLimitTraffic()).longValue() * 1024 * 1024;
                long j = jLongValue2 - jM1963b;
                Log.i("forzajuve", "monthLImit = " + jLongValue2 + ",monthfree = " + j);
                int i = !z ? 0 : (int) (((jLongValue2 - j) * 100) / jLongValue2);
                Const.setTodayUsedTraffic(jM1953a);
                Const.setMonthFreeTraffic(j);
                Const.setMonthUsedTraffic(jM1963b);
                Log.i("4.0", "today use = " + jM1953a + ",month use = " + jM1963b);
                Const.setProgressTrafficMonthUsed(i);
                NetCache.setTraffic_used_progress(i);
                MyUtils.showLeSecNotification(context);
                LeSafeObservable.get(context).noticeRefreshTrafficInfo();
                if (Const.getIsNetMonitorOn()) {
                    long netEverydayLimit = Const.getNetEverydayLimit();
                    if (Const.getNetEverydayLimit() != -1 && !Const.getIsTodayNoticed() && jM1953a >= 1024 * netEverydayLimit * 1024) {
                        m1956a(context, 22, 0, 10, netEverydayLimit);
                    }
                    if (Const.getIsNetMonthFreeNoticeOn1() && !Const.isNetAlarmedInMonth() && i >= 90 && i < 100) {
                        m1956a(context, 20, 0, 10, 0L);
                    }
                    if (j < 0 && z) {
                        m1956a(context, 21, 0, 10, netEverydayLimit);
                        break;
                    }
                }
                break;
            case 12:
                mutiSIMdoStats(getNetWorkStatsService(), context);
                break;
            case 13:
                long totalToday = getTotalToday(getInstance(context).getOpenHelper().getWritableDatabase(), getDate());
                long jStatsSettingUiMonthTrafficLowLevel2 = statsSettingUiMonthTrafficLowLevel(context);
                long netEverydayLimit2 = Const.getNetEverydayLimit();
                if (Const.getNetEverydayLimit() != -1 && !Const.getIsTodayNoticed() && totalToday >= 1024 * netEverydayLimit2 * 1024) {
                    m1956a(context, 22, 0, 13, netEverydayLimit2);
                }
                if (TextUtils.isEmpty("dev")) {
                    jLongValue = jStatsSettingUiMonthTrafficLowLevel2;
                } else {
                    String[] strArrQueryTrafficCheck2 = getInstance(context).queryTrafficCheck("dev");
                    if (!TextUtils.isEmpty(strArrQueryTrafficCheck2[0]) && WflUtils.isInTheSameMonth(System.currentTimeMillis(), Long.valueOf(strArrQueryTrafficCheck2[0]).longValue()) && checkCorrectTime(System.currentTimeMillis(), Long.valueOf(strArrQueryTrafficCheck2[0]).longValue())) {
                        Log.i("testtrafficbug", "touch open if begin " + jStatsSettingUiMonthTrafficLowLevel2 + ",trafficCheckDatas[1] = " + strArrQueryTrafficCheck2[1]);
                        jLongValue = Long.valueOf(strArrQueryTrafficCheck2[1]).longValue() + jStatsSettingUiMonthTrafficLowLevel2;
                        Log.i("testtrafficbug", "touch open if begin " + jLongValue + ",trafficCheckDatas[1] = " + strArrQueryTrafficCheck2[1]);
                    } else {
                        jLongValue = jStatsSettingUiMonthTrafficLowLevel2;
                    }
                }
                if (jLongValue < 0) {
                    jStatsSettingUiMonthTrafficLowLevel = statsSettingUiMonthTrafficLowLevel(context) < 0 ? 0L : statsSettingUiMonthTrafficLowLevel(context);
                } else {
                    jStatsSettingUiMonthTrafficLowLevel = jLongValue;
                }
                boolean z2 = !"-1".equals(Const.getMonthLimitTraffic());
                long jLongValue3 = Long.valueOf(Const.getMonthLimitTraffic()).longValue() * 1024 * 1024;
                long j2 = jLongValue3 - jStatsSettingUiMonthTrafficLowLevel;
                Log.i("forzajuve", "monthLImit = " + jLongValue3 + ",monthfree = " + j2);
                int i2 = !z2 ? 0 : (int) (((jLongValue3 - j2) * 100) / jLongValue3);
                if (Const.getIsNetMonthFreeNoticeOn1() && !Const.isNetAlarmedInMonth() && i2 >= 90 && i2 < 100) {
                    Log.i("forzajuve", "touch warnning");
                    m1956a(context, 20, 0, 13, netEverydayLimit2);
                }
                Const.setTodayUsedTraffic(totalToday);
                Const.setMonthFreeTraffic(j2);
                Const.setMonthUsedTraffic(jStatsSettingUiMonthTrafficLowLevel);
                Const.setProgressTrafficMonthUsed(i2);
                Log.i("3.6", "today use = " + totalToday + ",month use = " + jStatsSettingUiMonthTrafficLowLevel);
                NetCache.setTraffic_used_progress(i2);
                MyUtils.showLeSecNotification(context);
                LeSafeObservable.get(context).noticeRefreshTrafficInfo();
                if (j2 < 0 && z2 && !Const.isNetLimitedInMonth()) {
                    m1956a(context, 21, 0, 13, netEverydayLimit2);
                    break;
                }
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m1959a(String imsi, String imsi2, Context context) {
        SharedPreferences sp = getTrafficSP(context);
        if (!TextUtils.isEmpty(imsi) && !NetCache.getCached_imsi().equals(imsi)) {
            sp.edit().putString(NetConstant.IMSI_CATCHE_SIM, imsi).commit();
            NetCache.setCached_imsi(imsi);
            Log.i("trafficui", "edit IMSI_CATCHE_SIM");
        }
        if (!TextUtils.isEmpty(imsi2) && !NetCache.getCached_imsi2().equals(imsi2)) {
            sp.edit().putString(NetConstant.IMSI_CATCHE_SIM2, imsi2).commit();
            NetCache.setCached_imsi2(imsi2);
        }
    }

    public static long statsSystemMonthTraffic(Context context) {
        String simSubscriberId = WflUtils.getActiveSubscriberId(context);
        NetworkTemplate template = NetworkTemplate.buildTemplateMobileAll(simSubscriberId);
        long totalMonth = m1963b(getNetWorkStatsService(), template);
        return totalMonth;
    }

    public static long statsSystemMonthTraffic(Context context, int postion) {
        String simSubscriberId = getSIMSubscriberId(context, postion);
        NetworkTemplate template = NetworkTemplate.buildTemplateMobileAll(simSubscriberId);
        long totalMonth = m1963b(getNetWorkStatsService(), template);
        return totalMonth;
    }

    public static String getSIMSubscriberId(Context context, int postion) {
        if (MyMultiSIMUtils.isMultiSim(context)) {
            return MultiSIMUtils.getDefault(context).getSubscriberId(postion);
        }
        if (getTrafficMode(context) == 13) {
            return "dev";
        }
        return WflUtils.getActiveSubscriberId(context);
    }

    /* JADX INFO: renamed from: a */
    private static long m1953a(Object statsService, NetworkTemplate template) {
        long startTimeToday = WflUtils.getTriggerTime(0, 0, 0);
        long end = System.currentTimeMillis();
        try {
            long totalNetwork = invoke("getSummaryForNetwork", statsService, template, startTimeToday, end);
            return totalNetwork;
        } catch (Exception e) {
            return 0L;
        }
    }

    /* JADX INFO: renamed from: b */
    private static long m1963b(Object statsService, NetworkTemplate template) {
        long startTimeMonth = WflUtils.parseMonthStartTime(Long.valueOf(System.currentTimeMillis())).longValue();
        long end = System.currentTimeMillis();
        long totalNetwork = 0;
        try {
            totalNetwork = invoke("getSummaryForNetwork", statsService, template, startTimeMonth, end);
            Log.i("testtrafficbug", "sys month used = " + totalNetwork);
            return totalNetwork;
        } catch (Exception e) {
            return totalNetwork;
        }
    }

    public static long statsSettingUiMonthTrafficLowLevel(Context context) {
        SQLiteDatabase db = context.openOrCreateDatabase(DB_NAME, 0, null);
        return getTotalMonthly(db).longValue();
    }

    private TrafficStatsService(Context context) {
        this.f4742a = new TrafficStatsSQLiteOpenHelper(context);
        this.f4743b = PreferenceManager.getDefaultSharedPreferences(context);
        this.f4744c = this.f4743b.edit();
        this.f4745d = context;
    }

    public TrafficStatsSQLiteOpenHelper getOpenHelper() {
        return this.f4742a;
    }

    public void setOpenHelper(TrafficStatsSQLiteOpenHelper openHelper) {
        this.f4742a = openHelper;
    }

    public SharedPreferences getPreferences() {
        return this.f4743b;
    }

    public void setPreferences(SharedPreferences preferences) {
        this.f4743b = preferences;
    }

    public SQLiteDatabase getSQLiteDatabase() {
        return this.f4742a.getWritableDatabase();
    }

    public static String getDetailedDate() {
        return getCurrentYear() + "." + getCurrentMonth() + "." + Calendar.getInstance().get(5);
    }

    public static int getDate() {
        return Calendar.getInstance().get(5);
    }

    public void updateTrafficTab(int dateFlag, int total) {
        SQLiteDatabase db = this.f4742a.getWritableDatabase();
        Cursor cursor = db.rawQuery("select total from traffic where date=?", new String[]{String.valueOf(dateFlag)});
        if (cursor != null) {
            if (cursor.getCount() == 0) {
                ContentValues values = new ContentValues();
                values.put(TOTAL, Integer.valueOf(total));
                values.put("date", Integer.valueOf(dateFlag));
                db.insert(TRAFFIC, TOTAL, values);
            } else {
                while (cursor.moveToNext()) {
                    db.execSQL("update traffic set total=? where date=?", new Object[]{Integer.valueOf(total), Integer.valueOf(dateFlag)});
                }
            }
        }
        if (cursor != null && !cursor.isClosed()) {
            cursor.close();
        }
    }

    public int getTotalBeforeDay(int day) {
        SQLiteDatabase db = this.f4742a.getWritableDatabase();
        int sumTotal = 0;
        for (int i = 1; i < day; i++) {
            Cursor cusor = db.rawQuery(" SELECT total FROM traffic where date = ?", new String[]{String.valueOf(i)});
            if (cusor.moveToFirst()) {
                sumTotal += cusor.getInt(0);
            }
            Log.i("forzajuve", "sumTotal i =" + sumTotal);
            cusor.close();
        }
        return sumTotal;
    }

    public void deleteTrafficData() {
        SQLiteDatabase db = this.f4742a.getWritableDatabase();
        if (db != null && db.isOpen()) {
            db.execSQL("DELETE FROM apps");
            db.close();
        }
    }

    public static int getCurrentMonth() {
        return Calendar.getInstance().get(2) + 1;
    }

    public static int getCurrentYear() {
        return Calendar.getInstance().get(1);
    }

    public void insertDayTrafficDate(Context context) {
        int mode = getTrafficMode(context);
        if (mode == 13) {
            m1958a("dev", 0);
            return;
        }
        PhoneSimInfo info = getImsiInfo(context);
        if (info.sim1IMSI != null) {
            m1958a(info.sim1IMSI, 0);
        }
        if (info.sim2IMSI != null) {
            m1958a(info.sim2IMSI, 1);
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1958a(String imsi, int postion) {
        try {
            int bar_height = m1967c();
            SQLiteDatabase db = this.f4742a.getWritableDatabase();
            long maxTotal = this.f4743b.getLong(imsi, -1L);
            String today = getDetailedDate();
            long trafficToday = postion == 0 ? Const.getTodayUsedTraffic() : Const.getTodayUsedTraffic2();
            Cursor cusrsor = db.rawQuery("SELECT total FROM traffic WHERE date = ? and imsi = ?", new String[]{today, imsi});
            if (cusrsor.moveToFirst()) {
                if (trafficToday > maxTotal) {
                    this.f4744c.putLong(imsi, trafficToday).commit();
                    maxTotal = trafficToday;
                    m1957a(db, maxTotal, imsi);
                }
                Log.i("double", "trafficToday = " + trafficToday);
                int height = getHeight(trafficToday, maxTotal);
                db.execSQL("update traffic set total = ?, height = ? where date = ? and imsi = ?", new Object[]{Long.valueOf(trafficToday), Integer.valueOf(height), today, imsi});
            } else {
                ContentValues values = new ContentValues();
                values.put(TOTAL, Long.valueOf(trafficToday));
                values.put("date", today);
                values.put("imsi", imsi);
                if (maxTotal == -1) {
                    if (trafficToday <= 0) {
                        values.put(SaveData.FLOATVIEW_HEIGHT, (Integer) 0);
                    } else {
                        values.put(SaveData.FLOATVIEW_HEIGHT, Integer.valueOf(bar_height));
                        this.f4744c.putLong(imsi, trafficToday).commit();
                    }
                } else if (maxTotal >= trafficToday) {
                    values.put(SaveData.FLOATVIEW_HEIGHT, Integer.valueOf(getHeight(trafficToday, maxTotal)));
                } else {
                    this.f4744c.putLong(imsi, trafficToday).commit();
                    m1957a(db, trafficToday, imsi);
                    values.put(SaveData.FLOATVIEW_HEIGHT, Integer.valueOf(bar_height));
                }
                db.insert(TRAFFIC, TOTAL, values);
            }
            if (this.f4743b.getBoolean("traffc_view_height_changed_flag", false)) {
                m1957a(db, this.f4743b.getLong(imsi, -1L), imsi);
                this.f4744c.putBoolean("traffc_view_height_changed_flag", false).commit();
                Log.i("viewheight1", "touch my change height");
            }
            cusrsor.close();
            db.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public HashMap<String, TrafficDate> getDayTrafficInMonth(String imsi) {
        HashMap<String, TrafficDate> map = new HashMap<>();
        try {
            SQLiteDatabase db = this.f4742a.getReadableDatabase();
            SQLiteDatabase sQLiteDatabaseM1964b = m1964b(db);
            String[] strArr = new String[1];
            if (imsi == null) {
                imsi = "";
            }
            strArr[0] = imsi;
            Cursor cursor = sQLiteDatabaseM1964b.rawQuery(" SELECT total,date,height FROM traffic where imsi = ?", strArr);
            if (cursor != null) {
                while (cursor.moveToNext()) {
                    int dayTotal = cursor.getInt(0);
                    String day = cursor.getString(1);
                    int height = cursor.getInt(2);
                    TrafficDate trafficDate = new TrafficDate(day, dayTotal, height);
                    map.put(day, trafficDate);
                }
            }
            if (cursor != null && !cursor.isClosed()) {
                cursor.close();
            }
            if (db != null && db.isOpen()) {
                db.close();
            }
        } catch (Exception e) {
            Log.i("sqle", "getDayTrafficInMonth sql exception");
            e.printStackTrace();
        }
        return map;
    }

    /* JADX INFO: renamed from: a */
    private void m1957a(SQLiteDatabase db, long maxTotal, String imsi) {
        Cursor cursor = db.rawQuery("select total,date from traffic where imsi = ?", new String[]{imsi});
        while (cursor.moveToNext()) {
            String day = cursor.getString(1);
            if (day.startsWith(getCurrentYear() + "." + getCurrentMonth() + ".")) {
                int total = cursor.getInt(0);
                Log.i("exec", "total = " + total);
                db.execSQL("update traffic set height=? where total=? and imsi= ?", new Object[]{Integer.valueOf(getHeight(total, maxTotal)), Integer.valueOf(total), imsi});
            }
        }
        cursor.close();
    }

    public int getHeight(long total, long maxTotal) {
        int BAR_MAXHEIGHT2 = m1967c();
        if (maxTotal <= 0) {
            return 0;
        }
        if (19522578 <= total) {
            float total2 = total;
            float maxtotal2 = maxTotal;
            return (int) ((total2 / maxtotal2) * BAR_MAXHEIGHT2);
        }
        int height = (int) ((((long) BAR_MAXHEIGHT2) * total) / maxTotal);
        return height <= BAR_MAXHEIGHT2 ? height : BAR_MAXHEIGHT2;
    }

    public void do4newMonth() {
        SharedPreferences sp = getTrafficSP(this.f4745d);
        if (sp.getInt("haveDone4newMonthTime", -1) != getCurrentMonth()) {
            deleteTrafficData();
            Const.setNetLimitedInMonth(false);
            Const.setNetLimitedInMonth2(false);
            Const.setIsNetAlarmedInMonth(false);
            Const.setHasNoticed2MonthLimit(false);
            Const.setIsNetAlarmedInMonth2(false);
            this.f4744c.putLong(NetCache.imsi, -1L).commit();
            this.f4744c.putLong(NetCache.imsi2, -1L).commit();
            sp.edit().putInt("haveDone4newMonthTime", getCurrentMonth()).commit();
            getExecutorService().execute(new Thread() { // from class: com.lenovo.safecenter.net.support.TrafficStatsService.3
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    TrafficStatsService.this.refresh();
                }
            });
            Log.i("forzajuve", "do4newmonth is exec ...");
        }
    }

    public static int getTetheringLabel(ConnectivityManager cm) {
        String[] usbRegexs = cm.getTetherableUsbRegexs();
        String[] wifiRegexs = cm.getTetherableWifiRegexs();
        String[] bluetoothRegexs = cm.getTetherableBluetoothRegexs();
        boolean usbAvailable = usbRegexs.length != 0;
        boolean wifiAvailable = wifiRegexs.length != 0;
        boolean bluetoothAvailable = bluetoothRegexs.length != 0;
        if (wifiAvailable && usbAvailable && bluetoothAvailable) {
            return C0415R.string.tether_settings_title_all;
        }
        if (wifiAvailable && usbAvailable) {
            return C0415R.string.tether_settings_title_all;
        }
        if (wifiAvailable && bluetoothAvailable) {
            return C0415R.string.tether_settings_title_all;
        }
        if (wifiAvailable) {
            return C0415R.string.tether_settings_title_wifi;
        }
        if (usbAvailable && bluetoothAvailable) {
            return C0415R.string.tether_settings_title_usb_bluetooth;
        }
        if (usbAvailable) {
            return C0415R.string.tether_settings_title_usb;
        }
        return C0415R.string.tether_settings_title_bluetooth;
    }

    public static void alert(Context ctx, CharSequence msg) {
        if (ctx != null) {
            try {
                new AlertDialog.Builder(ctx).setNeutralButton(C0415R.string.btn_OK, (DialogInterface.OnClickListener) null).setMessage(msg).setTitle(C0415R.string.error).show();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static boolean createShell(Context ctx) {
        String iptables;
        Log.i("createShell", "touch createShell method");
        if (ctx == null) {
            Log.i("createShell", "ctx is null");
            return false;
        }
        String[] ITFS_WIFI = {"tiwlan+", "wlan+", "eth+", "ra+"};
        String[] ITFS_3G = {"rmnet+", "pdp+", "ppp+", "uwbr+", "wimax+", "vsnet+", "ccmni+", "usb+"};
        StringBuilder command = new StringBuilder();
        command.append("#####\n");
        command.append("#!/sbin/ash\n");
        SharedPreferences prefs_sys = ctx.getSharedPreferences("system info", 0);
        SharedPreferences prefs_sys_wlan = ctx.getSharedPreferences("wlan info", 0);
        String allUid = prefs_sys.getString("selected uids", "");
        String[] uids = allUid.split(C0092c.f1284O);
        String allUidWlan = prefs_sys_wlan.getString("selected uids", "");
        String[] uidsWlan = allUidWlan.split(C0092c.f1284O);
        if (nacServerIsExist()) {
            iptables = "iptables ";
        } else {
            iptables = ctx.getFilesDir() + "/iptables ";
        }
        command.append(iptables + " -F OUTPUT\n");
        command.append(iptables + "-P OUTPUT ACCEPT\n");
        command.append(iptables + "-A OUTPUT -o lo -j ACCEPT\n");
        if (NetCache.traffic_mode != 13) {
            Log.i("createShell", "in not open phone");
            if (!allUid.equals("") && uids.length > 0) {
                for (String uid : uids) {
                    command.append(iptables + "-A OUTPUT -o rmnet+ -m owner --uid-owner " + uid + " -j DROP\n");
                    command.append(iptables + "-A OUTPUT -o ccmni+ -m owner --uid-owner " + uid + " -j DROP\n");
                }
            }
            if (!allUidWlan.equals("") && uidsWlan.length > 0) {
                for (String uid2 : uidsWlan) {
                    command.append(iptables + "-A OUTPUT -o wlan0 -m owner --uid-owner " + uid2 + " -j DROP\n");
                }
            }
        } else {
            if (!allUid.equals("") && uids.length > 0) {
                for (String uid3 : uids) {
                    for (String mobileNetName : ITFS_3G) {
                        command.append(iptables + "-A OUTPUT -o " + mobileNetName + " -m owner --uid-owner " + uid3 + " -j DROP\n");
                    }
                }
            }
            if (!allUidWlan.equals("") && uidsWlan.length > 0) {
                for (String uid4 : uidsWlan) {
                    for (String wifiNetName : ITFS_WIFI) {
                        command.append(iptables + "-A OUTPUT -o " + wifiNetName + " -m owner --uid-owner " + uid4 + " -j DROP\n");
                    }
                }
            }
        }
        return CMDHelper.exeCmd(ctx, command.toString());
    }

    public static String getPlatform(Context context) {
        try {
            String platform = MultiSIMUtils.getDefault(context).getPlatform();
            Log.i("4.1", "platform =" + platform);
            return platform;
        } catch (Throwable e) {
            e.printStackTrace();
            return "mtk";
        }
    }

    public static long getTotalToday(SQLiteDatabase db, int date) {
        long total = 0;
        int today = getDate();
        try {
            Cursor cursor = db.rawQuery(" SELECT SUM(sent)+SUM(received) AS daily FROM apps WHERE uid=65525 AND _date=?", new String[]{String.valueOf(today)});
            if (cursor != null && cursor.moveToFirst()) {
                cursor.moveToFirst();
                total = cursor.getLong(cursor.getColumnIndex("daily"));
                if (!cursor.isClosed()) {
                    cursor.close();
                }
                if (db.isOpen() && !db.isDbLockedByOtherThreads()) {
                    db.close();
                }
            }
        } catch (Exception e) {
            Log.i("trafficdb", "catch traffic db exception");
        }
        return total;
    }

    public static Long getTotalMonthly(SQLiteDatabase db) {
        Cursor cursor = db.rawQuery("SELECT SUM(sent)+SUM(received) AS total FROM apps WHERE uid = 65525", null);
        if (cursor != null) {
            try {
                try {
                    cursor.moveToFirst();
                    Long lValueOf = Long.valueOf(cursor.getLong(0));
                    if (cursor != null) {
                        try {
                            if (!cursor.isClosed()) {
                                cursor.close();
                            }
                        } catch (Exception e) {
                            e.printStackTrace();
                            return lValueOf;
                        }
                    }
                    if (!db.isOpen() || db.isDbLockedByOtherThreads()) {
                        return lValueOf;
                    }
                    db.close();
                    return lValueOf;
                } catch (Exception e2) {
                    e2.printStackTrace();
                    if (cursor != null) {
                        try {
                            if (!cursor.isClosed()) {
                                cursor.close();
                            }
                            if (db.isOpen() && !db.isDbLockedByOtherThreads()) {
                                db.close();
                            }
                        } catch (Exception e3) {
                            e3.printStackTrace();
                        }
                    } else if (db.isOpen()) {
                        db.close();
                    }
                    return -1L;
                }
            } catch (Throwable th) {
                if (cursor != null) {
                    try {
                        if (!cursor.isClosed()) {
                            cursor.close();
                        }
                        if (db.isOpen() && !db.isDbLockedByOtherThreads()) {
                            db.close();
                        }
                    } catch (Exception e4) {
                        e4.printStackTrace();
                        throw th;
                    }
                } else if (db.isOpen()) {
                    db.close();
                }
                throw th;
            }
        }
        if (cursor != null) {
            try {
                if (!cursor.isClosed()) {
                    cursor.close();
                }
                if (db.isOpen() && !db.isDbLockedByOtherThreads()) {
                    db.close();
                }
            } catch (Exception e5) {
                e5.printStackTrace();
            }
        } else if (db.isOpen()) {
            db.close();
        }
        return -1L;
    }

    public void refreshTotal() {
        SQLiteDatabase db = this.f4742a.getWritableDatabase();
        try {
            Context context = this.f4745d;
            m1955a(65525, db);
            if (db != null && db.isOpen() && !db.isDbLockedByOtherThreads()) {
                db.close();
            }
        } catch (Exception e) {
            Log.i("Receiver", "catch Exception......");
        }
    }

    public void refresh() {
        SQLiteDatabase db = this.f4742a.getWritableDatabase();
        try {
            Context context = this.f4745d;
            m1955a(65525, db);
            ArrayList<AppInfo> apps = getApps(this.f4745d);
            for (AppInfo appInfo : apps) {
                Context context2 = this.f4745d;
                m1955a(appInfo.uid, db);
            }
        } catch (Exception e) {
            e.printStackTrace();
            Log.i("Receiver", "catch Exception......");
        } finally {
            db.close();
            Log.i("Receiver", "finally......");
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1955a(int uid, SQLiteDatabase db) {
        long receivedData;
        long sendData;
        Log.i("3.6", " uid = " + uid);
        int day = getDate();
        if (uid == 65525) {
            receivedData = TrafficStats.getMobileRxBytes();
            Log.i("3.6", "receivedData 65525 = " + receivedData);
            sendData = TrafficStats.getMobileTxBytes();
            Log.i("3.6", "sendData 65525 = " + sendData);
        } else {
            receivedData = TrafficStats.getUidRxBytes(uid);
            sendData = TrafficStats.getUidTxBytes(uid);
            Log.i("3.6", "update_process " + uid + "===== and receivedData = " + receivedData + "sendData = " + sendData);
        }
        if (receivedData == -1) {
            receivedData = 0;
        }
        if (sendData == -1) {
            sendData = 0;
        }
        Cursor cursor = null;
        try {
            cursor = m1954a(db).query("apps", new String[]{"received", "sent", "last_received", "last_sent"}, "uid = ? ", new String[]{String.valueOf(uid)}, null, null, "_id DESC", DatabaseTables.SYSTEM_MARK);
            if (cursor.getCount() != 0) {
                cursor.moveToFirst();
                Long last_received = Long.valueOf(cursor.getLong(cursor.getColumnIndex("last_received")));
                Log.i("3.6", "last_received" + last_received);
                Long last_sent = Long.valueOf(cursor.getLong(cursor.getColumnIndex("last_sent")));
                if (last_received.longValue() == -1) {
                    last_received = 0L;
                }
                if (last_sent.longValue() == -1) {
                    last_sent = 0L;
                }
                Long received = Long.valueOf(receivedData - last_received.longValue());
                Long send = Long.valueOf(sendData - last_sent.longValue());
                Long total = Long.valueOf(received.longValue() + send.longValue());
                Log.i("3.6", "update_process uid=" + uid + "and last_received = " + last_received + " last_send = " + last_sent + " total = " + total);
                if (total.longValue() != 0) {
                    if (total.longValue() > 0) {
                        m1954a(db).execSQL("INSERT INTO apps (uid, _date, received, sent, last_received, last_sent) VALUES ( ? , ? , ? , ? , ? , ? )", new Object[]{Integer.valueOf(uid), Integer.valueOf(day), received, send, Long.valueOf(receivedData), Long.valueOf(sendData)});
                        Log.i("Receiver", "update_process totoal >>>>>>> 0 uid =" + uid);
                    } else {
                        m1954a(db).execSQL("INSERT INTO apps (uid, _date, received, sent, last_received, last_sent) VALUES ( ? , ? , ? , ? , ? , ? )", new Object[]{Integer.valueOf(uid), Integer.valueOf(day), Long.valueOf(receivedData), Long.valueOf(sendData), Long.valueOf(receivedData), Long.valueOf(sendData)});
                        Log.i("Receiver", "update_process totoal <<<<<< 0");
                    }
                }
            } else if (receivedData + sendData > 0) {
                m1954a(db).execSQL("INSERT INTO apps (uid, _date, received, sent, last_received, last_sent) VALUES ( ? , ? , ? , ? , ? , ? )", new Object[]{Integer.valueOf(uid), Integer.valueOf(day), Long.valueOf(receivedData), Long.valueOf(sendData), Long.valueOf(receivedData), Long.valueOf(sendData)});
                Log.i("3.6", "update_process getCount() == 0 then insert into the table......");
                m1954a(db).execSQL("update apps set received = ?, sent = ? where uid = ?", new Object[]{0, 0, Integer.valueOf(uid)});
            }
        } finally {
            if (cursor != null) {
                cursor.close();
            }
        }
    }

    public static HashSet<Integer> getNetWorkApps(Context ctx, HashSet<Integer> set) {
        HashSet<Integer> mApps = new HashSet<>();
        PackageManager pkgmanager = ctx.getPackageManager();
        List<ApplicationInfo> installed = pkgmanager.getInstalledApplications(0);
        for (ApplicationInfo applicationInfo : installed) {
            if (pkgmanager.checkPermission("android.permission.INTERNET", applicationInfo.packageName) == 0 && !set.contains(Integer.valueOf(applicationInfo.uid))) {
                mApps.add(Integer.valueOf(applicationInfo.uid));
            }
        }
        return mApps;
    }

    public static ArrayList<AppInfo> getApps(Context ctx) {
        ArrayList<AppInfo> mApps = new ArrayList<>();
        PackageManager pkgmanager = ctx.getPackageManager();
        List<ApplicationInfo> installed = pkgmanager.getInstalledApplications(0);
        for (ApplicationInfo applicationInfo : installed) {
            if (pkgmanager.checkPermission("android.permission.INTERNET", applicationInfo.packageName) == 0) {
                AppInfo appInfo = new AppInfo();
                appInfo.uid = applicationInfo.uid;
                appInfo.item_3g = 0L;
                mApps.add(appInfo);
            }
        }
        return mApps;
    }

    public static ArrayList<AppInfo> getAppInfos(Context ctx, HashSet<Integer> set) {
        ArrayList<AppInfo> appList = new ArrayList<>();
        TrafficStatsSQLiteOpenHelper openHelper = new TrafficStatsSQLiteOpenHelper(ctx);
        SQLiteDatabase db = openHelper.getWritableDatabase();
        Cursor cursor = null;
        try {
            cursor = db.query("apps", new String[]{"uid", "SUM(received)+SUM(sent) AS item_3g"}, null, null, "uid", null, "SUM(received)+SUM(sent) DESC");
            Log.d("boot", "apps in database: " + cursor.getCount());
            while (cursor.moveToNext()) {
                AppInfo app = new AppInfo();
                app.uid = cursor.getInt(cursor.getColumnIndex("uid"));
                if (app.uid != 65525 && app.uid != 1000) {
                    app.item_3g = cursor.getLong(cursor.getColumnIndex("item_3g"));
                    appList.add(app);
                    set.add(Integer.valueOf(app.uid));
                }
            }
            if (cursor != null) {
                cursor.close();
            }
            Log.d("boot", "apps to show: " + appList.size());
            openHelper.close();
            return appList;
        } catch (Throwable th) {
            if (cursor != null) {
                cursor.close();
            }
            throw th;
        }
    }

    public void refreshUid() {
        SQLiteDatabase db = this.f4742a.getWritableDatabase();
        try {
            ArrayList<AppInfo> apps = getApps(this.f4745d);
            for (AppInfo appInfo : apps) {
                Context context = this.f4745d;
                m1955a(appInfo.uid, db);
            }
            if (db != null && db.isOpen()) {
                db.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
            Log.i("Receiver", "catch Exception......");
        }
    }

    public static int getSimState(Context context) {
        TelephonyManager mTelephonyMgr = (TelephonyManager) context.getSystemService("phone");
        return mTelephonyMgr.getSimState();
    }

    public static boolean getIfSimState(Context context) {
        int simState = getSimState(context);
        return (simState == 1 || simState == 0) ? false : true;
    }

    public static PhoneSimInfo getImsiInfo(Context context) {
        PhoneSimInfo info = new PhoneSimInfo();
        info.isMutiSimCard = NetCache.isProvideMuti;
        try {
            long now = System.currentTimeMillis();
            long bootTime = NetCache.getBoot_time();
            boolean isBoot = bootTime == 0 || now - bootTime < 60000;
            if (!MyMultiSIMUtils.isMultiSim(context)) {
                info.sim1IMSI = WflUtils.getActiveSubscriberId(context);
                if (TextUtils.isEmpty(info.sim1IMSI) && (IsAirModeOn(context) || isBoot)) {
                    info.sim1IMSI = NetCache.getCached_imsi();
                    Log.i("bootairtest", "touch @@@@@@ single");
                }
                if (!TextUtils.isEmpty(info.sim1IMSI)) {
                    info.SimState = true;
                }
                info.sim2IMSI = null;
            } else {
                info.sim1IMSI = MultiSIMUtils.getDefault(context).getSubscriberId(0);
                info.sim2IMSI = MultiSIMUtils.getDefault(context).getSubscriberId(1);
                Log.i("bootairtest", "@getImsiInfo now = " + now + "boottime =" + bootTime + ",is boot =" + isBoot);
                if (TextUtils.isEmpty(info.sim1IMSI) && TextUtils.isEmpty(info.sim2IMSI) && (IsAirModeOn(context) || isBoot)) {
                    info.sim1IMSI = NetCache.getCached_imsi();
                    info.sim2IMSI = NetCache.getCached_imsi2();
                    Log.i("bootairtest", "touch @@@@@@ double");
                }
                if (!TextUtils.isEmpty(info.sim1IMSI) || !TextUtils.isEmpty(info.sim2IMSI)) {
                    info.SimState = true;
                }
                Log.i("bootairtest", "imsi1 =" + info.sim1IMSI + ",imsi2 = " + info.sim2IMSI + "info.SimState = " + info.SimState);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return info;
    }

    public static int getImsiOperator(int postion, Context context) {
        PhoneSimInfo info = getImsiInfo(context);
        String tmp = postion == 0 ? info.sim1IMSI : info.sim2IMSI;
        if (tmp.contains("46000") || tmp.contains("46002")) {
            return 0;
        }
        if (tmp.contains("46001")) {
            return 1;
        }
        if (tmp.contains("46003")) {
            return 2;
        }
        return 8;
    }

    public static void mutiSIMdoStats(Object statsService, Context context) {
        long totalToday1;
        long totalMonth1;
        long totalToday2;
        long totalMonth2;
        int progress1;
        int progress2;
        PhoneSimInfo info = getImsiInfo(context);
        m1959a(info.sim1IMSI, info.sim2IMSI, context);
        NetworkTemplate template1 = NetworkTemplate.buildTemplateMobileAll(info.sim1IMSI);
        NetworkTemplate template2 = NetworkTemplate.buildTemplateMobileAll(info.sim2IMSI);
        Log.i("4.0", "sim1 imsi = " + info.sim1IMSI + ",sim2 imsi = " + info.sim2IMSI + ",totalMonth = 0,totalMonth2 =0");
        TrafficStatsService service = getInstance(context);
        if (TextUtils.isEmpty(info.sim1IMSI)) {
            totalToday1 = Const.getTodayUsedTraffic();
            totalMonth1 = Const.getMonthUsedTraffic();
        } else {
            totalToday1 = m1953a(statsService, template1);
            totalMonth1 = m1963b(statsService, template1);
            String[] trafficCheckDatas1 = service.queryTrafficCheck(info.sim1IMSI);
            Log.i("testtrafficbug", "check month used  sim1 = " + trafficCheckDatas1[1] + ",trafficCheckDatas1[0] = " + trafficCheckDatas1[0] + ",System.currentTimeMillis() =" + System.currentTimeMillis());
            if (!TextUtils.isEmpty(trafficCheckDatas1[0]) && WflUtils.isInTheSameMonth(System.currentTimeMillis(), Long.valueOf(trafficCheckDatas1[0]).longValue()) && checkCorrectTime(System.currentTimeMillis(), Long.valueOf(trafficCheckDatas1[0]).longValue())) {
                Log.i("testtrafficbug", "touch sim1 if begin " + totalMonth1 + ",trafficCheckDatas1[1] = " + trafficCheckDatas1[1]);
                totalMonth1 += Long.valueOf(trafficCheckDatas1[1]).longValue();
                Log.i("testtrafficbug", "touch sim1 if end " + totalMonth1 + ",trafficCheckDatas1[1] = " + trafficCheckDatas1[1]);
            }
        }
        if (TextUtils.isEmpty(info.sim2IMSI)) {
            totalToday2 = Const.getTodayUsedTraffic2();
            totalMonth2 = Const.getMonthUsedTraffic2();
        } else {
            totalToday2 = m1953a(statsService, template2);
            totalMonth2 = m1963b(statsService, template2);
            String[] trafficCheckDatas2 = service.queryTrafficCheck(info.sim2IMSI);
            Log.i("testtrafficbug", "check month used  sim2 = " + trafficCheckDatas2[1] + ",trafficCheckDatas2[0] = " + trafficCheckDatas2[0] + ",System.currentTimeMillis() =" + System.currentTimeMillis());
            if (!TextUtils.isEmpty(trafficCheckDatas2[0]) && WflUtils.isInTheSameMonth(System.currentTimeMillis(), Long.valueOf(trafficCheckDatas2[0]).longValue()) && checkCorrectTime(System.currentTimeMillis(), Long.valueOf(trafficCheckDatas2[0]).longValue())) {
                Log.i("testtrafficbug", "touch sim2 if begin " + totalMonth2 + ",trafficCheckDatas2[1] = " + trafficCheckDatas2[1]);
                totalMonth2 += Long.valueOf(trafficCheckDatas2[1]).longValue();
                Log.i("testtrafficbug", "touch sim2 if end " + totalMonth2 + ",trafficCheckDatas2[1] = " + trafficCheckDatas2[1]);
            }
        }
        if (totalMonth1 < 0) {
            totalMonth1 = m1963b(statsService, template1) < 0 ? 0L : m1963b(statsService, template1);
        }
        if (totalMonth2 < 0) {
            totalMonth2 = m1963b(statsService, template2) < 0 ? 0L : m1963b(statsService, template2);
        }
        boolean ifSeted1 = !"-1".equals(Const.getMonthLimitTraffic());
        boolean ifSeted2 = !"-1".equals(Const.getMonthLimitTraffic2());
        long monthLimit1 = Long.valueOf(Const.getMonthLimitTraffic()).longValue() * 1024 * 1024;
        long monthLimit2 = Long.valueOf(Const.getMonthLimitTraffic2()).longValue() * 1024 * 1024;
        long monthFree1 = monthLimit1 - totalMonth1;
        long monthFree2 = monthLimit2 - totalMonth2;
        if (!ifSeted1) {
            progress1 = 0;
        } else {
            progress1 = (int) (((monthLimit1 - monthFree1) * 100) / monthLimit1);
        }
        if (!ifSeted2) {
            progress2 = 0;
        } else {
            progress2 = (int) (((monthLimit2 - monthFree2) * 100) / monthLimit2);
        }
        Const.setTodayUsedTraffic(totalToday1);
        Const.setMonthFreeTraffic(monthFree1);
        Const.setMonthUsedTraffic(totalMonth1);
        Log.i("letraffic", "today use1 = " + totalToday1 + ",month use1 = " + totalMonth1);
        Const.setTodayUsedTraffic2(totalToday2);
        Const.setMonthFreeTraffic2(monthFree2);
        Const.setMonthUsedTraffic2(totalMonth2);
        Log.i("4.0", "today use2 = " + totalToday2 + ",month use2 = " + totalMonth2);
        Const.setProgressTrafficMonthUsed(progress1);
        Const.setProgressTrafficMonthUsed2(progress2);
        NetCache.setTraffic_used_progress(progress1);
        NetCache.setTraffic_used_progress2(progress2);
        MyUtils.showLeSecNotification(context);
        LeSafeObservable.get(context).noticeRefreshTrafficInfo();
        if (Const.getIsNetMonitorOn()) {
            long todayLimit = Const.getNetEverydayLimit();
            if (Const.getNetEverydayLimit() != -1 && !Const.getIsTodayNoticed() && totalToday1 >= 1024 * todayLimit * 1024) {
                m1956a(context, 22, 0, 12, todayLimit);
            }
            if (Const.getNetEverydayLimit() != -1 && !getIsTodayNoticed2(context) && totalToday2 >= 1024 * todayLimit * 1024) {
                m1956a(context, 22, 1, 12, todayLimit);
            }
            if (Const.getIsNetMonthFreeNoticeOn1() && !Const.isNetAlarmedInMonth() && progress1 >= 90 && progress1 < 100) {
                m1956a(context, 20, 0, 12, todayLimit);
            }
            if (Const.getIsNetMonthFreeNoticeOn2() && !Const.isNetAlarmedInMonth2() && progress2 >= 90 && progress2 < 100) {
                m1956a(context, 20, 1, 12, todayLimit);
            }
            if (monthFree1 < 0 && ifSeted1) {
                m1956a(context, 21, 0, 12, todayLimit);
            }
            if (monthFree2 < 0 && ifSeted2) {
                m1956a(context, 21, 1, 12, todayLimit);
            }
        }
    }

    public static String formatTraffic(long total, Context context) {
        return total == 0 ? "" : Formatter.formatShortFileSize(context, total);
    }

    public static String getDataSIMId(Context context) {
        MultiSIMUtils mUtils = MultiSIMUtils.getDefault(context);
        try {
            Method method = mUtils.getClass().getDeclaredMethod("getDataSubscriberId", null);
            String id = (String) method.invoke(mUtils, new Object[0]);
            Log.i("s3", "data id =" + id);
            return id;
        } catch (Exception e) {
            e.printStackTrace();
            PhoneSimInfo info = getImsiInfo(context);
            if (Const.getTodayUsedTraffic() == 0 && Const.getTodayUsedTraffic2() > 0) {
                String id2 = info.sim2IMSI;
                return id2;
            }
            String id3 = info.sim1IMSI;
            return id3;
        }
    }

    public static int getDataCardPosition(Context context) {
        int i;
        boolean zIsEmpty = false;
        if (MyMultiSIMUtils.isMultiSim(context) && Const.SDK_VERSION >= 14) {
            MultiSIMUtils multiSIMUtils = MultiSIMUtils.getDefault(context);
            PhoneSimInfo imsiInfo = getImsiInfo(context);
            Logger.m1950i("8.20", "imsi 1 =" + imsiInfo.sim1IMSI + "imsi2 = " + imsiInfo.sim2IMSI);
            try {
                String str = (String) multiSIMUtils.getClass().getDeclaredMethod("getDataSubscriberId", null).invoke(multiSIMUtils, new Object[0]);
                if (!WflUtils.isMobileNetwork(context)) {
                    String dataCacheImsi = Const.getDataCacheImsi();
                    Log.i("8.20", "cachimsi =" + dataCacheImsi);
                    if (TextUtils.isEmpty(dataCacheImsi)) {
                        i = 0;
                        if (!TextUtils.isEmpty(imsiInfo.sim2IMSI) && (zIsEmpty = TextUtils.isEmpty(imsiInfo.sim1IMSI))) {
                            i = 1;
                        }
                    } else {
                        i = dataCacheImsi.equals(imsiInfo.sim1IMSI) ? 0 : 1;
                    }
                } else {
                    i = str.equals(imsiInfo.sim1IMSI) ? 0 : 1;
                }
                return i;
            } catch (Exception e) {
                e.printStackTrace();
                if (imsiInfo.sim1IMSI == null && imsiInfo.sim2IMSI != null) {
                    return 1;
                }
                if (imsiInfo.sim1IMSI != null && imsiInfo.sim2IMSI == null) {
                    return zIsEmpty ? 1 : 0;
                }
                if (imsiInfo.sim1IMSI == null || imsiInfo.sim2IMSI == null) {
                    return 3;
                }
                if (Const.getTodayUsedTraffic() != 0 || Const.getTodayUsedTraffic2() <= 0) {
                    return zIsEmpty ? 1 : 0;
                }
                return 1;
            }
        }
        return 0;
    }

    public static void startIntent2TrafficCorrect(int card, Context context, int type) {
        boolean z = true;
        try {
            PhoneSimInfo info = getImsiInfo(context);
            if (card == 0) {
                if (TextUtils.isEmpty(info.sim1IMSI)) {
                    if (getTrafficMode(context) == 13 && MyMultiSIMUtils.isMultiSim(context) && !TextUtils.isEmpty(info.sim2IMSI)) {
                        Toast.makeText(context, C0415R.string.net_error_code12, 1).show();
                        return;
                    } else {
                        Toast.makeText(context, C0415R.string.net_simcard_error2, 1).show();
                        return;
                    }
                }
            } else if (TextUtils.isEmpty(info.sim2IMSI)) {
                Toast.makeText(context, C0415R.string.net_simcard_error2, 1).show();
                return;
            }
            if (type == 0) {
                if (!Utils.getCanCorrectFlag(context)) {
                    long jCurrentTimeMillis = System.currentTimeMillis() - Utils.getLastCorrectTime(context);
                    if (jCurrentTimeMillis < TrafficCorrectSetting.TIME) {
                        if (jCurrentTimeMillis <= 0) {
                            Utils.setLastCorrectTime(context);
                        }
                        z = false;
                    }
                    if (!z) {
                        Toast.makeText(context, C0415R.string.net_traffic_correct_notice, 1).show();
                        return;
                    }
                }
                canCorrect = false;
                Utils.setCanCorrectFlag(context, canCorrect);
                Utils.setCorrectPostion(context, card);
                f4740h.sendMessageDelayed(f4740h.obtainMessage(66), TrafficCorrectSetting.TIME);
                if (Utils.hasSetConfiged(card, context)) {
                    Toast.makeText(context, C0415R.string.net_traffic_correct_first_notice, 1).show();
                    Log.i(SecurityService.TAG, "touch toast short");
                    Utils.setLastCorrectTime(context);
                    Intent i = new Intent(context, (Class<?>) SecurityService.class);
                    i.putExtra(TrafficCorrectSetting.CORRECT, true);
                    context.startService(i);
                    return;
                }
                Intent mIntent = new Intent(context, (Class<?>) TrafficCorrectSetting.class);
                mIntent.putExtra("card", card);
                mIntent.putExtra("correct_type", type);
                context.startActivity(mIntent);
                return;
            }
            Intent mIntent2 = new Intent(context, (Class<?>) TrafficCorrectSetting.class);
            mIntent2.putExtra("card", card);
            mIntent2.putExtra("correct_type", type);
            context.startActivity(mIntent2);
        } catch (Exception e) {
        }
    }

    public static StringBuilder getSIMCarryInfo(int card, Context context) throws Exception {
        StringBuilder builder = new StringBuilder();
        if (card == 0) {
            SharedPreferences sp = context.getSharedPreferences(Utils.SIM1_PROPERTIES, 0);
            if (!sp.getBoolean(Utils.BOOLEAN_SET_LOCATION, false)) {
                builder.append(context.getString(C0415R.string.no_setting_text));
            } else {
                builder.append(sp.getString(Utils.PROVINCE_DESC, CookiePolicy.DEFAULT)).append(",").append(sp.getString(Utils.CITY_DESC, CookiePolicy.DEFAULT)).append(",").append(sp.getString(Utils.CARRY_DESC, CookiePolicy.DEFAULT)).append(",").append(sp.getString(Utils.BRAND_DESC, CookiePolicy.DEFAULT));
            }
        } else {
            SharedPreferences sp2 = context.getSharedPreferences(Utils.SIM2_PROPERTIES, 0);
            if (!sp2.getBoolean(Utils.BOOLEAN_SET_LOCATION, false)) {
                builder.append(context.getString(C0415R.string.no_setting_text));
            } else {
                builder.append(sp2.getString(Utils.PROVINCE_DESC, CookiePolicy.DEFAULT)).append(",").append(sp2.getString(Utils.CITY_DESC, CookiePolicy.DEFAULT)).append(",").append(sp2.getString(Utils.CARRY_DESC, CookiePolicy.DEFAULT)).append(",").append(sp2.getString(Utils.BRAND_DESC, CookiePolicy.DEFAULT));
            }
        }
        Log.i("plu", "builder = " + builder.toString());
        return builder;
    }

    public static int getTrafficMode(Context context) {
        if (!isSystemApp(context)) {
            return 13;
        }
        if (Const.SDK_VERSION < 14 || MyMultiSIMUtils.isMultiSim(context)) {
            return (Const.SDK_VERSION < 14 || !MyMultiSIMUtils.isMultiSim(context)) ? 13 : 12;
        }
        return 10;
    }

    public static boolean nacServerIsExist() {
        File file = new File("/system/bin/nac_server");
        return file.exists() && file.length() > 0;
    }

    public static void startTrafficCorrect(Context context, int card) {
        if (WflUtils.isNetworkAvailable(context)) {
            Intent i = new Intent();
            i.setAction(NetConstant.AUTO_CORRECT_ACTION);
            i.putExtra("card", card);
            context.sendBroadcast(i);
        }
    }

    public static int getDayCountInMonth() {
        int nowMonth = getCurrentMonth();
        if (nowMonth == 1 || nowMonth == 3 || nowMonth == 5 || nowMonth == 7 || nowMonth == 8 || nowMonth == 10 || nowMonth == 12) {
            return 32;
        }
        if (nowMonth == 2) {
            int nowYear = getCurrentYear();
            if ((nowYear % 4 == 0 && nowYear % 100 != 0) || nowYear % 400 == 0) {
                return 30;
            }
            return 29;
        }
        return 31;
    }

    public static void addNetWhiteList(Context context) {
        PackageManager mPackageManager = context.getPackageManager();
        try {
            ApplicationInfo info = mPackageManager.getApplicationInfo(PACKAGE_NAME, 0);
            Const.mNetWhiteApps.add(Integer.valueOf(info.uid));
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        try {
            ApplicationInfo info2 = mPackageManager.getApplicationInfo(NetConstant.TRAFFIC_PLUGIN, 0);
            Const.mNetWhiteApps.add(Integer.valueOf(info2.uid));
        } catch (PackageManager.NameNotFoundException e2) {
            e2.printStackTrace();
        }
        try {
            ApplicationInfo info3 = mPackageManager.getApplicationInfo("com.lenovo.lsf.device", 0);
            Const.mNetWhiteApps2.add(Integer.valueOf(info3.uid));
        } catch (PackageManager.NameNotFoundException e3) {
            e3.printStackTrace();
        }
        try {
            ApplicationInfo info4 = mPackageManager.getApplicationInfo("com.lenovo.ue.service", 0);
            Const.mNetWhiteApps2.add(Integer.valueOf(info4.uid));
        } catch (PackageManager.NameNotFoundException e4) {
            e4.printStackTrace();
        }
        try {
            ApplicationInfo info5 = mPackageManager.getApplicationInfo("com.android.SDAC", 0);
            Const.mNetWhiteApps2.add(Integer.valueOf(info5.uid));
        } catch (PackageManager.NameNotFoundException e5) {
            e5.printStackTrace();
        }
    }

    public static void startAutoCorrectTraffic(Context context, long intervalTime) {
        long triggerTime;
        AlarmManager alarmManager = (AlarmManager) context.getSystemService("alarm");
        Intent intent = new Intent();
        intent.setAction(CORRECT_ACTION_RTC_SIM);
        PendingIntent pendingIntent = PendingIntent.getService(context, 0, intent, 0);
        if (System.currentTimeMillis() > WflUtils.getTriggerTime(22, 0, 0)) {
            Log.i("8.31", "triggerTime<currentTime");
            triggerTime = WflUtils.getTriggerTime(22, 0, 0) + 86400000;
        } else {
            triggerTime = WflUtils.getTriggerTime(22, 0, 0);
        }
        alarmManager.setRepeating(1, triggerTime, intervalTime, pendingIntent);
        Log.i("8.31", "correct_ACTION_RTC");
    }

    public static void cancelAutoCorrectTraffic(Context context) {
        AlarmManager alarmManager = (AlarmManager) context.getSystemService("alarm");
        Intent intent = new Intent();
        intent.setAction(CORRECT_ACTION_RTC_SIM);
        PendingIntent pendingIntent = PendingIntent.getService(context, 0, intent, 0);
        alarmManager.cancel(pendingIntent);
        Log.i("4.2", "cancel correct_ACTION_RTC");
    }

    public static void startAutoCorrectTraffic2(Context context, long intervalTime) {
        long triggerTime;
        AlarmManager alarmManager = (AlarmManager) context.getSystemService("alarm");
        Intent intent = new Intent();
        intent.setAction(CORRECT_ACTION_RTC_SIM2);
        PendingIntent pendingIntent = PendingIntent.getService(context, 0, intent, 0);
        if (System.currentTimeMillis() > WflUtils.getTriggerTime(22, 30, 0)) {
            Log.i("8.20", "triggerTime<currentTime");
            triggerTime = WflUtils.getTriggerTime(22, 30, 0) + 86400000;
        } else {
            triggerTime = WflUtils.getTriggerTime(22, 30, 0);
        }
        alarmManager.setRepeating(1, triggerTime, intervalTime, pendingIntent);
        Log.i("4.2", "correct_ACTION_RTC");
    }

    public static void cancelAutoCorrectTraffic2(Context context) {
        AlarmManager alarmManager = (AlarmManager) context.getSystemService("alarm");
        Intent intent = new Intent();
        intent.setAction(CORRECT_ACTION_RTC_SIM2);
        PendingIntent pendingIntent = PendingIntent.getService(context, 0, intent, 0);
        alarmManager.cancel(pendingIntent);
        Log.i("4.2", "cancel correct_ACTION_RTC_SIM2");
    }

    public static void startAutoTrafficCorrectSim2(Context context) {
        switch (Const.getNetCorrectCycle2()) {
            case 0:
                startAutoCorrectTraffic2(context, 604800000L);
                break;
            case 1:
                startAutoCorrectTraffic2(context, 864000000L);
                break;
            case 2:
                cancelAutoCorrectTraffic2(context);
                break;
        }
    }

    public static void startAutoTrafficCorrectSim1(Context context) {
        switch (Const.getNetCorrectCycle()) {
            case 0:
                startAutoCorrectTraffic(context, 604800000L);
                break;
            case 1:
                startAutoCorrectTraffic(context, 864000000L);
                break;
            case 2:
                cancelAutoCorrectTraffic(context);
                break;
        }
    }

    public static boolean getMySIMState(Context context) {
        PhoneSimInfo info = getImsiInfo(context);
        switch (getTrafficMode(context)) {
            case 10:
                if (TextUtils.isEmpty(info.sim1IMSI)) {
                    return false;
                }
                return true;
            case 11:
            default:
                return true;
            case 12:
                if (TextUtils.isEmpty(info.sim1IMSI) && TextUtils.isEmpty(info.sim2IMSI)) {
                    return false;
                }
                return true;
            case 13:
                return true;
        }
    }

    public static void setMonthLimit(Context context) {
        SharedPreferences sp = getTrafficSP(context);
        sp.edit().putString("Month_Limit_Traffic", "-1").commit();
    }

    public static Object getNetWorkStatsService() {
        INetworkStatsService statsService = INetworkStatsService.Stub.asInterface(ServiceManager.getService("netstats"));
        if (Build.VERSION.SDK_INT < 16) {
            return statsService;
        }
        Object object = null;
        try {
            try {
                Method method = Class.forName("android.net.INetworkStatsService").getDeclaredMethod("openSession", null);
                try {
                    object = method.invoke(statsService, new Object[0]);
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                } catch (IllegalArgumentException e2) {
                    e2.printStackTrace();
                } catch (InvocationTargetException e3) {
                    e3.printStackTrace();
                }
                return object;
            } catch (NoSuchMethodException e4) {
                e4.printStackTrace();
                return object;
            }
        } catch (ClassNotFoundException e5) {
            e5.printStackTrace();
            return object;
        }
    }

    public static long invoke(String methodName, Object object, NetworkTemplate template, long startTimeMonth, long end) {
        Class<?> cls = object.getClass();
        NetworkStats stats = null;
        if ("getSummaryForAllUid".equals(methodName)) {
            try {
                Method method = cls.getDeclaredMethod("getSummaryForAllUid", NetworkTemplate.class, Long.TYPE, Long.TYPE, Boolean.TYPE);
                stats = (NetworkStats) method.invoke(object, template, Long.valueOf(startTimeMonth), Long.valueOf(end), false);
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            } catch (IllegalArgumentException e2) {
                e2.printStackTrace();
            } catch (NoSuchMethodException e3) {
                e3.printStackTrace();
            } catch (InvocationTargetException e4) {
                e4.printStackTrace();
            }
        }
        if ("getSummaryForNetwork".equals(methodName)) {
            try {
                Method method2 = cls.getDeclaredMethod("getSummaryForNetwork", NetworkTemplate.class, Long.TYPE, Long.TYPE);
                stats = (NetworkStats) method2.invoke(object, template, Long.valueOf(startTimeMonth), Long.valueOf(end));
            } catch (IllegalAccessException e5) {
                e5.printStackTrace();
            } catch (IllegalArgumentException e6) {
                e6.printStackTrace();
            } catch (NoSuchMethodException e7) {
                e7.printStackTrace();
            } catch (InvocationTargetException e8) {
                e8.printStackTrace();
            }
        }
        NetworkStats.Entry devTotal = stats.getTotal((NetworkStats.Entry) null);
        long totalNetwork = devTotal.rxBytes + devTotal.txBytes;
        return totalNetwork;
    }

    public static NetworkStats invokeForAllUid(String methodName, Object object, NetworkTemplate template, long start, long end) {
        Class<?> cls = object.getClass();
        if (!"getSummaryForAllUid".equals(methodName)) {
            return null;
        }
        try {
            Method method = cls.getDeclaredMethod("getSummaryForAllUid", NetworkTemplate.class, Long.TYPE, Long.TYPE, Boolean.TYPE);
            NetworkStats stats = (NetworkStats) method.invoke(object, template, Long.valueOf(start), Long.valueOf(end), false);
            return stats;
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return null;
        } catch (IllegalArgumentException e2) {
            e2.printStackTrace();
            return null;
        } catch (NoSuchMethodException e3) {
            e3.printStackTrace();
            return null;
        } catch (InvocationTargetException e4) {
            e4.printStackTrace();
            return null;
        }
    }

    public static void startIntentNetFilter(Context context) {
        Intent intent;
        int mode = getTrafficMode(context);
        if (mode == 12 || mode == 10) {
            intent = new Intent(context, (Class<?>) NetFilter.class);
        } else {
            intent = new Intent(context, (Class<?>) LowLevelNetFilter.class);
        }
        context.startActivity(intent);
    }

    public static void startIntentTraffic(Context context) {
        Intent intent;
        int mode = getTrafficMode(context);
        Log.i("9.17", "mode =" + mode);
        if (mode == 12) {
            intent = new Intent(context, (Class<?>) TrafficStatisticsDoubleMode.class);
        } else {
            intent = new Intent(context, (Class<?>) TrafficStatistics.class);
        }
        context.startActivity(intent);
    }

    public static void trafficForceUpdate(Context context) {
        if (Const.SDK_VERSION >= 14 && isSystemApp(context)) {
            INetworkStatsService statsService = INetworkStatsService.Stub.asInterface(ServiceManager.getService("netstats"));
            NetCache.is_net_flush_cast = true;
            try {
                statsService.forceUpdate();
                return;
            } catch (Exception e) {
                e.printStackTrace();
                return;
            }
        }
        TrafficStatsService service = getInstance(context);
        NetCache.is_net_flush_cast = true;
        service.refreshTotal();
        statsTrafficMobileInLimit(context);
    }

    public static void changeBinFileOwnerMode(final String fileName, final Context context) {
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.net.support.TrafficStatsService.4
            @Override // java.lang.Runnable
            public final void run() throws Throwable {
                FileOutputStream fos = null;
                try {
                    try {
                        String filePath = context.getFilesDir() + CookieSpec.PATH_DELIM + fileName;
                        File nbFile = new File(filePath);
                        if (!nbFile.exists()) {
                            InputStream open = context.getResources().getAssets().open(fileName);
                            byte[] buffer = new byte[open.available()];
                            open.read(buffer);
                            FileOutputStream fos2 = new FileOutputStream(nbFile);
                            try {
                                fos2.write(buffer);
                                fos = fos2;
                            } catch (Exception e) {
                                e = e;
                                fos = fos2;
                                e.printStackTrace();
                                Log.i("testroot", "touch exception ~~~");
                                Log.i("testroot", "exception =" + e.getMessage());
                                if (fos != null) {
                                    try {
                                        fos.close();
                                        return;
                                    } catch (IOException e2) {
                                        e2.printStackTrace();
                                        return;
                                    }
                                }
                                return;
                            } catch (Throwable th) {
                                th = th;
                                fos = fos2;
                                if (fos != null) {
                                    try {
                                        fos.close();
                                    } catch (IOException e3) {
                                        e3.printStackTrace();
                                    }
                                }
                                throw th;
                            }
                        }
                        StringBuffer sb = new StringBuffer();
                        sb.append("chown root.shell ").append(context.getFilesDir()).append(CookieSpec.PATH_DELIM).append(fileName).append("\n").append("chmod 755 ").append(context.getFilesDir()).append(CookieSpec.PATH_DELIM).append(fileName).append("\n");
                        CMDHelper.exeCmd(context, sb.toString());
                        Log.i("testroot", "touch way ~~~");
                        if (fos != null) {
                            try {
                                fos.close();
                            } catch (IOException e4) {
                                e4.printStackTrace();
                            }
                        }
                    } catch (Exception e5) {
                        e = e5;
                    }
                } catch (Throwable th2) {
                    th = th2;
                }
            }
        }).start();
    }

    public String[] queryTrafficCheck(String simSubscriberId) {
        SharedPreferences sp = this.f4745d.getSharedPreferences("net_check_traffic" + simSubscriberId, 0);
        boolean flag = sp.getBoolean("is_init_check_traffic", false);
        if (!flag) {
            Log.i("testtrafficbug", "touch db flag begin");
            SQLiteDatabase db = this.f4742a.getReadableDatabase();
            String[] date = new String[3];
            SQLiteDatabase sQLiteDatabaseM1964b = m1964b(db);
            String[] strArr = new String[1];
            if (simSubscriberId == null) {
                simSubscriberId = "";
            }
            strArr[0] = simSubscriberId;
            Cursor cursor = sQLiteDatabaseM1964b.rawQuery("select * from traffic_Check where sim_subscriber_id=?", strArr);
            if (cursor != null && !cursor.isClosed() && cursor.moveToFirst()) {
                Log.i("testtrafficbug", "_id=" + cursor.getString(cursor.getColumnIndex("_id")));
                Log.i("testtrafficbug", "checktime=" + cursor.getString(cursor.getColumnIndex("checktime")));
                Log.i("testtrafficbug", "inaccuracy=" + cursor.getString(cursor.getColumnIndex("inaccuracy")));
                date[0] = cursor.getString(cursor.getColumnIndex("_id"));
                date[1] = cursor.getString(cursor.getColumnIndex("checktime"));
                date[2] = cursor.getString(cursor.getColumnIndex("inaccuracy"));
            }
            if (!TextUtils.isEmpty(date[0])) {
                sp.edit().putString("checktime", date[1]).commit();
                sp.edit().putString("inaccuracy", date[2]).commit();
            }
            if (cursor != null && !cursor.isClosed()) {
                cursor.close();
            }
            if (db != null && db.isOpen()) {
                db.close();
            }
            sp.edit().putBoolean("is_init_check_traffic", true).commit();
            Log.i("testtrafficbug", "touch db flag end");
        }
        String[] date2 = new String[3];
        date2[0] = sp.getString("checktime", "");
        date2[1] = sp.getString("inaccuracy", "");
        Log.i("testtrafficbug", "queryTrafficCheck  date[0]= " + date2[0] + ",date[1] =" + date2[1]);
        return date2;
    }

    public void updateTrafficCheck(String simSubscriberId, String inaccuracy) {
        SharedPreferences sp = this.f4745d.getSharedPreferences("net_check_traffic" + simSubscriberId, 0);
        sp.edit().putString("checktime", String.valueOf(System.currentTimeMillis())).commit();
        sp.edit().putString("inaccuracy", inaccuracy).commit();
        Log.i("testtrafficbug", "updateTrafficCheck  inaccuracy= " + inaccuracy);
    }

    /* JADX INFO: renamed from: a */
    private SQLiteDatabase m1954a(SQLiteDatabase db) {
        if (db == null) {
            return this.f4742a.getWritableDatabase();
        }
        if (!db.isOpen()) {
            return this.f4742a.getWritableDatabase();
        }
        return db;
    }

    /* JADX INFO: renamed from: b */
    private SQLiteDatabase m1964b(SQLiteDatabase db) {
        if (db == null) {
            return this.f4742a.getReadableDatabase();
        }
        if (!db.isOpen()) {
            return this.f4742a.getReadableDatabase();
        }
        return db;
    }

    public static boolean isSystemApp(Context context) {
        try {
            ApplicationInfo info = context.getPackageManager().getApplicationInfo(PACKAGE_NAME, 0);
            if ((info.flags & 1) == 0) {
                return false;
            }
            return true;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }

    public static float getRawSize(Context c, int unit, float size) {
        Resources r;
        if (c == null) {
            r = Resources.getSystem();
        } else {
            r = c.getResources();
        }
        return TypedValue.applyDimension(unit, size, r.getDisplayMetrics());
    }

    public static float getRawSize(Context c, float size) {
        Resources r;
        try {
            if (c == null) {
                r = Resources.getSystem();
            } else {
                r = c.getResources();
            }
            return TypedValue.applyDimension(1, size, r.getDisplayMetrics());
        } catch (Exception e) {
            e.printStackTrace();
            return 0.0f;
        }
    }

    public static int dip2px(Context context, float dpValue) {
        float scale = context.getResources().getDisplayMetrics().density;
        return (int) ((dpValue * scale) + 0.5f);
    }

    /* JADX INFO: renamed from: c */
    private int m1967c() {
        int bar_height;
        if (this.f4743b.getInt("traffc_view_height", 0) == 0) {
            bar_height = (int) NetCache.getTraffic_view_height();
            Log.i("viewheight1", "NetCache.getTraffic_view_height() =" + bar_height);
        } else {
            bar_height = this.f4743b.getInt("traffc_view_height", 0);
        }
        Log.i("viewheight1", "final bar_height  =" + bar_height);
        return bar_height;
    }

    public static boolean checkCorrectTime(long now, long time) {
        Log.i("checktraffic", "now = " + now + ",time =" + time);
        if (now >= time) {
            return true;
        }
        return false;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: d */
    public void m1968d() {
        this.f4744c.putLong("last_save_daily_data_time", System.currentTimeMillis()).commit();
    }

    public static boolean getIsAutoDeny(Context context) {
        SharedPreferences sp = getTrafficSP(context);
        return sp.getBoolean("auto_deny_mode", true);
    }

    public static void setIsAutoDeny(Context context, boolean auto) {
        SharedPreferences sp = getTrafficSP(context);
        sp.edit().putBoolean("auto_deny_mode", auto).commit();
    }

    public static void initFridayAlarm(Context context) {
        Log.i("week", "touch initFridayAlarm");
        AlarmManager alarmManager = (AlarmManager) context.getSystemService("alarm");
        Intent intent = new Intent();
        intent.setAction(NOTICE_TRAFFIC_ACTION_RTC);
        PendingIntent pendingIntent = PendingIntent.getService(context, 0, intent, 0);
        alarmManager.setRepeating(1, getTriggerTime(18, 30, 0), 86400000L, pendingIntent);
    }

    public static long getTriggerTime(int hours, int minutes, int seconds) {
        Date date = new Date();
        date.setHours(hours);
        date.setMinutes(minutes);
        date.setSeconds(seconds);
        return date.getTime();
    }

    /* JADX INFO: renamed from: a */
    private static void m1956a(Context context, int notifyType, int cardPostion, int trafficMode, long todayLimit) {
        String tmp = "";
        if (trafficMode == 12) {
            tmp = cardPostion == 0 ? context.getString(C0415R.string.net_card1) : context.getString(C0415R.string.net_card2);
        }
        Log.i("traffic_noti", "tmp = " + tmp);
        switch (notifyType) {
            case 20:
                int id2 = cardPostion == 0 ? 9 : 24;
                DoubleCardUtil.showTariffOutLimitNotification(context, context.getString(C0415R.string.lesafe_tariff_warn_text), tmp + context.getString(C0415R.string.net_month_free_notification), id2);
                if (cardPostion == 0) {
                    Const.setIsNetAlarmedInMonth(true);
                } else {
                    Const.setIsNetAlarmedInMonth2(true);
                }
                break;
            case 21:
                int id3 = cardPostion == 0 ? 529 : 530;
                boolean flag = cardPostion == 0 ? Const.isNetLimitedInMonth() : Const.isNetLimitedInMonth2();
                ConnectivityManager mConnService = (ConnectivityManager) context.getSystemService("connectivity");
                boolean connFlag = mConnService.getMobileDataEnabled();
                StringBuilder content = new StringBuilder();
                content.append(tmp + context.getString(C0415R.string.curr_month_traffic_out_limit_warm_text));
                if (!flag) {
                    if (getIsAutoDeny(context) && connFlag && getDataCardPosition(context) == cardPostion) {
                        Intent intent = new Intent(context, (Class<?>) TrafficDailog.class);
                        intent.putExtra(NetConstant.SIM_CARD_POSTION, cardPostion);
                        intent.setFlags(268435456);
                        context.startActivity(intent);
                    } else {
                        DoubleCardUtil.showTariffOutLimitNotification(context, context.getString(C0415R.string.lesafe_tariff_warn_text), content.toString(), id3);
                    }
                    if (cardPostion == 0) {
                        Const.setNetLimitedInMonth(true);
                    } else {
                        Const.setNetLimitedInMonth2(true);
                    }
                }
                break;
            case 22:
                String s = tmp + context.getString(C0415R.string.curr_today_traffic_out_limit_warning);
                DoubleCardUtil.showTariffOutLimitNotification(context, context.getString(C0415R.string.lesafe_tariff_warn_text), String.format(s, Long.valueOf(todayLimit)), 22);
                if (cardPostion == 0) {
                    Const.setIsTodayNoticed(true);
                } else {
                    setIsTodayNoticed2(context, true);
                }
                break;
        }
    }

    public static boolean getIsTodayNoticed2(Context context) {
        SharedPreferences sp = getTrafficSP(context);
        return sp.getBoolean("today_noticed_sim2", false);
    }

    public static void setIsTodayNoticed2(Context context, boolean isNotice) {
        SharedPreferences sp = getTrafficSP(context);
        sp.edit().putBoolean("today_noticed_sim2", isNotice).commit();
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.net.support.TrafficStatsService$5] */
    public static void setPluginPhoneNumberData(String data, final Context context) {
        new Thread() { // from class: com.lenovo.safecenter.net.support.TrafficStatsService.5
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    SharedPreferences sp = context.getSharedPreferences("SIM1_properties", 0);
                    if (sp != null) {
                        sp.edit().putString("phoneNumber", NetConstant.ERROR).commit();
                        Log.i("TrafficCorrectCenter", "setPluginPhoneNumberData phoneNumber = " + sp.getString("phoneNumber", CookiePolicy.DEFAULT));
                    }
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            }
        }.start();
    }

    public static void setBackValue(int value) {
        f4741i = value;
    }

    public static int getBackValue() {
        return f4741i;
    }

    public static boolean getTrafficDaliogNoticeValue(Context context) {
        SharedPreferences sp = getTrafficSP(context);
        return sp.getBoolean("traffic_dailog_notice_value", false);
    }

    public static void setTrafficDaliogNoticeValue(Context context, boolean isNotice) {
        SharedPreferences sp = getTrafficSP(context);
        sp.edit().putBoolean("traffic_dailog_notice_value", isNotice).commit();
    }

    public static SharedPreferences getTrafficSP(Context context) {
        SharedPreferences sp = context.getSharedPreferences(Const.TRAFFIC_PREFERENCES_NAME, 0);
        return sp;
    }

    public static int getWeekOfDate() {
        Calendar calendar = Calendar.getInstance();
        Date date = new Date();
        calendar.setTime(date);
        int dayOfWeek = calendar.get(7);
        return dayOfWeek - 1;
    }

    public static void initNetCache(Context context) {
        PhoneSimInfo info = getImsiInfo(context);
        NetCache.imsi = info.sim1IMSI;
        NetCache.imsi2 = info.sim2IMSI;
        NetCache.isProvideMuti = MyMultiSIMUtils.isMultiSim(context);
        NetCache.data_id_postion = getDataCardPosition(context);
        NetCache.traffic_mode = getTrafficMode(context);
        NetCache.setTraffic_view_height(getRawSize(context, BAR_MAXHEIGHT));
        NetCache.setTraffic_view_width(getRawSize(context, TRAFFIC_CHILDVIEW_WIDTH));
        SharedPreferences sp = getTrafficSP(context);
        NetCache.setCached_imsi(sp.getString(NetConstant.IMSI_CATCHE_SIM, ""));
        NetCache.setCached_imsi2(sp.getString(NetConstant.IMSI_CATCHE_SIM2, ""));
    }

    public static String getDataString(long total) {
        DecimalFormat df = new DecimalFormat("###.0");
        if (total == -1) {
            return "0M";
        }
        if (total < 1024) {
            return total + "B";
        }
        if (total < 1048576) {
            return df.format(total / 1024.0f) + "KB";
        }
        if (total < 1073741824) {
            return df.format((total / 1024.0f) / 1024.0f) + "MB";
        }
        if (total < 0) {
            return df.format(((total / 1024.0f) / 1024.0f) / 1024.0f) + "GB";
        }
        return "";
    }

    public static boolean getMobileDataButtonValue(Context context) {
        SharedPreferences sp = getTrafficSP(context);
        return sp.getBoolean("mobile_data_all_button_value", true);
    }

    public static void setMobileDataButtonValue(Context context, boolean value) {
        SharedPreferences sp = getTrafficSP(context);
        sp.edit().putBoolean("mobile_data_all_button_value", value).commit();
    }

    public static boolean getWlanDataButtonValue(Context context) {
        SharedPreferences sp = getTrafficSP(context);
        return sp.getBoolean("wlan_data_all_button_value", true);
    }

    public static void setWlanDataButtonValue(Context context, boolean value) {
        SharedPreferences sp = getTrafficSP(context);
        sp.edit().putBoolean("wlan_data_all_button_value", value).commit();
    }

    public static void do4NewMonthBug(Context context) {
        if (Const.getProgressTrafficMonthUsed() < 100 && Const.isNetLimitedInMonth()) {
            Const.setNetLimitedInMonth(false);
        }
        if (Const.getProgressTrafficMonthUsed2() < 100 && Const.isNetLimitedInMonth2()) {
            Const.setNetLimitedInMonth2(false);
        }
    }

    public static boolean IsAirModeOn(Context context) {
        return Settings.System.getInt(context.getContentResolver(), "airplane_mode_on", 0) == 1;
    }

    public static void openPhoneFirstRun(final Context context) {
        final SharedPreferences sp = getTrafficSP(context);
        boolean firstBoot = sp.getBoolean("lesafe_net_first_run_flag", true);
        if (firstBoot && getTrafficMode(context) == 13) {
            getExecutorService().execute(new Thread() { // from class: com.lenovo.safecenter.net.support.TrafficStatsService.6
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    TrafficStatsService trafficStatsService = TrafficStatsService.getInstance(context);
                    trafficStatsService.refresh();
                    sp.edit().putBoolean("lesafe_net_first_run_flag", false).commit();
                }
            });
        }
    }

    public void insertToApp(long re, long sent, long last_re, long last_sent, int uid) {
        SQLiteDatabase db = this.f4742a.getWritableDatabase();
        db.execSQL("INSERT INTO apps (uid, _date, received, sent, last_received, last_sent) VALUES ( ? , ? , ? , ? , ? , ? )", new Object[]{Integer.valueOf(uid), Integer.valueOf(getDate()), Long.valueOf(re), Long.valueOf(sent), Long.valueOf(last_re), Long.valueOf(last_sent)});
    }
}
