package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class VECReportError extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<STReportError> f619a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f620b;
    public ArrayList<STReportError> queryinfo;

    static {
        f620b = !VECReportError.class.desiredAssertionStatus();
    }

    public VECReportError() {
        this.queryinfo = null;
        this.queryinfo = this.queryinfo;
    }

    public VECReportError(ArrayList<STReportError> arrayList) {
        this.queryinfo = null;
        this.queryinfo = arrayList;
    }

    public final String className() {
        return "QQPIM.VECReportError";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f620b) {
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
        return JceUtil.equals(this.queryinfo, ((VECReportError) obj).queryinfo);
    }

    public final String fullClassName() {
        return "QQPIM.VECReportError";
    }

    public final ArrayList<STReportError> getQueryinfo() {
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
        if (f619a == null) {
            f619a = new ArrayList<>();
            f619a.add(new STReportError());
        }
        setQueryinfo((ArrayList) jceInputStream.read(f619a, 0, true));
    }

    public final void setQueryinfo(ArrayList<STReportError> arrayList) {
        this.queryinfo = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((Collection) this.queryinfo, 0);
    }
}
