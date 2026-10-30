package ledroid.utils;

import android.util.Log;
import java.lang.reflect.AccessibleObject;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.security.AccessController;
import java.security.PrivilegedAction;

/* JADX INFO: loaded from: classes.dex */
public class ReflectClass {

    /* JADX INFO: renamed from: a */
    private String f6397a;

    /* JADX INFO: renamed from: b */
    private Class<?> f6398b;

    /* JADX INFO: renamed from: c */
    private Object f6399c;

    public ReflectClass(String name) {
        this.f6397a = null;
        this.f6398b = null;
        this.f6399c = null;
        this.f6397a = name;
    }

    public ReflectClass(Class<?> clazz) {
        this(clazz.getName());
        this.f6398b = clazz;
    }

    public ReflectClass(String name, Object instance) {
        this.f6397a = null;
        this.f6398b = null;
        this.f6399c = null;
        this.f6397a = name;
        this.f6399c = instance;
    }

    public ReflectClass(Class<?> clazz, Object instance) {
        this(clazz.getName(), instance);
        this.f6398b = clazz;
    }

    /* JADX INFO: renamed from: a */
    private Class<?> m2692a() throws ClassNotFoundException {
        if (this.f6398b == null) {
            this.f6398b = Class.forName(this.f6397a);
        }
        return this.f6398b;
    }

    public void setInstance(Object instance) {
        this.f6399c = instance;
    }

    public boolean hasInstance() {
        return this.f6399c != null;
    }

    public Object newInstance() throws IllegalAccessException, NoSuchMethodException, InstantiationException, ClassNotFoundException, InvocationTargetException {
        if (this.f6399c != null) {
            throw new IllegalAccessException("Instance already new.");
        }
        Constructor<?> constructor = m2692a().getDeclaredConstructor(new Class[0]);
        if (constructor != null) {
            C1108a accessController = new C1108a(constructor);
            accessController.m2695a();
            constructor.setAccessible(true);
            this.f6399c = constructor.newInstance(new Object[0]);
        }
        return this.f6399c;
    }

    public Object newInstance(Class<?>[] argTypes, Object[] args) throws IllegalAccessException, NoSuchMethodException, InstantiationException, ClassNotFoundException, InvocationTargetException {
        if (this.f6399c != null) {
            throw new IllegalAccessException("Instance already new.");
        }
        this.f6399c = m2692a().getDeclaredConstructor(argTypes).newInstance(args);
        return this.f6399c;
    }

    public boolean hasField(String fieldName) {
        try {
            m2692a().getDeclaredField(fieldName);
            return true;
        } catch (ClassNotFoundException | NoSuchFieldException | SecurityException e) {
            return false;
        }
    }

    public boolean hasMethod(String methodName, Class<?>[] argTypes) {
        Method m = null;
        try {
            m = m2692a().getDeclaredMethod(methodName, argTypes);
        } catch (ClassNotFoundException e) {
            Log.w("ReflectClass", e.getLocalizedMessage());
        } catch (NoSuchMethodException e2) {
            Log.w("ReflectClass", e2.getLocalizedMessage());
        } catch (SecurityException e3) {
            Log.w("ReflectClass", e3.getLocalizedMessage());
        }
        return m != null;
    }

    public int getStaticFieldValueInt(String fieldName) throws IllegalAccessException, NoSuchFieldException, ClassNotFoundException {
        return m2692a().getDeclaredField(fieldName).getInt(null);
    }

    public int getFieldValueInt(String fieldName) throws IllegalAccessException, NoSuchFieldException, ClassNotFoundException {
        if (this.f6399c == null) {
            throw new IllegalAccessException("No [" + this.f6397a + "] instance for field [" + fieldName + "].");
        }
        return m2692a().getDeclaredField(fieldName).getInt(this.f6399c);
    }

    public static final class ReflectField<T> {

        /* JADX INFO: renamed from: a */
        private Field f6400a;

        ReflectField(Field field) {
            this.f6400a = field;
            if (this.f6400a != null && !this.f6400a.isAccessible()) {
                C1108a accessController = new C1108a(this.f6400a);
                accessController.m2695a();
            }
        }

        protected final T getValue(Object obj) {
            try {
                return (T) this.f6400a.get(obj);
            } catch (IllegalAccessException | IllegalArgumentException e) {
                return null;
            }
        }
    }

    public <T> ReflectField<T> getDeclaredField(String fieldName, Class<T> fieldType) {
        try {
            Field field = m2692a().getDeclaredField(fieldName);
            ReflectField<T> reflectField = new ReflectField<>(field);
            return reflectField;
        } catch (Exception e) {
            Log.w("ReflectClass", e.getLocalizedMessage());
            return null;
        }
    }

    public <T> T getFieldVaule(ReflectField<T> field) {
        return field.getValue(this.f6399c);
    }

    public Method getDeclaredMethod(String methodName, Class<?>... argTypes) {
        try {
            Method m = m2692a().getDeclaredMethod(methodName, argTypes);
            return m;
        } catch (Exception e) {
            Log.w("ReflectClass", e.getLocalizedMessage());
            return null;
        }
    }

    public Object invoke(Method m, Object... args) throws IllegalAccessException, InvocationTargetException {
        if (m != null) {
            return m.invoke(this.f6399c, args);
        }
        Log.w("ReflectClass", "Method object is null.");
        return null;
    }

    public Object invoke(String methodName, Class<?>[] argTypes, Object... args) throws IllegalAccessException, InvocationTargetException {
        Method m = getDeclaredMethod(methodName, argTypes);
        if (m == null) {
            return null;
        }
        return invoke(m, args);
    }

    /* JADX INFO: renamed from: ledroid.utils.ReflectClass$a */
    private static final class C1108a {

        /* JADX INFO: renamed from: a */
        private AccessibleObject f6401a;

        /* JADX INFO: renamed from: b */
        private Boolean f6402b = true;

        C1108a(AccessibleObject member) {
            this.f6401a = member;
        }

        /* JADX INFO: renamed from: a */
        public final void m2695a() {
            this.f6402b = true;
            AccessController.doPrivileged(new PrivilegedAction<Void>() { // from class: ledroid.utils.ReflectClass.a.1
                @Override // java.security.PrivilegedAction
                public final /* synthetic */ Void run() {
                    if (C1108a.this.f6401a == null) {
                        return null;
                    }
                    C1108a.this.f6401a.setAccessible(C1108a.this.f6402b.booleanValue());
                    return null;
                }
            });
        }
    }
}
