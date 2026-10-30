package tms;

import QQPIM.ADInfo;
import QQPIM.AnalyseInfo;
import QQPIM.BrowserClient;
import QQPIM.BrowserResult;
import QQPIM.BrowserUrl;
import QQPIM.Category;
import QQPIM.ChangeUrlReqInfo;
import QQPIM.ChangeUrlResInfo;
import QQPIM.ChannelInfo;
import QQPIM.ClientVersionInfo;
import QQPIM.CmdInfoRes;
import QQPIM.CommentInfo;
import QQPIM.ConfInfo;
import QQPIM.ConfSrc;
import QQPIM.DeviceInfo;
import QQPIM.DownInfo;
import QQPIM.FBIllegaSoft;
import QQPIM.FBMobile;
import QQPIM.FBSoftDesc;
import QQPIM.FBWBList;
import QQPIM.GUIDInfo;
import QQPIM.HotWordReqInfo;
import QQPIM.HotWordResInfo;
import QQPIM.LicenceCheckResult;
import QQPIM.LicenceInfo;
import QQPIM.MalSoftType;
import QQPIM.MySoftSimpleInfo;
import QQPIM.NotifyInfo;
import QQPIM.PhoneInfo;
import QQPIM.RequestTemplate;
import QQPIM.RespMark;
import QQPIM.RetInfo;
import QQPIM.RspTemplate;
import QQPIM.STCloudOrderReq;
import QQPIM.STQuery;
import QQPIM.STQueryResult;
import QQPIM.STReportBack;
import QQPIM.STRetInfo;
import QQPIM.STSmsInfo;
import QQPIM.STTrafficTemplate;
import QQPIM.STVecCloudBak;
import QQPIM.SUI;
import QQPIM.ServerCmdInfo;
import QQPIM.ServerInfo;
import QQPIM.SmsReport;
import QQPIM.SoftAction;
import QQPIM.SoftFeature;
import QQPIM.SoftKey;
import QQPIM.SoftServerInfo;
import QQPIM.SoftSimpleInfo;
import QQPIM.TelReport;
import QQPIM.TipInfo;
import QQPIM.UnknownSoftInfo;
import QQPIM.UrlCheckRequest;
import QQPIM.UrlCheckResponse;
import QQPIM.VECReportError;
import QQPIM.VirusClientInfo;
import QQPIM.VirusInfo;
import QQPIM.VirusServerInfo;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.p012qq.jce.wup.UniPacket;
import com.tencent.tccdb.TccCryptor;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ErrorCode;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.exception.NetWorkException;
import com.tencent.tmsecure.exception.NetworkOnMainThreadException;
import com.tencent.tmsecure.module.software.AppEntity;
import com.tencent.tmsecure.module.software.SoftwareManager;
import com.tencent.tmsecure.module.wupsession.WupConfig;
import com.tencent.tmsecure.utils.Log;
import com.tencent.tmsecure.utils.StringUtil;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.atomic.AtomicReference;

/* JADX INFO: renamed from: tms.hc */
/* JADX INFO: loaded from: classes.dex */
public final class C1316hc extends BaseManager {

    /* JADX INFO: renamed from: a */
    public static String f7442a = "WupSessionManagerImpl";

    /* JADX INFO: renamed from: b */
    private Context f7443b;

    /* JADX INFO: renamed from: c */
    private WupConfig f7444c;

    /* JADX INFO: renamed from: d */
    private boolean f7445d;

    /* JADX INFO: renamed from: a */
    private int m3460a(UniPacket uniPacket, UniPacket uniPacket2, int i) {
        uniPacket.setRequestId(i);
        uniPacket.setServantName(WupConfig.getServantName(i));
        uniPacket.setFuncName(WupConfig.getFuncName(i));
        uniPacket.setEncodeName(InterfaceC0079b.f1213a);
        uniPacket2.setEncodeName(InterfaceC0079b.f1213a);
        return this.f7444c.checkGuid();
    }

