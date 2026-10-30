package com.tendcloud.tenddata;

import java.io.IOException;
import java.io.OutputStream;
import java.math.BigInteger;
import java.nio.ByteBuffer;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

/* JADX INFO: renamed from: com.tendcloud.tenddata.p */
/* JADX INFO: loaded from: classes.dex */
public class C0084p {

    /* JADX INFO: renamed from: a */
    protected byte[] f162a = new byte[9];

    /* JADX INFO: renamed from: b */
    protected OutputStream f163b;

    public C0084p(OutputStream outputStream) {
        this.f163b = outputStream;
    }

    /* JADX INFO: renamed from: b */
    public static int m77b(double d) {
        return 9;
    }

    /* JADX INFO: renamed from: b */
    public static int m78b(float f) {
        return 5;
    }

    /* JADX INFO: renamed from: b */
    public static int m79b(boolean z) {
        return 1;
    }

    /* JADX INFO: renamed from: b */
    public static int m80b(byte[] bArr) {
        if (bArr == null) {
            return 1;
        }
        return m81c(bArr.length) + bArr.length;
    }

    /* JADX INFO: renamed from: c */
    public static int m81c(int i) {
        if (i < 16) {
            return 1;
        }
        return i < 65536 ? 3 : 5;
    }

    /* JADX INFO: renamed from: c */
    public static int m82c(long j) {
        if (j < -32) {
            if (j < -32768) {
                return j < -2147483648L ? 9 : 5;
            }
            return j < -128 ? 3 : 2;
        }
        if (j < 128) {
            return 1;
        }
        if (j < 65536) {
            return j < 256 ? 2 : 3;
        }
        return j < 4294967296L ? 5 : 9;
    }

    /* JADX INFO: renamed from: c */
    public static int m83c(String str) {
        try {
            byte[] bytes = str.getBytes("UTF-8");
            return bytes.length + m81c(bytes.length);
        } catch (Exception e) {
            return 0;
        }
    }

    /* JADX INFO: renamed from: a */
    public C0084p m84a() throws IOException {
        this.f163b.write(-62);
        return this;
    }

