package tms;

import android.os.Parcel;
import android.os.Parcelable;
import com.tencent.tmsecure.common.DataEntity;

/* JADX INFO: renamed from: tms.g */
/* JADX INFO: loaded from: classes.dex */
public final class C1301g implements Parcelable.Creator<DataEntity> {
    @Override // android.os.Parcelable.Creator
    /* JADX INFO: renamed from: a, reason: merged with bridge method [inline-methods] */
    public final DataEntity createFromParcel(Parcel parcel) {
        return new DataEntity(parcel, null);
    }

    @Override // android.os.Parcelable.Creator
    /* JADX INFO: renamed from: a, reason: merged with bridge method [inline-methods] */
    public final DataEntity[] newArray(int i) {
        return new DataEntity[i];
    }
}
