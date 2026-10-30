package com.lenovo.lps.reaper.sdk.api;

import com.lenovo.lps.reaper.sdk.util.AnalyticsTrackerUtils;
import com.lenovo.lps.reaper.sdk.util.Messages;
import com.lenovo.lps.reaper.sdk.util.TLog;

/* JADX INFO: loaded from: classes.dex */
public final class CustomParameter {
    public static final int ACTIVITY_SCOPE = 3;
    public static final int MAX_INDEX = 5;
    public static final int MAX_LENGTH = 256;
    public static final int SESSION_SCOPE = 2;
    public static final int VISITOR_SCOPE = 1;

    /* JADX INFO: renamed from: a */
    private int f1104a;

    /* JADX INFO: renamed from: b */
    private String f1105b;

    /* JADX INFO: renamed from: c */
    private String f1106c;

    /* JADX INFO: renamed from: d */
    private int f1107d;

    public CustomParameter() {
        this(3);
    }

    public CustomParameter(int scope) {
        this.f1107d = scope;
    }

    public CustomParameter(int index, String name, String value, int scope) {
        this.f1104a = index;
        this.f1105b = name;
        this.f1106c = value;
        this.f1107d = scope;
    }

    public final void reset() {
        this.f1104a = 0;
    }

    public final boolean isValid() {
        return this.f1104a > 0 && this.f1104a <= 5;
    }

    public static boolean check(int index, String name, String value) {
        if (index < 1 || index > 5) {
            TLog.m245w("CustomParameter", String.format(Messages.CUSTOM_PARAMETER_INDEX_MESSAGE, 0, 6));
            return false;
        }
        if (name == null || name.length() == 0) {
            TLog.m245w("CustomParameter", Messages.CUSTOM_PARAMETER_NAME_MESSAGE);
            return false;
        }
        if (value != null && value.length() != 0) {
            return true;
        }
        TLog.m245w("CustomParameter", Messages.CUSTOM_PARAMETER_VALUE_MESSAGE);
        return false;
    }

    public final int getIndex() {
        return this.f1104a;
    }

    public final String getName() {
        return this.f1105b;
    }

    public final String getValue() {
        return this.f1106c;
    }

    public final int getScope() {
        return this.f1107d;
    }

    public final void setIndex(int index) {
        this.f1104a = index;
    }

    public final void setName(String name) {
        this.f1105b = name;
    }

    public final void setValue(String value) {
        this.f1106c = value;
    }

    public final String toString() {
        if (!isValid()) {
            return "";
        }
        StringBuilder sb = new StringBuilder(200);
        sb.append("(");
        sb.append(this.f1104a);
        sb.append("!");
        sb.append(AnalyticsTrackerUtils.encode(this.f1105b));
        sb.append("!");
        sb.append(AnalyticsTrackerUtils.encode(this.f1106c));
        sb.append("!");
        sb.append(this.f1107d);
        sb.append(")");
        return sb.toString();
    }
}
