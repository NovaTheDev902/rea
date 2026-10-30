package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class SoftAction extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static FeatureKey f546a;

    /* JADX INFO: renamed from: b */
    static ArrayList<ActionItem> f547b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f548c;
    public FeatureKey featurekey;
    public ArrayList<ActionItem> vecaction;

    static {
        f548c = !SoftAction.class.desiredAssertionStatus();
    }

    public SoftAction() {
        this.featurekey = null;
        this.vecaction = null;
        this.featurekey = this.featurekey;
        this.vecaction = this.vecaction;
    }

    public SoftAction(FeatureKey featureKey, ArrayList<ActionItem> arrayList) {
        this.featurekey = null;
        this.vecaction = null;
        this.featurekey = featureKey;
        this.vecaction = arrayList;
    }

    public final String className() {
        return "QQPIM.SoftAction";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f548c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.featurekey, "featurekey");
        jceDisplayer.display((Collection) this.vecaction, "vecaction");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        SoftAction softAction = (SoftAction) obj;
        return JceUtil.equals(this.featurekey, softAction.featurekey) && JceUtil.equals(this.vecaction, softAction.vecaction);
    }

    public final String fullClassName() {
        return "QQPIM.SoftAction";
    }

    public final FeatureKey getFeaturekey() {
        return this.featurekey;
    }

    public final ArrayList<ActionItem> getVecaction() {
        return this.vecaction;
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
        if (f546a == null) {
            f546a = new FeatureKey();
        }
        this.featurekey = (FeatureKey) jceInputStream.read((JceStruct) f546a, 0, true);
        if (f547b == null) {
            f547b = new ArrayList<>();
            f547b.add(new ActionItem());
        }
        setVecaction((ArrayList) jceInputStream.read(f547b, 1, true));
    }

    public final void setFeaturekey(FeatureKey featureKey) {
        this.featurekey = featureKey;
    }

    public final void setVecaction(ArrayList<ActionItem> arrayList) {
        this.vecaction = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.featurekey, 0);
        jceOutputStream.write((Collection) this.vecaction, 1);
    }
}
