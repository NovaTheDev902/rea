package com.tencent.lbsapi.p013a;

import android.content.Context;
import android.database.Cursor;
import android.net.ConnectivityManager;
import android.net.Proxy;
import android.net.Uri;
import java.io.IOException;
import java.net.InetSocketAddress;
import org.apache.commons.httpclient.cookie.Cookie2;
import org.apache.http.HttpEntity;
import org.apache.http.HttpHost;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.methods.HttpRequestBase;
import org.apache.http.entity.ByteArrayEntity;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicHeader;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.util.EntityUtils;

/* JADX INFO: renamed from: com.tencent.lbsapi.a.c */
/* JADX INFO: loaded from: classes.dex */
public class C1059c {

    /* JADX INFO: renamed from: a */
    public static final String f5901a = "POST";

    /* JADX INFO: renamed from: b */
    public static final String f5902b = "GET";

    /* JADX INFO: renamed from: i */
    private static Uri f5909i = Uri.parse("content://telephony/carriers/preferapn");

    /* JADX INFO: renamed from: c */
    protected static String f5903c = "ctnet";

    /* JADX INFO: renamed from: d */
    protected static String f5904d = "ctwap";

    /* JADX INFO: renamed from: e */
    protected static String f5905e = "cmnet";

    /* JADX INFO: renamed from: f */
    protected static String f5906f = "cmwap";

    /* JADX INFO: renamed from: g */
    protected static String f5907g = "uninet";

    /* JADX INFO: renamed from: h */
    protected static String f5908h = "uniwap";

