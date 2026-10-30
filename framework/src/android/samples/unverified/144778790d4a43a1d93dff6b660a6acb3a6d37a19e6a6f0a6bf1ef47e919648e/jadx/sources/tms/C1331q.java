package tms;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.io.File;
import java.util.ArrayList;

/* JADX INFO: renamed from: tms.q */
/* JADX INFO: loaded from: classes.dex */
public final class C1331q {

    /* JADX INFO: renamed from: a */
    public static final String f7470a = "key_last_verify_success";

    /* JADX INFO: renamed from: b */
    public static final String f7471b = "key_last_verify_time";

    /* JADX INFO: renamed from: c */
    public static final String f7472c = "key_next_verify_time";

    /* JADX INFO: renamed from: d */
    public static final String f7473d = "action_verify";

    /* JADX INFO: renamed from: a */
    public static void m3538a() {
        Context applicaionContext = TMSApplication.getApplicaionContext();
        AlarmManager alarmManager = (AlarmManager) applicaionContext.getSystemService("alarm");
        Intent intent = new Intent(applicaionContext, TMSApplication.getSecureServiceClass());
        intent.setAction(f7473d);
        alarmManager.cancel(PendingIntent.getService(applicaionContext, 0, intent, 0));
    }

    /* JADX INFO: renamed from: a */
    public static void m3539a(Context context, String str) {
        Intent intent = new Intent("android.intent.action.VIEW");
        intent.addFlags(268435456);
        intent.setDataAndType(Uri.fromFile(new File(str)), "application/vnd.android.package-archive");
        context.startActivity(intent);
    }

    /* JADX INFO: renamed from: a */
    public static void m3540a(Context context, String str, String str2, int i) {
        C1340z c1340z = new C1340z(context);
        c1340z.m3657a(context.getFilesDir().getAbsolutePath());
        c1340z.m3659b(str2);
        c1340z.m3656a(i);
        c1340z.m3658a(str, false);
    }

    /* JADX INFO: renamed from: b */
    public static boolean m3541b(Context context, String str) {
        try {
            ArrayList arrayList = new ArrayList();
            arrayList.add("pm install " + str);
            return ScriptHelper.runScriptAsRoot(arrayList) == 0;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: c */
    public static boolean m3542c(Context context, String str) {
        try {
            ArrayList arrayList = new ArrayList();
            arrayList.add("mount -o remount,rw /");
            arrayList.add("chmod 0777 " + str);
            arrayList.add("rm " + str);
            int iRunScriptAsRoot = ScriptHelper.runScriptAsRoot(arrayList);
            File file = new File(str);
            if (file.exists()) {
                file.delete();
            }
            return iRunScriptAsRoot == 0;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: d */
    public static void m3543d(Context context, String str) {
        Intent intent = new Intent("android.intent.action.DELETE", Uri.parse("package:" + str));
        intent.addFlags(268435456);
        context.startActivity(intent);
    }

    /* JADX INFO: renamed from: e */
    public static boolean m3544e(Context context, String str) {
        try {
            ArrayList arrayList = new ArrayList();
            arrayList.add("pm uninstall " + str);
            return ScriptHelper.runScriptAsRoot(arrayList) == 0;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: f */
    public static boolean m3545f(Context context, String str) {
        try {
            ArrayList arrayList = new ArrayList();
            arrayList.add("pm disable " + str);
            arrayList.add("pm enable " + str);
            return ScriptHelper.runScriptAsRoot(arrayList) == 0;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: g */
    public static boolean m3546g(Context context, String str) {
        try {
            if (ScriptHelper.runScriptAsRoot(str) == 0) {
                return true;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }
}
