package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class CloudResult extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f108a;
    public long hashKey;
    public int safeType;

    static {
        f108a = !CloudResult.class.desiredAssertionStatus();
    }

    public CloudResult() {
        this.hashKey = 0L;
        this.safeType = 0;
        this.hashKey = this.hashKey;
        this.safeType = this.safeType;
    }

    public CloudResult(long j, int i) {
        this.hashKey = 0L;
        this.safeType = 0;
        this.hashKey = j;
        this.safeType = i;
    }

    public final String className() {
        return "QQPIM.CloudResult";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f108a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.hashKey, "hashKey");
        jceDisplayer.display(this.safeType, "safeType");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        CloudResult cloudResult = (CloudResult) obj;
        return JceUtil.equals(this.hashKey, cloudResult.hashKey) && JceUtil.equals(this.safeType, cloudResult.safeType);
    }

    public final String fullClassName() {
        return "QQPIM.CloudResult";
    }

    public final long getHashKey() {
        return this.hashKey;
    }

    public final int getSafeType() {
        return this.safeType;
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
        this.safeType = jceInputStream.read(this.safeType, 1, true);
    }

    public final void setHashKey(long j) {
        this.hashKey = j;
    }

    public final void setSafeType(int i) {
        this.safeType = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.hashKey, 0);
        jceOutputStream.write(this.safeType, 1);
    }
}
