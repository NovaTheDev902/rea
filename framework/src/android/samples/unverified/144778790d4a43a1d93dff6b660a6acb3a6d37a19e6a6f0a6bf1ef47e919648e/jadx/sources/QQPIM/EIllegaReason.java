package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EIllegaReason {
    public static final EIllegaReason IR_Ad;
    public static final EIllegaReason IR_Conn;
    public static final EIllegaReason IR_Damage;
    public static final EIllegaReason IR_GetInfo;
    public static final EIllegaReason IR_InvalidDownLoad;
    public static final EIllegaReason IR_InvalidInstall;
    public static final EIllegaReason IR_NeedUpdate;
    public static final EIllegaReason IR_Other;
    public static final EIllegaReason IR_Pay;
    public static final EIllegaReason IR_Plugin;
    public static final EIllegaReason IR_SMS;
    public static final EIllegaReason IR_TermProc;
    public static final EIllegaReason IR_Virus;
    public static final EIllegaReason IR_WrongInfo;
    public static final int _IR_Ad = 6;
    public static final int _IR_Conn = 2;
    public static final int _IR_Damage = 8;
    public static final int _IR_GetInfo = 4;
    public static final int _IR_InvalidDownLoad = 9;
    public static final int _IR_InvalidInstall = 10;
    public static final int _IR_NeedUpdate = 13;
    public static final int _IR_Other = 0;
    public static final int _IR_Pay = 1;
    public static final int _IR_Plugin = 5;
    public static final int _IR_SMS = 3;
    public static final int _IR_TermProc = 7;
    public static final int _IR_Virus = 11;
    public static final int _IR_WrongInfo = 12;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f195a;

    /* JADX INFO: renamed from: b */
    private static EIllegaReason[] f196b;

    /* JADX INFO: renamed from: c */
    private int f197c;

    /* JADX INFO: renamed from: d */
    private String f198d;

    static {
        f195a = !EIllegaReason.class.desiredAssertionStatus();
        f196b = new EIllegaReason[14];
        IR_Other = new EIllegaReason(0, 0, "IR_Other");
        IR_Pay = new EIllegaReason(1, 1, "IR_Pay");
        IR_Conn = new EIllegaReason(2, 2, "IR_Conn");
        IR_SMS = new EIllegaReason(3, 3, "IR_SMS");
        IR_GetInfo = new EIllegaReason(4, 4, "IR_GetInfo");
        IR_Plugin = new EIllegaReason(5, 5, "IR_Plugin");
        IR_Ad = new EIllegaReason(6, 6, "IR_Ad");
        IR_TermProc = new EIllegaReason(7, 7, "IR_TermProc");
        IR_Damage = new EIllegaReason(8, 8, "IR_Damage");
        IR_InvalidDownLoad = new EIllegaReason(9, 9, "IR_InvalidDownLoad");
        IR_InvalidInstall = new EIllegaReason(10, 10, "IR_InvalidInstall");
        IR_Virus = new EIllegaReason(11, 11, "IR_Virus");
        IR_WrongInfo = new EIllegaReason(12, 12, "IR_WrongInfo");
        IR_NeedUpdate = new EIllegaReason(13, 13, "IR_NeedUpdate");
    }

    private EIllegaReason(int i, int i2, String str) {
        this.f198d = new String();
        this.f198d = str;
        this.f197c = i2;
        f196b[i] = this;
    }

    public static EIllegaReason convert(int i) {
        for (int i2 = 0; i2 < f196b.length; i2++) {
            if (f196b[i2].value() == i) {
                return f196b[i2];
            }
        }
        if (f195a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EIllegaReason convert(String str) {
        for (int i = 0; i < f196b.length; i++) {
            if (f196b[i].toString().equals(str)) {
                return f196b[i];
            }
        }
        if (f195a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f198d;
    }

    public final int value() {
        return this.f197c;
    }
}
