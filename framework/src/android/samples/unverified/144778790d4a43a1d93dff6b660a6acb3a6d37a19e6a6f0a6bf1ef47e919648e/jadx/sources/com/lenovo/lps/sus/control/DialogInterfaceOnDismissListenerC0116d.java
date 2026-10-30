package com.lenovo.lps.sus.control;

import android.content.Context;
import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.d */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnDismissListenerC0116d implements DialogInterface.OnDismissListener {

    /* JADX INFO: renamed from: a */
    private final /* synthetic */ Context f1473a;

    DialogInterfaceOnDismissListenerC0116d(Context context) {
        this.f1473a = context;
    }

    @Override // android.content.DialogInterface.OnDismissListener
    public final void onDismiss(DialogInterface dialogInterface) {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity popupPromptionDialog onDismiss myPromptionInfoAlertDialog=" + C0111am.f1444n + "; context=" + this.f1473a);
        if (C0111am.f1448r != null && C0111am.f1430D != null) {
            C0111am.f1448r.removeCallbacks(C0111am.f1430D);
        }
        C0111am.f1447q = 3;
        C0092c.m354d(false);
    }
}
