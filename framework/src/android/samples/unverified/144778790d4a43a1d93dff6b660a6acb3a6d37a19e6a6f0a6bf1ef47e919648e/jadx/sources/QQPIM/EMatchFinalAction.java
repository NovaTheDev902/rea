package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EMatchFinalAction {
    public static final EMatchFinalAction EM_FINAL_ACTION_DOUBT;
    public static final EMatchFinalAction EM_FINAL_ACTION_INTERCEPT;
    public static final EMatchFinalAction EM_FINAL_ACTION_MAX;
    public static final EMatchFinalAction EM_FINAL_ACTION_MIN;
    public static final EMatchFinalAction EM_FINAL_ACTION_PASS;
    public static final int _EM_FINAL_ACTION_DOUBT = 3;
    public static final int _EM_FINAL_ACTION_INTERCEPT = 2;
    public static final int _EM_FINAL_ACTION_MAX = 4;
    public static final int _EM_FINAL_ACTION_MIN = 0;
    public static final int _EM_FINAL_ACTION_PASS = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f231a;

    /* JADX INFO: renamed from: b */
    private static EMatchFinalAction[] f232b;

    /* JADX INFO: renamed from: c */
    private int f233c;

    /* JADX INFO: renamed from: d */
    private String f234d;

    static {
        f231a = !EMatchFinalAction.class.desiredAssertionStatus();
        f232b = new EMatchFinalAction[5];
        EM_FINAL_ACTION_MIN = new EMatchFinalAction(0, 0, "EM_FINAL_ACTION_MIN");
        EM_FINAL_ACTION_PASS = new EMatchFinalAction(1, 1, "EM_FINAL_ACTION_PASS");
        EM_FINAL_ACTION_INTERCEPT = new EMatchFinalAction(2, 2, "EM_FINAL_ACTION_INTERCEPT");
        EM_FINAL_ACTION_DOUBT = new EMatchFinalAction(3, 3, "EM_FINAL_ACTION_DOUBT");
        EM_FINAL_ACTION_MAX = new EMatchFinalAction(4, 4, "EM_FINAL_ACTION_MAX");
    }

    private EMatchFinalAction(int i, int i2, String str) {
        this.f234d = new String();
        this.f234d = str;
        this.f233c = i2;
        f232b[i] = this;
    }

    public static EMatchFinalAction convert(int i) {
        for (int i2 = 0; i2 < f232b.length; i2++) {
            if (f232b[i2].value() == i) {
                return f232b[i2];
            }
        }
        if (f231a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EMatchFinalAction convert(String str) {
        for (int i = 0; i < f232b.length; i++) {
            if (f232b[i].toString().equals(str)) {
                return f232b[i];
            }
        }
        if (f231a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f234d;
    }

    public final int value() {
        return this.f233c;
    }
}
