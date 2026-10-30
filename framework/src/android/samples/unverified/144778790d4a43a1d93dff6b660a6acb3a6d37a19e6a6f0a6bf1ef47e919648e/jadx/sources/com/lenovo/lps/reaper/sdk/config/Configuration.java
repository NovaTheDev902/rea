package com.lenovo.lps.reaper.sdk.config;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.Build;
import android.provider.Settings;
import android.telephony.TelephonyManager;
import android.util.DisplayMetrics;
import android.view.WindowManager;
import com.lenovo.lps.reaper.sdk.AnalyticsTracker;
import com.lenovo.lps.reaper.sdk.storage.ServerConfigStorage;
import com.lenovo.lps.reaper.sdk.util.AnalyticsTrackerUtils;
import com.lenovo.lps.reaper.sdk.util.Constants;
import com.lenovo.lps.reaper.sdk.util.PlusUtil;
import com.lenovo.lps.reaper.sdk.util.TLog;
import com.lenovo.lps.sus.p008c.C0092c;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Date;
import java.util.Locale;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class Configuration {

    /* JADX INFO: renamed from: f */
    private static String f1127f;

    /* JADX INFO: renamed from: g */
    private static String f1128g;

    /* JADX INFO: renamed from: h */
    private static String f1129h;

    /* JADX INFO: renamed from: i */
    private static final Locale f1130i = Locale.getDefault();

    /* JADX INFO: renamed from: j */
    private static String f1131j = "com.lenovo.lps.reaper.sdk.AnalyticsTrackerBuilder";
    protected static int reaperServerPort;
    protected static String reaperServerhost;

    /* JADX INFO: renamed from: a */
    private final Context f1132a;
    protected String applicationToken;

    /* JADX INFO: renamed from: b */
    private String f1133b;

    /* JADX INFO: renamed from: c */
    private String f1134c;
    protected String channel;
    protected String customReaperServer;

    /* JADX INFO: renamed from: d */
    private String f1135d;

    /* JADX INFO: renamed from: e */
    private String f1136e;
    protected boolean isSupportMultiRequest = true;

    /* JADX INFO: renamed from: k */
    private boolean f1137k;
    protected String userAgent;
    protected int versionCode;
    protected String versionName;

    public Configuration(Context context) {
        this.f1132a = context;
        DisplayMetrics displayMetrics = new DisplayMetrics();
        ((WindowManager) this.f1132a.getSystemService("window")).getDefaultDisplay().getMetrics(displayMetrics);
        this.f1133b = String.valueOf(displayMetrics.widthPixels) + "x" + String.valueOf(displayMetrics.heightPixels);
        TLog.m243i("Configuration", "displayScreen: " + this.f1133b);
    }

    public void initialize() throws Throwable {
        try {
            PackageManager packageManager = this.f1132a.getPackageManager();
            ApplicationInfo applicationInfo = packageManager.getApplicationInfo(this.f1132a.getPackageName(), 128);
            PackageInfo packageInfo = packageManager.getPackageInfo(this.f1132a.getPackageName(), 0);
            this.versionName = packageInfo.versionName;
            this.versionCode = packageInfo.versionCode;
            this.applicationToken = applicationInfo.metaData.getString(C0092c.f1333au);
            this.customReaperServer = applicationInfo.metaData.getString("lenovo:customReaperServer");
            Object obj = applicationInfo.metaData.get("lenovo:channel");
            this.f1137k = applicationInfo.metaData.getBoolean("lenovo:forceUpdateConfig");
            TLog.setTestMode(applicationInfo.metaData.getBoolean("lenovo:isTestMode"));
            if (!this.applicationToken.matches("^[A-Za-z0-9]+$")) {
                TLog.m241e("Configuration", "ApplicationToken should be Number and Character, another char will be Delete.");
                this.applicationToken = this.applicationToken.replaceAll("[^A-Za-z0-9]", "");
                TLog.m241e("Configuration", "New Token is " + this.applicationToken);
            }
            if (this.customReaperServer != null && this.customReaperServer.length() > 0) {
                initReportAndConfigurationUrl(this.customReaperServer);
            }
            if (obj == null) {
                this.channel = Constants.CHANNEL_DEFAULT;
            } else {
                this.channel = AnalyticsTrackerUtils.encode(String.valueOf(obj));
            }
            if (TLog.isTestMode()) {
                TLog.m243i("Configuration", "versionName = " + this.versionName);
                TLog.m243i("Configuration", "versionCode = " + this.versionCode);
                TLog.m243i("Configuration", "applicationToken = " + this.applicationToken);
                TLog.m243i("Configuration", "customReaperServer = " + this.customReaperServer);
                TLog.m243i("Configuration", "channel = " + this.channel);
                TLog.m243i("Configuration", "isTestMode = " + TLog.isTestMode());
            }
        } catch (Exception e) {
            TLog.m241e("Configuration", "parseApplicationInfo. " + e.getMessage());
        }
        m213a();
        m214b();
    }

    public void initialize(String applicationToken, int reportIntervalInSeconds) throws Throwable {
        this.applicationToken = applicationToken;
        m213a();
        m214b();
    }

    /* JADX INFO: renamed from: a */
    private void m213a() {
        PlusUtil.DeviceIdentify.initialDeviceIdentify(this.f1132a);
        try {
            TelephonyManager telephonyManager = (TelephonyManager) this.f1132a.getSystemService("phone");
            this.f1134c = telephonyManager.getDeviceId();
            this.f1136e = telephonyManager.getLine1Number();
            if (this.f1136e == null) {
                this.f1136e = "0";
            }
        } catch (Exception e) {
            this.f1134c = "";
            TLog.m241e("Configuration", e.getMessage());
        }
        try {
            this.f1135d = Settings.Secure.getString(this.f1132a.getContentResolver(), "android_id");
            TLog.m243i("Configuration", "androidId: " + this.f1135d);
        } catch (Exception e2) {
            this.f1135d = "";
            TLog.m241e("Configuration", "exception when get android id. " + e2.getMessage());
        }
    }

    /* JADX INFO: renamed from: b */
    private void m214b() throws Throwable {
        if (this.versionName == null) {
            this.versionName = AnalyticsTracker.getInstance().getVersionName();
        }
        if (this.versionCode == 0) {
            this.versionCode = AnalyticsTracker.getInstance().getVersionCode();
        }
        String leOSVersion = m211a("operating");
        Object[] objArr = new Object[9];
        objArr[0] = this.versionName;
        objArr[1] = Integer.valueOf(this.versionCode);
        objArr[2] = AnalyticsTrackerUtils.replaceInvalidCharacter(Build.VERSION.RELEASE);
        objArr[3] = f1130i.getLanguage() == null ? "en" : f1130i.getLanguage().toLowerCase();
        objArr[4] = f1130i.getCountry() == null ? "" : f1130i.getCountry().toLowerCase();
        objArr[5] = AnalyticsTrackerUtils.replaceInvalidCharacter(Build.MODEL);
        objArr[6] = Build.ID;
        objArr[7] = leOSVersion == null ? "" : AnalyticsTrackerUtils.encode(leOSVersion);
        objArr[8] = AnalyticsTrackerUtils.replaceInvalidCharacter(Build.MANUFACTURER);
        this.userAgent = String.format("%s/%s (Linux; U; Android %s; %s-%s; %s; Build/%s; %s; %s)", objArr);
        TLog.m243i("Configuration", "userAgent = " + this.userAgent);
    }

    public void initReportAndConfigurationUrl(String reaperServerUrl) {
        String mReaperServerUrl = reaperServerUrl;
        if (mReaperServerUrl.endsWith(CookieSpec.PATH_DELIM)) {
            mReaperServerUrl = mReaperServerUrl.substring(0, mReaperServerUrl.length() - 1);
        }
        try {
            URL serverUrl = new URL(mReaperServerUrl);
            f1127f = mReaperServerUrl + "/reaper/server/post";
            f1128g = mReaperServerUrl + "/reaper/server/report";
            f1129h = mReaperServerUrl + "/reaper/server/config";
            reaperServerhost = serverUrl.getHost();
            reaperServerPort = serverUrl.getPort() == -1 ? 80 : serverUrl.getPort();
            if (TLog.isTestMode()) {
                TLog.m243i("Configuration", "postUrl: " + f1127f.toString());
                TLog.m243i("Configuration", "reportUrl: " + f1128g.toString());
                TLog.m243i("Configuration", "configUrl: " + f1129h.toString());
            }
        } catch (MalformedURLException e) {
            TLog.m241e("Configuration", "initReportAndConfigurationUrl. " + e.getMessage());
        }
    }

    /* JADX INFO: renamed from: a */
    private static String m211a(String key) throws Throwable {
        String str;
        String strSubstring = null;
        BufferedReader buffReader = null;
        FileReader fileReader = null;
        if (new File("/etc/version.conf").exists()) {
            try {
                try {
                    FileReader fileReader2 = new FileReader("/etc/version.conf");
                    try {
                        BufferedReader buffReader2 = new BufferedReader(fileReader2, 1024);
                        do {
                            try {
                                str = buffReader2.readLine();
                                if (str == null) {
                                    try {
                                        fileReader2.close();
                                    } catch (IOException e) {
                                    }
                                    try {
                                        buffReader2.close();
                                    } catch (Exception e2) {
                                    }
                                }
                            } catch (IOException e3) {
                                fileReader = fileReader2;
                                buffReader = buffReader2;
                                TLog.m241e("Configuration", String.format("IO Exception when getting kernel version of %s", key));
                                if (fileReader != null) {
                                    try {
                                        fileReader.close();
                                    } catch (IOException e4) {
                                    }
                                }
                                if (buffReader != null) {
                                    try {
                                        buffReader.close();
                                    } catch (Exception e5) {
                                    }
                                }
                            } catch (Throwable th) {
                                th = th;
                                fileReader = fileReader2;
                                buffReader = buffReader2;
                                if (fileReader != null) {
                                    try {
                                        fileReader.close();
                                    } catch (IOException e6) {
                                    }
                                }
                                if (buffReader == null) {
                                    throw th;
                                }
                                try {
                                    buffReader.close();
                                    throw th;
                                } catch (Exception e7) {
                                    throw th;
                                }
                            }
                        } while (str.indexOf(key) == -1);
                        strSubstring = str.substring(str.indexOf(44) + 1, str.length());
                        try {
                            fileReader2.close();
                        } catch (IOException e8) {
                        }
                        try {
                            buffReader2.close();
                        } catch (Exception e9) {
                        }
                    } catch (IOException e10) {
                        fileReader = fileReader2;
                    } catch (Throwable th2) {
                        th = th2;
                        fileReader = fileReader2;
                    }
                } catch (IOException e11) {
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } else {
            TLog.m245w("Configuration", "leos version file not exists!");
        }
        return strSubstring;
    }

    public static Class<?> getAnalyticsTrackerBuilderClass() {
        try {
            Class<?> analyticsTrackerBuilderClass = Class.forName(f1131j);
            return analyticsTrackerBuilderClass;
        } catch (ClassNotFoundException e) {
            TLog.m241e("Configuration", "Could not find class define for class:" + f1131j);
            f1131j = "com.lenovo.lps.reaper.sdk.AnalyticsTrackerBuilder";
            try {
                Class<?> analyticsTrackerBuilderClass2 = Class.forName(f1131j);
                return analyticsTrackerBuilderClass2;
            } catch (ClassNotFoundException e2) {
                TLog.m241e("Configuration", "Could not find class define for class:" + f1131j);
                return null;
            }
        }
    }

    public boolean needReport(String category, String action) {
        if (category == null || action == null) {
            TLog.m245w("Configuration", "wrong parameter.");
            return false;
        }
        String actionTmp = action;
        if (Constants.Event.EVENT_TYPE_VIEW.equals(category) && action.startsWith(CookieSpec.PATH_DELIM)) {
            actionTmp = action.substring(1);
        }
        return ServerConfigStorage.get(m212a(category, actionTmp), true);
    }

    public void clearExistPreference() {
        SharedPreferences sharedPreferences = this.f1132a.getSharedPreferences(Constants.SharedPreference.COMMON, 0);
        sharedPreferences.edit().clear().commit();
        ServerConfigStorage.clear();
    }

    public boolean updatePrefrence(String category, String[] actions, boolean[] values) {
        if (category == null || actions == null || values == null || actions.length != values.length) {
            TLog.m245w("Configuration", "wrong parameter.");
            return false;
        }
        SharedPreferences sharedPreferences = this.f1132a.getSharedPreferences(Constants.SharedPreference.COMMON, 0);
        SharedPreferences.Editor editor = sharedPreferences.edit();
        int length = values.length;
        for (int i = 0; i < length; i++) {
            String key = m212a(category, actions[i]);
            editor.putBoolean(key, values[i]);
            ServerConfigStorage.put(key, values[i]);
        }
        return editor.commit();
    }

    public boolean isCollectData() {
        if (!Constants.LEOS_APP_TOKEN.equals(this.applicationToken)) {
            return true;
        }
        String dataCollection = Settings.System.getString(this.f1132a.getContentResolver(), "data_collection");
        TLog.m243i("Configuration", "dataCollection: " + dataCollection);
        return dataCollection == null || !"0".equals(dataCollection);
    }

    public static void setAnalyticsTrackerBuilderClass(String clazz) {
        f1131j = clazz;
    }

    public String getCountry() {
        return f1130i.getCountry();
    }

    public String getLanguage() {
        return f1130i.getLanguage();
    }

    public String getDisplayScreen() {
        return this.f1133b;
    }

    public String getDeviceId() {
        return this.f1134c;
    }

    public String getPhoneNumber() {
        return this.f1136e;
    }

    public String getAndroidId() {
        return this.f1135d;
    }

    public String getApplicationToken() {
        return this.applicationToken;
    }

    public String getCustomReaperServer() {
        return this.customReaperServer;
    }

    public String getChannel() {
        return this.channel;
    }

    public String getUserAgent() {
        return this.userAgent;
    }

    public String getDeviceInfo() {
        return String.format("&sv=%s&ds=%s&aid=%s&dit=%s&di=%s&net=%d", Constants.SDK_VERSION, this.f1133b, this.f1135d, PlusUtil.DeviceIdentify.getDeviceType(), PlusUtil.DeviceIdentify.getDeviceID(), Integer.valueOf(PlusUtil.NetworkStatus.getNetworkStatus()));
    }

    public String getReportWithCompressUrl() {
        return f1127f;
    }

    public String getReportUrl() {
        return f1128g;
    }

    public String getServerConfigUrl() {
        return f1129h;
    }

    public String getReaperServerHost() {
        return reaperServerhost;
    }

    public int getReaperServerPort() {
        return reaperServerPort;
    }

    public int getMaxEventsPerRequest() {
        return 30;
    }

    public int getEventCacheSize() {
        return 50;
    }

    public boolean supportMultiRequest() {
        return this.isSupportMultiRequest;
    }

    public void setMultiRequestSupport(boolean flag) {
        this.isSupportMultiRequest = flag;
    }

    public int getMaxConnectionsPerTask() {
        return 5;
    }

    /* JADX INFO: renamed from: a */
    private static String m212a(String category, String action) {
        StringBuilder sb = new StringBuilder(64);
        return sb.append(Constants.SharedPreference.COMMON_KEY_PRE).append(".").append(category).append(".").append(action).toString();
    }

    public long getMaxCacheInterval() {
        return 5000L;
    }

    public void saveUpdateTimestamp() {
        SharedPreferences sharedPreferences = this.f1132a.getSharedPreferences(Constants.SharedPreference.CONFIGUPDATE, 0);
        boolean succ = sharedPreferences.edit().putLong(Constants.ServerConfig.UpdateStrategy.CATEGORY_UPDATE, System.currentTimeMillis()).commit();
        ServerConfigStorage.setTimestampMills(System.currentTimeMillis());
        if (succ && TLog.isTestMode()) {
            TLog.m240d("Configuration", "Configuration Timestamp Has Saved: " + new Date(System.currentTimeMillis()).toString());
        } else {
            TLog.m245w("Configuration", "Configuration Timestamp Save Failed.");
        }
    }

    public boolean checkTimestamp() {
        if (this.f1137k) {
            return true;
        }
        long timestampMills = ServerConfigStorage.getTimestampMills();
        long interval = (((System.currentTimeMillis() - timestampMills) / 1000) / 60) / 60;
        return 0 > interval || interval >= ServerConfigStorage.UpdateConfigStrategy.getUpdateIntervalHour();
    }

    public void saveServerUrlToFile(String url) {
        SharedPreferences sharedPreferences = this.f1132a.getSharedPreferences(Constants.SharedPreference.SERVER_URL, 0);
        boolean succ = sharedPreferences.edit().putString(Constants.SharedPreference.SERVER_URL_KEY, url).commit();
        if (succ && TLog.isTestMode()) {
            TLog.m240d("Configuration", "ServerUrl Has Saved: " + url);
        } else {
            TLog.m245w("Configuration", "ServerUrl Save Failed.");
        }
    }

    public String getServerUrlFromFile() {
        SharedPreferences sharedPreferences = this.f1132a.getSharedPreferences(Constants.SharedPreference.SERVER_URL, 0);
        return sharedPreferences.getString(Constants.SharedPreference.SERVER_URL_KEY, null);
    }
}
