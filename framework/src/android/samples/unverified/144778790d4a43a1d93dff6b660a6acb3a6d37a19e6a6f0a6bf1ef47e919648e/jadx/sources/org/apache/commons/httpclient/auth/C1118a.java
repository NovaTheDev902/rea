package org.apache.commons.httpclient.auth;

import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.SecretKeySpec;
import org.apache.commons.codec.binary.Base64;
import org.apache.commons.httpclient.util.EncodingUtil;

/* JADX INFO: renamed from: org.apache.commons.httpclient.auth.a */
/* JADX INFO: compiled from: NTLM.java */
/* JADX INFO: loaded from: classes.dex */
final class C1118a {

    /* JADX INFO: renamed from: a */
    private byte[] f6610a;

    /* JADX INFO: renamed from: b */
    private int f6611b = 0;

    /* JADX INFO: renamed from: c */
    private String f6612c = "ASCII";

    C1118a() {
    }

    /* JADX INFO: renamed from: a */
    public final String m2783a(String message, String username, String password, String host, String domain) throws AuthenticationException {
        if (message == null || message.trim().equals("")) {
            String response = m2782a(host, domain);
            return response;
        }
        String response2 = m2784a(username, password, host, domain, m2778a(message));
        return response2;
    }

    /* JADX INFO: renamed from: a */
    private static Cipher m2775a(byte[] key) throws AuthenticationException {
        try {
            Cipher ecipher = Cipher.getInstance("DES/ECB/NoPadding");
            byte[] key2 = new byte[8];
            key2[0] = (byte) ((key[0] >> 1) & 255);
            key2[1] = (byte) ((((key[0] & 1) << 6) | (((key[1] & 255) >> 2) & 255)) & 255);
            key2[2] = (byte) ((((key[1] & 3) << 5) | (((key[2] & 255) >> 3) & 255)) & 255);
            key2[3] = (byte) ((((key[2] & 7) << 4) | (((key[3] & 255) >> 4) & 255)) & 255);
            key2[4] = (byte) ((((key[3] & 15) << 3) | (((key[4] & 255) >> 5) & 255)) & 255);
            key2[5] = (byte) ((((key[4] & 31) << 2) | (((key[5] & 255) >> 6) & 255)) & 255);
            key2[6] = (byte) ((((key[5] & 63) << 1) | (((key[6] & 255) >> 7) & 255)) & 255);
            key2[7] = (byte) (key[6] & 127);
            for (int i = 0; i < key2.length; i++) {
                key2[i] = (byte) (key2[i] << 1);
            }
            try {
                ecipher.init(1, new SecretKeySpec(key2, "DES"));
                return ecipher;
            } catch (InvalidKeyException e) {
                e = e;
                throw new AuthenticationException("Invalid key for DES encryption.", e);
            } catch (NoSuchAlgorithmException e2) {
                e = e2;
                throw new AuthenticationException("DES encryption is not available.", e);
            } catch (NoSuchPaddingException e3) {
                e = e3;
                throw new AuthenticationException("NoPadding option for DES is not available.", e);
            }
        } catch (InvalidKeyException e4) {
            e = e4;
        } catch (NoSuchAlgorithmException e5) {
            e = e5;
        } catch (NoSuchPaddingException e6) {
            e = e6;
        }
    }

    /* JADX INFO: renamed from: a */
    private static byte[] m2779a(byte[] key, byte[] bytes) throws AuthenticationException {
        Cipher ecipher = m2775a(key);
        try {
            byte[] enc = ecipher.doFinal(bytes);
            return enc;
        } catch (BadPaddingException e) {
            throw new AuthenticationException("Data not padded correctly for DES encryption.", e);
        } catch (IllegalBlockSizeException e2) {
            throw new AuthenticationException("Invalid block size for DES encryption.", e2);
        }
    }

    /* JADX INFO: renamed from: a */
    private void m2777a(int length) {
        this.f6610a = new byte[length];
        this.f6611b = 0;
    }

