package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class MalSoftType extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static SoftKey f439a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f440b;
    public int malsofttype;
    public SoftKey softkey;

    static {
        f440b = !MalSoftType.class.desiredAssertionStatus();
    }

    public MalSoftType() {
        this.softkey = null;
        this.malsofttype = 0;
        this.softkey = this.softkey;
        this.malsofttype = this.malsofttype;
    }

    public MalSoftType(SoftKey softKey, int i) {
        this.softkey = null;
        this.malsofttype = 0;
        this.softkey = softKey;
        this.malsofttype = i;
    }

    public final String className() {
        return "QQPIM.MalSoftType";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f440b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.softkey, "softkey");
        jceDisplayer.display(this.malsofttype, "malsofttype");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        MalSoftType malSoftType = (MalSoftType) obj;
        return JceUtil.equals(this.softkey, malSoftType.softkey) && JceUtil.equals(this.malsofttype, malSoftType.malsofttype);
    }

    public final String fullClassName() {
        return "QQPIM.MalSoftType";
    }

    public final int getMalsofttype() {
        return this.malsofttype;
    }

    public final SoftKey getSoftkey() {
        return this.softkey;
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
        if (f439a == null) {
            f439a = new SoftKey();
        }
        this.softkey = (SoftKey) jceInputStream.read((JceStruct) f439a, 0, true);
        this.malsofttype = jceInputStream.read(this.malsofttype, 1, true);
    }

    public final void setMalsofttype(int i) {
        this.malsofttype = i;
    }

    public final void setSoftkey(SoftKey softKey) {
        this.softkey = softKey;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.softkey, 0);
        jceOutputStream.write(this.malsofttype, 1);
    }
}
