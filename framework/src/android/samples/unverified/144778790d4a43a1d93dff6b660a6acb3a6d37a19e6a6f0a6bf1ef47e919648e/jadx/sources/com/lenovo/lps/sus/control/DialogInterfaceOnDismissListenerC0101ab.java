package com.lenovo.lps.sus.control;

import android.app.Activity;
import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.ab */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnDismissListenerC0101ab implements DialogInterface.OnDismissListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSNotificationActivity f1408a;

    DialogInterfaceOnDismissListenerC0101ab(SUSNotificationActivity sUSNotificationActivity) {
        this.f1408a = sUSNotificationActivity;
    }

    @Override // android.content.DialogInterface.OnDismissListener
    public final void onDismiss(DialogInterface dialogInterface) {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity popupPromptionDialog onDismiss myCustomDialog=" + SUSNotificationActivity.f1384d + "; myContext=" + this.f1408a.f1386e);
        if (this.f1408a.f1390j != null && this.f1408a.f1391k != null) {
            this.f1408a.f1390j.removeCallbacks(this.f1408a.f1391k);
        }
        SUSNotificationActivity.f1385h = 3;
        if (this.f1408a.f1386e != null) {
            ((Activity) this.f1408a.f1386e).finish();
        }
    }
}
