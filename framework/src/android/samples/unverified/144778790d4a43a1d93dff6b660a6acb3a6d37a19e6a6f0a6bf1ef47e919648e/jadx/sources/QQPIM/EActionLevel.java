package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EActionLevel {
    public static final EActionLevel EAL_Common;
    public static final EActionLevel EAL_Detail;
    public static final EActionLevel EAL_None;
    public static final EActionLevel EAL_Simple;
    public static final int _EAL_Common = 2;
    public static final int _EAL_Detail = 3;
    public static final int _EAL_None = 0;
    public static final int _EAL_Simple = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f135a;

    /* JADX INFO: renamed from: b */
    private static EActionLevel[] f136b;

    /* JADX INFO: renamed from: c */
    private int f137c;

    /* JADX INFO: renamed from: d */
    private String f138d;

    static {
        f135a = !EActionLevel.class.desiredAssertionStatus();
        f136b = new EActionLevel[4];
        EAL_None = new EActionLevel(0, 0, "EAL_None");
        EAL_Simple = new EActionLevel(1, 1, "EAL_Simple");
        EAL_Common = new EActionLevel(2, 2, "EAL_Common");
        EAL_Detail = new EActionLevel(3, 3, "EAL_Detail");
    }

    private EActionLevel(int i, int i2, String str) {
        this.f138d = new String();
        this.f138d = str;
        this.f137c = i2;
        f136b[i] = this;
    }

    public static EActionLevel convert(int i) {
        for (int i2 = 0; i2 < f136b.length; i2++) {
            if (f136b[i2].value() == i) {
                return f136b[i2];
            }
        }
        if (f135a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EActionLevel convert(String str) {
        for (int i = 0; i < f136b.length; i++) {
            if (f136b[i].toString().equals(str)) {
                return f136b[i];
            }
        }
        if (f135a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f138d;
    }

    public final int value() {
        return this.f137c;
    }
}
