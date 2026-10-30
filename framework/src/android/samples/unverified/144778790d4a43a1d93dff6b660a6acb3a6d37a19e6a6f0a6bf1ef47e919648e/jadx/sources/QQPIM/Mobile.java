package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class Mobile extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f450a;
    public String brand;
    public String model;
    public String url;

    static {
        f450a = !Mobile.class.desiredAssertionStatus();
    }

    public Mobile() {
        this.model = "";
        this.brand = "";
        this.url = "";
        this.model = this.model;
        this.brand = this.brand;
        this.url = this.url;
    }

    public Mobile(String str, String str2, String str3) {
        this.model = "";
        this.brand = "";
        this.url = "";
        this.model = str;
        this.brand = str2;
        this.url = str3;
    }

    public final String className() {
        return "QQPIM.Mobile";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f450a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.model, "model");
        jceDisplayer.display(this.brand, "brand");
        jceDisplayer.display(this.url, "url");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        Mobile mobile = (Mobile) obj;
        return JceUtil.equals(this.model, mobile.model) && JceUtil.equals(this.brand, mobile.brand) && JceUtil.equals(this.url, mobile.url);
    }

    public final String fullClassName() {
        return "QQPIM.Mobile";
    }

    public final String getBrand() {
        return this.brand;
    }

    public final String getModel() {
        return this.model;
    }

    public final String getUrl() {
        return this.url;
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
        this.brand = jceInputStream.readString(1, true);
        this.url = jceInputStream.readString(2, false);
    }

    public final void setBrand(String str) {
        this.brand = str;
    }

    public final void setModel(String str) {
        this.model = str;
    }

    public final void setUrl(String str) {
        this.url = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.model, 0);
        jceOutputStream.write(this.brand, 1);
        if (this.url != null) {
            jceOutputStream.write(this.url, 2);
        }
    }
}
