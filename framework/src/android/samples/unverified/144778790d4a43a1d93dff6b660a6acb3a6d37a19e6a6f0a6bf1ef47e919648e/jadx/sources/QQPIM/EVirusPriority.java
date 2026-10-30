package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EVirusPriority {
    public static final EVirusPriority VP_High;
    public static final EVirusPriority VP_Low;
    public static final EVirusPriority VP_Mid;
    public static final int _VP_High = 2;
    public static final int _VP_Low = 0;
    public static final int _VP_Mid = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f393a;

    /* JADX INFO: renamed from: b */
    private static EVirusPriority[] f394b;

    /* JADX INFO: renamed from: c */
    private int f395c;

    /* JADX INFO: renamed from: d */
    private String f396d;

    static {
        f393a = !EVirusPriority.class.desiredAssertionStatus();
        f394b = new EVirusPriority[3];
        VP_Low = new EVirusPriority(0, 0, "VP_Low");
        VP_Mid = new EVirusPriority(1, 1, "VP_Mid");
        VP_High = new EVirusPriority(2, 2, "VP_High");
    }

    private EVirusPriority(int i, int i2, String str) {
        this.f396d = new String();
        this.f396d = str;
        this.f395c = i2;
        f394b[i] = this;
    }

    public static EVirusPriority convert(int i) {
        for (int i2 = 0; i2 < f394b.length; i2++) {
            if (f394b[i2].value() == i) {
                return f394b[i2];
            }
        }
        if (f393a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EVirusPriority convert(String str) {
        for (int i = 0; i < f394b.length; i++) {
            if (f394b[i].toString().equals(str)) {
                return f394b[i];
            }
        }
        if (f393a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f396d;
    }

    public final int value() {
        return this.f395c;
    }
}
