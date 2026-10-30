package com.tencent.lbsapi.core;

import android.location.Location;
import android.location.LocationListener;
import android.os.Bundle;

/* JADX INFO: renamed from: com.tencent.lbsapi.core.f */
/* JADX INFO: loaded from: classes.dex */
final class C1068f implements LocationListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ QLBSEngine f5969a;

    C1068f(QLBSEngine qLBSEngine) {
        this.f5969a = qLBSEngine;
    }

    @Override // android.location.LocationListener
    public final void onLocationChanged(Location location) throws Throwable {
        if (location != null) {
            QLBSEngine.m2501a(this.f5969a, location);
        }
    }

    @Override // android.location.LocationListener
    public final void onProviderDisabled(String str) {
    }

    @Override // android.location.LocationListener
    public final void onProviderEnabled(String str) {
    }

    @Override // android.location.LocationListener
    public final void onStatusChanged(String str, int i, Bundle bundle) {
    }
}
