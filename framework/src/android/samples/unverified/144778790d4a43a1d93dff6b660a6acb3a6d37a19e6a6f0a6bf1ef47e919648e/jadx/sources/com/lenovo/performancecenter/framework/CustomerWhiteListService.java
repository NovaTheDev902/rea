package com.lenovo.performancecenter.framework;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class CustomerWhiteListService extends Service {

    /* JADX INFO: renamed from: a */
    private final ICustomerWhiteListService.Stub f1633a = new ICustomerWhiteListService.Stub() { // from class: com.lenovo.performancecenter.framework.CustomerWhiteListService.1
        @Override // com.lenovo.performancecenter.framework.ICustomerWhiteListService
        public final List<String> getCustomerWhiteList() throws RemoteException {
            return DataLayerManager.getUserWhiteList(CustomerWhiteListService.this);
        }
    };

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
    }

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return this.f1633a;
    }
}
