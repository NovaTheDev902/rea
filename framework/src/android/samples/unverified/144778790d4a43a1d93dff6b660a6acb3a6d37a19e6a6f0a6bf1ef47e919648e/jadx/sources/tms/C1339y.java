package tms;

import QQPIM.ConnectType;
import QQPIM.EModelID;
import android.os.Looper;
import com.lenovo.safecenter.net.cache.NetConstant;
import com.tencent.tmsecure.common.ErrorCode;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.exception.NetWorkException;
import com.tencent.tmsecure.exception.NetworkOnMainThreadException;
import com.tencent.tmsecure.utils.NetworkUtil;
import com.tencent.tmsecure.utils.SDKUtil;
import com.tencent.tmsecure.utils.WifiUtil;
import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.ProtocolException;
import java.net.Proxy;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.net.URL;
import java.net.UnknownHostException;
import java.util.Hashtable;
import java.util.Map;
import java.util.concurrent.atomic.AtomicReference;
import java.util.zip.InflaterInputStream;
import org.apache.commons.httpclient.HttpState;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.commons.httpclient.methods.multipart.FilePart;
import org.apache.http.client.ClientProtocolException;

/* JADX INFO: renamed from: tms.y */
/* JADX INFO: loaded from: classes.dex */
public final class C1339y {

    /* JADX INFO: renamed from: a */
    public static final String f7502a = "GET";

    /* JADX INFO: renamed from: b */
    public static final String f7503b = "POST";

    /* JADX INFO: renamed from: n */
    private static volatile boolean f7504n = false;

    /* JADX INFO: renamed from: o */
    private static volatile String f7505o = null;

    /* JADX INFO: renamed from: p */
    private static volatile boolean f7506p = false;

    /* JADX INFO: renamed from: q */
    private static volatile boolean f7507q = false;

    /* JADX INFO: renamed from: r */
    private static volatile long f7508r = 0;

    /* JADX INFO: renamed from: c */
    private String f7509c;

    /* JADX INFO: renamed from: e */
    private HttpURLConnection f7511e;

    /* JADX INFO: renamed from: f */
    private byte[] f7512f;

    /* JADX INFO: renamed from: d */
    private String f7510d = "GET";

    /* JADX INFO: renamed from: g */
    private int f7513g = -1;

    /* JADX INFO: renamed from: h */
    private Hashtable<String, String> f7514h = new Hashtable<>(0);

    /* JADX INFO: renamed from: i */
    private boolean f7515i = false;

    /* JADX INFO: renamed from: j */
    private boolean f7516j = true;

    /* JADX INFO: renamed from: k */
    private byte f7517k = 0;

    /* JADX INFO: renamed from: l */
    private byte f7518l = 0;

    /* JADX INFO: renamed from: m */
    private byte f7519m = 0;

    /* JADX INFO: renamed from: tms.y$a */
    class a implements WifiUtil.IWifiApproveCheckCallBack {
        private a() {
        }

        /* synthetic */ a(C1339y c1339y, byte b) {
            this();
        }

        @Override // com.tencent.tmsecure.utils.WifiUtil.IWifiApproveCheckCallBack
        public final void onWifiApproveCheckFinished(boolean z, boolean z2) {
            if (C1339y.f7505o == null || !C1339y.f7505o.equals(WifiUtil.getSSID())) {
                return;
            }
            if (z2) {
                boolean unused = C1339y.f7504n = true;
            } else {
                boolean unused2 = C1339y.f7504n = z;
            }
            boolean unused3 = C1339y.f7507q = z2;
            C1339y.m3631o();
        }
    }

    private C1339y(String str) {
        this.f7509c = str;
    }

