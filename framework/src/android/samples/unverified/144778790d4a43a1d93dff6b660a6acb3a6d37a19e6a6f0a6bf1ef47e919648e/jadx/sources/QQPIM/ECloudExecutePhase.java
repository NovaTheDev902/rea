package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ECloudExecutePhase {
    public static final ECloudExecutePhase ECEP_Phase_Execute;
    public static final ECloudExecutePhase ECEP_Phase_None;
    public static final ECloudExecutePhase ECEP_Phase_Show;
    public static final ECloudExecutePhase ECEP_Phase_User_Confirm;
    public static final int _ECEP_Phase_Execute = 3;
    public static final int _ECEP_Phase_None = 0;
    public static final int _ECEP_Phase_Show = 1;
    public static final int _ECEP_Phase_User_Confirm = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f171a;

    /* JADX INFO: renamed from: b */
    private static ECloudExecutePhase[] f172b;

    /* JADX INFO: renamed from: c */
    private int f173c;

    /* JADX INFO: renamed from: d */
    private String f174d;

    static {
        f171a = !ECloudExecutePhase.class.desiredAssertionStatus();
        f172b = new ECloudExecutePhase[4];
        ECEP_Phase_None = new ECloudExecutePhase(0, 0, "ECEP_Phase_None");
        ECEP_Phase_Show = new ECloudExecutePhase(1, 1, "ECEP_Phase_Show");
        ECEP_Phase_User_Confirm = new ECloudExecutePhase(2, 2, "ECEP_Phase_User_Confirm");
        ECEP_Phase_Execute = new ECloudExecutePhase(3, 3, "ECEP_Phase_Execute");
    }

    private ECloudExecutePhase(int i, int i2, String str) {
        this.f174d = new String();
        this.f174d = str;
        this.f173c = i2;
        f172b[i] = this;
    }

    public static ECloudExecutePhase convert(int i) {
        for (int i2 = 0; i2 < f172b.length; i2++) {
            if (f172b[i2].value() == i) {
                return f172b[i2];
            }
        }
        if (f171a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ECloudExecutePhase convert(String str) {
        for (int i = 0; i < f172b.length; i++) {
            if (f172b[i].toString().equals(str)) {
                return f172b[i];
            }
        }
        if (f171a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f174d;
    }

    public final int value() {
        return this.f173c;
    }
}
