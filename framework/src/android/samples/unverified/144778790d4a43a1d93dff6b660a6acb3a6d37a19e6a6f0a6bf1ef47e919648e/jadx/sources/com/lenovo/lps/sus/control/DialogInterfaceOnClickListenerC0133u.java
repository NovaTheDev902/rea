package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.u */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnClickListenerC0133u implements DialogInterface.OnClickListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSPromptActivity f1483a;

    DialogInterfaceOnClickListenerC0133u(SUSPromptActivity sUSPromptActivity) {
        this.f1483a = sUSPromptActivity;
    }

    @Override // android.content.DialogInterface.OnClickListener
    public final void onClick(DialogInterface dialogInterface, int i) {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog NegativeButton myMSGHandler=null");
        this.f1483a.f1403l = true;
        this.f1483a.f1404m = true;
        dialogInterface.dismiss();
    }
}
