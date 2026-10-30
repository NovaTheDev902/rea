package org.apache.commons.httpclient;

import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.lang.reflect.Method;

/* JADX INFO: loaded from: classes.dex */
public class HttpException extends IOException {

    /* JADX INFO: renamed from: a */
    static Class f6479a;

    /* JADX INFO: renamed from: b */
    private String f6480b;

    /* JADX INFO: renamed from: c */
    private int f6481c;

    /* JADX INFO: renamed from: d */
    private final Throwable f6482d;

    public HttpException() {
        this.f6481c = 200;
        this.f6482d = null;
    }

    public HttpException(String message) {
        super(message);
        this.f6481c = 200;
        this.f6482d = null;
    }

    public HttpException(String message, Throwable cause) {
        Class<?> clsM2709a;
        Class clsM2709a2;
        super(message);
        this.f6481c = 200;
        this.f6482d = cause;
        try {
            Class<?>[] clsArr = new Class[1];
            if (f6479a == null) {
                clsM2709a = m2709a("java.lang.Throwable");
                f6479a = clsM2709a;
            } else {
                clsM2709a = f6479a;
            }
            clsArr[0] = clsM2709a;
            if (f6479a == null) {
                clsM2709a2 = m2709a("java.lang.Throwable");
                f6479a = clsM2709a2;
            } else {
                clsM2709a2 = f6479a;
            }
            Method initCause = clsM2709a2.getMethod("initCause", clsArr);
            initCause.invoke(this, cause);
        } catch (Exception e) {
        }
    }

    /* JADX INFO: renamed from: a */
    private static Class m2709a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    @Override // java.lang.Throwable
    public Throwable getCause() {
        return this.f6482d;
    }

    @Override // java.lang.Throwable
    public void printStackTrace() {
        printStackTrace(System.err);
    }

    @Override // java.lang.Throwable
    public void printStackTrace(PrintStream s) {
        try {
            getClass().getMethod("getStackTrace", new Class[0]);
            super.printStackTrace(s);
        } catch (Exception e) {
            super.printStackTrace(s);
            if (this.f6482d != null) {
                s.print("Caused by: ");
                this.f6482d.printStackTrace(s);
            }
        }
    }

    @Override // java.lang.Throwable
    public void printStackTrace(PrintWriter s) {
        try {
            getClass().getMethod("getStackTrace", new Class[0]);
            super.printStackTrace(s);
        } catch (Exception e) {
            super.printStackTrace(s);
            if (this.f6482d != null) {
                s.print("Caused by: ");
                this.f6482d.printStackTrace(s);
            }
        }
    }

    public void setReason(String reason) {
        this.f6480b = reason;
    }

    public String getReason() {
        return this.f6480b;
    }

    public void setReasonCode(int code) {
        this.f6481c = code;
    }

    public int getReasonCode() {
        return this.f6481c;
    }
}
