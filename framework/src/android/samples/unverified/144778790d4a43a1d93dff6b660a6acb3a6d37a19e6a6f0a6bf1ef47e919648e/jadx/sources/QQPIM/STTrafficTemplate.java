package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class STTrafficTemplate extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<STMatchRule> f516a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f517b;
    public ArrayList<STMatchRule> matchRules;

    static {
        f517b = !STTrafficTemplate.class.desiredAssertionStatus();
    }

    public STTrafficTemplate() {
        this.matchRules = null;
        this.matchRules = this.matchRules;
    }

    public STTrafficTemplate(ArrayList<STMatchRule> arrayList) {
        this.matchRules = null;
        this.matchRules = arrayList;
    }

    public final String className() {
        return "QQPIM.STTrafficTemplate";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f517b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display((Collection) this.matchRules, "matchRules");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.matchRules, ((STTrafficTemplate) obj).matchRules);
    }

    public final String fullClassName() {
        return "QQPIM.STTrafficTemplate";
    }

    public final ArrayList<STMatchRule> getMatchRules() {
        return this.matchRules;
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
        if (f516a == null) {
            f516a = new ArrayList<>();
            f516a.add(new STMatchRule());
        }
        setMatchRules((ArrayList) jceInputStream.read(f516a, 0, false));
    }

    public final void setMatchRules(ArrayList<STMatchRule> arrayList) {
        this.matchRules = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        if (this.matchRules != null) {
            jceOutputStream.write((Collection) this.matchRules, 0);
        }
    }
}
