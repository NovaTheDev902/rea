package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EAskType {
    public static final EAskType EAT_END;
    public static final EAskType EAT_None;
    public static final EAskType EAT_OK_Cancel;
    public static final EAskType EAT_Only_OK;
    public static final int _EAT_END = 3;
    public static final int _EAT_None = 0;
    public static final int _EAT_OK_Cancel = 2;
    public static final int _EAT_Only_OK = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f143a;

    /* JADX INFO: renamed from: b */
    private static EAskType[] f144b;

    /* JADX INFO: renamed from: c */
    private int f145c;

    /* JADX INFO: renamed from: d */
    private String f146d;

    static {
        f143a = !EAskType.class.desiredAssertionStatus();
        f144b = new EAskType[4];
        EAT_None = new EAskType(0, 0, "EAT_None");
        EAT_Only_OK = new EAskType(1, 1, "EAT_Only_OK");
        EAT_OK_Cancel = new EAskType(2, 2, "EAT_OK_Cancel");
        EAT_END = new EAskType(3, 3, "EAT_END");
    }

    private EAskType(int i, int i2, String str) {
        this.f146d = new String();
        this.f146d = str;
        this.f145c = i2;
        f144b[i] = this;
    }

    public static EAskType convert(int i) {
        for (int i2 = 0; i2 < f144b.length; i2++) {
            if (f144b[i2].value() == i) {
                return f144b[i2];
            }
        }
        if (f143a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EAskType convert(String str) {
        for (int i = 0; i < f144b.length; i++) {
            if (f144b[i].toString().equals(str)) {
                return f144b[i];
            }
        }
        if (f143a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f146d;
    }

    public final int value() {
        return this.f145c;
    }
}
