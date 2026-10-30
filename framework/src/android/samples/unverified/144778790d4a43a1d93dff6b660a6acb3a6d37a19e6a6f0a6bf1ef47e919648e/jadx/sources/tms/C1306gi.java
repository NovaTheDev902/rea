package tms;

import QQPIM.AnalyseInfo;
import QQPIM.FeatureKey;
import QQPIM.SoftActionConfig;
import QQPIM.SoftFeature;
import QQPIM.UploadFileInfo;
import QQPIM.VirusClientInfo;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.qscanner.AmScanner;
import com.tencent.tmsecure.module.qscanner.ApkKey;
import com.tencent.tmsecure.module.qscanner.CertChecker;
import com.tencent.tmsecure.module.qscanner.QScanListener;
import com.tencent.tmsecure.module.qscanner.QScanResult;
import com.tencent.tmsecure.module.qscanner.QScanResultEntity;
import com.tencent.tmsecure.module.software.AppEntity;
import com.tencent.tmsecure.module.software.SoftwareManager;
import com.tencent.tmsecure.module.update.UpdateConfig;
import com.tencent.tmsecure.module.wupsession.WupSessionManager;
import com.tencent.tmsecure.utils.Log;
import com.tencent.tmsecure.utils.StringUtil;
import com.tencent.tmsecure.utils.UpdateUtil;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: renamed from: tms.gi */
/* JADX INFO: loaded from: classes.dex */
public final class C1306gi extends BaseManager {

    /* JADX INFO: renamed from: m */
    private static final String[] f7383m = {"image", AppEntity.KEY_ICON_DRAWABLE, "photo", "music", "dcim", "weibo"};

    /* JADX INFO: renamed from: a */
    private Context f7384a;

    /* JADX INFO: renamed from: b */
    private SoftwareManager f7385b;

    /* JADX INFO: renamed from: c */
    private AmScanner f7386c;

    /* JADX INFO: renamed from: d */
    private C1275ex f7387d;

    /* JADX INFO: renamed from: e */
    private CertChecker f7388e;

    /* JADX INFO: renamed from: g */
    private boolean f7390g;

    /* JADX INFO: renamed from: f */
    private byte[] f7389f = new byte[0];

    /* JADX INFO: renamed from: h */
    private boolean f7391h = false;

    /* JADX INFO: renamed from: i */
    private Object f7392i = new Object();

    /* JADX INFO: renamed from: j */
    private boolean f7393j = false;

    /* JADX INFO: renamed from: k */
    private boolean f7394k = false;

    /* JADX INFO: renamed from: l */
    private Object f7395l = new Object();

    /* JADX INFO: renamed from: a */
    public static String m3360a(Context context) {
        VirusClientInfo virusClientInfo = UpdateUtil.getVirusClientInfo(context, C1336v.m3577a(context, UpdateConfig.VIRUS_BASE_NAME, (String) null));
        Date date = new Date(virusClientInfo != null ? ((long) virusClientInfo.getTimestamp()) * 1000 : 0L);
        return new SimpleDateFormat("yyyyMMdd").format(date) + (date.getHours() > 12 ? "B" : "A");
    }

    /* JADX WARN: Code duplicated, block: B:12:0x0016 A[Catch: all -> 0x002c, TryCatch #1 {, blocks: (B:4:0x0003, B:5:0x0006, B:6:0x000b, B:10:0x0010, B:12:0x0016, B:13:0x001a, B:14:0x0022, B:27:0x0030, B:28:0x0031, B:21:0x002a, B:22:0x002b, B:8:0x000d, B:9:0x000f, B:16:0x0024, B:17:0x0026), top: B:31:0x0003, inners: #0, #2 }] */
    /* JADX WARN: Code duplicated, block: B:15:0x0023  */
    /* JADX WARN: Code duplicated, block: B:7:0x000c  */
    /* JADX INFO: renamed from: a */
    private synchronized ArrayList<QScanResultEntity> m3361a(ArrayList<AppEntity> arrayList, QScanListener qScanListener, boolean z) {
        ArrayList<QScanResultEntity> arrayListM3369b;
        if (qScanListener != null) {
            qScanListener.onScanStarted();
            m3378a();
            synchronized (this.f7389f) {
                this.f7390g = true;
            }
            arrayListM3369b = m3369b(arrayList, qScanListener);
            if (z) {
                arrayListM3369b = m3371c(arrayListM3369b, qScanListener);
            }
            m3364a(qScanListener, arrayListM3369b);
            m3382b();
            synchronized (this.f7389f) {
                this.f7390g = false;
            }
        } else {
            m3378a();
            synchronized (this.f7389f) {
                this.f7390g = true;
                arrayListM3369b = m3369b(arrayList, qScanListener);
                if (z) {
                    arrayListM3369b = m3371c(arrayListM3369b, qScanListener);
                }
                m3364a(qScanListener, arrayListM3369b);
                m3382b();
                synchronized (this.f7389f) {
                    this.f7390g = false;
                }
            }
        }
        throw th;
        return arrayListM3369b;
    }

