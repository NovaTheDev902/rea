package com.lenovo.lps.sus.p008c;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.StatFs;
import android.os.SystemClock;
import android.provider.Settings;
import android.telephony.TelephonyManager;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Display;
import android.view.WindowManager;
import com.lenovo.lps.sus.SUSListener;
import com.lenovo.lps.sus.control.C0104ae;
import com.lenovo.lps.sus.control.C0111am;
import com.lenovo.lps.sus.control.C0136x;
import com.lenovo.lps.sus.control.SUSCustdefNotificationActivity;
import com.lenovo.lps.sus.control.SUSNotificationActivity;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.net.URLEncoder;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Random;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;

/* JADX INFO: renamed from: com.lenovo.lps.sus.c.c */
/* JADX INFO: loaded from: classes.dex */
public final class C0092c {

    /* JADX INFO: renamed from: A */
    public static final String f1270A = "PackageID";

    /* JADX INFO: renamed from: B */
    public static final String f1271B = "ChannelKey";

    /* JADX INFO: renamed from: C */
    public static final String f1272C = "VerCode";

    /* JADX INFO: renamed from: D */
    public static final String f1273D = "VerName";

    /* JADX INFO: renamed from: E */
    public static final String f1274E = "DownloadURL";

    /* JADX INFO: renamed from: F */
    public static final String f1275F = "IT";

    /* JADX INFO: renamed from: G */
    public static final String f1276G = "Size";

    /* JADX INFO: renamed from: H */
    public static final String f1277H = "UpdateDesc";

    /* JADX INFO: renamed from: I */
    public static final String f1278I = "FileName";

    /* JADX INFO: renamed from: J */
    public static final String f1279J = "CtrlKey";

    /* JADX INFO: renamed from: K */
    public static final String f1280K = "CustKey";

    /* JADX INFO: renamed from: L */
    public static final String f1281L = "RES";

    /* JADX INFO: renamed from: M */
    public static final String f1282M = "\"";

    /* JADX INFO: renamed from: N */
    public static final String f1283N = ":";

    /* JADX INFO: renamed from: O */
    public static final String f1284O = ";";

    /* JADX INFO: renamed from: P */
    public static final String f1285P = "{";

    /* JADX INFO: renamed from: Q */
    public static final String f1286Q = "}";

    /* JADX INFO: renamed from: R */
    public static final String f1287R = "SUS-";

    /* JADX INFO: renamed from: S */
    public static final String f1288S = "SUCCESS";

    /* JADX INFO: renamed from: T */
    public static final String f1289T = "LATESTVERSION";

    /* JADX INFO: renamed from: U */
    public static final String f1290U = "NOTFOUND";

    /* JADX INFO: renamed from: V */
    public static final String f1291V = "EXCEPTION";

    /* JADX INFO: renamed from: W */
    public static final String f1292W = "http://susapi.lenovomm.com/adpserver/ctrl?CtrlType=testConnect";

    /* JADX INFO: renamed from: X */
    public static final String f1293X = "GetVerInfo?SDKVer=1.3&OSType=Android&ReqType=%s&AppKey=%s&PackName=%s&AppVerCode=%s&AppVerName=%s&VerSubType=%s&AppTags=%s&Resolution=%s&DevID=%s&AndID=%s&OSVer=%s&Lang=%s&Count=%s&DModel=%s&Mfr=%s&BVer=%s";

    /* JADX INFO: renamed from: Y */
    public static final String f1294Y = "GetVIByPN?SDKVer=1.3&OSType=Android&ReqType=%s&PackName=%s&AppVerCode=%s&AppVerName=%s&VerSubType=%s&AppTags=%s&Resolution=%s&DevID=%s&AndID=%s&OSVer=%s&Lang=%s&Count=%s&DModel=%s&Mfr=%s&BVer=%s";

    /* JADX INFO: renamed from: Z */
    public static final String f1295Z = "GetVIByAK?SDKVer=1.3&OSType=Android&ReqType=%s&AppKey=%s&AppVerCode=%s&AppVerName=%s&VerSubType=%s&AppTags=%s&Resolution=%s&DevID=%s&AndID=%s&OSVer=%s&Lang=%s&Count=%s&DModel=%s&Mfr=%s&BVer=%s";

    /* JADX INFO: renamed from: aA */
    public static final String f1297aA = "No";

    /* JADX INFO: renamed from: aB */
    public static final int f1298aB = 1;

    /* JADX INFO: renamed from: aC */
    public static final int f1299aC = 8192;

    /* JADX INFO: renamed from: aD */
    public static final int f1300aD = 16384;

    /* JADX INFO: renamed from: aG */
    public static final int f1303aG = 93;

    /* JADX INFO: renamed from: aa */
    public static final String f1313aa = "QueryAVInfo?SDKVer=1.3&OSType=Android&ReqType=%s&PackName=%s&AppVerCode=%s&AppVerName=%s&VerSubType=%s&AppTags=%s&Resolution=%s&DevID=%s&AndID=%s&OSVer=%s&Lang=%s&Count=%s&DModel=%s&Mfr=%s&BVer=%s";

    /* JADX INFO: renamed from: ab */
    public static final String f1314ab = "DownloadSumBySDK?SDKVer=1.3&pt=android&id=%s&pn=%s&vc=%s&vn=%s&ch=%s&rep1=%s&rep2=%s&rep3=%s&OL=%s";

    /* JADX INFO: renamed from: ac */
    public static final String f1315ac = "queryupgrade?PackNameList=%s";

    /* JADX INFO: renamed from: ad */
    public static final String f1316ad = "SUS_SETTINGS";

    /* JADX INFO: renamed from: ae */
    public static final String f1317ae = "SUS_UPDATEACTIONTYPE";

