package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EImageSize {
    public static final EImageSize EIS_Big;
    public static final EImageSize EIS_End;
    public static final EImageSize EIS_Medium;
    public static final EImageSize EIS_None;
    public static final EImageSize EIS_Small;
    public static final EImageSize EIS_Thumbnail;
    public static final int _EIS_Big = 3;
    public static final int _EIS_End = 5;
    public static final int _EIS_Medium = 2;
    public static final int _EIS_None = 0;
    public static final int _EIS_Small = 1;
    public static final int _EIS_Thumbnail = 4;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f203a;

    /* JADX INFO: renamed from: b */
    private static EImageSize[] f204b;

    /* JADX INFO: renamed from: c */
    private int f205c;

    /* JADX INFO: renamed from: d */
    private String f206d;

    static {
        f203a = !EImageSize.class.desiredAssertionStatus();
        f204b = new EImageSize[6];
        EIS_None = new EImageSize(0, 0, "EIS_None");
        EIS_Small = new EImageSize(1, 1, "EIS_Small");
        EIS_Medium = new EImageSize(2, 2, "EIS_Medium");
        EIS_Big = new EImageSize(3, 3, "EIS_Big");
        EIS_Thumbnail = new EImageSize(4, 4, "EIS_Thumbnail");
        EIS_End = new EImageSize(5, 5, "EIS_End");
    }

    private EImageSize(int i, int i2, String str) {
        this.f206d = new String();
        this.f206d = str;
        this.f205c = i2;
        f204b[i] = this;
    }

    public static EImageSize convert(int i) {
        for (int i2 = 0; i2 < f204b.length; i2++) {
            if (f204b[i2].value() == i) {
                return f204b[i2];
            }
        }
        if (f203a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EImageSize convert(String str) {
        for (int i = 0; i < f204b.length; i++) {
            if (f204b[i].toString().equals(str)) {
                return f204b[i];
            }
        }
        if (f203a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f206d;
    }

    public final int value() {
        return this.f205c;
    }
}
