package com.tencent.tmsecure.module.phoneservice;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import tms.C1289fk;

/* JADX INFO: loaded from: classes.dex */
public final class UsefulNumberManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1289fk f6190a;

    public final List<UsefulNumberEntity> getAllYellowNumbers() {
        return isExpired() ? new ArrayList() : this.f6190a.m3324a();
    }

    public final HashMap<String, ArrayList<UsefulNumberEntity>> getAllYellowNumbersWithGroup() {
        return isExpired() ? new HashMap<>() : this.f6190a.m3325b();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6190a = new C1289fk();
        this.f6190a.onCreate(context);
        setImpl(this.f6190a);
    }
}
