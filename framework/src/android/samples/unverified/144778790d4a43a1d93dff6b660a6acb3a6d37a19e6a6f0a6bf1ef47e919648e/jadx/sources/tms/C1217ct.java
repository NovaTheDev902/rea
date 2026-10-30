package tms;

import android.content.Intent;
import android.text.TextUtils;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.utils.SDKUtil;
import java.io.ByteArrayInputStream;

/* JADX INFO: renamed from: tms.ct */
/* JADX INFO: loaded from: classes.dex */
final class C1217ct implements InterfaceC1171ba {

    /* JADX INFO: renamed from: a */
    private final String f7027a = "0c";

    /* JADX INFO: renamed from: b */
    private final String f7028b = "01";

    /* JADX INFO: renamed from: c */
    private final String f7029c = "03";

    /* JADX INFO: renamed from: d */
    private final String f7030d = "00";

    /* JADX INFO: renamed from: e */
    private Intent f7031e;

    /* JADX INFO: renamed from: f */
    private a f7032f;

    /* JADX INFO: renamed from: tms.ct$a */
    static final class a {

        /* JADX INFO: renamed from: a */
        String f7033a = null;

        /* JADX INFO: renamed from: b */
        String f7034b;

        /* JADX INFO: renamed from: c */
        String f7035c;

        a() {
        }
    }

    public C1217ct(Intent intent) {
        this.f7031e = intent;
    }

    /* JADX INFO: renamed from: a */
    private static int m3065a(char c) {
        if (c >= '0' && c <= '9') {
            return c - '0';
        }
        if (c >= 'A' && c <= 'F') {
            return (c - 'A') + 10;
        }
        if (c < 'a' || c > 'f') {
            throw new RuntimeException("invalid hex char '" + c + "'");
        }
        return (c - 'a') + 10;
    }

    /* JADX INFO: renamed from: a */
    private boolean m3066a(ByteArrayInputStream byteArrayInputStream) {
        byteArrayInputStream.reset();
        while (byteArrayInputStream.available() > 0) {
            String strM3072f = m3072f(byteArrayInputStream);
            if ("0c".equals(strM3072f)) {
                this.f7032f.f7034b = "http://" + new String(m3067a(m3071e(byteArrayInputStream)));
            } else if ("01".equals(strM3072f)) {
                this.f7032f.f7035c = new String(m3067a(m3071e(byteArrayInputStream)));
            }
        }
        return TextUtils.isEmpty(this.f7032f.f7035c);
    }

    /* JADX INFO: renamed from: a */
    private static byte[] m3067a(String str) {
        if (str == null) {
            return null;
        }
        int length = str.length();
        byte[] bArr = new byte[length / 2];
        for (int i = 0; i < length; i += 2) {
            bArr[i / 2] = (byte) ((m3065a(str.charAt(i)) << 4) | m3065a(str.charAt(i + 1)));
        }
        return bArr;
    }

    /* JADX INFO: renamed from: b */
    private boolean m3068b(ByteArrayInputStream byteArrayInputStream) {
        byteArrayInputStream.reset();
        while (byteArrayInputStream.available() > 0) {
            this.f7032f.f7035c = new String(m3067a(m3071e(byteArrayInputStream)));
        }
        return TextUtils.isEmpty(this.f7032f.f7035c);
    }

    /* JADX INFO: renamed from: c */
    private boolean m3069c(ByteArrayInputStream byteArrayInputStream) {
        StringBuilder sb = new StringBuilder();
        String str = "";
        byteArrayInputStream.reset();
        while (byteArrayInputStream.available() > 0) {
            String strM3072f = m3072f(byteArrayInputStream);
            if (strM3072f.equals("03")) {
                String str2 = new String(m3067a(m3070d(byteArrayInputStream)));
                sb.append(str2);
                if (str.equals("0c")) {
                    this.f7032f.f7034b = "http://" + str2;
                } else if (str.equals("01")) {
                    this.f7032f.f7035c = str2;
                }
            } else {
                str = strM3072f;
            }
        }
        if (TextUtils.isEmpty(this.f7032f.f7035c)) {
            this.f7032f.f7035c = sb.toString();
        }
        return TextUtils.isEmpty(this.f7032f.f7035c);
    }

    /* JADX INFO: renamed from: d */
    private static String m3070d(ByteArrayInputStream byteArrayInputStream) {
        if (byteArrayInputStream == null) {
            return null;
        }
        StringBuilder sb = new StringBuilder();
        while (byteArrayInputStream.available() > 0) {
            String strM3072f = m3072f(byteArrayInputStream);
            if (strM3072f.equals("00")) {
                break;
            }
            sb.append(strM3072f);
        }
        return sb.toString();
    }

    /* JADX INFO: renamed from: e */
    private static String m3071e(ByteArrayInputStream byteArrayInputStream) {
        if (byteArrayInputStream == null) {
            return null;
        }
        StringBuilder sb = new StringBuilder();
        while (!m3072f(byteArrayInputStream).equals("03") && byteArrayInputStream.available() > 0) {
        }
        while (true) {
            String strM3072f = m3072f(byteArrayInputStream);
            if (strM3072f.equals("00") || byteArrayInputStream.available() <= 0) {
                break;
            }
            sb.append(strM3072f);
        }
        return sb.toString();
    }

    /* JADX INFO: renamed from: f */
    private static String m3072f(ByteArrayInputStream byteArrayInputStream) {
        if (byteArrayInputStream == null) {
            return null;
        }
        int i = byteArrayInputStream.read();
        StringBuilder sb = new StringBuilder(2);
        sb.append("0123456789abcdef".charAt((i >> 4) & 15));
        sb.append("0123456789abcdef".charAt(i & 15));
        return sb.toString().toLowerCase();
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: a */
    public final String mo2971a() {
        if (this.f7032f == null) {
            return null;
        }
        a aVar = this.f7032f;
        return aVar.f7035c + aVar.f7034b;
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: a */
    public final void mo2972a(byte[] bArr) {
        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(bArr);
        this.f7032f = new a();
        if (m3066a(byteArrayInputStream) || m3068b(byteArrayInputStream) || m3069c(byteArrayInputStream)) {
            return;
        }
        this.f7032f = null;
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: b */
    public final String mo2973b() {
        if (this.f7032f == null) {
            return null;
        }
        a aVar = this.f7032f;
        return aVar.f7033a == null ? aVar.f7034b : aVar.f7033a;
    }

    @Override // tms.InterfaceC1171ba
    /* JADX INFO: renamed from: c */
    public final SmsEntity mo2974c() {
        byte[] byteArrayExtra = this.f7031e.getByteArrayExtra(SettingUtil.DATA);
        if (byteArrayExtra == null || SDKUtil.getSDKVersion() <= 3) {
            return null;
        }
        mo2972a(byteArrayExtra);
        SmsEntity smsEntity = new SmsEntity();
        smsEntity.phonenum = mo2973b();
        smsEntity.body = mo2971a();
        smsEntity.type = 1;
        smsEntity.protocolType = 2;
        smsEntity.raw = this.f7031e;
        return smsEntity;
    }
}
