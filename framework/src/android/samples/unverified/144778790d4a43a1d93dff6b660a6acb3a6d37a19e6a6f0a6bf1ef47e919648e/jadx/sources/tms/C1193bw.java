package tms;

import android.content.Intent;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import java.util.Arrays;

/* JADX INFO: renamed from: tms.bw */
/* JADX INFO: loaded from: classes.dex */
final class C1193bw {

    /* JADX INFO: renamed from: a */
    private InterfaceC1171ba f6966a;

    C1193bw() {
    }

    /* JADX INFO: renamed from: a */
    private static boolean m3031a(String str, String... strArr) {
        return strArr.length > 1 ? Arrays.asList(strArr).contains(str) : strArr[0].equals(str);
    }

    /* JADX INFO: renamed from: a */
    public final synchronized void m3032a(Intent intent) {
        String action = intent.getAction();
        String type = intent.getType();
        if (action != null) {
            if (m3031a(action, "android.provider.Telephony.SMS_RECEIVED", "android.provider.Telephony.SMS_RECEIVED2", "android.provider.Telephony.GSM_SMS_RECEIVED")) {
                this.f6966a = new C1199cb(intent);
            } else if (type == null) {
                this.f6966a = null;
            } else if (!m3031a(action, "android.provider.Telephony.WAP_PUSH_RECEIVED")) {
                this.f6966a = null;
            } else if (m3031a(type, PushReceiver.CONTENT_MIME_TYPE_PUSH_SI, PushReceiver.CONTENT_MIME_TYPE_PUSH_SL, "application/vnd.wap.coc")) {
                this.f6966a = new C1217ct(intent);
            } else if (m3031a(type, "application/vnd.wap.mms-message")) {
                this.f6966a = new C1192bv(intent);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public final synchronized boolean m3033a() {
        return this.f6966a != null;
    }

    /* JADX INFO: renamed from: b */
    public final synchronized SmsEntity m3034b() {
        SmsEntity smsEntityMo2974c = null;
        synchronized (this) {
            if (this.f6966a != null) {
                smsEntityMo2974c = this.f6966a.mo2974c();
                this.f6966a = null;
            }
        }
        return smsEntityMo2974c;
    }
}
