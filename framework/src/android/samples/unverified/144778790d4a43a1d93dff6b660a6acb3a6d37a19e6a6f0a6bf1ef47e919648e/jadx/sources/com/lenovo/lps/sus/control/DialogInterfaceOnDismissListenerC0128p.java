package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import com.lenovo.lps.sus.EventType;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.p */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnDismissListenerC0128p implements DialogInterface.OnDismissListener {
    DialogInterfaceOnDismissListenerC0128p() {
    }

    @Override // android.content.DialogInterface.OnDismissListener
    public final void onDismiss(DialogInterface dialogInterface) {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog onDismiss myUpdateInfoAlertDialog=" + C0111am.f1443m + "; myApplicationContext=" + C0111am.f1455y);
        if (C0111am.f1446p && !C0111am.f1445o) {
            C0104ae.m440a(EventType.SUS_UPDATEPROMPT_USER_CONFIRM);
        } else if (C0111am.f1445o) {
            C0111am.f1445o = false;
            C0104ae.m440a(EventType.SUS_UPDATEPROMPT_USER_CANCEL);
        }
        if (C0111am.f1443m != null) {
            C0111am.f1443m = null;
        }
    }
}
