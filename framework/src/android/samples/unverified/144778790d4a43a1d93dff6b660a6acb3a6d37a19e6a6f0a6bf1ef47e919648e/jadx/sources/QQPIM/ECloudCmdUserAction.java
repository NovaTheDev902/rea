package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ECloudCmdUserAction {
    public static final ECloudCmdUserAction EUA_Accept;
    public static final ECloudCmdUserAction EUA_None;
    public static final ECloudCmdUserAction EUA_Reject;
    public static final int _EUA_Accept = 1;
    public static final int _EUA_None = 0;
    public static final int _EUA_Reject = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f167a;

    /* JADX INFO: renamed from: b */
    private static ECloudCmdUserAction[] f168b;

    /* JADX INFO: renamed from: c */
    private int f169c;

    /* JADX INFO: renamed from: d */
    private String f170d;

    static {
        f167a = !ECloudCmdUserAction.class.desiredAssertionStatus();
        f168b = new ECloudCmdUserAction[3];
        EUA_None = new ECloudCmdUserAction(0, 0, "EUA_None");
        EUA_Accept = new ECloudCmdUserAction(1, 1, "EUA_Accept");
        EUA_Reject = new ECloudCmdUserAction(2, 2, "EUA_Reject");
    }

    private ECloudCmdUserAction(int i, int i2, String str) {
        this.f170d = new String();
        this.f170d = str;
        this.f169c = i2;
        f168b[i] = this;
    }

    public static ECloudCmdUserAction convert(int i) {
        for (int i2 = 0; i2 < f168b.length; i2++) {
            if (f168b[i2].value() == i) {
                return f168b[i2];
            }
        }
        if (f167a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ECloudCmdUserAction convert(String str) {
        for (int i = 0; i < f168b.length; i++) {
            if (f168b[i].toString().equals(str)) {
                return f168b[i];
            }
        }
        if (f167a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f170d;
    }

    public final int value() {
        return this.f169c;
    }
}
