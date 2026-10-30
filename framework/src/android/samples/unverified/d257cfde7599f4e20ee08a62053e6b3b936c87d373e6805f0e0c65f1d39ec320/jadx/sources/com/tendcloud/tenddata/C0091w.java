package com.tendcloud.tenddata;

import java.io.IOException;

/* JADX INFO: renamed from: com.tendcloud.tenddata.w */
/* JADX INFO: loaded from: classes.dex */
public class C0091w implements InterfaceC0076h, InterfaceC0080l {

    /* JADX INFO: renamed from: a */
    public long f189a = 0;

    /* JADX INFO: renamed from: b */
    public int f190b = 1;

    /* JADX INFO: renamed from: c */
    public String f191c = "";

    /* JADX INFO: renamed from: d */
    public byte[] f192d = new byte[0];

    /* JADX INFO: renamed from: e */
    public String f193e = "";

    @Override // com.tendcloud.tenddata.InterfaceC0080l
    /* JADX INFO: renamed from: a */
    public int mo56a() {
        return C0084p.m81c(5) + C0084p.m82c(this.f189a) + C0084p.m81c(this.f190b) + C0084p.m83c(this.f191c) + C0084p.m80b(this.f192d) + C0084p.m83c(this.f193e);
    }

    @Override // com.tendcloud.tenddata.InterfaceC0076h
    /* JADX INFO: renamed from: a */
    public void mo57a(C0084p c0084p) throws IOException {
        c0084p.m110b(5);
        c0084p.m89a(this.f189a);
        c0084p.m88a(this.f190b);
        c0084p.m98a(this.f191c);
        c0084p.m105a(this.f192d);
        c0084p.m98a(this.f193e);
    }
}
