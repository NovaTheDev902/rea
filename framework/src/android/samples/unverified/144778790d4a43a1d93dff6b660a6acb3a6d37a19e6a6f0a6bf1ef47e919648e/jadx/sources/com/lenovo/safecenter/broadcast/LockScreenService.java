package com.lenovo.safecenter.broadcast;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.os.PowerManager;
import android.provider.MultiSIMUtils;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.PwdUtil;

/* JADX INFO: loaded from: classes.dex */
public class LockScreenService extends Service {

    /* JADX INFO: renamed from: a */
    static TextView f3419a;

    /* JADX INFO: renamed from: b */
    static EditText f3420b;

    /* JADX INFO: renamed from: c */
    static TextView f3421c;

    /* JADX INFO: renamed from: d */
    static WindowManager.LayoutParams f3422d;

    /* JADX INFO: renamed from: e */
    static WindowManager f3423e;

    /* JADX INFO: renamed from: f */
    static View f3424f;

    /* JADX INFO: renamed from: g */
    static LayoutInflater f3425g;

    /* JADX INFO: renamed from: h */
    static SharedPreferences f3426h;

    /* JADX INFO: renamed from: i */
    static boolean f3427i = true;

    /* JADX INFO: renamed from: j */
    private static PowerManager f3428j;

    /* JADX INFO: renamed from: k */
    private static PowerManager.WakeLock f3429k;

