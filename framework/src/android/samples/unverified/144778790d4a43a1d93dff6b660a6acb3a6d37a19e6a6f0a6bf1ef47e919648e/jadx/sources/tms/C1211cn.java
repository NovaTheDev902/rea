package tms;

import android.content.Context;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
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
import com.tencent.tmsecure.module.aresengine.ISmsDao;
import com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.module.aresengine.TelephonyEntity;

/* JADX INFO: renamed from: tms.cn */
/* JADX INFO: loaded from: classes.dex */
public final class C1211cn extends DataIntercepterBuilder<SmsEntity> {

    /* JADX INFO: renamed from: a */
    private Context f6995a = TMSApplication.getApplicaionContext();

    /* JADX INFO: renamed from: tms.cn$a */
    static final class a extends OutgoingSmsFiter {

        /* JADX INFO: renamed from: a */
        private IContactDao<? extends ContactEntity> f6996a;

        /* JADX INFO: renamed from: b */
        private AbsSysDao f6997b;

        /* JADX INFO: renamed from: c */
        private ISmsDao<? extends SmsEntity> f6998c;

        /* JADX INFO: renamed from: d */
        private C1167ax f6999d = new C1167ax();

        /* JADX INFO: renamed from: e */
        private IEntityConverter f7000e;

        public a() {
            this.f6999d.m2953a(1);
            this.f6999d.m2952a(1, new C1195by(this));
            AresEngineFactor aresEngineFactor = ((AresEngineManager) ManagerCreator.getManager(AresEngineManager.class)).getAresEngineFactor();
            this.f7000e = aresEngineFactor.getEntityConverter();
            this.f6996a = aresEngineFactor.getPrivateListDao();
            this.f6998c = aresEngineFactor.getPrivateSmsDao();
            this.f6997b = aresEngineFactor.getSysDao();
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        public final FilterConfig defalutFilterConfig() {
            FilterConfig filterConfig = new FilterConfig();
            filterConfig.set(1, 2);
            return filterConfig;
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        protected final /* synthetic */ FilterResult onFiltering(TelephonyEntity telephonyEntity, Object[] objArr) {
            return this.f6999d.m2951a((SmsEntity) telephonyEntity, getConfig(), objArr);
        }

        @Override // com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter
        public final void setEntityConvertor(IEntityConverter iEntityConverter) {
            this.f7000e = iEntityConverter;
        }

        @Override // com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter
        public final void setPrivateListDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f6996a = iContactDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter
        public final void setPrivateSmsDao(ISmsDao<? extends SmsEntity> iSmsDao) {
            this.f6998c = iSmsDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter
        public final void setSystDao(AbsSysDao absSysDao) {
            this.f6997b = absSysDao;
        }
    }

    /* JADX INFO: renamed from: tms.cn$b */
    static final class b extends DataMonitor<SmsEntity> {

        /* JADX INFO: renamed from: a */
        private ContentObserver f7001a = new C1198ca(this, new Handler());

        /* JADX INFO: renamed from: b */
        private Context f7002b;

        public b(Context context) {
            this.f7002b = context;
            this.f7002b.getContentResolver().registerContentObserver(Uri.parse("content://sms"), true, this.f7001a);
        }

        protected final void finalize() throws Throwable {
            if (this.f7001a != null) {
                this.f7002b.getContentResolver().unregisterContentObserver(this.f7001a);
            }
            super.finalize();
        }
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataFilter<SmsEntity> getDataFilter() {
        Context context = this.f6995a;
        return new a();
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataHandler getDataHandler() {
        return new DataHandler();
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataMonitor<SmsEntity> getDataMonitor() {
        return new b(this.f6995a);
    }

    /* JADX INFO: Access modifiers changed from: protected */
    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final String getName() {
        return DataIntercepterBuilder.TYPE_OUTGOING_SMS;
    }
}
