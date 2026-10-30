package com.lenovo.safecenter.utils.update;

/* JADX INFO: loaded from: classes.dex */
public class LeSafeUpdateInfo {

    /* JADX INFO: renamed from: a */
    private String f5866a;

    /* JADX INFO: renamed from: b */
    private String f5867b;

    /* JADX INFO: renamed from: c */
    private String f5868c;

    /* JADX INFO: renamed from: d */
    private String f5869d;

    /* JADX INFO: renamed from: e */
    private String f5870e;

    /* JADX INFO: renamed from: f */
    private String f5871f;

    /* JADX INFO: renamed from: g */
    private long f5872g;

    public LeSafeUpdateInfo(String channelKey, String versionName, String versionCode, String updateDesc, String url, String apkName, long fileSize) {
        this.f5866a = channelKey;
        this.f5867b = versionName;
        this.f5868c = versionCode;
        this.f5869d = updateDesc;
        this.f5870e = url;
        this.f5871f = apkName;
        this.f5872g = fileSize;
    }

    public String getChannelKey() {
        return this.f5866a;
    }

    public String getVersionName() {
        return this.f5867b;
    }

    public String getVersionCode() {
        return this.f5868c;
    }

    public String getUpdateDesc() {
        return this.f5869d;
    }

    public String getUrl() {
        return this.f5870e;
    }

    public String getApkName() {
        return this.f5871f;
    }

    public long getFileSize() {
        return this.f5872g;
    }

    public String toString() {
        return "LeSafeUpdateInfo [channelKey=" + this.f5866a + ", versionName=" + this.f5867b + ", versionCode=" + this.f5868c + ", updateDesc=" + this.f5869d + ", url=" + this.f5870e + ", apkName=" + this.f5871f + ", fileSize=" + this.f5872g + "]";
    }
}
