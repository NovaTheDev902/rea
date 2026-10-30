package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class uploadPacketInfoResp extends JceStruct {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f630a;
    public int is_succ;

    static {
        f630a = !uploadPacketInfoResp.class.desiredAssertionStatus();
    }

    public uploadPacketInfoResp() {
        this.is_succ = 0;
        this.is_succ = this.is_succ;
    }

    public uploadPacketInfoResp(int i) {
        this.is_succ = 0;
        this.is_succ = i;
    }

    public final String className() {
        return "QQPIM.uploadPacketInfoResp";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f630a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.is_succ, "is_succ");
    }

    public final boolean equals(Object obj) {
        return JceUtil.equals(this.is_succ, ((uploadPacketInfoResp) obj).is_succ);
    }

    public final int getIs_succ() {
        return this.is_succ;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.is_succ = jceInputStream.read(this.is_succ, 0, true);
    }

    public final void setIs_succ(int i) {
        this.is_succ = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.is_succ, 0);
    }
}
