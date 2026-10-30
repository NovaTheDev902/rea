package tms;

import android.content.Intent;
import com.google.android.mms.pdu.EncodedStringValue;
import com.google.android.mms.pdu.GenericPdu;
import com.google.android.mms.pdu.PduParser;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bv */
/* JADX INFO: loaded from: classes.dex */
final class C1192bv implements InterfaceC1171ba {

    /* JADX INFO: renamed from: a */
    private Intent f6964a;

    /* JADX INFO: renamed from: b */
    private GenericPdu f6965b;

    public C1192bv(Intent intent) {
        this.f6964a = intent;
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: a */
    public final String mo2971a() {
        return "NO TEXT";
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: a */
    public final void mo2972a(byte[] bArr) {
        this.f6965b = new PduParser(bArr).parse();
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: b */
    public final String mo2973b() {
        EncodedStringValue from;
        if (this.f6965b == null || (from = this.f6965b.getFrom()) == null) {
            return null;
        }
        return from.getString();
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: c */
    public final SmsEntity mo2974c() {
        mo2972a(this.f6964a.getByteArrayExtra(SettingUtil.DATA));
        if (this.f6965b == null) {
            return null;
        }
        SmsEntity smsEntity = new SmsEntity();
        smsEntity.date = System.currentTimeMillis();
        smsEntity.body = "NO TEXT";
        smsEntity.phonenum = mo2973b();
        smsEntity.protocolType = 1;
        smsEntity.raw = this.f6964a;
        smsEntity.read = 0;
        smsEntity.type = 1;
        return smsEntity;
    }
}
