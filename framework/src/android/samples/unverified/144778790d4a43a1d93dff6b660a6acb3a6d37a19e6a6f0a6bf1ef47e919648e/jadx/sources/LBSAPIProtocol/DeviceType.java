package LBSAPIProtocol;

/* JADX INFO: loaded from: classes.dex */
public final class DeviceType {
    public static final DeviceType DEVICE_ANDROID;
    public static final DeviceType DEVICE_IPHONE;
    public static final DeviceType DEVICE_S60_V3;
    public static final DeviceType DEVICE_S60_V5;
    public static final int _DEVICE_ANDROID = 1;
    public static final int _DEVICE_IPHONE = 4;
    public static final int _DEVICE_S60_V3 = 2;
    public static final int _DEVICE_S60_V5 = 3;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f4a;

    /* JADX INFO: renamed from: b */
    private static DeviceType[] f5b;

    /* JADX INFO: renamed from: c */
    private int f6c;

    /* JADX INFO: renamed from: d */
    private String f7d;

    static {
        f4a = !DeviceType.class.desiredAssertionStatus();
        f5b = new DeviceType[4];
        DEVICE_ANDROID = new DeviceType(0, 1, "DEVICE_ANDROID");
        DEVICE_S60_V3 = new DeviceType(1, 2, "DEVICE_S60_V3");
        DEVICE_S60_V5 = new DeviceType(2, 3, "DEVICE_S60_V5");
        DEVICE_IPHONE = new DeviceType(3, 4, "DEVICE_IPHONE");
    }

    private DeviceType(int i, int i2, String str) {
        this.f7d = new String();
        this.f7d = str;
        this.f6c = i2;
        f5b[i] = this;
    }

    public static DeviceType convert(int i) {
        for (int i2 = 0; i2 < f5b.length; i2++) {
            if (f5b[i2].value() == i) {
                return f5b[i2];
            }
        }
        if (f4a) {
            return null;
        }
        throw new AssertionError();
    }

    public static DeviceType convert(String str) {
        for (int i = 0; i < f5b.length; i++) {
            if (f5b[i].toString().equals(str)) {
                return f5b[i];
            }
        }
        if (f4a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f7d;
    }

    public final int value() {
        return this.f6c;
    }
}
