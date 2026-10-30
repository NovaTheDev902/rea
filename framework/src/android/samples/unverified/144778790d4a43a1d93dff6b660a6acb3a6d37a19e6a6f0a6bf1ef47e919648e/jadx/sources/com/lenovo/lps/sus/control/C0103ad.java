package com.lenovo.lps.sus.control;

import android.os.Message;
import android.widget.CompoundButton;
import com.lenovo.lps.sus.p007b.EnumC0086b;
import com.lenovo.lps.sus.p008c.C0090a;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.ad */
/* JADX INFO: loaded from: classes.dex */
final class C0103ad implements CompoundButton.OnCheckedChangeListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSPromptActivity f1410a;

    /* JADX INFO: renamed from: b */
    private final /* synthetic */ int f1411b;

    C0103ad(SUSPromptActivity sUSPromptActivity, int i) {
        this.f1410a = sUSPromptActivity;
        this.f1411b = i;
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
        if (SUSPromptActivity.f1400i != null) {
            Message message = new Message();
            message.what = EnumC0086b.m293a(EnumC0086b.SUS_USER_CHANGESETTINGS_EVENT);
            message.obj = Integer.valueOf(this.f1411b);
            message.arg1 = num.intValue();
            SUSPromptActivity.f1400i.sendMessage(message);
        }
    }
}
