package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.wupsession.WupConfig;

/* JADX INFO: loaded from: classes.dex */
public final class UserInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ProductVersion f611a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f612b;
    public int buildno;
    public String channelid;

    /* JADX INFO: renamed from: ct */
    public int f613ct;
    public String guid;
    public String imei;
    public String imsi;

    /* JADX INFO: renamed from: ip */
    public String f614ip;
    public int isbuildin;
    public int isroot;
    public short lang;

    /* JADX INFO: renamed from: lc */
    public String f615lc;
    public String phone;
    public int product;

    /* JADX INFO: renamed from: qq */
    public String f616qq;
    public int sdkversion;

    /* JADX INFO: renamed from: ua */
    public String f617ua;
    public String uuid;
    public ProductVersion version;

    static {
        f612b = !UserInfo.class.desiredAssertionStatus();
    }

    public UserInfo() {
        this.imei = "";
        this.f616qq = "";
        this.phone = "";
        this.f614ip = "";
        this.f615lc = "";
        this.channelid = "";
        this.f617ua = "";
        this.f613ct = ConnectType.CT_NONE.value();
        this.product = EProduct.EP_None.value();
        this.version = null;
        this.guid = "";
        this.imsi = "";
        this.isbuildin = 0;
        this.isroot = 0;
        this.sdkversion = 0;
        this.buildno = 0;
        this.uuid = "";
        this.lang = (short) 0;
        this.imei = this.imei;
        this.f616qq = this.f616qq;
        this.phone = this.phone;
        this.f614ip = this.f614ip;
        this.f615lc = this.f615lc;
        this.channelid = this.channelid;
        this.f617ua = this.f617ua;
        this.f613ct = this.f613ct;
        this.product = this.product;
        this.version = this.version;
        this.guid = this.guid;
        this.imsi = this.imsi;
        this.isbuildin = this.isbuildin;
        this.isroot = this.isroot;
        this.sdkversion = this.sdkversion;
        this.buildno = this.buildno;
        this.uuid = this.uuid;
        this.lang = this.lang;
    }

    public UserInfo(String str, String str2, String str3, String str4, String str5, String str6, String str7, int i, int i2, ProductVersion productVersion, String str8, String str9, int i3, int i4, int i5, int i6, String str10, short s) {
        this.imei = "";
        this.f616qq = "";
        this.phone = "";
        this.f614ip = "";
        this.f615lc = "";
        this.channelid = "";
        this.f617ua = "";
        this.f613ct = ConnectType.CT_NONE.value();
        this.product = EProduct.EP_None.value();
        this.version = null;
        this.guid = "";
        this.imsi = "";
        this.isbuildin = 0;
        this.isroot = 0;
        this.sdkversion = 0;
        this.buildno = 0;
        this.uuid = "";
        this.lang = (short) 0;
        this.imei = str;
        this.f616qq = str2;
        this.phone = str3;
        this.f614ip = str4;
        this.f615lc = str5;
        this.channelid = str6;
        this.f617ua = str7;
        this.f613ct = i;
        this.product = i2;
        this.version = productVersion;
        this.guid = str8;
        this.imsi = str9;
        this.isbuildin = i3;
        this.isroot = i4;
        this.sdkversion = i5;
        this.buildno = i6;
        this.uuid = str10;
        this.lang = s;
    }

    public final String className() {
        return "QQPIM.UserInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f612b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.imei, "imei");
        jceDisplayer.display(this.f616qq, "qq");
        jceDisplayer.display(this.phone, "phone");
        jceDisplayer.display(this.f614ip, "ip");
        jceDisplayer.display(this.f615lc, TMSApplication.CON_LC);
        jceDisplayer.display(this.channelid, "channelid");
        jceDisplayer.display(this.f617ua, "ua");
        jceDisplayer.display(this.f613ct, "ct");
        jceDisplayer.display(this.product, TMSApplication.CON_PRODUCT);
        jceDisplayer.display((JceStruct) this.version, "version");
        jceDisplayer.display(this.guid, WupConfig.KEY_GUID);
        jceDisplayer.display(this.imsi, "imsi");
        jceDisplayer.display(this.isbuildin, "isbuildin");
        jceDisplayer.display(this.isroot, "isroot");
        jceDisplayer.display(this.sdkversion, "sdkversion");
        jceDisplayer.display(this.buildno, "buildno");
        jceDisplayer.display(this.uuid, "uuid");
        jceDisplayer.display(this.lang, "lang");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        UserInfo userInfo = (UserInfo) obj;
        return JceUtil.equals(this.imei, userInfo.imei) && JceUtil.equals(this.f616qq, userInfo.f616qq) && JceUtil.equals(this.phone, userInfo.phone) && JceUtil.equals(this.f614ip, userInfo.f614ip) && JceUtil.equals(this.f615lc, userInfo.f615lc) && JceUtil.equals(this.channelid, userInfo.channelid) && JceUtil.equals(this.f617ua, userInfo.f617ua) && JceUtil.equals(this.f613ct, userInfo.f613ct) && JceUtil.equals(this.product, userInfo.product) && JceUtil.equals(this.version, userInfo.version) && JceUtil.equals(this.guid, userInfo.guid) && JceUtil.equals(this.imsi, userInfo.imsi) && JceUtil.equals(this.isbuildin, userInfo.isbuildin) && JceUtil.equals(this.isroot, userInfo.isroot) && JceUtil.equals(this.sdkversion, userInfo.sdkversion) && JceUtil.equals(this.buildno, userInfo.buildno) && JceUtil.equals(this.uuid, userInfo.uuid) && JceUtil.equals(this.lang, userInfo.lang);
    }

    public final String fullClassName() {
        return "QQPIM.UserInfo";
    }

    public final int getBuildno() {
        return this.buildno;
    }

    public final String getChannelid() {
        return this.channelid;
    }

    public final int getCt() {
        return this.f613ct;
    }

    public final String getGuid() {
        return this.guid;
    }

    public final String getImei() {
        return this.imei;
    }

    public final String getImsi() {
        return this.imsi;
    }

    public final String getIp() {
        return this.f614ip;
    }

    public final int getIsbuildin() {
        return this.isbuildin;
    }

    public final int getIsroot() {
        return this.isroot;
    }

    public final short getLang() {
        return this.lang;
    }

    public final String getLc() {
        return this.f615lc;
    }

    public final String getPhone() {
        return this.phone;
    }

    public final int getProduct() {
        return this.product;
    }

    public final String getQq() {
        return this.f616qq;
    }

    public final int getSdkversion() {
        return this.sdkversion;
    }

    public final String getUa() {
        return this.f617ua;
    }

    public final String getUuid() {
        return this.uuid;
    }

    public final ProductVersion getVersion() {
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
        this.imei = jceInputStream.readString(0, true);
        this.f616qq = jceInputStream.readString(1, false);
        this.phone = jceInputStream.readString(2, false);
        this.f614ip = jceInputStream.readString(3, false);
        this.f615lc = jceInputStream.readString(4, false);
        this.channelid = jceInputStream.readString(5, false);
        this.f617ua = jceInputStream.readString(6, false);
        this.f613ct = jceInputStream.read(this.f613ct, 7, false);
        this.product = jceInputStream.read(this.product, 8, false);
        if (f611a == null) {
            f611a = new ProductVersion();
        }
        this.version = (ProductVersion) jceInputStream.read((JceStruct) f611a, 9, false);
        this.guid = jceInputStream.readString(10, false);
        this.imsi = jceInputStream.readString(11, false);
        this.isbuildin = jceInputStream.read(this.isbuildin, 12, false);
        this.isroot = jceInputStream.read(this.isroot, 13, false);
        this.sdkversion = jceInputStream.read(this.sdkversion, 14, false);
        this.buildno = jceInputStream.read(this.buildno, 15, false);
        this.uuid = jceInputStream.readString(16, false);
        this.lang = jceInputStream.read(this.lang, 17, false);
    }

    public final void setBuildno(int i) {
        this.buildno = i;
    }

    public final void setChannelid(String str) {
        this.channelid = str;
    }

    public final void setCt(int i) {
        this.f613ct = i;
    }

    public final void setGuid(String str) {
        this.guid = str;
    }

    public final void setImei(String str) {
        this.imei = str;
    }

    public final void setImsi(String str) {
        this.imsi = str;
    }

    public final void setIp(String str) {
        this.f614ip = str;
    }

    public final void setIsbuildin(int i) {
        this.isbuildin = i;
    }

    public final void setIsroot(int i) {
        this.isroot = i;
    }

    public final void setLang(short s) {
        this.lang = s;
    }

    public final void setLc(String str) {
        this.f615lc = str;
    }

    public final void setPhone(String str) {
        this.phone = str;
    }

    public final void setProduct(int i) {
        this.product = i;
    }

    public final void setQq(String str) {
        this.f616qq = str;
    }

    public final void setSdkversion(int i) {
        this.sdkversion = i;
    }

    public final void setUa(String str) {
        this.f617ua = str;
    }

    public final void setUuid(String str) {
        this.uuid = str;
    }

    public final void setVersion(ProductVersion productVersion) {
        this.version = productVersion;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.imei, 0);
        if (this.f616qq != null) {
            jceOutputStream.write(this.f616qq, 1);
        }
        if (this.phone != null) {
            jceOutputStream.write(this.phone, 2);
        }
        if (this.f614ip != null) {
            jceOutputStream.write(this.f614ip, 3);
        }
        if (this.f615lc != null) {
            jceOutputStream.write(this.f615lc, 4);
        }
        if (this.channelid != null) {
            jceOutputStream.write(this.channelid, 5);
        }
        if (this.f617ua != null) {
            jceOutputStream.write(this.f617ua, 6);
        }
        jceOutputStream.write(this.f613ct, 7);
        jceOutputStream.write(this.product, 8);
        if (this.version != null) {
            jceOutputStream.write((JceStruct) this.version, 9);
        }
        if (this.guid != null) {
            jceOutputStream.write(this.guid, 10);
        }
        if (this.imsi != null) {
            jceOutputStream.write(this.imsi, 11);
        }
        jceOutputStream.write(this.isbuildin, 12);
        jceOutputStream.write(this.isroot, 13);
        jceOutputStream.write(this.sdkversion, 14);
        jceOutputStream.write(this.buildno, 15);
        if (this.uuid != null) {
            jceOutputStream.write(this.uuid, 16);
        }
        jceOutputStream.write(this.lang, 17);
    }
}
