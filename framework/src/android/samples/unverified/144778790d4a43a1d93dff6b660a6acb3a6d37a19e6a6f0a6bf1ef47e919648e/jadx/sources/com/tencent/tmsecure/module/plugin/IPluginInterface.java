package com.tencent.tmsecure.module.plugin;

import android.app.Activity;

/* JADX INFO: loaded from: classes.dex */
public interface IPluginInterface {
    Object getProperty(String str);

    AbsPluginViewElement<?> getStartViewElement(Activity activity);

    AbsPluginViewElement<?> getViewElement(int i, Activity activity);

    void onCreate(IContext iContext, IContext iContext2, AbsPluginControler absPluginControler);

    void setProperty(String str, Object obj);
}