    /* JADX INFO: renamed from: l */
    private Handler f3430l = new Handler() { // from class: com.lenovo.safecenter.broadcast.LockScreenService.2
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    LockScreenService.f3423e.addView(LockScreenService.f3424f, LockScreenService.f3422d);
                    LockScreenService.f3421c.setClickable(true);
                    break;
                case 2:
                    try {
                        InputMethodManager imm = (InputMethodManager) LockScreenService.this.getSystemService("input_method");
                        imm.hideSoftInputFromWindow(LockScreenService.f3420b.getWindowToken(), 0);
                        LockScreenService.f3423e.removeView(LockScreenService.f3424f);
                        LockScreenService.f3427i = true;
                        LockScreenService.f3421c.setClickable(true);
                    } catch (Exception e) {
                        Log.i("test", "remove view error :" + e);
                        return;
                    }
                    break;
            }
        }
    };

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override // android.app.Service
    public int onStartCommand(Intent intent, int flags, int startId) {
        String phoneNumber = intent.getStringExtra("phonenumber");
        if (!MyUtils.isLocked) {
            f3425g = LayoutInflater.from(this);
            f3424f = f3425g.inflate(C0415R.layout.lockedscreen, (ViewGroup) null);
            f3419a = (TextView) f3424f.findViewById(C0415R.id.lockedscreen_tv);
            f3420b = (EditText) f3424f.findViewById(C0415R.id.lockedscreen_pwd);
            f3421c = (TextView) f3424f.findViewById(C0415R.id.lockedscreen_login);
            f3428j = (PowerManager) getSystemService("power");
            f3429k = f3428j.newWakeLock(10, "BackLight");
            f3426h = getSharedPreferences("antitheft", 0);
            f3423e = (WindowManager) getSystemService("window");
            f3422d = new WindowManager.LayoutParams(2010, 256);
            f3422d.width = -1;
            f3422d.height = -1;
            f3422d.screenOrientation = 1;
            f3420b.setFocusable(true);
            f3420b.setFocusableInTouchMode(true);
            f3421c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.broadcast.LockScreenService.1
                /* JADX WARN: Type inference failed for: r0v25, types: [com.lenovo.safecenter.broadcast.LockScreenService$1$1] */
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (PwdUtil.checkPassword(LockScreenService.this.getApplicationContext(), LockScreenService.f3420b.getText().toString())) {
                        LockScreenService.f3421c.setClickable(false);
                        if (LockScreenService.f3427i) {
                            LockScreenService.f3427i = false;
                            Log.i("test", "lockscreen onclick");
                            LockScreenService.this.stopService(new Intent("com.lenovo.antitheft.ALARM"));
                            LockScreenService.f3426h.edit().putBoolean("all", false).commit();
                            LockScreenService.f3426h.edit().putBoolean("locked", false).commit();
                            LockScreenService.f3426h.edit().putBoolean("alarm", false).commit();
                            LockScreenService.f3426h.edit().putBoolean("sim_changed_locked_screen", false).commit();
                            MyUtils.isLocked = false;
                            LockScreenService.this.f3430l.sendEmptyMessage(2);
                            if (LockScreenService.f3429k != null) {
                                LockScreenService.f3429k.release();
                            }
                            new Thread() { // from class: com.lenovo.safecenter.broadcast.LockScreenService.1.1
                                @Override // java.lang.Thread, java.lang.Runnable
                                public final void run() {
                                    if (MyMultiSIMUtils.isMultiSim(LockScreenService.this)) {
                                        int[] states = MyMultiSIMUtils.getAllSimState(LockScreenService.this);
                                        int simState0 = states[0];
                                        int simState1 = states[1];
                                        boolean sim1Ready = simState0 == 5 || simState0 == 2 || simState0 == 3;
                                        boolean sim2Ready = simState1 == 5 || simState1 == 2 || simState1 == 3;
                                        String simSerialNumber1 = LockScreenService.this.getSimSerialNumber(0, sim1Ready, LockScreenService.this);
                                        String simSerialNumber2 = LockScreenService.this.getSimSerialNumber(1, sim2Ready, LockScreenService.this);
                                        if (simSerialNumber1 != null) {
                                            LockScreenService.f3426h.edit().putString("ORG_SIM_NUMBER1", simSerialNumber1).commit();
                                        } else {
                                            LockScreenService.f3426h.edit().putString("ORG_SIM_NUMBER1", "").commit();
                                        }
                                        if (simSerialNumber2 != null) {
                                            LockScreenService.f3426h.edit().putString("ORG_SIM_NUMBER2", simSerialNumber2).commit();
                                        } else {
                                            LockScreenService.f3426h.edit().putString("ORG_SIM_NUMBER2", "").commit();
                                        }
                                    } else {
                                        TelephonyManager mTelephonyMgr = (TelephonyManager) LockScreenService.this.getSystemService("phone");
                                        int SimState = mTelephonyMgr.getSimState();
                                        if (SimState == 5 || SimState == 2 || SimState == 3) {
                                            String simSerialNumber = null;
                                            while (simSerialNumber == null) {
                                                simSerialNumber = mTelephonyMgr.getSubscriberId();
                                                Log.e("test", "......" + simSerialNumber);
                                            }
                                            LockScreenService.f3426h.edit().putString("ORG_SIM_NUMBER", simSerialNumber).commit();
                                        }
                                    }
                                    LockScreenService.this.stopSelf();
                                }
                            }.start();
                            return;
                        }
                        return;
                    }
                    LockScreenService.f3420b.setText("");
                    LockScreenService.f3419a.setText(C0415R.string.pwd_error_tips);
                    LockScreenService.f3419a.setTextColor(-65536);
                }
            });
            if (f3429k != null) {
                f3429k.acquire();
            }
            this.f3430l.sendEmptyMessage(1);
            MyUtils.isLocked = true;
        }
        if (phoneNumber != null && !phoneNumber.equals("")) {
            MyUtils.sendMsgToSafeNumber(this, phoneNumber, getString(C0415R.string.lock_screen_ok) + getString(C0415R.string.from_lesecurity));
        }
        return super.onStartCommand(intent, flags, startId);
    }

    public String getSimSerialNumber(int id, boolean state, Context context) {
        if (!state) {
            return null;
        }
        String number = MultiSIMUtils.getDefault(context).getSubscriberId(id);
        while (true) {
            if (number == null || "".equals(number)) {
                number = MultiSIMUtils.getDefault(context).getSubscriberId(id);
                Log.e("test", "......get sim " + id + ": " + number);
            } else {
                return number;
            }
        }
    }
}
