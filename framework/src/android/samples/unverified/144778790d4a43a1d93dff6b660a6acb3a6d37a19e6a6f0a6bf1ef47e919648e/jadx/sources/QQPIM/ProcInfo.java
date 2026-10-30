package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ProcInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f477a;
    public String desc;
    public String file;
    public String uid;

    static {
        f477a = !ProcInfo.class.desiredAssertionStatus();
    }

    public ProcInfo() {
        this.file = "";
        this.desc = "";
        this.uid = "";
        this.file = this.file;
        this.desc = this.desc;
        this.uid = this.uid;
    }

    public ProcInfo(String str, String str2, String str3) {
        this.file = "";
        this.desc = "";
        this.uid = "";
        this.file = str;
        this.desc = str2;
        this.uid = str3;
    }

    public final String className() {
        return "QQPIM.ProcInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f477a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.file, "file");
        jceDisplayer.display(this.desc, "desc");
        jceDisplayer.display(this.uid, "uid");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ProcInfo procInfo = (ProcInfo) obj;
        return JceUtil.equals(this.file, procInfo.file) && JceUtil.equals(this.desc, procInfo.desc) && JceUtil.equals(this.uid, procInfo.uid);
    }

    public final String fullClassName() {
        return "QQPIM.ProcInfo";
    }

    public final String getDesc() {
        return this.desc;
    }

    public final String getFile() {
        return this.file;
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
        this.file = jceInputStream.readString(0, true);
        this.desc = jceInputStream.readString(1, false);
        this.uid = jceInputStream.readString(2, false);
    }

    public final void setDesc(String str) {
        this.desc = str;
    }

    public final void setFile(String str) {
        this.file = str;
    }

    public final void setUid(String str) {
        this.uid = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.file, 0);
        if (this.desc != null) {
            jceOutputStream.write(this.desc, 1);
        }
        if (this.uid != null) {
            jceOutputStream.write(this.uid, 2);
        }
    }
}
