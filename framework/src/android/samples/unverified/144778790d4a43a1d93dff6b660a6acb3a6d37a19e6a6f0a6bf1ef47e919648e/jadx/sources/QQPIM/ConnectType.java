package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ConnectType {
    public static final ConnectType CT_GPRS;
    public static final ConnectType CT_GPRS_NET;
    public static final ConnectType CT_GPRS_WAP;
    public static final ConnectType CT_NONE;
    public static final ConnectType CT_WIFI;
    public static final int _CT_GPRS = 1;
    public static final int _CT_GPRS_NET = 4;
    public static final int _CT_GPRS_WAP = 3;
    public static final int _CT_NONE = 0;
    public static final int _CT_WIFI = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f117a;

    /* JADX INFO: renamed from: b */
    private static ConnectType[] f118b;

    /* JADX INFO: renamed from: c */
    private int f119c;

    /* JADX INFO: renamed from: d */
    private String f120d;

    static {
        f117a = !ConnectType.class.desiredAssertionStatus();
        f118b = new ConnectType[5];
        CT_NONE = new ConnectType(0, 0, "CT_NONE");
        CT_GPRS = new ConnectType(1, 1, "CT_GPRS");
        CT_WIFI = new ConnectType(2, 2, "CT_WIFI");
        CT_GPRS_WAP = new ConnectType(3, 3, "CT_GPRS_WAP");
        CT_GPRS_NET = new ConnectType(4, 4, "CT_GPRS_NET");
    }

    private ConnectType(int i, int i2, String str) {
        this.f120d = new String();
        this.f120d = str;
        this.f119c = i2;
        f118b[i] = this;
    }

    public static ConnectType convert(int i) {
        for (int i2 = 0; i2 < f118b.length; i2++) {
            if (f118b[i2].value() == i) {
                return f118b[i2];
            }
        }
        if (f117a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ConnectType convert(String str) {
        for (int i = 0; i < f118b.length; i++) {
            if (f118b[i].toString().equals(str)) {
                return f118b[i];
            }
        }
        if (f117a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f120d;
    }

    public final int value() {
        return this.f119c;
    }
}