    /* JADX INFO: renamed from: a */
    private ArrayList<AppEntity> m3362a(boolean z) throws Throwable {
        ArrayList<String> arrayList = new ArrayList();
        List listAsList = z ? null : Arrays.asList(f7383m);
        List<String> listM3384c = m3384c();
        if (listM3384c != null && listM3384c.size() > 0) {
            Iterator<String> it = listM3384c.iterator();
            while (it.hasNext()) {
                File file = new File(it.next());
                if (file.exists() && file.canRead()) {
                    arrayList.addAll(C1336v.m3582a(file, (List<String>) listAsList, z));
                }
            }
        }
        ArrayList<AppEntity> arrayList2 = new ArrayList<>();
        for (String str : arrayList) {
            AppEntity appEntity = new AppEntity();
            appEntity.setApkFlag(true);
            appEntity.setApkPath(str);
            arrayList2.add(appEntity);
        }
        return arrayList2;
    }

    /* JADX INFO: renamed from: a */
    private void m3363a(QScanListener qScanListener) {
        synchronized (this.f7392i) {
            try {
                if (this.f7391h) {
                    if (qScanListener != null) {
                        qScanListener.onScanPaused();
                    }
                    this.f7392i.wait();
                    if (qScanListener != null) {
                        qScanListener.onScanContinue();
                    }
                    this.f7391h = false;
                }
            } catch (InterruptedException e) {
                Log.m2634e("QScannerManangerImpl", e.getMessage());
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private void m3364a(QScanListener qScanListener, ArrayList<QScanResultEntity> arrayList) {
        synchronized (this.f7392i) {
            this.f7391h = false;
        }
        synchronized (this.f7395l) {
            this.f7393j = false;
            this.f7394k = false;
        }
        if (qScanListener != null) {
            qScanListener.onScanFinished(arrayList);
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m3365a(ArrayList<QScanResultEntity> arrayList, ArrayList<AnalyseInfo> arrayList2) {
        for (QScanResultEntity qScanResultEntity : arrayList) {
            for (AnalyseInfo analyseInfo : arrayList2) {
                if (qScanResultEntity.packageName.equals(analyseInfo.featureKey.uniCode) && qScanResultEntity.size == analyseInfo.featureKey.fileSize && analyseInfo.cloudCheck.safeType != 0) {
                    qScanResultEntity.type = analyseInfo.cloudCheck.safeType;
                    qScanResultEntity.advice = analyseInfo.cloudCheck.handleAdvice;
                    qScanResultEntity.name = analyseInfo.cloudCheck.virusName;
                    qScanResultEntity.discription = analyseInfo.cloudCheck.short_desc;
                    qScanResultEntity.malwareid = analyseInfo.cloudCheck.virusID;
                    qScanResultEntity.url = analyseInfo.cloudCheck.handleUrl;
                }
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private void m3366a(ArrayList<QScanResultEntity> arrayList, List<AnalyseInfo> list) {
        for (AnalyseInfo analyseInfo : list) {
            UploadFileInfo uploadFileInfo = analyseInfo.getUploadFileInfo();
            if (uploadFileInfo != null && uploadFileInfo.getVecUploadFile() != null && uploadFileInfo.getVecUploadFile().size() > 0) {
                for (QScanResultEntity qScanResultEntity : arrayList) {
                    if (qScanResultEntity.packageName.equals(analyseInfo.featureKey.uniCode) && qScanResultEntity.size == analyseInfo.featureKey.fileSize) {
                        C1144aa c1144aa = new C1144aa(this.f7384a);
                        c1144aa.m2872a(C1144aa.f6813a);
                        c1144aa.m2870a(qScanResultEntity.path, uploadFileInfo);
                    }
                }
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private void m3367a(List<AnalyseInfo> list) throws Throwable {
        ArrayList arrayList = new ArrayList();
        for (AnalyseInfo analyseInfo : list) {
            if (analyseInfo.getActionLevel() != 0) {
                arrayList.add(new SoftActionConfig(analyseInfo.featureKey, analyseInfo.actionLevel));
            }
        }
        if (arrayList.size() > 0) {
            C1336v.m3575a(this.f7384a, arrayList, "label_sa_cfg", "sa_cfg.dat");
        }
    }

    /* JADX INFO: renamed from: a */
    private static boolean m3368a(List<String> list, String str) {
        boolean z = false;
        if (list == null || str == null) {
            return false;
        }
        Iterator<String> it = list.iterator();
        while (true) {
            boolean zEquals = z;
            if (!it.hasNext()) {
                return zEquals;
            }
            String next = it.next();
            if (str.equals(next)) {
                zEquals = true;
            } else {
                try {
                    String canonicalPath = new File(next).getCanonicalPath();
                    String canonicalPath2 = new File(str).getCanonicalPath();
                    if (canonicalPath != null && canonicalPath2 != null) {
                        zEquals = canonicalPath.equals(canonicalPath2);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            z = zEquals;
        }
    }

    /* JADX WARN: Code duplicated, block: B:40:0x00b4  */
    /* JADX WARN: Code duplicated, block: B:42:0x00bb  */
    /* JADX WARN: Code duplicated, block: B:46:0x00c4  */
    /* JADX WARN: Code duplicated, block: B:49:0x00de  */
    /* JADX WARN: Code duplicated, block: B:72:0x004f A[SYNTHETIC] */
    /* JADX INFO: renamed from: b */
    private ArrayList<QScanResultEntity> m3369b(ArrayList<AppEntity> arrayList, QScanListener qScanListener) {
        long jCurrentTimeMillis;
        QScanResultEntity qScanResultEntity;
        ArrayList<QScanResultEntity> arrayList2 = new ArrayList<>();
        if (arrayList == null || arrayList.size() == 0) {
            return arrayList2;
        }
        int i = 0;
        while (true) {
            int i2 = i;
            if (i2 >= arrayList.size()) {
                return arrayList2;
            }
            m3363a(qScanListener);
            if (m3370b(qScanListener)) {
                return arrayList2;
            }
            long jCurrentTimeMillis2 = System.currentTimeMillis();
            AppEntity appEntity = arrayList.get(i2);
            AppEntity apkInfo = appEntity.isApk() ? this.f7385b.getApkInfo(appEntity, 9) : this.f7385b.getAppInfo(appEntity, 73);
            if (apkInfo != null) {
                int i3 = 0;
                if (apkInfo.isApk()) {
                    i3 = 2;
                } else if (apkInfo.isSystemApp()) {
                    i3 = 1;
                }
                QScanResultEntity qScanResultEntityM3275a = this.f7387d.m3275a(apkInfo.getPackageName(), apkInfo.getApkPath(), apkInfo.getSize(), i3);
                if (qScanResultEntityM3275a != null) {
                    if (qScanResultEntityM3275a != null) {
                        arrayList2.add(qScanResultEntityM3275a);
                        if (qScanListener != null) {
                            if (qScanResultEntityM3275a.apkType != 0 || qScanResultEntityM3275a.apkType == 1) {
                                qScanListener.onPackageScanProgress(((i2 + 1) * 100) / arrayList.size(), qScanResultEntityM3275a);
                            } else if (qScanResultEntityM3275a.apkType == 2) {
                                qScanListener.onSdcardScanProgress(((i2 + 1) * 100) / arrayList.size(), qScanResultEntityM3275a);
                            }
                        }
                    }
                    jCurrentTimeMillis = System.currentTimeMillis() - jCurrentTimeMillis2;
                    if (jCurrentTimeMillis < 20) {
                        try {
                            Thread.sleep(20 - jCurrentTimeMillis);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                } else {
                    AppEntity appInfo = apkInfo.isApk() ? apkInfo : this.f7385b.getAppInfo(apkInfo, 16);
                    if (appInfo != null) {
                        ApkKey apkKey = appInfo == null ? null : new ApkKey(StringUtil.assertNotNullString(appInfo.getPackageName()), StringUtil.assertNotNullString(appInfo.getAppName()), StringUtil.assertNotNullString(appInfo.getCertMD5()), StringUtil.assertNotNullString(appInfo.getVersion()), appInfo.getVersionCode(), (int) appInfo.getSize(), StringUtil.assertNotNullString(appInfo.getApkPath()), i3);
                        QScanResult qScanResultScanApk = this.f7386c.scanApk(apkKey);
                        QScanResult qScanResultCheckCert = qScanResultScanApk != null ? this.f7388e.checkCert(qScanResultScanApk) : null;
                        if (qScanResultCheckCert == null) {
                            qScanResultEntity = null;
                        } else {
                            qScanResultEntity = new QScanResultEntity();
                            qScanResultEntity.packageName = qScanResultCheckCert.apkkey.getPkgName();
                            qScanResultEntity.softName = qScanResultCheckCert.apkkey.getSoftName();
                            qScanResultEntity.version = qScanResultCheckCert.apkkey.getVersion();
                            qScanResultEntity.versionCode = qScanResultCheckCert.apkkey.getVersionCode();
                            qScanResultEntity.path = qScanResultCheckCert.apkkey.path;
                            qScanResultEntity.apkType = qScanResultCheckCert.apkkey.apkType;
                            qScanResultEntity.certMd5 = qScanResultCheckCert.apkkey.certMd5;
                            qScanResultEntity.size = qScanResultCheckCert.apkkey.size;
                            qScanResultEntity.type = qScanResultCheckCert.type;
                            qScanResultEntity.advice = qScanResultCheckCert.advice;
                            qScanResultEntity.malwareid = qScanResultCheckCert.malwareid;
                            qScanResultEntity.name = qScanResultCheckCert.name;
                            qScanResultEntity.label = qScanResultCheckCert.label;
                            qScanResultEntity.discription = qScanResultCheckCert.discription;
                            qScanResultEntity.url = qScanResultCheckCert.url;
                        }
                        apkKey.certMd5 = qScanResultCheckCert != null ? qScanResultCheckCert.getApkkey().getCertMd5() : null;
                        this.f7387d.m3276a(apkKey, qScanResultEntity);
                        qScanResultEntityM3275a = qScanResultEntity;
                        if (qScanResultEntityM3275a != null) {
                            arrayList2.add(qScanResultEntityM3275a);
                            if (qScanListener != null) {
                                if (qScanResultEntityM3275a.apkType != 0) {
                                    qScanListener.onPackageScanProgress(((i2 + 1) * 100) / arrayList.size(), qScanResultEntityM3275a);
                                } else {
                                    qScanListener.onPackageScanProgress(((i2 + 1) * 100) / arrayList.size(), qScanResultEntityM3275a);
                                }
                            }
                        }
                        jCurrentTimeMillis = System.currentTimeMillis() - jCurrentTimeMillis2;
                        if (jCurrentTimeMillis < 20) {
                            Thread.sleep(20 - jCurrentTimeMillis);
                        }
                    }
                }
            }
            i = i2 + 1;
        }
    }

    /* JADX INFO: renamed from: b */
    private boolean m3370b(QScanListener qScanListener) {
        boolean z = true;
        synchronized (this.f7395l) {
            if (!this.f7393j) {
                z = false;
            } else if (qScanListener != null && !this.f7394k) {
                qScanListener.onScanCanceled();
                this.f7394k = true;
            }
        }
        return z;
    }

    /* JADX INFO: renamed from: c */
    private ArrayList<QScanResultEntity> m3371c(ArrayList<QScanResultEntity> arrayList, QScanListener qScanListener) throws Throwable {
        SoftFeature softFeature;
        m3363a(qScanListener);
        if (!m3370b(qScanListener)) {
            if (!C1278f.m3286a().m3294b()) {
                throw new RuntimeException("TMS licence expired! Please contact TMS(Tencent Mobile Secure) group.");
            }
            if (qScanListener != null) {
                qScanListener.onCloudScan();
            }
            m3363a(qScanListener);
            if (!m3370b(qScanListener)) {
                ArrayList arrayList2 = new ArrayList();
                for (QScanResultEntity qScanResultEntity : arrayList) {
                    if (qScanResultEntity == null) {
                        softFeature = null;
                    } else {
                        SoftFeature softFeature2 = new SoftFeature();
                        softFeature2.setFeatureKey(new FeatureKey(qScanResultEntity.packageName, qScanResultEntity.softName, qScanResultEntity.version, qScanResultEntity.versionCode, qScanResultEntity.certMd5, qScanResultEntity.size));
                        softFeature2.setRequestType(1);
                        softFeature2.setIsBuildIn(qScanResultEntity.apkType == 1);
                        softFeature2.setEngineVersion(2);
                        softFeature2.setLocalSafeType(qScanResultEntity.type);
                        softFeature2.setLocalVirusID(qScanResultEntity.malwareid);
                        softFeature2.setLocalVirusName(qScanResultEntity.name);
                        softFeature = softFeature2;
                    }
                    arrayList2.add(softFeature);
                }
                ArrayList<AnalyseInfo> arrayList3 = new ArrayList<>();
                int analyseInfo = ((WupSessionManager) ManagerCreator.getManager(WupSessionManager.class)).getAnalyseInfo(arrayList2, arrayList3);
                m3363a(qScanListener);
                if (!m3370b(qScanListener)) {
                    if (analyseInfo == 0) {
                        m3365a(arrayList, arrayList3);
                        m3366a(arrayList, (List<AnalyseInfo>) arrayList3);
                        C1330p.m3532a(this.f7384a.getApplicationContext()).m3535a();
                        m3367a(arrayList3);
                    } else if (qScanListener != null) {
                        qScanListener.onCloudScanError(analyseInfo);
                    }
                }
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: g */
    private ArrayList<AppEntity> m3372g() {
        ArrayList<AppEntity> arrayList = new ArrayList<>();
        for (ApplicationInfo applicationInfo : this.f7384a.getPackageManager().getInstalledApplications(0)) {
            AppEntity appEntity = new AppEntity();
            appEntity.setPackageName(applicationInfo.packageName);
            arrayList.add(appEntity);
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public final int m3373a(String str) {
        if (this.f7388e != null) {
            return this.f7388e.getApkClass(str);
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<QScanResultEntity> m3374a(QScanListener qScanListener, boolean z) {
        return m3361a(m3372g(), qScanListener, z);
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<QScanResultEntity> m3375a(QScanListener qScanListener, boolean z, boolean z2) {
        return m3361a(m3362a(z2), qScanListener, z);
    }

    /* JADX WARN: Code duplicated, block: B:12:0x001d  */
    /* JADX WARN: Code duplicated, block: B:7:0x000c  */
    /* JADX INFO: renamed from: a */
    public final synchronized ArrayList<QScanResultEntity> m3376a(ArrayList<QScanResultEntity> arrayList, QScanListener qScanListener) {
        ArrayList<QScanResultEntity> arrayListM3371c;
        if (qScanListener != null) {
            qScanListener.onScanStarted();
            m3378a();
            synchronized (this.f7389f) {
                this.f7390g = true;
            }
            arrayListM3371c = m3371c(arrayList, qScanListener);
            m3364a(qScanListener, arrayListM3371c);
            m3382b();
            synchronized (this.f7389f) {
                this.f7390g = false;
            }
        } else {
            m3378a();
            synchronized (this.f7389f) {
                this.f7390g = true;
                arrayListM3371c = m3371c(arrayList, qScanListener);
                m3364a(qScanListener, arrayListM3371c);
                m3382b();
                synchronized (this.f7389f) {
                    this.f7390g = false;
                }
            }
        }
        throw th;
        return arrayListM3371c;
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<QScanResultEntity> m3377a(List<String> list, QScanListener qScanListener, boolean z) {
        if (list == null || list.size() == 0) {
            return new ArrayList<>();
        }
        ArrayList<AppEntity> arrayList = new ArrayList<>(list.size());
        for (String str : list) {
            AppEntity appEntity = new AppEntity();
            appEntity.setPackageName(str);
            arrayList.add(appEntity);
        }
        return m3361a(arrayList, qScanListener, z);
    }

    /* JADX INFO: renamed from: a */
    public final void m3378a() {
        if (this.f7387d == null) {
            this.f7387d = C1275ex.m3272a();
        }
        if (this.f7386c == null) {
            this.f7386c = new AmScanner(this.f7384a, C1336v.m3577a(this.f7384a, UpdateConfig.VIRUS_BASE_NAME, (String) null));
        }
        if (this.f7388e == null) {
            this.f7388e = new CertChecker(this.f7384a);
        }
    }

    /* JADX INFO: renamed from: b */
    public final ArrayList<QScanResultEntity> m3379b(QScanListener qScanListener, boolean z) {
        return m3375a(qScanListener, z, false);
    }

    /* JADX INFO: renamed from: b */
    public final ArrayList<QScanResultEntity> m3380b(QScanListener qScanListener, boolean z, boolean z2) {
        ArrayList<AppEntity> arrayListM3372g = m3372g();
        arrayListM3372g.addAll(m3362a(z2));
        return m3361a(arrayListM3372g, qScanListener, z);
    }

    /* JADX INFO: renamed from: b */
    public final ArrayList<QScanResultEntity> m3381b(List<String> list, QScanListener qScanListener, boolean z) {
        if (list == null || list.size() == 0) {
            return new ArrayList<>();
        }
        ArrayList<AppEntity> arrayList = new ArrayList<>(list.size());
        for (String str : list) {
            AppEntity appEntity = new AppEntity();
            appEntity.setApkFlag(true);
            appEntity.setApkPath(str);
            arrayList.add(appEntity);
        }
        return m3361a(arrayList, qScanListener, z);
    }

    /* JADX INFO: renamed from: b */
    public final void m3382b() {
        synchronized (this.f7389f) {
            if (this.f7390g) {
                return;
            }
            C1275ex.m3273b();
            this.f7387d = null;
            if (this.f7386c != null) {
                this.f7386c.finalize();
                this.f7386c = null;
            }
        }
    }

    /* JADX INFO: renamed from: c */
    public final ArrayList<QScanResultEntity> m3383c(QScanListener qScanListener, boolean z) {
        return m3380b(qScanListener, z, false);
    }

    /* JADX WARN: Code duplicated, block: B:79:0x00cf A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: c */
    public final List<String> m3384c() throws Throwable {
        BufferedReader bufferedReader;
        boolean z;
        ArrayList arrayList = new ArrayList();
        BufferedReader bufferedReader2 = null;
        try {
            try {
                bufferedReader = new BufferedReader(new FileReader("/proc/mounts"));
                while (true) {
                    try {
                        String line = bufferedReader.readLine();
                        if (line == null) {
                            break;
                        }
                        if (line == null) {
                            z = false;
                        } else {
                            z = ((!line.contains("vfat") && !line.contains("exfat") && !line.contains("/mnt") && !line.contains("fuse")) || !line.contains("/dev/block/vold") || line.contains("/mnt/secure") || line.contains("/mnt/asec") || line.contains("/mnt/obb") || line.contains("/dev/mapper") || line.contains("tmpfs")) ? false : true;
                        }
                        if (z) {
                            String[] strArrSplit = line.split("\\s+");
                            if (strArrSplit.length >= 2 && !m3368a(arrayList, strArrSplit[1])) {
                                if (strArrSplit[1].endsWith(CookieSpec.PATH_DELIM)) {
                                    arrayList.add(strArrSplit[1].substring(0, strArrSplit[1].length() - 1));
                                } else {
                                    arrayList.add(strArrSplit[1]);
                                }
                            }
                        }
                    } catch (FileNotFoundException e) {
                        e = e;
                        e.printStackTrace();
                        if (bufferedReader != null) {
                            try {
                                bufferedReader.close();
                            } catch (IOException e2) {
                                e = e2;
                                e.printStackTrace();
                            }
                        }
                    } catch (IOException e3) {
                        e = e3;
                        e.printStackTrace();
                        if (bufferedReader != null) {
                            try {
                                bufferedReader.close();
                            } catch (IOException e4) {
                                e = e4;
                                e.printStackTrace();
                            }
                        }
                    }
                }
                if (bufferedReader != null) {
                    try {
                        bufferedReader.close();
                    } catch (IOException e5) {
                        e = e5;
                        e.printStackTrace();
                    }
                }
            } catch (Throwable th) {
                th = th;
                if (0 != 0) {
                    try {
                        bufferedReader2.close();
                    } catch (IOException e6) {
                        e6.printStackTrace();
                    }
                }
                throw th;
            }
        } catch (FileNotFoundException e7) {
            e = e7;
            bufferedReader = null;
        } catch (IOException e8) {
            e = e8;
            bufferedReader = null;
        } catch (Throwable th2) {
            th = th2;
            if (0 != 0) {
                bufferedReader2.close();
            }
            throw th;
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: d */
    public final void m3385d() {
        synchronized (this.f7392i) {
            this.f7391h = true;
        }
    }

    /* JADX INFO: renamed from: e */
    public final void m3386e() {
        synchronized (this.f7392i) {
            this.f7392i.notifyAll();
        }
    }

    /* JADX INFO: renamed from: f */
    public final void m3387f() {
        synchronized (this.f7395l) {
            this.f7393j = true;
        }
        synchronized (this.f7392i) {
            this.f7392i.notifyAll();
        }
    }

    protected final void finalize() {
        m3382b();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 2;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7384a = context;
        this.f7385b = (SoftwareManager) ManagerCreator.getManager(SoftwareManager.class);
        C1336v.m3577a(context, UpdateConfig.VIRUS_BASE_NAME, (String) null);
    }
}
