package tms;

import QQPIM.RuleTypeID;
import QQPIM.SmsReport;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.lenovo.safecenter.safemode.SofeModeMain;
import com.tencent.tccdb.MCheckInput;
import com.tencent.tccdb.MMatchSysResult;
import com.tencent.tccdb.MRuleTypeID;
import com.tencent.tccdb.SmsChecker;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.DataEntity;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.MessageHandler;
import com.tencent.tmsecure.common.SDKClient;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.aresengine.AresEngineFactor;
import com.tencent.tmsecure.module.aresengine.DataFilter;
import com.tencent.tmsecure.module.aresengine.DataHandler;
import com.tencent.tmsecure.module.aresengine.DataIntercepter;
import com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder;
import com.tencent.tmsecure.module.aresengine.DataMonitor;
import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.IIntelligentSmsChecker;
import com.tencent.tmsecure.module.aresengine.InComingSmsFilter;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.module.aresengine.TelephonyEntity;
import com.tencent.tmsecure.module.update.UpdateConfig;
import com.tencent.tmsecure.module.wupsession.WupSessionManager;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.atomic.AtomicReference;

/* JADX INFO: renamed from: tms.au */
/* JADX INFO: loaded from: classes.dex */
public final class C1164au extends BaseManager {

    /* JADX INFO: renamed from: a */
    private final HashMap<String, DataIntercepter<? extends TelephonyEntity>> f6855a = new HashMap<>();

    /* JADX INFO: renamed from: b */
    private IIntelligentSmsChecker f6856b;

    /* JADX INFO: renamed from: c */
    private AresEngineFactor f6857c;

    /* JADX INFO: renamed from: tms.au$a */
    final class a implements MessageHandler {
        a() {
        }

        @Override // com.tencent.tmsecure.common.MessageHandler
        public final boolean isMatch(int i) {
            return i == 1 || i == 2 || i == 3;
        }

        /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
        @Override // com.tencent.tmsecure.common.MessageHandler
        public final DataEntity onProcessing(DataEntity dataEntity) {
            boolean z = false;
            int iWhat = dataEntity.what();
            DataEntity dataEntity2 = new DataEntity(iWhat);
            switch (iWhat) {
                case 1:
                    Bundle bundle = dataEntity.bundle();
                    SmsEntity smsEntityM2605a = SmsEntity.m2605a(bundle.getByteArray(SofeModeMain.TS_SMS));
                    DataIntercepter<? extends TelephonyEntity> dataIntercepterM2941a = C1164au.this.m2941a(DataIntercepterBuilder.TYPE_INCOMING_SMS);
                    String string = bundle.getString("event_sender");
                    if (dataIntercepterM2941a != null) {
                        DataMonitor<T> dataMonitor = dataIntercepterM2941a.dataMonitor();
                        if (dataMonitor instanceof C1189bs.a) {
                            ((C1189bs.a) dataMonitor).m3012a(smsEntityM2605a, 2, string);
                        } else {
                            dataMonitor.notifyDataReached(smsEntityM2605a, new Object[0]);
                        }
                    }
                    return dataEntity2;
                case 2:
                    SmsEntity smsEntityM2605a2 = SmsEntity.m2605a(dataEntity.bundle().getByteArray(SofeModeMain.TS_SMS));
                    DataIntercepter<? extends TelephonyEntity> dataIntercepterM2941a2 = C1164au.this.m2941a(DataIntercepterBuilder.TYPE_INCOMING_SMS);
                    DataFilter dataFilter = dataIntercepterM2941a2 != null ? dataIntercepterM2941a2.dataFilter() : null;
                    if (dataIntercepterM2941a2 != null && (dataFilter instanceof InComingSmsFilter)) {
                        DataHandler dataHandler = dataIntercepterM2941a2.dataHandler();
                        dataFilter.m2596a();
                        FilterResult filterResultFilter = dataFilter.filter(smsEntityM2605a2, 1, null);
                        dataFilter.m2597a(dataHandler);
                        if (filterResultFilter != null) {
                            IIntelligentSmsChecker.CheckResult checkResult = (filterResultFilter.mParams == null || filterResultFilter.mParams.length <= 0) ? null : (IIntelligentSmsChecker.CheckResult) filterResultFilter.mParams[0];
                            z = (filterResultFilter != null && (filterResultFilter.mState == 1 || (filterResultFilter.mState == 2 && checkResult != null && (checkResult != null ? ((Boolean) filterResultFilter.mParams[1]).booleanValue() : false)))) || (filterResultFilter.mState == 2 && filterResultFilter.mFilterfiled == 1);
                        }
                    }
                    dataEntity2.bundle().putBoolean("blocked", z);
                    return dataEntity2;
                case 3:
                    Bundle bundle2 = dataEntity.bundle();
                    String string2 = bundle2.getString("command");
                    String string3 = bundle2.getString(SettingUtil.DATA);
                    if (string2 != null && string3 != null) {
                        if (string2.equals("add")) {
                            C1337w.m3609a().m3614a(string3);
                        } else {
                            C1337w.m3609a().m3616b(string3);
                        }
                    }
                    return dataEntity2;
                default:
                    return dataEntity2;
            }
        }
    }

