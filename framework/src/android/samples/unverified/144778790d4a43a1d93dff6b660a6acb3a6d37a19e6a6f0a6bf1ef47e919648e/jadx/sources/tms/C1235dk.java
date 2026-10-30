package tms;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ResolveInfo;
import com.tencent.tmsecure.module.optimize.IAutoBootHelper;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/* JADX INFO: renamed from: tms.dk */
/* JADX INFO: loaded from: classes.dex */
final class C1235dk implements IAutoBootHelper {

    /* JADX INFO: renamed from: a */
    private final ConcurrentHashMap<String, ArrayList<String>> f7123a = new ConcurrentHashMap<>(new HashMap());

    /* JADX INFO: renamed from: b */
    private Context f7124b;

    public C1235dk(Context context) {
        this.f7124b = context;
    }

    /* JADX INFO: renamed from: a */
    private boolean m3142a(String str) {
        ArrayList<String> arrayList = this.f7123a.get(str);
        if (arrayList == null || arrayList.size() <= 0) {
            return false;
        }
        Iterator<String> it = arrayList.iterator();
        boolean z = true;
        while (it.hasNext()) {
            boolean z2 = (this.f7124b.getPackageManager().getComponentEnabledSetting(new ComponentName(str, it.next())) != 2) & z;
            if (!z2) {
                return z2;
            }
            z = z2;
        }
        return z;
    }

    @Override // com.tencent.tmsecure.module.optimize.IAutoBootHelper
    public final ArrayList<IAutoBootHelper.Pair<String, Boolean>> getAllAutoBootApps() {
        ArrayList<String> arrayList;
        ArrayList<IAutoBootHelper.Pair<String, Boolean>> arrayList2 = new ArrayList<>();
        List<ResolveInfo> listQueryBroadcastReceivers = this.f7124b.getPackageManager().queryBroadcastReceivers(new Intent("android.intent.action.BOOT_COMPLETED"), 512);
        this.f7123a.clear();
        for (ResolveInfo resolveInfo : listQueryBroadcastReceivers) {
            String str = resolveInfo.activityInfo.packageName;
            String str2 = resolveInfo.activityInfo.name;
            if (this.f7123a.containsKey(str)) {
                arrayList = this.f7123a.get(str);
            } else {
                arrayList = new ArrayList<>();
                this.f7123a.put(str, arrayList);
            }
            if (!arrayList.contains(str2)) {
                arrayList.add(str2);
            }
        }
        for (Map.Entry<String, ArrayList<String>> entry : this.f7123a.entrySet()) {
            arrayList2.add(new IAutoBootHelper.Pair<>(entry.getKey(), Boolean.valueOf(m3142a(entry.getKey()))));
        }
        return arrayList2;
    }

    @Override // com.tencent.tmsecure.module.optimize.IAutoBootHelper
    public final boolean setAutoBootEnable(String str, boolean z) {
        if (ScriptHelper.providerSupportPmRelative() || ScriptHelper.isSystemUid() || ScriptHelper.isRootGot()) {
            ArrayList<String> arrayList = this.f7123a.get(str);
            ArrayList arrayList2 = new ArrayList();
            if (arrayList != null) {
                if (ScriptHelper.providerSupportPmRelative()) {
                    Iterator<String> it = arrayList.iterator();
                    while (it.hasNext()) {
                        if (!ScriptHelper.provider().m3510a(str, it.next(), z)) {
                            break;
                        }
                    }
                } else {
                    for (String str2 : arrayList) {
                        Object[] objArr = new Object[3];
                        objArr[0] = z ? "enable" : "disable";
                        objArr[1] = str;
                        objArr[2] = str2;
                        arrayList2.add(String.format("pm %s '%s/%s'", objArr));
                    }
                    ScriptHelper.runScriptIfSystemUidOrAsRoot(arrayList2);
                }
            }
        }
        return m3142a(str) == z;
    }
}
