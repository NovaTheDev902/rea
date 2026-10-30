package com.lenovo.lps.reaper.sdk.sdac;

import java.lang.reflect.Method;

/* JADX INFO: loaded from: classes.dex */
public class ReflectUtils {
    public static Object invokeClass(String className, String singleMethodName, Class<?>[] cls, Object... args) {
        try {
            Class<?> tmex = Class.forName(className);
            if (hasMethod(tmex, singleMethodName)) {
                Method tmexMethod = tmex.getMethod(singleMethodName, cls);
                return tmexMethod.invoke(tmex, args);
            }
        } catch (Exception e) {
        }
        return null;
    }

    public static Object invoke(Object c, String m, Class<?>[] cls, Object... args) {
        try {
            if (hasMethod(c.getClass(), m)) {
                Method method = c.getClass().getMethod(m, cls);
                return method.invoke(c, args);
            }
        } catch (Exception e) {
        }
        return null;
    }

    public static boolean hasMethod(Class<?> clazz, String m) {
        try {
            Method[] methods = clazz.getDeclaredMethods();
            for (Method method : methods) {
                if (m.equals(method.getName())) {
                    return true;
                }
            }
        } catch (Exception e) {
        }
        return false;
    }
}
