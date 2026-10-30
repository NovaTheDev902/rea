package com.lenovo.lps.sus.p003a.p004a.p005a;

import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;

/* JADX INFO: renamed from: com.lenovo.lps.sus.a.a.a.c */
/* JADX INFO: loaded from: classes.dex */
public class C0080c {

    /* JADX INFO: renamed from: a */
    private static C0081d f1215a = new C0081d();

    /* JADX INFO: renamed from: a */
    public static String m253a(String str) {
        C0098i.m409a(C0092c.f1339b, "downloadurl=" + str);
        if (str.indexOf(C0092c.f1359v) > 0) {
            str = m254b(str.replace(C0092c.f1360w, ""));
        }
        C0098i.m409a(C0092c.f1339b, "HDSdownloadurl=" + str);
        return str;
    }

    /* JADX INFO: renamed from: b */
    private static String m254b(String str) throws Exception {
        StringBuilder sb = new StringBuilder();
        sb.append(C0092c.m392s());
        sb.append(String.format("/*%s*", f1215a.mo250a()));
        try {
            sb.append(URLEncoder.encode(f1215a.mo251a(String.format("%s|%d|%d|%d", str, -1L, 0, 0)), InterfaceC0079b.f1213a));
            return sb.toString();
        } catch (UnsupportedEncodingException e) {
            throw new Exception("don't support charset UTF-8!");
        }
    }
}
