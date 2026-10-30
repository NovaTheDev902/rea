package com.tencent.tmsecure.module.antitheft;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1155al;
import tms.C1158ao;

/* JADX INFO: loaded from: classes.dex */
public final class AntitheftManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1155al f6059a;

    public final String encryptPassword(String str) {
        return isExpired() ? "" : C1158ao.m2930c(str);
    }

    public final String getHelperNumber() {
        return isExpired() ? "" : this.f6059a.m2928a().m2931a();
    }

    public final String getPassword() {
        return isExpired() ? "" : this.f6059a.m2928a().m2932a(false);
    }

    public final boolean handleSmsCommand(IAntitheftTips iAntitheftTips, String str, String str2) {
        if (isExpired()) {
            return false;
        }
        return this.f6059a.m2929a(iAntitheftTips, str, str2);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6059a = new C1155al();
        this.f6059a.onCreate(context);
        setImpl(this.f6059a);
    }

    public final void setHelperNumber(String str) {
        if (isExpired()) {
            return;
        }
        this.f6059a.m2928a().m2934b(str);
    }

    public final void setPassword(String str) {
        if (isExpired()) {
            return;
        }
        this.f6059a.m2928a().m2933a(str);
    }
}
