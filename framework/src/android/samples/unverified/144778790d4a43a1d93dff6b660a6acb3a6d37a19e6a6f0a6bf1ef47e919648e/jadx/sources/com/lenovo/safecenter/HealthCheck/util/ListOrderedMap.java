package com.lenovo.safecenter.HealthCheck.util;

import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class ListOrderedMap {

    /* JADX INFO: renamed from: b */
    private ArrayList<HealthItemResult> f2450b;

    /* JADX INFO: renamed from: d */
    private boolean f2452d;

    /* JADX INFO: renamed from: a */
    private HashMap<Integer, HealthItemResult> f2449a = new HashMap<>();

    /* JADX INFO: renamed from: c */
    private Comparator<HealthItemResult> f2451c = new Comparator<HealthItemResult>() { // from class: com.lenovo.safecenter.HealthCheck.util.ListOrderedMap.1
        @Override // java.util.Comparator
        public final /* bridge */ /* synthetic */ int compare(HealthItemResult healthItemResult, HealthItemResult healthItemResult2) {
            HealthItemResult healthItemResult3 = healthItemResult;
            HealthItemResult healthItemResult4 = healthItemResult2;
            int i = healthItemResult3.weight;
            int i2 = healthItemResult4.weight;
            return i - i2 == 0 ? healthItemResult3.key - healthItemResult4.key : i - i2;
        }
    };

    public HealthItemResult put(int key, HealthItemResult value) {
        HealthItemResult healthItemResultPut;
        synchronized (this.f2449a) {
            this.f2452d = false;
            healthItemResultPut = this.f2449a.put(Integer.valueOf(key), value);
        }
        return healthItemResultPut;
    }

    public HealthItemResult remove(int key) {
        HealthItemResult healthItemResultRemove;
        synchronized (this.f2449a) {
            this.f2452d = false;
            healthItemResultRemove = this.f2449a.remove(Integer.valueOf(key));
        }
        return healthItemResultRemove;
    }

    public void clear() {
        synchronized (this.f2449a) {
            this.f2449a.clear();
            this.f2450b.clear();
        }
    }

    public HealthItemResult getValueByIndex(int index) {
        HealthItemResult healthItemResult;
        synchronized (this.f2449a) {
            while (!this.f2452d) {
                synchronized (this.f2449a) {
                    ArrayList<HealthItemResult> arrayList = new ArrayList<>(this.f2449a.values());
                    Collections.sort(arrayList, this.f2451c);
                    this.f2450b = arrayList;
                    this.f2452d = true;
                }
            }
            healthItemResult = this.f2450b.get(index);
        }
        return healthItemResult;
    }

    public HealthItemResult getValueByKey(int key) {
        HealthItemResult healthItemResult;
        synchronized (this.f2449a) {
            healthItemResult = this.f2449a.get(Integer.valueOf(key));
        }
        return healthItemResult;
    }

    public int size() {
        int size;
        synchronized (this.f2449a) {
            size = this.f2449a.size();
        }
        return size;
    }
}
