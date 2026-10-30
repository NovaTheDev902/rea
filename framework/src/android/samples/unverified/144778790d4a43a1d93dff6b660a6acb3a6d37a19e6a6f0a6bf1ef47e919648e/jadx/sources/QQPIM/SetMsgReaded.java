package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class SetMsgReaded extends JceStruct {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f542a;
    public byte issetreaded;

    static {
        f542a = !SetMsgReaded.class.desiredAssertionStatus();
    }

    public SetMsgReaded() {
        this.issetreaded = (byte) 0;
        this.issetreaded = this.issetreaded;
    }

    public SetMsgReaded(byte b) {
        this.issetreaded = (byte) 0;
        this.issetreaded = b;
    }

    public final String className() {
        return "QQPIM.SetMsgReaded";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f542a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.issetreaded, "issetreaded");
    }

    public final boolean equals(Object obj) {
        return JceUtil.equals(this.issetreaded, ((SetMsgReaded) obj).issetreaded);
    }

    public final String fullClassName() {
        return "QQPIM.SetMsgReaded";
    }

    public final byte getIssetreaded() {
        return this.issetreaded;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.issetreaded = jceInputStream.read(this.issetreaded, 0, true);
    }

    public final void setIssetreaded(byte b) {
        this.issetreaded = b;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.issetreaded, 0);
    }
}
