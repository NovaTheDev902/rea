package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class CloudFeature extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f100a;
    public long hashKey;
    public boolean isRom;

    static {
        f100a = !CloudFeature.class.desiredAssertionStatus();
    }

    public CloudFeature() {
        this.hashKey = 0L;
        this.isRom = false;
        this.hashKey = this.hashKey;
        this.isRom = this.isRom;
    }

    public CloudFeature(long j, boolean z) {
        this.hashKey = 0L;
        this.isRom = false;
        this.hashKey = j;
        this.isRom = z;
    }

    public final String className() {
        return "QQPIM.CloudFeature";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f100a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.hashKey, "hashKey");
        jceDisplayer.display(this.isRom, "isRom");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        CloudFeature cloudFeature = (CloudFeature) obj;
        return JceUtil.equals(this.hashKey, cloudFeature.hashKey) && JceUtil.equals(this.isRom, cloudFeature.isRom);
    }

    public final String fullClassName() {
        return "QQPIM.CloudFeature";
    }

    public final long getHashKey() {
        return this.hashKey;
    }

    public final boolean getIsRom() {
        return this.isRom;
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
        this.hashKey = jceInputStream.read(this.hashKey, 0, true);
        this.isRom = jceInputStream.read(this.isRom, 1, false);
    }

    public final void setHashKey(long j) {
        this.hashKey = j;
    }

    public final void setIsRom(boolean z) {
        this.isRom = z;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.hashKey, 0);
        jceOutputStream.write(this.isRom, 1);
    }
}
