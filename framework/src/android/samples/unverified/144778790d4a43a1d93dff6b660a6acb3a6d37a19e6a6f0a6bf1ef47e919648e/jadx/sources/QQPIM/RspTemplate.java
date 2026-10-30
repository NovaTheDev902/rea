package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class RspTemplate extends JceStruct {

    /* JADX INFO: renamed from: a */
    static ArrayList<UrlCheckResponse> f497a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f498b;
    public ArrayList<UrlCheckResponse> rspTemp;

    static {
        f498b = !RspTemplate.class.desiredAssertionStatus();
    }

    public RspTemplate() {
        this.rspTemp = null;
        this.rspTemp = this.rspTemp;
    }

    public RspTemplate(ArrayList<UrlCheckResponse> arrayList) {
        this.rspTemp = null;
        this.rspTemp = arrayList;
    }

    public final String className() {
        return "QQPIM.RspTemplate";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f498b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display((Collection) this.rspTemp, "rspTemp");
    }

    public final boolean equals(Object obj) {
        return JceUtil.equals(this.rspTemp, ((RspTemplate) obj).rspTemp);
    }

    public final ArrayList<UrlCheckResponse> getRspTemp() {
        return this.rspTemp;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        if (f497a == null) {
            f497a = new ArrayList<>();
            f497a.add(new UrlCheckResponse());
        }
        setRspTemp((ArrayList) jceInputStream.read(f497a, 0, false));
    }

    public final void setRspTemp(ArrayList<UrlCheckResponse> arrayList) {
        this.rspTemp = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        if (this.rspTemp != null) {
            jceOutputStream.write((Collection) this.rspTemp, 0);
        }
    }
}
