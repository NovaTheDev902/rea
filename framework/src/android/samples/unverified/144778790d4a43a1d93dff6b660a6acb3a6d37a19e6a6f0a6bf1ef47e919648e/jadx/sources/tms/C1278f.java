package tms;

import QQPIM.LicenceCheckResult;
import android.util.Log;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.utils.Base64;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.security.GeneralSecurityException;
import java.security.interfaces.RSAPublicKey;
import java.util.Calendar;
import java.util.Properties;
import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESKeySpec;

/* JADX INFO: renamed from: tms.f */
/* JADX INFO: loaded from: classes.dex */
public final class C1278f {

    /* JADX INFO: renamed from: a */
    private static volatile C1278f f7301a = null;

    /* JADX INFO: renamed from: b */
    private C1185bo f7302b;

    /* JADX INFO: renamed from: c */
    private Calendar f7303c = Calendar.getInstance();

    /* JADX INFO: renamed from: d */
    private C1231dg f7304d;

    /* JADX INFO: renamed from: tms.f$a */
    public class a {
        public a() {
        }
    }

    private C1278f() {
        m3289g();
    }

    /* JADX INFO: renamed from: a */
    public static synchronized C1278f m3286a() {
        if (f7301a == null) {
            f7301a = new C1278f();
        }
        return f7301a;
    }

