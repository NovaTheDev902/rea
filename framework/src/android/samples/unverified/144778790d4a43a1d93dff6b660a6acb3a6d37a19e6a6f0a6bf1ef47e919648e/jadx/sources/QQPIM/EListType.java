package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EListType {
    public static final EListType ELT_Black;
    public static final EListType ELT_White;
    public static final int _ELT_Black = 0;
    public static final int _ELT_White = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f211a;

    /* JADX INFO: renamed from: b */
    private static EListType[] f212b;

    /* JADX INFO: renamed from: c */
    private int f213c;

    /* JADX INFO: renamed from: d */
    private String f214d;

    static {
        f211a = !EListType.class.desiredAssertionStatus();
        f212b = new EListType[2];
        ELT_Black = new EListType(0, 0, "ELT_Black");
        ELT_White = new EListType(1, 1, "ELT_White");
    }

    private EListType(int i, int i2, String str) {
        this.f214d = new String();
        this.f214d = str;
        this.f213c = i2;
        f212b[i] = this;
    }

    public static EListType convert(int i) {
        for (int i2 = 0; i2 < f212b.length; i2++) {
            if (f212b[i2].value() == i) {
                return f212b[i2];
            }
        }
        if (f211a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EListType convert(String str) {
        for (int i = 0; i < f212b.length; i++) {
            if (f212b[i].toString().equals(str)) {
                return f212b[i];
            }
        }
        if (f211a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f214d;
    }

    public final int value() {
        return this.f213c;
    }
}
