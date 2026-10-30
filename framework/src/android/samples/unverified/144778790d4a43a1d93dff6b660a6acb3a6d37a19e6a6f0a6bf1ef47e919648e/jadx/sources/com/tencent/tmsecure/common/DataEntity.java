package com.tencent.tmsecure.common;

import android.os.Bundle;
import android.os.Parcel;
import android.os.Parcelable;
import tms.C1301g;

/* JADX INFO: loaded from: classes.dex */
public final class DataEntity implements Parcelable {
    public static final Parcelable.Creator<DataEntity> CREATOR = new C1301g();

    /* JADX INFO: renamed from: a */
    private Bundle f6030a;

    /* JADX INFO: renamed from: b */
    private int f6031b;

    public DataEntity(int i) {
        this.f6031b = i;
        this.f6030a = new Bundle();
    }

    private DataEntity(Parcel parcel) {
        this.f6031b = parcel.readInt();
        this.f6030a = parcel.readBundle();
    }

    public /* synthetic */ DataEntity(Parcel parcel, C1301g c1301g) {
        this(parcel);
    }

    public final Bundle bundle() {
        return this.f6030a;
    }

    @Override // android.os.Parcelable
    public final int describeContents() {
        return 0;
    }

    public final int what() {
        return this.f6031b;
    }

    @Override // android.os.Parcelable
    public final void writeToParcel(Parcel parcel, int i) {
        parcel.writeInt(this.f6031b);
        parcel.writeBundle(this.f6030a);
    }
}
