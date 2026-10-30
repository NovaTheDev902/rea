package com.lenovo.lps.sus.p009d;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Process;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.SocketException;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.http.Header;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;

/* JADX INFO: renamed from: com.lenovo.lps.sus.d.f */
/* JADX INFO: loaded from: classes.dex */
public class C0144f extends Thread {

    /* JADX INFO: renamed from: a */
    private Context f1584a;

    /* JADX INFO: renamed from: b */
    private boolean f1585b = false;

    /* JADX INFO: renamed from: c */
    private InterfaceC0139a f1586c;

    /* JADX INFO: renamed from: d */
    private String f1587d;

    /* JADX INFO: renamed from: e */
    private String f1588e;

    /* JADX INFO: renamed from: f */
    private long f1589f;

    /* JADX INFO: renamed from: g */
    private File f1590g;

    /* JADX INFO: renamed from: h */
    private String f1591h;

    /* JADX INFO: renamed from: i */
    private String f1592i;

    /* JADX INFO: renamed from: j */
    private int f1593j;

    public C0144f(Context context, int i, String str, String str2, long j, File file, String str3, InterfaceC0139a interfaceC0139a) {
        this.f1587d = null;
        this.f1588e = null;
        this.f1589f = 0L;
        this.f1590g = null;
        this.f1591h = null;
        this.f1592i = null;
        this.f1593j = 0;
        this.f1584a = context;
        this.f1586c = interfaceC0139a;
        this.f1593j = (i < 0 || i > 2) ? 0 : i;
        this.f1587d = str;
        if (this.f1587d == null) {
            this.f1587d = C0092c.f1331as;
        }
        this.f1588e = str2;
        this.f1589f = j;
        this.f1590g = file;
        this.f1591h = str3;
        this.f1592i = String.valueOf(this.f1590g.toString()) + CookieSpec.PATH_DELIM + this.f1591h;
    }

    /* JADX INFO: renamed from: a */
    private void m555a(String str) {
        if (this.f1586c != null) {
            this.f1586c.mo534a(str);
        }
    }

    /* JADX INFO: renamed from: a */
    public void m556a() {
        this.f1585b = true;
    }

    /* JADX INFO: renamed from: a */
    public void m557a(InterfaceC0139a interfaceC0139a) {
        this.f1586c = interfaceC0139a;
    }

    /* JADX INFO: renamed from: b */
    public void m558b() {
        this.f1585b = true;
    }

