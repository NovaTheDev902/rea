package tms;

import android.os.Parcel;
import android.os.Parcelable;
import com.tencent.tmsecure.module.permission.PermissionRequestInfo;

/* JADX INFO: renamed from: tms.ez */
/* JADX INFO: loaded from: classes.dex */
public final class C1277ez implements Parcelable.Creator<PermissionRequestInfo> {
    @Override // android.os.Parcelable.Creator
    /* JADX INFO: renamed from: a, reason: merged with bridge method [inline-methods] */
    public final PermissionRequestInfo createFromParcel(Parcel parcel) {
        return PermissionRequestInfo.createFromParcel(parcel);
    }

    @Override // android.os.Parcelable.Creator
    /* JADX INFO: renamed from: a, reason: merged with bridge method [inline-methods] */
    public final PermissionRequestInfo[] newArray(int i) {
        return new PermissionRequestInfo[i];
    }
}
