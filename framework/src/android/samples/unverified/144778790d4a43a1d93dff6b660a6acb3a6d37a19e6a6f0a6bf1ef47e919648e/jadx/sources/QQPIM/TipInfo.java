package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class TipInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f583a;
    public String strTips;
    public String strTitle;

    static {
        f583a = !TipInfo.class.desiredAssertionStatus();
    }

    public TipInfo() {
        this.strTips = "";
        this.strTitle = "";
        this.strTips = this.strTips;
        this.strTitle = this.strTitle;
    }

    public TipInfo(String str, String str2) {
        this.strTips = "";
        this.strTitle = "";
        this.strTips = str;
        this.strTitle = str2;
    }

    public final String className() {
        return "QQPIM.TipInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f583a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.strTips, "strTips");
        jceDisplayer.display(this.strTitle, "strTitle");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        TipInfo tipInfo = (TipInfo) obj;
        return JceUtil.equals(this.strTips, tipInfo.strTips) && JceUtil.equals(this.strTitle, tipInfo.strTitle);
    }

    public final String fullClassName() {
        return "QQPIM.TipInfo";
    }

    public final String getStrTips() {
        return this.strTips;
    }

    public final String getStrTitle() {
        return this.strTitle;
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
        this.strTips = jceInputStream.readString(0, true);
        this.strTitle = jceInputStream.readString(1, false);
    }

    public final void setStrTips(String str) {
        this.strTips = str;
    }

    public final void setStrTitle(String str) {
        this.strTitle = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.strTips, 0);
        if (this.strTitle != null) {
            jceOutputStream.write(this.strTitle, 1);
        }
    }
}
