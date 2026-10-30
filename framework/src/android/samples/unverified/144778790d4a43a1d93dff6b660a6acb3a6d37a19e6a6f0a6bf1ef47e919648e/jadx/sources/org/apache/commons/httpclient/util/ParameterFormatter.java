package org.apache.commons.httpclient.util;

import com.lenovo.safecenter.utils.Untils;
import org.apache.commons.httpclient.NameValuePair;

/* JADX INFO: loaded from: classes.dex */
public class ParameterFormatter {

    /* JADX INFO: renamed from: a */
    private static final char[] f6782a = {'(', ')', '<', '>', '@', Untils.PAUSE, Untils.WAIT, ':', '\\', '\"', '/', '[', ']', '?', '=', '{', '}', ' ', '\t'};

    /* JADX INFO: renamed from: b */
    private static final char[] f6783b = {'\"', '\\'};

    /* JADX INFO: renamed from: c */
    private boolean f6784c = true;

    /* JADX INFO: renamed from: a */
    private static boolean m2849a(char[] chars, char ch) {
        for (char c : chars) {
            if (ch == c) {
                return true;
            }
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2848a(char ch) {
        return m2849a(f6783b, ch);
    }

    /* JADX INFO: renamed from: b */
    private static boolean m2850b(char ch) {
        return m2849a(f6782a, ch);
    }

    public boolean isAlwaysUseQuotes() {
        return this.f6784c;
    }

    public void setAlwaysUseQuotes(boolean alwaysUseQuotes) {
        this.f6784c = alwaysUseQuotes;
    }

    public static void formatValue(StringBuffer buffer, String value, boolean alwaysUseQuotes) {
        if (buffer == null) {
            throw new IllegalArgumentException("String buffer may not be null");
        }
        if (value == null) {
            throw new IllegalArgumentException("Value buffer may not be null");
        }
        if (alwaysUseQuotes) {
            buffer.append('\"');
            for (int i = 0; i < value.length(); i++) {
                char ch = value.charAt(i);
                if (m2848a(ch)) {
                    buffer.append('\\');
                }
                buffer.append(ch);
            }
            buffer.append('\"');
            return;
        }
        int offset = buffer.length();
        boolean unsafe = false;
        for (int i2 = 0; i2 < value.length(); i2++) {
            char ch2 = value.charAt(i2);
            if (m2850b(ch2)) {
                unsafe = true;
            }
            if (m2848a(ch2)) {
                buffer.append('\\');
            }
            buffer.append(ch2);
        }
        if (unsafe) {
            buffer.insert(offset, '\"');
            buffer.append('\"');
        }
    }

    public void format(StringBuffer buffer, NameValuePair param) {
        if (buffer == null) {
            throw new IllegalArgumentException("String buffer may not be null");
        }
        if (param == null) {
            throw new IllegalArgumentException("Parameter may not be null");
        }
        buffer.append(param.getName());
        String value = param.getValue();
        if (value != null) {
            buffer.append("=");
            formatValue(buffer, value, this.f6784c);
        }
    }

    public String format(NameValuePair param) {
        StringBuffer buffer = new StringBuffer();
        format(buffer, param);
        return buffer.toString();
    }
}
