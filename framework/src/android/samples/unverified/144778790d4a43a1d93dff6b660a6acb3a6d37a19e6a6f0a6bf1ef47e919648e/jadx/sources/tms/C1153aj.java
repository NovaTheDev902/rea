package tms;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: tms.aj */
/* JADX INFO: loaded from: classes.dex */
public final class C1153aj {

    /* JADX INFO: renamed from: a */
    private static volatile C1153aj f6833a;

    /* JADX INFO: renamed from: b */
    private List<InterfaceC1197c> f6834b = new ArrayList();

    private C1153aj() {
        Iterator<String> it = m2913d().iterator();
        while (it.hasNext()) {
            this.f6834b.add(new C1224d(it.next()));
        }
    }

    /* JADX INFO: renamed from: a */
    public static synchronized C1153aj m2912a() {
        if (f6833a == null) {
            f6833a = new C1153aj();
        }
        return f6833a;
    }

    /* JADX INFO: renamed from: d */
    public static final synchronized List<String> m2913d() {
        ArrayList arrayList;
        synchronized (C1153aj.class) {
            arrayList = new ArrayList();
            for (String str : new String[]{"phone", "phone1", "phone2", "phoneEX"}) {
                if (C1152ai.m2908b(str) != null) {
                    arrayList.add(str);
                }
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public final void m2914a(String str) {
        this.f6834b.get(0).mo3038a(str);
    }

    /* JADX INFO: renamed from: b */
    public final void m2915b() {
        Iterator<InterfaceC1197c> it = this.f6834b.iterator();
        while (it.hasNext()) {
            it.next().mo3040b();
        }
    }

    /* JADX INFO: renamed from: c */
    public final boolean m2916c() {
        Iterator<InterfaceC1197c> it = this.f6834b.iterator();
        while (it.hasNext()) {
            it.next().mo3039a();
        }
        return true;
    }
}
