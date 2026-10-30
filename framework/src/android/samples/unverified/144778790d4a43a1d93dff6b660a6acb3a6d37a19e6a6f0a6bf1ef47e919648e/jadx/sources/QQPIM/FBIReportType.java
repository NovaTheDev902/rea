package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class FBIReportType {
    public static final FBIReportType FBI_FEEDBACK;
    public static final FBIReportType FBI_REPORT;
    public static final int _FBI_FEEDBACK = 1;
    public static final int _FBI_REPORT = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f398a;

    /* JADX INFO: renamed from: b */
    private static FBIReportType[] f399b;

    /* JADX INFO: renamed from: c */
    private int f400c;

    /* JADX INFO: renamed from: d */
    private String f401d;

    static {
        f398a = !FBIReportType.class.desiredAssertionStatus();
        f399b = new FBIReportType[2];
        FBI_REPORT = new FBIReportType(0, 0, "FBI_REPORT");
        FBI_FEEDBACK = new FBIReportType(1, 1, "FBI_FEEDBACK");
    }

    private FBIReportType(int i, int i2, String str) {
        this.f401d = new String();
        this.f401d = str;
        this.f400c = i2;
        f399b[i] = this;
    }

    public static FBIReportType convert(int i) {
        for (int i2 = 0; i2 < f399b.length; i2++) {
            if (f399b[i2].value() == i) {
                return f399b[i2];
            }
        }
        if (f398a) {
            return null;
        }
        throw new AssertionError();
    }

    public static FBIReportType convert(String str) {
        for (int i = 0; i < f399b.length; i++) {
            if (f399b[i].toString().equals(str)) {
                return f399b[i];
            }
        }
        if (f398a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f401d;
    }

    public final int value() {
        return this.f400c;
    }
}
