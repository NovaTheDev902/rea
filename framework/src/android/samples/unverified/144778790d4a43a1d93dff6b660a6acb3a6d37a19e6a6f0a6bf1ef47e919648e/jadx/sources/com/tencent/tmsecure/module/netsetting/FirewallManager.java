package com.tencent.tmsecure.module.netsetting;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.ArrayList;
import java.util.List;
import tms.C1234dj;

/* JADX INFO: loaded from: classes.dex */
public class FirewallManager extends BaseManager {
    public static final int FEATURE_CAN_NOT_USE = 0;
    public static final int FEATURE_CAN_USE = 1;
    public static final int FEATURE_CAN_VIP = 2;

    /* JADX INFO: renamed from: a */
    private C1234dj f6097a;

    public boolean getEnable() {
        if (isExpired()) {
            return false;
        }
        return this.f6097a.m3141c();
    }

    public int getFeature() {
        return this.f6097a.m3134a();
    }

    public ArrayList<Rule> getRules(int i) {
        return isExpired() ? new ArrayList<>() : this.f6097a.m3135a(i);
    }

    public boolean init(List<Rule> list) {
        if (isExpired()) {
            return false;
        }
        return this.f6097a.m3138a(list);
    }

    public boolean isInited() {
        if (isExpired()) {
            return false;
        }
        return this.f6097a.m3140b();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public void onCreate(Context context) {
        this.f6097a = new C1234dj();
        this.f6097a.onCreate(context);
        setImpl(this.f6097a);
    }

    public void setEnable(boolean z) {
        if (isExpired()) {
            return;
        }
        this.f6097a.m3137a(z);
    }

    public void setRule(Rule rule) {
        if (isExpired()) {
            return;
        }
        this.f6097a.m3136a(rule);
    }

    public void setRules(List<Rule> list) {
        if (isExpired()) {
            return;
        }
        this.f6097a.m3139b(list);
    }
}
