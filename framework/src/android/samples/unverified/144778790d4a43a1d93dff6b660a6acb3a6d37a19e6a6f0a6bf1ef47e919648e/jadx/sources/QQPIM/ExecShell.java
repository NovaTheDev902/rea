package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ExecShell extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f397a;
    public String shellcmd;

    static {
        f397a = !ExecShell.class.desiredAssertionStatus();
    }

    public ExecShell() {
        this.shellcmd = "";
        this.shellcmd = this.shellcmd;
    }

    public ExecShell(String str) {
        this.shellcmd = "";
        this.shellcmd = str;
    }

    public final String className() {
        return "QQPIM.ExecShell";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f397a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.shellcmd, "shellcmd");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.shellcmd, ((ExecShell) obj).shellcmd);
    }

    public final String fullClassName() {
        return "QQPIM.ExecShell";
    }

    public final String getShellcmd() {
        return this.shellcmd;
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
        this.shellcmd = jceInputStream.readString(0, true);
    }

    public final void setShellcmd(String str) {
        this.shellcmd = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.shellcmd, 0);
    }
}
