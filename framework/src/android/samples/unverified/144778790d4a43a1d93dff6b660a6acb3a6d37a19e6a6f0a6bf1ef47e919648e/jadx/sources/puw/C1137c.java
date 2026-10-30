package puw;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

/* JADX INFO: renamed from: puw.c */
/* JADX INFO: loaded from: classes.dex */
public class C1137c {
    /* JADX INFO: renamed from: a */
    public static String m2857a(ArrayList<String> arrayList) {
        StringBuffer stringBuffer = new StringBuffer();
        for (int i = 0; i < arrayList.size(); i++) {
            arrayList.set(i, m2862d(arrayList.get(i)));
        }
        Collections.reverse(arrayList);
        for (int i2 = 0; i2 < arrayList.size(); i2++) {
            String str = arrayList.get(i2);
            if (str.equals("list")) {
                arrayList.set(i2 - 1, "<" + arrayList.get(i2 - 1));
                arrayList.set(0, arrayList.get(0) + ">");
            } else if (str.equals("map")) {
                arrayList.set(i2 - 1, "<" + arrayList.get(i2 - 1) + ",");
                arrayList.set(0, arrayList.get(0) + ">");
            } else if (str.equals("Array")) {
                arrayList.set(i2 - 1, "<" + arrayList.get(i2 - 1));
                arrayList.set(0, arrayList.get(0) + ">");
            }
        }
        Collections.reverse(arrayList);
        Iterator<String> it = arrayList.iterator();
        while (it.hasNext()) {
            stringBuffer.append(it.next());
        }
        return stringBuffer.toString();
    }

    /* JADX INFO: renamed from: a */
    public static ArrayList<String> m2858a(String str) {
        ArrayList<String> arrayList = new ArrayList<>();
        int i = 0;
        int iIndexOf = str.indexOf("<");
        while (i < iIndexOf) {
            m2859a(arrayList, str.substring(i, iIndexOf));
            i = iIndexOf + 1;
            iIndexOf = str.indexOf("<", i);
            int iIndexOf2 = str.indexOf(",", i);
            if (iIndexOf == -1) {
                iIndexOf = iIndexOf2;
            }
            if (iIndexOf2 != -1 && iIndexOf2 < iIndexOf) {
                iIndexOf = iIndexOf2;
            }
        }
        m2859a(arrayList, str.substring(i, str.length()));
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    private static void m2859a(ArrayList<String> arrayList, String str) {
        int length = str.length();
        while (str.charAt(length - 1) == '>' && (length = length - 1) != 0) {
        }
        arrayList.add(0, m2863e(str.substring(0, length)));
    }

    /* JADX INFO: renamed from: b */
    public static Object m2860b(String str) throws C1141g {
        Object obj;
        Iterator<String> it = m2858a(str).iterator();
        Object objM2861c = null;
        Object obj2 = null;
        Object obj3 = null;
        while (it.hasNext()) {
            objM2861c = m2861c(it.next());
            if (objM2861c instanceof String) {
                if ("Array".equals((String) objM2861c)) {
                    if (obj3 == null) {
                        objM2861c = Array.newInstance((Class<?>) Byte.class, 0);
                        obj = obj2;
                    } else {
                        obj = obj2;
                    }
                } else if ("?".equals((String) objM2861c)) {
                    obj = obj2;
                } else if (obj3 == null) {
                    obj = obj2;
                    obj3 = objM2861c;
                } else {
                    obj = obj3;
                    obj3 = objM2861c;
                }
            } else if (objM2861c instanceof List) {
                if (obj3 == null || !(obj3 instanceof Byte)) {
                    if (obj3 != null) {
                        ((List) objM2861c).add(obj3);
                    }
                    obj = obj2;
                    obj3 = null;
                } else {
                    objM2861c = Array.newInstance((Class<?>) Byte.class, 1);
                    Array.set(objM2861c, 0, obj3);
                    obj = obj2;
                }
            } else if (objM2861c instanceof Map) {
                if ((obj2 != null) & (obj3 != null)) {
                    ((Map) objM2861c).put(obj3, obj2);
                }
                obj = null;
                obj3 = null;
            } else if (obj3 == null) {
                obj = obj2;
                obj3 = objM2861c;
            } else {
                obj = obj3;
                obj3 = objM2861c;
            }
            obj2 = obj;
        }
        return objM2861c;
    }

    /* JADX INFO: renamed from: c */
    public static Object m2861c(String str) throws C1141g {
        if (str.equals("java.lang.Integer")) {
            return 0;
        }
        if (str.equals("java.lang.Boolean")) {
            return false;
        }
        if (str.equals("java.lang.Byte")) {
            return (byte) 0;
        }
        if (str.equals("java.lang.Double")) {
            return Double.valueOf(0.0d);
        }
        if (str.equals("java.lang.Float")) {
            return Float.valueOf(0.0f);
        }
        if (str.equals("java.lang.Long")) {
            return 0L;
        }
        if (str.equals("java.lang.Short")) {
            return (short) 0;
        }
        if (str.equals("java.lang.Character")) {
            throw new IllegalArgumentException("can not support java.lang.Character");
        }
        if (str.equals("java.lang.String")) {
            return "";
        }
        if (str.equals("java.util.List")) {
            return new ArrayList();
        }
        if (str.equals("java.util.Map")) {
            return new HashMap();
        }
        if (str.equals("Array")) {
            return "Array";
        }
        if (str.equals("?")) {
            return str;
        }
        try {
            return Class.forName(str).getConstructor(new Class[0]).newInstance(new Object[0]);
        } catch (Exception e) {
            e.printStackTrace();
            throw new C1141g(e);
        }
    }

    /* JADX INFO: renamed from: d */
    public static String m2862d(String str) {
        if (str.equals("java.lang.Integer") || str.equals("int")) {
            return "int32";
        }
        if (str.equals("java.lang.Boolean") || str.equals("boolean")) {
            return "bool";
        }
        if (str.equals("java.lang.Byte") || str.equals("byte")) {
            return "char";
        }
        if (str.equals("java.lang.Double") || str.equals("double")) {
            return "double";
        }
        if (str.equals("java.lang.Float") || str.equals("float")) {
            return "float";
        }
        if (str.equals("java.lang.Long") || str.equals("long")) {
            return "int64";
        }
        if (str.equals("java.lang.Short") || str.equals("short")) {
            return "short";
        }
        if (str.equals("java.lang.Character")) {
            throw new IllegalArgumentException("can not support java.lang.Character");
        }
        if (str.equals("java.lang.String")) {
            return "string";
        }
        if (str.equals("java.util.List")) {
            return "list";
        }
        return str.equals("java.util.Map") ? "map" : str;
    }

    /* JADX INFO: renamed from: e */
    public static String m2863e(String str) {
        if (str.equals("int32")) {
            return "java.lang.Integer";
        }
        if (str.equals("bool")) {
            return "java.lang.Boolean";
        }
        if (str.equals("char")) {
            return "java.lang.Byte";
        }
        if (str.equals("double")) {
            return "java.lang.Double";
        }
        if (str.equals("float")) {
            return "java.lang.Float";
        }
        if (str.equals("int64")) {
            return "java.lang.Long";
        }
        if (str.equals("short")) {
            return "java.lang.Short";
        }
        if (str.equals("string")) {
            return "java.lang.String";
        }
        if (str.equals("list")) {
            return "java.util.List";
        }
        return str.equals("map") ? "java.util.Map" : str;
    }
}
