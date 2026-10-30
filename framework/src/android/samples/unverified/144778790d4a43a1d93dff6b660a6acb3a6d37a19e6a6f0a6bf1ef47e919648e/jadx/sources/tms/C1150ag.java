package tms;

import com.lenovo.safecenter.utils.Untils;
import com.tencent.tmsecure.module.phoneservice.IpDialHeaders;

/* JADX INFO: renamed from: tms.ag */
/* JADX INFO: loaded from: classes.dex */
public final class C1150ag {
    /* JADX INFO: renamed from: a */
    public static boolean m2891a(String str) {
        if (str == null || str.trim().length() < 3) {
            return false;
        }
        for (char c : new char[]{'/', '#', Untils.PAUSE, Untils.WAIT, '.', '(', ')', Untils.WILD, '*'}) {
            if (str.indexOf(c) >= 0) {
                return false;
            }
        }
        return true;
    }

    /* JADX INFO: renamed from: a */
    public static boolean m2892a(String str, String str2) {
        if (str == null || str2 == null) {
            if (str == null) {
                str = "";
            }
            if (str2 == null) {
                str2 = "";
            }
            return str.compareTo(str2) == 0;
        }
        String strM2895c = m2895c(str);
        String strM2895c2 = m2895c(str2);
        if (strM2895c.length() >= 8 && strM2895c2.length() >= 8) {
            return strM2895c.substring(strM2895c.length() + (-8)).compareTo(strM2895c2.substring(strM2895c2.length() + (-8))) == 0;
        }
        if (strM2895c.length() >= 7) {
            strM2895c = strM2895c.substring(strM2895c.length() - 7);
        }
        if (strM2895c2.length() >= 7) {
            strM2895c2 = strM2895c2.substring(strM2895c2.length() - 7);
        }
        return strM2895c.compareTo(strM2895c2) == 0;
    }

    /* JADX INFO: renamed from: a */
    public static String[] m2893a(int i) {
        String[] strArr = new String[2];
        switch (i) {
            case 0:
                strArr[0] = IpDialHeaders.IP_HEADER_12593;
                strArr[1] = IpDialHeaders.IP_HEADER_17951;
                return strArr;
            case 1:
                strArr[0] = IpDialHeaders.IP_HEADER_10193;
                strArr[1] = IpDialHeaders.IP_HEADER_17911;
                return strArr;
            case 2:
                strArr[0] = IpDialHeaders.IP_HEADER_17909;
                strArr[1] = IpDialHeaders.IP_HEADER_17901;
                return strArr;
            default:
                strArr[0] = IpDialHeaders.IP_HEADER_12593;
                strArr[1] = IpDialHeaders.IP_HEADER_17951;
                return strArr;
        }
    }

    /* JADX INFO: renamed from: b */
    public static int m2894b(String str) {
        String strSubstring;
        String[] strArr = {"+86", IpDialHeaders.IP_HEADER_12593, IpDialHeaders.IP_HEADER_17909, IpDialHeaders.IP_HEADER_17951, IpDialHeaders.IP_HEADER_17911, IpDialHeaders.IP_HEADER_10193, IpDialHeaders.IP_HEADER_12583, IpDialHeaders.IP_HEADER_12520, IpDialHeaders.IP_HEADER_96688};
        String strReplaceAll = str.replaceAll("[ -]", "");
        int i = 0;
        while (true) {
            if (i >= strArr.length) {
                strSubstring = strReplaceAll;
                break;
            }
            if (strReplaceAll.startsWith(strArr[i])) {
                strSubstring = strReplaceAll.substring(strArr[i].length());
                break;
            }
            i++;
        }
        if (strSubstring.length() > 8) {
            strSubstring = strSubstring.substring(strSubstring.length() - 8);
        }
        int iCharAt = -1;
        int length = strSubstring.length();
        for (int i2 = 0; i2 < length; i2++) {
            iCharAt = (iCharAt << 4) | ((byte) strSubstring.charAt(i2));
        }
        return iCharAt;
    }

    /* JADX INFO: renamed from: c */
    private static String m2895c(String str) {
        if (str == null) {
            return null;
        }
        String strReplaceAll = str.replaceAll("[ -]", "");
        for (String str2 : new String[]{"+86", "0086", IpDialHeaders.IP_HEADER_12593, IpDialHeaders.IP_HEADER_17901, IpDialHeaders.IP_HEADER_17909, IpDialHeaders.IP_HEADER_17951, IpDialHeaders.IP_HEADER_17911, IpDialHeaders.IP_HEADER_17910, IpDialHeaders.IP_HEADER_10193, IpDialHeaders.IP_HEADER_12583, IpDialHeaders.IP_HEADER_12520, IpDialHeaders.IP_HEADER_96688}) {
            if (strReplaceAll.startsWith(str2)) {
                return strReplaceAll.substring(str2.length());
            }
        }
        return strReplaceAll;
    }
}
