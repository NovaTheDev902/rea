package com.tendcloud.tenddata;

import android.app.ActivityManager;
import android.app.PendingIntent;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.location.Location;
import android.location.LocationManager;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Proxy;
import android.net.Uri;
import android.net.wifi.ScanResult;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Environment;
import android.os.StatFs;
import android.preference.PreferenceManager;
import android.telephony.CellLocation;
import android.telephony.TelephonyManager;
import android.telephony.cdma.CdmaCellLocation;
import android.telephony.gsm.GsmCellLocation;
import android.util.DisplayMetrics;
import android.view.WindowManager;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.net.Socket;
import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;
import java.util.UUID;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.apache.http.HttpHost;

/* JADX INFO: renamed from: com.tendcloud.tenddata.u */
/* JADX INFO: loaded from: classes.dex */
final class C0089u {

    /* JADX INFO: renamed from: a */
    public static Context f176a = null;

    /* JADX INFO: renamed from: c */
    private static final String f178c = "pref.deviceid.key";

    /* JADX INFO: renamed from: d */
    private static TelephonyManager f179d = null;

    /* JADX INFO: renamed from: e */
    private static final String f180e = "UTF-8";

    /* JADX INFO: renamed from: f */
    private static final String f181f = "00:00:00:00:00:00";

    /* JADX INFO: renamed from: h */
    private static String f183h;

    /* JADX INFO: renamed from: g */
    private static final Pattern f182g = Pattern.compile("^([0-9A-F]{2}:){5}([0-9A-F]{2})$");

    /* JADX INFO: renamed from: b */
    static String f177b = null;

    C0089u() {
    }

    /* JADX INFO: renamed from: A */
    static String m157A() {
        return Locale.getDefault().getCountry();
    }

    /* JADX INFO: renamed from: B */
    static String m158B() {
        return Locale.getDefault().getLanguage();
    }

    /* JADX INFO: renamed from: C */
    static String m159C() {
        DisplayMetrics displayMetrics = f176a.getResources().getDisplayMetrics();
        return displayMetrics != null ? displayMetrics.widthPixels + "*" + displayMetrics.heightPixels + "*" + displayMetrics.density : "";
    }

    /* JADX INFO: renamed from: D */
    static String m160D() {
        String[] strArr = {"UNKNOWN", "GPRS", "EDGE", "UMTS", C0090v.f185b, "EVDO_0", "EVDO_A", "1xRTT", "HSDPA", "HSUPA", "HSPA", "IDEN", "EVDO_B", "LTE", "EHRPD", "HSPAP"};
        if (!m178a("android.permission.READ_PHONE_STATE")) {
            return "";
        }
        m166J();
        int networkType = f179d.getNetworkType();
        return (networkType < 0 || networkType >= strArr.length) ? strArr[0] : strArr[networkType];
    }

    /* JADX INFO: renamed from: E */
    static C0081m m161E() {
        C0081m c0081m = new C0081m();
        String[] strArrM173Q = m173Q();
        try {
            c0081m.f125a = strArrM173Q[0];
            c0081m.f126b = Integer.valueOf(strArrM173Q[1]).intValue();
            c0081m.f128d = strArrM173Q[2];
            c0081m.f127c = Float.valueOf(strArrM173Q[3]).floatValue();
        } catch (Exception e) {
        }
        int[] iArrM162F = m162F();
        c0081m.f131g = iArrM162F[0];
        c0081m.f132h = iArrM162F[1];
        int[] iArrM163G = m163G();
        c0081m.f133i = iArrM163G[0];
        c0081m.f134j = iArrM163G[1];
        c0081m.f135k = iArrM163G[2];
        c0081m.f136l = iArrM163G[3];
        c0081m.f137m = m164H();
        DisplayMetrics displayMetrics = new DisplayMetrics();
        ((WindowManager) f176a.getSystemService("window")).getDefaultDisplay().getMetrics(displayMetrics);
        c0081m.f138n = displayMetrics.widthPixels / displayMetrics.xdpi;
        c0081m.f139o = displayMetrics.heightPixels / displayMetrics.ydpi;
        c0081m.f140p = displayMetrics.densityDpi;
        c0081m.f141q = Build.DISPLAY;
        c0081m.f142r = "unknown";
        try {
            c0081m.f142r = (String) Class.forName("android.os.SystemProperties").getDeclaredMethod("get", String.class).invoke(null, "gsm.version.baseband");
        } catch (Exception e2) {
        }
        String strM188f = m188f();
        if (strM188f != null) {
            c0081m.f143s = strM188f;
        }
        String strM192h = m192h();
        if (strM192h != null) {
            c0081m.f144t = strM192h;
        }
        m176a(c0081m);
        c0081m.f149y = m203o();
        c0081m.f123A = m200l();
        c0081m.f124B = m190g();
        return c0081m;
    }