    /* JADX INFO: renamed from: a */
    public static synchronized C1339y m3623a(String str) throws NetWorkException {
        C1339y c1339y;
        if (!NetworkUtil.canNetworkOnMainThread() && Thread.currentThread().getId() == Looper.getMainLooper().getThread().getId()) {
            throw new NetworkOnMainThreadException();
        }
        if (str == null || str.length() == 0) {
            throw new NetWorkException(ErrorCode.ERR_OPEN_CONNECTION, "url is null!");
        }
        c1339y = new C1339y(str);
        ConnectType networkType = NetworkUtil.getNetworkType();
        if (ConnectType.CT_NONE == networkType) {
            throw new NetWorkException(-1052, "no connecition!");
        }
        c1339y.m3625a(c1339y.f7509c, networkType);
        return c1339y;
    }

    /* JADX INFO: renamed from: a */
    public static synchronized C1339y m3624a(C1339y c1339y) throws NetWorkException {
        C1339y c1339y2;
        ConnectType networkType = NetworkUtil.getNetworkType();
        c1339y2 = new C1339y(c1339y.m3651l());
        if (ConnectType.CT_NONE == networkType) {
            throw new NetWorkException(-1052, "no connection!");
        }
        c1339y2.m3625a(c1339y2.f7509c, networkType);
        c1339y2.m3638b(c1339y.m3634a());
        c1339y2.f7512f = c1339y.m3640b();
        c1339y2.m3636a(c1339y.f7514h);
        return c1339y2;
    }

    /* JADX INFO: renamed from: a */
    private void m3625a(String str, ConnectType connectType) throws NetWorkException {
        try {
            m3652m();
            if (ConnectType.CT_NONE != connectType) {
                if (ConnectType.CT_GPRS_WAP == connectType) {
                    this.f7511e = (HttpURLConnection) new URL(str).openConnection(new Proxy(Proxy.Type.HTTP, InetSocketAddress.createUnresolved(NetworkUtil.getProxyHost(), NetworkUtil.getProxyPort())));
                    this.f7515i = true;
                } else {
                    if (ConnectType.CT_WIFI == connectType && "com.tencent.qqpimsecure".equals(TMSApplication.getApplicaionContext().getPackageName())) {
                        String ssid = WifiUtil.getSSID();
                        if (f7505o == null || !f7505o.equals(ssid) || (System.currentTimeMillis() - f7508r > 5000 && !f7506p)) {
                            f7504n = false;
                            f7506p = true;
                            f7505o = ssid;
                            WifiUtil.needWifiApprove(new a(this, (byte) 0));
                        } else if (f7504n && !f7506p) {
                            f7506p = true;
                            WifiUtil.needWifiApprove(new a(this, (byte) 0));
                        }
                        f7508r = System.currentTimeMillis();
                    }
                    this.f7511e = (HttpURLConnection) new URL(str).openConnection();
                    this.f7515i = false;
                }
                this.f7511e.setReadTimeout(EModelID._EMID_QQPim_Begin);
                this.f7511e.setConnectTimeout(EModelID._EMID_QQPim_Begin);
            }
        } catch (IOException e) {
            throw new NetWorkException(-1056, "IOException : " + e.getMessage());
        } catch (IllegalArgumentException e2) {
            throw new NetWorkException(-1057, "IllegalArgumentException : " + e2.getMessage());
        } catch (SecurityException e3) {
            throw new NetWorkException(-1058, "SecurityException: " + e3.getMessage());
        } catch (UnsupportedOperationException e4) {
            throw new NetWorkException(-1059, "UnsupportedOperationException: " + e4.getMessage());
        }
    }

    /* JADX INFO: renamed from: a */
    private static byte[] m3627a(InputStream inputStream) throws NetWorkException {
        BufferedInputStream bufferedInputStream = new BufferedInputStream(inputStream);
        byte[] bArr = new byte[2048];
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
        while (true) {
            try {
                int i = inputStream.read(bArr);
                if (i == -1) {
                    byte[] byteArray = byteArrayOutputStream.toByteArray();
                    try {
                        bufferedInputStream.close();
                        byteArrayOutputStream.close();
                        return byteArray;
                    } catch (Exception e) {
                        throw new NetWorkException(-56, "get Bytes from inputStream: " + e.getMessage());
                    }
                }
                byteArrayOutputStream.write(bArr, 0, i);
            } catch (IOException e2) {
                throw new NetWorkException(-56, "get Bytes from inputStream when read buffer: " + e2.getMessage());
            }
        }
    }

