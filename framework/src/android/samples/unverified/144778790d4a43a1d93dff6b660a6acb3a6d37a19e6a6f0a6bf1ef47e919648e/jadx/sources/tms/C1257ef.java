package tms;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import com.tencent.tmsecure.module.plugin.IContext;

/* JADX INFO: renamed from: tms.ef */
/* JADX INFO: loaded from: classes.dex */
final class C1257ef implements IContext.ILayoutInflater {

    /* JADX INFO: renamed from: a */
    LayoutInflater f7235a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1293fo f7236b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ C1293fo.a f7237c;

    C1257ef(C1293fo.a aVar, C1293fo c1293fo) {
        this.f7237c = aVar;
        this.f7236b = c1293fo;
        this.f7235a = LayoutInflater.from(C1293fo.this.f7339b);
    }

    @Override // com.tencent.tmsecure.module.plugin.IContext.ILayoutInflater
    public final View inflate(Activity activity, int i, ViewGroup viewGroup) {
        return this.f7235a.inflate(i, viewGroup);
    }

    @Override // com.tencent.tmsecure.module.plugin.IContext.ILayoutInflater
    public final View inflate(Activity activity, int i, ViewGroup viewGroup, boolean z) {
        return this.f7235a.inflate(i, viewGroup, z);
    }
}
