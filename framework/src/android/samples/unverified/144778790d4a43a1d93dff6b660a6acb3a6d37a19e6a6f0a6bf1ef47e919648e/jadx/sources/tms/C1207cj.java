package tms;

import java.security.interfaces.RSAPublicKey;
import javax.crypto.Cipher;
import javax.security.cert.CertificateException;
import javax.security.cert.X509Certificate;

/* JADX INFO: renamed from: tms.cj */
/* JADX INFO: loaded from: classes.dex */
final class C1207cj {
    /* JADX INFO: renamed from: a */
    public static RSAPublicKey m3041a(byte[] bArr) {
        try {
            return (RSAPublicKey) X509Certificate.getInstance(bArr).getPublicKey();
        } catch (CertificateException e) {
            e.printStackTrace();
            return null;
        }
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m3042a(byte[] bArr, RSAPublicKey rSAPublicKey) {
        if (rSAPublicKey == null) {
            return null;
        }
        try {
            Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
            cipher.init(2, rSAPublicKey);
            return cipher.doFinal(bArr);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}