    /* JADX INFO: renamed from: a */
    public C0084p m85a(byte b) {
        return m109b(b);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m86a(double d) {
        return m118c(d);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m87a(float f) {
        return m119c(f);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m88a(int i) {
        return m122d(i);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m89a(long j) {
        return m111b(j);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m90a(InterfaceC0076h interfaceC0076h) {
        if (interfaceC0076h == null) {
            return m108b();
        }
        interfaceC0076h.mo57a(this);
        return this;
    }

    /* JADX INFO: renamed from: a */
    public C0084p m91a(Boolean bool) {
        if (bool == null) {
            return m108b();
        }
        return bool.booleanValue() ? m117c() : m84a();
    }

    /* JADX INFO: renamed from: a */
    public C0084p m92a(Byte b) {
        return b == null ? m108b() : m109b(b.byteValue());
    }

    /* JADX INFO: renamed from: a */
    public C0084p m93a(Double d) {
        return d == null ? m108b() : m118c(d.doubleValue());
    }

    /* JADX INFO: renamed from: a */
    public C0084p m94a(Float f) {
        return f == null ? m108b() : m119c(f.floatValue());
    }

    /* JADX INFO: renamed from: a */
    public C0084p m95a(Integer num) {
        return num == null ? m108b() : m122d(num.intValue());
    }

    /* JADX INFO: renamed from: a */
    public C0084p m96a(Long l) {
        return l == null ? m108b() : m111b(l.longValue());
    }

    /* JADX INFO: renamed from: a */
    public C0084p m97a(Short sh) {
        return sh == null ? m108b() : m115b(sh.shortValue());
    }

    /* JADX INFO: renamed from: a */
    public C0084p m98a(String str) {
        return str == null ? m112b("") : m112b(str);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m99a(BigInteger bigInteger) {
        return bigInteger == null ? m108b() : m113b(bigInteger);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m100a(ByteBuffer byteBuffer) throws IOException {
        if (byteBuffer == null) {
            return m108b();
        }
        m125f(byteBuffer.remaining());
        return m116b(byteBuffer.array(), byteBuffer.arrayOffset() + byteBuffer.position(), byteBuffer.remaining());
    }

    /* JADX INFO: renamed from: a */
    public C0084p m101a(List list) throws IOException {
        if (list == null) {
            return m108b();
        }
        m110b(list.size());
        Iterator it = list.iterator();
        while (it.hasNext()) {
            m98a((String) it.next());
        }
        return this;
    }

    /* JADX INFO: renamed from: a */
    public C0084p m102a(Map map) throws IOException {
        if (map == null) {
            return m108b();
        }
        HashMap map2 = new HashMap();
        for (String str : map.keySet()) {
            Object obj = map.get(str);
            if (obj instanceof String) {
                map2.put(str, obj.toString());
            } else if (obj instanceof Number) {
                map2.put(str, Double.valueOf(((Number) obj).doubleValue()));
            }
        }
        m124e(map2.size());
        for (Map.Entry entry : map2.entrySet()) {
            m98a((String) entry.getKey());
            Object value = entry.getValue();
            if (value instanceof Number) {
                m86a(((Number) value).doubleValue());
            } else if (value instanceof String) {
                m98a(value.toString());
            }
        }
        return this;
    }

    /* JADX INFO: renamed from: a */
    public C0084p m103a(short s) {
        return m115b(s);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m104a(boolean z) {
        return z ? m117c() : m84a();
    }

    /* JADX INFO: renamed from: a */
    public C0084p m105a(byte[] bArr) throws IOException {
        if (bArr == null) {
            return m108b();
        }
        m125f(bArr.length);
        return m123d(bArr);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m106a(byte[] bArr, int i, int i2) throws IOException {
        m125f(i2);
        return m116b(bArr, i, i2);
    }

    /* JADX INFO: renamed from: a */
    public C0084p m107a(Long[] lArr) throws IOException {
        if (lArr == null || lArr.length == 0) {
            return m108b();
        }
        m110b(lArr.length);
        for (Long l : lArr) {
            m89a(l.longValue());
        }
        return this;
    }

    /* JADX INFO: renamed from: b */
    public C0084p m108b() throws IOException {
        this.f163b.write(-64);
        return this;
    }

    /* JADX INFO: renamed from: b */
    public C0084p m109b(byte b) throws IOException {
        if (b < -32) {
            this.f162a[0] = -48;
            this.f162a[1] = b;
            this.f163b.write(this.f162a, 0, 2);
        } else {
            this.f163b.write(b);
        }
        return this;
    }

    /* JADX INFO: renamed from: b */
    public C0084p m110b(int i) throws IOException {
        if (i < 16) {
            this.f163b.write((byte) (i | 144));
        } else if (i < 65536) {
            this.f162a[0] = -36;
            this.f162a[1] = (byte) (i >> 8);
            this.f162a[2] = (byte) (i >> 0);
            this.f163b.write(this.f162a, 0, 3);
        } else {
            this.f162a[0] = -35;
            this.f162a[1] = (byte) (i >> 24);
            this.f162a[2] = (byte) (i >> 16);
            this.f162a[3] = (byte) (i >> 8);
            this.f162a[4] = (byte) (i >> 0);
            this.f163b.write(this.f162a, 0, 5);
        }
        return this;
    }

    /* JADX INFO: renamed from: b */
    public C0084p m111b(long j) throws IOException {
        if (j < -32) {
            if (j < -32768) {
                if (j < -2147483648L) {
                    this.f162a[0] = -45;
                    this.f162a[1] = (byte) (j >> 56);
                    this.f162a[2] = (byte) (j >> 48);
                    this.f162a[3] = (byte) (j >> 40);
                    this.f162a[4] = (byte) (j >> 32);
                    this.f162a[5] = (byte) (j >> 24);
                    this.f162a[6] = (byte) (j >> 16);
                    this.f162a[7] = (byte) (j >> 8);
                    this.f162a[8] = (byte) (j >> 0);
                    this.f163b.write(this.f162a, 0, 9);
                } else {
                    this.f162a[0] = -46;
                    this.f162a[1] = (byte) (j >> 24);
                    this.f162a[2] = (byte) (j >> 16);
                    this.f162a[3] = (byte) (j >> 8);
                    this.f162a[4] = (byte) (j >> 0);
                    this.f163b.write(this.f162a, 0, 5);
                }
            } else if (j < -128) {
                this.f162a[0] = -47;
                this.f162a[1] = (byte) (j >> 8);
                this.f162a[2] = (byte) (j >> 0);
                this.f163b.write(this.f162a, 0, 3);
            } else {
                this.f162a[0] = -48;
                this.f162a[1] = (byte) j;
                this.f163b.write(this.f162a, 0, 2);
            }
        } else if (j < 128) {
            this.f163b.write((byte) j);
        } else if (j < 65536) {
            if (j < 256) {
                this.f162a[0] = -52;
                this.f162a[1] = (byte) j;
                this.f163b.write(this.f162a, 0, 2);
            } else {
                this.f162a[0] = -51;
                this.f162a[1] = (byte) ((65280 & j) >> 8);
                this.f162a[2] = (byte) ((255 & j) >> 0);
                this.f163b.write(this.f162a, 0, 3);
            }
        } else if (j < 4294967296L) {
            this.f162a[0] = -50;
            this.f162a[1] = (byte) (((-16777216) & j) >> 24);
            this.f162a[2] = (byte) ((16711680 & j) >> 16);
            this.f162a[3] = (byte) ((65280 & j) >> 8);
            this.f162a[4] = (byte) ((255 & j) >> 0);
            this.f163b.write(this.f162a, 0, 5);
        } else {
            this.f162a[0] = -49;
            this.f162a[1] = (byte) (j >> 56);
            this.f162a[2] = (byte) (j >> 48);
            this.f162a[3] = (byte) (j >> 40);
            this.f162a[4] = (byte) (j >> 32);
            this.f162a[5] = (byte) (j >> 24);
            this.f162a[6] = (byte) (j >> 16);
            this.f162a[7] = (byte) (j >> 8);
            this.f162a[8] = (byte) (j >> 0);
            this.f163b.write(this.f162a, 0, 9);
        }
        return this;
    }

    /* JADX INFO: renamed from: b */
    public C0084p m112b(String str) throws IOException {
        byte[] bytes = str.getBytes("UTF-8");
        m125f(bytes.length);
        return m123d(bytes);
    }

    /* JADX INFO: renamed from: b */
    public C0084p m113b(BigInteger bigInteger) throws IOException {
        if (bigInteger.bitLength() <= 63) {
            return m111b(bigInteger.longValue());
        }
        if (bigInteger.bitLength() > 64 || bigInteger.signum() < 0) {
            throw new IOException("can't pack BigInteger larger than 0xffffffffffffffff");
        }
        this.f162a[0] = -49;
        byte[] byteArray = bigInteger.toByteArray();
        this.f162a[1] = byteArray[byteArray.length - 8];
        this.f162a[2] = byteArray[byteArray.length - 7];
        this.f162a[3] = byteArray[byteArray.length - 6];
        this.f162a[4] = byteArray[byteArray.length - 5];
        this.f162a[5] = byteArray[byteArray.length - 4];
        this.f162a[6] = byteArray[byteArray.length - 3];
        this.f162a[7] = byteArray[byteArray.length - 2];
        this.f162a[8] = byteArray[byteArray.length - 1];
        this.f163b.write(this.f162a, 0, 9);
        return this;
    }

    /* JADX INFO: renamed from: b */
    public C0084p m114b(ByteBuffer byteBuffer) throws IOException {
        m125f(byteBuffer.remaining());
        return m116b(byteBuffer.array(), byteBuffer.arrayOffset() + byteBuffer.position(), byteBuffer.remaining());
    }

    /* JADX INFO: renamed from: b */
    public C0084p m115b(short s) throws IOException {
        if (s < -32) {
            if (s < -128) {
                this.f162a[0] = -47;
                this.f162a[1] = (byte) (s >> 8);
                this.f162a[2] = (byte) (s >> 0);
                this.f163b.write(this.f162a, 0, 3);
            } else {
                this.f162a[0] = -48;
                this.f162a[1] = (byte) s;
                this.f163b.write(this.f162a, 0, 2);
            }
        } else if (s < 128) {
            this.f163b.write((byte) s);
        } else if (s < 256) {
            this.f162a[0] = -52;
            this.f162a[1] = (byte) s;
            this.f163b.write(this.f162a, 0, 2);
        } else {
            this.f162a[0] = -51;
            this.f162a[1] = (byte) (s >> 8);
            this.f162a[2] = (byte) (s >> 0);
            this.f163b.write(this.f162a, 0, 3);
        }
        return this;
    }

    /* JADX INFO: renamed from: b */
    public C0084p m116b(byte[] bArr, int i, int i2) throws IOException {
        this.f163b.write(bArr, i, i2);
        return this;
    }

    /* JADX INFO: renamed from: c */
    public C0084p m117c() throws IOException {
        this.f163b.write(-61);
        return this;
    }

    /* JADX INFO: renamed from: c */
    public C0084p m118c(double d) throws IOException {
        this.f162a[0] = -53;
        long jDoubleToRawLongBits = Double.doubleToRawLongBits(d);
        this.f162a[1] = (byte) (jDoubleToRawLongBits >> 56);
        this.f162a[2] = (byte) (jDoubleToRawLongBits >> 48);
        this.f162a[3] = (byte) (jDoubleToRawLongBits >> 40);
        this.f162a[4] = (byte) (jDoubleToRawLongBits >> 32);
        this.f162a[5] = (byte) (jDoubleToRawLongBits >> 24);
        this.f162a[6] = (byte) (jDoubleToRawLongBits >> 16);
        this.f162a[7] = (byte) (jDoubleToRawLongBits >> 8);
        this.f162a[8] = (byte) (jDoubleToRawLongBits >> 0);
        this.f163b.write(this.f162a, 0, 9);
        return this;
    }

    /* JADX INFO: renamed from: c */
    public C0084p m119c(float f) throws IOException {
        this.f162a[0] = -54;
        int iFloatToRawIntBits = Float.floatToRawIntBits(f);
        this.f162a[1] = (byte) (iFloatToRawIntBits >> 24);
        this.f162a[2] = (byte) (iFloatToRawIntBits >> 16);
        this.f162a[3] = (byte) (iFloatToRawIntBits >> 8);
        this.f162a[4] = (byte) (iFloatToRawIntBits >> 0);
        this.f163b.write(this.f162a, 0, 5);
        return this;
    }

    /* JADX INFO: renamed from: c */
    public C0084p m120c(boolean z) {
        return z ? m117c() : m84a();
    }

    /* JADX INFO: renamed from: c */
    public C0084p m121c(byte[] bArr) throws IOException {
        m125f(bArr.length);
        return m116b(bArr, 0, bArr.length);
    }

    /* JADX INFO: renamed from: d */
    public C0084p m122d(int i) throws IOException {
        if (i < -32) {
            if (i < -32768) {
                this.f162a[0] = -46;
                this.f162a[1] = (byte) (i >> 24);
                this.f162a[2] = (byte) (i >> 16);
                this.f162a[3] = (byte) (i >> 8);
                this.f162a[4] = (byte) (i >> 0);
                this.f163b.write(this.f162a, 0, 5);
            } else if (i < -128) {
                this.f162a[0] = -47;
                this.f162a[1] = (byte) (i >> 8);
                this.f162a[2] = (byte) (i >> 0);
                this.f163b.write(this.f162a, 0, 3);
            } else {
                this.f162a[0] = -48;
                this.f162a[1] = (byte) i;
                this.f163b.write(this.f162a, 0, 2);
            }
        } else if (i < 128) {
            this.f163b.write((byte) i);
        } else if (i < 256) {
            this.f162a[0] = -52;
            this.f162a[1] = (byte) i;
            this.f163b.write(this.f162a, 0, 2);
        } else if (i < 65536) {
            this.f162a[0] = -51;
            this.f162a[1] = (byte) (i >> 8);
            this.f162a[2] = (byte) (i >> 0);
            this.f163b.write(this.f162a, 0, 3);
        } else {
            this.f162a[0] = -50;
            this.f162a[1] = (byte) (i >> 24);
            this.f162a[2] = (byte) (i >> 16);
            this.f162a[3] = (byte) (i >> 8);
            this.f162a[4] = (byte) (i >> 0);
            this.f163b.write(this.f162a, 0, 5);
        }
        return this;
    }

    /* JADX INFO: renamed from: d */
    public C0084p m123d(byte[] bArr) throws IOException {
        this.f163b.write(bArr);
        return this;
    }

    /* JADX INFO: renamed from: e */
    public C0084p m124e(int i) throws IOException {
        if (i < 16) {
            this.f163b.write((byte) (i | 128));
        } else if (i < 65536) {
            this.f162a[0] = -34;
            this.f162a[1] = (byte) (i >> 8);
            this.f162a[2] = (byte) (i >> 0);
            this.f163b.write(this.f162a, 0, 3);
        } else {
            this.f162a[0] = -33;
            this.f162a[1] = (byte) (i >> 24);
            this.f162a[2] = (byte) (i >> 16);
            this.f162a[3] = (byte) (i >> 8);
            this.f162a[4] = (byte) (i >> 0);
            this.f163b.write(this.f162a, 0, 5);
        }
        return this;
    }

    /* JADX INFO: renamed from: f */
    public C0084p m125f(int i) throws IOException {
        if (i < 32) {
            this.f163b.write((byte) (i | 160));
        } else if (i < 65536) {
            this.f162a[0] = -38;
            this.f162a[1] = (byte) (i >> 8);
            this.f162a[2] = (byte) (i >> 0);
            this.f163b.write(this.f162a, 0, 3);
        } else {
            this.f162a[0] = -37;
            this.f162a[1] = (byte) (i >> 24);
            this.f162a[2] = (byte) (i >> 16);
            this.f162a[3] = (byte) (i >> 8);
            this.f162a[4] = (byte) (i >> 0);
            this.f163b.write(this.f162a, 0, 5);
        }
        return this;
    }
}
