package com.tencent.tmsecure.utils;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.telephony.gsm.SmsManager;
import java.util.Iterator;

/* JADX INFO: loaded from: classes.dex */
public abstract class SMSUtil {

    /* JADX INFO: renamed from: com.tencent.tmsecure.utils.SMSUtil$a */
    interface InterfaceC1081a {
        /* JADX INFO: renamed from: a */
        void mo2638a(String str, String str2);
    }

    /* JADX INFO: renamed from: com.tencent.tmsecure.utils.SMSUtil$b */
    static final class C1082b implements InterfaceC1081a {

        /* JADX INFO: renamed from: a */
        private SmsManager f6280a = SmsManager.getDefault();

        @Override // com.tencent.tmsecure.utils.SMSUtil.InterfaceC1081a
        /* JADX INFO: renamed from: a */
        public final void mo2638a(String str, String str2) {
            if (str2.length() <= 70) {
                this.f6280a.sendTextMessage(str, null, str2, null, null);
                return;
            }
            Iterator<String> it = this.f6280a.divideMessage(str2).iterator();
            while (it.hasNext()) {
                this.f6280a.sendTextMessage(str, null, it.next(), null, null);
            }
        }
    }

    /* JADX INFO: renamed from: com.tencent.tmsecure.utils.SMSUtil$c */
    static final class C1083c implements InterfaceC1081a {

        /* JADX INFO: renamed from: a */
        private android.telephony.SmsManager f6281a = android.telephony.SmsManager.getDefault();

        @Override // com.tencent.tmsecure.utils.SMSUtil.InterfaceC1081a
        /* JADX INFO: renamed from: a */
        public final void mo2638a(String str, String str2) {
            if (str2.length() <= 70) {
                this.f6281a.sendTextMessage(str, null, str2, null, null);
                return;
            }
            Iterator<String> it = this.f6281a.divideMessage(str2).iterator();
            while (it.hasNext()) {
                this.f6281a.sendTextMessage(str, null, it.next(), null, null);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m2637a(Context context, String str, String str2) {
        Intent intent = new Intent("android.intent.action.VIEW", Uri.parse("smsto:" + str));
        intent.putExtra("address", str);
        intent.putExtra("sms_body", str2);
        intent.setType("vnd.android-dir/mms-sms");
        context.startActivity(intent);
    }

    public static void sendSMS(String str, String str2, Context context) {
        Log.m2636i(str, str2);
        if (str == null || str2 == null) {
            return;
        }
        try {
            (SDKUtil.getSDKVersion() > 3 ? new C1083c() : new C1082b()).mo2638a(str, str2);
        } catch (Exception e) {
            try {
                m2637a(context, str, str2);
            } catch (Exception e2) {
            }
        }
    }
}
