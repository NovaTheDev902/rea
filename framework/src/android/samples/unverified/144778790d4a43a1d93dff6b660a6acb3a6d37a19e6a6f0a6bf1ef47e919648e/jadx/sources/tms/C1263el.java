package tms;

import com.tencent.tmsecure.module.permission.AbsDummyServiceCallback;
import com.tencent.tmsecure.module.permission.PermissionRequestInfo;

/* JADX INFO: renamed from: tms.el */
/* JADX INFO: loaded from: classes.dex */
public class C1263el extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ PermissionRequestInfo f7247a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ AbsDummyServiceCallback f7248b;

    public C1263el(AbsDummyServiceCallback absDummyServiceCallback, PermissionRequestInfo permissionRequestInfo) {
        this.f7248b = absDummyServiceCallback;
        this.f7247a = permissionRequestInfo;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public void run() {
        try {
            this.f7248b.onHandleAslynRequest(this.f7247a);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
