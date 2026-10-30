package tms;

import com.tencent.tmsecure.module.optimize.CpuHelperImpl;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.util.ArrayList;

/* JADX INFO: renamed from: tms.ed */
/* JADX INFO: loaded from: classes.dex */
public class C1255ed implements ScriptHelper.Callback {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ CpuHelperImpl f7233a;

    public C1255ed(CpuHelperImpl cpuHelperImpl) {
        this.f7233a = cpuHelperImpl;
    }

    @Override // com.tencent.tmsecure.utils.ScriptHelper.Callback
    public void onFinish(int i) {
        if (i == 0) {
            ArrayList arrayList = new ArrayList();
            arrayList.add("chmod 666 /sys/devices/system/cpu/kernel_max");
            arrayList.add("chmod 666 /sys/devices/system/cpu/online");
            arrayList.add("chmod 777 /sys/devices/system/cpu/cpu0/cpufreq/");
            arrayList.add("chmod 666 /sys/devices/system/cpu/cpu0/cpufreq/*");
            arrayList.add("chmod 777 /sys/devices/system/cpu/cpu0/cpufreq/stats/");
            arrayList.add("chmod 666 /sys/devices/system/cpu/cpu0/cpufreq/stats/*");
        }
    }
}
