package com.lenovo.feedback2.agent;

import android.os.Build;
import android.view.View;
import java.lang.reflect.Field;

/* JADX INFO: renamed from: com.lenovo.feedback2.agent.a */
/* JADX INFO: compiled from: ViewFetcher.java */
/* JADX INFO: loaded from: classes.dex */
final class C0048a {

    /* JADX INFO: renamed from: b */
    private static Class<?> f954b;

    /* JADX INFO: renamed from: a */
    private String f955a;

    public C0048a() {
        if (Build.VERSION.SDK_INT < 13) {
            this.f955a = "mWindowManager";
        } else {
            this.f955a = "sWindowManager";
        }
    }

    /* JADX INFO: renamed from: a */
    public static View m137a(View[] views) {
        View[] decorViews = new View[views.length];
        int i = 0;
        for (View view : views) {
            if (view.getClass().getName().equals("com.android.internal.policy.impl.PhoneWindow$DecorView")) {
                decorViews[i] = view;
                i++;
            }
        }
        View view2 = null;
        int i2 = 0;
        long drawingTime = 0;
        while (i2 < decorViews.length) {
            View view3 = decorViews[i2];
            if (view3 == null || !view3.isShown() || !view3.hasWindowFocus() || view3.getDrawingTime() <= drawingTime) {
                view3 = view2;
            } else {
                drawingTime = view3.getDrawingTime();
            }
            i2++;
            view2 = view3;
        }
        return view2;
    }

    static {
        try {
            f954b = Class.forName("android.view.WindowManagerImpl");
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        } catch (SecurityException e2) {
            e2.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: a */
    public final View[] m138a() {
        try {
            Field viewsField = f954b.getDeclaredField("mViews");
            Field instanceField = f954b.getDeclaredField(this.f955a);
            viewsField.setAccessible(true);
            instanceField.setAccessible(true);
            Object instance = instanceField.get(null);
            return (View[]) viewsField.get(instance);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return null;
        } catch (IllegalArgumentException e2) {
            e2.printStackTrace();
            return null;
        } catch (NoSuchFieldException e3) {
            e3.printStackTrace();
            return null;
        } catch (SecurityException e4) {
            e4.printStackTrace();
            return null;
        }
    }
}
