package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EActionType {
    public static final EActionType EAT_Call;
    public static final EActionType EAT_NONE;
    public static final EActionType EAT_ReadContact;
    public static final EActionType EAT_ReadGps;
    public static final EActionType EAT_ReadIMEI;
    public static final EActionType EAT_ReadIMSI;
    public static final EActionType EAT_ReadLog;
    public static final EActionType EAT_ReadSMS;
    public static final EActionType EAT_RequestRoot;
    public static final EActionType EAT_SendSMS;
    public static final EActionType EAT_ShowAd;
    public static final int _EAT_Call = 2;
    public static final int _EAT_NONE = 0;
    public static final int _EAT_ReadContact = 4;
    public static final int _EAT_ReadGps = 8;
    public static final int _EAT_ReadIMEI = 6;
    public static final int _EAT_ReadIMSI = 7;
    public static final int _EAT_ReadLog = 5;
    public static final int _EAT_ReadSMS = 3;
    public static final int _EAT_RequestRoot = 9;
    public static final int _EAT_SendSMS = 1;
    public static final int _EAT_ShowAd = 10;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f139a;

    /* JADX INFO: renamed from: b */
    private static EActionType[] f140b;

    /* JADX INFO: renamed from: c */
    private int f141c;

    /* JADX INFO: renamed from: d */
    private String f142d;

    static {
        f139a = !EActionType.class.desiredAssertionStatus();
        f140b = new EActionType[11];
        EAT_NONE = new EActionType(0, 0, "EAT_NONE");
        EAT_SendSMS = new EActionType(1, 1, "EAT_SendSMS");
        EAT_Call = new EActionType(2, 2, "EAT_Call");
        EAT_ReadSMS = new EActionType(3, 3, "EAT_ReadSMS");
        EAT_ReadContact = new EActionType(4, 4, "EAT_ReadContact");
        EAT_ReadLog = new EActionType(5, 5, "EAT_ReadLog");
        EAT_ReadIMEI = new EActionType(6, 6, "EAT_ReadIMEI");
        EAT_ReadIMSI = new EActionType(7, 7, "EAT_ReadIMSI");
        EAT_ReadGps = new EActionType(8, 8, "EAT_ReadGps");
        EAT_RequestRoot = new EActionType(9, 9, "EAT_RequestRoot");
        EAT_ShowAd = new EActionType(10, 10, "EAT_ShowAd");
    }

    private EActionType(int i, int i2, String str) {
        this.f142d = new String();
        this.f142d = str;
        this.f141c = i2;
        f140b[i] = this;
    }

    public static EActionType convert(int i) {
        for (int i2 = 0; i2 < f140b.length; i2++) {
            if (f140b[i2].value() == i) {
                return f140b[i2];
            }
        }
        if (f139a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EActionType convert(String str) {
        for (int i = 0; i < f140b.length; i++) {
            if (f140b[i].toString().equals(str)) {
                return f140b[i];
            }
        }
        if (f139a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f142d;
    }

    public final int value() {
        return this.f141c;
    }
}
