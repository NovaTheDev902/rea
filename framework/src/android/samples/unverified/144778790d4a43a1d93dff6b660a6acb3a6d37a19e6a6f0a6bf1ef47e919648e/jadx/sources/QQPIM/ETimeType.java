package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ETimeType {
    public static final ETimeType ETT_Total;
    public static final ETimeType ETT_Week;
    public static final int _ETT_Total = 1;
    public static final int _ETT_Week = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f361a;

    /* JADX INFO: renamed from: b */
    private static ETimeType[] f362b;

    /* JADX INFO: renamed from: c */
    private int f363c;

    /* JADX INFO: renamed from: d */
    private String f364d;

    static {
        f361a = !ETimeType.class.desiredAssertionStatus();
        f362b = new ETimeType[2];
        ETT_Total = new ETimeType(0, 1, "ETT_Total");
        ETT_Week = new ETimeType(1, 2, "ETT_Week");
    }

    private ETimeType(int i, int i2, String str) {
        this.f364d = new String();
        this.f364d = str;
        this.f363c = i2;
        f362b[i] = this;
    }

    public static ETimeType convert(int i) {
        for (int i2 = 0; i2 < f362b.length; i2++) {
            if (f362b[i2].value() == i) {
                return f362b[i2];
            }
        }
        if (f361a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ETimeType convert(String str) {
        for (int i = 0; i < f362b.length; i++) {
            if (f362b[i].toString().equals(str)) {
                return f362b[i];
            }
        }
        if (f361a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f364d;
    }

    public final int value() {
        return this.f363c;
    }
}
