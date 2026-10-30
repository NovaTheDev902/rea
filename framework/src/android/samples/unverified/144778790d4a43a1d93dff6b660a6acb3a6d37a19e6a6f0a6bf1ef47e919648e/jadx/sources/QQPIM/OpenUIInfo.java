package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class OpenUIInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f469a;
    public int uiid;

    static {
        f469a = !OpenUIInfo.class.desiredAssertionStatus();
    }

    public OpenUIInfo() {
        this.uiid = 0;
        this.uiid = this.uiid;
    }

    public OpenUIInfo(int i) {
        this.uiid = 0;
        this.uiid = i;
    }

    public final String className() {
        return "QQPIM.OpenUIInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f469a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.uiid, "uiid");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.uiid, ((OpenUIInfo) obj).uiid);
    }

    public final String fullClassName() {
        return "QQPIM.OpenUIInfo";
    }

    public final int getUiid() {
        return this.uiid;
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
        this.uiid = jceInputStream.read(this.uiid, 0, true);
    }

    public final void setUiid(int i) {
        this.uiid = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.uiid, 0);
    }
}
