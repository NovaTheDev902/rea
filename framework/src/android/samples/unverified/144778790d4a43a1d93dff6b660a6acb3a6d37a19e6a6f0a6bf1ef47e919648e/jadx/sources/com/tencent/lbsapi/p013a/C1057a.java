package com.tencent.lbsapi.p013a;

import android.content.Context;
import java.net.UnknownHostException;
import org.apache.commons.httpclient.methods.PostMethod;
import org.apache.http.message.BasicHeader;

/* JADX INFO: renamed from: com.tencent.lbsapi.a.a */
/* JADX INFO: loaded from: classes.dex */
public class C1057a extends Thread {

    /* JADX INFO: renamed from: a */
    private byte[] f5896a = null;

    /* JADX INFO: renamed from: b */
    private InterfaceC1058b f5897b = null;

    /* JADX INFO: renamed from: c */
    private int f5898c = 0;

    /* JADX INFO: renamed from: d */
    private String f5899d = null;

    /* JADX INFO: renamed from: e */
    private Context f5900e = null;

    /* JADX INFO: renamed from: a */
    protected void m2485a(int i) {
        this.f5898c = i;
    }

    /* JADX INFO: renamed from: a */
    protected void m2486a(Context context) {
        this.f5900e = context;
    }

    /* JADX INFO: renamed from: a */
    protected void m2487a(InterfaceC1058b interfaceC1058b) {
        this.f5897b = interfaceC1058b;
    }

    /* JADX INFO: renamed from: a */
    protected void m2488a(String str) {
        this.f5899d = str;
    }

    /* JADX INFO: renamed from: a */
    protected void m2489a(byte[] bArr) {
        this.f5896a = bArr;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public void run() {
        boolean z;
        if (this.f5897b == null) {
            return;
        }
        int i = 0;
        do {
            try {
                byte[] bArrM2493a = C1059c.m2493a("http://lbsapi.3g.qq.com/wupbin", this.f5896a, "POST", new BasicHeader[]{new BasicHeader("Content-Type", PostMethod.FORM_URL_ENCODED_CONTENT_TYPE), new BasicHeader("UA", "ANDROID"), new BasicHeader("LBS-UIN", this.f5899d)}, this.f5900e);
                if (this.f5897b != null) {
                    this.f5897b.mo2491a(this.f5898c, bArrM2493a, bArrM2493a.length);
                }
                z = false;
            } catch (C1060d e) {
                if (this.f5897b != null) {
                    this.f5897b.mo2490a(this.f5898c, -1, "HTTP数据错误");
                }
                z = false;
            } catch (NullPointerException e2) {
                if (i < 1) {
                    i++;
                    z = true;
                } else {
                    if (this.f5897b != null) {
                        this.f5897b.mo2490a(this.f5898c, -1, "HTTP数据错误");
                    }
                    z = false;
                }
            } catch (UnknownHostException e3) {
                if (i < 1) {
                    i++;
                    z = true;
                } else {
                    if (this.f5897b != null) {
                        this.f5897b.mo2490a(this.f5898c, -1, "HTTP数据错误");
                    }
                    z = false;
                }
            } catch (Exception e4) {
                e4.getCause();
                e4.printStackTrace();
                if (this.f5897b != null) {
                    this.f5897b.mo2490a(this.f5898c, -1, "HTTP数据错误");
                }
                z = false;
            }
        } while (z);
        this.f5900e = null;
        this.f5897b = null;
        try {
            finalize();
        } catch (Throwable th) {
            th.printStackTrace();
        }
    }
}
