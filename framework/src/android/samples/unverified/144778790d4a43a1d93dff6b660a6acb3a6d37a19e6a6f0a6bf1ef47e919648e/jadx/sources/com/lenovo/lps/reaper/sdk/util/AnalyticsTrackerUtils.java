package com.lenovo.lps.reaper.sdk.util;

import com.lenovo.lps.reaper.sdk.AnalyticsTrackerBuilder;
import com.lenovo.lps.reaper.sdk.api.CustomParameter;
import com.lenovo.lps.reaper.sdk.api.Event;
import com.lenovo.lps.reaper.sdk.config.Configuration;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.util.Stack;

/* JADX INFO: loaded from: classes.dex */
public final class AnalyticsTrackerUtils {

    /* JADX INFO: renamed from: b */
    private static boolean f1186b;

    /* JADX INFO: renamed from: a */
    private static final String f1185a = AnalyticsTrackerUtils.class.getName();

    /* JADX INFO: renamed from: c */
    private static ThreadLocal<Stack<C0076a>> f1187c = new ThreadLocal<>();

    public static AnalyticsTrackerBuilder getAnalyticsTrackerBuilder() {
        Class<?> clazz = Configuration.getAnalyticsTrackerBuilderClass();
        try {
            return (AnalyticsTrackerBuilder) clazz.newInstance();
        } catch (Exception e) {
            TLog.m241e(f1185a, "Error when initialize AnalyticsTrackerBuilder. " + e.getMessage());
            return null;
        }
    }

    public static String getCustomVariableParams(Event event) {
        StringBuilder sb = new StringBuilder(64);
        CustomParameter[] customParameters = event.getCustomParameters();
        if (customParameters == null) {
            return "";
        }
        for (CustomParameter customParameter : customParameters) {
            sb.append(customParameter);
        }
        return sb.toString();
    }

    public static String encode(String str) {
        try {
            return URLEncoder.encode(str, InterfaceC0079b.f1213a).replace("+", "%20");
        } catch (UnsupportedEncodingException e) {
            TLog.m241e(f1185a, "exception when encode, str is: " + str);
            return str;
        }
    }

    public static String replaceInvalidCharacter(String str) {
        try {
            return str.replaceAll("[^0-9a-zA-Z /():,;*+=_.-]", "?");
        } catch (Exception e) {
            TLog.m241e(f1185a, "exception when replace, str is: " + str);
            return str;
        }
    }

    public static boolean isTestMode() {
        return f1186b;
    }

    public static void setTestMode(boolean testMode) {
        f1186b = testMode;
    }

    public static void push(String name) {
        if (f1186b) {
            Stack<C0076a> timeStack = f1187c.get();
            if (timeStack == null) {
                timeStack = new Stack<>();
                f1187c.set(timeStack);
            }
            timeStack.push(new C0076a(name, System.currentTimeMillis()));
        }
    }

    public static void pop() {
        if (f1186b) {
            Stack<C0076a> timeStack = f1187c.get();
            C0076a element = timeStack.pop();
            TLog.m243i("TimeTracker", element.f1188a + " use " + (System.currentTimeMillis() - element.f1189b) + "ms.");
        }
    }

    /* JADX INFO: renamed from: com.lenovo.lps.reaper.sdk.util.AnalyticsTrackerUtils$a */
    static class C0076a {

        /* JADX INFO: renamed from: a */
        private String f1188a;

        /* JADX INFO: renamed from: b */
        private long f1189b;

        public C0076a(String name, long start) {
            this.f1188a = name;
            this.f1189b = start;
        }
    }
}
