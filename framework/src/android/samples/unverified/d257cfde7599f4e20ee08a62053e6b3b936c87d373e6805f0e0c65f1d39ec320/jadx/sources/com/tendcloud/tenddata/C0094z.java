package com.tendcloud.tenddata;

import java.io.IOException;

/* JADX INFO: renamed from: com.tendcloud.tenddata.z */
/* JADX INFO: loaded from: classes.dex */
public class C0094z implements InterfaceC0076h, InterfaceC0080l {

    /* JADX INFO: renamed from: a */
    public String f220a = "";

    /* JADX INFO: renamed from: b */
    public long f221b = 0;

    /* JADX INFO: renamed from: c */
    public int f222c = 0;

    /* JADX INFO: renamed from: d */
    public String f223d = "";

    @Override // com.tendcloud.tenddata.InterfaceC0080l
    /* JADX INFO: renamed from: a */
    public int mo56a() {
        return C0084p.m81c(4) + C0084p.m83c(this.f220a) + C0084p.m82c(this.f221b) + C0084p.m81c(this.f222c) + C0084p.m83c(this.f223d);
    }

    @Override // com.tendcloud.tenddata.InterfaceC0076h
    /* JADX INFO: renamed from: a */
    public void mo57a(C0084p c0084p) throws IOException {
        c0084p.m110b(4);
        c0084p.m98a(this.f220a);
        c0084p.m89a(this.f221b);
        c0084p.m88a(this.f222c);
        c0084p.m98a(this.f223d);
    }
}
