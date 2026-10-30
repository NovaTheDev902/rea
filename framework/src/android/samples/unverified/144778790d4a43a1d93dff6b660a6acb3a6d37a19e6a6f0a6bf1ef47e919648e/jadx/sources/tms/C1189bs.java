package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.os.RemoteException;
import com.lenovo.safecenter.safemode.SofeModeMain;
import com.tencent.tmsecure.common.DataEntity;
import com.tencent.tmsecure.common.ISDKClient;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.aresengine.AbsSysDao;
import com.tencent.tmsecure.module.aresengine.AresEngineFactor;
import com.tencent.tmsecure.module.aresengine.AresEngineManager;
import com.tencent.tmsecure.module.aresengine.ContactEntity;
import com.tencent.tmsecure.module.aresengine.DataFilter;
import com.tencent.tmsecure.module.aresengine.DataHandler;
import com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder;
import com.tencent.tmsecure.module.aresengine.DataMonitor;
import com.tencent.tmsecure.module.aresengine.FilterConfig;
import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.IContactDao;
import com.tencent.tmsecure.module.aresengine.IEntityConverter;
import com.tencent.tmsecure.module.aresengine.IIntelligentSmsChecker;
import com.tencent.tmsecure.module.aresengine.IKeyWordDao;
import com.tencent.tmsecure.module.aresengine.ILastCallLogDao;
import com.tencent.tmsecure.module.aresengine.IPhoneDeviceController;
import com.tencent.tmsecure.module.aresengine.ISmsDao;
import com.tencent.tmsecure.module.aresengine.InComingSmsFilter;
import com.tencent.tmsecure.module.aresengine.IntelligentSmsHandler;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.module.aresengine.TelephonyEntity;
import java.util.ArrayList;

/* JADX INFO: renamed from: tms.bs */
/* JADX INFO: loaded from: classes.dex */
public final class C1189bs extends DataIntercepterBuilder<SmsEntity> {

    /* JADX INFO: renamed from: a */
    private Context f6940a = TMSApplication.getApplicaionContext();

    /* JADX INFO: renamed from: tms.bs$a */
    static final class a extends DataMonitor<SmsEntity> {

        /* JADX INFO: renamed from: b */
        private AbstractC1194bx f6942b;

        /* JADX INFO: renamed from: a */
        private Context f6941a = TMSApplication.getApplicaionContext();

        /* JADX INFO: renamed from: c */
        private c f6943c = new c(0);

        public a() {
            m3010a();
        }

        /* JADX INFO: renamed from: a */
        private void m3010a() {
            this.f6942b = new C1177bg(this);
            this.f6942b.m3035a(this.f6941a);
        }

        /* JADX INFO: renamed from: b */
        private void m3011b() {
            this.f6942b.m3037b(this.f6941a);
        }

        /* JADX INFO: renamed from: a */
        final void m3012a(SmsEntity smsEntity, Object... objArr) {
            if (smsEntity != null) {
                notifyDataReached(smsEntity, objArr);
            }
        }

        protected final void finalize() throws Throwable {
            m3011b();
            super.finalize();
        }

        /* JADX INFO: Access modifiers changed from: protected */
        @Override // com.tencent.tmsecure.module.aresengine.DataMonitor
        public final /* synthetic */ void onPostDataToFilter(boolean z, TelephonyEntity telephonyEntity, Object[] objArr) {
            super.onPostDataToFilter(z, (SmsEntity) telephonyEntity, objArr);
            if (!z || objArr == null || objArr.length < 2 || !(objArr[1] instanceof BroadcastReceiver)) {
                return;
            }
            ((BroadcastReceiver) objArr[1]).abortBroadcast();
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataMonitor
        public final void setRegisterState(boolean z) {
            if (z != this.f6942b.m3036a()) {
                if (z) {
                    m3010a();
                } else {
                    m3011b();
                }
            }
        }
    }

    /* JADX INFO: renamed from: tms.bs$b */
    static final class b extends InComingSmsFilter {

        /* JADX INFO: renamed from: d */
        private IContactDao<? extends ContactEntity> f6944d;

        /* JADX INFO: renamed from: e */
        private IContactDao<? extends ContactEntity> f6945e;

