package tms;

import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bh */
/* JADX INFO: loaded from: classes.dex */
final class C1178bh extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1189bs.b f6916a;

    C1178bh(C1189bs.b bVar) {
        this.f6916a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    public final boolean mo2967f() {
        return m2963b() == 2 && this.f6916a.f6946f.contains(((SmsEntity) m2960a()).phonenum, 1);
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    public final void mo2968g() {
        SmsEntity smsEntity = (SmsEntity) m2960a();
        this.f6916a.f6954n.blockSms(m2964c());
        FilterResult filterResult = new FilterResult();
        filterResult.mData = m2960a();
        filterResult.mFilterfiled = m2965d();
        filterResult.mState = m2963b();
        filterResult.mDotos.add(this.f6916a.m3014a(smsEntity, this.f6916a.f6949i, filterResult));
        m2961a(filterResult);
    }
}