    /* JADX INFO: renamed from: af */
    public static final String f1318af = "SUS_NEWVERSIONCODE";

    /* JADX INFO: renamed from: ag */
    public static final String f1319ag = "CHANGEDATE";

    /* JADX INFO: renamed from: ah */
    public static final String f1320ah = "SUS_REAPERAPPINFO";

    /* JADX INFO: renamed from: ai */
    public static final String f1321ai = "SUS_REAPERAPPINFO_LASTTIME";

    /* JADX INFO: renamed from: aj */
    public static final String f1322aj = "SUS_IDENTIFICATIONFILE";

    /* JADX INFO: renamed from: ak */
    public static final String f1323ak = "SUS_IDENTIFICATIONFILE_DOWNLOADURL";

    /* JADX INFO: renamed from: al */
    public static final String f1324al = "SUS_DOWNLOAD_FAIL_NUM";

    /* JADX INFO: renamed from: am */
    public static final int f1325am = 2;

    /* JADX INFO: renamed from: an */
    public static final int f1326an = 6;

    /* JADX INFO: renamed from: ao */
    public static final int f1327ao = 2048;

    /* JADX INFO: renamed from: ap */
    public static final long f1328ap = 3000;

    /* JADX INFO: renamed from: aq */
    public static final int f1329aq = 6000;

    /* JADX INFO: renamed from: ar */
    public static final int f1330ar = 10000;

    /* JADX INFO: renamed from: as */
    public static final String f1331as = "SUSDownloadManager";

    /* JADX INFO: renamed from: at */
    public static final String f1332at = "SUS_analytics";

    /* JADX INFO: renamed from: au */
    public static final String f1333au = "lenovo:applicationToken";

    /* JADX INFO: renamed from: av */
    public static final String f1334av = "SUS_APPKEY";

    /* JADX INFO: renamed from: aw */
    public static final String f1335aw = "SUS_CHANNEL";

    /* JADX INFO: renamed from: ax */
    public static final String f1336ax = "SUS_VERTYPE";

    /* JADX INFO: renamed from: ay */
    public static final String f1337ay = "Yes";

    /* JADX INFO: renamed from: az */
    public static final String f1338az = "Latest";

    /* JADX INFO: renamed from: b */
    public static final String f1339b = "SUS";

    /* JADX INFO: renamed from: c */
    public static final String f1340c = "1.3";

    /* JADX INFO: renamed from: d */
    public static final String f1341d = "SUSdownload";

    /* JADX INFO: renamed from: e */
    public static final String f1342e = "|$|$";

    /* JADX INFO: renamed from: f */
    public static final String f1343f = "\\|\\$\\|\\$";

    /* JADX INFO: renamed from: h */
    public static final String f1345h = "http://10.109.4.129:8080/adpserver/";

    /* JADX INFO: renamed from: j */
    public static final String f1347j = "http://susapi.lenovomm.com/adpserver/";

    /* JADX INFO: renamed from: k */
    public static final String f1348k = "/adpserver/";

    /* JADX INFO: renamed from: l */
    public static final String f1349l = "http://test.surepush.cn/susserver/";

    /* JADX INFO: renamed from: q */
    public static final String f1354q = "http://lcs.lenovomm.com";

    /* JADX INFO: renamed from: r */
    public static final String f1355r = "http://lcs.lenovomm.com";

    /* JADX INFO: renamed from: s */
    public static final String f1356s = "http://lcs.dev.surepush.cn";

    /* JADX INFO: renamed from: t */
    public static final String f1357t = "http://lcs.test.lenovomm.cn";

    /* JADX INFO: renamed from: u */
    public static final String f1358u = "http://lcs.lenovomm.com";

    /* JADX INFO: renamed from: v */
    public static final String f1359v = "adp@cluster-1";

    /* JADX INFO: renamed from: x */
    public static final String f1361x = "SUSRESINFO";

    /* JADX INFO: renamed from: y */
    public static final String f1362y = "FORMATVERCODE";

    /* JADX INFO: renamed from: z */
    public static final String f1363z = "V1";

    /* JADX INFO: renamed from: a */
    public static Random f1296a = new Random(SystemClock.uptimeMillis());

    /* JADX INFO: renamed from: g */
    public static final Long f1344g = 5242880L;

    /* JADX INFO: renamed from: i */
    public static String f1346i = "http://susapi.dev.surepush.cn/adpserver/";

    /* JADX INFO: renamed from: m */
    public static int f1350m = 0;

    /* JADX INFO: renamed from: n */
    public static String f1351n = null;

    /* JADX INFO: renamed from: o */
    public static String f1352o = null;

    /* JADX INFO: renamed from: p */
    public static boolean f1353p = false;

    /* JADX INFO: renamed from: w */
    public static final String f1360w = String.valueOf(m392s()) + "/get?path=";

    /* JADX INFO: renamed from: aE */
    public static String f1301aE = null;

    /* JADX INFO: renamed from: aF */
    public static boolean f1302aF = true;

    /* JADX INFO: renamed from: aH */
    public static boolean f1304aH = false;

    /* JADX INFO: renamed from: aI */
    public static boolean f1305aI = false;

    /* JADX INFO: renamed from: aJ */
    public static final Integer f1306aJ = 2;

    /* JADX INFO: renamed from: aK */
    public static final Integer f1307aK = 4;

    /* JADX INFO: renamed from: aL */
    public static boolean f1308aL = false;

    /* JADX INFO: renamed from: aN */
    private static Boolean f1310aN = false;

    /* JADX INFO: renamed from: aO */
    private static Boolean f1311aO = false;

    /* JADX INFO: renamed from: aP */
    private static Boolean f1312aP = false;

