package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EGetDataType {
    public static final EGetDataType MGDT_BData;
    public static final EGetDataType MGDT_Url;
    public static final int _MGDT_BData = 1;
    public static final int _MGDT_Url = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f187a;

    /* JADX INFO: renamed from: b */
    private static EGetDataType[] f188b;

    /* JADX INFO: renamed from: c */
    private int f189c;

    /* JADX INFO: renamed from: d */
    private String f190d;

    static {
        f187a = !EGetDataType.class.desiredAssertionStatus();
        f188b = new EGetDataType[2];
        MGDT_Url = new EGetDataType(0, 0, "MGDT_Url");
        MGDT_BData = new EGetDataType(1, 1, "MGDT_BData");
    }

    private EGetDataType(int i, int i2, String str) {
        this.f190d = new String();
        this.f190d = str;
        this.f189c = i2;
        f188b[i] = this;
    }

    public static EGetDataType convert(int i) {
        for (int i2 = 0; i2 < f188b.length; i2++) {
            if (f188b[i2].value() == i) {
                return f188b[i2];
            }
        }
        if (f187a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EGetDataType convert(String str) {
        for (int i = 0; i < f188b.length; i++) {
            if (f188b[i].toString().equals(str)) {
                return f188b[i];
            }
        }
        if (f187a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f190d;
    }

    public final int value() {
        return this.f189c;
    }
}
