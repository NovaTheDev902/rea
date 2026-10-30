package com.lenovo.performancecenter.performance;

import android.app.ActivityManager;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.content.pm.ServiceInfo;
import android.os.Handler;
import android.util.Log;
import android.view.inputmethod.InputMethodInfo;
import android.view.inputmethod.InputMethodManager;
import com.lenovo.performancecenter.coreui.util.MemoryTools;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.performancecenter.service.object.PolicyAppInfo;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Timer;
import java.util.TreeMap;

/* JADX INFO: loaded from: classes.dex */
public class ScanApplicationInfo {
    public static final long DEFAULT_POLICY_TIME = 20;
    public static final int GET_CAN_KILL_LIST = 0;
    public static final String POLICY_SETTINGS = "policy_settings";
    public static final String POLICY_SWITCH = "policy_switch";
    public static final String POLICY_TIME = "policy_time";

    /* JADX INFO: renamed from: f */
    private static ScanApplicationInfo f1826f;

    /* JADX INFO: renamed from: a */
    private Timer f1827a;

    /* JADX INFO: renamed from: b */
    private PolicyTask f1828b;

    /* JADX INFO: renamed from: c */
    private long f1829c;

    /* JADX INFO: renamed from: d */
    private boolean f1830d;

    /* JADX INFO: renamed from: e */
    private Handler f1831e;

    private ScanApplicationInfo(Handler handler) {
        Log.i("ScanApp", "ScanApplicationInfo Constructor");
        this.f1831e = handler;
    }

    public static ScanApplicationInfo getSingleton(Context context, Handler handler) {
        Log.i("PolicyService", "getSingleton : " + f1826f);
        if (f1826f == null) {
            f1826f = new ScanApplicationInfo(handler);
            Log.i("PolicyService", "instance = new ScanApplicationInfo(context)");
        }
        return f1826f;
    }

    public static void releaseInstance() {
        Log.i("PolicyService", "getSingleton : " + f1826f);
        f1826f = null;
    }

    public void initPolicyTask(Context context) {
        SharedPreferences pref = context.getSharedPreferences(POLICY_SETTINGS, 0);
        this.f1829c = pref.getLong(POLICY_TIME, 20L);
        this.f1830d = pref.getBoolean(POLICY_SWITCH, false);
        if (this.f1830d) {
            this.f1827a = new Timer(true);
            this.f1828b = new PolicyTask(context, this.f1831e);
            this.f1827a.schedule(this.f1828b, this.f1829c * 60000, this.f1829c * 60000);
        }
    }

    public void stopPolicyTask(Context context) {
        if (this.f1828b != null) {
            this.f1828b.cancel();
            this.f1828b.release();
            this.f1828b = null;
        }
    }

    public void restartPolicyTask(Context context) {
        stopPolicyTask(context);
        initPolicyTask(context);
    }

    public void updateConfiguration(String key, Object value, Context context) {
        if (POLICY_TIME.equals(key)) {
            this.f1829c = ((Long) value).longValue();
            restartPolicyTask(context);
            return;
        }
        if (POLICY_SWITCH.equals(key)) {
            this.f1830d = ((Boolean) value).booleanValue();
            if (this.f1830d) {
                restartPolicyTask(context);
            } else if (this.f1828b != null) {
                this.f1828b.cancel();
                this.f1828b.isRunning = false;
                stopPolicyTask(context);
            }
        }
    }

    /* JADX WARN: Code duplicated, block: B:18:0x0074  */
    /* JADX INFO: renamed from: a */
    private static TreeMap<Integer, String> m717a(Context context, ArrayList<String> launchers) {
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningProcesses start");
        TreeMap<Integer, String> mapRunningProcess = new TreeMap<>();
        PackageManager pkgManager = context.getPackageManager();
        ArrayList<String> userWhiteList = DataLayerManager.getUserWhiteList(context);
        ArrayList<String> highLevelWhiteList = DataLayerManager.getLenovoHighLevelPkg(context);
        ArrayList<String> notKillHiddenAppList = DataLayerManager.getWhiteListNotKillForHidden(context);
        ActivityManager activityManager = (ActivityManager) context.getSystemService("activity");
        List<ActivityManager.RunningAppProcessInfo> runningAppProcesses = activityManager.getRunningAppProcesses();
        for (int i = 0; i < runningAppProcesses.size(); i++) {
            ActivityManager.RunningAppProcessInfo rapInfo = runningAppProcesses.get(i);
            if (rapInfo.importance > 100) {
                String[] pkgList = rapInfo.pkgList;
                for (String packageName : pkgList) {
                    if (launchers.contains(packageName)) {
                        if (!userWhiteList.contains(packageName) && !highLevelWhiteList.contains(packageName)) {
                            mapRunningProcess.put(Integer.valueOf(rapInfo.pid), packageName);
                        }
                    } else if (!notKillHiddenAppList.contains(packageName) && !m718a(pkgManager, packageName)) {
                        mapRunningProcess.put(Integer.valueOf(rapInfo.pid), packageName);
                    }
                }
            }
        }
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningProcesses end");
        return mapRunningProcess;
    }