    /* JADX INFO: renamed from: F */
    static int[] m162F() {
        int[] iArr = {0, 0};
        int[] iArr2 = new int[4];
        for (int i = 0; i < 4; i++) {
            iArr2[i] = 0;
        }
        try {
            FileReader fileReader = new FileReader("/proc/meminfo");
            BufferedReader bufferedReader = new BufferedReader(fileReader, 1024);
            for (int i2 = 0; i2 < 4; i2++) {
                try {
                    iArr2[i2] = m194i(bufferedReader.readLine());
                } catch (IOException e) {
                    try {
                        bufferedReader.close();
                        fileReader.close();
                    } catch (IOException e2) {
                    }
                } catch (Throwable th) {
                    try {
                        bufferedReader.close();
                        fileReader.close();
                    } catch (IOException e3) {
                    }
                    throw th;
                }
            }
            iArr[0] = iArr2[0];
            iArr[1] = iArr2[3] + iArr2[1] + iArr2[2];
            try {
                bufferedReader.close();
                fileReader.close();
            } catch (IOException e4) {
            }
        } catch (FileNotFoundException e5) {
        }
        return iArr;
    }

    /* JADX INFO: renamed from: G */
    static int[] m163G() {
        StatFs statFs = new StatFs(Environment.getDataDirectory().getAbsolutePath());
        int availableBlocks = statFs.getAvailableBlocks();
        StatFs statFs2 = new StatFs(Environment.getExternalStorageDirectory().getAbsolutePath());
        return new int[]{(statFs.getBlockCount() * (statFs.getBlockSize() / 512)) / 2, ((statFs.getBlockSize() / 512) * availableBlocks) / 2, (statFs2.getBlockCount() * (statFs2.getBlockSize() / 512)) / 2, ((statFs2.getBlockSize() / 512) * statFs2.getAvailableBlocks()) / 2};
    }

    /* JADX INFO: renamed from: H */
    static int m164H() {
        Matcher matcher = Pattern.compile("\\s*([0-9]+)").matcher(m197j("/sys/class/power_supply/battery/full_bat"));
        if (!matcher.find()) {
            return 0;
        }
        try {
            return Integer.valueOf(matcher.toMatchResult().group(0)).intValue();
        } catch (Exception e) {
            return 0;
        }
    }

    /* JADX INFO: renamed from: I */
    static String m165I() {
        if (f177b == null) {
            Sensor[] sensorArr = new Sensor[64];
            for (Sensor sensor : ((SensorManager) f176a.getSystemService("sensor")).getSensorList(-1)) {
                if (sensor.getType() < sensorArr.length && sensor.getType() >= 0) {
                    sensorArr[sensor.getType()] = sensor;
                }
            }
            StringBuffer stringBuffer = new StringBuffer();
            for (int i = 0; i < sensorArr.length; i++) {
                if (sensorArr[i] != null) {
                    stringBuffer.append(i).append('.').append(sensorArr[i].getVendor()).append('-').append(sensorArr[i].getName()).append('-').append(sensorArr[i].getVersion()).append('\n');
                }
            }
            f177b = String.valueOf(stringBuffer.toString().hashCode());
        }
        return f177b;
    }

    /* JADX INFO: renamed from: J */
    private static synchronized void m166J() {
        if (f179d == null) {
            f179d = (TelephonyManager) f176a.getSystemService("phone");
        }
    }

