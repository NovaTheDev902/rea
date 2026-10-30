package org.apache.commons.httpclient.util;

import java.util.ArrayList;
import java.util.List;
import org.apache.commons.httpclient.NameValuePair;

/* JADX INFO: loaded from: classes.dex */
public class ParameterParser {

    /* JADX INFO: renamed from: a */
    private char[] f6785a = null;

    /* JADX INFO: renamed from: b */
    private int f6786b = 0;

    /* JADX INFO: renamed from: c */
    private int f6787c = 0;

    /* JADX INFO: renamed from: d */
    private int f6788d = 0;

    /* JADX INFO: renamed from: e */
    private int f6789e = 0;

    /* JADX INFO: renamed from: a */
    private boolean m2853a() {
        return this.f6786b < this.f6787c;
    }

    /* JADX INFO: renamed from: a */
    private String m2851a(boolean quoted) {
        while (this.f6788d < this.f6789e && Character.isWhitespace(this.f6785a[this.f6788d])) {
            this.f6788d++;
        }
        while (this.f6789e > this.f6788d && Character.isWhitespace(this.f6785a[this.f6789e - 1])) {
            this.f6789e--;
        }
        if (quoted && this.f6789e - this.f6788d >= 2 && this.f6785a[this.f6788d] == '\"' && this.f6785a[this.f6789e - 1] == '\"') {
            this.f6788d++;
            this.f6789e--;
        }
        if (this.f6789e < this.f6788d) {
            return null;
        }
        String result = new String(this.f6785a, this.f6788d, this.f6789e - this.f6788d);
        return result;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2854a(char ch, char[] charray) {
        for (char c : charray) {
            if (ch == c) {
                return true;
            }
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    private String m2852a(char[] terminators) {
        this.f6788d = this.f6786b;
        this.f6789e = this.f6786b;
        while (m2853a()) {
            char ch = this.f6785a[this.f6786b];
            if (m2854a(ch, terminators)) {
                break;
            }
            this.f6789e++;
            this.f6786b++;
        }
        return m2851a(false);
    }

    /* JADX INFO: renamed from: b */
    private String m2855b(char[] terminators) {
        this.f6788d = this.f6786b;
        this.f6789e = this.f6786b;
        boolean quoted = false;
        boolean charEscaped = false;
        while (m2853a()) {
            char ch = this.f6785a[this.f6786b];
            if (!quoted && m2854a(ch, terminators)) {
                break;
            }
            if (!charEscaped && ch == '\"') {
                quoted = !quoted;
            }
            charEscaped = !charEscaped && ch == '\\';
            this.f6789e++;
            this.f6786b++;
        }
        return m2851a(true);
    }

    public List parse(String str, char separator) {
        return str == null ? new ArrayList() : parse(str.toCharArray(), separator);
    }

    public List parse(char[] chars, char separator) {
        return chars == null ? new ArrayList() : parse(chars, 0, chars.length, separator);
    }

    public List parse(char[] chars, int offset, int length, char separator) {
        if (chars == null) {
            return new ArrayList();
        }
        List params = new ArrayList();
        this.f6785a = chars;
        this.f6786b = offset;
        this.f6787c = length;
        while (m2853a()) {
            String paramName = m2852a(new char[]{'=', separator});
            String paramValue = null;
            if (m2853a() && chars[this.f6786b] == '=') {
                this.f6786b++;
                paramValue = m2855b(new char[]{separator});
            }
            if (m2853a() && chars[this.f6786b] == separator) {
                this.f6786b++;
            }
            if (paramName != null && (!paramName.equals("") || paramValue != null)) {
                params.add(new NameValuePair(paramName, paramValue));
            }
        }
        return params;
    }
}
