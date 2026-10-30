package LBSAPIProtocol;

/* JADX INFO: loaded from: classes.dex */
public final class GPSTYPE {
    public static final GPSTYPE GPS_MARS;
    public static final GPSTYPE GPS_WGS84;
    public static final GPSTYPE GPS_WGS_REAL;
    public static final int _GPS_MARS = 1;
    public static final int _GPS_WGS84 = 0;
    public static final int _GPS_WGS_REAL = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f9a;

    /* JADX INFO: renamed from: b */
    private static GPSTYPE[] f10b;

    /* JADX INFO: renamed from: c */
    private int f11c;

    /* JADX INFO: renamed from: d */
    private String f12d;

    static {
        f9a = !GPSTYPE.class.desiredAssertionStatus();
        f10b = new GPSTYPE[3];
        GPS_WGS84 = new GPSTYPE(0, 0, "GPS_WGS84");
        GPS_MARS = new GPSTYPE(1, 1, "GPS_MARS");
        GPS_WGS_REAL = new GPSTYPE(2, 2, "GPS_WGS_REAL");
    }

    private GPSTYPE(int i, int i2, String str) {
        this.f12d = new String();
        this.f12d = str;
        this.f11c = i2;
        f10b[i] = this;
    }

    public static GPSTYPE convert(int i) {
        for (int i2 = 0; i2 < f10b.length; i2++) {
            if (f10b[i2].value() == i) {
                return f10b[i2];
            }
        }
        if (f9a) {
            return null;
        }
        throw new AssertionError();
    }

    public static GPSTYPE convert(String str) {
        for (int i = 0; i < f10b.length; i++) {
            if (f10b[i].toString().equals(str)) {
                return f10b[i];
            }
        }
        if (f9a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f12d;
    }

    public final int value() {
        return this.f11c;
    }
}
