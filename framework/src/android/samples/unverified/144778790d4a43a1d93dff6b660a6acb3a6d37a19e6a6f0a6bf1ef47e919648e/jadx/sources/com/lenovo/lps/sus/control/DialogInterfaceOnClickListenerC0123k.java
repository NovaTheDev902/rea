package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0090a;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.k */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnClickListenerC0123k implements DialogInterface.OnClickListener {
    DialogInterfaceOnClickListenerC0123k() {
    }

    @Override // android.content.DialogInterface.OnClickListener
    public final void onClick(DialogInterface dialogInterface, int i) {
        C0111am.f1445o = false;
        C0111am.f1446p = true;
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog PositiveButton");
        C0090a.m317e();
        dialogInterface.dismiss();
    }
}
