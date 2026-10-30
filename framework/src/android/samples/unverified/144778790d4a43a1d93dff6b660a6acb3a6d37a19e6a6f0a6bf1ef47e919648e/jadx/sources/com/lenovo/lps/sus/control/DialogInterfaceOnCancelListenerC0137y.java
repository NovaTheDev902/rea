package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.y */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnCancelListenerC0137y implements DialogInterface.OnCancelListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSNotificationActivity f1550a;

    DialogInterfaceOnCancelListenerC0137y(SUSNotificationActivity sUSNotificationActivity) {
        this.f1550a = sUSNotificationActivity;
    }

    @Override // android.content.DialogInterface.OnCancelListener
    public final void onCancel(DialogInterface dialogInterface) {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity popupPromptionDialog CancelListener");
        if (this.f1550a.f1390j != null && this.f1550a.f1391k != null) {
            this.f1550a.f1390j.removeCallbacks(this.f1550a.f1391k);
        }
        SUSNotificationActivity.f1385h = 3;
        dialogInterface.dismiss();
    }
}
