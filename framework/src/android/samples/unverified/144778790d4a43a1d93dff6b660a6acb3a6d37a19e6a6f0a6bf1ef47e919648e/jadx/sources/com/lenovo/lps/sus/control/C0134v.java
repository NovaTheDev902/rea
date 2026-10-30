package com.lenovo.lps.sus.control;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Handler;
import android.os.Message;
import android.widget.Toast;
import com.lenovo.lps.sus.EventType;
import com.lenovo.lps.sus.SUS;
import com.lenovo.lps.sus.SUSListener;
import com.lenovo.lps.sus.p007b.C0085a;
import com.lenovo.lps.sus.p007b.C0087c;
import com.lenovo.lps.sus.p007b.C0089e;
import com.lenovo.lps.sus.p007b.EnumC0086b;
import com.lenovo.lps.sus.p007b.EnumC0088d;
import com.lenovo.lps.sus.p008c.C0090a;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import java.io.File;
import java.net.URLDecoder;
import java.net.URLEncoder;
import java.util.Date;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.v */
/* JADX INFO: loaded from: classes.dex */
public class C0134v {

    /* JADX INFO: renamed from: aa */
    private static /* synthetic */ int[] f1486aa;

    /* JADX INFO: renamed from: ab */
    private static /* synthetic */ int[] f1487ab;

    /* JADX INFO: renamed from: c */
    private Context f1514c;

    /* JADX INFO: renamed from: d */
    private Handler f1515d;

    /* JADX INFO: renamed from: e */
    private C0111am f1516e;

    /* JADX INFO: renamed from: a */
    public static String f1485a = null;

    /* JADX INFO: renamed from: b */
    public static boolean f1488b = true;

    /* JADX INFO: renamed from: X */
    private static C0112an f1484X = null;

    /* JADX INFO: renamed from: f */
    private C0087c f1517f = null;

    /* JADX INFO: renamed from: g */
    private int f1518g = 0;

    /* JADX INFO: renamed from: h */
    private String f1519h = null;

    /* JADX INFO: renamed from: i */
    private String f1520i = null;

    /* JADX INFO: renamed from: j */
    private String f1521j = null;

    /* JADX INFO: renamed from: k */
    private String f1522k = null;

    /* JADX INFO: renamed from: l */
    private String f1523l = null;

    /* JADX INFO: renamed from: m */
    private String f1524m = null;

    /* JADX INFO: renamed from: n */
    private String f1525n = null;

    /* JADX INFO: renamed from: o */
    private String f1526o = null;

    /* JADX INFO: renamed from: p */
    private String f1527p = null;

    /* JADX INFO: renamed from: q */
    private String f1528q = null;

    /* JADX INFO: renamed from: r */
    private String f1529r = null;

    /* JADX INFO: renamed from: s */
    private String f1530s = null;

    /* JADX INFO: renamed from: t */
    private String f1531t = null;

    /* JADX INFO: renamed from: u */
    private String f1532u = null;

    /* JADX INFO: renamed from: v */
    private String f1533v = null;

    /* JADX INFO: renamed from: w */
    private String f1534w = null;

    /* JADX INFO: renamed from: x */
    private String f1535x = null;

    /* JADX INFO: renamed from: y */
    private String f1536y = null;

    /* JADX INFO: renamed from: z */
    private String f1537z = null;

    /* JADX INFO: renamed from: A */
    private String f1489A = null;

    /* JADX INFO: renamed from: B */
    private boolean f1490B = true;

    /* JADX INFO: renamed from: C */
    private boolean f1491C = true;

    /* JADX INFO: renamed from: D */
    private boolean f1492D = false;

    /* JADX INFO: renamed from: E */
    private String f1493E = null;

    /* JADX INFO: renamed from: F */
    private C0138z f1494F = null;

    /* JADX INFO: renamed from: G */
    private String f1495G = null;

    /* JADX INFO: renamed from: H */
    private C0107ah f1496H = null;

    /* JADX INFO: renamed from: I */
    private String f1497I = null;

    /* JADX INFO: renamed from: J */
    private File f1498J = null;

    /* JADX INFO: renamed from: K */
    private String f1499K = null;

    /* JADX INFO: renamed from: L */
    private long f1500L = 0;

    /* JADX INFO: renamed from: M */
    private String f1501M = null;

    /* JADX INFO: renamed from: N */
    private SUSListener f1502N = null;

    /* JADX INFO: renamed from: O */
    private SUSListener f1503O = null;

    /* JADX INFO: renamed from: P */
    private String f1504P = null;

    /* JADX INFO: renamed from: Q */
    private long f1505Q = 0;

    /* JADX INFO: renamed from: R */
    private long f1506R = 0;

    /* JADX INFO: renamed from: S */
    private int f1507S = 0;

    /* JADX INFO: renamed from: T */
    private int f1508T = 0;

    /* JADX INFO: renamed from: U */
    private int f1509U = 100;

    /* JADX INFO: renamed from: V */
    private long f1510V = 0;

    /* JADX INFO: renamed from: W */
    private long f1511W = 0;

    /* JADX INFO: renamed from: Y */
    private EnumC0113ap f1512Y = EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_USERSETTINGS;

    /* JADX INFO: renamed from: Z */
    private EnumC0108ai f1513Z = EnumC0108ai.SUS_CUSTOM_DOWNLOADMANAGER_NOTIFICATION;

    public C0134v(Context context) {
        this.f1514c = null;
        this.f1515d = null;
        this.f1516e = null;
        if (C0092c.m397w()) {
            this.f1514c = context;
            C0098i.m409a(C0092c.f1339b, "use activity's context,context=" + context);
        } else {
            this.f1514c = context.getApplicationContext();
            C0098i.m409a(C0092c.f1339b, "use ApplicationContext,myApplicationContext=" + this.f1514c);
        }
        this.f1515d = new HandlerC0118f(this);
        this.f1516e = new C0111am(this.f1514c, this.f1515d);
        C0098i.m409a(C0092c.f1339b, "mySUSUIHandler=" + this.f1516e);
    }

