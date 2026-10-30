package tms;

import QQPIM.NetInterfaceTypeInfo;
import QQPIM.NetInterfaceTypeInfoList;
import QQPIM.NetInterfaceUsageType;
import android.content.Context;
import android.text.TextUtils;
import com.lenovo.lps.sus.p008c.C0092c;
import com.p012qq.jce.wup.UniAttribute;
import com.tencent.tccdb.TccCryptor;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.update.UpdateConfig;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: tms.db */
/* JADX INFO: loaded from: classes.dex */
final class C1226db {

    /* JADX INFO: renamed from: e */
    private static String f7065e = "upload_config_des";

    /* JADX INFO: renamed from: j */
    private String f7074j;

    /* JADX INFO: renamed from: a */
    private final String f7066a = "MOBILE";

    /* JADX INFO: renamed from: b */
    private final String f7067b = "WIFI";

    /* JADX INFO: renamed from: c */
    private final String f7068c = "EXCLUDE";

    /* JADX INFO: renamed from: d */
    private final String f7069d = UpdateConfig.TRAFFIC_MONITOR_CONFIG_NAME;

    /* JADX INFO: renamed from: f */
    private final List<String> f7070f = new ArrayList();

    /* JADX INFO: renamed from: g */
    private final List<String> f7071g = new ArrayList();

    /* JADX INFO: renamed from: h */
    private final ArrayList<String> f7072h = new ArrayList<>();

    /* JADX INFO: renamed from: k */
    private Context f7075k = TMSApplication.getApplicaionContext();

    /* JADX INFO: renamed from: l */
    private int f7076l = 0;

    /* JADX INFO: renamed from: i */
    private C1149af f7073i = new C1149af("NetInterfaceManager");

    public C1226db(String str) {
        this.f7074j = str;
    }

    /* JADX INFO: renamed from: a */
    private String m3090a(ArrayList<String> arrayList) {
        if (this.f7076l == 0 || arrayList.isEmpty()) {
            return null;
        }
        StringBuilder sb = new StringBuilder();
        if (this.f7076l == 17) {
            sb.append("[WFGG]: ");
        } else if (this.f7076l == 1) {
            sb.append("[2G3G]: ");
        } else if (this.f7076l == 16) {
            sb.append("[WIFI]: ");
        }
        int i = 0;
        while (true) {
            int i2 = i;
            if (i2 >= arrayList.size()) {
                return sb.toString();
            }
            sb.append(arrayList.get(i2));
            if (i2 < arrayList.size() - 1) {
                sb.append(", ");
            } else {
                sb.append(C0092c.f1284O);
            }
            i = i2 + 1;
        }
    }

    /* JADX INFO: renamed from: a */
    private static boolean m3091a(List<String> list, String str) {
        Iterator<String> it = list.iterator();
        while (it.hasNext()) {
            if (str.startsWith(it.next())) {
                return true;
            }
        }
        return false;
    }

