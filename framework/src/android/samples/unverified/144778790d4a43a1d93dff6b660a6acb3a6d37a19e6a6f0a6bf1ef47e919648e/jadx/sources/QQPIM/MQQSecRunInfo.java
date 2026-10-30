package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class MQQSecRunInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f431a;
    public int option;

    static {
        f431a = !MQQSecRunInfo.class.desiredAssertionStatus();
    }

    public MQQSecRunInfo() {
        this.option = 0;
        this.option = this.option;
    }

    public MQQSecRunInfo(int i) {
        this.option = 0;
        this.option = i;
    }

    public final String className() {
        return "QQPIM.MQQSecRunInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f431a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.option, "option");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.option, ((MQQSecRunInfo) obj).option);
    }

    public final String fullClassName() {
        return "QQPIM.MQQSecRunInfo";
    }

    public final int getOption() {
        return this.option;
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
        this.option = jceInputStream.read(this.option, 0, true);
    }

    public final void setOption(int i) {
        this.option = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.option, 0);
    }
}
