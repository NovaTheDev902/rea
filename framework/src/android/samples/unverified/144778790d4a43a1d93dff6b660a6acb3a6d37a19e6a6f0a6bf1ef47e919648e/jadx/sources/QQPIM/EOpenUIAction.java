package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EOpenUIAction {
    public static final EOpenUIAction EOpenUIA_NONE;
    public static final EOpenUIAction EOpenUIA_Sec_Android_SoftGame_WRecommend;
    public static final int _EOpenUIA_NONE = 0;
    public static final int _EOpenUIA_Sec_Android_SoftGame_WRecommend = 120101000;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f277a;

    /* JADX INFO: renamed from: b */
    private static EOpenUIAction[] f278b;

    /* JADX INFO: renamed from: c */
    private int f279c;

    /* JADX INFO: renamed from: d */
    private String f280d;

    static {
        f277a = !EOpenUIAction.class.desiredAssertionStatus();
        f278b = new EOpenUIAction[2];
        EOpenUIA_NONE = new EOpenUIAction(0, 0, "EOpenUIA_NONE");
        EOpenUIA_Sec_Android_SoftGame_WRecommend = new EOpenUIAction(1, _EOpenUIA_Sec_Android_SoftGame_WRecommend, "EOpenUIA_Sec_Android_SoftGame_WRecommend");
    }

    private EOpenUIAction(int i, int i2, String str) {
        this.f280d = new String();
        this.f280d = str;
        this.f279c = i2;
        f278b[i] = this;
    }

    public static EOpenUIAction convert(int i) {
        for (int i2 = 0; i2 < f278b.length; i2++) {
            if (f278b[i2].value() == i) {
                return f278b[i2];
            }
        }
        if (f277a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EOpenUIAction convert(String str) {
        for (int i = 0; i < f278b.length; i++) {
            if (f278b[i].toString().equals(str)) {
                return f278b[i];
            }
        }
        if (f277a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f280d;
    }

    public final int value() {
        return this.f279c;
    }
}
