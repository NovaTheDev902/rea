package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.telephony.PhoneNumberUtils;
import android.telephony.TelephonyManager;
import android.text.TextUtils;

/* JADX INFO: renamed from: tms.be */
/* JADX INFO: loaded from: classes.dex */
final class C1175be extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1184bn.b f6911a;

    /* JADX INFO: renamed from: b */
    private TelephonyManager f6912b;

    C1175be(C1184bn.b bVar) {
        this.f6911a = bVar;
        this.f6912b = (TelephonyManager) this.f6911a.f6932a.getSystemService("phone");
    }

    @Override // android.content.BroadcastReceiver
    public final void onReceive(Context context, Intent intent) {
        if (this.f6912b.getCallState() == 1) {
            String stringExtra = intent.getStringExtra("incoming_number");
            if (stringExtra == null) {
                stringExtra = getResultData();
            }
            String strStripSeparators = PhoneNumberUtils.stripSeparators(stringExtra);
            if (TextUtils.isEmpty(strStripSeparators)) {
                return;
            }
            new C1176bf(this, strStripSeparators).start();
        }
    }
}
