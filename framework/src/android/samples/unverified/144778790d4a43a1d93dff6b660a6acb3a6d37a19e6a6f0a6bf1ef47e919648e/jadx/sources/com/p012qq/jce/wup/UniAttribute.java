package com.p012qq.jce.wup;

import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceUtil;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import puw.C1140f;
import puw.C1141g;

/* JADX INFO: loaded from: classes.dex */
public class UniAttribute extends C1140f {

    /* JADX INFO: renamed from: d */
    protected HashMap<String, byte[]> f5880d = null;

    /* JADX INFO: renamed from: a */
    private HashMap<String, Object> f5878a = new HashMap<>();

    /* JADX INFO: renamed from: b */
    JceInputStream f5879b = new JceInputStream();

    /* JADX INFO: renamed from: a */
    private Object m2476a(byte[] bArr, Object obj) {
        this.f5879b.warp(bArr);
        this.f5879b.setServerEncoding(this.f6810h);
        return this.f5879b.read(obj, 0, true);
    }

    /* JADX INFO: renamed from: a */
    private void m2477a(String str, Object obj) {
        this.f5878a.put(str, obj);
    }

    @Override // puw.C1140f
    public void clearCacheData() {
        this.f5878a.clear();
    }

    @Override // puw.C1140f
    public boolean containsKey(String str) {
        return this.f5880d != null ? this.f5880d.containsKey(str) : this.f6808f.containsKey(str);
    }

    @Override // puw.C1140f
    public void decode(byte[] bArr) {
        try {
            super.decode(bArr);
        } catch (Exception e) {
            this.f5879b.warp(bArr);
            this.f5879b.setServerEncoding(this.f6810h);
            HashMap map = new HashMap(1);
            map.put("", new byte[0]);
            this.f5880d = this.f5879b.readMap(map, 0, false);
        }
    }

    public void decodeVersion2(byte[] bArr) {
        super.decode(bArr);
    }

    public void decodeVersion3(byte[] bArr) {
        this.f5879b.warp(bArr);
        this.f5879b.setServerEncoding(this.f6810h);
        HashMap map = new HashMap(1);
        map.put("", new byte[0]);
        this.f5880d = this.f5879b.readMap(map, 0, false);
    }

    @Override // puw.C1140f
    public byte[] encode() {
        if (this.f5880d == null) {
            return super.encode();
        }
        JceOutputStream jceOutputStream = new JceOutputStream(0);
        jceOutputStream.setServerEncoding(this.f6810h);
        jceOutputStream.write((Map) this.f5880d, 0);
        return JceUtil.getJceBufArray(jceOutputStream.getByteBuffer());
    }

    @Override // puw.C1140f
    public <T> T get(String str) throws C1141g {
        if (this.f5880d != null) {
            throw new RuntimeException("data is encoded by new version, please use getByClass(String name, T proxy)");
        }
        return (T) super.get(str);
    }

    @Override // puw.C1140f
    public <T> T get(String str, Object obj) {
        if (this.f5880d != null) {
            throw new RuntimeException("data is encoded by new version, please use get(String name, T proxy, Object defaultValue)");
        }
        return (T) super.get(str, obj);
    }

    /* JADX WARN: Multi-variable type inference failed */
    public <T> T get(String str, T t, Object obj) {
        return !this.f5880d.containsKey(str) ? obj : (T) getByClass(str, t);
    }

    public <T> T getByClass(String str, T t) throws C1141g {
        byte[] value;
        if (this.f5880d != null) {
            if (!this.f5880d.containsKey(str)) {
                return null;
            }
            if (this.f5878a.containsKey(str)) {
                return (T) this.f5878a.get(str);
            }
            try {
                T t2 = (T) m2476a(this.f5880d.get(str), t);
                if (t2 == null) {
                    return t2;
                }
                m2477a(str, t2);
                return t2;
            } catch (Exception e) {
                throw new C1141g(e);
            }
        }
        if (!this.f6808f.containsKey(str)) {
            return null;
        }
        if (this.f5878a.containsKey(str)) {
            return (T) this.f5878a.get(str);
        }
        byte[] bArr = new byte[0];
        Iterator<Map.Entry<String, byte[]>> it = this.f6808f.get(str).entrySet().iterator();
        if (it.hasNext()) {
            Map.Entry<String, byte[]> next = it.next();
            next.getKey();
            value = next.getValue();
        } else {
            value = bArr;
        }
        try {
            this.f5879b.warp(value);
            this.f5879b.setServerEncoding(this.f6810h);
            T t3 = (T) this.f5879b.read((Object) t, 0, true);
            m2477a(str, t3);
            return t3;
        } catch (Exception e2) {
            throw new C1141g(e2);
        }
    }

