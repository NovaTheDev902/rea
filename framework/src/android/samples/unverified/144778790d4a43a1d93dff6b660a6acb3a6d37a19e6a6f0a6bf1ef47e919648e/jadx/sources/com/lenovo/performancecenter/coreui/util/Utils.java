package com.lenovo.performancecenter.coreui.util;

import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.net.Uri;
import android.os.Build;
import android.os.Parcelable;
import android.util.Log;
import android.view.KeyEvent;
import android.widget.Toast;
import com.lenovo.performancecenter.LeemCenterJNITools;
import com.lenovo.performancecenter.service.object.KillAllPackageReceiver;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.shortcut.CleanAcitivty;
import com.lenovo.safecenter.utils.Const;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.RandomAccessFile;
import java.lang.ref.SoftReference;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class Utils {
    public static final long CLICK_INTERVAL = 15000;
    public static final String SP_SHORTCUT = "SHORTCUT";
    public static final String SP_SHORTCUT_CLICKPOSTION = "SHORTCUT_CLICKPOSTION";
    public static final String SP_SHORTCUT_ENDMEMORY = "SHORTCUT_ENDMEMORY";
    public static final String SP_SHORTCUT_LASTCLICK = "SHORTCUT_LASTCLICK";

    /* JADX INFO: renamed from: a */
    private static long f1611a;

    /* JADX INFO: renamed from: b */
    private static ArrayList<String> f1612b;

    /* JADX INFO: renamed from: c */
    private static boolean f1613c;
    public static boolean isPerfRoot;

    public static <T> T getSoftreference(T t) {
        return (T) new SoftReference(t).get();
    }

    public static void recordBootTime(long bootTime) {
        f1611a = bootTime;
    }

    public static long getBootTime() {
        return f1611a;
    }

    public static void recordOpenPkgList(String pkgName) {
        if (f1612b == null) {
            f1612b = new ArrayList<>();
        }
        f1612b.add(pkgName);
    }

    public static ArrayList<String> getRecordPkgList() {
        if (f1612b == null) {
            f1612b = new ArrayList<>();
        }
        return f1612b;
    }

    public static void recordKillTimeAndPosition(Context context, long killTime, int position) {
        SharedPreferences sp = context.getSharedPreferences(SP_SHORTCUT, 0);
        SharedPreferences.Editor editor = sp.edit();
        editor.putLong(SP_SHORTCUT_LASTCLICK, killTime);
        editor.putInt(SP_SHORTCUT_CLICKPOSTION, position);
        editor.commit();
        KillAllPackageReceiver.sendBroadcastAboutKillEvent(context, killTime, position);
    }

    public static long getLastKillTime(Context context) {
        SharedPreferences sp = context.getSharedPreferences(SP_SHORTCUT, 0);
        return sp.getLong(SP_SHORTCUT_LASTCLICK, 0L);
    }

    public static int getLastClickPosition(Context context) {
        SharedPreferences sp = context.getSharedPreferences(SP_SHORTCUT, 0);
        return sp.getInt(SP_SHORTCUT_CLICKPOSTION, 0);
    }

    public static void recordEndMemory(Context context, int endMeomory) {
        SharedPreferences sp = context.getSharedPreferences(SP_SHORTCUT, 0);
        SharedPreferences.Editor editor = sp.edit();
        editor.putInt(SP_SHORTCUT_ENDMEMORY, endMeomory);
        editor.commit();
    }

    public static int getEndMemory(Context context) {
        SharedPreferences sp = context.getSharedPreferences(SP_SHORTCUT, 0);
        return sp.getInt(SP_SHORTCUT_ENDMEMORY, 1);
    }

    public static ProgressDialog showDialog(Context context, String showMessage) {
        ProgressDialog dialog = new ProgressDialog(context);
        dialog.setMessage(showMessage);
        dialog.setIndeterminate(true);
        dialog.setCancelable(true);
        dialog.setCanceledOnTouchOutside(false);
        dialog.setOnKeyListener(new DialogInterface.OnKeyListener() { // from class: com.lenovo.performancecenter.coreui.util.Utils.1
            @Override // android.content.DialogInterface.OnKeyListener
            public final boolean onKey(DialogInterface dialog2, int keyCode, KeyEvent event) {
                return true;
            }
        });
        dialog.show();
        return dialog;
    }

    public static int getTotleCpu() {
        long start = System.currentTimeMillis();
        float totleCpu = LeemCenterJNITools.getTotalCpuload_native();
        long end = System.currentTimeMillis();
        Log.i("test", "getTotleCpu() " + (end - start) + "");
        return (int) totleCpu;
    }

    public static int readCpuUsage() {
        int result;
        long start = System.currentTimeMillis();
        try {
            RandomAccessFile reader = new RandomAccessFile("/proc/stat", "r");
            String load = reader.readLine();
            String[] toks = load.split(" ");
            long idle1 = Long.parseLong(toks[5]);
            long cpu1 = Long.parseLong(toks[2]) + Long.parseLong(toks[3]) + Long.parseLong(toks[4]) + Long.parseLong(toks[6]) + Long.parseLong(toks[7]) + Long.parseLong(toks[8]);
            try {
                Thread.sleep(360L);
            } catch (Exception e) {
            }
            reader.seek(0L);
            String load2 = reader.readLine();
            reader.close();
            String[] toks2 = load2.split(" ");
            long idle2 = Long.parseLong(toks2[5]);
            long cpu2 = Long.parseLong(toks2[2]) + Long.parseLong(toks2[3]) + Long.parseLong(toks2[4]) + Long.parseLong(toks2[6]) + Long.parseLong(toks2[7]) + Long.parseLong(toks2[8]);
            long totalDiff = (cpu2 + idle2) - (cpu1 + idle1);
            if (totalDiff == 0) {
                result = 0;
            } else {
                result = (int) ((100 * (cpu2 - cpu1)) / totalDiff);
            }
            long end = System.currentTimeMillis();
            Log.i("test", "readCpuUsage() " + (end - start) + "   " + result + "%");
            return result;
        } catch (IOException ex) {
            ex.printStackTrace();
            return 0;
        }
    }

    public static boolean isLenovoApk(String pkgName) {
        if (Const.LENOVO_APKS == null || Const.LENOVO_APKS.equals("")) {
            return false;
        }
        boolean bool = Const.LENOVO_APKS.contains(pkgName);
        return bool;
    }

    public static void createShortCut(Context context, int iconResId, int appnameResId) {
        if (!hasShortcut(context)) {
            m569a(context, iconResId, appnameResId);
        }
    }

    public static void createShortCut(Context context, int iconResId, int appnameResId, boolean toast) {
        if (hasShortcut(context)) {
            Toast.makeText(context, context.getText(C0415R.string.setting_shortcut_exact), 0).show();
        } else {
            m569a(context, iconResId, appnameResId);
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m569a(Context context, int iconResId, int appnameResId) {
        Intent shortcutintent = new Intent("com.android.launcher.action.INSTALL_SHORTCUT");
        shortcutintent.putExtra("duplicate", false);
        shortcutintent.putExtra("android.intent.extra.shortcut.NAME", context.getString(appnameResId));
        Parcelable icon = Intent.ShortcutIconResource.fromContext(context.getApplicationContext(), iconResId);
        shortcutintent.putExtra("android.intent.extra.shortcut.ICON_RESOURCE", icon);
        shortcutintent.putExtra("android.intent.extra.shortcut.INTENT", new Intent(context.getApplicationContext(), (Class<?>) CleanAcitivty.class));
        context.sendBroadcast(shortcutintent);
    }

    public static boolean hasShortcut(Context context) {
        String uriStr;
        if (Build.VERSION.SDK_INT < 8) {
            uriStr = "content://com.android.launcher.settings/favorites?notify=true";
        } else {
            uriStr = "content://com.android.launcher2.settings/favorites?notify=true";
        }
        Uri CONTENT_URI = Uri.parse(uriStr);
        Cursor cursor = context.getContentResolver().query(CONTENT_URI, null, " iconPackage=? and iconResource=? ", new String[]{TrafficStatsService.PACKAGE_NAME, "com.lenovo.safecenter:drawable/onkey_shutcut_green"}, null);
        if (cursor == null || cursor.getCount() <= 0) {
            return false;
        }
        return true;
    }

    public static boolean getIsRoot() {
        if (!TrafficStatsService.nacServerIsExist()) {
            new Thread(new Runnable() { // from class: com.lenovo.performancecenter.coreui.util.Utils.2
                @Override // java.lang.Runnable
                public final void run() throws Throwable {
                    Process mProcess = null;
                    try {
                        try {
                            mProcess = Runtime.getRuntime().exec("su");
                            DataOutputStream mOutputStream = new DataOutputStream(mProcess.getOutputStream());
                            try {
                                mOutputStream.writeBytes("ls data\n");
                                mOutputStream.flush();
                                InputStream mInputStream = mProcess.getInputStream();
                                BufferedReader in = new BufferedReader(new InputStreamReader(mInputStream));
                                String line = in.readLine();
                                if (line != null) {
                                    String readStr = "denied" + line + "\n";
                                    boolean unused = Utils.f1613c = true;
                                    Log.i("ROOT", "retrie permission" + readStr);
                                }
                                mOutputStream.close();
                                mInputStream.close();
                                if (mProcess != null) {
                                    mProcess.destroy();
                                }
                            } catch (Exception e) {
                                e = e;
                                Log.i("ROOT", "" + e);
                                boolean unused2 = Utils.f1613c = false;
                                if (mProcess != null) {
                                    mProcess.destroy();
                                }
                            } catch (Throwable th) {
                                th = th;
                                if (mProcess != null) {
                                    mProcess.destroy();
                                }
                                throw th;
                            }
                        } catch (Throwable th2) {
                            th = th2;
                        }
                    } catch (Exception e2) {
                        e = e2;
                    }
                }
            }).start();
            if (!f1613c) {
                return false;
            }
        }
        return true;
    }
}
