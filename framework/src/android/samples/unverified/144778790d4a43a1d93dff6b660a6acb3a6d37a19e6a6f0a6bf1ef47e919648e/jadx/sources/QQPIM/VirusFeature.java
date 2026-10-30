package QQPIM;

import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.database.AppDatabase;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class VirusFeature extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f622a;
    public String content;

    /* JADX INFO: renamed from: id */
    public short f623id;

    static {
        f622a = !VirusFeature.class.desiredAssertionStatus();
    }

    public VirusFeature() {
        this.f623id = (short) 0;
        this.content = "";
        this.f623id = this.f623id;
        this.content = this.content;
    }

    public VirusFeature(short s, String str) {
        this.f623id = (short) 0;
        this.content = "";
        this.f623id = s;
        this.content = str;
    }

    public final String className() {
        return "QQPIM.VirusFeature";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f622a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.f623id, QueryPermissions.f1958ID);
        jceDisplayer.display(this.content, AppDatabase.CONTENT);
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        VirusFeature virusFeature = (VirusFeature) obj;
        return JceUtil.equals(this.f623id, virusFeature.f623id) && JceUtil.equals(this.content, virusFeature.content);
    }

    public final String fullClassName() {
        return "QQPIM.VirusFeature";
    }

    public final String getContent() {
        return this.content;
    }

    public final short getId() {
        return this.f623id;
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
        this.f623id = jceInputStream.read(this.f623id, 0, true);
        this.content = jceInputStream.readString(1, true);
    }

    public final void setContent(String str) {
        this.content = str;
    }

    public final void setId(short s) {
        this.f623id = s;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.f623id, 0);
        jceOutputStream.write(this.content, 1);
    }
}
