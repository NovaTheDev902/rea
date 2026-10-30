package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ESwitchSetID {
    public static final ESwitchSetID ESSID_Cloud_Update;
    public static final ESwitchSetID ESSID_Connect_Debug_Server;
    public static final ESwitchSetID ESSID_Crash_Report;
    public static final ESwitchSetID ESSID_END;
    public static final ESwitchSetID ESSID_Flow_Dial;
    public static final ESwitchSetID ESSID_Module_Advance_Defence;
    public static final ESwitchSetID ESSID_None;
    public static final ESwitchSetID ESSID_Recommend_Soft;
    public static final ESwitchSetID ESSID_Report_Soft_List;
    public static final int _ESSID_Cloud_Update = 5;
    public static final int _ESSID_Connect_Debug_Server = 4;
    public static final int _ESSID_Crash_Report = 1;
    public static final int _ESSID_END = 8;
    public static final int _ESSID_Flow_Dial = 3;
    public static final int _ESSID_Module_Advance_Defence = 2;
    public static final int _ESSID_None = 0;
    public static final int _ESSID_Recommend_Soft = 6;
    public static final int _ESSID_Report_Soft_List = 7;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f353a;

    /* JADX INFO: renamed from: b */
    private static ESwitchSetID[] f354b;

    /* JADX INFO: renamed from: c */
    private int f355c;

    /* JADX INFO: renamed from: d */
    private String f356d;

    static {
        f353a = !ESwitchSetID.class.desiredAssertionStatus();
        f354b = new ESwitchSetID[9];
        ESSID_None = new ESwitchSetID(0, 0, "ESSID_None");
        ESSID_Crash_Report = new ESwitchSetID(1, 1, "ESSID_Crash_Report");
        ESSID_Module_Advance_Defence = new ESwitchSetID(2, 2, "ESSID_Module_Advance_Defence");
        ESSID_Flow_Dial = new ESwitchSetID(3, 3, "ESSID_Flow_Dial");
        ESSID_Connect_Debug_Server = new ESwitchSetID(4, 4, "ESSID_Connect_Debug_Server");
        ESSID_Cloud_Update = new ESwitchSetID(5, 5, "ESSID_Cloud_Update");
        ESSID_Recommend_Soft = new ESwitchSetID(6, 6, "ESSID_Recommend_Soft");
        ESSID_Report_Soft_List = new ESwitchSetID(7, 7, "ESSID_Report_Soft_List");
        ESSID_END = new ESwitchSetID(8, 8, "ESSID_END");
    }

    private ESwitchSetID(int i, int i2, String str) {
        this.f356d = new String();
        this.f356d = str;
        this.f355c = i2;
        f354b[i] = this;
    }

    public static ESwitchSetID convert(int i) {
        for (int i2 = 0; i2 < f354b.length; i2++) {
            if (f354b[i2].value() == i) {
                return f354b[i2];
            }
        }
        if (f353a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ESwitchSetID convert(String str) {
        for (int i = 0; i < f354b.length; i++) {
            if (f354b[i].toString().equals(str)) {
                return f354b[i];
            }
        }
        if (f353a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f356d;
    }

    public final int value() {
        return this.f355c;
    }
}
