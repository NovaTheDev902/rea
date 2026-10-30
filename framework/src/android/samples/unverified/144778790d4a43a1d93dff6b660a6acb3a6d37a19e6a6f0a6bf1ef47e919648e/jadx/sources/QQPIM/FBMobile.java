package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class FBMobile extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f404a;
    public String city;
    public int mtype;
    public String phone;

    /* JADX INFO: renamed from: sp */
    public int f405sp;
    public String state;

    static {
        f404a = !FBMobile.class.desiredAssertionStatus();
    }

    public FBMobile() {
        this.phone = "";
        this.mtype = 0;
        this.state = "";
        this.city = "";
        this.f405sp = 0;
        this.phone = this.phone;
        this.mtype = this.mtype;
        this.state = this.state;
        this.city = this.city;
        this.f405sp = this.f405sp;
    }

    public FBMobile(String str, int i, String str2, String str3, int i2) {
        this.phone = "";
        this.mtype = 0;
        this.state = "";
        this.city = "";
        this.f405sp = 0;
        this.phone = str;
        this.mtype = i;
        this.state = str2;
        this.city = str3;
        this.f405sp = i2;
    }

    public final String className() {
        return "QQPIM.FBMobile";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f404a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.phone, "phone");
        jceDisplayer.display(this.mtype, "mtype");
        jceDisplayer.display(this.state, "state");
        jceDisplayer.display(this.city, "city");
        jceDisplayer.display(this.f405sp, "sp");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        FBMobile fBMobile = (FBMobile) obj;
        return JceUtil.equals(this.phone, fBMobile.phone) && JceUtil.equals(this.mtype, fBMobile.mtype) && JceUtil.equals(this.state, fBMobile.state) && JceUtil.equals(this.city, fBMobile.city) && JceUtil.equals(this.f405sp, fBMobile.f405sp);
    }

    public final String fullClassName() {
        return "QQPIM.FBMobile";
    }

    public final String getCity() {
        return this.city;
    }

    public final int getMtype() {
        return this.mtype;
    }

    public final String getPhone() {
        return this.phone;
    }

    public final int getSp() {
        return this.f405sp;
    }

    public final String getState() {
        return this.state;
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
        this.phone = jceInputStream.readString(0, true);
        this.mtype = jceInputStream.read(this.mtype, 1, true);
        this.state = jceInputStream.readString(2, true);
        this.city = jceInputStream.readString(3, true);
        this.f405sp = jceInputStream.read(this.f405sp, 4, true);
    }

    public final void setCity(String str) {
        this.city = str;
    }

    public final void setMtype(int i) {
        this.mtype = i;
    }

    public final void setPhone(String str) {
        this.phone = str;
    }

    public final void setSp(int i) {
        this.f405sp = i;
    }

    public final void setState(String str) {
        this.state = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.phone, 0);
        jceOutputStream.write(this.mtype, 1);
        jceOutputStream.write(this.state, 2);
        jceOutputStream.write(this.city, 3);
        jceOutputStream.write(this.f405sp, 4);
    }
}
