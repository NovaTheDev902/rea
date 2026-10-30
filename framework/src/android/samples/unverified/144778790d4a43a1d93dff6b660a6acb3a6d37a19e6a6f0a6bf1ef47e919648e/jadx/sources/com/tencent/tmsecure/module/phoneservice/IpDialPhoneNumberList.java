package com.tencent.tmsecure.module.phoneservice;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Iterator;
import tms.C1150ag;

/* JADX INFO: loaded from: classes.dex */
public final class IpDialPhoneNumberList implements Serializable {

    /* JADX INFO: renamed from: b */
    private static final long f6182b = 1;

    /* JADX INFO: renamed from: a */
    ArrayList<IpDialPhoneNumber> f6183a;

    public IpDialPhoneNumberList() {
        this.f6183a = new ArrayList<>();
    }

    public IpDialPhoneNumberList(IpDialPhoneNumberList ipDialPhoneNumberList) {
        this();
        copyFrom(ipDialPhoneNumberList);
    }

    public final void add(IpDialPhoneNumber ipDialPhoneNumber) {
        if (ipDialPhoneNumber == null || existed(ipDialPhoneNumber)) {
            return;
        }
        this.f6183a.add(ipDialPhoneNumber);
    }

    public final void clear() {
        this.f6183a.clear();
    }

    public final void copyFrom(IpDialPhoneNumberList ipDialPhoneNumberList) {
        if (ipDialPhoneNumberList != null) {
            this.f6183a.clear();
            Iterator<IpDialPhoneNumber> it = ipDialPhoneNumberList.f6183a.iterator();
            while (it.hasNext()) {
                this.f6183a.add(new IpDialPhoneNumber(it.next()));
            }
        }
    }

    public final void copyFrom(ArrayList<IpDialPhoneNumber> arrayList) {
        if (arrayList != null) {
            this.f6183a.clear();
            Iterator<IpDialPhoneNumber> it = arrayList.iterator();
            while (it.hasNext()) {
                add(new IpDialPhoneNumber(it.next()));
            }
        }
    }

    public final boolean existed(IpDialPhoneNumber ipDialPhoneNumber) {
        if (ipDialPhoneNumber == null) {
            return false;
        }
        Iterator<IpDialPhoneNumber> it = this.f6183a.iterator();
        while (it.hasNext()) {
            if (C1150ag.m2892a(it.next().getPhoneNumber(), ipDialPhoneNumber.getPhoneNumber())) {
                return true;
            }
        }
        return false;
    }

    public final IpDialPhoneNumber get(int i) {
        if (isValidIndex(i)) {
            return this.f6183a.get(i);
        }
        return null;
    }

    public final boolean isValidIndex(int i) {
        return i >= 0 && i < this.f6183a.size();
    }

    public final String listToString() {
        return this.f6183a.toString();
    }

    public final void remove(int i) {
        if (isValidIndex(i)) {
            this.f6183a.remove(i);
        }
    }

    public final int size() {
        return this.f6183a.size();
    }

    public final ArrayList<IpDialPhoneNumber> toArrayList() {
        return new ArrayList<>(this.f6183a);
    }
}