    /* JADX INFO: renamed from: aM */
    public static int f1309aM = 0;

    /* JADX INFO: renamed from: a */
    public static int m323a(Context context, String str, String str2) {
        return context.getResources().getIdentifier(str2, str, context.getPackageName());
    }

    /* JADX INFO: renamed from: a */
    public static String m324a(int i, String str, String str2, String str3, String str4, String str5, String str6, String str7, String str8, String str9, String str10, String str11, String str12, String str13, String str14, String str15) {
        String strEncode;
        String str16 = null;
        String str17 = String.valueOf(m358e()) + f1294Y;
        if (str4 == null) {
            strEncode = null;
        } else {
            try {
                strEncode = URLEncoder.encode(str4, InterfaceC0079b.f1213a);
            } catch (UnsupportedEncodingException e) {
                return str16;
            }
        }
        str16 = String.format(str17, String.valueOf(i), str2 == null ? null : URLEncoder.encode(str2, InterfaceC0079b.f1213a), str3 == null ? null : URLEncoder.encode(str3, InterfaceC0079b.f1213a), strEncode, str5 == null ? null : URLEncoder.encode(str5, InterfaceC0079b.f1213a), str6 == null ? null : URLEncoder.encode(str6, InterfaceC0079b.f1213a), str7 == null ? null : URLEncoder.encode(str7, InterfaceC0079b.f1213a), str8 == null ? null : URLEncoder.encode(str8, InterfaceC0079b.f1213a), str9 == null ? null : URLEncoder.encode(str9, InterfaceC0079b.f1213a), str10 == null ? null : URLEncoder.encode(str10, InterfaceC0079b.f1213a), str11 == null ? null : URLEncoder.encode(str11, InterfaceC0079b.f1213a), str12 == null ? null : URLEncoder.encode(str12, InterfaceC0079b.f1213a), str13 == null ? null : URLEncoder.encode(str13, InterfaceC0079b.f1213a), str14 == null ? null : URLEncoder.encode(str14, InterfaceC0079b.f1213a), str15 == null ? null : URLEncoder.encode(str15, InterfaceC0079b.f1213a));
        return str16;
    }

    /* JADX INFO: renamed from: a */
    public static String m325a(Context context) {
        String string;
        Bundle bundle;
        try {
            ApplicationInfo applicationInfo = context.getPackageManager().getApplicationInfo(context.getPackageName(), 128);
            string = (applicationInfo == null || (bundle = applicationInfo.metaData) == null) ? null : bundle.getString(f1334av);
        } catch (Exception e) {
            e.printStackTrace();
        }
        if (string != null) {
            return string.trim();
        }
        return null;
    }

    /* JADX INFO: renamed from: a */
    public static String m326a(String str) {
        MessageDigest messageDigest = null;
        try {
            messageDigest = MessageDigest.getInstance("MD5");
        } catch (NoSuchAlgorithmException e) {
        }
        messageDigest.update(str.getBytes());
        byte[] bArrDigest = messageDigest.digest();
        StringBuffer stringBuffer = new StringBuffer();
        for (byte b : bArrDigest) {
            stringBuffer.append(Integer.toHexString(b & 255));
        }
        return stringBuffer.toString();
    }

