package com.lenovo.lps.sus.control;

import android.view.View;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.j */
/* JADX INFO: loaded from: classes.dex */
final class ViewOnClickListenerC0122j implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSCustdefNotificationActivity f1479a;

    ViewOnClickListenerC0122j(SUSCustdefNotificationActivity sUSCustdefNotificationActivity) {
        this.f1479a = sUSCustdefNotificationActivity;
    }

    @Override // android.view.View.OnClickListener
    public final void onClick(View view) {
        if (view.equals(this.f1479a.f1379i)) {
            C0104ae.m447b();
            SUSCustdefNotificationActivity.f1374e = 3;
            this.f1479a.finish();
        }
    }
}
