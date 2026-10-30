package com.p012qq.taf.jce;

import java.io.UnsupportedEncodingException;
import java.lang.reflect.Array;
import java.nio.BufferUnderflowException;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import puw.C1138d;
import puw.C1142h;

/* JADX INFO: loaded from: classes.dex */
public final class JceInputStream {

    /* JADX INFO: renamed from: a */
    protected String f5887a = "GBK";

    /* JADX INFO: renamed from: b */
    private ByteBuffer f5888b;

    /* JADX INFO: renamed from: com.qq.taf.jce.JceInputStream$a */
    public static class C1056a {

        /* JADX INFO: renamed from: a */
        public byte f5889a;

        /* JADX INFO: renamed from: b */
        public int f5890b;
    }

    public JceInputStream() {
    }

    public JceInputStream(ByteBuffer byteBuffer) {
        this.f5888b = byteBuffer;
    }

    public JceInputStream(byte[] bArr) {
        this.f5888b = ByteBuffer.wrap(bArr);
    }

    public JceInputStream(byte[] bArr, int i) {
        this.f5888b = ByteBuffer.wrap(bArr);
        this.f5888b.position(i);
    }

    /* JADX WARN: Multi-variable type inference failed */
    /* JADX INFO: renamed from: a */
    private <K, V> Map<K, V> m2479a(Map<K, V> map, Map<K, V> map2, int i, boolean z) {
        if (map2 == null || map2.isEmpty()) {
            return new HashMap();
        }
        Map.Entry<K, V> next = map2.entrySet().iterator().next();
        K key = next.getKey();
        V value = next.getValue();
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return map;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 8:
                int i2 = read(0, 0, true);
                if (i2 < 0) {
                    throw new C1142h("size invalid: " + i2);
                }
                for (int i3 = 0; i3 < i2; i3++) {
                    map.put(read(key, 0, true), read(value, 1, true));
                }
                return map;
            default:
                throw new C1142h("type mismatch.");
        }
    }

    /* JADX INFO: renamed from: a */
    private void m2480a() {
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        m2481a(c1056a.f5889a);
    }

    /* JADX INFO: renamed from: a */
    private void m2481a(byte b) {
        int i = 0;
        switch (b) {
            case 0:
                m2482a(1);
                return;
            case 1:
                m2482a(2);
                return;
            case 2:
                m2482a(4);
                return;
            case 3:
                m2482a(8);
                return;
            case 4:
                m2482a(4);
                return;
            case 5:
                m2482a(8);
                return;
            case 6:
                int i2 = this.f5888b.get();
                if (i2 < 0) {
                    i2 += 256;
                }
                m2482a(i2);
                return;
            case 7:
                m2482a(this.f5888b.getInt());
                return;
            case 8:
                int i3 = read(0, 0, true);
                while (i < i3 * 2) {
                    m2480a();
                    i++;
                }
                return;
            case 9:
                int i4 = read(0, 0, true);
                while (i < i4) {
                    m2480a();
                    i++;
                }
                return;
            case 10:
                skipToStructEnd();
                return;
            case 11:
            case 12:
                return;
            case 13:
                C1056a c1056a = new C1056a();
                readHead(c1056a);
                if (c1056a.f5889a != 0) {
                    throw new C1142h("skipField with invalid type, type value: " + ((int) b) + ", " + ((int) c1056a.f5889a));
                }
                m2482a(read(0, 0, true));
                return;
            default:
                throw new C1142h("invalid type.");
        }
    }

    /* JADX INFO: renamed from: a */
    private void m2482a(int i) {
        this.f5888b.position(this.f5888b.position() + i);
    }

    /* JADX WARN: Multi-variable type inference failed */
    /* JADX INFO: renamed from: a */
    private <T> T[] m2483a(T t, int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return null;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 9:
                int i2 = read(0, 0, true);
                if (i2 < 0) {
                    throw new C1142h("size invalid: " + i2);
                }
                T[] tArr = (T[]) ((Object[]) Array.newInstance(t.getClass(), i2));
                for (int i3 = 0; i3 < i2; i3++) {
                    tArr[i3] = read((Object) t, 0, true);
                }
                return tArr;
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public static void main(String[] strArr) {
    }

    public static int readHead(C1056a c1056a, ByteBuffer byteBuffer) {
        byte b = byteBuffer.get();
        c1056a.f5889a = (byte) (b & 15);
        c1056a.f5890b = (b & 240) >> 4;
        if (c1056a.f5890b != 15) {
            return 1;
        }
        c1056a.f5890b = byteBuffer.get();
        return 2;
    }

    public final JceStruct directRead(JceStruct jceStruct, int i, boolean z) {
        JceStruct jceStructNewInit = null;
        if (skipToTag(i)) {
            try {
                jceStructNewInit = jceStruct.newInit();
                C1056a c1056a = new C1056a();
                readHead(c1056a);
                if (c1056a.f5889a != 10) {
                    throw new C1142h("type mismatch.");
                }
                jceStructNewInit.readFrom(this);
                skipToStructEnd();
            } catch (Exception e) {
                throw new C1142h(e.getMessage());
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return jceStructNewInit;
    }

    public final ByteBuffer getBs() {
        return this.f5888b;
    }

    public final byte read(byte b, int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return b;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 0:
                return this.f5888b.get();
            case 12:
                return (byte) 0;
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final double read(double d, int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return d;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 4:
                return this.f5888b.getFloat();
            case 5:
                return this.f5888b.getDouble();
            case 12:
                return 0.0d;
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final float read(float f, int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return f;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 4:
                return this.f5888b.getFloat();
            case 12:
                return 0.0f;
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final int read(int i, int i2, boolean z) {
        if (!skipToTag(i2)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return i;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 0:
                return this.f5888b.get();
            case 1:
                return this.f5888b.getShort();
            case 2:
                return this.f5888b.getInt();
            case 12:
                return 0;
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final long read(long j, int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return j;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 0:
                return this.f5888b.get();
            case 1:
                return this.f5888b.getShort();
            case 2:
                return this.f5888b.getInt();
            case 3:
                return this.f5888b.getLong();
            case 12:
                return 0L;
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final JceStruct read(JceStruct jceStruct, int i, boolean z) {
        JceStruct jceStruct2 = null;
        if (skipToTag(i)) {
            try {
                jceStruct2 = (JceStruct) jceStruct.getClass().newInstance();
                C1056a c1056a = new C1056a();
                readHead(c1056a);
                if (c1056a.f5889a != 10) {
                    throw new C1142h("type mismatch.");
                }
                jceStruct2.readFrom(this);
                skipToStructEnd();
            } catch (Exception e) {
                throw new C1142h(e.getMessage());
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return jceStruct2;
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final <T> Object read(T t, int i, boolean z) {
        if (t instanceof Byte) {
            return Byte.valueOf(read((byte) 0, i, z));
        }
        if (t instanceof Boolean) {
            return Boolean.valueOf(read(false, i, z));
        }
        if (t instanceof Short) {
            return Short.valueOf(read((short) 0, i, z));
        }
        if (t instanceof Integer) {
            return Integer.valueOf(read(0, i, z));
        }
        if (t instanceof Long) {
            return Long.valueOf(read(0L, i, z));
        }
        if (t instanceof Float) {
            return Float.valueOf(read(0.0f, i, z));
        }
        if (t instanceof Double) {
            return Double.valueOf(read(0.0d, i, z));
        }
        if (t instanceof String) {
            return String.valueOf(readString(i, z));
        }
        if (t instanceof Map) {
            return readMap((Map) t, i, z);
        }
        if (t instanceof List) {
            return readArray((List) t, i, z);
        }
        if (t instanceof JceStruct) {
            return read((JceStruct) t, i, z);
        }
        if (!t.getClass().isArray()) {
            throw new C1142h("read object error: unsupport type.");
        }
        if ((t instanceof byte[]) || (t instanceof Byte[])) {
            return read((byte[]) null, i, z);
        }
        if (t instanceof boolean[]) {
            return read((boolean[]) null, i, z);
        }
        if (t instanceof short[]) {
            return read((short[]) null, i, z);
        }
        if (t instanceof int[]) {
            return read((int[]) null, i, z);
        }
        if (t instanceof long[]) {
            return read((long[]) null, i, z);
        }
        if (t instanceof float[]) {
            return read((float[]) null, i, z);
        }
        return t instanceof double[] ? read((double[]) null, i, z) : readArray((Object[]) t, i, z);
    }

    public final String read(String str, int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return str;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 6:
                int i2 = this.f5888b.get();
                if (i2 < 0) {
                    i2 += 256;
                }
                byte[] bArr = new byte[i2];
                this.f5888b.get(bArr);
                try {
                    return new String(bArr, this.f5887a);
                } catch (UnsupportedEncodingException e) {
                    return new String(bArr);
                }
            case 7:
                int i3 = this.f5888b.getInt();
                if (i3 > 104857600 || i3 < 0) {
                    throw new C1142h("String too long: " + i3);
                }
                byte[] bArr2 = new byte[i3];
                this.f5888b.get(bArr2);
                try {
                    return new String(bArr2, this.f5887a);
                } catch (UnsupportedEncodingException e2) {
                    return new String(bArr2);
                }
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final short read(short s, int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return s;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 0:
                return this.f5888b.get();
            case 1:
                return this.f5888b.getShort();
            case 12:
                return (short) 0;
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final boolean read(boolean z, int i, boolean z2) {
        return read((byte) 0, i, z2) != 0;
    }

    public final byte[] read(byte[] bArr, int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return null;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 9:
                int i2 = read(0, 0, true);
                if (i2 < 0) {
                    throw new C1142h("size invalid: " + i2);
                }
                byte[] bArr2 = new byte[i2];
                for (int i3 = 0; i3 < i2; i3++) {
                    bArr2[i3] = read(bArr2[0], 0, true);
                }
                return bArr2;
            case 13:
                C1056a c1056a2 = new C1056a();
                readHead(c1056a2);
                if (c1056a2.f5889a != 0) {
                    throw new C1142h("type mismatch, tag: " + i + ", type: " + ((int) c1056a.f5889a) + ", " + ((int) c1056a2.f5889a));
                }
                int i4 = read(0, 0, true);
                if (i4 < 0) {
                    throw new C1142h("invalid size, tag: " + i + ", type: " + ((int) c1056a.f5889a) + ", " + ((int) c1056a2.f5889a) + ", size: " + i4);
                }
                byte[] bArr3 = new byte[i4];
                this.f5888b.get(bArr3);
                return bArr3;
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final double[] read(double[] dArr, int i, boolean z) {
        double[] dArr2 = null;
        if (skipToTag(i)) {
            C1056a c1056a = new C1056a();
            readHead(c1056a);
            switch (c1056a.f5889a) {
                case 9:
                    int i2 = read(0, 0, true);
                    if (i2 < 0) {
                        throw new C1142h("size invalid: " + i2);
                    }
                    dArr2 = new double[i2];
                    for (int i3 = 0; i3 < i2; i3++) {
                        dArr2[i3] = read(dArr2[0], 0, true);
                    }
                    break;
                    break;
                default:
                    throw new C1142h("type mismatch.");
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return dArr2;
    }

    public final float[] read(float[] fArr, int i, boolean z) {
        float[] fArr2 = null;
        if (skipToTag(i)) {
            C1056a c1056a = new C1056a();
            readHead(c1056a);
            switch (c1056a.f5889a) {
                case 9:
                    int i2 = read(0, 0, true);
                    if (i2 < 0) {
                        throw new C1142h("size invalid: " + i2);
                    }
                    fArr2 = new float[i2];
                    for (int i3 = 0; i3 < i2; i3++) {
                        fArr2[i3] = read(fArr2[0], 0, true);
                    }
                    break;
                    break;
                default:
                    throw new C1142h("type mismatch.");
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return fArr2;
    }

    public final int[] read(int[] iArr, int i, boolean z) {
        int[] iArr2 = null;
        if (skipToTag(i)) {
            C1056a c1056a = new C1056a();
            readHead(c1056a);
            switch (c1056a.f5889a) {
                case 9:
                    int i2 = read(0, 0, true);
                    if (i2 < 0) {
                        throw new C1142h("size invalid: " + i2);
                    }
                    iArr2 = new int[i2];
                    for (int i3 = 0; i3 < i2; i3++) {
                        iArr2[i3] = read(iArr2[0], 0, true);
                    }
                    break;
                    break;
                default:
                    throw new C1142h("type mismatch.");
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return iArr2;
    }

    public final long[] read(long[] jArr, int i, boolean z) {
        long[] jArr2 = null;
        if (skipToTag(i)) {
            C1056a c1056a = new C1056a();
            readHead(c1056a);
            switch (c1056a.f5889a) {
                case 9:
                    int i2 = read(0, 0, true);
                    if (i2 < 0) {
                        throw new C1142h("size invalid: " + i2);
                    }
                    jArr2 = new long[i2];
                    for (int i3 = 0; i3 < i2; i3++) {
                        jArr2[i3] = read(jArr2[0], 0, true);
                    }
                    break;
                    break;
                default:
                    throw new C1142h("type mismatch.");
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return jArr2;
    }

    public final JceStruct[] read(JceStruct[] jceStructArr, int i, boolean z) {
        return (JceStruct[]) readArray(jceStructArr, i, z);
    }

    public final String[] read(String[] strArr, int i, boolean z) {
        return (String[]) readArray(strArr, i, z);
    }

    public final short[] read(short[] sArr, int i, boolean z) {
        short[] sArr2 = null;
        if (skipToTag(i)) {
            C1056a c1056a = new C1056a();
            readHead(c1056a);
            switch (c1056a.f5889a) {
                case 9:
                    int i2 = read(0, 0, true);
                    if (i2 < 0) {
                        throw new C1142h("size invalid: " + i2);
                    }
                    sArr2 = new short[i2];
                    for (int i3 = 0; i3 < i2; i3++) {
                        sArr2[i3] = read(sArr2[0], 0, true);
                    }
                    break;
                    break;
                default:
                    throw new C1142h("type mismatch.");
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return sArr2;
    }

    public final boolean[] read(boolean[] zArr, int i, boolean z) {
        boolean[] zArr2 = null;
        if (skipToTag(i)) {
            C1056a c1056a = new C1056a();
            readHead(c1056a);
            switch (c1056a.f5889a) {
                case 9:
                    int i2 = read(0, 0, true);
                    if (i2 < 0) {
                        throw new C1142h("size invalid: " + i2);
                    }
                    zArr2 = new boolean[i2];
                    for (int i3 = 0; i3 < i2; i3++) {
                        zArr2[i3] = read(zArr2[0], 0, true);
                    }
                    break;
                    break;
                default:
                    throw new C1142h("type mismatch.");
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return zArr2;
    }

    public final <T> List<T> readArray(List<T> list, int i, boolean z) {
        if (list == null || list.isEmpty()) {
            return new ArrayList();
        }
        Object[] objArrM2483a = m2483a(list.get(0), i, z);
        if (objArrM2483a == null) {
            return null;
        }
        ArrayList arrayList = new ArrayList();
        for (Object obj : objArrM2483a) {
            arrayList.add(obj);
        }
        return arrayList;
    }

    public final <T> T[] readArray(T[] tArr, int i, boolean z) {
        if (tArr == null || tArr.length == 0) {
            throw new C1142h("unable to get type of key and value.");
        }
        return (T[]) m2483a(tArr[0], i, z);
    }

    public final String readByteString(String str, int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return str;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 6:
                int i2 = this.f5888b.get();
                if (i2 < 0) {
                    i2 += 256;
                }
                byte[] bArr = new byte[i2];
                this.f5888b.get(bArr);
                return C1138d.m2865a(bArr);
            case 7:
                int i3 = this.f5888b.getInt();
                if (i3 > 104857600 || i3 < 0) {
                    throw new C1142h("String too long: " + i3);
                }
                byte[] bArr2 = new byte[i3];
                this.f5888b.get(bArr2);
                return C1138d.m2865a(bArr2);
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final void readHead(C1056a c1056a) {
        readHead(c1056a, this.f5888b);
    }

    public final List readList(int i, boolean z) {
        ArrayList arrayList = new ArrayList();
        if (skipToTag(i)) {
            C1056a c1056a = new C1056a();
            readHead(c1056a);
            switch (c1056a.f5889a) {
                case 9:
                    int i2 = read(0, 0, true);
                    if (i2 < 0) {
                        throw new C1142h("size invalid: " + i2);
                    }
                    for (int i3 = 0; i3 < i2; i3++) {
                        C1056a c1056a2 = new C1056a();
                        readHead(c1056a2);
                        switch (c1056a2.f5889a) {
                            case 0:
                                m2482a(1);
                                break;
                            case 1:
                                m2482a(2);
                                break;
                            case 2:
                                m2482a(4);
                                break;
                            case 3:
                                m2482a(8);
                                break;
                            case 4:
                                m2482a(4);
                                break;
                            case 5:
                                m2482a(8);
                                break;
                            case 6:
                                int i4 = this.f5888b.get();
                                if (i4 < 0) {
                                    i4 += 256;
                                }
                                m2482a(i4);
                                break;
                            case 7:
                                m2482a(this.f5888b.getInt());
                                break;
                            case 8:
                            case 9:
                                break;
                            case 10:
                                try {
                                    JceStruct jceStruct = (JceStruct) Class.forName(JceStruct.class.getName()).getConstructor(new Class[0]).newInstance(new Object[0]);
                                    jceStruct.readFrom(this);
                                    skipToStructEnd();
                                    arrayList.add(jceStruct);
                                } catch (Exception e) {
                                    e.printStackTrace();
                                    throw new C1142h("type mismatch." + e);
                                }
                                break;
                            case 11:
                            default:
                                throw new C1142h("type mismatch.");
                            case 12:
                                arrayList.add(new Integer(0));
                                break;
                        }
                    }
                    break;
                    break;
                default:
                    throw new C1142h("type mismatch.");
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return arrayList;
    }

    public final <K, V> HashMap<K, V> readMap(Map<K, V> map, int i, boolean z) {
        return (HashMap) m2479a(new HashMap(), map, i, z);
    }

    public final String readString(int i, boolean z) {
        if (!skipToTag(i)) {
            if (z) {
                throw new C1142h("require field not exist.");
            }
            return null;
        }
        C1056a c1056a = new C1056a();
        readHead(c1056a);
        switch (c1056a.f5889a) {
            case 6:
                int i2 = this.f5888b.get();
                if (i2 < 0) {
                    i2 += 256;
                }
                byte[] bArr = new byte[i2];
                this.f5888b.get(bArr);
                try {
                    return new String(bArr, this.f5887a);
                } catch (UnsupportedEncodingException e) {
                    return new String(bArr);
                }
            case 7:
                int i3 = this.f5888b.getInt();
                if (i3 > 104857600 || i3 < 0) {
                    throw new C1142h("String too long: " + i3);
                }
                byte[] bArr2 = new byte[i3];
                this.f5888b.get(bArr2);
                try {
                    return new String(bArr2, this.f5887a);
                } catch (UnsupportedEncodingException e2) {
                    return new String(bArr2);
                }
            default:
                throw new C1142h("type mismatch.");
        }
    }

    public final Map<String, String> readStringMap(int i, boolean z) {
        HashMap map = new HashMap();
        if (skipToTag(i)) {
            C1056a c1056a = new C1056a();
            readHead(c1056a);
            switch (c1056a.f5889a) {
                case 8:
                    int i2 = read(0, 0, true);
                    if (i2 < 0) {
                        throw new C1142h("size invalid: " + i2);
                    }
                    for (int i3 = 0; i3 < i2; i3++) {
                        map.put(readString(0, true), readString(1, true));
                    }
                    break;
                    break;
                default:
                    throw new C1142h("type mismatch.");
            }
        } else if (z) {
            throw new C1142h("require field not exist.");
        }
        return map;
    }

    public final int setServerEncoding(String str) {
        this.f5887a = str;
        return 0;
    }

    public final void skipToStructEnd() {
        C1056a c1056a = new C1056a();
        do {
            readHead(c1056a);
            m2481a(c1056a.f5889a);
        } while (c1056a.f5889a != 11);
    }

    public final boolean skipToTag(int i) {
        try {
            C1056a c1056a = new C1056a();
            while (true) {
                int head = readHead(c1056a, this.f5888b.duplicate());
                if (i <= c1056a.f5890b || c1056a.f5889a == 11) {
                    break;
                }
                m2482a(head);
                m2481a(c1056a.f5889a);
            }
            return i == c1056a.f5890b;
        } catch (BufferUnderflowException e) {
            return false;
        } catch (C1142h e2) {
            return false;
        }
    }

    public final void warp(byte[] bArr) {
        if (this.f5888b != null) {
            this.f5888b.clear();
        }
        this.f5888b = ByteBuffer.wrap(bArr);
    }
}
