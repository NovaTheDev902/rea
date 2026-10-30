package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EOperationType {
    public static final EOperationType OT_Add;
    public static final EOperationType OT_Del;
    public static final EOperationType OT_NONE;
    public static final int _OT_Add = 1;
    public static final int _OT_Del = 2;
    public static final int _OT_NONE = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f281a;

    /* JADX INFO: renamed from: b */
    private static EOperationType[] f282b;

    /* JADX INFO: renamed from: c */
    private int f283c;

    /* JADX INFO: renamed from: d */
    private String f284d;

    static {
        f281a = !EOperationType.class.desiredAssertionStatus();
        f282b = new EOperationType[3];
        OT_NONE = new EOperationType(0, 0, "OT_NONE");
        OT_Add = new EOperationType(1, 1, "OT_Add");
        OT_Del = new EOperationType(2, 2, "OT_Del");
    }

    private EOperationType(int i, int i2, String str) {
        this.f284d = new String();
        this.f284d = str;
        this.f283c = i2;
        f282b[i] = this;
    }

    public static EOperationType convert(int i) {
        for (int i2 = 0; i2 < f282b.length; i2++) {
            if (f282b[i2].value() == i) {
                return f282b[i2];
            }
        }
        if (f281a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EOperationType convert(String str) {
        for (int i = 0; i < f282b.length; i++) {
            if (f282b[i].toString().equals(str)) {
                return f282b[i];
            }
        }
        if (f281a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f284d;
    }

    public final int value() {
        return this.f283c;
    }
}
