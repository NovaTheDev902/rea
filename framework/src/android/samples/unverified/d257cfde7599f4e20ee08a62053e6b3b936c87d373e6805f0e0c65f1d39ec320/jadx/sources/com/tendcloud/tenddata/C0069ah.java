package com.tendcloud.tenddata;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: com.tendcloud.tenddata.ah */
/* JADX INFO: loaded from: classes.dex */
public class C0069ah implements InterfaceC0076h, InterfaceC0088t {

    /* JADX INFO: renamed from: a */
    public String f64a = "";

    /* JADX INFO: renamed from: b */
    public String f65b = "";

    /* JADX INFO: renamed from: c */
    public C0078j f66c = new C0078j();

    /* JADX INFO: renamed from: d */
    public C0093y f67d = new C0093y();

    /* JADX INFO: renamed from: e */
    public List f68e = new ArrayList();

    /* JADX INFO: renamed from: f */
    public long f69f = 0;

    /* JADX INFO: renamed from: g */
    public long f70g = 0;

    /* JADX INFO: renamed from: h */
    public long f71h = 0;

    /* JADX INFO: renamed from: i */
    public Long[][] f72i;

    @Override // com.tendcloud.tenddata.InterfaceC0088t
    /* JADX INFO: renamed from: a */
    public int mo58a() {
        return C0084p.m81c(5) + C0084p.m83c(this.f64a) + C0084p.m83c(this.f65b) + this.f66c.mo56a() + this.f67d.mo56a();
    }

    @Override // com.tendcloud.tenddata.InterfaceC0076h
    /* JADX INFO: renamed from: a */
    public void mo57a(C0084p c0084p) throws IOException {
        c0084p.m110b(6);
        c0084p.m98a(this.f64a);
        c0084p.m98a(this.f65b);
        c0084p.m90a(this.f66c);
        c0084p.m90a(this.f67d);
        c0084p.m110b(this.f68e.size());
        Iterator it = this.f68e.iterator();
        while (it.hasNext()) {
            c0084p.m90a((C0068ag) it.next());
        }
        if (this.f72i == null) {
            c0084p.m108b();
            return;
        }
        c0084p.m110b(this.f72i.length);
        for (Long[] lArr : this.f72i) {
            c0084p.m107a(lArr);
        }
    }
}
