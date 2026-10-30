package tms;

import android.os.IBinder;
import android.os.IInterface;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;

/* JADX INFO: renamed from: tms.ai */
/* JADX INFO: loaded from: classes.dex */
public final class C1152ai {

    /* JADX INFO: renamed from: a */
    private static Class<?> f6826a;

    /* JADX INFO: renamed from: b */
    private static IBinder f6827b;

    /* JADX INFO: renamed from: c */
    private static Method f6828c;

    /* JADX INFO: renamed from: d */
    private static Method f6829d;

    /* JADX INFO: renamed from: e */
    private static Method f6830e;

    /* JADX INFO: renamed from: f */
    private static Method f6831f;

    /* JADX INFO: renamed from: g */
    private static HashMap<String, IBinder> f6832g;

    static {
        try {
            f6826a = Class.forName("android.os.ServiceManager");
            f6828c = f6826a.getDeclaredMethod("getService", String.class);
            f6829d = f6826a.getDeclaredMethod("addService", String.class, IBinder.class);
            f6830e = f6826a.getDeclaredMethod("checkService", String.class);
            f6831f = f6826a.getDeclaredMethod("listServices", new Class[0]);
            Field declaredField = f6826a.getDeclaredField("sCache");
            declaredField.setAccessible(true);
            f6832g = (HashMap) declaredField.get(null);
            Field declaredField2 = f6826a.getDeclaredField("sServiceManager");
            declaredField2.setAccessible(true);
            f6827b = ((IInterface) declaredField2.get(null)).asBinder();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e2) {
            e2.printStackTrace();
        } catch (IllegalArgumentException e3) {
            e3.printStackTrace();
        } catch (NoSuchFieldException e4) {
            e4.printStackTrace();
        } catch (NoSuchMethodException e5) {
            e5.printStackTrace();
        } catch (SecurityException e6) {
            e6.printStackTrace();
        }
    }

    private C1152ai() {
    }

    /* JADX INFO: renamed from: a */
    public static IBinder m2904a(String str) {
        return (IBinder) m2905a(f6828c, str);
    }

    /* JADX INFO: renamed from: a */
    private static Object m2905a(Method method, Object... objArr) {
        try {
            return method.invoke(null, objArr);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return null;
        } catch (IllegalArgumentException e2) {
            e2.printStackTrace();
            return null;
        } catch (InvocationTargetException e3) {
            e3.printStackTrace();
            return null;
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m2906a(String str, IBinder iBinder) {
        m2905a(f6829d, str, iBinder);
    }

    /* JADX INFO: renamed from: a */
    public static String[] m2907a() {
        return (String[]) m2905a(f6831f, new Object[0]);
    }

    /* JADX INFO: renamed from: b */
    public static IBinder m2908b(String str) {
        return (IBinder) m2905a(f6830e, str);
    }

    /* JADX INFO: renamed from: b */
    public static synchronized void m2909b(String str, IBinder iBinder) {
        f6832g.put(str, iBinder);
    }

    /* JADX INFO: renamed from: c */
    public static synchronized IBinder m2910c(String str) {
        return f6832g.get(str);
    }

    /* JADX INFO: renamed from: d */
    public static synchronized IBinder m2911d(String str) {
        IBinder iBinderM2904a;
        HashMap map = new HashMap(f6832g);
        f6832g.clear();
        iBinderM2904a = m2904a(str);
        f6832g.putAll(map);
        return iBinderM2904a;
    }
}
