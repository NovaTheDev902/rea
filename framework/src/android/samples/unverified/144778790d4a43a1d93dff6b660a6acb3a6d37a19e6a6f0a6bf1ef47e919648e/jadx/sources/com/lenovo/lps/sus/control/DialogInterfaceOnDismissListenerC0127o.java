package com.lenovo.lps.sus.control;

import android.app.Activity;
import android.content.DialogInterface;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.o */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnDismissListenerC0127o implements DialogInterface.OnDismissListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSPromptActivity f1480a;

    DialogInterfaceOnDismissListenerC0127o(SUSPromptActivity sUSPromptActivity) {
        this.f1480a = sUSPromptActivity;
    }

    @Override // android.content.DialogInterface.OnDismissListener
    public final void onDismiss(DialogInterface dialogInterface) {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog onDismiss myCustomDialog=" + SUSPromptActivity.f1401j + "; myContext=" + this.f1480a.f1402k);
        if (this.f1480a.f1402k != null) {
            ((Activity) this.f1480a.f1402k).finish();
        }
    }
}
