package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EConditionBit {
    public static final EConditionBit ECB_End;
    public static final EConditionBit ECB_IsBindQQ;
    public static final EConditionBit ECB_IsQxinOpen;
    public static final EConditionBit ECB_IsSetEntrance;
    public static final EConditionBit ECB_None;
    public static final int _ECB_End = 33;
    public static final int _ECB_IsBindQQ = 2;
    public static final int _ECB_IsQxinOpen = 1;
    public static final int _ECB_IsSetEntrance = 3;
    public static final int _ECB_None = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f175a;

    /* JADX INFO: renamed from: b */
    private static EConditionBit[] f176b;

    /* JADX INFO: renamed from: c */
    private int f177c;

    /* JADX INFO: renamed from: d */
    private String f178d;

    static {
        f175a = !EConditionBit.class.desiredAssertionStatus();
        f176b = new EConditionBit[5];
        ECB_None = new EConditionBit(0, 0, "ECB_None");
        ECB_IsQxinOpen = new EConditionBit(1, 1, "ECB_IsQxinOpen");
        ECB_IsBindQQ = new EConditionBit(2, 2, "ECB_IsBindQQ");
        ECB_IsSetEntrance = new EConditionBit(3, 3, "ECB_IsSetEntrance");
        ECB_End = new EConditionBit(4, 33, "ECB_End");
    }

    private EConditionBit(int i, int i2, String str) {
        this.f178d = new String();
        this.f178d = str;
        this.f177c = i2;
        f176b[i] = this;
    }

    public static EConditionBit convert(int i) {
        for (int i2 = 0; i2 < f176b.length; i2++) {
            if (f176b[i2].value() == i) {
                return f176b[i2];
            }
        }
        if (f175a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EConditionBit convert(String str) {
        for (int i = 0; i < f176b.length; i++) {
            if (f176b[i].toString().equals(str)) {
                return f176b[i];
            }
        }
        if (f175a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f178d;
    }

    public final int value() {
        return this.f177c;
    }
}
