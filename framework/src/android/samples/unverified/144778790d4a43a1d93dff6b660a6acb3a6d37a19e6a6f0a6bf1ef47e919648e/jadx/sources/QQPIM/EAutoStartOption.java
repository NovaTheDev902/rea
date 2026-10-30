package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EAutoStartOption {
    public static final EAutoStartOption EASO_Forbid;
    public static final EAutoStartOption EASO_NONE;
    public static final EAutoStartOption EASO_OK;
    public static final int _EASO_Forbid = 2;
    public static final int _EASO_NONE = 0;
    public static final int _EASO_OK = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f147a;

    /* JADX INFO: renamed from: b */
    private static EAutoStartOption[] f148b;

    /* JADX INFO: renamed from: c */
    private int f149c;

    /* JADX INFO: renamed from: d */
    private String f150d;

    static {
        f147a = !EAutoStartOption.class.desiredAssertionStatus();
        f148b = new EAutoStartOption[3];
        EASO_NONE = new EAutoStartOption(0, 0, "EASO_NONE");
        EASO_OK = new EAutoStartOption(1, 1, "EASO_OK");
        EASO_Forbid = new EAutoStartOption(2, 2, "EASO_Forbid");
    }

    private EAutoStartOption(int i, int i2, String str) {
        this.f150d = new String();
        this.f150d = str;
        this.f149c = i2;
        f148b[i] = this;
    }

    public static EAutoStartOption convert(int i) {
        for (int i2 = 0; i2 < f148b.length; i2++) {
            if (f148b[i2].value() == i) {
                return f148b[i2];
            }
        }
        if (f147a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EAutoStartOption convert(String str) {
        for (int i = 0; i < f148b.length; i++) {
            if (f148b[i].toString().equals(str)) {
                return f148b[i];
            }
        }
        if (f147a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f150d;
    }

    public final int value() {
        return this.f149c;
    }
}
