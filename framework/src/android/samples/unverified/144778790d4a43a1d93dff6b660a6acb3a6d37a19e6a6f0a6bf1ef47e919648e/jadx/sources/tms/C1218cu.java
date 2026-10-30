package tms;

import android.text.TextUtils;
import java.util.Arrays;
import org.apache.commons.httpclient.cookie.CookiePolicy;

/* JADX INFO: renamed from: tms.cu */
/* JADX INFO: loaded from: classes.dex */
final class C1218cu {

    /* JADX INFO: renamed from: a */
    private static final String[] f7036a = {"cmwap", "cmnet", "3gwap", "3gnet", "uniwap", "uninet", "ctwap", "ctnet", CookiePolicy.DEFAULT};

    /* JADX INFO: renamed from: b */
    private static final String[] f7037b = {"cmnet", "3gnet", "uninet", "ctnet"};

    /* JADX INFO: renamed from: c */
    private static final String[] f7038c = {"cmwap", "3gwap", "uniwap", "ctwap"};

    /* JADX INFO: renamed from: a */
    public static String m3073a(String str) {
        if (!TextUtils.isEmpty(str)) {
            String lowerCase = str.toLowerCase();
            for (int i = 0; i < f7036a.length; i++) {
                if (lowerCase.startsWith(f7036a[i])) {
                    return f7036a[i];
                }
            }
        }
        return null;
    }

    /* JADX INFO: renamed from: b */
    public static boolean m3074b(String str) {
        if (TextUtils.isEmpty(str)) {
            return false;
        }
        return Arrays.asList(f7037b).contains(str);
    }

    /* JADX INFO: renamed from: c */
    public static boolean m3075c(String str) {
        if (TextUtils.isEmpty(str)) {
            return false;
        }
        return Arrays.asList(f7038c).contains(str);
    }
}
