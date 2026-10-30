package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EPhoneType {
    public static final EPhoneType MPT_Android;
    public static final EPhoneType MPT_BB;
    public static final EPhoneType MPT_END;
    public static final EPhoneType MPT_Iphone;
    public static final EPhoneType MPT_Kjava;
    public static final EPhoneType MPT_MTK;
    public static final EPhoneType MPT_NONE;
    public static final EPhoneType MPT_PC_Windows;
    public static final EPhoneType MPT_Server;
    public static final EPhoneType MPT_Symbian;
    public static final EPhoneType MPT_SymbianV5;
    public static final EPhoneType MPT_WinPhone;
    public static final int _MPT_Android = 2;
    public static final int _MPT_BB = 8;
    public static final int _MPT_END = 102;
    public static final int _MPT_Iphone = 3;
    public static final int _MPT_Kjava = 4;
    public static final int _MPT_MTK = 7;
    public static final int _MPT_NONE = 0;
    public static final int _MPT_PC_Windows = 9;
    public static final int _MPT_Server = 5;
    public static final int _MPT_Symbian = 1;
    public static final int _MPT_SymbianV5 = 101;
    public static final int _MPT_WinPhone = 6;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f289a;

    /* JADX INFO: renamed from: b */
    private static EPhoneType[] f290b;

    /* JADX INFO: renamed from: c */
    private int f291c;

    /* JADX INFO: renamed from: d */
    private String f292d;

    static {
        f289a = !EPhoneType.class.desiredAssertionStatus();
        f290b = new EPhoneType[12];
        MPT_NONE = new EPhoneType(0, 0, "MPT_NONE");
        MPT_Symbian = new EPhoneType(1, 1, "MPT_Symbian");
        MPT_Android = new EPhoneType(2, 2, "MPT_Android");
        MPT_Iphone = new EPhoneType(3, 3, "MPT_Iphone");
        MPT_Kjava = new EPhoneType(4, 4, "MPT_Kjava");
        MPT_Server = new EPhoneType(5, 5, "MPT_Server");
        MPT_WinPhone = new EPhoneType(6, 6, "MPT_WinPhone");
        MPT_MTK = new EPhoneType(7, 7, "MPT_MTK");
        MPT_BB = new EPhoneType(8, 8, "MPT_BB");
        MPT_PC_Windows = new EPhoneType(9, 9, "MPT_PC_Windows");
        MPT_SymbianV5 = new EPhoneType(10, 101, "MPT_SymbianV5");
        MPT_END = new EPhoneType(11, 102, "MPT_END");
    }

    private EPhoneType(int i, int i2, String str) {
        this.f292d = new String();
        this.f292d = str;
        this.f291c = i2;
        f290b[i] = this;
    }

    public static EPhoneType convert(int i) {
        for (int i2 = 0; i2 < f290b.length; i2++) {
            if (f290b[i2].value() == i) {
                return f290b[i2];
            }
        }
        if (f289a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EPhoneType convert(String str) {
        for (int i = 0; i < f290b.length; i++) {
            if (f290b[i].toString().equals(str)) {
                return f290b[i];
            }
        }
        if (f289a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f292d;
    }

    public final int value() {
        return this.f291c;
    }
}
