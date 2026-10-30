package com.lenovo.performancecenter.performance;

import android.app.ActivityManager;
import android.content.Context;
import android.os.Debug;
import android.os.Handler;
import android.os.Message;
import com.lenovo.performancecenter.LeemCenterJNITools;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.performancecenter.service.object.PolicyAppInfo;
import com.lenovo.performancecenter.service.object.PolicyObject;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.TimerTask;

/* JADX INFO: loaded from: classes.dex */
public class PolicyTask extends TimerTask {

    /* JADX INFO: renamed from: a */
    private String f1815a;

    /* JADX INFO: renamed from: c */
    private Handler f1817c;
    protected ArrayList<PolicyObject> canKillList;

    /* JADX INFO: renamed from: e */
    private HashMap<String, PolicyAppInfo> f1819e;

    /* JADX INFO: renamed from: f */
    private HashMap<String, PolicyObject> f1820f;

    /* JADX INFO: renamed from: g */
    private ArrayList<PolicyObject> f1821g;

    /* JADX INFO: renamed from: h */
    private ArrayList<PolicyObject> f1822h;

    /* JADX INFO: renamed from: i */
    private Context f1823i;

    /* JADX INFO: renamed from: b */
    private String f1816b = "";

    /* JADX INFO: renamed from: d */
    private int f1818d = 5;

    /* JADX INFO: renamed from: j */
    private String f1824j = "";
    public boolean isRunning = true;

    public PolicyTask(Context context, Handler handler) {
        this.f1815a = "";
        this.f1823i = context;
        this.f1817c = handler;
        ActivityManager am = (ActivityManager) this.f1823i.getSystemService("activity");
        if (!am.getRunningTasks(1).isEmpty()) {
            List<ActivityManager.RunningTaskInfo> runningTaskInfo = am.getRunningTasks(1);
            if (runningTaskInfo.size() != 0) {
                this.f1815a = runningTaskInfo.get(0).topActivity.getPackageName();
            }
        }
        this.f1820f = new HashMap<>();
        this.f1821g = new ArrayList<>();
        this.canKillList = new ArrayList<>();
        this.f1822h = new ArrayList<>();
        this.f1819e = new HashMap<>();
    }

    public void updatePolicyData(PolicyAppInfo mUAI, boolean executePolicy) {
        PolicyObject po;
        long[] pidCpuTime = new long[1];
        int ret = LeemCenterJNITools.getPidCpuTime_native(new int[]{mUAI.pid}, pidCpuTime);
        if (ret == 0) {
            if (this.f1820f.containsKey(mUAI.packageName)) {
                po = this.f1820f.get(mUAI.packageName);
            } else {
                po = new PolicyObject(mUAI.pid, mUAI.packageName, mUAI.label, mUAI.processName);
                po.lastCpuTime = pidCpuTime[0];
            }
            if (mUAI.packageName.equals(this.f1815a)) {
                if (!executePolicy) {
                    po.lastQianTaiCputime = pidCpuTime[0];
                } else if (po.lastQianTaiCputime >= 0) {
                    po.totleQianTaiCpuTime += pidCpuTime[0] - po.lastQianTaiCputime;
                }
            } else if (mUAI.packageName.equals(this.f1816b) && po.lastQianTaiCputime >= 0) {
                po.totleQianTaiCpuTime += pidCpuTime[0] - po.lastQianTaiCputime;
            }
            if (executePolicy) {
                po.cpuTimeSpace = (pidCpuTime[0] - po.lastCpuTime) - po.totleQianTaiCpuTime;
            } else {
                po.selfRunningCount++;
                po.impLevel = mUAI.getTotleImpLevel().longValue();
            }
            this.f1820f.put(mUAI.packageName, po);
        }
    }

    /* JADX INFO: renamed from: a */
    private void m714a() {
        synchronized (this.f1819e) {
            for (String pkgName : this.f1819e.keySet()) {
                if (this.f1820f.containsKey(pkgName)) {
                    updatePolicyData(this.f1819e.get(pkgName), true);
                    PolicyObject po = this.f1820f.get(pkgName);
                    if (po.selfRunningCount == PolicyObject.totleRuningCount) {
                        synchronized (this.f1821g) {
                            this.f1821g.add(po);
                        }
                    } else {
                        continue;
                    }
                }
            }
        }
        synchronized (this.canKillList) {
            PolicyObject.sortBy = false;
            synchronized (this.f1821g) {
                m715a(this.f1821g);
                int i = 0;
                for (PolicyObject policyObject : this.f1821g) {
                    if (i <= this.f1818d && policyObject.impLevel > 100 && !DataLayerManager.isInSysWhiteList(policyObject.proName, this.f1823i)) {
                        i++;
                        synchronized (this.canKillList) {
                            this.canKillList.add(policyObject);
                        }
                        this.f1822h.add(policyObject);
                    }
                    i = i;
                }
            }
            PolicyObject.sortBy = true;
            synchronized (this.f1821g) {
                m715a(this.f1821g);
                int i2 = 0;
                for (PolicyObject policyObject2 : this.f1821g) {
                    if (!this.f1822h.contains(policyObject2) && i2 <= this.f1818d && policyObject2.cpuTimeSpace > 0 && !DataLayerManager.isInSysWhiteList(policyObject2.proName, this.f1823i) && policyObject2.impLevel > 200) {
                        i2++;
                        synchronized (this.canKillList) {
                            this.canKillList.add(policyObject2);
                        }
                    }
                    i2 = i2;
                }
            }
        }
    }

