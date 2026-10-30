package seC.dujmehn.p003x;

import android.content.Context;
import android.util.Base64;
import java.lang.reflect.InvocationTargetException;
import seC.dujmehn.qdtheyt.s.q.q;
import seC.dujmehn.x.r;

/* JADX INFO: renamed from: seC.dujmehn.x.v */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0264v implements Runnable {

    /* JADX INFO: renamed from: q */
    final /* synthetic */ Context f121q;

    RunnableC0264v(Context context) {
        this.f121q = context;
    }

    public static StringBuilder ZZDfqQWZKJkcTXtb(StringBuilder sb, String str) {
        return (StringBuilder) StringBuilder.class.getMethod(ZZDfqQWZKJkcTXtb6408(), String.class).invoke(sb, str);
    }

    public static String ZZDfqQWZKJkcTXtb6408() {
        byte[] wjxzqy = Base64.decode("B0ZIB1xW".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "f68b22fbcfd74c4eb57f0ef84faedf6a".charAt(n % "f68b22fbcfd74c4eb57f0ef84faedf6a".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static String eVRQwCxTsSktZIBK(StringBuilder sb) {
        return (String) StringBuilder.class.getMethod(eVRQwCxTsSktZIBK3111(), new Class[0]).invoke(sb, new Object[0]);
    }

    public static String eVRQwCxTsSktZIBK3111() {
        byte[] wjxzqy = Base64.decode("FV01RxdRW14=".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "a2f3e8596a964063b0c33e16ef46f62a".charAt(n % "a2f3e8596a964063b0c33e16ef46f62a".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static void rlgixJJJJJpuwlJJJJJaWiNC(String str, Throwable th) throws IllegalAccessException, InvocationTargetException {
        q.class.getMethod(rlgixJJJJJpuwlJJJJJaWiNC9477(), String.class, Throwable.class).invoke(null, str, th);
    }

    public static String rlgixJJJJJpuwlJJJJJaWiNC9477() {
        byte[] wjxzqy = Base64.decode("UQ==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "08e7f124bf094dbab29bb5c55d8e1244".charAt(n % "08e7f124bf094dbab29bb5c55d8e1244".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static String run2891() {
        byte[] wjxzqy = Base64.decode("Ul5ZX2FFXABWQkEIFA==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "9753173c31224fceb6ce7b5e8f70a6c6".charAt(n % "9753173c31224fceb6ce7b5e8f70a6c6".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static String zizOioJJJJJiNfYJdglk(Throwable th) {
        return (String) Throwable.class.getMethod(zizOioJJJJJiNfYJdglk6653(), new Class[0]).invoke(th, new Object[0]);
    }

    public static String zizOioJJJJJiNfYJdglk6653() {
        byte[] wjxzqy = Base64.decode("BFEWKAEVSlNQXA==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "c4bedf92797d4ef6924734f7bb71f2ea".charAt(n % "c4bedf92797d4ef6924734f7bb71f2ea".length())));
        }
        String w = xg.toString();
        return w;
    }

    @Override // java.lang.Runnable
    public final void run() throws IllegalAccessException, InvocationTargetException {
        try {
            r.r(this.f121q);
        } catch (Throwable unused) {
            rlgixJJJJJpuwlJJJJJaWiNC(eVRQwCxTsSktZIBK(ZZDfqQWZKJkcTXtb(new StringBuilder(hkd2891()), zizOioJJJJJiNfYJdglk(th))), th);
        }
    }
}
