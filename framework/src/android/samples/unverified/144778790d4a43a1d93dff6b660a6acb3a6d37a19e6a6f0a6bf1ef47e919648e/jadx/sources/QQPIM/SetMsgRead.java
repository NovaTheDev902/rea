package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class SetMsgRead extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f541a;
    public byte issetread;

    static {
        f541a = !SetMsgRead.class.desiredAssertionStatus();
    }

    public SetMsgRead() {
        this.issetread = (byte) 0;
        this.issetread = this.issetread;
    }

    public SetMsgRead(byte b) {
        this.issetread = (byte) 0;
        this.issetread = b;
    }

    public final String className() {
        return "QQPIM.SetMsgRead";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f541a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.issetread, "issetread");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.issetread, ((SetMsgRead) obj).issetread);
    }

    public final String fullClassName() {
        return "QQPIM.SetMsgRead";
    }

    public final byte getIssetread() {
        return this.issetread;
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
        this.issetread = jceInputStream.read(this.issetread, 0, true);
    }

    public final void setIssetread(byte b) {
        this.issetread = b;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.issetread, 0);
    }
}
