package com.lenovo.lps.sus.control;

import android.content.DialogInterface;
import android.view.KeyEvent;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.s */
/* JADX INFO: loaded from: classes.dex */
final class DialogInterfaceOnKeyListenerC0131s implements DialogInterface.OnKeyListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSPromptActivity f1482a;

    DialogInterfaceOnKeyListenerC0131s(SUSPromptActivity sUSPromptActivity) {
        this.f1482a = sUSPromptActivity;
    }

    @Override // android.content.DialogInterface.OnKeyListener
    public final boolean onKey(DialogInterface dialogInterface, int i, KeyEvent keyEvent) {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog KeyListener keyCode=" + i + "; event=" + keyEvent);
        return i == 84 || i == 3 || i == 4;
    }
}