    /* JADX INFO: renamed from: a */
    private void m2776a(byte b) {
        this.f6610a[this.f6611b] = b;
        this.f6611b++;
    }

    /* JADX INFO: renamed from: b */
    private void m2780b(byte[] bytes) {
        for (byte b : bytes) {
            this.f6610a[this.f6611b] = b;
            this.f6611b++;
        }
    }

    /* JADX INFO: renamed from: a */
    private String m2774a() {
        byte[] resp;
        if (this.f6610a.length > this.f6611b) {
            byte[] tmp = new byte[this.f6611b];
            for (int i = 0; i < this.f6611b; i++) {
                tmp[i] = this.f6610a[i];
            }
            resp = tmp;
        } else {
            resp = this.f6610a;
        }
        return EncodingUtil.getAsciiString(Base64.encodeBase64(resp));
    }

    /* JADX INFO: renamed from: a */
    public final String m2782a(String host, String domain) {
        String host2 = host.toUpperCase();
        String domain2 = domain.toUpperCase();
        byte[] hostBytes = EncodingUtil.getBytes(host2, "ASCII");
        byte[] domainBytes = EncodingUtil.getBytes(domain2, "ASCII");
        int finalLength = hostBytes.length + 32 + domainBytes.length;
        m2777a(finalLength);
        byte[] protocol = EncodingUtil.getBytes("NTLMSSP", "ASCII");
        m2780b(protocol);
        m2776a((byte) 0);
        m2776a((byte) 1);
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2776a((byte) 6);
        m2776a((byte) 82);
        m2776a((byte) 0);
        m2776a((byte) 0);
        int iDomLen = domainBytes.length;
        byte[] domLen = m2781b(iDomLen);
        m2776a(domLen[0]);
        m2776a(domLen[1]);
        m2776a(domLen[0]);
        m2776a(domLen[1]);
        byte[] domOff = m2781b(hostBytes.length + 32);
        m2776a(domOff[0]);
        m2776a(domOff[1]);
        m2776a((byte) 0);
        m2776a((byte) 0);
        byte[] hostLen = m2781b(hostBytes.length);
        m2776a(hostLen[0]);
        m2776a(hostLen[1]);
        m2776a(hostLen[0]);
        m2776a(hostLen[1]);
        byte[] hostOff = m2781b(32);
        m2776a(hostOff[0]);
        m2776a(hostOff[1]);
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2780b(hostBytes);
        m2780b(domainBytes);
        return m2774a();
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m2778a(String message) {
        byte[] msg = Base64.decodeBase64(EncodingUtil.getBytes(message, "ASCII"));
        byte[] nonce = new byte[8];
        for (int i = 0; i < 8; i++) {
            nonce[i] = msg[i + 24];
        }
        return nonce;
    }

    /* JADX INFO: renamed from: a */
    public final String m2784a(String user, String password, String host, String domain, byte[] nonce) throws AuthenticationException {
        String domain2 = domain.toUpperCase();
        String host2 = host.toUpperCase();
        String user2 = user.toUpperCase();
        byte[] domainBytes = EncodingUtil.getBytes(domain2, "ASCII");
        byte[] hostBytes = EncodingUtil.getBytes(host2, "ASCII");
        byte[] userBytes = EncodingUtil.getBytes(user2, this.f6612c);
        int domainLen = domainBytes.length;
        int hostLen = hostBytes.length;
        int userLen = userBytes.length;
        int finalLength = domainLen + 88 + userLen + hostLen;
        m2777a(finalLength);
        byte[] ntlmssp = EncodingUtil.getBytes("NTLMSSP", "ASCII");
        m2780b(ntlmssp);
        m2776a((byte) 0);
        m2776a((byte) 3);
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2780b(m2781b(24));
        m2780b(m2781b(24));
        m2780b(m2781b(finalLength - 24));
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2780b(m2781b(0));
        m2780b(m2781b(0));
        m2780b(m2781b(finalLength));
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2780b(m2781b(domainLen));
        m2780b(m2781b(domainLen));
        m2780b(m2781b(64));
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2780b(m2781b(userLen));
        m2780b(m2781b(userLen));
        m2780b(m2781b(domainLen + 64));
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2780b(m2781b(hostLen));
        m2780b(m2781b(hostLen));
        m2780b(m2781b(domainLen + 64 + userLen));
        for (int i = 0; i < 6; i++) {
            m2776a((byte) 0);
        }
        m2780b(m2781b(finalLength));
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2776a((byte) 6);
        m2776a((byte) 82);
        m2776a((byte) 0);
        m2776a((byte) 0);
        m2780b(domainBytes);
        m2780b(userBytes);
        m2780b(hostBytes);
        byte[] bytes = EncodingUtil.getBytes(password.toUpperCase(), this.f6612c);
        byte[] bArr = new byte[7];
        byte[] bArr2 = new byte[7];
        int length = bytes.length;
        if (length > 7) {
            length = 7;
        }
        int i2 = 0;
        while (i2 < length) {
            bArr[i2] = bytes[i2];
            i2++;
        }
        for (int i3 = i2; i3 < 7; i3++) {
            bArr[i3] = 0;
        }
        int length2 = bytes.length;
        if (length2 > 14) {
            length2 = 14;
        }
        int i4 = 7;
        while (i4 < length2) {
            bArr2[i4 - 7] = bytes[i4];
            i4++;
        }
        for (int i5 = i4; i5 < 14; i5++) {
            bArr2[i5 - 7] = 0;
        }
        byte[] bArr3 = {75, 71, 83, 33, 64, 35, 36, 37};
        byte[] bArrM2779a = m2779a(bArr, bArr3);
        byte[] bArrM2779a2 = m2779a(bArr2, bArr3);
        byte[] bArr4 = new byte[21];
        for (int i6 = 0; i6 < bArrM2779a.length; i6++) {
            bArr4[i6] = bArrM2779a[i6];
        }
        for (int i7 = 0; i7 < bArrM2779a2.length; i7++) {
            bArr4[i7 + 8] = bArrM2779a2[i7];
        }
        for (int i8 = 0; i8 < 5; i8++) {
            bArr4[i8 + 16] = 0;
        }
        byte[] bArr5 = new byte[24];
        byte[] bArr6 = new byte[7];
        byte[] bArr7 = new byte[7];
        byte[] bArr8 = new byte[7];
        for (int i9 = 0; i9 < 7; i9++) {
            bArr6[i9] = bArr4[i9];
        }
        for (int i10 = 0; i10 < 7; i10++) {
            bArr7[i10] = bArr4[i10 + 7];
        }
        for (int i11 = 0; i11 < 7; i11++) {
            bArr8[i11] = bArr4[i11 + 14];
        }
        byte[] bArrM2779a3 = m2779a(bArr6, nonce);
        byte[] bArrM2779a4 = m2779a(bArr7, nonce);
        byte[] bArrM2779a5 = m2779a(bArr8, nonce);
        for (int i12 = 0; i12 < 8; i12++) {
            bArr5[i12] = bArrM2779a3[i12];
        }
        for (int i13 = 0; i13 < 8; i13++) {
            bArr5[i13 + 8] = bArrM2779a4[i13];
        }
        for (int i14 = 0; i14 < 8; i14++) {
            bArr5[i14 + 16] = bArrM2779a5[i14];
        }
        m2780b(bArr5);
        return m2774a();
    }

    /* JADX INFO: renamed from: b */
    private static byte[] m2781b(int num) {
        byte[] val = new byte[2];
        String hex = Integer.toString(num, 16);
        while (hex.length() < 4) {
            hex = new StringBuffer().append("0").append(hex).toString();
        }
        String low = hex.substring(2, 4);
        String high = hex.substring(0, 2);
        val[0] = (byte) Integer.parseInt(low, 16);
        val[1] = (byte) Integer.parseInt(high, 16);
        return val;
    }

    /* JADX INFO: renamed from: b */
    public final void m2785b(String credentialCharset) {
        this.f6612c = credentialCharset;
    }
}
