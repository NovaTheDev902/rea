package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ETipsUserAction {
    public static final ETipsUserAction ETT_Reject;
    public static final ETipsUserAction ETUA_Accept;
    public static final int _ETT_Reject = 2;
    public static final int _ETUA_Accept = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f365a;

    /* JADX INFO: renamed from: b */
    private static ETipsUserAction[] f366b;

    /* JADX INFO: renamed from: c */
    private int f367c;

    /* JADX INFO: renamed from: d */
    private String f368d;

    static {
        f365a = !ETipsUserAction.class.desiredAssertionStatus();
        f366b = new ETipsUserAction[2];
        ETUA_Accept = new ETipsUserAction(0, 1, "ETUA_Accept");
        ETT_Reject = new ETipsUserAction(1, 2, "ETT_Reject");
    }

    private ETipsUserAction(int i, int i2, String str) {
        this.f368d = new String();
        this.f368d = str;
        this.f367c = i2;
        f366b[i] = this;
    }

    public static ETipsUserAction convert(int i) {
        for (int i2 = 0; i2 < f366b.length; i2++) {
            if (f366b[i2].value() == i) {
                return f366b[i2];
            }
        }
        if (f365a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ETipsUserAction convert(String str) {
        for (int i = 0; i < f366b.length; i++) {
            if (f366b[i].toString().equals(str)) {
                return f366b[i];
            }
        }
        if (f365a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f368d;
    }

    public final int value() {
        return this.f367c;
    }
}