        /* JADX INFO: renamed from: f */
        private IContactDao<? extends ContactEntity> f6946f;

        /* JADX INFO: renamed from: g */
        private AbsSysDao f6947g;

        /* JADX INFO: renamed from: h */
        private ISmsDao<? extends SmsEntity> f6948h;

        /* JADX INFO: renamed from: i */
        private ISmsDao<? extends SmsEntity> f6949i;

        /* JADX INFO: renamed from: j */
        private IKeyWordDao f6950j;

        /* JADX INFO: renamed from: k */
        private ILastCallLogDao f6951k;

        /* JADX INFO: renamed from: l */
        private IntelligentSmsHandler f6952l;

        /* JADX INFO: renamed from: m */
        private IEntityConverter f6953m;

        /* JADX INFO: renamed from: n */
        private IPhoneDeviceController f6954n;

        /* JADX INFO: renamed from: o */
        private IIntelligentSmsChecker f6955o = ((AresEngineManager) ManagerCreator.getManager(AresEngineManager.class)).getIntelligentSmsChecker();

        /* JADX INFO: renamed from: p */
        private C1167ax f6956p = new C1167ax();

        b() {
            this.f6956p.m2953a(1, 2, 4, 8, 16, 32, 64, 128);
            this.f6956p.m2952a(1, new C1178bh(this));
            this.f6956p.m2952a(2, new C1180bj(this));
            this.f6956p.m2952a(4, new C1181bk(this));
            this.f6956p.m2952a(8, new C1182bl(this));
            this.f6956p.m2952a(16, new C1183bm(this));
            this.f6956p.m2952a(32, new C1186bp(this));
            this.f6956p.m2952a(64, new C1187bq(this));
            this.f6956p.m2952a(128, new C1188br(this));
            AresEngineFactor aresEngineFactor = ((AresEngineManager) ManagerCreator.getManager(AresEngineManager.class)).getAresEngineFactor();
            this.f6954n = aresEngineFactor.getPhoneDeviceController();
            this.f6946f = aresEngineFactor.getPrivateListDao();
            this.f6944d = aresEngineFactor.getWhiteListDao();
            this.f6945e = aresEngineFactor.getBlackListDao();
            this.f6950j = aresEngineFactor.getKeyWordDao();
            this.f6947g = aresEngineFactor.getSysDao();
            this.f6951k = aresEngineFactor.getLastCallLogDao();
            this.f6948h = aresEngineFactor.getSmsDao();
            this.f6949i = aresEngineFactor.getPrivateSmsDao();
            this.f6953m = aresEngineFactor.getEntityConverter();
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX INFO: renamed from: a */
        public final Runnable m3014a(SmsEntity smsEntity, ISmsDao<? extends SmsEntity> iSmsDao, FilterResult filterResult) {
            return new RunnableC1190bt(this, iSmsDao, smsEntity, filterResult);
        }

        /* JADX INFO: renamed from: a */
        static /* synthetic */ void m3016a(b bVar, C1167ax.a aVar) {
            FilterResult filterResult = new FilterResult();
            SmsEntity smsEntity = (SmsEntity) aVar.m2960a();
            filterResult.mData = aVar.m2960a();
            filterResult.mFilterfiled = aVar.m2965d();
            filterResult.mState = aVar.m2963b();
            if (aVar.m2963b() == 0) {
                bVar.f6954n.unBlockSms(smsEntity, aVar.m2964c());
            } else if (aVar.m2963b() == 1) {
                bVar.f6954n.blockSms(aVar.m2964c());
                if (bVar.f6948h != null) {
                    filterResult.mDotos.add(bVar.m3014a((SmsEntity) aVar.m2960a(), bVar.f6948h, filterResult));
                }
            }
            aVar.m2961a(filterResult);
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        public final FilterConfig defalutFilterConfig() {
            FilterConfig filterConfig = new FilterConfig();
            filterConfig.set(1, 2);
            filterConfig.set(2, 0);
            filterConfig.set(4, 1);
            filterConfig.set(8, 0);
            filterConfig.set(16, 0);
            filterConfig.set(32, 1);
            filterConfig.set(64, 2);
            filterConfig.set(128, 1);
            return filterConfig;
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        protected final /* synthetic */ FilterResult onFiltering(TelephonyEntity telephonyEntity, Object[] objArr) {
            SmsEntity smsEntity = (SmsEntity) telephonyEntity;
            FilterResult filterResultM2951a = this.f6956p.m2951a(smsEntity, getConfig(), objArr);
            if (filterResultM2951a != null) {
                return filterResultM2951a;
            }
            FilterResult filterResult = new FilterResult();
            filterResult.mData = smsEntity;
            filterResult.mFilterfiled = -1;
            filterResult.mState = 0;
            if (objArr != null && objArr.length >= 2 && ((Integer) objArr[0]).intValue() == 2) {
                filterResult.mDotos.add(new RunnableC1179bi(this, smsEntity, objArr));
            }
            return filterResult;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setBlacklistDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f6945e = iContactDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setEntityConvertor(IEntityConverter iEntityConverter) {
            this.f6953m = iEntityConverter;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setIntelligentSmsHandler(IntelligentSmsHandler intelligentSmsHandler) {
            this.f6952l = intelligentSmsHandler;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setKeywordDao(IKeyWordDao iKeyWordDao) {
            this.f6950j = iKeyWordDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setLastCallLogDao(ILastCallLogDao iLastCallLogDao) {
            this.f6951k = iLastCallLogDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setPhoneDeviceController(IPhoneDeviceController iPhoneDeviceController) {
            this.f6954n = iPhoneDeviceController;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setPrivateSmsDao(ISmsDao<? extends SmsEntity> iSmsDao) {
            this.f6949i = iSmsDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setPrivatelistDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f6946f = iContactDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setSmsDao(ISmsDao<? extends SmsEntity> iSmsDao) {
            this.f6948h = iSmsDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setSysDao(AbsSysDao absSysDao) {
            this.f6947g = absSysDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setWhitelistDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f6944d = iContactDao;
        }
    }

    /* JADX INFO: renamed from: tms.bs$c */
    static final class c {

        /* JADX INFO: renamed from: a */
        private C1337w f6957a;

        private c() {
            this.f6957a = C1337w.m3609a();
        }

        /* synthetic */ c(byte b) {
            this();
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX INFO: renamed from: a */
        public ArrayList<ISDKClient> m3028a(SmsEntity smsEntity) {
            ArrayList<ISDKClient> arrayListM3615b = this.f6957a.m3615b();
            ArrayList<ISDKClient> arrayList = new ArrayList<>();
            DataEntity dataEntity = new DataEntity(2);
            dataEntity.bundle().putByteArray(SofeModeMain.TS_SMS, SmsEntity.m2607a(smsEntity));
            try {
                for (int size = arrayListM3615b.size() - 1; size >= 0; size--) {
                    ISDKClient iSDKClient = arrayListM3615b.get(size);
                    DataEntity dataEntitySendMessage = iSDKClient.sendMessage(dataEntity);
                    if (dataEntitySendMessage == null) {
                        arrayListM3615b.remove(iSDKClient);
                    } else if (dataEntitySendMessage != null && dataEntitySendMessage.bundle().getBoolean("blocked")) {
                        arrayList.add(iSDKClient);
                    }
                }
            } catch (RemoteException e) {
                e.printStackTrace();
            }
            return arrayList.size() == 0 ? arrayListM3615b : arrayList;
        }

        /* JADX INFO: renamed from: a */
        public final boolean m3030a(SmsEntity smsEntity, Object... objArr) {
            BroadcastReceiver broadcastReceiver = (BroadcastReceiver) objArr[0];
            if (this.f6957a.m3617c() == 1) {
                return true;
            }
            if (broadcastReceiver != null) {
                broadcastReceiver.abortBroadcast();
            }
            new C1191bu(this, smsEntity).start();
            return false;
        }
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataFilter<SmsEntity> getDataFilter() {
        Context context = this.f6940a;
        return new b();
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataHandler getDataHandler() {
        return new DataHandler();
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataMonitor<SmsEntity> getDataMonitor() {
        return new a();
    }

    /* JADX INFO: Access modifiers changed from: protected */
    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final String getName() {
        return DataIntercepterBuilder.TYPE_INCOMING_SMS;
    }
}
