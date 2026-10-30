package com.tencent.tccdb;

import android.content.Context;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.update.UpdateConfig;
import java.util.ArrayList;
import tms.C1147ad;
import tms.C1336v;

/* JADX INFO: loaded from: classes.dex */
public class TelNumberLocator {

    /* JADX INFO: renamed from: c */
    private static TelNumberLocator f6021c = null;

    /* JADX INFO: renamed from: a */
    private int f6022a;

    /* JADX INFO: renamed from: b */
    private Context f6023b;

    static {
        C1147ad.m2873a(TMSApplication.getApplicaionContext(), TMSApplication.getStrFromEnvMap(TMSApplication.CON_LOCATION_LIBNAME));
    }

    private TelNumberLocator(Context context) {
        this.f6023b = context;
        this.f6022a = newObject(context);
        if (this.f6022a == 0) {
            throw new OutOfMemoryError();
        }
        reload();
    }

    /* JADX INFO: renamed from: a */
    private static void m2582a(int i) {
        switch (i) {
            case -4:
                throw new OutOfMemoryError();
            case 0:
                return;
            default:
                throw new TelNumberLocatorException(i);
        }
    }

    private static native void deleteObject(int i);

    private static native int[] getAreaCode(int i);

    private static native int getAreaCodeLocation(int i, int i2, StringBuffer stringBuffer);

    private static native int getCityNameList(int i, String str, ArrayList<String> arrayList);

    private static native int[] getCountryCode(int i);

    private static native int getCountryCodeLocation(int i, int i2, StringBuffer stringBuffer);

    public static synchronized TelNumberLocator getDefault(Context context) {
        if (f6021c == null) {
            f6021c = new TelNumberLocator(context);
        }
        return f6021c;
    }

    private static native int getDetailYellowPages(int i, ArrayList<Integer> arrayList, ArrayList<String> arrayList2, ArrayList<String> arrayList3, ArrayList<String> arrayList4);

    private static native int getLocation(int i, StringBuffer stringBuffer, StringBuffer stringBuffer2, StringBuffer stringBuffer3, String str, boolean z);

    private static native int getMobileNumLocation(int i, int i2, StringBuffer stringBuffer);

    private static native int getProvinceNameList(int i, ArrayList<String> arrayList);

    private static native int getYellowPages(int i, ArrayList<String> arrayList, ArrayList<String> arrayList2);

    private static native int init(int i, String str, String str2);

    private static native int newObject(Context context);

    private static native int patch(int i, String str, String str2, String str3);

    protected void finalize() {
        if (this.f6022a != 0) {
            deleteObject(this.f6022a);
        }
    }

    public int[] getAreaCode() {
        return getAreaCode(this.f6022a);
    }

    public String getAreaCodeLocation(int i) {
        StringBuffer stringBuffer = new StringBuffer();
        int areaCodeLocation = getAreaCodeLocation(this.f6022a, i, stringBuffer);
        if (areaCodeLocation < 0) {
            if (areaCodeLocation == -1) {
                return "";
            }
            m2582a(areaCodeLocation);
        }
        return stringBuffer.toString();
    }

    public ArrayList<String> getCityNameList(String str) {
        ArrayList<String> arrayList = new ArrayList<>();
        m2582a(getCityNameList(this.f6022a, str, arrayList));
        return arrayList;
    }

    public int[] getCountryCode() {
        return getCountryCode(this.f6022a);
    }

    public String getCountryCodeLocation(int i) {
        StringBuffer stringBuffer = new StringBuffer();
        int countryCodeLocation = getCountryCodeLocation(this.f6022a, i, stringBuffer);
        if (countryCodeLocation < 0) {
            if (countryCodeLocation == -1) {
                return "";
            }
            m2582a(countryCodeLocation);
        }
        return stringBuffer.toString();
    }

    public boolean getDetailYellowPages(ArrayList<Integer> arrayList, ArrayList<String> arrayList2, ArrayList<String> arrayList3, ArrayList<String> arrayList4) {
        if (arrayList2 == null || arrayList3 == null) {
            return false;
        }
        m2582a(getDetailYellowPages(this.f6022a, arrayList, arrayList2, arrayList3, arrayList4));
        return true;
    }

    public void getLocation(StringBuffer stringBuffer, StringBuffer stringBuffer2, StringBuffer stringBuffer3, String str, boolean z) {
        int location = getLocation(this.f6022a, stringBuffer, stringBuffer2, stringBuffer3, str, z);
        if (location < 0) {
            if (location != -1) {
                m2582a(location);
                return;
            }
            stringBuffer.replace(0, stringBuffer.length(), "");
            stringBuffer2.replace(0, stringBuffer2.length(), "");
            stringBuffer3.replace(0, stringBuffer3.length(), "");
        }
    }

    public String getMobileNumLocation(int i) {
        StringBuffer stringBuffer = new StringBuffer();
        int mobileNumLocation = getMobileNumLocation(this.f6022a, i, stringBuffer);
        if (mobileNumLocation < 0) {
            if (mobileNumLocation == -1) {
                return "";
            }
            m2582a(mobileNumLocation);
        }
        return stringBuffer.toString();
    }

    public ArrayList<String> getProvinceNameList() {
        ArrayList<String> arrayList = new ArrayList<>();
        m2582a(getProvinceNameList(this.f6022a, arrayList));
        return arrayList;
    }

    public boolean getYellowPages(ArrayList<String> arrayList, ArrayList<String> arrayList2) {
        if (arrayList == null || arrayList2 == null) {
            return false;
        }
        m2582a(getYellowPages(this.f6022a, arrayList, arrayList2));
        return true;
    }

    public int patchLocation(String str, String str2) {
        return patch(this.f6022a, C1336v.m3577a(this.f6023b, UpdateConfig.LOCATION_NAME, (String) null), str, str2);
    }

    public void reload() {
        try {
            String strM3577a = C1336v.m3577a(this.f6023b, UpdateConfig.LOCATION_NAME, (String) null);
            String strM3577a2 = C1336v.m3577a(this.f6023b, "yd.sdb", (String) null);
            if (strM3577a == null && strM3577a2 == null) {
                return;
            }
            m2582a(init(this.f6022a, strM3577a, strM3577a2));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
