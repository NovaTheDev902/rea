package com.lenovo.performancecenter.performance;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.drawable.Drawable;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.performancecenter.framework.PerformanceDatabaseHelper;
import com.lenovo.safecenter.net.cache.NetConstant;
import com.lenovo.safecenter.utils.Const;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class DataLayerManagerAccelerate {
    public static int getBootCountForHealth(Context context) {
        DataLayerManageBoot dataLayer = new DataLayerManageBoot();
        dataLayer.getBootMap(context);
        return dataLayer.getNeedChangeToForbidJustCount();
    }

    public static void setBootOneKeyConfigForHealth(Context context) {
        DataLayerManageBoot dataLayer = new DataLayerManageBoot();
        HashMap<String[], int[]> bootMap = dataLayer.getBootMap(context);
        RootPassage.setComponentAbleBoot(context, bootMap);
        dataLayer.updatePkgsInBootDB(context, bootMap);
    }

    public static boolean isAppCanBoot(Context context, String pkgName) {
        boolean canBoot;
        PerformanceDatabaseHelper dbHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase readDB = dbHelper.getReadableDatabase();
        Cursor cursor = readDB.rawQuery("SELECT * FROM BootCom WHERE pkgName=?", new String[]{pkgName});
        if (cursor != null && cursor.moveToFirst()) {
            int state = cursor.getInt(cursor.getColumnIndex(DatabaseTables.BOOTCOMPLETED_ITEM_CUSTOMER_STATE));
            canBoot = state == 1;
            cursor.close();
        } else {
            canBoot = true;
        }
        readDB.close();
        dbHelper.close();
        return canBoot;
    }

    public static void setAppBoot(Context context, String[] componentName, boolean canBoot) {
        if (componentName != null && componentName[0] != null && componentName[1] != null) {
            int wantState = canBoot ? 1 : 2;
            DataLayerManageBoot dataLayer = new DataLayerManageBoot();
            dataLayer.updateSinglePkgDB(context, componentName[0], wantState);
            RootPassage.setComponentAbleBoot(context, componentName, wantState);
        }
    }

    public static boolean isManageTheBoot(Context context, String pkgName) {
        PackageManager pm = context.getPackageManager();
        try {
            ApplicationInfo ai = pm.getApplicationInfo(pkgName, 0);
            if ((ai.flags & 1) != 0 || context.getApplicationContext().getPackageName().equals(pkgName) || Const.PACKAGENAME_APP_LOCK.equals(pkgName) || NetConstant.TRAFFIC_PLUGIN.equals(pkgName)) {
                return false;
            }
            return true;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.DataLayerManagerAccelerate$a */
    static class C0173a implements Comparable<C0173a> {

        /* JADX INFO: renamed from: a */
        Drawable f1713a;

        /* JADX INFO: renamed from: b */
        CharSequence f1714b;

        /* JADX INFO: renamed from: c */
        String f1715c;

        /* JADX INFO: renamed from: d */
        String f1716d;

        /* JADX INFO: renamed from: e */
        String f1717e;

        /* JADX INFO: renamed from: f */
        int f1718f;

        /* JADX INFO: renamed from: g */
        int f1719g;

        @Override // java.lang.Comparable
        public final /* synthetic */ int compareTo(C0173a c0173a) {
            C0173a c0173a2 = c0173a;
            int i = this.f1718f - c0173a2.f1718f;
            return i != 0 ? i : this.f1714b.toString().compareTo(c0173a2.f1714b.toString());
        }

        public C0173a(Drawable appIcon, CharSequence appName, String pkgName, String proName, String clsName, int state, int expertSuggest) {
            this.f1713a = appIcon;
            this.f1714b = appName;
            this.f1715c = pkgName;
            this.f1716d = proName;
            this.f1717e = clsName;
            this.f1718f = state;
            this.f1719g = expertSuggest;
        }

        public final String toString() {
            return "appName:" + ((Object) this.f1714b) + " pkgName:" + this.f1715c + " proName:" + this.f1716d + " clsName:" + this.f1717e + " state:" + this.f1718f + " expertSuggest:" + this.f1719g;
        }

        public final int hashCode() {
            int result = this.f1718f + 629;
            return (result * 37) + this.f1714b.hashCode();
        }

        public final boolean equals(Object o) {
            if (!(o instanceof C0173a)) {
                return false;
            }
            C0173a app = (C0173a) o;
            return this.f1718f == app.f1718f && this.f1714b.equals(app.f1714b);
        }
    }
}
