package tms;

import android.content.Context;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.module.netsetting.Rule;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: renamed from: tms.dj */
/* JADX INFO: loaded from: classes.dex */
public final class C1234dj extends BaseManager {

    /* JADX INFO: renamed from: a */
    private int f7120a = -1;

    /* JADX INFO: renamed from: b */
    private boolean f7121b = false;

    /* JADX INFO: renamed from: c */
    private String f7122c;

    /* JADX INFO: renamed from: a */
    public final int m3134a() {
        if (this.f7120a != -1) {
            return this.f7120a;
        }
        String strRunScript = ScriptHelper.runScript("cat /proc/net/ip_tables_names");
        String strRunScript2 = ScriptHelper.runScript("cat /proc/net/ip_tables_matches");
        String strRunScript3 = ScriptHelper.runScript("cat /proc/net/ip_tables_targets");
        if (strRunScript == null || strRunScript2 == null || strRunScript3 == null) {
            this.f7120a = 0;
            return this.f7120a;
        }
        if (!strRunScript.contains("filter") || !strRunScript2.contains("owner")) {
            this.f7120a = 0;
        } else if (strRunScript3.contains("MARK") && new File("/proc/net/netfilter/nfnetlink_queue").exists()) {
            this.f7120a = 2;
        } else {
            this.f7120a = 1;
        }
        return this.f7120a;
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<Rule> m3135a(int i) {
        boolean zEquals;
        String strRunScript = ScriptHelper.runScript(this.f7122c + " list-rules ");
        if (strRunScript == null) {
            return new ArrayList<>();
        }
        ArrayList<Rule> arrayList = new ArrayList<>();
        ArrayList<Rule> arrayList2 = new ArrayList();
        ArrayList<Rule> arrayList3 = new ArrayList();
        String[] strArrSplit = strRunScript.toString().split("\n");
        for (String str : strArrSplit) {
            String[] strArrSplit2 = str.split("[ ]+");
            if (i == 2) {
                if (strArrSplit2[0].equals("host")) {
                    Rule rule = new Rule();
                    rule.type = 2;
                    rule.host = strArrSplit2[1];
                    rule.hostVerdict = strArrSplit2[2];
                    arrayList.add(rule);
                }
            } else if (i == 1 && ((zEquals = strArrSplit2[0].equals("mobile")) || strArrSplit2[0].equals(SettingUtil.WIFI))) {
                Rule rule2 = new Rule();
                rule2.type = 1;
                rule2.uid = Integer.valueOf(strArrSplit2[1]).intValue();
                if (zEquals) {
                    rule2.uidMobileVerdict = strArrSplit2[2];
                    arrayList2.add(rule2);
                } else {
                    rule2.uidWifiVerdict = strArrSplit2[2];
                    arrayList3.add(rule2);
                }
            }
        }
        if (i == 1) {
            for (Rule rule3 : arrayList3) {
                for (Rule rule4 : arrayList2) {
                    if (rule3.uid == rule4.uid) {
                        rule4.uidWifiVerdict = rule3.uidWifiVerdict;
                    }
                }
            }
            arrayList.addAll(arrayList2);
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public final void m3136a(Rule rule) {
        ArrayList arrayList = new ArrayList();
        arrayList.add(rule);
        m3139b(arrayList);
    }

    /* JADX INFO: renamed from: a */
    public final void m3137a(boolean z) {
        ScriptHelper.runScript(this.f7122c + " set-enable " + z);
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3138a(List<Rule> list) {
        boolean z = true;
        if (!this.f7121b) {
            String str = this.f7122c;
            if (!C1219cv.m3076a(str) && ScriptHelper.runScript(str + " init-chain") == null) {
                z = false;
            }
            this.f7121b = z;
        }
        if (this.f7121b) {
            ArrayList arrayList = new ArrayList();
            for (Rule rule : list) {
                switch (rule.type) {
                    case 1:
                        if ((rule.uidMobileVerdict != null && !rule.uidMobileVerdict.equals(Rule.VERDICT_ACCEPT)) || (rule.uidWifiVerdict != null && !rule.uidWifiVerdict.equals(Rule.VERDICT_ACCEPT))) {
                            arrayList.add(rule);
                        }
                        break;
                    case 2:
                        if (rule.hostVerdict != null && !rule.hostVerdict.equals(Rule.VERDICT_ACCEPT)) {
                            arrayList.add(rule);
                        }
                        break;
                }
            }
            m3139b(arrayList);
        }
        return this.f7121b;
    }

    /* JADX INFO: renamed from: b */
    public final void m3139b(List<Rule> list) {
        String str = this.f7122c;
        StringBuilder sb = new StringBuilder(str + " set-hosts ");
        StringBuilder sb2 = new StringBuilder(str + " set-uids ");
        for (Rule rule : list) {
            switch (rule.type) {
                case 1:
                    if (rule.uidMobileVerdict != null) {
                        sb2.append(" " + rule.uid + " mobile " + rule.uidMobileVerdict);
                    }
                    if (rule.uidWifiVerdict != null) {
                        sb2.append(" " + rule.uid + " wifi " + rule.uidWifiVerdict);
                    }
                    break;
                case 2:
                    if (rule.hostVerdict != null) {
                        sb.append(" " + rule.host + " " + rule.hostVerdict);
                    }
                    break;
            }
        }
        if (ScriptHelper.runScript(sb.toString()) == null) {
            return;
        }
        ScriptHelper.runScript(sb2.toString());
    }

    /* JADX INFO: renamed from: b */
    public final boolean m3140b() {
        this.f7121b = C1219cv.m3076a(this.f7122c);
        return this.f7121b;
    }

    /* JADX INFO: renamed from: c */
    public final boolean m3141c() {
        String strRunScript = ScriptHelper.runScript(this.f7122c + " get-enable");
        if (strRunScript == null) {
            return false;
        }
        return strRunScript.contains("true");
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7122c = C1336v.m3577a(context, "firewall.dat", (String) null);
    }
}
