package tms;

import android.database.ContentObserver;
import android.os.Handler;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.aresengine.AresEngineManager;
import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.cd */
/* JADX INFO: loaded from: classes.dex */
final class C1201cd extends ContentObserver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ Handler f6980a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1216cs.a f6981b;

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    C1201cd(C1216cs.a aVar, Handler handler, Handler handler2) {
        super(handler);
        this.f6981b = aVar;
        this.f6980a = handler2;
    }

    @Override // android.database.ContentObserver
    public final synchronized void onChange(boolean z) {
        super.onChange(z);
        CallLogEntity lastCallLog = ((AresEngineManager) ManagerCreator.getManager(AresEngineManager.class)).getAresEngineFactor().getSysDao().getLastCallLog();
        if (lastCallLog != null) {
            this.f6980a.postDelayed(new RunnableC1202ce(this, lastCallLog), 2000L);
        }
    }
}
