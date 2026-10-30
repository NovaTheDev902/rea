package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class HotwordInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f420a;
    public String hotword;

    static {
        f420a = !HotwordInfo.class.desiredAssertionStatus();
    }

    public HotwordInfo() {
        this.hotword = "";
        this.hotword = this.hotword;
    }

    public HotwordInfo(String str) {
        this.hotword = "";
        this.hotword = str;
    }

    public final String className() {
        return "QQPIM.HotwordInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f420a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.hotword, "hotword");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.hotword, ((HotwordInfo) obj).hotword);
    }

    public final String fullClassName() {
        return "QQPIM.HotwordInfo";
    }

    public final String getHotword() {
        return this.hotword;
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
        this.hotword = jceInputStream.readString(0, true);
    }

    public final void setHotword(String str) {
        this.hotword = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.hotword, 0);
    }
}
