package com.tencent.tmsecure.module.optimize;

import android.content.Context;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.PriorityQueue;
import tms.C1255ed;
import tms.C1336v;

/* JADX INFO: loaded from: classes.dex */
public class CpuHelperImpl implements ICpuHelper {

    /* JADX INFO: renamed from: a */
    private static final String f6109a = "/sys/devices/system/cpu/cpu0/cpufreq/";

    /* JADX INFO: renamed from: b */
    private static final String f6110b = "/sys/devices/system/cpu/cpu0/cpufreq/stats/";

    /* JADX INFO: renamed from: c */
    private static final String f6111c = "cpuinfo_max_freq";

    /* JADX INFO: renamed from: d */
    private static final String f6112d = "cpuinfo_min_freq";

    /* JADX INFO: renamed from: e */
    private static final String f6113e = "scaling_available_governors";

    /* JADX INFO: renamed from: f */
    private static final String f6114f = "scaling_governor";

    /* JADX INFO: renamed from: g */
    private static final String f6115g = "scaling_max_freq";

    /* JADX INFO: renamed from: h */
    private static final String f6116h = "scaling_min_freq";

    /* JADX INFO: renamed from: i */
    private static final String f6117i = "scaling_cur_freq";

    /* JADX INFO: renamed from: j */
    private static final String f6118j = "scaling_available_frequencies";

    /* JADX INFO: renamed from: k */
    private static final String f6119k = "scaling_setspeed";

    /* JADX INFO: renamed from: l */
    private static final String f6120l = "time_in_state";

    /* JADX INFO: renamed from: m */
    private static final String f6121m = "/sys/devices/system/cpu/";

    /* JADX INFO: renamed from: n */
    private static final String f6122n = "kernel_max";

    /* JADX INFO: renamed from: o */
    private static final String f6123o = "online";

    /* JADX INFO: renamed from: p */
    private static final String f6124p = "present";

    /* JADX INFO: renamed from: q */
    private static final String f6125q = "possible";

    /* JADX INFO: renamed from: r */
    private int f6126r = 0;

    /* JADX INFO: renamed from: s */
    private String[] f6127s;

    /* JADX INFO: renamed from: t */
    private int[] f6128t;

    /* JADX INFO: renamed from: u */
    private int f6129u;

    /* JADX INFO: renamed from: v */
    private int f6130v;

    /* JADX INFO: renamed from: w */
    private int f6131w;

    public CpuHelperImpl(Context context) {
        if (ScriptHelper.providerSupportCpuRelative()) {
            return;
        }
        ScriptHelper.canRunAtRoot(new C1255ed(this));
    }

    /* JADX INFO: renamed from: a */
    private static PriorityQueue<Integer> m2609a(String str) {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        String[] strArrSplit = str.split(",");
        if (strArrSplit != null) {
            for (String str2 : strArrSplit) {
                String[] strArrSplit2 = str2.split("-");
                if (strArrSplit2 != null) {
                    if (strArrSplit2.length == 1) {
                        priorityQueue.add(Integer.valueOf(Integer.parseInt(strArrSplit2[0])));
                    } else if (strArrSplit2.length == 2) {
                        int i = Integer.parseInt(strArrSplit2[1]);
                        for (int i2 = Integer.parseInt(strArrSplit2[0]); i2 <= i; i2++) {
                            priorityQueue.add(Integer.valueOf(i2));
                        }
                    }
                }
            }
        }
        return priorityQueue;
    }

