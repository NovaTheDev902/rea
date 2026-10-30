package com.tencent.tmsecure.module.adcheck;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.ArrayList;
import java.util.List;
import tms.C1154ak;

/* JADX INFO: loaded from: classes.dex */
public final class AdcheckManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1154ak f6058a;

    public final boolean checkIsAd(NotificationInfo notificationInfo) {
        if (isExpired()) {
            return false;
        }
        return this.f6058a.m2920a(notificationInfo);
    }

    public final boolean clear(NotificationInfo notificationInfo) {
        return this.f6058a.m2922b(notificationInfo);
    }

    public final boolean clear(List<NotificationInfo> list) {
        return this.f6058a.m2921a(list);
    }

    public final ArrayList<NotificationInfo> findAllNotificationInfo() {
        return isExpired() ? new ArrayList<>() : this.f6058a.m2919a();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6058a = new C1154ak();
        this.f6058a.onCreate(context);
        setImpl(this.f6058a);
    }
}
