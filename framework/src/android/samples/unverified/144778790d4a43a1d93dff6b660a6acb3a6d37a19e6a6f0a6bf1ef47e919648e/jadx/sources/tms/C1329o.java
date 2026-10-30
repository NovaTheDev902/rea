package tms;

import com.tencent.tmsecure.exception.UnauthorizedCallerException;

/* JADX INFO: renamed from: tms.o */
/* JADX INFO: loaded from: classes.dex */
public class C1329o {
    /* JADX INFO: renamed from: a */
    public static void m3531a(Class<?>... clsArr) throws UnauthorizedCallerException {
        boolean z = false;
        for (StackTraceElement stackTraceElement : Thread.currentThread().getStackTrace()) {
            for (Class<?> cls : clsArr) {
                if (stackTraceElement.getClassName().equals(cls.getName())) {
                    z = true;
                    break;
                }
            }
        }
        if (!z) {
            throw new UnauthorizedCallerException();
        }
    }
}
