package com.lenovo.lps.sus.control;

import android.widget.TextView;
import com.lenovo.lps.sus.p008c.C0092c;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.l */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0124l implements Runnable {
    RunnableC0124l() {
    }

    @Override // java.lang.Runnable
    public final void run() {
        TextView textView;
        if (C0111am.f1447q.intValue() > 0) {
            C0111am.f1447q = Integer.valueOf(C0111am.f1447q.intValue() - 1);
        }
        if (C0111am.f1447q.intValue() == 0) {
            if (C0111am.f1448r != null) {
                C0111am.f1448r.removeCallbacks(C0111am.f1430D);
            }
            if (C0111am.f1444n == null || C0111am.f1455y == null || C0111am.f1444n == null) {
                return;
            }
            C0111am.f1444n.dismiss();
            C0111am.f1447q = 3;
            return;
        }
        String string = C0111am.f1447q.toString();
        if (string != null && string.length() > 0 && C0111am.f1444n != null && C0111am.f1455y != null && (textView = (TextView) C0111am.f1444n.findViewById(C0092c.m323a(C0111am.f1455y, C0111am.f1442l, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_TIME"))) != null) {
            textView.setText(string);
        }
        if (C0111am.f1448r == null || C0111am.f1430D == null) {
            return;
        }
        C0111am.f1448r.removeCallbacks(C0111am.f1430D);
        C0111am.f1448r.postDelayed(C0111am.f1430D, 1500L);
    }
}
