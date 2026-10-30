package tms;

import android.content.Context;
import com.tencent.tccdb.TelNumberLocator;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.update.UpdateConfig;
import com.tencent.tmsecure.module.update.UpdateManager;
import com.tencent.tmsecure.utils.Log;
import java.util.ArrayList;

/* JADX INFO: renamed from: tms.fj */
/* JADX INFO: loaded from: classes.dex */
public final class C1288fj extends BaseManager {

    /* JADX INFO: renamed from: a */
    private TelNumberLocator f7328a;

    /* JADX INFO: renamed from: b */
    private Context f7329b;

    /* JADX INFO: renamed from: a */
    public final String m3319a(String str) {
        if (str == null) {
            return "";
        }
        StringBuffer stringBuffer = new StringBuffer();
        StringBuffer stringBuffer2 = new StringBuffer();
        StringBuffer stringBuffer3 = new StringBuffer();
        try {
            this.f7328a.getLocation(stringBuffer, stringBuffer2, stringBuffer3, str, false);
            return stringBuffer.append(stringBuffer2).append(stringBuffer3).toString();
        } catch (Exception e) {
            return "";
        }
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<String> m3320a() {
        try {
            ArrayList<String> provinceNameList = this.f7328a.getProvinceNameList();
            provinceNameList.remove(0);
            ArrayList<String> cityNameList = this.f7328a.getCityNameList("");
            if (cityNameList == null) {
                return provinceNameList;
            }
            cityNameList.remove(0);
            provinceNameList.addAll(0, cityNameList);
            return provinceNameList;
        } catch (Exception e) {
            Log.m2636i("LocationManagerImpl.getProvinceNameList", e.getMessage());
            return new ArrayList<>();
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3321a(StringBuffer stringBuffer, StringBuffer stringBuffer2, StringBuffer stringBuffer3, String str) {
        String str2 = str == null ? "" : str;
        if (stringBuffer == null || stringBuffer2 == null || stringBuffer3 == null) {
            return;
        }
        try {
            this.f7328a.getLocation(stringBuffer, stringBuffer2, stringBuffer3, str2, false);
        } catch (Exception e) {
            Log.m2636i("LocationManagerImpl.getLocation", e.getMessage());
        }
    }

    /* JADX INFO: renamed from: b */
    public final ArrayList<String> m3322b(String str) {
        if ("".compareTo(str) == 0) {
            return new ArrayList<>();
        }
        try {
            ArrayList<String> cityNameList = this.f7328a.getCityNameList("");
            cityNameList.remove(0);
            return cityNameList.contains(str) ? new ArrayList<>() : this.f7328a.getCityNameList(str);
        } catch (Exception e) {
            Log.m2636i("LocationManagerImpl.getCityNameList", e.getMessage());
            return new ArrayList<>();
        }
    }

    protected final void finalize() throws Throwable {
        ((UpdateManager) ManagerCreator.getManager(UpdateManager.class)).removeObserver(2);
        super.finalize();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7329b = context;
        C1336v.m3577a(this.f7329b, UpdateConfig.LOCATION_NAME, (String) null);
        this.f7328a = TelNumberLocator.getDefault(this.f7329b);
    }
}
