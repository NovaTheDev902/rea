package com.tencent.tmsecure.module.permission;

import android.os.RemoteException;
import tms.C1263el;

/* JADX INFO: loaded from: classes.dex */
public abstract class AbsDummyServiceCallback extends IDummyServiceCallback.Stub {
    public abstract void onHandleAslynRequest(PermissionRequestInfo permissionRequestInfo) throws Exception;

    protected abstract int onHandleSyncRequest(PermissionRequestInfo permissionRequestInfo) throws Exception;

    @Override // com.tencent.tmsecure.module.permission.IDummyServiceCallback
    public final int onRequest(PermissionRequestInfo permissionRequestInfo) throws RemoteException {
        if (permissionRequestInfo.mValue == 1 || permissionRequestInfo.mValue == 0) {
            new C1263el(this, permissionRequestInfo).start();
            return 0;
        }
        if (permissionRequestInfo.mValue != 2) {
            return 0;
        }
        try {
            return onHandleSyncRequest(permissionRequestInfo);
        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
    }
}
