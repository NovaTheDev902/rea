package com.lenovo.safecenter.aidl.usbdebugmode;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.provider.Settings;
import android.util.Log;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

/* JADX INFO: loaded from: classes.dex */
public class RemoteUsbDebugModeService extends Service {

    /* JADX INFO: renamed from: a */
    private final IRemoteUsbDebugModeService.Stub f2957a = new IRemoteUsbDebugModeService.Stub() { // from class: com.lenovo.safecenter.aidl.usbdebugmode.RemoteUsbDebugModeService.1
        @Override // com.lenovo.safecenter.aidl.usbdebugmode.IRemoteUsbDebugModeService
        public final boolean setUsbDebugMode(boolean isEnable) throws RemoteException {
            return RemoteUsbDebugModeService.this.m1295a(isEnable);
        }
    };

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
    }

    @Override // android.app.Service
    public void onDestroy() {
        Log.i("wu0wu", "RemoteService onDestroy()");
        super.onDestroy();
    }

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        Log.i("wu0wu", "RemoteService onBind action=" + intent.getAction());
        return this.f2957a;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public boolean m1295a(final boolean isEnable) {
        ExecutorService exec = Executors.newFixedThreadPool(1);
        Callable<Boolean> call = new Callable<Boolean>() { // from class: com.lenovo.safecenter.aidl.usbdebugmode.RemoteUsbDebugModeService.2
            @Override // java.util.concurrent.Callable
            public final /* synthetic */ Boolean call() throws Exception {
                boolean zPutInt = false;
                zPutInt = false;
                if (RemoteUsbDebugModeService.this.checkCallingOrSelfPermission("android.permission.WRITE_SECURE_SETTINGS") == 0 && RemoteUsbDebugModeService.this.checkCallingOrSelfPermission("android.permission.WRITE_SETTINGS") == 0) {
                    zPutInt = Settings.Secure.putInt(RemoteUsbDebugModeService.this.getContentResolver(), "adb_enabled", isEnable ? 1 : 0);
                }
                return Boolean.valueOf(zPutInt);
            }
        };
        Future<Boolean> future = null;
        Boolean result = false;
        try {
            future = exec.submit(call);
            result = future.get(300L, TimeUnit.MILLISECONDS);
        } catch (TimeoutException ex) {
            future.cancel(true);
            ex.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
        exec.shutdown();
        return result.booleanValue();
    }
}