    /* JADX INFO: renamed from: d */
    private static String[] m3629d(String str) {
        String[] strArr = new String[2];
        int iIndexOf = str.indexOf("://");
        if (-1 != iIndexOf) {
            str = str.substring(iIndexOf + 3);
        }
        int iIndexOf2 = str.indexOf(CookieSpec.PATH_DELIM);
        if (-1 != iIndexOf2) {
            strArr[0] = str.substring(0, iIndexOf2);
            strArr[1] = str.substring(iIndexOf2);
        } else {
            strArr[0] = str;
            strArr[1] = "";
        }
        return strArr;
    }

    /* JADX INFO: renamed from: o */
    static /* synthetic */ boolean m3631o() {
        f7506p = false;
        return false;
    }

    /* JADX INFO: renamed from: p */
    private int m3632p() throws NetWorkException {
        m3645f();
        m3625a(this.f7509c, NetworkUtil.getNetworkType());
        m3638b(this.f7510d);
        if ("POST".equalsIgnoreCase(this.f7510d) && this.f7512f != null) {
            this.f7512f = this.f7512f;
        }
        m3639b(this.f7514h);
        return m3641c();
    }

    /* JADX INFO: renamed from: a */
    public final int m3633a(boolean z, AtomicReference<byte[]> atomicReference) throws NetWorkException {
        if (this.f7511e != null) {
            if (this.f7513g == 200 || this.f7513g == 206) {
                try {
                    atomicReference.set(m3627a(z ? new InflaterInputStream(this.f7511e.getInputStream()) : this.f7511e.getInputStream()));
                    return 0;
                } catch (Exception e) {
                    throw new NetWorkException(-4002, "get response exception : " + e.getMessage());
                }
            }
        }
        return ErrorCode.ERR_RESPONSE;
    }

    /* JADX INFO: renamed from: a */
    public final String m3634a() {
        return this.f7510d;
    }

    /* JADX INFO: renamed from: a */
    public final void m3635a(String str, String str2) {
        if (str == null || str2 == null || this.f7511e == null) {
            return;
        }
        this.f7511e.setRequestProperty(str, str2);
        this.f7514h.put(str, str2);
    }

