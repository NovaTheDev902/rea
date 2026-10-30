package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ODevice extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f466a;
    public int bcamerapixel;
    public int fcamerapixel;

    static {
        f466a = !ODevice.class.desiredAssertionStatus();
    }

    public ODevice() {
        this.fcamerapixel = 0;
        this.bcamerapixel = 0;
        this.fcamerapixel = this.fcamerapixel;
        this.bcamerapixel = this.bcamerapixel;
    }

    public ODevice(int i, int i2) {
        this.fcamerapixel = 0;
        this.bcamerapixel = 0;
        this.fcamerapixel = i;
        this.bcamerapixel = i2;
    }

    public final String className() {
        return "QQPIM.ODevice";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f466a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.fcamerapixel, "fcamerapixel");
        jceDisplayer.display(this.bcamerapixel, "bcamerapixel");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ODevice oDevice = (ODevice) obj;
        return JceUtil.equals(this.fcamerapixel, oDevice.fcamerapixel) && JceUtil.equals(this.bcamerapixel, oDevice.bcamerapixel);
    }

    public final String fullClassName() {
        return "QQPIM.ODevice";
    }

    public final int getBcamerapixel() {
        return this.bcamerapixel;
    }

    public final int getFcamerapixel() {
        return this.fcamerapixel;
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
        this.fcamerapixel = jceInputStream.read(this.fcamerapixel, 0, true);
        this.bcamerapixel = jceInputStream.read(this.bcamerapixel, 1, true);
    }

    public final void setBcamerapixel(int i) {
        this.bcamerapixel = i;
    }

    public final void setFcamerapixel(int i) {
        this.fcamerapixel = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.fcamerapixel, 0);
        jceOutputStream.write(this.bcamerapixel, 1);
    }
}
