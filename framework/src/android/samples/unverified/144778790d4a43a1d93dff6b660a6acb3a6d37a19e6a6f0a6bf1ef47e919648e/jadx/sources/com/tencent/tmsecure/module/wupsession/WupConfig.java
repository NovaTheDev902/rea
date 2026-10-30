package com.tencent.tmsecure.module.wupsession;

import QQPIM.ConnectType;
import QQPIM.DeviceInfo;
import QQPIM.GUIDInfo;
import QQPIM.MachineInfo;
import QQPIM.PhoneType;
import QQPIM.ProductVersion;
import QQPIM.SPhoneType;
import QQPIM.SUIKey;
import QQPIM.SUserInfo;
import QQPIM.UserInfo;
import android.content.Context;
import com.lenovo.performancecenter.LeemCenterTools;
import com.lenovo.safecenter.mmsutils.CharacterSets;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.safemode.SofeModeMain;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.utils.EnvUtil;
import com.tencent.tmsecure.utils.NetworkUtil;
import com.tencent.tmsecure.utils.PhoneInfoUtil;
import com.tencent.tmsecure.utils.SDKUtil;
import com.tencent.tmsecure.utils.StringUtil;
import java.util.concurrent.atomic.AtomicReference;
import tms.C1149af;
import tms.C1315hb;

/* JADX INFO: loaded from: classes.dex */
public final class WupConfig {
    public static final String KEY_GUID = "guid";
    public static final int RQ_BROWER_CHECK = 38;
    public static final int RQ_CHECK_LICENCE = 39;
    public static final int RQ_CHECK_URL = 36;
    public static final int RQ_CHECK_URL_EX = 37;
    public static final int RQ_GET_ADS = 17;
    public static final int RQ_GET_ANALYSE_INFO = 11;
    public static final int RQ_GET_CATEGORY_LIST = 8;
    public static final int RQ_GET_CHANGE_URL = 22;
    public static final int RQ_GET_CONFIG = 23;
    public static final int RQ_GET_CONFIG_V3 = 24;
    public static final int RQ_GET_CONFIG_V3_CPT = 25;
    public static final int RQ_GET_GUID = 18;
    public static final int RQ_GET_HOT_WORD = 19;
    public static final int RQ_GET_MARK = 40;
    public static final int RQ_GET_MY_SOFT_LIST = 10;
    public static final int RQ_GET_QUERY_INFO = 33;
    public static final int RQ_GET_SOFT_INFO = 0;
    public static final int RQ_GET_SOFT_LIST = 9;
    public static final int RQ_GET_TIME = 16;
    public static final int RQ_GET_TRAFFIC_CMD = 34;
    public static final int RQ_GET_TRAFFIC_TEMPLATE = 32;
    public static final int RQ_GET_UPDATES_V2 = 12;
    public static final int RQ_GET_VIRUS_INFOS = 7;
    public static final int RQ_REPORT_CHANNEL_INFO = 5;
    public static final int RQ_REPORT_DOWN_SOFT = 14;
    public static final int RQ_REPORT_ERROR_MSG = 35;
    public static final int RQ_REPORT_FBILLEGA_REASON = 4;
    public static final int RQ_REPORT_MOBILE = 26;
    public static final int RQ_REPORT_NOTIFY_INFO = 21;
    public static final int RQ_REPORT_SMS = 28;
    public static final int RQ_REPORT_SOFT_ACTION = 20;
    public static final int RQ_REPORT_SOFT_DESC = 15;
    public static final int RQ_REPORT_SOFT_FEATURE = 30;
    public static final int RQ_REPORT_SOFT_TYPE = 1;
    public static final int RQ_REPORT_SOFT_USAGE_INFO = 31;
    public static final int RQ_REPORT_TEL = 29;
    public static final int RQ_REPORT_TIPS_RES = 13;
    public static final int RQ_REPORT_UNKNOW_SOFT_INFO = 3;
    public static final int RQ_REPORT_USER_COMMENT = 2;
    public static final int RQ_REPORT_VIRUS_LIB_UPDATE = 6;
    public static final int RQ_REPORT_WBLIST = 27;

    /* JADX INFO: renamed from: d */
    private String f6242d;

    /* JADX INFO: renamed from: e */
    private String f6243e;

    /* JADX INFO: renamed from: f */
    private Context f6244f;

    /* JADX INFO: renamed from: h */
    private PhoneType f6246h;

    /* JADX INFO: renamed from: i */
    private SPhoneType f6247i;

    /* JADX INFO: renamed from: j */
    private UserInfo f6248j;

    /* JADX INFO: renamed from: k */
    private SUserInfo f6249k;

