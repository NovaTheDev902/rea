package com.tendcloud.tenddata;

import java.io.IOException;

/* JADX INFO: renamed from: com.tendcloud.tenddata.j */
/* JADX INFO: loaded from: classes.dex */
public class C0078j implements InterfaceC0076h, InterfaceC0080l {

    /* JADX INFO: renamed from: a */
    public String f113a = "";

    /* JADX INFO: renamed from: b */
    public String f114b = "";

    /* JADX INFO: renamed from: c */
    public String f115c = "";

    /* JADX INFO: renamed from: d */
    public long f116d = 0;

    /* JADX INFO: renamed from: e */
    public String f117e = "";

    /* JADX INFO: renamed from: f */
    public String f118f = "";

    /* JADX INFO: renamed from: g */
    public boolean f119g = false;

    /* JADX INFO: renamed from: h */
    public long f120h = 0;

    /* JADX INFO: renamed from: i */
    public long f121i = 0;

    @Override // com.tendcloud.tenddata.InterfaceC0080l
    /* JADX INFO: renamed from: a */
    public int mo56a() {
        return C0084p.m81c(9) + C0084p.m83c(this.f113a) + C0084p.m83c(this.f114b) + C0084p.m83c(this.f115c) + C0084p.m82c(this.f116d) + C0084p.m83c(this.f117e) + C0084p.m83c(this.f118f) + C0084p.m79b(this.f119g) + C0084p.m82c(this.f120h) + C0084p.m82c(this.f121i);
    }

    @Override // com.tendcloud.tenddata.InterfaceC0076h
    /* JADX INFO: renamed from: a */
    public void mo57a(C0084p c0084p) throws IOException {
        c0084p.m110b(9);
        c0084p.m98a(this.f113a);
        c0084p.m98a(this.f114b);
        c0084p.m98a(this.f115c);
        c0084p.m89a(this.f116d);
        c0084p.m98a(this.f117e);
        c0084p.m98a(this.f118f);
        c0084p.m104a(this.f119g);
        c0084p.m89a(this.f120h);
        c0084p.m89a(this.f121i);
    }
}
