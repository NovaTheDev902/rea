package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.n */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnClickListenerC0126n implements DialogInterface.OnClickListener {
    DialogInterfaceOnClickListenerC0126n() {
    }

    @Override // android.content.DialogInterface.OnClickListener
    public final void onClick(DialogInterface dialogInterface, int i) {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog NegativeButton myMSGHandler=null");
        C0111am.f1445o = true;
        C0111am.f1446p = true;
        dialogInterface.dismiss();
    }
}
