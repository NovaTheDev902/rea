package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class CloudCmd extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static byte[] f97a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f98b;
    public int cmdid;
    public byte[] param;
    public int seqid;

    static {
        f98b = !CloudCmd.class.desiredAssertionStatus();
    }

    public CloudCmd() {
        this.cmdid = 0;
        this.param = null;
        this.seqid = 0;
        this.cmdid = this.cmdid;
        this.param = this.param;
        this.seqid = this.seqid;
    }

    public CloudCmd(int i, byte[] bArr, int i2) {
        this.cmdid = 0;
        this.param = null;
        this.seqid = 0;
        this.cmdid = i;
        this.param = bArr;
        this.seqid = i2;
    }

    public final String className() {
        return "QQPIM.CloudCmd";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f98b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.cmdid, "cmdid");
        jceDisplayer.display(this.param, "param");
        jceDisplayer.display(this.seqid, "seqid");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        CloudCmd cloudCmd = (CloudCmd) obj;
        return JceUtil.equals(this.cmdid, cloudCmd.cmdid) && JceUtil.equals(this.param, cloudCmd.param) && JceUtil.equals(this.seqid, cloudCmd.seqid);
    }

    public final String fullClassName() {
        return "QQPIM.CloudCmd";
    }

    public final int getCmdid() {
        return this.cmdid;
    }

    public final byte[] getParam() {
        return this.param;
    }

    public final int getSeqid() {
        return this.seqid;
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
        this.cmdid = jceInputStream.read(this.cmdid, 0, true);
        if (f97a == null) {
            f97a = new byte[1];
            f97a[0] = 0;
        }
        this.param = jceInputStream.read(f97a, 1, true);
        this.seqid = jceInputStream.read(this.seqid, 2, true);
    }

    public final void setCmdid(int i) {
        this.cmdid = i;
    }

    public final void setParam(byte[] bArr) {
        this.param = bArr;
    }

    public final void setSeqid(int i) {
        this.seqid = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.cmdid, 0);
        jceOutputStream.write(this.param, 1);
        jceOutputStream.write(this.seqid, 2);
    }
}
