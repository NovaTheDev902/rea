package com.lenovo.lps.sus.control;

import android.content.DialogInterface;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.aj */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnClickListenerC0109aj implements DialogInterface.OnClickListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSNotificationActivity f1427a;

    DialogInterfaceOnClickListenerC0109aj(SUSNotificationActivity sUSNotificationActivity) {
        this.f1427a = sUSNotificationActivity;
    }

    @Override // android.content.DialogInterface.OnClickListener
    public final void onClick(DialogInterface dialogInterface, int i) {
        if (this.f1427a.f1390j != null && this.f1427a.f1391k != null) {
            this.f1427a.f1390j.removeCallbacks(this.f1427a.f1391k);
        }
        SUSNotificationActivity.f1385h = 3;
        dialogInterface.dismiss();
    }
}
