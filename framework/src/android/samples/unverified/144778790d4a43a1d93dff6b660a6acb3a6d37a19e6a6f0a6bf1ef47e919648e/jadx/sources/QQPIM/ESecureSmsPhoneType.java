package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ESecureSmsPhoneType {
    public static final ESecureSmsPhoneType ESS_MPT_Android;
    public static final ESecureSmsPhoneType ESS_MPT_Iphone;
    public static final ESecureSmsPhoneType ESS_MPT_NONE;
    public static final ESecureSmsPhoneType ESS_MPT_Symbian;
    public static final ESecureSmsPhoneType ESS_MPT_SymbianV5;
    public static final int _ESS_MPT_Android = 2;
    public static final int _ESS_MPT_Iphone = 3;
    public static final int _ESS_MPT_NONE = 0;
    public static final int _ESS_MPT_Symbian = 1;
    public static final int _ESS_MPT_SymbianV5 = 101;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f325a;

    /* JADX INFO: renamed from: b */
    private static ESecureSmsPhoneType[] f326b;

    /* JADX INFO: renamed from: c */
    private int f327c;

    /* JADX INFO: renamed from: d */
    private String f328d;

    static {
        f325a = !ESecureSmsPhoneType.class.desiredAssertionStatus();
        f326b = new ESecureSmsPhoneType[5];
        ESS_MPT_NONE = new ESecureSmsPhoneType(0, 0, "ESS_MPT_NONE");
        ESS_MPT_Symbian = new ESecureSmsPhoneType(1, 1, "ESS_MPT_Symbian");
        ESS_MPT_Android = new ESecureSmsPhoneType(2, 2, "ESS_MPT_Android");
        ESS_MPT_Iphone = new ESecureSmsPhoneType(3, 3, "ESS_MPT_Iphone");
        ESS_MPT_SymbianV5 = new ESecureSmsPhoneType(4, 101, "ESS_MPT_SymbianV5");
    }

    private ESecureSmsPhoneType(int i, int i2, String str) {
        this.f328d = new String();
        this.f328d = str;
        this.f327c = i2;
        f326b[i] = this;
    }

    public static ESecureSmsPhoneType convert(int i) {
        for (int i2 = 0; i2 < f326b.length; i2++) {
            if (f326b[i2].value() == i) {
                return f326b[i2];
            }
        }
        if (f325a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ESecureSmsPhoneType convert(String str) {
        for (int i = 0; i < f326b.length; i++) {
            if (f326b[i].toString().equals(str)) {
                return f326b[i];
            }
        }
        if (f325a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f328d;
    }

    public final int value() {
        return this.f327c;
    }
}
