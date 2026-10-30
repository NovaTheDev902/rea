package com.lenovo.lps.reaper.sdk.api;

import java.util.Date;

/* JADX INFO: loaded from: classes.dex */
public final class Event {

    /* JADX INFO: renamed from: a */
    private long f1110a;

    /* JADX INFO: renamed from: b */
    private int f1111b;

    /* JADX INFO: renamed from: c */
    private String f1112c;

    /* JADX INFO: renamed from: d */
    private int f1113d;

    /* JADX INFO: renamed from: e */
    private long f1114e;

    /* JADX INFO: renamed from: f */
    private long f1115f;

    /* JADX INFO: renamed from: g */
    private long f1116g;

    /* JADX INFO: renamed from: h */
    private int f1117h;

    /* JADX INFO: renamed from: i */
    private String f1118i;

    /* JADX INFO: renamed from: j */
    private String f1119j;

    /* JADX INFO: renamed from: k */
    private String f1120k;

    /* JADX INFO: renamed from: l */
    private int f1121l;

    /* JADX INFO: renamed from: m */
    private int f1122m;

    /* JADX INFO: renamed from: n */
    private String f1123n;

    /* JADX INFO: renamed from: o */
    private String f1124o;

    /* JADX INFO: renamed from: p */
    private long f1125p;

    /* JADX INFO: renamed from: q */
    private CustomParameter[] f1126q;

    public Event(String account, String category, String action, String label, int value) {
        this.f1112c = account;
        this.f1118i = category;
        this.f1119j = action;
        this.f1120k = label;
        this.f1121l = value;
        this.f1125p = System.currentTimeMillis();
    }

    public Event(long id, int sessionId, String account, int randomVal, long timestampFirst, long timestampPre, long timestampCur, long timestampEvent, int visits, String category, String action, String label, int value, int networkStauts, String userId, String userIdClass) {
        this.f1110a = id;
        this.f1111b = sessionId;
        this.f1112c = account;
        this.f1113d = randomVal;
        this.f1117h = visits;
        this.f1118i = category;
        this.f1119j = action;
        this.f1120k = label == null ? "" : label;
        this.f1121l = value;
        this.f1122m = networkStauts;
        this.f1123n = userId == null ? "" : userId;
        this.f1124o = userIdClass == null ? "" : userIdClass;
        this.f1122m = networkStauts;
        this.f1114e = timestampFirst;
        this.f1115f = timestampPre;
        this.f1116g = timestampCur;
        this.f1125p = timestampEvent;
    }

    public final String toString() {
        return String.valueOf(this.f1110a);
    }

    public final String toStringFull() {
        StringBuilder strBuff = new StringBuilder(200);
        strBuff.append("ID:").append(this.f1110a).append(" SessionID:").append(this.f1111b).append(" Visits:").append(this.f1117h).append(" Category:").append(this.f1118i).append(" Action:").append(this.f1119j).append(" Label:").append(this.f1120k).append(" Value:").append(this.f1121l).append(" NetworkStatus:").append(this.f1122m).append(" TimestampFirst:").append(new Date(this.f1114e).toLocaleString()).append(" TimestampPre:").append(new Date(this.f1115f).toLocaleString()).append(" TimestampCur:").append(new Date(this.f1116g).toLocaleString()).append(" TimestampEvent:").append(new Date(this.f1125p).toLocaleString());
        return strBuff.toString();
    }

    public final CustomParameter[] getCustomParameters() {
        return this.f1126q;
    }

    public final void setCustomParameters(CustomParameter[] customParameters) {
        this.f1126q = new CustomParameter[customParameters.length];
        for (int i = 0; i < customParameters.length; i++) {
            this.f1126q[i] = new CustomParameter();
            this.f1126q[i].setIndex(customParameters[i].getIndex());
            this.f1126q[i].setName(customParameters[i].getName());
            this.f1126q[i].setValue(customParameters[i].getValue());
        }
    }

    public final long getId() {
        return this.f1110a;
    }

    public final int getSessionId() {
        return this.f1111b;
    }

    public final String getAccount() {
        return this.f1112c;
    }

    public final int getRandomVal() {
        return this.f1113d;
    }

    public final long getTimestampFirst() {
        return this.f1114e;
    }

    public final long getTimestampPre() {
        return this.f1115f;
    }

    public final long getTimestampCur() {
        return this.f1116g;
    }

    public final int getVisits() {
        return this.f1117h;
    }

    public final String getCategory() {
        return this.f1118i;
    }

    public final String getAction() {
        return this.f1119j;
    }

    public final String getLabel() {
        return this.f1120k;
    }

    public final int getValue() {
        return this.f1121l;
    }

    public final int getNetworkStatus() {
        return this.f1122m;
    }

    public final String getUserId() {
        return this.f1123n;
    }

    public final String getUserIdClass() {
        return this.f1124o;
    }

    public final long getTimestampEvent() {
        return this.f1125p;
    }

    public final void setId(long id) {
        this.f1110a = id;
    }

    public final void setSessionId(int sessionId) {
        this.f1111b = sessionId;
    }

    public final void setAccount(String account) {
        this.f1112c = account;
    }

    public final void setRandomVal(int randomVal) {
        this.f1113d = randomVal;
    }

    public final void setTimestampFirst(long timestampFirst) {
        this.f1114e = timestampFirst;
    }

    public final void setTimestampPre(long timestampPre) {
        this.f1115f = timestampPre;
    }

    public final void setTimestampCur(long timestampCur) {
        this.f1116g = timestampCur;
    }

    public final void setVisits(int visits) {
        this.f1117h = visits;
    }

    public final void setCategory(String category) {
        this.f1118i = category;
    }

    public final void setAction(String action) {
        this.f1119j = action;
    }

    public final void setLabel(String label) {
        this.f1120k = label;
    }

    public final void setValue(int value) {
        this.f1121l = value;
    }

    public final void setNetworkStatus(int networkStatus) {
        this.f1122m = networkStatus;
    }

    public final void setTimestampEvent(long timestampEvent) {
        this.f1125p = timestampEvent;
    }
}
