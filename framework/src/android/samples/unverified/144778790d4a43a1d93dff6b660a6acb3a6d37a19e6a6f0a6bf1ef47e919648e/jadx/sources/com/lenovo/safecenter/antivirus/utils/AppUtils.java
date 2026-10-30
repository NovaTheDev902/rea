package com.lenovo.safecenter.antivirus.utils;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageParser;
import android.content.pm.Signature;
import android.content.res.AssetManager;
import android.content.res.Resources;
import android.database.Cursor;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Environment;
import android.util.DisplayMetrics;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.domain.Appinfo;
import com.lenovo.safecenter.antivirus.domain.CommonFile;
import com.lenovo.safecenter.antivirus.domain.VirusDemo;
import com.lenovo.safecenter.antivirus.support.AntiVirusDBHelper;
import com.lenovo.safecenter.antivirus.support.AntiVirusDBService;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.tencent.tmsecure.module.qscanner.QScanResultEntity;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Set;

/* JADX INFO: loaded from: classes.dex */
public class AppUtils {
    public static final String SDCARD2_PATH = "/mnt/sdcard2";

    public static boolean isThirdpartApp(ApplicationInfo appInfo) {
        if ((appInfo.flags & 128) == 0 && (appInfo.flags & 1) != 0) {
            return false;
        }
        return true;
    }

    public static List<Appinfo> getAppSInfo(Context context) {
        AntiVirusDBHelper nn = new AntiVirusDBHelper(context);
        return nn.getAppsInfo();
    }

    public static List<ApplicationInfo> getInstalledApps(Context context) {
        PackageManager pm = context.getPackageManager();
        ArrayList<ApplicationInfo> third_apps = new ArrayList<>();
        List<ApplicationInfo> installedAppList = pm.getInstalledApplications(0);
        if (installedAppList == null) {
            return null;
        }
        for (ApplicationInfo applicationInfo : installedAppList) {
            if (!applicationInfo.packageName.equals(TrafficStatsService.PACKAGE_NAME)) {
                third_apps.add(applicationInfo);
            }
        }
        return third_apps;
    }

    public static List<ApplicationInfo> getInstalledThirdApps(Context context) {
        PackageManager pm = context.getPackageManager();
        ArrayList<ApplicationInfo> third_apps = new ArrayList<>();
        List<ApplicationInfo> installedAppList = pm.getInstalledApplications(0);
        if (installedAppList == null) {
            return null;
        }
        for (ApplicationInfo applicationInfo : installedAppList) {
            boolean flag = isThirdpartApp(applicationInfo);
            if (flag && !applicationInfo.packageName.equals(TrafficStatsService.PACKAGE_NAME)) {
                third_apps.add(applicationInfo);
            }
        }
        Log.i("mes", "third_apps=" + third_apps.size() + "");
        return third_apps;
    }

    public static List<String> getInstalledSystemApps(Context context) {
        PackageManager pm = context.getPackageManager();
        ArrayList<String> third_apps = new ArrayList<>();
        List<ApplicationInfo> installedAppList = pm.getInstalledApplications(0);
        if (installedAppList == null) {
            return null;
        }
        for (ApplicationInfo applicationInfo : installedAppList) {
            boolean flag = isThirdpartApp(applicationInfo);
            String name = applicationInfo.loadLabel(pm).toString();
            if (!flag || name.equals(context.getString(C0415R.string.safecenter))) {
                third_apps.add(applicationInfo.packageName);
            }
        }
        Log.i("mes", "third_apps=" + third_apps.size() + "");
        return third_apps;
    }

    public static int getAppsCount(Context context) {
        PackageManager pm = context.getPackageManager();
        List<ApplicationInfo> installedAppList = pm.getInstalledApplications(0);
        if (installedAppList == null) {
            return 0;
        }
        return installedAppList.size();
    }

