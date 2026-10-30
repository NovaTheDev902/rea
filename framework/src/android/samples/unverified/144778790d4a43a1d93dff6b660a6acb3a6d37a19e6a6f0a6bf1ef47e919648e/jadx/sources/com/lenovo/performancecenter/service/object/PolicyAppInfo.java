package com.lenovo.performancecenter.service.object;

import android.content.ContentValues;
import android.content.Context;
import android.content.pm.PackageManager;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.drawable.Drawable;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.performancecenter.framework.PerformanceDatabaseHelper;
import java.io.Serializable;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class PolicyAppInfo implements Serializable {
    public static final String ANR_TYPE = "ANR";
    public static final String APP_TYPE_SYSTEM = "system";
    public static final String APP_TYPE_USER = "user";
    public static final String CRASHED_TYPE = "CRASHED";
    public static final String DescribeFromWeiYunXing = "performance.UsedAppInfo.weiyunxing";
    public static final String DescribeFromYiChang = "performance.UsedAppInfo.yichang";
    public static final String DescribeFromZhengYunXing = "performance.UsedAppInfo.zhengzaiyunxing";

    /* JADX INFO: renamed from: a */
    private String f1943a;

    /* JADX INFO: renamed from: b */
    private boolean f1944b;

    /* JADX INFO: renamed from: c */
    private boolean f1945c;

    /* JADX INFO: renamed from: d */
    private boolean f1946d;

    /* JADX INFO: renamed from: e */
    private long f1947e;

    /* JADX INFO: renamed from: f */
    private long f1948f;
    public int flag;

    /* JADX INFO: renamed from: g */
    private long f1949g;

    /* JADX INFO: renamed from: h */
    private long f1950h;

    /* JADX INFO: renamed from: i */
    private long f1951i;
    public Drawable icon;

    /* JADX INFO: renamed from: j */
    private String f1952j;

    /* JADX INFO: renamed from: k */
    private String f1953k;

    /* JADX INFO: renamed from: l */
    private String f1954l;
    public String label;
    protected long lastErrorTime;

    /* JADX INFO: renamed from: m */
    private ArrayList<Float> f1955m;

    /* JADX INFO: renamed from: n */
    private Context f1956n;

    /* JADX INFO: renamed from: o */
    private PackageManager f1957o;
    public String packageName;
    public int pid;
    public String processName;
    public int uid;

    public PolicyAppInfo(int uid, String processName, Context context) {
        this.f1950h = -1L;
        this.f1951i = -1L;
        this.lastErrorTime = -1L;
        this.f1955m = new ArrayList<>();
        this.uid = uid;
        this.processName = processName;
        this.f1957o = context.getPackageManager();
        this.f1956n = context;
    }

    public PolicyAppInfo(String processName, String errorCondition) {
        this.f1950h = -1L;
        this.f1951i = -1L;
        this.lastErrorTime = -1L;
        this.f1955m = new ArrayList<>();
        this.processName = processName;
        this.f1953k = errorCondition;
        this.lastErrorTime = System.currentTimeMillis();
    }

    public Long getTotleImpLevel() {
        long levelResult = (long) Math.floor(this.f1949g / this.f1947e);
        return levelResult < 100 ? Long.valueOf(this.f1948f) : Long.valueOf(levelResult);
    }

    public void updateUAIRunningTimeToDatebase() {
        PerformanceDatabaseHelper dbh = new PerformanceDatabaseHelper(this.f1956n.getApplicationContext());
        SQLiteDatabase db = dbh.getWritableDatabase();
        ContentValues evs = new ContentValues();
        evs.put(DatabaseTables.LAST_RUNNING_TIME, Long.valueOf(getRunningTime()));
        evs.put(DatabaseTables.LAST_FOREGROUND, Long.valueOf(getForegoing()));
        try {
            db.update(DatabaseTables.UsedAppInfo_TABLE_NAME, evs, "Package_Name= '" + this.packageName + "'", null);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            db.close();
            dbh.close();
        }
    }

    public Long generateAppTotleImpLevel() {
        long levelResult = (long) Math.floor(this.f1949g / this.f1947e);
        if (levelResult < 100) {
            return Long.valueOf(this.f1948f);
        }
        this.f1949g = levelResult;
        this.f1948f = levelResult;
        this.f1947e = 1L;
        return Long.valueOf(levelResult);
    }

    public int hashCode() {
        return this.packageName.hashCode();
    }

    public boolean equals(Object o) {
        return this.packageName.equals(((PolicyAppInfo) o).packageName);
    }

    public int compareTo(PolicyAppInfo obj) {
        if (!DataLayerManager.isInSysWhiteList(this.processName, this.f1956n) && !DataLayerManager.isInSysWhiteList(obj.processName, this.f1956n)) {
            return -1;
        }
        if (this.f1946d && !obj.f1946d) {
            return -1;
        }
        if ((this.f1946d || !obj.f1946d) && this.f1949g <= obj.f1949g) {
            return this.f1949g >= obj.f1949g ? 0 : -1;
        }
        return 1;
    }

    public boolean isHasStore() {
        return this.f1944b;
    }

    public void setHasStore(boolean hasStore) {
        this.f1944b = hasStore;
    }

    public long getImportance() {
        return this.f1948f;
    }

    public void setImportance(long importance) {
        if (importance > 100) {
            this.f1948f = importance;
            this.f1949g += importance;
        } else if (importance == 100) {
            this.f1948f = importance;
            this.f1949g = this.f1947e * importance;
        }
    }

    public long getNum() {
        return this.f1947e;
    }

    public void addNum() {
        this.f1947e++;
    }

    public long getForegoing() {
        return this.f1950h;
    }

    public void setForegoing(long foregoing) {
        this.f1950h = foregoing;
    }

    public long getRunningTime() {
        return this.f1951i;
    }

    public void setRunningTime(long runningTime) {
        this.f1951i = runningTime;
    }

    public ArrayList<Float> getCpuInfoTenTime() {
        return this.f1955m;
    }

    public void setCpuInfoTenTime(ArrayList<Float> cpuInfoTenTime) {
        this.f1955m = cpuInfoTenTime;
    }

    public boolean isCanUninstall() {
        return this.f1946d;
    }

    public void setCanUninstall(boolean canUninstall) {
        this.f1946d = canUninstall;
    }

    public boolean isTodayUsed() {
        return this.f1945c;
    }

    public void setTodayUsed(boolean todayUsed) {
        this.f1945c = todayUsed;
    }

    public String getAppDir() {
        return this.f1943a;
    }

    public void setAppDir(String appDir) {
        this.f1943a = appDir;
    }

    public long getLastErrorTime() {
        return this.lastErrorTime;
    }

    public void setLastErrorTime(long lastErrorTime) {
        this.lastErrorTime = lastErrorTime;
    }

    public String getLastCondition() {
        return this.f1953k;
    }

    public void setLastCondition(String lastCondition) {
        this.f1953k = lastCondition;
    }

    public String getLastStackTrace() {
        return this.f1954l;
    }

    public void setLastStackTrace(String lastStackTrace) {
        this.f1954l = lastStackTrace;
    }

    public String getLastLongMsg() {
        return this.f1952j;
    }

    public void setLastLongMsg(String lastLongMsg) {
        this.f1952j = lastLongMsg;
    }
}
