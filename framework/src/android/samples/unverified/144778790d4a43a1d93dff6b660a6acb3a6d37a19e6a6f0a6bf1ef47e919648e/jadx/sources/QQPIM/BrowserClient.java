package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.wupsession.WupConfig;

/* JADX INFO: loaded from: classes.dex */
public final class BrowserClient extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f79a;
    public String guid;
    public String imei;
    public int product;

    /* JADX INFO: renamed from: ua */
    public String f80ua;
    public String version;

    static {
        f79a = !BrowserClient.class.desiredAssertionStatus();
    }

    public BrowserClient() {
        this.product = 0;
        this.version = "";
        this.imei = "";
        this.guid = "";
        this.f80ua = "";
        this.product = this.product;
        this.version = this.version;
        this.imei = this.imei;
        this.guid = this.guid;
        this.f80ua = this.f80ua;
    }

    public BrowserClient(int i, String str, String str2, String str3, String str4) {
        this.product = 0;
        this.version = "";
        this.imei = "";
        this.guid = "";
        this.f80ua = "";
        this.product = i;
        this.version = str;
        this.imei = str2;
        this.guid = str3;
        this.f80ua = str4;
    }

    public final String className() {
        return "QQPIM.BrowserClient";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f79a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.product, TMSApplication.CON_PRODUCT);
        jceDisplayer.display(this.version, "version");
        jceDisplayer.display(this.imei, "imei");
        jceDisplayer.display(this.guid, WupConfig.KEY_GUID);
        jceDisplayer.display(this.f80ua, "ua");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        BrowserClient browserClient = (BrowserClient) obj;
        return JceUtil.equals(this.product, browserClient.product) && JceUtil.equals(this.version, browserClient.version) && JceUtil.equals(this.imei, browserClient.imei) && JceUtil.equals(this.guid, browserClient.guid) && JceUtil.equals(this.f80ua, browserClient.f80ua);
    }

    public final String fullClassName() {
        return "QQPIM.BrowserClient";
    }

    public final String getGuid() {
        return this.guid;
    }

    public final String getImei() {
        return this.imei;
    }

    public final int getProduct() {
        return this.product;
    }

    public final String getUa() {
        return this.f80ua;
    }

    public final String getVersion() {
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
        this.product = jceInputStream.read(this.product, 0, true);
        this.version = jceInputStream.readString(1, true);
        this.imei = jceInputStream.readString(2, true);
        this.guid = jceInputStream.readString(3, true);
        this.f80ua = jceInputStream.readString(4, true);
    }

    public final void setGuid(String str) {
        this.guid = str;
    }

    public final void setImei(String str) {
        this.imei = str;
    }

    public final void setProduct(int i) {
        this.product = i;
    }

    public final void setUa(String str) {
        this.f80ua = str;
    }

    public final void setVersion(String str) {
        this.version = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.product, 0);
        jceOutputStream.write(this.version, 1);
        jceOutputStream.write(this.imei, 2);
        jceOutputStream.write(this.guid, 3);
        jceOutputStream.write(this.f80ua, 4);
    }
}
