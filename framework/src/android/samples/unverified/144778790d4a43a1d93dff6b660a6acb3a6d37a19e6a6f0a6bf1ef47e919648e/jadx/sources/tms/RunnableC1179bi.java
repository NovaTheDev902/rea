package tms;

import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bi */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1179bi implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SmsEntity f6917a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ Object[] f6918b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ C1189bs.b f6919c;

    RunnableC1179bi(C1189bs.b bVar, SmsEntity smsEntity, Object[] objArr) {
        this.f6919c = bVar;
        this.f6917a = smsEntity;
        this.f6918b = objArr;
    }

    @Override // java.lang.Runnable
    public final void run() {
        this.f6919c.f6954n.unBlockSms(this.f6917a, this.f6918b);
    }
}
