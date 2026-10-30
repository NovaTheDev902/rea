package com.tendcloud.tenddata;

import java.io.IOException;
import java.util.Map;

/* JADX INFO: renamed from: com.tendcloud.tenddata.af */
/* JADX INFO: loaded from: classes.dex */
public class C0067af implements InterfaceC0076h, InterfaceC0080l {

    /* JADX INFO: renamed from: a */
    public String f55a = "";

    /* JADX INFO: renamed from: b */
    public String f56b = "";

    /* JADX INFO: renamed from: c */
    public int f57c = 0;

    /* JADX INFO: renamed from: d */
    public long f58d;

    /* JADX INFO: renamed from: e */
    public Map f59e;

    @Override // com.tendcloud.tenddata.InterfaceC0080l
    /* JADX INFO: renamed from: a */
    public int mo56a() {
        return C0084p.m81c(3) + C0084p.m83c(this.f55a) + C0084p.m83c(this.f56b) + C0084p.m81c(this.f57c);
    }

    @Override // com.tendcloud.tenddata.InterfaceC0076h
    /* JADX INFO: renamed from: a */
    public void mo57a(C0084p c0084p) throws IOException {
        c0084p.m110b(5);
        c0084p.m98a(this.f55a);
        c0084p.m98a(this.f56b);
        c0084p.m88a(this.f57c);
        c0084p.m89a(this.f58d);
        c0084p.m102a(this.f59e);
    }
}
