package com.p012qq.taf.jce;

import java.util.Collection;
import java.util.List;
import java.util.Map;
import puw.C1135a;

/* JADX INFO: loaded from: classes.dex */
public final class JceDisplayer {

    /* JADX INFO: renamed from: a */
    private StringBuilder f5885a;

    /* JADX INFO: renamed from: b */
    private int f5886b;

    public JceDisplayer(StringBuilder sb) {
        this.f5886b = 0;
        this.f5885a = sb;
    }

    public JceDisplayer(StringBuilder sb, int i) {
        this.f5886b = 0;
        this.f5885a = sb;
        this.f5886b = i;
    }

    /* JADX INFO: renamed from: a */
    private void m2478a(String str) {
        for (int i = 0; i < this.f5886b; i++) {
            this.f5885a.append('\t');
        }
        if (str != null) {
            this.f5885a.append(str).append(": ");
        }
    }

    public static void main(String[] strArr) {
        StringBuilder sb = new StringBuilder();
        sb.append(1.2d);
        System.out.println(sb.toString());
    }

    public final JceDisplayer display(byte b, String str) {
        m2478a(str);
        this.f5885a.append((int) b).append('\n');
        return this;
    }

    public final JceDisplayer display(char c, String str) {
        m2478a(str);
        this.f5885a.append(c).append('\n');
        return this;
    }

    public final JceDisplayer display(double d, String str) {
        m2478a(str);
        this.f5885a.append(d).append('\n');
        return this;
    }

    public final JceDisplayer display(float f, String str) {
        m2478a(str);
        this.f5885a.append(f).append('\n');
        return this;
    }

    public final JceDisplayer display(int i, String str) {
        m2478a(str);
        this.f5885a.append(i).append('\n');
        return this;
    }

    public final JceDisplayer display(long j, String str) {
        m2478a(str);
        this.f5885a.append(j).append('\n');
        return this;
    }

