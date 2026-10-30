package tms;

import android.content.ComponentName;
import android.content.pm.ServiceInfo;
import android.os.IBinder;
import com.tencent.tmsecure.common.ISDKClient;

/* JADX INFO: renamed from: tms.ab */
/* JADX INFO: loaded from: classes.dex */
final class C1145ab extends C1337w.a {

    /* JADX INFO: renamed from: c */
    final /* synthetic */ Object f6816c;

    /* JADX INFO: renamed from: d */
    final /* synthetic */ C1337w f6817d;

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    C1145ab(C1337w c1337w, ServiceInfo serviceInfo, Object obj) {
        super(serviceInfo);
        this.f6817d = c1337w;
        this.f6816c = obj;
    }

    @Override // android.content.ServiceConnection
    public final void onServiceConnected(ComponentName componentName, IBinder iBinder) {
        this.f7487b = ISDKClient.Proxy.asInterface(iBinder);
        this.f6817d.f7481c.put(this.f7486a.packageName, this.f7487b);
        synchronized (this.f6816c) {
            this.f6816c.notify();
        }
    }

    @Override // android.content.ServiceConnection
    public final void onServiceDisconnected(ComponentName componentName) {
        this.f6817d.f7481c.remove(this.f7486a.packageName);
        this.f7487b = null;
    }
}
