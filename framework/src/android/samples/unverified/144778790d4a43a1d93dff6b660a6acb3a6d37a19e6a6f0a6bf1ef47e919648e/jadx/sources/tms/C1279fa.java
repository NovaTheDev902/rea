package tms;

import android.os.Parcel;
import android.os.Parcelable;
import com.tencent.tmsecure.module.permission.PermissionTableItem;

/* JADX INFO: renamed from: tms.fa */
/* JADX INFO: loaded from: classes.dex */
public final class C1279fa implements Parcelable.Creator<PermissionTableItem> {
    @Override // android.os.Parcelable.Creator
    /* JADX INFO: renamed from: a, reason: merged with bridge method [inline-methods] */
    public final PermissionTableItem createFromParcel(Parcel parcel) {
        return PermissionTableItem.createFromParcel(parcel);
    }

    @Override // android.os.Parcelable.Creator
    /* JADX INFO: renamed from: a, reason: merged with bridge method [inline-methods] */
    public final PermissionTableItem[] newArray(int i) {
        return new PermissionTableItem[i];
    }
}
