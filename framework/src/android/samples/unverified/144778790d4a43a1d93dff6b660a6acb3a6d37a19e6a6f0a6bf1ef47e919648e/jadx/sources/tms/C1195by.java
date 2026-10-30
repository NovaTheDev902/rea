package tms;

import com.tencent.tmsecure.module.aresengine.FilterResult;

/* JADX INFO: renamed from: tms.by */
/* JADX INFO: loaded from: classes.dex */
final class C1195by extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1211cn.a f6969a;

    C1195by(C1211cn.a aVar) {
        this.f6969a = aVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        return m2963b() == 2 && this.f6969a.f6996a.contains(m2960a().phonenum, 1);
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        FilterResult filterResult = new FilterResult();
        filterResult.mFilterfiled = m2965d();
        filterResult.mState = m2963b();
        filterResult.mData = m2960a();
        filterResult.mDotos.add(new RunnableC1196bz(this, filterResult));
        m2961a(filterResult);
    }
}
