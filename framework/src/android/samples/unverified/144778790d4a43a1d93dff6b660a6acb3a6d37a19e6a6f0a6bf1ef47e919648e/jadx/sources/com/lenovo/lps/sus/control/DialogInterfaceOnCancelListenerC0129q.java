package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.q */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnCancelListenerC0129q implements DialogInterface.OnCancelListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSPromptActivity f1481a;

    DialogInterfaceOnCancelListenerC0129q(SUSPromptActivity sUSPromptActivity) {
        this.f1481a = sUSPromptActivity;
    }

    @Override // android.content.DialogInterface.OnCancelListener
    public final void onCancel(DialogInterface dialogInterface) {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog CancelListener");
        this.f1481a.f1403l = true;
        this.f1481a.f1404m = true;
        dialogInterface.dismiss();
    }
}
