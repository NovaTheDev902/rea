package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ChangeUrlResInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f89a;
    public String changeurl;

    static {
        f89a = !ChangeUrlResInfo.class.desiredAssertionStatus();
    }

    public ChangeUrlResInfo() {
        this.changeurl = "";
        this.changeurl = this.changeurl;
    }

    public ChangeUrlResInfo(String str) {
        this.changeurl = "";
        this.changeurl = str;
    }

    public final String className() {
        return "QQPIM.ChangeUrlResInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f89a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.changeurl, "changeurl");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.changeurl, ((ChangeUrlResInfo) obj).changeurl);
    }

    public final String fullClassName() {
        return "QQPIM.ChangeUrlResInfo";
    }

    public final String getChangeurl() {
        return this.changeurl;
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
        this.changeurl = jceInputStream.readString(0, true);
    }

    public final void setChangeurl(String str) {
        this.changeurl = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.changeurl, 0);
    }
}