    /* JADX INFO: renamed from: a */
    private int m3461a(UniPacket uniPacket, UniPacket uniPacket2, boolean z) throws Throwable {
        C1339y c1339yM3623a;
        IllegalArgumentException illegalArgumentException;
        NetWorkException netWorkException;
        int iM3633a;
        C1339y c1339y;
        int i = ErrorCode.ERR_WUP;
        try {
            try {
                byte[] bArrEncrypt = TccCryptor.encrypt(this.f7443b, uniPacket.encode(), (byte[]) null);
                c1339yM3623a = C1339y.m3623a(WupConfig.HOST_URL);
                try {
                    try {
                        c1339yM3623a.m3638b("POST");
                        c1339yM3623a.m3637a(bArrEncrypt);
                        c1339yM3623a.m3641c();
                        AtomicReference<byte[]> atomicReference = new AtomicReference<>();
                        iM3633a = c1339yM3623a.m3633a(false, atomicReference);
                        if (iM3633a != 0) {
                            if (c1339yM3623a != null) {
                                c1339yM3623a.m3645f();
                            }
                            if (!this.f7445d && iM3633a == 0) {
                                TMSApplication.reportChannelInfo();
                            }
                            return iM3633a;
                        }
                        try {
                            byte[] bArr = atomicReference.get();
                            if (!z && bArr != null && bArr.length > 0) {
                                uniPacket2.decode(TccCryptor.decrypt(this.f7443b, bArr, null));
                            }
                            if (c1339yM3623a != null) {
                                c1339yM3623a.m3645f();
                            }
                            if (!this.f7445d) {
                                TMSApplication.reportChannelInfo();
                            }
                            return 0;
                        } catch (NetWorkException e) {
                            netWorkException = e;
                            c1339y = c1339yM3623a;
                            try {
                                int errCode = netWorkException.getErrCode();
                                try {
                                    Log.m2634e(f7442a, "NetWorkException:" + netWorkException.getMessage());
                                    netWorkException.printStackTrace();
                                    if (c1339y != null) {
                                        c1339y.m3645f();
                                    }
                                    if (this.f7445d || errCode != 0) {
                                        return errCode;
                                    }
                                    TMSApplication.reportChannelInfo();
                                    return errCode;
                                } catch (Throwable th) {
                                    c1339yM3623a = c1339y;
                                    i = errCode;
                                    th = th;
                                }
                            } catch (Throwable th2) {
                                th = th2;
                                c1339yM3623a = c1339y;
                                i = iM3633a;
                            }
                        } catch (NetworkOnMainThreadException e2) {
                            throw e2;
                        } catch (Throwable th3) {
                            th = th3;
                            i = iM3633a;
                        }
                    } catch (IllegalArgumentException e3) {
                        illegalArgumentException = e3;
                        try {
                            Log.m2634e(f7442a, "wup agrs error:" + illegalArgumentException.getMessage());
                            illegalArgumentException.printStackTrace();
                            if (c1339yM3623a != null) {
                                c1339yM3623a.m3645f();
                            }
                            if (!this.f7445d) {
                            }
                            return -6057;
                        } catch (Throwable th4) {
                            i = -6057;
                            th = th4;
                        }
                    } catch (Throwable th5) {
                        th = th5;
                        Log.m2634e(f7442a, "wup error:" + th.getMessage());
                        th.printStackTrace();
                        if (c1339yM3623a != null) {
                            c1339yM3623a.m3645f();
                        }
                        if (!this.f7445d) {
                        }
                        return ErrorCode.ERR_WUP;
                    }
                } catch (NetWorkException e4) {
                    netWorkException = e4;
                    iM3633a = -6000;
                    c1339y = c1339yM3623a;
                } catch (NetworkOnMainThreadException e5) {
                    throw e5;
                }
            } catch (Throwable th6) {
                th = th6;
            }
        } catch (NetWorkException e6) {
            netWorkException = e6;
            iM3633a = -6000;
            c1339y = null;
        } catch (NetworkOnMainThreadException e7) {
            throw e7;
        } catch (IllegalArgumentException e8) {
            illegalArgumentException = e8;
            c1339yM3623a = null;
        } catch (Throwable th7) {
            th = th7;
            c1339yM3623a = null;
        }
        if (c1339yM3623a != null) {
            c1339yM3623a.m3645f();
        }
        if (!this.f7445d && i == 0) {
            TMSApplication.reportChannelInfo();
        }
        throw th;
    }

