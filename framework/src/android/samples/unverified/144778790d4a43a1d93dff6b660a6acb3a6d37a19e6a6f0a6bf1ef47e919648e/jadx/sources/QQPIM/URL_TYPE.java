package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class URL_TYPE {
    public static final URL_TYPE E_URL_BLACK_LIST;
    public static final URL_TYPE E_URL_MAX;
    public static final URL_TYPE E_URL_REGULAR;
    public static final URL_TYPE E_URL_SHADINESS;
    public static final URL_TYPE E_URL_WHITE_LIST;
    public static final int _E_URL_BLACK_LIST = 3;
    public static final int _E_URL_MAX = 4;
    public static final int _E_URL_REGULAR = 0;
    public static final int _E_URL_SHADINESS = 2;
    public static final int _E_URL_WHITE_LIST = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f592a;

    /* JADX INFO: renamed from: b */
    private static URL_TYPE[] f593b;

    /* JADX INFO: renamed from: c */
    private int f594c;

    /* JADX INFO: renamed from: d */
    private String f595d;

    static {
        f592a = !URL_TYPE.class.desiredAssertionStatus();
        f593b = new URL_TYPE[5];
        E_URL_REGULAR = new URL_TYPE(0, 0, "E_URL_REGULAR");
        E_URL_WHITE_LIST = new URL_TYPE(1, 1, "E_URL_WHITE_LIST");
        E_URL_SHADINESS = new URL_TYPE(2, 2, "E_URL_SHADINESS");
        E_URL_BLACK_LIST = new URL_TYPE(3, 3, "E_URL_BLACK_LIST");
        E_URL_MAX = new URL_TYPE(4, 4, "E_URL_MAX");
    }

    private URL_TYPE(int i, int i2, String str) {
        this.f595d = new String();
        this.f595d = str;
        this.f594c = i2;
        f593b[i] = this;
    }

    public static URL_TYPE convert(int i) {
        for (int i2 = 0; i2 < f593b.length; i2++) {
            if (f593b[i2].value() == i) {
                return f593b[i2];
            }
        }
        if (f592a) {
            return null;
        }
        throw new AssertionError();
    }

    public static URL_TYPE convert(String str) {
        for (int i = 0; i < f593b.length; i++) {
            if (f593b[i].toString().equals(str)) {
                return f593b[i];
            }
        }
        if (f592a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f595d;
    }

    public final int value() {
        return this.f594c;
    }
}
