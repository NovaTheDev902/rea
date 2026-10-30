package tms;

import com.tencent.tmsecure.module.update.IUpdateObserver;
import com.tencent.tmsecure.module.update.UpdateInfo;

/* JADX INFO: renamed from: tms.dc */
/* JADX INFO: loaded from: classes.dex */
final class C1227dc implements IUpdateObserver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1244dt f7077a;

    C1227dc(C1244dt c1244dt) {
        this.f7077a = c1244dt;
    }

    @Override // com.tencent.tmsecure.module.update.IUpdateObserver
    public final void onChanged(UpdateInfo updateInfo) throws Throwable {
        this.f7077a.m3181i();
    }
}
