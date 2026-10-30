package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class SafeType {
    public static final SafeType C_AD_BLOCK;
    public static final SafeType C_LOW_RISK;
    public static final SafeType C_MIDDLE_RISK;
    public static final SafeType C_NOT_HIT;
    public static final SafeType C_NOT_Official;
    public static final SafeType C_RISK;
    public static final SafeType C_SAFE;
    public static final SafeType C_UNKNOWN;
    public static final SafeType C_VIRUS;
    public static final int _C_AD_BLOCK = 7;
    public static final int _C_LOW_RISK = 4;
    public static final int _C_MIDDLE_RISK = 5;
    public static final int _C_NOT_HIT = 6;
    public static final int _C_NOT_Official = 8;
    public static final int _C_RISK = 2;
    public static final int _C_SAFE = 1;
    public static final int _C_UNKNOWN = 0;
    public static final int _C_VIRUS = 3;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f531a;

    /* JADX INFO: renamed from: b */
    private static SafeType[] f532b;

    /* JADX INFO: renamed from: c */
    private int f533c;

    /* JADX INFO: renamed from: d */
    private String f534d;

    static {
        f531a = !SafeType.class.desiredAssertionStatus();
        f532b = new SafeType[9];
        C_UNKNOWN = new SafeType(0, 0, "C_UNKNOWN");
        C_SAFE = new SafeType(1, 1, "C_SAFE");
        C_RISK = new SafeType(2, 2, "C_RISK");
        C_VIRUS = new SafeType(3, 3, "C_VIRUS");
        C_LOW_RISK = new SafeType(4, 4, "C_LOW_RISK");
        C_MIDDLE_RISK = new SafeType(5, 5, "C_MIDDLE_RISK");
        C_NOT_HIT = new SafeType(6, 6, "C_NOT_HIT");
        C_AD_BLOCK = new SafeType(7, 7, "C_AD_BLOCK");
        C_NOT_Official = new SafeType(8, 8, "C_NOT_Official");
    }

    private SafeType(int i, int i2, String str) {
        this.f534d = new String();
        this.f534d = str;
        this.f533c = i2;
        f532b[i] = this;
    }

    public static SafeType convert(int i) {
        for (int i2 = 0; i2 < f532b.length; i2++) {
            if (f532b[i2].value() == i) {
                return f532b[i2];
            }
        }
        if (f531a) {
            return null;
        }
        throw new AssertionError();
    }

    public static SafeType convert(String str) {
        for (int i = 0; i < f532b.length; i++) {
            if (f532b[i].toString().equals(str)) {
                return f532b[i];
            }
        }
        if (f531a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f534d;
    }

    public final int value() {
        return this.f533c;
    }
}
