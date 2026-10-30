package tms;

import QQPIM.LicenceCheckResult;
import QQPIM.LicenceInfo;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.wupsession.WupSessionManager;
import com.tencent.tmsecure.utils.StringUtil;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.security.cert.CertificateException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.Properties;

/* JADX INFO: renamed from: tms.dg */
/* JADX INFO: loaded from: classes.dex */
final class C1231dg {

    /* JADX INFO: renamed from: a */
    private static final HashMap<String, String> f7105a = new HashMap<>();

    /* JADX INFO: renamed from: b */
    private static final long f7106b = new GregorianCalendar(2016, 0, 1).getTimeInMillis() / 1000;

    /* JADX INFO: renamed from: c */
    private Properties f7107c;

    /* JADX INFO: renamed from: d */
    private Context f7108d;

    static {
        f7105a.put("AresEngineManager", "aresengine");
        f7105a.put("QScannerManager", "qscanner");
        f7105a.put("LocationManager", "phoneservice");
        f7105a.put("IpDialManager", "phoneservice");
        f7105a.put("UsefulNumberManager", "phoneservice");
        f7105a.put("NetworkManager", "network");
        f7105a.put("TrafficCorrectionManager", "network");
        f7105a.put("FirewallManager", "network");
        f7105a.put("NetSettingManager", "netsetting");
        f7105a.put("OptimizeManager", "optimize");
        f7105a.put("UpdateManager", "update");
        f7105a.put("UrlCheckManager", "urlcheck");
        f7105a.put("PermissionManager", QueryPermissions.PERMISSION);
        f7105a.put("SoftwareManager", "software");
        f7105a.put("AntitheftManager", "antitheft");
        f7105a.put("PowerSavingManager", "powersaving");
    }

    C1231dg(Properties properties, Context context) {
        this.f7107c = properties;
        this.f7108d = context;
    }

    /* JADX INFO: renamed from: a */
    private String m3111a(String str) {
        PackageInfo packageInfo;
        String strM2878c;
        CertificateException e;
        IOException e2;
        try {
            packageInfo = this.f7108d.getPackageManager().getPackageInfo(str, 64);
        } catch (PackageManager.NameNotFoundException e3) {
            e3.printStackTrace();
            packageInfo = null;
        }
        if (packageInfo == null) {
            return null;
        }
        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(packageInfo.signatures[0].toByteArray());
        try {
            strM2878c = C1148ae.m2878c(((X509Certificate) CertificateFactory.getInstance("X.509").generateCertificate(byteArrayInputStream)).getEncoded());
            try {
                byteArrayInputStream.close();
                return strM2878c;
            } catch (IOException e4) {
                e2 = e4;
                e2.printStackTrace();
                return strM2878c;
            } catch (CertificateException e5) {
                e = e5;
                e.printStackTrace();
                return strM2878c;
            }
        } catch (IOException e6) {
            strM2878c = null;
            e2 = e6;
        } catch (CertificateException e7) {
            strM2878c = null;
            e = e7;
        }
    }

    /* JADX INFO: renamed from: a */
    final int m3112a(LicenceCheckResult licenceCheckResult) {
        return ((WupSessionManager) ManagerCreator.getManager(WupSessionManager.class)).checkLicence(new LicenceInfo(m3111a(this.f7108d.getPackageName()), StringUtil.assertNotNullString(TMSApplication.getStrFromEnvMap(TMSApplication.CON_CHANNEL))), licenceCheckResult);
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3113a() {
        int i = Integer.parseInt(m3115b());
        if (i == 873461 || i == 873789) {
            if (System.currentTimeMillis() < new GregorianCalendar(2013, 0, 30).getTimeInMillis()) {
                return true;
            }
        }
        return m3111a(this.f7108d.getPackageName()).equals(this.f7107c.getProperty("signature").toUpperCase().trim());
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3114a(Class<? extends BaseManager> cls) {
        String str = f7105a.get(cls.getSimpleName());
        if (str == null) {
            return true;
        }
        String property = this.f7107c.getProperty(str);
        if (property != null) {
            return property.equals(DatabaseTables.SYSTEM_MARK);
        }
        return false;
    }

    /* JADX INFO: renamed from: b */
    public final String m3115b() {
        return this.f7107c.getProperty("lc_sdk_channel");
    }

    /* JADX INFO: renamed from: c */
    public final String m3116c() {
        return this.f7107c.getProperty("lc_sdk_pid");
    }

    /* JADX INFO: renamed from: d */
    public final long m3117d() {
        return Long.parseLong(this.f7107c.getProperty("expiry.seconds", Long.toString(f7106b)));
    }
}