    /* JADX INFO: renamed from: a */
    public static String m327a(String str, Boolean bool, int i) throws Throwable {
        InputStream inputStream;
        InputStream content;
        if (str == null || bool == null) {
            return null;
        }
        BasicHttpParams basicHttpParams = new BasicHttpParams();
        HttpConnectionParams.setConnectionTimeout(basicHttpParams, i);
        HttpConnectionParams.setSoTimeout(basicHttpParams, i);
        DefaultHttpClient defaultHttpClient = new DefaultHttpClient(basicHttpParams);
        HttpGet httpGet = new HttpGet(str);
        StringBuilder sb = new StringBuilder();
        if (!bool.booleanValue()) {
            try {
                defaultHttpClient.execute(httpGet);
                return null;
            } catch (ClientProtocolException e) {
                return null;
            } catch (IOException e2) {
                return null;
            }
        }
        try {
            HttpResponse httpResponseExecute = defaultHttpClient.execute(httpGet);
            int statusCode = httpResponseExecute.getStatusLine().getStatusCode();
            HttpEntity entity = httpResponseExecute.getEntity();
            if (200 != statusCode || entity == null) {
                content = null;
            } else {
                content = entity.getContent();
                try {
                    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(content), 8192);
                    while (true) {
                        String line = bufferedReader.readLine();
                        if (line == null) {
                            break;
                        }
                        sb.append(line);
                    }
                } catch (IOException e3) {
                    if (content != null) {
                        try {
                            content.close();
                        } catch (IOException e4) {
                            return null;
                        }
                    }
                } catch (IllegalStateException e5) {
                    if (content != null) {
                        try {
                            content.close();
                        } catch (IOException e6) {
                            return null;
                        }
                    }
                } catch (Throwable th) {
                    inputStream = content;
                    th = th;
                    if (inputStream != null) {
                        try {
                            inputStream.close();
                        } catch (IOException e7) {
                            return null;
                        }
                    }
                    throw th;
                }
            }
            if (content != null) {
                try {
                    content.close();
                } catch (IOException e8) {
                    return null;
                }
            }
        } catch (IOException e9) {
            content = null;
        } catch (IllegalStateException e10) {
            content = null;
        } catch (Throwable th2) {
            th = th2;
            inputStream = null;
        }
        return sb.toString();
    }

    /* JADX INFO: renamed from: a */
    public static String m328a(String str, String str2, Boolean bool, int i) {
        StringEntity stringEntity;
        BasicHttpParams basicHttpParams = new BasicHttpParams();
        HttpConnectionParams.setConnectionTimeout(basicHttpParams, i);
        HttpConnectionParams.setSoTimeout(basicHttpParams, i);
        DefaultHttpClient defaultHttpClient = new DefaultHttpClient(basicHttpParams);
        HttpPost httpPost = new HttpPost(str);
        try {
            stringEntity = new StringEntity(str2);
        } catch (UnsupportedEncodingException e) {
            stringEntity = null;
        }
        httpPost.setEntity(stringEntity);
        try {
            defaultHttpClient.execute(httpPost);
        } catch (ClientProtocolException e2) {
        } catch (IOException e3) {
        }
        return null;
    }

    /* JADX INFO: renamed from: a */
    public static String m329a(String str, String str2, String str3, String str4, String str5, String str6, String str7, String str8, String str9) {
        String strEncode;
        String str10 = null;
        String strM361f = m361f();
        if (str == null) {
            strEncode = null;
        } else {
            try {
                strEncode = URLEncoder.encode(str, InterfaceC0079b.f1213a);
            } catch (UnsupportedEncodingException e) {
                return str10;
            }
        }
        str10 = String.format(strM361f, strEncode, str2 == null ? null : URLEncoder.encode(str2, InterfaceC0079b.f1213a), str3 == null ? null : URLEncoder.encode(str3, InterfaceC0079b.f1213a), str4 == null ? null : URLEncoder.encode(str4, InterfaceC0079b.f1213a), str5 == null ? null : URLEncoder.encode(str5, InterfaceC0079b.f1213a), null, null, null, null);
        return str10;
    }

    /* JADX INFO: renamed from: a */
    public static void m330a(int i) {
        f1350m = i;
    }

    /* JADX WARN: Code duplicated, block: B:23:0x007d  */
    /* JADX WARN: Code duplicated, block: B:25:0x0099  */
    /* JADX WARN: Code duplicated, block: B:33:? A[RETURN, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:34:? A[RETURN, SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    public static void m331a(Context context, String str, String str2, Handler handler, SUSListener sUSListener, int i, boolean z) {
        boolean z2;
        int i2;
        File file;
        Intent intent;
        String str3;
        if (context == null) {
            return;
        }
        C0098i.m409a(f1339b, "installPackageByInstallType entry file =" + str + "; installerPackageName" + str2 + "; susListener" + sUSListener + "; reqInstallType" + i + "; isOnlySilentInstall" + z);
        if (1 == i || 2 == i || 3 == i || 4 == i) {
            z2 = context.checkCallingOrSelfPermission("android.permission.INSTALL_PACKAGES") == 0;
            C0098i.m409a(f1339b, "installPackageByInstallType isInstallPackagePermission =" + z2);
        } else {
            z2 = false;
        }
        if (1 != i) {
            if (4 == i && !z2) {
                i2 = 0;
            }
            if (i2 == 0 && i2 <= 4) {
                new C0136x(context, str, str2, handler, sUSListener, i2, z).run();
                return;
            }
            file = new File(str);
            if (file.exists()) {
                intent = new Intent("android.intent.action.VIEW");
                str3 = "file://" + file.getAbsolutePath();
                if (str3 != null) {
                    intent.setFlags(268435456);
                    intent.putExtra("apk_from", "com.lenovo.appstore");
                    intent.setDataAndType(Uri.parse(str3), "application/vnd.android.package-archive");
                    context.startActivity(intent);
                }
            }
        }
        if (!z2) {
            return;
        }
        i2 = i;
        if (i2 == 0) {
        }
        file = new File(str);
        if (file.exists()) {
            intent = new Intent("android.intent.action.VIEW");
            str3 = "file://" + file.getAbsolutePath();
            if (str3 != null) {
                intent.setFlags(268435456);
                intent.putExtra("apk_from", "com.lenovo.appstore");
                intent.setDataAndType(Uri.parse(str3), "application/vnd.android.package-archive");
                context.startActivity(intent);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m332a(String str, String str2) {
        try {
            Runtime.getRuntime().exec("chmod " + str + " " + str2);
        } catch (IOException e) {
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m333a(String str, String str2, boolean z) {
        if (str != null) {
            if ((str == null || str.contains("/SUSdownload")) && str2 != null) {
                if (str2 == null || str2.length() > 0) {
                    long jCurrentTimeMillis = System.currentTimeMillis();
                    File file = new File(str);
                    if (file.isDirectory()) {
                        File[] fileArrListFiles = file.listFiles();
                        for (File file2 : fileArrListFiles) {
                            if (str2 == null || str2.equals(file2.getName())) {
                                if (str2 != null && str2.equals(file2.getName()) && jCurrentTimeMillis > file2.lastModified() + 604800000) {
                                    file2.delete();
                                }
                            } else if (jCurrentTimeMillis > file2.lastModified() + 3600000) {
                                file2.delete();
                            }
                        }
                    }
                }
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m334a(boolean z) {
        f1353p = z;
    }

    /* JADX INFO: renamed from: a */
    public static boolean m335a() {
        return f1353p;
    }

    /* JADX INFO: renamed from: a */
    public static boolean m336a(long j) {
        return (Environment.getExternalStorageState().equals("mounted") ? m376k() : m374j()) >= f1344g.longValue() + j;
    }

    /* JADX INFO: renamed from: a */
    public static boolean m337a(long j, long j2, long j3) {
        return j >= j2 + j3;
    }

    /* JADX INFO: renamed from: a */
    public static boolean m338a(Context context, String str) {
        return context.getPackageManager().checkPermission(str, context.getPackageName()) == 0;
    }

    /* JADX INFO: renamed from: b */
    public static String m339b() {
        return f1351n;
    }

    /* JADX INFO: renamed from: b */
    public static String m340b(int i, String str, String str2, String str3, String str4, String str5, String str6, String str7, String str8, String str9, String str10, String str11, String str12, String str13, String str14, String str15) {
        String strEncode;
        String str16 = null;
        String str17 = String.valueOf(m358e()) + f1295Z;
        if (str2 == null) {
            strEncode = null;
        } else {
            try {
                strEncode = URLEncoder.encode(str2, InterfaceC0079b.f1213a);
            } catch (UnsupportedEncodingException e) {
                return str16;
            }
        }
        str16 = String.format(str17, String.valueOf(i), strEncode, str3 == null ? null : URLEncoder.encode(str3, InterfaceC0079b.f1213a), str4 == null ? null : URLEncoder.encode(str4, InterfaceC0079b.f1213a), str5 == null ? null : URLEncoder.encode(str5, InterfaceC0079b.f1213a), str6 == null ? null : URLEncoder.encode(str6, InterfaceC0079b.f1213a), str7 == null ? null : URLEncoder.encode(str7, InterfaceC0079b.f1213a), str8 == null ? null : URLEncoder.encode(str8, InterfaceC0079b.f1213a), str9 == null ? null : URLEncoder.encode(str9, InterfaceC0079b.f1213a), str10 == null ? null : URLEncoder.encode(str10, InterfaceC0079b.f1213a), str11 == null ? null : URLEncoder.encode(str11, InterfaceC0079b.f1213a), str12 == null ? null : URLEncoder.encode(str12, InterfaceC0079b.f1213a), str13 == null ? null : URLEncoder.encode(str13, InterfaceC0079b.f1213a), str14 == null ? null : URLEncoder.encode(str14, InterfaceC0079b.f1213a), str15 == null ? null : URLEncoder.encode(str15, InterfaceC0079b.f1213a));
        return str16;
    }

    /* JADX INFO: renamed from: b */
    public static String m341b(long j) {
        DecimalFormat decimalFormat = new DecimalFormat("###.##");
        return j < 1048576 ? String.valueOf(decimalFormat.format(new Float(j / 1024.0f).doubleValue())) + "KB" : String.valueOf(decimalFormat.format(new Float(j / 1048576.0f).doubleValue())) + "MB";
    }

    /* JADX INFO: renamed from: b */
    public static String m342b(Context context) {
        String string;
        Bundle bundle;
        try {
            ApplicationInfo applicationInfo = context.getPackageManager().getApplicationInfo(context.getPackageName(), 128);
            string = (applicationInfo == null || (bundle = applicationInfo.metaData) == null) ? null : bundle.getString(f1336ax);
        } catch (Exception e) {
            e.printStackTrace();
        }
        if (string != null) {
            return string.trim();
        }
        return null;
    }

    /* JADX INFO: renamed from: b */
    public static String m343b(Context context, String str) {
        int identifier = context.getResources().getIdentifier(str, "string", context.getPackageName());
        if (identifier > 0) {
            return context.getResources().getString(identifier);
        }
        return null;
    }

    /* JADX INFO: renamed from: b */
    public static void m344b(int i) {
        f1309aM = i;
        C0098i.m409a(f1339b, "setInstallType installTypeByUserSetting=" + f1309aM);
    }

    /* JADX INFO: renamed from: b */
    public static void m345b(String str) {
        if (str == null || str.length() <= 0) {
            f1351n = null;
        } else {
            f1351n = str;
        }
    }

    /* JADX INFO: renamed from: b */
    public static void m346b(boolean z) {
        f1304aH = z;
    }

    /* JADX INFO: renamed from: c */
    public static int m347c(Context context, String str) {
        int identifier = context.getResources().getIdentifier(str, QueryPermissions.f1958ID, context.getPackageName());
        if (identifier < 0) {
            return 0;
        }
        return identifier;
    }

    /* JADX INFO: renamed from: c */
    public static String m348c(Context context) {
        String string;
        Bundle bundle;
        try {
            ApplicationInfo applicationInfo = context.getPackageManager().getApplicationInfo(context.getPackageName(), 128);
            string = (applicationInfo == null || (bundle = applicationInfo.metaData) == null) ? null : bundle.getString(f1335aw);
        } catch (Exception e) {
            e.printStackTrace();
        }
        if (string != null) {
            return string.trim();
        }
        return null;
    }

    /* JADX INFO: renamed from: c */
    public static void m349c(String str) {
        if (str == null || str.length() <= 0) {
            f1352o = null;
        } else {
            f1352o = str;
        }
    }

    /* JADX INFO: renamed from: c */
    public static void m350c(boolean z) {
        f1302aF = z;
    }

    /* JADX INFO: renamed from: c */
    public static boolean m351c() {
        return f1304aH;
    }

    /* JADX INFO: renamed from: d */
    public static void m352d(Context context, String str) {
        if (context == null || str == null || str.length() == 0) {
            return;
        }
        File file = new File(str);
        if (file.exists()) {
            int iM323a = m323a(context, "drawable", "sus_notification_install_icon");
            int i = iM323a == 0 ? 17301633 : iM323a;
            String strM343b = m343b(context, "SUS_NOTIFICATION_INSTALLAPK_TITLE");
            String strM343b2 = m343b(context, "SUS_NOTIFICATION_INSTALLAPK");
            String str2 = strM343b == null ? "Please install the apk！" : strM343b;
            if (strM343b2 == null) {
                strM343b2 = "Please install the apk:";
            }
            int iLastIndexOf = str.lastIndexOf(CookieSpec.PATH_DELIM);
            String strSubstring = str.substring((-1 == iLastIndexOf || iLastIndexOf >= str.length()) ? 0 : iLastIndexOf + 1);
            Notification notification = new Notification(i, str2, System.currentTimeMillis());
            notification.flags = 2;
            notification.flags = 16;
            Intent intent = new Intent("android.intent.action.VIEW");
            intent.setFlags(268435456);
            intent.setDataAndType(Uri.fromFile(file), "application/vnd.android.package-archive");
            intent.putExtra("apk_from", "com.lenovo.appstore");
            notification.setLatestEventInfo(context, strM343b2, strSubstring, PendingIntent.getActivity(context, 0, intent, 0));
            ((NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION)).notify(i, notification);
        }
    }

    /* JADX INFO: renamed from: d */
    public static void m353d(String str) {
        f1301aE = str;
    }

    /* JADX INFO: renamed from: d */
    public static void m354d(boolean z) {
        f1308aL = z;
    }

    /* JADX INFO: renamed from: d */
    public static boolean m355d() {
        return f1302aF;
    }

    /* JADX INFO: renamed from: d */
    public static boolean m356d(Context context) {
        String string;
        Bundle bundle;
        String string2 = null;
        if (context == null) {
            return false;
        }
        try {
            ApplicationInfo applicationInfo = context.getPackageManager().getApplicationInfo(context.getPackageName(), 128);
            if (applicationInfo == null || (bundle = applicationInfo.metaData) == null) {
                string = null;
            } else {
                string = bundle.getString(f1332at);
                try {
                    string2 = bundle.getString(f1333au);
                } catch (Exception e) {
                    e = e;
                    e.printStackTrace();
                }
            }
        } catch (Exception e2) {
            e = e2;
            string = null;
        }
        return (string == null || string2 == null || !"YES".equals(string)) ? false : true;
    }

    /* JADX INFO: renamed from: e */
    public static int m357e(Context context) {
        int i = 0;
        try {
            i = context.getPackageManager().getPackageInfo(context.getPackageName(), 0).versionCode;
        } catch (PackageManager.NameNotFoundException e) {
        }
        if (i < 0) {
            Log.i("SUSSDK", "Versioncode is invalid");
        }
        return i;
    }

    /* JADX INFO: renamed from: e */
    public static String m358e() {
        if (f1351n != null && f1351n.length() > 0) {
            return f1351n;
        }
        switch (f1350m) {
            case 0:
                return f1347j;
            case 1:
                return f1346i;
            case 2:
                return f1349l;
            case 3:
                return f1345h;
            default:
                return null;
        }
    }

    /* JADX INFO: renamed from: e */
    public static void m359e(String str) {
        if (str != null) {
            if (str == null || str.contains("/SUSdownload")) {
                long jCurrentTimeMillis = System.currentTimeMillis();
                File file = new File(str);
                if (file.isDirectory()) {
                    File[] fileArrListFiles = file.listFiles();
                    for (File file2 : fileArrListFiles) {
                        if (file2 != null && file2.isFile() && jCurrentTimeMillis > file2.lastModified() + 1800000) {
                            file2.delete();
                        }
                    }
                }
            }
        }
    }

    /* JADX INFO: renamed from: e */
    public static void m360e(boolean z) {
        Context contextM466l = C0104ae.m466l();
        if (contextM466l == null || m395u()) {
            return;
        }
        Intent intent = new Intent();
        intent.putExtra("FailFlag", z);
        if (m397w()) {
            C0111am.m470a(contextM466l, z);
            return;
        }
        if (m396v()) {
            intent.setClass(contextM466l, SUSCustdefNotificationActivity.class);
        } else {
            intent.setClass(contextM466l, SUSNotificationActivity.class);
        }
        intent.setFlags(268435456);
        contextM466l.startActivity(intent);
    }

    /* JADX INFO: renamed from: f */
    public static String m361f() {
        return String.valueOf(m358e()) + f1314ab;
    }

    /* JADX INFO: renamed from: f */
    public static String m362f(Context context) {
        try {
            return context.getPackageManager().getPackageInfo(context.getPackageName(), 0).versionName;
        } catch (PackageManager.NameNotFoundException e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: f */
    public static void m363f(boolean z) {
        f1310aN = Boolean.valueOf(z);
    }

    /* JADX INFO: renamed from: f */
    public static boolean m364f(String str) {
        if (str == null) {
            return false;
        }
        for (int i = 0; i < str.length(); i++) {
            if (!Character.isDigit(str.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    /* JADX INFO: renamed from: g */
    public static String m365g(Context context) {
        return context.getPackageName();
    }

    /* JADX INFO: renamed from: g */
    public static String m366g(String str) {
        try {
            return str.replaceAll("[^0-9a-zA-Z /():,;*+=_.-]", "?");
        } catch (Exception e) {
            return str;
        }
    }

    /* JADX INFO: renamed from: g */
    public static void m367g(boolean z) {
        f1311aO = Boolean.valueOf(z);
    }

    /* JADX INFO: renamed from: g */
    public static boolean m368g() {
        return f1305aI;
    }

    /* JADX INFO: renamed from: h */
    public static String m369h(Context context) {
        PackageManager packageManager = context.getPackageManager();
        try {
            PackageInfo packageInfo = context.getPackageManager().getPackageInfo(context.getPackageName(), 0);
            if (packageInfo != null) {
                return packageManager.getApplicationLabel(packageInfo.applicationInfo).toString();
            }
            return null;
        } catch (PackageManager.NameNotFoundException e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: h */
    public static void m370h(boolean z) {
        f1312aP = Boolean.valueOf(z);
    }

    /* JADX INFO: renamed from: h */
    public static boolean m371h() {
        return Environment.getExternalStorageState().equals("mounted");
    }

    /* JADX INFO: renamed from: i */
    public static String m372i() {
        return f1301aE;
    }

    /* JADX INFO: renamed from: i */
    public static String m373i(Context context) {
        String deviceId;
        TelephonyManager telephonyManager = (TelephonyManager) context.getSystemService("phone");
        if (telephonyManager == null) {
            Log.w("MobclickAgent", "No IMEI.");
        }
        try {
            deviceId = m338a(context, "android.permission.READ_PHONE_STATE") ? telephonyManager.getDeviceId() : "";
        } catch (Exception e) {
            e.printStackTrace();
        }
        if (deviceId == null || (deviceId != null && deviceId.length() <= 0)) {
            Log.w("MobclickAgent", "No IMEI.");
            deviceId = m393s(context);
            if (deviceId == null) {
                Log.w("MobclickAgent", "Failed to take mac as IMEI.");
                return null;
            }
        }
        return m326a(deviceId);
    }

    /* JADX INFO: renamed from: j */
    public static long m374j() {
        StatFs statFs = new StatFs(Environment.getDataDirectory().getPath());
        return ((long) statFs.getAvailableBlocks()) * ((long) statFs.getBlockSize());
    }

    /* JADX INFO: renamed from: j */
    public static String[] m375j(Context context) {
        String[] strArr = {"Unknown", "Unknown"};
        if (context.getPackageManager().checkPermission("android.permission.ACCESS_NETWORK_STATE", context.getPackageName()) != 0) {
            strArr[0] = "Unknown";
            return strArr;
        }
        ConnectivityManager connectivityManager = (ConnectivityManager) context.getSystemService("connectivity");
        if (connectivityManager == null) {
            strArr[0] = "Unknown";
            return strArr;
        }
        if (connectivityManager.getNetworkInfo(1).getState() == NetworkInfo.State.CONNECTED) {
            strArr[0] = "WLAN";
            return strArr;
        }
        NetworkInfo networkInfo = connectivityManager.getNetworkInfo(0);
        if (networkInfo.getState() != NetworkInfo.State.CONNECTED) {
            return strArr;
        }
        strArr[0] = "2G/3G";
        strArr[1] = networkInfo.getSubtypeName();
        return strArr;
    }

    /* JADX INFO: renamed from: k */
    public static long m376k() {
        if (!Environment.getExternalStorageState().equals("mounted")) {
            return -1L;
        }
        StatFs statFs = new StatFs(Environment.getExternalStorageDirectory().getPath());
        return ((long) statFs.getAvailableBlocks()) * ((long) statFs.getBlockSize());
    }

    /* JADX INFO: renamed from: k */
    public static boolean m377k(Context context) {
        ConnectivityManager connectivityManager = (ConnectivityManager) context.getSystemService("connectivity");
        if (connectivityManager != null && connectivityManager.getNetworkInfo(1).getState() == NetworkInfo.State.CONNECTED) {
            return true;
        }
        return false;
    }

    /* JADX INFO: renamed from: l */
    public static String m378l() {
        return m366g(Build.VERSION.RELEASE);
    }

    /* JADX INFO: renamed from: l */
    public static boolean m379l(Context context) {
        ConnectivityManager connectivityManager = (ConnectivityManager) context.getSystemService("connectivity");
        if (connectivityManager == null) {
            return false;
        }
        if (connectivityManager.getNetworkInfo(0).getState() != NetworkInfo.State.CONNECTED && connectivityManager.getNetworkInfo(1).getState() != NetworkInfo.State.CONNECTED) {
            return false;
        }
        return true;
    }

    /* JADX INFO: renamed from: m */
    public static String m380m(Context context) {
        NetworkInfo activeNetworkInfo = ((ConnectivityManager) context.getSystemService("connectivity")).getActiveNetworkInfo();
        if (activeNetworkInfo != null && activeNetworkInfo.getType() != 1) {
            String extraInfo = activeNetworkInfo.getExtraInfo();
            Log.i("TAG", "net type:" + extraInfo);
            if (extraInfo == null) {
                return null;
            }
            if (extraInfo.equals("cmwap") || extraInfo.equals("3gwap") || extraInfo.equals("uniwap")) {
                return "10.0.0.172";
            }
            return null;
        }
        return null;
    }

    /* JADX INFO: renamed from: m */
    public static boolean m381m() {
        String strM378l = m378l();
        return (strM378l == null || strM378l.startsWith(DatabaseTables.SYSTEM_MARK) || strM378l.startsWith("2.0") || strM378l.startsWith("2.1") || strM378l.startsWith("2.2")) ? false : true;
    }

    /* JADX INFO: renamed from: n */
    public static String m382n() {
        return Locale.getDefault().getLanguage();
    }

    /* JADX INFO: renamed from: n */
    public static String m383n(Context context) {
        String string;
        f1305aI = false;
        if (Environment.getExternalStorageState().equals("mounted")) {
            File externalStorageDirectory = Environment.getExternalStorageDirectory();
            string = String.valueOf(externalStorageDirectory.getParent()) + CookieSpec.PATH_DELIM + externalStorageDirectory.getName() + "/SUSdownload";
        } else {
            string = context.getCacheDir().toString();
            f1305aI = true;
        }
        if (string != null) {
            File file = new File(string);
            if (!file.exists()) {
                file.mkdirs();
            }
        }
        return string;
    }

    /* JADX INFO: renamed from: o */
    public static String m384o() {
        return Locale.getDefault().getCountry();
    }

    /* JADX INFO: renamed from: o */
    public static boolean m385o(Context context) {
        ConnectivityManager connectivityManager = (ConnectivityManager) context.getApplicationContext().getSystemService("connectivity");
        if (connectivityManager == null) {
            return false;
        }
        NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
        return activeNetworkInfo != null && activeNetworkInfo.isAvailable();
    }

    /* JADX INFO: renamed from: p */
    public static String m386p() {
        return m366g(Build.MODEL);
    }

    /* JADX INFO: renamed from: p */
    public static String m387p(Context context) {
        int i;
        int i2;
        int i3;
        int i4;
        int i5;
        int i6;
        int iIntValue;
        int i7 = 0;
        DisplayMetrics displayMetrics = new DisplayMetrics();
        WindowManager windowManager = (WindowManager) context.getSystemService("window");
        windowManager.getDefaultDisplay().getMetrics(displayMetrics);
        int orientation = windowManager.getDefaultDisplay().getOrientation();
        Display defaultDisplay = windowManager.getDefaultDisplay();
        try {
            Class<?> cls = Class.forName("android.view.Display");
            if (cls != null) {
                Method method = cls.getMethod("getRawWidth", new Class[0]);
                int iIntValue2 = method != null ? ((Integer) method.invoke(defaultDisplay, new Object[0])).intValue() : 0;
                try {
                    Method method2 = cls.getMethod("getRawHeight", new Class[0]);
                    if (method2 != null) {
                        iIntValue = ((Integer) method2.invoke(defaultDisplay, new Object[0])).intValue();
                        i7 = iIntValue2;
                    } else {
                        iIntValue = 0;
                        i7 = iIntValue2;
                    }
                } catch (ClassNotFoundException e) {
                    i6 = iIntValue2;
                    i7 = i6;
                    iIntValue = 0;
                } catch (IllegalAccessException e2) {
                    i5 = iIntValue2;
                    i7 = i5;
                    iIntValue = 0;
                } catch (IllegalArgumentException e3) {
                    i4 = iIntValue2;
                    i7 = i4;
                    iIntValue = 0;
                } catch (NoSuchMethodException e4) {
                    i3 = iIntValue2;
                    i7 = i3;
                    iIntValue = 0;
                } catch (SecurityException e5) {
                    i2 = iIntValue2;
                    i7 = i2;
                    iIntValue = 0;
                } catch (InvocationTargetException e6) {
                    i = iIntValue2;
                    i7 = i;
                    iIntValue = 0;
                }
            } else {
                iIntValue = 0;
            }
        } catch (ClassNotFoundException e7) {
            i6 = 0;
        } catch (IllegalAccessException e8) {
            i5 = 0;
        } catch (IllegalArgumentException e9) {
            i4 = 0;
        } catch (NoSuchMethodException e10) {
            i3 = 0;
        } catch (SecurityException e11) {
            i2 = 0;
        } catch (InvocationTargetException e12) {
            i = 0;
        }
        C0098i.m409a(f1339b, "rotation =" + orientation + "; rawWidth=" + i7 + "; rawHeight=" + iIntValue);
        if (orientation == 0 || orientation == 2) {
            if (i7 <= 0 || iIntValue <= 0) {
                iIntValue = displayMetrics.widthPixels;
                i7 = displayMetrics.heightPixels;
            } else {
                int i8 = iIntValue;
                iIntValue = i7;
                i7 = i8;
            }
        } else if (i7 <= 0 || iIntValue <= 0) {
            i7 = displayMetrics.widthPixels;
            iIntValue = displayMetrics.heightPixels;
        }
        C0098i.m409a(f1339b, "rotation =" + orientation + "; widthPixels=" + iIntValue + "; heightPixels=" + i7);
        return String.valueOf(iIntValue) + "x" + String.valueOf(i7);
    }

    /* JADX INFO: renamed from: q */
    public static String m388q() {
        return m366g(Build.MANUFACTURER);
    }

    /* JADX INFO: renamed from: q */
    public static String m389q(Context context) {
        String deviceId = ((TelephonyManager) context.getSystemService("phone")).getDeviceId();
        if (deviceId != null && deviceId.length() <= 14) {
            C0098i.m409a(f1339b, "DeviceID'length is error!get the SIM1's deviceid. deviceId=" + deviceId);
        }
        return deviceId;
    }

    /* JADX INFO: renamed from: r */
    public static String m390r() {
        return Build.DISPLAY;
    }

    /* JADX INFO: renamed from: r */
    public static String m391r(Context context) {
        return Settings.Secure.getString(context.getContentResolver(), "android_id");
    }

    /* JADX INFO: renamed from: s */
    public static String m392s() {
        return m394t();
    }

    /* JADX INFO: renamed from: s */
    private static String m393s(Context context) {
        try {
            return ((WifiManager) context.getSystemService(SettingUtil.WIFI)).getConnectionInfo().getMacAddress();
        } catch (Exception e) {
            Log.i(f1339b, "getMAC exception", e);
            return null;
        }
    }

    /* JADX INFO: renamed from: t */
    public static String m394t() {
        if (f1352o != null && f1352o.length() > 0) {
            return f1352o;
        }
        switch (f1350m) {
            case 0:
                return "http://lcs.lenovomm.com";
            case 1:
                return f1356s;
            case 2:
                return f1357t;
            case 3:
                return "http://lcs.lenovomm.com";
            default:
                return null;
        }
    }

    /* JADX INFO: renamed from: u */
    public static boolean m395u() {
        return f1308aL;
    }

    /* JADX INFO: renamed from: v */
    public static boolean m396v() {
        return f1310aN.booleanValue();
    }

    /* JADX INFO: renamed from: w */
    public static boolean m397w() {
        return f1311aO.booleanValue();
    }

    /* JADX INFO: renamed from: x */
    public static boolean m398x() {
        return f1312aP.booleanValue();
    }

    /* JADX INFO: renamed from: y */
    public static int m399y() {
        C0098i.m409a(f1339b, "getInstallType installTypeByUserSetting=" + f1309aM);
        return f1309aM;
    }
}
