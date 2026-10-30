package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EInfoID {
    public static final EInfoID EI_CPU;
    public static final EInfoID EI_DEVICE;
    public static final EInfoID EI_End;
    public static final EInfoID EI_GPU;
    public static final EInfoID EI_MOBILE;
    public static final EInfoID EI_None;
    public static final EInfoID EI_SCREEN;
    public static final EInfoID EI_STORAGE;
    public static final int _EI_CPU = 2;
    public static final int _EI_DEVICE = 6;
    public static final int _EI_End = 7;
    public static final int _EI_GPU = 4;
    public static final int _EI_MOBILE = 1;
    public static final int _EI_None = 0;
    public static final int _EI_SCREEN = 3;
    public static final int _EI_STORAGE = 5;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f207a;

    /* JADX INFO: renamed from: b */
    private static EInfoID[] f208b;

    /* JADX INFO: renamed from: c */
    private int f209c;

    /* JADX INFO: renamed from: d */
    private String f210d;

    static {
        f207a = !EInfoID.class.desiredAssertionStatus();
        f208b = new EInfoID[8];
        EI_None = new EInfoID(0, 0, "EI_None");
        EI_MOBILE = new EInfoID(1, 1, "EI_MOBILE");
        EI_CPU = new EInfoID(2, 2, "EI_CPU");
        EI_SCREEN = new EInfoID(3, 3, "EI_SCREEN");
        EI_GPU = new EInfoID(4, 4, "EI_GPU");
        EI_STORAGE = new EInfoID(5, 5, "EI_STORAGE");
        EI_DEVICE = new EInfoID(6, 6, "EI_DEVICE");
        EI_End = new EInfoID(7, 7, "EI_End");
    }

    private EInfoID(int i, int i2, String str) {
        this.f210d = new String();
        this.f210d = str;
        this.f209c = i2;
        f208b[i] = this;
    }

    public static EInfoID convert(int i) {
        for (int i2 = 0; i2 < f208b.length; i2++) {
            if (f208b[i2].value() == i) {
                return f208b[i2];
            }
        }
        if (f207a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EInfoID convert(String str) {
        for (int i = 0; i < f208b.length; i++) {
            if (f208b[i].toString().equals(str)) {
                return f208b[i];
            }
        }
        if (f207a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f210d;
    }

    public final int value() {
        return this.f209c;
    }
}
