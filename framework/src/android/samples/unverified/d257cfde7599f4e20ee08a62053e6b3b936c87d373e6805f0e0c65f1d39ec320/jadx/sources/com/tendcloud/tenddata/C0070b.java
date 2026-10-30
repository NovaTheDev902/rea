package com.tendcloud.tenddata;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: com.tendcloud.tenddata.b */
/* JADX INFO: loaded from: classes.dex */
public class C0070b implements InterfaceC0076h, InterfaceC0080l {

    /* JADX INFO: renamed from: d */
    public static final int f73d = 1;

    /* JADX INFO: renamed from: e */
    public static final int f74e = 2;

    /* JADX INFO: renamed from: f */
    public static final int f75f = 3;

    /* JADX INFO: renamed from: a */
    public String f76a = "";

    /* JADX INFO: renamed from: b */
    public long f77b = 0;

    /* JADX INFO: renamed from: c */
    public int f78c = 0;

    /* JADX INFO: renamed from: g */
    public int f79g = 0;

    /* JADX INFO: renamed from: h */
    public List f80h = new ArrayList();

    /* JADX INFO: renamed from: i */
    public List f81i = new ArrayList();

    /* JADX INFO: renamed from: j */
    public int f82j = 0;

    /* JADX INFO: renamed from: k */
    public int f83k = 0;

    @Override // com.tendcloud.tenddata.InterfaceC0080l
    /* JADX INFO: renamed from: a */
    public int mo56a() {
        int i;
        int iM81c = C0084p.m81c(7) + C0084p.m83c(this.f76a) + C0084p.m82c(this.f77b) + C0084p.m81c(this.f78c) + C0084p.m81c(this.f79g) + C0084p.m81c(this.f83k) + C0084p.m81c(this.f80h.size());
        Iterator it = this.f80h.iterator();
        while (true) {
            i = iM81c;
            if (!it.hasNext()) {
                break;
            }
            iM81c = ((C0094z) it.next()).mo56a() + i;
        }
        int iM81c2 = C0084p.m81c(this.f81i.size()) + i;
        Iterator it2 = this.f81i.iterator();
        while (true) {
            int i2 = iM81c2;
            if (!it2.hasNext()) {
                return i2;
            }
            iM81c2 = ((C0067af) it2.next()).mo56a() + i2;
        }
    }

    @Override // com.tendcloud.tenddata.InterfaceC0076h
    /* JADX INFO: renamed from: a */
    public void mo57a(C0084p c0084p) throws IOException {
        c0084p.m110b(7);
        c0084p.m98a(this.f76a);
        c0084p.m89a(this.f77b);
        c0084p.m88a(this.f78c);
        c0084p.m88a(this.f79g);
        c0084p.m110b(this.f80h.size());
        Iterator it = this.f80h.iterator();
        while (it.hasNext()) {
            c0084p.m90a((C0094z) it.next());
        }
        c0084p.m110b(this.f81i.size());
        Iterator it2 = this.f81i.iterator();
        while (it2.hasNext()) {
            c0084p.m90a((C0067af) it2.next());
        }
        c0084p.m88a(this.f83k);
    }
}
