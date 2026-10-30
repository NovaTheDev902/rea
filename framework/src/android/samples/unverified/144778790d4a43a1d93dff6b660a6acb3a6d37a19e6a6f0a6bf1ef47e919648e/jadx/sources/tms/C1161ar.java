package tms;

import android.location.Location;
import android.location.LocationListener;
import android.os.Bundle;
import com.tencent.tmsecure.module.antitheft.LocationResolver;

/* JADX INFO: renamed from: tms.ar */
/* JADX INFO: loaded from: classes.dex */
public class C1161ar implements LocationListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ LocationResolver f6850a;

    public C1161ar(LocationResolver locationResolver) {
        this.f6850a = locationResolver;
    }

    @Override // android.location.LocationListener
    public void onLocationChanged(Location location) {
        if (this.f6850a.m2588b()) {
            return;
        }
        this.f6850a.f6065f.gotLocation(location);
        this.f6850a.f6060a.removeUpdates(this);
        this.f6850a.f6060a.removeUpdates(this.f6850a.f6068i);
    }

    @Override // android.location.LocationListener
    public void onProviderDisabled(String str) {
    }

    @Override // android.location.LocationListener
    public void onProviderEnabled(String str) {
    }

    @Override // android.location.LocationListener
    public void onStatusChanged(String str, int i, Bundle bundle) {
    }
}
