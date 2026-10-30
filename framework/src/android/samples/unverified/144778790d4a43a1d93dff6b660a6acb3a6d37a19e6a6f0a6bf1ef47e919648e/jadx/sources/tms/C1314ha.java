package tms;

import QQPIM.BrowserClient;
import QQPIM.BrowserResult;
import QQPIM.BrowserUrl;
import QQPIM.ConnectType;
import QQPIM.EModelID;
import QQPIM.RspTemplate;
import QQPIM.UrlCheckResponse;
import android.content.Context;
import android.net.Proxy;
import com.tencent.tccdb.TccCryptor;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.wupsession.WupConfig;
import com.tencent.tmsecure.module.wupsession.WupSessionManager;
import com.tencent.tmsecure.utils.Base64;
import com.tencent.tmsecure.utils.Log;
import com.tencent.tmsecure.utils.NetworkUtil;
import com.tencent.tmsecure.utils.PhoneInfoUtil;
import com.tencent.tmsecure.utils.StringUtil;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.atomic.AtomicReference;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.http.HttpEntity;
import org.apache.http.HttpHost;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.params.HttpClientParams;
import org.apache.http.conn.ClientConnectionManager;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;

/* JADX INFO: renamed from: tms.ha */
/* JADX INFO: loaded from: classes.dex */
public final class C1314ha extends BaseManager {

    /* JADX INFO: renamed from: e */
    private static final String[] f7431e = {"paipai.com", "tencent.com", "soso.com", "qq.com", "baidu.mobi", "baidu.com", "taobao.com", "kanshula.com.cn", "kanshu.la", "read.xxsy.net", "t.sina.cn", "sina.cn", "mop.com", "xs8.cn", "t.qunar.com", "qidian.com", "easou.com", "hongxiu.com", "ifeng.com", "google.com.hk", "google.com", "google.cn", "tianya.cn", "bbs.dospy.com", "58.com", "17k.com", "sogou.com", "weibo.com", "renren.com", "sohu.com", "163.com", "sina.com.cn"};

    /* JADX INFO: renamed from: a */
    private Context f7432a;

    /* JADX INFO: renamed from: b */
    private String[] f7433b;

    /* JADX INFO: renamed from: c */
    private LinkedHashMap<Long, UrlCheckResponse> f7434c;

    /* JADX INFO: renamed from: d */
    private long f7435d;

    /* JADX INFO: renamed from: tms.ha$a */
    class a {

        /* JADX INFO: renamed from: a */
        public String f7436a;

        /* JADX INFO: renamed from: b */
        public int f7437b;

        private a() {
        }

