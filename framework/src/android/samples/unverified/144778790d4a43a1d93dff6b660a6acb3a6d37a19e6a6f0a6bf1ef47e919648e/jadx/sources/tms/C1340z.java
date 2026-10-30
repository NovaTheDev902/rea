package tms;

import QQPIM.ConnectType;
import android.content.Context;
import android.net.Proxy;
import android.os.Bundle;
import android.os.Environment;
import android.os.Looper;
import com.tencent.tmsecure.common.ErrorCode;
import com.tencent.tmsecure.exception.NetworkOnMainThreadException;
import com.tencent.tmsecure.utils.Log;
import com.tencent.tmsecure.utils.NetworkUtil;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.net.URI;
import java.net.URISyntaxException;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.conn.ClientConnectionManager;

/* JADX INFO: renamed from: tms.z */
/* JADX INFO: loaded from: classes.dex */
public class C1340z extends C1338x {

    /* JADX INFO: renamed from: l */
    private Context f7521l;

    /* JADX INFO: renamed from: m */
    private HttpGet f7522m;

    /* JADX INFO: renamed from: n */
    private String f7523n;

    /* JADX INFO: renamed from: o */
    private String f7524o;

    /* JADX INFO: renamed from: s */
    private boolean f7528s;

    /* JADX INFO: renamed from: p */
    private String f7525p = null;

    /* JADX INFO: renamed from: q */
    private String f7526q = null;

    /* JADX INFO: renamed from: r */
    private int f7527r = 0;

    /* JADX INFO: renamed from: t */
    private boolean f7529t = false;

    /* JADX INFO: renamed from: u */
    private long f7530u = 0;

    /* JADX INFO: renamed from: v */
    private long f7531v = 0;

    public C1340z(Context context) {
        this.f7522m = null;
        this.f7523n = null;
        this.f7524o = null;
        this.f7528s = false;
        if (!NetworkUtil.canNetworkOnMainThread() && Thread.currentThread().getId() == Looper.getMainLooper().getThread().getId()) {
            throw new NetworkOnMainThreadException();
        }
        this.f7521l = context;
        this.f7528s = "mounted".equals(Environment.getExternalStorageState());
        if (this.f7528s) {
            this.f7523n = "/sdcard/qqsecure";
            this.f7524o = "/sdcard/qqsecure";
            File file = new File(this.f7523n);
            if (!file.exists()) {
                file.mkdir();
            }
        } else {
            this.f7523n = context.getCacheDir().getAbsolutePath();
            this.f7524o = context.getFilesDir().getAbsolutePath();
        }
        this.f7522m = new HttpGet();
        if (NetworkUtil.getNetworkType() == ConnectType.CT_GPRS_WAP) {
            m3620a(Proxy.getDefaultHost(), Proxy.getDefaultPort());
            m3622a(true);
        }
    }

    /*  JADX ERROR: Types fix failed
        jadx.core.utils.exceptions.JadxOverflowException: Type inference error: updates count limit reached with updateSeq = 7681. Try increasing type updates limit count.
        	at jadx.core.utils.ErrorsCounter.addError(ErrorsCounter.java:59)
        	at jadx.core.utils.ErrorsCounter.error(ErrorsCounter.java:31)
        	at jadx.core.dex.attributes.nodes.NotificationAttrNode.addError(NotificationAttrNode.java:19)
        	at jadx.core.dex.visitors.typeinference.FixTypesVisitor.visit(FixTypesVisitor.java:99)
        */
    /* JADX INFO: renamed from: a */
    private int m3653a(org.apache.http.HttpEntity r12, android.os.Bundle r13, boolean r14) {
        /*
            Method dump skipped, instruction units count: 768
            To view this dump add '--comments-level debug' option
        */
        throw new UnsupportedOperationException("Method not decompiled: tms.C1340z.m3653a(org.apache.http.HttpEntity, android.os.Bundle, boolean):int");
    }

    /* JADX INFO: renamed from: c */
    private int m3654c(String str) {
        int i;
        URI uri = null;
        try {
            uri = new URI(str);
            i = -1000;
        } catch (URISyntaxException e) {
            Log.m2634e("HttpBase", "url error: " + e.getMessage());
            e.printStackTrace();
            i = -1053;
        }
        if (uri == null) {
            return i;
        }
        this.f7522m.setURI(uri);
        return 0;
    }

