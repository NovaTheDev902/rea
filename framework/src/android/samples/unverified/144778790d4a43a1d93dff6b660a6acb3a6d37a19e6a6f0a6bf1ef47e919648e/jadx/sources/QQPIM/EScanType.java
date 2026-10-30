package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EScanType {
    public static final EScanType ST_Apk;
    public static final EScanType ST_END;
    public static final EScanType ST_File;
    public static final EScanType ST_NONE;
    public static final int _ST_Apk = 1;
    public static final int _ST_END = 3;
    public static final int _ST_File = 2;
    public static final int _ST_NONE = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f321a;

    /* JADX INFO: renamed from: b */
    private static EScanType[] f322b;

    /* JADX INFO: renamed from: c */
    private int f323c;

    /* JADX INFO: renamed from: d */
    private String f324d;

    static {
        f321a = !EScanType.class.desiredAssertionStatus();
        f322b = new EScanType[4];
        ST_NONE = new EScanType(0, 0, "ST_NONE");
        ST_Apk = new EScanType(1, 1, "ST_Apk");
        ST_File = new EScanType(2, 2, "ST_File");
        ST_END = new EScanType(3, 3, "ST_END");
    }

    private EScanType(int i, int i2, String str) {
        this.f324d = new String();
        this.f324d = str;
        this.f323c = i2;
        f322b[i] = this;
    }

    public static EScanType convert(int i) {
        for (int i2 = 0; i2 < f322b.length; i2++) {
            if (f322b[i2].value() == i) {
                return f322b[i2];
            }
        }
        if (f321a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EScanType convert(String str) {
        for (int i = 0; i < f322b.length; i++) {
            if (f322b[i].toString().equals(str)) {
                return f322b[i];
            }
        }
        if (f321a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f324d;
    }

    public final int value() {
        return this.f323c;
    }
}
