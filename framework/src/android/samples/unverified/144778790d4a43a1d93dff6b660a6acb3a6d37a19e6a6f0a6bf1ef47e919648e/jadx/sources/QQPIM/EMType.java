package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EMType {
    public static final EMType MT_AreaCode;
    public static final EMType MT_CountryCode;
    public static final EMType MT_Mobile;
    public static final int _MT_AreaCode = 1;
    public static final int _MT_CountryCode = 2;
    public static final int _MT_Mobile = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f215a;

    /* JADX INFO: renamed from: b */
    private static EMType[] f216b;

    /* JADX INFO: renamed from: c */
    private int f217c;

    /* JADX INFO: renamed from: d */
    private String f218d;

    static {
        f215a = !EMType.class.desiredAssertionStatus();
        f216b = new EMType[3];
        MT_Mobile = new EMType(0, 0, "MT_Mobile");
        MT_AreaCode = new EMType(1, 1, "MT_AreaCode");
        MT_CountryCode = new EMType(2, 2, "MT_CountryCode");
    }

    private EMType(int i, int i2, String str) {
        this.f218d = new String();
        this.f218d = str;
        this.f217c = i2;
        f216b[i] = this;
    }

    public static EMType convert(int i) {
        for (int i2 = 0; i2 < f216b.length; i2++) {
            if (f216b[i2].value() == i) {
                return f216b[i2];
            }
        }
        if (f215a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EMType convert(String str) {
        for (int i = 0; i < f216b.length; i++) {
            if (f216b[i].toString().equals(str)) {
                return f216b[i];
            }
        }
        if (f215a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f218d;
    }

    public final int value() {
        return this.f217c;
    }
}