    /* JADX WARN: Code duplicated, block: B:103:0x031c A[Catch: FileNotFoundException -> 0x0262, RuntimeException -> 0x03c5, all -> 0x05ae, TryCatch #25 {FileNotFoundException -> 0x0262, RuntimeException -> 0x03c5, all -> 0x05ae, blocks: (B:62:0x0170, B:63:0x018a, B:64:0x018e, B:66:0x019a, B:97:0x02c3, B:99:0x02ed, B:100:0x02f0, B:101:0x02fc, B:103:0x031c, B:105:0x0322, B:107:0x0332, B:109:0x0357, B:116:0x0372, B:118:0x037c, B:119:0x039a, B:120:0x03a6, B:68:0x01af, B:70:0x01df, B:72:0x020f, B:74:0x0219, B:75:0x0237, B:76:0x0243), top: B:260:0x0170 }] */
    /* JADX WARN: Code duplicated, block: B:105:0x0322 A[Catch: FileNotFoundException -> 0x0262, RuntimeException -> 0x03c5, all -> 0x05ae, TryCatch #25 {FileNotFoundException -> 0x0262, RuntimeException -> 0x03c5, all -> 0x05ae, blocks: (B:62:0x0170, B:63:0x018a, B:64:0x018e, B:66:0x019a, B:97:0x02c3, B:99:0x02ed, B:100:0x02f0, B:101:0x02fc, B:103:0x031c, B:105:0x0322, B:107:0x0332, B:109:0x0357, B:116:0x0372, B:118:0x037c, B:119:0x039a, B:120:0x03a6, B:68:0x01af, B:70:0x01df, B:72:0x020f, B:74:0x0219, B:75:0x0237, B:76:0x0243), top: B:260:0x0170 }] */
    /* JADX WARN: Code duplicated, block: B:107:0x0332 A[Catch: FileNotFoundException -> 0x0262, RuntimeException -> 0x03c5, all -> 0x05ae, TRY_LEAVE, TryCatch #25 {FileNotFoundException -> 0x0262, RuntimeException -> 0x03c5, all -> 0x05ae, blocks: (B:62:0x0170, B:63:0x018a, B:64:0x018e, B:66:0x019a, B:97:0x02c3, B:99:0x02ed, B:100:0x02f0, B:101:0x02fc, B:103:0x031c, B:105:0x0322, B:107:0x0332, B:109:0x0357, B:116:0x0372, B:118:0x037c, B:119:0x039a, B:120:0x03a6, B:68:0x01af, B:70:0x01df, B:72:0x020f, B:74:0x0219, B:75:0x0237, B:76:0x0243), top: B:260:0x0170 }] */
    /* JADX WARN: Code duplicated, block: B:127:0x03f0  */
    /* JADX WARN: Code duplicated, block: B:139:0x041f A[Catch: FileNotFoundException -> 0x04bd, RuntimeException -> 0x04e8, all -> 0x05b0, TRY_ENTER, TryCatch #27 {FileNotFoundException -> 0x04bd, RuntimeException -> 0x04e8, all -> 0x05b0, blocks: (B:111:0x0361, B:113:0x0367, B:135:0x0416, B:139:0x041f, B:141:0x0428, B:142:0x0440, B:144:0x0448, B:153:0x04ce, B:158:0x04f4, B:159:0x04ff, B:161:0x0505, B:163:0x050b, B:165:0x0513, B:167:0x051d, B:146:0x046c, B:148:0x0476, B:149:0x0494, B:150:0x049e), top: B:257:0x0361 }] */
    /* JADX WARN: Code duplicated, block: B:144:0x0448 A[Catch: FileNotFoundException -> 0x04bd, RuntimeException -> 0x04e8, all -> 0x05b0, EDGE_INSN: B:144:0x0448->B:39:0x0101 BREAK  A[LOOP:0: B:257:0x0361->B:269:0x0361], TryCatch #27 {FileNotFoundException -> 0x04bd, RuntimeException -> 0x04e8, all -> 0x05b0, blocks: (B:111:0x0361, B:113:0x0367, B:135:0x0416, B:139:0x041f, B:141:0x0428, B:142:0x0440, B:144:0x0448, B:153:0x04ce, B:158:0x04f4, B:159:0x04ff, B:161:0x0505, B:163:0x050b, B:165:0x0513, B:167:0x051d, B:146:0x046c, B:148:0x0476, B:149:0x0494, B:150:0x049e), top: B:257:0x0361 }] */
    /* JADX WARN: Code duplicated, block: B:153:0x04ce A[Catch: FileNotFoundException -> 0x04bd, RuntimeException -> 0x04e8, all -> 0x05b0, TRY_LEAVE, TryCatch #27 {FileNotFoundException -> 0x04bd, RuntimeException -> 0x04e8, all -> 0x05b0, blocks: (B:111:0x0361, B:113:0x0367, B:135:0x0416, B:139:0x041f, B:141:0x0428, B:142:0x0440, B:144:0x0448, B:153:0x04ce, B:158:0x04f4, B:159:0x04ff, B:161:0x0505, B:163:0x050b, B:165:0x0513, B:167:0x051d, B:146:0x046c, B:148:0x0476, B:149:0x0494, B:150:0x049e), top: B:257:0x0361 }] */
    /* JADX WARN: Code duplicated, block: B:157:0x04f2 A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:174:0x0537  */
    /* JADX WARN: Code duplicated, block: B:188:0x0581  */
    /* JADX WARN: Code duplicated, block: B:221:0x05fc A[EDGE_INSN: B:221:0x05fc->B:39:0x0101 BREAK  A[LOOP:0: B:257:0x0361->B:269:0x0361]] */
    /* JADX WARN: Code duplicated, block: B:222:0x0602  */
    /* JADX WARN: Code duplicated, block: B:230:0x04f4 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:232:0x0416 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:234:0x0541 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:240:0x03fa A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:244:0x0108 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:246:0x053c A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:248:0x03f5 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:250:0x029b A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:252:0x0296 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:254:0x010d A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:258:0x018a A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:260:0x0170 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:264:0x050b A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:265:0x041d A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:266:0x0367 A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:267:0x0513 A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:270:0x0361 A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:271:0x0361 A[ADDED_TO_REGION, REMOVE, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:277:? A[RETURN, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:279:? A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:38:0x00fa  */
    /* JADX WARN: Code duplicated, block: B:40:0x0103  */
    /* JADX WARN: Code duplicated, block: B:47:0x0118  */
    /* JADX WARN: Code duplicated, block: B:60:0x0165 A[Catch: all -> 0x05ab, RuntimeException -> 0x05d4, FileNotFoundException -> 0x05f1, TRY_ENTER, TRY_LEAVE, TryCatch #4 {all -> 0x05ab, blocks: (B:34:0x00d0, B:36:0x00da, B:60:0x0165, B:58:0x0147), top: B:226:0x00a7 }] */
    /* JADX WARN: Code duplicated, block: B:66:0x019a A[Catch: FileNotFoundException -> 0x0262, RuntimeException -> 0x03c5, all -> 0x05ae, TryCatch #25 {FileNotFoundException -> 0x0262, RuntimeException -> 0x03c5, all -> 0x05ae, blocks: (B:62:0x0170, B:63:0x018a, B:64:0x018e, B:66:0x019a, B:97:0x02c3, B:99:0x02ed, B:100:0x02f0, B:101:0x02fc, B:103:0x031c, B:105:0x0322, B:107:0x0332, B:109:0x0357, B:116:0x0372, B:118:0x037c, B:119:0x039a, B:120:0x03a6, B:68:0x01af, B:70:0x01df, B:72:0x020f, B:74:0x0219, B:75:0x0237, B:76:0x0243), top: B:260:0x0170 }] */
    /* JADX WARN: Code duplicated, block: B:83:0x0291  */
    /* JADX WARN: Code duplicated, block: B:91:0x02b7  */
    /* JADX WARN: Code duplicated, block: B:92:0x02b9  */
    /* JADX WARN: Code duplicated, block: B:94:0x02bd A[ADDED_TO_REGION] */
    @Override // java.lang.Thread, java.lang.Runnable
    public void run() throws Throwable {
        HttpGet httpGet;
        RuntimeException runtimeException;
        InputStream inputStream;
        long j;
        FileNotFoundException fileNotFoundException;
        InputStream inputStream2;
        HttpGet httpGet2;
        FileOutputStream fileOutputStream;
        char c;
        boolean z;
        boolean z2;
        long j2;
        DefaultHttpClient defaultHttpClient;
        InputStream inputStream3;
        HttpResponse httpResponseExecute;
        int statusCode;
        Header firstHeader;
        String str;
        InputStream content;
        FileOutputStream fileOutputStream2;
        long j3;
        int i;
        long j4;
        String value;
        int i2;
        Process.setThreadPriority(10);
        InputStream inputStream4 = null;
        if (this.f1592i != null) {
            if (this.f1592i == null || this.f1592i.length() != 0) {
                SharedPreferences sharedPreferences = this.f1584a.getSharedPreferences(C0092c.f1322aj, 0);
                String string = sharedPreferences.getString(C0092c.f1323ak, null);
                int i3 = sharedPreferences.getInt(C0092c.f1324al, 0);
                if (string == null || !string.equals(this.f1588e)) {
                    if (this.f1592i != null) {
                        File file = new File(this.f1592i);
                        if (file.exists()) {
                            file.delete();
                        }
                    }
                    i3 = 0;
                } else if (this.f1592i != null) {
                    File file2 = new File(this.f1592i);
                    if (file2.exists()) {
                        long length = file2.length();
                        if (length == this.f1589f) {
                            m555a(this.f1592i);
                            return;
                        } else if (length > this.f1589f || i3 > 6) {
                            file2.delete();
                            i3 = 0;
                        } else {
                            i3++;
                        }
                    }
                }
                SharedPreferences.Editor editorEdit = sharedPreferences.edit();
                editorEdit.putString(C0092c.f1323ak, this.f1588e);
                editorEdit.putInt(C0092c.f1324al, i3);
                editorEdit.commit();
                FileOutputStream fileOutputStream3 = null;
                try {
                    try {
                        byte[] bArr = new byte[2048];
                        try {
                            try {
                                if (this.f1592i != null) {
                                    File file3 = new File(this.f1592i);
                                    if (file3.exists()) {
                                        long length2 = file3.length();
                                        if (0 < length2) {
                                            fileOutputStream3 = new FileOutputStream(this.f1592i, true);
                                            try {
                                                try {
                                                    fileOutputStream3.close();
                                                    fileOutputStream3 = null;
                                                    z2 = true;
                                                    j2 = length2;
                                                } catch (IOException e) {
                                                    C0098i.m412c(C0092c.f1339b, "exception when closing the file before download : " + e);
                                                    j2 = length2;
                                                    z2 = true;
                                                }
                                            } catch (FileNotFoundException e2) {
                                                httpGet2 = null;
                                                fileOutputStream = fileOutputStream3;
                                                fileNotFoundException = e2;
                                                inputStream2 = null;
                                                j = length2;
                                                try {
                                                    C0098i.m409a(C0092c.f1339b, "FileNotFoundException for " + this.f1592i + " : " + fileNotFoundException);
                                                    c = 492;
                                                    if (httpGet2 != null) {
                                                        httpGet2.abort();
                                                    }
                                                    if (inputStream2 != null) {
                                                        try {
                                                            inputStream2.close();
                                                        } catch (IOException e3) {
                                                        }
                                                    }
                                                    if (fileOutputStream != null) {
                                                        try {
                                                            fileOutputStream.close();
                                                        } catch (IOException e4) {
                                                            C0098i.m412c(C0092c.f1339b, "exception when closing the file after download : " + e4);
                                                        }
                                                    }
                                                    if (j < this.f1589f) {
                                                    }
                                                    sleep(C0092c.f1328ap);
                                                    z = this.f1585b;
                                                    if (this.f1586c != null) {
                                                        this.f1586c.mo535a(z);
                                                    }
                                                } catch (Throwable th) {
                                                    th = th;
                                                    inputStream4 = inputStream2;
                                                    fileOutputStream3 = fileOutputStream;
                                                    httpGet = httpGet2;
                                                    if (httpGet != null) {
                                                        httpGet.abort();
                                                    }
                                                    if (inputStream4 != null) {
                                                        try {
                                                            inputStream4.close();
                                                        } catch (IOException e5) {
                                                        }
                                                    }
                                                    if (fileOutputStream3 != null) {
                                                        throw th;
                                                    }
                                                    try {
                                                        fileOutputStream3.close();
                                                        throw th;
                                                    } catch (IOException e6) {
                                                        C0098i.m412c(C0092c.f1339b, "exception when closing the file after download : " + e6);
                                                        throw th;
                                                    }
                                                }
                                            } catch (RuntimeException e7) {
                                                httpGet = null;
                                                inputStream = null;
                                                runtimeException = e7;
                                                j = length2;
                                                try {
                                                    C0098i.m409a(C0092c.f1339b, "Exception for " + this.f1588e + runtimeException.toString());
                                                    c = 491;
                                                    if (httpGet != null) {
                                                        httpGet.abort();
                                                    }
                                                    if (inputStream != null) {
                                                        try {
                                                            inputStream.close();
                                                        } catch (IOException e8) {
                                                        }
                                                    }
                                                    if (fileOutputStream3 != null) {
                                                        try {
                                                            fileOutputStream3.close();
                                                        } catch (IOException e9) {
                                                            C0098i.m412c(C0092c.f1339b, "exception when closing the file after download : " + e9);
                                                        }
                                                    }
                                                    if (j < this.f1589f) {
                                                    }
                                                    sleep(C0092c.f1328ap);
                                                    z = this.f1585b;
                                                    if (this.f1586c != null) {
                                                        this.f1586c.mo535a(z);
                                                    }
                                                } catch (Throwable th2) {
                                                    th = th2;
                                                    inputStream4 = inputStream;
                                                    if (httpGet != null) {
                                                        httpGet.abort();
                                                    }
                                                    if (inputStream4 != null) {
                                                        inputStream4.close();
                                                    }
                                                    if (fileOutputStream3 != null) {
                                                        throw th;
                                                    }
                                                    fileOutputStream3.close();
                                                    throw th;
                                                }
                                            }
                                        }
                                        BasicHttpParams basicHttpParams = new BasicHttpParams();
                                        HttpConnectionParams.setConnectionTimeout(basicHttpParams, (this.f1593j * 2000) + 6000);
                                        HttpConnectionParams.setSoTimeout(basicHttpParams, 10000);
                                        defaultHttpClient = new DefaultHttpClient(basicHttpParams);
                                        if (this.f1585b) {
                                            httpGet = null;
                                            c = 491;
                                            j = j2;
                                            inputStream3 = null;
                                        } else {
                                            httpGet = new HttpGet(this.f1588e);
                                            if (z2) {
                                                try {
                                                    httpGet.addHeader("Range", "bytes=" + j2 + "-");
                                                    try {
                                                        httpResponseExecute = defaultHttpClient.execute(httpGet);
                                                        statusCode = httpResponseExecute.getStatusLine().getStatusCode();
                                                        if (statusCode == 503) {
                                                            C0098i.m412c(C0092c.f1339b, "got HTTP response code 503");
                                                            c = 193;
                                                            httpGet.abort();
                                                            httpGet = null;
                                                            j = j2;
                                                            inputStream3 = null;
                                                        } else if ((!z2 || statusCode == 200) && (!z2 || statusCode == 206)) {
                                                            C0098i.m412c(C0092c.f1339b, "received response for " + this.f1588e);
                                                            firstHeader = httpResponseExecute.getFirstHeader("Content-Length");
                                                            if (firstHeader != null) {
                                                                value = firstHeader.getValue();
                                                                if (value != null) {
                                                                    i2 = Integer.parseInt(value);
                                                                    if (((long) i2) + j2 != this.f1589f) {
                                                                        C0098i.m411b(C0092c.f1339b, "fileSize error!!! fileSize=%d" + this.f1589f + "; contentLength=%d" + i2);
                                                                    }
                                                                }
                                                                str = value;
                                                            } else {
                                                                str = null;
                                                            }
                                                            try {
                                                                content = httpResponseExecute.getEntity().getContent();
                                                                fileOutputStream2 = fileOutputStream3;
                                                                j3 = 0;
                                                                while (true) {
                                                                    try {
                                                                        if (this.f1585b) {
                                                                            httpGet.abort();
                                                                            httpGet = null;
                                                                            fileOutputStream3 = fileOutputStream2;
                                                                            j = j2;
                                                                            inputStream3 = content;
                                                                            c = 491;
                                                                            break;
                                                                        }
                                                                        try {
                                                                            i = content.read(bArr);
                                                                            if (i == -1) {
                                                                                if (str != null || j2 == Integer.parseInt(str)) {
                                                                                    C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                                                } else {
                                                                                    C0098i.m409a(C0092c.f1339b, "mismatched content length " + this.f1588e);
                                                                                }
                                                                                if (j2 < this.f1589f) {
                                                                                    fileOutputStream3 = fileOutputStream2;
                                                                                    j = j2;
                                                                                    inputStream3 = content;
                                                                                    c = 491;
                                                                                    break;
                                                                                }
                                                                                C0098i.m412c(C0092c.f1339b, "download completed for " + this.f1588e);
                                                                                fileOutputStream3 = fileOutputStream2;
                                                                                long j5 = j2;
                                                                                inputStream3 = content;
                                                                                c = 200;
                                                                                j = j5;
                                                                                break;
                                                                            }
                                                                            if (fileOutputStream2 == null) {
                                                                                try {
                                                                                    fileOutputStream2 = new FileOutputStream(this.f1592i, true);
                                                                                } catch (IOException e10) {
                                                                                    fileOutputStream3 = fileOutputStream2;
                                                                                    j = j2;
                                                                                    inputStream3 = content;
                                                                                    c = 491;
                                                                                }
                                                                            }
                                                                            fileOutputStream2.write(bArr, 0, i);
                                                                            j2 += (long) i;
                                                                            if (this.f1586c != null) {
                                                                                j4 = j2 - j3;
                                                                                if (j4 < 0 && (j4 << 7) > this.f1589f) {
                                                                                    this.f1586c.mo533a(j2, this.f1589f);
                                                                                    j3 = j2;
                                                                                }
                                                                            }
                                                                        } catch (IOException e11) {
                                                                            if (C0092c.m379l(this.f1584a)) {
                                                                                C0098i.m412c(C0092c.f1339b, "Read Failed " + this.f1588e + " Net Up");
                                                                            } else {
                                                                                C0098i.m412c(C0092c.f1339b, "Read Failed " + this.f1588e + ", Net Down");
                                                                            }
                                                                            httpGet.abort();
                                                                            httpGet = null;
                                                                            fileOutputStream3 = fileOutputStream2;
                                                                            j = j2;
                                                                            inputStream3 = content;
                                                                            c = 491;
                                                                        }
                                                                    } catch (FileNotFoundException e12) {
                                                                        fileNotFoundException = e12;
                                                                        long j6 = j2;
                                                                        inputStream2 = content;
                                                                        httpGet2 = httpGet;
                                                                        fileOutputStream = fileOutputStream2;
                                                                        j = j6;
                                                                        C0098i.m409a(C0092c.f1339b, "FileNotFoundException for " + this.f1592i + " : " + fileNotFoundException);
                                                                        c = 492;
                                                                        if (httpGet2 != null) {
                                                                            httpGet2.abort();
                                                                        }
                                                                        if (inputStream2 != null) {
                                                                            inputStream2.close();
                                                                        }
                                                                        if (fileOutputStream != null) {
                                                                            fileOutputStream.close();
                                                                        }
                                                                    } catch (RuntimeException e13) {
                                                                        fileOutputStream3 = fileOutputStream2;
                                                                        runtimeException = e13;
                                                                        j = j2;
                                                                        inputStream = content;
                                                                        C0098i.m409a(C0092c.f1339b, "Exception for " + this.f1588e + runtimeException.toString());
                                                                        c = 491;
                                                                        if (httpGet != null) {
                                                                            httpGet.abort();
                                                                        }
                                                                        if (inputStream != null) {
                                                                            inputStream.close();
                                                                        }
                                                                        if (fileOutputStream3 != null) {
                                                                            fileOutputStream3.close();
                                                                        }
                                                                    } catch (Throwable th3) {
                                                                        fileOutputStream3 = fileOutputStream2;
                                                                        th = th3;
                                                                        inputStream4 = content;
                                                                        if (httpGet != null) {
                                                                            httpGet.abort();
                                                                        }
                                                                        if (inputStream4 != null) {
                                                                            inputStream4.close();
                                                                        }
                                                                        if (fileOutputStream3 != null) {
                                                                            throw th;
                                                                        }
                                                                        fileOutputStream3.close();
                                                                        throw th;
                                                                    }
                                                                }
                                                            } catch (IOException e14) {
                                                                if (C0092c.m379l(this.f1584a)) {
                                                                    C0098i.m412c(C0092c.f1339b, "Get Failed " + this.f1588e + ", Net Up");
                                                                } else {
                                                                    C0098i.m412c(C0092c.f1339b, "Get Failed " + this.f1588e + ", Net Down");
                                                                }
                                                                httpGet.abort();
                                                                httpGet = null;
                                                                c = 491;
                                                                long j7 = j2;
                                                                inputStream3 = null;
                                                                j = j7;
                                                            }
                                                        } else {
                                                            C0098i.m409a(C0092c.f1339b, "http error " + statusCode + " for download " + this.f1588e);
                                                            Header firstHeader2 = httpResponseExecute.getFirstHeader("Content-Length");
                                                            if (firstHeader2 != null) {
                                                                firstHeader2.getValue();
                                                            }
                                                            httpGet.abort();
                                                            httpGet = null;
                                                            c = 491;
                                                            long j8 = j2;
                                                            inputStream3 = null;
                                                            j = j8;
                                                        }
                                                    } catch (IOException e15) {
                                                        if (C0092c.m379l(this.f1584a)) {
                                                            C0098i.m412c(C0092c.f1339b, "Execute Failed " + this.f1588e + ", Net Up");
                                                        } else {
                                                            C0098i.m412c(C0092c.f1339b, "Execute Failed " + this.f1588e + ", Net Down");
                                                        }
                                                        httpGet.abort();
                                                        httpGet = null;
                                                        c = 491;
                                                        long j9 = j2;
                                                        inputStream3 = null;
                                                        j = j9;
                                                    } catch (IllegalArgumentException e16) {
                                                        C0098i.m409a(C0092c.f1339b, "Arg exception trying to execute request for " + this.f1588e + " : " + e16);
                                                        c = 400;
                                                        httpGet.abort();
                                                        httpGet = null;
                                                        j = j2;
                                                        inputStream3 = null;
                                                    } catch (SocketException e17) {
                                                        C0098i.m409a(C0092c.f1339b, "timeout exception trying to execute request for " + this.f1588e + " : " + e17);
                                                        c = 491;
                                                        httpGet.abort();
                                                        httpGet = null;
                                                        j = j2;
                                                        inputStream3 = null;
                                                    }
                                                } catch (FileNotFoundException e18) {
                                                    fileNotFoundException = e18;
                                                    j = j2;
                                                    inputStream2 = null;
                                                    httpGet2 = httpGet;
                                                    fileOutputStream = fileOutputStream3;
                                                    C0098i.m409a(C0092c.f1339b, "FileNotFoundException for " + this.f1592i + " : " + fileNotFoundException);
                                                    c = 492;
                                                    if (httpGet2 != null) {
                                                        httpGet2.abort();
                                                    }
                                                    if (inputStream2 != null) {
                                                        inputStream2.close();
                                                    }
                                                    if (fileOutputStream != null) {
                                                        fileOutputStream.close();
                                                    }
                                                    if (j < this.f1589f) {
                                                    }
                                                    sleep(C0092c.f1328ap);
                                                    z = this.f1585b;
                                                    if (this.f1586c != null) {
                                                        this.f1586c.mo535a(z);
                                                    }
                                                } catch (RuntimeException e19) {
                                                    runtimeException = e19;
                                                    j = j2;
                                                    inputStream = null;
                                                    C0098i.m409a(C0092c.f1339b, "Exception for " + this.f1588e + runtimeException.toString());
                                                    c = 491;
                                                    if (httpGet != null) {
                                                        httpGet.abort();
                                                    }
                                                    if (inputStream != null) {
                                                        inputStream.close();
                                                    }
                                                    if (fileOutputStream3 != null) {
                                                        fileOutputStream3.close();
                                                    }
                                                    if (j < this.f1589f) {
                                                    }
                                                    sleep(C0092c.f1328ap);
                                                    z = this.f1585b;
                                                    if (this.f1586c != null) {
                                                        this.f1586c.mo535a(z);
                                                    }
                                                } catch (Throwable th4) {
                                                    th = th4;
                                                    if (httpGet != null) {
                                                        httpGet.abort();
                                                    }
                                                    if (inputStream4 != null) {
                                                        inputStream4.close();
                                                    }
                                                    if (fileOutputStream3 != null) {
                                                        throw th;
                                                    }
                                                    fileOutputStream3.close();
                                                    throw th;
                                                }
                                            } else {
                                                httpResponseExecute = defaultHttpClient.execute(httpGet);
                                                statusCode = httpResponseExecute.getStatusLine().getStatusCode();
                                                if (statusCode == 503) {
                                                    C0098i.m412c(C0092c.f1339b, "got HTTP response code 503");
                                                    c = 193;
                                                    httpGet.abort();
                                                    httpGet = null;
                                                    j = j2;
                                                    inputStream3 = null;
                                                } else if (z2) {
                                                    C0098i.m412c(C0092c.f1339b, "received response for " + this.f1588e);
                                                    firstHeader = httpResponseExecute.getFirstHeader("Content-Length");
                                                    if (firstHeader != null) {
                                                        value = firstHeader.getValue();
                                                        if (value != null) {
                                                            i2 = Integer.parseInt(value);
                                                            if (((long) i2) + j2 != this.f1589f) {
                                                                C0098i.m411b(C0092c.f1339b, "fileSize error!!! fileSize=%d" + this.f1589f + "; contentLength=%d" + i2);
                                                            }
                                                        }
                                                        str = value;
                                                    } else {
                                                        str = null;
                                                    }
                                                    content = httpResponseExecute.getEntity().getContent();
                                                    fileOutputStream2 = fileOutputStream3;
                                                    j3 = 0;
                                                    while (true) {
                                                        if (this.f1585b) {
                                                            httpGet.abort();
                                                            httpGet = null;
                                                            fileOutputStream3 = fileOutputStream2;
                                                            j = j2;
                                                            inputStream3 = content;
                                                            c = 491;
                                                            break;
                                                        }
                                                        i = content.read(bArr);
                                                        if (i == -1) {
                                                            if (str != null) {
                                                                C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                            } else {
                                                                C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                            }
                                                            if (j2 < this.f1589f) {
                                                                fileOutputStream3 = fileOutputStream2;
                                                                j = j2;
                                                                inputStream3 = content;
                                                                c = 491;
                                                                break;
                                                            }
                                                            C0098i.m412c(C0092c.f1339b, "download completed for " + this.f1588e);
                                                            fileOutputStream3 = fileOutputStream2;
                                                            long j10 = j2;
                                                            inputStream3 = content;
                                                            c = 200;
                                                            j = j10;
                                                            break;
                                                        }
                                                        if (fileOutputStream2 == null) {
                                                            fileOutputStream2 = new FileOutputStream(this.f1592i, true);
                                                        }
                                                        fileOutputStream2.write(bArr, 0, i);
                                                        j2 += (long) i;
                                                        if (this.f1586c != null) {
                                                            j4 = j2 - j3;
                                                            if (j4 < 0) {
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    C0098i.m412c(C0092c.f1339b, "received response for " + this.f1588e);
                                                    firstHeader = httpResponseExecute.getFirstHeader("Content-Length");
                                                    if (firstHeader != null) {
                                                        value = firstHeader.getValue();
                                                        if (value != null) {
                                                            i2 = Integer.parseInt(value);
                                                            if (((long) i2) + j2 != this.f1589f) {
                                                                C0098i.m411b(C0092c.f1339b, "fileSize error!!! fileSize=%d" + this.f1589f + "; contentLength=%d" + i2);
                                                            }
                                                        }
                                                        str = value;
                                                    } else {
                                                        str = null;
                                                    }
                                                    content = httpResponseExecute.getEntity().getContent();
                                                    fileOutputStream2 = fileOutputStream3;
                                                    j3 = 0;
                                                    while (true) {
                                                        if (this.f1585b) {
                                                            httpGet.abort();
                                                            httpGet = null;
                                                            fileOutputStream3 = fileOutputStream2;
                                                            j = j2;
                                                            inputStream3 = content;
                                                            c = 491;
                                                            break;
                                                        }
                                                        i = content.read(bArr);
                                                        if (i == -1) {
                                                            if (str != null) {
                                                                C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                            } else {
                                                                C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                            }
                                                            if (j2 < this.f1589f) {
                                                                fileOutputStream3 = fileOutputStream2;
                                                                j = j2;
                                                                inputStream3 = content;
                                                                c = 491;
                                                                break;
                                                            }
                                                            C0098i.m412c(C0092c.f1339b, "download completed for " + this.f1588e);
                                                            fileOutputStream3 = fileOutputStream2;
                                                            long j11 = j2;
                                                            inputStream3 = content;
                                                            c = 200;
                                                            j = j11;
                                                            break;
                                                        }
                                                        if (fileOutputStream2 == null) {
                                                            fileOutputStream2 = new FileOutputStream(this.f1592i, true);
                                                        }
                                                        fileOutputStream2.write(bArr, 0, i);
                                                        j2 += (long) i;
                                                        if (this.f1586c != null) {
                                                            j4 = j2 - j3;
                                                            if (j4 < 0) {
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (httpGet != null) {
                                            httpGet.abort();
                                        }
                                        if (inputStream3 != null) {
                                            try {
                                                inputStream3.close();
                                            } catch (IOException e20) {
                                            }
                                        }
                                        if (fileOutputStream3 != null) {
                                            try {
                                                fileOutputStream3.close();
                                            } catch (IOException e21) {
                                                C0098i.m412c(C0092c.f1339b, "exception when closing the file after download : " + e21);
                                            }
                                        }
                                        if (j < this.f1589f && 200 == c) {
                                            m555a(this.f1592i);
                                            return;
                                        }
                                        sleep(C0092c.f1328ap);
                                        z = this.f1585b;
                                        if (this.f1586c != null) {
                                            this.f1586c.mo535a(z);
                                        }
                                    }
                                }
                                BasicHttpParams basicHttpParams2 = new BasicHttpParams();
                                HttpConnectionParams.setConnectionTimeout(basicHttpParams2, (this.f1593j * 2000) + 6000);
                                HttpConnectionParams.setSoTimeout(basicHttpParams2, 10000);
                                defaultHttpClient = new DefaultHttpClient(basicHttpParams2);
                                if (this.f1585b) {
                                    httpGet = null;
                                    c = 491;
                                    j = j2;
                                    inputStream3 = null;
                                } else {
                                    httpGet = new HttpGet(this.f1588e);
                                    if (z2) {
                                        httpGet.addHeader("Range", "bytes=" + j2 + "-");
                                        httpResponseExecute = defaultHttpClient.execute(httpGet);
                                        statusCode = httpResponseExecute.getStatusLine().getStatusCode();
                                        if (statusCode == 503) {
                                            C0098i.m412c(C0092c.f1339b, "got HTTP response code 503");
                                            c = 193;
                                            httpGet.abort();
                                            httpGet = null;
                                            j = j2;
                                            inputStream3 = null;
                                        } else if (z2) {
                                            C0098i.m412c(C0092c.f1339b, "received response for " + this.f1588e);
                                            firstHeader = httpResponseExecute.getFirstHeader("Content-Length");
                                            if (firstHeader != null) {
                                                value = firstHeader.getValue();
                                                if (value != null) {
                                                    i2 = Integer.parseInt(value);
                                                    if (((long) i2) + j2 != this.f1589f) {
                                                        C0098i.m411b(C0092c.f1339b, "fileSize error!!! fileSize=%d" + this.f1589f + "; contentLength=%d" + i2);
                                                    }
                                                }
                                                str = value;
                                            } else {
                                                str = null;
                                            }
                                            content = httpResponseExecute.getEntity().getContent();
                                            fileOutputStream2 = fileOutputStream3;
                                            j3 = 0;
                                            while (true) {
                                                if (this.f1585b) {
                                                    httpGet.abort();
                                                    httpGet = null;
                                                    fileOutputStream3 = fileOutputStream2;
                                                    j = j2;
                                                    inputStream3 = content;
                                                    c = 491;
                                                    break;
                                                }
                                                i = content.read(bArr);
                                                if (i == -1) {
                                                    if (str != null) {
                                                        C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                    } else {
                                                        C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                    }
                                                    if (j2 < this.f1589f) {
                                                        fileOutputStream3 = fileOutputStream2;
                                                        j = j2;
                                                        inputStream3 = content;
                                                        c = 491;
                                                        break;
                                                    }
                                                    C0098i.m412c(C0092c.f1339b, "download completed for " + this.f1588e);
                                                    fileOutputStream3 = fileOutputStream2;
                                                    long j12 = j2;
                                                    inputStream3 = content;
                                                    c = 200;
                                                    j = j12;
                                                    break;
                                                }
                                                if (fileOutputStream2 == null) {
                                                    fileOutputStream2 = new FileOutputStream(this.f1592i, true);
                                                }
                                                fileOutputStream2.write(bArr, 0, i);
                                                j2 += (long) i;
                                                if (this.f1586c != null) {
                                                    j4 = j2 - j3;
                                                    if (j4 < 0) {
                                                    }
                                                }
                                            }
                                        } else {
                                            C0098i.m412c(C0092c.f1339b, "received response for " + this.f1588e);
                                            firstHeader = httpResponseExecute.getFirstHeader("Content-Length");
                                            if (firstHeader != null) {
                                                value = firstHeader.getValue();
                                                if (value != null) {
                                                    i2 = Integer.parseInt(value);
                                                    if (((long) i2) + j2 != this.f1589f) {
                                                        C0098i.m411b(C0092c.f1339b, "fileSize error!!! fileSize=%d" + this.f1589f + "; contentLength=%d" + i2);
                                                    }
                                                }
                                                str = value;
                                            } else {
                                                str = null;
                                            }
                                            content = httpResponseExecute.getEntity().getContent();
                                            fileOutputStream2 = fileOutputStream3;
                                            j3 = 0;
                                            while (true) {
                                                if (this.f1585b) {
                                                    httpGet.abort();
                                                    httpGet = null;
                                                    fileOutputStream3 = fileOutputStream2;
                                                    j = j2;
                                                    inputStream3 = content;
                                                    c = 491;
                                                    break;
                                                }
                                                i = content.read(bArr);
                                                if (i == -1) {
                                                    if (str != null) {
                                                        C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                    } else {
                                                        C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                    }
                                                    if (j2 < this.f1589f) {
                                                        fileOutputStream3 = fileOutputStream2;
                                                        j = j2;
                                                        inputStream3 = content;
                                                        c = 491;
                                                        break;
                                                    }
                                                    C0098i.m412c(C0092c.f1339b, "download completed for " + this.f1588e);
                                                    fileOutputStream3 = fileOutputStream2;
                                                    long j13 = j2;
                                                    inputStream3 = content;
                                                    c = 200;
                                                    j = j13;
                                                    break;
                                                }
                                                if (fileOutputStream2 == null) {
                                                    fileOutputStream2 = new FileOutputStream(this.f1592i, true);
                                                }
                                                fileOutputStream2.write(bArr, 0, i);
                                                j2 += (long) i;
                                                if (this.f1586c != null) {
                                                    j4 = j2 - j3;
                                                    if (j4 < 0) {
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        httpResponseExecute = defaultHttpClient.execute(httpGet);
                                        statusCode = httpResponseExecute.getStatusLine().getStatusCode();
                                        if (statusCode == 503) {
                                            C0098i.m412c(C0092c.f1339b, "got HTTP response code 503");
                                            c = 193;
                                            httpGet.abort();
                                            httpGet = null;
                                            j = j2;
                                            inputStream3 = null;
                                        } else if (z2) {
                                            C0098i.m412c(C0092c.f1339b, "received response for " + this.f1588e);
                                            firstHeader = httpResponseExecute.getFirstHeader("Content-Length");
                                            if (firstHeader != null) {
                                                value = firstHeader.getValue();
                                                if (value != null) {
                                                    i2 = Integer.parseInt(value);
                                                    if (((long) i2) + j2 != this.f1589f) {
                                                        C0098i.m411b(C0092c.f1339b, "fileSize error!!! fileSize=%d" + this.f1589f + "; contentLength=%d" + i2);
                                                    }
                                                }
                                                str = value;
                                            } else {
                                                str = null;
                                            }
                                            content = httpResponseExecute.getEntity().getContent();
                                            fileOutputStream2 = fileOutputStream3;
                                            j3 = 0;
                                            while (true) {
                                                if (this.f1585b) {
                                                    httpGet.abort();
                                                    httpGet = null;
                                                    fileOutputStream3 = fileOutputStream2;
                                                    j = j2;
                                                    inputStream3 = content;
                                                    c = 491;
                                                    break;
                                                }
                                                i = content.read(bArr);
                                                if (i == -1) {
                                                    if (str != null) {
                                                        C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                    } else {
                                                        C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                    }
                                                    if (j2 < this.f1589f) {
                                                        fileOutputStream3 = fileOutputStream2;
                                                        j = j2;
                                                        inputStream3 = content;
                                                        c = 491;
                                                        break;
                                                    }
                                                    C0098i.m412c(C0092c.f1339b, "download completed for " + this.f1588e);
                                                    fileOutputStream3 = fileOutputStream2;
                                                    long j14 = j2;
                                                    inputStream3 = content;
                                                    c = 200;
                                                    j = j14;
                                                    break;
                                                }
                                                if (fileOutputStream2 == null) {
                                                    fileOutputStream2 = new FileOutputStream(this.f1592i, true);
                                                }
                                                fileOutputStream2.write(bArr, 0, i);
                                                j2 += (long) i;
                                                if (this.f1586c != null) {
                                                    j4 = j2 - j3;
                                                    if (j4 < 0) {
                                                    }
                                                }
                                            }
                                        } else {
                                            C0098i.m412c(C0092c.f1339b, "received response for " + this.f1588e);
                                            firstHeader = httpResponseExecute.getFirstHeader("Content-Length");
                                            if (firstHeader != null) {
                                                value = firstHeader.getValue();
                                                if (value != null) {
                                                    i2 = Integer.parseInt(value);
                                                    if (((long) i2) + j2 != this.f1589f) {
                                                        C0098i.m411b(C0092c.f1339b, "fileSize error!!! fileSize=%d" + this.f1589f + "; contentLength=%d" + i2);
                                                    }
                                                }
                                                str = value;
                                            } else {
                                                str = null;
                                            }
                                            content = httpResponseExecute.getEntity().getContent();
                                            fileOutputStream2 = fileOutputStream3;
                                            j3 = 0;
                                            while (true) {
                                                if (this.f1585b) {
                                                    httpGet.abort();
                                                    httpGet = null;
                                                    fileOutputStream3 = fileOutputStream2;
                                                    j = j2;
                                                    inputStream3 = content;
                                                    c = 491;
                                                    break;
                                                }
                                                i = content.read(bArr);
                                                if (i == -1) {
                                                    if (str != null) {
                                                        C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                    } else {
                                                        C0098i.m409a(C0092c.f1339b, "mismatched content length for " + this.f1588e);
                                                    }
                                                    if (j2 < this.f1589f) {
                                                        fileOutputStream3 = fileOutputStream2;
                                                        j = j2;
                                                        inputStream3 = content;
                                                        c = 491;
                                                        break;
                                                    }
                                                    C0098i.m412c(C0092c.f1339b, "download completed for " + this.f1588e);
                                                    fileOutputStream3 = fileOutputStream2;
                                                    long j15 = j2;
                                                    inputStream3 = content;
                                                    c = 200;
                                                    j = j15;
                                                    break;
                                                }
                                                if (fileOutputStream2 == null) {
                                                    fileOutputStream2 = new FileOutputStream(this.f1592i, true);
                                                }
                                                fileOutputStream2.write(bArr, 0, i);
                                                j2 += (long) i;
                                                if (this.f1586c != null) {
                                                    j4 = j2 - j3;
                                                    if (j4 < 0) {
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (httpGet != null) {
                                    httpGet.abort();
                                }
                                if (inputStream3 != null) {
                                    inputStream3.close();
                                }
                                if (fileOutputStream3 != null) {
                                    fileOutputStream3.close();
                                }
                            } catch (FileNotFoundException e22) {
                                fileNotFoundException = e22;
                                fileOutputStream = fileOutputStream3;
                                long j16 = j2;
                                httpGet2 = null;
                                inputStream2 = null;
                                j = j16;
                            } catch (RuntimeException e23) {
                                runtimeException = e23;
                                httpGet = null;
                                long j17 = j2;
                                inputStream = null;
                                j = j17;
                            }
                            z2 = false;
                            fileOutputStream3 = null;
                            j2 = 0;
                        } catch (Throwable th5) {
                            th = th5;
                            httpGet = null;
                        }
                    } catch (FileNotFoundException e24) {
                        fileNotFoundException = e24;
                        inputStream2 = null;
                        j = 0;
                        httpGet2 = null;
                        fileOutputStream = null;
                    } catch (RuntimeException e25) {
                        runtimeException = e25;
                        inputStream = null;
                        fileOutputStream3 = null;
                        j = 0;
                        httpGet = null;
                    } catch (Throwable th6) {
                        th = th6;
                        httpGet = null;
                        fileOutputStream3 = null;
                    }
                    sleep(C0092c.f1328ap);
                } catch (InterruptedException e26) {
                    C0098i.m412c(C0092c.f1339b, "exception when sleeping the thread : " + e26);
                }
                if (j < this.f1589f) {
                }
                z = this.f1585b;
                if (this.f1586c != null) {
                    this.f1586c.mo535a(z);
                }
            }
        }
    }
}
