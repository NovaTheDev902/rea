package com.tencent.tmsecure.module.networkload;

import com.tencent.tmsecure.module.networkload.NetworkLoadTask;
import java.util.List;
import tms.BinderC1252ea;

/* JADX INFO: loaded from: classes.dex */
public final class DownloadServiceBinder<T extends NetworkLoadTask> extends BinderC1252ea<T> {
    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ List getAllTasks() {
        return super.getAllTasks();
    }

    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ List getFailedTasks() {
        return super.getFailedTasks();
    }

    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ List getFinishedTasks() {
        return super.getFinishedTasks();
    }

    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ List getPausedTasks() {
        return super.getPausedTasks();
    }

    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ List getRunningTasks() {
        return super.getRunningTasks();
    }

    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ List getWaitingTasks() {
        return super.getWaitingTasks();
    }

    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ void registListener(NetworkLoadTaskListener networkLoadTaskListener) {
        super.registListener(networkLoadTaskListener);
    }

    @Override // tms.BinderC1252ea
    public final /* bridge */ /* synthetic */ void setDownloadDirPath(String str) {
        super.setDownloadDirPath(str);
    }

    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ void setNetworkLoadTaskDao(INetworkLoadTaskDao iNetworkLoadTaskDao) {
        super.setNetworkLoadTaskDao(iNetworkLoadTaskDao);
    }

    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ void setRunningTaskCountLimit(byte b) {
        super.setRunningTaskCountLimit(b);
    }

    @Override // tms.AbstractBinderC1230df
    public final /* bridge */ /* synthetic */ void unregistListener(NetworkLoadTaskListener networkLoadTaskListener) {
        super.unregistListener(networkLoadTaskListener);
    }
}
