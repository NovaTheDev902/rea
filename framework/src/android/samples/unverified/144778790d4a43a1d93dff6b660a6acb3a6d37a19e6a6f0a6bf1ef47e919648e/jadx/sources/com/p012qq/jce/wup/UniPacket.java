package com.p012qq.jce.wup;

import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceUtil;
import java.nio.ByteBuffer;
import java.util.HashMap;
import java.util.Map;
import puw.C1139e;

/* JADX INFO: loaded from: classes.dex */
public class UniPacket extends UniAttribute {

    /* JADX INFO: renamed from: c */
    static HashMap<String, byte[]> f5881c = null;

    /* JADX INFO: renamed from: e */
    static HashMap<String, HashMap<String, byte[]>> f5882e = null;

    /* JADX INFO: renamed from: a */
    protected C1139e f5883a = new C1139e();

    /* JADX INFO: renamed from: j */
    private int f5884j = 0;

    public UniPacket() {
        this.f5883a.f6797a = (short) 2;
    }

    public UniPacket(boolean z) {
        if (z) {
            useVersion3();
        } else {
            this.f5883a.f6797a = (short) 2;
        }
    }

    public byte[] createOldRespEncode() {
        JceOutputStream jceOutputStream = new JceOutputStream(0);
        jceOutputStream.setServerEncoding(this.f6810h);
        jceOutputStream.write((Map) this.f6808f, 0);
        byte[] jceBufArray = JceUtil.getJceBufArray(jceOutputStream.getByteBuffer());
        JceOutputStream jceOutputStream2 = new JceOutputStream(0);
        jceOutputStream2.setServerEncoding(this.f6810h);
        jceOutputStream2.write(this.f5883a.f6797a, 1);
        jceOutputStream2.write(this.f5883a.f6798b, 2);
        jceOutputStream2.write(this.f5883a.f6800d, 3);
        jceOutputStream2.write(this.f5883a.f6799c, 4);
        jceOutputStream2.write(this.f5884j, 5);
        jceOutputStream2.write(jceBufArray, 6);
        jceOutputStream2.write((Map) this.f5883a.f6806j, 7);
        return JceUtil.getJceBufArray(jceOutputStream2.getByteBuffer());
    }

    public UniPacket createResponse() {
        UniPacket uniPacket = new UniPacket();
        uniPacket.setRequestId(getRequestId());
        uniPacket.setServantName(getServantName());
        uniPacket.setFuncName(getFuncName());
        uniPacket.setEncodeName(this.f6810h);
        return uniPacket;
    }

