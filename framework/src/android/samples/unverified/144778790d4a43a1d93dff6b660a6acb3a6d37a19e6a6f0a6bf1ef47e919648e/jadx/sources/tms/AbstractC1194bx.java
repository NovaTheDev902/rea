package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.text.TextUtils;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.utils.SDKUtil;

/* JADX INFO: renamed from: tms.bx */
/* JADX INFO: loaded from: classes.dex */
abstract class AbstractC1194bx extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    private C1193bw f6967a = new C1193bw();

    /* JADX INFO: renamed from: b */
    private boolean f6968b;

    AbstractC1194bx() {
    }

    /* JADX INFO: renamed from: a */
    public final void m3035a(Context context) {
        try {
            IntentFilter intentFilter = new IntentFilter("android.provider.Telephony.SMS_RECEIVED");
            intentFilter.addCategory("android.intent.category.DEFAULT");
            intentFilter.setPriority(Integer.MAX_VALUE);
            context.registerReceiver(this, intentFilter, "android.permission.BROADCAST_SMS", null);
            IntentFilter intentFilter2 = new IntentFilter("android.provider.Telephony.SMS_RECEIVED2");
            intentFilter2.addCategory("android.intent.category.DEFAULT");
            intentFilter2.setPriority(Integer.MAX_VALUE);
            context.registerReceiver(this, intentFilter2, "android.permission.BROADCAST_SMS", null);
            IntentFilter intentFilter3 = new IntentFilter("android.provider.Telephony.GSM_SMS_RECEIVED");
            intentFilter3.addCategory("android.intent.category.DEFAULT");
            intentFilter3.setPriority(Integer.MAX_VALUE);
            context.registerReceiver(this, intentFilter3, "android.permission.BROADCAST_SMS", null);
            IntentFilter intentFilter4 = new IntentFilter("android.provider.Telephony.WAP_PUSH_RECEIVED");
            intentFilter4.addDataType("application/vnd.wap.mms-message");
            intentFilter4.addCategory("android.intent.category.DEFAULT");
            intentFilter4.setPriority(Integer.MAX_VALUE);
            context.registerReceiver(this, intentFilter4, "android.permission.BROADCAST_SMS", null);
            IntentFilter intentFilter5 = new IntentFilter("android.provider.Telephony.WAP_PUSH_RECEIVED");
            intentFilter5.addDataType(PushReceiver.CONTENT_MIME_TYPE_PUSH_SI);
            intentFilter5.addDataType(PushReceiver.CONTENT_MIME_TYPE_PUSH_SL);
            intentFilter5.addDataType("application/vnd.wap.coc");
            intentFilter5.addCategory("android.intent.category.DEFAULT");
            intentFilter5.setPriority(Integer.MAX_VALUE);
            context.registerReceiver(this, intentFilter5, "android.permission.BROADCAST_SMS", null);
            this.f6968b = true;
        } catch (IntentFilter.MalformedMimeTypeException e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: a */
    abstract void mo2996a(SmsEntity smsEntity, BroadcastReceiver broadcastReceiver);

    /* JADX INFO: renamed from: a */
    public final boolean m3036a() {
        return this.f6968b;
    }

    /* JADX INFO: renamed from: b */
    public final void m3037b(Context context) {
        if (this.f6968b) {
            context.unregisterReceiver(this);
            this.f6968b = false;
        }
    }

    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        this.f6967a.m3032a(intent);
        SmsEntity smsEntityM3034b = this.f6967a.m3033a() ? this.f6967a.m3034b() : null;
        if (smsEntityM3034b == null || TextUtils.isEmpty(smsEntityM3034b.phonenum) || TextUtils.isEmpty(smsEntityM3034b.body) || SDKUtil.getSDKVersion() <= 4) {
            return;
        }
        mo2996a(smsEntityM3034b, this);
    }
}
