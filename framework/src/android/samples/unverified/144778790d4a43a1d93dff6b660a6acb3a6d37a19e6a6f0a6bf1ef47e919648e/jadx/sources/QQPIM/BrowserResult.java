package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class BrowserResult extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f81a;
    public String checkAdvise;
    public String checkDesc;
    public int safeType;

    static {
        f81a = !BrowserResult.class.desiredAssertionStatus();
    }

    public BrowserResult() {
        this.safeType = 0;
        this.checkDesc = "";
        this.checkAdvise = "";
        this.safeType = this.safeType;
        this.checkDesc = this.checkDesc;
        this.checkAdvise = this.checkAdvise;
    }

    public BrowserResult(int i, String str, String str2) {
        this.safeType = 0;
        this.checkDesc = "";
        this.checkAdvise = "";
        this.safeType = i;
        this.checkDesc = str;
        this.checkAdvise = str2;
    }

    public final String className() {
        return "QQPIM.BrowserResult";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f81a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.safeType, "safeType");
        jceDisplayer.display(this.checkDesc, "checkDesc");
        jceDisplayer.display(this.checkAdvise, "checkAdvise");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        BrowserResult browserResult = (BrowserResult) obj;
        return JceUtil.equals(this.safeType, browserResult.safeType) && JceUtil.equals(this.checkDesc, browserResult.checkDesc) && JceUtil.equals(this.checkAdvise, browserResult.checkAdvise);
    }

    public final String fullClassName() {
        return "QQPIM.BrowserResult";
    }

    public final String getCheckAdvise() {
        return this.checkAdvise;
    }

    public final String getCheckDesc() {
        return this.checkDesc;
    }

    public final int getSafeType() {
        return this.safeType;
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
        this.safeType = jceInputStream.read(this.safeType, 0, true);
        this.checkDesc = jceInputStream.readString(1, false);
        this.checkAdvise = jceInputStream.readString(2, false);
    }

    public final void setCheckAdvise(String str) {
        this.checkAdvise = str;
    }

    public final void setCheckDesc(String str) {
        this.checkDesc = str;
    }

    public final void setSafeType(int i) {
        this.safeType = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.safeType, 0);
        if (this.checkDesc != null) {
            jceOutputStream.write(this.checkDesc, 1);
        }
        if (this.checkAdvise != null) {
            jceOutputStream.write(this.checkAdvise, 2);
        }
    }
}
