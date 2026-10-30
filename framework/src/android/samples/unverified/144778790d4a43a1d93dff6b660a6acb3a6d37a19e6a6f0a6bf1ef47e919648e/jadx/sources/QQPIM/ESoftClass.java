package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ESoftClass {
    public static final ESoftClass ESC_Dangerous;
    public static final ESoftClass ESC_NONE;
    public static final ESoftClass ESC_Rogue;
    public static final ESoftClass ESC_System_Cannot_Delete;
    public static final ESoftClass ESC_Trust;
    public static final ESoftClass ESC_Virus;
    public static final int _ESC_Dangerous = 4;
    public static final int _ESC_NONE = 0;
    public static final int _ESC_Rogue = 2;
    public static final int _ESC_System_Cannot_Delete = 5;
    public static final int _ESC_Trust = 1;
    public static final int _ESC_Virus = 3;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f337a;

    /* JADX INFO: renamed from: b */
    private static ESoftClass[] f338b;

    /* JADX INFO: renamed from: c */
    private int f339c;

    /* JADX INFO: renamed from: d */
    private String f340d;

    static {
        f337a = !ESoftClass.class.desiredAssertionStatus();
        f338b = new ESoftClass[6];
        ESC_NONE = new ESoftClass(0, 0, "ESC_NONE");
        ESC_Trust = new ESoftClass(1, 1, "ESC_Trust");
        ESC_Rogue = new ESoftClass(2, 2, "ESC_Rogue");
        ESC_Virus = new ESoftClass(3, 3, "ESC_Virus");
        ESC_Dangerous = new ESoftClass(4, 4, "ESC_Dangerous");
        ESC_System_Cannot_Delete = new ESoftClass(5, 5, "ESC_System_Cannot_Delete");
    }

    private ESoftClass(int i, int i2, String str) {
        this.f340d = new String();
        this.f340d = str;
        this.f339c = i2;
        f338b[i] = this;
    }

    public static ESoftClass convert(int i) {
        for (int i2 = 0; i2 < f338b.length; i2++) {
            if (f338b[i2].value() == i) {
                return f338b[i2];
            }
        }
        if (f337a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ESoftClass convert(String str) {
        for (int i = 0; i < f338b.length; i++) {
            if (f338b[i].toString().equals(str)) {
                return f338b[i];
            }
        }
        if (f337a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f340d;
    }

    public final int value() {
        return this.f339c;
    }
}
