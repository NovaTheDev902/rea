package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.r */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnCancelListenerC0130r implements DialogInterface.OnCancelListener {
    DialogInterfaceOnCancelListenerC0130r() {
    }

    @Override // android.content.DialogInterface.OnCancelListener
    public final void onCancel(DialogInterface dialogInterface) {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog CancelListener");
        C0111am.f1445o = true;
        C0111am.f1446p = true;
        dialogInterface.dismiss();
    }
}