    /* JADX INFO: renamed from: K */
    private static String m167K() {
        String strM172P;
        String strM171O = m171O();
        String strM169M = m169M();
        String strM170N = m170N();
        String strM168L = m168L();
        String[] strArr = {strM171O, strM169M, strM170N, strM168L};
        int length = strArr.length;
        int i = 0;
        while (true) {
            if (i >= length) {
                strM172P = null;
                break;
            }
            strM172P = strArr[i];
            if (!m183c(strM172P)) {
                break;
            }
            i++;
        }
        if (m183c(strM172P)) {
            strM172P = m172P();
        }
        if (m183c(strM171O)) {
            m193h(strM172P);
        }
        if (m183c(strM169M)) {
            m189f(strM172P);
        }
        if (m183c(strM170N)) {
            m191g(strM172P);
        }
        if (m183c(strM168L)) {
            m187e(strM172P);
        }
        return strM172P;
    }

    /* JADX INFO: renamed from: L */
    private static String m168L() {
        if ("mounted".equals(Environment.getExternalStorageState())) {
            return m184d(Environment.getExternalStorageDirectory() + "/.tid" + m165I());
        }
        return null;
    }

    /* JADX INFO: renamed from: M */
    private static String m169M() {
        return m184d("/tmp/.tid");
    }

    /* JADX INFO: renamed from: N */
    private static String m170N() {
        return m184d("/var/.tid");
    }

    /* JADX INFO: renamed from: O */
    private static String m171O() {
        return PreferenceManager.getDefaultSharedPreferences(f176a).getString(f178c, null);
    }

    /* JADX INFO: renamed from: P */
    private static String m172P() {
        String strM192h = m192h();
        String str = "1";
        if (m183c(strM192h)) {
            strM192h = m188f();
            str = "0";
        }
        if (m183c(strM192h)) {
            strM192h = UUID.randomUUID().toString();
            str = "2";
        }
        return str + m179b(strM192h);
    }

    /* JADX INFO: renamed from: Q */
    private static String[] m173Q() {
        boolean z;
        String[] strArr = new String[4];
        for (int i = 0; i < 4; i++) {
            strArr[i] = "";
        }
        ArrayList arrayList = new ArrayList();
        try {
            FileReader fileReader = new FileReader("/proc/cpuinfo");
            BufferedReader bufferedReader = new BufferedReader(fileReader, 1024);
            while (true) {
                try {
                    String line = bufferedReader.readLine();
                    if (line != null) {
                        arrayList.add(line);
                    } else {
                        try {
                            break;
                        } catch (FileNotFoundException e) {
                            z = true;
                        } catch (IOException e2) {
                            z = true;
                        }
                    }
                } catch (IOException e3) {
                    try {
                        bufferedReader.close();
                        fileReader.close();
                        z = false;
                    } catch (IOException e4) {
                        z = false;
                    }
                } catch (Throwable th) {
                    try {
                        bufferedReader.close();
                        fileReader.close();
                    } catch (IOException e5) {
                    }
                    throw th;
                }
            }
            bufferedReader.close();
            fileReader.close();
            z = true;
        } catch (FileNotFoundException e6) {
            z = false;
        }
        String[] strArr2 = {"Processor\\s*:\\s*(.*)", "CPU\\s*variant\\s*:\\s*0x(.*)", "Hardware\\s*:\\s*(.*)"};
        if (z) {
            int size = arrayList.size();
            for (int i2 = 0; i2 < 3; i2++) {
                Pattern patternCompile = Pattern.compile(strArr2[i2]);
                for (int i3 = 0; i3 < size; i3++) {
                    Matcher matcher = patternCompile.matcher((String) arrayList.get(i3));
                    if (matcher.find()) {
                        strArr[i2] = matcher.toMatchResult().group(1);
                    }
                }
            }
        }
        strArr[3] = m197j("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq");
        return strArr;
    }

    /* JADX INFO: renamed from: a */
    private static String m174a(Cursor cursor, String str) {
        return cursor.getString(cursor.getColumnIndex(str));
    }

    /* JADX INFO: renamed from: a */
    static String m175a(String str, String str2) {
        String lowerCase = str.toLowerCase();
        if (lowerCase.startsWith("unknown") || lowerCase.startsWith("alps") || lowerCase.startsWith("android") || lowerCase.startsWith("sprd") || lowerCase.startsWith("spreadtrum") || lowerCase.startsWith("rockchip") || lowerCase.startsWith("wondermedia") || lowerCase.startsWith("mtk") || lowerCase.startsWith("mt65") || lowerCase.startsWith("nvidia") || lowerCase.startsWith("brcm") || lowerCase.startsWith("marvell") || str2.toLowerCase().contains(lowerCase)) {
            return null;
        }
        return str;
    }