    /* JADX INFO: renamed from: l */
    private DeviceInfo f6250l;

    /* JADX INFO: renamed from: m */
    private MachineInfo f6251m;

    /* JADX INFO: renamed from: n */
    private SUIKey f6252n;
    public static final String HOST_URL = TMSApplication.getStrFromEnvMap(TMSApplication.CON_HOST_URL);
    public static String REDIRECT_URL = null;
    public static final String gQua = "AQQSecure_GA_2_0/011201&ADR&" + PhoneInfoUtil.getModelName() + "&V2";

    /* JADX INFO: renamed from: a */
    private static String f6239a = null;
    public static C1315hb[] mWupParam = {new C1315hb(0, "info", "getSoftInfo"), new C1315hb(1, "info", "reportSoftType"), new C1315hb(2, "info", "reportUserComment"), new C1315hb(3, "info", "reportUnknowSoftInfo"), new C1315hb(4, "info", "reportFBIllegaReason"), new C1315hb(5, "info", "reportChannelInfo"), new C1315hb(6, "info", "reportVirusLibUpdate"), new C1315hb(7, "info", "getVirusInfos"), new C1315hb(8, "info", "getCategoryList"), new C1315hb(9, "info", "getSoftList"), new C1315hb(10, "info", "getMySoftList"), new C1315hb(11, "info", "getAnalyseInfo"), new C1315hb(12, "info", "getUpdatesV2"), new C1315hb(13, "info", "reportTipsRes"), new C1315hb(14, "info", "reportDownSoft"), new C1315hb(15, "info", "reportSoftDesc"), new C1315hb(16, "info", "getTime"), new C1315hb(17, "info", "getADs"), new C1315hb(18, "info", "getGuid"), new C1315hb(19, "info", "getHotWord"), new C1315hb(20, "info", "reportSoftAction"), new C1315hb(21, "info", "reportNotifyInfo"), new C1315hb(22, "info", "getChangeUrl"), new C1315hb(23, "conf", "getConfig"), new C1315hb(24, "conf", "getConfigV3"), new C1315hb(25, "conf", "getConfigV3CPT"), new C1315hb(26, "conf", "reportMobile"), new C1315hb(27, "conf", "reportWBList"), new C1315hb(28, SofeModeMain.TS_SMS, "reportSms"), new C1315hb(29, SofeModeMain.TS_SMS, "reportTel"), new C1315hb(30, SofeModeMain.TS_SMS, "reportSoftFeature"), new C1315hb(31, "report", "reportSoftUsageInfo"), new C1315hb(32, TrafficStatsService.TRAFFIC, "getTrafficTemplate"), new C1315hb(33, TrafficStatsService.TRAFFIC, "getQueryInfo"), new C1315hb(34, TrafficStatsService.TRAFFIC, "getCloudOrder"), new C1315hb(35, TrafficStatsService.TRAFFIC, "reportErrorMsg"), new C1315hb(36, LeemCenterTools.LAST_CHECKUP_SHAREDPREFERENCE, "checkUrl"), new C1315hb(37, LeemCenterTools.LAST_CHECKUP_SHAREDPREFERENCE, "checkUrlExt"), new C1315hb(37, "info", "browerCheck"), new C1315hb(39, LeemCenterTools.LAST_CHECKUP_SHAREDPREFERENCE, "getlicencedate"), new C1315hb(40, "benchmark", "getMark")};

    /* JADX INFO: renamed from: b */
    private final String f6240b = "imei";

    /* JADX INFO: renamed from: c */
    private final String f6241c = "mac";

    /* JADX INFO: renamed from: g */
    private C1149af f6245g = new C1149af("wup");

    public WupConfig(Context context) {
        this.f6242d = null;
        this.f6243e = null;
        this.f6244f = context;
        if (f6239a == null) {
            f6239a = this.f6245g.m2883a(KEY_GUID, (String) null);
        }
        this.f6242d = StringUtil.assertNotNullString(PhoneInfoUtil.getIMEI(this.f6244f));
        this.f6243e = StringUtil.assertNotNullString(PhoneInfoUtil.getMAC(this.f6244f));
    }

