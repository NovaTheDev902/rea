package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class SwitchSet extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f580a;
    public byte isopen;
    public int switchid;

    static {
        f580a = !SwitchSet.class.desiredAssertionStatus();
    }

    public SwitchSet() {
        this.switchid = 0;
        this.isopen = (byte) 0;
        this.switchid = this.switchid;
        this.isopen = this.isopen;
    }

    public SwitchSet(int i, byte b) {
        this.switchid = 0;
        this.isopen = (byte) 0;
        this.switchid = i;
        this.isopen = b;
    }

    public final String className() {
        return "QQPIM.SwitchSet";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f580a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.switchid, "switchid");
        jceDisplayer.display(this.isopen, "isopen");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        SwitchSet switchSet = (SwitchSet) obj;
        return JceUtil.equals(this.switchid, switchSet.switchid) && JceUtil.equals(this.isopen, switchSet.isopen);
    }

    public final String fullClassName() {
        return "QQPIM.SwitchSet";
    }

    public final byte getIsopen() {
        return this.isopen;
    }

    public final int getSwitchid() {
        return this.switchid;
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
        this.switchid = jceInputStream.read(this.switchid, 0, true);
        this.isopen = jceInputStream.read(this.isopen, 1, true);
    }

    public final void setIsopen(byte b) {
        this.isopen = b;
    }

    public final void setSwitchid(int i) {
        this.switchid = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.switchid, 0);
        jceOutputStream.write(this.isopen, 1);
    }
}
