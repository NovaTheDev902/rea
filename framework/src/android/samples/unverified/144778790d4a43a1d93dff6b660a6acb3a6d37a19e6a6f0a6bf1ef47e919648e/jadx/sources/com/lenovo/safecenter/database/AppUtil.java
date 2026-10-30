package com.lenovo.safecenter.database;

import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;
import android.text.TextUtils;
import android.util.Log;
import com.lenovo.install.PackageUtil;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.support.AppInfo;
import com.lenovo.safecenter.support.MD5Util;
import com.lenovo.safecenter.support.WhiteAppsList;
import com.lenovo.safecenter.utils.Const;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class AppUtil {
    public static int PERM_TOTAL = 15;

    /* JADX INFO: renamed from: a */
    private static int f3492a = 8;

    /* JADX INFO: renamed from: b */
    private static int f3493b = 3;

    /* JADX INFO: renamed from: c */
    private static int f3494c = 2;

    public static List<ApplicationInfo> getInstalledThirdApps(Context context) {
        PackageManager pm = context.getPackageManager();
        ArrayList<ApplicationInfo> third_apps = new ArrayList<>();
        List<ApplicationInfo> installedAppList = pm.getInstalledApplications(8192);
        if (installedAppList == null) {
            return Collections.emptyList();
        }
        for (ApplicationInfo applicationInfo : installedAppList) {
            boolean flag = isThirdpartApp(applicationInfo);
            if (flag && !Const.LENOVO_APKS.contains(applicationInfo.packageName + "\n")) {
                third_apps.add(applicationInfo);
            }
        }
        return third_apps;
    }

    public static boolean isThirdpartApp(ApplicationInfo appInfo) {
        if ((appInfo.flags & 128) == 0 && (appInfo.flags & 1) != 0) {
            return false;
        }
        return true;
    }

    /* JADX INFO: renamed from: a */
    private static int m1488a(int[] selected, int start, int len) {
        for (int i = start; i < start + len; i++) {
            if (selected[i] == 1) {
                return 1;
            }
        }
        return 0;
    }

    public static HashMap<String, String> getAppPermissionConfigurs(ContentResolver resolver, String pkgname) {
        HashMap<String, String> map = new HashMap<>();
        map.put(AppDatabase.PERM_TYPE_PRIVCY, "-1");
        map.put(AppDatabase.PERM_TYPE_DEVICE, "-1");
        map.put("location", "-1");
        map.put(AppDatabase.DB_APP_SENDMESSAGE, "-1");
        map.put(AppDatabase.DB_APP_CALL, "-1");
        Cursor cursor = null;
        try {
            Uri quri = Uri.parse("content://com.lenovo.providers.querypermissions/pkgname/" + pkgname);
            cursor = resolver.query(quri, null, null, null, null);
            if (cursor.moveToFirst()) {
                int[] selected = new int[PERM_TOTAL];
                for (int i = 0; i < selected.length; i++) {
                    String tmp = cursor.getString(i + 2);
                    if (TextUtils.isEmpty(tmp)) {
                        selected[i] = 0;
                    } else {
                        selected[i] = Integer.valueOf(tmp).intValue();
                    }
                }
                map.put(AppDatabase.PERM_TYPE_PRIVCY, Integer.toString(m1488a(selected, 0, f3492a)));
                map.put(AppDatabase.PERM_TYPE_DEVICE, Integer.toString(m1488a(selected, f3492a, f3494c)));
                map.put("location", Integer.toString(m1488a(selected, f3492a + f3494c, f3493b)));
                if (selected[PERM_TOTAL - 2] == -1) {
                    selected[PERM_TOTAL - 2] = 2;
                }
                map.put(AppDatabase.DB_APP_SENDMESSAGE, Integer.toString(selected[PERM_TOTAL - 2]));
                if (selected[PERM_TOTAL - 1] == -1) {
                    selected[PERM_TOTAL - 1] = 0;
                }
                map.put(AppDatabase.DB_APP_CALL, Integer.toString(selected[PERM_TOTAL - 1]));
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (cursor != null) {
                cursor.close();
            }
        }
        return map;
    }

    public static boolean checkPkgExit(ContentResolver resolver, String pkgname) {
        boolean exit = false;
        Cursor cursor = null;
        try {
            Uri uri = Uri.parse("content://com.lenovo.providers.querypermissions/pkgname/" + pkgname);
            cursor = resolver.query(uri, null, null, null, null);
            if (cursor.getCount() > 0) {
                exit = true;
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (cursor != null) {
                cursor.close();
            }
        }
        return exit;
    }

    public static int getAppPermissionConfigurs(ContentResolver resolver, String pkgname, String type) {
        int select;
        Cursor cursor = null;
        try {
            try {
                Uri quri = Uri.parse("content://com.lenovo.providers.querypermissions/pkgname/" + pkgname + "/type/" + type);
                cursor = resolver.query(quri, null, null, null, null);
                if (cursor.moveToFirst()) {
                    select = Integer.valueOf(cursor.getString(cursor.getColumnIndex(QueryPermissions.RECOMMENDEDACTION))).intValue();
                } else if (type.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                    select = 2;
                } else {
                    select = 1;
                }
            } catch (Exception e) {
                e.printStackTrace();
                if (type.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                    select = 2;
                } else {
                    select = 0;
                }
            }
            return select;
        } finally {
            if (cursor != null) {
                cursor.close();
            }
        }
    }

    public static ContentValues getContentValues(AppInfo app) {
        ContentValues value = new ContentValues();
        value.put("uid", Integer.valueOf(app.uid));
        value.put("name", app.name);
        value.put(AppDatabase.DB_SELECTED, Integer.valueOf(app.selected));
        value.put(AppDatabase.APP_PKG_NAME, app.packageName);
        value.put(AppDatabase.APP_PER_TYPE, app.appType);
        value.put("pername", app.perName);
        value.put(AppDatabase.DB_TRUSTED, Integer.valueOf(app.trusted));
        value.put(AppDatabase.DB_SUGGEST, Integer.valueOf(app.suggest));
        value.put("isupload", Integer.valueOf(app.isupload));
        return value;
    }

    public static void insertApp(SQLiteDatabase db, AppInfo app) {
        ContentValues value = new ContentValues();
        value.put("uid", Integer.valueOf(app.uid));
        value.put("name", app.name);
        value.put(AppDatabase.DB_SELECTED, Integer.valueOf(app.selected));
        value.put(AppDatabase.APP_PKG_NAME, app.packageName);
        value.put(AppDatabase.APP_PER_TYPE, app.appType);
        value.put("pername", app.perName);
        value.put(AppDatabase.DB_TRUSTED, Integer.valueOf(app.trusted));
        value.put(AppDatabase.DB_SUGGEST, Integer.valueOf(app.suggest));
        value.put("isupload", Integer.valueOf(app.isupload));
        db.insert(AppDatabase.DB_APP, "name", value);
    }

    public static boolean isNotExist(ArrayList<AppInfo> target, AppInfo appInfo) {
        boolean flag = true;
        for (AppInfo appInfo1 : target) {
            if (appInfo1.uid == appInfo.uid) {
                flag = false;
            }
        }
        return flag;
    }

    public static String getPerDescription(Context context, String perType) {
        if (perType.equals("android.permission.READ_SMS") || perType.equals("android.permission.RECEIVE_SMS")) {
            return context.getString(C0415R.string.perm_rsms);
        }
        if (perType.equals("android.permission.READ_CONTACTS")) {
            return context.getString(C0415R.string.perm_rcontacts);
        }
        if (perType.equals("android.permission.READ_CALENDAR")) {
            return context.getString(C0415R.string.perm_calendar);
        }
        if (perType.equals("android.permission.ACCESS_COARSE_LOCATION")) {
            return context.getString(C0415R.string.perm_c_location);
        }
        if (perType.equals("android.permission.ACCESS_FINE_LOCATION")) {
            return context.getString(C0415R.string.perm_c_location);
        }
        if (perType.equals("android.permission.ACCESS_LOCATION_EXTRA_COMMANDS")) {
            return context.getString(C0415R.string.perm_c_location);
        }
        if (perType.equals("com.android.browser.permission.READ_HISTORY_BOOKMARKS")) {
            return context.getString(C0415R.string.perm_history);
        }
        if (perType.equals("android.permission.RECORD_AUDIO")) {
            return context.getString(C0415R.string.perm_record);
        }
        if (perType.equals("android.permission.CAMERA")) {
            return context.getString(C0415R.string.perm_camera);
        }
        if (perType.equals("android.permission.SEND_SMS")) {
            return context.getString(C0415R.string.perm_send_sms);
        }
        if (perType.equals("android.permission.CALL_PHONE")) {
            return context.getString(C0415R.string.perm_call);
        }
        if (perType.equals("android.permission.CALL_PRIVILEGED")) {
            return context.getString(C0415R.string.perm_call);
        }
        if (perType.equals("android.permission.INTERNET")) {
            return context.getString(C0415R.string.perm_internet);
        }
        if (perType.equals("android.permission.WRITE_SMS")) {
            return context.getString(C0415R.string.perm_wsms);
        }
        if (perType.equals("android.permission.WRITE_CONTACTS")) {
            return context.getString(C0415R.string.perm_wcontact);
        }
        return null;
    }

    public static String getDescriptionByType(Context context, AppDatabase database, String pkgname, String perType) {
        if (perType.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
            return context.getString(C0415R.string.perm_privacy_info);
        }
        if (perType.equals("location")) {
            return context.getString(C0415R.string.perm_c_location);
        }
        if (perType.equals(AppDatabase.PERM_TYPE_DEVICE)) {
            return context.getString(C0415R.string.perm_tap_calling);
        }
        if (perType.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
            return context.getString(C0415R.string.perm_send_sms);
        }
        if (perType.equals(AppDatabase.DB_APP_CALL)) {
            return context.getString(C0415R.string.perm_call);
        }
        if (perType.equals(AppDatabase.DB_APP_INTERNET)) {
            return context.getString(C0415R.string.perm_internet);
        }
        return null;
    }

    public static String getDescriptionByPid(Context context, int pid) {
        switch (pid) {
            case 1:
                String des = context.getString(C0415R.string.perm_rsms);
                return des;
            case 2:
                String des2 = context.getString(C0415R.string.perm_rcalllogs);
                return des2;
            case 3:
                String des3 = context.getString(C0415R.string.perm_rcontact);
                return des3;
            case 4:
                String des4 = context.getString(C0415R.string.perm_calendar);
                return des4;
            case 5:
            case 48:
                String des5 = context.getString(C0415R.string.perm_c_location);
                return des5;
            case 6:
                String des6 = context.getString(C0415R.string.perm_record);
                return des6;
            case 7:
                String des7 = context.getString(C0415R.string.perm_camera);
                return des7;
            case 8:
                String des8 = context.getString(C0415R.string.perm_call);
                return des8;
            case 9:
                String des9 = context.getString(C0415R.string.perm_history);
                return des9;
            case 11:
                String des10 = context.getString(C0415R.string.perm_send_sms);
                return des10;
            case 44:
                String des11 = context.getString(C0415R.string.perm_wsms);
                return des11;
            case 45:
                String des12 = context.getString(C0415R.string.perm_wcontact);
                return des12;
            default:
                return "";
        }
    }

    public static int isSelected(ArrayList<AppInfo> list, int uid) {
        if (list.size() == 0) {
            return 0;
        }
        for (AppInfo appInfo : list) {
            if (appInfo.uid == uid) {
                return appInfo.selected;
            }
        }
        return 0;
    }

    public static void getAppsForBoot(Context ctx, PackageManager pm, SQLiteDatabase db, ApplicationInfo appinfo, String permName, String typeName, boolean contains, boolean version, int suggest) {
        int uid = appinfo.uid;
        String pkgname = appinfo.packageName;
        String name = pm.getApplicationLabel(appinfo).toString();
        if (pm.checkPermission(permName, pkgname) == 0) {
            Cursor cursor = db.rawQuery("select * from appname where uid=? and apptype=? and pername=?", new String[]{Integer.toString(uid), typeName, permName});
            if (cursor.getCount() == 0) {
                AppInfo app = new AppInfo();
                app.packageName = pkgname;
                app.uid = uid;
                app.name = name;
                app.appType = typeName;
                app.perName = permName;
                if (contains) {
                    app.trusted = 1;
                    app.selected = 0;
                } else {
                    app.trusted = 0;
                    if (!version) {
                        if (suggest < 0) {
                            if (typeName.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                                app.selected = 2;
                            } else if (app.appType.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
                                app.selected = 1;
                            } else {
                                app.selected = 0;
                            }
                        } else {
                            app.selected = suggest;
                        }
                    } else {
                        app.selected = 0;
                    }
                }
                insertApp(db, app);
            }
            cursor.close();
        }
    }

    public static void getAppsForBoot(PackageManager pm, SQLiteDatabase db, String perName, String appType, AppInfo app, int selected, int suggest) {
        if (pm.checkPermission(perName, app.packageName) == 0) {
            app.perName = perName;
            app.appType = appType;
            app.selected = selected;
            app.suggest = suggest;
            ContentValues values = getContentValues(app);
            if (db.update(AppDatabase.DB_APP, values, "packagename=? and pername=?", new String[]{app.packageName, app.perName}) <= 0) {
                db.insert(AppDatabase.DB_APP, "name", values);
            }
        }
    }

    public static void configurateAppsPermission(Context context, PackageManager pm, SQLiteDatabase db, ContentResolver resolver, List<String> whiteApps, ApplicationInfo appinfo, boolean version) {
        String pkgname = appinfo.packageName;
        boolean contains = whiteApps.contains(pkgname);
        HashMap<String, String> map = getAppPermissionConfigurs(resolver, pkgname);
        int priSelect = Integer.valueOf(map.get(AppDatabase.PERM_TYPE_PRIVCY)).intValue();
        getAppsForBoot(context, pm, db, appinfo, "android.permission.READ_SMS", AppDatabase.PERM_TYPE_PRIVCY, contains, version, priSelect);
        getAppsForBoot(context, pm, db, appinfo, "android.permission.WRITE_SMS", AppDatabase.PERM_TYPE_PRIVCY, contains, version, priSelect);
        getAppsForBoot(context, pm, db, appinfo, "android.permission.RECEIVE_SMS", AppDatabase.PERM_TYPE_PRIVCY, contains, version, priSelect);
        getAppsForBoot(context, pm, db, appinfo, "android.permission.READ_CONTACTS", AppDatabase.PERM_TYPE_PRIVCY, contains, version, priSelect);
        getAppsForBoot(context, pm, db, appinfo, "android.permission.WRITE_CONTACTS", AppDatabase.PERM_TYPE_PRIVCY, contains, version, priSelect);
        getAppsForBoot(context, pm, db, appinfo, "android.permission.READ_CALENDAR", AppDatabase.PERM_TYPE_PRIVCY, contains, version, priSelect);
        getAppsForBoot(context, pm, db, appinfo, "com.android.browser.permission.READ_HISTORY_BOOKMARKS", AppDatabase.PERM_TYPE_PRIVCY, contains, version, priSelect);
        int locSelect = Integer.valueOf(map.get("location")).intValue();
        getAppsForBoot(context, pm, db, appinfo, "android.permission.ACCESS_COARSE_LOCATION", "location", contains, version, locSelect);
        getAppsForBoot(context, pm, db, appinfo, "android.permission.ACCESS_FINE_LOCATION", "location", contains, version, locSelect);
        getAppsForBoot(context, pm, db, appinfo, "android.permission.ACCESS_LOCATION_EXTRA_COMMANDS", "location", contains, version, locSelect);
        int devSelect = Integer.valueOf(map.get(AppDatabase.PERM_TYPE_DEVICE)).intValue();
        getAppsForBoot(context, pm, db, appinfo, "android.permission.RECORD_AUDIO", AppDatabase.PERM_TYPE_DEVICE, contains, version, devSelect);
        getAppsForBoot(context, pm, db, appinfo, "android.permission.CAMERA", AppDatabase.PERM_TYPE_DEVICE, contains, version, devSelect);
        int smsSelect = Integer.valueOf(map.get(AppDatabase.DB_APP_SENDMESSAGE)).intValue();
        getAppsForBoot(context, pm, db, appinfo, "android.permission.SEND_SMS", AppDatabase.DB_APP_SENDMESSAGE, contains, version, smsSelect);
        int callSelect = Integer.valueOf(map.get(AppDatabase.DB_APP_CALL)).intValue();
        getAppsForBoot(context, pm, db, appinfo, "android.permission.CALL_PHONE", AppDatabase.DB_APP_CALL, contains, version, callSelect);
        getAppsForBoot(context, pm, db, appinfo, "android.permission.CALL_PRIVILEGED", AppDatabase.DB_APP_CALL, contains, version, callSelect);
    }

    public static int getTrust(Map<String, AppInfo> permMap) {
        if (permMap.get(AppDatabase.PERM_TYPE_PRIVCY) != null) {
            return permMap.get(AppDatabase.PERM_TYPE_PRIVCY).trusted;
        }
        if (permMap.get("location") != null) {
            return permMap.get("location").trusted;
        }
        if (permMap.get(AppDatabase.PERM_TYPE_DEVICE) != null) {
            return permMap.get(AppDatabase.PERM_TYPE_DEVICE).trusted;
        }
        if (permMap.get(AppDatabase.DB_APP_CALL) != null) {
            return permMap.get(AppDatabase.DB_APP_CALL).trusted;
        }
        if (permMap.get(AppDatabase.DB_APP_SENDMESSAGE) != null) {
            return permMap.get(AppDatabase.DB_APP_SENDMESSAGE).trusted;
        }
        return 0;
    }

    public static void configurateAppsPermission(Context context, PackageManager pm, SQLiteDatabase db, ContentResolver resolver, ApplicationInfo appinfo, Map<String, AppInfo> permMap) {
        String pkgname = appinfo.packageName;
        HashMap<String, String> map = getAppPermissionConfigurs(resolver, pkgname);
        AppInfo app = new AppInfo();
        app.uid = appinfo.uid;
        app.packageName = pkgname;
        app.name = pm.getApplicationLabel(appinfo).toString();
        app.trusted = getTrust(permMap);
        int priSelect = permMap.get(AppDatabase.PERM_TYPE_PRIVCY) == null ? 0 : permMap.get(AppDatabase.PERM_TYPE_PRIVCY).selected;
        int priSuggest = Integer.valueOf(map.get(AppDatabase.PERM_TYPE_PRIVCY)).intValue();
        Log.d("test", pkgname + ", priSelect:" + priSelect + ", priSuggest:" + priSuggest);
        getAppsForBoot(pm, db, "android.permission.READ_SMS", AppDatabase.PERM_TYPE_PRIVCY, app, priSelect, priSuggest);
        getAppsForBoot(pm, db, "android.permission.WRITE_SMS", AppDatabase.PERM_TYPE_PRIVCY, app, priSelect, priSuggest);
        getAppsForBoot(pm, db, "android.permission.RECEIVE_SMS", AppDatabase.PERM_TYPE_PRIVCY, app, priSelect, priSuggest);
        getAppsForBoot(pm, db, "android.permission.READ_CONTACTS", AppDatabase.PERM_TYPE_PRIVCY, app, priSelect, priSuggest);
        getAppsForBoot(pm, db, "android.permission.WRITE_CONTACTS", AppDatabase.PERM_TYPE_PRIVCY, app, priSelect, priSuggest);
        getAppsForBoot(pm, db, "android.permission.READ_CALENDAR", AppDatabase.PERM_TYPE_PRIVCY, app, priSelect, priSuggest);
        getAppsForBoot(pm, db, "com.android.browser.permission.READ_HISTORY_BOOKMARKS", AppDatabase.PERM_TYPE_PRIVCY, app, priSelect, priSuggest);
        int locSelect = permMap.get("location") == null ? 0 : permMap.get("location").selected;
        int locSuggest = Integer.valueOf(map.get("location")).intValue();
        Log.d("test", pkgname + ", locSelect:" + locSelect + ", locSuggest:" + locSuggest);
        getAppsForBoot(pm, db, "android.permission.ACCESS_COARSE_LOCATION", "location", app, locSelect, locSuggest);
        getAppsForBoot(pm, db, "android.permission.ACCESS_FINE_LOCATION", "location", app, locSelect, locSuggest);
        getAppsForBoot(pm, db, "android.permission.ACCESS_LOCATION_EXTRA_COMMANDS", "location", app, locSelect, locSuggest);
        int devSelect = permMap.get(AppDatabase.PERM_TYPE_DEVICE) == null ? 0 : permMap.get(AppDatabase.PERM_TYPE_DEVICE).selected;
        int devSuggest = Integer.valueOf(map.get(AppDatabase.PERM_TYPE_DEVICE)).intValue();
        Log.d("test", pkgname + ", devSelect:" + devSelect + ", devSuggest:" + devSuggest);
        getAppsForBoot(pm, db, "android.permission.RECORD_AUDIO", AppDatabase.PERM_TYPE_DEVICE, app, devSelect, devSuggest);
        getAppsForBoot(pm, db, "android.permission.CAMERA", AppDatabase.PERM_TYPE_DEVICE, app, devSelect, devSuggest);
        int smsSelect = permMap.get(AppDatabase.DB_APP_SENDMESSAGE) == null ? 0 : permMap.get(AppDatabase.DB_APP_SENDMESSAGE).selected;
        int smsSuggest = Integer.valueOf(map.get(AppDatabase.DB_APP_SENDMESSAGE)).intValue();
        Log.d("test", pkgname + ", smsSelect:" + smsSelect + ", smsSuggest:" + smsSuggest);
        getAppsForBoot(pm, db, "android.permission.SEND_SMS", AppDatabase.DB_APP_SENDMESSAGE, app, smsSelect, smsSuggest);
        int callSelect = permMap.get(AppDatabase.DB_APP_CALL) == null ? 0 : permMap.get(AppDatabase.DB_APP_CALL).selected;
        int callSuggest = Integer.valueOf(map.get(AppDatabase.DB_APP_CALL)).intValue();
        Log.d("test", pkgname + ", callSelect:" + callSelect + ", callSuggest:" + callSuggest);
        getAppsForBoot(pm, db, "android.permission.CALL_PHONE", AppDatabase.DB_APP_CALL, app, callSelect, callSuggest);
        getAppsForBoot(pm, db, "android.permission.CALL_PRIVILEGED", AppDatabase.DB_APP_CALL, app, callSelect, callSuggest);
    }

    public static void batchOperateDBForBoot(Context context, AppDatabase database, boolean versionCode) throws Throwable {
        PackageManager pm = context.getPackageManager();
        ContentResolver resolver = context.getContentResolver();
        List<String> whiteApps = WhiteAppsList.getThirdWhiteAppsList(context);
        List<ApplicationInfo> installed = getInstalledThirdApps(context);
        SQLiteDatabase db = database.getWritableDatabase();
        db.beginTransaction();
        try {
            for (ApplicationInfo appinfo : installed) {
                configurateAppsPermission(context, pm, db, resolver, whiteApps, appinfo, versionCode);
            }
            db.setTransactionSuccessful();
        } catch (IllegalStateException e) {
            e.printStackTrace();
        } finally {
            db.endTransaction();
            db.close();
        }
        Log.d("test", "batchOperateDBForBoot end...");
    }

    public static void batchOperateDB(AppDatabase database, Context context, PackageManager pm, ApplicationInfo appinfo) {
        ContentResolver resolver = context.getContentResolver();
        SQLiteDatabase db = database.getWritableDatabase();
        db.beginTransaction();
        try {
            String pkgname = appinfo.packageName;
            if (PackageUtil.newAppMap.get(pkgname) == null) {
                List<String> whiteApps = WhiteAppsList.getThirdWhiteAppsList(context);
                configurateAppsPermission(context, pm, db, resolver, whiteApps, appinfo, Const.getPreInstalledVersion());
            } else {
                configurateAppsPermission(context, pm, db, resolver, appinfo, PackageUtil.newAppMap.get(pkgname));
            }
            db.setTransactionSuccessful();
        } catch (IllegalStateException e) {
            e.printStackTrace();
        } finally {
            db.endTransaction();
            db.close();
        }
    }

    public static boolean isTariff(String permName) {
        HashSet<String> tariffPermissionNameList = new HashSet<>();
        tariffPermissionNameList.add("android.permission.CALL_PHONE");
        tariffPermissionNameList.add("android.permission.SEND_SMS");
        tariffPermissionNameList.add("android.permission.CALL_PRIVILEGED");
        return tariffPermissionNameList.contains(permName);
    }

    public static boolean isTariffType(String permType) {
        HashSet<String> tariffPermissionNameList = new HashSet<>();
        tariffPermissionNameList.add(AppDatabase.DB_APP_INTERNET);
        tariffPermissionNameList.add(AppDatabase.DB_APP_SENDMESSAGE);
        tariffPermissionNameList.add(AppDatabase.DB_APP_CALL);
        return tariffPermissionNameList.contains(permType);
    }

    public static String getCretMD5(Context Context, String packName) {
        String md5 = null;
        try {
            Signature[] sigs = Context.getPackageManager().getPackageInfo(packName, 64).signatures;
            for (int i = 0; i < sigs.length; i++) {
                String str1 = sigs[i].toCharsString();
                md5 = MD5Util.getMD5String(sigs[i].toByteArray()).toUpperCase();
                Log.i("info", "str1==" + str1 + ">>>>>>>>str===" + md5);
            }
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return md5;
    }

    public static boolean isNacExist(Context context) {
        ApplicationInfo info = null;
        PackageManager manager = context.getPackageManager();
        try {
            info = manager.getApplicationInfo("com.lenovo.leos.nac", 0);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return info != null;
    }

    public static boolean isAntiVirusExist(Context context) {
        ApplicationInfo info = null;
        PackageManager manager = context.getPackageManager();
        try {
            info = manager.getApplicationInfo("com.lenovo.antivirus", 0);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return info != null;
    }

    public static boolean isHarassExist(Context context) {
        ApplicationInfo info = null;
        PackageManager manager = context.getPackageManager();
        try {
            info = manager.getApplicationInfo("com.lenovo.safecenter.lenovoAntiSpam", 0);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return info != null;
    }

    public static boolean isAppExistence(Context context, String pkgName) {
        PackageInfo packageInfo;
        try {
            packageInfo = context.getPackageManager().getPackageInfo(pkgName, 0);
        } catch (PackageManager.NameNotFoundException e) {
            packageInfo = null;
            e.printStackTrace();
        }
        return packageInfo != null;
    }

    public static int getAppVersionCode(Context context, String pkgName) {
        try {
            return context.getPackageManager().getPackageInfo(pkgName, 0).versionCode;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return -1;
        }
    }
}