    @Override // com.p012qq.jce.wup.UniAttribute, puw.C1140f
    public void decode(byte[] bArr) {
        if (bArr.length < 4) {
            throw new IllegalArgumentException("decode package must include size head");
        }
        try {
            JceInputStream jceInputStream = new JceInputStream(bArr, 4);
            jceInputStream.setServerEncoding(this.f6810h);
            readFrom(jceInputStream);
            if (this.f5883a.f6797a == 3) {
                JceInputStream jceInputStream2 = new JceInputStream(this.f5883a.f6803g);
                jceInputStream2.setServerEncoding(this.f6810h);
                if (f5881c == null) {
                    f5881c = new HashMap<>();
                    f5881c.put("", new byte[0]);
                }
                this.f5880d = jceInputStream2.readMap(f5881c, 0, false);
                return;
            }
            JceInputStream jceInputStream3 = new JceInputStream(this.f5883a.f6803g);
            jceInputStream3.setServerEncoding(this.f6810h);
            if (f5882e == null) {
                f5882e = new HashMap<>();
                HashMap<String, byte[]> map = new HashMap<>();
                map.put("", new byte[0]);
                f5882e.put("", map);
            }
            this.f6808f = jceInputStream3.readMap(f5882e, 0, false);
            this.f6809g = new HashMap<>();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override // com.p012qq.jce.wup.UniAttribute
    public void decodeVersion2(byte[] bArr) {
        if (bArr.length < 4) {
            throw new IllegalArgumentException("decode package must include size head");
        }
        try {
            JceInputStream jceInputStream = new JceInputStream(bArr, 4);
            jceInputStream.setServerEncoding(this.f6810h);
            readFrom(jceInputStream);
            JceInputStream jceInputStream2 = new JceInputStream(this.f5883a.f6803g);
            jceInputStream2.setServerEncoding(this.f6810h);
            if (f5882e == null) {
                f5882e = new HashMap<>();
                HashMap<String, byte[]> map = new HashMap<>();
                map.put("", new byte[0]);
                f5882e.put("", map);
            }
            this.f6808f = jceInputStream2.readMap(f5882e, 0, false);
            this.f6809g = new HashMap<>();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override // com.p012qq.jce.wup.UniAttribute
    public void decodeVersion3(byte[] bArr) {
        if (bArr.length < 4) {
            throw new IllegalArgumentException("decode package must include size head");
        }
        try {
            JceInputStream jceInputStream = new JceInputStream(bArr, 4);
            jceInputStream.setServerEncoding(this.f6810h);
            readFrom(jceInputStream);
            JceInputStream jceInputStream2 = new JceInputStream(this.f5883a.f6803g);
            jceInputStream2.setServerEncoding(this.f6810h);
            if (f5881c == null) {
                f5881c = new HashMap<>();
                f5881c.put("", new byte[0]);
            }
            this.f5880d = jceInputStream2.readMap(f5881c, 0, false);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public void display(StringBuilder sb, int i) {
        this.f5883a.display(sb, i);
    }

    @Override // com.p012qq.jce.wup.UniAttribute, puw.C1140f
    public byte[] encode() {
        if (this.f5883a.f6797a != 2) {
            if (this.f5883a.f6801e == null) {
                this.f5883a.f6801e = "";
            }
            if (this.f5883a.f6802f == null) {
                this.f5883a.f6802f = "";
            }
        } else {
            if (this.f5883a.f6801e.equals("")) {
                throw new IllegalArgumentException("servantName can not is null");
            }
            if (this.f5883a.f6802f.equals("")) {
                throw new IllegalArgumentException("funcName can not is null");
            }
        }
        JceOutputStream jceOutputStream = new JceOutputStream(0);
        jceOutputStream.setServerEncoding(this.f6810h);
        if (this.f5883a.f6797a == 2) {
            jceOutputStream.write((Map) this.f6808f, 0);
        } else {
            jceOutputStream.write((Map) this.f5880d, 0);
        }
        this.f5883a.f6803g = JceUtil.getJceBufArray(jceOutputStream.getByteBuffer());
        JceOutputStream jceOutputStream2 = new JceOutputStream(0);
        jceOutputStream2.setServerEncoding(this.f6810h);
        writeTo(jceOutputStream2);
        byte[] jceBufArray = JceUtil.getJceBufArray(jceOutputStream2.getByteBuffer());
        int length = jceBufArray.length;
        ByteBuffer byteBufferAllocate = ByteBuffer.allocate(length + 4);
        byteBufferAllocate.putInt(length + 4).put(jceBufArray).flip();
        return byteBufferAllocate.array();
    }

    public String getFuncName() {
        return this.f5883a.f6802f;
    }

    public int getOldRespIret() {
        return this.f5884j;
    }

    public int getRequestId() {
        return this.f5883a.f6800d;
    }

    public String getServantName() {
        return this.f5883a.f6801e;
    }

    @Override // com.p012qq.jce.wup.UniAttribute, puw.C1140f
    public <T> void put(String str, T t) {
        if (str.startsWith(".")) {
            throw new IllegalArgumentException("put name can not startwith . , now is " + str);
        }
        super.put(str, t);
    }

    public void readFrom(JceInputStream jceInputStream) {
        this.f5883a.readFrom(jceInputStream);
    }

    public void setFuncName(String str) {
        this.f5883a.f6802f = str;
    }

    public void setOldRespIret(int i) {
        this.f5884j = i;
    }

    public void setRequestId(int i) {
        this.f5883a.f6800d = i;
    }

    public void setServantName(String str) {
        this.f5883a.f6801e = str;
    }

    @Override // com.p012qq.jce.wup.UniAttribute
    public void useVersion3() {
        super.useVersion3();
        this.f5883a.f6797a = (short) 3;
    }

    public void writeTo(JceOutputStream jceOutputStream) {
        this.f5883a.writeTo(jceOutputStream);
    }
}
