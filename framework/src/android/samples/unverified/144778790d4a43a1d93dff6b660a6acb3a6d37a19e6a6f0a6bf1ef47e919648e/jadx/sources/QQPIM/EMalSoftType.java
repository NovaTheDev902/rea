package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class EMalSoftType {
    public static final EMalSoftType MST_BeInstalled;
    public static final EMalSoftType MST_BeTerminated;
    public static final EMalSoftType MST_BeUninstalled;
    public static final EMalSoftType MST_BlockNetLink;
    public static final EMalSoftType MST_BlockSMS;
    public static final EMalSoftType MST_NONE;
    public static final int _MST_BeInstalled = 5;
    public static final int _MST_BeTerminated = 3;
    public static final int _MST_BeUninstalled = 2;
    public static final int _MST_BlockNetLink = 4;
    public static final int _MST_BlockSMS = 1;
    public static final int _MST_NONE = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f219a;

    /* JADX INFO: renamed from: b */
    private static EMalSoftType[] f220b;

    /* JADX INFO: renamed from: c */
    private int f221c;

    /* JADX INFO: renamed from: d */
    private String f222d;

    static {
        f219a = !EMalSoftType.class.desiredAssertionStatus();
        f220b = new EMalSoftType[6];
        MST_NONE = new EMalSoftType(0, 0, "MST_NONE");
        MST_BlockSMS = new EMalSoftType(1, 1, "MST_BlockSMS");
        MST_BeUninstalled = new EMalSoftType(2, 2, "MST_BeUninstalled");
        MST_BeTerminated = new EMalSoftType(3, 3, "MST_BeTerminated");
        MST_BlockNetLink = new EMalSoftType(4, 4, "MST_BlockNetLink");
        MST_BeInstalled = new EMalSoftType(5, 5, "MST_BeInstalled");
    }

    private EMalSoftType(int i, int i2, String str) {
        this.f222d = new String();
        this.f222d = str;
        this.f221c = i2;
        f220b[i] = this;
    }

    public static EMalSoftType convert(int i) {
        for (int i2 = 0; i2 < f220b.length; i2++) {
            if (f220b[i2].value() == i) {
                return f220b[i2];
            }
        }
        if (f219a) {
            return null;
        }
        throw new AssertionError();
    }

    public static EMalSoftType convert(String str) {
        for (int i = 0; i < f220b.length; i++) {
            if (f220b[i].toString().equals(str)) {
                return f220b[i];
            }
        }
        if (f219a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f222d;
    }

    public final int value() {
        return this.f221c;
    }
}
