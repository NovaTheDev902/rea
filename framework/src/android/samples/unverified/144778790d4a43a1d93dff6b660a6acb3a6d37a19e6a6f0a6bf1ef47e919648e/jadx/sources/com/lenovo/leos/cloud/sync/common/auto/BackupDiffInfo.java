package com.lenovo.leos.cloud.sync.common.auto;

import android.os.Parcel;
import android.os.Parcelable;

/* JADX INFO: loaded from: classes.dex */
public class BackupDiffInfo implements Parcelable {
    public static final Parcelable.Creator<BackupDiffInfo> CREATOR = new Parcelable.Creator<BackupDiffInfo>() { // from class: com.lenovo.leos.cloud.sync.common.auto.BackupDiffInfo.1
        @Override // android.os.Parcelable.Creator
        public final /* synthetic */ BackupDiffInfo createFromParcel(Parcel x0) {
            BackupDiffInfo backupDiffInfo = new BackupDiffInfo();
            backupDiffInfo.setNeverBackup(x0.readByte() != 0);
            backupDiffInfo.opAdd = x0.readInt();
            backupDiffInfo.opDelete = x0.readInt();
            backupDiffInfo.opUpdate = x0.readInt();
            return backupDiffInfo;
        }

        @Override // android.os.Parcelable.Creator
        public final /* bridge */ /* synthetic */ BackupDiffInfo[] newArray(int x0) {
            return new BackupDiffInfo[x0];
        }
    };
    public boolean neverBackup = true;
    public int opAdd;
    public int opDelete;
    public int opUpdate;

    public boolean isNeverBackup() {
        return this.neverBackup;
    }

    public void setNeverBackup(boolean everBackup) {
        this.neverBackup = everBackup;
    }

    @Override // android.os.Parcelable
    public int describeContents() {
        return 0;
    }

    @Override // android.os.Parcelable
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeByte(this.neverBackup ? (byte) 1 : (byte) 0);
        dest.writeInt(this.opAdd);
        dest.writeInt(this.opDelete);
        dest.writeInt(this.opUpdate);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("neverBackup:").append(this.neverBackup);
        sb.append(",add:").append(this.opAdd);
        sb.append(",del:").append(this.opDelete);
        sb.append(",update:").append(this.opUpdate);
        return sb.toString();
    }
}
