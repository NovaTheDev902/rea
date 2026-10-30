package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EMobileOperator {
    public static final EMobileOperator EMOP_End;
    public static final EMobileOperator EMOP_Mobile;
    public static final EMobileOperator EMOP_None;
    public static final EMobileOperator EMOP_Telecom;
    public static final EMobileOperator EMOP_Unicom;
    public static final int _EMOP_End = 4;
    public static final int _EMOP_Mobile = 2;
    public static final int _EMOP_None = 0;
    public static final int _EMOP_Telecom = 3;
    public static final int _EMOP_Unicom = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f243a;

    /* JADX INFO: renamed from: b */
    private static EMobileOperator[] f244b;

    /* JADX INFO: renamed from: c */
    private int f245c;

    /* JADX INFO: renamed from: d */
    private String f246d;

    static {
        f243a = !EMobileOperator.class.desiredAssertionStatus();
        f244b = new EMobileOperator[5];
        EMOP_None = new EMobileOperator(0, 0, "EMOP_None");
        EMOP_Unicom = new EMobileOperator(1, 1, "EMOP_Unicom");
        EMOP_Mobile = new EMobileOperator(2, 2, "EMOP_Mobile");
        EMOP_Telecom = new EMobileOperator(3, 3, "EMOP_Telecom");
        EMOP_End = new EMobileOperator(4, 4, "EMOP_End");
    }

    private EMobileOperator(int i, int i2, String str) {
        this.f246d = new String();
        this.f246d = str;
        this.f245c = i2;
        f244b[i] = this;
    }

    public static EMobileOperator convert(int i) {
        for (int i2 = 0; i2 < f244b.length; i2++) {
            if (f244b[i2].value() == i) {
                return f244b[i2];
            }
        }
        if (f243a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EMobileOperator convert(String str) {
        for (int i = 0; i < f244b.length; i++) {
            if (f244b[i].toString().equals(str)) {
                return f244b[i];
            }
        }
        if (f243a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f246d;
    }

    public final int value() {
        return this.f245c;
    }
}
