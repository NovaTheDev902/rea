package QQPIM;

import com.lenovo.providers.querypermissions.QueryPermissions;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ClientVersionInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f94a;

    /* JADX INFO: renamed from: id */
    public int f95id;
    public String info;
    public int version;

    static {
        f94a = !ClientVersionInfo.class.desiredAssertionStatus();
    }

    public ClientVersionInfo() {
        this.f95id = 0;
        this.version = 0;
        this.info = "";
        this.f95id = this.f95id;
        this.version = this.version;
        this.info = this.info;
    }

    public ClientVersionInfo(int i, int i2, String str) {
        this.f95id = 0;
        this.version = 0;
        this.info = "";
        this.f95id = i;
        this.version = i2;
        this.info = str;
    }

    public final String className() {
        return "QQPIM.ClientVersionInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f94a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.f95id, QueryPermissions.f1958ID);
        jceDisplayer.display(this.version, "version");
        jceDisplayer.display(this.info, "info");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ClientVersionInfo clientVersionInfo = (ClientVersionInfo) obj;
        return JceUtil.equals(this.f95id, clientVersionInfo.f95id) && JceUtil.equals(this.version, clientVersionInfo.version) && JceUtil.equals(this.info, clientVersionInfo.info);
    }

    public final String fullClassName() {
        return "QQPIM.ClientVersionInfo";
    }

    public final int getId() {
        return this.f95id;
    }

    public final String getInfo() {
        return this.info;
    }

    public final int getVersion() {
        return this.version;
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
        this.f95id = jceInputStream.read(this.f95id, 0, true);
        this.version = jceInputStream.read(this.version, 1, true);
        this.info = jceInputStream.readString(2, false);
    }

    public final void setId(int i) {
        this.f95id = i;
    }

    public final void setInfo(String str) {
        this.info = str;
    }

    public final void setVersion(int i) {
        this.version = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.f95id, 0);
        jceOutputStream.write(this.version, 1);
        if (this.info != null) {
            jceOutputStream.write(this.info, 2);
        }
    }
}
