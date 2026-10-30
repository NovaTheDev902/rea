package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import com.tencent.tmsecure.module.software.AppEntity;

/* JADX INFO: loaded from: classes.dex */
public final class UploadFile extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f599a;
    public int pos;
    public int size;

    static {
        f599a = !UploadFile.class.desiredAssertionStatus();
    }

    public UploadFile() {
        this.pos = 0;
        this.size = 0;
        this.pos = this.pos;
        this.size = this.size;
    }

    public UploadFile(int i, int i2) {
        this.pos = 0;
        this.size = 0;
        this.pos = i;
        this.size = i2;
    }

    public final String className() {
        return "QQPIM.UploadFile";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f599a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.pos, "pos");
        jceDisplayer.display(this.size, AppEntity.KEY_SIZE_LONG);
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        UploadFile uploadFile = (UploadFile) obj;
        return JceUtil.equals(this.pos, uploadFile.pos) && JceUtil.equals(this.size, uploadFile.size);
    }

    public final String fullClassName() {
        return "QQPIM.UploadFile";
    }

    public final int getPos() {
        return this.pos;
    }

    public final int getSize() {
        return this.size;
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
        this.pos = jceInputStream.read(this.pos, 0, true);
        this.size = jceInputStream.read(this.size, 1, true);
    }

    public final void setPos(int i) {
        this.pos = i;
    }

    public final void setSize(int i) {
        this.size = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.pos, 0);
        jceOutputStream.write(this.size, 1);
    }
}
