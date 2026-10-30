package com.tencent.tmsecure.module.phoneservice;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.ArrayList;
import tms.C1288fj;

/* JADX INFO: loaded from: classes.dex */
public final class LocationManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1288fj f6189a;

    public final ArrayList<String> getCityNameList(String str) {
        return isExpired() ? new ArrayList<>() : this.f6189a.m3322b(str);
    }

    public final String getLocation(String str) {
        return isExpired() ? "" : this.f6189a.m3319a(str);
    }

    public final void getLocation(StringBuffer stringBuffer, StringBuffer stringBuffer2, StringBuffer stringBuffer3, String str) {
        if (isExpired()) {
            return;
        }
        this.f6189a.m3321a(stringBuffer, stringBuffer2, stringBuffer3, str);
    }

    public final ArrayList<String> getProvinceNameList() {
        return isExpired() ? new ArrayList<>() : this.f6189a.m3320a();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6189a = new C1288fj();
        this.f6189a.onCreate(context);
        setImpl(this.f6189a);
    }
}
