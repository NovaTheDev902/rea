package com.tendcloud.tenddata;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/* JADX INFO: renamed from: com.tendcloud.tenddata.k */
/* JADX INFO: loaded from: classes.dex */
public class C0079k {

    /* JADX INFO: renamed from: a */
    private static final ExecutorService f122a = Executors.newSingleThreadExecutor();

    /* JADX INFO: renamed from: a */
    public static void m71a(Runnable runnable) {
        f122a.execute(runnable);
    }
}
