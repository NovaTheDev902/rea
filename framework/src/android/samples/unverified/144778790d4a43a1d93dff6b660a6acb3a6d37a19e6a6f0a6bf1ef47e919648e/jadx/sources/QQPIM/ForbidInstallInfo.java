package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ForbidInstallInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f413a;
    public int option;
    public String uid;

    static {
        f413a = !ForbidInstallInfo.class.desiredAssertionStatus();
    }

    public ForbidInstallInfo() {
        this.option = 0;
        this.uid = "";
        this.option = this.option;
        this.uid = this.uid;
    }

    public ForbidInstallInfo(int i, String str) {
        this.option = 0;
        this.uid = "";
        this.option = i;
        this.uid = str;
    }

    public final String className() {
        return "QQPIM.ForbidInstallInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f413a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.option, "option");
        jceDisplayer.display(this.uid, "uid");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ForbidInstallInfo forbidInstallInfo = (ForbidInstallInfo) obj;
        return JceUtil.equals(this.option, forbidInstallInfo.option) && JceUtil.equals(this.uid, forbidInstallInfo.uid);
    }

    public final String fullClassName() {
        return "QQPIM.ForbidInstallInfo";
    }

    public final int getOption() {
        return this.option;
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
        this.option = jceInputStream.read(this.option, 0, true);
        this.uid = jceInputStream.readString(1, true);
    }

    public final void setOption(int i) {
        this.option = i;
    }

    public final void setUid(String str) {
        this.uid = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.option, 0);
        jceOutputStream.write(this.uid, 1);
    }
}
