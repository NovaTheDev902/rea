package com.tencent.tmsecure.module.phoneservice;

import com.lenovo.safecenter.utils.Untils;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Iterator;

/* JADX INFO: loaded from: classes.dex */
public final class IpDialProvinceCityList implements Serializable {

    /* JADX INFO: renamed from: b */
    private static final long f6187b = 1;

    /* JADX INFO: renamed from: a */
    ArrayList<IpDialProvinceCity> f6188a;

    public IpDialProvinceCityList() {
        this.f6188a = new ArrayList<>();
    }

    public IpDialProvinceCityList(IpDialProvinceCityList ipDialProvinceCityList) {
        this();
        copyFrom(ipDialProvinceCityList);
    }

    public final void add(IpDialProvinceCity ipDialProvinceCity) {
        if (ipDialProvinceCity == null || existed(ipDialProvinceCity)) {
            return;
        }
        this.f6188a.add(ipDialProvinceCity);
    }

    public final void clear() {
        this.f6188a.clear();
    }

    public final void copyFrom(IpDialProvinceCityList ipDialProvinceCityList) {
        if (ipDialProvinceCityList != null) {
            this.f6188a.clear();
            Iterator<IpDialProvinceCity> it = ipDialProvinceCityList.f6188a.iterator();
            while (it.hasNext()) {
                this.f6188a.add(new IpDialProvinceCity(it.next()));
            }
        }
    }

    public final void copyFrom(ArrayList<IpDialProvinceCity> arrayList) {
        if (arrayList != null) {
            this.f6188a.clear();
            Iterator<IpDialProvinceCity> it = arrayList.iterator();
            while (it.hasNext()) {
                this.f6188a.add(new IpDialProvinceCity(it.next()));
            }
        }
    }

    public final boolean existed(IpDialProvinceCity ipDialProvinceCity) {
        if (ipDialProvinceCity == null) {
            return false;
        }
        String str = ipDialProvinceCity.getProvince() + ipDialProvinceCity.getCity();
        for (IpDialProvinceCity ipDialProvinceCity2 : this.f6188a) {
            if (ipDialProvinceCity2.getCity().length() == 0) {
                if (ipDialProvinceCity2.getProvince().compareTo(ipDialProvinceCity.getProvince()) == 0) {
                    return true;
                }
            } else if ((ipDialProvinceCity2.getProvince() + ipDialProvinceCity2.getCity()).compareTo(str) == 0) {
                return true;
            }
        }
        return false;
    }

    public final IpDialProvinceCity get(int i) {
        if (isValidIndex(i)) {
            return new IpDialProvinceCity(this.f6188a.get(i));
        }
        return null;
    }

    public final boolean isValidIndex(int i) {
        return i >= 0 && i < this.f6188a.size();
    }

    public final String listToString() {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        for (IpDialProvinceCity ipDialProvinceCity : this.f6188a) {
            sb.append(ipDialProvinceCity.f6185a + ipDialProvinceCity.f6186b).append(Untils.PAUSE);
        }
        sb.append(']');
        return sb.toString();
    }

    public final void remove(int i) {
        if (isValidIndex(i)) {
            this.f6188a.remove(i);
        }
    }

    public final int size() {
        return this.f6188a.size();
    }

    public final ArrayList<IpDialProvinceCity> toArrayList() {
        return new ArrayList<>(this.f6188a);
    }
}
