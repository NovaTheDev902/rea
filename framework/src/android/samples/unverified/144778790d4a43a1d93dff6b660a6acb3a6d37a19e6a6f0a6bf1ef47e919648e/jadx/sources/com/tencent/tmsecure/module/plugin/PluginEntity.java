package com.tencent.tmsecure.module.plugin;

import com.tencent.tmsecure.common.BaseEntity;

/* JADX INFO: loaded from: classes.dex */
public class PluginEntity extends BaseEntity {

    /* JADX INFO: renamed from: a */
    private int f6195a = -1;
    public String mPluginFilePath;
    public IPluginInterface mPluginInterface;
    public String mPluginName;
    public String mPluginPkgName;
    public int mPluginVerion;

    public boolean equals(Object obj) {
        return (obj instanceof PluginEntity) && getKey() == ((PluginEntity) obj).getKey();
    }

    public int getKey() {
        if (this.f6195a == -1) {
            this.f6195a = this.mPluginInterface.getClass().getName().hashCode();
        }
        return this.f6195a;
    }

    public int hashCode() {
        return getKey() + 48;
    }
}
