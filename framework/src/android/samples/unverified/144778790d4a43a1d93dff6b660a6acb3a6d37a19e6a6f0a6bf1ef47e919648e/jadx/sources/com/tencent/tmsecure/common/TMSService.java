package com.tencent.tmsecure.common;

import android.app.Notification;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.tencent.tmsecure.utils.SDKUtil;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import tms.C1330p;
import tms.C1331q;
import tms.RunnableC1325k;

/* JADX INFO: loaded from: classes.dex */
public abstract class TMSService extends Service {

    /* JADX INFO: renamed from: a */
    private static final HashMap<Class<?>, BaseService> f6044a = new HashMap<>();

    /* JADX INFO: renamed from: b */
    private static final HashMap<Class<?>, ArrayList<BaseServiceConnection>> f6045b = new HashMap<>();

    /* JADX INFO: renamed from: com.tencent.tmsecure.common.TMSService$a */
    interface InterfaceC1074a {
        /* JADX INFO: renamed from: a */
        void mo2585a();
    }

    /* JADX INFO: renamed from: com.tencent.tmsecure.common.TMSService$b */
    static final class C1075b implements InterfaceC1074a {

        /* JADX INFO: renamed from: a */
        private Service f6046a;

        public C1075b(Service service) {
            this.f6046a = service;
        }

        @Override // com.tencent.tmsecure.common.TMSService.InterfaceC1074a
        /* JADX INFO: renamed from: a */
        public final void mo2585a() {
            this.f6046a.setForeground(true);
        }
    }

    /* JADX INFO: renamed from: com.tencent.tmsecure.common.TMSService$c */
    static final class C1076c implements InterfaceC1074a {

        /* JADX INFO: renamed from: a */
        private Service f6047a;

        public C1076c(Service service) {
            this.f6047a = service;
        }

        @Override // com.tencent.tmsecure.common.TMSService.InterfaceC1074a
        /* JADX INFO: renamed from: a */
        public final void mo2585a() {
            try {
                Notification notification = new Notification();
                notification.setLatestEventInfo(this.f6047a, null, null, PendingIntent.getActivity(this.f6047a, 0, new Intent(), 0));
                this.f6047a.startForeground(Integer.MAX_VALUE, notification);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static IBinder bindService(Class<? extends BaseService> cls, BaseServiceConnection baseServiceConnection) {
        IBinder iBinder;
        synchronized (BaseService.class) {
            BaseService baseService = f6044a.get(cls);
            if (baseService != null) {
                IBinder binder = baseService.getBinder();
                ArrayList<BaseServiceConnection> arrayList = f6045b.get(cls);
                if (arrayList == null) {
                    arrayList = new ArrayList<>(1);
                    f6045b.put(cls, arrayList);
                }
                arrayList.add(baseServiceConnection);
                iBinder = binder;
            } else {
                iBinder = null;
            }
        }
        return iBinder;
    }

    public static BaseService startService(BaseService baseService) {
        return startService(baseService, null);
    }

    public static BaseService startService(BaseService baseService, Intent intent) {
        synchronized (BaseService.class) {
            if (f6044a.containsKey(baseService.getClass())) {
                f6044a.get(baseService.getClass()).onStart(intent);
            } else {
                baseService.onCreate(TMSApplication.getApplicaionContext());
                baseService.onStart(intent);
                f6044a.put(baseService.getClass(), baseService);
            }
        }
        return baseService;
    }

    public static void stopBackgroundService() {
        Context applicaionContext = TMSApplication.getApplicaionContext();
        applicaionContext.stopService(new Intent(applicaionContext, TMSApplication.getSecureServiceClass()));
        C1331q.m3538a();
    }

    public static synchronized boolean stopService(BaseService baseService) {
        return stopService((Class<? extends BaseService>) baseService.getClass());
    }

    public static boolean stopService(Class<? extends BaseService> cls) {
        synchronized (BaseService.class) {
            if (!f6044a.containsKey(cls)) {
                return true;
            }
            ArrayList<BaseServiceConnection> arrayList = f6045b.get(cls);
            if (arrayList != null && arrayList.size() != 0) {
                return false;
            }
            f6044a.get(cls).onDestory();
            f6044a.remove(cls);
            f6045b.remove(cls);
            return true;
        }
    }

    public static void unBindService(Class<? extends BaseService> cls, BaseServiceConnection baseServiceConnection) {
        synchronized (BaseService.class) {
            ArrayList<BaseServiceConnection> arrayList = f6045b.get(cls);
            if (arrayList != null) {
                arrayList.remove(baseServiceConnection);
            }
        }
    }

    @Override // android.app.Service
    public final IBinder onBind(Intent intent) {
        return SDKClient.getInstance();
    }

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
        (SDKUtil.getSDKVersion() >= 5 ? new C1076c(this) : new C1075b(this)).mo2585a();
        f6044a.clear();
        f6045b.clear();
        C1330p.m3532a(TMSApplication.getApplicaionContext()).m3535a();
    }

    @Override // android.app.Service
    public void onDestroy() {
        synchronized (BaseService.class) {
            Iterator<BaseService> it = f6044a.values().iterator();
            while (it.hasNext()) {
                it.next().onDestory();
            }
            f6044a.clear();
        }
        f6045b.clear();
        super.onDestroy();
    }

    @Override // android.app.Service
    public void onStart(Intent intent, int i) {
        super.onStart(intent, i);
        String action = intent == null ? null : intent.getAction();
        if (action != null) {
            if (!action.equals("com.tencent.tmsecure.action.SKIP_SMS_RECEIVED_EVENT")) {
                if (action.equals(C1331q.f7473d)) {
                    new Thread(new RunnableC1325k(this)).start();
                    return;
                }
                return;
            }
            DataEntity dataEntity = new DataEntity(3);
            String stringExtra = intent.getStringExtra("command");
            String stringExtra2 = intent.getStringExtra(SettingUtil.DATA);
            if (stringExtra == null || stringExtra2 == null) {
                return;
            }
            try {
                Bundle bundle = dataEntity.bundle();
                bundle.putString("command", stringExtra);
                bundle.putString(SettingUtil.DATA, stringExtra2);
                SDKClient.getInstance().sendMessage(dataEntity);
            } catch (RemoteException e) {
                e.printStackTrace();
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
    }
}
