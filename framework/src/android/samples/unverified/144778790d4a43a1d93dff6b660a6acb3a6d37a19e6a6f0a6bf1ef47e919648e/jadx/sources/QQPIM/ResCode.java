package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ResCode extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f492a;
    public int rescode;

    static {
        f492a = !ResCode.class.desiredAssertionStatus();
    }

    public ResCode() {
        this.rescode = 0;
        this.rescode = this.rescode;
    }

    public ResCode(int i) {
        this.rescode = 0;
        this.rescode = i;
    }

    public final String className() {
        return "QQPIM.ResCode";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f492a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.rescode, "rescode");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.rescode, ((ResCode) obj).rescode);
    }

    public final String fullClassName() {
        return "QQPIM.ResCode";
    }

    public final int getRescode() {
        return this.rescode;
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
        this.rescode = jceInputStream.read(this.rescode, 0, true);
    }

    public final void setRescode(int i) {
        this.rescode = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.rescode, 0);
    }
}
