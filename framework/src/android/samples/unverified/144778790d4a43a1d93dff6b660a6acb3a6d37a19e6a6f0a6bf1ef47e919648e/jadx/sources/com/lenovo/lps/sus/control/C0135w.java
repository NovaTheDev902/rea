package com.lenovo.lps.sus.control;

import android.os.Message;
import android.widget.CompoundButton;
import com.lenovo.lps.sus.p007b.EnumC0086b;
import com.lenovo.lps.sus.p008c.C0090a;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.w */
/* JADX INFO: loaded from: classes.dex */
final class C0135w implements CompoundButton.OnCheckedChangeListener {

    /* JADX INFO: renamed from: a */
    private final /* synthetic */ int f1538a;

    C0135w(int i) {
        this.f1538a = i;
    }

    @Override // android.widget.CompoundButton.OnCheckedChangeListener
    public final void onCheckedChanged(CompoundButton compoundButton, boolean z) {
        Integer num;
        Integer.valueOf(0);
        if (z) {
            num = 1;
            C0090a.m316d();
        } else {
            num = 0;
        }
        if (C0111am.f1456z != null) {
            Message message = new Message();
            message.what = EnumC0086b.m293a(EnumC0086b.SUS_USER_CHANGESETTINGS_EVENT);
            message.obj = Integer.valueOf(this.f1538a);
            message.arg1 = num.intValue();
            C0111am.f1456z.sendMessage(message);
        }
    }
}