        /* synthetic */ a(C1314ha c1314ha, byte b) {
            this();
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r2v0 */
    /* JADX WARN: Type inference failed for: r2v1 */
    /* JADX WARN: Type inference failed for: r2v19 */
    /* JADX WARN: Type inference failed for: r2v2, types: [java.io.ByteArrayOutputStream] */
    /* JADX WARN: Type inference failed for: r2v29 */
    /* JADX WARN: Type inference failed for: r2v30 */
    /* JADX WARN: Type inference failed for: r2v31 */
    /* JADX WARN: Type inference failed for: r2v32 */
    /* JADX WARN: Type inference failed for: r2v6 */
    /* JADX WARN: Type inference failed for: r2v7 */
    /* JADX WARN: Type inference failed for: r3v10 */
    /* JADX WARN: Type inference failed for: r3v11, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r3v12, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r3v13, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r3v14, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r3v15 */
    /* JADX WARN: Type inference failed for: r3v20, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r3v23 */
    /* JADX WARN: Type inference failed for: r3v24 */
    /* JADX WARN: Type inference failed for: r3v25 */
    /* JADX WARN: Type inference failed for: r3v26 */
    /* JADX WARN: Type inference failed for: r3v27 */
    /* JADX WARN: Type inference failed for: r3v28 */
    /* JADX WARN: Type inference failed for: r3v29 */
    /* JADX WARN: Type inference failed for: r3v30 */
    /* JADX WARN: Type inference failed for: r3v31 */
    /* JADX WARN: Type inference failed for: r3v32 */
    /* JADX WARN: Type inference failed for: r3v33 */
    /* JADX WARN: Type inference failed for: r3v34 */
    /* JADX WARN: Type inference failed for: r3v5 */
    /* JADX WARN: Type inference failed for: r3v6 */
    /* JADX WARN: Type inference failed for: r3v7 */
    /* JADX WARN: Type inference failed for: r3v8 */
    /* JADX WARN: Type inference failed for: r3v9 */
    /* JADX INFO: renamed from: a */
    private static int m3452a(String str, a aVar) throws Throwable {
        IOException iOException;
        ?? r3;
        ClientProtocolException clientProtocolException;
        ?? r4;
        URISyntaxException uRISyntaxException;
        ?? r5;
        ClientConnectionManager connectionManager;
        ?? r2 = 0;
        byteArrayOutputStream = null;
        byteArrayOutputStream = null;
        byteArrayOutputStream = null;
        ByteArrayOutputStream byteArrayOutputStream = null;
        ByteArrayOutputStream byteArrayOutputStream2 = null;
        ByteArrayOutputStream byteArrayOutputStream3 = null;
        r2 = 0;
        int i = 0;
        BasicHttpParams basicHttpParams = new BasicHttpParams();
        HttpConnectionParams.setConnectionTimeout(basicHttpParams, 10000);
        HttpConnectionParams.setSoTimeout(basicHttpParams, EModelID._EMID_Secure_Begin);
        HttpConnectionParams.setSocketBufferSize(basicHttpParams, 4096);
        HttpClientParams.setRedirecting(basicHttpParams, true);
        DefaultHttpClient defaultHttpClient = new DefaultHttpClient(basicHttpParams);
        ConnectType networkType = NetworkUtil.getNetworkType();
        ConnectType connectType = ConnectType.CT_GPRS_WAP;
        ?? content = connectType;
        if (networkType == connectType) {
            defaultHttpClient.getParams().setParameter("http.route.default-proxy", new HttpHost(Proxy.getDefaultHost(), Proxy.getDefaultPort()));
            content = "http.route.default-proxy";
        }
        HttpGet httpGet = new HttpGet();
        try {
            try {
                httpGet.setURI(new URI(str));
                HttpResponse httpResponseExecute = defaultHttpClient.execute(httpGet);
                httpResponseExecute.getStatusLine().getStatusCode();
                HttpEntity entity = httpResponseExecute.getEntity();
                aVar.f7437b = (int) entity.getContentLength();
                content = entity.getContent();
                try {
                    byte[] bArr = new byte[1024];
                    ByteArrayOutputStream byteArrayOutputStream4 = new ByteArrayOutputStream();
                    int i2 = 0;
                    while (i2 < 2048) {
                        try {
                            int i3 = content.read(bArr);
                            if (i3 == -1) {
                                break;
                            }
                            if (i2 + i3 > 2048) {
                                i3 = 2048 - i2;
                            }
                            byteArrayOutputStream4.write(bArr, 0, i3);
                            i2 = i3 + i2;
                        } catch (ClientProtocolException e) {
                            byteArrayOutputStream2 = byteArrayOutputStream4;
                            clientProtocolException = e;
                            r4 = content;
                            i = -3051;
                            clientProtocolException.printStackTrace();
                            if (r4 != 0) {
                                try {
                                    r4.close();
                                } catch (IOException e2) {
                                    e2.printStackTrace();
                                }
                            }
                            if (byteArrayOutputStream2 != null) {
                                try {
                                    byteArrayOutputStream2.close();
                                } catch (IOException e3) {
                                    e3.printStackTrace();
                                }
                            }
                            connectionManager = defaultHttpClient.getConnectionManager();
                            r2 = byteArrayOutputStream2;
                            content = r4;
                        } catch (IOException e4) {
                            byteArrayOutputStream3 = byteArrayOutputStream4;
                            iOException = e4;
                            r3 = content;
                            i = -3056;
                            iOException.printStackTrace();
                            if (r3 != 0) {
                                try {
                                    r3.close();
                                } catch (IOException e5) {
                                    e5.printStackTrace();
                                }
                            }
                            if (byteArrayOutputStream3 != null) {
                                try {
                                    byteArrayOutputStream3.close();
                                } catch (IOException e6) {
                                    e6.printStackTrace();
                                }
                            }
                            connectionManager = defaultHttpClient.getConnectionManager();
                            r2 = byteArrayOutputStream3;
                            content = r3;
                        } catch (URISyntaxException e7) {
                            byteArrayOutputStream = byteArrayOutputStream4;
                            uRISyntaxException = e7;
                            r5 = content;
                            i = -3053;
                            uRISyntaxException.printStackTrace();
                            if (r5 != 0) {
                                try {
                                    r5.close();
                                } catch (IOException e8) {
                                    e8.printStackTrace();
                                }
                            }
                            if (byteArrayOutputStream != null) {
                                try {
                                    byteArrayOutputStream.close();
                                } catch (IOException e9) {
                                    e9.printStackTrace();
                                }
                            }
                            connectionManager = defaultHttpClient.getConnectionManager();
                            r2 = byteArrayOutputStream;
                            content = r5;
                        } catch (Throwable th) {
                            th = th;
                            r2 = byteArrayOutputStream4;
                            if (content != 0) {
                                try {
                                    content.close();
                                } catch (IOException e10) {
                                    e10.printStackTrace();
                                }
                            }
                            if (r2 != 0) {
                                try {
                                    r2.close();
                                } catch (IOException e11) {
                                    e11.printStackTrace();
                                }
                            }
                            defaultHttpClient.getConnectionManager().shutdown();
                            throw th;
                        }
                    }
                    String strM2878c = C1148ae.m2878c(byteArrayOutputStream4.toByteArray());
                    aVar.f7436a = strM2878c;
                    Object obj = strM2878c;
                    if (content != 0) {
                        try {
                            content.close();
                            obj = strM2878c;
                        } catch (IOException e12) {
                            e12.printStackTrace();
                            obj = e12;
                        }
                    }
                    if (byteArrayOutputStream4 != null) {
                        try {
                            byteArrayOutputStream4.close();
                        } catch (IOException e13) {
                            e13.printStackTrace();
                        }
                    }
                    connectionManager = defaultHttpClient.getConnectionManager();
                    r2 = obj;
                    content = content;
                } catch (ClientProtocolException e14) {
                    clientProtocolException = e14;
                    r4 = content;
                } catch (IOException e15) {
                    iOException = e15;
                    r3 = content;
                } catch (URISyntaxException e16) {
                    uRISyntaxException = e16;
                    r5 = content;
                }
            } catch (Throwable th2) {
                th = th2;
            }
        } catch (URISyntaxException e17) {
            uRISyntaxException = e17;
            r5 = 0;
        } catch (ClientProtocolException e18) {
            clientProtocolException = e18;
            r4 = 0;
        } catch (IOException e19) {
            iOException = e19;
            r3 = 0;
        } catch (Throwable th3) {
            th = th3;
            content = 0;
        }
        connectionManager.shutdown();
        return i;
    }

    /* JADX INFO: renamed from: a */
    private static String m3453a(Context context, String[] strArr) {
        StringBuffer stringBuffer = new StringBuffer();
        int i = 0;
        while (i < strArr.length - 1) {
            stringBuffer.append(strArr[i] + "|");
            i++;
        }
        stringBuffer.append(strArr[i]);
        byte[] bArrEncrypt = TccCryptor.encrypt(context, stringBuffer.toString().getBytes(), (byte[]) null);
        if (bArrEncrypt != null) {
            return Base64.encodeToString(bArrEncrypt, 0);
        }
        return null;
    }

    /* JADX INFO: renamed from: a */
    private void m3454a() {
        long jCurrentTimeMillis = System.currentTimeMillis();
        if (this.f7435d == 0 || jCurrentTimeMillis - this.f7435d < 21600000) {
            return;
        }
        Iterator<Long> it = this.f7434c.keySet().iterator();
        while (it.hasNext()) {
            long jLongValue = it.next().longValue();
            this.f7435d = jLongValue;
            if (jCurrentTimeMillis - jLongValue < 21600000) {
                break;
            } else {
                it.remove();
            }
        }
        if (this.f7434c.size() == 0) {
            this.f7435d = 0L;
        }
    }

    /* JADX INFO: renamed from: a */
    private static String[] m3455a(Context context, String str) {
        byte[] bArrDecrypt;
        if (str == null || (bArrDecrypt = TccCryptor.decrypt(context, Base64.decode(str, 0), null)) == null) {
            return null;
        }
        return new String(bArrDecrypt).split("\\|");
    }

    /* JADX INFO: renamed from: c */
    private static String m3456c(String str) {
        int iIndexOf = str.indexOf("://");
        if (-1 != iIndexOf) {
            str = str.substring(iIndexOf + 3);
        }
        int iIndexOf2 = str.indexOf(CookieSpec.PATH_DELIM);
        if (-1 != iIndexOf2) {
            str = str.substring(0, iIndexOf2);
        }
        int iIndexOf3 = str.indexOf("?");
        if (-1 != iIndexOf3) {
            str = str.substring(0, iIndexOf3);
        }
        return str.toLowerCase();
    }

    /* JADX INFO: renamed from: a */
    public final UrlCheckResponse m3457a(String str) {
        if (str == null || str.length() == 0) {
            return new UrlCheckResponse(str, -1, 0, 0, "");
        }
        String strM3456c = m3456c(str);
        if (strM3456c.length() != 0) {
            for (String str2 : this.f7433b) {
                if (strM3456c.endsWith(str2)) {
                    return new UrlCheckResponse(str, 0, 0, 0, "");
                }
            }
        }
        m3454a();
        for (UrlCheckResponse urlCheckResponse : this.f7434c.values()) {
            if (str.equalsIgnoreCase(urlCheckResponse.getUrl())) {
                return urlCheckResponse;
            }
        }
        AtomicReference<UrlCheckResponse> atomicReference = new AtomicReference<>();
        if (((WupSessionManager) ManagerCreator.getManager(WupSessionManager.class)).checkUrl(str, atomicReference) != 0) {
            return new UrlCheckResponse(str, -1, 0, 0, "");
        }
        UrlCheckResponse urlCheckResponse2 = atomicReference.get();
        if (urlCheckResponse2 == null || urlCheckResponse2.url.length() == 0) {
            return new UrlCheckResponse(str, -1, 0, 0, "");
        }
        long jCurrentTimeMillis = System.currentTimeMillis();
        this.f7434c.put(Long.valueOf(jCurrentTimeMillis), urlCheckResponse2);
        if (this.f7435d != 0) {
            return urlCheckResponse2;
        }
        this.f7435d = jCurrentTimeMillis;
        return urlCheckResponse2;
    }

    /* JADX WARN: Code duplicated, block: B:21:0x0057 A[PHI: r0
  0x0057: PHI (r0v18 boolean) = (r0v3 boolean), (r0v29 boolean) binds: [B:11:0x0030, B:17:0x004d] A[DONT_GENERATE, DONT_INLINE]] */
    /* JADX WARN: Code duplicated, block: B:24:0x006b  */
    /* JADX WARN: Code duplicated, block: B:28:0x0081  */
    /* JADX WARN: Code duplicated, block: B:29:0x0083  */
    /* JADX WARN: Code duplicated, block: B:58:0x0111 A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:59:0x007b A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:60:? A[LOOP:2: B:22:0x0065->B:60:?, LOOP_END, SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    public final Map<String, UrlCheckResponse> m3458a(List<String> list) {
        ArrayList<UrlCheckResponse> rspTemp;
        boolean z;
        Iterator<UrlCheckResponse> it;
        UrlCheckResponse next;
        if (list == null || list.size() == 0) {
            return new HashMap(0);
        }
        int size = list.size();
        HashMap map = new HashMap(size);
        ArrayList<String> arrayList = new ArrayList(1);
        boolean z2 = false;
        for (int i = 0; i < size; i++) {
            String str = list.get(i);
            String strM3456c = m3456c(str);
            if (strM3456c.length() != 0) {
                for (String str2 : this.f7433b) {
                    if (strM3456c.endsWith(str2)) {
                        map.put(str, new UrlCheckResponse(str, 0, 0, 0, ""));
                        z2 = true;
                        break;
                    }
                }
                if (z2) {
                    z2 = false;
                } else {
                    z = z2;
                    m3454a();
                    it = this.f7434c.values().iterator();
                    while (true) {
                        if (it.hasNext()) {
                            z2 = z;
                            break;
                        }
                        next = it.next();
                        if (str.equalsIgnoreCase(next.getUrl())) {
                            map.put(str, next);
                            z2 = true;
                            break;
                        }
                    }
                    if (z2) {
                        z2 = false;
                    } else {
                        arrayList.add(str);
                    }
                }
            } else {
                z = z2;
                m3454a();
                it = this.f7434c.values().iterator();
                while (true) {
                    if (it.hasNext()) {
                        z2 = z;
                        break;
                    }
                    next = it.next();
                    if (str.equalsIgnoreCase(next.getUrl())) {
                        map.put(str, next);
                        z2 = true;
                        break;
                    }
                }
                if (z2) {
                    z2 = false;
                } else {
                    arrayList.add(str);
                }
            }
        }
        if (arrayList.size() == 0) {
            return map;
        }
        AtomicReference<RspTemplate> atomicReference = new AtomicReference<>();
        int size2 = arrayList.size();
        ((WupSessionManager) ManagerCreator.getManager(WupSessionManager.class)).checkUrlEx(arrayList, atomicReference);
        HashMap map2 = new HashMap(size2);
        for (String str3 : arrayList) {
            map2.put(str3, new UrlCheckResponse(str3, -1, 0, 0, ""));
        }
        arrayList.clear();
        RspTemplate rspTemplate = atomicReference.get();
        if (rspTemplate == null || (rspTemp = rspTemplate.getRspTemp()) == null || rspTemp.size() == 0) {
            map.putAll(map2);
            return map;
        }
        int size3 = rspTemp.size();
        for (int i2 = 0; i2 < size3; i2++) {
            UrlCheckResponse urlCheckResponse = rspTemp.get(i2);
            map2.put(urlCheckResponse.url, urlCheckResponse);
            long jCurrentTimeMillis = System.currentTimeMillis();
            this.f7434c.put(Long.valueOf(jCurrentTimeMillis), urlCheckResponse);
            if (this.f7435d == 0) {
                this.f7435d = jCurrentTimeMillis;
            }
        }
        return map;
    }

    /* JADX INFO: renamed from: b */
    public final int m3459b(String str) throws Throwable {
        BrowserResult browserResult;
        a aVar = new a(this, (byte) 0);
        int iM3452a = m3452a(str, aVar);
        if (iM3452a != 0) {
            return iM3452a;
        }
        BrowserClient browserClient = new BrowserClient(13, "1.0.0", StringUtil.assertNotNullString(PhoneInfoUtil.getIMEI(this.f7432a)), WupConfig.KEY_GUID, "ua");
        BrowserUrl browserUrl = new BrowserUrl(str, aVar.f7436a, aVar.f7437b);
        AtomicReference<BrowserResult> atomicReference = new AtomicReference<>();
        int iBrowerCheck = ((WupSessionManager) ManagerCreator.getManager(WupSessionManager.class)).browerCheck(browserClient, browserUrl, atomicReference);
        if (iBrowerCheck == 0 && (browserResult = atomicReference.get()) != null) {
            Log.m2636i("checkApkUrl", browserResult.getCheckAdvise());
        }
        return iBrowerCheck;
    }

    protected final void finalize() throws Throwable {
        super.finalize();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 0;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7432a = context;
        try {
            this.f7433b = m3455a(this.f7432a, "fn7DR51xfDgi7Lhj70a+CpV57KhMEahaW0d1xQwGoC4NccjARG86lGHFDUdSH17jmnXBGPctbzUXqd0J0VzthugONZRgDs9dz+NHVb0sW+Hd6kcFghcq8ElvTFT6AmoB8082a60zuj2DvKXY25ZVOmNIGnArv6uG/FCY8SVQowql9jUyZgq7McRK8lIT2w2eLbIRT0EGGmWvV+QBtrpkW/tmsvR+LK1TnCdX6AgMNylJnELEyVoVY9Tk+oRQVkY4TF9QQNXFeADOWgDDmgKqgBDBbMYbGQGPV+TCT/1Zk0dVQ3betG6IqcJV38yR+MP1PVYa1JR5idMc5hoPxKpKYhgfBSVa+hXfouSG88wSRJiASrcOXOb5IWudeQqvE5FZeTYgAc4LFRxj6UF2La/jzJezxMrVaQ+i3/BCJlxSqF5UUOYJklVWHHEEsxZ8Z6LS");
            this.f7434c = new LinkedHashMap<>();
            m3455a(this.f7432a, m3453a(this.f7432a, f7431e));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
