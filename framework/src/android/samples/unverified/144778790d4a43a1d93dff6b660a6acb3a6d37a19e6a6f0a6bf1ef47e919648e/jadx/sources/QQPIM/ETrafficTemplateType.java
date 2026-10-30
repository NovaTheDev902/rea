package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class ETrafficTemplateType {
    public static final ETrafficTemplateType E_TRAFFIC_TEMPLATE_TYPE_BALANCE_BEGIN;
    public static final ETrafficTemplateType E_TRAFFIC_TEMPLATE_TYPE_BALANCE_END;
    public static final ETrafficTemplateType E_TRAFFIC_TEMPLATE_TYPE_EXCESS;
    public static final ETrafficTemplateType E_TRAFFIC_TEMPLATE_TYPE_LEFT;
    public static final ETrafficTemplateType E_TRAFFIC_TEMPLATE_TYPE_MAX;
    public static final ETrafficTemplateType E_TRAFFIC_TEMPLATE_TYPE_MIN;
    public static final ETrafficTemplateType E_TRAFFIC_TEMPLATE_TYPE_PACKAGE;
    public static final ETrafficTemplateType E_TRAFFIC_TEMPLATE_TYPE_USE;
    public static final int _E_TRAFFIC_TEMPLATE_TYPE_BALANCE_BEGIN = 5;
    public static final int _E_TRAFFIC_TEMPLATE_TYPE_BALANCE_END = 6;
    public static final int _E_TRAFFIC_TEMPLATE_TYPE_EXCESS = 3;
    public static final int _E_TRAFFIC_TEMPLATE_TYPE_LEFT = 1;
    public static final int _E_TRAFFIC_TEMPLATE_TYPE_MAX = 7;
    public static final int _E_TRAFFIC_TEMPLATE_TYPE_MIN = 0;
    public static final int _E_TRAFFIC_TEMPLATE_TYPE_PACKAGE = 4;
    public static final int _E_TRAFFIC_TEMPLATE_TYPE_USE = 2;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f369a;

    /* JADX INFO: renamed from: b */
    private static ETrafficTemplateType[] f370b;

    /* JADX INFO: renamed from: c */
    private int f371c;

    /* JADX INFO: renamed from: d */
    private String f372d;

    static {
        f369a = !ETrafficTemplateType.class.desiredAssertionStatus();
        f370b = new ETrafficTemplateType[8];
        E_TRAFFIC_TEMPLATE_TYPE_MIN = new ETrafficTemplateType(0, 0, "E_TRAFFIC_TEMPLATE_TYPE_MIN");
        E_TRAFFIC_TEMPLATE_TYPE_LEFT = new ETrafficTemplateType(1, 1, "E_TRAFFIC_TEMPLATE_TYPE_LEFT");
        E_TRAFFIC_TEMPLATE_TYPE_USE = new ETrafficTemplateType(2, 2, "E_TRAFFIC_TEMPLATE_TYPE_USE");
        E_TRAFFIC_TEMPLATE_TYPE_EXCESS = new ETrafficTemplateType(3, 3, "E_TRAFFIC_TEMPLATE_TYPE_EXCESS");
        E_TRAFFIC_TEMPLATE_TYPE_PACKAGE = new ETrafficTemplateType(4, 4, "E_TRAFFIC_TEMPLATE_TYPE_PACKAGE");
        E_TRAFFIC_TEMPLATE_TYPE_BALANCE_BEGIN = new ETrafficTemplateType(5, 5, "E_TRAFFIC_TEMPLATE_TYPE_BALANCE_BEGIN");
        E_TRAFFIC_TEMPLATE_TYPE_BALANCE_END = new ETrafficTemplateType(6, 6, "E_TRAFFIC_TEMPLATE_TYPE_BALANCE_END");
        E_TRAFFIC_TEMPLATE_TYPE_MAX = new ETrafficTemplateType(7, 7, "E_TRAFFIC_TEMPLATE_TYPE_MAX");
    }

    private ETrafficTemplateType(int i, int i2, String str) {
        this.f372d = new String();
        this.f372d = str;
        this.f371c = i2;
        f370b[i] = this;
    }

    public static ETrafficTemplateType convert(int i) {
        for (int i2 = 0; i2 < f370b.length; i2++) {
            if (f370b[i2].value() == i) {
                return f370b[i2];
            }
        }
        if (f369a) {
            return null;
        }
        throw new AssertionError();
    }

    public static ETrafficTemplateType convert(String str) {
        for (int i = 0; i < f370b.length; i++) {
            if (f370b[i].toString().equals(str)) {
                return f370b[i];
            }
        }
        if (f369a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f372d;
    }

    public final int value() {
        return this.f371c;
    }
}
