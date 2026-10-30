package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.database.ContentObserver;
import android.os.Handler;
import android.provider.CallLog;
import android.telephony.PhoneNumberUtils;
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
import com.tencent.tmsecure.module.aresengine.ICallLogDao;
import com.tencent.tmsecure.module.aresengine.IContactDao;
import com.tencent.tmsecure.module.aresengine.IEntityConverter;
import com.tencent.tmsecure.module.aresengine.ILastCallLogDao;
import com.tencent.tmsecure.module.aresengine.IPhoneDeviceController;
import com.tencent.tmsecure.module.aresengine.IShortCallChecker;
import com.tencent.tmsecure.module.aresengine.SystemCalllogFilter;
import com.tencent.tmsecure.module.aresengine.TelephonyEntity;
import java.util.concurrent.ConcurrentLinkedQueue;

/* JADX INFO: renamed from: tms.cs */
/* JADX INFO: loaded from: classes.dex */
public final class C1216cs extends DataIntercepterBuilder<CallLogEntity> {

    /* JADX INFO: renamed from: a */
    private Context f7008a = TMSApplication.getApplicaionContext();

    /* JADX INFO: renamed from: tms.cs$a */
    static final class a extends DataMonitor<CallLogEntity> {

        /* JADX INFO: renamed from: a */
        private Context f7009a;

        /* JADX INFO: renamed from: b */
        private ContentObserver f7010b;

        /* JADX INFO: renamed from: d */
        private final ConcurrentLinkedQueue<String> f7012d = new ConcurrentLinkedQueue<>();

        /* JADX INFO: renamed from: e */
        private final ConcurrentLinkedQueue<String> f7013e = new ConcurrentLinkedQueue<>();

        /* JADX INFO: renamed from: c */
        private BroadcastReceiver f7011c = new C1200cc(this);

        public a(Context context) {
            this.f7009a = context;
            IntentFilter intentFilter = new IntentFilter();
            intentFilter.setPriority(Integer.MAX_VALUE);
            intentFilter.addCategory("android.intent.category.DEFAULT");
            intentFilter.addAction("android.intent.action.PHONE_STATE");
            this.f7009a.registerReceiver(this.f7011c, intentFilter);
            IntentFilter intentFilter2 = new IntentFilter();
            intentFilter2.setPriority(Integer.MAX_VALUE);
            intentFilter2.addCategory("android.intent.category.DEFAULT");
            intentFilter2.addAction("android.intent.action.NEW_OUTGOING_CALL");
            this.f7009a.registerReceiver(this.f7011c, intentFilter2);
            Handler handler = new Handler();
            this.f7010b = new C1201cd(this, handler, handler);
            this.f7009a.getContentResolver().registerContentObserver(CallLog.CONTENT_URI, true, this.f7010b);
        }

        /* JADX INFO: renamed from: a */
        static /* synthetic */ void m3049a(a aVar, CallLogEntity callLogEntity, ConcurrentLinkedQueue concurrentLinkedQueue) {
            String str;
            while (concurrentLinkedQueue.size() > 0 && (str = (String) concurrentLinkedQueue.peek()) != null && str.equals(callLogEntity.phonenum)) {
                concurrentLinkedQueue.poll();
                if (!str.equals("null")) {
                    long jCurrentTimeMillis = System.currentTimeMillis();
                    callLogEntity.phonenum = PhoneNumberUtils.stripSeparators(callLogEntity.phonenum);
                    aVar.notifyDataReached(callLogEntity, Long.valueOf(jCurrentTimeMillis));
                }
            }
            concurrentLinkedQueue.clear();
        }

        protected final void finalize() throws Throwable {
            this.f7009a.getContentResolver().unregisterContentObserver(this.f7010b);
            this.f7010b = null;
            this.f7009a.unregisterReceiver(this.f7011c);
            this.f7011c = null;
            super.finalize();
        }
    }

    /* JADX INFO: renamed from: tms.cs$b */
    static final class b extends SystemCalllogFilter {

        /* JADX INFO: renamed from: a */
        private IContactDao<? extends ContactEntity> f7014a;

        /* JADX INFO: renamed from: b */
        private IContactDao<? extends ContactEntity> f7015b;

        /* JADX INFO: renamed from: c */
        private IContactDao<? extends ContactEntity> f7016c;

        /* JADX INFO: renamed from: d */
        private ICallLogDao<? extends CallLogEntity> f7017d;

        /* JADX INFO: renamed from: e */
        private ICallLogDao<? extends CallLogEntity> f7018e;

        /* JADX INFO: renamed from: f */
        private ILastCallLogDao f7019f;

        /* JADX INFO: renamed from: g */
        private IShortCallChecker f7020g;

        /* JADX INFO: renamed from: h */
        private AbsSysDao f7021h;

        /* JADX INFO: renamed from: i */
        private IPhoneDeviceController f7022i;

        /* JADX INFO: renamed from: j */
        private IEntityConverter f7023j;

        /* JADX INFO: renamed from: k */
        private Context f7024k;

        /* JADX INFO: renamed from: m */
        private boolean f7026m = m3057c();

        /* JADX INFO: renamed from: l */
        private C1167ax f7025l = new C1167ax();

