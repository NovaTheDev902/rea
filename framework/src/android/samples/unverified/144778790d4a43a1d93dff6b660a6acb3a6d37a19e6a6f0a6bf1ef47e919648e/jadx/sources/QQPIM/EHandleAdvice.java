package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EHandleAdvice {
    public static final EHandleAdvice HA_Check_Page;
    public static final EHandleAdvice HA_Check_Page_Update;
    public static final EHandleAdvice HA_Clear;
    public static final EHandleAdvice HA_Clear_Update;
    public static final EHandleAdvice HA_Down_Tool;
    public static final EHandleAdvice HA_Down_Tool_Update;
    public static final EHandleAdvice HA_None;
    public static final EHandleAdvice HA_Update;
    public static final int _HA_Check_Page = 4;
    public static final int _HA_Check_Page_Update = 5;
    public static final int _HA_Clear = 1;
    public static final int _HA_Clear_Update = 3;
    public static final int _HA_Down_Tool = 6;
    public static final int _HA_Down_Tool_Update = 7;
    public static final int _HA_None = 0;
    public static final int _HA_Update = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f191a;

    /* JADX INFO: renamed from: b */
    private static EHandleAdvice[] f192b;

    /* JADX INFO: renamed from: c */
    private int f193c;

    /* JADX INFO: renamed from: d */
    private String f194d;

    static {
        f191a = !EHandleAdvice.class.desiredAssertionStatus();
        f192b = new EHandleAdvice[8];
        HA_None = new EHandleAdvice(0, 0, "HA_None");
        HA_Clear = new EHandleAdvice(1, 1, "HA_Clear");
        HA_Update = new EHandleAdvice(2, 2, "HA_Update");
        HA_Clear_Update = new EHandleAdvice(3, 3, "HA_Clear_Update");
        HA_Check_Page = new EHandleAdvice(4, 4, "HA_Check_Page");
        HA_Check_Page_Update = new EHandleAdvice(5, 5, "HA_Check_Page_Update");
        HA_Down_Tool = new EHandleAdvice(6, 6, "HA_Down_Tool");
        HA_Down_Tool_Update = new EHandleAdvice(7, 7, "HA_Down_Tool_Update");
    }

    private EHandleAdvice(int i, int i2, String str) {
        this.f194d = new String();
        this.f194d = str;
        this.f193c = i2;
        f192b[i] = this;
    }

    public static EHandleAdvice convert(int i) {
        for (int i2 = 0; i2 < f192b.length; i2++) {
            if (f192b[i2].value() == i) {
                return f192b[i2];
            }
        }
        if (f191a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EHandleAdvice convert(String str) {
        for (int i = 0; i < f192b.length; i++) {
            if (f192b[i].toString().equals(str)) {
                return f192b[i];
            }
        }
        if (f191a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f194d;
    }

    public final int value() {
        return this.f193c;
    }
}
