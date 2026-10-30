package com.lenovo.safecenter.lenovoAntiSpam.domain;

/* JADX INFO: loaded from: classes.dex */
public class BlackInfo {

    /* JADX INFO: renamed from: a */
    private int f3802a;

    /* JADX INFO: renamed from: b */
    private String f3803b;

    /* JADX INFO: renamed from: c */
    private String f3804c;

    /* JADX INFO: renamed from: d */
    private int f3805d;

    /* JADX INFO: renamed from: e */
    private int f3806e;

    /* JADX INFO: renamed from: f */
    private boolean f3807f;

    /* JADX INFO: renamed from: g */
    private int f3808g;

    /* JADX INFO: renamed from: h */
    private String f3809h;

    public BlackInfo() {
        this.f3806e = 0;
        this.f3807f = false;
        this.f3808g = 0;
    }

    public BlackInfo(String name, String phoneNumber, int type, int isUpload) {
        this.f3806e = 0;
        this.f3807f = false;
        this.f3808g = 0;
        this.f3803b = name;
        this.f3804c = phoneNumber;
        this.f3805d = type;
        this.f3806e = isUpload;
    }

    public BlackInfo(int id, String name, String phoneNumber, int type, int isUpload) {
        this.f3806e = 0;
        this.f3807f = false;
        this.f3808g = 0;
        this.f3802a = id;
        this.f3803b = name;
        this.f3804c = phoneNumber;
        this.f3805d = type;
        this.f3806e = isUpload;
    }

    public int getId() {
        return this.f3802a;
    }

    public void setId(int id) {
        this.f3802a = id;
    }

    public String getName() {
        return this.f3803b;
    }

    public void setName(String name) {
        this.f3803b = name;
    }

    public String getPhoneNumber() {
        return this.f3804c;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.f3804c = phoneNumber;
    }

    public int getType() {
        return this.f3805d;
    }

    public void setType(int type) {
        this.f3805d = type;
    }

    public int getIsUpload() {
        return this.f3806e;
    }

    public void setIsUpload(int isUpload) {
        this.f3806e = isUpload;
    }

    public boolean isSelect() {
        return this.f3807f;
    }

    public void setSelect(boolean isSelect) {
        this.f3807f = isSelect;
    }

    public int getIntercepttype() {
        return this.f3808g;
    }

    public void setIntercepttype(int intercepttype) {
        this.f3808g = intercepttype;
    }

    public String getRealnumber() {
        return this.f3809h;
    }

    public void setRealnumber(String realnumber) {
        this.f3809h = realnumber;
    }
}