    /* JADX INFO: renamed from: a */
    static void m176a(C0081m c0081m) {
        Cursor cursorQuery;
        Uri uri = Uri.parse("content://telephony/carriers/preferapn");
        if (f176a.checkCallingOrSelfUriPermission(uri, 1) == 0 && (cursorQuery = f176a.getContentResolver().query(uri, null, null, null, null)) != null && cursorQuery.moveToFirst()) {
            try {
                c0081m.f145u = m174a(cursorQuery, "apn");
                c0081m.f146v = m174a(cursorQuery, "mcc");
                c0081m.f147w = m174a(cursorQuery, "mnc");
                String strM174a = m174a(cursorQuery, "proxy");
                if (strM174a != null && !strM174a.trim().equals("")) {
                    c0081m.f148x = true;
                }
            } finally {
                cursorQuery.close();
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public static boolean m177a() {
        if (!m178a("android.permission.INTERNET")) {
            return false;
        }
        if (m178a("android.permission.ACCESS_NETWORK_STATE")) {
            NetworkInfo activeNetworkInfo = ((ConnectivityManager) f176a.getSystemService("connectivity")).getActiveNetworkInfo();
            return activeNetworkInfo != null && activeNetworkInfo.isConnected();
        }
        Socket socket = null;
        try {
            Socket socket2 = new Socket(" .               ", 80);
            if (socket2 != null) {
                try {
                    socket2.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return true;
        } catch (Exception e2) {
            if (0 == 0) {
                return false;
            }
            try {
                socket.close();
                return false;
            } catch (IOException e3) {
                e3.printStackTrace();
                return false;
            }
        } catch (Throwable th) {
            if (0 != 0) {
                try {
                    socket.close();
                } catch (IOException e4) {
                    e4.printStackTrace();
                }
            }
            throw th;
        }
    }

    /* JADX INFO: renamed from: a */
    static boolean m178a(String str) {
        return f176a.checkCallingOrSelfPermission(str) == 0;
    }

    /* JADX INFO: renamed from: b */
    static String m179b(String str) {
        try {
            byte[] bArrDigest = MessageDigest.getInstance("MD5").digest(str.getBytes(f180e));
            StringBuilder sb = new StringBuilder();
            for (byte b : bArrDigest) {
                sb.append(Integer.toHexString(b & 255));
            }
            return sb.toString();
        } catch (Exception e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: b */
    private static void m180b(String str, String str2) {
        try {
            File file = new File(str);
            if (file.exists() && file.length() == str2.length()) {
                return;
            }
            file.getParentFile().mkdirs();
            if (Build.VERSION.SDK_INT >= 9) {
                C0063ab.m54a(file);
            } else {
                Runtime.getRuntime().exec("chmod 444 " + file.getAbsolutePath());
            }
            FileOutputStream fileOutputStream = new FileOutputStream(file);
            fileOutputStream.write(str2.getBytes());
            fileOutputStream.close();
        } catch (Exception e) {
        }
    }

    /* JADX INFO: renamed from: b */
    public static boolean m181b() {
        if (!m178a("android.permission.ACCESS_NETWORK_STATE")) {
            return false;
        }
        NetworkInfo activeNetworkInfo = ((ConnectivityManager) f176a.getSystemService("connectivity")).getActiveNetworkInfo();
        return activeNetworkInfo != null && 1 == activeNetworkInfo.getType() && activeNetworkInfo.isConnected();
    }

    /* JADX INFO: renamed from: c */
    public static boolean m182c() {
        return !m183c(Proxy.getDefaultHost());
    }

    /* JADX INFO: renamed from: c */
    static final boolean m183c(String str) {
        return str == null || "".equals(str.trim());
    }

    /* JADX INFO: renamed from: d */
    private static String m184d(String str) {
        try {
            FileInputStream fileInputStream = new FileInputStream(str);
            byte[] bArr = new byte[128];
            int i = fileInputStream.read(bArr);
            fileInputStream.close();
            return new String(bArr, 0, i);
        } catch (Exception e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: d */
    public static HttpHost m185d() {
        return new HttpHost(Proxy.getDefaultHost(), Proxy.getDefaultPort());
    }

    /* JADX INFO: renamed from: e */
    public static synchronized String m186e() {
        String str;
        if (f183h != null) {
            str = f183h;
        } else {
            f183h = m167K();
            str = f183h;
        }
        return str;
    }

    /* JADX INFO: renamed from: e */
    private static void m187e(String str) {
        m180b(Environment.getExternalStorageDirectory() + "/.tid" + m165I(), str);
    }

    /* JADX INFO: renamed from: f */
    public static String m188f() {
        if (!m178a("android.permission.READ_PHONE_STATE")) {
            return "";
        }
        m166J();
        return f179d.getDeviceId();
    }

    /* JADX INFO: renamed from: f */
    private static void m189f(String str) {
        m180b("/tmp/.tid", str);
    }

    /* JADX INFO: renamed from: g */
    public static String m190g() {
        return "android_id";
    }

    /* JADX INFO: renamed from: g */
    private static void m191g(String str) {
        m180b("/var/.tid", str);
    }

    /* JADX INFO: renamed from: h */
    public static String m192h() {
        WifiInfo connectionInfo;
        if (m178a("android.permission.ACCESS_WIFI_STATE")) {
            WifiManager wifiManager = (WifiManager) f176a.getSystemService("wifi");
            if (wifiManager.isWifiEnabled() && (connectionInfo = wifiManager.getConnectionInfo()) != null) {
                String strTrim = connectionInfo.getMacAddress().toUpperCase().trim();
                return (f181f.equals(strTrim) || !f182g.matcher(strTrim).matches()) ? "" : strTrim;
            }
        }
        return "";
    }

    /* JADX INFO: renamed from: h */
    private static void m193h(String str) {
        SharedPreferences.Editor editorEdit = PreferenceManager.getDefaultSharedPreferences(f176a).edit();
        editorEdit.putString(f178c, str);
        editorEdit.commit();
    }

    /* JADX INFO: renamed from: i */
    private static int m194i(String str) {
        try {
            Matcher matcher = Pattern.compile("([0-9]+)").matcher(str);
            return Integer.valueOf(matcher.find() ? matcher.toMatchResult().group(0) : "").intValue();
        } catch (Exception e) {
            return 0;
        }
    }

    /* JADX INFO: renamed from: i */
    public static String m195i() {
        StringBuilder sb = new StringBuilder();
        if (m178a("android.permission.ACCESS_WIFI_STATE")) {
            WifiManager wifiManager = (WifiManager) f176a.getSystemService("wifi");
            if (wifiManager.isWifiEnabled()) {
                WifiInfo connectionInfo = wifiManager.getConnectionInfo();
                String bssid = null;
                if (connectionInfo != null && connectionInfo.getBSSID() != null) {
                    bssid = connectionInfo.getBSSID();
                    sb.append(bssid).append('/').append(connectionInfo.getRssi()).append(";;");
                }
                List<ScanResult> scanResults = wifiManager.getScanResults();
                if (scanResults != null) {
                    for (ScanResult scanResult : scanResults) {
                        if (scanResult.BSSID != null && !scanResult.BSSID.equals(bssid)) {
                            sb.append(scanResult.BSSID).append('/').append(scanResult.level).append(';');
                        }
                    }
                }
            }
        }
        return sb.toString();
    }

    /* JADX INFO: renamed from: j */
    static String m196j() {
        String strTrim = Build.MODEL.trim();
        String strM175a = m175a(Build.MANUFACTURER.trim(), strTrim);
        if (m183c(strM175a)) {
            strM175a = m175a(Build.BRAND.trim(), strTrim);
        }
        StringBuilder sb = new StringBuilder();
        if (strM175a == null) {
            strM175a = "";
        }
        return sb.append(strM175a).append(":").append(strTrim).toString();
    }

    /* JADX INFO: renamed from: j */
    private static String m197j(String str) {
        String str2 = "";
        try {
            FileReader fileReader = new FileReader(str);
            try {
                char[] cArr = new char[1024];
                BufferedReader bufferedReader = new BufferedReader(fileReader, 1024);
                while (true) {
                    int i = bufferedReader.read(cArr, 0, 1024);
                    if (-1 == i) {
                        break;
                    }
                    str2 = str2 + new String(cArr, 0, i);
                }
                bufferedReader.close();
                fileReader.close();
            } catch (IOException e) {
            }
        } catch (FileNotFoundException e2) {
        }
        return str2;
    }

    /* JADX INFO: renamed from: k */
    private static long m198k(String str) {
        long jCharAt = 1125899906842597L;
        int length = str.length();
        for (int i = 0; i < length; i++) {
            jCharAt = (jCharAt * 131) + ((long) str.charAt(i));
        }
        return jCharAt;
    }

    /* JADX INFO: renamed from: k */
    static String m199k() {
        return Build.VERSION.SDK;
    }

    /* JADX INFO: renamed from: l */
    static String m200l() {
        if (!m178a("android.permission.READ_PHONE_STATE")) {
            return "";
        }
        m166J();
        return f179d.getSimSerialNumber();
    }

    /* JADX INFO: renamed from: m */
    static String m201m() {
        if (!m178a("android.permission.READ_PHONE_STATE")) {
            return "";
        }
        m166J();
        return f179d.getNetworkOperator();
    }

    /* JADX INFO: renamed from: n */
    static String m202n() {
        if (!m178a("android.permission.READ_PHONE_STATE")) {
            return "";
        }
        m166J();
        return f179d.getSimOperator();
    }

    /* JADX INFO: renamed from: o */
    static String m203o() {
        if (!m178a("android.permission.READ_PHONE_STATE")) {
            return "";
        }
        m166J();
        return f179d.getSubscriberId();
    }

    /* JADX INFO: renamed from: p */
    static String m204p() {
        if (!m178a("android.permission.READ_PHONE_STATE")) {
            return "";
        }
        m166J();
        return f179d.getNetworkOperatorName();
    }

    /* JADX INFO: renamed from: q */
    public static C0090v m205q() {
        CdmaCellLocation cdmaCellLocation;
        C0090v c0090v = new C0090v();
        if (m178a("android.permission.ACCESS_COARSE_LOCATION") || m178a("android.permission.ACCESS_FINE_LOCATION")) {
            try {
                CellLocation cellLocation = ((TelephonyManager) f176a.getSystemService("phone")).getCellLocation();
                if (cellLocation instanceof GsmCellLocation) {
                    GsmCellLocation gsmCellLocation = (GsmCellLocation) cellLocation;
                    if (gsmCellLocation != null) {
                        c0090v.f187d = gsmCellLocation.getCid();
                        c0090v.f188e = gsmCellLocation.getLac();
                        c0090v.f186c = "gsm";
                        if (Build.VERSION.SDK_INT >= 9) {
                            c0090v.f186c += C0063ab.m53a(gsmCellLocation);
                        }
                    }
                } else if ((cellLocation instanceof CdmaCellLocation) && (cdmaCellLocation = (CdmaCellLocation) cellLocation) != null) {
                    c0090v.f187d = cdmaCellLocation.getBaseStationId();
                    c0090v.f188e = cdmaCellLocation.getNetworkId();
                    c0090v.f186c = "cdma:" + cdmaCellLocation.getSystemId() + ':' + cdmaCellLocation.getBaseStationLatitude() + ':' + cdmaCellLocation.getBaseStationLongitude();
                }
            } catch (Exception e) {
            }
        }
        return c0090v;
    }

    /* JADX INFO: renamed from: r */
    static List m206r() {
        ArrayList arrayList = new ArrayList();
        try {
            if (m178a("android.permission.ACCESS_FINE_LOCATION") || m178a("android.permission.ACCESS_COARSE_LOCATION")) {
                LocationManager locationManager = (LocationManager) f176a.getSystemService("location");
                for (String str : locationManager.getProviders(true)) {
                    Location lastKnownLocation = locationManager.getLastKnownLocation(str);
                    if (lastKnownLocation != null) {
                        arrayList.add(lastKnownLocation);
                    }
                    try {
                        PendingIntent broadcast = PendingIntent.getBroadcast(f176a, 0, new Intent(), 0);
                        locationManager.requestLocationUpdates(str, 300000L, 0.0f, broadcast);
                        locationManager.removeUpdates(broadcast);
                    } catch (Exception e) {
                    }
                }
            }
        } catch (Exception e2) {
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: s */
    static String m207s() {
        try {
            return String.valueOf(f176a.getPackageManager().getPackageInfo(f176a.getPackageName(), 0).versionCode);
        } catch (Exception e) {
            return "unknown";
        }
    }

    /* JADX INFO: renamed from: t */
    static String m208t() {
        try {
            return f176a.getPackageManager().getPackageInfo(f176a.getPackageName(), 0).versionName;
        } catch (Exception e) {
            return "unknown";
        }
    }

    /* JADX INFO: renamed from: u */
    static Long[][] m209u() {
        List<ActivityManager.RecentTaskInfo> recentTasks;
        ActivityManager activityManager = (ActivityManager) f176a.getSystemService(C0073e.f108g);
        PackageManager packageManager = f176a.getPackageManager();
        HashSet hashSet = new HashSet();
        hashSet.add(f176a.getPackageName());
        HashSet hashSet2 = new HashSet();
        if (m178a("android.permission.GET_TASKS") && (recentTasks = activityManager.getRecentTasks(10, 1)) != null) {
            Iterator<ActivityManager.RecentTaskInfo> it = recentTasks.iterator();
            while (it.hasNext()) {
                ComponentName component = it.next().baseIntent.getComponent();
                if (component != null) {
                    String packageName = component.getPackageName();
                    if (hashSet.add(packageName)) {
                        hashSet2.add(Long.valueOf(m198k(packageName)));
                    }
                }
            }
        }
        List<ActivityManager.RunningAppProcessInfo> runningAppProcesses = activityManager.getRunningAppProcesses();
        HashSet hashSet3 = new HashSet();
        if (runningAppProcesses != null) {
            Iterator<ActivityManager.RunningAppProcessInfo> it2 = runningAppProcesses.iterator();
            while (it2.hasNext()) {
                String str = it2.next().processName;
                if (packageManager.getLaunchIntentForPackage(str) != null && !hashSet.contains(str)) {
                    hashSet3.add(Long.valueOf(m198k(str)));
                }
            }
        }
        List<ApplicationInfo> installedApplications = packageManager.getInstalledApplications(0);
        HashSet hashSet4 = new HashSet();
        if (installedApplications != null) {
            for (ApplicationInfo applicationInfo : installedApplications) {
                if ((applicationInfo.flags & 1) <= 0 && !hashSet.contains(applicationInfo.packageName)) {
                    hashSet4.add(Long.valueOf(m198k(applicationInfo.packageName)));
                }
            }
        }
        Long[][] lArr = new Long[3][];
        lArr[0] = new Long[hashSet2.size()];
        lArr[0] = (Long[]) hashSet2.toArray(lArr[0]);
        lArr[1] = new Long[hashSet3.size()];
        lArr[1] = (Long[]) hashSet3.toArray(lArr[1]);
        lArr[2] = new Long[hashSet4.size()];
        lArr[2] = (Long[]) hashSet4.toArray(lArr[2]);
        return lArr;
    }

    /* JADX INFO: renamed from: v */
    static String m210v() {
        return f176a.getPackageName();
    }

    /* JADX INFO: renamed from: w */
    static long m211w() {
        try {
            if (Build.VERSION.SDK_INT < 9) {
                return -1L;
            }
            return C0063ab.m52a(f176a);
        } catch (Exception e) {
            return -1L;
        }
    }

    /* JADX INFO: renamed from: x */
    static long m212x() {
        try {
            if (Build.VERSION.SDK_INT < 9) {
                return -1L;
            }
            return C0063ab.m55b(f176a);
        } catch (Exception e) {
            return -1L;
        }
    }

    /* JADX INFO: renamed from: y */
    static long m213y() {
        try {
            return new File(f176a.getPackageManager().getApplicationInfo(f176a.getPackageName(), 0).sourceDir).length();
        } catch (Exception e) {
            return -1L;
        }
    }

    /* JADX INFO: renamed from: z */
    static String m214z() {
        try {
            return f176a.getPackageManager().getPackageInfo(f176a.getPackageName(), 64).signatures[0].toCharsString();
        } catch (PackageManager.NameNotFoundException e) {
            return "";
        }
    }
}
