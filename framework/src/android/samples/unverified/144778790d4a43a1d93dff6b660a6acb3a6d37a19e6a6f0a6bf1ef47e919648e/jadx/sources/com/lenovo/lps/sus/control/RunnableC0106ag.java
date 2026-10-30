package com.lenovo.lps.sus.control;

import android.widget.TextView;
import com.lenovo.lps.sus.p008c.C0092c;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.ag */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0106ag implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSNotificationActivity f1423a;

    RunnableC0106ag(SUSNotificationActivity sUSNotificationActivity) {
        this.f1423a = sUSNotificationActivity;
    }

    @Override // java.lang.Runnable
    public final void run() {
        TextView textView;
        if (SUSNotificationActivity.f1385h.intValue() > 0) {
            SUSNotificationActivity.f1385h = Integer.valueOf(SUSNotificationActivity.f1385h.intValue() - 1);
        }
        if (SUSNotificationActivity.f1385h.intValue() == 0) {
            if (this.f1423a.f1390j != null) {
                this.f1423a.f1390j.removeCallbacks(this.f1423a.f1391k);
            }
            if (SUSNotificationActivity.f1384d == null || this.f1423a.f1386e == null || SUSNotificationActivity.f1384d == null) {
                return;
            }
            SUSNotificationActivity.f1384d.dismiss();
            SUSNotificationActivity.f1385h = 3;
            return;
        }
        String string = SUSNotificationActivity.f1385h.toString();
        if (string != null && string.length() > 0 && SUSNotificationActivity.f1384d != null && this.f1423a.f1386e != null && (textView = (TextView) SUSNotificationActivity.f1384d.findViewById(C0092c.m323a(this.f1423a.f1386e, SUSNotificationActivity.f1383c, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_TIME"))) != null) {
            textView.setText(string);
        }
        if (this.f1423a.f1390j == null || this.f1423a.f1391k == null) {
            return;
        }
        this.f1423a.f1390j.removeCallbacks(this.f1423a.f1391k);
        this.f1423a.f1390j.postDelayed(this.f1423a.f1391k, 1500L);
    }
}
