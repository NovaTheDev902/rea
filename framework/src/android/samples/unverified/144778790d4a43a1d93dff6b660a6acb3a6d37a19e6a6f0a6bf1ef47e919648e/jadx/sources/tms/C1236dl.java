package tms;

import android.bluetooth.BluetoothAdapter;
import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.net.wifi.WifiManager;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.utils.SDKUtil;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;

/* JADX INFO: renamed from: tms.dl */
/* JADX INFO: loaded from: classes.dex */
public final class C1236dl extends BaseManager {

    /* JADX INFO: renamed from: d */
    private Context f7128d;

    /* JADX INFO: renamed from: e */
    private ContentResolver f7129e;

    /* JADX INFO: renamed from: f */
    private TelephonyManager f7130f;

    /* JADX INFO: renamed from: g */
    private WifiManager f7131g;

    /* JADX INFO: renamed from: h */
    private BluetoothAdapter f7132h;

    /* JADX INFO: renamed from: i */
    private ConnectivityManager f7133i;

    /* JADX INFO: renamed from: a */
    private final Uri f7125a = Uri.parse("content://telephony/carriers");

    /* JADX INFO: renamed from: b */
    private final Uri f7126b = Uri.parse("content://telephony/carriers/current");

    /* JADX INFO: renamed from: c */
    private final Uri f7127c = Uri.parse("content://telephony/carriers/preferapn");

    /* JADX INFO: renamed from: j */
    private final String[] f7134j = {"_id", "apn", "type"};

    /* JADX INFO: renamed from: tms.dl$a */
    static final class a {

        /* JADX INFO: renamed from: a */
        public String f7135a;

        /* JADX INFO: renamed from: b */
        public String f7136b;

        /* JADX INFO: renamed from: c */
        public String f7137c;

        /* JADX INFO: renamed from: d */
        public String f7138d;

        a() {
        }
    }

    /* JADX INFO: renamed from: a */
    private static String m3143a(String str, boolean z) {
        if (str == null) {
            return null;
        }
        String strTrim = str.trim().replace("_suffix_apn", "").trim();
        return !z ? strTrim + "_suffix_apn" : strTrim;
    }

    /* JADX INFO: renamed from: b */
    private static boolean m3144b(String str) {
        return str.toLowerCase().endsWith("mms");
    }

