package com.lenovo.safecenter.lenovoAntiSpam.utils;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Build;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import android.util.Log;
import android.util.Xml;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import java.io.File;
import java.io.InputStream;
import java.net.URLEncoder;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;
import java.util.zip.GZIPInputStream;
import org.apache.commons.httpclient.cookie.Cookie2;
import org.apache.commons.httpclient.params.HttpConnectionParams;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.xmlpull.v1.XmlPullParser;

/* JADX INFO: loaded from: classes.dex */
public class HttpUtils {
    public static final int down_success = 2;
    public static final int net_disconnect = 1;
    public static final int server_disconnect = 0;
    public static final int version_isNew = 3;
    public static String Lastin_tag = "";
    public static String Lastin_CallNumbers = "";
    public static String Lastin_SmsNumbers = "";
    public static String Expire_tag = "";
    public static String Expire_CallNumbers = "";
    public static String Expire_SmsNumbers = "";
    public static int count = 0;
    public static boolean threadFlag = false;

    public static int down(Context context) {
        int i;
        TelephonyManager manager = (TelephonyManager) context.getSystemService("phone");
        Map<String, String> params = new HashMap<>();
        params.put("lang", "zh-cn");
        if (TextUtils.isEmpty(execService("mms_lastintag", context))) {
            params.put("lastintag", "0");
            params.put("expiredtag", "0");
        } else {
            params.put("lastintag", TextUtils.isEmpty(execService("lastintag", context)) ? "0" : execService("lastintag", context));
            params.put("expiredtag", TextUtils.isEmpty(execService("expiredtag", context)) ? "0" : execService("expiredtag", context));
        }
        params.put("devicefamily", "lephone");
        params.put("deviceidtype", "imei");
        if (manager.getDeviceId() == null) {
            params.put("deviceid", "N/A");
        } else {
            params.put("deviceid", manager.getDeviceId());
        }
        params.put("devicevendor", Build.MANUFACTURER);
        Log.i("version", "http://sss.lenovomm.com/sss/1.0/whitenolistsync");
        int resultcode = m1664a("http://sss.lenovomm.com/sss/1.0/whitenolistsync", params, InterfaceC0079b.f1213a);
        Log.i("xmlresult", count + "》》" + resultcode);
        if (resultcode == 2 || resultcode == 3) {
            return resultcode;
        }
        while (count < 2) {
            try {
                count++;
                resultcode = m1664a("http://sss.lenovomm.com/sss/1.0/whitenolistsync", params, InterfaceC0079b.f1213a);
                Log.i("xmlresult", count + "》while》" + resultcode);
                if (resultcode == 2 || resultcode == 3) {
                    count = 0;
                    i = resultcode;
                    return i;
                }
            } catch (Exception e) {
                e.printStackTrace();
                return 1;
            }
        }
        if (count >= 2) {
            Log.i("xmlresult", count + "》HttpUtils.count>=2》" + resultcode);
            count = 0;
            i = resultcode == 0 ? 0 : 1;
        } else {
            i = 1;
        }
        return i;
    }

