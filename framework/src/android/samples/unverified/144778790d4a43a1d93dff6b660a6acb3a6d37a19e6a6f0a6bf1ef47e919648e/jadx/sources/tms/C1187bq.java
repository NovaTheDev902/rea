package tms;

import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.IIntelligentSmsChecker;
import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bq */
/* JADX INFO: loaded from: classes.dex */
final class C1187bq extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1189bs.b f6938a;

    C1187bq(C1189bs.b bVar) {
        this.f6938a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    public final boolean mo2967f() {
        IIntelligentSmsChecker.CheckResult checkResultCheck = this.f6938a.f6955o.check((SmsEntity) m2960a());
        boolean z = m2963b() == 2 && checkResultCheck.mSuggestion != 4;
        if (z) {
            m2962a(checkResultCheck);
        }
        return z;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    public final void mo2968g() {
        boolean zHandleCheckResult;
        FilterResult filterResult = new FilterResult();
        SmsEntity smsEntity = (SmsEntity) m2960a();
        IIntelligentSmsChecker.CheckResult checkResult = (IIntelligentSmsChecker.CheckResult) m2966e();
        filterResult.mData = m2960a();
        filterResult.mFilterfiled = m2965d();
        filterResult.mState = m2963b();
        if (IIntelligentSmsChecker.CheckResult.shouldBeBlockedOrNot(checkResult)) {
            zHandleCheckResult = true;
        } else {
            zHandleCheckResult = checkResult.mSuggestion == 1 ? false : false;
        }
        if (this.f6938a.f6952l != null) {
            zHandleCheckResult = this.f6938a.f6952l.handleCheckResult(smsEntity, checkResult, zHandleCheckResult);
        }
        if (zHandleCheckResult) {
            this.f6938a.f6954n.blockSms(m2964c());
            filterResult.mDotos.add(this.f6938a.m3014a((SmsEntity) m2960a(), this.f6938a.f6948h, filterResult));
        } else {
            this.f6938a.f6954n.unBlockSms(smsEntity, m2964c());
        }
        filterResult.mParams = new Object[]{checkResult, Boolean.valueOf(zHandleCheckResult)};
        m2961a(filterResult);
    }
}