    /* JADX INFO: renamed from: a */
    private DeviceInfo m2628a() {
        if (this.f6250l == null) {
            this.f6250l = new DeviceInfo();
            this.f6250l.setImei(this.f6242d);
            this.f6250l.setImsi(StringUtil.assertNotNullString(PhoneInfoUtil.getIMSI(this.f6244f)));
            this.f6250l.setMac(this.f6243e);
            this.f6250l.setIccid(StringUtil.assertNotNullString(PhoneInfoUtil.getICCID(this.f6244f)));
            this.f6250l.setAndroidid(StringUtil.assertNotNullString(PhoneInfoUtil.getAndoidId()));
            this.f6250l.setSdkversion(SDKUtil.getSDKVersion());
            this.f6250l.setModel(StringUtil.assertNotNullString(PhoneInfoUtil.getModelName()));
            this.f6250l.setProduct(StringUtil.assertNotNullString(PhoneInfoUtil.getProductName()));
            this.f6250l.setNetfile(StringUtil.assertNotNullString(EnvUtil.getDeviceInfoStr(this.f6244f)));
            this.f6250l.setLguid(f6239a);
        } else {
            this.f6250l.setLguid(f6239a);
            this.f6250l.setImei(this.f6242d);
            this.f6250l.setMac(this.f6243e);
        }
        return this.f6250l;
    }

    /* JADX INFO: renamed from: b */
    private int m2629b() {
        GUIDInfo gUIDInfo;
        DeviceInfo deviceInfoM2628a = m2628a();
        AtomicReference<GUIDInfo> atomicReference = new AtomicReference<>();
        int guidFromServer = ((WupSessionManager) ManagerCreator.getManager(WupSessionManager.class)).getGuidFromServer(deviceInfoM2628a, atomicReference);
        if (guidFromServer == 0 && (gUIDInfo = atomicReference.get()) != null) {
            f6239a = gUIDInfo.getGuid();
            if (f6239a == null || f6239a.equals("")) {
                return -2001;
            }
        }
        return guidFromServer;
    }

    /* JADX INFO: renamed from: c */
    private boolean m2630c() {
        String strAssertNotNullString = StringUtil.assertNotNullString(PhoneInfoUtil.getIMEI(this.f6244f));
        String strAssertNotNullString2 = StringUtil.assertNotNullString(PhoneInfoUtil.getMAC(this.f6244f));
        this.f6242d = this.f6245g.m2883a("imei", strAssertNotNullString);
        this.f6243e = this.f6245g.m2883a("mac", strAssertNotNullString2);
        if (strAssertNotNullString.equals(this.f6242d) && strAssertNotNullString2.equals(this.f6243e)) {
            return false;
        }
        this.f6242d = strAssertNotNullString;
        this.f6243e = strAssertNotNullString2;
        return true;
    }

    public static String getFuncName(int i) {
        return mWupParam[i].f7441c;
    }

    public static String getServantName(int i) {
        return mWupParam[i].f7440b;
    }

    public final int checkGuid() {
        if (f6239a == null || f6239a.equals("") || m2630c()) {
            int iM2629b = m2629b();
            if (iM2629b != 0) {
                return iM2629b;
            }
            this.f6245g.m2888a("imei", this.f6242d, false);
            this.f6245g.m2888a("mac", this.f6243e, false);
            this.f6245g.m2888a(KEY_GUID, f6239a, false);
            this.f6245g.m2884a();
        }
        return 0;
    }

