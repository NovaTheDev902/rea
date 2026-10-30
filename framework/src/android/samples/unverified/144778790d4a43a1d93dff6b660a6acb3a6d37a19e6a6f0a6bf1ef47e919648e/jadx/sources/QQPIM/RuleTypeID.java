package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class RuleTypeID extends JceStruct {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f499a;
    public int ucRuleType;
    public int uiRuleID;

    static {
        f499a = !RuleTypeID.class.desiredAssertionStatus();
    }

    public RuleTypeID() {
        this.ucRuleType = 0;
        this.uiRuleID = 0;
        this.ucRuleType = this.ucRuleType;
        this.uiRuleID = this.uiRuleID;
    }

    public RuleTypeID(int i, int i2) {
        this.ucRuleType = 0;
        this.uiRuleID = 0;
        this.ucRuleType = i;
        this.uiRuleID = i2;
    }

    public final String className() {
        return "QQPIM.RuleTypeID";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f499a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.ucRuleType, "ucRuleType");
        jceDisplayer.display(this.uiRuleID, "uiRuleID");
    }

    public final boolean equals(Object obj) {
        RuleTypeID ruleTypeID = (RuleTypeID) obj;
        return JceUtil.equals(this.ucRuleType, ruleTypeID.ucRuleType) && JceUtil.equals(this.uiRuleID, ruleTypeID.uiRuleID);
    }

    public final int getUcRuleType() {
        return this.ucRuleType;
    }

    public final int getUiRuleID() {
        return this.uiRuleID;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.ucRuleType = jceInputStream.read(this.ucRuleType, 0, true);
        this.uiRuleID = jceInputStream.read(this.uiRuleID, 1, true);
    }

    public final void setUcRuleType(int i) {
        this.ucRuleType = i;
    }

    public final void setUiRuleID(int i) {
        this.uiRuleID = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.ucRuleType, 0);
        jceOutputStream.write(this.uiRuleID, 1);
    }
}
