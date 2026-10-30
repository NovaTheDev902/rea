package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class SPhoneType extends JceStruct {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f500a;
    public int phonetype;

    static {
        f500a = !SPhoneType.class.desiredAssertionStatus();
    }

    public SPhoneType() {
        this.phonetype = 0;
        this.phonetype = this.phonetype;
    }

    public SPhoneType(int i) {
        this.phonetype = 0;
        this.phonetype = i;
    }

    public final String className() {
        return "QQPIM.SPhoneType";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f500a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.phonetype, "phonetype");
    }

    public final boolean equals(Object obj) {
        return JceUtil.equals(this.phonetype, ((SPhoneType) obj).phonetype);
    }

    public final int getPhonetype() {
        return this.phonetype;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.phonetype = jceInputStream.read(this.phonetype, 0, true);
    }

    public final void setPhonetype(int i) {
        this.phonetype = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.phonetype, 0);
    }
}
