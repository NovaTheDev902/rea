package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.IntentFilter;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.aresengine.AbsSysDao;
import com.tencent.tmsecure.module.aresengine.AresEngineFactor;
import com.tencent.tmsecure.module.aresengine.AresEngineManager;
import com.tencent.tmsecure.module.aresengine.CallLogEntity;
import com.tencent.tmsecure.module.aresengine.ContactEntity;
import com.tencent.tmsecure.module.aresengine.DataFilter;
import com.tencent.tmsecure.module.aresengine.DataHandler;
import com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder;
import com.tencent.tmsecure.module.aresengine.DataMonitor;
import com.tencent.tmsecure.module.aresengine.FilterConfig;
import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.IContactDao;
import com.tencent.tmsecure.module.aresengine.ILastCallLogDao;
import com.tencent.tmsecure.module.aresengine.IPhoneDeviceController;
import com.tencent.tmsecure.module.aresengine.InComingCallFilter;
import com.tencent.tmsecure.module.aresengine.TelephonyEntity;

/* JADX INFO: renamed from: tms.bn */
/* JADX INFO: loaded from: classes.dex */
public final class C1184bn extends DataIntercepterBuilder<CallLogEntity> {

    /* JADX INFO: renamed from: a */
    private Context f6924a = TMSApplication.getApplicaionContext();

    /* JADX INFO: renamed from: tms.bn$a */
    static final class a extends InComingCallFilter {

        /* JADX INFO: renamed from: a */
        private IContactDao<? extends ContactEntity> f6925a;

        /* JADX INFO: renamed from: b */
        private IContactDao<? extends ContactEntity> f6926b;

        /* JADX INFO: renamed from: c */
        private IContactDao<? extends ContactEntity> f6927c;

        /* JADX INFO: renamed from: d */
        private AbsSysDao f6928d;

        /* JADX INFO: renamed from: e */
        private ILastCallLogDao f6929e;

        /* JADX INFO: renamed from: f */
        private C1167ax f6930f = new C1167ax();

        /* JADX INFO: renamed from: g */
        private IPhoneDeviceController f6931g;

        a() {
            this.f6930f.m2953a(1, 2, 4, 8, 16, 32);
            this.f6930f.m2952a(1, m2998a(1));
            this.f6930f.m2952a(2, m2998a(2));
            this.f6930f.m2952a(4, m2998a(4));
            this.f6930f.m2952a(8, m2998a(8));
            this.f6930f.m2952a(16, m2998a(16));
            this.f6930f.m2952a(32, m2998a(32));
            AresEngineFactor aresEngineFactor = ((AresEngineManager) ManagerCreator.getManager(AresEngineManager.class)).getAresEngineFactor();
            this.f6931g = aresEngineFactor.getPhoneDeviceController();
            this.f6925a = aresEngineFactor.getWhiteListDao();
            this.f6926b = aresEngineFactor.getBlackListDao();
            this.f6927c = aresEngineFactor.getPrivateListDao();
            this.f6929e = aresEngineFactor.getLastCallLogDao();
            this.f6928d = aresEngineFactor.getSysDao();
        }

        /* JADX INFO: renamed from: a */
        private C1167ax.a m2998a(int i) {
            return new C1173bc(this, i);
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        public final FilterConfig defalutFilterConfig() {
            FilterConfig filterConfig = new FilterConfig();
            filterConfig.set(1, 0);
            filterConfig.set(2, 0);
            filterConfig.set(4, 1);
            filterConfig.set(8, 0);
            filterConfig.set(16, 0);
            filterConfig.set(32, 0);
            return filterConfig;
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        protected final /* synthetic */ FilterResult onFiltering(TelephonyEntity telephonyEntity, Object[] objArr) {
            return this.f6930f.m2951a((CallLogEntity) telephonyEntity, getConfig(), objArr);
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setBlacklistDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f6926b = iContactDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setLastCallLogDao(ILastCallLogDao iLastCallLogDao) {
            this.f6929e = iLastCallLogDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setPhoneDeviceController(IPhoneDeviceController iPhoneDeviceController) {
            this.f6931g = iPhoneDeviceController;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setPrivatelistDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f6927c = iContactDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setSysDao(AbsSysDao absSysDao) {
            this.f6928d = absSysDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setWhitelistDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f6925a = iContactDao;
        }
    }

    /* JADX INFO: renamed from: tms.bn$b */
    static final class b extends DataMonitor<CallLogEntity> {

        /* JADX INFO: renamed from: a */
        private Context f6932a;

        /* JADX INFO: renamed from: b */
        private BroadcastReceiver f6933b = new C1175be(this);

        public b(Context context) {
            this.f6932a = context;
            IntentFilter intentFilter = new IntentFilter();
            intentFilter.setPriority(Integer.MAX_VALUE);
            intentFilter.addCategory("android.intent.category.DEFAULT");
            intentFilter.addAction("android.intent.action.PHONE_STATE");
            this.f6932a.registerReceiver(this.f6933b, intentFilter);
        }

        protected final void finalize() throws Throwable {
            this.f6932a.unregisterReceiver(this.f6933b);
            super.finalize();
        }
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataFilter<CallLogEntity> getDataFilter() {
        Context context = this.f6924a;
        return new a();
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataHandler getDataHandler() {
        return new DataHandler();
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataMonitor<CallLogEntity> getDataMonitor() {
        return new b(this.f6924a);
    }

    /* JADX INFO: Access modifiers changed from: protected */
    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final String getName() {
        return DataIntercepterBuilder.TYPE_INCOMING_CALL;
    }
}
