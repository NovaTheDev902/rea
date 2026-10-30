package tms;

import android.content.Context;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;
import com.tencent.tmsecure.module.powersaving.IBatteryInfoHelper;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/* JADX INFO: renamed from: tms.et */
/* JADX INFO: loaded from: classes.dex */
final class C1271et implements IBatteryInfoHelper {

    /* JADX INFO: renamed from: a */
    private Class<?> f7283a;

    /* JADX INFO: renamed from: b */
    private Object f7284b;

    /* JADX INFO: renamed from: c */
    private Method f7285c;

    /* JADX INFO: renamed from: d */
    private Context f7286d;

    C1271et(Context context) {
        try {
            this.f7286d = context;
            this.f7283a = Class.forName("com.android.internal.os.PowerProfile");
            this.f7285c = this.f7283a.getDeclaredMethod("getAveragePower", String.class);
            this.f7284b = this.f7283a.getConstructor(Context.class).newInstance(context);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e2) {
            e2.printStackTrace();
        } catch (IllegalArgumentException e3) {
            e3.printStackTrace();
        } catch (InstantiationException e4) {
            e4.printStackTrace();
        } catch (NoSuchMethodException e5) {
            e5.printStackTrace();
        } catch (InvocationTargetException e6) {
            e6.printStackTrace();
        } catch (Exception e7) {
            e7.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: a */
    private double m3269a() {
        double d;
        Exception exc;
        double d2;
        InvocationTargetException invocationTargetException;
        double d3;
        IllegalArgumentException illegalArgumentException;
        double d4;
        IllegalAccessException illegalAccessException;
        try {
            NetSettingManager netSettingManager = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
            double dDoubleValue = netSettingManager.isWifiEnabled() ? 0.0d + (((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_WIFI_ACTIVE"))).doubleValue() / 4.0d) : 0.0d;
            try {
                return netSettingManager.isBluetoothEnabled() ? dDoubleValue + ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_BLUETOOTH_ACTIVE"))).doubleValue() : dDoubleValue;
            } catch (IllegalAccessException e) {
                d4 = dDoubleValue;
                illegalAccessException = e;
                illegalAccessException.printStackTrace();
                return d4;
            } catch (IllegalArgumentException e2) {
                d3 = dDoubleValue;
                illegalArgumentException = e2;
                illegalArgumentException.printStackTrace();
                return d3;
            } catch (InvocationTargetException e3) {
                d2 = dDoubleValue;
                invocationTargetException = e3;
                invocationTargetException.printStackTrace();
                return d2;
            } catch (Exception e4) {
                d = dDoubleValue;
                exc = e4;
                exc.printStackTrace();
                return d;
            }
        } catch (IllegalAccessException e5) {
            d4 = 0.0d;
            illegalAccessException = e5;
        } catch (IllegalArgumentException e6) {
            d3 = 0.0d;
            illegalArgumentException = e6;
        } catch (InvocationTargetException e7) {
            d2 = 0.0d;
            invocationTargetException = e7;
        } catch (Exception e8) {
            d = 0.0d;
            exc = e8;
        }
    }

    @Override // com.tencent.tmsecure.module.powersaving.IBatteryInfoHelper
    public final double getCallRemainHours() {
        try {
            return ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_BATTERY_CAPACITY"))).doubleValue() / (((((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_NONE"))).doubleValue() + ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_RADIO_ACTIVE"))).doubleValue()) + ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_CPU_ACTIVE"))).doubleValue()) + m3269a());
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return 0.0d;
        } catch (IllegalArgumentException e2) {
            e2.printStackTrace();
            return 0.0d;
        } catch (InvocationTargetException e3) {
            e3.printStackTrace();
            return 0.0d;
        } catch (Exception e4) {
            e4.printStackTrace();
            return 0.0d;
        }
    }

    @Override // com.tencent.tmsecure.module.powersaving.IBatteryInfoHelper
    public final double getContinueRemainHours() {
        try {
            return ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_BATTERY_CAPACITY"))).doubleValue() / (((((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_NONE"))).doubleValue() + (((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_CPU_ACTIVE"))).doubleValue() / 3.0d)) + (((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_SCREEN_FULL"))).doubleValue() * ((double) C1328n.m3528b(this.f7286d.getContentResolver())))) + m3269a());
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return 0.0d;
        } catch (IllegalArgumentException e2) {
            e2.printStackTrace();
            return 0.0d;
        } catch (InvocationTargetException e3) {
            e3.printStackTrace();
            return 0.0d;
        } catch (Exception e4) {
            e4.printStackTrace();
            return 0.0d;
        }
    }

    @Override // com.tencent.tmsecure.module.powersaving.IBatteryInfoHelper
    public final double getMaxPowerUseHours() {
        double dDoubleValue = 0.0d;
        try {
            dDoubleValue = ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_NONE"))).doubleValue() + (((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_CPU_ACTIVE"))).doubleValue() / 3.0d) + (((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_SCREEN_FULL"))).doubleValue() * ((double) C1328n.m3528b(this.f7286d.getContentResolver()))) + (((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_WIFI_ACTIVE"))).doubleValue() / 4.0d) + ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_BLUETOOTH_ACTIVE"))).doubleValue() + ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_GPS_ON"))).doubleValue();
            return ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_BATTERY_CAPACITY"))).doubleValue() / dDoubleValue;
        } catch (IllegalAccessException e) {
            double d = dDoubleValue;
            e.printStackTrace();
            return d;
        } catch (IllegalArgumentException e2) {
            double d2 = dDoubleValue;
            e2.printStackTrace();
            return d2;
        } catch (InvocationTargetException e3) {
            double d3 = dDoubleValue;
            e3.printStackTrace();
            return d3;
        } catch (Exception e4) {
            double d4 = dDoubleValue;
            e4.printStackTrace();
            return d4;
        }
    }

    @Override // com.tencent.tmsecure.module.powersaving.IBatteryInfoHelper
    public final double getStayRemainHours() {
        try {
            return ((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_BATTERY_CAPACITY"))).doubleValue() / (((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_NONE"))).doubleValue() + (((Double) this.f7285c.invoke(this.f7284b, C1151ah.m2900a("com.android.internal.os.PowerProfile", "POWER_CPU_ACTIVE"))).doubleValue() / 3.0d));
        } catch (IllegalAccessException e) {
            e.printStackTrace();
            return 0.0d;
        } catch (IllegalArgumentException e2) {
            e2.printStackTrace();
            return 0.0d;
        } catch (InvocationTargetException e3) {
            e3.printStackTrace();
            return 0.0d;
        } catch (Exception e4) {
            e4.printStackTrace();
            return 0.0d;
        }
    }
}
