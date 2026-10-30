package org.apache.commons.httpclient;

/* JADX INFO: renamed from: org.apache.commons.httpclient.b */
/* JADX INFO: compiled from: HttpMethodBase.java */
/* JADX INFO: loaded from: classes.dex */
final class C1119b implements InterfaceC1130d {

    /* JADX INFO: renamed from: a */
    private final HttpMethodBase f6613a;

    C1119b(HttpMethodBase httpMethodBase) {
        this.f6613a = httpMethodBase;
    }

    @Override // org.apache.commons.httpclient.InterfaceC1130d
    /* JADX INFO: renamed from: a */
    public final void mo2786a() {
        this.f6613a.responseBodyConsumed();
    }
}
