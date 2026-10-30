package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ECProduct {
    public static final ECProduct ECP_END;
    public static final ECProduct ECP_HIPhonebook;
    public static final ECProduct ECP_None;
    public static final ECProduct ECP_Phonebook;
    public static final ECProduct ECP_Pim;
    public static final ECProduct ECP_Secure;
    public static final int _ECP_END = 5;
    public static final int _ECP_HIPhonebook = 4;
    public static final int _ECP_None = 0;
    public static final int _ECP_Phonebook = 2;
    public static final int _ECP_Pim = 3;
    public static final int _ECP_Secure = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f151a;

    /* JADX INFO: renamed from: b */
    private static ECProduct[] f152b;

    /* JADX INFO: renamed from: c */
    private int f153c;

    /* JADX INFO: renamed from: d */
    private String f154d;

    static {
        f151a = !ECProduct.class.desiredAssertionStatus();
        f152b = new ECProduct[6];
        ECP_None = new ECProduct(0, 0, "ECP_None");
        ECP_Secure = new ECProduct(1, 1, "ECP_Secure");
        ECP_Phonebook = new ECProduct(2, 2, "ECP_Phonebook");
        ECP_Pim = new ECProduct(3, 3, "ECP_Pim");
        ECP_HIPhonebook = new ECProduct(4, 4, "ECP_HIPhonebook");
        ECP_END = new ECProduct(5, 5, "ECP_END");
    }

    private ECProduct(int i, int i2, String str) {
        this.f154d = new String();
        this.f154d = str;
        this.f153c = i2;
        f152b[i] = this;
    }

    public static ECProduct convert(int i) {
        for (int i2 = 0; i2 < f152b.length; i2++) {
            if (f152b[i2].value() == i) {
                return f152b[i2];
            }
        }
        if (f151a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ECProduct convert(String str) {
        for (int i = 0; i < f152b.length; i++) {
            if (f152b[i].toString().equals(str)) {
                return f152b[i];
            }
        }
        if (f151a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f154d;
    }

    public final int value() {
        return this.f153c;
    }
}
