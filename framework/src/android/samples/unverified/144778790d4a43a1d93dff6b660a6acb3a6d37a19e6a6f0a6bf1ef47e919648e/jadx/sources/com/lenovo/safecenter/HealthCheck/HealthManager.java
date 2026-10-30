package com.lenovo.safecenter.HealthCheck;

import android.content.Context;
import com.lenovo.safecenter.HealthCheck.item.HealthAdvertiseIntercept;
import com.lenovo.safecenter.HealthCheck.item.HealthBootApp;
import com.lenovo.safecenter.HealthCheck.item.HealthClearCache;
import com.lenovo.safecenter.HealthCheck.item.HealthHarassIntercept;
import com.lenovo.safecenter.HealthCheck.item.HealthKillVirus;
import com.lenovo.safecenter.HealthCheck.item.HealthLeCloudSynForContact;
import com.lenovo.safecenter.HealthCheck.item.HealthLowMenory;
import com.lenovo.safecenter.HealthCheck.item.HealthNoSetTrafficLimit;
import com.lenovo.safecenter.HealthCheck.item.HealthProtectPrivacy;
import com.lenovo.safecenter.HealthCheck.item.HealthProtectThief;
import com.lenovo.safecenter.HealthCheck.item.HealthProtectTraffic;
import com.lenovo.safecenter.HealthCheck.item.HealthProtectVirus;
import com.lenovo.safecenter.HealthCheck.item.HealthReadPrivacyApp;
import com.lenovo.safecenter.HealthCheck.item.HealthRunningAppProcess;
import com.lenovo.safecenter.HealthCheck.item.HealthSafeInputMethod;
import com.lenovo.safecenter.HealthCheck.item.HealthSafehomepage;
import com.lenovo.safecenter.HealthCheck.item.HealthSafepaymen;
import com.lenovo.safecenter.HealthCheck.item.HealthSendSmsFromBackgroud;
import com.lenovo.safecenter.HealthCheck.item.HealthTrafficMonitor;
import com.lenovo.safecenter.HealthCheck.item.HealthWlanAutoUpdateLab;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.WflUtils;
import com.tencent.tmsecure.utils.Log;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

/* JADX INFO: loaded from: classes.dex */
public class HealthManager implements HealthResultCallback {
    public static final int ACTION_HEALTH_OPTIMIZE = 1;
    public static final int ACTION_HEALTH_SCAN = 0;

    /* JADX INFO: renamed from: l */
    private TreeMap<Integer, BaseHealthCheck> f2401l;

    /* JADX INFO: renamed from: m */
    private HealthCheckCallback f2402m;

    /* JADX INFO: renamed from: n */
    private Context f2403n;

    /* JADX INFO: renamed from: p */
    private boolean f2405p;

    /* JADX INFO: renamed from: a */
    private int f2390a = 0;

    /* JADX INFO: renamed from: b */
    private int f2391b = 0;

    /* JADX INFO: renamed from: c */
    private int f2392c = 0;

    /* JADX INFO: renamed from: d */
    private int f2393d = 0;

    /* JADX INFO: renamed from: e */
    private int f2394e = 0;

    /* JADX INFO: renamed from: f */
    private int f2395f = 100;

    /* JADX INFO: renamed from: g */
    private int f2396g = 0;

    /* JADX INFO: renamed from: h */
    private int f2397h = 0;

    /* JADX INFO: renamed from: i */
    private int f2398i = 0;

    /* JADX INFO: renamed from: j */
    private int f2399j = 0;

    /* JADX INFO: renamed from: k */
    private int f2400k = 0;

    /* JADX INFO: renamed from: o */
    private boolean f2404o = false;