    /* JADX INFO: renamed from: a */
    public final void m3636a(Hashtable<String, String> hashtable) {
        if (this.f7511e == null || hashtable == null) {
            return;
        }
        for (Map.Entry<String, String> entry : hashtable.entrySet()) {
            m3635a(entry.getKey(), entry.getValue());
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3637a(byte[] bArr) {
        this.f7512f = bArr;
    }

    /* JADX INFO: renamed from: b */
    public final void m3638b(String str) {
        this.f7510d = str;
        if ("GET".equalsIgnoreCase(str)) {
            this.f7510d = "GET";
        } else if ("POST".equalsIgnoreCase(str)) {
            this.f7510d = "POST";
        }
    }

    /* JADX INFO: renamed from: b */
    public final void m3639b(Hashtable<String, String> hashtable) {
        if (hashtable == null || hashtable.size() == 0 || this.f7511e == null) {
            return;
        }
        for (Map.Entry<String, String> entry : hashtable.entrySet()) {
            this.f7511e.setRequestProperty(entry.getKey(), entry.getValue());
        }
    }

    /* JADX INFO: renamed from: b */
    public final byte[] m3640b() {
        return this.f7512f;
    }

    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r1v10 */
    /* JADX WARN: Type inference failed for: r1v2 */
    /* JADX WARN: Type inference failed for: r1v3 */
    /* JADX WARN: Type inference failed for: r1v31, types: [java.lang.String] */
    /* JADX WARN: Type inference failed for: r1v4 */
    /* JADX WARN: Type inference failed for: r1v5 */
    /* JADX WARN: Type inference failed for: r1v6 */
    /* JADX WARN: Type inference failed for: r1v7 */
    /* JADX WARN: Type inference failed for: r1v8 */
    /* JADX WARN: Type inference failed for: r1v9 */
    /* JADX INFO: renamed from: c */
    public final int m3641c() throws NetWorkException {
        int i;
        int i2;
        while (true) {
            if ("com.tencent.qqpimsecure".equals(TMSApplication.getApplicaionContext().getPackageName()) && ConnectType.CT_WIFI == NetworkUtil.getNetworkType()) {
                long jCurrentTimeMillis = System.currentTimeMillis();
                while (f7506p) {
                    if (System.currentTimeMillis() - jCurrentTimeMillis > 5000) {
                        if (System.currentTimeMillis() - jCurrentTimeMillis < NetConstant.SLEEP_SECONDS_TEN) {
                            break;
                        }
                        jCurrentTimeMillis = System.currentTimeMillis();
                    }
                }
                if (f7504n && !f7506p && !f7507q) {
                    throw new NetWorkException(ErrorCode.ERR_WIFI_NEED_APPROVE, "wifi need approve!");
                }
                if (f7506p) {
                    f7504n = true;
                }
            }
            try {
                if (SDKUtil.getSDKVersion() < 8) {
                    System.setProperty("http.keepAlive", HttpState.PREEMPTIVE_DEFAULT);
                }
                i = this.f7510d;
                try {
                    if ("GET".equalsIgnoreCase(i)) {
                        i2 = ErrorCode.ERR_GET;
                        this.f7511e.setRequestMethod("GET");
                    } else {
                        i2 = ErrorCode.ERR_POST;
                        this.f7511e.setRequestMethod("POST");
                        this.f7511e.setRequestProperty("Accept", "*/*");
                        this.f7511e.setRequestProperty("Accept-Charset", "utf-8");
                        this.f7511e.setDoOutput(true);
                        this.f7511e.setDoInput(true);
                        this.f7511e.setUseCaches(false);
                        if (this.f7512f != null) {
                            this.f7511e.setRequestProperty("Content-Type", FilePart.DEFAULT_CONTENT_TYPE);
                            this.f7511e.setRequestProperty("Content-length", "" + this.f7512f.length);
                            OutputStream outputStream = this.f7511e.getOutputStream();
                            outputStream.write(this.f7512f);
                            outputStream.flush();
                            outputStream.close();
                        }
                    }
                    this.f7513g = this.f7511e.getResponseCode();
                    if (this.f7513g >= 301 && this.f7513g <= 305) {
                        byte b = this.f7517k;
                        this.f7517k = (byte) (b + 1);
                        if (b < 2) {
                            this.f7509c = m3649j();
                            return m3632p();
                        }
                    } else if (this.f7513g == 200) {
                        String strM3648i = m3648i();
                        if (this.f7515i && strM3648i != null && strM3648i.toLowerCase().indexOf("vnd.wap.wml") != -1) {
                            byte b2 = this.f7518l;
                            this.f7518l = (byte) (b2 + 1);
                            if (b2 < 1) {
                                return m3632p();
                            }
                        }
                    }
                    if (this.f7513g == 206 || this.f7513g == 200) {
                        return this.f7513g;
                    }
                    byte b3 = this.f7519m;
                    this.f7519m = (byte) (b3 + 1);
                    if (b3 >= 2) {
                        throw new NetWorkException(this.f7513g + i2, "response code is unnormal: " + this.f7513g + " SDK Version:" + SDKUtil.getSDKVersion());
                    }
                    if (i2 == -1 && "true".equals(System.getProperty("http.keepAlive"))) {
                        System.setProperty("http.keepAlive", HttpState.PREEMPTIVE_DEFAULT);
                    }
                    return m3632p();
                } catch (NetWorkException e) {
                    e = e;
                    byte b4 = this.f7519m;
                    this.f7519m = (byte) (b4 + 1);
                    if (b4 < 2) {
                        return m3632p();
                    }
                    throw new NetWorkException(i - 56, "sendRequest NetWorkException: " + e.getMessage());
                } catch (IllegalStateException e2) {
                    e = e2;
                    byte b5 = this.f7519m;
                    this.f7519m = (byte) (b5 + 1);
                    if (b5 < 2) {
                        return m3632p();
                    }
                    throw new NetWorkException(i - 61, "sendRequest IllegalStateException: " + e.getMessage());
                } catch (ProtocolException e3) {
                    e = e3;
                    byte b6 = this.f7519m;
                    this.f7519m = (byte) (b6 + 1);
                    if (b6 < 2) {
                        return m3632p();
                    }
                    throw new NetWorkException(i - 51, "sendRequest ProtocolException: " + e.getMessage());
                } catch (SocketException e4) {
                    e = e4;
                    byte b7 = this.f7519m;
                    this.f7519m = (byte) (b7 + 1);
                    if (b7 < 2) {
                        return m3632p();
                    }
                    throw new NetWorkException(i - 54, "sendRequest SocketException: " + e.getMessage());
                } catch (SocketTimeoutException e5) {
                    e = e5;
                    byte b8 = this.f7519m;
                    this.f7519m = (byte) (b8 + 1);
                    if (b8 < 2) {
                        return m3632p();
                    }
                    throw new NetWorkException(i - 55, "sendRequest" + e.getMessage());
                } catch (UnknownHostException e6) {
                    e = e6;
                    byte b9 = this.f7519m;
                    this.f7519m = (byte) (b9 + 1);
                    if (b9 < 2) {
                        m3652m();
                        return m3632p();
                    }
                    if (this.f7516j) {
                        this.f7516j = false;
                        m3645f();
                        if (this.f7515i) {
                            m3625a(this.f7509c, ConnectType.CT_GPRS_NET);
                        } else if (ConnectType.CT_WIFI == NetworkUtil.getNetworkType()) {
                            String proxyHost = NetworkUtil.getProxyHost();
                            if (proxyHost == null || proxyHost.length() <= 0 || NetworkUtil.getProxyPort() <= 0) {
                                throw new NetWorkException(i - 62, "sendRequest UnknownHostException: " + e.getMessage() + " networktype:" + NetworkUtil.getNetworkType());
                            }
                            m3625a(this.f7509c, ConnectType.CT_GPRS_WAP);
                        }
                        if (this.f7511e != null) {
                            m3638b(this.f7510d);
                            if ("POST".equalsIgnoreCase(this.f7510d) && this.f7512f != null) {
                                m3637a(this.f7512f);
                            }
                            m3639b(this.f7514h);
                        }
                    }
                    throw new NetWorkException(i - 62, "sendRequest UnknownHostException: " + e.getMessage() + " networktype:" + NetworkUtil.getNetworkType());
                } catch (ClientProtocolException e7) {
                    e = e7;
                    byte b10 = this.f7519m;
                    this.f7519m = (byte) (b10 + 1);
                    if (b10 < 2) {
                        return m3632p();
                    }
                    throw new NetWorkException(i - 51, "sendRequest ClientProtocolException: " + e.getMessage());
                } catch (Exception e8) {
                    e = e8;
                    byte b11 = this.f7519m;
                    this.f7519m = (byte) (b11 + 1);
                    if (b11 < 2) {
                        return m3632p();
                    }
                    throw new NetWorkException(i, "sendRequest " + e.getClass().getName() + " : " + e.getMessage());
                } catch (IllegalAccessError e9) {
                    e = e9;
                    byte b12 = this.f7519m;
                    this.f7519m = (byte) (b12 + 1);
                    if (b12 < 2) {
                        return m3632p();
                    }
                    throw new NetWorkException(i - 60, "sendRequest IllegalAccessError: " + e.getMessage());
                }
            } catch (NetWorkException e10) {
                e = e10;
                i = 0;
            } catch (SocketException e11) {
                e = e11;
                i = 0;
            } catch (Exception e12) {
                e = e12;
                i = 0;
            } catch (IllegalAccessError e13) {
                e = e13;
                i = 0;
            } catch (IllegalStateException e14) {
                e = e14;
                i = 0;
            } catch (ProtocolException e15) {
                e = e15;
                i = 0;
            } catch (SocketTimeoutException e16) {
                e = e16;
                i = 0;
            } catch (UnknownHostException e17) {
                e = e17;
                i = 0;
            } catch (ClientProtocolException e18) {
                e = e18;
                i = 0;
            }
            m3639b(this.f7514h);
        }
    }

    /* JADX INFO: renamed from: c */
    public final String m3642c(String str) throws NetWorkException {
        try {
            return this.f7511e.getHeaderField(str);
        } catch (Exception e) {
            throw new NetWorkException(-56, "get header field: " + e.getMessage());
        }
    }

    /* JADX INFO: renamed from: d */
    public final InputStream m3643d() throws NetWorkException {
        try {
            return this.f7511e.getInputStream();
        } catch (Exception e) {
            throw new NetWorkException(-56, "get inputStream: " + e.getMessage());
        }
    }

    /* JADX INFO: renamed from: e */
    public final int m3644e() {
        return this.f7513g;
    }

    /* JADX INFO: renamed from: f */
    public final void m3645f() {
        if (this.f7511e != null) {
            this.f7511e.disconnect();
            this.f7511e = null;
        }
    }

    /* JADX INFO: renamed from: g */
    public final long m3646g() throws NetWorkException {
        String strM3642c = m3642c("Content-Range");
        if (strM3642c == null) {
            return -1L;
        }
        try {
            return Long.parseLong(strM3642c.substring(strM3642c.lastIndexOf(47) + 1).trim());
        } catch (Exception e) {
            throw new NetWorkException(-56, "get breakpoint total size: " + e.getMessage());
        }
    }

    /* JADX INFO: renamed from: h */
    public final long m3647h() throws NetWorkException {
        String strM3642c = m3642c("content-length");
        if (strM3642c == null) {
            return -1L;
        }
        try {
            return Long.parseLong(strM3642c.trim());
        } catch (Exception e) {
            throw new NetWorkException(-56, "get content length: " + e.getMessage());
        }
    }

    /* JADX INFO: renamed from: i */
    public final String m3648i() throws NetWorkException {
        try {
            return this.f7511e.getHeaderField("Content-Type");
        } catch (Exception e) {
            throw new NetWorkException(-56, "get content type: " + e.getMessage());
        }
    }

    /* JADX INFO: renamed from: j */
    public final String m3649j() throws NetWorkException {
        try {
            return this.f7511e.getHeaderField("Location");
        } catch (Exception e) {
            throw new NetWorkException(-56, "get redirect url: " + e.getMessage());
        }
    }

    /* JADX INFO: renamed from: k */
    public final boolean m3650k() {
        return this.f7515i;
    }

    /* JADX INFO: renamed from: l */
    public final String m3651l() {
        return this.f7509c;
    }

    /* JADX INFO: renamed from: m */
    public final String m3652m() {
        String host = this.f7511e != null ? this.f7511e.getURL().getHost() : m3629d(this.f7509c)[0];
        if ((host == null || host.length() == 0) && this.f7511e == null) {
            host = m3629d(this.f7509c)[0];
        }
        try {
            InetAddress byName = InetAddress.getByName(host);
            if (byName != null) {
                return byName.getHostAddress();
            }
        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
        return "";
    }
}
