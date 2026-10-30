package LBSAPIProtocol;

/* JADX INFO: loaded from: classes.dex */
public final class POI_SORT_METHOD {
    public static final POI_SORT_METHOD SORT_BY_DISTANCE;
    public static final POI_SORT_METHOD SORT_BY_HOT;
    public static final int _SORT_BY_DISTANCE = 0;
    public static final int _SORT_BY_HOT = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f21a;

    /* JADX INFO: renamed from: b */
    private static POI_SORT_METHOD[] f22b;

    /* JADX INFO: renamed from: c */
    private int f23c;

    /* JADX INFO: renamed from: d */
    private String f24d;

    static {
        f21a = !POI_SORT_METHOD.class.desiredAssertionStatus();
        f22b = new POI_SORT_METHOD[2];
        SORT_BY_DISTANCE = new POI_SORT_METHOD(0, 0, "SORT_BY_DISTANCE");
        SORT_BY_HOT = new POI_SORT_METHOD(1, 1, "SORT_BY_HOT");
    }

    private POI_SORT_METHOD(int i, int i2, String str) {
        this.f24d = new String();
        this.f24d = str;
        this.f23c = i2;
        f22b[i] = this;
    }

    public static POI_SORT_METHOD convert(int i) {
        for (int i2 = 0; i2 < f22b.length; i2++) {
            if (f22b[i2].value() == i) {
                return f22b[i2];
            }
        }
        if (f21a) {
            return null;
        }
        throw new AssertionError();
    }

    public static POI_SORT_METHOD convert(String str) {
        for (int i = 0; i < f22b.length; i++) {
            if (f22b[i].toString().equals(str)) {
                return f22b[i];
            }
        }
        if (f21a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f24d;
    }

    public final int value() {
        return this.f23c;
    }
}
