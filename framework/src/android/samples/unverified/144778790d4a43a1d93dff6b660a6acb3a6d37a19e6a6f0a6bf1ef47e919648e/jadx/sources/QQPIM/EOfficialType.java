package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EOfficialType {
    public static final EOfficialType OFFICIAL_NONE;
    public static final EOfficialType OFFICIAL_NOT;
    public static final EOfficialType OFFICIAL_YES;
    public static final int _OFFICIAL_NONE = 0;
    public static final int _OFFICIAL_NOT = 1;
    public static final int _OFFICIAL_YES = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f273a;

    /* JADX INFO: renamed from: b */
    private static EOfficialType[] f274b;

    /* JADX INFO: renamed from: c */
    private int f275c;

    /* JADX INFO: renamed from: d */
    private String f276d;

    static {
        f273a = !EOfficialType.class.desiredAssertionStatus();
        f274b = new EOfficialType[3];
        OFFICIAL_NONE = new EOfficialType(0, 0, "OFFICIAL_NONE");
        OFFICIAL_NOT = new EOfficialType(1, 1, "OFFICIAL_NOT");
        OFFICIAL_YES = new EOfficialType(2, 2, "OFFICIAL_YES");
    }

    private EOfficialType(int i, int i2, String str) {
        this.f276d = new String();
        this.f276d = str;
        this.f275c = i2;
        f274b[i] = this;
    }

    public static EOfficialType convert(int i) {
        for (int i2 = 0; i2 < f274b.length; i2++) {
            if (f274b[i2].value() == i) {
                return f274b[i2];
            }
        }
        if (f273a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EOfficialType convert(String str) {
        for (int i = 0; i < f274b.length; i++) {
            if (f274b[i].toString().equals(str)) {
                return f274b[i];
            }
        }
        if (f273a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f276d;
    }

    public final int value() {
        return this.f275c;
    }
}