    public <T> T getByClass(String str, T t, T t2) throws C1141g {
        byte[] value;
        if (this.f5880d != null) {
            if (!this.f5880d.containsKey(str)) {
                return t2;
            }
            if (this.f5878a.containsKey(str)) {
                return (T) this.f5878a.get(str);
            }
            try {
                T t3 = (T) m2476a(this.f5880d.get(str), t);
                if (t3 == null) {
                    return t3;
                }
                m2477a(str, t3);
                return t3;
            } catch (Exception e) {
                throw new C1141g(e);
            }
        }
        if (!this.f6808f.containsKey(str)) {
            return t2;
        }
        if (this.f5878a.containsKey(str)) {
            return (T) this.f5878a.get(str);
        }
        byte[] bArr = new byte[0];
        Iterator<Map.Entry<String, byte[]>> it = this.f6808f.get(str).entrySet().iterator();
        if (it.hasNext()) {
            Map.Entry<String, byte[]> next = it.next();
            next.getKey();
            value = next.getValue();
        } else {
            value = bArr;
        }
        try {
            this.f5879b.warp(value);
            this.f5879b.setServerEncoding(this.f6810h);
            T t4 = (T) this.f5879b.read((Object) t, 0, true);
            m2477a(str, t4);
            return t4;
        } catch (Exception e2) {
            throw new C1141g(e2);
        }
    }

    @Override // puw.C1140f
    public /* bridge */ /* synthetic */ String getEncodeName() {
        return super.getEncodeName();
    }

    @Override // puw.C1140f
    public <T> T getJceStruct(String str) throws C1141g {
        if (this.f5880d != null) {
            throw new RuntimeException("data is encoded by new version, please use getJceStruct(String name,T proxy)");
        }
        return (T) super.getJceStruct(str);
    }

    public <T> T getJceStruct(String str, T t) throws C1141g {
        if (!this.f5880d.containsKey(str)) {
            return null;
        }
        if (this.f5878a.containsKey(str)) {
            return (T) this.f5878a.get(str);
        }
        try {
            T t2 = (T) m2476a(this.f5880d.get(str), t);
            if (t2 == null) {
                return t2;
            }
            m2477a(str, t2);
            return t2;
        } catch (Exception e) {
            throw new C1141g(e);
        }
    }

    @Override // puw.C1140f
    public Set<String> getKeySet() {
        return this.f5880d != null ? Collections.unmodifiableSet(this.f5880d.keySet()) : Collections.unmodifiableSet(this.f6808f.keySet());
    }

    @Override // puw.C1140f
    public boolean isEmpty() {
        return this.f5880d != null ? this.f5880d.isEmpty() : this.f6808f.isEmpty();
    }

    @Override // puw.C1140f
    public <T> void put(String str, T t) {
        if (this.f5880d == null) {
            super.put(str, t);
            return;
        }
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
        this.f5880d.put(str, JceUtil.getJceBufArray(jceOutputStream.getByteBuffer()));
    }

    @Override // puw.C1140f
    public <T> T remove(String str) throws C1141g {
        if (this.f5880d == null) {
            return (T) super.remove(str);
        }
        if (!this.f5880d.containsKey(str)) {
            return null;
        }
        this.f5880d.remove(str);
        return null;
    }

    public <T> T remove(String str, T t) throws C1141g {
        if (!this.f5880d.containsKey(str)) {
            return null;
        }
        if (t != null) {
            return (T) m2476a(this.f5880d.remove(str), t);
        }
        this.f5880d.remove(str);
        return null;
    }

    @Override // puw.C1140f
    public /* bridge */ /* synthetic */ void setEncodeName(String str) {
        super.setEncodeName(str);
    }

    @Override // puw.C1140f
    public int size() {
        return this.f5880d != null ? this.f5880d.size() : this.f6808f.size();
    }

    public void useVersion3() {
        this.f5880d = new HashMap<>();
    }
}
