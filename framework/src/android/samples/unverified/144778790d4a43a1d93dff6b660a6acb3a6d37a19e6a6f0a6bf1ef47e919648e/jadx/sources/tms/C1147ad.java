package tms;

import android.content.Context;
import java.io.File;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: renamed from: tms.ad */
/* JADX INFO: loaded from: classes.dex */
public class C1147ad {
    /* JADX WARN: Code duplicated, block: B:45:0x0174 A[PHI: r4
  0x0174: PHI (r4v6 java.lang.String) = (r4v5 java.lang.String), (r4v5 java.lang.String), (r4v12 java.lang.String), (r4v12 java.lang.String) binds: [B:22:0x00c3, B:24:0x00cb, B:26:0x00fa, B:44:0x0173] A[DONT_GENERATE, DONT_INLINE]] */
    /* JADX INFO: renamed from: a */
    public static boolean m2873a(Context context, String str) {
        String str2;
        boolean z;
        String str3;
        boolean z2;
        String str4;
        try {
            String string = context.getCacheDir().toString();
            if (string.endsWith(CookieSpec.PATH_DELIM)) {
                string = string.substring(0, string.length() - 2);
            }
            int iLastIndexOf = string.lastIndexOf(47);
            if (iLastIndexOf != -1) {
                str2 = string.substring(0, iLastIndexOf) + "/lib/";
            } else {
                str2 = "";
            }
        } catch (Exception e) {
            str2 = "/data/data/" + context.getPackageName() + "/lib/";
        }
        if (str2.length() != 0) {
            if (new File(str2 + str).exists()) {
                try {
                    System.load(str2 + str);
                    z = true;
                } catch (UnsatisfiedLinkError e2) {
                    z = false;
                }
            } else {
                z = false;
            }
            if (z || str.endsWith(".so")) {
                str3 = str;
            } else {
                str3 = str + ".so";
                if (new File(str2 + str3).exists()) {
                    try {
                        System.load(str2 + str3);
                        z = true;
                    } catch (UnsatisfiedLinkError e3) {
                    }
                }
            }
            if (z || str3.startsWith("lib")) {
                z2 = z;
                str4 = str3;
            } else {
                str3 = "lib" + str3;
                if (new File(str2 + str3).exists()) {
                    try {
                        System.load(str2 + str3);
                        z2 = true;
                        str4 = str3;
                    } catch (UnsatisfiedLinkError e4) {
                        z2 = z;
                        str4 = str3;
                    }
                } else {
                    z2 = z;
                    str4 = str3;
                }
            }
            if (!z2) {
                try {
                    System.loadLibrary(str);
                    z2 = true;
                } catch (UnsatisfiedLinkError e5) {
                }
            }
            if (!z2) {
                try {
                    String str5 = "/data/data/" + context.getPackageName() + "/app_libs/" + str4;
                    if (new File(str5).exists()) {
                        try {
                            System.load(str5);
                        } catch (UnsatisfiedLinkError e6) {
                            return false;
                        }
                    }
                } catch (UnsatisfiedLinkError e7) {
                    return false;
                }
            }
        } else {
            try {
                System.loadLibrary(str);
            } catch (UnsatisfiedLinkError e8) {
                return false;
            }
        }
        return true;
    }
}
