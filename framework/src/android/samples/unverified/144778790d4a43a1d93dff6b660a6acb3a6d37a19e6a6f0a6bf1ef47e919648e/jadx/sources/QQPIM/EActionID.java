package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EActionID {
    public static final EActionID EAID_Cloud_Cmd;
    public static final EActionID EAID_Cloud_Info;
    public static final EActionID EAID_Config_No_Note_Update;
    public static final EActionID EAID_Config_Update;
    public static final EActionID EAID_END;
    public static final EActionID EAID_None;
    public static final EActionID EAID_Show_Promote;
    public static final EActionID EAID_Show_SecureWarn;
    public static final EActionID EAID_Show_Tips;
    public static final EActionID EAID_Soft_Force_Update;
    public static final EActionID EAID_Soft_No_Note_Update;
    public static final EActionID EAID_Soft_Update;
    public static final int _EAID_Cloud_Cmd = 30;
    public static final int _EAID_Cloud_Info = 19;
    public static final int _EAID_Config_No_Note_Update = 11;
    public static final int _EAID_Config_Update = 10;
    public static final int _EAID_END = 31;
    public static final int _EAID_None = 0;
    public static final int _EAID_Show_Promote = 21;
    public static final int _EAID_Show_SecureWarn = 22;
    public static final int _EAID_Show_Tips = 20;
    public static final int _EAID_Soft_Force_Update = 3;
    public static final int _EAID_Soft_No_Note_Update = 4;
    public static final int _EAID_Soft_Update = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f131a;

    /* JADX INFO: renamed from: b */
    private static EActionID[] f132b;

    /* JADX INFO: renamed from: c */
    private int f133c;

    /* JADX INFO: renamed from: d */
    private String f134d;

    static {
        f131a = !EActionID.class.desiredAssertionStatus();
        f132b = new EActionID[12];
        EAID_None = new EActionID(0, 0, "EAID_None");
        EAID_Soft_Update = new EActionID(1, 2, "EAID_Soft_Update");
        EAID_Soft_Force_Update = new EActionID(2, 3, "EAID_Soft_Force_Update");
        EAID_Soft_No_Note_Update = new EActionID(3, 4, "EAID_Soft_No_Note_Update");
        EAID_Config_Update = new EActionID(4, 10, "EAID_Config_Update");
        EAID_Config_No_Note_Update = new EActionID(5, 11, "EAID_Config_No_Note_Update");
        EAID_Cloud_Info = new EActionID(6, 19, "EAID_Cloud_Info");
        EAID_Show_Tips = new EActionID(7, 20, "EAID_Show_Tips");
        EAID_Show_Promote = new EActionID(8, 21, "EAID_Show_Promote");
        EAID_Show_SecureWarn = new EActionID(9, 22, "EAID_Show_SecureWarn");
        EAID_Cloud_Cmd = new EActionID(10, 30, "EAID_Cloud_Cmd");
        EAID_END = new EActionID(11, 31, "EAID_END");
    }

    private EActionID(int i, int i2, String str) {
        this.f134d = new String();
        this.f134d = str;
        this.f133c = i2;
        f132b[i] = this;
    }

    public static EActionID convert(int i) {
        for (int i2 = 0; i2 < f132b.length; i2++) {
            if (f132b[i2].value() == i) {
                return f132b[i2];
            }
        }
        if (f131a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EActionID convert(String str) {
        for (int i = 0; i < f132b.length; i++) {
            if (f132b[i].toString().equals(str)) {
                return f132b[i];
            }
        }
        if (f131a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f134d;
    }

    public final int value() {
        return this.f133c;
    }
}