    public HashMap<String, Integer> getCanBeKilledApp() {
        m714a();
        HashMap<String, Integer> result = new HashMap<>();
        synchronized (this.canKillList) {
            for (PolicyObject po : this.canKillList) {
                result.put(po.pkgName, Integer.valueOf(po.pid));
            }
            this.canKillList.clear();
        }
        synchronized (this.f1821g) {
            this.f1821g.clear();
        }
        return result;
    }

    @Override // java.util.TimerTask, java.lang.Runnable
    public void run() {
        int i;
        int i2;
        synchronized (this.f1821g) {
            this.f1821g.clear();
        }
        synchronized (this.canKillList) {
            this.canKillList.clear();
        }
        this.f1822h.clear();
        m716b();
        m714a();
        synchronized (this.canKillList) {
            ArrayList<PolicyObject> arrayList = this.canKillList;
            int size = arrayList.size();
            int[] iArr = new int[size];
            for (int i3 = 0; i3 < size; i3++) {
                if (arrayList.get(i3) != null) {
                    iArr[i3] = arrayList.get(i3).pid;
                }
            }
            Debug.MemoryInfo[] processMemoryInfo = ((ActivityManager) this.f1823i.getSystemService("activity")).getProcessMemoryInfo(iArr);
            if (processMemoryInfo.length > 0) {
                int length = iArr.length;
                int i4 = 0;
                for (int i5 = 0; i5 < length; i5++) {
                    int totalPss = processMemoryInfo[i5].getTotalPss();
                    if (totalPss > 0) {
                        i4 += totalPss * 1024;
                    }
                }
                i = i4;
            } else {
                i = 0;
            }
            ArrayList arrayList2 = new ArrayList();
            int i6 = 0;
            for (PolicyObject policyObject : this.canKillList) {
                if (policyObject != null) {
                    i6++;
                    arrayList2.add(policyObject.pkgName);
                }
                i6 = i6;
            }
            try {
                RootPassage.execRootCmd(null, arrayList2, " -fs ", this.f1823i);
            } catch (Exception e) {
                for (PolicyObject policyObject2 : this.canKillList) {
                    if (policyObject2 != null) {
                        int i7 = i6 + 1;
                        ((ActivityManager) this.f1823i.getSystemService("activity")).killBackgroundProcesses(policyObject2.pkgName);
                        i2 = i7;
                    } else {
                        i2 = i6;
                    }
                    i6 = i2;
                }
            }
            Message messageObtainMessage = this.f1817c.obtainMessage(0);
            messageObtainMessage.arg1 = i6;
            messageObtainMessage.arg2 = i;
            this.f1817c.sendMessage(messageObtainMessage);
        }
        m716b();
        this.f1820f.clear();
        PolicyObject.totleRuningCount = 0;
    }

    /* JADX INFO: renamed from: a */
    private void m715a(ArrayList<PolicyObject> poList) {
        Collections.sort(poList, new Comparator<PolicyObject>() { // from class: com.lenovo.performancecenter.performance.PolicyTask.1
            @Override // java.util.Comparator
            public final /* synthetic */ int compare(PolicyObject policyObject, PolicyObject policyObject2) {
                return policyObject.compareTo(policyObject2);
            }
        });
    }

    /* JADX INFO: renamed from: b */
    private void m716b() {
        synchronized (this.f1819e) {
            this.f1819e.clear();
            PolicyObject.totleRuningCount++;
            this.f1819e = ScanApplicationInfo.readRunningAppInfoPolicy(this.f1823i, this);
        }
    }

    public void release() {
        if (this.f1820f != null) {
            this.f1820f.clear();
        }
        if (this.f1821g != null) {
            this.f1821g.clear();
        }
        if (this.canKillList != null) {
            this.canKillList.clear();
        }
        if (this.f1822h != null) {
            this.f1822h.clear();
        }
        if (this.f1819e != null) {
            this.f1819e.clear();
        }
    }
}
