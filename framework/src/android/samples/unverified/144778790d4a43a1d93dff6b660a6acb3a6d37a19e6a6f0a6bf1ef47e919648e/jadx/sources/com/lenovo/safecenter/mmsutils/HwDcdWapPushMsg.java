package com.lenovo.safecenter.mmsutils;

import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class HwDcdWapPushMsg {
    public static final String ERR_TAG = "HwDcdWapPushMsg.java";

    /* JADX INFO: renamed from: a */
    private HashMap<Integer, String> f4298a = new HashMap<>();
    public static int WAP_PUSH_TYPE_SI = 0;
    public static int WAP_PUSH_TYPE_SL = 1;
    public static int WAP_PUSH_PROJECTION_PRIOR = 0;
    public static int WAP_PUSH_PROJECTION_HREF = 1;
    public static int WAP_PUSH_PROJECTION_SI_EXPIRED = 2;
    public static int WAP_PUSH_PROJECTION_SI_CREATED = 3;
    public static int WAP_PUSH_PROJECTION_SI_ID = 4;
    public static int WAP_PUSH_PRIO_NONE = 5;
    public static int WAP_PUSH_PRIO_LOW = 6;
    public static int WAP_PUSH_PRIO_MEDIUM = 7;
    public static int WAP_PUSH_PRIO_HIGH = 8;
    public static int WAP_PUSH_PRIO_DELETE = 9;
    public static int WAP_PUSH_PRIO_CACHE = 10;
    public static int WAP_PUSH_PROJECTION_SI_TEXT = 100;

    public HwDcdWapPushMsg(int type) {
    }

    public void setAttributeValue(int attr, String attrValue) {
        this.f4298a.put(Integer.valueOf(attr), attrValue);
    }

    public String getAttributeValueString(int attr) {
        if (this.f4298a.containsKey(Integer.valueOf(attr))) {
            return this.f4298a.get(Integer.valueOf(attr));
        }
        return null;
    }
}
