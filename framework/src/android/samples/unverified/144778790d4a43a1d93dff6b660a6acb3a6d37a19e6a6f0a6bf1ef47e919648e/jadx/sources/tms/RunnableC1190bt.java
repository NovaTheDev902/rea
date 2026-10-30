package tms;

import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.ISmsDao;
import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bt */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1190bt implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ ISmsDao f6958a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ SmsEntity f6959b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ FilterResult f6960c;

    /* JADX INFO: renamed from: d */
    final /* synthetic */ C1189bs.b f6961d;

    RunnableC1190bt(C1189bs.b bVar, ISmsDao iSmsDao, SmsEntity smsEntity, FilterResult filterResult) {
        this.f6961d = bVar;
        this.f6958a = iSmsDao;
        this.f6959b = smsEntity;
        this.f6960c = filterResult;
    }

    @Override // java.lang.Runnable
    public final void run() {
        this.f6958a.insert(this.f6961d.f6953m == null ? this.f6959b : this.f6961d.f6953m.convert(this.f6959b), this.f6960c);
    }
}
