package com.tencent.tmsecure.utils;

import android.content.Intent;
import android.net.LocalSocket;
import android.net.LocalSocketAddress;
import android.os.Process;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.tencent.tmsecure.common.TMSApplication;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import tms.C1319hf;
import tms.C1332r;
import tms.C1336v;
import tms.InterfaceC1326l;

/* JADX INFO: loaded from: classes.dex */
public final class ScriptHelper {
    public static final int ROOT_GOT = 0;
    public static final String ROOT_GOT_ACTION = "com.tencent.tmsecure.root";
    public static final int ROOT_NOT_GOT = 2;
    public static final int ROOT_NOT_SUPPORT = 1;
    public static final int ROOT_NO_RESPOND = -1;

    /* JADX INFO: renamed from: d */
    private static final String f6285d = "/dev/socket/script_socket";

    /* JADX INFO: renamed from: f */
    private static final String f6287f = "athena_v2.dat";

    /* JADX INFO: renamed from: g */
    private static final boolean f6288g;

    /* JADX INFO: renamed from: h */
    private static final boolean f6289h;

    /* JADX INFO: renamed from: i */
    private static final int f6290i = 30000;

    /* JADX INFO: renamed from: j */
    private static InterfaceC1326l f6291j;

    /* JADX INFO: renamed from: a */
    private static boolean f6282a = false;

    /* JADX INFO: renamed from: b */
    private static boolean f6283b = false;

    /* JADX INFO: renamed from: c */
    private static Object f6284c = new Object();

    /* JADX INFO: renamed from: e */
    private static final String f6286e = TMSApplication.getApplicaionContext().getPackageName();

    public interface Callback {
        void onFinish(int i);
    }

    /* JADX INFO: renamed from: com.tencent.tmsecure.utils.ScriptHelper$a */
    static final class C1084a {

        /* JADX INFO: renamed from: a */
        int f6292a;

        /* JADX INFO: renamed from: b */
        int f6293b;

        /* JADX INFO: renamed from: c */
        int f6294c;

        /* JADX INFO: renamed from: d */
        byte[] f6295d;

        C1084a() {
        }
    }

    /* JADX INFO: renamed from: com.tencent.tmsecure.utils.ScriptHelper$b */
    static final class C1085b {

        /* JADX INFO: renamed from: a */
        int f6296a;

        /* JADX INFO: renamed from: b */
        byte[] f6297b;

        C1085b() {
        }
    }

    static {
        f6288g = C1336v.m3605h("/system/bin/su") || C1336v.m3605h("/system/xbin/su") || C1336v.m3605h("/sbin/su");
        f6289h = new File(f6285d).exists();
        f6291j = null;
    }

    /* JADX INFO: renamed from: a */
    private static int m2639a() {
        String strRunScript = runScript(QueryPermissions.f1958ID);
        if (strRunScript == null) {
            return 2;
        }
        if (strRunScript.contains("uid=0")) {
            return 0;
        }
        String strRunScript2 = runScript("su");
        if (strRunScript2 == null) {
            return 2;
        }
        if (strRunScript2.contains("Kill") || strRunScript2.contains("kill")) {
            return -1;
        }
        String strRunScript3 = runScript(QueryPermissions.f1958ID);
        if (strRunScript3 == null || !strRunScript3.contains("uid=0")) {
            return 2;
        }
        m2641b();
        return 0;
    }

