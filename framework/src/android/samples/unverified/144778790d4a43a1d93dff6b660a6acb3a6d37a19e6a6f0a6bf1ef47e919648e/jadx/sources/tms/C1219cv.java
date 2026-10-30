package tms;

import com.tencent.tmsecure.utils.ScriptHelper;

/* JADX INFO: renamed from: tms.cv */
/* JADX INFO: loaded from: classes.dex */
final class C1219cv {
    /* JADX INFO: renamed from: a */
    public static boolean m3076a(String str) {
        String strRunScript = ScriptHelper.runScript("chmod 755 " + str, str + " is-chain-inited");
        if (strRunScript == null) {
            return false;
        }
        return strRunScript.contains("true");
    }
}
