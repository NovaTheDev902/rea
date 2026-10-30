package com.tendcloud.tenddata;

import java.io.IOException;

/* JADX INFO: renamed from: com.tendcloud.tenddata.ag */
/* JADX INFO: loaded from: classes.dex */
public class C0068ag implements InterfaceC0076h {

    /* JADX INFO: renamed from: a */
    public int f60a = -1;

    /* JADX INFO: renamed from: b */
    public C0070b f61b;

    /* JADX INFO: renamed from: c */
    public C0081m f62c;

    /* JADX INFO: renamed from: d */
    public C0091w f63d;

    @Override // com.tendcloud.tenddata.InterfaceC0076h
    /* JADX INFO: renamed from: a */
    public void mo57a(C0084p c0084p) throws IOException {
        c0084p.m110b(2);
        c0084p.m88a(this.f60a);
        switch (this.f60a) {
            case 1:
                c0084p.m90a(this.f62c);
                return;
            case 2:
                c0084p.m90a(this.f61b);
                return;
            case 3:
                c0084p.m90a(this.f63d);
                return;
            default:
                throw new IOException("unknown TMessageType");
        }
    }
}
