package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EModleMarkID {
    public static final EModleMarkID EMM_CPU;
    public static final EModleMarkID EMM_End;
    public static final EModleMarkID EMM_Media;
    public static final EModleMarkID EMM_Memory;
    public static final EModleMarkID EMM_None;
    public static final EModleMarkID EMM_TOTAL;
    public static final int _EMM_CPU = 2;
    public static final int _EMM_End = 5;
    public static final int _EMM_Media = 3;
    public static final int _EMM_Memory = 4;
    public static final int _EMM_None = 0;
    public static final int _EMM_TOTAL = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f265a;

    /* JADX INFO: renamed from: b */
    private static EModleMarkID[] f266b;

    /* JADX INFO: renamed from: c */
    private int f267c;

    /* JADX INFO: renamed from: d */
    private String f268d;

    static {
        f265a = !EModleMarkID.class.desiredAssertionStatus();
        f266b = new EModleMarkID[6];
        EMM_None = new EModleMarkID(0, 0, "EMM_None");
        EMM_TOTAL = new EModleMarkID(1, 1, "EMM_TOTAL");
        EMM_CPU = new EModleMarkID(2, 2, "EMM_CPU");
        EMM_Media = new EModleMarkID(3, 3, "EMM_Media");
        EMM_Memory = new EModleMarkID(4, 4, "EMM_Memory");
        EMM_End = new EModleMarkID(5, 5, "EMM_End");
    }

    private EModleMarkID(int i, int i2, String str) {
        this.f268d = new String();
        this.f268d = str;
        this.f267c = i2;
        f266b[i] = this;
    }

    public static EModleMarkID convert(int i) {
        for (int i2 = 0; i2 < f266b.length; i2++) {
            if (f266b[i2].value() == i) {
                return f266b[i2];
            }
        }
        if (f265a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EModleMarkID convert(String str) {
        for (int i = 0; i < f266b.length; i++) {
            if (f266b[i].toString().equals(str)) {
                return f266b[i];
            }
        }
        if (f265a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f268d;
    }

    public final int value() {
        return this.f267c;
    }
}