    public static String getCretMD5(Context Context, String packName) {
        String md5 = null;
        try {
            Signature[] sigs = Context.getPackageManager().getPackageInfo(packName, 64).signatures;
            for (int i = 0; i < sigs.length; i++) {
                String str1 = sigs[i].toCharsString();
                md5 = MD5Util.getMD5String(sigs[i].toByteArray());
                Log.i("info", "str1==" + str1 + ">>>>>>>>str===" + md5);
            }
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        if (md5 != null) {
            return md5.toUpperCase();
        }
        return md5;
    }

    public boolean ScanVirus_SHA1(String sha1, Context context) {
        try {
            AntiVirusDBService service = new AntiVirusDBService(context);
            List<String> shalist = service.getVirus_SHA1();
            for (String virus_sha1 : shalist) {
                if (virus_sha1.equalsIgnoreCase(sha1)) {
                    return true;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }

    public boolean ScanVirus_MD5(String pkgname, String md5, Context context) {
        AntiVirusDBService service = new AntiVirusDBService(context);
        return service.getVirus_md5(pkgname, md5);
    }

    public static List<CommonFile> getAllFiles(Context context) {
        PackageManager pm = context.getPackageManager();
        ArrayList<CommonFile> allFile = new ArrayList<>();
        List<ApplicationInfo> installedAppList = pm.getInstalledApplications(0);
        if (installedAppList == null) {
            return null;
        }
        for (ApplicationInfo applicationInfo : installedAppList) {
            if (!applicationInfo.packageName.equals(TrafficStatsService.PACKAGE_NAME)) {
                CommonFile cf = new CommonFile();
                cf.setApk(true);
                cf.setApplicationInfo(applicationInfo);
                cf.setSD(false);
                allFile.add(cf);
            }
        }
        allFile.addAll(getSDcardFiles(context));
        return allFile;
    }

    public static ArrayList<CommonFile> getSDcardFiles(Context context) {
        ArrayList<CommonFile> result = new ArrayList<>();
        String sdpath = "";
        boolean sdCardExist = Environment.getExternalStorageState().equals("mounted");
        if (sdCardExist) {
            sdpath = Environment.getExternalStorageDirectory().getAbsolutePath();
            File sdf = new File(sdpath);
            if (sdf.exists()) {
                m1326a(sdf.listFiles(), result, context);
            }
        }
        if (!SDCARD2_PATH.equals(sdpath)) {
            File sdf2 = new File(SDCARD2_PATH);
            if (sdf2.exists()) {
                m1326a(sdf2.listFiles(), result, context);
            }
        }
        return result;
    }

    /* JADX INFO: renamed from: a */
    private static void m1326a(File[] files, ArrayList<CommonFile> result, Context context) {
        PackageInfo info;
        if (files != null) {
            PackageManager pm = context.getPackageManager();
            for (File f : files) {
                if (f.isDirectory()) {
                    m1326a(f.listFiles(), result, context);
                } else if (f.getName().toLowerCase().endsWith(".apk") && (info = pm.getPackageArchiveInfo(f.getPath(), 1)) != null) {
                    CommonFile cf = new CommonFile();
                    cf.setApk(true);
                    cf.setApplicationInfo(info.applicationInfo);
                    cf.setFilePath(f.getPath());
                    cf.setSD(true);
                    result.add(cf);
                }
            }
        }
    }

    public static String getCretMD5(Signature[] sigs) {
        String md5 = null;
        for (int i = 0; i < sigs.length; i++) {
            sigs[i].toCharsString();
            md5 = MD5Util.getMD5String(sigs[i].toByteArray());
        }
        return md5.toUpperCase();
    }

    public static Appinfo getAppInfo(String filePath, Context context) {
        try {
            PackageManager pm = context.getPackageManager();
            PackageInfo info = pm.getPackageArchiveInfo(filePath, 64);
            String md5 = getCretMD5(info.signatures);
            String sha1 = "preload";
            File file = new File(filePath);
            long filesize = file.length();
            if (filesize < 20971520) {
                sha1 = SHA1Util.getFileMD5String(file);
            }
            return new Appinfo(info.packageName, md5, sha1, String.valueOf(filesize), filePath);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static Drawable getUninstallAPKIcon(String apkPath, Context context) {
        try {
            PackageParser packageParser = new PackageParser(apkPath);
            DisplayMetrics metrics = new DisplayMetrics();
            metrics.setToDefaults();
            PackageParser.Package mPkgInfo = packageParser.parsePackage(new File(apkPath), apkPath, metrics, 0);
            ApplicationInfo info = mPkgInfo.applicationInfo;
            Resources pRes = context.getResources();
            AssetManager assmgr = new AssetManager();
            assmgr.addAssetPath(apkPath);
            Resources res = new Resources(assmgr, pRes.getDisplayMetrics(), pRes.getConfiguration());
            return res.getDrawable(info.icon);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public static String getVirusDescKey(String packageName) {
        return "v_" + packageName;
    }

    public static void markVirus(String packageName, Context context) {
        String virus_pkgname = HttpUtils.execService("viruspkgname", context);
        if (!virus_pkgname.equalsIgnoreCase("")) {
            boolean isexist = false;
            String[] arr$ = virus_pkgname.split(",");
            for (String vir : arr$) {
                if (vir.equals(packageName)) {
                    isexist = true;
                    break;
                }
            }
            if (!isexist) {
                virus_pkgname = virus_pkgname + "," + packageName;
            }
        } else {
            virus_pkgname = packageName;
        }
        HttpUtils.UpdateConfig("viruspkgname", virus_pkgname, context);
    }

    public static void checkVirus(Context context, String pkgName) {
        Cursor cursor = context.getContentResolver().query(Uri.parse("content://com.lenovo.antivirus.AppinfoProvider/check"), null, "pkgname=?", new String[]{pkgName}, null);
        if (cursor != null && cursor.getCount() > 0) {
            markVirus(pkgName, context);
        }
        if (cursor != null) {
            cursor.close();
        }
    }

    public static void execLocalResult(QScanResultEntity result, Context context) {
        if (result.type == 3 && result.apkType != 1) {
            markVirus(result.packageName, context);
            HttpUtils.UpdateConfig(getVirusDescKey(result.packageName), result.discription, context);
        }
    }

    public static void execNetResult(List<VirusDemo> list, Context context) {
        HashMap<String, String> virusPackageNameMap = new HashMap<>();
        String virus_pkgname = HttpUtils.execService("viruspkgname", context);
        if (!virus_pkgname.equalsIgnoreCase("")) {
            String[] arr$ = virus_pkgname.split(",");
            for (String vir : arr$) {
                virusPackageNameMap.put(vir, null);
            }
        }
        if (list != null && list.size() > 0) {
            for (VirusDemo v_str : list) {
                if (!virusPackageNameMap.containsKey(v_str.getPkgName())) {
                    virusPackageNameMap.put(v_str.getPkgName(), null);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        Set<String> pkgs = virusPackageNameMap.keySet();
        for (String pkg : pkgs) {
            sb.append(pkg);
            sb.append(",");
        }
        if (sb.length() > 0) {
            HttpUtils.UpdateConfig("viruspkgname", sb.deleteCharAt(sb.length() - 1).toString(), context);
        }
    }

    public static boolean isNeedScan(Context context) {
        return true;
    }
}
