package com.lenovo.leos.cloud.sync.common.auto;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public class EasySyncServiceProxy {

    /* JADX INFO: renamed from: a */
    private static ILesyncService f1069a;

    /* JADX INFO: renamed from: b */
    private static ServiceConnection f1070b;

    /* JADX INFO: renamed from: c */
    private static boolean f1071c = false;

    public interface EasySyncCallback {
        void onFail(String str);

        void onFinish(BackupDiffInfo backupDiffInfo);
    }

    public static void unbind(Context context) {
        if (f1071c) {
            context.unbindService(f1070b);
            f1071c = false;
        }
    }

    public static void queryContactDiffInfo(Context context, EasySyncCallback callback) {
        f1070b = new ServiceConnectionC0067a(callback);
        f1071c = context.bindService(new Intent("com.lenovo.leos.cloud.sync.AUTO_SYNC"), f1070b, 1);
    }

    /* JADX INFO: renamed from: com.lenovo.leos.cloud.sync.common.auto.EasySyncServiceProxy$a */
    private static class ServiceConnectionC0067a implements ServiceConnection {

        /* JADX INFO: renamed from: a */
        private EasySyncCallback f1072a;

        public ServiceConnectionC0067a(EasySyncCallback callback) {
            this.f1072a = callback;
        }

        @Override // android.content.ServiceConnection
        public final void onServiceDisconnected(ComponentName name) {
            ILesyncService unused = EasySyncServiceProxy.f1069a = null;
        }

        @Override // android.content.ServiceConnection
        public final void onServiceConnected(ComponentName name, IBinder service) {
            ILesyncService unused = EasySyncServiceProxy.f1069a = ILesyncService.Stub.asInterface(service);
            try {
                this.f1072a.onFinish(EasySyncServiceProxy.f1069a.getContactDiff());
            } catch (RemoteException e) {
                e.printStackTrace();
                this.f1072a.onFail("invoke remote service failed.");
            }
        }
    }
}
