package com.lenovo.feedback2.message;

import android.os.Parcel;
import android.os.Parcelable;

/* JADX INFO: loaded from: classes.dex */
public class Message implements Parcelable {
    public static final Parcelable.Creator<Message> CREATOR = new Parcelable.Creator<Message>() { // from class: com.lenovo.feedback2.message.Message.1
        @Override // android.os.Parcelable.Creator
        public final /* synthetic */ Message createFromParcel(Parcel parcel) {
            return new Message(parcel, (byte) 0);
        }

        @Override // android.os.Parcelable.Creator
        public final /* bridge */ /* synthetic */ Message[] newArray(int i) {
            return new Message[i];
        }
    };

    /* JADX INFO: renamed from: a */
    private int f961a;

    /* JADX INFO: renamed from: b */
    private String f962b;

    /* JADX INFO: renamed from: c */
    private int f963c;

    /* JADX INFO: renamed from: d */
    private byte[] f964d;

    public int getVersion() {
        return this.f961a;
    }

    public void setVersion(int version) {
        this.f961a = version;
    }

    public String getHeader() {
        return this.f962b;
    }

    public void setHeader(String header) {
        this.f962b = header;
    }

    public byte[] getData() {
        return this.f964d;
    }

    public void setData(byte[] data) {
        this.f964d = data;
        this.f963c = data.length;
    }

    public Message() {
    }

    private Message(Parcel in) {
        readFromParcel(in);
    }

    /* synthetic */ Message(Parcel parcel, byte b) {
        this(parcel);
    }

    @Override // android.os.Parcelable
    public int describeContents() {
        return 0;
    }

    @Override // android.os.Parcelable
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeInt(this.f961a);
        dest.writeString(this.f962b);
        dest.writeInt(this.f963c);
        dest.writeByteArray(this.f964d);
    }

    public void readFromParcel(Parcel in) {
        this.f961a = in.readInt();
        this.f962b = in.readString();
        this.f963c = in.readInt();
        this.f964d = new byte[this.f963c];
        in.readByteArray(this.f964d);
    }
}
