package com.lenovo.safecenter.platform;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Build;
import android.os.Handler;
import android.os.Message;
import android.provider.MultiSIMUtils;
import android.provider.Settings;
import android.telephony.TelephonyManager;
import android.util.Log;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.DaoImpl;
import com.lenovo.safecenter.adapter.DbAdapter;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.utils.AlarmManageUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.WflUtils;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: loaded from: classes.dex */
public class BootBroadcast extends BroadcastReceiver {

    /* JADX INFO: renamed from: b */
    private static Context f4927b;
    public static boolean ignorePlaneMode = true;

    /* JADX INFO: renamed from: j */
    private static Handler f4928j = new Handler() { // from class: com.lenovo.safecenter.platform.BootBroadcast.3
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    MyUtils.lockedScreen(BootBroadcast.f4927b, null);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    private SharedPreferences f4929a;

    /* JADX INFO: renamed from: c */
    private String f4930c;

    /* JADX INFO: renamed from: g */
    private DaoImpl f4934g;

    /* JADX INFO: renamed from: d */
    private String f4931d = null;

    /* JADX INFO: renamed from: e */
    private String f4932e = null;

    /* JADX INFO: renamed from: f */
    private String f4933f = null;

    /* JADX INFO: renamed from: h */
    private boolean f4935h = true;

    /* JADX INFO: renamed from: i */
    private boolean f4936i = true;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2038a(BootBroadcast x0, Context x1) {
        try {
            String string = Settings.System.getString(x1.getContentResolver(), "old_input");
            if (Settings.Secure.getString(x1.getContentResolver(), "default_input_method").equals("com.android.inputmethod.latin/.LatinIME") && string != null && !string.equals("")) {
                Settings.Secure.putString(x1.getContentResolver(), "default_input_method", string);
            }
        } catch (Exception e) {
            Log.e("ydp", "safeinput error" + e);
        }
        if (x0.f4929a.getBoolean(Const.KEY_IS_PROTECT_THIEF_ON, false)) {
            if (x0.f4929a.getBoolean("all", false) || x0.f4929a.getBoolean("locked", false)) {
                f4928j.sendEmptyMessage(1);
            }
            if (x0.f4929a.getBoolean("all", false) || x0.f4929a.getBoolean("alarm", false)) {
                Log.e("ydp", "all or alarm :" + x0.f4929a.getBoolean("all", false) + "  " + x0.f4929a.getBoolean("alarm", false));
                MyUtils.alarming(x1);
            }
        }
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ void m2041b(BootBroadcast x0, Context x1) {
        if (x0.f4929a.getBoolean(Const.KEY_IS_PROTECT_THIEF_ON, false)) {
            f4927b = x1;
            Log.e("test", "==============>checking SIM");
            if (!MyMultiSIMUtils.isMultiSim(x1)) {
                Log.e("test", "==============>checking SIM one Sim");
                TelephonyManager telephonyManager = (TelephonyManager) x1.getSystemService("phone");
                int simState = telephonyManager.getSimState();
                Log.e("test", "Sim State: " + simState);
                if (simState != 5 || m2039a(x1)) {
                    return;
                }
                Log.e("test", "SIM_STATE_READY");
                if (ignorePlaneMode) {
                    ignorePlaneMode = false;
                    String string = x0.f4929a.getString("ORG_SIM_NUMBER", "");
                    if (string == null || string.length() == 0) {
                        return;
                    }
                    while (true) {
                        if (x0.f4931d != null && !"".equals(x0.f4931d)) {
                            break;
                        }
                        x0.f4931d = telephonyManager.getSubscriberId();
                        Log.e("test", "......" + x0.f4931d);
                    }
                    if (x0.f4931d.equals(string)) {
                        return;
                    }
                    x0.m2040b();
                    return;
                }
                return;
            }
            Log.e("test", "==============>checking SIM MultiSim");
            String string2 = x0.f4929a.getString("ORG_SIM_NUMBER1", "");
            String string3 = x0.f4929a.getString("ORG_SIM_NUMBER2", "");
            int[] allSimState = MyMultiSIMUtils.getAllSimState(x1);
            int i = allSimState[0];
            int i2 = allSimState[1];
            Log.i("test", "sim1:" + i + "  sim2:" + i2);
            boolean z = i == 5;
            boolean z2 = i2 == 5;
            if ((z || z2) && !m2039a(x1) && ignorePlaneMode) {
                ignorePlaneMode = false;
                Log.i("boot", "boot  sim0" + i + "sim1" + i2);
                x0.f4932e = m2037a(0, z);
                x0.f4933f = m2037a(1, z2);
                Log.e("test", "orgSimSerialNumber1:" + string2);
                Log.e("test", "orgSimSerialNumber2:" + string3);
                Log.e("test", "simSerialNumber1:" + x0.f4932e);
                Log.e("test", "simSerialNumber2:" + x0.f4933f);
                if ((string2.equals(x0.f4932e) || string3.equals(x0.f4932e) || x0.f4932e.equals("no card")) && (string2.equals(x0.f4933f) || string3.equals(x0.f4933f) || x0.f4933f.equals("no card"))) {
                    return;
                }
                x0.m2040b();
            }
        }
    }

    /* JADX WARN: Type inference failed for: r0v8, types: [com.lenovo.safecenter.platform.BootBroadcast$2] */
    /* JADX WARN: Type inference failed for: r0v9, types: [com.lenovo.safecenter.platform.BootBroadcast$1] */
    @Override // android.content.BroadcastReceiver
    public void onReceive(final Context context, Intent intent) {
        f4927b = context;
        this.f4929a = context.getSharedPreferences("antitheft", 0);
        if (intent.getAction().equals("android.intent.action.BOOT_COMPLETED")) {
            AlarmManageUtils.noticeUpdateLab(context);
            WflUtils.registerContentObserver(context);
            new Thread() { // from class: com.lenovo.safecenter.platform.BootBroadcast.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    BootBroadcast.m2038a(BootBroadcast.this, context);
                    if (Build.VERSION.SDK_INT >= 14) {
                        BootBroadcast.this.f4934g = new DaoImpl(new DbAdapter(context));
                        if (BootBroadcast.this.f4934g.queryCount() <= 0) {
                            Log.e("ydp", "create sayment database!!");
                            InputStream is = context.getResources().openRawResource(C0415R.raw.data_1);
                            try {
                                FileOutputStream fos = new FileOutputStream("/data/data/com.lenovo.safecenter/databases/safepayment.db", false);
                                byte[] buffer = new byte[is.available()];
                                is.read(buffer);
                                fos.write(buffer);
                                fos.close();
                                is.close();
                            } catch (FileNotFoundException e) {
                                e.printStackTrace();
                            } catch (IOException e2) {
                                e2.printStackTrace();
                            }
                        }
                    }
                }
            }.start();
        }
        if (intent.getAction().equals("android.intent.action.SIM_STATE_CHANGED") && this.f4929a.getBoolean("simchanged", true)) {
            new Thread() { // from class: com.lenovo.safecenter.platform.BootBroadcast.2
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    BootBroadcast.m2041b(BootBroadcast.this, context);
                }
            }.start();
        }
    }

