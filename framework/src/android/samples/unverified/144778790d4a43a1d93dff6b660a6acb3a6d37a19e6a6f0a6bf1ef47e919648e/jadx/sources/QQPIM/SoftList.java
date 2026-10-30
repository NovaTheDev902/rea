package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class SoftList extends JceStruct {

    /* JADX INFO: renamed from: a */
    static ArrayList<SoftElementInfo> f564a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f565b;
    public ArrayList<SoftElementInfo> vctSofts;

    static {
        f565b = !SoftList.class.desiredAssertionStatus();
    }

    public SoftList() {
        this.vctSofts = null;
        this.vctSofts = this.vctSofts;
    }

    public SoftList(ArrayList<SoftElementInfo> arrayList) {
        this.vctSofts = null;
        this.vctSofts = arrayList;
    }

    public final String className() {
        return "QQPIM.SoftList";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f565b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display((Collection) this.vctSofts, "vctSofts");
    }

    public final boolean equals(Object obj) {
        return JceUtil.equals(this.vctSofts, ((SoftList) obj).vctSofts);
    }

    public final ArrayList<SoftElementInfo> getVctSofts() {
        return this.vctSofts;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        if (f564a == null) {
            f564a = new ArrayList<>();
            f564a.add(new SoftElementInfo());
        }
        setVctSofts((ArrayList) jceInputStream.read(f564a, 0, true));
    }

    public final void setVctSofts(ArrayList<SoftElementInfo> arrayList) {
        this.vctSofts = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((Collection) this.vctSofts, 0);
    }
}
