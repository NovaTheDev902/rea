package puw;

import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

/* JADX INFO: renamed from: puw.f */
/* JADX INFO: loaded from: classes.dex */
public class C1140f {

    /* JADX INFO: renamed from: f */
    protected HashMap<String, HashMap<String, byte[]>> f6808f = new HashMap<>();

    /* JADX INFO: renamed from: g */
    protected HashMap<String, Object> f6809g = new HashMap<>();

    /* JADX INFO: renamed from: a */
    private HashMap<String, Object> f6807a = new HashMap<>();

    /* JADX INFO: renamed from: h */
    protected String f6810h = "GBK";

    /* JADX INFO: renamed from: i */
    JceInputStream f6811i = new JceInputStream();

    /* JADX INFO: renamed from: a */
    private Object m2867a(String str) {
        if (this.f6809g.containsKey(str)) {
            return this.f6809g.get(str);
        }
        Object objM2860b = C1137c.m2860b(str);
        this.f6809g.put(str, objM2860b);
        return objM2860b;
    }

    /* JADX INFO: renamed from: a */
    private void m2868a(String str, Object obj) {
        this.f6807a.put(str, obj);
    }

    /* JADX INFO: renamed from: a */
    private void m2869a(ArrayList<String> arrayList, Object obj) {
        if (obj.getClass().isArray()) {
            if (!obj.getClass().getComponentType().toString().equals("byte")) {
                throw new IllegalArgumentException("only byte[] is supported");
            }
            if (Array.getLength(obj) > 0) {
                arrayList.add("java.util.List");
                m2869a(arrayList, Array.get(obj, 0));
                return;
            } else {
                arrayList.add("Array");
                arrayList.add("?");
                return;
            }
        }
        if (obj instanceof Array) {
            throw new IllegalArgumentException("can not support Array, please use List");
        }
        if (obj instanceof List) {
            arrayList.add("java.util.List");
            List list = (List) obj;
            if (list.size() > 0) {
                m2869a(arrayList, list.get(0));
                return;
            } else {
                arrayList.add("?");
                return;
            }
        }
        if (!(obj instanceof Map)) {
            arrayList.add(obj.getClass().getName());
            return;
        }
        arrayList.add("java.util.Map");
        Map map = (Map) obj;
        if (map.size() <= 0) {
            arrayList.add("?");
            arrayList.add("?");
        } else {
            Object next = map.keySet().iterator().next();
            Object obj2 = map.get(next);
            arrayList.add(next.getClass().getName());
            m2869a(arrayList, obj2);
        }
    }

    public void clearCacheData() {
        this.f6807a.clear();
    }

    public boolean containsKey(String str) {
        return this.f6808f.containsKey(str);
    }

    public void decode(byte[] bArr) {
        this.f6811i.warp(bArr);
        this.f6811i.setServerEncoding(this.f6810h);
        HashMap map = new HashMap(1);
        HashMap map2 = new HashMap(1);
        map2.put("", new byte[0]);
        map.put("", map2);
        this.f6808f = this.f6811i.readMap(map, 0, false);
    }

    public byte[] encode() {
        JceOutputStream jceOutputStream = new JceOutputStream(0);
        jceOutputStream.setServerEncoding(this.f6810h);
        jceOutputStream.write((Map) this.f6808f, 0);
        return JceUtil.getJceBufArray(jceOutputStream.getByteBuffer());
    }

