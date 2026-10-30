package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EQueryType {
    public static final EQueryType E_QUERY_ALL;
    public static final EQueryType E_QUERY_MAX;
    public static final EQueryType E_QUERY_MIN;
    public static final EQueryType E_QUERY_MONEY;
    public static final EQueryType E_QUERY_TRAFFIC;
    public static final int _E_QUERY_ALL = 1;
    public static final int _E_QUERY_MAX = 4;
    public static final int _E_QUERY_MIN = 0;
    public static final int _E_QUERY_MONEY = 3;
    public static final int _E_QUERY_TRAFFIC = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f297a;

    /* JADX INFO: renamed from: b */
    private static EQueryType[] f298b;

    /* JADX INFO: renamed from: c */
    private int f299c;

    /* JADX INFO: renamed from: d */
    private String f300d;

    static {
        f297a = !EQueryType.class.desiredAssertionStatus();
        f298b = new EQueryType[5];
        E_QUERY_MIN = new EQueryType(0, 0, "E_QUERY_MIN");
        E_QUERY_ALL = new EQueryType(1, 1, "E_QUERY_ALL");
        E_QUERY_TRAFFIC = new EQueryType(2, 2, "E_QUERY_TRAFFIC");
        E_QUERY_MONEY = new EQueryType(3, 3, "E_QUERY_MONEY");
        E_QUERY_MAX = new EQueryType(4, 4, "E_QUERY_MAX");
    }

    private EQueryType(int i, int i2, String str) {
        this.f300d = new String();
        this.f300d = str;
        this.f299c = i2;
        f298b[i] = this;
    }

    public static EQueryType convert(int i) {
        for (int i2 = 0; i2 < f298b.length; i2++) {
            if (f298b[i2].value() == i) {
                return f298b[i2];
            }
        }
        if (f297a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EQueryType convert(String str) {
        for (int i = 0; i < f298b.length; i++) {
            if (f298b[i].toString().equals(str)) {
                return f298b[i];
            }
        }
        if (f297a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f300d;
    }

    public final int value() {
        return this.f299c;
    }
}