    /* JADX INFO: renamed from: q */
    private boolean f2406q = false;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1037a(HealthManager x0) {
        Log.m2636i("wu0wu", "onScanStarted...");
        Iterator<Map.Entry<Integer, BaseHealthCheck>> it = x0.f2401l.entrySet().iterator();
        ArrayList<BaseHealthCheck> arrayList = new ArrayList<>();
        while (it.hasNext()) {
            BaseHealthCheck value = it.next().getValue();
            if (WflUtils.isRoot() || !value.isRootItem) {
                Log.m2636i("wu0wu", "getAllCheckItems item.mKey=" + value.mKey);
                arrayList.add(value);
            }
        }
        if (x0.f2405p || HealthKillVirus.isClounKillVirus(x0.f2403n)) {
            x0.f2399j = 100;
            x0.f2400k = x0.f2399j / (arrayList.size() - 1);
        } else {
            x0.f2399j = (arrayList.size() * 4) + 100;
            x0.f2400k = 4;
        }
        Log.m2636i("wu0wu", "mValueProgressEveryCheck=" + x0.f2400k);
        x0.f2402m.onStarted(x0.f2399j, 0);
        x0.setStatus(0);
        x0.setScore(100);
        x0.setScanProgress(0);
        x0.m1039a(arrayList);
        x0.m1036a(0);
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1038a(HealthManager x0, ArrayList x1) {
        WflUtils.Log("i", "wu0wu", "===================Optimization.start======================");
        x0.f2402m.onStarted(x0.f2399j, 1);
        x0.setProgressBarIndeterminate(true);
        x0.setStatus(2);
        ArrayList<BaseHealthCheck> arrayList = new ArrayList<>();
        if (x1 != null && x1.size() != 0) {
            int i = 0;
            while (true) {
                int i2 = i;
                if (i2 >= x1.size()) {
                    break;
                }
                Log.m2636i("wu0wu", "keys=" + x1.get(i2));
                if (x0.f2401l.get(x1.get(i2)) != null && x0.f2401l.get(x1.get(i2)).result != null) {
                    arrayList.add(x0.f2401l.get(x1.get(i2)));
                }
                i = i2 + 1;
            }
        } else {
            Iterator<Map.Entry<Integer, BaseHealthCheck>> it = x0.f2401l.entrySet().iterator();
            while (it.hasNext()) {
                BaseHealthCheck value = it.next().getValue();
                if (value.result != null && (value.result.weight == 1 || value.result.weight == 3)) {
                    arrayList.add(value);
                }
            }
        }
        x0.m1041b(arrayList);
        x0.m1036a(1);
        WflUtils.Log("i", "wu0wu", "===================Optimization.end======================");
    }

    public HealthManager(Context context, boolean isAidl) {
        this.f2401l = null;
        this.f2405p = false;
        this.f2403n = context;
        this.f2405p = isAidl;
        this.f2401l = new TreeMap<>();
        HealthProtectVirus healthProtectVirus = new HealthProtectVirus(this.f2403n, this);
        HealthAdvertiseIntercept healthAdvertiseIntercept = new HealthAdvertiseIntercept(this.f2403n, this);
        this.f2401l.put(Integer.valueOf(healthProtectVirus.mKey), healthProtectVirus);
        this.f2401l.put(Integer.valueOf(healthAdvertiseIntercept.mKey), healthAdvertiseIntercept);
        if (!this.f2405p) {
            HealthLeCloudSynForContact healthLeCloudSynForContact = new HealthLeCloudSynForContact(this.f2403n, this);
            HealthSafehomepage healthSafehomepage = new HealthSafehomepage(this.f2403n, this);
            HealthProtectThief healthProtectThief = new HealthProtectThief(this.f2403n, this);
            HealthNoSetTrafficLimit healthNoSetTrafficLimit = new HealthNoSetTrafficLimit(this.f2403n, this);
            HealthBootApp healthBootApp = new HealthBootApp(this.f2403n, this);
            this.f2401l.put(Integer.valueOf(healthLeCloudSynForContact.mKey), healthLeCloudSynForContact);
            this.f2401l.put(Integer.valueOf(healthSafehomepage.mKey), healthSafehomepage);
            this.f2401l.put(Integer.valueOf(healthProtectThief.mKey), healthProtectThief);
            this.f2401l.put(Integer.valueOf(healthNoSetTrafficLimit.mKey), healthNoSetTrafficLimit);
            this.f2401l.put(Integer.valueOf(healthBootApp.mKey), healthBootApp);
        }
        HealthRunningAppProcess healthRunningAppProcess = new HealthRunningAppProcess(this.f2403n, this);
        HealthClearCache healthClearCache = new HealthClearCache(this.f2403n, this);
        HealthProtectTraffic healthProtectTraffic = new HealthProtectTraffic(this.f2403n, this);
        HealthSendSmsFromBackgroud healthSendSmsFromBackgroud = new HealthSendSmsFromBackgroud(this.f2403n, this);
        HealthProtectPrivacy healthProtectPrivacy = new HealthProtectPrivacy(this.f2403n, this);
        HealthReadPrivacyApp healthReadPrivacyApp = new HealthReadPrivacyApp(this.f2403n, this);
        HealthHarassIntercept healthHarassIntercept = new HealthHarassIntercept(this.f2403n, this);
        HealthTrafficMonitor healthTrafficMonitor = new HealthTrafficMonitor(this.f2403n, this);
        HealthSafepaymen healthSafepaymen = new HealthSafepaymen(this.f2403n, this);
        HealthSafeInputMethod healthSafeInputMethod = new HealthSafeInputMethod(this.f2403n, this);
        HealthWlanAutoUpdateLab healthWlanAutoUpdateLab = new HealthWlanAutoUpdateLab(this.f2403n, this);
        this.f2401l.put(Integer.valueOf(healthRunningAppProcess.mKey), healthRunningAppProcess);
        this.f2401l.put(Integer.valueOf(healthClearCache.mKey), healthClearCache);
        this.f2401l.put(Integer.valueOf(healthProtectTraffic.mKey), healthProtectTraffic);
        this.f2401l.put(Integer.valueOf(healthSendSmsFromBackgroud.mKey), healthSendSmsFromBackgroud);
        this.f2401l.put(Integer.valueOf(healthProtectPrivacy.mKey), healthProtectPrivacy);
        this.f2401l.put(Integer.valueOf(healthReadPrivacyApp.mKey), healthReadPrivacyApp);
        this.f2401l.put(Integer.valueOf(healthHarassIntercept.mKey), healthHarassIntercept);
        this.f2401l.put(Integer.valueOf(healthTrafficMonitor.mKey), healthTrafficMonitor);
        this.f2401l.put(Integer.valueOf(healthSafepaymen.mKey), healthSafepaymen);
        this.f2401l.put(Integer.valueOf(healthSafeInputMethod.mKey), healthSafeInputMethod);
        this.f2401l.put(Integer.valueOf(healthWlanAutoUpdateLab.mKey), healthWlanAutoUpdateLab);
        if (!this.f2405p) {
            HealthKillVirus healthKillVirus = new HealthKillVirus(this.f2403n, this);
            this.f2401l.put(Integer.valueOf(healthKillVirus.mKey), healthKillVirus);
        }
    }

    public void scan(final HealthCheckCallback scanCallback) {
        Log.m2636i("wu0wu", "HealthManager scan ||isWorking=" + this.f2406q);
        if (!this.f2406q) {
            new Thread(new Runnable() { // from class: com.lenovo.safecenter.HealthCheck.HealthManager.1
                @Override // java.lang.Runnable
                public final void run() {
                    HealthManager.this.f2406q = true;
                    HealthManager.this.f2402m = scanCallback;
                    HealthManager.m1037a(HealthManager.this);
                    HealthManager.this.f2406q = false;
                }
            }).start();
        }
    }

    public void optimize(final ArrayList<Integer> keys) {
        if (!this.f2406q) {
            new Thread(new Runnable() { // from class: com.lenovo.safecenter.HealthCheck.HealthManager.2
                @Override // java.lang.Runnable
                public final void run() {
                    HealthManager.this.f2406q = true;
                    HealthManager.m1038a(HealthManager.this, keys);
                    HealthManager.this.f2406q = false;
                }
            }).start();
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.HealthResultCallback
    public void onOneItemProcess(HealthItemResult result) {
        this.f2402m.onOneItemProcess(result);
    }

    @Override // com.lenovo.safecenter.HealthCheck.HealthResultCallback
    public void result(HealthItemResult result) {
        this.f2402m.onResult(result);
    }

    public void exit() {
        if (this.f2396g == 0 || this.f2396g == 2) {
            this.f2404o = true;
        } else {
            this.f2404o = true;
            m1035a();
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1035a() {
        if (this.f2401l != null) {
            if (this.f2401l.containsKey(21)) {
                if (this.f2396g == 0 && getScanIndex() == getAllItemSize() - 1) {
                    ((HealthKillVirus) getHealthCheckItemByKey(21)).cancelScan();
                    WflUtils.Log("d", "wu0wu", "mQScannerMananger.cancelScan()");
                }
                WflUtils.Log("d", "wu0wu", "KEY_KILL_VIRUS.clear()");
                getHealthCheckItemByKey(21).clear();
            }
            this.f2401l.clear();
        }
    }

    public boolean containsKey(int key) {
        return this.f2401l.containsKey(Integer.valueOf(key));
    }

    public void setItemsManual() {
        if (containsKey(2)) {
            HealthLeCloudSynForContact lecloud = (HealthLeCloudSynForContact) getHealthCheckItemByKey(2);
            if (lecloud.isShowLeCloudActivity()) {
                lecloud.manual();
            }
        }
        if (containsKey(4)) {
            HealthLowMenory lowMemory = (HealthLowMenory) getHealthCheckItemByKey(4);
            if (lowMemory.isShowLowMemoryActivity()) {
                lowMemory.manual();
            }
        }
        if (containsKey(5)) {
            HealthProtectThief thief = (HealthProtectThief) getHealthCheckItemByKey(5);
            if (thief.isShowProtectThiefActivity()) {
                thief.manual();
            }
        }
        if (containsKey(7)) {
            HealthBootApp bootApp = (HealthBootApp) getHealthCheckItemByKey(7);
            if (bootApp.isShowBootSpeedActivity()) {
                bootApp.manual();
            }
        }
    }

    public int getAllItemSize() {
        if (this.f2401l == null) {
            return 0;
        }
        return this.f2401l.size();
    }

    public BaseHealthCheck getHealthCheckItemByKey(int itemKey) {
        if (this.f2401l == null) {
            return null;
        }
        return this.f2401l.get(Integer.valueOf(itemKey));
    }

    public int getScanIndex() {
        return this.f2397h;
    }

    public int getStatus() {
        return this.f2396g;
    }

    public void setStatus(int status) {
        this.f2396g = status;
        this.f2402m.onStatusChanged(status);
    }

    public int getScore() {
        return this.f2395f;
    }

    public void setScore(int score) {
        this.f2395f = score;
        this.f2402m.onScoreChanged(score);
    }

    public int getScanProgress() {
        return this.f2398i;
    }

    public void setScanProgress(int scanProgress) {
        this.f2398i = scanProgress;
        this.f2402m.onProgressChanged(scanProgress);
    }

    public int getMAX_PROGRESS() {
        return this.f2399j;
    }

    public int getValueProgressEveryCheck() {
        return this.f2400k;
    }

    public void setProgressBarIndeterminate(boolean isIndeterminate) {
        this.f2402m.setProgressBarIndeterminate(isIndeterminate);
    }

    public void plusOrDecrementNumItem(int viewType, boolean isPlus) {
        switch (viewType) {
            case 1:
                if (isPlus) {
                    this.f2390a++;
                } else {
                    this.f2390a--;
                }
                break;
            case 2:
                if (isPlus) {
                    this.f2393d++;
                } else {
                    this.f2393d--;
                }
                break;
            case 3:
                if (isPlus) {
                    this.f2391b++;
                } else {
                    this.f2391b--;
                }
                break;
            case 4:
                if (isPlus) {
                    this.f2394e++;
                } else {
                    this.f2394e--;
                }
                break;
            case 5:
                if (isPlus) {
                    this.f2392c++;
                } else {
                    this.f2392c--;
                }
                break;
        }
    }

    public int getNumDangerItem() {
        return this.f2390a;
    }

    public int getNumManualItem() {
        return this.f2391b;
    }

    public int getNumSafeItem() {
        return this.f2392c;
    }

    public int getNumCanOptimizationItem() {
        return this.f2393d;
    }

    public int getNumHasOptimizationItem() {
        return this.f2394e;
    }

    public void saveHealthScoreAndCheckupTime() {
        Const.isHealthCheckNoOptimiza(false);
        WflUtils.Log("i", "wu0wu", "HealthCheckup saveHealthScoreAndCheckupTime...");
        int score = this.f2395f;
        if (this.f2395f > 100) {
            score = 100;
        } else if (this.f2395f < 0) {
            score = 0;
        }
        Const.setHealthCheckupScore(score);
        Const.setHealthCheckupTime(System.currentTimeMillis());
        if (Const.isFirstHealthCheckup()) {
            Const.setFirstHealthCheckup();
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1039a(ArrayList<BaseHealthCheck> scanItems) {
        for (int index = 0; index < scanItems.size(); index++) {
            BaseHealthCheck checkItem = scanItems.get(index);
            this.f2397h = index;
            WflUtils.Log("i", "wu0wu", "checkItem.key=" + checkItem.mKey);
            checkItem.scan();
            this.f2401l.put(Integer.valueOf(checkItem.mKey), checkItem);
            try {
                Thread.sleep(300L);
                if (this.f2404o) {
                    WflUtils.Log("i", "wu0wu", "isExit scan");
                    m1035a();
                    return;
                }
                continue;
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        if (this.f2395f != 100) {
            setStatus(1);
        } else {
            setStatus(3);
        }
    }

    /* JADX INFO: renamed from: b */
    private void m1041b(ArrayList<BaseHealthCheck> canOptimizaItems) {
        for (int index = 0; index < canOptimizaItems.size(); index++) {
            BaseHealthCheck checkItem = canOptimizaItems.get(index);
            checkItem.optimiza();
            this.f2401l.put(Integer.valueOf(checkItem.mKey), checkItem);
            WflUtils.Log("i", "wu0wu", "optimiza checkItem.key=" + checkItem.mKey);
            if (this.f2396g == 4) {
                WflUtils.Log("i", "wu0wu", "===================Optimization.end======================");
                return;
            }
            if (this.f2404o) {
                WflUtils.Log("i", "wu0wu", "isExit Optimization");
                m1035a();
                return;
            } else {
                try {
                    Thread.sleep(300L);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
        if (this.f2395f != 100) {
            setStatus(1);
        } else {
            setStatus(3);
        }
        saveHealthScoreAndCheckupTime();
    }

    /* JADX INFO: renamed from: a */
    private void m1036a(int action) {
        saveHealthScoreAndCheckupTime();
        this.f2402m.onFinished(action);
    }

    public int getSizeByWeightType(int type) {
        int count = 0;
        for (Map.Entry<Integer, BaseHealthCheck> entry : this.f2401l.entrySet()) {
            BaseHealthCheck item = entry.getValue();
            if (item.result.weight == type) {
                count++;
            }
        }
        return count;
    }
}
