package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ESP {
    public static final ESP SP_Mobile;
    public static final ESP SP_Telecom;
    public static final ESP SP_Unicom;
    public static final int _SP_Mobile = 0;
    public static final int _SP_Telecom = 2;
    public static final int _SP_Unicom = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f317a;

    /* JADX INFO: renamed from: b */
    private static ESP[] f318b;

    /* JADX INFO: renamed from: c */
    private int f319c;

    /* JADX INFO: renamed from: d */
    private String f320d;

    static {
        f317a = !ESP.class.desiredAssertionStatus();
        f318b = new ESP[3];
        SP_Mobile = new ESP(0, 0, "SP_Mobile");
        SP_Unicom = new ESP(1, 1, "SP_Unicom");
        SP_Telecom = new ESP(2, 2, "SP_Telecom");
    }

    private ESP(int i, int i2, String str) {
        this.f320d = new String();
        this.f320d = str;
        this.f319c = i2;
        f318b[i] = this;
    }

    public static ESP convert(int i) {
        for (int i2 = 0; i2 < f318b.length; i2++) {
            if (f318b[i2].value() == i) {
                return f318b[i2];
            }
        }
        if (f317a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ESP convert(String str) {
        for (int i = 0; i < f318b.length; i++) {
            if (f318b[i].toString().equals(str)) {
                return f318b[i];
            }
        }
        if (f317a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f320d;
    }

    public final int value() {
        return this.f319c;
    }
}
