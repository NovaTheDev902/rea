package com.lenovo.lps.reaper.sdk.sdac;

import android.content.Context;
import android.telephony.CellLocation;
import android.telephony.cdma.CdmaCellLocation;
import android.telephony.gsm.GsmCellLocation;

/* JADX INFO: loaded from: classes.dex */
public class MultiSIMDeviceInfo {
    public static final int GEMINI_SIM_1 = 0;
    public static final int GEMINI_SIM_2 = 1;

    /* JADX INFO: renamed from: a */
    private static MultiSIMDeviceInfo f1150a = null;

    /* JADX INFO: renamed from: b */
    private Object f1151b;

    private MultiSIMDeviceInfo(Context context) {
        this.f1151b = ReflectUtils.invokeClass("android.provider.MultiSIMUtils", "getDefault", new Class[]{Context.class}, context);
    }

    public static synchronized MultiSIMDeviceInfo getInstance(Context context) {
        if (f1150a == null) {
            f1150a = new MultiSIMDeviceInfo(context);
        }
        return f1150a;
    }

    public int getCellId(int simId) {
        int cid = -1;
        try {
            CellLocation cell = (CellLocation) m220a("getCellLocation", simId);
            if (cell instanceof GsmCellLocation) {
                cid = ((GsmCellLocation) cell).getCid();
            } else {
                cid = ((CdmaCellLocation) cell).getBaseStationId();
            }
        } catch (Exception e) {
        }
        return cid;
    }

    public CellLocation getCellLocation(int simId) {
        try {
            return (CellLocation) m220a("getCellLocation", simId);
        } catch (Exception e) {
            return null;
        }
    }

    public String getSubscriberId(int simId) {
        return (String) m220a("getSubscriberId", simId);
    }

    public String getDeviceId(int simId) {
        return (String) m220a("getDeviceId", simId);
    }

    public String getSmsCenter() {
        String sms = (String) m220a("getScAddress", 0);
        if (sms == null || sms.length() == 0) {
            return (String) m220a("getScAddress", 1);
        }
        return sms;
    }

    public String getNetworkOperator(int simId) {
        return (String) m220a("getNetworkOperator", simId);
    }

    public String getSimOperator(int simId) {
        return (String) m220a("getSimOperator", simId);
    }

    public String getSimSerialNumber(int simId) {
        return (String) m220a("getSimSerialNumber", simId);
    }

    public int getPhoneType(int simId) {
        try {
            return ((Integer) m220a("getPhoneType", simId)).intValue();
        } catch (Exception e) {
            return 0;
        }
    }

    public int getSimState(int simId) {
        try {
            return ((Integer) m220a("getSimState", simId)).intValue();
        } catch (Exception e) {
            return 1;
        }
    }

    /* JADX INFO: renamed from: a */
    private Object m220a(String methodName, int simId) {
        if (this.f1151b == null) {
            return null;
        }
        try {
            Object obj = ReflectUtils.invoke(this.f1151b, methodName, new Class[]{Integer.TYPE}, Integer.valueOf(simId));
            return obj;
        } catch (Exception e) {
            return null;
        }
    }
}
