package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.b */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnCancelListenerC0114b implements DialogInterface.OnCancelListener {
    DialogInterfaceOnCancelListenerC0114b() {
    }

    @Override // android.content.DialogInterface.OnCancelListener
    public final void onCancel(DialogInterface dialogInterface) {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity popupPromptionDialog CancelListener");
        if (C0111am.f1448r != null && C0111am.f1430D != null) {
            C0111am.f1448r.removeCallbacks(C0111am.f1430D);
        }
        C0111am.f1447q = 3;
        dialogInterface.dismiss();
    }
}
