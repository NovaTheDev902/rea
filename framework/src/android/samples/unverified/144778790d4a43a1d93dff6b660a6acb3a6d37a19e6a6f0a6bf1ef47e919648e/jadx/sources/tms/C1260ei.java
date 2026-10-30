package tms;

import com.tencent.tmsecure.module.optimize.ICpuHelper;

/* JADX INFO: renamed from: tms.ei */
/* JADX INFO: loaded from: classes.dex */
public final class C1260ei implements ICpuHelper {

    /* JADX INFO: renamed from: a */
    private ICpuHelper f7239a;

    public C1260ei(ICpuHelper iCpuHelper) {
        this.f7239a = iCpuHelper;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final int getAvailableCpus() {
        return 1;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final int getCpuInfoMaxFreq() {
        return this.f7239a.getCpuInfoMaxFreq();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final int getCpuInfoMinFreq() {
        return this.f7239a.getCpuInfoMinFreq();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final int getKernelMax() {
        return this.f7239a.getKernelMax();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final String[] getOnlineCpus() {
        return this.f7239a.getOnlineCpus();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final int[] getScalingAvaliableFrequencies() {
        return this.f7239a.getScalingAvaliableFrequencies();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final String[] getScalingAvaliableGovernors() {
        return this.f7239a.getScalingAvaliableGovernors();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final int getScalingCurFreq() {
        return this.f7239a.getScalingCurFreq();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final String getScalingGovernor() {
        return this.f7239a.getScalingGovernor();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final int getScalingMaxFreq() {
        return this.f7239a.getScalingMaxFreq();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final int getScalingMinFreq() {
        return this.f7239a.getScalingMinFreq();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final void setScalingFreq(int i) throws IllegalArgumentException {
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final void setScalingGovernor(String str) throws IllegalArgumentException {
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final void setScalingMaxFreq(int i) throws IllegalArgumentException {
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public final void setScalingMinFreq(int i) throws IllegalArgumentException {
    }
}
