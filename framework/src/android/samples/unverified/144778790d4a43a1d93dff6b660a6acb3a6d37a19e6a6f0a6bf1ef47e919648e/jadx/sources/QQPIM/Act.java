package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class Act {
    public static final Act E_ACT_CHANGE_CODE;
    public static final Act E_ACT_CHANGE_TIME;
    public static final Act E_ACT_CLOSE;
    public static final Act E_ACT_FREQUNCY;
    public static final Act E_ACT_MAX;
    public static final Act E_ACT_MIN;
    public static final Act E_ACT_NOTHING;
    public static final Act E_ACT_REVISE_IMMEDI;
    public static final Act E_ACT_UPDATE_CODE;
    public static final int _E_ACT_CHANGE_CODE = 4;
    public static final int _E_ACT_CHANGE_TIME = 7;
    public static final int _E_ACT_CLOSE = 5;
    public static final int _E_ACT_FREQUNCY = 2;
    public static final int _E_ACT_MAX = 8;
    public static final int _E_ACT_MIN = 0;
    public static final int _E_ACT_NOTHING = 1;
    public static final int _E_ACT_REVISE_IMMEDI = 6;
    public static final int _E_ACT_UPDATE_CODE = 3;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f64a;

    /* JADX INFO: renamed from: b */
    private static Act[] f65b;

    /* JADX INFO: renamed from: c */
    private int f66c;

    /* JADX INFO: renamed from: d */
    private String f67d;

    static {
        f64a = !Act.class.desiredAssertionStatus();
        f65b = new Act[9];
        E_ACT_MIN = new Act(0, 0, "E_ACT_MIN");
        E_ACT_NOTHING = new Act(1, 1, "E_ACT_NOTHING");
        E_ACT_FREQUNCY = new Act(2, 2, "E_ACT_FREQUNCY");
        E_ACT_UPDATE_CODE = new Act(3, 3, "E_ACT_UPDATE_CODE");
        E_ACT_CHANGE_CODE = new Act(4, 4, "E_ACT_CHANGE_CODE");
        E_ACT_CLOSE = new Act(5, 5, "E_ACT_CLOSE");
        E_ACT_REVISE_IMMEDI = new Act(6, 6, "E_ACT_REVISE_IMMEDI");
        E_ACT_CHANGE_TIME = new Act(7, 7, "E_ACT_CHANGE_TIME");
        E_ACT_MAX = new Act(8, 8, "E_ACT_MAX");
    }

    private Act(int i, int i2, String str) {
        this.f67d = new String();
        this.f67d = str;
        this.f66c = i2;
        f65b[i] = this;
    }

    public static Act convert(int i) {
        for (int i2 = 0; i2 < f65b.length; i2++) {
            if (f65b[i2].value() == i) {
                return f65b[i2];
            }
        }
        if (f64a) {
            return null;
        }
        throw new AssertionError();
    }

    public static Act convert(String str) {
        for (int i = 0; i < f65b.length; i++) {
            if (f65b[i].toString().equals(str)) {
                return f65b[i];
            }
        }
        if (f64a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f67d;
    }

    public final int value() {
        return this.f66c;
    }
}
