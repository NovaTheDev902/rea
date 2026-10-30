package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ERankType {
    public static final ERankType ERT_Model;
    public static final ERankType ERT_Total;
    public static final int _ERT_Model = 2;
    public static final int _ERT_Total = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f301a;

    /* JADX INFO: renamed from: b */
    private static ERankType[] f302b;

    /* JADX INFO: renamed from: c */
    private int f303c;

    /* JADX INFO: renamed from: d */
    private String f304d;

    static {
        f301a = !ERankType.class.desiredAssertionStatus();
        f302b = new ERankType[2];
        ERT_Total = new ERankType(0, 1, "ERT_Total");
        ERT_Model = new ERankType(1, 2, "ERT_Model");
    }

    private ERankType(int i, int i2, String str) {
        this.f304d = new String();
        this.f304d = str;
        this.f303c = i2;
        f302b[i] = this;
    }

    public static ERankType convert(int i) {
        for (int i2 = 0; i2 < f302b.length; i2++) {
            if (f302b[i2].value() == i) {
                return f302b[i2];
            }
        }
        if (f301a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ERankType convert(String str) {
        for (int i = 0; i < f302b.length; i++) {
            if (f302b[i].toString().equals(str)) {
                return f302b[i];
            }
        }
        if (f301a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f304d;
    }

    public final int value() {
        return this.f303c;
    }
}
