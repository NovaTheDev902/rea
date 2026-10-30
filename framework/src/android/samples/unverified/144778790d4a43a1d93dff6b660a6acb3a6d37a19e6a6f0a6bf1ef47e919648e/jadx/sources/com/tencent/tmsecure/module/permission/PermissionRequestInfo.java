package com.tencent.tmsecure.module.permission;

import android.os.Binder;
import android.os.Parcel;
import android.os.Parcelable;
import tms.C1277ez;

/* JADX INFO: loaded from: classes.dex */
public final class PermissionRequestInfo implements Parcelable {
    public static Parcelable.Creator<PermissionRequestInfo> CREATOR = new C1277ez();
    public String[] mInfo1;
    public int[] mInfo2;
    public byte[] mInfo3;
    public int mRid;
    public int mValue;
    public int mPid = Binder.getCallingPid();
    public int mUid = Binder.getCallingUid();

    public static PermissionRequestInfo createFromParcel(Parcel parcel) {
        PermissionRequestInfo permissionRequestInfo = new PermissionRequestInfo();
        permissionRequestInfo.mPid = parcel.readInt();
        permissionRequestInfo.mUid = parcel.readInt();
        permissionRequestInfo.mValue = parcel.readInt();
        permissionRequestInfo.mRid = parcel.readInt();
        permissionRequestInfo.mInfo1 = parcel.createStringArray();
        permissionRequestInfo.mInfo2 = parcel.createIntArray();
        permissionRequestInfo.mInfo3 = parcel.createByteArray();
        return permissionRequestInfo;
    }

    @Override // android.os.Parcelable
    public final int describeContents() {
        return 0;
    }

    @Override // android.os.Parcelable
    public final void writeToParcel(Parcel parcel, int i) {
        parcel.writeInt(this.mPid);
        parcel.writeInt(this.mUid);
        parcel.writeInt(this.mValue);
        parcel.writeInt(this.mRid);
        parcel.writeStringArray(this.mInfo1);
        parcel.writeIntArray(this.mInfo2);
        parcel.writeByteArray(this.mInfo3);
    }
}