    public final JceDisplayer display(JceStruct jceStruct, String str) {
        display('{', str);
        if (jceStruct == null) {
            this.f5885a.append('\t').append("null");
        } else {
            jceStruct.display(this.f5885a, this.f5886b + 1);
        }
        display('}', (String) null);
        return this;
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final <T> JceDisplayer display(T t, String str) {
        if (t == 0) {
            this.f5885a.append("null").append('\n');
        } else if (t instanceof Byte) {
            display(((Byte) t).byteValue(), str);
        } else if (t instanceof Boolean) {
            display(((Boolean) t).booleanValue(), str);
        } else if (t instanceof Short) {
            display(((Short) t).shortValue(), str);
        } else if (t instanceof Integer) {
            display(((Integer) t).intValue(), str);
        } else if (t instanceof Long) {
            display(((Long) t).longValue(), str);
        } else if (t instanceof Float) {
            display(((Float) t).floatValue(), str);
        } else if (t instanceof Double) {
            display(((Double) t).doubleValue(), str);
        } else if (t instanceof String) {
            display((String) t, str);
        } else if (t instanceof Map) {
            display((Map) t, str);
        } else if (t instanceof List) {
            display((Collection) t, str);
        } else if (t instanceof JceStruct) {
            display((JceStruct) t, str);
        } else if (t instanceof byte[]) {
            display((byte[]) t, str);
        } else if (t instanceof boolean[]) {
            display((boolean[]) t, str);
        } else if (t instanceof short[]) {
            display((short[]) t, str);
        } else if (t instanceof int[]) {
            display((int[]) t, str);
        } else if (t instanceof long[]) {
            display((long[]) t, str);
        } else if (t instanceof float[]) {
            display((float[]) t, str);
        } else if (t instanceof double[]) {
            display((double[]) t, str);
        } else {
            if (!t.getClass().isArray()) {
                throw new C1135a("write object error: unsupport type.");
            }
            display((Object[]) t, str);
        }
        return this;
    }

    public final JceDisplayer display(String str, String str2) {
        m2478a(str2);
        if (str == null) {
            this.f5885a.append("null").append('\n');
        } else {
            this.f5885a.append(str).append('\n');
        }
        return this;
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final <T> JceDisplayer display(Collection<T> collection, String str) {
        if (collection != null) {
            return display(collection.toArray(), str);
        }
        m2478a(str);
        this.f5885a.append("null").append('\t');
        return this;
    }

    public final <K, V> JceDisplayer display(Map<K, V> map, String str) {
        m2478a(str);
        if (map == null) {
            this.f5885a.append("null").append('\n');
        } else if (map.isEmpty()) {
            this.f5885a.append(map.size()).append(", {}").append('\n');
        } else {
            this.f5885a.append(map.size()).append(", {").append('\n');
            JceDisplayer jceDisplayer = new JceDisplayer(this.f5885a, this.f5886b + 1);
            JceDisplayer jceDisplayer2 = new JceDisplayer(this.f5885a, this.f5886b + 2);
            for (Map.Entry<K, V> entry : map.entrySet()) {
                jceDisplayer.display('(', (String) null);
                jceDisplayer2.display(entry.getKey(), (String) null);
                jceDisplayer2.display(entry.getValue(), (String) null);
                jceDisplayer.display(')', (String) null);
            }
            display('}', (String) null);
        }
        return this;
    }

    public final JceDisplayer display(short s, String str) {
        m2478a(str);
        this.f5885a.append((int) s).append('\n');
        return this;
    }

    public final JceDisplayer display(boolean z, String str) {
        m2478a(str);
        this.f5885a.append(z ? 'T' : 'F').append('\n');
        return this;
    }

    public final JceDisplayer display(byte[] bArr, String str) {
        m2478a(str);
        if (bArr == null) {
            this.f5885a.append("null").append('\n');
        } else if (bArr.length == 0) {
            this.f5885a.append(bArr.length).append(", []").append('\n');
        } else {
            this.f5885a.append(bArr.length).append(", [").append('\n');
            JceDisplayer jceDisplayer = new JceDisplayer(this.f5885a, this.f5886b + 1);
            for (byte b : bArr) {
                jceDisplayer.display(b, (String) null);
            }
            display(']', (String) null);
        }
        return this;
    }

    public final JceDisplayer display(char[] cArr, String str) {
        m2478a(str);
        if (cArr == null) {
            this.f5885a.append("null").append('\n');
        } else if (cArr.length == 0) {
            this.f5885a.append(cArr.length).append(", []").append('\n');
        } else {
            this.f5885a.append(cArr.length).append(", [").append('\n');
            JceDisplayer jceDisplayer = new JceDisplayer(this.f5885a, this.f5886b + 1);
            for (char c : cArr) {
                jceDisplayer.display(c, (String) null);
            }
            display(']', (String) null);
        }
        return this;
    }

    public final JceDisplayer display(double[] dArr, String str) {
        m2478a(str);
        if (dArr == null) {
            this.f5885a.append("null").append('\n');
        } else if (dArr.length == 0) {
            this.f5885a.append(dArr.length).append(", []").append('\n');
        } else {
            this.f5885a.append(dArr.length).append(", [").append('\n');
            JceDisplayer jceDisplayer = new JceDisplayer(this.f5885a, this.f5886b + 1);
            for (double d : dArr) {
                jceDisplayer.display(d, (String) null);
            }
            display(']', (String) null);
        }
        return this;
    }

    public final JceDisplayer display(float[] fArr, String str) {
        m2478a(str);
        if (fArr == null) {
            this.f5885a.append("null").append('\n');
        } else if (fArr.length == 0) {
            this.f5885a.append(fArr.length).append(", []").append('\n');
        } else {
            this.f5885a.append(fArr.length).append(", [").append('\n');
            JceDisplayer jceDisplayer = new JceDisplayer(this.f5885a, this.f5886b + 1);
            for (float f : fArr) {
                jceDisplayer.display(f, (String) null);
            }
            display(']', (String) null);
        }
        return this;
    }

    public final JceDisplayer display(int[] iArr, String str) {
        m2478a(str);
        if (iArr == null) {
            this.f5885a.append("null").append('\n');
        } else if (iArr.length == 0) {
            this.f5885a.append(iArr.length).append(", []").append('\n');
        } else {
            this.f5885a.append(iArr.length).append(", [").append('\n');
            JceDisplayer jceDisplayer = new JceDisplayer(this.f5885a, this.f5886b + 1);
            for (int i : iArr) {
                jceDisplayer.display(i, (String) null);
            }
            display(']', (String) null);
        }
        return this;
    }

    public final JceDisplayer display(long[] jArr, String str) {
        m2478a(str);
        if (jArr == null) {
            this.f5885a.append("null").append('\n');
        } else if (jArr.length == 0) {
            this.f5885a.append(jArr.length).append(", []").append('\n');
        } else {
            this.f5885a.append(jArr.length).append(", [").append('\n');
            JceDisplayer jceDisplayer = new JceDisplayer(this.f5885a, this.f5886b + 1);
            for (long j : jArr) {
                jceDisplayer.display(j, (String) null);
            }
            display(']', (String) null);
        }
        return this;
    }

    public final <T> JceDisplayer display(T[] tArr, String str) {
        m2478a(str);
        if (tArr == null) {
            this.f5885a.append("null").append('\n');
        } else if (tArr.length == 0) {
            this.f5885a.append(tArr.length).append(", []").append('\n');
        } else {
            this.f5885a.append(tArr.length).append(", [").append('\n');
            JceDisplayer jceDisplayer = new JceDisplayer(this.f5885a, this.f5886b + 1);
            for (T t : tArr) {
                jceDisplayer.display(t, (String) null);
            }
            display(']', (String) null);
        }
        return this;
    }

    public final JceDisplayer display(short[] sArr, String str) {
        m2478a(str);
        if (sArr == null) {
            this.f5885a.append("null").append('\n');
        } else if (sArr.length == 0) {
            this.f5885a.append(sArr.length).append(", []").append('\n');
        } else {
            this.f5885a.append(sArr.length).append(", [").append('\n');
            JceDisplayer jceDisplayer = new JceDisplayer(this.f5885a, this.f5886b + 1);
            for (short s : sArr) {
                jceDisplayer.display(s, (String) null);
            }
            display(']', (String) null);
        }
        return this;
    }
}
