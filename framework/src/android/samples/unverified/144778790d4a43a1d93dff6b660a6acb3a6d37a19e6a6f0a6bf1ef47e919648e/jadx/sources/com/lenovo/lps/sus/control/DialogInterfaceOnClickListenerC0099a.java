package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0090a;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.a */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnClickListenerC0099a implements DialogInterface.OnClickListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSPromptActivity f1407a;

    DialogInterfaceOnClickListenerC0099a(SUSPromptActivity sUSPromptActivity) {
        this.f1407a = sUSPromptActivity;
    }

    @Override // android.content.DialogInterface.OnClickListener
    public final void onClick(DialogInterface dialogInterface, int i) {
        this.f1407a.f1403l = false;
        this.f1407a.f1404m = true;
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog PositiveButton");
        C0090a.m317e();
        dialogInterface.dismiss();
    }
}