    /* JADX WARN: Code duplicated, block: B:136:0x015e A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:143:0x0163 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:30:0x00b4 A[PHI: r0 r2
  0x00b4: PHI (r0v11 int) = (r0v0 int), (r0v4 int), (r0v9 int), (r0v15 int) binds: [B:72:0x0155, B:51:0x011d, B:29:0x00b2, B:61:0x0134] A[DONT_GENERATE, DONT_INLINE]
  0x00b4: PHI (r2v10 ??) = (r2v12 ??), (r2v13 ??), (r2v14 ??), (r2v15 ??) binds: [B:72:0x0155, B:51:0x011d, B:29:0x00b2, B:61:0x0134] A[DONT_GENERATE, DONT_INLINE]] */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r2v1, types: [java.lang.String] */
    /* JADX WARN: Type inference failed for: r2v10, types: [java.io.File] */
    /* JADX WARN: Type inference failed for: r2v11, types: [java.io.File] */
    /* JADX WARN: Type inference failed for: r2v12 */
    /* JADX WARN: Type inference failed for: r2v13 */
    /* JADX WARN: Type inference failed for: r2v14 */
    /* JADX WARN: Type inference failed for: r2v15 */
    /* JADX WARN: Type inference failed for: r2v16 */
    /* JADX WARN: Type inference failed for: r2v17 */
    /* JADX WARN: Type inference failed for: r2v18 */
    /* JADX WARN: Type inference failed for: r2v2 */
    /* JADX WARN: Type inference failed for: r2v3 */
    /* JADX WARN: Type inference failed for: r2v4 */
    /* JADX WARN: Type inference failed for: r2v5 */
    /* JADX WARN: Type inference failed for: r2v6, types: [java.io.File] */
    /* JADX WARN: Type inference failed for: r2v7, types: [java.io.File] */
    /* JADX WARN: Type inference failed for: r2v8, types: [java.io.File] */
    /* JADX WARN: Type inference failed for: r2v9, types: [java.io.File] */
    /* JADX WARN: Type inference failed for: r4v10 */
    /* JADX WARN: Type inference failed for: r4v19, types: [java.io.FileOutputStream] */
    /* JADX WARN: Type inference failed for: r4v26 */
    /* JADX WARN: Type inference failed for: r4v34 */
    /* JADX WARN: Type inference failed for: r4v36 */
    /* JADX WARN: Type inference failed for: r4v7, types: [java.lang.StringBuilder] */
    /* JADX WARN: Type inference failed for: r5v10, types: [java.io.FileOutputStream] */
    /* JADX WARN: Type inference failed for: r5v11, types: [java.io.FileOutputStream] */
    /* JADX WARN: Type inference failed for: r5v12 */
    /* JADX WARN: Type inference failed for: r5v18 */
    /* JADX WARN: Type inference failed for: r5v19 */
    /* JADX WARN: Type inference failed for: r5v20 */
    /* JADX WARN: Type inference failed for: r5v21 */
    /* JADX WARN: Type inference failed for: r5v22, types: [java.io.FileOutputStream] */
    /* JADX WARN: Type inference failed for: r5v32, types: [java.io.FileOutputStream] */
    /* JADX WARN: Type inference failed for: r5v35 */
    /* JADX WARN: Type inference failed for: r5v36 */
    /* JADX WARN: Type inference failed for: r5v37 */
    /* JADX WARN: Type inference failed for: r5v5, types: [java.lang.String] */
    /* JADX WARN: Type inference failed for: r5v6 */
    /* JADX WARN: Type inference failed for: r5v7 */
    /* JADX WARN: Type inference failed for: r5v8 */
    /* JADX WARN: Type inference failed for: r5v9, types: [java.io.FileOutputStream] */
    /* JADX INFO: renamed from: e */
    private int m3655e() throws Throwable {
        ?? r4;
        int i;
        int i2;
        ?? r2;
        FileInputStream fileInputStream;
        int i3 = 0;
        FileInputStream fileInputStream2 = null;
        int i4 = ErrorCode.ERR_FILE_OP;
        Log.m2636i("HttpGetFile", this.f7523n + File.separator + this.f7525p);
        ?? file = "HttpGetFile";
        ?? Append = new StringBuilder().append(this.f7524o).append(File.separator);
        ?? fileOutputStream = this.f7526q;
        Log.m2636i("HttpGetFile", Append.append(fileOutputStream).toString());
        try {
            try {
                file = new File(this.f7523n + File.separator + this.f7525p);
                try {
                    if (file.exists()) {
                        if (this.f7528s || this.f7527r != 1) {
                            File file2 = new File(this.f7524o + File.separator + this.f7526q);
                            if (file2.exists()) {
                                file2.delete();
                                fileOutputStream = new FileOutputStream(file2);
                            } else {
                                new File(this.f7524o).mkdirs();
                                file2.createNewFile();
                                fileOutputStream = new FileOutputStream(file2);
                            }
                        } else {
                            fileOutputStream = this.f7521l.openFileOutput(this.f7526q, 1);
                        }
                        try {
                            fileInputStream = new FileInputStream((File) file);
                            try {
                                byte[] bArr = new byte[1024];
                                while (true) {
                                    int i5 = fileInputStream.read(bArr);
                                    if (i5 == -1) {
                                        break;
                                    }
                                    fileOutputStream.write(bArr, 0, i5);
                                }
                            } catch (FileNotFoundException e) {
                                e = e;
                                fileInputStream2 = fileInputStream;
                                r4 = fileOutputStream;
                                file = file;
                                try {
                                    Log.m2634e("HttpBase", "file not found");
                                    e.printStackTrace();
                                    if (fileInputStream2 != null) {
                                        try {
                                            fileInputStream2.close();
                                            i2 = -7001;
                                        } catch (IOException e2) {
                                            Log.m2634e("HttpBase", "fis close file error");
                                            e2.printStackTrace();
                                            i2 = -7000;
                                        }
                                    } else {
                                        i2 = -7001;
                                    }
                                    if (r4 != 0) {
                                        try {
                                            r4.close();
                                            i4 = i2;
                                        } catch (IOException e3) {
                                            Log.m2634e("HttpBase", "fosclose file error");
                                            e3.printStackTrace();
                                        }
                                    } else {
                                        i4 = i2;
                                    }
                                    if (file != 0 && file.exists()) {
                                        r2 = file;
                                        r2 = file;
                                        r2 = file;
                                        r2 = file;
                                        r2.delete();
                                    }
                                } catch (Throwable th) {
                                    th = th;
                                    fileOutputStream = r4;
                                    if (fileInputStream2 != null) {
                                        try {
                                            fileInputStream2.close();
                                        } catch (IOException e4) {
                                            Log.m2634e("HttpBase", "fis close file error");
                                            e4.printStackTrace();
                                        }
                                    }
                                    if (fileOutputStream != 0) {
                                        try {
                                            fileOutputStream.close();
                                        } catch (IOException e5) {
                                            Log.m2634e("HttpBase", "fosclose file error");
                                            e5.printStackTrace();
                                        }
                                    }
                                    if (file != 0 || !file.exists()) {
                                        throw th;
                                    }
                                    file.delete();
                                    throw th;
                                }
                            } catch (IOException e6) {
                                e = e6;
                                fileInputStream2 = fileInputStream;
                                Log.m2634e("HttpBase", "file io error");
                                e.printStackTrace();
                                if (fileInputStream2 != null) {
                                    try {
                                        fileInputStream2.close();
                                        i = -7056;
                                    } catch (IOException e7) {
                                        Log.m2634e("HttpBase", "fis close file error");
                                        e7.printStackTrace();
                                        i = -7000;
                                    }
                                } else {
                                    i = -7056;
                                }
                                if (fileOutputStream != 0) {
                                    try {
                                        fileOutputStream.close();
                                        i4 = i;
                                    } catch (IOException e8) {
                                        Log.m2634e("HttpBase", "fosclose file error");
                                        e8.printStackTrace();
                                    }
                                } else {
                                    i4 = i;
                                }
                                if (file != 0 && file.exists()) {
                                    r2 = file;
                                    r2 = file;
                                    r2 = file;
                                    r2 = file;
                                    r2.delete();
                                }
                            } catch (Exception e9) {
                                e = e9;
                                fileInputStream2 = fileInputStream;
                                Log.m2634e("HttpBase", "file op error");
                                e.printStackTrace();
                                if (fileInputStream2 != null) {
                                    try {
                                        fileInputStream2.close();
                                    } catch (IOException e10) {
                                        Log.m2634e("HttpBase", "fis close file error");
                                        e10.printStackTrace();
                                    }
                                }
                                if (fileOutputStream != 0) {
                                    try {
                                        fileOutputStream.close();
                                    } catch (IOException e11) {
                                        Log.m2634e("HttpBase", "fosclose file error");
                                        e11.printStackTrace();
                                    }
                                }
                                if (file != 0 && file.exists()) {
                                    r2 = file;
                                    r2 = file;
                                    r2 = file;
                                    r2 = file;
                                    r2.delete();
                                }
                            } catch (Throwable th2) {
                                th = th2;
                                fileInputStream2 = fileInputStream;
                                if (fileInputStream2 != null) {
                                    fileInputStream2.close();
                                }
                                if (fileOutputStream != 0) {
                                    fileOutputStream.close();
                                }
                                if (file != 0) {
                                    throw th;
                                }
                                throw th;
                            }
                        } catch (FileNotFoundException e12) {
                            e = e12;
                            r4 = fileOutputStream;
                            file = file;
                        } catch (IOException e13) {
                            e = e13;
                        } catch (Exception e14) {
                            e = e14;
                        }
                    } else {
                        fileInputStream = null;
                        fileOutputStream = 0;
                        i3 = -7001;
                    }
                    if (fileInputStream != null) {
                        try {
                            fileInputStream.close();
                        } catch (IOException e15) {
                            Log.m2634e("HttpBase", "fis close file error");
                            e15.printStackTrace();
                            i3 = -7000;
                        }
                    }
                    if (fileOutputStream != 0) {
                        try {
                            fileOutputStream.close();
                            i4 = i3;
                        } catch (IOException e16) {
                            Log.m2634e("HttpBase", "fosclose file error");
                            e16.printStackTrace();
                        }
                    } else {
                        i4 = i3;
                    }
                    if (file != 0 && file.exists()) {
                        r2 = file;
                        r2 = file;
                        r2 = file;
                        r2 = file;
                        r2.delete();
                    }
                } catch (FileNotFoundException e17) {
                    e = e17;
                    r4 = 0;
                    file = file;
                } catch (IOException e18) {
                    e = e18;
                    fileOutputStream = 0;
                } catch (Exception e19) {
                    e = e19;
                    fileOutputStream = 0;
                } catch (Throwable th3) {
                    th = th3;
                    fileOutputStream = 0;
                }
            } catch (Throwable th4) {
                th = th4;
            }
        } catch (FileNotFoundException e20) {
            e = e20;
            file = 0;
            r4 = 0;
        } catch (IOException e21) {
            e = e21;
            file = 0;
            fileOutputStream = 0;
        } catch (Exception e22) {
            e = e22;
            file = 0;
            fileOutputStream = 0;
        } catch (Throwable th5) {
            th = th5;
            file = 0;
            fileOutputStream = 0;
        }
        r2 = file;
        r2 = file;
        r2 = file;
        r2 = file;
        return i4;
    }

