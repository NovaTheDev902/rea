package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class TopList extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<ModelMarkInfo> f588a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f589b;
    public ArrayList<ModelMarkInfo> markinfos;
    public int modelmarkid;

    static {
        f589b = !TopList.class.desiredAssertionStatus();
    }

    public TopList() {
        this.modelmarkid = 0;
        this.markinfos = null;
        this.modelmarkid = this.modelmarkid;
        this.markinfos = this.markinfos;
    }

    public TopList(int i, ArrayList<ModelMarkInfo> arrayList) {
        this.modelmarkid = 0;
        this.markinfos = null;
        this.modelmarkid = i;
        this.markinfos = arrayList;
    }

    public final String className() {
        return "QQPIM.TopList";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f589b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.modelmarkid, "modelmarkid");
        jceDisplayer.display((Collection) this.markinfos, "markinfos");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        TopList topList = (TopList) obj;
        return JceUtil.equals(this.modelmarkid, topList.modelmarkid) && JceUtil.equals(this.markinfos, topList.markinfos);
    }

    public final String fullClassName() {
        return "QQPIM.TopList";
    }

    public final ArrayList<ModelMarkInfo> getMarkinfos() {
        return this.markinfos;
    }

    public final int getModelmarkid() {
        return this.modelmarkid;
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
        this.modelmarkid = jceInputStream.read(this.modelmarkid, 0, true);
        if (f588a == null) {
            f588a = new ArrayList<>();
            f588a.add(new ModelMarkInfo());
        }
        setMarkinfos((ArrayList) jceInputStream.read(f588a, 1, true));
    }

    public final void setMarkinfos(ArrayList<ModelMarkInfo> arrayList) {
        this.markinfos = arrayList;
    }

    public final void setModelmarkid(int i) {
        this.modelmarkid = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.modelmarkid, 0);
        jceOutputStream.write((Collection) this.markinfos, 1);
    }
}
