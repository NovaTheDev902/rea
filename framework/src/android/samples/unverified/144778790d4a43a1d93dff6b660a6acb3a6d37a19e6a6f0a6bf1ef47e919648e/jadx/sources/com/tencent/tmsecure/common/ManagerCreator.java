package com.tencent.tmsecure.common;

import android.content.Context;
import java.lang.ref.WeakReference;
import java.util.HashMap;
import tms.C1278f;

/* JADX INFO: loaded from: classes.dex */
public final class ManagerCreator {

    /* JADX INFO: renamed from: a */
    private static volatile ManagerCreator f6035a = null;

    /* JADX INFO: renamed from: b */
    private HashMap<Class<? extends BaseManager>, BaseManager> f6036b = new HashMap<>();

    /* JADX INFO: renamed from: c */
    private HashMap<Class<? extends BaseManager>, WeakReference<? extends BaseManager>> f6037c = new HashMap<>();

    /* JADX INFO: renamed from: d */
    private Context f6038d;

    private ManagerCreator(Context context) {
        this.f6038d = context.getApplicationContext();
    }

    /* JADX INFO: renamed from: a */
    private <T extends BaseManager> T m2583a(Class<T> cls) {
        T tCast;
        WeakReference<? extends BaseManager> weakReference;
        if (!C1278f.m3286a().m3293a((Class<? extends BaseManager>) cls)) {
            throw new SecurityException("Your license did not have the permission that geting the Manager named " + cls.getSimpleName());
        }
        if (cls == null) {
            throw new NullPointerException("the param of getManager can't be null.");
        }
        synchronized (cls) {
            tCast = cls.cast(this.f6036b.get(cls));
            if (tCast == null && (weakReference = this.f6037c.get(cls)) != null) {
                tCast = cls.cast(weakReference.get());
            }
            if (tCast == null) {
                try {
                    tCast = cls.newInstance();
                    tCast.onCreate(this.f6038d);
                    if (tCast.getSingletonType() == 1) {
                        this.f6036b.put(cls, tCast);
                    } else if (tCast.getSingletonType() == 0) {
                        this.f6037c.put(cls, new WeakReference<>(tCast));
                    }
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
        }
        return tCast;
    }

    /* JADX INFO: renamed from: a */
    static synchronized ManagerCreator m2584a() {
        if (f6035a == null) {
            f6035a = new ManagerCreator(TMSApplication.getApplicaionContext());
        }
        return f6035a;
    }

    public static <T extends BaseManager> T getManager(Class<T> cls) {
        return (T) m2584a().m2583a(cls);
    }
}