    /* JADX INFO: renamed from: tms.au$b */
    static final class b implements IIntelligentSmsChecker {

        /* JADX INFO: renamed from: a */
        static final int[][] f6859a = {new int[]{0, 0}, new int[]{1, 1}, new int[]{2, 2}};

        /* JADX INFO: renamed from: b */
        private Context f6860b;

        /* JADX INFO: renamed from: c */
        private SmsChecker f6861c;

        public b(Context context) {
            this.f6860b = context;
            this.f6861c = SmsChecker.getInstance(this.f6860b);
        }

        /* JADX INFO: renamed from: a */
        private static int m2949a(MMatchSysResult mMatchSysResult) {
            int i = mMatchSysResult.finalAction;
            if (i <= 0 || i > 4) {
                return -1;
            }
            if (i != 1) {
                return i;
            }
            if (mMatchSysResult.actionReason == 1 || mMatchSysResult.actionReason == 5) {
                return mMatchSysResult.minusMark <= 10 ? 1 : 4;
            }
            return i;
        }

        @Override // com.tencent.tmsecure.module.aresengine.IIntelligentSmsChecker
        public final IIntelligentSmsChecker.CheckResult check(SmsEntity smsEntity) {
            IIntelligentSmsChecker.CheckResult checkResult = new IIntelligentSmsChecker.CheckResult();
            if (smsEntity.protocolType < 0 || smsEntity.protocolType > 2) {
                smsEntity.protocolType = 0;
            }
            MCheckInput mCheckInput = new MCheckInput(smsEntity.phonenum, smsEntity.body, 3, f6859a[smsEntity.protocolType][0], 0);
            AtomicReference<MMatchSysResult> atomicReference = new AtomicReference<>();
            this.f6861c.checkSmsSys(mCheckInput, atomicReference);
            MMatchSysResult mMatchSysResult = atomicReference.get();
            checkResult.mInnterResult = mMatchSysResult;
            checkResult.mContentType = mMatchSysResult.contentType;
            checkResult.mSuggestion = m2949a(mMatchSysResult);
            return checkResult;
        }

        @Override // com.tencent.tmsecure.module.aresengine.IIntelligentSmsChecker
        public final boolean isChartSms(SmsEntity smsEntity) {
            AtomicReference<MMatchSysResult> atomicReference = new AtomicReference<>();
            if (smsEntity.body == null || smsEntity.body.length() == 0) {
                return false;
            }
            boolean zCheckChargeSms = this.f6861c.checkChargeSms(new MCheckInput(smsEntity.phonenum, smsEntity.body, 3, smsEntity.protocolType, smsEntity.type == 2 ? 1 : 0), atomicReference);
            if (!zCheckChargeSms) {
                return zCheckChargeSms;
            }
            int iM2949a = m2949a(atomicReference.get());
            return iM2949a == 2 || iM2949a == 3;
        }
    }

