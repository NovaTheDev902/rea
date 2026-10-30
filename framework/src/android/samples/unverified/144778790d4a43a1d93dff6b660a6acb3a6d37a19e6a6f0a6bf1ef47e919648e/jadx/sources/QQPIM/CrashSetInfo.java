package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class CrashSetInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f121a;
    public int crashdata;
    public int uploadtype;

    static {
        f121a = !CrashSetInfo.class.desiredAssertionStatus();
    }

    public CrashSetInfo() {
        this.uploadtype = 0;
        this.crashdata = 0;
        this.uploadtype = this.uploadtype;
        this.crashdata = this.crashdata;
    }

    public CrashSetInfo(int i, int i2) {
        this.uploadtype = 0;
        this.crashdata = 0;
        this.uploadtype = i;
        this.crashdata = i2;
    }

    public final String className() {
        return "QQPIM.CrashSetInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f121a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.uploadtype, "uploadtype");
        jceDisplayer.display(this.crashdata, "crashdata");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        CrashSetInfo crashSetInfo = (CrashSetInfo) obj;
        return JceUtil.equals(this.uploadtype, crashSetInfo.uploadtype) && JceUtil.equals(this.crashdata, crashSetInfo.crashdata);
    }

    public final String fullClassName() {
        return "QQPIM.CrashSetInfo";
    }

    public final int getCrashdata() {
        return this.crashdata;
    }

    public final int getUploadtype() {
        return this.uploadtype;
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
        this.uploadtype = jceInputStream.read(this.uploadtype, 0, true);
        this.crashdata = jceInputStream.read(this.crashdata, 1, true);
    }

    public final void setCrashdata(int i) {
        this.crashdata = i;
    }

    public final void setUploadtype(int i) {
        this.uploadtype = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.uploadtype, 0);
        jceOutputStream.write(this.crashdata, 1);
    }
}
