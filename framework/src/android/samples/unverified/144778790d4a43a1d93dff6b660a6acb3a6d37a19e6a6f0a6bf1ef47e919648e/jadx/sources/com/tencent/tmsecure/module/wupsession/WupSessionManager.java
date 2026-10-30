package com.tencent.tmsecure.module.wupsession;

import QQPIM.ADInfo;
import QQPIM.AnalyseInfo;
import QQPIM.BrowserClient;
import QQPIM.BrowserResult;
import QQPIM.BrowserUrl;
import QQPIM.Category;
import QQPIM.ChangeUrlReqInfo;
import QQPIM.ChangeUrlResInfo;
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
import QQPIM.RespMark;
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
import QQPIM.UrlCheckResponse;
import QQPIM.VECReportError;
import QQPIM.VirusClientInfo;
import QQPIM.VirusInfo;
import QQPIM.VirusServerInfo;
import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.atomic.AtomicReference;
import tms.C1149af;
import tms.C1316hc;

/* JADX INFO: loaded from: classes.dex */
public final class WupSessionManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1316hc f6253a;

    public final int browerCheck(BrowserClient browserClient, BrowserUrl browserUrl, AtomicReference<BrowserResult> atomicReference) {
        return this.f6253a.m3464a(browserClient, browserUrl, atomicReference);
    }

    public final int checkLicence(LicenceInfo licenceInfo, LicenceCheckResult licenceCheckResult) {
        return this.f6253a.m3470a(licenceInfo, licenceCheckResult);
    }

    public final int checkUrl(String str, AtomicReference<UrlCheckResponse> atomicReference) {
        return this.f6253a.m3477a(str, atomicReference);
    }

    public final int checkUrlEx(List<String> list, AtomicReference<RspTemplate> atomicReference) {
        return this.f6253a.m3492b(list, atomicReference);
    }

    public final int getADs(ArrayList<ADInfo> arrayList) {
        return this.f6253a.m3497e(arrayList);
    }

    public final int getAnalyseInfo(List<SoftFeature> list, ArrayList<AnalyseInfo> arrayList) {
        return this.f6253a.m3482a(list, arrayList);
    }

    public final int getCategoryList(String str, AtomicReference<SoftServerInfo> atomicReference, ArrayList<Category> arrayList) {
        return this.f6253a.m3478a(str, atomicReference, arrayList);
    }

    public final int getChangeUrl(ChangeUrlReqInfo changeUrlReqInfo, AtomicReference<ChangeUrlResInfo> atomicReference) {
        return this.f6253a.m3465a(changeUrlReqInfo, atomicReference);
    }

    public final int getConfigV3(ArrayList<ConfInfo> arrayList, ArrayList<ConfSrc> arrayList2, AtomicReference<TipInfo> atomicReference) {
        return this.f6253a.m3480a(arrayList, arrayList2, atomicReference);
    }

    public final int getConfigV3CPT(ArrayList<ConfInfo> arrayList, ArrayList<ConfSrc> arrayList2, AtomicReference<TipInfo> atomicReference) {
        return this.f6253a.m3490b(arrayList, arrayList2, atomicReference);
    }

    public final String getGuid() {
        return new C1149af("wup").m2883a(WupConfig.KEY_GUID, (String) null);
    }

    public final int getGuidFromServer(DeviceInfo deviceInfo, AtomicReference<GUIDInfo> atomicReference) {
        return this.f6253a.m3467a(deviceInfo, atomicReference);
    }

    public final int getHotWord(HotWordReqInfo hotWordReqInfo, AtomicReference<HotWordResInfo> atomicReference) {
        return this.f6253a.m3469a(hotWordReqInfo, atomicReference);
    }

    public final int getMark(PhoneInfo phoneInfo, AtomicReference<RespMark> atomicReference) {
        return this.f6253a.m3471a(phoneInfo, atomicReference);
    }

    public final int getMySoftList(List<SoftKey> list, AtomicReference<SoftServerInfo> atomicReference, ArrayList<MySoftSimpleInfo> arrayList) {
        return this.f6253a.m3484a(list, atomicReference, arrayList);
    }

    public final int getOperatorDataSyncInfo(STQuery sTQuery, AtomicReference<STQueryResult> atomicReference) {
        return this.f6253a.m3473a(sTQuery, atomicReference);
    }

    public final int getSoftList(String str, AtomicReference<SoftServerInfo> atomicReference, ArrayList<SoftSimpleInfo> arrayList) {
        return this.f6253a.m3488b(str, atomicReference, arrayList);
    }

    public final int getTime(AtomicReference<ServerInfo> atomicReference) {
        return this.f6253a.m3486a(atomicReference);
    }

    public final int getTrafficCmd(STCloudOrderReq sTCloudOrderReq, AtomicReference<STVecCloudBak> atomicReference) {
        return this.f6253a.m3472a(sTCloudOrderReq, atomicReference);
    }

    public final int getTrafficTemplate(STSmsInfo sTSmsInfo, AtomicReference<STTrafficTemplate> atomicReference, AtomicReference<STRetInfo> atomicReference2) {
        return this.f6253a.m3474a(sTSmsInfo, atomicReference, atomicReference2);
    }

    public final int getUpdatesV2(List<ClientVersionInfo> list, AtomicReference<ServerCmdInfo> atomicReference) {
        return this.f6253a.m3483a(list, atomicReference);
    }

    public final int getVirusInfos(VirusClientInfo virusClientInfo, AtomicReference<VirusServerInfo> atomicReference, ArrayList<VirusInfo> arrayList) {
        return this.f6253a.m3476a(virusClientInfo, atomicReference, arrayList);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6253a = new C1316hc();
        this.f6253a.onCreate(context);
        setImpl(this.f6253a);
    }

    public final int reportChannelInfo() {
        return this.f6253a.m3463a();
    }

    public final int reportDownSoft(DownInfo downInfo) {
        return this.f6253a.m3468a(downInfo);
    }

    public final int reportFBIllegaReason(ArrayList<FBIllegaSoft> arrayList) {
        return this.f6253a.m3493c(arrayList);
    }

    public final int reportMobile(ArrayList<FBMobile> arrayList) {
        return this.f6253a.m3499f(arrayList);
    }

    public final int reportNotifyInfo(List<NotifyInfo> list) {
        return this.f6253a.m3498e(list);
    }

    public final int reportOperatorDataSyncErrorMsg(VECReportError vECReportError, AtomicReference<STReportBack> atomicReference) {
        return this.f6253a.m3475a(vECReportError, atomicReference);
    }

    public final int reportSms(List<SmsReport> list) {
        return this.f6253a.m3481a(list);
    }

    public final int reportSoftAction(List<SoftAction> list) {
        return this.f6253a.m3496d(list);
    }

    public final int reportSoftDesc(ArrayList<FBSoftDesc> arrayList) {
        return this.f6253a.m3495d(arrayList);
    }

    public final int reportSoftFeature(List<SoftFeature> list) {
        return this.f6253a.m3494c(list);
    }

    public final int reportSoftType(Map<SoftKey, MalSoftType> map) {
        return this.f6253a.m3485a(map);
    }

    public final int reportSoftUsageInfo(ArrayList<SUI> arrayList) {
        return this.f6253a.m3501h(arrayList);
    }

    public final int reportTel(List<TelReport> list) {
        return this.f6253a.m3491b(list);
    }

    public final int reportTipsRes(CmdInfoRes cmdInfoRes) {
        return this.f6253a.m3466a(cmdInfoRes);
    }

    public final int reportUnknowSoftInfo(ArrayList<UnknownSoftInfo> arrayList) {
        return this.f6253a.m3489b(arrayList);
    }

    public final int reportUserComment(ArrayList<CommentInfo> arrayList) {
        return this.f6253a.m3479a(arrayList);
    }

    public final int reportVirusLibUpdate() {
        return this.f6253a.m3487b();
    }

    public final int reportWBList(ArrayList<FBWBList> arrayList) {
        return this.f6253a.m3500g(arrayList);
    }
}
