package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class SoftName extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f570a;
    public String softname;
    public String uid;

    static {
        f570a = !SoftName.class.desiredAssertionStatus();
    }

    public SoftName() {
        this.uid = "";
        this.softname = "";
        this.uid = this.uid;
        this.softname = this.softname;
    }

    public SoftName(String str, String str2) {
        this.uid = "";
        this.softname = "";
        this.uid = str;
        this.softname = str2;
    }

    public final String className() {
        return "QQPIM.SoftName";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f570a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.uid, "uid");
        jceDisplayer.display(this.softname, "softname");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        SoftName softName = (SoftName) obj;
        return JceUtil.equals(this.uid, softName.uid) && JceUtil.equals(this.softname, softName.softname);
    }

    public final String fullClassName() {
        return "QQPIM.SoftName";
    }

    public final String getSoftname() {
        return this.softname;
    }

    public final String getUid() {
        return this.uid;
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
        this.uid = jceInputStream.readString(0, true);
        this.softname = jceInputStream.readString(1, true);
    }

    public final void setSoftname(String str) {
        this.softname = str;
    }

    public final void setUid(String str) {
        this.uid = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.uid, 0);
        jceOutputStream.write(this.softname, 1);
    }
}
