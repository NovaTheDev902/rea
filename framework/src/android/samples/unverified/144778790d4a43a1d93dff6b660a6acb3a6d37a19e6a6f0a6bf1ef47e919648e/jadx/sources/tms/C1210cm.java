package tms;

import com.tencent.tccdb.MMatchSysResult;
import com.tencent.tmsecure.module.aresengine.IIntelligentSmsChecker;
import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.cm */
/* JADX INFO: loaded from: classes.dex */
public final class C1210cm implements IIntelligentSmsChecker {

    /* JADX INFO: renamed from: a */
    IIntelligentSmsChecker.CheckResult f6994a = new IIntelligentSmsChecker.CheckResult();

    public C1210cm() {
        this.f6994a.mContentType = 1;
        this.f6994a.mSuggestion = 4;
        this.f6994a.mInnterResult = new MMatchSysResult(0, 0, 0, 0, 0, null);
    }

    @Override // com.tencent.tmsecure.module.aresengine.IIntelligentSmsChecker
    public final IIntelligentSmsChecker.CheckResult check(SmsEntity smsEntity) {
        return this.f6994a;
    }

    @Override // com.tencent.tmsecure.module.aresengine.IIntelligentSmsChecker
    public final boolean isChartSms(SmsEntity smsEntity) {
        return false;
    }
}
