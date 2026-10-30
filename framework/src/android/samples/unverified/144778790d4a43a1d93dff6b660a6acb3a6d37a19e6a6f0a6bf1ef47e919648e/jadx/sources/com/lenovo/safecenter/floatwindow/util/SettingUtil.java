package com.lenovo.safecenter.floatwindow.util;

import QQPIM.EModelID;
import QQPIM.ENotifyID;
import android.bluetooth.BluetoothAdapter;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.media.AudioManager;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Bundle;
import android.os.Vibrator;
import android.provider.Settings;
import android.telephony.TelephonyManager;
import com.lenovo.safecenter.floatwindow.view.FloatWindow;
import com.lenovo.safecenter.floatwindow.view.FloatwindowCache;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class SettingUtil {
    public static final String AIRPLANE = "airplane";
    public static final String AUTOROTATE = "autorotate";
    public static final String BLUETOOTH = "bluetooth";
    public static final String BRIGHTNESS = "brightness";
    public static final String CHILD_MODE = "child_mode";
    public static final String DATA = "data";
    public static final String GUEST_MODE = "guest_mode";
    public static final String RINGTONE = "ringtone";
    public static final String TIMEOUT = "timeout";
    public static final String TOUCH_VIBRATOR = "vibrator";
    public static final String VIBRATE = "vibrate";
    public static final String WIFI = "wifi";

    /* JADX INFO: renamed from: d */
    private static String f3583d = null;
    public static boolean isMultiSim;

    /* JADX INFO: renamed from: a */
    private Context f3584a;

    /* JADX INFO: renamed from: b */
    private TelephonyManager f3585b;

    /* JADX INFO: renamed from: c */
    private ConnectivityManager f3586c;

    /* JADX INFO: renamed from: e */
    private SharedPreferences f3587e;

    /* JADX INFO: renamed from: f */
    private AudioManager f3588f;

    /* JADX INFO: renamed from: g */
    private Vibrator f3589g;

    public SettingUtil(Context context) {
        this.f3584a = context;
        if (this.f3586c == null) {
            this.f3586c = (ConnectivityManager) context.getSystemService("connectivity");
        }
        if (this.f3585b == null) {
            this.f3585b = (TelephonyManager) context.getSystemService("phone");
        }
        if (this.f3588f == null) {
            this.f3588f = (AudioManager) context.getSystemService("audio");
        }
        if (this.f3589g == null) {
            this.f3589g = (Vibrator) context.getSystemService(TOUCH_VIBRATOR);
        }
    }

    public int getStatus(String param) {
        int bluetooth_on;
        int brightness;
        int timeout;
        if (param.equals(TIMEOUT)) {
            int timeout2 = Settings.System.getInt(this.f3584a.getContentResolver(), "screen_off_timeout", 0);
            if (timeout2 == -1) {
                timeout = 4;
            } else if (timeout2 <= 30000) {
                timeout = 1;
            } else if (timeout2 <= 60000) {
                timeout = 2;
            } else if (timeout2 <= 120000) {
                timeout = 3;
            } else {
                timeout = 4;
            }
            return timeout;
        }
        if (param.equals(WIFI)) {
            WifiManager wifiManager = (WifiManager) this.f3584a.getSystemService(WIFI);
            return wifiManager.isWifiEnabled() ? 1 : 0;
        }
        if (param.equals(CHILD_MODE)) {
            return Settings.System.getInt(this.f3584a.getContentResolver(), "child_mode_on", 0);
        }
        if (param.equals(GUEST_MODE)) {
            return Settings.System.getInt(this.f3584a.getContentResolver(), "guest_mode_on", 0);
        }
        if (param.equals(BLUETOOTH)) {
            try {
                BluetoothAdapter adapter = BluetoothAdapter.getDefaultAdapter();
                bluetooth_on = adapter.isEnabled() ? 1 : 0;
            } catch (Exception e) {
                bluetooth_on = Settings.System.getInt(this.f3584a.getContentResolver(), "bluetooth_on", 0);
            }
            return bluetooth_on;
        }
        if (param.equals(TOUCH_VIBRATOR)) {
            return Settings.System.getInt(this.f3584a.getContentResolver(), "haptic_feedback_enabled", 0);
        }
        if (param.equals(AUTOROTATE)) {
            return Settings.System.getInt(this.f3584a.getContentResolver(), "accelerometer_rotation", 0);
        }
        if (param.equals(BRIGHTNESS)) {
            int brightness2 = Settings.System.getInt(this.f3584a.getContentResolver(), "screen_brightness", 0);
            int mode = Settings.System.getInt(this.f3584a.getContentResolver(), "screen_brightness_mode", 0);
            if (mode == 1) {
                brightness = 5;
            } else if (brightness2 < 80) {
                brightness = 1;
            } else if (brightness2 < 140) {
                brightness = 2;
            } else if (brightness2 < 200) {
                brightness = 3;
            } else {
                brightness = 4;
            }
            return brightness;
        }
        if (param.equals(AIRPLANE)) {
            return Settings.System.getInt(this.f3584a.getContentResolver(), "airplane_mode_on", 0);
        }
        if (param.equals(DATA)) {
            if (getSimState() && ("Lenovo S880".equals(Build.MODEL) || "Lenovo A60+".equals(Build.MODEL) || "Lenovo A750".equals(Build.MODEL))) {
                ConnectivityManager cm = (ConnectivityManager) this.f3584a.getSystemService("connectivity");
                NetworkInfo ni = cm.getActiveNetworkInfo();
                if (ni != null && "CONNECTED".equals(ni.getState().name())) {
                    return 1;
                }
                return 0;
            }
            if (getSimState()) {
                boolean mobileData = getMobileData();
                return mobileData ? 1 : 0;
            }
            return 0;
        }
        if (param.equals(RINGTONE)) {
            return this.f3588f.getRingerMode() == 2 ? 1 : 0;
        }
        if (param.equals(VIBRATE)) {
            int vibrateFlag = this.f3588f.getVibrateSetting(0);
            if (vibrateFlag != 1 || this.f3588f.getRingerMode() == 0) {
                return 0;
            }
            return 1;
        }
        return 0;
    }

    public boolean getSimState() {
        int airplane_on = Settings.System.getInt(this.f3584a.getContentResolver(), "airplane_mode_on", 0);
        if (airplane_on == 1) {
            return false;
        }
        if (!isMultiSim) {
            return this.f3585b.getSimState() == 5;
        }
        MultiSIMUtils simUtils = new MultiSIMUtils(this.f3584a);
        return simUtils.getSimState(0) == 5 || simUtils.getSimState(1) == 5;
    }

    public boolean isMultiSim() {
        if (f3583d == null) {
            f3583d = "true";
            try {
                Class<?> cls = Class.forName("android.provider.MultiSIMUtils");
                Method method = cls.getMethod("getDefault", Context.class);
                Object invoke = method.invoke(null, this.f3584a);
                Method method2 = cls.getMethod("getPhoneCount", null);
                int cardCount = ((Integer) method2.invoke(invoke, null)).intValue();
                if (cardCount > 1) {
                    isMultiSim = true;
                }
            } catch (ClassNotFoundException e) {
                isMultiSim = false;
            } catch (Exception e2) {
                isMultiSim = false;
            }
            return isMultiSim;
        }
        return isMultiSim;
    }

    public Object invokeMethod(String methodName, Object[] arg) throws Exception {
        Class<?> cls = this.f3586c.getClass();
        Class<?>[] clsArr = null;
        if (arg != null) {
            clsArr = new Class[]{arg.getClass()};
        }
        Method method = cls.getMethod(methodName, clsArr);
        return method.invoke(this.f3586c, arg);
    }

    public boolean getMobileData() {
        try {
            boolean isMobileDataEnable = ((Boolean) invokeMethod("getMobileDataEnabled", null)).booleanValue();
            return isMobileDataEnable;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public void setStatus(String param, int value) {
        int value2;
        if (param.equals(AIRPLANE)) {
            if (value != getStatus(AIRPLANE)) {
                Settings.System.putInt(this.f3584a.getContentResolver(), "airplane_mode_on", value);
                Intent intent = new Intent("android.intent.action.AIRPLANE_MODE");
                intent.putExtra("state", value == 1);
                this.f3584a.sendBroadcast(intent);
                return;
            }
            return;
        }
        if (param.equals(WIFI)) {
            WifiManager wifiManager = (WifiManager) this.f3584a.getSystemService(WIFI);
            if (wifiManager != null) {
                wifiManager.setWifiEnabled(value != 0);
                return;
            }
            return;
        }
        if (param.equals(GUEST_MODE)) {
            FloatWindow.instanceFloatWindow.delFloatWindow();
            Intent it = new Intent("com.lenovo.safecenter.view.DialogActivity");
            if (value == 0) {
                it.putExtra("style", 5);
            } else {
                it.putExtra("style", 4);
            }
            it.setFlags(268435456);
            this.f3584a.startActivity(it);
            return;
        }
        if (param.equals(CHILD_MODE)) {
            FloatWindow.instanceFloatWindow.delFloatWindow();
            Intent childrenActivity = new Intent("com.lenovo.safecenter.view.DialogActivity");
            if (value == 1) {
                childrenActivity.putExtra("style", 1);
            } else {
                childrenActivity.putExtra("style", 2);
            }
            childrenActivity.setFlags(268435456);
            this.f3584a.startActivity(childrenActivity);
            return;
        }
        if (param.equals(BLUETOOTH)) {
            if (value != getStatus(BLUETOOTH)) {
                try {
                    BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
                    if (bluetoothAdapter != null) {
                        if (value == 0) {
                            bluetoothAdapter.disable();
                        } else {
                            bluetoothAdapter.enable();
                        }
                    }
                    return;
                } catch (Exception e) {
                    return;
                }
            }
            return;
        }
        if (param.equals(TOUCH_VIBRATOR)) {
            if (value != getStatus(TOUCH_VIBRATOR)) {
                Settings.System.putInt(this.f3584a.getContentResolver(), "haptic_feedback_enabled", value);
                return;
            }
            return;
        }
        if (param.equals(AUTOROTATE)) {
            if (value != getStatus(AUTOROTATE)) {
                Settings.System.putInt(this.f3584a.getContentResolver(), "accelerometer_rotation", value);
                return;
            }
            return;
        }
        if (param.equals(BRIGHTNESS)) {
            boolean auto = false;
            switch (value) {
                case 1:
                    value = 64;
                    break;
                case 2:
                    value = 127;
                    break;
                case 3:
                    value = 190;
                    break;
                case 4:
                    value = 255;
                    break;
                case 5:
                    auto = true;
                    break;
                default:
                    value = 60;
                    break;
            }
            Intent intent2 = new Intent();
            intent2.setClass(this.f3584a, FloatwindowCache.class);
            intent2.setFlags(ENotifyID._ENID_END);
            intent2.setFlags(268435456);
            Bundle mBundle = new Bundle();
            mBundle.putBoolean("autoFlag", auto);
            mBundle.putInt("value", value);
            intent2.putExtras(mBundle);
            this.f3584a.startActivity(intent2);
            return;
        }
        if (param.equals(TIMEOUT)) {
            switch (value) {
                case 1:
                    value2 = EModelID._EMID_QQPim_Begin;
                    break;
                case 2:
                    value2 = 60000;
                    break;
                case 3:
                    value2 = 120000;
                    break;
                case 4:
                    value2 = 600000;
                    break;
                default:
                    value2 = EModelID._EMID_QQPim_Begin;
                    break;
            }
            Settings.System.putInt(this.f3584a.getContentResolver(), "screen_off_timeout", value2);
            return;
        }
        if (param.equals(DATA)) {
            if (isMultiSim()) {
                MultiSIMUtils utils = new MultiSIMUtils(this.f3584a);
                if ("qualcomm".equals(utils.getPlatform())) {
                    if (value == 0) {
                        setMobileData(false);
                        return;
                    }
                    String dataSubscriberId = utils.getDataSubscriberId();
                    if (dataSubscriberId != null) {
                        if (dataSubscriberId.equals(utils.getSubscriberId(0)) && utils.getSimState(0) == 5) {
                            setMobileData(true);
                            return;
                        } else {
                            if (dataSubscriberId.equals(utils.getSubscriberId(1)) && utils.getSimState(1) == 5) {
                                setMobileData(true);
                                return;
                            }
                            return;
                        }
                    }
                    return;
                }
                Intent intent3 = new Intent("android.intent.action.DATA_DEFAULT_SIM");
                if (value == 0) {
                    intent3.putExtra("simid", Long.parseLong("0"));
                    this.f3584a.sendBroadcast(intent3);
                    return;
                }
                long dataSimId = getDefaultDataSimId();
                if (dataSimId != -1) {
                    intent3.putExtra("simid", dataSimId);
                    this.f3584a.sendBroadcast(intent3);
                    return;
                }
                return;
            }
            setMobileData(value == 1);
            return;
        }
        if (param.equals(RINGTONE)) {
            if (value != getStatus(RINGTONE)) {
                if (value == 1) {
                    this.f3588f.setRingerMode(2);
                    return;
                } else if (getStatus(VIBRATE) == 1) {
                    this.f3588f.setRingerMode(1);
                    return;
                } else {
                    this.f3588f.setRingerMode(0);
                    return;
                }
            }
            return;
        }
        if (param.equals(VIBRATE) && value != getStatus(VIBRATE)) {
            if (value == 1) {
                this.f3588f.setVibrateSetting(0, 1);
                if (getStatus(RINGTONE) == 1) {
                    this.f3588f.setRingerMode(2);
                } else {
                    this.f3588f.setRingerMode(1);
                }
                this.f3589g.vibrate(new long[]{500, 500, 1000}, -1);
                return;
            }
            this.f3588f.setVibrateSetting(0, 0);
            if (getStatus(RINGTONE) == 1) {
                this.f3588f.setRingerMode(2);
            } else {
                this.f3588f.setRingerMode(0);
            }
        }
    }

    public Object invokeBooleanArgMethod(String methodName, boolean value) throws Exception {
        Method method = this.f3586c.getClass().getMethod(methodName, Boolean.TYPE);
        return method.invoke(this.f3586c, Boolean.valueOf(value));
    }

    public void setMobileData(boolean bool) {
        try {
            invokeBooleanArgMethod("setMobileDataEnabled", bool);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public long getDefaultDataSimId() {
        this.f3587e = this.f3584a.getSharedPreferences(Constants.DATASUBSCRIBERID, 32768);
        return this.f3587e.getLong(Constants.DATASUBSCRIBERID, -1L);
    }

    public long getDataSimId() {
        try {
            Class<?> cls = Class.forName("android.provider.Telephony$SIMInfo");
            Method method = cls.getMethod("getInsertedSIMList", Context.class);
            List simList = (List) method.invoke(null, this.f3584a);
            if (simList.size() == 0) {
                return -1L;
            }
            if (simList.size() == 1) {
                Iterator iterator = simList.iterator();
                if (iterator.hasNext()) {
                    Object next = iterator.next();
                    Field simId = cls.getField("mSimId");
                    return ((Long) simId.get(next)).longValue();
                }
            } else {
                int simSlot = -1;
                MultiSIMUtils simUtils = new MultiSIMUtils(this.f3584a);
                String dataSubscriberId = simUtils.getDataSubscriberId();
                if (dataSubscriberId == null) {
                    int status = simUtils.getSimState(0);
                    if (status == 5) {
                        simSlot = 0;
                    } else {
                        int status2 = simUtils.getSimState(1);
                        if (status2 == 5) {
                            simSlot = 1;
                        }
                    }
                } else {
                    String subscriberId0 = simUtils.getSubscriberId(0);
                    String subscriberId1 = simUtils.getSubscriberId(1);
                    if (dataSubscriberId.endsWith(subscriberId0)) {
                        simSlot = 0;
                    } else if (dataSubscriberId.endsWith(subscriberId1)) {
                        simSlot = 1;
                    }
                }
                for (Object next2 : simList) {
                    next2.getClass();
                    Field slot = cls.getField("mSlot");
                    int mSlot = ((Integer) slot.get(next2)).intValue();
                    if (mSlot == simSlot) {
                        Field simId2 = cls.getField("mSimId");
                        return ((Long) simId2.get(next2)).longValue();
                    }
                }
            }
            return -1L;
        } catch (Exception e) {
        }
    }

    public boolean getQualcommSimState() {
        MultiSIMUtils utils = new MultiSIMUtils(this.f3584a);
        String dataSubscriberId = utils.getDataSubscriberId();
        if (dataSubscriberId != null) {
            if (dataSubscriberId.equals(utils.getSubscriberId(0)) && utils.getSimState(0) == 5) {
                return true;
            }
            if (dataSubscriberId.equals(utils.getSubscriberId(1)) && utils.getSimState(1) == 5) {
                return true;
            }
        }
        return false;
    }
}
