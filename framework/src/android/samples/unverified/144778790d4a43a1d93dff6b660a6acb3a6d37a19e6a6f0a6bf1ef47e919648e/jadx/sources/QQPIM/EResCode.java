package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EResCode {
    public static final EResCode ERC_Account_Err;
    public static final EResCode ERC_Account_Not_Actived;
    public static final EResCode ERC_Account_Not_Exist;
    public static final EResCode ERC_Account_Not_Valid;
    public static final EResCode ERC_Data_Get_Activity_Err;
    public static final EResCode ERC_Data_Get_Module_Err;
    public static final EResCode ERC_Data_Get_Person_Err;
    public static final EResCode ERC_Data_Init_Person_Err;
    public static final EResCode ERC_Data_Null;
    public static final EResCode ERC_ERROR;
    public static final EResCode ERC_OK;
    public static final EResCode ERC_Points_Expired;
    public static final EResCode ERC_Points_Expired_Client_Notice;
    public static final EResCode ERC_Points_Invalid;
    public static final EResCode ERC_Points_No_Enough;
    public static final EResCode ERC_Points_Ope_Invalid;
    public static final int _ERC_Account_Err = 201;
    public static final int _ERC_Account_Not_Actived = 202;
    public static final int _ERC_Account_Not_Exist = 204;
    public static final int _ERC_Account_Not_Valid = 203;
    public static final int _ERC_Data_Get_Activity_Err = 302;
    public static final int _ERC_Data_Get_Module_Err = 303;
    public static final int _ERC_Data_Get_Person_Err = 301;
    public static final int _ERC_Data_Init_Person_Err = 304;
    public static final int _ERC_Data_Null = 305;
    public static final int _ERC_ERROR = 1;
    public static final int _ERC_OK = 0;
    public static final int _ERC_Points_Expired = 104;
    public static final int _ERC_Points_Expired_Client_Notice = -104;
    public static final int _ERC_Points_Invalid = 102;
    public static final int _ERC_Points_No_Enough = 101;
    public static final int _ERC_Points_Ope_Invalid = 103;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f309a;

    /* JADX INFO: renamed from: b */
    private static EResCode[] f310b;

    /* JADX INFO: renamed from: c */
    private int f311c;

    /* JADX INFO: renamed from: d */
    private String f312d;

    static {
        f309a = !EResCode.class.desiredAssertionStatus();
        f310b = new EResCode[16];
        ERC_OK = new EResCode(0, 0, "ERC_OK");
        ERC_ERROR = new EResCode(1, 1, "ERC_ERROR");
        ERC_Points_No_Enough = new EResCode(2, 101, "ERC_Points_No_Enough");
        ERC_Points_Invalid = new EResCode(3, 102, "ERC_Points_Invalid");
        ERC_Points_Ope_Invalid = new EResCode(4, 103, "ERC_Points_Ope_Invalid");
        ERC_Points_Expired = new EResCode(5, 104, "ERC_Points_Expired");
        ERC_Points_Expired_Client_Notice = new EResCode(6, -104, "ERC_Points_Expired_Client_Notice");
        ERC_Account_Err = new EResCode(7, 201, "ERC_Account_Err");
        ERC_Account_Not_Actived = new EResCode(8, 202, "ERC_Account_Not_Actived");
        ERC_Account_Not_Valid = new EResCode(9, 203, "ERC_Account_Not_Valid");
        ERC_Account_Not_Exist = new EResCode(10, 204, "ERC_Account_Not_Exist");
        ERC_Data_Get_Person_Err = new EResCode(11, 301, "ERC_Data_Get_Person_Err");
        ERC_Data_Get_Activity_Err = new EResCode(12, 302, "ERC_Data_Get_Activity_Err");
        ERC_Data_Get_Module_Err = new EResCode(13, 303, "ERC_Data_Get_Module_Err");
        ERC_Data_Init_Person_Err = new EResCode(14, 304, "ERC_Data_Init_Person_Err");
        ERC_Data_Null = new EResCode(15, 305, "ERC_Data_Null");
    }

    private EResCode(int i, int i2, String str) {
        this.f312d = new String();
        this.f312d = str;
        this.f311c = i2;
        f310b[i] = this;
    }

    public static EResCode convert(int i) {
        for (int i2 = 0; i2 < f310b.length; i2++) {
            if (f310b[i2].value() == i) {
                return f310b[i2];
            }
        }
        if (f309a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EResCode convert(String str) {
        for (int i = 0; i < f310b.length; i++) {
            if (f310b[i].toString().equals(str)) {
                return f310b[i];
            }
        }
        if (f309a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f312d;
    }

    public final int value() {
        return this.f311c;
    }
}
