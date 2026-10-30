package com.tendcloud.tenddata;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.zip.GZIPOutputStream;
import org.apache.http.HttpHost;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.conn.scheme.PlainSocketFactory;
import org.apache.http.conn.scheme.Scheme;
import org.apache.http.conn.scheme.SchemeRegistry;
import org.apache.http.entity.ByteArrayEntity;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;

/* JADX INFO: renamed from: com.tendcloud.tenddata.o */
/* JADX INFO: loaded from: classes.dex */
public final class C0083o {

    /* JADX INFO: renamed from: a */
    private static final String f158a = "http://tdcv3.talkingdata.net";

    /* JADX INFO: renamed from: b */
    private static final String f159b = "/g/d";

    /* JADX INFO: renamed from: c */
    private static final int f160c = 60000;

    /* JADX INFO: renamed from: d */
    private static final boolean f161d = true;

    /* JADX INFO: renamed from: a */
    static DefaultHttpClient m74a() {
        HttpHost httpHostM185d;
        int i = f160c;
        boolean zM181b = C0089u.m181b();
        new SchemeRegistry().register(new Scheme("http", PlainSocketFactory.getSocketFactory(), 80));
        BasicHttpParams basicHttpParams = new BasicHttpParams();
        HttpConnectionParams.setConnectionTimeout(basicHttpParams, zM181b ? f160c : 120000);
        if (!zM181b) {
            i = 120000;
        }
        HttpConnectionParams.setSoTimeout(basicHttpParams, i);
        DefaultHttpClient defaultHttpClient = new DefaultHttpClient(basicHttpParams);
        if (!zM181b && C0089u.m182c() && (httpHostM185d = C0089u.m185d()) != null) {
            defaultHttpClient.getParams().setParameter("http.route.default-proxy", httpHostM185d);
        }
        return defaultHttpClient;
    }

    /* JADX INFO: renamed from: a */
    static boolean m75a(C0069ah c0069ah) throws IOException {
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
        GZIPOutputStream gZIPOutputStream = new GZIPOutputStream(byteArrayOutputStream);
        new C0084p(gZIPOutputStream).m90a(c0069ah);
        gZIPOutputStream.finish();
        gZIPOutputStream.flush();
        return m76a(f159b, byteArrayOutputStream.toByteArray(), f161d);
    }

    /* JADX INFO: renamed from: a */
    static boolean m76a(String str, byte[] bArr, boolean z) {
        DefaultHttpClient defaultHttpClientM74a = m74a();
        try {
            HttpPost httpPost = new HttpPost(f158a + str);
            ByteArrayEntity byteArrayEntity = new ByteArrayEntity(bArr);
            byteArrayEntity.setContentType("application/unpack_chinar");
            httpPost.setEntity(byteArrayEntity);
            if (defaultHttpClientM74a.execute(httpPost).getStatusLine().getStatusCode() == 200) {
                return f161d;
            }
            return false;
        } catch (Exception e) {
        }
    }
}
