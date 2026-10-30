package com.tencent.tmsecure.module.aresengine;

import java.util.HashMap;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public final class FilterConfig {
    public static final int STATE_ACCEPTABLE = 0;
    public static final int STATE_DISABLE = 3;
    public static final int STATE_EMTPY = 4;
    public static final int STATE_ENABLE = 2;
    public static final int STATE_REJECTABLE = 1;

    /* JADX INFO: renamed from: a */
    private HashMap<Integer, Integer> f6089a;

    public FilterConfig() {
        this(null);
    }

    public FilterConfig(String str) {
        this.f6089a = new HashMap<>();
        if (str != null) {
            String[] strArrSplit = str.trim().split(",");
            for (int i = 0; i < strArrSplit.length; i += 2) {
                set(Integer.parseInt(strArrSplit[i]), Integer.parseInt(strArrSplit[i + 1]));
            }
        }
    }

    public final String dump() {
        StringBuffer stringBuffer = new StringBuffer();
        for (Map.Entry<Integer, Integer> entry : this.f6089a.entrySet()) {
            stringBuffer.append((entry.getKey() + "," + entry.getValue()) + ",");
        }
        if (stringBuffer.length() > 0) {
            stringBuffer.deleteCharAt(stringBuffer.length() - 1);
        }
        return stringBuffer.toString();
    }

    public final int get(int i) {
        Integer num = this.f6089a.get(Integer.valueOf(i));
        if (num != null) {
            return num.intValue();
        }
        return 4;
    }

    public final void reset() {
        this.f6089a.clear();
    }

    public final void set(int i, int i2) {
        if (i2 != 0 && i2 != 1 && i2 != 2 && i2 != 3 && i2 != 4) {
            throw new IllegalStateException("the state " + i2 + " is not define.");
        }
        this.f6089a.put(Integer.valueOf(i), Integer.valueOf(i2));
    }
}
