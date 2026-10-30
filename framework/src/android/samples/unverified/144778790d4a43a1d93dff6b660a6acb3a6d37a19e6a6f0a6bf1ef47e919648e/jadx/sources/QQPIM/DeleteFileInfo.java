package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class DeleteFileInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f123a;
    public String file;

    static {
        f123a = !DeleteFileInfo.class.desiredAssertionStatus();
    }

    public DeleteFileInfo() {
        this.file = "";
        this.file = this.file;
    }

    public DeleteFileInfo(String str) {
        this.file = "";
        this.file = str;
    }

    public final String className() {
        return "QQPIM.DeleteFileInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f123a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.file, "file");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.file, ((DeleteFileInfo) obj).file);
    }

    public final String fullClassName() {
        return "QQPIM.DeleteFileInfo";
    }

    public final String getFile() {
        return this.file;
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
        this.file = jceInputStream.readString(0, true);
    }

    public final void setFile(String str) {
        this.file = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.file, 0);
    }
}
