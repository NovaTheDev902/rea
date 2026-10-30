package tms;

import com.tencent.tmsecure.module.aresengine.AbsSysDao;
import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.IContactDao;
import com.tencent.tmsecure.module.aresengine.ILastCallLogDao;

/* JADX INFO: renamed from: tms.bc */
/* JADX INFO: loaded from: classes.dex */
final class C1173bc extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ int f6908a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1184bn.a f6909b;

    C1173bc(C1184bn.a aVar, int i) {
        this.f6909b = aVar;
        this.f6908a = i;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        Object obj = null;
        boolean z = m2963b() != 2;
        switch (this.f6908a) {
            case 1:
                obj = this.f6909b.f6927c;
                break;
            case 2:
                obj = this.f6909b.f6925a;
                break;
            case 4:
                obj = this.f6909b.f6926b;
                break;
            case 8:
                obj = this.f6909b.f6928d;
                break;
            case 16:
                obj = this.f6909b.f6929e;
                break;
        }
        if (obj == null && this.f6908a == 32) {
            return true;
        }
        if (obj instanceof IContactDao) {
            return z & ((IContactDao) obj).contains(m2960a().phonenum, 0);
        }
        if (obj instanceof ILastCallLogDao) {
            return z & ((ILastCallLogDao) obj).contains(m2960a().phonenum);
        }
        return obj instanceof AbsSysDao ? z & ((AbsSysDao) obj).contains(m2960a().phonenum) : z & false;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        FilterResult filterResult = new FilterResult();
        filterResult.mData = m2960a();
        filterResult.mParams = m2964c();
        filterResult.mState = m2963b();
        filterResult.mFilterfiled = m2965d();
        if (m2963b() != 0 && m2963b() == 1) {
            filterResult.mDotos.add(new RunnableC1174bd(this));
        }
        m2961a(filterResult);
    }
}