    /* JADX WARN: Code duplicated, block: B:47:0x0088 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r2v3, types: [boolean] */
    /* JADX WARN: Type inference failed for: r2v4 */
    /* JADX WARN: Type inference failed for: r2v6, types: [java.io.FileInputStream] */
    /* JADX INFO: renamed from: b */
    private NetInterfaceTypeInfoList m3092b() throws Throwable {
        ?? Exists;
        FileInputStream fileInputStream;
        NetInterfaceTypeInfoList netInterfaceTypeInfoList;
        String strM3577a = C1336v.m3577a(this.f7075k, UpdateConfig.TRAFFIC_MONITOR_CONFIG_NAME, (String) null);
        if (strM3577a == null || strM3577a.length() == 0 || (Exists = new File(strM3577a).exists()) == 0) {
            return null;
        }
        try {
            try {
                fileInputStream = new FileInputStream(new File(strM3577a));
                try {
                    C1334t c1334tM3572a = C1335u.m3572a(fileInputStream);
                    byte[] bArr = new byte[fileInputStream.available()];
                    fileInputStream.read(bArr);
                    if (C1332r.m3548a(C1148ae.m2876a(bArr)).equals(C1332r.m3548a(c1334tM3572a.m3570c()))) {
                        byte[] bArrDecrypt = TccCryptor.decrypt(TMSApplication.getApplicaionContext(), bArr, null);
                        UniAttribute uniAttribute = new UniAttribute();
                        uniAttribute.decode(bArrDecrypt);
                        netInterfaceTypeInfoList = (NetInterfaceTypeInfoList) uniAttribute.get(NetInterfaceUsageType.NET_INTERFACE_TYPE_TRAFFIC_STAT.toString(), new NetInterfaceTypeInfoList());
                    } else {
                        netInterfaceTypeInfoList = null;
                    }
                    if (fileInputStream == null) {
                        return netInterfaceTypeInfoList;
                    }
                    try {
                        fileInputStream.close();
                        return netInterfaceTypeInfoList;
                    } catch (IOException e) {
                        e.printStackTrace();
                        return netInterfaceTypeInfoList;
                    }
                } catch (Exception e2) {
                    e = e2;
                    e.printStackTrace();
                    if (fileInputStream != null) {
                        try {
                            fileInputStream.close();
                        } catch (IOException e3) {
                            e3.printStackTrace();
                        }
                    }
                    return null;
                }
            } catch (Throwable th) {
                th = th;
                if (Exists != 0) {
                    try {
                        Exists.close();
                    } catch (IOException e4) {
                        e4.printStackTrace();
                    }
                }
                throw th;
            }
        } catch (Exception e5) {
            e = e5;
            fileInputStream = null;
        } catch (Throwable th2) {
            th = th2;
            Exists = 0;
            if (Exists != 0) {
                Exists.close();
            }
            throw th;
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3093a() throws Throwable {
        NetInterfaceTypeInfoList netInterfaceTypeInfoListM3092b = m3092b();
        if (netInterfaceTypeInfoListM3092b != null) {
            for (NetInterfaceTypeInfo netInterfaceTypeInfo : netInterfaceTypeInfoListM3092b.vctInterfaceInfos) {
                if ("MOBILE".equalsIgnoreCase(netInterfaceTypeInfo.typeName)) {
                    this.f7070f.clear();
                    this.f7070f.addAll(netInterfaceTypeInfo.keySet);
                } else if ("WIFI".equalsIgnoreCase(netInterfaceTypeInfo.typeName)) {
                    this.f7071g.clear();
                    this.f7071g.addAll(netInterfaceTypeInfo.keySet);
                } else if ("EXCLUDE".equalsIgnoreCase(netInterfaceTypeInfo.typeName)) {
                    this.f7072h.clear();
                    this.f7072h.addAll(netInterfaceTypeInfo.keySet);
                }
            }
        }
        String[] strArrM3593b = C1336v.m3593b(new File(this.f7074j));
        int length = strArrM3593b != null ? strArrM3593b.length : 0;
        ArrayList<String> arrayList = new ArrayList<>();
        this.f7076l = 17;
        for (int i = 2; i < length; i++) {
            String lowerCase = strArrM3593b[i].trim().trim().split("[: ]+")[0].trim().toLowerCase();
            if (!m3091a(this.f7072h, lowerCase)) {
                if (m3091a(this.f7070f, lowerCase)) {
                    this.f7076l &= -2;
                } else if (m3091a(this.f7071g, lowerCase)) {
                    this.f7076l &= -17;
                } else {
                    arrayList.add(lowerCase);
                }
            }
        }
        String strM3090a = m3090a(arrayList);
        if (TextUtils.isEmpty(strM3090a)) {
            return;
        }
        this.f7073i.m2888a(f7065e, strM3090a, true);
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3094a(String str) {
        return m3091a(this.f7070f, str);
    }

    /* JADX INFO: renamed from: b */
    public final boolean m3095b(String str) {
        return m3091a(this.f7071g, str);
    }
}
