package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class CmdInfoRes extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<CloudInfoRes> f109a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f110b;
    public ArrayList<CloudInfoRes> infores;

    static {
        f110b = !CmdInfoRes.class.desiredAssertionStatus();
    }

    public CmdInfoRes() {
        this.infores = null;
        this.infores = this.infores;
    }

    public CmdInfoRes(ArrayList<CloudInfoRes> arrayList) {
        this.infores = null;
        this.infores = arrayList;
    }

    public final String className() {
        return "QQPIM.CmdInfoRes";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f110b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display((Collection) this.infores, "infores");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.infores, ((CmdInfoRes) obj).infores);
    }

    public final String fullClassName() {
        return "QQPIM.CmdInfoRes";
    }

    public final ArrayList<CloudInfoRes> getInfores() {
        return this.infores;
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
        if (f109a == null) {
            f109a = new ArrayList<>();
            f109a.add(new CloudInfoRes());
        }
        setInfores((ArrayList) jceInputStream.read(f109a, 1, true));
    }

    public final void setInfores(ArrayList<CloudInfoRes> arrayList) {
        this.infores = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((Collection) this.infores, 1);
    }
}
