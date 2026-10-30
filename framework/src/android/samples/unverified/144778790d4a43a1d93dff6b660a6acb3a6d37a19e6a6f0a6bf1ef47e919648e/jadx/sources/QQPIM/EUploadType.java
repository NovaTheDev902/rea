package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EUploadType {
    public static final EUploadType EUT_Upload_Auto;
    public static final EUploadType EUT_Upload_End;
    public static final EUploadType EUT_Upload_None;
    public static final EUploadType EUT_Upload_Request;
    public static final int _EUT_Upload_Auto = 2;
    public static final int _EUT_Upload_End = 3;
    public static final int _EUT_Upload_None = 0;
    public static final int _EUT_Upload_Request = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f373a;

    /* JADX INFO: renamed from: b */
    private static EUploadType[] f374b;

    /* JADX INFO: renamed from: c */
    private int f375c;

    /* JADX INFO: renamed from: d */
    private String f376d;

    static {
        f373a = !EUploadType.class.desiredAssertionStatus();
        f374b = new EUploadType[4];
        EUT_Upload_None = new EUploadType(0, 0, "EUT_Upload_None");
        EUT_Upload_Request = new EUploadType(1, 1, "EUT_Upload_Request");
        EUT_Upload_Auto = new EUploadType(2, 2, "EUT_Upload_Auto");
        EUT_Upload_End = new EUploadType(3, 3, "EUT_Upload_End");
    }

    private EUploadType(int i, int i2, String str) {
        this.f376d = new String();
        this.f376d = str;
        this.f375c = i2;
        f374b[i] = this;
    }

    public static EUploadType convert(int i) {
        for (int i2 = 0; i2 < f374b.length; i2++) {
            if (f374b[i2].value() == i) {
                return f374b[i2];
            }
        }
        if (f373a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EUploadType convert(String str) {
        for (int i = 0; i < f374b.length; i++) {
            if (f374b[i].toString().equals(str)) {
                return f374b[i];
            }
        }
        if (f373a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f376d;
    }

    public final int value() {
        return this.f375c;
    }
}
