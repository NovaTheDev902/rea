package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EUserInterfaceID {
    public static final EUserInterfaceID EUIID_PBJB_Iphone_Call_Skin_List;
    public static final EUserInterfaceID EUIID_PB_Android_Private_Entry;
    public static final EUserInterfaceID EUIID_SecJB_Iphone_About_Entry;
    public static final EUserInterfaceID EUIID_Sec_Android_Harass_Entry;
    public static final EUserInterfaceID EUIID_Sec_Android_SoftGame_Main;
    public static final EUserInterfaceID EUIID_Sec_Android_VirusChk_Main;
    public static final EUserInterfaceID EUIID_Sec_Android_VirusChk_Tool;
    public static final EUserInterfaceID EUIID_Sec_Iphone_About_Entry;
    public static final int _EUIID_PBJB_Iphone_Call_Skin_List = 203010101;
    public static final int _EUIID_PB_Android_Private_Entry = 42010300;
    public static final int _EUIID_SecJB_Iphone_About_Entry = 163010101;
    public static final int _EUIID_Sec_Android_Harass_Entry = 12010300;
    public static final int _EUIID_Sec_Android_SoftGame_Main = 12010100;
    public static final int _EUIID_Sec_Android_VirusChk_Main = 12010200;
    public static final int _EUIID_Sec_Android_VirusChk_Tool = 12010201;
    public static final int _EUIID_Sec_Iphone_About_Entry = 13010101;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f389a;

    /* JADX INFO: renamed from: b */
    private static EUserInterfaceID[] f390b;

    /* JADX INFO: renamed from: c */
    private int f391c;

    /* JADX INFO: renamed from: d */
    private String f392d;

    static {
        f389a = !EUserInterfaceID.class.desiredAssertionStatus();
        f390b = new EUserInterfaceID[8];
        EUIID_Sec_Android_SoftGame_Main = new EUserInterfaceID(0, _EUIID_Sec_Android_SoftGame_Main, "EUIID_Sec_Android_SoftGame_Main");
        EUIID_Sec_Android_VirusChk_Main = new EUserInterfaceID(1, _EUIID_Sec_Android_VirusChk_Main, "EUIID_Sec_Android_VirusChk_Main");
        EUIID_Sec_Android_VirusChk_Tool = new EUserInterfaceID(2, _EUIID_Sec_Android_VirusChk_Tool, "EUIID_Sec_Android_VirusChk_Tool");
        EUIID_Sec_Android_Harass_Entry = new EUserInterfaceID(3, _EUIID_Sec_Android_Harass_Entry, "EUIID_Sec_Android_Harass_Entry");
        EUIID_Sec_Iphone_About_Entry = new EUserInterfaceID(4, _EUIID_Sec_Iphone_About_Entry, "EUIID_Sec_Iphone_About_Entry");
        EUIID_PB_Android_Private_Entry = new EUserInterfaceID(5, _EUIID_PB_Android_Private_Entry, "EUIID_PB_Android_Private_Entry");
        EUIID_SecJB_Iphone_About_Entry = new EUserInterfaceID(6, _EUIID_SecJB_Iphone_About_Entry, "EUIID_SecJB_Iphone_About_Entry");
        EUIID_PBJB_Iphone_Call_Skin_List = new EUserInterfaceID(7, _EUIID_PBJB_Iphone_Call_Skin_List, "EUIID_PBJB_Iphone_Call_Skin_List");
    }

    private EUserInterfaceID(int i, int i2, String str) {
        this.f392d = new String();
        this.f392d = str;
        this.f391c = i2;
        f390b[i] = this;
    }

    public static EUserInterfaceID convert(int i) {
        for (int i2 = 0; i2 < f390b.length; i2++) {
            if (f390b[i2].value() == i) {
                return f390b[i2];
            }
        }
        if (f389a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EUserInterfaceID convert(String str) {
        for (int i = 0; i < f390b.length; i++) {
            if (f390b[i].toString().equals(str)) {
                return f390b[i];
            }
        }
        if (f389a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f392d;
    }

    public final int value() {
        return this.f391c;
    }
}
