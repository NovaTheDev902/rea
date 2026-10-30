package puw;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.HashMap;
import java.util.Map;

/* JADX INFO: renamed from: puw.e */
/* JADX INFO: loaded from: classes.dex */
public final class C1139e extends JceStruct {

    /* JADX INFO: renamed from: k */
    static byte[] f6794k;

    /* JADX INFO: renamed from: l */
    static Map<String, String> f6795l;

    /* JADX INFO: renamed from: m */
    static final /* synthetic */ boolean f6796m;

    /* JADX INFO: renamed from: g */
    public byte[] f6803g;

    /* JADX INFO: renamed from: i */
    public Map<String, String> f6805i;

    /* JADX INFO: renamed from: j */
    public Map<String, String> f6806j;

    /* JADX INFO: renamed from: a */
    public short f6797a = 0;

    /* JADX INFO: renamed from: b */
    public byte f6798b = 0;

    /* JADX INFO: renamed from: c */
    public int f6799c = 0;

    /* JADX INFO: renamed from: d */
    public int f6800d = 0;

    /* JADX INFO: renamed from: e */
    public String f6801e = null;

    /* JADX INFO: renamed from: f */
    public String f6802f = null;

    /* JADX INFO: renamed from: h */
    public int f6804h = 0;

    static {
        f6796m = !C1139e.class.desiredAssertionStatus();
        f6794k = null;
        f6795l = null;
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f6796m) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.f6797a, "iVersion");
        jceDisplayer.display(this.f6798b, "cPacketType");
        jceDisplayer.display(this.f6799c, "iMessageType");
        jceDisplayer.display(this.f6800d, "iRequestId");
        jceDisplayer.display(this.f6801e, "sServantName");
        jceDisplayer.display(this.f6802f, "sFuncName");
        jceDisplayer.display(this.f6803g, "sBuffer");
        jceDisplayer.display(this.f6804h, "iTimeout");
        jceDisplayer.display((Map) this.f6805i, "context");
        jceDisplayer.display((Map) this.f6806j, "status");
    }

    public final boolean equals(Object obj) {
        C1139e c1139e = (C1139e) obj;
        return JceUtil.equals(1, (int) c1139e.f6797a) && JceUtil.equals(1, (int) c1139e.f6798b) && JceUtil.equals(1, c1139e.f6799c) && JceUtil.equals(1, c1139e.f6800d) && JceUtil.equals((Object) 1, (Object) c1139e.f6801e) && JceUtil.equals((Object) 1, (Object) c1139e.f6802f) && JceUtil.equals((Object) 1, (Object) c1139e.f6803g) && JceUtil.equals(1, c1139e.f6804h) && JceUtil.equals((Object) 1, (Object) c1139e.f6805i) && JceUtil.equals((Object) 1, (Object) c1139e.f6806j);
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        try {
            this.f6797a = jceInputStream.read(this.f6797a, 1, true);
            this.f6798b = jceInputStream.read(this.f6798b, 2, true);
            this.f6799c = jceInputStream.read(this.f6799c, 3, true);
            this.f6800d = jceInputStream.read(this.f6800d, 4, true);
            this.f6801e = jceInputStream.readString(5, true);
            this.f6802f = jceInputStream.readString(6, true);
            if (f6794k == null) {
                f6794k = new byte[]{0};
            }
            this.f6803g = jceInputStream.read(f6794k, 7, true);
            this.f6804h = jceInputStream.read(this.f6804h, 8, true);
            if (f6795l == null) {
                f6795l = new HashMap();
                f6795l.put("", "");
            }
            this.f6805i = (Map) jceInputStream.read(f6795l, 9, true);
            if (f6795l == null) {
                f6795l = new HashMap();
                f6795l.put("", "");
            }
            this.f6806j = (Map) jceInputStream.read(f6795l, 10, true);
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("RequestPacket decode error " + C1136b.m2856a(this.f6803g));
            throw new RuntimeException(e);
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.f6797a, 1);
        jceOutputStream.write(this.f6798b, 2);
        jceOutputStream.write(this.f6799c, 3);
        jceOutputStream.write(this.f6800d, 4);
        jceOutputStream.write(this.f6801e, 5);
        jceOutputStream.write(this.f6802f, 6);
        jceOutputStream.write(this.f6803g, 7);
        jceOutputStream.write(this.f6804h, 8);
        jceOutputStream.write((Map) this.f6805i, 9);
        jceOutputStream.write((Map) this.f6806j, 10);
    }
}
