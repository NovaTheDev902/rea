package QQPIM;

/* JADX INFO: loaded from: classes.dex */
public final class SoftListType {
    public static final SoftListType BLACKLIST_ROM;
    public static final SoftListType BLACKLIST_ROM_THIRDPART;
    public static final SoftListType BLACKLIST_WITHPLUGIN;
    public static final SoftListType WHITELIST_COMMON;
    public static final SoftListType WHITELIST_ROM;
    public static final SoftListType WHITELIST_UNUSUAL;
    public static final int _BLACKLIST_ROM = 2;
    public static final int _BLACKLIST_ROM_THIRDPART = 4;
    public static final int _BLACKLIST_WITHPLUGIN = 3;
    public static final int _WHITELIST_COMMON = 0;
    public static final int _WHITELIST_ROM = 5;
    public static final int _WHITELIST_UNUSUAL = 1;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f566a;

    /* JADX INFO: renamed from: b */
    private static SoftListType[] f567b;

    /* JADX INFO: renamed from: c */
    private int f568c;

    /* JADX INFO: renamed from: d */
    private String f569d;

    static {
        f566a = !SoftListType.class.desiredAssertionStatus();
        f567b = new SoftListType[6];
        WHITELIST_COMMON = new SoftListType(0, 0, "WHITELIST_COMMON");
        WHITELIST_UNUSUAL = new SoftListType(1, 1, "WHITELIST_UNUSUAL");
        BLACKLIST_ROM = new SoftListType(2, 2, "BLACKLIST_ROM");
        BLACKLIST_WITHPLUGIN = new SoftListType(3, 3, "BLACKLIST_WITHPLUGIN");
        BLACKLIST_ROM_THIRDPART = new SoftListType(4, 4, "BLACKLIST_ROM_THIRDPART");
        WHITELIST_ROM = new SoftListType(5, 5, "WHITELIST_ROM");
    }

    private SoftListType(int i, int i2, String str) {
        this.f569d = new String();
        this.f569d = str;
        this.f568c = i2;
        f567b[i] = this;
    }

    public static SoftListType convert(int i) {
        for (int i2 = 0; i2 < f567b.length; i2++) {
            if (f567b[i2].value() == i) {
                return f567b[i2];
            }
        }
        if (f566a) {
            return null;
        }
        throw new AssertionError();
    }

    public static SoftListType convert(String str) {
        for (int i = 0; i < f567b.length; i++) {
            if (f567b[i].toString().equals(str)) {
                return f567b[i];
            }
        }
        if (f566a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f569d;
    }

    public final int value() {
        return this.f568c;
    }
}
