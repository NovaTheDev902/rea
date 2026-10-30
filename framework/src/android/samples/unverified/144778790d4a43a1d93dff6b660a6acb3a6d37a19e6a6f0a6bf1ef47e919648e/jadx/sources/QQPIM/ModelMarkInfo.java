package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class ModelMarkInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static Mobile f451a;

    /* JADX INFO: renamed from: b */
    static ArrayList<Mark> f452b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f453c;
    public int mark;
    public ArrayList<Mark> marks;
    public Mobile mobile;

    static {
        f453c = !ModelMarkInfo.class.desiredAssertionStatus();
    }

    public ModelMarkInfo() {
        this.mobile = null;
        this.marks = null;
        this.mark = 0;
        this.mobile = this.mobile;
        this.marks = this.marks;
        this.mark = this.mark;
    }

    public ModelMarkInfo(Mobile mobile, ArrayList<Mark> arrayList, int i) {
        this.mobile = null;
        this.marks = null;
        this.mark = 0;
        this.mobile = mobile;
        this.marks = arrayList;
        this.mark = i;
    }

    public final String className() {
        return "QQPIM.ModelMarkInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f453c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.mobile, "mobile");
        jceDisplayer.display((Collection) this.marks, "marks");
        jceDisplayer.display(this.mark, "mark");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ModelMarkInfo modelMarkInfo = (ModelMarkInfo) obj;
        return JceUtil.equals(this.mobile, modelMarkInfo.mobile) && JceUtil.equals(this.marks, modelMarkInfo.marks) && JceUtil.equals(this.mark, modelMarkInfo.mark);
    }

    public final String fullClassName() {
        return "QQPIM.ModelMarkInfo";
    }

    public final int getMark() {
        return this.mark;
    }

    public final ArrayList<Mark> getMarks() {
        return this.marks;
    }

    public final Mobile getMobile() {
        return this.mobile;
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
        if (f451a == null) {
            f451a = new Mobile();
        }
        this.mobile = (Mobile) jceInputStream.read((JceStruct) f451a, 0, true);
        if (f452b == null) {
            f452b = new ArrayList<>();
            f452b.add(new Mark());
        }
        setMarks((ArrayList) jceInputStream.read(f452b, 1, true));
        setMark(jceInputStream.read(this.mark, 2, true));
    }

    public final void setMark(int i) {
        this.mark = i;
    }

    public final void setMarks(ArrayList<Mark> arrayList) {
        this.marks = arrayList;
    }

    public final void setMobile(Mobile mobile) {
        this.mobile = mobile;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.mobile, 0);
        jceOutputStream.write((Collection) this.marks, 1);
        jceOutputStream.write(this.mark, 2);
    }
}
