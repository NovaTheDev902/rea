package com.lenovo.performancecenter.service.object;

/* JADX INFO: loaded from: classes.dex */
public class PolicyObject {
    public static final String Describe = "com.lenovo.performancecenter.service.object.PolicyObject";
    public static boolean sortBy;
    public static int totleRuningCount;
    public long impLevel;
    public String label;
    public long lastCpuTime;
    public int pid;
    public String pkgName;
    public String proName;
    public int selfRunningCount;
    public long totleQianTaiCpuTime;
    public long lastQianTaiCputime = -1;
    public long cpuTimeSpace = -1;

    public PolicyObject(int pid, String pkgName, String label, String proName) {
        this.pid = pid;
        this.pkgName = pkgName;
        this.label = label;
        this.proName = proName;
    }

    public int hashCode() {
        return this.pkgName.hashCode();
    }

    public boolean equals(Object o) {
        return this.pkgName.equals(((PolicyObject) o).pkgName);
    }

    public int compareTo(PolicyObject obj) {
        if (sortBy) {
            if (this.cpuTimeSpace > obj.cpuTimeSpace) {
                return -1;
            }
            return this.cpuTimeSpace < obj.cpuTimeSpace ? 1 : 0;
        }
        if (this.impLevel <= obj.impLevel) {
            return this.impLevel < obj.impLevel ? 1 : 0;
        }
        return -1;
    }
}
