package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class NetInterfaceUsageType {
    public static final NetInterfaceUsageType NET_INTERFACE_TYPE_TRAFFIC_STAT;
    public static final int _NET_INTERFACE_TYPE_TRAFFIC_STAT = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f460a;

    /* JADX INFO: renamed from: b */
    private static NetInterfaceUsageType[] f461b;

    /* JADX INFO: renamed from: c */
    private int f462c = 0;

    /* JADX INFO: renamed from: d */
    private String f463d;

    static {
        f460a = !NetInterfaceUsageType.class.desiredAssertionStatus();
        f461b = new NetInterfaceUsageType[1];
        NET_INTERFACE_TYPE_TRAFFIC_STAT = new NetInterfaceUsageType("NET_INTERFACE_TYPE_TRAFFIC_STAT");
    }

    private NetInterfaceUsageType(String str) {
        this.f463d = new String();
        this.f463d = str;
        f461b[0] = this;
    }

    public static NetInterfaceUsageType convert(int i) {
        for (int i2 = 0; i2 < f461b.length; i2++) {
            if (f461b[i2].value() == i) {
                return f461b[i2];
            }
        }
        if (f460a) {
            return null;
        }
        throw new AssertionError();
    }

    public static NetInterfaceUsageType convert(String str) {
        for (int i = 0; i < f461b.length; i++) {
            if (f461b[i].toString().equals(str)) {
                return f461b[i];
            }
        }
        if (f460a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f463d;
    }

    public final int value() {
        return this.f462c;
    }
}
