package tms;

import android.telephony.PhoneNumberUtils;
import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.bf */
/* JADX INFO: loaded from: classes.dex */
final class C1176bf extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ String f6913a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1175be f6914b;

    C1176bf(C1175be c1175be, String str) {
        this.f6914b = c1175be;
        this.f6913a = str;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        CallLogEntity callLogEntity = new CallLogEntity();
        callLogEntity.phonenum = this.f6913a != null ? PhoneNumberUtils.stripSeparators(this.f6913a) : "";
        callLogEntity.type = 1;
        callLogEntity.date = System.currentTimeMillis();
        this.f6914b.f6911a.notifyDataReached(callLogEntity, new Object[0]);
    }
}
