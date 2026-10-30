package com.tencent.tmsecure.module.network;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ErrorCode;
import java.util.ArrayList;
import tms.C1239do;
import tms.C1247dw;

/* JADX INFO: loaded from: classes.dex */
public final class TrafficCorrectionManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    C1247dw f6103a;

    /* JADX INFO: renamed from: b */
    ArrayList<CodeName> f6104b = new ArrayList<>();

    public final ArrayList<CodeName> getAllProvinces() {
        return isExpired() ? this.f6104b : C1239do.m3170b();
    }

    public final ArrayList<CodeName> getBrands(String str) {
        return isExpired() ? this.f6104b : C1239do.m3168a(str);
    }

    public final ArrayList<CodeName> getCarries() {
        return isExpired() ? this.f6104b : C1239do.m3167a();
    }

    public final ArrayList<CodeName> getCities(String str) {
        return isExpired() ? this.f6104b : C1239do.m3171b(str);
    }

    public final TrafficCorrectionConfig getConfig() {
        return isExpired() ? new TrafficCorrectionConfig() : this.f6103a.m3214a();
    }

    public final int getCorrectionResult(TrafficCorrectionResult trafficCorrectionResult, String str, String str2) {
        return isExpired() ? ErrorCode.ERR_LICENSE_EXPIRED : this.f6103a.m3212a(trafficCorrectionResult, str, str2);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6103a = new C1247dw();
        this.f6103a.onCreate(context);
        setImpl(this.f6103a);
    }

    public final int setConfig(TrafficCorrectionConfig trafficCorrectionConfig) {
        return isExpired() ? ErrorCode.ERR_LICENSE_EXPIRED : this.f6103a.m3211a(trafficCorrectionConfig);
    }

    public final int startCorrection(ArrayList<CorrectionDataInfo> arrayList) {
        return isExpired() ? ErrorCode.ERR_LICENSE_EXPIRED : this.f6103a.m3213a(arrayList);
    }
}
