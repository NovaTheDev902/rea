package com.lenovo.lps.sus.p008c;

/* JADX INFO: renamed from: com.lenovo.lps.sus.c.d */
/* JADX INFO: loaded from: classes.dex */
public class C0093d implements Comparable {

    /* JADX INFO: renamed from: a */
    public String f1364a;

    /* JADX INFO: renamed from: b */
    public long f1365b;

    /* JADX INFO: renamed from: c */
    public long f1366c;

    /* JADX INFO: renamed from: d */
    public int f1367d;

    @Override // java.lang.Comparable
    /* JADX INFO: renamed from: a, reason: merged with bridge method [inline-methods] */
    public int compareTo(C0093d c0093d) {
        return (c0093d != null && this.f1366c - c0093d.f1366c <= 0) ? -1 : 1;
    }
}
