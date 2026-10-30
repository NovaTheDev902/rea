package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class HotWordResInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<HotwordInfo> f418a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f419b;
    public ArrayList<HotwordInfo> hotwords;
    public int totalnum;

    static {
        f419b = !HotWordResInfo.class.desiredAssertionStatus();
    }

    public HotWordResInfo() {
        this.totalnum = 0;
        this.hotwords = null;
        this.totalnum = this.totalnum;
        this.hotwords = this.hotwords;
    }

    public HotWordResInfo(int i, ArrayList<HotwordInfo> arrayList) {
        this.totalnum = 0;
        this.hotwords = null;
        this.totalnum = i;
        this.hotwords = arrayList;
    }

    public final String className() {
        return "QQPIM.HotWordResInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f419b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.totalnum, "totalnum");
        jceDisplayer.display((Collection) this.hotwords, "hotwords");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        HotWordResInfo hotWordResInfo = (HotWordResInfo) obj;
        return JceUtil.equals(this.totalnum, hotWordResInfo.totalnum) && JceUtil.equals(this.hotwords, hotWordResInfo.hotwords);
    }

    public final String fullClassName() {
        return "QQPIM.HotWordResInfo";
    }

    public final ArrayList<HotwordInfo> getHotwords() {
        return this.hotwords;
    }

    public final int getTotalnum() {
        return this.totalnum;
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
        this.totalnum = jceInputStream.read(this.totalnum, 0, true);
        if (f418a == null) {
            f418a = new ArrayList<>();
            f418a.add(new HotwordInfo());
        }
        setHotwords((ArrayList) jceInputStream.read(f418a, 1, true));
    }

    public final void setHotwords(ArrayList<HotwordInfo> arrayList) {
        this.hotwords = arrayList;
    }

    public final void setTotalnum(int i) {
        this.totalnum = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.totalnum, 0);
        jceOutputStream.write((Collection) this.hotwords, 1);
    }
}
