package com.tencent.tmsecure.module.netsetting;

import com.tencent.tmsecure.common.ManagerCreator;

/* JADX INFO: loaded from: classes.dex */
public final class Proguard {
    public final void callAllMethods() {
        NetSettingManager netSettingManager = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
        netSettingManager.getApnState();
        netSettingManager.setApnState(false);
        netSettingManager.getAPNType(null);
        netSettingManager.getCurUsedApn();
        netSettingManager.getMobileDataConnectivity();
        netSettingManager.setApnState(false);
        netSettingManager.setMobileDataConnectivity(false);
        netSettingManager.isMobileDataConnectivityActive();
        netSettingManager.isWifiActive();
        netSettingManager.switchTo(0);
    }
}
