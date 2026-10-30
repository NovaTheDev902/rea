package com.lenovo.safecenter.lenovoAntiSpam.domain;

/* JADX INFO: loaded from: classes.dex */
public class Contract {

    /* JADX INFO: renamed from: a */
    private String f3810a;

    /* JADX INFO: renamed from: b */
    private String f3811b;

    /* JADX INFO: renamed from: c */
    private int f3812c;

    /* JADX INFO: renamed from: d */
    private String f3813d;

    /* JADX INFO: renamed from: e */
    private int f3814e;

    /* JADX INFO: renamed from: f */
    private String f3815f;

    /* JADX INFO: renamed from: g */
    private boolean f3816g = false;

    /* JADX INFO: renamed from: h */
    private String f3817h;

    public Contract() {
    }

    public Contract(String name, String phoneNumber, int type, String date, int callType) {
        this.f3810a = name;
        this.f3811b = phoneNumber;
        this.f3812c = type;
        this.f3813d = date;
        this.f3814e = callType;
    }

    public Contract(String name, String phoneNumber, int type, String date, String smsContent) {
        this.f3810a = name;
        this.f3811b = phoneNumber;
        this.f3812c = type;
        this.f3813d = date;
        this.f3815f = smsContent;
    }

    public String getName() {
        return this.f3810a;
    }

    public void setName(String name) {
        this.f3810a = name;
    }

    public String getPhoneNumber() {
        return this.f3811b;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.f3811b = phoneNumber;
    }

    public int getType() {
        return this.f3812c;
    }

    public void setType(int type) {
        this.f3812c = type;
    }

    public String getDate() {
        return this.f3813d;
    }

    public void setDate(String date) {
        this.f3813d = date;
    }

    public int getCallType() {
        return this.f3814e;
    }

    public void setCallType(int callType) {
        this.f3814e = callType;
    }

    public String getSmsContent() {
        return this.f3815f;
    }

    public void setSmsContent(String smsContent) {
        this.f3815f = smsContent;
    }

    public boolean isSelect() {
        return this.f3816g;
    }

    public void setSelect(boolean isSelect) {
        this.f3816g = isSelect;
    }

    public String getRealnumber() {
        return this.f3817h;
    }

    public void setRealnumber(String realnumber) {
        this.f3817h = realnumber;
    }
}
