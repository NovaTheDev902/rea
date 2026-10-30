package com.tencent.tmsecure.module.aresengine;

import android.content.Intent;
import android.os.Parcel;

/* JADX INFO: loaded from: classes.dex */
public class SmsEntity extends TelephonyEntity {
    public static final int PROTOCOL_TYPE_MMS = 1;
    public static final int PROTOCOL_TYPE_SMS = 0;
    public static final int PROTOCOL_TYPE_WAPPUSH = 2;
    public static final int SMS_TYPE_IN = 1;
    public static final int SMS_TYPE_OUT = 2;

    /* JADX INFO: renamed from: a */
    private static final long f6093a = 1;
    public String body;
    public long date;
    public int protocolType;
    public transient Intent raw;
    public int read;
    public int smstype;
    public int type;

    public SmsEntity() {
        this.read = 0;
        this.protocolType = 0;
        this.smstype = this.protocolType;
        this.date = System.currentTimeMillis();
    }

    private SmsEntity(Parcel parcel) {
        this.f6027id = parcel.readInt();
        this.phonenum = parcel.readString();
        this.name = parcel.readString();
        this.body = parcel.readString();
        this.date = parcel.readLong();
        this.type = parcel.readInt();
        this.protocolType = parcel.readInt();
        this.read = parcel.readInt();
        this.smstype = parcel.readInt();
        this.raw = (Intent) parcel.readParcelable(Intent.class.getClassLoader());
    }

    public SmsEntity(SmsEntity smsEntity) {
        super(smsEntity);
        this.body = smsEntity.body;
        this.date = smsEntity.date;
        this.type = smsEntity.type;
        this.protocolType = smsEntity.protocolType;
        this.read = smsEntity.read;
        this.smstype = smsEntity.smstype;
        this.raw = smsEntity.raw;
    }

    /* JADX INFO: renamed from: a */
    public static SmsEntity m2605a(byte[] bArr) {
        Parcel parcelObtain = Parcel.obtain();
        parcelObtain.unmarshall(bArr, 0, bArr.length);
        parcelObtain.setDataPosition(0);
        SmsEntity smsEntity = new SmsEntity(parcelObtain);
        parcelObtain.recycle();
        return smsEntity;
    }

    /* JADX INFO: renamed from: a */
    private void m2606a(Parcel parcel, int i) {
        parcel.writeInt(this.f6027id);
        parcel.writeString(this.phonenum);
        parcel.writeString(this.name);
        parcel.writeString(this.body);
        parcel.writeLong(this.date);
        parcel.writeInt(this.type);
        parcel.writeInt(this.protocolType);
        parcel.writeInt(this.read);
        parcel.writeInt(this.smstype);
        parcel.writeParcelable(this.raw, 0);
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m2607a(SmsEntity smsEntity) {
        Parcel parcelObtain = Parcel.obtain();
        smsEntity.m2606a(parcelObtain, 0);
        byte[] bArrMarshall = parcelObtain.marshall();
        parcelObtain.recycle();
        return bArrMarshall;
    }

    public String getBody() {
        return this.body;
    }

    public void setBody(String str) {
        if (str == null) {
            str = "";
        }
        this.body = str;
    }
}
