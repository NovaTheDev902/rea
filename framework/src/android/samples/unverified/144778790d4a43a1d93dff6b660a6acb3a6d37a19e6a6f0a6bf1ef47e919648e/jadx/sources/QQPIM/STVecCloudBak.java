package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class STVecCloudBak extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<STCloudOrderBak> f518a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f519b;
    public ArrayList<STCloudOrderBak> vecbak;

    static {
        f519b = !STVecCloudBak.class.desiredAssertionStatus();
    }

    public STVecCloudBak() {
        this.vecbak = null;
        this.vecbak = this.vecbak;
    }

    public STVecCloudBak(ArrayList<STCloudOrderBak> arrayList) {
        this.vecbak = null;
        this.vecbak = arrayList;
    }

    public final String className() {
        return "QQPIM.STVecCloudBak";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f519b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display((Collection) this.vecbak, "vecbak");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.vecbak, ((STVecCloudBak) obj).vecbak);
    }

    public final String fullClassName() {
        return "QQPIM.STVecCloudBak";
    }

    public final ArrayList<STCloudOrderBak> getVecbak() {
        return this.vecbak;
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
        if (f518a == null) {
            f518a = new ArrayList<>();
            f518a.add(new STCloudOrderBak());
        }
        setVecbak((ArrayList) jceInputStream.read(f518a, 0, false));
    }

    public final void setVecbak(ArrayList<STCloudOrderBak> arrayList) {
        this.vecbak = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        if (this.vecbak != null) {
            jceOutputStream.write((Collection) this.vecbak, 0);
        }
    }
}
