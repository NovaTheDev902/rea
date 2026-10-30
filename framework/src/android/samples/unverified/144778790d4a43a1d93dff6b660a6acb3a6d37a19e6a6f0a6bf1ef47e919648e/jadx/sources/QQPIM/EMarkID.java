package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EMarkID {
    public static final EMarkID EM_2D;
    public static final EMarkID EM_3D;
    public static final EMarkID EM_CPU;
    public static final EMarkID EM_End;
    public static final EMarkID EM_IO;
    public static final EMarkID EM_None;
    public static final EMarkID EM_RAM;
    public static final EMarkID EM_SDCARD;
    public static final EMarkID EM_TOTAL;
    public static final int _EM_2D = 6;
    public static final int _EM_3D = 7;
    public static final int _EM_CPU = 2;
    public static final int _EM_End = 8;
    public static final int _EM_IO = 5;
    public static final int _EM_None = 0;
    public static final int _EM_RAM = 3;
    public static final int _EM_SDCARD = 4;
    public static final int _EM_TOTAL = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f223a;

    /* JADX INFO: renamed from: b */
    private static EMarkID[] f224b;

    /* JADX INFO: renamed from: c */
    private int f225c;

    /* JADX INFO: renamed from: d */
    private String f226d;

    static {
        f223a = !EMarkID.class.desiredAssertionStatus();
        f224b = new EMarkID[9];
        EM_None = new EMarkID(0, 0, "EM_None");
        EM_TOTAL = new EMarkID(1, 1, "EM_TOTAL");
        EM_CPU = new EMarkID(2, 2, "EM_CPU");
        EM_RAM = new EMarkID(3, 3, "EM_RAM");
        EM_SDCARD = new EMarkID(4, 4, "EM_SDCARD");
        EM_IO = new EMarkID(5, 5, "EM_IO");
        EM_2D = new EMarkID(6, 6, "EM_2D");
        EM_3D = new EMarkID(7, 7, "EM_3D");
        EM_End = new EMarkID(8, 8, "EM_End");
    }

    private EMarkID(int i, int i2, String str) {
        this.f226d = new String();
        this.f226d = str;
        this.f225c = i2;
        f224b[i] = this;
    }

    public static EMarkID convert(int i) {
        for (int i2 = 0; i2 < f224b.length; i2++) {
            if (f224b[i2].value() == i) {
                return f224b[i2];
            }
        }
        if (f223a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EMarkID convert(String str) {
        for (int i = 0; i < f224b.length; i++) {
            if (f224b[i].toString().equals(str)) {
                return f224b[i];
            }
        }
        if (f223a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f226d;
    }

    public final int value() {
        return this.f225c;
    }
}
