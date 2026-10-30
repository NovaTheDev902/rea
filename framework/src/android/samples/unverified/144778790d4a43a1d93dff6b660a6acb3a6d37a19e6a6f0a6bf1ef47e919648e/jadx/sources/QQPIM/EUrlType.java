package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EUrlType {
    public static final EUrlType EUT_Page;
    public static final EUrlType EUT_Pkg;
    public static final int _EUT_Page = 1;
    public static final int _EUT_Pkg = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f377a;

    /* JADX INFO: renamed from: b */
    private static EUrlType[] f378b;

    /* JADX INFO: renamed from: c */
    private int f379c;

    /* JADX INFO: renamed from: d */
    private String f380d;

    static {
        f377a = !EUrlType.class.desiredAssertionStatus();
        f378b = new EUrlType[2];
        EUT_Pkg = new EUrlType(0, 0, "EUT_Pkg");
        EUT_Page = new EUrlType(1, 1, "EUT_Page");
    }

    private EUrlType(int i, int i2, String str) {
        this.f380d = new String();
        this.f380d = str;
        this.f379c = i2;
        f378b[i] = this;
    }

    public static EUrlType convert(int i) {
        for (int i2 = 0; i2 < f378b.length; i2++) {
            if (f378b[i2].value() == i) {
                return f378b[i2];
            }
        }
        if (f377a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EUrlType convert(String str) {
        for (int i = 0; i < f378b.length; i++) {
            if (f378b[i].toString().equals(str)) {
                return f378b[i];
            }
        }
        if (f377a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f380d;
    }

    public final int value() {
        return this.f379c;
    }
}
