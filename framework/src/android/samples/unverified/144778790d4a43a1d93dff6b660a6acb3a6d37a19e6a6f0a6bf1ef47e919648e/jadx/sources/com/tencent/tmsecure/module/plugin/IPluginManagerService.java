package com.tencent.tmsecure.module.plugin;

import android.os.IInterface;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public interface IPluginManagerService extends IInterface {
    List<PluginEntity> getAllPlugins();
}
