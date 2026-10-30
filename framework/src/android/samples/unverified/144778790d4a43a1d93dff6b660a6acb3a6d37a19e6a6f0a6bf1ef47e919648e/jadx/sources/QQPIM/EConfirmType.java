package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EConfirmType {
    public static final EConfirmType ECT_Confirm_Type_End;
    public static final EConfirmType ECT_Confirm_Type_None;
    public static final EConfirmType ECT_Confirm_Type_SecondChk;
    public static final int _ECT_Confirm_Type_End = 2;
    public static final int _ECT_Confirm_Type_None = 0;
    public static final int _ECT_Confirm_Type_SecondChk = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f179a;

    /* JADX INFO: renamed from: b */
    private static EConfirmType[] f180b;

    /* JADX INFO: renamed from: c */
    private int f181c;

    /* JADX INFO: renamed from: d */
    private String f182d;

    static {
        f179a = !EConfirmType.class.desiredAssertionStatus();
        f180b = new EConfirmType[3];
        ECT_Confirm_Type_None = new EConfirmType(0, 0, "ECT_Confirm_Type_None");
        ECT_Confirm_Type_SecondChk = new EConfirmType(1, 1, "ECT_Confirm_Type_SecondChk");
        ECT_Confirm_Type_End = new EConfirmType(2, 2, "ECT_Confirm_Type_End");
    }

    private EConfirmType(int i, int i2, String str) {
        this.f182d = new String();
        this.f182d = str;
        this.f181c = i2;
        f180b[i] = this;
    }

    public static EConfirmType convert(int i) {
        for (int i2 = 0; i2 < f180b.length; i2++) {
            if (f180b[i2].value() == i) {
                return f180b[i2];
            }
        }
        if (f179a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EConfirmType convert(String str) {
        for (int i = 0; i < f180b.length; i++) {
            if (f180b[i].toString().equals(str)) {
                return f180b[i];
            }
        }
        if (f179a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f182d;
    }

    public final int value() {
        return this.f181c;
    }
}
