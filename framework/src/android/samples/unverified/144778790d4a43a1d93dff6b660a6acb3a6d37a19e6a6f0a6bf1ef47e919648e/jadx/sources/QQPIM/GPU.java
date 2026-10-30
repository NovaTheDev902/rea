package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class GPU extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f415a;
    public String model;
    public String version;

    static {
        f415a = !GPU.class.desiredAssertionStatus();
    }

    public GPU() {
        this.model = "";
        this.version = "";
        this.model = this.model;
        this.version = this.version;
    }

    public GPU(String str, String str2) {
        this.model = "";
        this.version = "";
        this.model = str;
        this.version = str2;
    }

    public final String className() {
        return "QQPIM.GPU";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f415a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.model, "model");
        jceDisplayer.display(this.version, "version");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        GPU gpu = (GPU) obj;
        return JceUtil.equals(this.model, gpu.model) && JceUtil.equals(this.version, gpu.version);
    }

    public final String fullClassName() {
        return "QQPIM.GPU";
    }

    public final String getModel() {
        return this.model;
    }

    public final String getVersion() {
        return this.version;
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
        this.model = jceInputStream.readString(0, true);
        this.version = jceInputStream.readString(1, true);
    }

    public final void setModel(String str) {
        this.model = str;
    }

    public final void setVersion(String str) {
        this.version = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.model, 0);
        jceOutputStream.write(this.version, 1);
    }
}
