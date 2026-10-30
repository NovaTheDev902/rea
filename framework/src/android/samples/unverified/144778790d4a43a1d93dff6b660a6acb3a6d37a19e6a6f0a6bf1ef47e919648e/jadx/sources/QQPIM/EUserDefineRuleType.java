package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EUserDefineRuleType {
    public static final EUserDefineRuleType EMUDRT_BLACK;
    public static final EUserDefineRuleType EMUDRT_MAX;
    public static final EUserDefineRuleType EMUDRT_MIN;
    public static final EUserDefineRuleType EMUDRT_WHITE;
    public static final int _EMUDRT_BLACK = 2;
    public static final int _EMUDRT_MAX = 3;
    public static final int _EMUDRT_MIN = 0;
    public static final int _EMUDRT_WHITE = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f385a;

    /* JADX INFO: renamed from: b */
    private static EUserDefineRuleType[] f386b;

    /* JADX INFO: renamed from: c */
    private int f387c;

    /* JADX INFO: renamed from: d */
    private String f388d;

    static {
        f385a = !EUserDefineRuleType.class.desiredAssertionStatus();
        f386b = new EUserDefineRuleType[4];
        EMUDRT_MIN = new EUserDefineRuleType(0, 0, "EMUDRT_MIN");
        EMUDRT_WHITE = new EUserDefineRuleType(1, 1, "EMUDRT_WHITE");
        EMUDRT_BLACK = new EUserDefineRuleType(2, 2, "EMUDRT_BLACK");
        EMUDRT_MAX = new EUserDefineRuleType(3, 3, "EMUDRT_MAX");
    }

    private EUserDefineRuleType(int i, int i2, String str) {
        this.f388d = new String();
        this.f388d = str;
        this.f387c = i2;
        f386b[i] = this;
    }

    public static EUserDefineRuleType convert(int i) {
        for (int i2 = 0; i2 < f386b.length; i2++) {
            if (f386b[i2].value() == i) {
                return f386b[i2];
            }
        }
        if (f385a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EUserDefineRuleType convert(String str) {
        for (int i = 0; i < f386b.length; i++) {
            if (f386b[i].toString().equals(str)) {
                return f386b[i];
            }
        }
        if (f385a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f388d;
    }

    public final int value() {
        return this.f387c;
    }
}
