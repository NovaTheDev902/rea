package tms;

import com.tencent.tmsecure.module.network.INetworkChangeCallBack;
import com.tencent.tmsecure.module.network.INetworkInfoDao;
import com.tencent.tmsecure.module.network.INetworkMonitor;
import com.tencent.tmsecure.module.network.NetDataEntity;
import com.tencent.tmsecure.module.network.NetDataEntityFactory;
import com.tencent.tmsecure.module.network.NetworkInfoEntity;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: tms.cz */
/* JADX INFO: loaded from: classes.dex */
class C1223cz implements INetworkChangeCallBack, INetworkMonitor {

    /* JADX INFO: renamed from: a */
    private NetDataEntityFactory f7046a;

    /* JADX INFO: renamed from: b */
    private INetworkInfoDao f7047b;

    /* JADX INFO: renamed from: c */
    private Date f7048c;

    /* JADX INFO: renamed from: d */
    private long f7049d;

    /* JADX INFO: renamed from: e */
    private long f7050e;

    /* JADX INFO: renamed from: f */
    private long f7051f;

    /* JADX INFO: renamed from: g */
    private NetDataEntity f7052g;

    /* JADX INFO: renamed from: h */
    private int f7053h;

    /* JADX INFO: renamed from: i */
    private byte[] f7054i = new byte[0];

    /* JADX INFO: renamed from: j */
    private List<INetworkChangeCallBack> f7055j = new ArrayList();

    /* JADX INFO: renamed from: k */
    private boolean f7056k = false;

    /* JADX INFO: renamed from: l */
    private boolean f7057l = true;

    public C1223cz(NetDataEntityFactory netDataEntityFactory, INetworkInfoDao iNetworkInfoDao) {
        this.f7049d = 0L;
        this.f7050e = 0L;
        this.f7051f = 0L;
        this.f7053h = -1;
        this.f7046a = netDataEntityFactory;
        this.f7047b = iNetworkInfoDao;
        NetworkInfoEntity todayNetworkInfoEntity = this.f7047b.getTodayNetworkInfoEntity();
        this.f7048c = todayNetworkInfoEntity.mStartDate;
        this.f7049d = todayNetworkInfoEntity.mTotalForMonth;
        this.f7050e = todayNetworkInfoEntity.mUsedForDay;
        this.f7051f = todayNetworkInfoEntity.mUsedForMonth;
        this.f7053h = this.f7047b.getClosingDayForMonth();
    }

    /* JADX INFO: renamed from: c */
    private NetworkInfoEntity m3086c() {
        NetworkInfoEntity networkInfoEntity = new NetworkInfoEntity();
        networkInfoEntity.mTotalForMonth = this.f7049d;
        networkInfoEntity.mUsedForMonth = this.f7051f;
        networkInfoEntity.mRetialForMonth = this.f7049d - this.f7051f;
        networkInfoEntity.mUsedForDay = this.f7050e;
        networkInfoEntity.mStartDate = this.f7048c;
        this.f7047b.setTodayNetworkInfoEntity(networkInfoEntity);
        return networkInfoEntity;
    }

