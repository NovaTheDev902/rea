package seC.dujmehn.Cutyq;

import android.util.Base64;
import java.lang.reflect.InvocationTargetException;

/* JADX INFO: renamed from: seC.dujmehn.Cutyq.e */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0242e implements Runnable {
    RunnableC0242e() {
    }

    public static void JEBrZtWgvsfKOqTZ(String str, Throwable th) throws IllegalAccessException, InvocationTargetException {
        seC.dujmehn.qdtheyt.s.q.q.class.getMethod(JEBrZtWgvsfKOqTZ6157(), String.class, Throwable.class).invoke(null, str, th);
    }

    public static String JEBrZtWgvsfKOqTZ6157() {
        byte[] wjxzqy = Base64.decode("VA==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "54b6610e1af242f78e38a5866eaa7c41".charAt(n % "54b6610e1af242f78e38a5866eaa7c41".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static String JRodlpNbDaBtAXQC(StringBuilder sb) {
        return (String) StringBuilder.class.getMethod(JRodlpNbDaBtAXQC2228(), new Class[0]).invoke(sb, new Object[0]);
    }

    public static String JRodlpNbDaBtAXQC2228() {
        byte[] wjxzqy = Base64.decode("QVhhR0IPXVY=".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "57230f3106b84946bdb07fbe57df6fcf".charAt(n % "57230f3106b84946bdb07fbe57df6fcf".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static String bcgFCehikWVvTveX(Throwable th) {
        return (String) Throwable.class.getMethod(bcgFCehikWVvTveX3632(), new Class[0]).invoke(th, new Object[0]);
    }

    public static String bcgFCehikWVvTveX3632() {
        byte[] wjxzqy = Base64.decode("BQRBeVIVS1lRUQ==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "ba547f8864ce4fbab24829d5efd40b60".charAt(n % "ba547f8864ce4fbab24829d5efd40b60".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static StringBuilder cxbeZYXsBEYIqHOX(StringBuilder sb, String str) {
        return (StringBuilder) StringBuilder.class.getMethod(cxbeZYXsBEYIqHOX2512(), String.class).invoke(sb, str);
    }

    public static String cxbeZYXsBEYIqHOX2512() {
        byte[] wjxzqy = Base64.decode("UkISUQ1c".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "32b4c86fd44346dbacbc3602a011c38f".charAt(n % "32b4c86fd44346dbacbc3602a011c38f".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static String run8292() {
        byte[] wjxzqy = Base64.decode("IkxeQ0NYV10BSyJDWUQZQFwIUidWF3UaUwRAEgsJW0xG".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "f933c193d9f644939f6c470b0a0fbf5a".charAt(n % "f933c193d9f644939f6c470b0a0fbf5a".length())));
        }
        String w = xg.toString();
        return w;
    }

    @Override // java.lang.Runnable
    public final void run() throws IllegalAccessException, InvocationTargetException {
        try {
            seC.dujmehn.r.r.j = true;
        } catch (Throwable unused) {
            JEBrZtWgvsfKOqTZ(JRodlpNbDaBtAXQC(cxbeZYXsBEYIqHOX(new StringBuilder(hkd8292()), bcgFCehikWVvTveX(th))), th);
        }
    }
}
