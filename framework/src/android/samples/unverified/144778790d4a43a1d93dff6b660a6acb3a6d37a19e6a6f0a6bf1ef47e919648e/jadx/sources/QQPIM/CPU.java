package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class CPU extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f83a;
    public int maxfreq;
    public int minfreq;
    public String model;

    static {
        f83a = !CPU.class.desiredAssertionStatus();
    }

    public CPU() {
        this.model = "";
        this.maxfreq = 0;
        this.minfreq = 0;
        this.model = this.model;
        this.maxfreq = this.maxfreq;
        this.minfreq = this.minfreq;
    }

    public CPU(String str, int i, int i2) {
        this.model = "";
        this.maxfreq = 0;
        this.minfreq = 0;
        this.model = str;
        this.maxfreq = i;
        this.minfreq = i2;
    }

    public final String className() {
        return "QQPIM.CPU";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f83a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.model, "model");
        jceDisplayer.display(this.maxfreq, "maxfreq");
        jceDisplayer.display(this.minfreq, "minfreq");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        CPU cpu = (CPU) obj;
        return JceUtil.equals(this.model, cpu.model) && JceUtil.equals(this.maxfreq, cpu.maxfreq) && JceUtil.equals(this.minfreq, cpu.minfreq);
    }

    public final String fullClassName() {
        return "QQPIM.CPU";
    }

    public final int getMaxfreq() {
        return this.maxfreq;
    }

    public final int getMinfreq() {
        return this.minfreq;
    }

    public final String getModel() {
        return this.model;
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
        this.maxfreq = jceInputStream.read(this.maxfreq, 1, true);
        this.minfreq = jceInputStream.read(this.minfreq, 2, true);
    }

    public final void setMaxfreq(int i) {
        this.maxfreq = i;
    }

    public final void setMinfreq(int i) {
        this.minfreq = i;
    }

    public final void setModel(String str) {
        this.model = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.model, 0);
        jceOutputStream.write(this.maxfreq, 1);
        jceOutputStream.write(this.minfreq, 2);
    }
}