    /* JADX INFO: renamed from: a */
    public static String m496a(C0085a c0085a) {
        if (c0085a == null) {
            return "{\"RES\":\"NOTFOUND\"}";
        }
        if (!C0092c.f1288S.equals(c0085a.m284h())) {
            if (C0092c.f1289T.equals(c0085a.m284h())) {
                return "{\"RES\":\"LATESTVERSION\"}";
            }
            return C0092c.f1290U.equals(c0085a.m284h()) ? "{\"RES\":\"NOTFOUND\"}" : "{\"RES\":\"NOTFOUND\"}";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("{\"RES\":\"");
        sb.append(C0092c.f1288S);
        sb.append(C0092c.f1282M);
        sb.append(",\"ChannelKey\":\"");
        sb.append(URLEncoder.encode("Common".equals(c0085a.m286i()) ? "null" : c0085a.m286i()));
        sb.append(C0092c.f1282M);
        sb.append(",\"VerCode\":\"");
        sb.append(URLEncoder.encode(c0085a.m276d()));
        sb.append(C0092c.f1282M);
        sb.append(",\"VerName\":\"");
        sb.append(URLEncoder.encode(c0085a.m272b()));
        sb.append(C0092c.f1282M);
        sb.append(",\"DownloadURL\":\"");
        sb.append(URLEncoder.encode(c0085a.m278e()));
        sb.append(C0092c.f1282M);
        sb.append(",\"Size\":\"");
        sb.append(URLEncoder.encode(String.valueOf(c0085a.m280f())));
        sb.append(C0092c.f1282M);
        sb.append(",\"UpdateDesc\":\"");
        sb.append(URLEncoder.encode(c0085a.m282g()));
        sb.append(C0092c.f1282M);
        sb.append(",\"FileName\":\"");
        sb.append(URLEncoder.encode(c0085a.m288j()));
        sb.append(C0092c.f1282M);
        sb.append(",\"ForceUpdate\":\"");
        sb.append(URLEncoder.encode(c0085a.m290k()));
        sb.append(C0092c.f1282M);
        sb.append(",\"CustKey\":\"");
        sb.append(URLEncoder.encode(c0085a.m292l()));
        sb.append(C0092c.f1282M);
        sb.append(C0092c.f1286Q);
        return sb.toString();
    }

    /* JADX INFO: renamed from: b */
    public static void m497b(String str) {
        f1485a = str;
    }

    /* JADX INFO: renamed from: n */
    public static String m498n() {
        return f1485a;
    }

    /* JADX INFO: renamed from: o */
    public static String m499o() {
        return "{\"RES\":\"NOTFOUND\"}";
    }

    /* JADX INFO: renamed from: p */
    public static String m500p() {
        return "{\"RES\":\"LATESTVERSION\"}";
    }

    /* JADX INFO: renamed from: q */
    public static String m501q() {
        return "{\"RES\":\"EXCEPTION\"}";
    }

    /* JADX INFO: renamed from: v */
    private static /* synthetic */ int[] m502v() {
        int[] iArr = f1486aa;
        if (iArr == null) {
            iArr = new int[EnumC0113ap.m495a().length];
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYAPPKEY_CUSTINPUT_NOUSERSETTINGS.ordinal()] = 6;
            } catch (NoSuchFieldError e) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTDM2ACTIVITY__NOUSERSETTINGS.ordinal()] = 7;
            } catch (NoSuchFieldError e2) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTINPUT_NOUSERSETTINGS.ordinal()] = 3;
            } catch (NoSuchFieldError e3) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTINPUT_NOUSERSETTINGS_AUTOINSTALL.ordinal()] = 5;
            } catch (NoSuchFieldError e4) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTINPUT_NOUSERSETTINGS_CUSTCONF.ordinal()] = 4;
            } catch (NoSuchFieldError e5) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTINPUT_QUERYALLVER.ordinal()] = 9;
            } catch (NoSuchFieldError e6) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTINPUT_QUERYLATESTVER.ordinal()] = 8;
            } catch (NoSuchFieldError e7) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_IGNOREUSERSETTINGS.ordinal()] = 2;
            } catch (NoSuchFieldError e8) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_USERSETTINGS.ordinal()] = 1;
            } catch (NoSuchFieldError e9) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_DOWNLOAD_BYURL.ordinal()] = 10;
            } catch (NoSuchFieldError e10) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_INSTALLAPP.ordinal()] = 11;
            } catch (NoSuchFieldError e11) {
            }
            try {
                iArr[EnumC0113ap.SUS_UPDATETRANSATION_TYPE_TESTSUSSERVER.ordinal()] = 12;
            } catch (NoSuchFieldError e12) {
            }
            f1486aa = iArr;
        }
        return iArr;
    }

    /* JADX INFO: renamed from: w */
    private static /* synthetic */ int[] m503w() {
        int[] iArr = f1487ab;
        if (iArr == null) {
            iArr = new int[EnumC0086b.m296b().length];
            try {
                iArr[EnumC0086b.SUS_DOWNLOAD_EXCEPTION_EVENT.ordinal()] = 8;
            } catch (NoSuchFieldError e) {
            }
            try {
                iArr[EnumC0086b.SUS_FINISH_EVENT.ordinal()] = 10;
            } catch (NoSuchFieldError e2) {
            }
            try {
                iArr[EnumC0086b.SUS_INSTALLAPK_EVENT.ordinal()] = 3;
            } catch (NoSuchFieldError e3) {
            }
            try {
                iArr[EnumC0086b.SUS_NOTIFICATION_INSTALL_EVENT.ordinal()] = 13;
            } catch (NoSuchFieldError e4) {
            }
            try {
                iArr[EnumC0086b.SUS_QUERY_EXCEPTION_EVENT.ordinal()] = 7;
            } catch (NoSuchFieldError e5) {
            }
            try {
                iArr[EnumC0086b.SUS_REPORT_SILENCEINSTALLRESULT_EVENT.ordinal()] = 12;
            } catch (NoSuchFieldError e6) {
            }
            try {
                iArr[EnumC0086b.SUS_REQNEWAPPVERSION_RESPONE_EVENT.ordinal()] = 4;
            } catch (NoSuchFieldError e7) {
            }
            try {
                iArr[EnumC0086b.SUS_STARTUPDATE_EVENT.ordinal()] = 1;
            } catch (NoSuchFieldError e8) {
            }
            try {
                iArr[EnumC0086b.SUS_TESTSUSSERVER_EVENT.ordinal()] = 9;
            } catch (NoSuchFieldError e9) {
            }
            try {
                iArr[EnumC0086b.SUS_UPDATE_PROMPT_EVENT.ordinal()] = 2;
            } catch (NoSuchFieldError e10) {
            }
            try {
                iArr[EnumC0086b.SUS_UPDATE_USERACTION_EVENT.ordinal()] = 11;
            } catch (NoSuchFieldError e11) {
            }
            try {
                iArr[EnumC0086b.SUS_USER_CHANGESETTINGS_EVENT.ordinal()] = 6;
            } catch (NoSuchFieldError e12) {
            }
            try {
                iArr[EnumC0086b.SUS_USER_REQUPDATE_EVENT.ordinal()] = 5;
            } catch (NoSuchFieldError e13) {
            }
            f1487ab = iArr;
        }
        return iArr;
    }

    /* JADX INFO: renamed from: a */
    public void m504a() {
        C0098i.m409a(C0092c.f1339b, "UpdateTransaction finish entry");
        if (this.f1516e != null) {
            C0098i.m409a(C0092c.f1339b, "UpdateTransaction call mySUSUIHandler finish");
            this.f1516e.m487a();
            this.f1516e = null;
        }
        this.f1514c = null;
        this.f1515d = null;
        this.f1504P = null;
        this.f1505Q = 0L;
        this.f1506R = 0L;
        this.f1507S = 0;
        this.f1511W = 0L;
        this.f1510V = 0L;
        C0098i.m409a(C0092c.f1339b, "UpdateTransaction finish end");
    }

    /* JADX INFO: renamed from: a */
    public void m505a(int i, int i2) {
        if (this.f1514c == null) {
            return;
        }
        if (this.f1517f == null) {
            this.f1517f = new C0087c();
        }
        this.f1517f.m301a(i);
        this.f1517f.m304b(i2);
        SharedPreferences.Editor editorEdit = this.f1514c.getSharedPreferences(C0092c.f1316ad, 0).edit();
        editorEdit.putInt(C0092c.f1317ae, this.f1517f.m300a());
        editorEdit.putInt(C0092c.f1318af, i2);
        editorEdit.commit();
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    /* JADX WARN: Code duplicated, block: B:15:0x0068  */
    /* JADX WARN: Code duplicated, block: B:18:0x006d  */
    /* JADX WARN: Code duplicated, block: B:20:0x0074  */
    /* JADX WARN: Code duplicated, block: B:271:0x053b  */
    /* JADX INFO: renamed from: a */
    public void m506a(Message message) {
        String strM343b;
        String strM343b2;
        String strM343b3;
        String strM343b4;
        String strM383n;
        boolean zM336a;
        String strM343b5;
        boolean z;
        if (message == null || this.f1514c == null) {
            return;
        }
        switch (m503w()[EnumC0086b.m294a(message.what).ordinal()]) {
            case 1:
                m514c();
                break;
            case 2:
                C0098i.m409a(C0092c.f1339b, "SUS_UPDATE_PROMPT_MSG mySUSUIHandler=" + this.f1516e);
                switch (m502v()[this.f1512Y.ordinal()]) {
                    case 3:
                    case 6:
                    case 7:
                        z = false;
                        if (this.f1516e != null) {
                            m519h();
                            if (this.f1517f != null) {
                                this.f1516e.m490a((C0085a) message.obj, this.f1517f.m303b(), C0092c.m355d() ? z : false);
                            }
                        }
                        break;
                    case 4:
                        if (!this.f1490B) {
                            C0104ae.m447b();
                        }
                        z = false;
                        if (this.f1516e != null) {
                            m519h();
                            if (this.f1517f != null) {
                                this.f1516e.m490a((C0085a) message.obj, this.f1517f.m303b(), C0092c.m355d() ? z : false);
                            }
                        }
                        break;
                    case 5:
                        Message message2 = new Message();
                        if (this.f1515d != null) {
                            message.what = EnumC0086b.m293a(EnumC0086b.SUS_USER_REQUPDATE_EVENT);
                            message.obj = 0;
                            this.f1515d.sendMessage(message2);
                            z = true;
                        } else {
                            z = true;
                        }
                        if (this.f1516e != null) {
                            m519h();
                            if (this.f1517f != null) {
                                this.f1516e.m490a((C0085a) message.obj, this.f1517f.m303b(), C0092c.m355d() ? z : false);
                            }
                        }
                        break;
                    case 8:
                    case 9:
                        C0104ae.m447b();
                        break;
                    default:
                        z = true;
                        if (this.f1516e != null) {
                            m519h();
                            if (this.f1517f != null) {
                                this.f1516e.m490a((C0085a) message.obj, this.f1517f.m303b(), C0092c.m355d() ? z : false);
                            }
                        }
                        break;
                }
                break;
            case 3:
                if (EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTINPUT_NOUSERSETTINGS_CUSTCONF == this.f1512Y && !this.f1491C) {
                    C0104ae.m447b();
                } else {
                    String str = (String) message.obj;
                    if (str != null && (str == null || str.length() > 0)) {
                        C0098i.m409a(C0092c.f1339b, "handle SUS_INSTALLAPK_EVENT,file=" + str);
                        m517f();
                        this.f1496H = new C0107ah(this.f1495G);
                        if (this.f1496H != null) {
                            this.f1496H.start();
                        } else {
                            C0098i.m411b(C0092c.f1339b, "mySUSResInfoThread == null!");
                        }
                        this.f1495G = null;
                        if (EnumC0113ap.SUS_UPDATETRANSATION_TYPE_DOWNLOAD_BYURL != this.f1512Y) {
                            if (EnumC0113ap.SUS_UPDATETRANSATION_TYPE_INSTALLAPP != this.f1512Y) {
                                if (C0092c.m351c() && !C0104ae.m457f() && !C0104ae.m459g() && this.f1514c != null && (strM343b3 = C0092c.m343b(this.f1514c, "SUS_MSG_DOWNLOADCOMPLETE")) != null && strM343b3.length() > 0) {
                                    Toast.makeText(this.f1514c, strM343b3, 1).show();
                                }
                                if (this.f1502N != null) {
                                    this.f1502N.onUpdateNotification(EventType.SUS_DOWNLOADCOMPLETE, str);
                                }
                            }
                            if (this.f1492D && str != null && C0092c.m399y() > 0) {
                                C0098i.m409a(C0092c.f1339b, "chmod 777,filename=" + str);
                                C0092c.m332a("777", str);
                            }
                            if (new File(str).exists()) {
                                C0092c.m331a(this.f1514c, str, this.f1528q, this.f1515d, this.f1502N, C0092c.m399y(), false);
                            }
                            C0104ae.m447b();
                        } else {
                            if (C0092c.m351c() && !C0104ae.m457f() && !C0104ae.m459g() && this.f1514c != null && (strM343b4 = C0092c.m343b(this.f1514c, "SUS_MSG_DOWNLOADCOMPLETE")) != null && strM343b4.length() > 0) {
                                Toast.makeText(this.f1514c, strM343b4, 1).show();
                            }
                            this.f1503O = this.f1502N;
                            C0104ae.m447b();
                            if (this.f1503O != null) {
                                this.f1503O.onUpdateNotification(EventType.SUS_DOWNLOADCOMPLETE, str);
                            }
                            this.f1503O = null;
                        }
                    } else {
                        C0104ae.m447b();
                    }
                }
                break;
            case 4:
                m511a((String) message.obj);
                break;
            case 5:
                int iIntValue = (message == null || message.obj == null) ? 0 : ((Integer) message.obj).intValue();
                if (iIntValue == 0) {
                    this.f1510V = System.currentTimeMillis();
                }
                this.f1492D = false;
                if (this.f1504P != null) {
                    String str2 = this.f1504P;
                    zM336a = C0092c.m337a(this.f1505Q, this.f1500L, this.f1506R);
                    strM383n = str2;
                } else {
                    strM383n = C0092c.m383n(this.f1514c);
                    this.f1492D = C0092c.m368g();
                    C0092c.m333a(strM383n, this.f1499K, this.f1492D);
                    zM336a = C0092c.m336a(this.f1500L);
                    if (!zM336a) {
                        C0092c.m359e(strM383n);
                        zM336a = C0092c.m336a(this.f1500L);
                    }
                }
                C0098i.m409a(C0092c.f1339b, "downloadpath=" + strM383n);
                if (!zM336a) {
                    if (C0092c.m351c() && !C0104ae.m457f() && !C0104ae.m459g() && this.f1514c != null && (strM343b5 = C0092c.m343b(this.f1514c, "SUS_MSG_INSUFFICIENTSTORAGESPACE")) != null && strM343b5.length() > 0) {
                        Toast.makeText(this.f1514c, strM343b5, 1).show();
                    }
                    this.f1503O = this.f1502N;
                    C0104ae.m447b();
                    if (this.f1503O != null) {
                        this.f1503O.onUpdateNotification(EventType.SUS_FAIL_INSUFFICIENTSTORAGESPACE, "insufficient storage space");
                        this.f1503O = null;
                    }
                    C0098i.m409a(C0092c.f1339b, "INSUFFICIENTSTORAGESPACE");
                } else {
                    this.f1498J = new File(strM383n);
                    if (this.f1498J != null && !this.f1498J.exists()) {
                        this.f1498J.mkdirs();
                    }
                    if (this.f1498J != null && (this.f1498J == null || this.f1498J.exists())) {
                        m497b(strM383n);
                        if (this.f1502N != null && this.f1509U != this.f1508T) {
                            this.f1508T = this.f1509U;
                            this.f1502N.onUpdateNotification(EventType.SUS_DOWNLOADSTART, "Start the downloading");
                        }
                        if (this.f1516e == null || this.f1497I == null || strM383n == null || this.f1499K == null || this.f1500L <= 0) {
                            C0098i.m409a(C0092c.f1339b, "updateHandler exception.");
                            C0104ae.m447b();
                        } else {
                            this.f1516e.m489a(iIntValue, this.f1497I, strM383n, this.f1499K, this.f1500L, this.f1513Z);
                        }
                    } else {
                        C0098i.m409a(C0092c.f1339b, "The folder isn't exit! path=" + strM383n);
                        this.f1503O = this.f1502N;
                        C0104ae.m447b();
                        if (this.f1503O != null) {
                            this.f1503O.onUpdateNotification(EventType.SUS_FAIL_DOWNOLADFOLDER_FOLDER_NOTEXIST, "The download folder does not exist.");
                            this.f1503O = null;
                        }
                        C0098i.m409a(C0092c.f1339b, "The download folder does not exist.");
                    }
                }
                break;
            case 6:
                m505a(Integer.valueOf(message.arg1).intValue(), ((Integer) message.obj).intValue());
                break;
            case 7:
                if (C0092c.m397w()) {
                    C0111am.m474c();
                } else if (C0092c.m396v()) {
                    SUSCustdefNotificationActivity.m416b();
                } else {
                    SUSNotificationActivity.m424a();
                }
                if (C0092c.m351c() && !C0104ae.m457f() && !C0104ae.m459g() && this.f1514c != null && (strM343b2 = C0092c.m343b(this.f1514c, "SUS_MSG_UPDATE_EXCEPTION")) != null && strM343b2.length() > 0) {
                    Toast.makeText(this.f1514c, strM343b2, 1).show();
                }
                this.f1503O = this.f1502N;
                C0104ae.m447b();
                if (this.f1503O != null) {
                    this.f1503O.onUpdateNotification(EventType.SUS_QUERY_RESP, C0092c.f1291V);
                    this.f1503O = null;
                }
                break;
            case 8:
                boolean zBooleanValue = ((Boolean) message.obj).booleanValue();
                if (this.f1507S < 2 && !zBooleanValue) {
                    this.f1507S++;
                    if (this.f1514c != null) {
                        if (1 == this.f1507S) {
                            if (System.currentTimeMillis() - this.f1510V > 4000) {
                                if (!C0092c.m395u() && !C0104ae.m457f() && !C0104ae.m459g()) {
                                    C0092c.m360e(true);
                                }
                                this.f1511W = System.currentTimeMillis();
                            }
                        } else if (2 == this.f1507S && (((this.f1511W > 0 && System.currentTimeMillis() - this.f1511W > 9000) || (0 == this.f1511W && System.currentTimeMillis() - this.f1510V > 6000)) && !C0092c.m395u() && !C0104ae.m457f() && !C0104ae.m459g())) {
                            C0092c.m360e(true);
                        }
                    }
                    Message message3 = new Message();
                    if (this.f1515d != null) {
                        message3.what = EnumC0086b.m293a(EnumC0086b.SUS_USER_REQUPDATE_EVENT);
                        message3.obj = Integer.valueOf(this.f1507S);
                        this.f1515d.sendMessage(message3);
                    }
                    break;
                } else {
                    if (C0092c.m397w()) {
                        C0111am.m474c();
                    } else if (C0092c.m396v()) {
                        SUSCustdefNotificationActivity.m416b();
                    } else {
                        SUSNotificationActivity.m424a();
                    }
                    if (C0092c.m351c() && !C0104ae.m457f() && !C0104ae.m459g() && this.f1514c != null && (strM343b = C0092c.m343b(this.f1514c, "SUS_MSG_UPDATE_EXCEPTION")) != null && strM343b.length() > 0) {
                        Toast.makeText(this.f1514c, strM343b, 1).show();
                    }
                    Message message4 = new Message();
                    if (this.f1515d != null) {
                        message4.what = EnumC0086b.m293a(EnumC0086b.SUS_FINISH_EVENT);
                        this.f1515d.sendMessageDelayed(message4, 300L);
                    }
                    this.f1503O = this.f1502N;
                    if (this.f1503O != null && !zBooleanValue) {
                        this.f1503O.onUpdateNotification(EventType.SUS_FAIL_DOWNLOAD_EXCEPTION, null);
                        this.f1503O = null;
                        break;
                    }
                }
                break;
            case 9:
                this.f1503O = this.f1502N;
                C0104ae.m447b();
                if (this.f1503O != null) {
                    String str3 = (String) message.obj;
                    if (str3 == null || str3.length() <= 0) {
                        str3 = "FAIL";
                    }
                    this.f1503O.onUpdateNotification(EventType.SUS_TESTSERVER_RESP, str3);
                }
                this.f1503O = null;
                break;
            case 10:
                C0104ae.m447b();
                break;
            case 11:
                EventType eventType = (EventType) message.obj;
                this.f1503O = this.f1502N;
                if (eventType != null) {
                    if (EventType.SUS_UPDATEPROMPT_USER_CONFIRM.equals(eventType)) {
                        if (this.f1503O != null) {
                            this.f1503O.onUpdateNotification(EventType.SUS_UPDATEPROMPT_USER_CONFIRM, "user click the confirm button!");
                        }
                        Message message5 = new Message();
                        if (this.f1515d != null) {
                            message5.what = EnumC0086b.m293a(EnumC0086b.SUS_USER_REQUPDATE_EVENT);
                            this.f1515d.sendMessage(message5);
                        } else {
                            C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog PositiveButton myMSGHandler=null");
                        }
                    } else if (EventType.SUS_UPDATEPROMPT_USER_CANCEL.equals(eventType)) {
                        C0104ae.m447b();
                        if (this.f1503O != null) {
                            this.f1503O.onUpdateNotification(EventType.SUS_UPDATEPROMPT_USER_CONFIRM, "user click the cancel button!");
                        }
                    }
                }
                this.f1503O = null;
                break;
            case 13:
                C0092c.m352d(this.f1514c, (String) message.obj);
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    public void m507a(EventType eventType) {
        Message message = new Message();
        if (this.f1515d == null || eventType == null) {
            return;
        }
        message.what = EnumC0086b.m293a(EnumC0086b.SUS_UPDATE_USERACTION_EVENT);
        message.obj = eventType;
        this.f1515d.sendMessage(message);
    }

    /* JADX INFO: renamed from: a */
    public void m508a(SUSListener sUSListener) {
        this.f1502N = sUSListener;
    }

    /* JADX INFO: renamed from: a */
    public void m509a(EnumC0113ap enumC0113ap, C0089e c0089e) {
        C0098i.m409a(C0092c.f1339b, "startUpdateTransaction!");
        this.f1512Y = enumC0113ap;
        this.f1513Z = EnumC0108ai.SUS_CUSTOM_DOWNLOADMANAGER_NOTIFICATION;
        this.f1507S = 0;
        this.f1509U++;
        if (this.f1509U > 10000) {
            this.f1509U = 1;
        }
        this.f1508T = 0;
        this.f1511W = 0L;
        this.f1510V = 0L;
        switch (m502v()[this.f1512Y.ordinal()]) {
            case 1:
            case 2:
            case 7:
                if (!m515d()) {
                    System.out.println("getappinfo fail!");
                    C0098i.m411b(C0092c.f1339b, "getappinfo fail!");
                    C0104ae.m447b();
                    return;
                }
                break;
            case 3:
            case 4:
            case 5:
                this.f1528q = c0089e.f1259a;
                this.f1518g = Integer.valueOf(c0089e.f1260b).intValue();
                this.f1522k = c0089e.f1261c;
                this.f1490B = c0089e.f1262d;
                this.f1491C = c0089e.f1263e;
                break;
            case 6:
                this.f1521j = c0089e.f1259a;
                this.f1518g = Integer.valueOf(c0089e.f1260b).intValue();
                this.f1522k = c0089e.f1261c;
                break;
            case 8:
            case 9:
                this.f1528q = c0089e.f1259a;
                this.f1518g = Integer.valueOf(c0089e.f1260b).intValue();
                this.f1522k = c0089e.f1261c;
                break;
            case 10:
                this.f1497I = c0089e.f1259a;
                this.f1499K = c0089e.f1260b;
                this.f1500L = Long.valueOf(c0089e.f1261c).longValue();
                Message message = new Message();
                if (this.f1515d != null) {
                    message.what = EnumC0086b.m293a(EnumC0086b.SUS_USER_REQUPDATE_EVENT);
                    message.obj = 0;
                    this.f1515d.sendMessage(message);
                    return;
                }
                return;
            case 11:
                String str = c0089e.f1259a;
                Message message2 = new Message();
                if (this.f1515d != null) {
                    message2.what = EnumC0086b.m293a(EnumC0086b.SUS_INSTALLAPK_EVENT);
                    message2.obj = str;
                    this.f1515d.sendMessage(message2);
                    return;
                }
                return;
            case 12:
                m525r();
                return;
        }
        m516e();
        m518g();
        Message message3 = new Message();
        if (this.f1515d != null) {
            message3.what = EnumC0086b.m293a(EnumC0086b.SUS_STARTUPDATE_EVENT);
            this.f1515d.sendMessage(message3);
        }
        C0090a.m309a(this.f1514c, this.f1528q, String.valueOf(this.f1518g), this.f1522k);
        switch (m502v()[this.f1512Y.ordinal()]) {
            case 2:
                C0090a.m313b();
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    public void m510a(C0138z c0138z) {
        this.f1494F = c0138z;
    }

    /* JADX INFO: renamed from: a */
    public void m511a(String str) {
        String str2;
        String str3;
        String str4;
        String str5;
        String str6;
        boolean z;
        String strM343b;
        String strM343b2;
        if (str == null || ((str != null && str.length() <= 0) || !(str == null || str.startsWith(C0092c.f1287R)))) {
            C0104ae.m447b();
        }
        C0098i.m409a(C0092c.f1339b, "responeStr = " + str);
        String strSubstring = str.substring(C0092c.f1287R.length());
        if (strSubstring == null || (strSubstring != null && strSubstring.length() <= 0)) {
            C0104ae.m447b();
            return;
        }
        boolean z2 = false;
        String strDecode = null;
        String string = null;
        String string2 = null;
        String string3 = null;
        String str7 = C0092c.f1297aA;
        try {
            JSONObject jSONObject = new JSONObject(strSubstring).getJSONObject(C0092c.f1361x);
            String string4 = jSONObject != null ? jSONObject.getString(C0092c.f1281L) : null;
            if (C0092c.f1288S.equals(string4)) {
                String string5 = jSONObject.getString(C0092c.f1272C);
                String string6 = jSONObject.getString(C0092c.f1273D);
                String string7 = jSONObject.getString(C0092c.f1274E);
                String string8 = jSONObject.getString(C0092c.f1276G);
                String string9 = jSONObject.getString(C0092c.f1277H);
                String string10 = jSONObject.getString(C0092c.f1278I);
                String string11 = jSONObject.getString(C0092c.f1271B);
                String string12 = jSONObject.getString(C0092c.f1270A);
                try {
                    string = jSONObject.getString(C0092c.f1279J);
                } catch (JSONException e) {
                }
                try {
                    string2 = jSONObject.getString(C0092c.f1280K);
                } catch (JSONException e2) {
                }
                try {
                    string3 = jSONObject.getString(C0092c.f1275F);
                } catch (JSONException e3) {
                }
                if (string3 != null && string3.length() > 0) {
                    if ("it_si_noprompt".equals(string3)) {
                        SUS.silentUpdateEnable();
                        C0092c.m344b(1);
                    } else if ("it_si_notification".equals(string3)) {
                        SUS.silentUpdateEnable();
                        C0092c.m344b(2);
                    } else if ("it_si_normal".equals(string3)) {
                        SUS.silentUpdateEnable();
                        C0092c.m344b(3);
                    } else if ("it_sdk_autocheck".equals(string3)) {
                        SUS.silentUpdateEnable();
                        C0092c.m344b(4);
                    }
                }
                if (string8 == null || string8.length() <= 0 || !C0092c.m364f(string8)) {
                    z2 = true;
                } else {
                    this.f1500L = Long.valueOf(string8).longValue();
                }
                if (string5 == null || string5.length() <= 0 || !C0092c.m364f(string5)) {
                    z2 = true;
                }
                if (string12 == null || string12.length() <= 0 || !C0092c.m364f(string12)) {
                    z2 = true;
                } else {
                    this.f1523l = string12;
                }
                if (string == null || string.length() <= 0 || !C0092c.m364f(string)) {
                    z2 = true;
                } else {
                    this.f1501M = string;
                }
                if (string6 == null || string6.length() < 0 || string7 == null || string7.length() <= 0 || string9 == null || string9.length() < 0 || string10 == null || string10.length() < 0 || string2 == null || string2.length() < 0 || string4 == null || string4.length() <= 0 || string11 == null || string11.length() <= 0) {
                    z2 = true;
                }
                this.f1497I = URLDecoder.decode(string7);
                this.f1499K = URLDecoder.decode(string10);
                String strDecode2 = URLDecoder.decode(string5);
                strDecode = URLDecoder.decode(string6);
                String strDecode3 = URLDecoder.decode(string9);
                String strDecode4 = URLDecoder.decode(string4);
                String strDecode5 = URLDecoder.decode(string2);
                String strDecode6 = URLDecoder.decode(string11);
                this.f1525n = strDecode2;
                this.f1526o = strDecode;
                this.f1527p = strDecode6;
                if (this.f1501M != null && this.f1501M.length() > 0 && C0092c.m364f(this.f1501M)) {
                    if (C0092c.f1307aK.equals(Integer.valueOf(Integer.valueOf(this.f1501M).intValue() & C0092c.f1307aK.intValue()))) {
                        C0090a.m310a(this.f1514c, true);
                    } else {
                        C0090a.m310a(this.f1514c, false);
                    }
                }
                if (this.f1501M == null || this.f1501M.length() <= 0 || !C0092c.m364f(this.f1501M)) {
                    str2 = strDecode6;
                    str3 = strDecode4;
                    str4 = strDecode5;
                    str5 = strDecode3;
                    str6 = strDecode2;
                    z = z2;
                } else if (C0092c.f1306aJ.equals(Integer.valueOf(Integer.valueOf(this.f1501M).intValue() & C0092c.f1306aJ.intValue()))) {
                    str7 = C0092c.f1337ay;
                    str2 = strDecode6;
                    str3 = strDecode4;
                    str4 = strDecode5;
                    str5 = strDecode3;
                    str6 = strDecode2;
                    z = z2;
                } else {
                    str7 = C0092c.f1297aA;
                    str2 = strDecode6;
                    str3 = strDecode4;
                    str4 = strDecode5;
                    str5 = strDecode3;
                    str6 = strDecode2;
                    z = z2;
                }
            } else if (C0092c.f1289T.equals(string4) || C0092c.f1290U.equals(string4) || C0092c.f1291V.equals(string4)) {
                str2 = null;
                str3 = string4;
                str4 = null;
                str5 = null;
                str6 = null;
                z = false;
            } else {
                str2 = null;
                str3 = string4;
                str4 = null;
                str5 = null;
                str6 = null;
                z = true;
            }
        } catch (JSONException e4) {
            str2 = null;
            str3 = null;
            str4 = null;
            str5 = null;
            str6 = null;
            z = true;
        }
        if (z) {
            C0090a.m311a("ParamException:" + str);
            this.f1503O = this.f1502N;
            C0104ae.m447b();
            if (this.f1503O != null) {
                this.f1503O.onUpdateNotification(EventType.SUS_QUERY_RESP, m501q());
                this.f1503O = null;
                return;
            }
            return;
        }
        C0085a c0085a = new C0085a(String.valueOf(this.f1518g), this.f1519h, str6, strDecode, this.f1497I, Long.valueOf(this.f1500L), str5, str3, str2, this.f1499K, str7, str4);
        if (C0092c.f1288S.equals(c0085a.m284h())) {
            EnumC0088d enumC0088dM519h = m519h();
            int iIntValue = Integer.valueOf(str6).intValue();
            switch (m502v()[this.f1512Y.ordinal()]) {
                case 1:
                    if (EnumC0088d.UPDATEACTION_NEWVERPROMPT == enumC0088dM519h && iIntValue <= m520i() && C0092c.m355d()) {
                        C0090a.m308a();
                        C0104ae.m447b();
                        break;
                    }
                default:
                    if (EnumC0088d.UPDATEACTION_NEWVERPROMPT == enumC0088dM519h && iIntValue > m520i()) {
                        m505a(EnumC0088d.UPDATEACTION_NORMAL.ordinal(), 0);
                    }
                    break;
            }
        }
        if (this.f1502N != null) {
            this.f1502N.onUpdateNotification(EventType.SUS_QUERY_RESP, m496a(c0085a));
        }
        switch (m502v()[this.f1512Y.ordinal()]) {
            case 8:
            case 9:
                this.f1503O = this.f1502N;
                C0104ae.m447b();
                break;
            default:
                if (C0092c.f1288S.equals(c0085a.m284h())) {
                    C0090a.m315c();
                    if (C0092c.m398x() || C0104ae.m459g()) {
                        C0098i.m409a(C0092c.f1339b, "SilentInstall sendEvent SUS_UPDATEPROMPT_USER_CONFIRM");
                        m507a(EventType.SUS_UPDATEPROMPT_USER_CONFIRM);
                    } else {
                        Message message = new Message();
                        if (this.f1515d != null) {
                            message.what = EnumC0086b.m293a(EnumC0086b.SUS_UPDATE_PROMPT_EVENT);
                            message.obj = c0085a;
                            this.f1515d.sendMessage(message);
                        }
                    }
                } else if (!C0092c.f1289T.equals(c0085a.m284h())) {
                    if (C0092c.m351c() && !C0104ae.m457f() && !C0104ae.m459g() && this.f1514c != null && (strM343b = C0092c.m343b(this.f1514c, "SUS_MSG_NOTFOUND")) != null && strM343b.length() > 0) {
                        Toast.makeText(this.f1514c, strM343b, 1).show();
                    }
                    C0098i.m409a(C0092c.f1339b, C0092c.f1290U);
                    C0104ae.m447b();
                } else {
                    if (C0092c.m351c() && !C0104ae.m457f() && !C0104ae.m459g() && this.f1514c != null && (strM343b2 = C0092c.m343b(this.f1514c, "SUS_MSG_LATESTVERSION")) != null && strM343b2.length() > 0) {
                        Toast.makeText(this.f1514c, strM343b2, 1).show();
                    }
                    C0098i.m409a(C0092c.f1339b, C0092c.f1289T);
                    C0104ae.m447b();
                }
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    public void m512a(String str, long j, long j2) {
        this.f1504P = str;
        this.f1505Q = j;
        this.f1506R = j2;
    }

    /* JADX INFO: renamed from: b */
    public void m513b() {
        if (this.f1498J == null || !this.f1498J.exists() || this.f1499K == null) {
            return;
        }
        File file = new File(String.valueOf(this.f1498J.toString()) + CookieSpec.PATH_DELIM + this.f1499K);
        if (file.exists()) {
            file.delete();
        }
    }

    /* JADX INFO: renamed from: c */
    public void m514c() {
        this.f1494F = new C0138z(this.f1515d, this.f1493E);
        if (this.f1494F != null) {
            this.f1494F.start();
        } else {
            C0098i.m411b(C0092c.f1339b, "myReqNewAppVersionThread == null!");
        }
    }

    /* JADX INFO: renamed from: d */
    public boolean m515d() {
        if (this.f1514c == null) {
            C0098i.m411b(C0092c.f1339b, " null == myApplicationContext ");
            return false;
        }
        this.f1518g = C0092c.m357e(this.f1514c);
        if (this.f1518g < 0) {
            System.out.println("VersionCode fail!");
            C0098i.m411b(C0092c.f1339b, "VersionCode fail!");
            return false;
        }
        this.f1519h = C0092c.m362f(this.f1514c);
        if (this.f1519h == null || (this.f1519h != null && this.f1519h.length() == 0)) {
            System.out.println("VersionName is null!");
        }
        this.f1521j = C0092c.m325a(this.f1514c);
        if (this.f1521j != null) {
            this.f1521j.length();
        }
        this.f1528q = C0092c.m365g(this.f1514c);
        if (this.f1528q == null || this.f1528q.length() == 0) {
            System.out.println("PackageName fail!");
            C0098i.m411b(C0092c.f1339b, "PackageName fail!");
            return false;
        }
        String strM348c = C0092c.m348c(this.f1514c);
        this.f1522k = C0092c.m342b(this.f1514c);
        if (this.f1522k == null || (this.f1522k != null && this.f1522k.length() == 0)) {
            this.f1522k = strM348c;
        }
        if (this.f1522k != null && this.f1522k.length() > 0) {
            this.f1522k = this.f1522k.toLowerCase();
        }
        this.f1520i = C0092c.m369h(this.f1514c);
        if (this.f1520i != null && this.f1520i.length() != 0) {
            return true;
        }
        System.out.println("AppName fail!");
        C0098i.m411b(C0092c.f1339b, "AppName fail!");
        return false;
    }

    /* JADX INFO: renamed from: e */
    public boolean m516e() {
        this.f1537z = C0092c.m387p(this.f1514c);
        this.f1530s = C0092c.m389q(this.f1514c);
        this.f1531t = C0092c.m391r(this.f1514c);
        this.f1532u = C0092c.m378l();
        this.f1533v = C0092c.m382n();
        this.f1534w = C0092c.m384o();
        this.f1535x = C0092c.m386p();
        this.f1536y = C0092c.m388q();
        this.f1489A = C0092c.m390r();
        return true;
    }

    /* JADX INFO: renamed from: f */
    public String m517f() {
        this.f1495G = C0092c.m329a(this.f1523l, this.f1528q, String.valueOf(this.f1525n), this.f1526o, this.f1527p, null, null, null, null);
        return this.f1495G;
    }

    /* JADX INFO: renamed from: g */
    public String m518g() {
        switch (m502v()[this.f1512Y.ordinal()]) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 7:
            case 8:
                this.f1493E = C0092c.m324a(2, this.f1520i, this.f1528q, String.valueOf(this.f1518g), this.f1519h, this.f1522k, this.f1529r, this.f1537z, this.f1530s, this.f1531t, this.f1532u, this.f1533v, this.f1534w, this.f1535x, this.f1536y, this.f1489A);
                break;
            case 6:
                this.f1493E = C0092c.m340b(1, this.f1520i, this.f1521j, String.valueOf(this.f1518g), this.f1519h, this.f1522k, this.f1529r, this.f1537z, this.f1530s, this.f1531t, this.f1532u, this.f1533v, this.f1534w, this.f1535x, this.f1536y, this.f1489A);
                break;
            case 12:
                this.f1493E = C0092c.f1292W;
                break;
        }
        if (this.f1493E != null && this.f1493E.length() != 0) {
            C0098i.m409a(C0092c.f1339b, "myReqKey=" + this.f1493E);
            return this.f1493E;
        }
        System.out.println("ReqKey fail!");
        C0098i.m411b(C0092c.f1339b, "ReqKey fail!");
        return null;
    }

    /* JADX INFO: renamed from: h */
    public EnumC0088d m519h() {
        if (this.f1517f == null) {
            this.f1517f = new C0087c();
            if (this.f1514c != null) {
                SharedPreferences sharedPreferences = this.f1514c.getSharedPreferences(C0092c.f1316ad, 0);
                int i = sharedPreferences.getInt(C0092c.f1317ae, 0);
                int i2 = sharedPreferences.getInt(C0092c.f1318af, 0);
                this.f1517f.m301a(i);
                this.f1517f.m304b(i2);
            }
        }
        return this.f1517f.m303b();
    }

    /* JADX INFO: renamed from: i */
    public int m520i() {
        if (this.f1517f == null) {
            return 0;
        }
        return this.f1517f.m305c();
    }

    /* JADX INFO: renamed from: j */
    public String m521j() {
        return this.f1493E;
    }

    /* JADX INFO: renamed from: k */
    public int m522k() {
        return this.f1518g;
    }

    /* JADX INFO: renamed from: l */
    public String m523l() {
        return this.f1520i;
    }

    /* JADX INFO: renamed from: m */
    public C0138z m524m() {
        return this.f1494F;
    }

    /* JADX INFO: renamed from: r */
    public void m525r() {
        f1484X = new C0112an(this.f1515d);
        if (f1484X != null) {
            f1484X.start();
        } else {
            C0098i.m411b(C0092c.f1339b, "startTestSUSServerThread == null!");
        }
    }

    /* JADX INFO: renamed from: s */
    public boolean m526s() {
        if (this.f1514c == null) {
            return false;
        }
        return new Date().after(new Date(this.f1514c.getSharedPreferences(C0092c.f1320ah, 0).getLong(C0092c.f1321ai, 0L) + 86400000));
    }

    /* JADX INFO: renamed from: t */
    public void m527t() {
        SharedPreferences.Editor editorEdit = this.f1514c.getSharedPreferences(C0092c.f1320ah, 0).edit();
        editorEdit.putLong(C0092c.f1321ai, new Date().getTime());
        editorEdit.commit();
    }

    /* JADX INFO: renamed from: u */
    public Context m528u() {
        return this.f1514c;
    }
}