    /* JADX INFO: renamed from: a */
    private static ChannelInfo m3462a(Context context) {
        ChannelInfo channelInfo = new ChannelInfo();
        channelInfo.setId(StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_CHANNEL)));
        channelInfo.setProduct(TMSApplication.getIntFromEnvMap(TMSApplication.CON_PRODUCT));
        PackageManager packageManager = context.getPackageManager();
        channelInfo.setIsbuildin(0);
        try {
            ApplicationInfo applicationInfo = packageManager.getApplicationInfo(context.getPackageName(), 8192);
            if (applicationInfo != null && (applicationInfo.flags & 1) != 0) {
                channelInfo.setIsbuildin(1);
            }
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        } catch (Exception e2) {
        }
        SoftwareManager softwareManager = (SoftwareManager) ManagerCreator.getManager(SoftwareManager.class);
        ArrayList<SoftKey> arrayList = new ArrayList<>();
        for (String str : new String[]{"com.tencent.qqpimsecure", "com.tencent.qq", "com.qzone", "com.tencent.qqphonebook", "com.tencent.mtt", "com.tencent.WBlog", "com.tencent.qqgame.hallinstaller.hall"}) {
            AppEntity appInfo = softwareManager.getAppInfo(str, 25);
            if (appInfo != null) {
                Boolean bool = (Boolean) appInfo.get(AppEntity.KEY_IS_SYSTEM_BOOL);
                Integer num = (Integer) appInfo.get(AppEntity.KEY_VERSION_CODE_INT);
                SoftKey softKey = new SoftKey();
                softKey.setUid(StringUtil.assertNotNullString((String) appInfo.get(AppEntity.KEY_SIGNATURE_MD5_STR)));
                softKey.setSoftname(StringUtil.assertNotNullString((String) appInfo.get("pkgName")));
                softKey.setName(StringUtil.assertNotNullString((String) appInfo.get("appName")));
                softKey.setIsbuildin((bool == null || !bool.booleanValue()) ? 0 : 1);
                softKey.setVersion(StringUtil.assertNotNullString((String) appInfo.get("version")));
                softKey.setVersioncode(num == null ? 0 : num.intValue());
                softKey.setProducttime("");
                softKey.setCert(StringUtil.assertNotNullString((String) appInfo.get(AppEntity.KEY_SIGNATURE_MD5_STR)));
                arrayList.add(softKey);
            }
        }
        channelInfo.setChecksoft(arrayList);
        return channelInfo;
    }

    /* JADX INFO: renamed from: a */
    public final int m3463a() throws Throwable {
        this.f7445d = true;
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 5);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("channelinfo", m3462a(this.f7443b));
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        this.f7445d = false;
        return iM3461a;
    }

    /* JADX INFO: renamed from: a */
    public final int m3464a(BrowserClient browserClient, BrowserUrl browserUrl, AtomicReference<BrowserResult> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 38);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("client", browserClient);
        uniPacket.put("url", browserUrl);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        BrowserResult browserResult = (BrowserResult) uniPacket2.getByClass(QueryPermissions.RECOMMENDEDACTION, new BrowserResult());
        if (browserResult != null) {
            atomicReference.set(browserResult);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3465a(ChangeUrlReqInfo changeUrlReqInfo, AtomicReference<ChangeUrlResInfo> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 22);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("urlreqinfo", changeUrlReqInfo);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        ChangeUrlResInfo changeUrlResInfo = (ChangeUrlResInfo) uniPacket2.getByClass("urlresinfo", new ChangeUrlResInfo());
        if (changeUrlResInfo != null) {
            atomicReference.set(changeUrlResInfo);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3466a(CmdInfoRes cmdInfoRes) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 13);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("cmdinfores", cmdInfoRes);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: a */
    public final int m3467a(DeviceInfo deviceInfo, AtomicReference<GUIDInfo> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        uniPacket.setRequestId(18);
        uniPacket.setServantName(WupConfig.getServantName(18));
        uniPacket.setFuncName(WupConfig.getFuncName(18));
        uniPacket.setEncodeName(InterfaceC0079b.f1213a);
        uniPacket2.setEncodeName(InterfaceC0079b.f1213a);
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("deviceinfo", deviceInfo);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        GUIDInfo gUIDInfo = (GUIDInfo) uniPacket2.getByClass("guidinfo", new GUIDInfo());
        if (gUIDInfo != null) {
            atomicReference.set(gUIDInfo);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3468a(DownInfo downInfo) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 14);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("downinfo", downInfo);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: a */
    public final int m3469a(HotWordReqInfo hotWordReqInfo, AtomicReference<HotWordResInfo> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 19);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("hotwordreq", hotWordReqInfo);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        HotWordResInfo hotWordResInfo = (HotWordResInfo) uniPacket2.getByClass("hotwordres", new HotWordResInfo());
        if (hotWordResInfo != null) {
            atomicReference.set(hotWordResInfo);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3470a(LicenceInfo licenceInfo, LicenceCheckResult licenceCheckResult) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 39);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("licinfo", licenceInfo);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        RetInfo retInfo = (RetInfo) uniPacket2.getByClass("outinfo", new RetInfo());
        if (retInfo == null) {
            return -2;
        }
        licenceCheckResult.value = retInfo;
        Integer num = (Integer) uniPacket2.getByClass("", 0);
        if (num == null) {
            return -2;
        }
        return num.intValue();
    }

    /* JADX INFO: renamed from: a */
    public final int m3471a(PhoneInfo phoneInfo, AtomicReference<RespMark> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 40);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("phoneinfo", phoneInfo);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        RespMark respMark = (RespMark) uniPacket2.getByClass("respmark", new RespMark());
        if (respMark != null) {
            atomicReference.set(respMark);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3472a(STCloudOrderReq sTCloudOrderReq, AtomicReference<STVecCloudBak> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 34);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("cloudreq", sTCloudOrderReq);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        STVecCloudBak sTVecCloudBak = (STVecCloudBak) uniPacket2.getByClass("cloudrsp", new STVecCloudBak());
        if (sTVecCloudBak != null) {
            atomicReference.set(sTVecCloudBak);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3473a(STQuery sTQuery, AtomicReference<STQueryResult> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 33);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("queryParam", sTQuery);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        STQueryResult sTQueryResult = (STQueryResult) uniPacket2.getByClass("queryresult", new STQueryResult());
        if (sTQueryResult != null) {
            atomicReference.set(sTQueryResult);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3474a(STSmsInfo sTSmsInfo, AtomicReference<STTrafficTemplate> atomicReference, AtomicReference<STRetInfo> atomicReference2) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 32);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("smsinfo", sTSmsInfo);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        STTrafficTemplate sTTrafficTemplate = (STTrafficTemplate) uniPacket2.getByClass("traffictemplate", new STTrafficTemplate());
        if (sTTrafficTemplate != null) {
            atomicReference.set(sTTrafficTemplate);
        }
        STRetInfo sTRetInfo = (STRetInfo) uniPacket2.getByClass("stretinfo", new STRetInfo());
        if (atomicReference2 != null) {
            atomicReference2.set(sTRetInfo);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3475a(VECReportError vECReportError, AtomicReference<STReportBack> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 35);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("reportmsg", vECReportError);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        STReportBack sTReportBack = (STReportBack) uniPacket2.getByClass("reportback", new STReportBack());
        if (sTReportBack != null) {
            atomicReference.set(sTReportBack);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3476a(VirusClientInfo virusClientInfo, AtomicReference<VirusServerInfo> atomicReference, ArrayList<VirusInfo> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 7);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("clientinfo", virusClientInfo);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        VirusServerInfo virusServerInfo = (VirusServerInfo) uniPacket2.getByClass("serverinfo", new VirusServerInfo());
        if (virusServerInfo != null) {
            atomicReference.set(virusServerInfo);
        }
        ArrayList arrayList2 = new ArrayList();
        arrayList2.add(new VirusInfo());
        ArrayList arrayList3 = (ArrayList) uniPacket2.getByClass("virusinfos", arrayList2);
        if (arrayList3 != null) {
            arrayList.clear();
            arrayList.addAll(arrayList3);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3477a(String str, AtomicReference<UrlCheckResponse> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 36);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        UrlCheckRequest urlCheckRequest = new UrlCheckRequest();
        urlCheckRequest.url = str;
        uniPacket.put("checkrequest", urlCheckRequest);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        UrlCheckResponse urlCheckResponse = (UrlCheckResponse) uniPacket2.getByClass("checkresponse", new UrlCheckResponse());
        if (urlCheckResponse != null) {
            atomicReference.set(urlCheckResponse);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3478a(String str, AtomicReference<SoftServerInfo> atomicReference, ArrayList<Category> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 8);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("request", str);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        SoftServerInfo softServerInfo = (SoftServerInfo) uniPacket2.getByClass("serverinfo", new SoftServerInfo());
        if (softServerInfo != null) {
            atomicReference.set(softServerInfo);
        }
        ArrayList arrayList2 = new ArrayList();
        arrayList2.add(new Category());
        ArrayList arrayList3 = (ArrayList) uniPacket2.getByClass("categorys", arrayList2);
        if (arrayList3 != null) {
            arrayList.clear();
            arrayList.addAll(arrayList3);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3479a(ArrayList<CommentInfo> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 2);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("usercommentinfo", arrayList);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX WARN: Multi-variable type inference failed */
    /* JADX INFO: renamed from: a */
    public final int m3480a(ArrayList<ConfInfo> arrayList, ArrayList<ConfSrc> arrayList2, AtomicReference<TipInfo> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 24);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("machineinfo", this.f7444c.getMachineInfo());
        uniPacket.put("vecinfo", arrayList);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        ArrayList arrayList3 = new ArrayList();
        arrayList3.add(new ConfSrc());
        ArrayList arrayList4 = (ArrayList) uniPacket2.getByClass("vecsrc", arrayList3);
        if (arrayList4 != null) {
            arrayList2.clear();
            arrayList2.addAll(arrayList4);
        }
        if (atomicReference != 0) {
            atomicReference.set(uniPacket2.getByClass("tipinfo", new TipInfo()));
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3481a(List<SmsReport> list) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 28);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getSPhoneType());
        uniPacket.put("userinfo", this.f7444c.getSUserInfo());
        uniPacket.put("vecSmsReport", list);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: a */
    public final int m3482a(List<SoftFeature> list, ArrayList<AnalyseInfo> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 11);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("vecSoftFeature", list);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        ArrayList arrayList2 = new ArrayList();
        arrayList2.add(new AnalyseInfo());
        ArrayList arrayList3 = (ArrayList) uniPacket2.getByClass("vecAnalyseInfo", arrayList2);
        if (arrayList3 != null) {
            arrayList.clear();
            arrayList.addAll(arrayList3);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3483a(List<ClientVersionInfo> list, AtomicReference<ServerCmdInfo> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 12);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("vecclient", list);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        ServerCmdInfo serverCmdInfo = (ServerCmdInfo) uniPacket2.getByClass("cmdinfo", new ServerCmdInfo());
        if (serverCmdInfo != null) {
            atomicReference.set(serverCmdInfo);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3484a(List<SoftKey> list, AtomicReference<SoftServerInfo> atomicReference, ArrayList<MySoftSimpleInfo> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 10);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("vecsoftkey", list);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        SoftServerInfo softServerInfo = (SoftServerInfo) uniPacket2.getByClass("serverinfo", new SoftServerInfo());
        if (softServerInfo != null) {
            atomicReference.set(softServerInfo);
        }
        ArrayList arrayList2 = new ArrayList();
        arrayList2.add(new MySoftSimpleInfo());
        ArrayList arrayList3 = (ArrayList) uniPacket2.getByClass("softs", arrayList2);
        if (arrayList3 != null) {
            arrayList.clear();
            arrayList.addAll(arrayList3);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final int m3485a(Map<SoftKey, MalSoftType> map) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 1);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("malsofttype", map);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: a */
    public final int m3486a(AtomicReference<ServerInfo> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 16);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        ServerInfo serverInfo = (ServerInfo) uniPacket2.getByClass("serverinfo", new ServerInfo());
        if (serverInfo != null) {
            atomicReference.set(serverInfo);
        }
        return 0;
    }

    /* JADX INFO: renamed from: b */
    public final int m3487b() throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 6);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: b */
    public final int m3488b(String str, AtomicReference<SoftServerInfo> atomicReference, ArrayList<SoftSimpleInfo> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 9);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("request", str);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        SoftServerInfo softServerInfo = (SoftServerInfo) uniPacket2.getByClass("serverinfo", new SoftServerInfo());
        if (softServerInfo != null) {
            atomicReference.set(softServerInfo);
        }
        ArrayList arrayList2 = new ArrayList();
        arrayList2.add(new SoftSimpleInfo());
        ArrayList arrayList3 = (ArrayList) uniPacket2.getByClass("softs", arrayList2);
        if (arrayList3 != null) {
            arrayList.clear();
            arrayList.addAll(arrayList3);
        }
        return 0;
    }

    /* JADX INFO: renamed from: b */
    public final int m3489b(ArrayList<UnknownSoftInfo> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 3);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("vecunknownsoftinfo", arrayList);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX WARN: Multi-variable type inference failed */
    /* JADX INFO: renamed from: b */
    public final int m3490b(ArrayList<ConfInfo> arrayList, ArrayList<ConfSrc> arrayList2, AtomicReference<TipInfo> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 25);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("vecinfo", arrayList);
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        ArrayList arrayList3 = new ArrayList();
        arrayList3.add(new ConfSrc());
        ArrayList arrayList4 = (ArrayList) uniPacket2.getByClass("vecsrc", arrayList3);
        if (arrayList4 != null) {
            arrayList2.clear();
            arrayList2.addAll(arrayList4);
        }
        if (atomicReference != 0) {
            atomicReference.set(uniPacket2.getByClass("tipinfo", new TipInfo()));
        }
        return 0;
    }

    /* JADX INFO: renamed from: b */
    public final int m3491b(List<TelReport> list) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 29);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getSPhoneType());
        uniPacket.put("userinfo", this.f7444c.getSUserInfo());
        uniPacket.put("vecTelReport", list);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: b */
    public final int m3492b(List<String> list, AtomicReference<RspTemplate> atomicReference) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 37);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        int size = list.size();
        ArrayList arrayList = new ArrayList(size);
        for (int i = 0; i < size; i++) {
            arrayList.add(new UrlCheckRequest(list.get(i), null, 0));
        }
        uniPacket.put("reqtemp", new RequestTemplate(arrayList));
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        RspTemplate rspTemplate = (RspTemplate) uniPacket2.getByClass("rsptemp", new RspTemplate());
        if (rspTemplate != null) {
            atomicReference.set(rspTemplate);
        }
        return 0;
    }

    /* JADX INFO: renamed from: c */
    public final int m3493c(ArrayList<FBIllegaSoft> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 4);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("vecillsoft", arrayList);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: c */
    public final int m3494c(List<SoftFeature> list) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 30);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getSPhoneType());
        uniPacket.put("userinfo", this.f7444c.getSUserInfo());
        uniPacket.put("vecSoftFeature", list);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: d */
    public final int m3495d(ArrayList<FBSoftDesc> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 15);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("vecsoftdesc", arrayList);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: d */
    public final int m3496d(List<SoftAction> list) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 20);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("vecsoftaction", list);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: e */
    public final int m3497e(ArrayList<ADInfo> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 17);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        int iM3461a = m3461a(uniPacket, uniPacket2, false);
        if (iM3461a != 0) {
            return iM3461a;
        }
        ArrayList arrayList2 = new ArrayList();
        arrayList2.add(new ADInfo());
        ArrayList arrayList3 = (ArrayList) uniPacket2.getByClass("ads", arrayList2);
        if (arrayList3 != null) {
            arrayList.clear();
            arrayList.addAll(arrayList3);
        }
        return 0;
    }

    /* JADX INFO: renamed from: e */
    public final int m3498e(List<NotifyInfo> list) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 21);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("phonetype", this.f7444c.getPhoneType());
        uniPacket.put("userinfo", this.f7444c.getUserInfo());
        uniPacket.put("vecnotifyinfo", list);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: f */
    public final int m3499f(ArrayList<FBMobile> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 26);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("machineinfo", this.f7444c.getMachineInfo());
        uniPacket.put("vecfb", arrayList);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    /* JADX INFO: renamed from: g */
    public final int m3500g(ArrayList<FBWBList> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 27);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("machineinfo", this.f7444c.getMachineInfo());
        uniPacket.put("vecwblist", arrayList);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    /* JADX INFO: renamed from: h */
    public final int m3501h(ArrayList<SUI> arrayList) throws Throwable {
        UniPacket uniPacket = new UniPacket(true);
        UniPacket uniPacket2 = new UniPacket(true);
        int iM3460a = m3460a(uniPacket, uniPacket2, 31);
        if (iM3460a != 0) {
            return iM3460a;
        }
        uniPacket.put("suikey", this.f7444c.getSUIKey());
        uniPacket.put("vecsui", arrayList);
        int iM3461a = m3461a(uniPacket, uniPacket2, true);
        if (iM3461a == 0) {
            return 0;
        }
        return iM3461a;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7443b = context;
        this.f7444c = new WupConfig(context);
    }
}