    /* JADX INFO: renamed from: a */
    public final void m3087a() {
        if (this.f7056k) {
            GregorianCalendar gregorianCalendar = new GregorianCalendar();
            GregorianCalendar gregorianCalendar2 = new GregorianCalendar();
            gregorianCalendar2.setTime(this.f7048c);
            GregorianCalendar gregorianCalendarM3556a = C1333s.m3556a(gregorianCalendar, this.f7053h);
            GregorianCalendar gregorianCalendarM3556a2 = C1333s.m3556a(gregorianCalendar2, this.f7053h);
            if (gregorianCalendar.get(5) == this.f7053h && gregorianCalendarM3556a.get(2) != gregorianCalendarM3556a2.get(2)) {
                this.f7051f = 0L;
                onClosingDateReached();
            }
            if (gregorianCalendar2.get(5) != gregorianCalendar.get(5)) {
                NetworkInfoEntity networkInfoEntity = new NetworkInfoEntity();
                networkInfoEntity.mStartDate = this.f7048c;
                networkInfoEntity.mUsedForDay = this.f7050e;
                this.f7047b.insert(networkInfoEntity);
                this.f7047b.resetToDayNetworkInfoEntity();
                this.f7050e = 0L;
                this.f7048c = new Date();
                onDayChanged();
            }
            NetDataEntity netDataEntity = this.f7046a.getNetDataEntity();
            if (netDataEntity.mReceiver > 0) {
                if (this.f7052g == null) {
                    throw new NullPointerException("An unexpected exception had happen. The monitor's enable is " + this.f7056k);
                }
                long j = netDataEntity.mReceiver + netDataEntity.mTranslate;
                long j2 = this.f7052g.mReceiver + this.f7052g.mTranslate;
                if (j2 == -1 || j2 == 0) {
                    this.f7052g = netDataEntity;
                    j2 = j;
                }
                long j3 = j - j2;
                if (j3 >= 0) {
                    j = j3;
                }
                this.f7050e += j;
                this.f7051f = j + this.f7051f;
                this.f7052g = netDataEntity;
                this.f7047b.setLastNetDataEntity(this.f7052g);
            }
            onNormalChanged(m3086c());
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3088a(boolean z) {
        this.f7056k = z;
        if (!this.f7056k) {
            m3086c();
            return;
        }
        this.f7052g = this.f7047b.getLastNetDataEntity();
        if (this.f7052g == null || this.f7052g.mReceiver < 0) {
            this.f7052g = this.f7046a.getNetDataEntity();
            this.f7047b.setLastNetDataEntity(this.f7052g);
        }
    }

    /* JADX WARN: Code duplicated, block: B:10:0x0012  */
    /* JADX WARN: Code duplicated, block: B:7:0x000c A[Catch: all -> 0x0014, TryCatch #0 {, blocks: (B:5:0x0005, B:7:0x000c, B:8:0x0010), top: B:14:0x0005 }] */
    @Override // com.tencent.tmsecure.module.network.INetworkMonitor
    public int addCallback(INetworkChangeCallBack iNetworkChangeCallBack) {
        int iHashCode;
        synchronized (this.f7054i) {
            if (iNetworkChangeCallBack != null) {
                this.f7055j.add(iNetworkChangeCallBack);
                if (iNetworkChangeCallBack != null) {
                    iHashCode = iNetworkChangeCallBack.hashCode();
                } else {
                    iHashCode = -1;
                }
            } else if (iNetworkChangeCallBack != null) {
                iHashCode = iNetworkChangeCallBack.hashCode();
            } else {
                iHashCode = -1;
            }
            throw th;
        }
        return iHashCode;
    }

    /* JADX INFO: renamed from: b */
    public final void m3089b() {
        NetworkInfoEntity systemTimeChange = this.f7047b.getSystemTimeChange(this.f7048c);
        if (systemTimeChange != null) {
            this.f7049d = systemTimeChange.mTotalForMonth;
            this.f7051f = systemTimeChange.mUsedForMonth;
            this.f7050e = systemTimeChange.mUsedForDay;
        }
        this.f7048c = new Date();
        m3086c();
    }

    @Override // com.tencent.tmsecure.module.network.INetworkMonitor
    public void clearAllLogs() {
        this.f7050e = 0L;
        this.f7051f = 0L;
        m3086c();
        this.f7048c = new Date();
        this.f7052g = this.f7046a.getNetDataEntity();
        this.f7047b.setLastNetDataEntity(this.f7052g);
        this.f7047b.resetToDayNetworkInfoEntity();
        this.f7047b.clearAll();
    }

    @Override // com.tencent.tmsecure.module.network.INetworkMonitor
    public ArrayList<NetworkInfoEntity> getAllLogs() {
        ArrayList<NetworkInfoEntity> all = this.f7047b.getAll();
        if (all != null && all.size() > 0) {
            Collections.sort(all);
        }
        return all;
    }

    @Override // com.tencent.tmsecure.module.network.INetworkMonitor
    public boolean getRefreshState() {
        return this.f7057l;
    }

    @Override // com.tencent.tmsecure.module.network.INetworkMonitor
    public void notifyConfigChange() {
        if (this.f7056k) {
            this.f7053h = this.f7047b.getClosingDayForMonth();
            this.f7049d = this.f7047b.getTotalForMonth();
            this.f7051f = this.f7047b.getUsedForMonth();
            this.f7050e = this.f7047b.getTodayNetworkInfoEntity().mUsedForDay;
        }
    }

    @Override // com.tencent.tmsecure.module.network.INetworkChangeCallBack
    public void onClosingDateReached() {
        synchronized (this.f7054i) {
            try {
                if (this.f7057l) {
                    Iterator<INetworkChangeCallBack> it = this.f7055j.iterator();
                    while (it.hasNext()) {
                        it.next().onClosingDateReached();
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override // com.tencent.tmsecure.module.network.INetworkChangeCallBack
    public void onDayChanged() {
        synchronized (this.f7054i) {
            try {
                if (this.f7057l) {
                    Iterator<INetworkChangeCallBack> it = this.f7055j.iterator();
                    while (it.hasNext()) {
                        it.next().onDayChanged();
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override // com.tencent.tmsecure.module.network.INetworkChangeCallBack
    public void onNormalChanged(NetworkInfoEntity networkInfoEntity) {
        synchronized (this.f7054i) {
            try {
                if (this.f7057l) {
                    Iterator<INetworkChangeCallBack> it = this.f7055j.iterator();
                    while (it.hasNext()) {
                        it.next().onNormalChanged(networkInfoEntity);
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override // com.tencent.tmsecure.module.network.INetworkMonitor
    public boolean removeCallback(int i) {
        synchronized (this.f7054i) {
            for (int size = this.f7055j.size() - 1; size >= 0; size--) {
                if (this.f7055j.get(size).hashCode() == i) {
                    return this.f7055j.remove(size) != null;
                }
            }
            return false;
        }
    }

    @Override // com.tencent.tmsecure.module.network.INetworkMonitor
    public boolean removeCallback(INetworkChangeCallBack iNetworkChangeCallBack) {
        boolean zRemove;
        synchronized (this.f7054i) {
            zRemove = iNetworkChangeCallBack != null ? this.f7055j.remove(iNetworkChangeCallBack) : false;
        }
        return zRemove;
    }

    @Override // com.tencent.tmsecure.module.network.INetworkMonitor
    public void setRefreshState(boolean z) {
        this.f7057l = z;
    }
}
