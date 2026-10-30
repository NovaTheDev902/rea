package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ESmsContentType {
    public static final ESmsContentType EMSCT_12590;
    public static final ESmsContentType EMSCT_ADS;
    public static final ESmsContentType EMSCT_CHARGE;
    public static final ESmsContentType EMSCT_FRAUD;
    public static final ESmsContentType EMSCT_MAX;
    public static final ESmsContentType EMSCT_MIN;
    public static final ESmsContentType EMSCT_NORMAL;
    public static final ESmsContentType EMSCT_OPERATOR_INFO;
    public static final ESmsContentType EMSCT_SEX;
    public static final ESmsContentType EMSCT_UNKNOWN;
    public static final int _EMSCT_12590 = 5;
    public static final int _EMSCT_ADS = 3;
    public static final int _EMSCT_CHARGE = 8;
    public static final int _EMSCT_FRAUD = 4;
    public static final int _EMSCT_MAX = 9;
    public static final int _EMSCT_MIN = 0;
    public static final int _EMSCT_NORMAL = 2;
    public static final int _EMSCT_OPERATOR_INFO = 7;
    public static final int _EMSCT_SEX = 6;
    public static final int _EMSCT_UNKNOWN = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f333a;

    /* JADX INFO: renamed from: b */
    private static ESmsContentType[] f334b;

    /* JADX INFO: renamed from: c */
    private int f335c;

    /* JADX INFO: renamed from: d */
    private String f336d;

    static {
        f333a = !ESmsContentType.class.desiredAssertionStatus();
        f334b = new ESmsContentType[10];
        EMSCT_MIN = new ESmsContentType(0, 0, "EMSCT_MIN");
        EMSCT_UNKNOWN = new ESmsContentType(1, 1, "EMSCT_UNKNOWN");
        EMSCT_NORMAL = new ESmsContentType(2, 2, "EMSCT_NORMAL");
        EMSCT_ADS = new ESmsContentType(3, 3, "EMSCT_ADS");
        EMSCT_FRAUD = new ESmsContentType(4, 4, "EMSCT_FRAUD");
        EMSCT_12590 = new ESmsContentType(5, 5, "EMSCT_12590");
        EMSCT_SEX = new ESmsContentType(6, 6, "EMSCT_SEX");
        EMSCT_OPERATOR_INFO = new ESmsContentType(7, 7, "EMSCT_OPERATOR_INFO");
        EMSCT_CHARGE = new ESmsContentType(8, 8, "EMSCT_CHARGE");
        EMSCT_MAX = new ESmsContentType(9, 9, "EMSCT_MAX");
    }

    private ESmsContentType(int i, int i2, String str) {
        this.f336d = new String();
        this.f336d = str;
        this.f335c = i2;
        f334b[i] = this;
    }

    public static ESmsContentType convert(int i) {
        for (int i2 = 0; i2 < f334b.length; i2++) {
            if (f334b[i2].value() == i) {
                return f334b[i2];
            }
        }
        if (f333a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ESmsContentType convert(String str) {
        for (int i = 0; i < f334b.length; i++) {
            if (f334b[i].toString().equals(str)) {
                return f334b[i];
            }
        }
        if (f333a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f336d;
    }

    public final int value() {
        return this.f335c;
    }
}
