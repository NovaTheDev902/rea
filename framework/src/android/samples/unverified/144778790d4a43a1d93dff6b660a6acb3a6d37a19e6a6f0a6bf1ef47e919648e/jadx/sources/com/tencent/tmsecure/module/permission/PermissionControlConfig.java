package com.tencent.tmsecure.module.permission;

import android.os.Parcel;
import android.os.Parcelable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public final class PermissionControlConfig implements Parcelable {
    public static final int PERMISSION_MODE_ABORT = 1;
    public static final int PERMISSION_MODE_ACCEPT = 0;
    public static final byte PERMISSION_MODE_ASK = 2;
    public static final int PERMISSION_MODE_NULL = 65535;

    /* JADX INFO: renamed from: a */
    private HashMap<Integer, PermissionTableItem> f6168a = new HashMap<>();

    /* JADX INFO: renamed from: b */
    private String f6169b;

    public PermissionControlConfig(List<PermissionTableItem> list, String str) {
        for (PermissionTableItem permissionTableItem : list) {
            this.f6168a.put(Integer.valueOf(permissionTableItem.mUid), permissionTableItem);
        }
        this.f6169b = str;
    }

    public static PermissionControlConfig createFromParcel(Parcel parcel) {
        int i = parcel.readInt();
        ArrayList arrayList = new ArrayList(i);
        for (int i2 = 0; i2 < i; i2++) {
            arrayList.add(PermissionTableItem.createFromParcel(parcel));
        }
        return new PermissionControlConfig(arrayList, parcel.readString());
    }

    public final boolean addItem(PermissionTableItem permissionTableItem) {
        if (this.f6168a.values().contains(permissionTableItem)) {
            return false;
        }
        this.f6168a.put(Integer.valueOf(permissionTableItem.mUid), permissionTableItem);
        return true;
    }

    @Override // android.os.Parcelable
    public final int describeContents() {
        return 0;
    }

    public final String getDummyDatabaseName() {
        return this.f6169b;
    }

    public final PermissionTableItem getItemByUid(int i) {
        return this.f6168a.get(Integer.valueOf(i));
    }

    public final ArrayList<PermissionTableItem> getItems() {
        return new ArrayList<>(this.f6168a.values());
    }

    public final int getValue(int i, int i2) {
        PermissionTableItem permissionTableItem = this.f6168a.get(Integer.valueOf(i));
        if (permissionTableItem == null || i2 >= PermissionRequestIDs.getCount()) {
            return -1;
        }
        return permissionTableItem.mRids[i2];
    }

    public final boolean removeItem(PermissionTableItem permissionTableItem) {
        if (!this.f6168a.values().contains(permissionTableItem)) {
            return false;
        }
        this.f6168a.remove(Integer.valueOf(permissionTableItem.mUid));
        return true;
    }

    public final void setDummyDatabaseName(String str) {
        this.f6169b = str;
    }

    public final boolean update(int i, int i2, int i3) {
        PermissionTableItem permissionTableItem = this.f6168a.get(Integer.valueOf(i));
        if (permissionTableItem != null && i2 < PermissionRequestIDs.getCount()) {
            permissionTableItem.mRids[i2] = i3;
        }
        return permissionTableItem != null;
    }

    public final boolean update(PermissionTableItem permissionTableItem) {
        Integer numValueOf = Integer.valueOf(permissionTableItem.mUid);
        PermissionTableItem permissionTableItem2 = this.f6168a.get(numValueOf);
        if (permissionTableItem2 != null) {
            this.f6168a.put(numValueOf, permissionTableItem);
        }
        return permissionTableItem2 != null;
    }

    @Override // android.os.Parcelable
    public final void writeToParcel(Parcel parcel, int i) {
        parcel.writeInt(this.f6168a.values().size());
        Iterator<PermissionTableItem> it = this.f6168a.values().iterator();
        while (it.hasNext()) {
            it.next().writeToParcel(parcel, 0);
        }
        parcel.writeString(this.f6169b);
    }
}
