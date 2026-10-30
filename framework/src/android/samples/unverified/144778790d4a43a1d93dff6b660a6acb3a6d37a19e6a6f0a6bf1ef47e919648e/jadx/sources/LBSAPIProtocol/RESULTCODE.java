package LBSAPIProtocol;

/* JADX INFO: loaded from: classes.dex */
public final class RESULTCODE {
    public static final RESULTCODE RESULT_AUTH_FAIL;
    public static final RESULTCODE RESULT_BACK_TIME_OUT;
    public static final RESULTCODE RESULT_EXCEPTION;
    public static final RESULTCODE RESULT_INPUT_ERROR;
    public static final RESULTCODE RESULT_POSITION_FAIL;
    public static final RESULTCODE RESULT_SUCC;
    public static final int _RESULT_AUTH_FAIL = 201;
    public static final int _RESULT_BACK_TIME_OUT = 301;
    public static final int _RESULT_EXCEPTION = 101;
    public static final int _RESULT_INPUT_ERROR = 202;
    public static final int _RESULT_POSITION_FAIL = 102;
    public static final int _RESULT_SUCC = 0;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f26a;

    /* JADX INFO: renamed from: b */
    private static RESULTCODE[] f27b;

    /* JADX INFO: renamed from: c */
    private int f28c;

    /* JADX INFO: renamed from: d */
    private String f29d;

    static {
        f26a = !RESULTCODE.class.desiredAssertionStatus();
        f27b = new RESULTCODE[6];
        RESULT_SUCC = new RESULTCODE(0, 0, "RESULT_SUCC");
        RESULT_EXCEPTION = new RESULTCODE(1, 101, "RESULT_EXCEPTION");
        RESULT_POSITION_FAIL = new RESULTCODE(2, 102, "RESULT_POSITION_FAIL");
        RESULT_AUTH_FAIL = new RESULTCODE(3, 201, "RESULT_AUTH_FAIL");
        RESULT_INPUT_ERROR = new RESULTCODE(4, 202, "RESULT_INPUT_ERROR");
        RESULT_BACK_TIME_OUT = new RESULTCODE(5, 301, "RESULT_BACK_TIME_OUT");
    }

    private RESULTCODE(int i, int i2, String str) {
        this.f29d = new String();
        this.f29d = str;
        this.f28c = i2;
        f27b[i] = this;
    }

    public static RESULTCODE convert(int i) {
        for (int i2 = 0; i2 < f27b.length; i2++) {
            if (f27b[i2].value() == i) {
                return f27b[i2];
            }
        }
        if (f26a) {
            return null;
        }
        throw new AssertionError();
    }

    public static RESULTCODE convert(String str) {
        for (int i = 0; i < f27b.length; i++) {
            if (f27b[i].toString().equals(str)) {
                return f27b[i];
            }
        }
        if (f26a) {
            return null;
        }
        throw new AssertionError();
    }

    public final String toString() {
        return this.f29d;
    }

    public final int value() {
        return this.f28c;
    }
}
