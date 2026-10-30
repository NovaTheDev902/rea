package com.tencent.tmsecure.module.networkload;

import tms.C1149af;

/* JADX INFO: loaded from: classes.dex */
public class NetworkloadProperties {

    /* JADX INFO: renamed from: b */
    private static final String f6106b = "mobile_download_bytes";

    /* JADX INFO: renamed from: c */
    private static final String f6107c = "mobile_upload_bytes";

    /* JADX INFO: renamed from: a */
    private static final String f6105a = "networkload";

    /* JADX INFO: renamed from: d */
    private static C1149af f6108d = new C1149af(f6105a);

    public static synchronized long getSelfMobileDownloadBytes() {
        return f6108d.m2882a(f6106b, 0L);
    }

    public static synchronized long getSelfMobileUploadBytes() {
        return f6108d.m2882a(f6107c, 0L);
    }

    public static synchronized void updateSelfMobileDownloadBytes(long j) {
        f6108d.m2887a(f6106b, j, true);
    }

    public static synchronized void updateSelfMobileUploadBytes(long j) {
        f6108d.m2887a(f6107c, j, true);
    }
}
