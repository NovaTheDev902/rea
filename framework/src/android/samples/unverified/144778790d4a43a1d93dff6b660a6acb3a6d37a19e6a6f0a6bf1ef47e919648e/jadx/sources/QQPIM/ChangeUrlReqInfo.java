package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ChangeUrlReqInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f88a;
    public String url;

    static {
        f88a = !ChangeUrlReqInfo.class.desiredAssertionStatus();
    }

    public ChangeUrlReqInfo() {
        this.url = "";
        this.url = this.url;
    }

    public ChangeUrlReqInfo(String str) {
        this.url = "";
        this.url = str;
    }

    public final String className() {
        return "QQPIM.ChangeUrlReqInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f88a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.url, "url");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.url, ((ChangeUrlReqInfo) obj).url);
    }

    public final String fullClassName() {
        return "QQPIM.ChangeUrlReqInfo";
    }

    public final String getUrl() {
        return this.url;
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
        this.url = jceInputStream.readString(0, true);
    }

    public final void setUrl(String str) {
        this.url = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.url, 0);
    }
}