    public final MachineInfo getMachineInfo() {
        if (this.f6251m == null) {
            this.f6251m = new MachineInfo();
            this.f6251m.setGuid(f6239a);
            this.f6251m.setLc(StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_LC)));
            this.f6251m.setImei(this.f6242d);
            this.f6251m.setSp(PhoneInfoUtil.getNetworkOperatorCode(this.f6244f));
            this.f6251m.setProduct(TMSApplication.getIntFromEnvMap(TMSApplication.CON_PRODUCT));
            this.f6251m.setChannelid(StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_CHANNEL)));
            this.f6251m.setPhonetype(getPhoneType());
            this.f6251m.setMachine(StringUtil.assertNotNullString(PhoneInfoUtil.getModelName()));
            this.f6251m.setImsi(StringUtil.assertNotNullString(PhoneInfoUtil.getIMSI(this.f6244f)));
            this.f6251m.setIsbuildin(EnvUtil.isBuildIn(this.f6244f) ? 1 : 0);
            this.f6251m.setIsroot(EnvUtil.hadsufile() ? 1 : 0);
        } else {
            this.f6251m.setGuid(f6239a);
            this.f6251m.setImei(this.f6242d);
        }
        return this.f6251m;
    }

    public final PhoneType getPhoneType() {
        if (this.f6246h == null) {
            this.f6246h = new PhoneType();
            this.f6246h.setPhonetype(2);
            this.f6246h.setSubplatform(TMSApplication.getIntFromEnvMap(TMSApplication.CON_SUB_PLATFORM));
        }
        return this.f6246h;
    }

    public final SPhoneType getSPhoneType() {
        if (this.f6247i == null) {
            this.f6247i = new SPhoneType();
            this.f6247i.setPhonetype(2);
        }
        return this.f6247i;
    }

    public final SUIKey getSUIKey() {
        if (this.f6252n == null) {
            this.f6252n = new SUIKey();
            this.f6252n.setGuid(f6239a);
            this.f6252n.setLc(StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_LC)));
            this.f6252n.setName("SECURE");
            this.f6252n.setVersion(StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_SOFTVERSION)));
            this.f6252n.setImei(this.f6242d);
            this.f6252n.setImsi(StringUtil.assertNotNullString(PhoneInfoUtil.getIMSI(this.f6244f)));
            this.f6252n.setType(2);
            this.f6252n.setOsversion(StringUtil.assertNotNullString(SDKUtil.getSDKName()));
            this.f6252n.setMachineuid(StringUtil.assertNotNullString(PhoneInfoUtil.getModelName()));
            this.f6252n.setMachineconf("screen=" + PhoneInfoUtil.getScreenWidth(this.f6244f) + CharacterSets.MIMENAME_ANY_CHARSET + PhoneInfoUtil.getScreenHeight(this.f6244f));
            this.f6252n.setSubplatform(TMSApplication.getIntFromEnvMap(TMSApplication.CON_SUB_PLATFORM));
            this.f6252n.setChannelid(StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_CHANNEL)));
            this.f6252n.setIsbuildin(EnvUtil.isBuildIn(this.f6244f) ? 1 : 0);
        } else {
            this.f6252n.setImei(this.f6242d);
        }
        return this.f6252n;
    }

    public final SUserInfo getSUserInfo() {
        if (this.f6249k == null) {
            this.f6249k = new SUserInfo();
            this.f6249k.setImsi(StringUtil.assertNotNullString(PhoneInfoUtil.getIMSI(this.f6244f)));
            this.f6249k.setImei(this.f6242d);
            this.f6249k.setLc(StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_LC)));
        } else {
            this.f6249k.setImei(this.f6242d);
        }
        return this.f6249k;
    }

    public final UserInfo getUserInfo() {
        if (this.f6248j == null) {
            this.f6248j = new UserInfo();
            this.f6248j.setImei(this.f6242d);
            this.f6248j.setLc(StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_LC)));
            this.f6248j.setChannelid(StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_CHANNEL)));
            this.f6248j.setUa(StringUtil.assertNotNullString(PhoneInfoUtil.getModelName()));
            this.f6248j.setProduct(TMSApplication.getIntFromEnvMap(TMSApplication.CON_PRODUCT));
            int intFromEnvMap = TMSApplication.getIntFromEnvMap(TMSApplication.CON_PVERSION);
            int intFromEnvMap2 = TMSApplication.getIntFromEnvMap(TMSApplication.CON_CVERSION);
            int intFromEnvMap3 = TMSApplication.getIntFromEnvMap(TMSApplication.CON_HOTFIX);
            if (intFromEnvMap == 0) {
                String[] strArrSplit = TMSApplication.getStrFromEnvMap(TMSApplication.CON_SOFTVERSION).trim().split("[\\.]");
                if (strArrSplit.length >= 3) {
                    intFromEnvMap = Integer.parseInt(strArrSplit[0]);
                    intFromEnvMap2 = Integer.parseInt(strArrSplit[1]);
                    intFromEnvMap3 = Integer.parseInt(strArrSplit[2]);
                }
            }
            this.f6248j.setVersion(new ProductVersion(intFromEnvMap, intFromEnvMap2, intFromEnvMap3));
            this.f6248j.setGuid(f6239a);
            this.f6248j.setImsi(StringUtil.assertNotNullString(PhoneInfoUtil.getIMSI(this.f6244f)));
            this.f6248j.setCt(NetworkUtil.getNetworkType() == ConnectType.CT_WIFI ? 2 : 1);
            this.f6248j.setIsbuildin(EnvUtil.isBuildIn(this.f6244f) ? 1 : 0);
            this.f6248j.setIsroot(EnvUtil.hadsufile() ? 1 : 0);
            this.f6248j.setSdkversion(SDKUtil.getSDKVersion());
            this.f6248j.setBuildno(TMSApplication.getIntFromEnvMap(TMSApplication.CON_BUILD));
        } else {
            this.f6248j.setGuid(f6239a);
            this.f6248j.setImei(this.f6242d);
            this.f6248j.setCt(NetworkUtil.getNetworkType() != ConnectType.CT_WIFI ? 1 : 2);
        }
        return this.f6248j;
    }
}