    /* JADX INFO: renamed from: a */
    private static int m1664a(String path, Map<String, String> params, String encoding) {
        try {
            StringBuilder sb = new StringBuilder();
            sb.append(path);
            if (params != null && !params.isEmpty()) {
                sb.append('?');
                for (Map.Entry<String, String> entry : params.entrySet()) {
                    sb.append(entry.getKey()).append('=').append(URLEncoder.encode(entry.getValue(), encoding)).append('&');
                }
                sb.deleteCharAt(sb.length() - 1);
            }
            Log.i(Cookie2.PATH, sb.toString());
            HttpGet httpGet = new HttpGet(sb.toString());
            DefaultHttpClient httpClient = new DefaultHttpClient();
            httpClient.getParams().setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 6000);
            httpClient.getParams().setParameter("http.socket.timeout", 6000);
            HttpResponse response = httpClient.execute(httpGet);
            HttpEntity httpEntity = response.getEntity();
            Log.i("StatusCode", response.getStatusLine().getStatusCode() + ">>>>>>>>>>");
            if (response.getStatusLine().getStatusCode() == 200) {
                return m1663a(httpEntity.getContent());
            }
            if (response.getStatusLine().getStatusCode() == 304) {
                return 3;
            }
            return 0;
        } catch (Exception e) {
            e.printStackTrace();
            return 1;
        }
    }

    public int queryNetBlack(Context context) {
        TelephonyManager manager = (TelephonyManager) context.getSystemService("phone");
        Map<String, String> params = new HashMap<>();
        params.put("lang", "zh-cn");
        if (TextUtils.isEmpty(execService("mms_lastintag", context))) {
            params.put("lastintag", "0");
            params.put("expiredtag", "0");
        } else {
            params.put("lastintag", TextUtils.isEmpty(execService("lastintag", context)) ? "0" : execService("lastintag", context));
            params.put("expiredtag", TextUtils.isEmpty(execService("expiredtag", context)) ? "0" : execService("expiredtag", context));
        }
        params.put("devicefamily", "lephone");
        params.put("deviceidtype", "imei");
        if (manager.getDeviceId() == null) {
            params.put("deviceid", "N/A");
        } else {
            params.put("deviceid", manager.getDeviceId());
        }
        params.put("devicevendor", Build.MANUFACTURER);
        Log.i("version", "http://sss.lenovomm.com/sss/1.0/whitenolistsync");
        int resultcode = m1666b("http://sss.lenovomm.com/sss/1.0/whitenolistsync", params, InterfaceC0079b.f1213a);
        Log.i("xmlresult", count + "》》" + resultcode);
        if (resultcode != 2 && resultcode != 3) {
            if (resultcode == 0) {
                return 0;
            }
            return 1;
        }
        return resultcode;
    }

    /* JADX INFO: renamed from: b */
    private static int m1666b(String path, Map<String, String> params, String encoding) {
        try {
            StringBuilder sb = new StringBuilder();
            sb.append(path);
            if (params != null && !params.isEmpty()) {
                sb.append('?');
                for (Map.Entry<String, String> entry : params.entrySet()) {
                    sb.append(entry.getKey()).append('=').append(URLEncoder.encode(entry.getValue(), encoding)).append('&');
                }
                sb.deleteCharAt(sb.length() - 1);
            }
            Log.i(Cookie2.PATH, sb.toString());
            HttpGet httpGet = new HttpGet(sb.toString());
            DefaultHttpClient httpClient = new DefaultHttpClient();
            httpClient.getParams().setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 6000);
            httpClient.getParams().setParameter("http.socket.timeout", 6000);
            HttpResponse response = httpClient.execute(httpGet);
            if (response.getStatusLine().getStatusCode() == 200) {
                return 2;
            }
            if (response.getStatusLine().getStatusCode() == 304) {
                return 3;
            }
            return 0;
        } catch (Exception e) {
            e.printStackTrace();
            return 1;
        }
    }

    /* JADX INFO: renamed from: a */
    private static int m1663a(InputStream inStream) throws Exception {
        XmlPullParser parser = Xml.newPullParser();
        parser.setInput(inStream, InterfaceC0079b.f1213a);
        int tag = 0;
        for (int event = parser.getEventType(); event != 1; event = parser.next()) {
            switch (event) {
                case 2:
                    if ("lastinlist".equals(parser.getName())) {
                        tag = 1;
                    }
                    if ("expiredlist".equals(parser.getName())) {
                        tag = 2;
                    }
                    if (tag == 1) {
                        if ("lastintag".equals(parser.getName())) {
                            Lastin_tag = parser.nextText();
                        }
                        if ("numbers4call".equals(parser.getName())) {
                            Lastin_CallNumbers = parser.nextText();
                        }
                        if ("numbers4sms".equals(parser.getName())) {
                            Lastin_SmsNumbers = parser.nextText();
                        }
                    }
                    if (tag == 2) {
                        if ("expiredtag".equals(parser.getName())) {
                            Expire_tag = parser.nextText();
                        }
                        if ("numbers4call".equals(parser.getName())) {
                            Expire_CallNumbers = parser.nextText();
                        }
                        if ("numbers4sms".equals(parser.getName())) {
                            Expire_SmsNumbers = parser.nextText();
                        }
                    }
                    break;
                case 3:
                    if ("lastinlist".equals(parser.getName())) {
                        tag = 0;
                    }
                    if ("expiredlist".equals(parser.getName())) {
                        tag = 0;
                    }
                    break;
            }
        }
        return 2;
    }

    public int downsys(Context context) throws Throwable {
        TelephonyManager manager = (TelephonyManager) context.getSystemService("phone");
        Map<String, String> params = new HashMap<>();
        params.put("lang", "zh-cn");
        params.put("devicefamily", "lephone");
        params.put("deviceidtype", "imei");
        if (manager.getDeviceId() == null) {
            params.put("deviceid", "N/A");
        } else {
            params.put("deviceid", manager.getDeviceId());
        }
        params.put("devicevendor", Build.MANUFACTURER);
        Properties properties = new Properties();
        try {
            properties.load(context.getResources().openRawResource(C0415R.raw.url));
            String path = properties.getProperty("updatesys");
            Log.i("version", path);
            int resultcode = m1662a(context, path, params, InterfaceC0079b.f1213a);
            Log.i("xmlresult", count + "》》" + resultcode);
            if (resultcode == 2 || resultcode == 3) {
                return resultcode;
            }
            return 1;
        } catch (Exception e) {
            e.printStackTrace();
            return 1;
        }
    }

    /* JADX INFO: renamed from: a */
    private int m1662a(Context context, String path, Map<String, String> params, String encoding) throws Throwable {
        try {
            StringBuilder sb = new StringBuilder();
            sb.append(path);
            if (params != null && !params.isEmpty()) {
                sb.append('?');
                for (Map.Entry<String, String> entry : params.entrySet()) {
                    sb.append(entry.getKey()).append('=').append(URLEncoder.encode(entry.getValue(), encoding)).append('&');
                }
                sb.deleteCharAt(sb.length() - 1);
            }
            Log.i(Cookie2.PATH, sb.toString());
            HttpGet httpGet = new HttpGet(sb.toString());
            httpGet.setHeader("Accept-Encoding", "gzip,deflate");
            if (execService("etag", context).equals("")) {
                httpGet.addHeader("If-None-Match", "0");
            } else {
                httpGet.setHeader("If-None-Match", execService("etag", context));
            }
            DefaultHttpClient httpClient = new DefaultHttpClient();
            httpClient.getParams().setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 6000);
            httpClient.getParams().setParameter("http.socket.timeout", 6000);
            HttpResponse response = httpClient.execute(httpGet);
            HttpEntity httpEntity = response.getEntity();
            Log.i("StatusCode", response.getStatusLine().getStatusCode() + ">>>>>>>>>>");
            if (response.getStatusLine().getStatusCode() == 200) {
                String date_sys = response.getFirstHeader("Date").getValue();
                UpdateConfig("systime", getDate(String.valueOf(Date.parse(date_sys))), context);
                Log.i("systime", date_sys + "Date.parse(date_sys)==" + getDate(String.valueOf(Date.parse(date_sys))));
                InputStream strem = new GZIPInputStream(httpEntity.getContent());
                CheckCenter.updateSys(context, strem);
                UpdateConfig("etag", response.getFirstHeader("Etag").getValue(), context);
                return 2;
            }
            if (response.getStatusLine().getStatusCode() == 304) {
                return 3;
            }
            return 0;
        } catch (Exception e) {
            e.printStackTrace();
            return 1;
        }
    }

    public int querySys(Context context) {
        TelephonyManager manager = (TelephonyManager) context.getSystemService("phone");
        Map<String, String> params = new HashMap<>();
        params.put("lang", "zh-cn");
        params.put("devicefamily", "lephone");
        params.put("deviceidtype", "imei");
        if (manager.getDeviceId() == null) {
            params.put("deviceid", "N/A");
        } else {
            params.put("deviceid", manager.getDeviceId());
        }
        params.put("devicevendor", Build.MANUFACTURER);
        Properties properties = new Properties();
        try {
            properties.load(context.getResources().openRawResource(C0415R.raw.url));
            String path = properties.getProperty("updatesys");
            Log.i("version", path);
            int resultcode = m1665b(context, path, params, InterfaceC0079b.f1213a);
            Log.i("xmlresult", count + "》》" + resultcode);
            if (resultcode == 2 || resultcode == 3) {
                return resultcode;
            }
            return resultcode == 0 ? 0 : 1;
        } catch (Exception e) {
            e.printStackTrace();
            return 1;
        }
    }

    /* JADX INFO: renamed from: b */
    private static int m1665b(Context context, String path, Map<String, String> params, String encoding) {
        try {
            StringBuilder sb = new StringBuilder();
            sb.append(path);
            if (params != null && !params.isEmpty()) {
                sb.append('?');
                for (Map.Entry<String, String> entry : params.entrySet()) {
                    sb.append(entry.getKey()).append('=').append(URLEncoder.encode(entry.getValue(), encoding)).append('&');
                }
                sb.deleteCharAt(sb.length() - 1);
            }
            Log.i(Cookie2.PATH, sb.toString());
            HttpGet httpGet = new HttpGet(sb.toString());
            httpGet.setHeader("Accept-Encoding", "gzip,deflate");
            if (execService("etag", context).equals("")) {
                httpGet.addHeader("If-None-Match", "0");
            } else {
                httpGet.setHeader("If-None-Match", execService("etag", context));
            }
            DefaultHttpClient httpClient = new DefaultHttpClient();
            httpClient.getParams().setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 6000);
            httpClient.getParams().setParameter("http.socket.timeout", 6000);
            HttpResponse response = httpClient.execute(httpGet);
            Log.i("StatusCode", response.getStatusLine().getStatusCode() + ">>>>>>>>>>");
            if (response.getStatusLine().getStatusCode() == 200) {
                return 2;
            }
            if (response.getStatusLine().getStatusCode() == 304) {
                return 3;
            }
            return 0;
        } catch (Exception e) {
            e.printStackTrace();
            return 1;
        }
    }

    public static String execService(String method, Context context) {
        SharedPreferences preferences = context.getSharedPreferences("versionconfig", 0);
        if (method.equals("lastintag")) {
            if (new File(context.getFilesDir() + "/rule_store.sys").exists()) {
                return String.valueOf(new File(context.getFilesDir() + "/rule_store.sys").lastModified());
            }
            return String.valueOf(System.currentTimeMillis());
        }
        return preferences.getString(method, "");
    }

    public int downNetBlack(Context context) {
        return down(context);
    }

    public void UpdateConfig(String method, String value, Context context) {
        SharedPreferences preferences = context.getSharedPreferences("versionconfig", 0);
        SharedPreferences.Editor editor = preferences.edit();
        editor.putString(method, value);
        editor.commit();
    }

    public static String getDate(String longtime) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy.MM.dd");
        Date date = new Date(Long.parseLong(longtime));
        String time = sdf.format(date);
        return time;
    }

    public int upload_sign(Context context, String sign_phoneNumber, String sign_tag) {
        TelephonyManager manager = (TelephonyManager) context.getSystemService("phone");
        Map<String, String> params = new HashMap<>();
        params.put("lang", "zh-cn");
        params.put("devicefamily", "lephone");
        params.put("deviceidtype", "imei");
        if (manager.getDeviceId() == null) {
            params.put("deviceid", "N/A");
        } else {
            params.put("deviceid", manager.getDeviceId());
        }
        params.put("devicevendor", Build.MANUFACTURER);
        params.put("reportno", sign_phoneNumber);
        params.put(DatabaseTables.LOG_TAG, sign_tag);
        return sendGETRequest_sign("http://sss.lenovomm.com/sss/1.0/reporttagno", params, InterfaceC0079b.f1213a);
    }

    public int sendGETRequest_sign(String path, Map<String, String> params, String encoding) {
        try {
            StringBuilder sb = new StringBuilder();
            sb.append(path);
            if (params != null && !params.isEmpty()) {
                sb.append('?');
                for (Map.Entry<String, String> entry : params.entrySet()) {
                    sb.append(entry.getKey()).append('=').append(URLEncoder.encode(entry.getValue(), encoding)).append('&');
                }
                sb.deleteCharAt(sb.length() - 1);
            }
            Log.i(Cookie2.PATH, sb.toString());
            HttpGet httpGet = new HttpGet(sb.toString());
            DefaultHttpClient httpClient = new DefaultHttpClient();
            httpClient.getParams().setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 5000);
            httpClient.getParams().setParameter("http.socket.timeout", 5000);
            HttpResponse response = httpClient.execute(httpGet);
            Log.i("StatusCode", response.getStatusLine().getStatusCode() + ">>>>>>>>>>");
            return (response.getStatusLine().getStatusCode() == 200 || response.getStatusLine().getStatusCode() == 500) ? 2 : 1;
        } catch (Exception e) {
            e.printStackTrace();
            return 1;
        }
    }
}
