package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EMarketList {
    public static final EMarketList EML_91Helper;
    public static final EMarketList EML_AnZhi;
    public static final EMarketList EML_AppChina;
    public static final EMarketList EML_Baidu;
    public static final EMarketList EML_GFan;
    public static final EMarketList EML_Google;
    public static final EMarketList EML_HiApk;
    public static final EMarketList EML_WanDouJia;
    public static final int _EML_91Helper = 5;
    public static final int _EML_AnZhi = 2;
    public static final int _EML_AppChina = 3;
    public static final int _EML_Baidu = 8;
    public static final int _EML_GFan = 4;
    public static final int _EML_Google = 7;
    public static final int _EML_HiApk = 1;
    public static final int _EML_WanDouJia = 6;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f227a;

    /* JADX INFO: renamed from: b */
    private static EMarketList[] f228b;

    /* JADX INFO: renamed from: c */
    private int f229c;

    /* JADX INFO: renamed from: d */
    private String f230d;

    static {
        f227a = !EMarketList.class.desiredAssertionStatus();
        f228b = new EMarketList[8];
        EML_HiApk = new EMarketList(0, 1, "EML_HiApk");
        EML_AnZhi = new EMarketList(1, 2, "EML_AnZhi");
        EML_AppChina = new EMarketList(2, 3, "EML_AppChina");
        EML_GFan = new EMarketList(3, 4, "EML_GFan");
        EML_91Helper = new EMarketList(4, 5, "EML_91Helper");
        EML_WanDouJia = new EMarketList(5, 6, "EML_WanDouJia");
        EML_Google = new EMarketList(6, 7, "EML_Google");
        EML_Baidu = new EMarketList(7, 8, "EML_Baidu");
    }

    private EMarketList(int i, int i2, String str) {
        this.f230d = new String();
        this.f230d = str;
        this.f229c = i2;
        f228b[i] = this;
    }

    public static EMarketList convert(int i) {
        for (int i2 = 0; i2 < f228b.length; i2++) {
            if (f228b[i2].value() == i) {
                return f228b[i2];
            }
        }
        if (f227a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EMarketList convert(String str) {
        for (int i = 0; i < f228b.length; i++) {
            if (f228b[i].toString().equals(str)) {
                return f228b[i];
            }
        }
        if (f227a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f230d;
    }

    public final int value() {
        return this.f229c;
    }
}
