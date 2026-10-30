package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class RequestTemplate extends JceStruct {

    /* JADX INFO: renamed from: a */
    static ArrayList<UrlCheckRequest> f490a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f491b;
    public ArrayList<UrlCheckRequest> reqTemp;

    static {
        f491b = !RequestTemplate.class.desiredAssertionStatus();
    }

    public RequestTemplate() {
        this.reqTemp = null;
        this.reqTemp = this.reqTemp;
    }

    public RequestTemplate(ArrayList<UrlCheckRequest> arrayList) {
        this.reqTemp = null;
        this.reqTemp = arrayList;
    }

    public final String className() {
        return "QQPIM.RequestTemplate";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f491b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display((Collection) this.reqTemp, "reqTemp");
    }

    public final boolean equals(Object obj) {
        return JceUtil.equals(this.reqTemp, ((RequestTemplate) obj).reqTemp);
    }

    public final ArrayList<UrlCheckRequest> getReqTemp() {
        return this.reqTemp;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        if (f490a == null) {
            f490a = new ArrayList<>();
            f490a.add(new UrlCheckRequest());
        }
        setReqTemp((ArrayList) jceInputStream.read(f490a, 0, false));
    }

    public final void setReqTemp(ArrayList<UrlCheckRequest> arrayList) {
        this.reqTemp = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        if (this.reqTemp != null) {
            jceOutputStream.write((Collection) this.reqTemp, 0);
        }
    }
}
