package com.tencent.tmsecure.module.antitheft;

import android.content.Context;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Handler;
import android.os.HandlerThread;
import tms.C1160aq;
import tms.C1161ar;
import tms.HandlerC1159ap;

/* JADX INFO: loaded from: classes.dex */
public final class LocationResolver {

    /* JADX INFO: renamed from: a */
    private LocationManager f6060a;

    /* JADX INFO: renamed from: d */
    private HandlerThread f6063d;

    /* JADX INFO: renamed from: e */
    private Handler f6064e;

    /* JADX INFO: renamed from: f */
    private LocCallback f6065f;

    /* JADX INFO: renamed from: b */
    private boolean f6061b = false;

    /* JADX INFO: renamed from: c */
    private boolean f6062c = false;

    /* JADX INFO: renamed from: g */
    private boolean f6066g = false;

    /* JADX INFO: renamed from: h */
    private byte[] f6067h = new byte[0];

    /* JADX INFO: renamed from: i */
    private final LocationListener f6068i = new C1160aq(this);

    /* JADX INFO: renamed from: j */
    private final LocationListener f6069j = new C1161ar(this);

    public interface LocCallback {
        void gotLocation(Location location);
    }

    LocationResolver() {
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m2586a() {
        this.f6060a.removeUpdates(this.f6068i);
        this.f6060a.removeUpdates(this.f6069j);
        Location lastKnownLocation = this.f6061b ? this.f6060a.getLastKnownLocation("gps") : null;
        Location lastKnownLocation2 = this.f6062c ? this.f6060a.getLastKnownLocation("network") : null;
        if (lastKnownLocation != null && lastKnownLocation2 != null) {
            if (lastKnownLocation.getTime() > lastKnownLocation2.getTime()) {
                this.f6065f.gotLocation(lastKnownLocation);
                return;
            } else {
                this.f6065f.gotLocation(lastKnownLocation2);
                return;
            }
        }
        if (lastKnownLocation != null) {
            this.f6065f.gotLocation(lastKnownLocation);
        } else if (lastKnownLocation2 != null) {
            this.f6065f.gotLocation(lastKnownLocation2);
        } else {
            this.f6065f.gotLocation(null);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public boolean m2588b() {
        boolean z = true;
        synchronized (this.f6067h) {
            if (!this.f6066g) {
                if (this.f6063d != null && this.f6063d.isAlive()) {
                    this.f6063d.interrupt();
                    this.f6063d = null;
                }
                this.f6066g = true;
                z = false;
            }
        }
        return z;
    }

    /* JADX INFO: renamed from: a */
    public final synchronized boolean m2595a(Context context, LocCallback locCallback, int i) {
        boolean z;
        this.f6065f = locCallback;
        this.f6066g = false;
        if (this.f6060a == null) {
            this.f6060a = (LocationManager) context.getSystemService("location");
        }
        try {
            this.f6061b = this.f6060a.isProviderEnabled("gps");
        } catch (Exception e) {
        }
        try {
            this.f6062c = this.f6060a.isProviderEnabled("network");
        } catch (Exception e2) {
        }
        if (this.f6061b || this.f6062c) {
            this.f6063d = new HandlerThread("location");
            this.f6063d.start();
            this.f6064e = new HandlerC1159ap(this, this.f6063d.getLooper());
            this.f6064e.sendEmptyMessageDelayed(0, i);
            if (this.f6061b) {
                this.f6060a.requestLocationUpdates("gps", 0L, 0.0f, this.f6068i);
            }
            if (this.f6062c) {
                this.f6060a.requestLocationUpdates("network", 0L, 0.0f, this.f6069j);
            }
            z = true;
        } else {
            z = false;
        }
        return z;
    }
}
