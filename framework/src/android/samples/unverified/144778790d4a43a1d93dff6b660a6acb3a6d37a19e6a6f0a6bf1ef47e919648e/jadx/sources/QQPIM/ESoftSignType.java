package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ESoftSignType {
    public static final ESoftSignType SIGN_FIRST;
    public static final ESoftSignType SIGN_HOT;
    public static final ESoftSignType SIGN_NEW;
    public static final ESoftSignType SIGN_NONE;
    public static final ESoftSignType SIGN_REC;
    public static final int _SIGN_FIRST = 4;
    public static final int _SIGN_HOT = 3;
    public static final int _SIGN_NEW = 1;
    public static final int _SIGN_NONE = 0;
    public static final int _SIGN_REC = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f341a;

    /* JADX INFO: renamed from: b */
    private static ESoftSignType[] f342b;

    /* JADX INFO: renamed from: c */
    private int f343c;

    /* JADX INFO: renamed from: d */
    private String f344d;

    static {
        f341a = !ESoftSignType.class.desiredAssertionStatus();
        f342b = new ESoftSignType[5];
        SIGN_NONE = new ESoftSignType(0, 0, "SIGN_NONE");
        SIGN_NEW = new ESoftSignType(1, 1, "SIGN_NEW");
        SIGN_REC = new ESoftSignType(2, 2, "SIGN_REC");
        SIGN_HOT = new ESoftSignType(3, 3, "SIGN_HOT");
        SIGN_FIRST = new ESoftSignType(4, 4, "SIGN_FIRST");
    }

    private ESoftSignType(int i, int i2, String str) {
        this.f344d = new String();
        this.f344d = str;
        this.f343c = i2;
        f342b[i] = this;
    }

    public static ESoftSignType convert(int i) {
        for (int i2 = 0; i2 < f342b.length; i2++) {
            if (f342b[i2].value() == i) {
                return f342b[i2];
            }
        }
        if (f341a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ESoftSignType convert(String str) {
        for (int i = 0; i < f342b.length; i++) {
            if (f342b[i].toString().equals(str)) {
                return f342b[i];
            }
        }
        if (f341a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f344d;
    }

    public final int value() {
        return this.f343c;
    }
}
