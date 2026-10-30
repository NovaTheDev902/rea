package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class Mark extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f441a;
    public int mark;
    public int markid;
    public int nrank;
    public int rank;

    static {
        f441a = !Mark.class.desiredAssertionStatus();
    }

    public Mark() {
        this.markid = 0;
        this.mark = 0;
        this.rank = 0;
        this.nrank = 0;
        this.markid = this.markid;
        this.mark = this.mark;
        this.rank = this.rank;
        this.nrank = this.nrank;
    }

    public Mark(int i, int i2, int i3, int i4) {
        this.markid = 0;
        this.mark = 0;
        this.rank = 0;
        this.nrank = 0;
        this.markid = i;
        this.mark = i2;
        this.rank = i3;
        this.nrank = i4;
    }

    public final String className() {
        return "QQPIM.Mark";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f441a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.markid, "markid");
        jceDisplayer.display(this.mark, "mark");
        jceDisplayer.display(this.rank, "rank");
        jceDisplayer.display(this.nrank, "nrank");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        Mark mark = (Mark) obj;
        return JceUtil.equals(this.markid, mark.markid) && JceUtil.equals(this.mark, mark.mark) && JceUtil.equals(this.rank, mark.rank) && JceUtil.equals(this.nrank, mark.nrank);
    }

    public final String fullClassName() {
        return "QQPIM.Mark";
    }

    public final int getMark() {
        return this.mark;
    }

    public final int getMarkid() {
        return this.markid;
    }

    public final int getNrank() {
        return this.nrank;
    }

    public final int getRank() {
        return this.rank;
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
        this.markid = jceInputStream.read(this.markid, 0, true);
        this.mark = jceInputStream.read(this.mark, 1, true);
        this.rank = jceInputStream.read(this.rank, 2, false);
        this.nrank = jceInputStream.read(this.nrank, 3, false);
    }

    public final void setMark(int i) {
        this.mark = i;
    }

    public final void setMarkid(int i) {
        this.markid = i;
    }

    public final void setNrank(int i) {
        this.nrank = i;
    }

    public final void setRank(int i) {
        this.rank = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.markid, 0);
        jceOutputStream.write(this.mark, 1);
        jceOutputStream.write(this.rank, 2);
        jceOutputStream.write(this.nrank, 3);
    }
}
