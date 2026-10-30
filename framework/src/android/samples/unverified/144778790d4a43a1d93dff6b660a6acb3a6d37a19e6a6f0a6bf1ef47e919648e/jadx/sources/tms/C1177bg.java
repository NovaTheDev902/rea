package tms;

import android.content.BroadcastReceiver;
import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bg */
/* JADX INFO: loaded from: classes.dex */
final class C1177bg extends AbstractC1194bx {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1189bs.a f6915a;

    C1177bg(C1189bs.a aVar) {
        this.f6915a = aVar;
    }

    @Override // tms.AbstractC1194bx
    /* JADX INFO: renamed from: a */
    final void mo2996a(SmsEntity smsEntity, BroadcastReceiver broadcastReceiver) {
        if (smsEntity == null || !this.f6915a.f6943c.m3030a(smsEntity, broadcastReceiver)) {
            return;
        }
        this.f6915a.notifyDataReached(smsEntity, 0, broadcastReceiver);
    }
}
