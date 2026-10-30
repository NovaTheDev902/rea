package tms;

import QQPIM.STMatchRule;
import QQPIM.STQueryInfo;
import com.lenovo.safecenter.net.support.Utils;
import com.tencent.tccdb.MatchRule;
import com.tencent.tmsecure.module.network.TrafficCorrectionConfig;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* JADX INFO: renamed from: tms.dd */
/* JADX INFO: loaded from: classes.dex */
final class C1228dd {

    /* JADX INFO: renamed from: b */
    private final String f7079b = "LAST_SYNC_TASK_EXECUTE_TIME";

    /* JADX INFO: renamed from: c */
    private final String f7080c = "LAST_SYNC_TASK_EXECUTE_RESULT";

    /* JADX INFO: renamed from: d */
    private final String f7081d = "LAST_OPERATOR_DATA_SYNC_TIME";

    /* JADX INFO: renamed from: e */
    private final String f7082e = "ZFT_OPERATOR_CONFIG_UPDATE_TIME";

    /* JADX INFO: renamed from: f */
    private final String f7083f = "OPERATOR_CONFIG_UPDATE_TIME";

    /* JADX INFO: renamed from: g */
    private final String f7084g = "OPERATOR_CONFIG_UPDATE_RESURRECTION_TIME";

    /* JADX INFO: renamed from: h */
    private final String f7085h = "MATCH_RULE_UPDATE_TIME";

    /* JADX INFO: renamed from: i */
    private final String f7086i = "CURRENT_IMSI";

    /* JADX INFO: renamed from: j */
    private final String f7087j = "SAMPLE_COLLECTED";

    /* JADX INFO: renamed from: k */
    private final String f7088k = Utils.PROVINCE;

    /* JADX INFO: renamed from: l */
    private final String f7089l = Utils.CITY;

    /* JADX INFO: renamed from: m */
    private final String f7090m = Utils.CARRY;

    /* JADX INFO: renamed from: n */
    private final String f7091n = Utils.BRAND;

    /* JADX INFO: renamed from: a */
    C1149af f7078a = new C1149af("operator_data_sync_setting");

    /* JADX INFO: renamed from: a */
    public final TrafficCorrectionConfig m3096a() {
        return new TrafficCorrectionConfig(this.f7078a.m2883a(Utils.PROVINCE, ""), this.f7078a.m2883a(Utils.CITY, ""), this.f7078a.m2883a(Utils.CARRY, ""), this.f7078a.m2883a(Utils.BRAND, ""));
    }

    /* JADX INFO: renamed from: a */
    public final List<MatchRule> m3097a(int i) {
        ArrayList arrayList = new ArrayList();
        String strM2883a = this.f7078a.m2883a("MATCH_RULE" + i, "");
        if (strM2883a != null && !"".equals(strM2883a)) {
            String[] strArrSplit = strM2883a.split("#ITEM#");
            for (String str : strArrSplit) {
                String[] strArrSplit2 = str.split("#COLUMN#");
                if (strArrSplit2 != null && strArrSplit2.length == 4) {
                    arrayList.add(new MatchRule(Integer.valueOf(strArrSplit2[0]).intValue(), Integer.valueOf(strArrSplit2[1]).intValue(), strArrSplit2[2], strArrSplit2[3]));
                }
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public final void m3098a(long j) {
        this.f7078a.m2887a("MATCH_RULE_UPDATE_TIME", j, true);
    }

    /* JADX INFO: renamed from: a */
    public final void m3099a(List<STMatchRule> list) {
        HashMap map = new HashMap();
        for (STMatchRule sTMatchRule : list) {
            String str = (String) map.get("MATCH_RULE" + sTMatchRule.type);
            map.put("MATCH_RULE" + sTMatchRule.type, str == null ? sTMatchRule.unit + "#COLUMN#" + sTMatchRule.type + "#COLUMN#" + sTMatchRule.prefix + "#COLUMN#" + sTMatchRule.postfix : str + "#ITEM#" + sTMatchRule.unit + "#COLUMN#" + sTMatchRule.type + "#COLUMN#" + sTMatchRule.prefix + "#COLUMN#" + sTMatchRule.postfix);
        }
        for (Map.Entry entry : map.entrySet()) {
            this.f7078a.m2888a((String) entry.getKey(), (String) entry.getValue(), false);
        }
        this.f7078a.m2884a();
    }

    /* JADX INFO: renamed from: b */
    public final List<STQueryInfo> m3100b(int i) {
        ArrayList arrayList = new ArrayList();
        String strM2883a = this.f7078a.m2883a("QUERY_INFO" + i, "");
        if (strM2883a != null && !"".equals(strM2883a)) {
            String[] strArrSplit = strM2883a.split("#ITEM#");
            for (String str : strArrSplit) {
                String[] strArrSplit2 = str.split("#COLUMN#");
                if (strArrSplit2 != null && strArrSplit2.length == 3) {
                    arrayList.add(new STQueryInfo(Integer.valueOf(strArrSplit2[0]).intValue(), strArrSplit2[1], strArrSplit2[2]));
                }
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: b */
    public final void m3101b(List<STQueryInfo> list) {
        HashMap map = new HashMap();
        for (STQueryInfo sTQueryInfo : list) {
            String str = (String) map.get("QUERY_INFO" + sTQueryInfo.getNQuerytype());
            map.put("QUERY_INFO" + sTQueryInfo.getNQuerytype(), str == null ? sTQueryInfo.getNQuerytype() + "#COLUMN#" + sTQueryInfo.getStrPort() + "#COLUMN#" + sTQueryInfo.getStrCode() : str + "#ITEM#" + sTQueryInfo.getNQuerytype() + "#COLUMN#" + sTQueryInfo.getStrPort() + "#COLUMN#" + sTQueryInfo.getStrCode());
        }
        for (Map.Entry entry : map.entrySet()) {
            this.f7078a.m2888a((String) entry.getKey(), (String) entry.getValue(), false);
        }
        this.f7078a.m2884a();
    }
}
