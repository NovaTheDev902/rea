package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EResult {
    public static final EResult ER_Fail;
    public static final EResult ER_Invalid;
    public static final EResult ER_Success;
    public static final int _ER_Fail = 0;
    public static final int _ER_Invalid = 2;
    public static final int _ER_Success = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f313a;

    /* JADX INFO: renamed from: b */
    private static EResult[] f314b;

    /* JADX INFO: renamed from: c */
    private int f315c;

    /* JADX INFO: renamed from: d */
    private String f316d;

    static {
        f313a = !EResult.class.desiredAssertionStatus();
        f314b = new EResult[3];
        ER_Fail = new EResult(0, 0, "ER_Fail");
        ER_Success = new EResult(1, 1, "ER_Success");
        ER_Invalid = new EResult(2, 2, "ER_Invalid");
    }

    private EResult(int i, int i2, String str) {
        this.f316d = new String();
        this.f316d = str;
        this.f315c = i2;
        f314b[i] = this;
    }

    public static EResult convert(int i) {
        for (int i2 = 0; i2 < f314b.length; i2++) {
            if (f314b[i2].value() == i) {
                return f314b[i2];
            }
        }
        if (f313a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EResult convert(String str) {
        for (int i = 0; i < f314b.length; i++) {
            if (f314b[i].toString().equals(str)) {
                return f314b[i];
            }
        }
        if (f313a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f316d;
    }

    public final int value() {
        return this.f315c;
    }
}
