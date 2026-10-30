package tms;

import android.os.Bundle;
import android.os.RemoteException;
import com.lenovo.safecenter.safemode.SofeModeMain;
import com.tencent.tmsecure.common.DataEntity;
import com.tencent.tmsecure.common.ISDKClient;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import java.util.ArrayList;
import java.util.Iterator;

/* JADX INFO: renamed from: tms.bu */
/* JADX INFO: loaded from: classes.dex */
final class C1191bu extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SmsEntity f6962a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1189bs.c f6963b;

    C1191bu(C1189bs.c cVar, SmsEntity smsEntity) {
        this.f6963b = cVar;
        this.f6962a = smsEntity;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        ArrayList arrayListM3028a = this.f6963b.m3028a(this.f6962a);
        C1189bs.c cVar = this.f6963b;
        SmsEntity smsEntity = this.f6962a;
        DataEntity dataEntity = new DataEntity(1);
        Bundle bundle = dataEntity.bundle();
        bundle.putByteArray(SofeModeMain.TS_SMS, SmsEntity.m2607a(smsEntity));
        bundle.putString("event_sender", TMSApplication.getApplicaionContext().getPackageName());
        try {
            Iterator it = arrayListM3028a.iterator();
            while (it.hasNext()) {
                ((ISDKClient) it.next()).sendMessage(dataEntity);
            }
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
