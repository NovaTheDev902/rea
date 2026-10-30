package LBSAPIProtocol;

/* JADX INFO: loaded from: classes.dex */
public final class UINTYPE {
    public static final UINTYPE UIN_EMAIL;
    public static final UINTYPE UIN_IMEI;
    public static final UINTYPE UIN_MOBILE;
    public static final UINTYPE UIN_QQ;
    public static final int _UIN_EMAIL = 1;
    public static final int _UIN_IMEI = 3;
    public static final int _UIN_MOBILE = 2;
    public static final int _UIN_QQ = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f57a;

    /* JADX INFO: renamed from: b */
    private static UINTYPE[] f58b;

    /* JADX INFO: renamed from: c */
    private int f59c;

    /* JADX INFO: renamed from: d */
    private String f60d;

    static {
        f57a = !UINTYPE.class.desiredAssertionStatus();
        f58b = new UINTYPE[4];
        UIN_QQ = new UINTYPE(0, 0, "UIN_QQ");
        UIN_EMAIL = new UINTYPE(1, 1, "UIN_EMAIL");
        UIN_MOBILE = new UINTYPE(2, 2, "UIN_MOBILE");
        UIN_IMEI = new UINTYPE(3, 3, "UIN_IMEI");
    }

    private UINTYPE(int i, int i2, String str) {
        this.f60d = new String();
        this.f60d = str;
        this.f59c = i2;
        f58b[i] = this;
    }

    public static UINTYPE convert(int i) {
        for (int i2 = 0; i2 < f58b.length; i2++) {
            if (f58b[i2].value() == i) {
                return f58b[i2];
            }
        }
        if (f57a) {
            return null;
        }
        throw new AssertionError();
    }

    public static UINTYPE convert(String str) {
        for (int i = 0; i < f58b.length; i++) {
            if (f58b[i].toString().equals(str)) {
                return f58b[i];
            }
        }
        if (f57a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f60d;
    }

    public final int value() {
        return this.f59c;
    }
}