    /* JADX INFO: renamed from: a */
    private static byte[] m3287a(int i) {
        try {
            InputStream inputStreamOpen = TMSApplication.getApplicaionContext().getAssets().open(i == 0 ? "licence.conf" : "licence" + i + ".conf");
            byte[] bArr = new byte[inputStreamOpen.available()];
            inputStreamOpen.read(bArr);
            inputStreamOpen.close();
            return bArr;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    /* JADX INFO: renamed from: a */
    private static byte[] m3288a(byte[] bArr, byte[] bArr2) {
        try {
            SecretKey secretKeyGenerateSecret = SecretKeyFactory.getInstance("DES").generateSecret(new DESKeySpec(bArr2));
            Cipher cipher = Cipher.getInstance("DES/ECB/NoPadding");
            cipher.init(2, secretKeyGenerateSecret);
            return cipher.doFinal(bArr);
        } catch (GeneralSecurityException e) {
            e.printStackTrace();
            return null;
        }
    }

    /* JADX INFO: renamed from: g */
    private void m3289g() {
        int i = 0;
        while (true) {
            try {
                byte[] bArrM3287a = m3287a(i);
                if (bArrM3287a == null) {
                    throw new RuntimeException("Certification file is missing! Please contact TMS(Tencent Mobile Secure) group.");
                }
                if (TMSApplication.getSecureServiceClass() == null) {
                    throw new RuntimeException("Licence authentication needs a backgroundservice, you must pass a Service'Class while calling TMSApplication.init method.");
                }
                RSAPublicKey rSAPublicKeyM3291i = m3291i();
                byte[] bArr = new byte[128];
                System.arraycopy(bArrM3287a, 0, bArr, 0, bArr.length);
                byte[] bArrM3042a = C1207cj.m3042a(bArr, rSAPublicKeyM3291i);
                if (bArrM3042a == null) {
                    throw new RuntimeException("RSA decrypt error.");
                }
                byte[] bArr2 = new byte[bArrM3287a.length - 128];
                System.arraycopy(bArrM3287a, 128, bArr2, 0, bArr2.length);
                ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(m3288a(bArr2, bArrM3042a));
                Properties properties = new Properties();
                try {
                    properties.load(byteArrayInputStream);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                this.f7304d = new C1231dg(properties, TMSApplication.getApplicaionContext());
                if (this.f7304d.m3113a()) {
                    m3290h();
                    this.f7303c.setTimeInMillis(System.currentTimeMillis());
                    return;
                }
                i++;
            } catch (RuntimeException e2) {
                throw new RuntimeException("Invaild signature! Please contact TMS(Tencent Mobile Secure) group.");
            }
        }
    }

    /* JADX INFO: renamed from: h */
    private final void m3290h() {
        long jM3117d;
        String strM2883a = new C1149af("licence").m2883a("expiry.enc_seconds", (String) null);
        if (strM2883a != null) {
            RSAPublicKey rSAPublicKeyM3291i = m3291i();
            try {
                byte[] bArrDecode = Base64.decode(strM2883a, 0);
                int i = ByteBuffer.wrap(bArrDecode).getInt();
                Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
                cipher.init(2, rSAPublicKeyM3291i);
                byte[] bArrDoFinal = cipher.doFinal(bArrDecode, 4, i);
                Cipher cipher2 = Cipher.getInstance("DES/ECB/PKCS5Padding");
                cipher2.init(2, SecretKeyFactory.getInstance("DES").generateSecret(new DESKeySpec(bArrDoFinal)));
                jM3117d = Long.parseLong(new String(cipher2.doFinal(bArrDecode, i + 4, (bArrDecode.length - 4) - i)), 16);
            } catch (Exception e) {
                e.printStackTrace();
                jM3117d = -1;
            }
        } else {
            jM3117d = -1;
        }
        if (jM3117d == -1) {
            jM3117d = this.f7304d.m3117d();
        }
        boolean z = System.currentTimeMillis() / 1000 >= jM3117d;
        Calendar calendar = Calendar.getInstance();
        calendar.setTimeInMillis(jM3117d * 1000);
        Log.d("LicMan", "expirySeconds=" + jM3117d + "(" + calendar.get(1) + "-" + calendar.get(2) + "-" + calendar.get(5) + ") expired=" + z);
        this.f7302b = new C1185bo(z);
    }

    /* JADX INFO: renamed from: i */
    private static RSAPublicKey m3291i() {
        return C1207cj.m3041a(Base64.decode("LS0tLS1CRUdJTiBDRVJUSUZJQ0FURS0tLS0tCk1JSUM5ekNDQWQ4Q0NRRGlsbUFjTWxiczVEQU5C\nZ2txaGtpRzl3MEJBUVVGQURCK01Rc3dDUVlEVlFRR0V3SkQKVGpFTE1Ba0dBMVVFQ0JNQ1IwUXhD\nekFKQmdOVkJBY1RBa2RhTVJJd0VBWURWUVFLRkFsMFpXTUlibU5sYm5ReApDekFKQmdOVkJBc1RB\nak5ITVE0d0RBWURWUVFERXdWdlltRnRZVEVrTUNJR0NTcUdTSWIzRFFFSkFSWVZiMkpoCmJXRjZa\nVzVuUUhSbGJtTmxiblF1WTI5dE1CNFhEVEV4TVRFeE5qRXhNVGN4TjFvWERURXlNREl5TkRFeE1U\nY3gKTjFvd2dZQXhDekFKQmdOVkJBWVRBa05PTVFzd0NRWURWUVFJRXdKSFJERUxNQWtHQTFVRUJ4\nTUNSMW94RURBTwpCZ05WQkFvVEIzUmxibU5sYm5ReEN6QUpCZ05WQkFzVEFqTkhNUkl3RUFZRFZR\nUURFd2x2WW1GdFlYcGxibWN4CkpEQWlCZ2txaGtpRzl3MEJDUUVXRlc5aVlXMWhlbVZ1WjBCMFpX\nNWpaVzUwTG1OdmJUQ0JuekFOQmdrcWhraUcKOXcwQkFRRUZBQU9CalFBd2dZa0NnWUVBd1kvV3FI\nV2NlRERkSm16anI3TlpSeS9qTllwS1NzVzExZngxaTIrQwpxTUE3NTJXb1d1bDZuSTB1MGZkWitk\nUzVUandRNkU0Qm13dXduVTVnQmJYK1VzQ2VHRHZaQVhQc045UEVWYnZTCkcvR25YclQrcTI2VUpP\nNHcrd3VNdmk5YWxkZHhhbkNKeXJ2ZWQ2NUdvMXhXUEErWGNHaVQxMndubjZtUHhyMnUKcVEwQ0F3\nRUFBVEFOQmdrcWhraUc5dzBCQVFVRkFBT0NBUUVBblpzV3FpSmV5SC9sT0prSWN6L2ZidDN3MXFL\nRApGTXJ5cFVHVFN6Z3NONWNaMW9yOGlvVG5ENGRLaDdJN2ttbDRpcGNvMDF0enc2MGhLYUtwNG9G\nMnYrMEs2NGZDCnBEMG9EUlkrOGoyK2RsMmNxeHBsT0FYdDc1RWFKNW40MG1DZDdTN0VBS0d2Z2Na\naVhyV0Z1eUtCL2QvNTh3Qm4KOEFGUVJhTnBySXNOSHpxMkMwL0JXR1pTSnJicmhOWExFY0ZtL0Ru\nTG14ZEVNYWxPSXhnSkhGcEFOS2tadXBzdgo0L0lDVFhSL0RJaURjbXJjbDFkNkc2VmgyaUcwaS9v\nRDBHQnBMZlFPcEF0Vmx6Y2lxZnBsTkphcnpRUTZUVXRyCm5GRmVNVDNDc2t5VGJwYnp1R2dDdUxj\nQVR3cnRQd1BOOWZzQXYrSjRJZm0rZUNVVDVnZlorMSsyNHc9PQotLS0tLUVORCBDRVJUSUZJQ0FU\nRS0tLS0tCg==\n".getBytes(), 0));
    }

    /* JADX INFO: renamed from: a */
    public final void m3292a(String str) {
        Log.d("LicMan", "strTimeSec=" + str);
        C1329o.m3531a(getClass());
        new C1149af("licence").m2888a("expiry.enc_seconds", str, true);
        m3290h();
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3293a(Class<? extends BaseManager> cls) {
        if (this.f7304d != null) {
            return this.f7304d.m3114a(cls);
        }
        return false;
    }

    /* JADX INFO: renamed from: b */
    public final boolean m3294b() {
        boolean zM3297e;
        LicenceCheckResult licenceCheckResult = new LicenceCheckResult();
        int iM3112a = this.f7304d.m3112a(licenceCheckResult);
        if (licenceCheckResult.value == null || licenceCheckResult.value.strtime_sec == null || licenceCheckResult.value.strtime_sec.length() == 0) {
            switch (iM3112a) {
                case -1:
                    return false;
                case 0:
                default:
                    return !m3297e();
                case 1:
                    return true;
            }
        }
        switch (iM3112a) {
            case -1:
                m3292a(licenceCheckResult.value.strtime_sec);
                zM3297e = true;
                break;
            case 0:
                throw new RuntimeException("Unknown licence! Please contact TMS(Tencent Mobile Secure) group.");
            case 1:
                m3292a(licenceCheckResult.value.strtime_sec);
                zM3297e = false;
                break;
            default:
                zM3297e = m3297e();
                break;
        }
        return !zM3297e;
    }

    /* JADX INFO: renamed from: c */
    public final String m3295c() {
        return this.f7304d.m3115b();
    }

    /* JADX INFO: renamed from: d */
    public final String m3296d() {
        return this.f7304d.m3116c();
    }

    /* JADX INFO: renamed from: e */
    public final boolean m3297e() {
        Calendar calendar = Calendar.getInstance();
        calendar.setTimeInMillis(System.currentTimeMillis());
        if (calendar.get(1) != this.f7303c.get(1) || calendar.get(6) != this.f7303c.get(6)) {
            m3290h();
        }
        this.f7303c.setTimeInMillis(System.currentTimeMillis());
        return this.f7302b.m3008a();
    }

    /* JADX INFO: renamed from: f */
    public final boolean m3298f() {
        return this.f7304d.m3113a();
    }
}
