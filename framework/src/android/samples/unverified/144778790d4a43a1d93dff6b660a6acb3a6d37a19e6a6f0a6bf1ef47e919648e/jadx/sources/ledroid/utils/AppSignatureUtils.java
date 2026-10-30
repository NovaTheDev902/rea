package ledroid.utils;

import android.content.Context;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public final class AppSignatureUtils {

    /* JADX INFO: renamed from: a */
    private static MessageDigest f6374a;

    /* JADX INFO: renamed from: b */
    private static List<String> f6375b = new ArrayList();

    /* JADX INFO: renamed from: c */
    private static final char[] f6376c = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    public static final String[] SIGNATURE_MD5S = {"EBAA529685AAE3A1D299AC15F7710AEA", "B78A0EE7E80045B4F9A0C425703D0CA4", "388CF508552BC50ED26A8715D33312BA", "49FF2FEA9A214DCC2F7EF229488B1A54", "56B44C8B44C3A4064FE0667DC91E01AA", "CEA942B20A36347B3BF793BFF50F737D"};

    private AppSignatureUtils() {
    }

    static {
        try {
            f6374a = MessageDigest.getInstance("MD5");
        } catch (NoSuchAlgorithmException nsaex) {
            nsaex.printStackTrace();
        }
    }

    public static String getCretMD5(Context context, String packName) {
        String md5 = null;
        try {
            Signature[] sigs = context.getPackageManager().getPackageInfo(packName, 64).signatures;
            for (Signature signature : sigs) {
                md5 = getMD5String(signature.toByteArray());
            }
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        if (md5 != null) {
            return md5.toUpperCase();
        }
        return null;
    }

    public static String getMD5String(byte[] bytes) {
        f6374a.update(bytes);
        byte[] bArrDigest = f6374a.digest();
        int length = bArrDigest.length;
        StringBuffer stringBuffer = new StringBuffer(length * 2);
        int i = length + 0;
        for (int i2 = 0; i2 < i; i2++) {
            byte b = bArrDigest[i2];
            char c = f6376c[(b & 240) >> 4];
            char c2 = f6376c[b & 15];
            stringBuffer.append(c);
            stringBuffer.append(c2);
        }
        return stringBuffer.toString();
    }

    public static List<String> getsignatureMd5sList(Context context) {
        String platformKey = getCretMD5(context, "com.android.settings");
        f6375b.add(platformKey);
        String sharedKey = getCretMD5(context, "com.android.contacts");
        f6375b.add(sharedKey);
        return f6375b;
    }
}
