package tms;

import android.location.Location;
import android.location.LocationListener;
import android.os.Bundle;
import com.tencent.tmsecure.module.antitheft.LocationResolver;

/* JADX INFO: renamed from: tms.aq */
/* JADX INFO: loaded from: classes.dex */
public class C1160aq implements LocationListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ LocationResolver f6849a;

    public C1160aq(LocationResolver locationResolver) {
        this.f6849a = locationResolver;
    }

    @Override // android.location.LocationListener
    public void onLocationChanged(Location location) {
        if (this.f6849a.m2588b()) {
            return;
        }
        this.f6849a.f6065f.gotLocation(location);
        this.f6849a.f6060a.removeUpdates(this);
        this.f6849a.f6060a.removeUpdates(this.f6849a.f6069j);
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
