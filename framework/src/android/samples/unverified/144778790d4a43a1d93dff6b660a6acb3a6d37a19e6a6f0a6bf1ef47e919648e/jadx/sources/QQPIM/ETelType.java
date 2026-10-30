package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ETelType {
    public static final ETelType ETT_MAX;
    public static final ETelType ETT_MIN;
    public static final ETelType ETT_MISS_CALL;
    public static final ETelType ETT_RING_ONE_SOUND;
    public static final ETelType ETT_USER_CANCEL;
    public static final ETelType ETT_USER_HANG_UP;
    public static final int _ETT_MAX = 5;
    public static final int _ETT_MIN = 0;
    public static final int _ETT_MISS_CALL = 3;
    public static final int _ETT_RING_ONE_SOUND = 1;
    public static final int _ETT_USER_CANCEL = 2;
    public static final int _ETT_USER_HANG_UP = 4;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f357a;

    /* JADX INFO: renamed from: b */
    private static ETelType[] f358b;

    /* JADX INFO: renamed from: c */
    private int f359c;

    /* JADX INFO: renamed from: d */
    private String f360d;

    static {
        f357a = !ETelType.class.desiredAssertionStatus();
        f358b = new ETelType[6];
        ETT_MIN = new ETelType(0, 0, "ETT_MIN");
        ETT_RING_ONE_SOUND = new ETelType(1, 1, "ETT_RING_ONE_SOUND");
        ETT_USER_CANCEL = new ETelType(2, 2, "ETT_USER_CANCEL");
        ETT_MISS_CALL = new ETelType(3, 3, "ETT_MISS_CALL");
        ETT_USER_HANG_UP = new ETelType(4, 4, "ETT_USER_HANG_UP");
        ETT_MAX = new ETelType(5, 5, "ETT_MAX");
    }

    private ETelType(int i, int i2, String str) {
        this.f360d = new String();
        this.f360d = str;
        this.f359c = i2;
        f358b[i] = this;
    }

    public static ETelType convert(int i) {
        for (int i2 = 0; i2 < f358b.length; i2++) {
            if (f358b[i2].value() == i) {
                return f358b[i2];
            }
        }
        if (f357a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ETelType convert(String str) {
        for (int i = 0; i < f358b.length; i++) {
            if (f358b[i].toString().equals(str)) {
                return f358b[i];
            }
        }
        if (f357a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f360d;
    }

    public final int value() {
        return this.f359c;
    }
}