    /* JADX WARN: Code duplicated, block: B:101:0x00e8 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:110:0x00e3 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:54:0x00e6 A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:99:0x00eb A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX INFO: renamed from: a */
    private static synchronized C1085b m2640a(C1084a c1084a, boolean z) {
        C1085b c1085b;
        InputStream inputStream;
        OutputStream outputStream;
        LocalSocket localSocket = new LocalSocket();
        OutputStream outputStream2 = null;
        InputStream inputStream2 = null;
        c1085b = new C1085b();
        LocalSocketAddress localSocketAddress = f6289h ? new LocalSocketAddress(f6285d, LocalSocketAddress.Namespace.FILESYSTEM) : new LocalSocketAddress(f6286e, LocalSocketAddress.Namespace.ABSTRACT);
        try {
            try {
                try {
                    try {
                        localSocket.connect(localSocketAddress);
                        inputStream = localSocketAddress;
                    } catch (Throwable th) {
                        th = th;
                        inputStream = 0;
                        outputStream2 = null;
                        if (outputStream2 != null) {
                            if (inputStream != 0) {
                                localSocket.close();
                                throw th;
                            }
                            inputStream.close();
                            localSocket.close();
                            throw th;
                        }
                        try {
                            outputStream2.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                        if (inputStream != 0) {
                            localSocket.close();
                            throw th;
                        }
                        try {
                            inputStream.close();
                        } catch (IOException e2) {
                            e2.printStackTrace();
                        }
                        try {
                            localSocket.close();
                            throw th;
                        } catch (IOException e3) {
                            e3.printStackTrace();
                            throw th;
                        }
                        throw th;
                    }
                } catch (IOException e4) {
                    boolean z2 = f6289h;
                    inputStream = z2;
                    inputStream = z2;
                    if (!z2 && z) {
                        m2642c();
                        try {
                            Thread.sleep(200L);
                        } catch (InterruptedException e5) {
                        }
                        c1085b = m2640a(c1084a, false);
                        if (0 != 0) {
                            try {
                                outputStream2.close();
                            } catch (IOException e6) {
                                e6.printStackTrace();
                            }
                        }
                        if (0 != 0) {
                            try {
                                inputStream2.close();
                            } catch (IOException e7) {
                                e7.printStackTrace();
                            }
                        }
                        try {
                            localSocket.close();
                        } catch (IOException e8) {
                            e8.printStackTrace();
                        }
                        return c1085b;
                    }
                }
                inputStream = localSocket.getInputStream();
                try {
                    outputStream = localSocket.getOutputStream();
                    try {
                        c1084a.f6294c = c1084a.f6295d.length;
                        byte[] bArr = new byte[12];
                        System.arraycopy(C1332r.m3549a(c1084a.f6292a), 0, bArr, 0, 4);
                        System.arraycopy(C1332r.m3549a(c1084a.f6293b), 0, bArr, 4, 4);
                        System.arraycopy(C1332r.m3549a(c1084a.f6294c), 0, bArr, 8, 4);
                        outputStream.write(bArr);
                        outputStream.write(c1084a.f6295d);
                        outputStream.flush();
                        Log.m2636i("andysinguan", new String(c1084a.f6295d));
                        byte[] bArr2 = new byte[4];
                        if (inputStream.read(bArr2) != 4) {
                            throw new IOException("respond data is invalid");
                        }
                        c1085b.f6296a = C1332r.m3552b(bArr2);
                        byte[] bArr3 = new byte[c1085b.f6296a];
                        if (inputStream.read(bArr3) != bArr3.length) {
                            throw new IOException("respond data is invalid");
                        }
                        c1085b.f6297b = bArr3;
                        Log.m2636i("andysinguan", new String(bArr3));
                        if (outputStream != null) {
                            try {
                                outputStream.close();
                            } catch (IOException e9) {
                                e9.printStackTrace();
                            }
                        }
                        if (inputStream != 0) {
                            try {
                                inputStream.close();
                            } catch (IOException e10) {
                                e10.printStackTrace();
                            }
                        }
                        try {
                            localSocket.close();
                        } catch (IOException e11) {
                            e11.printStackTrace();
                        }
                    } catch (IOException e12) {
                        e = e12;
                        e.printStackTrace();
                        if (outputStream != null) {
                            try {
                                outputStream.close();
                            } catch (IOException e13) {
                                e13.printStackTrace();
                            }
                        }
                        if (inputStream != 0) {
                            try {
                                inputStream.close();
                            } catch (IOException e14) {
                                e14.printStackTrace();
                            }
                        }
                        try {
                            localSocket.close();
                        } catch (IOException e15) {
                            e15.printStackTrace();
                        }
                        c1085b = null;
                    }
                } catch (IOException e16) {
                    e = e16;
                    outputStream = null;
                } catch (Throwable th2) {
                    th = th2;
                    outputStream2 = null;
                    if (outputStream2 != null) {
                        if (inputStream != 0) {
                            localSocket.close();
                            throw th;
                        }
                        inputStream.close();
                        localSocket.close();
                        throw th;
                    }
                    outputStream2.close();
                    if (inputStream != 0) {
                        localSocket.close();
                        throw th;
                    }
                    inputStream.close();
                    localSocket.close();
                    throw th;
                    throw th;
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (IOException e17) {
            e = e17;
            inputStream = 0;
            outputStream = null;
        }
        return c1085b;
    }

    /* JADX INFO: renamed from: b */
    private static void m2641b() {
        Set<Map.Entry<String, String>> setEntrySet = new ProcessBuilder(new String[0]).environment().entrySet();
        ArrayList arrayList = new ArrayList();
        for (Map.Entry<String, String> entry : setEntrySet) {
            arrayList.add("export " + entry.getKey() + "=" + entry.getValue());
        }
        runScript(arrayList);
    }

    /* JADX INFO: renamed from: c */
    private static void m2642c() {
        OutputStream outputStream = null;
        String strM3577a = C1336v.m3577a(TMSApplication.getApplicaionContext(), f6287f, (String) null);
        String str = "chmod 755 " + strM3577a + "\n" + (strM3577a + " " + f6286e + " " + Process.myUid()) + "\n";
        ProcessBuilder processBuilder = new ProcessBuilder(new String[0]);
        processBuilder.command("sh");
        try {
            try {
                processBuilder.redirectErrorStream(true);
                outputStream = processBuilder.start().getOutputStream();
                outputStream.write(str.getBytes());
                outputStream.flush();
                if (outputStream != null) {
                    try {
                        outputStream.close();
                    } catch (IOException e) {
                        e = e;
                        e.printStackTrace();
                    }
                }
            } catch (IOException e2) {
                e2.printStackTrace();
                if (outputStream != null) {
                    try {
                        outputStream.close();
                    } catch (IOException e3) {
                        e = e3;
                        e.printStackTrace();
                    }
                }
            }
        } catch (Throwable th) {
            if (outputStream != null) {
                try {
                    outputStream.close();
                } catch (IOException e4) {
                    e4.printStackTrace();
                }
            }
            throw th;
        }
    }

    public static int canRunAtRoot() {
        return canRunAtRoot(1);
    }

    public static int canRunAtRoot(int i) {
        int iM2639a = 0;
        if (f6289h) {
            return 0;
        }
        if (!f6288g) {
            return 1;
        }
        synchronized (f6284c) {
            if (f6283b) {
                iM2639a = 2;
            } else {
                f6283b = true;
                for (int i2 = 0; i2 < i; i2++) {
                    iM2639a = m2639a();
                    if (iM2639a != -1) {
                        break;
                    }
                }
                if (iM2639a == 0 && !f6282a) {
                    TMSApplication.getApplicaionContext().sendBroadcast(new Intent(ROOT_GOT_ACTION));
                    f6282a = true;
                }
                synchronized (f6284c) {
                    f6283b = false;
                }
            }
        }
        return iM2639a;
    }

    public static void canRunAtRoot(Callback callback) {
        new C1319hf(callback).start();
    }

    public static boolean isRootGot() {
        C1084a c1084a = new C1084a();
        c1084a.f6293b = 1000;
        c1084a.f6295d = "id\n".getBytes();
        C1085b c1085bM2640a = m2640a(c1084a, false);
        return c1085bM2640a != null && new String(c1085bM2640a.f6297b).contains("uid=0");
    }

    public static boolean isSystemUid() {
        return Process.myUid() == 1000;
    }

    public static InterfaceC1326l provider() {
        return f6291j;
    }

    public static boolean providerSupportCancelMissCall() {
        return f6291j != null && f6291j.m3509a(2);
    }

    public static boolean providerSupportCpuRelative() {
        return f6291j != null && f6291j.m3509a(3);
    }

    public static boolean providerSupportGetAllApkFiles() {
        return f6291j != null && f6291j.m3509a(1);
    }

    public static boolean providerSupportPmRelative() {
        return f6291j != null && f6291j.m3509a(4);
    }

    public static int runScript(StringBuilder sb, List<String> list) {
        String strRunScript = runScript(list);
        if (strRunScript != null && sb != null) {
            sb.append(strRunScript);
        }
        return strRunScript == null ? 0 : -1;
    }

    public static int runScript(StringBuilder sb, String... strArr) {
        return runScript(sb, (List<String>) Arrays.asList(strArr));
    }

    public static String runScript(int i, List<String> list) {
        StringBuilder sb = new StringBuilder();
        Iterator<String> it = list.iterator();
        while (it.hasNext()) {
            sb.append(it.next()).append("\n");
        }
        C1084a c1084a = new C1084a();
        c1084a.f6293b = i;
        c1084a.f6295d = sb.toString().getBytes();
        C1085b c1085bM2640a = m2640a(c1084a, true);
        if (c1085bM2640a != null) {
            return new String(c1085bM2640a.f6297b).trim();
        }
        return null;
    }

    public static String runScript(int i, String... strArr) {
        return runScript(i, (List<String>) Arrays.asList(strArr));
    }

    public static String runScript(List<String> list) {
        return runScript(30000, list);
    }

    public static String runScript(String... strArr) {
        return runScript(30000, (List<String>) Arrays.asList(strArr));
    }

    public static int runScriptAsRoot(StringBuilder sb, List<String> list) {
        if (canRunAtRoot() != 0) {
            return -1;
        }
        String strRunScript = runScript(list);
        if (strRunScript != null && sb != null) {
            sb.append(strRunScript);
        }
        return strRunScript != null ? 0 : -1;
    }

    public static int runScriptAsRoot(StringBuilder sb, String... strArr) {
        return runScriptAsRoot(sb, (List<String>) Arrays.asList(strArr));
    }

    public static int runScriptAsRoot(List<String> list) {
        return runScriptAsRoot(new StringBuilder(), list);
    }

    public static int runScriptAsRoot(String... strArr) {
        return runScriptAsRoot(new StringBuilder(), (List<String>) Arrays.asList(strArr));
    }

    public static int runScriptIfSystemUidOrAsRoot(List<String> list) {
        return isSystemUid() ? runScript(new StringBuilder(), list) : runScriptAsRoot(list);
    }

    public static int runScriptIfSystemUidOrAsRoot(String... strArr) {
        return isSystemUid() ? runScript(new StringBuilder(), strArr) : runScriptAsRoot(strArr);
    }

    public static String[] runScriptSplitLines(String... strArr) {
        StringBuilder sb = new StringBuilder();
        runScript(sb, (List<String>) Arrays.asList(strArr));
        return sb.toString().trim().split("\n");
    }

    public static void setProvider(InterfaceC1326l interfaceC1326l) {
        boolean z = false;
        for (StackTraceElement stackTraceElement : Thread.currentThread().getStackTrace()) {
            if (stackTraceElement.getClass().isAssignableFrom(TMSApplication.class) && stackTraceElement.getMethodName().indexOf("init") >= 0) {
                z = true;
                break;
            }
        }
        if (z) {
            f6291j = interfaceC1326l;
        } else {
            Log.m2634e("ScriptHelper", "Unauthorized caller");
        }
    }
}
