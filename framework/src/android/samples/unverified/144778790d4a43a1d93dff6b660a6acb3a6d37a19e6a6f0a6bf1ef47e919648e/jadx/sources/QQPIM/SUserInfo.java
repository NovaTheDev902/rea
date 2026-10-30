package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import com.tencent.tmsecure.common.TMSApplication;

/* JADX INFO: loaded from: classes.dex */
public final class SUserInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f527a;
    public String imei;
    public String imsi;

    /* JADX INFO: renamed from: ip */
    public String f528ip;

    /* JADX INFO: renamed from: lc */
    public String f529lc;
    public String phone;

    /* JADX INFO: renamed from: qq */
    public String f530qq;

    static {
        f527a = !SUserInfo.class.desiredAssertionStatus();
    }

    public SUserInfo() {
        this.imei = "";
        this.f530qq = "";
        this.phone = "";
        this.f528ip = "";
        this.f529lc = "";
        this.imsi = "";
        this.imei = this.imei;
        this.f530qq = this.f530qq;
        this.phone = this.phone;
        this.f528ip = this.f528ip;
        this.f529lc = this.f529lc;
        this.imsi = this.imsi;
    }

    public SUserInfo(String str, String str2, String str3, String str4, String str5, String str6) {
        this.imei = "";
        this.f530qq = "";
        this.phone = "";
        this.f528ip = "";
        this.f529lc = "";
        this.imsi = "";
        this.imei = str;
        this.f530qq = str2;
        this.phone = str3;
        this.f528ip = str4;
        this.f529lc = str5;
        this.imsi = str6;
    }

    public final String className() {
        return "QQPIM.SUserInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f527a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.imei, "imei");
        jceDisplayer.display(this.f530qq, "qq");
        jceDisplayer.display(this.phone, "phone");
        jceDisplayer.display(this.f528ip, "ip");
        jceDisplayer.display(this.f529lc, TMSApplication.CON_LC);
        jceDisplayer.display(this.imsi, "imsi");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        SUserInfo sUserInfo = (SUserInfo) obj;
        return JceUtil.equals(this.imei, sUserInfo.imei) && JceUtil.equals(this.f530qq, sUserInfo.f530qq) && JceUtil.equals(this.phone, sUserInfo.phone) && JceUtil.equals(this.f528ip, sUserInfo.f528ip) && JceUtil.equals(this.f529lc, sUserInfo.f529lc) && JceUtil.equals(this.imsi, sUserInfo.imsi);
    }

    public final String fullClassName() {
        return "QQPIM.QQPIM.SUserInfo";
    }

    public final String getImei() {
        return this.imei;
    }

    public final String getImsi() {
        return this.imsi;
    }

    public final String getIp() {
        return this.f528ip;
    }

    public final String getLc() {
        return this.f529lc;
    }

    public final String getPhone() {
        return this.phone;
    }

    public final String getQq() {
        return this.f530qq;
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
        this.imei = jceInputStream.readString(0, true);
        this.f530qq = jceInputStream.readString(1, false);
        this.phone = jceInputStream.readString(2, false);
        this.f528ip = jceInputStream.readString(3, false);
        this.f529lc = jceInputStream.readString(4, false);
        this.imsi = jceInputStream.readString(5, false);
    }

    public final void setImei(String str) {
        this.imei = str;
    }

    public final void setImsi(String str) {
        this.imsi = str;
    }

    public final void setIp(String str) {
        this.f528ip = str;
    }

    public final void setLc(String str) {
        this.f529lc = str;
    }

    public final void setPhone(String str) {
        this.phone = str;
    }

    public final void setQq(String str) {
        this.f530qq = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.imei, 0);
        if (this.f530qq != null) {
            jceOutputStream.write(this.f530qq, 1);
        }
        if (this.phone != null) {
            jceOutputStream.write(this.phone, 2);
        }
        if (this.f528ip != null) {
            jceOutputStream.write(this.f528ip, 3);
        }
        if (this.f529lc != null) {
            jceOutputStream.write(this.f529lc, 4);
        }
        if (this.imsi != null) {
            jceOutputStream.write(this.imsi, 5);
        }
    }
}
