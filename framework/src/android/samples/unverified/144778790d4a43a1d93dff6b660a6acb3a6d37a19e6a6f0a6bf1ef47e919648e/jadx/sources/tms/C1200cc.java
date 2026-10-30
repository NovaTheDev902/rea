package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.telephony.PhoneNumberUtils;
import android.telephony.TelephonyManager;
import java.util.concurrent.ConcurrentLinkedQueue;

/* JADX INFO: renamed from: tms.cc */
/* JADX INFO: loaded from: classes.dex */
final class C1200cc extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1216cs.a f6979a;

    C1200cc(C1216cs.a aVar) {
        this.f6979a = aVar;
    }

    @Override // android.content.BroadcastReceiver
    public final void onReceive(Context context, Intent intent) {
        TelephonyManager telephonyManager = (TelephonyManager) this.f6979a.f7009a.getSystemService("phone");
        if (intent.getAction().equals("android.intent.action.NEW_OUTGOING_CALL")) {
            String stringExtra = intent.getStringExtra("android.intent.extra.PHONE_NUMBER");
            if (stringExtra == null) {
                stringExtra = getResultData();
            }
            ConcurrentLinkedQueue concurrentLinkedQueue = this.f6979a.f7013e;
            if (stringExtra == null) {
                stringExtra = "null";
            }
            concurrentLinkedQueue.add(stringExtra);
            return;
        }
        if (telephonyManager.getCallState() == 1) {
            String stringExtra2 = intent.getStringExtra("incoming_number");
            if (stringExtra2 == null) {
                stringExtra2 = getResultData();
            }
            String strStripSeparators = PhoneNumberUtils.stripSeparators(stringExtra2);
            ConcurrentLinkedQueue concurrentLinkedQueue2 = this.f6979a.f7012d;
            if (strStripSeparators == null) {
                strStripSeparators = "null";
            }
            concurrentLinkedQueue2.add(strStripSeparators);
        }
    }
}