    public static HashMap<String, int[]> getRunningAppInfo(Context inContext) {
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningAppInfo start");
        HashMap<String, int[]> map = new HashMap<>();
        Context context = (Context) Utils.getSoftreference(inContext);
        ArrayList<String> launchers = getInstalledAppInLauncher(context);
        TreeMap<Integer, String> mapRunningProcess = m717a(context, launchers);
        for (Map.Entry<Integer, String> element : mapRunningProcess.entrySet()) {
            int pid = element.getKey().intValue();
            String pkgName = element.getValue();
            int inLauncher = launchers.contains(pkgName) ? 1 : 0;
            int memory = MemoryTools.getMemInfoForPid(context, pid);
            Log.i("DESIGN", System.currentTimeMillis() + " pid == " + pid + " packageName == " + pkgName + " memory == " + memory);
            if (map.get(pkgName) != null) {
                int[] value = map.get(pkgName);
                memory += value[1];
            }
            map.put(pkgName, new int[]{pid, memory, inLauncher});
        }
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningAppInfo end");
        return map;
    }

    public static HashMap<String, int[]> getRunningAppInfoJustInLauncher(Context inContext) {
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningAppInfoJustInLauncher start");
        HashMap<String, int[]> map = new HashMap<>();
        Context context = (Context) Utils.getSoftreference(inContext);
        ArrayList<String> launchers = getInstalledAppInLauncher(context);
        TreeMap<Integer, String> mapRunningProcess = m717a(context, launchers);
        for (Map.Entry<Integer, String> element : mapRunningProcess.entrySet()) {
            int pid = element.getKey().intValue();
            String pkgName = element.getValue();
            int inLauncher = launchers.contains(pkgName) ? 1 : 0;
            int memory = 0;
            if (inLauncher == 1) {
                memory = MemoryTools.getMemInfoForPid(context, pid);
                Log.i("DESIGN", System.currentTimeMillis() + " pid == " + pid + " packageName == " + pkgName + " memory == " + memory);
                if (map.get(pkgName) != null) {
                    int[] value = map.get(pkgName);
                    memory += value[1];
                }
            }
            map.put(pkgName, new int[]{pid, memory, inLauncher});
        }
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningAppInfoJustInLauncher end");
        return map;
    }

    public static ArrayList<String> getRunningAppListJustInLauncher(Context inContext) {
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningAppListJustInLauncher start");
        ArrayList<String> list = new ArrayList<>();
        Context context = (Context) Utils.getSoftreference(inContext);
        ArrayList<String> launchers = getInstalledAppInLauncher(context);
        TreeMap<Integer, String> mapRunningProcess = m717a(context, launchers);
        for (Map.Entry<Integer, String> element : mapRunningProcess.entrySet()) {
            String pkgName = element.getValue();
            if (launchers.contains(pkgName) && !list.contains(pkgName)) {
                list.add(pkgName);
            }
        }
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningAppListJustInLauncher end");
        return list;
    }

    public static ArrayList<String> getRunningAppList(Context inContext) {
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningAppList start");
        Context context = (Context) Utils.getSoftreference(inContext);
        ArrayList<String> list = new ArrayList<>();
        ArrayList<String> launchers = getInstalledAppInLauncher(context);
        TreeMap<Integer, String> mapRunningProcess = m717a(context, launchers);
        for (Map.Entry<Integer, String> element : mapRunningProcess.entrySet()) {
            String pkgName = element.getValue();
            if (!list.contains(pkgName)) {
                list.add(pkgName);
            }
        }
        Log.i("DESIGN", System.currentTimeMillis() + " getRunningAppList end");
        return list;
    }

