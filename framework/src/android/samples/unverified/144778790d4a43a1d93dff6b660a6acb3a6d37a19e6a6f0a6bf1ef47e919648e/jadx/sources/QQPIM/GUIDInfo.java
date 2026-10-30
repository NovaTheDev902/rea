package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import com.tencent.tmsecure.module.wupsession.WupConfig;

/* JADX INFO: loaded from: classes.dex */
public final class GUIDInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f416a;
    public String guid;

    static {
        f416a = !GUIDInfo.class.desiredAssertionStatus();
    }

    public GUIDInfo() {
        this.guid = "";
        this.guid = this.guid;
    }

    public GUIDInfo(String str) {
        this.guid = "";
        this.guid = str;
    }

    public final String className() {
        return "QQPIM.GUIDInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f416a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.guid, WupConfig.KEY_GUID);
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        return JceUtil.equals(this.guid, ((GUIDInfo) obj).guid);
    }

    public final String fullClassName() {
        return "QQPIM.GUIDInfo";
    }

    public final String getGuid() {
        return this.guid;
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
        this.guid = jceInputStream.readString(0, true);
    }

    public final void setGuid(String str) {
        this.guid = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.guid, 0);
    }
}
