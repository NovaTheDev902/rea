package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ERequestType {
    public static final ERequestType ERT_CloudCheck;
    public static final ERequestType ERT_GetSoftInfo;
    public static final ERequestType ERT_GetSoftInfoNoDesc;
    public static final ERequestType ERT_ReportAllSoft;
    public static final ERequestType ERT_ReportFeature;
    public static final ERequestType ERT_Report_Cloud_Get;
    public static final int _ERT_CloudCheck = 1;
    public static final int _ERT_GetSoftInfo = 2;
    public static final int _ERT_GetSoftInfoNoDesc = 4;
    public static final int _ERT_ReportAllSoft = 5;
    public static final int _ERT_ReportFeature = 0;
    public static final int _ERT_Report_Cloud_Get = 3;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f305a;

    /* JADX INFO: renamed from: b */
    private static ERequestType[] f306b;

    /* JADX INFO: renamed from: c */
    private int f307c;

    /* JADX INFO: renamed from: d */
    private String f308d;

    static {
        f305a = !ERequestType.class.desiredAssertionStatus();
        f306b = new ERequestType[6];
        ERT_ReportFeature = new ERequestType(0, 0, "ERT_ReportFeature");
        ERT_CloudCheck = new ERequestType(1, 1, "ERT_CloudCheck");
        ERT_GetSoftInfo = new ERequestType(2, 2, "ERT_GetSoftInfo");
        ERT_Report_Cloud_Get = new ERequestType(3, 3, "ERT_Report_Cloud_Get");
        ERT_GetSoftInfoNoDesc = new ERequestType(4, 4, "ERT_GetSoftInfoNoDesc");
        ERT_ReportAllSoft = new ERequestType(5, 5, "ERT_ReportAllSoft");
    }

    private ERequestType(int i, int i2, String str) {
        this.f308d = new String();
        this.f308d = str;
        this.f307c = i2;
        f306b[i] = this;
    }

    public static ERequestType convert(int i) {
        for (int i2 = 0; i2 < f306b.length; i2++) {
            if (f306b[i2].value() == i) {
                return f306b[i2];
            }
        }
        if (f305a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ERequestType convert(String str) {
        for (int i = 0; i < f306b.length; i++) {
            if (f306b[i].toString().equals(str)) {
                return f306b[i];
            }
        }
        if (f305a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f308d;
    }

    public final int value() {
        return this.f307c;
    }
}
