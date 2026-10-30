package com.lenovo.lps.sus.control;

import android.content.DialogInterface;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.aa */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnClickListenerC0100aa implements DialogInterface.OnClickListener {
    DialogInterfaceOnClickListenerC0100aa() {
    }

    @Override // android.content.DialogInterface.OnClickListener
    public final void onClick(DialogInterface dialogInterface, int i) {
        if (C0111am.f1448r != null && C0111am.f1430D != null) {
            C0111am.f1448r.removeCallbacks(C0111am.f1430D);
        }
        C0104ae.m447b();
        C0111am.f1447q = 3;
        dialogInterface.dismiss();
    }
}
