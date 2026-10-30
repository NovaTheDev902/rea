package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EMessageTime {
    public static final EMessageTime EMTI_END;
    public static final EMessageTime EMTI_Execute_Time_Zone;
    public static final EMessageTime EMTI_Get_X;
    public static final EMessageTime EMTI_Immediatly;
    public static final EMessageTime EMTI_None;
    public static final EMessageTime EMTI_Open;
    public static final EMessageTime EMTI_PB_Android_Private_Entry_Click;
    public static final EMessageTime EMTI_Sec_Android_Harass_Entry_Click;
    public static final int _EMTI_END = 420103001;
    public static final int _EMTI_Execute_Time_Zone = 4;
    public static final int _EMTI_Get_X = 3;
    public static final int _EMTI_Immediatly = 1;
    public static final int _EMTI_None = 0;
    public static final int _EMTI_Open = 2;
    public static final int _EMTI_PB_Android_Private_Entry_Click = 420103000;
    public static final int _EMTI_Sec_Android_Harass_Entry_Click = 120103000;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f235a;

    /* JADX INFO: renamed from: b */
    private static EMessageTime[] f236b;

    /* JADX INFO: renamed from: c */
    private int f237c;

    /* JADX INFO: renamed from: d */
    private String f238d;

    static {
        f235a = !EMessageTime.class.desiredAssertionStatus();
        f236b = new EMessageTime[8];
        EMTI_None = new EMessageTime(0, 0, "EMTI_None");
        EMTI_Immediatly = new EMessageTime(1, 1, "EMTI_Immediatly");
        EMTI_Open = new EMessageTime(2, 2, "EMTI_Open");
        EMTI_Get_X = new EMessageTime(3, 3, "EMTI_Get_X");
        EMTI_Execute_Time_Zone = new EMessageTime(4, 4, "EMTI_Execute_Time_Zone");
        EMTI_Sec_Android_Harass_Entry_Click = new EMessageTime(5, _EMTI_Sec_Android_Harass_Entry_Click, "EMTI_Sec_Android_Harass_Entry_Click");
        EMTI_PB_Android_Private_Entry_Click = new EMessageTime(6, _EMTI_PB_Android_Private_Entry_Click, "EMTI_PB_Android_Private_Entry_Click");
        EMTI_END = new EMessageTime(7, _EMTI_END, "EMTI_END");
    }

    private EMessageTime(int i, int i2, String str) {
        this.f238d = new String();
        this.f238d = str;
        this.f237c = i2;
        f236b[i] = this;
    }

    public static EMessageTime convert(int i) {
        for (int i2 = 0; i2 < f236b.length; i2++) {
            if (f236b[i2].value() == i) {
                return f236b[i2];
            }
        }
        if (f235a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EMessageTime convert(String str) {
        for (int i = 0; i < f236b.length; i++) {
            if (f236b[i].toString().equals(str)) {
                return f236b[i];
            }
        }
        if (f235a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f238d;
    }

    public final int value() {
        return this.f237c;
    }
}
