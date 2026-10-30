package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ECategoryPushType {
    public static final ECategoryPushType CPUSH_HIS;
    public static final ECategoryPushType CPUSH_NONE;
    public static final ECategoryPushType CPUSH_PUSH;
    public static final int _CPUSH_HIS = 2;
    public static final int _CPUSH_NONE = 0;
    public static final int _CPUSH_PUSH = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f155a;

    /* JADX INFO: renamed from: b */
    private static ECategoryPushType[] f156b;

    /* JADX INFO: renamed from: c */
    private int f157c;

    /* JADX INFO: renamed from: d */
    private String f158d;

    static {
        f155a = !ECategoryPushType.class.desiredAssertionStatus();
        f156b = new ECategoryPushType[3];
        CPUSH_NONE = new ECategoryPushType(0, 0, "CPUSH_NONE");
        CPUSH_PUSH = new ECategoryPushType(1, 1, "CPUSH_PUSH");
        CPUSH_HIS = new ECategoryPushType(2, 2, "CPUSH_HIS");
    }

    private ECategoryPushType(int i, int i2, String str) {
        this.f158d = new String();
        this.f158d = str;
        this.f157c = i2;
        f156b[i] = this;
    }

    public static ECategoryPushType convert(int i) {
        for (int i2 = 0; i2 < f156b.length; i2++) {
            if (f156b[i2].value() == i) {
                return f156b[i2];
            }
        }
        if (f155a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ECategoryPushType convert(String str) {
        for (int i = 0; i < f156b.length; i++) {
            if (f156b[i].toString().equals(str)) {
                return f156b[i];
            }
        }
        if (f155a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f158d;
    }

    public final int value() {
        return this.f157c;
    }
}
