package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class PhoneInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<PhoneInfoItem> f470a;

    /* JADX INFO: renamed from: b */
    static ArrayList<Mark> f471b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f472c;
    public ArrayList<Mark> marks;
    public ArrayList<PhoneInfoItem> phoneinfoitems;

    static {
        f472c = !PhoneInfo.class.desiredAssertionStatus();
    }

    public PhoneInfo() {
        this.phoneinfoitems = null;
        this.marks = null;
        this.phoneinfoitems = this.phoneinfoitems;
        this.marks = this.marks;
    }

    public PhoneInfo(ArrayList<PhoneInfoItem> arrayList, ArrayList<Mark> arrayList2) {
        this.phoneinfoitems = null;
        this.marks = null;
        this.phoneinfoitems = arrayList;
        this.marks = arrayList2;
    }

    public final String className() {
        return "QQPIM.PhoneInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f472c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((Collection) this.phoneinfoitems, "phoneinfoitems");
        jceDisplayer.display((Collection) this.marks, "marks");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        PhoneInfo phoneInfo = (PhoneInfo) obj;
        return JceUtil.equals(this.phoneinfoitems, phoneInfo.phoneinfoitems) && JceUtil.equals(this.marks, phoneInfo.marks);
    }

    public final String fullClassName() {
        return "QQPIM.PhoneInfo";
    }

    public final ArrayList<Mark> getMarks() {
        return this.marks;
    }

    public final ArrayList<PhoneInfoItem> getPhoneinfoitems() {
        return this.phoneinfoitems;
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
        if (f470a == null) {
            f470a = new ArrayList<>();
            f470a.add(new PhoneInfoItem());
        }
        setPhoneinfoitems((ArrayList) jceInputStream.read(f470a, 0, false));
        if (f471b == null) {
            f471b = new ArrayList<>();
            f471b.add(new Mark());
        }
        setMarks((ArrayList) jceInputStream.read(f471b, 1, false));
    }

    public final void setMarks(ArrayList<Mark> arrayList) {
        this.marks = arrayList;
    }

    public final void setPhoneinfoitems(ArrayList<PhoneInfoItem> arrayList) {
        this.phoneinfoitems = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        if (this.phoneinfoitems != null) {
            jceOutputStream.write((Collection) this.phoneinfoitems, 0);
        }
        if (this.marks != null) {
            jceOutputStream.write((Collection) this.marks, 1);
        }
    }
}
