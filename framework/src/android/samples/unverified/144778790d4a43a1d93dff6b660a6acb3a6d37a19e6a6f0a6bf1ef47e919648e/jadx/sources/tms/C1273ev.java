package tms;

import android.content.Intent;
import com.tencent.tmsecure.module.powersaving.PowerSavingConfig;
import com.tencent.tmsecure.module.powersaving.PowerSavingEventListener;
import java.lang.ref.WeakReference;
import java.util.Iterator;

/* JADX INFO: renamed from: tms.ev */
/* JADX INFO: loaded from: classes.dex */
final class C1273ev extends AbstractC1265en {

    /* JADX INFO: renamed from: e */
    final /* synthetic */ C1304gd f7288e;

    C1273ev(C1304gd c1304gd) {
        this.f7288e = c1304gd;
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: a */
    public final void mo3235a(Intent intent) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onBatteryLevelChanged(intent);
            }
        }
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: a */
    public final void mo3236a(boolean z) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onCloseWifi(z);
            }
        }
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: a */
    public final boolean mo3237a() {
        return this.f7288e.f7378b;
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: b */
    public final PowerSavingConfig mo3238b() {
        return this.f7288e.f7377a;
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: b */
    public final void mo3239b(Intent intent) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onStartBatteryCharging(intent);
            }
        }
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: b */
    public final void mo3240b(boolean z) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onOpenWifi(z);
            }
        }
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: c */
    public final void mo3241c(Intent intent) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onStopBatteryCharging(intent);
            }
        }
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: c */
    public final void mo3242c(boolean z) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onCloseMobileNetwork(z);
            }
        }
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: d */
    public final void mo3243d(Intent intent) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onFinishBatteryCharging(intent);
            }
        }
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: d */
    public final void mo3244d(boolean z) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onOpenMobileNetwork(z);
            }
        }
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: e */
    public final void mo3245e(boolean z) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onCloseBlueTooth(z);
            }
        }
    }

    @Override // tms.AbstractC1265en
    /* JADX INFO: renamed from: f */
    public final void mo3246f(boolean z) {
        Iterator it = this.f7288e.f7382f.iterator();
        while (it.hasNext()) {
            PowerSavingEventListener powerSavingEventListener = (PowerSavingEventListener) ((WeakReference) it.next()).get();
            if (powerSavingEventListener != null) {
                powerSavingEventListener.onOpenBlueTooth(z);
            }
        }
    }
}
