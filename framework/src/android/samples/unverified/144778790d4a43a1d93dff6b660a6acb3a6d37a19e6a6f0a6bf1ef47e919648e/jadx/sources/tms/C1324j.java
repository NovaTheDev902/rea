package tms;

import QQPIM.SoftListType;
import com.tencent.tmsecure.module.update.IUpdateObserver;
import com.tencent.tmsecure.module.update.UpdateInfo;

/* JADX INFO: renamed from: tms.j */
/* JADX INFO: loaded from: classes.dex */
final class C1324j implements IUpdateObserver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1162as f7451a;

    C1324j(C1162as c1162as) {
        this.f7451a = c1162as;
    }

    @Override // com.tencent.tmsecure.module.update.IUpdateObserver
    public final void onChanged(UpdateInfo updateInfo) {
        C1162as.m2936a(this.f7451a, SoftListType.WHITELIST_COMMON);
    }
}
