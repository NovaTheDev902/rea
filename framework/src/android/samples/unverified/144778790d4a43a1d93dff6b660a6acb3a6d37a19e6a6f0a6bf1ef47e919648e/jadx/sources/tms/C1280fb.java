package tms;

import android.content.Intent;
import android.content.pm.ResolveInfo;
import android.os.IBinder;
import android.os.Parcel;
import android.os.RemoteException;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: renamed from: tms.fb */
/* JADX INFO: loaded from: classes.dex */
final class C1280fb {

    /* JADX INFO: renamed from: a */
    private static int f7306a = 41;

    /* JADX INFO: renamed from: b */
    private static int f7307b = 43;

    /* JADX INFO: renamed from: c */
    private IBinder f7308c;

    public C1280fb() {
        if (C1151ah.m2902a("android.app.admin.IDevicePolicyManager$Stub")) {
            f7306a = C1151ah.m2897a("TRANSACTION_packageHasActiveAdmins", 41);
            f7307b = C1151ah.m2897a("TRANSACTION_removeActiveAdmin", 43);
            this.f7308c = C1152ai.m2904a("device_policy");
        }
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3301a(String str) {
        boolean z = false;
        if (this.f7308c != null) {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                try {
                    parcelObtain.writeInterfaceToken("android.app.admin.IDevicePolicyManager");
                    parcelObtain.writeString(str);
                    this.f7308c.transact(f7306a, parcelObtain, parcelObtain2, 0);
                    parcelObtain2.readException();
                    z = parcelObtain2.readInt() != 0;
                    parcelObtain.recycle();
                } catch (RemoteException e) {
                    e.printStackTrace();
                    parcelObtain.recycle();
                }
                parcelObtain2.recycle();
            } catch (Throwable th) {
                parcelObtain.recycle();
                parcelObtain2.recycle();
                throw th;
            }
        }
        return z;
    }

    /* JADX INFO: renamed from: b */
    public final boolean m3302b(String str) {
        if (this.f7308c != null) {
            Intent intent = new Intent("android.app.action.DEVICE_ADMIN_ENABLED");
            intent.setPackage(str);
            List<ResolveInfo> listQueryBroadcastReceivers = TMSApplication.getApplicaionContext().getPackageManager().queryBroadcastReceivers(intent, 0);
            if (listQueryBroadcastReceivers.size() > 0) {
                ArrayList arrayList = new ArrayList();
                for (ResolveInfo resolveInfo : listQueryBroadcastReceivers) {
                    if (resolveInfo.activityInfo.enabled) {
                        arrayList.add(String.format("service call %s %d i32 1 s16 %s s16 %s", "device_policy", Integer.valueOf(f7307b), resolveInfo.activityInfo.packageName, resolveInfo.activityInfo.name));
                    }
                }
                if (arrayList.size() > 0) {
                    ScriptHelper.runScriptAsRoot(arrayList);
                }
            }
        }
        return false;
    }
}
