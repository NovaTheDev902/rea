package tms;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.module.adcheck.NotificationInfo;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.atomic.AtomicReference;

/* JADX INFO: renamed from: tms.ak */
/* JADX INFO: loaded from: classes.dex */
public final class C1154ak extends BaseManager {
    /* JADX INFO: renamed from: a */
    private static int m2917a(String[] strArr, int i, String str, AtomicReference<String> atomicReference) {
        atomicReference.set(null);
        while (i < strArr.length) {
            if (strArr[i].trim().startsWith(str)) {
                atomicReference.set(strArr[i]);
                return i;
            }
            i++;
        }
        return -1;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2918a(NotificationInfo notificationInfo, boolean z) {
        return z && ScriptHelper.runScriptAsRoot(String.format("service call notification 2 s16 %s i32 %d", notificationInfo.mPkg, Long.valueOf(notificationInfo.mNotificationID))) == 0;
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<NotificationInfo> m2919a() {
        String[] strArrRunScriptSplitLines;
        boolean z = ScriptHelper.canRunAtRoot() == 0;
        ArrayList<NotificationInfo> arrayList = new ArrayList<>();
        if ((z || ScriptHelper.isSystemUid()) && (strArrRunScriptSplitLines = ScriptHelper.runScriptSplitLines("dumpsys notification")) != null) {
            int i = 2;
            while (i < strArrRunScriptSplitLines.length) {
                String strTrim = strArrRunScriptSplitLines[i].trim();
                if (strTrim.contains("mSoundNotification=")) {
                    break;
                }
                if (strTrim.contains("NotificationRecord")) {
                    AtomicReference atomicReference = new AtomicReference();
                    int iM2917a = m2917a(strArrRunScriptSplitLines, i, "tickerText=", atomicReference);
                    String strTrim2 = ((String) atomicReference.get()).trim();
                    int iM2917a2 = m2917a(strArrRunScriptSplitLines, iM2917a + 1, "flags=", atomicReference);
                    String strTrim3 = ((String) atomicReference.get()).trim();
                    NotificationInfo notificationInfo = new NotificationInfo();
                    try {
                        String[] strArrSplit = strTrim.trim().split("[ =]");
                        notificationInfo.mPkg = strArrSplit[2];
                        notificationInfo.mNotificationID = Long.parseLong(strArrSplit[4], 16);
                        String strSubstring = strTrim2.substring(11);
                        notificationInfo.mTickerText = strSubstring;
                        if (strSubstring.equals("null")) {
                            notificationInfo.mTickerText = null;
                        }
                        notificationInfo.mFlags = Long.parseLong(strTrim3.substring(8), 16);
                        arrayList.add(notificationInfo);
                        i = iM2917a2;
                    } catch (Exception e) {
                        throw new RuntimeException("flagsText: " + strTrim3 + " Notification: " + strTrim);
                    }
                }
                i++;
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public final boolean m2920a(NotificationInfo notificationInfo) {
        return false;
    }

    /* JADX INFO: renamed from: a */
    public final boolean m2921a(List<NotificationInfo> list) {
        boolean zM2918a = false;
        if (!(ScriptHelper.canRunAtRoot() == 0)) {
            return false;
        }
        Iterator<NotificationInfo> it = list.iterator();
        while (true) {
            boolean z = zM2918a;
            if (!it.hasNext()) {
                return z;
            }
            zM2918a = m2918a(it.next(), true) & z;
        }
    }

    /* JADX INFO: renamed from: b */
    public final boolean m2922b(NotificationInfo notificationInfo) {
        return m2918a(notificationInfo, ScriptHelper.canRunAtRoot() == 0);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
    }
}