    /* JADX WARN: Multi-variable type inference failed */
    public <T> T get(String str) throws C1141g {
        byte[] value;
        String key = null;
        if (!this.f6808f.containsKey(str)) {
            return null;
        }
        if (this.f6807a.containsKey(str)) {
            return (T) this.f6807a.get(str);
        }
        byte[] bArr = new byte[0];
        Iterator<Map.Entry<String, byte[]>> it = this.f6808f.get(str).entrySet().iterator();
        if (it.hasNext()) {
            Map.Entry<String, byte[]> next = it.next();
            key = next.getKey();
            value = next.getValue();
        } else {
            value = bArr;
        }
        try {
            Object objM2867a = m2867a(key);
            this.f6811i.warp(value);
            this.f6811i.setServerEncoding(this.f6810h);
            T t = (T) this.f6811i.read(objM2867a, 0, true);
            m2868a(str, t);
            return t;
        } catch (Exception e) {
            e.printStackTrace();
            throw new C1141g(e);
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    public <T> T get(String str, Object obj) {
        byte[] value;
        String key;
        if (!this.f6808f.containsKey(str)) {
            return obj;
        }
        if (this.f6807a.containsKey(str)) {
            return (T) this.f6807a.get(str);
        }
        byte[] bArr = new byte[0];
        Iterator<Map.Entry<String, byte[]>> it = this.f6808f.get(str).entrySet().iterator();
        if (it.hasNext()) {
            Map.Entry<String, byte[]> next = it.next();
            key = next.getKey();
            value = next.getValue();
        } else {
            value = bArr;
            key = "";
        }
        try {
            Object objM2867a = m2867a(key);
            this.f6811i.warp(value);
            this.f6811i.setServerEncoding(this.f6810h);
            T t = (T) this.f6811i.read(objM2867a, 0, true);
            m2868a(str, t);
            return t;
        } catch (Exception e) {
            e.printStackTrace();
            m2868a(str, obj);
            return obj;
        }
    }

    public String getEncodeName() {
        return this.f6810h;
    }

    public <T> T getJceStruct(String str) throws C1141g {
        String str2;
        byte[] bArr;
        if (!this.f6808f.containsKey(str)) {
            return null;
        }
        if (this.f6807a.containsKey(str)) {
            return (T) this.f6807a.get(str);
        }
        byte[] bArr2 = new byte[0];
        Iterator<Map.Entry<String, byte[]>> it = this.f6808f.get(str).entrySet().iterator();
        if (it.hasNext()) {
            Map.Entry<String, byte[]> next = it.next();
            String key = next.getKey();
            byte[] value = next.getValue();
            str2 = key;
            bArr = value;
        } else {
            str2 = null;
            bArr = bArr2;
        }
        try {
            Object objM2867a = m2867a(str2);
            this.f6811i.warp(bArr);
            this.f6811i.setServerEncoding(this.f6810h);
            T t = (T) this.f6811i.directRead((JceStruct) objM2867a, 0, true);
            m2868a(str, t);
            return t;
        } catch (Exception e) {
            e.printStackTrace();
            throw new C1141g(e);
        }
    }

    public Set<String> getKeySet() {
        return Collections.unmodifiableSet(this.f6808f.keySet());
    }

    public boolean isEmpty() {
        return this.f6808f.isEmpty();
    }

    public <T> void put(String str, T t) {
        if (str == null) {
            throw new IllegalArgumentException("put key can not is null");
        }
        if (t == null) {
            throw new IllegalArgumentException("put value can not is null");
        }
        if (t instanceof Set) {
            throw new IllegalArgumentException("can not support Set");
        }
        JceOutputStream jceOutputStream = new JceOutputStream();
        jceOutputStream.setServerEncoding(this.f6810h);
        jceOutputStream.write(t, 0);
        byte[] jceBufArray = JceUtil.getJceBufArray(jceOutputStream.getByteBuffer());
        HashMap<String, byte[]> map = new HashMap<>(1);
        ArrayList<String> arrayList = new ArrayList<>(1);
        m2869a(arrayList, t);
        map.put(C1137c.m2857a(arrayList), jceBufArray);
        this.f6807a.remove(str);
        this.f6808f.put(str, map);
    }

    /* JADX WARN: Multi-variable type inference failed */
    public <T> T remove(String str) throws C1141g {
        byte[] value;
        String key;
        if (!this.f6808f.containsKey(str)) {
            return null;
        }
        byte[] bArr = new byte[0];
        Iterator<Map.Entry<String, byte[]>> it = this.f6808f.remove(str).entrySet().iterator();
        if (it.hasNext()) {
            Map.Entry<String, byte[]> next = it.next();
            key = next.getKey();
            value = next.getValue();
        } else {
            value = bArr;
            key = "";
        }
        try {
            Object objM2860b = C1137c.m2860b(key);
            this.f6811i.warp(value);
            this.f6811i.setServerEncoding(this.f6810h);
            return (T) this.f6811i.read(objM2860b, 0, true);
        } catch (Exception e) {
            e.printStackTrace();
            throw new C1141g(e);
        }
    }

    public void setEncodeName(String str) {
        this.f6810h = str;
    }

    public int size() {
        return this.f6808f.size();
    }
}
