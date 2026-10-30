package com.lenovo.safecenter.notificationintercept;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.ComponentName;
import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Parcel;
import android.preference.PreferenceManager;
import android.text.Html;
import android.widget.RemoteViews;
import android.widget.Toast;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.performancecenter.performance.ScanApplicationInfo;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.utils.AppUtils;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.notificationintercept.support.IScanUtils;
import com.lenovo.safecenter.notificationintercept.support.InterceptPermission;
import com.lenovo.safecenter.notificationintercept.support.LogUtils;
import com.lenovo.safecenter.notificationintercept.support.NotiAdBean;
import com.lenovo.safecenter.notificationintercept.support.NotificationDB;
import com.lenovo.safecenter.notificationintercept.support.PermissionDB;
import com.lenovo.safecenter.notificationintercept.support.RecordBean;
import com.lenovo.safecenter.notificationintercept.support.RecordDB;
import com.lenovo.safecenter.notificationintercept.support.ScanUtilsImpl;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.support.WhiteAppsList;
import com.lenovo.safecenter.utils.Const;
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class InterceptUtils {
    public static final String AD_SWITCH = "ad_switch";
    public static final String FIRST_NOTIFY = "first_notify";
    public static final int FLAG_IACTIVITY = 18;
    public static final int FLAG_INOTIFICATION = 15;
    public static final int FLAG_NOTIFICATION_NOT_NULL = 1;
    public static final int FLAG_NOTIFICATION_NULL = 0;
    public static final String INTERCEPT_NEW_COUNT = "intercept_new_count";
    public static final int NOTIFY_ID = 133331;
    public static final int NOTIFY_ID_EMPTY = 133332;
    public static final int NOTIFY_ID_SCAN = 133333;
    public static final String NOTIFY_SWITCH = "notify_switch";
    public static final int PERMISSION_ALLOW = 1;
    public static final int PERMISSION_DEFAULT_ALLOW = 3;
    public static final int PERMISSION_FIRST_ALLOW = 0;
    public static final int PERMISSION_FORBID = 2;

    /* JADX INFO: renamed from: a */
    private static boolean f4759a = false;

    /* JADX INFO: renamed from: b */
    private static List<RecordBean> f4760b = new ArrayList();

    /* JADX INFO: renamed from: c */
    private static List<String> f4761c = new ArrayList();

    /* JADX INFO: renamed from: d */
    private static Map<String, Integer> f4762d = new HashMap();

    static {
        f4761c.clear();
        f4761c.add(TrafficStatsService.PACKAGE_NAME);
        f4761c.add("com.tencent.mm");
        f4761c.add("com.tencent.mm:push");
        f4761c.add("com.tencent.mobileqq");
        f4761c.add("com.tencent.android.pad");
        f4761c.add("com.duomi.android");
        f4761c.add("com.sina.weibo");
        f4761c.add("com.kugou.android");
        f4761c.add("cn.com.fetion");
        f4761c.add("com.xiaomi.channel");
        f4761c.add("com.immomo.momo");
        f4761c.add(Const.PACKAGENAME_LE_BATTERY);
        f4761c.add("com.dianxinos.powermanager");
        f4761c.add("com.qihoo360.mobilesafe.opti.powerctl");
        f4761c.add("com.zhimahu");
        f4761c.add("com.gau.go.launcherex.gowidget.gopowermaster");
        f4761c.add("com.yxlk.taskmanager");
        f4761c.add("com.antutu.powersaver");
        f4761c.add("com.snda.aipowermanager");
        f4761c.add("com.ijinshan.kbatterydoctor");
        f4761c.add("com.tencent.powermanager");
        f4761c.add("com.d1android.BatteryManager");
        f4761c.add("com.anguanjia.safe.battery");
    }

    /* JADX WARN: Code duplicated, block: B:70:0x0204  */
    /* JADX WARN: Code duplicated, block: B:72:0x020a  */
    /* JADX WARN: Code duplicated, block: B:85:0x023a  */
    /* JADX WARN: Code duplicated, block: B:87:0x0242  */
    /* JADX WARN: Code duplicated, block: B:88:0x0249  */
    public static boolean getInterceptPermission(byte[] buffer, int flag, Context context, DataOutputStream dos) throws IOException {
        int checkPermission;
        boolean z;
        Parcel parcel = Parcel.obtain();
        parcel.unmarshall(buffer, 0, buffer.length);
        parcel.setDataPosition(0);
        Notification notification = null;
        String packageName = "";
        int notificationId = 0;
        if (flag == 15) {
            parcel.enforceInterface("android.app.INotificationManager");
            packageName = parcel.readString();
            parcel.readString();
            notificationId = parcel.readInt();
        } else if (flag == 18) {
            parcel.enforceInterface("android.app.IActivityManager");
            ComponentName className = ComponentName.readFromParcel(parcel);
            packageName = className.getPackageName();
            parcel.readStrongBinder();
            notificationId = parcel.readInt();
        }
        if (m1974b(context, packageName) || m1972a(packageName)) {
            parcel.recycle();
            return true;
        }
        if (parcel.readInt() != 0) {
            try {
                notification = (Notification) Notification.CREATOR.createFromParcel(parcel);
            } catch (Exception e) {
                LogUtils.m1996e("Exception " + e.getMessage());
            }
            parcel.recycle();
        }
        if (notification == null || notification.contentView == null) {
            return true;
        }
        PermissionDB permissionDB = new PermissionDB(context);
        InterceptPermission interceptPermissionFindByName = permissionDB.findByName(packageName);
        if (interceptPermissionFindByName == null) {
            checkPermission = 0;
            ContentValues contentValues = new ContentValues();
            contentValues.put(QueryPermissions.PACKAGENAME, packageName);
            contentValues.put(QueryPermissions.PERMISSION, (Integer) 1);
            permissionDB.insert(contentValues);
            permissionDB.closeDatabase();
        } else {
            checkPermission = interceptPermissionFindByName.permission;
            permissionDB.closeDatabase();
        }
        LogUtils.m1997i(" checkPermission pkg = " + packageName + " permission == " + checkPermission);
        boolean handleNotification = false;
        if (checkPermission == 0) {
            handleNotification = true;
        }
        int mPermission = checkPermission == 2 ? 2 : 1;
        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        DataOutputStream data = new DataOutputStream(bos);
        if (f4759a) {
            int len = f4762d.size();
            data.writeInt(Integer.reverseBytes(mPermission == 1 ? 0 : 1));
            data.writeInt(Integer.reverseBytes(1));
            data.writeInt(Integer.reverseBytes(len));
            for (Map.Entry<String, Integer> entry : f4762d.entrySet()) {
                data.writeInt(Integer.reverseBytes(entry.getValue().intValue()));
            }
            f4759a = false;
        } else {
            data.writeInt(Integer.reverseBytes(mPermission == 1 ? 0 : 1));
            data.writeInt(Integer.reverseBytes(0));
        }
        byte[] byteArray = bos.toByteArray();
        data.close();
        bos.close();
        dos.write(byteArray);
        dos.flush();
        LogUtils.m1997i(" pkg === " + packageName + " permission == " + mPermission);
        if (notification != null) {
            String strM1969a = m1969a(notification);
            if (!"".equals(strM1969a) || handleNotification) {
                if ("".equals(strM1969a) && handleNotification) {
                    m1971a(context, m1970a(context, packageName), false, packageName, mPermission, handleNotification);
                } else {
                    String strM1970a = m1970a(context, packageName);
                    boolean z2 = false;
                    RecordDB recordDB = new RecordDB(context);
                    if (m1975b(strM1969a)) {
                        int[] iArrFindByPackage = recordDB.findByPackage(packageName);
                        if (iArrFindByPackage[0] <= 0 || mPermission != iArrFindByPackage[1]) {
                            if (recordDB.getCount() == 0) {
                                f4760b.clear();
                            } else if (f4760b.size() == 0) {
                                f4760b = recordDB.getLast();
                            }
                            int[] iArrFindByPackage2 = recordDB.findByPackage(packageName);
                            if (mPermission == 1 || iArrFindByPackage2[0] <= 0 || iArrFindByPackage2[1] != 1) {
                                z = true;
                            } else {
                                z = false;
                            }
                            if (z && !m1973a(strM1969a, mPermission, context, strM1970a, packageName, recordDB, notificationId)) {
                                z2 = true;
                            }
                            recordDB.closeDatabase();
                            m1971a(context, strM1970a, z2, packageName, mPermission, handleNotification);
                        } else {
                            recordDB.closeDatabase();
                        }
                    } else {
                        if (recordDB.getCount() == 0) {
                            f4760b.clear();
                        } else if (f4760b.size() == 0) {
                            f4760b = recordDB.getLast();
                        }
                        int[] iArrFindByPackage3 = recordDB.findByPackage(packageName);
                        if (mPermission == 1) {
                            z = true;
                        } else {
                            z = true;
                        }
                        if (z) {
                            z2 = true;
                        }
                        recordDB.closeDatabase();
                        m1971a(context, strM1970a, z2, packageName, mPermission, handleNotification);
                    }
                }
            }
        }
        return mPermission == 1;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m1973a(String content, int permission, Context context, String applicationLabel, String packageName, RecordDB recordDB, int notificationId) {
        int size = f4760b.size();
        int count = 0;
        int lastIndex = -1;
        for (int i = 0; i < size; i++) {
            RecordBean bean = f4760b.get(i);
            if (content.equals(bean.recordContent)) {
                count++;
                lastIndex = i;
            }
        }
        if (count != 0 && permission == f4760b.get(lastIndex).recordPermission) {
            return true;
        }
        synchronized (f4760b) {
            long currentTimeMillis = System.currentTimeMillis();
            ContentValues values = new ContentValues();
            values.put(QueryPermissions.PACKAGENAME, packageName);
            values.put("applabel", applicationLabel);
            values.put("notification_content", content);
            values.put(DatabaseTables.LOG_TIMESTAMP, Long.valueOf(currentTimeMillis));
            values.put("notification_id", Integer.valueOf(notificationId));
            values.put("record_permission", Integer.valueOf(permission));
            recordDB.insert(values);
            SharedPreferences dfPrefs = PreferenceManager.getDefaultSharedPreferences(context);
            int mCount = dfPrefs.getInt(INTERCEPT_NEW_COUNT, 0);
            SharedPreferences.Editor edit = dfPrefs.edit();
            edit.putInt(INTERCEPT_NEW_COUNT, mCount + 1);
            edit.commit();
            if (f4760b.size() >= 3) {
                f4760b.remove(0);
            }
            updateRecordListAdd(content, permission, currentTimeMillis);
        }
        return false;
    }

    public static void updateRecordListAdd(String content, int permission, long currentTimeMillis) {
        RecordBean bean = new RecordBean();
        bean.recordContent = content;
        bean.recordPermission = permission;
        bean.currentTimeMillis = currentTimeMillis;
        f4760b.add(bean);
    }

    public static void updateRecordListRemove(long currentTimeMillis) {
        for (RecordBean bean : f4760b) {
            if (bean.currentTimeMillis == currentTimeMillis) {
                f4760b.remove(bean);
                return;
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m1971a(Context context, String applicationLabel, boolean isToRecord, String packageName, int permission, boolean handleNotification) {
        LogUtils.m1997i(" showInterceptNotification Label=" + applicationLabel + " isToRecord = " + isToRecord + " handleNotification = " + handleNotification);
        if (isToRecord || handleNotification) {
            SharedPreferences df_prefs = PreferenceManager.getDefaultSharedPreferences(context);
            if (handleNotification && df_prefs.getBoolean(NOTIFY_SWITCH, true)) {
                LogUtils.m1997i(" show first Lable = " + applicationLabel + " pkg = " + packageName);
                Notification mNotification = new Notification();
                mNotification.icon = C0415R.drawable.notification_intercept_icon_green;
                mNotification.tickerText = String.format(context.getString(C0415R.string.notification_intercept_notify), applicationLabel);
                mNotification.when = System.currentTimeMillis();
                RemoteViews remoteViews = new RemoteViews(context.getPackageName(), C0415R.layout.notification_notify);
                Intent intent = new Intent(context, (Class<?>) NotificationTabActivity.class);
                intent.putExtra("tab", "noti_permission");
                intent.setFlags(335544320);
                PendingIntent contentIntent = PendingIntent.getActivity(context, 0, intent, 0);
                remoteViews.setTextViewText(C0415R.id.intercept_notify_label, String.format(context.getString(C0415R.string.notification_intercept_detail), applicationLabel));
                mNotification.contentView = remoteViews;
                mNotification.contentIntent = contentIntent;
                ((NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION)).notify(NOTIFY_ID, mNotification);
                return;
            }
            if (permission == 2 && df_prefs.getBoolean(NOTIFY_SWITCH, true)) {
                Notification mNotification2 = new Notification();
                RemoteViews remoteViews2 = new RemoteViews(context.getPackageName(), C0415R.layout.notification_notify_empty);
                PendingIntent contentIntent2 = PendingIntent.getActivity(context, 0, new Intent(), 0);
                mNotification2.icon = C0415R.drawable.notification_intercept_icon_green;
                mNotification2.tickerText = Html.fromHtml(context.getString(C0415R.string.notification_intercept_notify_str, applicationLabel));
                mNotification2.when = System.currentTimeMillis();
                mNotification2.contentView = remoteViews2;
                mNotification2.contentIntent = contentIntent2;
                NotificationManager manager = (NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION);
                manager.notify(NOTIFY_ID_EMPTY, mNotification2);
                try {
                    Thread.sleep(1000L);
                } catch (Exception e) {
                }
                manager.cancel(NOTIFY_ID_EMPTY);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private static String m1970a(Context context, String packageName) {
        PackageManager packageManager = context.getPackageManager();
        try {
            ApplicationInfo applicationInfo = packageManager.getApplicationInfo(packageName, 1);
            String applicationLabel = applicationInfo.loadLabel(packageManager).toString();
            return applicationLabel;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return "";
        }
    }

    /* JADX INFO: renamed from: b */
    private static boolean m1974b(Context context, String packageName) {
        try {
            PackageManager packageManager = context.getPackageManager();
            ApplicationInfo applicationInfo = packageManager.getApplicationInfo(packageName, 1);
            return (applicationInfo.flags & 1) != 0 || WhiteAppsList.contains(WhiteAppsList.md5s, AppUtils.getCretMD5(context, packageName));
        } catch (PackageManager.NameNotFoundException e) {
        }
    }

    /* JADX INFO: renamed from: a */
    private static boolean m1972a(String packageName) {
        return packageName.startsWith(TrafficStatsService.PACKAGE_NAME) || f4761c.contains(packageName);
    }

    /* JADX INFO: renamed from: b */
    private static boolean m1975b(String content) {
        if (!content.contains("%")) {
            return false;
        }
        if (content.trim().endsWith("%")) {
            return true;
        }
        String str = content.subSequence(0, content.indexOf("%")).toString();
        try {
            Integer.parseInt(str.trim());
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    /* JADX INFO: renamed from: a */
    private static String m1969a(Notification notification) {
        RemoteViews contentView = notification.contentView;
        String notificationSummary = "";
        if (contentView != null) {
            try {
                Field declaredField = contentView.getClass().getDeclaredField("mActions");
                if (declaredField != null) {
                    declaredField.setAccessible(true);
                    ArrayList actions = (ArrayList) declaredField.get(contentView);
                    for (int i = 0; i < actions.size(); i++) {
                        Field methodName = actions.get(i).getClass().getDeclaredField("methodName");
                        methodName.setAccessible(true);
                        if (((String) methodName.get(actions.get(i))).equals("setText")) {
                            Field value = actions.get(i).getClass().getDeclaredField("value");
                            value.setAccessible(true);
                            CharSequence charSequence = (CharSequence) value.get(actions.get(i));
                            notificationSummary = notificationSummary + ((Object) charSequence) + " ";
                        }
                    }
                    return notificationSummary;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return "";
    }

    public static void initWhiteListUid(Context context, String packageName) {
        if (packageName == null || "".equals(packageName)) {
            try {
                f4762d.clear();
                PackageManager packageManager = context.getPackageManager();
                for (String pkg : f4761c) {
                    try {
                        ApplicationInfo ai = packageManager.getApplicationInfo(pkg, 8192);
                        int uid = ai.uid;
                        if (uid > 0) {
                            f4762d.put(pkg, Integer.valueOf(uid));
                        }
                    } catch (PackageManager.NameNotFoundException e) {
                    }
                }
                f4759a = true;
                return;
            } catch (Exception e2) {
                return;
            }
        }
        if (f4761c.contains(packageName)) {
            try {
                PackageManager packageManager2 = context.getPackageManager();
                ApplicationInfo applicationInfo = packageManager2.getApplicationInfo(packageName, 1);
                int uid2 = applicationInfo.uid;
                if (f4762d.get(packageName) == null || f4762d.get(packageName).intValue() != uid2) {
                    f4762d.remove(packageName);
                    f4762d.put(packageName, Integer.valueOf(applicationInfo.uid));
                }
                f4759a = true;
            } catch (Exception e3) {
            }
        }
    }

    public static int adApkInsert(String packageName, Context context) {
        ScanApplicationInfo.killProcess(context, packageName);
        PermissionDB permissionDB = new PermissionDB(context);
        InterceptPermission findByName = permissionDB.findByName(packageName);
        if (findByName == null) {
            ContentValues contentValues = new ContentValues();
            contentValues.put(QueryPermissions.PACKAGENAME, packageName);
            contentValues.put(QueryPermissions.PERMISSION, (Integer) 2);
            permissionDB.insert(contentValues);
            permissionDB.closeDatabase();
            Toast.makeText(context, context.getString(C0415R.string.notification_ad_insert_notify, m1970a(context, packageName)), 1).show();
            return 1;
        }
        ContentValues contentValues2 = new ContentValues();
        contentValues2.put(QueryPermissions.PACKAGENAME, packageName);
        contentValues2.put(QueryPermissions.PERMISSION, (Integer) 2);
        permissionDB.update(findByName._id, contentValues2);
        permissionDB.closeDatabase();
        return findByName.permission;
    }

    /* JADX WARN: Type inference failed for: r0v1, types: [com.lenovo.safecenter.notificationintercept.InterceptUtils$1] */
    public static void appInit(final Context context) {
        LogUtils.m1997i(" appInit !! scanAll ");
        new Thread() { // from class: com.lenovo.safecenter.notificationintercept.InterceptUtils.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                IScanUtils utils = new ScanUtilsImpl();
                utils.notifyScanAll(context);
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v1, types: [com.lenovo.safecenter.notificationintercept.InterceptUtils$2] */
    public static void appInstall(final Context context, final String packageName) {
        LogUtils.m1997i(" appInstall !! scan ");
        new Thread() { // from class: com.lenovo.safecenter.notificationintercept.InterceptUtils.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                IScanUtils utils = new ScanUtilsImpl();
                utils.notifyScanSingle(context, packageName);
            }
        }.start();
    }

    public static void appRemoved(Context context, String packageName) {
        LogUtils.m1997i(" appInstall !! scan ");
        try {
            NotificationDB db = new NotificationDB(context);
            NotiAdBean findByName = db.findByName(packageName);
            if (findByName != null) {
                db.delete(findByName.getId());
            }
            db.closeDatabase();
        } catch (Exception e) {
            LogUtils.m1996e(" Pkg remove Exception " + e.getMessage());
            e.printStackTrace();
        }
    }

    public static void bootCompleted(Context context) {
        String filepath = context.getFilesDir().getAbsolutePath() + "/notification";
        String cmd = "dumpsys notification > " + filepath + "\n";
        boolean exeCmd = CMDHelper.exeCmd(context, cmd);
        LogUtils.m1997i(" bootCompleted exeCMD " + exeCmd);
        if (exeCmd) {
            List<String> notifications = null;
            try {
                BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(new File(filepath))));
                List<String> notifications2 = new ArrayList<>();
                while (true) {
                    try {
                        String line = reader.readLine();
                        if (line == null) {
                            break;
                        }
                        if (line.trim().startsWith("NotificationRecord")) {
                            String[] split = line.split(" ");
                            for (String mSplit : split) {
                                if (mSplit.startsWith("pkg")) {
                                    String substring = mSplit.substring(mSplit.lastIndexOf("=") + 1, mSplit.length());
                                    notifications2.add(substring);
                                }
                            }
                        }
                    } catch (FileNotFoundException e) {
                        e = e;
                        notifications = notifications2;
                        e.printStackTrace();
                    } catch (IOException e2) {
                        e = e2;
                        notifications = notifications2;
                        e.printStackTrace();
                    }
                }
                notifications = notifications2;
            } catch (FileNotFoundException e3) {
                e = e3;
            } catch (IOException e4) {
                e = e4;
            }
            if (notifications != null && notifications.size() != 0) {
                PermissionDB db = new PermissionDB(context);
                List<InterceptPermission> permissions = db.findAll();
                db.closeDatabase();
                for (String pkg : notifications) {
                    for (InterceptPermission mPermission : permissions) {
                        if (pkg.equals(mPermission.pkgname) && mPermission.permission == 2) {
                            RootPassage.clearnNotification(pkg, context);
                        }
                    }
                }
            }
        }
    }

    public static boolean notificationFilter(Context context, String packageName) {
        return m1974b(context, packageName) || m1972a(packageName);
    }

    @Deprecated
    public static void notificationForbid(Context context, String pkgName) {
        ContentValues values = new ContentValues();
        values.put(QueryPermissions.PACKAGENAME, pkgName);
        values.put(QueryPermissions.PERMISSION, (Integer) 2);
        PermissionDB db = new PermissionDB(context);
        InterceptPermission permission = db.findByName(pkgName);
        if (permission == null) {
            db.insert(values);
        } else {
            values.put("_id", Integer.valueOf(permission._id));
            db.update(permission._id, values);
        }
        db.closeDatabase();
    }

    @Deprecated
    public static void notificationAllow(Context context, String pkgName) {
        ContentValues values = new ContentValues();
        values.put(QueryPermissions.PACKAGENAME, pkgName);
        values.put(QueryPermissions.PERMISSION, (Integer) 1);
        PermissionDB db = new PermissionDB(context);
        InterceptPermission permission = db.findByName(pkgName);
        if (permission == null) {
            db.insert(values);
        } else {
            values.put("_id", Integer.valueOf(permission._id));
            db.update(permission._id, values);
        }
        db.closeDatabase();
    }

    /* JADX WARN: Type inference failed for: r3v6, types: [com.lenovo.safecenter.notificationintercept.InterceptUtils$3] */
    public static void notificationAllow(final Context context, final String pkgName, boolean isAllow) {
        ContentValues values = new ContentValues();
        values.put(QueryPermissions.PACKAGENAME, pkgName);
        values.put(QueryPermissions.PERMISSION, Integer.valueOf(isAllow ? 1 : 2));
        PermissionDB db = new PermissionDB(context);
        InterceptPermission permission = db.findByName(pkgName);
        if (permission == null) {
            db.insert(values);
        } else {
            values.put("_id", Integer.valueOf(permission._id));
            db.update(permission._id, values);
        }
        db.closeDatabase();
        if (!isAllow) {
            new Thread() { // from class: com.lenovo.safecenter.notificationintercept.InterceptUtils.3
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    RootPassage.clearnNotification(pkgName, context);
                }
            }.start();
        }
    }

    public static List<InterceptPermission> checkScannedAd(Context context) {
        PermissionDB pDB = new PermissionDB(context);
        List<InterceptPermission> permissions = pDB.findAll();
        pDB.closeDatabase();
        NotificationDB nDB = new NotificationDB(context);
        List<NotiAdBean> notifications = nDB.findAll();
        nDB.closeDatabase();
        List<InterceptPermission> mPermissions = new ArrayList<>();
        for (NotiAdBean adBean : notifications) {
            for (InterceptPermission permission : permissions) {
                if (adBean.getPkgName().equals(permission.pkgname) && permission.permission == 1) {
                    mPermissions.add(permission);
                }
            }
        }
        return mPermissions;
    }

    public static boolean setScannedAdForbid(Context context, List<InterceptPermission> permissions) {
        for (InterceptPermission mPermission : permissions) {
            mPermission.permission = 2;
        }
        try {
            PermissionDB pDB = new PermissionDB(context);
            pDB.updateList(permissions);
            pDB.closeDatabase();
            return true;
        } catch (Exception e) {
            LogUtils.m1996e(" update Error");
            e.printStackTrace();
            return false;
        }
    }

    public static boolean getNotificationAllow(Context context, String pkgName) {
        PermissionDB db = new PermissionDB(context);
        InterceptPermission permission = db.findByName(pkgName);
        db.closeDatabase();
        return permission == null || permission.permission == 1;
    }
}
