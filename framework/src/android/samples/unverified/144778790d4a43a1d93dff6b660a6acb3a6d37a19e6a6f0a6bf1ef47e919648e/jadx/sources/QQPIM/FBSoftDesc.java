package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class FBSoftDesc extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static SoftKey f406a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f407b;
    public String desc;
    public SoftKey softkey;

    static {
        f407b = !FBSoftDesc.class.desiredAssertionStatus();
    }

    public FBSoftDesc() {
        this.softkey = null;
        this.desc = "";
        this.softkey = this.softkey;
        this.desc = this.desc;
    }

    public FBSoftDesc(SoftKey softKey, String str) {
        this.softkey = null;
        this.desc = "";
        this.softkey = softKey;
        this.desc = str;
    }

    public final String className() {
        return "QQPIM.FBSoftDesc";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f407b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.softkey, "softkey");
        jceDisplayer.display(this.desc, "desc");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        FBSoftDesc fBSoftDesc = (FBSoftDesc) obj;
        return JceUtil.equals(this.softkey, fBSoftDesc.softkey) && JceUtil.equals(this.desc, fBSoftDesc.desc);
    }

    public final String fullClassName() {
        return "QQPIM.FBSoftDesc";
    }

    public final String getDesc() {
        return this.desc;
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
        if (f406a == null) {
            f406a = new SoftKey();
        }
        this.softkey = (SoftKey) jceInputStream.read((JceStruct) f406a, 0, true);
        this.desc = jceInputStream.readString(1, true);
    }

    public final void setDesc(String str) {
        this.desc = str;
    }

    public final void setSoftkey(SoftKey softKey) {
        this.softkey = softKey;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.softkey, 0);
        jceOutputStream.write(this.desc, 1);
    }
}
