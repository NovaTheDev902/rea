package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ESoftState {
    public static final ESoftState ESS_None;
    public static final ESoftState ESS_Offshelf;
    public static final int _ESS_None = 0;
    public static final int _ESS_Offshelf = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f345a;

    /* JADX INFO: renamed from: b */
    private static ESoftState[] f346b;

    /* JADX INFO: renamed from: c */
    private int f347c;

    /* JADX INFO: renamed from: d */
    private String f348d;

    static {
        f345a = !ESoftState.class.desiredAssertionStatus();
        f346b = new ESoftState[2];
        ESS_None = new ESoftState(0, 0, "ESS_None");
        ESS_Offshelf = new ESoftState(1, 1, "ESS_Offshelf");
    }

    private ESoftState(int i, int i2, String str) {
        this.f348d = new String();
        this.f348d = str;
        this.f347c = i2;
        f346b[i] = this;
    }

    public static ESoftState convert(int i) {
        for (int i2 = 0; i2 < f346b.length; i2++) {
            if (f346b[i2].value() == i) {
                return f346b[i2];
            }
        }
        if (f345a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ESoftState convert(String str) {
        for (int i = 0; i < f346b.length; i++) {
            if (f346b[i].toString().equals(str)) {
                return f346b[i];
            }
        }
        if (f345a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f348d;
    }

    public final int value() {
        return this.f347c;
    }
}
