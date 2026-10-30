package com.lenovo.lps.sus.control;

import android.content.DialogInterface;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.ac */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnClickListenerC0102ac implements DialogInterface.OnClickListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSNotificationActivity f1409a;

    DialogInterfaceOnClickListenerC0102ac(SUSNotificationActivity sUSNotificationActivity) {
        this.f1409a = sUSNotificationActivity;
    }

    @Override // android.content.DialogInterface.OnClickListener
    public final void onClick(DialogInterface dialogInterface, int i) {
        if (this.f1409a.f1390j != null && this.f1409a.f1391k != null) {
            this.f1409a.f1390j.removeCallbacks(this.f1409a.f1391k);
        }
        C0104ae.m447b();
        SUSNotificationActivity.f1385h = 3;
        dialogInterface.dismiss();
    }
}
