package com.lenovo.lps.sus.control;

import android.widget.TextView;
import com.lenovo.lps.sus.p008c.C0092c;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.e */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0117e implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ SUSCustdefNotificationActivity f1474a;

    RunnableC0117e(SUSCustdefNotificationActivity sUSCustdefNotificationActivity) {
        this.f1474a = sUSCustdefNotificationActivity;
    }

    @Override // java.lang.Runnable
    public final void run() {
        TextView textView;
        if (SUSCustdefNotificationActivity.f1374e.intValue() > 0) {
            SUSCustdefNotificationActivity.f1374e = Integer.valueOf(SUSCustdefNotificationActivity.f1374e.intValue() - 1);
        }
        if (SUSCustdefNotificationActivity.f1374e.intValue() == 0) {
            if (this.f1474a.f1377g != null) {
                this.f1474a.f1377g.removeCallbacks(this.f1474a.f1380j);
            }
            SUSCustdefNotificationActivity.f1374e = 3;
            this.f1474a.finish();
            return;
        }
        String string = SUSCustdefNotificationActivity.f1374e.toString();
        if (string != null && string.length() > 0 && SUSCustdefNotificationActivity.f1373c != null && (textView = (TextView) this.f1474a.findViewById(C0092c.m323a(SUSCustdefNotificationActivity.f1373c, SUSCustdefNotificationActivity.f1372b, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_TIME"))) != null) {
            textView.setText(string);
        }
        if (this.f1474a.f1377g == null || this.f1474a.f1380j == null) {
            return;
        }
        this.f1474a.f1377g.removeCallbacks(this.f1474a.f1380j);
        this.f1474a.f1377g.postDelayed(this.f1474a.f1380j, 1500L);
    }
}
