package tms;

import java.lang.reflect.Field;

/* JADX INFO: renamed from: tms.ah */
/* JADX INFO: loaded from: classes.dex */
public final class C1151ah {

    /* JADX INFO: renamed from: a */
    public static Class<?> f6825a;

    /* JADX INFO: renamed from: a */
    public static final int m2896a(Object obj, String str, int i) {
        m2902a(obj.getClass().getName());
        Field fieldM2903b = m2903b(str);
        if (fieldM2903b == null) {
            return i;
        }
        try {
            return fieldM2903b.getInt(obj);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return i;
        } catch (IllegalArgumentException e2) {
            e2.printStackTrace();
            return i;
        }
    }

    /* JADX INFO: renamed from: a */
    public static final int m2897a(String str, int i) {
        Field fieldM2903b = m2903b(str);
        if (fieldM2903b == null) {
            return i;
        }
        try {
            return fieldM2903b.getInt(null);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return i;
        } catch (IllegalArgumentException e2) {
            e2.printStackTrace();
            return i;
        }
    }

    /* JADX INFO: renamed from: a */
    public static Object m2898a(Object obj, String str) throws Exception {
        return obj.getClass().getField(str).get(obj);
    }

    /* JADX INFO: renamed from: a */
    public static Object m2899a(Object obj, String str, Object[] objArr) throws Exception {
        Class<?> cls = obj.getClass();
        Class<?>[] clsArr = new Class[objArr.length];
        int length = objArr.length;
        for (int i = 0; i < length; i++) {
            clsArr[i] = objArr[i].getClass();
            if (clsArr[i] == Integer.class) {
                clsArr[i] = Integer.TYPE;
            } else if (clsArr[i] == Boolean.class) {
                clsArr[i] = Boolean.TYPE;
            }
        }
        return cls.getMethod(str, clsArr).invoke(obj, objArr);
    }

    /* JADX INFO: renamed from: a */
    public static Object m2900a(String str, String str2) {
        m2902a(str);
        Field fieldM2903b = m2903b(str2);
        if (fieldM2903b == null) {
            return null;
        }
        try {
            return fieldM2903b.get(null);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return null;
        } catch (IllegalArgumentException e2) {
            e2.printStackTrace();
            return null;
        }
    }

    /* JADX INFO: renamed from: a */
    public static Object m2901a(String str, Object[] objArr) throws Exception {
        Class<?> cls = Class.forName(str);
        Class<?>[] clsArr = new Class[objArr.length];
        int length = objArr.length;
        for (int i = 0; i < length; i++) {
            clsArr[i] = objArr[i].getClass();
        }
        return cls.getConstructor(clsArr).newInstance(objArr);
    }

    /* JADX INFO: renamed from: a */
    public static final boolean m2902a(String str) {
        Class<?> cls = null;
        try {
            cls = Class.forName(str);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        f6825a = cls;
        return f6825a != null;
    }

    /* JADX INFO: renamed from: b */
    private static final Field m2903b(String str) {
        Field declaredField;
        SecurityException e;
        NoSuchFieldException e2;
        try {
            declaredField = f6825a.getDeclaredField(str);
            try {
                declaredField.setAccessible(true);
            } catch (NoSuchFieldException e3) {
                e2 = e3;
                e2.printStackTrace();
            } catch (SecurityException e4) {
                e = e4;
                e.printStackTrace();
            }
        } catch (NoSuchFieldException e5) {
            declaredField = null;
            e2 = e5;
        } catch (SecurityException e6) {
            declaredField = null;
            e = e6;
        }
        return declaredField;
    }
}
