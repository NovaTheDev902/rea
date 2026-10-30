package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ESmsAuditType {
    public static final ESmsAuditType EMSAT_BLACK;
    public static final ESmsAuditType EMSAT_CHARGE_INTERCEPT;
    public static final ESmsAuditType EMSAT_CONTENT_TOO_SHORT;
    public static final ESmsAuditType EMSAT_DOUBT;
    public static final ESmsAuditType EMSAT_DOUBT_INTERCEPT;
    public static final ESmsAuditType EMSAT_MAX;
    public static final ESmsAuditType EMSAT_NORMAL;
    public static final ESmsAuditType EMSAT_UNKNOWN;
    public static final ESmsAuditType EMSAT_WHITE;
    public static final ESmsAuditType MSAT_MIN;
    public static final int _EMSAT_BLACK = 3;
    public static final int _EMSAT_CHARGE_INTERCEPT = 8;
    public static final int _EMSAT_CONTENT_TOO_SHORT = 7;
    public static final int _EMSAT_DOUBT = 4;
    public static final int _EMSAT_DOUBT_INTERCEPT = 6;
    public static final int _EMSAT_MAX = 9;
    public static final int _EMSAT_NORMAL = 1;
    public static final int _EMSAT_UNKNOWN = 5;
    public static final int _EMSAT_WHITE = 2;
    public static final int _MSAT_MIN = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f329a;

    /* JADX INFO: renamed from: b */
    private static ESmsAuditType[] f330b;

    /* JADX INFO: renamed from: c */
    private int f331c;

    /* JADX INFO: renamed from: d */
    private String f332d;

    static {
        f329a = !ESmsAuditType.class.desiredAssertionStatus();
        f330b = new ESmsAuditType[10];
        MSAT_MIN = new ESmsAuditType(0, 0, "MSAT_MIN");
        EMSAT_NORMAL = new ESmsAuditType(1, 1, "EMSAT_NORMAL");
        EMSAT_WHITE = new ESmsAuditType(2, 2, "EMSAT_WHITE");
        EMSAT_BLACK = new ESmsAuditType(3, 3, "EMSAT_BLACK");
        EMSAT_DOUBT = new ESmsAuditType(4, 4, "EMSAT_DOUBT");
        EMSAT_UNKNOWN = new ESmsAuditType(5, 5, "EMSAT_UNKNOWN");
        EMSAT_DOUBT_INTERCEPT = new ESmsAuditType(6, 6, "EMSAT_DOUBT_INTERCEPT");
        EMSAT_CONTENT_TOO_SHORT = new ESmsAuditType(7, 7, "EMSAT_CONTENT_TOO_SHORT");
        EMSAT_CHARGE_INTERCEPT = new ESmsAuditType(8, 8, "EMSAT_CHARGE_INTERCEPT");
        EMSAT_MAX = new ESmsAuditType(9, 9, "EMSAT_MAX");
    }

    private ESmsAuditType(int i, int i2, String str) {
        this.f332d = new String();
        this.f332d = str;
        this.f331c = i2;
        f330b[i] = this;
    }

    public static ESmsAuditType convert(int i) {
        for (int i2 = 0; i2 < f330b.length; i2++) {
            if (f330b[i2].value() == i) {
                return f330b[i2];
            }
        }
        if (f329a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ESmsAuditType convert(String str) {
        for (int i = 0; i < f330b.length; i++) {
            if (f330b[i].toString().equals(str)) {
                return f330b[i];
            }
        }
        if (f329a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f332d;
    }

    public final int value() {
        return this.f331c;
    }
}
