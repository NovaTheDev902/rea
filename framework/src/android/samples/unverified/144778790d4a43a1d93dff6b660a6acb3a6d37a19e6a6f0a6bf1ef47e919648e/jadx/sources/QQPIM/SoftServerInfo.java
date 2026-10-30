package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import com.tencent.tmsecure.module.market.MarketManager;

/* JADX INFO: loaded from: classes.dex */
public final class SoftServerInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static byte[] f572a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f573b;
    public byte[] expand;
    public int status;

    static {
        f573b = !SoftServerInfo.class.desiredAssertionStatus();
    }

    public SoftServerInfo() {
        this.status = 0;
        this.expand = null;
        this.status = this.status;
        this.expand = this.expand;
    }

    public SoftServerInfo(int i, byte[] bArr) {
        this.status = 0;
        this.expand = null;
        this.status = i;
        this.expand = bArr;
    }

    public final String className() {
        return "QQPIM.SoftServerInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f573b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.status, "status");
        jceDisplayer.display(this.expand, MarketManager.JCE_EXPAND_KEY);
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        SoftServerInfo softServerInfo = (SoftServerInfo) obj;
        return JceUtil.equals(this.status, softServerInfo.status) && JceUtil.equals(this.expand, softServerInfo.expand);
    }

    public final String fullClassName() {
        return "QQPIM.SoftServerInfo";
    }

    public final byte[] getExpand() {
        return this.expand;
    }

    public final int getStatus() {
        return this.status;
    }

    public final int hashCode() {
        try {
            throw new Exception("Need define key first!");
        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.status = jceInputStream.read(this.status, 0, true);
        if (f572a == null) {
            f572a = new byte[1];
            f572a[0] = 0;
        }
        this.expand = jceInputStream.read(f572a, 1, false);
    }

    public final void setExpand(byte[] bArr) {
        this.expand = bArr;
    }

    public final void setStatus(int i) {
        this.status = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.status, 0);
        if (this.expand != null) {
            jceOutputStream.write(this.expand, 1);
        }
    }
}
