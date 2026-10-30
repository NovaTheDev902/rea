package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class STMatchRule extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f507a;
    public String postfix;
    public String prefix;
    public int type;
    public int unit;

    static {
        f507a = !STMatchRule.class.desiredAssertionStatus();
    }

    public STMatchRule() {
        this.unit = 0;
        this.type = 0;
        this.prefix = "";
        this.postfix = "";
        this.unit = this.unit;
        this.type = this.type;
        this.prefix = this.prefix;
        this.postfix = this.postfix;
    }

    public STMatchRule(int i, int i2, String str, String str2) {
        this.unit = 0;
        this.type = 0;
        this.prefix = "";
        this.postfix = "";
        this.unit = i;
        this.type = i2;
        this.prefix = str;
        this.postfix = str2;
    }

    public final String className() {
        return "QQPIM.STMatchRule";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f507a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.unit, "unit");
        jceDisplayer.display(this.type, "type");
        jceDisplayer.display(this.prefix, "prefix");
        jceDisplayer.display(this.postfix, "postfix");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        STMatchRule sTMatchRule = (STMatchRule) obj;
        return JceUtil.equals(this.unit, sTMatchRule.unit) && JceUtil.equals(this.type, sTMatchRule.type) && JceUtil.equals(this.prefix, sTMatchRule.prefix) && JceUtil.equals(this.postfix, sTMatchRule.postfix);
    }

    public final String fullClassName() {
        return "QQPIM.STMatchRule";
    }

    public final String getPostfix() {
        return this.postfix;
    }

    public final String getPrefix() {
        return this.prefix;
    }

    public final int getType() {
        return this.type;
    }

    public final int getUnit() {
        return this.unit;
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
        this.unit = jceInputStream.read(this.unit, 0, true);
        this.type = jceInputStream.read(this.type, 1, true);
        this.prefix = jceInputStream.readString(2, true);
        this.postfix = jceInputStream.readString(3, false);
    }

    public final void setPostfix(String str) {
        this.postfix = str;
    }

    public final void setPrefix(String str) {
        this.prefix = str;
    }

    public final void setType(int i) {
        this.type = i;
    }

    public final void setUnit(int i) {
        this.unit = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.unit, 0);
        jceOutputStream.write(this.type, 1);
        jceOutputStream.write(this.prefix, 2);
        if (this.postfix != null) {
            jceOutputStream.write(this.postfix, 3);
        }
    }
}
