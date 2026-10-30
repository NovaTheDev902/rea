package com.lenovo.lps.sus.control;

import android.view.View;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.ak */
/* JADX INFO: loaded from: classes.dex */
final class ViewOnClickListenerC0110ak implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSCustdefNotificationActivity f1428a;

    ViewOnClickListenerC0110ak(SUSCustdefNotificationActivity sUSCustdefNotificationActivity) {
        this.f1428a = sUSCustdefNotificationActivity;
    }

    @Override // android.view.View.OnClickListener
    public final void onClick(View view) {
        if (view.equals(this.f1428a.f1378h)) {
            SUSCustdefNotificationActivity.f1374e = 3;
            this.f1428a.finish();
        }
    }
}
