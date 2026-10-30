package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class STReportBack extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f512a;
    public int nreserve;

    static {
        f512a = !STReportBack.class.desiredAssertionStatus();
    }

    public STReportBack() {
        this.nreserve = 0;
        this.nreserve = this.nreserve;
    }

    public STReportBack(int i) {
        this.nreserve = 0;
        this.nreserve = i;
    }

    public final String className() {
        return "QQPIM.STReportBack";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f512a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.nreserve, "nreserve");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.nreserve, ((STReportBack) obj).nreserve);
    }

    public final String fullClassName() {
        return "QQPIM.STReportBack";
    }

    public final int getNreserve() {
        return this.nreserve;
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
        this.nreserve = jceInputStream.read(this.nreserve, 0, false);
    }

    public final void setNreserve(int i) {
        this.nreserve = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.nreserve, 0);
    }
}
