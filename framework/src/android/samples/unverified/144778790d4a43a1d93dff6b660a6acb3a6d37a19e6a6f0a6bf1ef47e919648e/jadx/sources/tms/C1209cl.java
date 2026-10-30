package tms;

import com.tencent.tmsecure.module.aresengine.AbsSysDao;
import com.tencent.tmsecure.module.aresengine.CallLogEntity;
import com.tencent.tmsecure.module.aresengine.ContactEntity;
import com.tencent.tmsecure.module.aresengine.DataFilter;
import com.tencent.tmsecure.module.aresengine.DataHandler;
import com.tencent.tmsecure.module.aresengine.DataIntercepter;
import com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder;
import com.tencent.tmsecure.module.aresengine.DataMonitor;
import com.tencent.tmsecure.module.aresengine.FilterConfig;
import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.ICallLogDao;
import com.tencent.tmsecure.module.aresengine.IContactDao;
import com.tencent.tmsecure.module.aresengine.IEntityConverter;
import com.tencent.tmsecure.module.aresengine.IKeyWordDao;
import com.tencent.tmsecure.module.aresengine.ILastCallLogDao;
import com.tencent.tmsecure.module.aresengine.IPhoneDeviceController;
import com.tencent.tmsecure.module.aresengine.IShortCallChecker;
import com.tencent.tmsecure.module.aresengine.ISmsDao;
import com.tencent.tmsecure.module.aresengine.InComingCallFilter;
import com.tencent.tmsecure.module.aresengine.InComingSmsFilter;
import com.tencent.tmsecure.module.aresengine.IntelligentSmsHandler;
import com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.module.aresengine.SystemCalllogFilter;
import com.tencent.tmsecure.module.aresengine.TelephonyEntity;

/* JADX INFO: renamed from: tms.cl */
/* JADX INFO: loaded from: classes.dex */
public final class C1209cl implements DataIntercepter<TelephonyEntity> {

    /* JADX INFO: renamed from: a */
    static final FilterConfig f6989a = new FilterConfig();

    /* JADX INFO: renamed from: b */
    static final FilterResult f6990b = new FilterResult();

    /* JADX INFO: renamed from: d */
    DataFilter<? extends TelephonyEntity> f6992d;

    /* JADX INFO: renamed from: c */
    a f6991c = new a();

    /* JADX INFO: renamed from: e */
    DataHandler f6993e = new DataHandler();

    /* JADX INFO: renamed from: tms.cl$a */
    static final class a extends DataMonitor<TelephonyEntity> {
        a() {
        }
    }

    /* JADX INFO: renamed from: tms.cl$b */
    static final class b extends InComingCallFilter {
        b() {
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        public final FilterConfig defalutFilterConfig() {
            return C1209cl.f6989a;
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        protected final /* synthetic */ FilterResult onFiltering(TelephonyEntity telephonyEntity, Object[] objArr) {
            return C1209cl.f6990b;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setBlacklistDao(IContactDao<? extends ContactEntity> iContactDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setLastCallLogDao(ILastCallLogDao iLastCallLogDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setPhoneDeviceController(IPhoneDeviceController iPhoneDeviceController) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setPrivatelistDao(IContactDao<? extends ContactEntity> iContactDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setSysDao(AbsSysDao absSysDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingCallFilter
        public final void setWhitelistDao(IContactDao<? extends ContactEntity> iContactDao) {
        }
    }

    /* JADX INFO: renamed from: tms.cl$c */
    static final class c extends InComingSmsFilter {
        c() {
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        public final FilterConfig defalutFilterConfig() {
            return C1209cl.f6989a;
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        protected final /* synthetic */ FilterResult onFiltering(TelephonyEntity telephonyEntity, Object[] objArr) {
            return C1209cl.f6990b;
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setBlacklistDao(IContactDao<? extends ContactEntity> iContactDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setEntityConvertor(IEntityConverter iEntityConverter) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setIntelligentSmsHandler(IntelligentSmsHandler intelligentSmsHandler) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setKeywordDao(IKeyWordDao iKeyWordDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setLastCallLogDao(ILastCallLogDao iLastCallLogDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setPhoneDeviceController(IPhoneDeviceController iPhoneDeviceController) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setPrivateSmsDao(ISmsDao<? extends SmsEntity> iSmsDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setPrivatelistDao(IContactDao<? extends ContactEntity> iContactDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setSmsDao(ISmsDao<? extends SmsEntity> iSmsDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setSysDao(AbsSysDao absSysDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.InComingSmsFilter
        public final void setWhitelistDao(IContactDao<? extends ContactEntity> iContactDao) {
        }
    }

    /* JADX INFO: renamed from: tms.cl$d */
    static final class d extends OutgoingSmsFiter {
        d() {
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        public final FilterConfig defalutFilterConfig() {
            return C1209cl.f6989a;
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        protected final /* synthetic */ FilterResult onFiltering(TelephonyEntity telephonyEntity, Object[] objArr) {
            return C1209cl.f6990b;
        }

        @Override // com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter
        public final void setEntityConvertor(IEntityConverter iEntityConverter) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter
        public final void setPrivateListDao(IContactDao<? extends ContactEntity> iContactDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter
        public final void setPrivateSmsDao(ISmsDao<? extends SmsEntity> iSmsDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.OutgoingSmsFiter
        public final void setSystDao(AbsSysDao absSysDao) {
        }
    }

    /* JADX INFO: renamed from: tms.cl$e */
    static final class e extends SystemCalllogFilter {
        e() {
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        public final FilterConfig defalutFilterConfig() {
            return C1209cl.f6989a;
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        protected final /* synthetic */ FilterResult onFiltering(TelephonyEntity telephonyEntity, Object[] objArr) {
            return C1209cl.f6990b;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setBlacklistDao(IContactDao<? extends ContactEntity> iContactDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setCalllogDao(ICallLogDao<? extends CallLogEntity> iCallLogDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setEntityConvertor(IEntityConverter iEntityConverter) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setLastCallLogDao(ILastCallLogDao iLastCallLogDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setPhoneDeviceController(IPhoneDeviceController iPhoneDeviceController) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setPrivateCalllogDao(ICallLogDao<? extends CallLogEntity> iCallLogDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setPrivatelistDao(IContactDao<? extends ContactEntity> iContactDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setShortCallChecker(IShortCallChecker iShortCallChecker) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setSysDao(AbsSysDao absSysDao) {
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setWhitelistDao(IContactDao<? extends ContactEntity> iContactDao) {
        }
    }

    public C1209cl(String str) {
        if (str.equals(DataIntercepterBuilder.TYPE_INCOMING_CALL)) {
            this.f6992d = new b();
            return;
        }
        if (str.equals(DataIntercepterBuilder.TYPE_INCOMING_SMS)) {
            this.f6992d = new c();
        } else if (str.equals(DataIntercepterBuilder.TYPE_OUTGOING_SMS)) {
            this.f6992d = new d();
        } else if (str.equals(DataIntercepterBuilder.TYPE_SYSTEM_CALL)) {
            this.f6992d = new e();
        }
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepter
    public final DataFilter<TelephonyEntity> dataFilter() {
        return this.f6992d;
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepter
    public final DataHandler dataHandler() {
        return this.f6993e;
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepter
    public final DataMonitor<TelephonyEntity> dataMonitor() {
        return this.f6991c;
    }
}
