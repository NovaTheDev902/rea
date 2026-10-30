package com.tencent.tmsecure.module.urlcheck;

import QQPIM.UrlCheckResponse;
import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import tms.C1314ha;

/* JADX INFO: loaded from: classes.dex */
public final class UrlCheckManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1314ha f6238a;

    public final int checkApkUrl(String str) {
        if (isExpired()) {
            return 0;
        }
        return this.f6238a.m3459b(str);
    }

    public final UrlCheckResponse checkUrl(String str) {
        return isExpired() ? new UrlCheckResponse(str, 0, 0, 0, "") : this.f6238a.m3457a(str);
    }

    public final Map<String, UrlCheckResponse> checkUrlEx(List<String> list) {
        return isExpired() ? new HashMap(0) : this.f6238a.m3458a(list);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6238a = new C1314ha();
        this.f6238a.onCreate(context);
        setImpl(this.f6238a);
    }
}
