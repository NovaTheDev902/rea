package com.tencent.tmsecure.module.plugin;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.List;
import tms.C1293fo;

/* JADX INFO: loaded from: classes.dex */
public final class PluginManager extends BaseManager {
    public static final int VERSION = 1;

    /* JADX INFO: renamed from: a */
    private C1293fo f6196a;

    public final IPluginDatabase createPluginDatabase(AbsPluginDatabaseFactor absPluginDatabaseFactor) {
        return this.f6196a.m3333a(absPluginDatabaseFactor);
    }

    public final List<PluginEntity> getAllPlugins() {
        return this.f6196a.m3336b();
    }

    public final AbsPluginControler getPluginControler() {
        return this.f6196a.m3332a();
    }

    public final PluginEntity getPluginEntityByKey(int i) {
        return this.f6196a.m3334a(i);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6196a = new C1293fo();
        this.f6196a.onCreate(context);
        setImpl(this.f6196a);
    }

    public final void setPluginControler(AbsPluginControler absPluginControler) {
        this.f6196a.m3335a(absPluginControler);
    }
}