    /* JADX INFO: renamed from: d */
    private boolean m3145d(boolean z) {
        if (m3147n() == z) {
            return true;
        }
        try {
            Method declaredMethod = Class.forName(this.f7130f.getClass().getName()).getDeclaredMethod("getITelephony", new Class[0]);
            declaredMethod.setAccessible(true);
            Object objInvoke = declaredMethod.invoke(this.f7130f, new Object[0]);
            Class<?> cls = Class.forName(objInvoke.getClass().getName());
            Method declaredMethod2 = z ? cls.getDeclaredMethod("enableDataConnectivity", new Class[0]) : cls.getDeclaredMethod("disableDataConnectivity", new Class[0]);
            declaredMethod2.setAccessible(true);
            declaredMethod2.invoke(objInvoke, new Object[0]);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /* JADX INFO: renamed from: e */
    private boolean m3146e(boolean z) {
        try {
            this.f7133i.getClass().getMethod("setMobileDataEnabled", Boolean.TYPE).invoke(this.f7133i, new Boolean(z));
            return true;
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return false;
        } catch (NoSuchMethodException e2) {
            e2.printStackTrace();
            return false;
        } catch (SecurityException e3) {
            e3.printStackTrace();
            return false;
        } catch (InvocationTargetException e4) {
            e4.printStackTrace();
            return false;
        }
    }

    /* JADX INFO: renamed from: n */
    private boolean m3147n() {
        return this.f7130f.getDataState() == 2;
    }

    /* JADX INFO: renamed from: o */
    private boolean m3148o() {
        try {
            return ((Boolean) this.f7133i.getClass().getMethod("getMobileDataEnabled", new Class[0]).invoke(this.f7133i, new Object[0])).booleanValue();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return false;
        } catch (NoSuchMethodException e2) {
            e2.printStackTrace();
            return false;
        } catch (SecurityException e3) {
            e3.printStackTrace();
            return false;
        } catch (InvocationTargetException e4) {
            e4.printStackTrace();
            return false;
        }
    }

    /* JADX INFO: renamed from: a */
    public final int m3149a(String str) {
        if (C1218cu.m3074b(str)) {
            return 0;
        }
        return C1218cu.m3075c(str) ? 1 : -1;
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3150a() {
        NetworkInfo activeNetworkInfo = ((ConnectivityManager) this.f7128d.getSystemService("connectivity")).getActiveNetworkInfo();
        return activeNetworkInfo != null && activeNetworkInfo.getType() == 1;
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3151a(int i) {
        if (m3149a(m3164k()) != i && i != -1) {
            String str = i == 0 ? "net" : "wap";
            Cursor cursorQuery = this.f7128d.getContentResolver().query(this.f7125a, new String[]{"_id", "apn", "type", "current"}, null, null, null);
            ArrayList arrayList = new ArrayList();
            if (cursorQuery != null) {
                int columnIndex = cursorQuery.getColumnIndex("_id");
                int columnIndex2 = cursorQuery.getColumnIndex("type");
                int columnIndex3 = cursorQuery.getColumnIndex("current");
                int columnIndex4 = cursorQuery.getColumnIndex("apn");
                if (cursorQuery.moveToFirst()) {
                    while (!cursorQuery.isAfterLast()) {
                        a aVar = new a();
                        aVar.f7135a = cursorQuery.getString(columnIndex);
                        aVar.f7136b = cursorQuery.getString(columnIndex4);
                        aVar.f7137c = cursorQuery.getString(columnIndex2);
                        aVar.f7138d = cursorQuery.getString(columnIndex3);
                        if (aVar.f7138d != null && aVar.f7138d.equals(DatabaseTables.SYSTEM_MARK) && aVar.f7136b != null && aVar.f7136b.endsWith(str) && aVar.f7137c != null && !m3144b(aVar.f7137c)) {
                            arrayList.add(aVar);
                        }
                        cursorQuery.moveToNext();
                    }
                }
                cursorQuery.close();
            }
            if (arrayList.size() > 0) {
                a aVar2 = (a) arrayList.get(0);
                ContentValues contentValues = new ContentValues();
                contentValues.put("apn_id", aVar2.f7135a);
                this.f7129e.update(this.f7127c, contentValues, null, null);
                return true;
            }
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3152a(boolean z) {
        if (this.f7131g == null) {
            return false;
        }
        return this.f7131g.setWifiEnabled(z);
    }

    /* JADX INFO: renamed from: b */
    public final boolean m3153b() {
        if (this.f7131g == null) {
            return false;
        }
        return this.f7131g.isWifiEnabled();
    }

    /* JADX INFO: renamed from: b */
    public final boolean m3154b(boolean z) {
        return SDKUtil.getSDKVersion() > 8 ? m3146e(z) : m3145d(z);
    }

    /* JADX INFO: renamed from: c */
    public final int m3155c() {
        if (this.f7131g == null) {
            return 4;
        }
        return this.f7131g.getWifiState();
    }

    /* JADX INFO: renamed from: c */
    public final boolean m3156c(boolean z) {
        boolean z2 = false;
        Cursor cursorQuery = this.f7129e.query(this.f7126b, this.f7134j, null, null, null);
        if (cursorQuery != null && cursorQuery.moveToFirst()) {
            int columnIndex = cursorQuery.getColumnIndex("_id");
            int columnIndex2 = cursorQuery.getColumnIndex("apn");
            int columnIndex3 = cursorQuery.getColumnIndex("type");
            boolean z3 = false;
            while (!cursorQuery.isAfterLast()) {
                String string = cursorQuery.getString(columnIndex3);
                String string2 = cursorQuery.getString(columnIndex2);
                if (m3144b(string)) {
                    cursorQuery.moveToNext();
                } else {
                    int i = cursorQuery.getInt(columnIndex);
                    ContentValues contentValues = new ContentValues();
                    contentValues.put("apn", m3143a(string2, z));
                    contentValues.put("type", m3143a(string, z));
                    z3 = this.f7129e.update(this.f7126b, contentValues, new StringBuilder().append("_id=").append(i).toString(), null) > 0;
                    cursorQuery.moveToNext();
                }
            }
            z2 = z3;
        }
        if (cursorQuery != null) {
            cursorQuery.close();
        }
        return z2;
    }

    /* JADX INFO: renamed from: d */
    public final int m3157d() {
        if (this.f7131g == null) {
            return -1;
        }
        return this.f7131g.getConnectionInfo().getRssi();
    }

    /* JADX INFO: renamed from: e */
    public final boolean m3158e() {
        if (this.f7132h == null) {
            return false;
        }
        return this.f7132h.isEnabled();
    }

    /* JADX INFO: renamed from: f */
    public final boolean m3159f() {
        if (this.f7132h == null) {
            return false;
        }
        if (this.f7132h.isEnabled()) {
            return true;
        }
        return this.f7132h.enable();
    }

    /* JADX INFO: renamed from: g */
    public final boolean m3160g() {
        if (this.f7132h == null) {
            return false;
        }
        if (this.f7132h.isEnabled()) {
            return this.f7132h.disable();
        }
        return true;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 0;
    }

    /* JADX INFO: renamed from: h */
    public final int m3161h() {
        if (this.f7132h == null) {
            return -1;
        }
        return this.f7132h.getState();
    }

    /* JADX INFO: renamed from: i */
    public final boolean m3162i() {
        return SDKUtil.getSDKVersion() > 8 ? m3148o() : m3147n();
    }

    /* JADX INFO: renamed from: j */
    public final boolean m3163j() {
        NetworkInfo activeNetworkInfo = this.f7133i.getActiveNetworkInfo();
        if (activeNetworkInfo != null) {
            return (activeNetworkInfo.getState() == NetworkInfo.State.CONNECTING || activeNetworkInfo.getState() == NetworkInfo.State.CONNECTED) && activeNetworkInfo.getType() == 0;
        }
        return false;
    }

    /* JADX INFO: renamed from: k */
    public final String m3164k() {
        int columnIndex;
        String strM3073a = null;
        Cursor cursorQuery = this.f7129e.query(this.f7127c, null, null, null, null);
        if (cursorQuery != null && cursorQuery.moveToFirst() && (columnIndex = cursorQuery.getColumnIndex("apn")) != -1) {
            String string = cursorQuery.getString(columnIndex);
            if (!TextUtils.isEmpty(string)) {
                strM3073a = C1218cu.m3073a(string);
            }
        }
        if (cursorQuery != null) {
            cursorQuery.close();
        }
        return strM3073a;
    }

    /* JADX INFO: renamed from: l */
    public final int m3165l() {
        return m3149a(m3164k());
    }

    /* JADX INFO: renamed from: m */
    public final boolean m3166m() {
        boolean z = false;
        Cursor cursorQuery = this.f7129e.query(this.f7126b, this.f7134j, null, null, null);
        if (cursorQuery != null && cursorQuery.moveToFirst()) {
            int columnIndex = cursorQuery.getColumnIndex("type");
            int i = 0;
            while (!cursorQuery.isAfterLast()) {
                String string = cursorQuery.getString(columnIndex);
                if (string != null) {
                    if (string != null && string.endsWith("_suffix_apn")) {
                        break;
                    }
                    if (!m3144b(string)) {
                        i++;
                    }
                    if (i > 0) {
                        z = true;
                        break;
                    }
                    cursorQuery.moveToNext();
                } else {
                    cursorQuery.moveToNext();
                }
            }
        }
        if (cursorQuery != null) {
            cursorQuery.close();
        }
        return z;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7128d = context;
        this.f7129e = this.f7128d.getContentResolver();
        this.f7130f = (TelephonyManager) this.f7128d.getSystemService("phone");
        this.f7131g = (WifiManager) this.f7128d.getSystemService(SettingUtil.WIFI);
        this.f7132h = BluetoothAdapter.getDefaultAdapter();
        this.f7133i = (ConnectivityManager) this.f7128d.getSystemService("connectivity");
    }
}
