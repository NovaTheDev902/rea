package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EDataUnit {
    public static final EDataUnit E_DATA_UNIT_BYTE;
    public static final EDataUnit E_DATA_UNIT_DATE;
    public static final EDataUnit E_DATA_UNIT_GB;
    public static final EDataUnit E_DATA_UNIT_KB;
    public static final EDataUnit E_DATA_UNIT_MAX;
    public static final EDataUnit E_DATA_UNIT_MB;
    public static final EDataUnit E_DATA_UNIT_MIN;
    public static final EDataUnit E_DATA_UNIT_YUAN;
    public static final int _E_DATA_UNIT_BYTE = 6;
    public static final int _E_DATA_UNIT_DATE = 5;
    public static final int _E_DATA_UNIT_GB = 4;
    public static final int _E_DATA_UNIT_KB = 2;
    public static final int _E_DATA_UNIT_MAX = 7;
    public static final int _E_DATA_UNIT_MB = 3;
    public static final int _E_DATA_UNIT_MIN = 0;
    public static final int _E_DATA_UNIT_YUAN = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f183a;

    /* JADX INFO: renamed from: b */
    private static EDataUnit[] f184b;

    /* JADX INFO: renamed from: c */
    private int f185c;

    /* JADX INFO: renamed from: d */
    private String f186d;

    static {
        f183a = !EDataUnit.class.desiredAssertionStatus();
        f184b = new EDataUnit[8];
        E_DATA_UNIT_MIN = new EDataUnit(0, 0, "E_DATA_UNIT_MIN");
        E_DATA_UNIT_YUAN = new EDataUnit(1, 1, "E_DATA_UNIT_YUAN");
        E_DATA_UNIT_KB = new EDataUnit(2, 2, "E_DATA_UNIT_KB");
        E_DATA_UNIT_MB = new EDataUnit(3, 3, "E_DATA_UNIT_MB");
        E_DATA_UNIT_GB = new EDataUnit(4, 4, "E_DATA_UNIT_GB");
        E_DATA_UNIT_DATE = new EDataUnit(5, 5, "E_DATA_UNIT_DATE");
        E_DATA_UNIT_BYTE = new EDataUnit(6, 6, "E_DATA_UNIT_BYTE");
        E_DATA_UNIT_MAX = new EDataUnit(7, 7, "E_DATA_UNIT_MAX");
    }

    private EDataUnit(int i, int i2, String str) {
        this.f186d = new String();
        this.f186d = str;
        this.f185c = i2;
        f184b[i] = this;
    }

    public static EDataUnit convert(int i) {
        for (int i2 = 0; i2 < f184b.length; i2++) {
            if (f184b[i2].value() == i) {
                return f184b[i2];
            }
        }
        if (f183a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EDataUnit convert(String str) {
        for (int i = 0; i < f184b.length; i++) {
            if (f184b[i].toString().equals(str)) {
                return f184b[i];
            }
        }
        if (f183a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f186d;
    }

    public final int value() {
        return this.f185c;
    }
}
