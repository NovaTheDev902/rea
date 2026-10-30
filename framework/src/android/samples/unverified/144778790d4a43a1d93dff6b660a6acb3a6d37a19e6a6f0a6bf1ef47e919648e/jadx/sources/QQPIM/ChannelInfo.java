package QQPIM;

import com.lenovo.providers.querypermissions.QueryPermissions;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import com.tencent.tmsecure.common.TMSApplication;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class ChannelInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<SoftKey> f90a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f91b;
    public ArrayList<SoftKey> checksoft;

    /* JADX INFO: renamed from: id */
    public String f92id;
    public int isbuildin;
    public int product;
    public String token;

    static {
        f91b = !ChannelInfo.class.desiredAssertionStatus();
    }

    public ChannelInfo() {
        this.f92id = "";
        this.product = EProduct.EP_None.value();
        this.isbuildin = 0;
        this.token = "";
        this.checksoft = null;
        this.f92id = this.f92id;
        this.product = this.product;
        this.isbuildin = this.isbuildin;
        this.token = this.token;
        this.checksoft = this.checksoft;
    }

    public ChannelInfo(String str, int i, int i2, String str2, ArrayList<SoftKey> arrayList) {
        this.f92id = "";
        this.product = EProduct.EP_None.value();
        this.isbuildin = 0;
        this.token = "";
        this.checksoft = null;
        this.f92id = str;
        this.product = i;
        this.isbuildin = i2;
        this.token = str2;
        this.checksoft = arrayList;
    }

    public final String className() {
        return "QQPIM.ChannelInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f91b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.f92id, QueryPermissions.f1958ID);
        jceDisplayer.display(this.product, TMSApplication.CON_PRODUCT);
        jceDisplayer.display(this.isbuildin, "isbuildin");
        jceDisplayer.display(this.token, "token");
        jceDisplayer.display((Collection) this.checksoft, "checksoft");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ChannelInfo channelInfo = (ChannelInfo) obj;
        return JceUtil.equals(this.f92id, channelInfo.f92id) && JceUtil.equals(this.product, channelInfo.product) && JceUtil.equals(this.isbuildin, channelInfo.isbuildin) && JceUtil.equals(this.token, channelInfo.token) && JceUtil.equals(this.checksoft, channelInfo.checksoft);
    }

    public final String fullClassName() {
        return "QQPIM.ChannelInfo";
    }

    public final ArrayList<SoftKey> getChecksoft() {
        return this.checksoft;
    }

    public final String getId() {
        return this.f92id;
    }

    public final int getIsbuildin() {
        return this.isbuildin;
    }

    public final int getProduct() {
        return this.product;
    }

    public final String getToken() {
        return this.token;
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
        this.f92id = jceInputStream.readString(0, true);
        this.product = jceInputStream.read(this.product, 1, false);
        this.isbuildin = jceInputStream.read(this.isbuildin, 2, false);
        this.token = jceInputStream.readString(3, false);
        if (f90a == null) {
            f90a = new ArrayList<>();
            f90a.add(new SoftKey());
        }
        setChecksoft((ArrayList) jceInputStream.read(f90a, 4, false));
    }

    public final void setChecksoft(ArrayList<SoftKey> arrayList) {
        this.checksoft = arrayList;
    }

    public final void setId(String str) {
        this.f92id = str;
    }

    public final void setIsbuildin(int i) {
        this.isbuildin = i;
    }

    public final void setProduct(int i) {
        this.product = i;
    }

    public final void setToken(String str) {
        this.token = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.f92id, 0);
        jceOutputStream.write(this.product, 1);
        jceOutputStream.write(this.isbuildin, 2);
        if (this.token != null) {
            jceOutputStream.write(this.token, 3);
        }
        if (this.checksoft != null) {
            jceOutputStream.write((Collection) this.checksoft, 4);
        }
    }
}
