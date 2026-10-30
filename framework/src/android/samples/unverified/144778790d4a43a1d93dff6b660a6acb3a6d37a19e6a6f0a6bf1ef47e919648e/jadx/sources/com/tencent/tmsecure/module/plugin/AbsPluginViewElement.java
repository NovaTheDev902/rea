package com.tencent.tmsecure.module.plugin;

import android.app.Activity;
import android.content.Intent;

/* JADX INFO: loaded from: classes.dex */
public abstract class AbsPluginViewElement<T> {

    /* JADX INFO: renamed from: a */
    protected Activity f6194a;

    public AbsPluginViewElement(Activity activity) {
        this.f6194a = activity;
    }

    public final void dismiss() {
        if (this.f6194a != null) {
            this.f6194a.finish();
        }
    }

    public final Activity getContainer() {
        return this.f6194a;
    }

    public abstract T getPresentContruct();

    public abstract Object onActivityMethodCall(int i, Object... objArr);

    public void setResult(int i) {
        this.f6194a.setResult(i);
    }

    public void setResult(int i, Intent intent) {
        this.f6194a.setResult(i, intent);
    }
}
