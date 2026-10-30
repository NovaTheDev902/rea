package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class SoftActionConfig extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static FeatureKey f549a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f550b;
    public int actionLevel;
    public FeatureKey featureKey;

    static {
        f550b = !SoftActionConfig.class.desiredAssertionStatus();
    }

    public SoftActionConfig() {
        this.featureKey = null;
        this.actionLevel = 0;
        this.featureKey = this.featureKey;
        this.actionLevel = this.actionLevel;
    }

    public SoftActionConfig(FeatureKey featureKey, int i) {
        this.featureKey = null;
        this.actionLevel = 0;
        this.featureKey = featureKey;
        this.actionLevel = i;
    }

    public final String className() {
        return "QQPIM.SoftActionConfig";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f550b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.featureKey, "featureKey");
        jceDisplayer.display(this.actionLevel, "actionLevel");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        SoftActionConfig softActionConfig = (SoftActionConfig) obj;
        return JceUtil.equals(this.featureKey, softActionConfig.featureKey) && JceUtil.equals(this.actionLevel, softActionConfig.actionLevel);
    }

    public final String fullClassName() {
        return "QQPIM.SoftActionConfig";
    }

    public final int getActionLevel() {
        return this.actionLevel;
    }

    public final FeatureKey getFeatureKey() {
        return this.featureKey;
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
        if (f549a == null) {
            f549a = new FeatureKey();
        }
        this.featureKey = (FeatureKey) jceInputStream.read((JceStruct) f549a, 0, true);
        this.actionLevel = jceInputStream.read(this.actionLevel, 1, false);
    }

    public final void setActionLevel(int i) {
        this.actionLevel = i;
    }

    public final void setFeatureKey(FeatureKey featureKey) {
        this.featureKey = featureKey;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.featureKey, 0);
        jceOutputStream.write(this.actionLevel, 1);
    }
}
