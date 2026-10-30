package com.lenovo.safecenter.antivirus.domain;

/* JADX INFO: loaded from: classes.dex */
public class VirusDemo {

    /* JADX INFO: renamed from: a */
    private int f3029a;

    /* JADX INFO: renamed from: b */
    private String f3030b;

    /* JADX INFO: renamed from: c */
    private String f3031c;

    /* JADX INFO: renamed from: d */
    private String f3032d;

    /* JADX INFO: renamed from: e */
    private String f3033e;

    /* JADX INFO: renamed from: f */
    private String f3034f;

    /* JADX INFO: renamed from: g */
    private String f3035g;

    /* JADX INFO: renamed from: h */
    private String f3036h;

    /* JADX INFO: renamed from: i */
    private String f3037i;

    /* JADX INFO: renamed from: j */
    private int f3038j;

    public int getPathKey() {
        return this.f3038j;
    }

    public void setPathKey(int pathKey) {
        this.f3038j = pathKey;
    }

    public VirusDemo() {
    }

    public VirusDemo(String name, String pkgName, String pkgSha1, String certmd5, String type, String source, String filesize) {
        this.f3030b = name;
        this.f3031c = pkgName;
        this.f3032d = pkgSha1;
        this.f3033e = certmd5;
        this.f3034f = type;
        this.f3035g = source;
        this.f3037i = filesize;
    }

    public VirusDemo(int id, String name, String pkgName, String pkgSha1, String certmd5, String type, String source, String filesize) {
        this.f3029a = id;
        this.f3030b = name;
        this.f3031c = pkgName;
        this.f3032d = pkgSha1;
        this.f3033e = certmd5;
        this.f3034f = type;
        this.f3035g = source;
        this.f3037i = filesize;
    }

    public String getName() {
        return this.f3030b;
    }

    public void setName(String name) {
        this.f3030b = name;
    }

    public String getPkgName() {
        return this.f3031c;
    }

    public void setPkgName(String pkgName) {
        this.f3031c = pkgName;
    }

    public String getPkgSha1() {
        return this.f3032d;
    }

    public void setPkgSha1(String pkgSha1) {
        this.f3032d = pkgSha1;
    }

    public String getCertmd5() {
        return this.f3033e;
    }

    public void setCertmd5(String certmd5) {
        this.f3033e = certmd5;
    }

    public String getType() {
        return this.f3034f;
    }

    public void setType(String type) {
        this.f3034f = type;
    }

    public String getSource() {
        return this.f3035g;
    }

    public void setSource(String source) {
        this.f3035g = source;
    }

    public String getVirusDesc() {
        return this.f3036h;
    }

    public void setVirusDesc(String virusDesc) {
        this.f3036h = virusDesc;
    }

    public String getFilesize() {
        return this.f3037i;
    }

    public void setFilesize(String filesize) {
        this.f3037i = filesize;
    }
}