    public static HashMap<String, PolicyAppInfo> readRunningAppInfoPolicy(Context inContext, PolicyTask policyTask) {
        int flag;
        Context context = (Context) Utils.getSoftreference(inContext);
        String myPkgName = inContext.getPackageName();
        HashMap<String, PolicyAppInfo> zhengYunXingMap = new HashMap<>();
        ActivityManager activityManager = (ActivityManager) context.getSystemService("activity");
        List<ActivityManager.RunningAppProcessInfo> runningAppProcesses = activityManager.getRunningAppProcesses();
        ArrayList<String> userWhiteList = DataLayerManager.getUserWhiteList(context);
        int rPCount = runningAppProcesses.size();
        for (int i = 0; i < rPCount && policyTask.isRunning; i++) {
            ActivityManager.RunningAppProcessInfo rapInfo = runningAppProcesses.get(i);
            if (rapInfo.importance > 100) {
                String[] pkgList = rapInfo.pkgList;
                int pkgCount = pkgList.length;
                for (int j = 0; j < pkgCount; j++) {
                    PackageManager pkgManager = context.getPackageManager();
                    try {
                        PackageInfo pkgInfo = pkgManager.getPackageInfo(pkgList[j], 1);
                        ApplicationInfo appInfo = pkgManager.getApplicationInfo(pkgList[j], 0);
                        if (!pkgInfo.packageName.equals(myPkgName) && !userWhiteList.contains(appInfo.packageName)) {
                            if ((appInfo.flags & 1) <= 0) {
                                flag = 0;
                            } else {
                                flag = 1;
                            }
                            CharSequence appLabel = "";
                            if (pkgInfo.applicationInfo.labelRes != 0) {
                                appLabel = pkgManager.getText(pkgList[j], pkgInfo.applicationInfo.labelRes, pkgInfo.applicationInfo);
                            }
                            PolicyAppInfo uai = new PolicyAppInfo(rapInfo.pid, rapInfo.processName, context);
                            uai.pid = rapInfo.pid;
                            uai.uid = rapInfo.uid;
                            uai.packageName = pkgList[j];
                            uai.processName = rapInfo.processName;
                            uai.label = (String) appLabel;
                            uai.addNum();
                            uai.setImportance(rapInfo.importance);
                            uai.flag = flag;
                            long currentTime = System.currentTimeMillis();
                            if (rapInfo.importance == 100) {
                                uai.setForegoing(currentTime);
                            }
                            uai.setRunningTime(currentTime);
                            uai.setTodayUsed(true);
                            uai.updateUAIRunningTimeToDatebase();
                            policyTask.updatePolicyData(uai, false);
                            zhengYunXingMap.put(uai.packageName, uai);
                            Log.i("ScanApp", rapInfo.processName + "========end=========");
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        }
        DataLayerManager.fileUserWhiteListPolicy(zhengYunXingMap, context);
        return zhengYunXingMap;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m718a(PackageManager pm, String pkgname) {
        if ("com.google.android.apps.maps".equals(pkgname)) {
            return false;
        }
        if (pm.checkPermission("android.permission.BIND_WALLPAPER", pkgname) == 0) {
            return true;
        }
        try {
            PackageInfo pi = pm.getPackageInfo(pkgname, 4);
            if (pi.services == null) {
                return false;
            }
            ServiceInfo[] arr$ = pi.services;
            for (ServiceInfo si : arr$) {
                if (si.permission != null && si.permission.equals("android.permission.BIND_WALLPAPER")) {
                    return true;
                }
            }
            return false;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }

    public static void addInputMethod(Context context, ArrayList<String> list) {
        InputMethodManager imm = (InputMethodManager) context.getSystemService("input_method");
        List<InputMethodInfo> mInputMethodProperties = imm.getInputMethodList();
        int size = mInputMethodProperties.size();
        for (int i = 0; i < size; i++) {
            InputMethodInfo info = mInputMethodProperties.get(i);
            list.add(info.getPackageName());
        }
    }

    public static ArrayList<String> getInstalledLauncher(Context context) {
        ArrayList<String> launchers = new ArrayList<>();
        PackageManager pm = context.getPackageManager();
        Intent it = new Intent("android.intent.action.MAIN");
        it.addCategory("android.intent.category.HOME");
        List<ResolveInfo> resolveList = pm.queryIntentActivities(it, 0);
        for (ResolveInfo ri : resolveList) {
            launchers.add(ri.activityInfo.packageName);
        }
        return launchers;
    }

    public static ArrayList<String> getInstalledAppInLauncher(Context context) {
        ArrayList<String> launchers = new ArrayList<>();
        PackageManager pm = context.getPackageManager();
        Intent it = new Intent("android.intent.action.MAIN");
        it.addCategory("android.intent.category.LAUNCHER");
        List<ResolveInfo> resolveList = pm.queryIntentActivities(it, 0);
        for (ResolveInfo ri : resolveList) {
            launchers.add(ri.activityInfo.packageName);
        }
        return launchers;
    }

    public static void killProcess(Context cotext, String pkgName) {
        try {
            RootPassage.execRootCmd(pkgName, " -fs ", cotext);
        } catch (Exception e) {
            ActivityManager am = (ActivityManager) cotext.getSystemService("activity");
            am.killBackgroundProcesses(pkgName);
        }
    }

    public static void killAllProcess(Handler handler, Context cotext, ArrayList<String> pkgList) {
        try {
            RootPassage.execRootCmd(handler, pkgList, " -fs ", cotext);
        } catch (Exception e) {
            ActivityManager am = (ActivityManager) cotext.getSystemService("activity");
            for (String pkgName : pkgList) {
                am.killBackgroundProcesses(pkgName);
            }
        }
    }
}