    /* JADX INFO: renamed from: a */
    public void m3656a(int i) {
        this.f7527r = i;
    }

    /* JADX INFO: renamed from: a */
    public void m3657a(String str) {
        this.f7524o = str;
    }

    /* JADX WARN: Code duplicated, block: B:93:0x02a3  */
    /* JADX WARN: Code duplicated, block: B:95:0x02ac  */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r1v0, types: [org.apache.http.client.HttpClient] */
    /* JADX WARN: Type inference failed for: r1v1 */
    /* JADX WARN: Type inference failed for: r1v10 */
    /* JADX WARN: Type inference failed for: r1v11, types: [java.lang.String] */
    /* JADX WARN: Type inference failed for: r1v13 */
    /* JADX WARN: Type inference failed for: r1v14 */
    /* JADX WARN: Type inference failed for: r1v15, types: [java.lang.String] */
    /* JADX WARN: Type inference failed for: r1v17 */
    /* JADX WARN: Type inference failed for: r1v18 */
    /* JADX WARN: Type inference failed for: r1v19 */
    /* JADX WARN: Type inference failed for: r1v2, types: [org.apache.http.client.HttpClient] */
    /* JADX WARN: Type inference failed for: r1v20 */
    /* JADX WARN: Type inference failed for: r1v21 */
    /* JADX WARN: Type inference failed for: r1v22 */
    /* JADX WARN: Type inference failed for: r1v23 */
    /* JADX WARN: Type inference failed for: r1v24 */
    /* JADX WARN: Type inference failed for: r1v25 */
    /* JADX WARN: Type inference failed for: r1v7 */
    /* JADX WARN: Type inference failed for: r1v8, types: [org.apache.http.client.HttpClient] */
    /* JADX WARN: Type inference failed for: r1v9 */
    /* JADX INFO: renamed from: a */
    public void m3658a(String str, boolean z) {
        int i;
        ?? A = 0;
        A = 0;
        A = 0;
        A = 0;
        A = 0;
        Bundle bundle = new Bundle();
        try {
            try {
                try {
                    try {
                        A = m3618a();
                        int iM3654c = m3654c(str);
                        if (iM3654c != 0) {
                            if (A != 0) {
                                A.getConnectionManager().shutdown();
                            }
                            if (iM3654c != 0) {
                                bundle.putInt(C1338x.f7492e, iM3654c);
                                m3619a(1, bundle);
                            }
                        } else if (this.f7529t) {
                            if (A != 0) {
                                A.getConnectionManager().shutdown();
                            }
                            A = -3003;
                            bundle.putInt(C1338x.f7492e, -3003);
                            m3619a(1, bundle);
                        } else if (this.f7522m.getURI() != null) {
                            String strM3579a = C1336v.m3579a(str, (String) null);
                            this.f7525p = strM3579a + BinderC1252ea.TEMPFILE_SUFFIX;
                            if (this.f7526q == null) {
                                this.f7526q = strM3579a;
                            }
                            File file = new File(this.f7523n + File.separator + this.f7525p);
                            if (file.exists()) {
                                this.f7531v = file.length();
                                this.f7522m.setHeader("RANGE", "bytes=" + this.f7531v + "-");
                            }
                            HttpResponse httpResponseExecute = A.execute(this.f7522m);
                            int statusCode = httpResponseExecute.getStatusLine().getStatusCode();
                            Log.m2636i("HttpBase", "statusCode == " + statusCode);
                            if (statusCode != 200 && statusCode != 206) {
                                int i2 = (-3000) - statusCode;
                                if (A != 0) {
                                    A = A;
                                    ClientConnectionManager connectionManager = A.getConnectionManager();
                                    connectionManager.shutdown();
                                    A = connectionManager;
                                }
                                if (i2 != 0) {
                                    A = C1338x.f7492e;
                                    bundle.putInt(C1338x.f7492e, i2);
                                    m3619a(1, bundle);
                                }
                            } else if (this.f7529t) {
                                if (A != 0) {
                                    A.getConnectionManager().shutdown();
                                }
                                A = -3003;
                                bundle.putInt(C1338x.f7492e, -3003);
                                m3619a(1, bundle);
                            } else {
                                HttpEntity entity = httpResponseExecute.getEntity();
                                if (entity != null) {
                                    int iM3653a = m3653a(entity, bundle, z);
                                    if (iM3653a != 0) {
                                        if (A != 0) {
                                            A.getConnectionManager().shutdown();
                                        }
                                        if (iM3653a != 0) {
                                            bundle.putInt(C1338x.f7492e, iM3653a);
                                            m3619a(1, bundle);
                                        }
                                    } else {
                                        int iM3655e = m3655e();
                                        if (iM3655e != 0) {
                                            if (A != 0) {
                                                ClientConnectionManager connectionManager2 = A.getConnectionManager();
                                                connectionManager2.shutdown();
                                                A = connectionManager2;
                                            }
                                            if (iM3655e != 0) {
                                                A = C1338x.f7492e;
                                                bundle.putInt(C1338x.f7492e, iM3655e);
                                                m3619a(1, bundle);
                                            }
                                        } else if (A != 0) {
                                            A.getConnectionManager().shutdown();
                                        }
                                    }
                                } else {
                                    try {
                                        Log.m2634e("HttpBase", "httpEntity == null");
                                        if (A != 0) {
                                            A.getConnectionManager().shutdown();
                                        }
                                        bundle.putInt(C1338x.f7492e, ErrorCode.ERR_RESPONSE);
                                        m3619a(1, bundle);
                                    } catch (Throwable th) {
                                        th = th;
                                        i = -4000;
                                        if (A != 0) {
                                            A.getConnectionManager().shutdown();
                                        }
                                        if (i != 0) {
                                            bundle.putInt(C1338x.f7492e, i);
                                            m3619a(1, bundle);
                                        }
                                        throw th;
                                    }
                                }
                            }
                        } else {
                            Log.m2634e("HttpBase", "url == null");
                            if (A != 0) {
                                A.getConnectionManager().shutdown();
                            }
                            A = -3053;
                            bundle.putInt(C1338x.f7492e, -3053);
                            m3619a(1, bundle);
                        }
                    } catch (Throwable th2) {
                        th = th2;
                    }
                } catch (SocketException e) {
                    Log.m2634e("HttpBase", "socket error:" + e.getMessage());
                    e.printStackTrace();
                    if (0 != 0) {
                        A.getConnectionManager().shutdown();
                    }
                    bundle.putInt(C1338x.f7492e, -3054);
                    m3619a(1, bundle);
                }
            } catch (SocketTimeoutException e2) {
                try {
                    Log.m2634e("HttpBase", "socket timeout error:" + e2.getMessage());
                    e2.printStackTrace();
                    if (0 != 0) {
                        A.getConnectionManager().shutdown();
                    }
                    bundle.putInt(C1338x.f7492e, -3055);
                    m3619a(1, bundle);
                } catch (Throwable th3) {
                    th = th3;
                    i = -3055;
                    if (A != 0) {
                        A.getConnectionManager().shutdown();
                    }
                    if (i != 0) {
                        bundle.putInt(C1338x.f7492e, i);
                        m3619a(1, bundle);
                    }
                    throw th;
                }
            } catch (ClientProtocolException e3) {
                Log.m2634e("HttpBase", "protocol error:" + e3.getMessage());
                e3.printStackTrace();
                if (0 != 0) {
                    A.getConnectionManager().shutdown();
                }
                bundle.putInt(C1338x.f7492e, -3051);
                m3619a(1, bundle);
            } catch (IOException e4) {
                try {
                    Log.m2634e("HttpBase", "io error:" + e4.getMessage());
                    e4.printStackTrace();
                    if (0 != 0) {
                        A.getConnectionManager().shutdown();
                    }
                    bundle.putInt(C1338x.f7492e, -3056);
                    m3619a(1, bundle);
                } catch (Throwable th4) {
                    th = th4;
                    i = -3056;
                    if (A != 0) {
                        A.getConnectionManager().shutdown();
                    }
                    if (i != 0) {
                        bundle.putInt(C1338x.f7492e, i);
                        m3619a(1, bundle);
                    }
                    throw th;
                }
            } catch (Exception e5) {
                Log.m2634e("HttpBase", "get error:" + e5.getMessage());
                e5.printStackTrace();
                if (0 != 0) {
                    A.getConnectionManager().shutdown();
                }
                bundle.putInt(C1338x.f7492e, ErrorCode.ERR_GET);
                m3619a(1, bundle);
            }
        } catch (Throwable th5) {
            th = th5;
            i = -3000;
        }
    }

    /* JADX INFO: renamed from: b */
    public void m3659b(String str) {
        this.f7526q = str;
    }

    /* JADX INFO: renamed from: b */
    public synchronized boolean m3660b() {
        return this.f7529t;
    }

    /* JADX INFO: renamed from: c */
    public synchronized void m3661c() {
        this.f7529t = true;
    }

    /* JADX INFO: renamed from: d */
    public String m3662d() {
        return this.f7524o + File.separator + this.f7526q;
    }
}
