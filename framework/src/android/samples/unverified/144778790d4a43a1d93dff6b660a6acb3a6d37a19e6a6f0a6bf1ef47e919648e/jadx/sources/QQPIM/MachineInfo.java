package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.wupsession.WupConfig;

/* JADX INFO: loaded from: classes.dex */
public final class MachineInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static PhoneType f432a;

    /* JADX INFO: renamed from: b */
    static ProductVersion f433b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f434c;
    public int buildno;
    public String channelid;

    /* JADX INFO: renamed from: ct */
    public int f435ct;
    public String guid;
    public String imei;
    public String imsi;

    /* JADX INFO: renamed from: ip */
    public String f436ip;
    public int isbuildin;
    public int isroot;
    public short lang;

    /* JADX INFO: renamed from: lc */
    public String f437lc;
    public String machine;
    public PhoneType phonetype;
    public int product;
    public int sdkversion;

    /* JADX INFO: renamed from: sp */
    public int f438sp;
    public String uuid;
    public ProductVersion version;

    static {
        f434c = !MachineInfo.class.desiredAssertionStatus();
    }

    public MachineInfo() {
        this.f437lc = "";
        this.imei = "";
        this.f438sp = 0;
        this.product = 0;
        this.channelid = "";
        this.f436ip = "";
        this.phonetype = null;
        this.machine = "";
        this.imsi = "";
        this.isbuildin = 0;
        this.isroot = 0;
        this.f435ct = ConnectType.CT_NONE.value();
        this.version = null;
        this.guid = "";
        this.sdkversion = 0;
        this.buildno = 0;
        this.uuid = "";
        this.lang = (short) 0;
        this.f437lc = this.f437lc;
        this.imei = this.imei;
        this.f438sp = this.f438sp;
        this.product = this.product;
        this.channelid = this.channelid;
        this.f436ip = this.f436ip;
        this.phonetype = this.phonetype;
        this.machine = this.machine;
        this.imsi = this.imsi;
        this.isbuildin = this.isbuildin;
        this.isroot = this.isroot;
        this.f435ct = this.f435ct;
        this.version = this.version;
        this.guid = this.guid;
        this.sdkversion = this.sdkversion;
        this.buildno = this.buildno;
        this.uuid = this.uuid;
        this.lang = this.lang;
    }

    public MachineInfo(String str, String str2, int i, int i2, String str3, String str4, PhoneType phoneType, String str5, String str6, int i3, int i4, int i5, ProductVersion productVersion, String str7, int i6, int i7, String str8, short s) {
        this.f437lc = "";
        this.imei = "";
        this.f438sp = 0;
        this.product = 0;
        this.channelid = "";
        this.f436ip = "";
        this.phonetype = null;
        this.machine = "";
        this.imsi = "";
        this.isbuildin = 0;
        this.isroot = 0;
        this.f435ct = ConnectType.CT_NONE.value();
        this.version = null;
        this.guid = "";
        this.sdkversion = 0;
        this.buildno = 0;
        this.uuid = "";
        this.lang = (short) 0;
        this.f437lc = str;
        this.imei = str2;
        this.f438sp = i;
        this.product = i2;
        this.channelid = str3;
        this.f436ip = str4;
        this.phonetype = phoneType;
        this.machine = str5;
        this.imsi = str6;
        this.isbuildin = i3;
        this.isroot = i4;
        this.f435ct = i5;
        this.version = productVersion;
        this.guid = str7;
        this.sdkversion = i6;
        this.buildno = i7;
        this.uuid = str8;
        this.lang = s;
    }

    public final String className() {
        return "QQPIM.MachineInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f434c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.f437lc, TMSApplication.CON_LC);
        jceDisplayer.display(this.imei, "imei");
        jceDisplayer.display(this.f438sp, "sp");
        jceDisplayer.display(this.product, TMSApplication.CON_PRODUCT);
        jceDisplayer.display(this.channelid, "channelid");
        jceDisplayer.display(this.f436ip, "ip");
        jceDisplayer.display((JceStruct) this.phonetype, "phonetype");
        jceDisplayer.display(this.machine, "machine");
        jceDisplayer.display(this.imsi, "imsi");
        jceDisplayer.display(this.isbuildin, "isbuildin");
        jceDisplayer.display(this.isroot, "isroot");
        jceDisplayer.display(this.f435ct, "ct");
        jceDisplayer.display((JceStruct) this.version, "version");
        jceDisplayer.display(this.guid, WupConfig.KEY_GUID);
        jceDisplayer.display(this.sdkversion, "sdkversion");
        jceDisplayer.display(this.buildno, "buildno");
        jceDisplayer.display(this.uuid, "uuid");
        jceDisplayer.display(this.lang, "lang");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        MachineInfo machineInfo = (MachineInfo) obj;
        return JceUtil.equals(this.f437lc, machineInfo.f437lc) && JceUtil.equals(this.imei, machineInfo.imei) && JceUtil.equals(this.f438sp, machineInfo.f438sp) && JceUtil.equals(this.product, machineInfo.product) && JceUtil.equals(this.channelid, machineInfo.channelid) && JceUtil.equals(this.f436ip, machineInfo.f436ip) && JceUtil.equals(this.phonetype, machineInfo.phonetype) && JceUtil.equals(this.machine, machineInfo.machine) && JceUtil.equals(this.imsi, machineInfo.imsi) && JceUtil.equals(this.isbuildin, machineInfo.isbuildin) && JceUtil.equals(this.isroot, machineInfo.isroot) && JceUtil.equals(this.f435ct, machineInfo.f435ct) && JceUtil.equals(this.version, machineInfo.version) && JceUtil.equals(this.guid, machineInfo.guid) && JceUtil.equals(this.sdkversion, machineInfo.sdkversion) && JceUtil.equals(this.buildno, machineInfo.buildno) && JceUtil.equals(this.uuid, machineInfo.uuid) && JceUtil.equals(this.lang, machineInfo.lang);
    }

    public final String fullClassName() {
        return "QQPIM.MachineInfo";
    }

    public final int getBuildno() {
        return this.buildno;
    }

    public final String getChannelid() {
        return this.channelid;
    }

    public final int getCt() {
        return this.f435ct;
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
        return this.f436ip;
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
        return this.f437lc;
    }

    public final String getMachine() {
        return this.machine;
    }

    public final PhoneType getPhonetype() {
        return this.phonetype;
    }

    public final int getProduct() {
        return this.product;
    }

    public final int getSdkversion() {
        return this.sdkversion;
    }

    public final int getSp() {
        return this.f438sp;
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
        this.f437lc = jceInputStream.readString(0, true);
        this.imei = jceInputStream.readString(1, true);
        this.f438sp = jceInputStream.read(this.f438sp, 2, true);
        this.product = jceInputStream.read(this.product, 3, false);
        this.channelid = jceInputStream.readString(4, false);
        this.f436ip = jceInputStream.readString(5, false);
        if (f432a == null) {
            f432a = new PhoneType();
        }
        this.phonetype = (PhoneType) jceInputStream.read((JceStruct) f432a, 6, false);
        this.machine = jceInputStream.readString(7, false);
        this.imsi = jceInputStream.readString(8, false);
        this.isbuildin = jceInputStream.read(this.isbuildin, 9, false);
        this.isroot = jceInputStream.read(this.isroot, 10, false);
        this.f435ct = jceInputStream.read(this.f435ct, 11, false);
        if (f433b == null) {
            f433b = new ProductVersion();
        }
        this.version = (ProductVersion) jceInputStream.read((JceStruct) f433b, 12, false);
        this.guid = jceInputStream.readString(13, false);
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
        this.f435ct = i;
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
        this.f436ip = str;
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
        this.f437lc = str;
    }

    public final void setMachine(String str) {
        this.machine = str;
    }

    public final void setPhonetype(PhoneType phoneType) {
        this.phonetype = phoneType;
    }

    public final void setProduct(int i) {
        this.product = i;
    }

    public final void setSdkversion(int i) {
        this.sdkversion = i;
    }

    public final void setSp(int i) {
        this.f438sp = i;
    }

    public final void setUuid(String str) {
        this.uuid = str;
    }

    public final void setVersion(ProductVersion productVersion) {
        this.version = productVersion;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.f437lc, 0);
        jceOutputStream.write(this.imei, 1);
        jceOutputStream.write(this.f438sp, 2);
        jceOutputStream.write(this.product, 3);
        if (this.channelid != null) {
            jceOutputStream.write(this.channelid, 4);
        }
        if (this.f436ip != null) {
            jceOutputStream.write(this.f436ip, 5);
        }
        if (this.phonetype != null) {
            jceOutputStream.write((JceStruct) this.phonetype, 6);
        }
        if (this.machine != null) {
            jceOutputStream.write(this.machine, 7);
        }
        if (this.imsi != null) {
            jceOutputStream.write(this.imsi, 8);
        }
        jceOutputStream.write(this.isbuildin, 9);
        jceOutputStream.write(this.isroot, 10);
        jceOutputStream.write(this.f435ct, 11);
        if (this.version != null) {
            jceOutputStream.write((JceStruct) this.version, 12);
        }
        if (this.guid != null) {
            jceOutputStream.write(this.guid, 13);
        }
        jceOutputStream.write(this.sdkversion, 14);
        jceOutputStream.write(this.buildno, 15);
        if (this.uuid != null) {
            jceOutputStream.write(this.uuid, 16);
        }
        jceOutputStream.write(this.lang, 17);
    }
}
