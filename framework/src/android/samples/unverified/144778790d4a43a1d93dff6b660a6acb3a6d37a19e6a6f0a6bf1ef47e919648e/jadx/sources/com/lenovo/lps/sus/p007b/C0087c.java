package com.lenovo.lps.sus.p007b;

/* JADX INFO: renamed from: com.lenovo.lps.sus.b.c */
/* JADX INFO: loaded from: classes.dex */
public class C0087c {

    /* JADX INFO: renamed from: a */
    public int f1254a = 0;

    /* JADX INFO: renamed from: b */
    public EnumC0088d f1255b = EnumC0088d.UPDATEACTION_NORMAL;

    /* JADX INFO: renamed from: c */
    public static EnumC0088d m299c(int i) {
        if (i == EnumC0088d.UPDATEACTION_NORMAL.ordinal()) {
            return EnumC0088d.UPDATEACTION_NORMAL;
        }
        if (i == EnumC0088d.UPDATEACTION_NEWVERPROMPT.ordinal()) {
            return EnumC0088d.UPDATEACTION_NEWVERPROMPT;
        }
        return null;
    }

    /* JADX INFO: renamed from: a */
    public int m300a() {
        return this.f1255b.ordinal();
    }

    /* JADX INFO: renamed from: a */
    public void m301a(int i) {
        if (i == EnumC0088d.UPDATEACTION_NORMAL.ordinal()) {
            this.f1255b = EnumC0088d.UPDATEACTION_NORMAL;
        } else if (i == EnumC0088d.UPDATEACTION_NEWVERPROMPT.ordinal()) {
            this.f1255b = EnumC0088d.UPDATEACTION_NEWVERPROMPT;
        }
    }

    /* JADX INFO: renamed from: a */
    public void m302a(EnumC0088d enumC0088d) {
        this.f1255b = enumC0088d;
    }

    /* JADX INFO: renamed from: b */
    public EnumC0088d m303b() {
        return this.f1255b;
    }

    /* JADX INFO: renamed from: b */
    public void m304b(int i) {
        this.f1254a = i;
    }

    /* JADX INFO: renamed from: c */
    public int m305c() {
        return this.f1254a;
    }
}