    /* JADX WARN: Code duplicated, block: B:25:0x006b A[PHI: r0 r2
  0x006b: PHI (r0v9 int) = (r0v6 int), (r0v5 int) binds: [B:22:0x005c, B:17:0x0046] A[DONT_GENERATE, DONT_INLINE]
  0x006b: PHI (r2v4 java.lang.String) = (r2v1 java.lang.String), (r2v0 java.lang.String) binds: [B:22:0x005c, B:17:0x0046] A[DONT_GENERATE, DONT_INLINE]] */
    /* JADX INFO: renamed from: a */
    protected static InetSocketAddress m2492a(Context context) {
        String defaultHost;
        int defaultPort;
        if (context == null) {
            defaultHost = Proxy.getDefaultHost();
            defaultPort = Proxy.getDefaultPort();
        } else {
            if (((ConnectivityManager) context.getSystemService("connectivity")).getActiveNetworkInfo().getType() != 0) {
                return null;
            }
            String host = Proxy.getHost(context);
            int port = Proxy.getPort(context);
            if (host == null || host.trim().length() == 0 || port <= 0) {
                host = Proxy.getDefaultHost();
                port = Proxy.getDefaultPort();
                if (host == null || host.trim().length() == 0 || port <= 0) {
                    C1061e c1061eM2494b = m2494b(context);
                    defaultHost = c1061eM2494b.f5911a;
                    defaultPort = c1061eM2494b.f5912b;
                } else {
                    defaultHost = host;
                    defaultPort = port;
                }
            } else {
                defaultHost = host;
                defaultPort = port;
            }
        }
        return (defaultHost == null || defaultHost.trim().length() <= 0) ? null : new InetSocketAddress(defaultHost, defaultPort);
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m2493a(String str, byte[] bArr, String str2, BasicHeader[] basicHeaderArr, Context context) throws IOException {
        HttpEntity httpEntityM2495b = m2495b(str, bArr, str2, basicHeaderArr, context);
        if (httpEntityM2495b == null) {
            return null;
        }
        byte[] byteArray = EntityUtils.toByteArray(httpEntityM2495b);
        httpEntityM2495b.consumeContent();
        return byteArray;
    }

    /* JADX INFO: renamed from: b */
    private static C1061e m2494b(Context context) {
        C1061e c1061e = new C1061e();
        try {
            try {
                Cursor cursorQuery = context.getContentResolver().query(f5909i, null, null, null, null);
                cursorQuery.moveToFirst();
                String string = cursorQuery.getString(cursorQuery.getColumnIndex("proxy"));
                if (string != null) {
                    string.toLowerCase();
                }
                String string2 = cursorQuery.getString(cursorQuery.getColumnIndex(Cookie2.PORT));
                String string3 = cursorQuery.getString(cursorQuery.getColumnIndex("apn"));
                if (string3 != null) {
                    string3.toLowerCase();
                }
                cursorQuery.close();
                if (string3 == null || !string3.startsWith(f5904d)) {
                    if (string3 == null || !string3.startsWith(f5906f)) {
                        if (string3 != null && string3.startsWith(f5908h)) {
                            if (string == null || string.length() <= 0 || Integer.valueOf(string2).intValue() >= 0) {
                                c1061e.f5911a = "10.0.0.172";
                                c1061e.f5912b = 80;
                            } else {
                                c1061e.f5911a = string;
                                c1061e.f5912b = Integer.valueOf(string2).intValue();
                            }
                        }
                    } else if (string == null || string.length() <= 0 || Integer.valueOf(string2).intValue() >= 0) {
                        c1061e.f5911a = "10.0.0.172";
                        c1061e.f5912b = 80;
                    } else {
                        c1061e.f5911a = string;
                        c1061e.f5912b = Integer.valueOf(string2).intValue();
                    }
                } else if (string == null || string.length() <= 0 || Integer.valueOf(string2).intValue() >= 0) {
                    c1061e.f5911a = "10.0.0.200";
                    c1061e.f5912b = 80;
                } else {
                    c1061e.f5911a = string;
                    c1061e.f5912b = Integer.valueOf(string2).intValue();
                }
                return c1061e;
            } catch (Exception e) {
                e.printStackTrace();
                return c1061e;
            }
        } catch (Throwable th) {
            return c1061e;
        }
    }

    /* JADX INFO: renamed from: b */
    protected static HttpEntity m2495b(String str, byte[] bArr, String str2, BasicHeader[] basicHeaderArr, Context context) {
        HttpRequestBase httpGet;
        String host;
        int port;
        BasicHttpParams basicHttpParams = new BasicHttpParams();
        HttpConnectionParams.setConnectionTimeout(basicHttpParams, 10000);
        HttpConnectionParams.setSoTimeout(basicHttpParams, 10000);
        ByteArrayEntity byteArrayEntity = new ByteArrayEntity(bArr);
        if (str2.equals("POST")) {
            HttpPost httpPost = new HttpPost(str);
            httpPost.setEntity(byteArrayEntity);
            httpGet = httpPost;
        } else {
            httpGet = new HttpGet(str + "?" + new String(bArr));
        }
        if (basicHeaderArr != null) {
            for (BasicHeader basicHeader : basicHeaderArr) {
                httpGet.addHeader(basicHeader);
            }
        }
        DefaultHttpClient defaultHttpClient = new DefaultHttpClient(basicHttpParams);
        if (m2492a(context) != null) {
            Proxy.getDefaultHost();
            Proxy.getDefaultPort();
            if (context == null) {
                host = Proxy.getDefaultHost();
                port = Proxy.getDefaultPort();
            } else {
                host = Proxy.getHost(context);
                port = Proxy.getPort(context);
                if (host == null || host.trim().length() == 0 || port <= 0) {
                    host = Proxy.getDefaultHost();
                    port = Proxy.getDefaultPort();
                }
            }
            if (host == null || host.trim().length() == 0 || port <= 0) {
                C1061e c1061eM2494b = m2494b(context);
                host = c1061eM2494b.f5911a;
                port = c1061eM2494b.f5912b;
            }
            defaultHttpClient.getParams().setParameter("http.route.default-proxy", new HttpHost(host, port));
        }
        try {
            HttpResponse httpResponseExecute = defaultHttpClient.execute(httpGet);
            int statusCode = httpResponseExecute.getStatusLine().getStatusCode();
            if (statusCode != 200) {
                throw new C1060d(statusCode);
            }
            return httpResponseExecute.getEntity();
        } catch (Exception e) {
            return null;
        }
    }
}
