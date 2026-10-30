package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class STQueryResult extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<STQueryInfo> f510a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f511b;
    public ArrayList<STQueryInfo> queryinfo;

    static {
        f511b = !STQueryResult.class.desiredAssertionStatus();
    }

    public STQueryResult() {
        this.queryinfo = null;
        this.queryinfo = this.queryinfo;
    }

    public STQueryResult(ArrayList<STQueryInfo> arrayList) {
        this.queryinfo = null;
        this.queryinfo = arrayList;
    }

    public final String className() {
        return "QQPIM.STQueryResult";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f511b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display((Collection) this.queryinfo, "queryinfo");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.queryinfo, ((STQueryResult) obj).queryinfo);
    }

    public final String fullClassName() {
        return "QQPIM.STQueryResult";
    }

    public final ArrayList<STQueryInfo> getQueryinfo() {
        return this.queryinfo;
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
        if (f510a == null) {
            f510a = new ArrayList<>();
            f510a.add(new STQueryInfo());
        }
        setQueryinfo((ArrayList) jceInputStream.read(f510a, 0, false));
    }

    public final void setQueryinfo(ArrayList<STQueryInfo> arrayList) {
        this.queryinfo = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        if (this.queryinfo != null) {
            jceOutputStream.write((Collection) this.queryinfo, 0);
        }
    }
}
