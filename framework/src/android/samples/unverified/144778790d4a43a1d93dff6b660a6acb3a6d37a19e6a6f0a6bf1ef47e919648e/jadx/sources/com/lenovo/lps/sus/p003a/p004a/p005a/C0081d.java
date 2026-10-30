package com.lenovo.lps.sus.p003a.p004a.p005a;

import com.lenovo.lps.sus.p003a.p004a.p006b.C0084c;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import javax.crypto.KeyGenerator;
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;

/* JADX INFO: renamed from: com.lenovo.lps.sus.a.a.a.d */
/* JADX INFO: loaded from: classes.dex */
public class C0081d implements InterfaceC0079b {

    /* JADX INFO: renamed from: c */
    public static final String f1216c = "HmacSHA1";

    /* JADX INFO: renamed from: a */
    public static String m255a(String str, String str2) throws Exception {
        try {
            C0081d c0081d = new C0081d();
            return c0081d.m256a(c0081d.m257a(str.getBytes(InterfaceC0079b.f1213a), str2)).trim();
        } catch (Exception e) {
            throw new Exception("make sign error happen!", e);
        }
    }

    @Override // com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b
    /* JADX INFO: renamed from: a */
    public String mo250a() {
        return EnumC0078a.BASE64.m249a();
    }

    @Override // com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b
    /* JADX INFO: renamed from: a */
    public String mo251a(String str) throws Exception {
        try {
            return C0084c.m262a(str, InterfaceC0079b.f1213a);
        } catch (Exception e) {
            throw new Exception("BASE64 encode fail");
        }
    }

    /* JADX INFO: renamed from: a */
    public String m256a(byte[] bArr) {
        return new String(C0084c.m264a(bArr));
    }

    /* JADX INFO: renamed from: a */
    public byte[] m257a(byte[] bArr, String str) throws NoSuchAlgorithmException, InvalidKeyException {
        SecretKeySpec secretKeySpec = new SecretKeySpec(m259b(str.getBytes()), f1216c);
        Mac mac = Mac.getInstance(secretKeySpec.getAlgorithm());
        mac.init(secretKeySpec);
        return mac.doFinal(bArr);
    }

    /* JADX INFO: renamed from: b */
    public String m258b() {
        return m256a(KeyGenerator.getInstance(f1216c).generateKey().getEncoded());
    }

    @Override // com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b
    /* JADX INFO: renamed from: b */
    public String mo252b(String str) throws Exception {
        try {
            return C0084c.m266b(str, InterfaceC0079b.f1213a);
        } catch (Exception e) {
            throw new Exception("BASE64 decode fail");
        }
    }

    /* JADX INFO: renamed from: b */
    public byte[] m259b(byte[] bArr) {
        return C0084c.m267b(bArr);
    }
}
