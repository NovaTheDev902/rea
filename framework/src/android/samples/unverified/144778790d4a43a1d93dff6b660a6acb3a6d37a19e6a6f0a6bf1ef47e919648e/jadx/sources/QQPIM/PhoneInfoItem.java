package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class PhoneInfoItem extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static byte[] f473a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f474b;
    public byte[] info;
    public int infoid;

    static {
        f474b = !PhoneInfoItem.class.desiredAssertionStatus();
    }

    public PhoneInfoItem() {
        this.infoid = 0;
        this.info = null;
        this.infoid = this.infoid;
        this.info = this.info;
    }

    public PhoneInfoItem(int i, byte[] bArr) {
        this.infoid = 0;
        this.info = null;
        this.infoid = i;
        this.info = bArr;
    }

    public final String className() {
        return "QQPIM.PhoneInfoItem";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f474b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.infoid, "infoid");
        jceDisplayer.display(this.info, "info");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        PhoneInfoItem phoneInfoItem = (PhoneInfoItem) obj;
        return JceUtil.equals(this.infoid, phoneInfoItem.infoid) && JceUtil.equals(this.info, phoneInfoItem.info);
    }

    public final String fullClassName() {
        return "QQPIM.PhoneInfoItem";
    }

    public final byte[] getInfo() {
        return this.info;
    }

    public final int getInfoid() {
        return this.infoid;
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
        this.infoid = jceInputStream.read(this.infoid, 0, true);
        if (f473a == null) {
            f473a = new byte[1];
            f473a[0] = 0;
        }
        this.info = jceInputStream.read(f473a, 1, true);
    }

    public final void setInfo(byte[] bArr) {
        this.info = bArr;
    }

    public final void setInfoid(int i) {
        this.infoid = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.infoid, 0);
        jceOutputStream.write(this.info, 1);
    }
}
