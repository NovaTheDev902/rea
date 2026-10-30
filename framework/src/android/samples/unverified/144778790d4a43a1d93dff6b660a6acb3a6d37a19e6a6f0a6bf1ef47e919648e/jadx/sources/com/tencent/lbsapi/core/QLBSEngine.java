package com.tencent.lbsapi.core;

import LBSAPIProtocol.Cell;
import LBSAPIProtocol.GPS;
import LBSAPIProtocol.Measure;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.IntentFilter;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.net.wifi.ScanResult;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings;
import android.telephony.CellLocation;
import android.telephony.NeighboringCellInfo;
import android.telephony.TelephonyManager;
import android.telephony.gsm.GsmCellLocation;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.tencent.lbsapi.QLBSNotification;
import com.tencent.lbsapi.model.QLBSCellInfo;
import com.tencent.lbsapi.model.QLBSWifiInfo;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class QLBSEngine {

    /* JADX INFO: renamed from: c */
    private Context f5919c;

    /* JADX INFO: renamed from: d */
    private QLBSNotification f5920d;

    /* JADX INFO: renamed from: r */
    private int f5934r;

    /* JADX INFO: renamed from: s */
    private int f5935s;

    /* JADX INFO: renamed from: t */
    private int f5936t;

    /* JADX INFO: renamed from: u */
    private int f5937u;

    /* JADX INFO: renamed from: v */
    private int f5938v;

    /* JADX INFO: renamed from: w */
    private int f5939w;

    /* JADX INFO: renamed from: e */
    private Handler f5921e = null;

    /* JADX INFO: renamed from: f */
    private TelephonyManager f5922f = null;

    /* JADX INFO: renamed from: g */
    private LocationManager f5923g = null;

    /* JADX INFO: renamed from: h */
    private int f5924h = 0;

    /* JADX INFO: renamed from: i */
    private LocationListener f5925i = null;

    /* JADX INFO: renamed from: j */
    private WifiManager f5926j = null;

    /* JADX INFO: renamed from: k */
    private BroadcastReceiver f5927k = null;

    /* JADX INFO: renamed from: l */
    private boolean f5928l = false;

    /* JADX INFO: renamed from: m */
    private boolean f5929m = false;

    /* JADX INFO: renamed from: n */
    private boolean f5930n = false;

    /* JADX INFO: renamed from: o */
    private boolean f5931o = true;

    /* JADX INFO: renamed from: p */
    private boolean f5932p = true;

    /* JADX INFO: renamed from: q */
    private boolean f5933q = false;

    /* JADX INFO: renamed from: x */
    private ArrayList f5940x = null;

    /* JADX INFO: renamed from: y */
    private ArrayList f5941y = null;

    /* JADX INFO: renamed from: z */
    private ArrayList f5942z = null;

    /* JADX INFO: renamed from: A */
    private String f5915A = null;

    /* JADX INFO: renamed from: B */
    private String f5916B = null;

    /* JADX INFO: renamed from: a */
    protected Runnable f5917a = new RunnableC1069g(this);

    /* JADX INFO: renamed from: b */
    protected Runnable f5918b = new RunnableC1071i(this);

    public QLBSEngine(Context context, QLBSNotification qLBSNotification) {
        this.f5919c = context;
        this.f5920d = qLBSNotification;
        m2516u();
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2500a(QLBSEngine qLBSEngine) {
        try {
            if (qLBSEngine.f5928l) {
                List<ScanResult> scanResults = qLBSEngine.f5926j.getScanResults();
                if (qLBSEngine.f5941y == null) {
                    qLBSEngine.f5941y = new ArrayList();
                } else {
                    qLBSEngine.f5941y.clear();
                }
                if (qLBSEngine.f5942z == null) {
                    qLBSEngine.f5942z = new ArrayList();
                } else {
                    qLBSEngine.f5942z.clear();
                }
                for (int i = 0; i < scanResults.size(); i++) {
                    ScanResult scanResult = scanResults.get(i);
                    String[] strArrSplit = scanResult.BSSID.split(C0092c.f1283N);
                    byte[] bArr = {0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i2 = 0; i2 < strArrSplit.length; i2++) {
                        bArr[5 - i2] = (byte) Integer.parseInt(strArrSplit[i2], 16);
                    }
                    qLBSEngine.f5941y.add(Long.valueOf((((long) (bArr[7] & 255)) << 56) | (bArr[0] & 255) | ((bArr[1] & 255) << 8) | ((bArr[2] & 255) << 16) | ((bArr[3] & 255) << 24) | ((bArr[4] & 255) << 32) | ((bArr[5] & 255) << 40) | (((long) (bArr[6] & 255)) << 48)));
                    qLBSEngine.f5942z.add(new QLBSWifiInfo(scanResult.SSID, scanResult.BSSID, scanResult.level));
                }
                if (qLBSEngine.f5931o) {
                    if (!qLBSEngine.f5929m) {
                        if (qLBSEngine.f5937u == 0 && qLBSEngine.f5938v == 900000000 && qLBSEngine.f5941y.size() == 0) {
                            if (qLBSEngine.f5920d != null) {
                                qLBSEngine.f5920d.onLocationNotification(0);
                                qLBSEngine.f5933q = false;
                            }
                            if (qLBSEngine.f5921e != null && qLBSEngine.f5917a != null) {
                                qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                            }
                        } else {
                            if (qLBSEngine.f5920d != null) {
                                qLBSEngine.f5920d.onLocationNotification(1);
                                qLBSEngine.f5933q = false;
                            }
                            if (qLBSEngine.f5921e != null && qLBSEngine.f5917a != null) {
                                qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                            }
                        }
                    }
                } else if (qLBSEngine.f5937u == 0 && qLBSEngine.f5941y.size() == 0) {
                    if (qLBSEngine.f5920d != null) {
                        qLBSEngine.f5920d.onLocationNotification(0);
                        qLBSEngine.f5933q = false;
                    }
                    if (qLBSEngine.f5921e != null) {
                        qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                    }
                } else {
                    if (qLBSEngine.f5920d != null) {
                        qLBSEngine.f5920d.onLocationNotification(1);
                        qLBSEngine.f5933q = false;
                    }
                    if (qLBSEngine.f5921e != null && qLBSEngine.f5917a != null) {
                        qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                    }
                }
                qLBSEngine.f5928l = false;
            }
        } catch (Exception e) {
            e.printStackTrace();
            qLBSEngine.f5928l = false;
            if (!qLBSEngine.f5931o) {
                if (qLBSEngine.f5937u == 0) {
                    if (qLBSEngine.f5920d != null) {
                        qLBSEngine.f5920d.onLocationNotification(0);
                        qLBSEngine.f5933q = false;
                    }
                    if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                        return;
                    }
                    qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                    return;
                }
                return;
            }
            if (qLBSEngine.f5929m) {
                return;
            }
            if (qLBSEngine.f5937u == 0 && qLBSEngine.f5938v == 900000000) {
                if (qLBSEngine.f5920d != null) {
                    qLBSEngine.f5920d.onLocationNotification(0);
                    qLBSEngine.f5933q = false;
                }
                if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                    return;
                }
                qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                return;
            }
            if (qLBSEngine.f5920d != null) {
                qLBSEngine.f5920d.onLocationNotification(1);
                qLBSEngine.f5933q = false;
            }
            if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                return;
            }
            qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
        }
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2501a(QLBSEngine qLBSEngine, Location location) throws Throwable {
        try {
            qLBSEngine.f5939w = (int) (location.getLongitude() * 1000000.0d);
            qLBSEngine.f5938v = (int) (location.getLatitude() * 1000000.0d);
            if (!qLBSEngine.f5933q) {
                if (qLBSEngine.f5937u != 0) {
                    qLBSEngine.m2538r();
                    return;
                }
                return;
            }
            if (qLBSEngine.f5929m) {
                qLBSEngine.f5923g.removeUpdates(qLBSEngine.f5925i);
                qLBSEngine.f5929m = false;
                if (!qLBSEngine.f5932p) {
                    if (qLBSEngine.f5937u != 0 || qLBSEngine.f5938v != 900000000) {
                        if (qLBSEngine.f5920d != null) {
                            qLBSEngine.f5920d.onLocationNotification(1);
                            qLBSEngine.f5933q = false;
                        }
                        if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                            return;
                        }
                        qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                        return;
                    }
                    if (qLBSEngine.f5920d != null) {
                        qLBSEngine.f5920d.onLocationNotification(0);
                        qLBSEngine.f5933q = false;
                    }
                    if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                        return;
                    }
                    qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                    qLBSEngine.f5933q = false;
                    return;
                }
                if (qLBSEngine.f5928l) {
                    return;
                }
                if (qLBSEngine.f5937u == 0 && qLBSEngine.f5938v == 900000000 && (qLBSEngine.f5941y.size() == 0 || qLBSEngine.f5941y == null)) {
                    if (qLBSEngine.f5920d != null) {
                        qLBSEngine.f5920d.onLocationNotification(0);
                        qLBSEngine.f5933q = false;
                    }
                    if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                        return;
                    }
                    qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                    return;
                }
                if (qLBSEngine.f5920d != null) {
                    qLBSEngine.f5920d.onLocationNotification(1);
                    qLBSEngine.f5933q = false;
                }
                if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                    return;
                }
                qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
            }
        } catch (Exception e) {
            e.printStackTrace();
            if (!qLBSEngine.f5932p) {
                if (qLBSEngine.f5937u == 0) {
                    if (qLBSEngine.f5920d != null) {
                        qLBSEngine.f5920d.onLocationNotification(0);
                        qLBSEngine.f5933q = false;
                    }
                    if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                        return;
                    }
                    qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                    return;
                }
                return;
            }
            if (qLBSEngine.f5928l) {
                return;
            }
            if (qLBSEngine.f5937u == 0 && (qLBSEngine.f5941y.size() == 0 || qLBSEngine.f5941y == null)) {
                if (qLBSEngine.f5920d != null) {
                    qLBSEngine.f5920d.onLocationNotification(0);
                    qLBSEngine.f5933q = false;
                }
                if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                    return;
                }
                qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
                return;
            }
            if (qLBSEngine.f5920d != null) {
                qLBSEngine.f5920d.onLocationNotification(1);
                qLBSEngine.f5933q = false;
            }
            if (qLBSEngine.f5921e == null || qLBSEngine.f5917a == null) {
                return;
            }
            qLBSEngine.f5921e.removeCallbacks(qLBSEngine.f5917a);
        }
    }

    /* JADX INFO: renamed from: i */
    static /* synthetic */ boolean m2510i(QLBSEngine qLBSEngine) {
        qLBSEngine.f5933q = false;
        return false;
    }

    /* JADX INFO: renamed from: j */
    static /* synthetic */ boolean m2511j(QLBSEngine qLBSEngine) {
        qLBSEngine.f5928l = false;
        return false;
    }

    /* JADX INFO: renamed from: m */
    static /* synthetic */ boolean m2514m(QLBSEngine qLBSEngine) {
        qLBSEngine.f5929m = false;
        return false;
    }

    /* JADX INFO: renamed from: t */
    public static long m2515t() {
        Calendar calendar = Calendar.getInstance();
        calendar.set(1970, 0, 1, 8, 0, 0);
        return (Calendar.getInstance().getTimeInMillis() - calendar.getTimeInMillis()) / 1000;
    }

    /* JADX INFO: renamed from: u */
    private void m2516u() {
        this.f5934r = 0;
        this.f5935s = 0;
        this.f5936t = 0;
        this.f5937u = 0;
        this.f5938v = 900000000;
        this.f5939w = 900000000;
        if (this.f5940x == null) {
            this.f5940x = new ArrayList();
        } else {
            this.f5940x.clear();
        }
        if (this.f5941y == null) {
            this.f5941y = new ArrayList();
        } else {
            this.f5941y.clear();
        }
        if (this.f5942z == null) {
            this.f5942z = new ArrayList();
        } else {
            this.f5942z.clear();
        }
        this.f5916B = null;
    }

    /* JADX INFO: renamed from: v */
    private void m2517v() {
        if (this.f5922f == null) {
            this.f5922f = (TelephonyManager) this.f5919c.getSystemService("phone");
        }
        if (this.f5922f != null) {
            try {
                this.f5915A = this.f5922f.getDeviceId();
                if (this.f5915A == null) {
                    this.f5915A = "";
                }
            } catch (Exception e) {
                this.f5915A = "";
            }
            if (this.f5922f.getPhoneType() != 1) {
                if (Integer.valueOf(Build.VERSION.SDK).intValue() < 4 || this.f5922f.getPhoneType() != 2) {
                    return;
                }
                try {
                    Class<?> cls = Class.forName("android.telephony.cdma.CdmaCellLocation");
                    if (cls != null) {
                        cls.getConstructor(null);
                        CellLocation cellLocation = this.f5922f.getCellLocation();
                        Method method = cls.getMethod("getSystemId", new Class[0]);
                        if (method != null) {
                            this.f5935s = ((Integer) method.invoke(cellLocation, null)).intValue();
                        }
                        Method method2 = cls.getMethod("getNetworkId", new Class[0]);
                        if (method2 != null) {
                            this.f5936t = ((Integer) method2.invoke(cellLocation, null)).intValue();
                        }
                        Method method3 = cls.getMethod("getBaseStationId", new Class[0]);
                        if (method3 != null) {
                            this.f5937u = ((Integer) method3.invoke(cellLocation, null)).intValue();
                        }
                        String networkOperator = this.f5922f.getNetworkOperator();
                        if (networkOperator != null) {
                            try {
                                this.f5934r = Integer.parseInt(networkOperator.substring(0, 3));
                                return;
                            } catch (Exception e2) {
                                this.f5916B = networkOperator;
                                return;
                            }
                        }
                        return;
                    }
                    return;
                } catch (Exception e3) {
                    e3.printStackTrace();
                    return;
                }
            }
            GsmCellLocation gsmCellLocation = (GsmCellLocation) this.f5922f.getCellLocation();
            if (gsmCellLocation != null) {
                this.f5936t = gsmCellLocation.getLac();
                this.f5937u = gsmCellLocation.getCid();
                if (this.f5936t <= 0 && this.f5937u <= 0) {
                    this.f5936t = 0;
                    this.f5937u = 0;
                    return;
                }
                String networkOperator2 = this.f5922f.getNetworkOperator();
                if (networkOperator2 != null) {
                    try {
                        this.f5934r = Integer.parseInt(networkOperator2.substring(0, 3));
                        this.f5935s = Integer.parseInt(networkOperator2.substring(3));
                    } catch (Exception e4) {
                        this.f5934r = 0;
                        this.f5935s = 0;
                        this.f5936t = 0;
                        this.f5937u = 0;
                        this.f5916B = networkOperator2;
                        return;
                    }
                }
                List neighboringCellInfo = this.f5922f.getNeighboringCellInfo();
                if (neighboringCellInfo != null) {
                    Iterator it = neighboringCellInfo.iterator();
                    while (it.hasNext()) {
                        this.f5940x.add(Integer.valueOf(((NeighboringCellInfo) it.next()).getCid()));
                    }
                }
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public void m2518a() {
        if (this.f5921e != null) {
            this.f5921e.removeCallbacks(this.f5917a);
        }
        this.f5933q = false;
        m2516u();
    }

    /* JADX INFO: renamed from: a */
    public void m2519a(boolean z) {
        this.f5931o = z;
    }

    /* JADX WARN: Code duplicated, block: B:53:0x00b0 A[Catch: all -> 0x0099, TryCatch #0 {, blocks: (B:4:0x0003, B:6:0x0018, B:7:0x001b, B:9:0x001f, B:11:0x0025, B:12:0x0028, B:14:0x002c, B:16:0x0030, B:17:0x003c, B:19:0x0040, B:20:0x0058, B:22:0x005c, B:44:0x0095, B:23:0x0064, B:25:0x0068, B:27:0x006e, B:28:0x0071, B:30:0x0075, B:49:0x009c, B:51:0x00a0, B:53:0x00b0, B:55:0x00b4, B:56:0x00bb, B:58:0x00bf, B:59:0x00cc, B:60:0x00d0, B:62:0x00d4, B:63:0x00e2, B:65:0x00e6, B:32:0x0079, B:34:0x007d, B:36:0x0081, B:38:0x0085, B:40:0x0089, B:66:0x0101, B:68:0x0105, B:69:0x010f, B:71:0x0113, B:72:0x011e), top: B:74:0x0003, inners: #1 }] */
    /* JADX WARN: Code duplicated, block: B:55:0x00b4 A[Catch: all -> 0x0099, TryCatch #0 {, blocks: (B:4:0x0003, B:6:0x0018, B:7:0x001b, B:9:0x001f, B:11:0x0025, B:12:0x0028, B:14:0x002c, B:16:0x0030, B:17:0x003c, B:19:0x0040, B:20:0x0058, B:22:0x005c, B:44:0x0095, B:23:0x0064, B:25:0x0068, B:27:0x006e, B:28:0x0071, B:30:0x0075, B:49:0x009c, B:51:0x00a0, B:53:0x00b0, B:55:0x00b4, B:56:0x00bb, B:58:0x00bf, B:59:0x00cc, B:60:0x00d0, B:62:0x00d4, B:63:0x00e2, B:65:0x00e6, B:32:0x0079, B:34:0x007d, B:36:0x0081, B:38:0x0085, B:40:0x0089, B:66:0x0101, B:68:0x0105, B:69:0x010f, B:71:0x0113, B:72:0x011e), top: B:74:0x0003, inners: #1 }] */
    /* JADX WARN: Code duplicated, block: B:58:0x00bf A[Catch: all -> 0x0099, TryCatch #0 {, blocks: (B:4:0x0003, B:6:0x0018, B:7:0x001b, B:9:0x001f, B:11:0x0025, B:12:0x0028, B:14:0x002c, B:16:0x0030, B:17:0x003c, B:19:0x0040, B:20:0x0058, B:22:0x005c, B:44:0x0095, B:23:0x0064, B:25:0x0068, B:27:0x006e, B:28:0x0071, B:30:0x0075, B:49:0x009c, B:51:0x00a0, B:53:0x00b0, B:55:0x00b4, B:56:0x00bb, B:58:0x00bf, B:59:0x00cc, B:60:0x00d0, B:62:0x00d4, B:63:0x00e2, B:65:0x00e6, B:32:0x0079, B:34:0x007d, B:36:0x0081, B:38:0x0085, B:40:0x0089, B:66:0x0101, B:68:0x0105, B:69:0x010f, B:71:0x0113, B:72:0x011e), top: B:74:0x0003, inners: #1 }] */
    /* JADX WARN: Code duplicated, block: B:60:0x00d0 A[Catch: all -> 0x0099, TryCatch #0 {, blocks: (B:4:0x0003, B:6:0x0018, B:7:0x001b, B:9:0x001f, B:11:0x0025, B:12:0x0028, B:14:0x002c, B:16:0x0030, B:17:0x003c, B:19:0x0040, B:20:0x0058, B:22:0x005c, B:44:0x0095, B:23:0x0064, B:25:0x0068, B:27:0x006e, B:28:0x0071, B:30:0x0075, B:49:0x009c, B:51:0x00a0, B:53:0x00b0, B:55:0x00b4, B:56:0x00bb, B:58:0x00bf, B:59:0x00cc, B:60:0x00d0, B:62:0x00d4, B:63:0x00e2, B:65:0x00e6, B:32:0x0079, B:34:0x007d, B:36:0x0081, B:38:0x0085, B:40:0x0089, B:66:0x0101, B:68:0x0105, B:69:0x010f, B:71:0x0113, B:72:0x011e), top: B:74:0x0003, inners: #1 }] */
    /* JADX WARN: Code duplicated, block: B:62:0x00d4 A[Catch: all -> 0x0099, TryCatch #0 {, blocks: (B:4:0x0003, B:6:0x0018, B:7:0x001b, B:9:0x001f, B:11:0x0025, B:12:0x0028, B:14:0x002c, B:16:0x0030, B:17:0x003c, B:19:0x0040, B:20:0x0058, B:22:0x005c, B:44:0x0095, B:23:0x0064, B:25:0x0068, B:27:0x006e, B:28:0x0071, B:30:0x0075, B:49:0x009c, B:51:0x00a0, B:53:0x00b0, B:55:0x00b4, B:56:0x00bb, B:58:0x00bf, B:59:0x00cc, B:60:0x00d0, B:62:0x00d4, B:63:0x00e2, B:65:0x00e6, B:32:0x0079, B:34:0x007d, B:36:0x0081, B:38:0x0085, B:40:0x0089, B:66:0x0101, B:68:0x0105, B:69:0x010f, B:71:0x0113, B:72:0x011e), top: B:74:0x0003, inners: #1 }] */
    /* JADX WARN: Code duplicated, block: B:63:0x00e2 A[Catch: all -> 0x0099, TryCatch #0 {, blocks: (B:4:0x0003, B:6:0x0018, B:7:0x001b, B:9:0x001f, B:11:0x0025, B:12:0x0028, B:14:0x002c, B:16:0x0030, B:17:0x003c, B:19:0x0040, B:20:0x0058, B:22:0x005c, B:44:0x0095, B:23:0x0064, B:25:0x0068, B:27:0x006e, B:28:0x0071, B:30:0x0075, B:49:0x009c, B:51:0x00a0, B:53:0x00b0, B:55:0x00b4, B:56:0x00bb, B:58:0x00bf, B:59:0x00cc, B:60:0x00d0, B:62:0x00d4, B:63:0x00e2, B:65:0x00e6, B:32:0x0079, B:34:0x007d, B:36:0x0081, B:38:0x0085, B:40:0x0089, B:66:0x0101, B:68:0x0105, B:69:0x010f, B:71:0x0113, B:72:0x011e), top: B:74:0x0003, inners: #1 }] */
    /* JADX WARN: Code duplicated, block: B:65:0x00e6 A[Catch: all -> 0x0099, TryCatch #0 {, blocks: (B:4:0x0003, B:6:0x0018, B:7:0x001b, B:9:0x001f, B:11:0x0025, B:12:0x0028, B:14:0x002c, B:16:0x0030, B:17:0x003c, B:19:0x0040, B:20:0x0058, B:22:0x005c, B:44:0x0095, B:23:0x0064, B:25:0x0068, B:27:0x006e, B:28:0x0071, B:30:0x0075, B:49:0x009c, B:51:0x00a0, B:53:0x00b0, B:55:0x00b4, B:56:0x00bb, B:58:0x00bf, B:59:0x00cc, B:60:0x00d0, B:62:0x00d4, B:63:0x00e2, B:65:0x00e6, B:32:0x0079, B:34:0x007d, B:36:0x0081, B:38:0x0085, B:40:0x0089, B:66:0x0101, B:68:0x0105, B:69:0x010f, B:71:0x0113, B:72:0x011e), top: B:74:0x0003, inners: #1 }] */
    /* JADX INFO: renamed from: a */
    public synchronized boolean m2520a(int i) {
        m2518a();
        this.f5933q = true;
        if (Settings.System.getInt(this.f5919c.getContentResolver(), "airplane_mode_on", 0) == 0) {
            m2517v();
        }
        if (this.f5932p) {
            if (!m2525e()) {
                this.f5932p = false;
            }
            if (this.f5932p) {
                try {
                    if (this.f5926j == null) {
                        this.f5926j = (WifiManager) this.f5919c.getSystemService(SettingUtil.WIFI);
                    }
                    if (this.f5927k == null) {
                        IntentFilter intentFilter = new IntentFilter();
                        intentFilter.addAction("android.net.wifi.SCAN_RESULTS");
                        this.f5927k = new C1070h(this);
                        this.f5919c.registerReceiver(this.f5927k, intentFilter);
                    }
                    if (this.f5926j != null) {
                        this.f5928l = this.f5926j.startScan();
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
        if (this.f5931o) {
            if (!m2522b()) {
                this.f5931o = false;
            }
            if (this.f5931o && !this.f5929m) {
                if (this.f5923g == null) {
                    this.f5923g = (LocationManager) this.f5919c.getSystemService("location");
                    if (this.f5923g != null) {
                        if (this.f5925i == null) {
                            this.f5925i = new C1068f(this);
                        }
                        if (this.f5924h == 1) {
                            this.f5923g.requestLocationUpdates("gps", 2000L, 5.0f, this.f5925i);
                        } else if (this.f5924h == 2) {
                            this.f5923g.requestLocationUpdates("network", 2000L, 5.0f, this.f5925i);
                        } else if (this.f5924h > 2) {
                            this.f5923g.requestLocationUpdates("network", 2000L, 5.0f, this.f5925i);
                            this.f5923g.requestLocationUpdates("gps", 2000L, 5.0f, this.f5925i);
                        }
                        this.f5929m = true;
                    }
                } else {
                    if (this.f5925i == null) {
                        this.f5925i = new C1068f(this);
                    }
                    if (this.f5924h == 1) {
                        this.f5923g.requestLocationUpdates("gps", 2000L, 5.0f, this.f5925i);
                    } else if (this.f5924h == 2) {
                        this.f5923g.requestLocationUpdates("network", 2000L, 5.0f, this.f5925i);
                    } else if (this.f5924h > 2) {
                        this.f5923g.requestLocationUpdates("network", 2000L, 5.0f, this.f5925i);
                        this.f5923g.requestLocationUpdates("gps", 2000L, 5.0f, this.f5925i);
                    }
                    this.f5929m = true;
                }
            }
        }
        if (this.f5931o || this.f5932p) {
            if (this.f5921e == null) {
                this.f5921e = new Handler(Looper.getMainLooper());
            }
            this.f5921e.postDelayed(this.f5917a, i * 1000);
        } else if (this.f5937u == 0) {
            if (this.f5920d != null) {
                this.f5920d.onLocationNotification(0);
                this.f5933q = false;
            }
        } else if (this.f5920d != null) {
            this.f5920d.onLocationNotification(1);
            this.f5933q = false;
        }
        return true;
    }

    /* JADX INFO: renamed from: b */
    public void m2521b(boolean z) {
        this.f5932p = z;
    }

    /* JADX INFO: renamed from: b */
    public boolean m2522b() {
        this.f5924h = 0;
        LocationManager locationManager = (LocationManager) this.f5919c.getSystemService("location");
        if (locationManager == null) {
            return false;
        }
        try {
            if (locationManager.isProviderEnabled("gps")) {
                this.f5924h = 1;
            }
        } catch (Exception e) {
        }
        try {
            if (locationManager.isProviderEnabled("network")) {
                this.f5924h += 2;
            }
        } catch (Exception e2) {
        }
        return this.f5924h > 0;
    }

    /* JADX INFO: renamed from: c */
    public int m2523c() {
        m2517v();
        if (this.f5934r == 0 && this.f5935s == 0) {
            return -1;
        }
        if (this.f5935s == 0 || this.f5935s == 2 || this.f5935s == 7) {
            return 0;
        }
        if (this.f5935s == 1 || this.f5935s == 6) {
            return 1;
        }
        return (this.f5935s == 3 || this.f5935s == 5) ? 2 : -1;
    }

    /* JADX INFO: renamed from: d */
    public QLBSCellInfo m2524d() {
        m2517v();
        return new QLBSCellInfo(m2528h(), m2527g(), m2529i(), m2530j());
    }

    /* JADX INFO: renamed from: e */
    public boolean m2525e() {
        try {
            if (this.f5926j == null) {
                this.f5926j = (WifiManager) this.f5919c.getSystemService(SettingUtil.WIFI);
            }
            if (this.f5926j != null) {
                return this.f5926j.isWifiEnabled();
            }
            return false;
        } catch (Exception e) {
            return false;
        }
    }

    /* JADX INFO: renamed from: f */
    public void m2526f() {
        if (this.f5927k != null) {
            this.f5919c.unregisterReceiver(this.f5927k);
        }
        if (this.f5920d != null) {
            this.f5920d = null;
        }
        if (this.f5923g != null && this.f5925i != null) {
            this.f5923g.removeUpdates(this.f5925i);
            this.f5923g = null;
            this.f5925i = null;
        }
        if (this.f5921e != null) {
            this.f5921e.removeCallbacks(this.f5917a);
            this.f5921e.removeCallbacks(this.f5918b);
            this.f5921e = null;
        }
    }

    /* JADX INFO: renamed from: g */
    public int m2527g() {
        return this.f5934r;
    }

    /* JADX INFO: renamed from: h */
    public int m2528h() {
        return this.f5935s;
    }

    /* JADX INFO: renamed from: i */
    public int m2529i() {
        return this.f5936t;
    }

    /* JADX INFO: renamed from: j */
    public int m2530j() {
        return this.f5937u;
    }

    /* JADX INFO: renamed from: k */
    public int m2531k() {
        return this.f5938v;
    }

    /* JADX INFO: renamed from: l */
    public int m2532l() {
        return this.f5939w;
    }

    /* JADX INFO: renamed from: m */
    public ArrayList m2533m() {
        return this.f5941y;
    }

    /* JADX INFO: renamed from: n */
    public ArrayList m2534n() {
        return this.f5942z;
    }

    /* JADX INFO: renamed from: o */
    public ArrayList m2535o() {
        return this.f5940x;
    }

    /* JADX INFO: renamed from: p */
    public String m2536p() {
        return this.f5915A == null ? "" : this.f5915A;
    }

    /* JADX INFO: renamed from: q */
    public String m2537q() {
        return this.f5916B == null ? "" : this.f5916B;
    }

    /* JADX WARN: Code duplicated, block: B:61:0x00d1 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:65:0x00cc A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: r */
    public void m2538r() throws Throwable {
        FileOutputStream fileOutputStreamOpenFileOutput;
        ObjectOutputStream objectOutputStream;
        ObjectOutputStream objectOutputStream2 = null;
        objectOutputStream2 = null;
        FileOutputStream fileOutputStream = null;
        ArrayList arrayListM2539s = m2539s();
        ArrayList arrayList = arrayListM2539s == null ? new ArrayList() : arrayListM2539s;
        Measure measure = new Measure();
        measure.setLTime(m2515t());
        measure.setStGps(new GPS(this.f5938v, this.f5939w, -1, 0));
        measure.setVCells(new ArrayList());
        measure.getVCells().add(new Cell((short) this.f5934r, (short) this.f5935s, this.f5936t, this.f5937u));
        Iterator it = this.f5940x.iterator();
        while (it.hasNext()) {
            measure.getVCells().add(new Cell((short) this.f5934r, (short) this.f5935s, this.f5936t, ((Integer) it.next()).intValue()));
        }
        measure.setVMacs(m2533m());
        measure.setStrExtraInfo(m2537q());
        arrayList.add(measure);
        if (arrayList == null || arrayList.size() == 0) {
            return;
        }
        try {
            fileOutputStreamOpenFileOutput = this.f5919c.openFileOutput("lbs_temp", 0);
            try {
                ObjectOutputStream objectOutputStream3 = new ObjectOutputStream(fileOutputStreamOpenFileOutput);
                try {
                    objectOutputStream3.writeObject(arrayList);
                    if (fileOutputStreamOpenFileOutput != null) {
                        try {
                            fileOutputStreamOpenFileOutput.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                    try {
                        objectOutputStream3.close();
                    } catch (IOException e2) {
                        e2.printStackTrace();
                    }
                } catch (Exception e3) {
                    e = e3;
                    objectOutputStream = objectOutputStream3;
                    fileOutputStream = fileOutputStreamOpenFileOutput;
                    try {
                        e.printStackTrace();
                        if (fileOutputStream != null) {
                            try {
                                fileOutputStream.close();
                            } catch (IOException e4) {
                                e4.printStackTrace();
                            }
                        }
                        if (objectOutputStream != null) {
                            try {
                                objectOutputStream.close();
                            } catch (IOException e5) {
                                e5.printStackTrace();
                            }
                        }
                    } catch (Throwable th) {
                        th = th;
                        fileOutputStreamOpenFileOutput = fileOutputStream;
                        objectOutputStream2 = objectOutputStream;
                        if (fileOutputStreamOpenFileOutput != null) {
                            try {
                                fileOutputStreamOpenFileOutput.close();
                            } catch (IOException e6) {
                                e6.printStackTrace();
                            }
                        }
                        if (objectOutputStream2 != null) {
                            try {
                                objectOutputStream2.close();
                            } catch (IOException e7) {
                                e7.printStackTrace();
                            }
                        }
                        throw th;
                    }
                } catch (Throwable th2) {
                    th = th2;
                    objectOutputStream2 = objectOutputStream3;
                    if (fileOutputStreamOpenFileOutput != null) {
                        fileOutputStreamOpenFileOutput.close();
                    }
                    if (objectOutputStream2 != null) {
                        objectOutputStream2.close();
                    }
                    throw th;
                }
            } catch (Exception e8) {
                e = e8;
                objectOutputStream = null;
                fileOutputStream = fileOutputStreamOpenFileOutput;
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (Exception e9) {
            e = e9;
            objectOutputStream = null;
        } catch (Throwable th4) {
            th = th4;
            fileOutputStreamOpenFileOutput = null;
        }
    }

    /* JADX INFO: renamed from: s */
    public ArrayList m2539s() throws Throwable {
        FileInputStream fileInputStreamOpenFileInput;
        ObjectInputStream objectInputStream;
        FileInputStream fileInputStream;
        ObjectInputStream objectInputStream2 = null;
        try {
            fileInputStreamOpenFileInput = this.f5919c.openFileInput("lbs_temp");
            try {
                ObjectInputStream objectInputStream3 = new ObjectInputStream(fileInputStreamOpenFileInput);
                try {
                    ArrayList arrayList = (ArrayList) objectInputStream3.readObject();
                    try {
                        objectInputStream3.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    if (fileInputStreamOpenFileInput != null) {
                        try {
                            fileInputStreamOpenFileInput.close();
                        } catch (IOException e2) {
                            e2.printStackTrace();
                        }
                    }
                    this.f5919c.deleteFile("lbs_temp");
                    return arrayList;
                } catch (Exception e3) {
                    objectInputStream = objectInputStream3;
                    fileInputStream = fileInputStreamOpenFileInput;
                    if (objectInputStream != null) {
                        try {
                            objectInputStream.close();
                        } catch (IOException e4) {
                            e4.printStackTrace();
                        }
                    }
                    if (fileInputStream != null) {
                        try {
                            fileInputStream.close();
                        } catch (IOException e5) {
                            e5.printStackTrace();
                        }
                    }
                    this.f5919c.deleteFile("lbs_temp");
                    return null;
                } catch (Throwable th) {
                    th = th;
                    objectInputStream2 = objectInputStream3;
                    if (objectInputStream2 != null) {
                        try {
                            objectInputStream2.close();
                        } catch (IOException e6) {
                            e6.printStackTrace();
                        }
                    }
                    if (fileInputStreamOpenFileInput != null) {
                        try {
                            fileInputStreamOpenFileInput.close();
                        } catch (IOException e7) {
                            e7.printStackTrace();
                        }
                    }
                    this.f5919c.deleteFile("lbs_temp");
                    throw th;
                }
            } catch (Exception e8) {
                objectInputStream = null;
                fileInputStream = fileInputStreamOpenFileInput;
            } catch (Throwable th2) {
                th = th2;
            }
        } catch (Exception e9) {
            objectInputStream = null;
            fileInputStream = null;
        } catch (Throwable th3) {
            th = th3;
            fileInputStreamOpenFileInput = null;
        }
    }

    public String toString() {
        return "mcc=" + this.f5934r + " mnc" + this.f5935s + " cell=" + this.f5937u + "  lat=" + this.f5938v + " wifiNum=" + this.f5941y.size();
    }
}
