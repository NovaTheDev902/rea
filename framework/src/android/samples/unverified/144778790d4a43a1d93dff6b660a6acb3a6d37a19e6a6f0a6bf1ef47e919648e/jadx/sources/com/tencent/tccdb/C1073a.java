package com.tencent.tccdb;

import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.update.IUpdateObserver;
import com.tencent.tmsecure.module.update.UpdateInfo;
import com.tencent.tmsecure.module.update.UpdateManager;
import java.io.File;

/* JADX INFO: renamed from: com.tencent.tccdb.a */
/* JADX INFO: loaded from: classes.dex */
final class C1073a implements IUpdateObserver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SmsChecker f6025a;

    C1073a(SmsChecker smsChecker) {
        this.f6025a = smsChecker;
    }

    @Override // com.tencent.tmsecure.module.update.IUpdateObserver
    public final void onChanged(UpdateInfo updateInfo) {
        String str = ((UpdateManager) ManagerCreator.getManager(UpdateManager.class)).getFileSavePath() + File.separator + updateInfo.fileName;
        if (SmsChecker.initSmsChecker(this.f6025a.f6014b, 3, str) == 0 && SmsChecker.initChargeChecker(this.f6025a.f6014b, 8, str) == 0) {
            this.f6025a.f6016d = true;
        } else {
            this.f6025a.f6016d = false;
        }
    }
}
