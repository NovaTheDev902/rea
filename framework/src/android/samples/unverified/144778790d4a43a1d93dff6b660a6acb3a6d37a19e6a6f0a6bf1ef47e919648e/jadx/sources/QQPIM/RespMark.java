package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class RespMark extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<Mark> f493a;

    /* JADX INFO: renamed from: b */
    static ArrayList<TopList> f494b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f495c;
    public ArrayList<Mark> marks;
    public ArrayList<TopList> toplists;

    static {
        f495c = !RespMark.class.desiredAssertionStatus();
    }

    public RespMark() {
        this.marks = null;
        this.toplists = null;
        this.marks = this.marks;
        this.toplists = this.toplists;
    }

    public RespMark(ArrayList<Mark> arrayList, ArrayList<TopList> arrayList2) {
        this.marks = null;
        this.toplists = null;
        this.marks = arrayList;
        this.toplists = arrayList2;
    }

    public final String className() {
        return "QQPIM.RespMark";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f495c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((Collection) this.marks, "marks");
        jceDisplayer.display((Collection) this.toplists, "toplists");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        RespMark respMark = (RespMark) obj;
        return JceUtil.equals(this.marks, respMark.marks) && JceUtil.equals(this.toplists, respMark.toplists);
    }

    public final String fullClassName() {
        return "QQPIM.RespMark";
    }

    public final ArrayList<Mark> getMarks() {
        return this.marks;
    }

    public final ArrayList<TopList> getToplists() {
        return this.toplists;
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
        if (f493a == null) {
            f493a = new ArrayList<>();
            f493a.add(new Mark());
        }
        setMarks((ArrayList) jceInputStream.read(f493a, 0, true));
        if (f494b == null) {
            f494b = new ArrayList<>();
            f494b.add(new TopList());
        }
        setToplists((ArrayList) jceInputStream.read(f494b, 1, true));
    }

    public final void setMarks(ArrayList<Mark> arrayList) {
        this.marks = arrayList;
    }

    public final void setToplists(ArrayList<TopList> arrayList) {
        this.toplists = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((Collection) this.marks, 0);
        jceOutputStream.write((Collection) this.toplists, 1);
    }
}
