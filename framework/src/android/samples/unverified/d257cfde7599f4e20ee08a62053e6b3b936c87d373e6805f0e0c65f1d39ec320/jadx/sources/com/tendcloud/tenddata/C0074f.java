package com.tendcloud.tenddata;

import java.io.IOException;

/* JADX INFO: renamed from: com.tendcloud.tenddata.f */
/* JADX INFO: loaded from: classes.dex */
public class C0074f implements InterfaceC0076h, InterfaceC0080l {

    /* JADX INFO: renamed from: a */
    public double f110a = 0.0d;

    /* JADX INFO: renamed from: b */
    public double f111b = 0.0d;

    @Override // com.tendcloud.tenddata.InterfaceC0080l
    /* JADX INFO: renamed from: a */
    public int mo56a() {
        return C0084p.m81c(2) + C0084p.m77b(this.f110a) + C0084p.m77b(this.f111b);
    }

    @Override // com.tendcloud.tenddata.InterfaceC0076h
    /* JADX INFO: renamed from: a */
    public void mo57a(C0084p c0084p) throws IOException {
        c0084p.m110b(2);
        c0084p.m86a(this.f110a);
        c0084p.m86a(this.f111b);
    }
}
