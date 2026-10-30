package tms;

import android.content.pm.PackageStats;
import android.os.Debug;
import com.tencent.tmsecure.module.optimize.IMemoryHelper;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: renamed from: tms.ej */
/* JADX INFO: loaded from: classes.dex */
public final class C1261ej implements IMemoryHelper {

    /* JADX INFO: renamed from: a */
    private IMemoryHelper f7240a;

    public C1261ej(IMemoryHelper iMemoryHelper) {
        this.f7240a = iMemoryHelper;
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final boolean clearAllCacheData() {
        return false;
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final boolean clearCacheData(String str) {
        return false;
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final ArrayList<PackageStats> getAllAppPackageStats(List<String> list) {
        return this.f7240a.getAllAppPackageStats(list);
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final PackageStats getAppPackageStats(String str) {
        return new PackageStats(str);
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final long getFreeMemery() {
        return this.f7240a.getFreeMemery();
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final Debug.MemoryInfo[] getRamSize(String[] strArr) {
        return this.f7240a.getRamSize(strArr);
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final long getTotalMemery() {
        return this.f7240a.getTotalMemery();
    }
}