    /* JADX INFO: renamed from: a */
    private static String m2037a(int id, boolean state) {
        if (!state) {
            return "no card";
        }
        String number = MultiSIMUtils.getDefault(f4927b).getSubscriberId(id);
        while (true) {
            if (number == null || "".equals(number)) {
                number = MultiSIMUtils.getDefault(f4927b).getSubscriberId(id);
                if (MultiSIMUtils.getDefault(f4927b).getSimState(id) == 1) {
                    return "no card";
                }
                Log.e("test", "......get sim " + id + ": " + number);
            } else {
                return number;
            }
        }
    }

    /* JADX INFO: renamed from: b */
    private void m2040b() {
        Log.e("test", "sendMsgAndLockScreen");
        if (this.f4929a.getBoolean("sim_alarm_screen", false)) {
            Log.i("ydp", "locked screen");
            f4928j.sendEmptyMessage(1);
        } else {
            Log.e("test", "SIM SAFE");
        }
        if (this.f4929a.getBoolean("sim_alarm_sms", false)) {
            Log.i("ydp", "sim_alarm_sms");
            this.f4930c = Const.getSafePhoneNumber();
            Intent it = new Intent("com.lenovo.antitheft.SENDMESSAGE");
            it.putExtra(PushReceiver.PHONE_NUMBER, this.f4930c);
            it.putExtra(DatabaseTables.LOG_MESSAGE, f4927b.getString(C0415R.string.simSerialNumber_changed) + PwdUtil.getPasswordWithJieMi(f4927b) + f4927b.getString(C0415R.string.command_content));
            it.putExtra("type", 500);
            f4927b.startService(it);
        }
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2039a(Context context) {
        return Settings.System.getInt(context.getContentResolver(), "airplane_mode_on", 0) != 0;
    }
}
