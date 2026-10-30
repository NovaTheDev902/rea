package com.lenovo.safecenter.utils.update;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.os.StatFs;
import android.preference.PreferenceManager;
import android.util.Log;
import android.widget.Toast;
import com.lenovo.lps.sus.EventType;
import com.lenovo.lps.sus.SUS;
import com.lenovo.lps.sus.SUSListener;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.VersionUpdateDIalogActivity;
import com.lenovo.safecenter.support.CMDHelper;
import java.io.File;
import java.net.URLDecoder;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public class LeSafeUpdate {
    public static final int SUS_ERROR_CODE_DOWNLOAD = 3;
    public static final int SUS_ERROR_CODE_INSUFFICIENTSTORAGESPACE = 4;
    public static final int SUS_ERROR_CODE_NETWORKUNAVAILABLE = 1;
    public static final int SUS_ERROR_CODE_PENDING = 2;

    /* JADX INFO: renamed from: a */
    int f5842a;

    /* JADX INFO: renamed from: b */
    boolean f5843b;

    /* JADX INFO: renamed from: c */
    boolean f5844c;

    /* JADX INFO: renamed from: e */
    private Context f5846e;

    /* JADX INFO: renamed from: f */
    private String f5847f;

    /* JADX INFO: renamed from: g */
    private String f5848g;

    /* JADX INFO: renamed from: i */
    private PackageManager f5850i;

    /* JADX INFO: renamed from: j */
    private SUSListener f5851j;

    /* JADX INFO: renamed from: k */
    private SharedPreferences f5852k;

    /* JADX INFO: renamed from: l */
    private boolean f5853l;

    /* JADX INFO: renamed from: m */
    private LeSafeUpdateListenser f5854m;

    /* JADX INFO: renamed from: h */
    private String f5849h = null;

    /* JADX INFO: renamed from: d */
    boolean f5845d = false;

    /* JADX INFO: renamed from: n */
    private Handler f5855n = new Handler() { // from class: com.lenovo.safecenter.utils.update.LeSafeUpdate.3
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    Intent intent = new Intent("android.intent.action.VIEW");
                    intent.setDataAndType(Uri.parse("file://" + ((String) msg.obj)), "application/vnd.android.package-archive");
                    intent.setFlags(268435456);
                    LeSafeUpdate.this.f5846e.startActivity(intent);
                    break;
                case 2:
                    LeSafeUpdateInfo lsui = (LeSafeUpdateInfo) msg.obj;
                    SUS.downloadApp(LeSafeUpdate.this.f5846e, lsui.getUrl(), lsui.getApkName(), Long.valueOf(lsui.getFileSize()));
                    break;
                case 3:
                    LeSafeUpdate.m2473h(LeSafeUpdate.this);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: o */
    private BroadcastReceiver f5856o = new BroadcastReceiver() { // from class: com.lenovo.safecenter.utils.update.LeSafeUpdate.4
        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if ("android.intent.action.PACKAGE_ADDED".equals(action)) {
                String urlPkgName = intent.getDataString();
                String[] stringArray = urlPkgName.split(C0092c.f1283N);
                String pkgName = stringArray[1];
                if (pkgName.equals(LeSafeUpdate.this.f5847f)) {
                    LeSafeUpdate.this.f5854m.onInstallComplete(true);
                    File f = new File(context.getCacheDir() + CookieSpec.PATH_DELIM + LeSafeUpdate.this.f5849h);
                    if (f.exists()) {
                        f.delete();
                    }
                    context.unregisterReceiver(LeSafeUpdate.this.f5856o);
                }
            }
        }
    };

    public interface LeSafeUpdateListenser {
        void onDownLoadComplete(String str);

        void onDownLoadException(int i);

        void onInstallComplete(boolean z);

        void onQueryResp(String str, LeSafeUpdateInfo leSafeUpdateInfo);
    }

    /* JADX INFO: renamed from: h */
    static /* synthetic */ void m2473h(LeSafeUpdate x0) {
        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction("android.intent.action.PACKAGE_ADDED");
        intentFilter.addDataScheme("package");
        x0.f5846e.registerReceiver(x0.f5856o, intentFilter);
    }

    public LeSafeUpdate(Context context, String pkgName, int versionCode, String channelKey, boolean moveToSystem, boolean promptDisable, boolean sdkPromptDisable, LeSafeUpdateListenser lsul) {
        this.f5847f = null;
        this.f5848g = null;
        this.f5853l = false;
        this.f5843b = false;
        this.f5844c = false;
        this.f5846e = context;
        this.f5850i = this.f5846e.getPackageManager();
        this.f5842a = versionCode;
        this.f5848g = channelKey;
        this.f5847f = pkgName;
        this.f5852k = PreferenceManager.getDefaultSharedPreferences(context);
        this.f5853l = moveToSystem;
        this.f5854m = lsul == null ? new LeSafeUpdateListenser() { // from class: com.lenovo.safecenter.utils.update.LeSafeUpdate.1
            @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
            public final void onQueryResp(String resultion, LeSafeUpdateInfo lfui) {
            }

            @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
            public final void onInstallComplete(boolean succeed) {
            }

            @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
            public final void onDownLoadException(int errorCode) {
            }

            @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
            public final void onDownLoadComplete(String path) {
            }
        } : lsul;
        this.f5843b = promptDisable;
        this.f5844c = sdkPromptDisable;
    }

    public void upDate(boolean downloadNow) {
        upDate(downloadNow, true);
    }

    public void upDate(final boolean downloadNow, final boolean installNow) {
        if (SUS.isVersionUpdateStarted() || this.f5845d) {
            m2465a(C0415R.string.SUS_NOTIFICATION_UPDATINGPROMPT);
            this.f5854m.onDownLoadException(2);
            return;
        }
        SUS.setAllPromptDisableFlag(this.f5843b);
        if (this.f5851j == null) {
            this.f5851j = new SUSListener() { // from class: com.lenovo.safecenter.utils.update.LeSafeUpdate.2
                /* JADX WARN: Type inference failed for: r2v35, types: [com.lenovo.safecenter.utils.update.LeSafeUpdate$2$1] */
                @Override // com.lenovo.lps.sus.SUSListener
                public final void onUpdateNotification(EventType eventType, final String param) {
                    switch (C10555.f5865a[eventType.ordinal()]) {
                        case 1:
                            if (param != null && param.length() > 0) {
                                try {
                                    JSONObject jsonObject = new JSONObject(param);
                                    try {
                                        String resultion = jsonObject.getString(C0092c.f1281L);
                                        if (C0092c.f1288S.equals(resultion)) {
                                            String jsonObjectStr = jsonObject.getString(C0092c.f1271B);
                                            String ChannelKey = (jsonObjectStr == null || jsonObjectStr.length() <= 0) ? null : URLDecoder.decode(jsonObjectStr);
                                            String jsonObjectStr2 = jsonObject.getString(C0092c.f1272C);
                                            String VerCode = (jsonObjectStr2 == null || jsonObjectStr2.length() <= 0) ? null : URLDecoder.decode(jsonObjectStr2);
                                            String jsonObjectStr3 = jsonObject.getString(C0092c.f1273D);
                                            String VerName = (jsonObjectStr3 == null || jsonObjectStr3.length() <= 0) ? null : URLDecoder.decode(jsonObjectStr3);
                                            String jsonObjectStr4 = jsonObject.getString(C0092c.f1274E);
                                            String DownloadURL = (jsonObjectStr4 == null || jsonObjectStr4.length() <= 0) ? null : URLDecoder.decode(jsonObjectStr4);
                                            String jsonObjectStr5 = jsonObject.getString(C0092c.f1276G);
                                            String Size = (jsonObjectStr5 == null || jsonObjectStr5.length() <= 0) ? null : URLDecoder.decode(jsonObjectStr5);
                                            String jsonObjectStr6 = jsonObject.getString(C0092c.f1277H);
                                            String UpdateDesc = (jsonObjectStr6 == null || jsonObjectStr6.length() <= 0) ? null : URLDecoder.decode(jsonObjectStr6);
                                            String jsonObjectStr7 = jsonObject.getString(C0092c.f1278I);
                                            LeSafeUpdate.this.f5849h = (jsonObjectStr7 == null || jsonObjectStr7.length() <= 0) ? null : URLDecoder.decode(jsonObjectStr7);
                                            LeSafeUpdate.this.f5854m.onQueryResp(C0092c.f1288S, new LeSafeUpdateInfo(ChannelKey, VerName, VerCode, UpdateDesc, DownloadURL, LeSafeUpdate.this.f5849h, Long.valueOf(Size).longValue()));
                                            if (downloadNow) {
                                                LeSafeUpdate.this.f5855n.sendMessage(LeSafeUpdate.this.f5855n.obtainMessage(2, new LeSafeUpdateInfo(ChannelKey, VerName, VerCode, UpdateDesc, DownloadURL, LeSafeUpdate.this.f5849h, Long.valueOf(Size).longValue())));
                                            } else {
                                                Intent i = new Intent(LeSafeUpdate.this.f5846e, (Class<?>) VersionUpdateDIalogActivity.class);
                                                i.putExtra("versionname", VerName);
                                                i.putExtra("appinfo", UpdateDesc);
                                                i.putExtra("url", DownloadURL);
                                                i.putExtra("apkname", LeSafeUpdate.this.f5849h);
                                                i.putExtra("filesize", Long.valueOf(Size));
                                                i.addFlags(335544320);
                                                LeSafeUpdate.this.f5846e.startActivity(i);
                                            }
                                        } else if (C0092c.f1289T.equals(resultion)) {
                                            LeSafeUpdate.this.m2465a(C0415R.string.SUS_MSG_LATESTVERSION);
                                            LeSafeUpdate.this.f5854m.onQueryResp(C0092c.f1289T, null);
                                            Log.e("ydp", "QueryResp LATESTVERSION");
                                        } else if (C0092c.f1290U.equals(resultion)) {
                                            LeSafeUpdate.this.m2465a(C0415R.string.SUS_MSG_LATESTVERSION);
                                            LeSafeUpdate.this.f5854m.onQueryResp(C0092c.f1290U, null);
                                            Log.e("ydp", "QueryResp NOTFOUND");
                                        } else if (C0092c.f1291V.equals(resultion)) {
                                            LeSafeUpdate.this.m2465a(C0415R.string.SUS_MSG_UPDATE_EXCEPTION);
                                            Log.e("ydp", "QueryResp EXCEPTION");
                                            LeSafeUpdate.this.f5854m.onQueryResp(C0092c.f1291V, null);
                                        }
                                    } catch (JSONException e) {
                                        e = e;
                                        LeSafeUpdate.this.f5854m.onQueryResp("JSONException", null);
                                        LeSafeUpdate.this.m2465a(C0415R.string.SUS_MSG_UPDATE_EXCEPTION);
                                        Log.e("ydp", "SUS_QUERY_RESP param:" + param);
                                        Log.e("ydp", "updateversion error start-----");
                                        e.printStackTrace();
                                        Log.e("ydp", "updateversion error end-----");
                                        return;
                                    }
                                } catch (JSONException e2) {
                                    e = e2;
                                }
                                break;
                            }
                            break;
                        case 2:
                            LeSafeUpdate.this.f5845d = true;
                            LeSafeUpdate.this.f5854m.onDownLoadComplete(param);
                            Log.e("ydp", "DOWNLOADCOMPLETE:" + param);
                            String command = "chmod 777 /data/data/com.lenovo.safecenter/cache/" + LeSafeUpdate.this.f5849h;
                            LeSafeUpdate.this.f5852k.edit().putString("updateFileName", LeSafeUpdate.this.f5852k.getString("updateFileName", "") + LeSafeUpdate.this.f5849h + ",").commit();
                            Runtime runtime = Runtime.getRuntime();
                            try {
                                runtime.exec(command);
                                runtime.exec("chmod 777 /data/data/com.lenovo.safecenter/cache");
                                if (installNow) {
                                    LeSafeUpdate.this.f5855n.sendMessage(LeSafeUpdate.this.f5855n.obtainMessage(3));
                                    new Thread() { // from class: com.lenovo.safecenter.utils.update.LeSafeUpdate.2.1
                                        @Override // java.lang.Thread, java.lang.Runnable
                                        public final void run() {
                                            if (LeSafeUpdate.this.canExecute("/data/data/com.lenovo.safecenter/cache/" + LeSafeUpdate.this.f5849h)) {
                                                if (LeSafeUpdate.this.f5853l) {
                                                    if (!CMDHelper.copyApk(LeSafeUpdate.this.f5846e, "/data/data/com.lenovo.safecenter/cache/" + LeSafeUpdate.this.f5849h, "/system/app/" + LeSafeUpdate.this.f5849h, LeSafeUpdate.this.f5847f)) {
                                                        LeSafeUpdate.this.f5845d = false;
                                                        LeSafeUpdate.this.f5855n.sendMessage(LeSafeUpdate.this.f5855n.obtainMessage(1, param));
                                                        return;
                                                    }
                                                    return;
                                                }
                                                if (!CMDHelper.installAPK(LeSafeUpdate.this.f5846e, "/data/data/com.lenovo.safecenter/cache/" + LeSafeUpdate.this.f5849h, LeSafeUpdate.this.f5847f)) {
                                                    LeSafeUpdate.this.f5845d = false;
                                                    LeSafeUpdate.this.f5855n.sendMessage(LeSafeUpdate.this.f5855n.obtainMessage(1, param));
                                                }
                                            }
                                        }
                                    }.start();
                                }
                                LeSafeUpdate.this.m2465a(C0415R.string.SUS_MSG_DOWNLOADCOMPLETE);
                                SUS.finish();
                            } catch (Exception e3) {
                                e3.printStackTrace();
                                return;
                            }
                            break;
                        case 3:
                            LeSafeUpdate.this.f5854m.onDownLoadException(2);
                            Log.e("ydp", "SUS_WARNING_PENDING");
                            break;
                        case 4:
                            SUS.setSDKPromptDisableFlag(true);
                            LeSafeUpdate.this.f5854m.onDownLoadException(1);
                            Log.e("ydp", "SUS_FAIL_NETWORKUNAVAILABLE");
                            LeSafeUpdate.this.m2465a(C0415R.string.SUS_MSG_FAIL_NETWORKUNAVAILABLE);
                            break;
                        case 5:
                            LeSafeUpdate.this.f5854m.onDownLoadException(3);
                            Log.e("ydp", "SUS_FAIL_DOWNLOAD_EXCEPTION");
                            LeSafeUpdate.this.m2465a(C0415R.string.SUS_MSG_UPDATE_EXCEPTION);
                            break;
                        case 6:
                            Log.e("ydp", "SUS_FAIL_NOWLANCONNECTED");
                            break;
                        case 7:
                            Log.e("ydp", "SUS_FAIL_INSUFFICIENTSTORAGESPACE");
                            LeSafeUpdate.this.f5854m.onDownLoadException(4);
                            break;
                        case 8:
                            SUS.setSDKPromptDisableFlag(true);
                            Log.e("ydp", "SUS_DOWNLOADSTART");
                            break;
                    }
                }
            };
        }
        SUS.setSUSListener(this.f5851j);
        File path = Environment.getDataDirectory();
        StatFs stat = new StatFs(path.getPath());
        long blockSize = stat.getBlockSize();
        long availableBlocks = stat.getAvailableBlocks();
        long availableSize = availableBlocks * blockSize;
        SUS.setDownloadPath(this.f5846e.getCacheDir().getPath(), availableSize, 1000L);
        SUS.setSDKPromptDisableFlag(true);
        SUS.AsyncQueryLatestVersionByPackageName(this.f5846e, this.f5847f, this.f5842a, this.f5848g);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.utils.update.LeSafeUpdate$5 */
    static /* synthetic */ class C10555 {

        /* JADX INFO: renamed from: a */
        static final /* synthetic */ int[] f5865a = new int[EventType.valuesCustom().length];

        static {
            try {
                f5865a[EventType.SUS_QUERY_RESP.ordinal()] = 1;
            } catch (NoSuchFieldError e) {
            }
            try {
                f5865a[EventType.SUS_DOWNLOADCOMPLETE.ordinal()] = 2;
            } catch (NoSuchFieldError e2) {
            }
            try {
                f5865a[EventType.SUS_WARNING_PENDING.ordinal()] = 3;
            } catch (NoSuchFieldError e3) {
            }
            try {
                f5865a[EventType.SUS_FAIL_NETWORKUNAVAILABLE.ordinal()] = 4;
            } catch (NoSuchFieldError e4) {
            }
            try {
                f5865a[EventType.SUS_FAIL_DOWNLOAD_EXCEPTION.ordinal()] = 5;
            } catch (NoSuchFieldError e5) {
            }
            try {
                f5865a[EventType.SUS_FAIL_NOWLANCONNECTED.ordinal()] = 6;
            } catch (NoSuchFieldError e6) {
            }
            try {
                f5865a[EventType.SUS_FAIL_INSUFFICIENTSTORAGESPACE.ordinal()] = 7;
            } catch (NoSuchFieldError e7) {
            }
            try {
                f5865a[EventType.SUS_DOWNLOADSTART.ordinal()] = 8;
            } catch (NoSuchFieldError e8) {
            }
        }
    }

    public boolean canExecute(String path) {
        File file = new File(path);
        for (int i = 0; i < 3; i++) {
            try {
                if (file.canExecute()) {
                    Log.i("ydp", "canExecute()...true");
                    return true;
                }
                Log.i("ydp", "canExecute()...false");
                try {
                    Thread.sleep(1500L);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            } catch (NoSuchMethodError e2) {
                try {
                    Thread.sleep(C0092c.f1328ap);
                    return true;
                } catch (InterruptedException e3) {
                    e2.printStackTrace();
                    return true;
                }
            }
        }
        return false;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m2465a(int text) {
        if (!this.f5843b && !this.f5844c) {
            Toast.makeText(this.f5846e, text, 0).show();
        }
    }
}
