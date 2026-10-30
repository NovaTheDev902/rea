package com.lenovo.safecenter.lenovoAntiSpam.utils;

import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.net.Uri;
import android.os.Build;
import android.provider.Settings;
import android.telephony.TelephonyManager;
import android.util.Log;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.utils.Untils;
import java.net.URLEncoder;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;
import org.apache.commons.httpclient.cookie.Cookie2;
import org.apache.commons.httpclient.params.HttpConnectionParams;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

/* JADX INFO: loaded from: classes.dex */
public class SafeCenter {
    public static int count = 0;
    public static final int net_disconnect = 1;
    public static final int server_disconnect = 0;
    public static final int upload_success = 2;

    /* JADX INFO: renamed from: a */
    private static int m1667a(String path, Map<String, String> params, String encoding) {
        try {
            StringBuilder sb = new StringBuilder();
            sb.append(path);
            if (params != null && !params.isEmpty()) {
                sb.append('?');
                for (Map.Entry<String, String> entry : params.entrySet()) {
                    Log.i(Cookie2.PATH, entry.getKey() + "===" + entry.getValue());
                    sb.append(entry.getKey()).append('=').append(URLEncoder.encode(entry.getValue(), encoding)).append('&');
                }
                sb.deleteCharAt(sb.length() - 1);
                Log.i(Cookie2.PATH, sb.toString());
            }
            HttpGet httpGet = new HttpGet(sb.toString());
            DefaultHttpClient httpClient = new DefaultHttpClient();
            httpClient.getParams().setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 6000);
            httpClient.getParams().setParameter("http.socket.timeout", 6000);
            HttpResponse response = httpClient.execute(httpGet);
            return response.getStatusLine().getStatusCode();
        } catch (Exception e) {
            e.printStackTrace();
            return 1;
        }
    }

    public static int upBlackToNet(Context context, String numberlist, int type) {
        try {
            Map<String, String> params = new HashMap<>();
            TelephonyManager manager = (TelephonyManager) context.getSystemService("phone");
            int size = numberlist.split(",").length;
            params.put("reportno", numberlist.replaceAll("-", "").replaceAll(" ", ""));
            params.put("waytype", String.valueOf(type));
            params.put("lang", "zh-cn");
            params.put("contenttype", getContentType(size));
            params.put(AppDatabase.CONTENT, getContent(size));
            params.put("devicefamily", "lephone");
            params.put("deviceidtype", "imei");
            if (manager.getDeviceId() == null) {
                params.put("deviceid", "N/A");
            } else {
                params.put("deviceid", manager.getDeviceId());
            }
            params.put("devicevendor", Build.MANUFACTURER);
            Properties properties = new Properties();
            properties.load(context.getResources().openRawResource(C0415R.raw.url));
            String path = properties.getProperty("uploadNetBlack");
            int returnCode = m1667a(path, params, InterfaceC0079b.f1213a);
            return returnCode == 200 ? 2 : 1;
        } catch (Exception e) {
            e.printStackTrace();
            return 1;
        }
    }

    public static String getContentType(int size) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < size; i++) {
            sb.append(-1).append(Untils.PAUSE);
        }
        return sb.deleteCharAt(sb.length() - 1).toString();
    }

    public static String getContent(int size) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < size; i++) {
            sb.append("N/A").append('|');
        }
        return sb.deleteCharAt(sb.length() - 1).toString();
    }

    public static void setPathUrl(Context context) {
        try {
            Properties properties = new Properties();
            properties.load(context.getResources().openRawResource(C0415R.raw.url));
            String newDownPath = properties.getProperty("downNETBLACK");
            String newUploadPath = properties.getProperty("uploadNetBlack");
            String path = Settings.System.getString(context.getContentResolver(), "upload_netBlack_url");
            if (path == null || !path.equals(newUploadPath)) {
                Settings.System.putString(context.getContentResolver(), "down_netBlack_url", newDownPath);
                Settings.System.putString(context.getContentResolver(), "upload_netBlack_url", newUploadPath);
            }
            String str = Settings.System.getString(context.getContentResolver(), "down_netBlack_url");
            String str1 = Settings.System.getString(context.getContentResolver(), "upload_netBlack_url");
            Log.i("resultmes", "down===" + str + "|||upload==" + str1);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static int findBlack(Context context, int type, String number) {
        try {
            if (CheckCenter.isLocalBlack(context, type, number)) {
                return 1;
            }
            return CheckCenter.isNetBlack(context, type, number) ? 2 : 0;
        } catch (Exception e) {
            return 0;
        }
    }

    public static boolean isIntercept(Context context, String number) {
        ContentResolver resolver = context.getContentResolver();
        int mode = Settings.System.getInt(resolver, "intercall_mode_type", 0);
        if (mode == 2) {
            return false;
        }
        if (mode != 0) {
            return mode == 1 && !CheckCenter.isWhitePerson(context, number);
        }
        int black_mode = findBlack(context, 1, number);
        if (black_mode == 0) {
            return false;
        }
        if (black_mode == 1) {
            int local_mode = Settings.System.getInt(resolver, "localBlackCall_mode_on", 1);
            return local_mode == 1;
        }
        if (black_mode != 2) {
            return false;
        }
        int net_mode = Settings.System.getInt(resolver, "netBlackCall_mode_on", 0);
        return net_mode == 1;
    }

    public static void AddPhoneLog(Context context, String number, long datetime) {
        ContentResolver resolver = context.getContentResolver();
        Uri uri = Uri.parse("content://com.lenovo.safecenter.HarassProvider/safe_log_harass");
        ContentValues values = new ContentValues();
        values.put(AppDatabase.NUMBER, number);
        values.put(AppDatabase.TIME, String.valueOf(datetime));
        resolver.insert(uri, values);
    }
}
