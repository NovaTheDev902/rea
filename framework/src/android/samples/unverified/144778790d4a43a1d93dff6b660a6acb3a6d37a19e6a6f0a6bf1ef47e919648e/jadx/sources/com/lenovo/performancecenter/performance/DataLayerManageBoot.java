package com.lenovo.performancecenter.performance;

import android.content.ComponentName;
import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.drawable.Drawable;
import android.util.Log;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.performancecenter.framework.PerformanceDatabaseHelper;
import com.lenovo.safecenter.net.cache.NetConstant;
import com.lenovo.safecenter.utils.Const;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class DataLayerManageBoot {

    /* JADX INFO: renamed from: a */
    private int f1709a = 0;

    /* JADX INFO: renamed from: b */
    private int f1710b = 0;

    /* JADX INFO: renamed from: c */
    private int f1711c = 0;

    /* JADX INFO: renamed from: d */
    private int f1712d;

    public int getBootAllowCount() {
        return this.f1709a;
    }

    public ArrayList<DataLayerManagerAccelerate.C0173a> getBootItem(Context context) {
        m633a(context);
        this.f1709a = 0;
        ArrayList<DataLayerManagerAccelerate.C0173a> listSuggestAllow = new ArrayList<>();
        ArrayList<DataLayerManagerAccelerate.C0173a> listSuggestForbid = new ArrayList<>();
        ArrayList<DataLayerManagerAccelerate.C0173a> listNoSuggest = new ArrayList<>();
        PackageManager pm = context.getPackageManager();
        PerformanceDatabaseHelper dbHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase readDB = dbHelper.getReadableDatabase();
        Cursor cursor = readDB.rawQuery("SELECT * FROM BootCom", null);
        if (cursor != null) {
            if (cursor.getCount() > 0) {
                cursor.moveToFirst();
                while (!cursor.isAfterLast()) {
                    String packageName = cursor.getString(cursor.getColumnIndex("pkgName"));
                    String clsName = cursor.getString(cursor.getColumnIndex(DatabaseTables.BOOTCOMPLETED_ITEM_CLSNAME));
                    int state = cursor.getInt(cursor.getColumnIndex(DatabaseTables.BOOTCOMPLETED_ITEM_CUSTOMER_STATE));
                    try {
                        ApplicationInfo appInfo = pm.getApplicationInfo(packageName, 0);
                        Drawable icon = appInfo.loadIcon(pm);
                        String appName = ((Object) appInfo.loadLabel(pm)) + "";
                        int expertSuggest = DataLayerManager.getExpertSuggest(context, packageName);
                        DataLayerManagerAccelerate.C0173a item = new DataLayerManagerAccelerate.C0173a(icon, appName, packageName, null, clsName, state, expertSuggest);
                        if (state != 2) {
                            this.f1709a++;
                        }
                        if (expertSuggest == 1) {
                            listSuggestAllow.add(item);
                        } else if (expertSuggest == 2) {
                            listSuggestForbid.add(item);
                        } else {
                            listNoSuggest.add(item);
                        }
                    } catch (PackageManager.NameNotFoundException e) {
                        e.printStackTrace();
                    }
                    cursor.moveToNext();
                }
            }
            cursor.close();
        }
        readDB.close();
        dbHelper.close();
        listSuggestAllow.trimToSize();
        listSuggestForbid.trimToSize();
        listNoSuggest.trimToSize();
        ArrayList<DataLayerManagerAccelerate.C0173a> list = new ArrayList<>();
        list.addAll(listSuggestForbid);
        list.addAll(listSuggestAllow);
        list.addAll(listNoSuggest);
        return list;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m633a(Context context) {
        ArrayList<String> fromDatabases = new ArrayList<>();
        PerformanceDatabaseHelper performanceDatabaseHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase readableDatabase = performanceDatabaseHelper.getReadableDatabase();
        Cursor cursorRawQuery = readableDatabase.rawQuery("SELECT pkgName FROM BootCom", null);
        if (cursorRawQuery != null) {
            if (cursorRawQuery.getCount() > 0) {
                cursorRawQuery.moveToFirst();
                while (!cursorRawQuery.isAfterLast()) {
                    fromDatabases.add(cursorRawQuery.getString(cursorRawQuery.getColumnIndex("pkgName")));
                    cursorRawQuery.moveToNext();
                }
            }
            cursorRawQuery.close();
        }
        readableDatabase.close();
        performanceDatabaseHelper.close();
        ArrayList<String> fromReal = m634b(context);
        ArrayList<String> deleteItem = m632a(fromDatabases, fromReal);
        ArrayList<String> insertItem = m632a(fromReal, fromDatabases);
        Log.i("DataLayerManageBoot", System.currentTimeMillis() + "  deleteItem == " + deleteItem.size() + " insertItem == " + insertItem.size());
        if (deleteItem.isEmpty() && insertItem.isEmpty()) {
            return true;
        }
        PerformanceDatabaseHelper dbHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase writeDB = dbHelper.getWritableDatabase();
        if (!deleteItem.isEmpty()) {
            for (int i = 0; i < deleteItem.size(); i++) {
                String packageName = deleteItem.get(i);
                writeDB.delete(DatabaseTables.BOOTCOMPLETED_TABLE_NAME, "pkgName=?", new String[]{packageName});
            }
        }
        if (!insertItem.isEmpty()) {
            HashMap<String, DataLayerManagerAccelerate.C0173a> maps = m635c(context);
            for (int i2 = 0; i2 < insertItem.size(); i2++) {
                String packageName2 = insertItem.get(i2);
                DataLayerManagerAccelerate.C0173a item = maps.get(packageName2);
                ContentValues values = new ContentValues();
                values.put("appName", item.f1714b.toString());
                values.put(DatabaseTables.BOOTCOMPLETED_ITEM_CLSNAME, item.f1717e);
                values.put("pkgName", item.f1715c);
                values.put(DatabaseTables.BOOTCOMPLETED_ITEM_PRONAME, item.f1716d);
                values.put("state", Integer.valueOf(item.f1718f));
                values.put(DatabaseTables.BOOTCOMPLETED_ITEM_CUSTOMER_STATE, Integer.valueOf(item.f1718f));
                writeDB.insert(DatabaseTables.BOOTCOMPLETED_TABLE_NAME, null, values);
            }
        }
        writeDB.close();
        dbHelper.close();
        return true;
    }

    /* JADX INFO: renamed from: b */
    private static ArrayList<String> m634b(Context context) {
        ArrayList<String> list = new ArrayList<>();
        PackageManager packageManager = context.getPackageManager();
        Intent intent = new Intent("android.intent.action.BOOT_COMPLETED");
        List<ResolveInfo> resolves = packageManager.queryBroadcastReceivers(intent, 600);
        for (ResolveInfo resolve : resolves) {
            ApplicationInfo app = resolve.activityInfo.applicationInfo;
            if ((app.flags & 1) == 0 && !context.getApplicationContext().getPackageName().equals(app.packageName) && !Const.PACKAGENAME_APP_LOCK.equals(app.packageName) && !NetConstant.TRAFFIC_PLUGIN.equals(app.packageName) && !list.contains(app.packageName)) {
                list.add(app.packageName);
            }
        }
        return list;
    }

    /* JADX INFO: renamed from: c */
    private static HashMap<String, DataLayerManagerAccelerate.C0173a> m635c(Context context) {
        int state;
        HashMap<String, DataLayerManagerAccelerate.C0173a> maps = new HashMap<>();
        PackageManager packageManager = context.getPackageManager();
        Intent intent = new Intent("android.intent.action.BOOT_COMPLETED");
        List<ResolveInfo> resolves = packageManager.queryBroadcastReceivers(intent, 600);
        for (ResolveInfo resolve : resolves) {
            ApplicationInfo app = resolve.activityInfo.applicationInfo;
            if ((app.flags & 1) == 0 && !context.getApplicationContext().getPackageName().equals(app.packageName) && !Const.PACKAGENAME_APP_LOCK.equals(app.packageName) && !NetConstant.TRAFFIC_PLUGIN.equals(app.packageName)) {
                int state2 = packageManager.getComponentEnabledSetting(new ComponentName(app.packageName, resolve.activityInfo.name));
                if (state2 == 0 || state2 == 1) {
                    state = 1;
                } else {
                    state = 2;
                }
                DataLayerManagerAccelerate.C0173a item = new DataLayerManagerAccelerate.C0173a(null, app.loadLabel(packageManager), app.packageName, app.processName, resolve.activityInfo.name, state, 0);
                if (!maps.containsKey(item.f1715c)) {
                    maps.put(item.f1715c, item);
                }
            }
        }
        return maps;
    }

    public ArrayList<DataLayerManagerAccelerate.C0173a> getBootAppInfoFromRealAllCls(Context context) {
        ArrayList<DataLayerManagerAccelerate.C0173a> list = new ArrayList<>();
        PackageManager packageManager = context.getPackageManager();
        Intent intent = new Intent("android.intent.action.BOOT_COMPLETED");
        List<ResolveInfo> resolves = packageManager.queryBroadcastReceivers(intent, 600);
        for (ResolveInfo resolve : resolves) {
            ApplicationInfo app = resolve.activityInfo.applicationInfo;
            if ((app.flags & 1) == 0 && !context.getApplicationContext().getPackageName().equals(app.packageName) && !Const.PACKAGENAME_APP_LOCK.equals(app.packageName) && !NetConstant.TRAFFIC_PLUGIN.equals(app.packageName)) {
                int state = packageManager.getComponentEnabledSetting(new ComponentName(app.packageName, resolve.activityInfo.name));
                DataLayerManagerAccelerate.C0173a item = new DataLayerManagerAccelerate.C0173a(null, null, app.packageName, null, resolve.activityInfo.name, state, 0);
                list.add(item);
            }
        }
        return list;
    }

    /* JADX INFO: renamed from: a */
    private static ArrayList<String> m632a(ArrayList<String> listA, ArrayList<String> listB) {
        if (!listB.isEmpty()) {
            ArrayList<String> listC = new ArrayList<>();
            listC.addAll(listA);
            for (int i = 0; i < listB.size(); i++) {
                String elementB = listB.get(i);
                if (listC.contains(elementB)) {
                    listC.remove(elementB);
                }
            }
            return listC;
        }
        return listA;
    }

    public int getNeedChangeToForbid() {
        Log.i("DataLayerManageBoot", "getNeedChangeToForbid == " + this.f1710b);
        return this.f1710b;
    }

    public int getNeedChangeToAllow() {
        Log.i("DataLayerManageBoot", "getNeedChangeToAllow == " + this.f1711c);
        return this.f1711c;
    }

    public HashMap<String[], int[]> getBootMap(Context context, ArrayList<DataLayerManagerAccelerate.C0173a> list) {
        this.f1710b = 0;
        this.f1711c = 0;
        HashMap<String[], int[]> bootMap = new HashMap<>();
        for (DataLayerManagerAccelerate.C0173a item : list) {
            String[] nameArr = {item.f1715c, item.f1717e};
            int[] stateArr = {-1, item.f1718f, item.f1719g, 0};
            if (stateArr[1] != 2 && stateArr[2] != 1) {
                this.f1710b++;
                stateArr[0] = 2;
            }
            if (stateArr[1] == 2 && stateArr[2] == 1) {
                this.f1711c++;
                stateArr[0] = 1;
            }
            bootMap.put(nameArr, stateArr);
            Log.i("DataLayerManageBoot", "getBootMap --- > packageName == " + nameArr[0] + " needChangeToState == " + stateArr[0]);
        }
        return bootMap;
    }

    public int updateSinglePkgDB(Context context, String packageName, int state) {
        PerformanceDatabaseHelper dbHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase writeDB = dbHelper.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(DatabaseTables.BOOTCOMPLETED_ITEM_CUSTOMER_STATE, Integer.valueOf(state));
        int updateCount = writeDB.update(DatabaseTables.BOOTCOMPLETED_TABLE_NAME, values, "pkgName=?", new String[]{packageName});
        writeDB.close();
        dbHelper.close();
        Log.i("DataLayerManageBoot", "updateSinglePkgDB --- > packageName == " + packageName + " newState == " + state);
        Log.i("DataLayerManageBoot", "updateSinglePkgDB --- > updateCount == " + updateCount);
        return updateCount;
    }

    public void updatePkgsInBootDB(Context context, HashMap<String[], int[]> cns) {
        PerformanceDatabaseHelper dbHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase writeDB = dbHelper.getWritableDatabase();
        for (Map.Entry<String[], int[]> entry : cns.entrySet()) {
            String packageName = entry.getKey()[0];
            int changeToState = entry.getValue()[0];
            Log.i("DataLayerManageBoot", "updateManyPkgsDB --- > packageName == " + packageName + " newState == " + changeToState);
            if (changeToState != -1) {
                ContentValues values = new ContentValues();
                values.put(DatabaseTables.BOOTCOMPLETED_ITEM_CUSTOMER_STATE, Integer.valueOf(changeToState));
                writeDB.update(DatabaseTables.BOOTCOMPLETED_TABLE_NAME, values, "pkgName=?", new String[]{packageName});
            }
        }
        writeDB.close();
        dbHelper.close();
    }

    public void updatePkgsInBootDB2(Context context, HashMap<String, int[]> cns) {
        PerformanceDatabaseHelper dbHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase writeDB = dbHelper.getWritableDatabase();
        for (Map.Entry<String, int[]> entry : cns.entrySet()) {
            String packageName = entry.getKey();
            int changeToState = entry.getValue()[0];
            Log.i("DataLayerManageBoot", "updateManyPkgsDB --- > packageName == " + packageName + " newState == " + changeToState);
            if (changeToState != -1) {
                ContentValues values = new ContentValues();
                values.put(DatabaseTables.BOOTCOMPLETED_ITEM_CUSTOMER_STATE, Integer.valueOf(changeToState));
                writeDB.update(DatabaseTables.BOOTCOMPLETED_TABLE_NAME, values, "pkgName=?", new String[]{packageName});
            }
        }
        writeDB.close();
        dbHelper.close();
    }

    public int getNeedChangeToForbidJustCount() {
        return this.f1712d;
    }

    public HashMap<String[], int[]> getBootMap(Context context) {
        m633a(context);
        HashMap<String[], int[]> bootMap = new HashMap<>();
        this.f1712d = 0;
        PerformanceDatabaseHelper dbHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase readDB = dbHelper.getReadableDatabase();
        Cursor cursor = readDB.rawQuery("SELECT * FROM BootCom", null);
        if (cursor != null) {
            if (cursor.getCount() > 0) {
                cursor.moveToFirst();
                while (!cursor.isAfterLast()) {
                    String[] nameArr = {cursor.getString(cursor.getColumnIndex("pkgName")), cursor.getString(cursor.getColumnIndex(DatabaseTables.BOOTCOMPLETED_ITEM_CLSNAME))};
                    int[] stateArr = {-1, cursor.getInt(cursor.getColumnIndex(DatabaseTables.BOOTCOMPLETED_ITEM_CUSTOMER_STATE)), DataLayerManager.getExpertSuggest(context, nameArr[0]), 0};
                    if (stateArr[1] != 2 && stateArr[2] != 1) {
                        this.f1712d++;
                        stateArr[0] = 2;
                    }
                    bootMap.put(nameArr, stateArr);
                    Log.i("DataLayerManageBoot", "getBootMap --- > packageName == " + nameArr[0] + " needChangeToState == " + stateArr[3]);
                    cursor.moveToNext();
                }
            }
            cursor.close();
        }
        readDB.close();
        dbHelper.close();
        return bootMap;
    }

    public ArrayList<String> getBootForbidedList(Context context) {
        ArrayList<String> list = new ArrayList<>();
        PerformanceDatabaseHelper dbHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase readDB = dbHelper.getReadableDatabase();
        Cursor cursor = readDB.rawQuery("SELECT * FROM BootCom WHERE customer_state=2", null);
        if (cursor != null) {
            if (cursor.getCount() > 0) {
                cursor.moveToFirst();
                while (!cursor.isAfterLast()) {
                    String packageName = cursor.getString(cursor.getColumnIndex("pkgName"));
                    list.add(packageName);
                    cursor.moveToNext();
                }
            }
            cursor.close();
        }
        readDB.close();
        dbHelper.close();
        list.trimToSize();
        return list;
    }

    public int getAllAllowBootCount(Context context) {
        m633a(context);
        int count = 0;
        PerformanceDatabaseHelper dbHelper = new PerformanceDatabaseHelper(context);
        SQLiteDatabase readDB = dbHelper.getReadableDatabase();
        Cursor cursor = readDB.rawQuery("SELECT * FROM BootCom WHERE customer_state=1", null);
        if (cursor != null) {
            count = cursor.getCount();
            cursor.close();
        }
        readDB.close();
        dbHelper.close();
        return count;
    }
}
