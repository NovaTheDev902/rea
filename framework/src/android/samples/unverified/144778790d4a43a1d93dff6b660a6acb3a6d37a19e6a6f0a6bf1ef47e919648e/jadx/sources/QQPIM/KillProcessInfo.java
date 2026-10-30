package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class KillProcessInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f424a;
    public String process;

    static {
        f424a = !KillProcessInfo.class.desiredAssertionStatus();
    }

    public KillProcessInfo() {
        this.process = "";
        this.process = this.process;
    }

    public KillProcessInfo(String str) {
        this.process = "";
        this.process = str;
    }

    public final String className() {
        return "QQPIM.KillProcessInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f424a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.process, "process");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.process, ((KillProcessInfo) obj).process);
    }

    public final String fullClassName() {
        return "QQPIM.KillProcessInfo";
    }

    public final String getProcess() {
        return this.process;
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
        this.process = jceInputStream.readString(0, true);
    }

    public final void setProcess(String str) {
        this.process = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.process, 0);
    }
}
