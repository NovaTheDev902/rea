package com.lenovo.safecenter.utils;

import android.util.Patterns;
import com.tencent.tmsecure.module.permission.PermissionControlConfig;
import java.util.regex.Matcher;

/* JADX INFO: loaded from: classes.dex */
public class Untils {
    public static final char PAUSE = ',';
    public static final int TOA_International = 145;
    public static final int TOA_Unknown = 129;
    public static final char WAIT = ';';
    public static final char WILD = 'N';

    /* JADX INFO: renamed from: a */
    private static final boolean[] f5809a = {true, true, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, true, false, true, true, true, true, true, false, true, false, false, true, true, false, false, true, true, true, true, true, true, true, false, true, true, true, true, true, true, true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true, false, true, false, false, true, true, true, true, true, true, true, false, false, true, false};

    /* JADX INFO: renamed from: b */
    private static final int f5810b = f5809a.length;

    public static boolean compare(String a, String b, boolean useStrictComparation) {
        return useStrictComparation ? compareStrictly(a, b) : compareLoosely(a, b);
    }

    public static boolean compareStrictly(String a, String b) {
        return compareStrictly(a, b, true);
    }

    public static boolean compareStrictly(String a, String b, boolean acceptInvalidCCCPrefix) {
        if (a == null || b == null) {
            return false;
        }
        if (a.length() == 0 && b.length() == 0) {
            return false;
        }
        int forwardIndexA = 0;
        int forwardIndexB = 0;
        C1043a cccA = m2438a(a, acceptInvalidCCCPrefix);
        C1043a cccB = m2438a(b, acceptInvalidCCCPrefix);
        boolean bothHasCountryCallingCode = false;
        boolean okToIgnorePrefix = true;
        boolean trunkPrefixIsOmittedA = false;
        boolean trunkPrefixIsOmittedB = false;
        if (cccA != null && cccB != null) {
            if (cccA.f5811a != cccB.f5811a) {
                return false;
            }
            okToIgnorePrefix = false;
            bothHasCountryCallingCode = true;
            forwardIndexA = cccA.f5812b;
            forwardIndexB = cccB.f5812b;
        } else if (cccA == null && cccB == null) {
            okToIgnorePrefix = false;
        } else {
            if (cccA != null) {
                forwardIndexA = cccA.f5812b;
            } else {
                int tmp = m2437a(b);
                if (tmp >= 0) {
                    forwardIndexA = tmp;
                    trunkPrefixIsOmittedA = true;
                }
            }
            if (cccB != null) {
                forwardIndexB = cccB.f5812b;
            } else {
                int tmp2 = m2437a(b);
                if (tmp2 >= 0) {
                    forwardIndexB = tmp2;
                    trunkPrefixIsOmittedB = true;
                }
            }
        }
        int backwardIndexA = a.length() - 1;
        int backwardIndexB = b.length() - 1;
        while (backwardIndexA >= forwardIndexA && backwardIndexB >= forwardIndexB) {
            boolean skip_compare = false;
            char chA = a.charAt(backwardIndexA);
            char chB = b.charAt(backwardIndexB);
            if (m2439a(chA)) {
                backwardIndexA--;
                skip_compare = true;
            }
            if (m2439a(chB)) {
                backwardIndexB--;
                skip_compare = true;
            }
            if (!skip_compare) {
                if (chA != chB) {
                    return false;
                }
                backwardIndexA--;
                backwardIndexB--;
            }
        }
        if (okToIgnorePrefix) {
            if ((trunkPrefixIsOmittedA && forwardIndexA <= backwardIndexA) || !m2441a(a, forwardIndexA, backwardIndexA)) {
                if (acceptInvalidCCCPrefix) {
                    return compare(a, b, false);
                }
                return false;
            }
            if ((trunkPrefixIsOmittedB && forwardIndexB <= backwardIndexB) || !m2441a(b, forwardIndexA, backwardIndexB)) {
                if (acceptInvalidCCCPrefix) {
                    return compare(a, b, false);
                }
                return false;
            }
        } else {
            boolean maybeNamp = !bothHasCountryCallingCode;
            while (backwardIndexA >= forwardIndexA) {
                char chA2 = a.charAt(backwardIndexA);
                if (isDialable(chA2)) {
                    if (maybeNamp && m2442b(chA2) == 1) {
                        maybeNamp = false;
                    } else {
                        return false;
                    }
                }
                backwardIndexA--;
            }
            while (backwardIndexB >= forwardIndexB) {
                char chB2 = b.charAt(backwardIndexB);
                if (isDialable(chB2)) {
                    if (maybeNamp && m2442b(chB2) == 1) {
                        maybeNamp = false;
                    } else {
                        return false;
                    }
                }
                backwardIndexB--;
            }
        }
        return true;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.utils.Untils$a */
    private static class C1043a {

        /* JADX INFO: renamed from: a */
        public final int f5811a;

        /* JADX INFO: renamed from: b */
        public final int f5812b;

        public C1043a(int countryCode, int newIndex) {
            this.f5811a = countryCode;
            this.f5812b = newIndex;
        }
    }

    /* JADX INFO: renamed from: a */
    private static C1043a m2438a(String str, boolean acceptThailandCase) {
        int state = 0;
        int ccc = 0;
        int length = str.length();
        for (int i = 0; i < length; i++) {
            char ch = str.charAt(i);
            switch (state) {
                case 0:
                    if (ch == '+') {
                        state = 1;
                    } else if (ch == '0') {
                        state = 2;
                    } else if (ch == '1') {
                        if (!acceptThailandCase) {
                            return null;
                        }
                        state = 8;
                    } else {
                        if (isDialable(ch)) {
                            return null;
                        }
                    }
                    break;
                case 1:
                case 3:
                case 5:
                case 6:
                case 7:
                    int ret = m2442b(ch);
                    if (ret > 0) {
                        ccc = (ccc * 10) + ret;
                        if (ccc < 100) {
                            if (!(ccc > 0 && ccc < f5810b && f5809a[ccc])) {
                                if (state == 1 || state == 3 || state == 5) {
                                    state = 6;
                                } else {
                                    state++;
                                }
                                break;
                            }
                        }
                        return new C1043a(ccc, i + 1);
                    }
                    if (isDialable(ch)) {
                        return null;
                    }
                    break;
                    break;
                case 2:
                    if (ch == '0') {
                        state = 3;
                    } else if (ch == '1') {
                        state = 4;
                    } else {
                        if (isDialable(ch)) {
                            return null;
                        }
                    }
                    break;
                case 4:
                    if (ch == '1') {
                        state = 5;
                    } else {
                        if (isDialable(ch)) {
                            return null;
                        }
                    }
                    break;
                case 8:
                    if (ch == '6') {
                        state = 9;
                    } else {
                        if (isDialable(ch)) {
                            return null;
                        }
                    }
                    break;
                case 9:
                    if (ch == '6') {
                        return new C1043a(66, i + 1);
                    }
                    return null;
                default:
                    return null;
            }
        }
        return null;
    }

    /* JADX INFO: renamed from: a */
    private static int m2437a(String str) {
        int length = str.length();
        for (int i = 0; i < length; i++) {
            char ch = str.charAt(i);
            if (m2442b(ch) >= 0) {
                return i + 1;
            }
            if (isDialable(ch)) {
                return -1;
            }
        }
        return -1;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2439a(char ch) {
        return !isDialable(ch) && ('a' > ch || ch > 'z') && ('A' > ch || ch > 'Z');
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2441a(String str, int forwardIndex, int backwardIndex) {
        boolean trunk_prefix_was_read = false;
        while (backwardIndex >= forwardIndex) {
            if (m2442b(str.charAt(backwardIndex)) >= 0) {
                if (trunk_prefix_was_read) {
                    return false;
                }
                trunk_prefix_was_read = true;
            } else if (isDialable(str.charAt(backwardIndex))) {
                return false;
            }
            backwardIndex--;
        }
        return true;
    }

    /* JADX INFO: renamed from: b */
    private static int m2442b(char ch) {
        if ('0' > ch || ch > '9') {
            return -1;
        }
        return ch - '0';
    }

    public static boolean compareLoosely(String a, String b) {
        int numNonDialableCharsInA = 0;
        int numNonDialableCharsInB = 0;
        if (a == null || b == null || a.length() == 0 || b.length() == 0) {
            return false;
        }
        int ia = m2443b(a);
        int ib = m2443b(b);
        int matched = 0;
        while (ia >= 0 && ib >= 0) {
            boolean skipCmp = false;
            char ca = a.charAt(ia);
            if (!isDialable(ca)) {
                ia--;
                skipCmp = true;
                numNonDialableCharsInA++;
            }
            char cb = b.charAt(ib);
            if (!isDialable(cb)) {
                ib--;
                skipCmp = true;
                numNonDialableCharsInB++;
            }
            if (!skipCmp) {
                if (cb != ca && ca != 'N' && cb != 'N') {
                    break;
                }
                ia--;
                ib--;
                matched++;
            }
        }
        if (matched < 7) {
            int effectiveALen = a.length() - numNonDialableCharsInA;
            int effectiveBLen = b.length() - numNonDialableCharsInB;
            if (effectiveALen == effectiveBLen && effectiveALen == matched) {
                return true;
            }
            return false;
        }
        if (matched >= 7 && (ia < 0 || ib < 0)) {
            return true;
        }
        if (m2444b(a, ia + 1) && m2444b(b, ib + 1)) {
            return true;
        }
        if (m2440a(a, ia + 1) && m2445c(b, ib + 1)) {
            return true;
        }
        if (m2440a(b, ib + 1) && m2445c(a, ia + 1)) {
            return true;
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2440a(String a, int len) {
        boolean found = false;
        for (int i = 0; i < len; i++) {
            char c = a.charAt(i);
            if (c == '0' && !found) {
                found = true;
            } else if (isNonSeparator(c)) {
                return false;
            }
        }
        return found;
    }

    /* JADX INFO: renamed from: b */
    private static int m2443b(String a) {
        int trimIndex;
        int origLength = a.length();
        int pIndex = a.indexOf(44);
        int wIndex = a.indexOf(59);
        if (pIndex >= 0 && wIndex >= 0) {
            if (pIndex >= wIndex) {
                pIndex = wIndex;
            }
            trimIndex = pIndex;
        } else if (pIndex >= 0) {
            trimIndex = pIndex;
        } else {
            trimIndex = wIndex >= 0 ? wIndex : -1;
        }
        if (trimIndex < 0) {
            return origLength - 1;
        }
        return trimIndex - 1;
    }

    public static final boolean is12Key(char c) {
        return (c >= '0' && c <= '9') || c == '*' || c == '#';
    }

    public static final boolean isDialable(char c) {
        return (c >= '0' && c <= '9') || c == '*' || c == '#' || c == '+' || c == 'N';
    }

    public static final boolean isReallyDialable(char c) {
        return (c >= '0' && c <= '9') || c == '*' || c == '#' || c == '+';
    }

    public static final boolean isNonSeparator(char c) {
        return (c >= '0' && c <= '9') || c == '*' || c == '#' || c == '+' || c == 'N' || c == ';' || c == ',';
    }

    /* JADX INFO: renamed from: b */
    private static boolean m2444b(String a, int len) {
        int state = 0;
        for (int i = 0; i < len; i++) {
            char c = a.charAt(i);
            switch (state) {
                case 0:
                    if (c == '+') {
                        state = 1;
                    } else if (c == '0') {
                        state = 2;
                    } else {
                        if (isNonSeparator(c)) {
                            return false;
                        }
                    }
                    break;
                case 1:
                case 3:
                default:
                    if (isNonSeparator(c)) {
                        return false;
                    }
                    break;
                    break;
                case 2:
                    if (c == '0') {
                        state = 3;
                    } else if (c == '1') {
                        state = 4;
                    } else {
                        if (isNonSeparator(c)) {
                            return false;
                        }
                    }
                    break;
                case 4:
                    if (c == '1') {
                        state = 5;
                    } else {
                        if (isNonSeparator(c)) {
                            return false;
                        }
                    }
                    break;
            }
        }
        return state == 1 || state == 3 || state == 5;
    }

    /* JADX INFO: renamed from: c */
    private static boolean m2445c(String a, int len) {
        int state = 0;
        for (int i = 0; i < len; i++) {
            char c = a.charAt(i);
            switch (state) {
                case 0:
                    if (c == '+') {
                        state = 1;
                    } else if (c == '0') {
                        state = 2;
                    } else {
                        if (isNonSeparator(c)) {
                            return false;
                        }
                    }
                    break;
                case 1:
                case 3:
                case 5:
                    if (isISODigit(c)) {
                        state = 6;
                    } else {
                        if (isNonSeparator(c)) {
                            return false;
                        }
                    }
                    break;
                case 2:
                    if (c == '0') {
                        state = 3;
                    } else if (c == '1') {
                        state = 4;
                    } else {
                        if (isNonSeparator(c)) {
                            return false;
                        }
                    }
                    break;
                case 4:
                    if (c == '1') {
                        state = 5;
                    } else {
                        if (isNonSeparator(c)) {
                            return false;
                        }
                    }
                    break;
                case 6:
                case 7:
                    if (isISODigit(c)) {
                        state++;
                    } else {
                        if (isNonSeparator(c)) {
                            return false;
                        }
                    }
                    break;
                default:
                    if (isNonSeparator(c)) {
                        return false;
                    }
                    break;
                    break;
            }
        }
        return state == 6 || state == 7 || state == 8;
    }

    public static boolean isISODigit(char c) {
        return c >= '0' && c <= '9';
    }

    public static boolean isPhoneNUmber(String number) {
        Matcher match = Patterns.PHONE.matcher(number);
        boolean bool = match.matches();
        return bool;
    }

    public static String jiaMi(String s, String key) {
        String str = "";
        if (key.length() != 0) {
            if (s != null) {
                int i = 0;
                int j = 0;
                while (i < s.length()) {
                    if (j > key.length() - 1) {
                        j %= key.length();
                    }
                    int ch = s.codePointAt(i) + key.codePointAt(j);
                    if (ch > 65535) {
                        ch %= PermissionControlConfig.PERMISSION_MODE_NULL;
                    }
                    str = str + ((char) ch);
                    i++;
                    j++;
                }
            }
            return str;
        }
        return s;
    }

    public static String jieMi(String s, String key) {
        String str = "";
        if (key.length() != 0) {
            if (!s.equals(key)) {
                int i = 0;
                int j = 0;
                while (i < s.length()) {
                    if (j > key.length() - 1) {
                        j %= key.length();
                    }
                    int ch = (s.codePointAt(i) + PermissionControlConfig.PERMISSION_MODE_NULL) - key.codePointAt(j);
                    if (ch > 65535) {
                        ch %= PermissionControlConfig.PERMISSION_MODE_NULL;
                    }
                    str = str + ((char) ch);
                    i++;
                    j++;
                }
            }
            return str;
        }
        return s;
    }
}
