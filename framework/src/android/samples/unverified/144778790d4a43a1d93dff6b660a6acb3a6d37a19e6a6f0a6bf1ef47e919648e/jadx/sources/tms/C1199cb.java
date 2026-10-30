package tms;

import android.content.Intent;
import android.os.Bundle;
import android.telephony.gsm.SmsMessage;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.utils.SDKUtil;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

/* JADX INFO: renamed from: tms.cb */
/* JADX INFO: loaded from: classes.dex */
final class C1199cb implements InterfaceC1171ba {

    /* JADX INFO: renamed from: a */
    private InterfaceC1171ba f6973a;

    /* JADX INFO: renamed from: b */
    private Intent f6974b;

    /* JADX INFO: renamed from: tms.cb$a */
    static final class a implements InterfaceC1171ba {

        /* JADX INFO: renamed from: a */
        private SmsMessage f6975a;

        a() {
        }

        @Override // tms.InterfaceC1171ba
        /* JADX INFO: renamed from: a */
        public final String mo2971a() {
            if (this.f6975a != null) {
                return this.f6975a.getMessageBody();
            }
            return null;
        }

        @Override // tms.InterfaceC1171ba
        /* JADX INFO: renamed from: a */
        public final void mo2972a(byte[] bArr) {
            try {
                this.f6975a = SmsMessage.createFromPdu(bArr);
            } catch (Throwable th) {
                this.f6975a = null;
            }
        }

        @Override // tms.InterfaceC1171ba
        /* JADX INFO: renamed from: b */
        public final String mo2973b() {
            if (this.f6975a != null) {
                return this.f6975a.getOriginatingAddress();
            }
            return null;
        }

        @Override // tms.InterfaceC1171ba
        /* JADX INFO: renamed from: c */
        public final SmsEntity mo2974c() {
            return null;
        }
    }

    /* JADX INFO: renamed from: tms.cb$b */
    static final class b implements InterfaceC1171ba {

        /* JADX INFO: renamed from: b */
        private static Method f6976b;

        /* JADX INFO: renamed from: c */
        private static Constructor<android.telephony.SmsMessage> f6977c;

        /* JADX INFO: renamed from: a */
        private android.telephony.SmsMessage f6978a;

        b() {
        }

        @Override // tms.InterfaceC1171ba
        /* JADX INFO: renamed from: a */
        public final String mo2971a() {
            if (this.f6978a != null) {
                return this.f6978a.getMessageBody();
            }
            return null;
        }

        @Override // tms.InterfaceC1171ba
        /* JADX INFO: renamed from: a */
        public final void mo2972a(byte[] bArr) {
            try {
                this.f6978a = android.telephony.SmsMessage.createFromPdu(bArr);
                this.f6978a.getMessageBody();
            } catch (Throwable th) {
                try {
                    if (f6976b == null || f6977c == null) {
                        f6976b = Class.forName("com.android.internal.telephony.gsm.SmsMessage").getMethod("createFromPdu", byte[].class);
                        f6976b.setAccessible(true);
                        f6977c = android.telephony.SmsMessage.class.getDeclaredConstructor(Class.forName("com.android.internal.telephony.SmsMessageBase"));
                        f6977c.setAccessible(true);
                    }
                    this.f6978a = f6977c.newInstance(f6976b.invoke(null, bArr));
                    this.f6978a.getMessageBody();
                } catch (Exception e) {
                    this.f6978a = null;
                }
            }
        }

        @Override // tms.InterfaceC1171ba
        /* JADX INFO: renamed from: b */
        public final String mo2973b() {
            if (this.f6978a != null) {
                return this.f6978a.getOriginatingAddress();
            }
            return null;
        }

        @Override // tms.InterfaceC1171ba
        /* JADX INFO: renamed from: c */
        public final SmsEntity mo2974c() {
            return null;
        }
    }

    public C1199cb(Intent intent) {
        this.f6974b = intent;
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: a */
    public final String mo2971a() {
        return this.f6973a.mo2971a();
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: a */
    public final void mo2972a(byte[] bArr) {
        if (this.f6973a == null) {
            if (SDKUtil.getSDKVersion() > 3) {
                this.f6973a = new b();
            } else {
                this.f6973a = new a();
            }
        }
        this.f6973a.mo2972a(bArr);
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: b */
    public final String mo2973b() {
        return this.f6973a.mo2973b();
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: c */
    public final SmsEntity mo2974c() {
        String strMo2973b;
        Bundle extras = this.f6974b.getExtras();
        Object[] objArr = extras != null ? (Object[]) extras.get("pdus") : null;
        if (objArr == null || objArr.length == 0) {
            return null;
        }
        StringBuffer stringBuffer = new StringBuffer();
        int i = 0;
        String str = null;
        while (i < objArr.length) {
            if (objArr[i] == null) {
                strMo2973b = str;
            } else {
                mo2972a((byte[]) objArr[i]);
                if (mo2971a() == null) {
                    break;
                }
                stringBuffer.append(mo2971a());
                strMo2973b = str == null ? mo2973b() : str;
            }
            i++;
            str = strMo2973b;
        }
        if (str == null) {
            return null;
        }
        SmsEntity smsEntity = new SmsEntity();
        smsEntity.phonenum = str;
        smsEntity.body = stringBuffer.toString();
        smsEntity.type = 1;
        smsEntity.protocolType = 0;
        smsEntity.raw = this.f6974b;
        return smsEntity;
    }
}
