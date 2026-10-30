package tms;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import com.tencent.tmsecure.module.plugin.IContext;

/* JADX INFO: renamed from: tms.em */
/* JADX INFO: loaded from: classes.dex */
final class C1264em implements IContext.ILayoutInflater {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1293fo f7249a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1293fo.b f7250b;

    C1264em(C1293fo.b bVar, C1293fo c1293fo) {
        this.f7250b = bVar;
        this.f7249a = c1293fo;
    }

    @Override // com.tencent.tmsecure.module.plugin.IContext.ILayoutInflater
    public final View inflate(Activity activity, int i, ViewGroup viewGroup) {
        this.f7250b.f7356f.m3342a(activity, this.f7250b.f7355e);
        LayoutInflater layoutInflaterFrom = LayoutInflater.from(activity);
        if (layoutInflaterFrom.getFactory() == null) {
            layoutInflaterFrom.setFactory(this.f7250b.f7357g);
        }
        View viewInflate = layoutInflaterFrom.inflate(this.f7250b.f7354d.getXml(i), viewGroup);
        this.f7250b.f7356f.m3341a();
        return viewInflate;
    }

    @Override // com.tencent.tmsecure.module.plugin.IContext.ILayoutInflater
    public final View inflate(Activity activity, int i, ViewGroup viewGroup, boolean z) {
        this.f7250b.f7356f.m3342a(activity, this.f7250b.f7355e);
        View viewInflate = LayoutInflater.from(activity).inflate(this.f7250b.f7354d.getXml(i), viewGroup, z);
        this.f7250b.f7356f.m3341a();
        return viewInflate;
    }
}