        public b(Context context) {
            this.f7024k = context;
            this.f7025l.m2953a(1, 2, 4, 8, 16, 32, 128, 64, 256);
            this.f7025l.m2952a(1, new C1203cf(this));
            this.f7025l.m2952a(2, new C1204cg(this));
            this.f7025l.m2952a(4, new C1205ch(this));
            this.f7025l.m2952a(8, new C1206ci(this));
            this.f7025l.m2952a(16, new C1208ck(this));
            this.f7025l.m2952a(32, new C1212co(this));
            this.f7025l.m2952a(64, new C1213cp(this));
            this.f7025l.m2952a(128, new C1214cq(this));
            this.f7025l.m2952a(256, new C1215cr(this));
            AresEngineFactor aresEngineFactor = ((AresEngineManager) ManagerCreator.getManager(AresEngineManager.class)).getAresEngineFactor();
            this.f7016c = aresEngineFactor.getPrivateListDao();
            this.f7014a = aresEngineFactor.getWhiteListDao();
            this.f7015b = aresEngineFactor.getBlackListDao();
            this.f7017d = aresEngineFactor.getCallLogDao();
            this.f7018e = aresEngineFactor.getPrivateCallLogDao();
            this.f7021h = aresEngineFactor.getSysDao();
            this.f7019f = aresEngineFactor.getLastCallLogDao();
            this.f7023j = aresEngineFactor.getEntityConverter();
            this.f7022i = aresEngineFactor.getPhoneDeviceController();
        }

        /* JADX INFO: renamed from: a */
        static /* synthetic */ void m3054a(b bVar, C1167ax.a aVar, ICallLogDao iCallLogDao, boolean z, boolean z2) {
            FilterResult filterResult = new FilterResult();
            filterResult.mParams = aVar.m2964c();
            filterResult.mData = aVar.m2960a();
            filterResult.mFilterfiled = aVar.m2965d();
            filterResult.mState = aVar.m2963b();
            aVar.m2961a(filterResult);
            if (iCallLogDao == null || !z) {
                return;
            }
            CallLogEntity callLogEntityConvert = (CallLogEntity) aVar.m2960a();
            if (z2) {
                callLogEntityConvert.type = 1;
            }
            bVar.f7021h.remove(callLogEntityConvert);
            if (bVar.f7023j != null) {
                callLogEntityConvert = bVar.f7023j.convert(callLogEntityConvert);
            }
            iCallLogDao.insert(callLogEntityConvert, filterResult);
        }

        /* JADX INFO: renamed from: c */
        private boolean m3057c() {
            try {
                return this.f7024k.getPackageManager().getApplicationInfo("com.htc.launcher", 0) != null;
            } catch (PackageManager.NameNotFoundException e) {
                return false;
            }
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        public final FilterConfig defalutFilterConfig() {
            FilterConfig filterConfig = new FilterConfig();
            filterConfig.set(1, 2);
            filterConfig.set(2, 0);
            filterConfig.set(4, 1);
            filterConfig.set(8, 0);
            filterConfig.set(16, 0);
            filterConfig.set(32, 3);
            filterConfig.set(128, 2);
            filterConfig.set(64, 2);
            filterConfig.set(256, 2);
            return filterConfig;
        }

        /* JADX INFO: Access modifiers changed from: protected */
        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        public final /* synthetic */ void onFiltered(TelephonyEntity telephonyEntity, FilterResult filterResult) {
            CallLogEntity callLogEntity = (CallLogEntity) telephonyEntity;
            super.onFiltered(callLogEntity, filterResult);
            if (callLogEntity.type == 2) {
                this.f7019f.update(callLogEntity);
            }
        }

        @Override // com.tencent.tmsecure.module.aresengine.DataFilter
        protected final /* synthetic */ FilterResult onFiltering(TelephonyEntity telephonyEntity, Object[] objArr) {
            return this.f7025l.m2951a((CallLogEntity) telephonyEntity, getConfig(), objArr);
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setBlacklistDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f7015b = iContactDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setCalllogDao(ICallLogDao<? extends CallLogEntity> iCallLogDao) {
            this.f7017d = iCallLogDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setEntityConvertor(IEntityConverter iEntityConverter) {
            this.f7023j = iEntityConverter;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setLastCallLogDao(ILastCallLogDao iLastCallLogDao) {
            this.f7019f = iLastCallLogDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setPhoneDeviceController(IPhoneDeviceController iPhoneDeviceController) {
            this.f7022i = iPhoneDeviceController;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setPrivateCalllogDao(ICallLogDao<? extends CallLogEntity> iCallLogDao) {
            this.f7018e = iCallLogDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setPrivatelistDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f7016c = iContactDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setShortCallChecker(IShortCallChecker iShortCallChecker) {
            this.f7020g = iShortCallChecker;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setSysDao(AbsSysDao absSysDao) {
            this.f7021h = absSysDao;
        }

        @Override // com.tencent.tmsecure.module.aresengine.SystemCalllogFilter
        public final void setWhitelistDao(IContactDao<? extends ContactEntity> iContactDao) {
            this.f7014a = iContactDao;
        }
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataFilter<CallLogEntity> getDataFilter() {
        return new b(this.f7008a);
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataHandler getDataHandler() {
        return new DataHandler();
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final DataMonitor<CallLogEntity> getDataMonitor() {
        return new a(this.f7008a);
    }

    /* JADX INFO: Access modifiers changed from: protected */
    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepterBuilder
    public final String getName() {
        return DataIntercepterBuilder.TYPE_SYSTEM_CALL;
    }
}
