package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ECategorySignType {
    public static final ECategorySignType CSIGN_HOT;
    public static final ECategorySignType CSIGN_NEW;
    public static final ECategorySignType CSIGN_NONE;
    public static final ECategorySignType CSIGN_REC;
    public static final int _CSIGN_HOT = 3;
    public static final int _CSIGN_NEW = 1;
    public static final int _CSIGN_NONE = 0;
    public static final int _CSIGN_REC = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f159a;

    /* JADX INFO: renamed from: b */
    private static ECategorySignType[] f160b;

    /* JADX INFO: renamed from: c */
    private int f161c;

    /* JADX INFO: renamed from: d */
    private String f162d;

    static {
        f159a = !ECategorySignType.class.desiredAssertionStatus();
        f160b = new ECategorySignType[4];
        CSIGN_NONE = new ECategorySignType(0, 0, "CSIGN_NONE");
        CSIGN_NEW = new ECategorySignType(1, 1, "CSIGN_NEW");
        CSIGN_REC = new ECategorySignType(2, 2, "CSIGN_REC");
        CSIGN_HOT = new ECategorySignType(3, 3, "CSIGN_HOT");
    }

    private ECategorySignType(int i, int i2, String str) {
        this.f162d = new String();
        this.f162d = str;
        this.f161c = i2;
        f160b[i] = this;
    }

    public static ECategorySignType convert(int i) {
        for (int i2 = 0; i2 < f160b.length; i2++) {
            if (f160b[i2].value() == i) {
                return f160b[i2];
            }
        }
        if (f159a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ECategorySignType convert(String str) {
        for (int i = 0; i < f160b.length; i++) {
            if (f160b[i].toString().equals(str)) {
                return f160b[i];
            }
        }
        if (f159a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f162d;
    }

    public final int value() {
        return this.f161c;
    }
}
