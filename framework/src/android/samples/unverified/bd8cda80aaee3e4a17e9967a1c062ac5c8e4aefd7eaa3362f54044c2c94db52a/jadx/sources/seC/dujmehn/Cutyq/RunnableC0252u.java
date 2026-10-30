package seC.dujmehn.Cutyq;

import android.content.Context;
import android.content.Intent;
import android.util.Base64;
import java.lang.reflect.InvocationTargetException;

/* JADX INFO: renamed from: seC.dujmehn.Cutyq.u */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0252u implements Runnable {

    /* JADX INFO: renamed from: q */
    final /* synthetic */ Context f60q;

    /* JADX INFO: renamed from: r */
    final /* synthetic */ Intent f61r;

    /* JADX INFO: renamed from: s */
    final /* synthetic */ String f62s;

    /* JADX INFO: renamed from: t */
    final /* synthetic */ SehuHusuyluh f63t;

    RunnableC0252u(SehuHusuyluh sehuHusuyluh, Context context, Intent intent, String str) {
        this.f63t = sehuHusuyluh;
        this.f60q = context;
        this.f61r = intent;
        this.f62s = str;
    }

    public static void MRoldQqjdVMTasJJJJJB(Context context, Intent intent, String str) throws IllegalAccessException, InvocationTargetException {
        SehuHusuyluh.class.getMethod(MRoldQqjdVMTasJJJJJB4311(), Context.class, Intent.class, String.class).invoke(null, context, intent, str);
    }

    public static String MRoldQqjdVMTasJJJJJB4311() {
        byte[] wjxzqy = Base64.decode("BA==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "ee17238609974624a45b83d0a5fc204c".charAt(n % "ee17238609974624a45b83d0a5fc204c".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static String MxTWxfwqFDGaGQam(StringBuilder sb) {
        return (String) StringBuilder.class.getMethod(MxTWxfwqFDGaGQam8309(), new Class[0]).invoke(sb, new Object[0]);
    }

    public static String MxTWxfwqFDGaGQam8309() {
        byte[] wjxzqy = Base64.decode("TV5jFURbCgQ=".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "910a62dc2f204266ad6693a3351ceaec".charAt(n % "910a62dc2f204266ad6693a3351ceaec".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static String SdAwnElSjtGlYGcc(Throwable th) {
        return (String) Throwable.class.getMethod(SdAwnElSjtGlYGcc6483(), new Class[0]).invoke(th, new Object[0]);
    }

    public static String SdAwnElSjtGlYGcc6483() {
        byte[] wjxzqy = Base64.decode("VwYVKVdHQVheVg==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "0cad242993fb42f694eebd25d2db87ba".charAt(n % "0cad242993fb42f694eebd25d2db87ba".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static void TRsBvJJJJJJOWBJvIFRM(String str, Throwable th) throws IllegalAccessException, InvocationTargetException {
        seC.dujmehn.qdtheyt.s.q.q.class.getMethod(TRsBvJJJJJJOWBJvIFRM8843(), String.class, Throwable.class).invoke(null, str, th);
    }

    public static String TRsBvJJJJJJOWBJvIFRM8843() {
        byte[] wjxzqy = Base64.decode("VQ==".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "4c871ec7b1de45ccbc9099a69d119eca".charAt(n % "4c871ec7b1de45ccbc9099a69d119eca".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static StringBuilder ptoTAOSmgtWCRXoy(StringBuilder sb, String str) {
        return (StringBuilder) StringBuilder.class.getMethod(ptoTAOSmgtWCRXoy6223(), String.class).invoke(sb, str);
    }

    public static String ptoTAOSmgtWCRXoy6223() {
        byte[] wjxzqy = Base64.decode("V0ATUwgF".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "60c6fab1c42e4ceab081602de5a24e07".charAt(n % "60c6fab1c42e4ceab081602de5a24e07".length())));
        }
        String w = xg.toString();
        return w;
    }

    public static String run9097() {
        byte[] wjxzqy = Base64.decode("WApjBFRWWkFVFxFURwYPXFBZXn9YW1EIXUYTfRxRVRFDDV4PGhM=".getBytes(), 0);
        String x = new String(wjxzqy);
        StringBuilder xg = new StringBuilder();
        for (int n = 0; n < x.length(); n++) {
            xg.append((char) (x.charAt(n) ^ "7d1a733707c14ca89797955d8438d20a".charAt(n % "7d1a733707c14ca89797955d8438d20a".length())));
        }
        String w = xg.toString();
        return w;
    }

    @Override // java.lang.Runnable
    public final void run() throws IllegalAccessException, InvocationTargetException {
        try {
            SehuHusuyluh sehuHusuyluh = this.f63t;
            MRoldQqjdVMTasJJJJJB(this.f60q, this.f61r, this.f62s);
        } catch (Throwable unused) {
            TRsBvJJJJJJOWBJvIFRM(MxTWxfwqFDGaGQam(ptoTAOSmgtWCRXoy(new StringBuilder(hkd9097()), SdAwnElSjtGlYGcc(th))), th);
        }
    }
}
