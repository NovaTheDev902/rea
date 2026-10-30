package tms;

import com.tencent.tccdb.TccCryptor;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.utils.Base64;

/* JADX INFO: renamed from: tms.ao */
/* JADX INFO: loaded from: classes.dex */
public final class C1158ao {

    /* JADX INFO: renamed from: b */
    public static final String f6845b = "password";

    /* JADX INFO: renamed from: c */
    public static final String f6846c = "helper";

    /* JADX INFO: renamed from: a */
    public C1149af f6847a = new C1149af("AntitheftProperty");

    /* JADX INFO: renamed from: c */
    public static final String m2930c(String str) {
        if (str == null) {
            return null;
        }
        return Base64.encodeToString(TccCryptor.encrypt(TMSApplication.getApplicaionContext(), str.getBytes(), (byte[]) null), 0);
    }

    /* JADX INFO: renamed from: a */
    public final String m2931a() {
        return this.f6847a.m2883a(f6846c, (String) null);
    }

    /* JADX INFO: renamed from: a */
    public final String m2932a(boolean z) {
        String strM2883a = this.f6847a.m2883a("password", (String) null);
        if (strM2883a == null) {
            return null;
        }
        if (z) {
            return strM2883a;
        }
        return new String(TccCryptor.decrypt(TMSApplication.getApplicaionContext(), Base64.decode(strM2883a.getBytes(), 0), null));
    }

    /* JADX INFO: renamed from: a */
    public final void m2933a(String str) {
        if (str == null) {
            return;
        }
        this.f6847a.m2888a("password", m2930c(str), true);
    }

    /* JADX INFO: renamed from: b */
    public final void m2934b(String str) {
        this.f6847a.m2888a(f6846c, str, true);
    }
}
