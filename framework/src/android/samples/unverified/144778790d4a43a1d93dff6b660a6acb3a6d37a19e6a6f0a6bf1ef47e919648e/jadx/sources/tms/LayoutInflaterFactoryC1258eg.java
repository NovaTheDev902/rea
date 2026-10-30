package tms;

import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import java.lang.reflect.Constructor;

/* JADX INFO: renamed from: tms.eg */
/* JADX INFO: loaded from: classes.dex */
final class LayoutInflaterFactoryC1258eg implements LayoutInflater.Factory {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1293fo.b f7238a;

    LayoutInflaterFactoryC1258eg(C1293fo.b bVar) {
        this.f7238a = bVar;
    }

    @Override // android.view.LayoutInflater.Factory
    public final View onCreateView(String str, Context context, AttributeSet attributeSet) {
        if (!str.startsWith("com.tencent.qqpimsecure.uilib")) {
            return null;
        }
        try {
            Constructor<?> constructor = (Constructor) C1293fo.f7338i.get(str);
            if (constructor == null) {
                constructor = Class.forName(str).getConstructor(Context.class, AttributeSet.class);
                C1293fo.f7338i.put(str, constructor);
            }
            return (View) constructor.newInstance(C1293fo.this.f7339b, attributeSet);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}
