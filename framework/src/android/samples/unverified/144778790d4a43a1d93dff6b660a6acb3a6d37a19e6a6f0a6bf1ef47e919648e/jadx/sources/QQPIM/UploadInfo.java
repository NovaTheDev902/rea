package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import com.tencent.tmsecure.module.software.AppEntity;

/* JADX INFO: loaded from: classes.dex */
public final class UploadInfo extends JceStruct {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f603a;
    public long pos;
    public int size;

    static {
        f603a = !UploadInfo.class.desiredAssertionStatus();
    }

    public UploadInfo() {
        this.pos = 0L;
        this.size = 0;
        this.pos = this.pos;
        this.size = this.size;
    }

    public UploadInfo(long j, int i) {
        this.pos = 0L;
        this.size = 0;
        this.pos = j;
        this.size = i;
    }

    public final String className() {
        return "QQPIM.UploadInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f603a) {
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
        UploadInfo uploadInfo = (UploadInfo) obj;
        return JceUtil.equals(this.pos, uploadInfo.pos) && JceUtil.equals(this.size, uploadInfo.size);
    }

    public final String fullClassName() {
        return "QQPIM.UploadInfo";
    }

    public final long getPos() {
        return this.pos;
    }

    public final int getSize() {
        return this.size;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.pos = jceInputStream.read(this.pos, 0, true);
        this.size = jceInputStream.read(this.size, 1, true);
    }

    public final void setPos(long j) {
        this.pos = j;
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