    /* JADX INFO: renamed from: a */
    public final DataIntercepter<? extends TelephonyEntity> m2941a(String str) {
        return this.f6855a.get(str);
    }

    /* JADX INFO: renamed from: a */
    public final List<DataIntercepter<? extends TelephonyEntity>> m2942a() {
        return new ArrayList(this.f6855a.values());
    }

    /* JADX INFO: renamed from: a */
    public final void m2943a(int i) {
        if (i == 0) {
            String strEncode = Uri.encode("#");
            Intent intent = new Intent("android.intent.action.CALL", Uri.parse("tel:" + strEncode + "67" + strEncode));
            intent.setFlags(268435456);
            TMSApplication.getApplicaionContext().startActivity(intent);
            return;
        }
        String strEncode2 = Uri.encode("#");
        String str = "";
        switch (i) {
            case 1:
                str = "00000000000";
                break;
            case 2:
                str = "13632545744";
                break;
            case 3:
                str = "13826512148";
                break;
        }
        Intent intent2 = new Intent("android.intent.action.CALL", Uri.parse("tel:**67*" + str + strEncode2));
        intent2.setFlags(268435456);
        TMSApplication.getApplicaionContext().startActivity(intent2);
    }

    /* JADX INFO: renamed from: a */
    public final void m2944a(AresEngineFactor aresEngineFactor) {
        this.f6857c = aresEngineFactor;
    }

    /* JADX INFO: renamed from: a */
    public final void m2945a(DataIntercepterBuilder<? extends TelephonyEntity> dataIntercepterBuilder) {
        if (this.f6855a.containsKey(dataIntercepterBuilder.getName())) {
            throw new RuntimeException("the intercepter named " + dataIntercepterBuilder.getName() + " had exited");
        }
        this.f6855a.put(dataIntercepterBuilder.getName(), (DataIntercepter<? extends TelephonyEntity>) dataIntercepterBuilder.m2599a());
    }

    /* JADX INFO: renamed from: a */
    public final boolean m2946a(List<SmsEntity> list) {
        ArrayList arrayList = new ArrayList();
        IIntelligentSmsChecker iIntelligentSmsCheckerM2947b = m2947b();
        for (SmsEntity smsEntity : list) {
            MMatchSysResult mMatchSysResult = iIntelligentSmsCheckerM2947b.check(smsEntity).mInnterResult;
            SmsReport smsReport = new SmsReport();
            smsReport.setComment(null);
            smsReport.setMatchTime((int) (System.currentTimeMillis() / 1000));
            smsReport.setSender(smsEntity.phonenum);
            smsReport.setSms(smsEntity.body);
            if (smsEntity.protocolType < 0 || smsEntity.protocolType > 2) {
                smsEntity.protocolType = 0;
            }
            smsReport.setSmsType(b.f6859a[smsEntity.protocolType][0]);
            smsReport.setUcAction(mMatchSysResult.finalAction);
            smsReport.setUcActionReason(mMatchSysResult.actionReason);
            smsReport.setUcMinusMark(mMatchSysResult.minusMark);
            smsReport.setUcContentType(mMatchSysResult.contentType);
            smsReport.vecHitRule = new ArrayList<>();
            for (MRuleTypeID mRuleTypeID : mMatchSysResult.ruleTypeID) {
                smsReport.vecHitRule.add(new RuleTypeID(mRuleTypeID.ruleType, mRuleTypeID.ruleID));
            }
            arrayList.add(smsReport);
        }
        return ((WupSessionManager) ManagerCreator.getManager(WupSessionManager.class)).reportSms(arrayList) == 0;
    }

    /* JADX INFO: renamed from: b */
    public final IIntelligentSmsChecker m2947b() {
        return this.f6856b;
    }

    /* JADX INFO: renamed from: c */
    public final AresEngineFactor m2948c() {
        if (this.f6857c == null) {
            throw new NullPointerException("The AresEngineManager's Factor can not be null.");
        }
        return this.f6857c;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6856b = new b(context);
        SDKClient.addMessageHandler(new a());
        C1336v.m3577a(context, UpdateConfig.SMS_CHECKER_NAME, (String) null);
    }
}