    /* JADX INFO: renamed from: a */
    private boolean m2610a(int i) {
        for (int i2 : getScalingAvaliableFrequencies()) {
            if (i2 == i) {
                return true;
            }
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    private int[] m2611a() {
        boolean z;
        int cpuInfoMinFreq = getCpuInfoMinFreq();
        int cpuInfoMaxFreq = getCpuInfoMaxFreq();
        int scalingCurFreq = getScalingCurFreq();
        if (cpuInfoMinFreq == 0 || cpuInfoMaxFreq == 0 || scalingCurFreq == 0) {
            return null;
        }
        ArrayList arrayList = new ArrayList(6);
        arrayList.add(Integer.valueOf(cpuInfoMinFreq));
        arrayList.add(Integer.valueOf(cpuInfoMaxFreq));
        if (scalingCurFreq != cpuInfoMinFreq && scalingCurFreq != cpuInfoMaxFreq) {
            arrayList.add(Integer.valueOf(scalingCurFreq));
        }
        String scalingGovernor = getScalingGovernor();
        if (!"userspace".equals(scalingGovernor) && getScalingAvaliableGovernors() != null && m2613b("userspace")) {
            setScalingGovernor("userspace");
        }
        if ("userspace".equals(getScalingGovernor())) {
            boolean z2 = true;
            int i = (cpuInfoMaxFreq + cpuInfoMinFreq) / 2;
            int i2 = 0;
            while (true) {
                i2++;
                if (i2 >= 3) {
                    break;
                }
                setScalingFreq(i, false);
                int scalingCurFreq2 = getScalingCurFreq();
                Iterator it = arrayList.iterator();
                while (true) {
                    if (!it.hasNext()) {
                        z = false;
                        break;
                    }
                    if (((Integer) it.next()).intValue() == scalingCurFreq2) {
                        z = true;
                        break;
                    }
                }
                if (!z) {
                    arrayList.add(Integer.valueOf(scalingCurFreq2));
                }
                if (z2) {
                    z2 = false;
                    i = (cpuInfoMaxFreq + scalingCurFreq2) / 2;
                } else {
                    z2 = true;
                    i = (cpuInfoMinFreq + scalingCurFreq2) / 2;
                }
            }
            setScalingGovernor(scalingGovernor);
        }
        int size = arrayList.size();
        int[] iArr = new int[size];
        for (int i3 = 0; i3 < size; i3++) {
            iArr[i3] = ((Integer) arrayList.get(i3)).intValue();
        }
        return iArr;
    }

    /* JADX INFO: renamed from: b */
    private static int m2612b() {
        PriorityQueue<Integer> priorityQueueM2609a = m2609a(C1336v.m3606i("/sys/devices/system/cpu/present").trim());
        int i = 0;
        Iterator<Integer> it = m2609a(C1336v.m3606i("/sys/devices/system/cpu/possible").trim()).iterator();
        while (true) {
            int i2 = i;
            if (!it.hasNext()) {
                return i2;
            }
            i = priorityQueueM2609a.contains(Integer.valueOf(it.next().intValue())) ? i2 + 1 : i2;
        }
    }

    /* JADX INFO: renamed from: b */
    private boolean m2613b(String str) {
        String[] scalingAvaliableGovernors = getScalingAvaliableGovernors();
        if (scalingAvaliableGovernors == null || scalingAvaliableGovernors.length == 0) {
            return false;
        }
        for (String str2 : scalingAvaliableGovernors) {
            if (str2.equals(str)) {
                return true;
            }
        }
        return false;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public int getAvailableCpus() {
        if (this.f6126r <= 0) {
            this.f6126r = m2612b();
        }
        return this.f6126r;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public int getCpuInfoMaxFreq() {
        if (this.f6129u == 0) {
            if (ScriptHelper.providerSupportCpuRelative()) {
                this.f6129u = ScriptHelper.provider().m3511b(1);
            } else {
                String strTrim = C1336v.m3606i("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq").trim();
                if (strTrim != null && strTrim.length() > 0) {
                    this.f6129u = Integer.valueOf(strTrim).intValue();
                }
            }
        }
        return this.f6129u;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public int getCpuInfoMinFreq() {
        if (this.f6130v == 0) {
            if (ScriptHelper.providerSupportCpuRelative()) {
                this.f6130v = ScriptHelper.provider().m3511b(0);
            } else {
                String strTrim = C1336v.m3606i("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq").trim();
                if (strTrim != null && strTrim.length() > 0) {
                    this.f6130v = Integer.valueOf(strTrim).intValue();
                }
            }
        }
        return this.f6130v;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public int getKernelMax() {
        String strTrim;
        if (ScriptHelper.providerSupportCpuRelative()) {
            return ScriptHelper.provider().m3522f();
        }
        if (this.f6131w == 0 && (strTrim = C1336v.m3606i("/sys/devices/system/cpu/kernel_max").trim()) != null && strTrim.length() > 0) {
            this.f6131w = Integer.valueOf(strTrim).intValue() + 1;
        }
        return this.f6131w;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public String[] getOnlineCpus() {
        if (ScriptHelper.providerSupportCpuRelative()) {
            return ScriptHelper.provider().m3516c(2);
        }
        String strTrim = C1336v.m3606i("/sys/devices/system/cpu/online").trim();
        if (strTrim == null || strTrim.length() <= 0) {
            return null;
        }
        int iIndexOf = strTrim.indexOf("-");
        while (true) {
            String str = strTrim;
            if (iIndexOf == -1) {
                return str.split(",");
            }
            int i = Integer.parseInt(str.substring(iIndexOf + 1, iIndexOf + 2));
            int i2 = Integer.parseInt(str.substring(iIndexOf - 1, iIndexOf));
            StringBuffer stringBuffer = new StringBuffer(i2 + ",");
            int i3 = i2;
            while (true) {
                i3++;
                if (i3 < i) {
                    stringBuffer.append(i3 + ",");
                }
            }
            stringBuffer.append(i);
            strTrim = str.replaceFirst(i2 + "-" + i, stringBuffer.toString());
            iIndexOf = strTrim.indexOf("-");
        }
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public synchronized int[] getScalingAvaliableFrequencies() {
        int[] iArr;
        int i = 0;
        synchronized (this) {
            if (this.f6128t == null) {
                if (ScriptHelper.providerSupportCpuRelative()) {
                    String[] strArrM3516c = ScriptHelper.provider().m3516c(1);
                    this.f6128t = new int[strArrM3516c.length];
                    while (i < strArrM3516c.length) {
                        this.f6128t[i] = Integer.valueOf(strArrM3516c[i]).intValue();
                        i++;
                    }
                } else {
                    String strTrim = C1336v.m3606i("/sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies").trim();
                    if (strTrim.length() > 0) {
                        String[] strArrSplit = strTrim.split(" ");
                        this.f6128t = new int[strArrSplit.length];
                        while (i < strArrSplit.length) {
                            this.f6128t[i] = Integer.valueOf(strArrSplit[i]).intValue();
                            i++;
                        }
                    } else {
                        String[] strArrM3607j = C1336v.m3607j("/sys/devices/system/cpu/cpu0/cpufreq/stats/time_in_state");
                        if (strArrM3607j == null || strArrM3607j.length <= 0) {
                            this.f6128t = m2611a();
                        } else {
                            this.f6128t = new int[strArrM3607j.length];
                            while (i < strArrM3607j.length) {
                                this.f6128t[i] = Integer.valueOf(strArrM3607j[i].split(" ")[0]).intValue();
                                i++;
                            }
                        }
                    }
                }
            }
            iArr = this.f6128t;
        }
        return iArr;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public synchronized String[] getScalingAvaliableGovernors() {
        if (this.f6127s == null) {
            if (ScriptHelper.providerSupportCpuRelative()) {
                this.f6127s = ScriptHelper.provider().m3516c(0);
            } else {
                String strTrim = C1336v.m3606i("/sys/devices/system/cpu/cpu0/cpufreq/scaling_available_governors").trim();
                if (strTrim != null && strTrim.length() > 0) {
                    this.f6127s = strTrim.split(" ");
                }
            }
        }
        return this.f6127s;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public int getScalingCurFreq() {
        if (ScriptHelper.providerSupportCpuRelative()) {
            return ScriptHelper.provider().m3511b(2);
        }
        String strTrim = C1336v.m3606i("/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq").trim();
        if (strTrim == null || strTrim.length() == 0) {
            return 0;
        }
        return Integer.valueOf(strTrim).intValue();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public String getScalingGovernor() {
        if (ScriptHelper.providerSupportCpuRelative()) {
            return ScriptHelper.provider().m3520e();
        }
        String strTrim = C1336v.m3606i("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor").trim();
        if (strTrim == null || strTrim.length() == 0) {
            return null;
        }
        return strTrim;
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public int getScalingMaxFreq() {
        if (ScriptHelper.providerSupportCpuRelative()) {
            return ScriptHelper.provider().m3511b(4);
        }
        String strTrim = C1336v.m3606i("/sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq").trim();
        if (strTrim == null || strTrim.length() == 0) {
            return 0;
        }
        return Integer.valueOf(strTrim).intValue();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public int getScalingMinFreq() {
        if (ScriptHelper.providerSupportCpuRelative()) {
            return ScriptHelper.provider().m3511b(3);
        }
        String strTrim = C1336v.m3606i("/sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq").trim();
        if (strTrim == null || strTrim.length() == 0) {
            return 0;
        }
        return Integer.valueOf(strTrim).intValue();
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public void setScalingFreq(int i) throws IllegalArgumentException {
        setScalingFreq(i, true);
    }

    public void setScalingFreq(int i, boolean z) throws IllegalArgumentException {
        if (ScriptHelper.providerSupportCpuRelative()) {
            ScriptHelper.provider().m3506a(2, i, z);
            return;
        }
        if (z) {
            if (!m2610a(i)) {
                throw new IllegalArgumentException("the freq is not available!");
            }
            if (i < getScalingMinFreq() || i > getScalingMaxFreq()) {
                throw new IllegalArgumentException("the freq should not be smaller than the min freq and not be larger than the max freq!");
            }
        }
        ScriptHelper.runScriptAsRoot("echo " + i + " > " + f6109a + f6119k);
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public synchronized void setScalingGovernor(String str) throws IllegalArgumentException {
        if (ScriptHelper.providerSupportCpuRelative()) {
            ScriptHelper.provider().m3507a(str);
        } else {
            if (this.f6127s == null) {
                getScalingAvaliableGovernors();
            }
            if (!m2613b(str)) {
                throw new IllegalArgumentException("the governor is unavailable!");
            }
            ScriptHelper.runScriptAsRoot("echo " + str + " > " + f6109a + f6114f);
        }
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public void setScalingMaxFreq(int i) throws IllegalArgumentException {
        if (ScriptHelper.providerSupportCpuRelative()) {
            ScriptHelper.provider().m3506a(4, i, true);
        } else {
            if (!m2610a(i)) {
                throw new IllegalArgumentException("the max freq is not available!");
            }
            if (i < getScalingMinFreq()) {
                throw new IllegalArgumentException("the max freq can not be smaller than the min freq!");
            }
            ScriptHelper.runScriptAsRoot("echo " + i + " > " + f6109a + f6115g);
        }
    }

    @Override // com.tencent.tmsecure.module.optimize.ICpuHelper
    public void setScalingMinFreq(int i) throws IllegalArgumentException {
        if (ScriptHelper.providerSupportCpuRelative()) {
            ScriptHelper.provider().m3506a(3, i, true);
        } else {
            if (!m2610a(i)) {
                throw new IllegalArgumentException("the min freq is not available!");
            }
            if (i > getScalingMaxFreq()) {
                throw new IllegalArgumentException("the min freq can not be larger than the max freq!");
            }
            ScriptHelper.runScriptAsRoot("echo " + i + " > " + f6109a + f6116h);
        }
    }
}
