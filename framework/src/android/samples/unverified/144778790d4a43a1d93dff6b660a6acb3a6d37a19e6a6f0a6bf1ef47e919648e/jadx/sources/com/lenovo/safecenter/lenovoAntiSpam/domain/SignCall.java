package com.lenovo.safecenter.lenovoAntiSpam.domain;

/* JADX INFO: loaded from: classes.dex */
public class SignCall {

    /* JADX INFO: renamed from: a */
    private int f3819a;

    /* JADX INFO: renamed from: b */
    private String f3820b;

    /* JADX INFO: renamed from: c */
    private int f3821c;

    /* JADX INFO: renamed from: d */
    private int f3822d;

    /* JADX INFO: renamed from: e */
    private int f3823e;

    /* JADX INFO: renamed from: f */
    private int f3824f;

    /* JADX INFO: renamed from: g */
    private String f3825g;

    /* JADX INFO: renamed from: h */
    private int f3826h;

    public int getId() {
        return this.f3819a;
    }

    public SignCall() {
        this.f3823e = 0;
        this.f3824f = 0;
        this.f3826h = -1;
    }

    public int getTotalCall() {
        return this.f3824f;
    }

    public SignCall(String number, int sType, int totalCall) {
        this.f3823e = 0;
        this.f3824f = 0;
        this.f3826h = -1;
        this.f3820b = number;
        this.f3822d = sType;
        this.f3824f = totalCall;
    }

    public void setTotalCall(int totalCall) {
        this.f3824f = totalCall;
    }

    public SignCall(int id, String number, int bType, int sType, int isUpload, String addTime) {
        this.f3823e = 0;
        this.f3824f = 0;
        this.f3826h = -1;
        this.f3819a = id;
        this.f3820b = number;
        this.f3821c = bType;
        this.f3822d = sType;
        this.f3823e = isUpload;
        this.f3825g = addTime;
    }

    public SignCall(String number, int bType, int sType, int isUpload, String addTime) {
        this.f3823e = 0;
        this.f3824f = 0;
        this.f3826h = -1;
        this.f3820b = number;
        this.f3821c = bType;
        this.f3822d = sType;
        this.f3823e = isUpload;
        this.f3825g = addTime;
    }

    public void setId(int id) {
        this.f3819a = id;
    }

    public String getNumber() {
        return this.f3820b;
    }

    public void setNumber(String number) {
        this.f3820b = number;
    }

    public int getbType() {
        return this.f3821c;
    }

    public void setbType(int bType) {
        this.f3821c = bType;
    }

    public int getsType() {
        return this.f3822d;
    }

    public void setsType(int sType) {
        this.f3822d = sType;
    }

    public int getIsUpload() {
        return this.f3823e;
    }

    public void setIsUpload(int isUpload) {
        this.f3823e = isUpload;
    }

    public String getAddTime() {
        return this.f3825g;
    }

    public void setAddTime(String addTime) {
        this.f3825g = addTime;
    }

    public int getCallDur() {
        return this.f3826h;
    }

    public void setCallDur(int callDur) {
        this.f3826h = callDur;
    }
}
