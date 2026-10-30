package com.lenovo.safecenter.systeminfo.service;

import android.content.pm.PackageManager;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.os.PowerManager;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class SensorInfoService {

    /* JADX INFO: renamed from: a */
    private static final String f5632a = SensorInfoService.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static SensorInfoService f5633b = null;

    /* JADX INFO: renamed from: c */
    private SensorManager f5634c;

    private SensorInfoService() {
    }

    public static SensorInfoService getInstance() {
        if (f5633b == null) {
            synchronized (SensorInfoService.class) {
                f5633b = new SensorInfoService();
            }
        }
        return f5633b;
    }

    public boolean suppert(int sensorType) {
        if (this.f5634c == null) {
            this.f5634c = (SensorManager) Const.mContext.getSystemService("sensor");
        }
        List<Sensor> sensors = this.f5634c.getSensorList(sensorType);
        return sensors != null && sensors.size() > 0;
    }

    public boolean suppert(String sensorType) {
        PackageManager pm = Const.mContext.getPackageManager();
        boolean support = pm.hasSystemFeature(sensorType);
        return support;
    }

    public String sensorInfo() {
        PowerManager pm = (PowerManager) Const.mContext.getSystemService("power");
        PowerManager.WakeLock lock = pm.newWakeLock(536870922, f5632a);
        lock.acquire();
        StringBuffer buffer = new StringBuffer();
        buffer.append(Const.mContext.getString(C0415R.string.senor_ori)).append(suppert(3) ? "支持" : "不支持").append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.senor_acc)).append(suppert(1) ? "支持" : "不支持").append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.senor_lig)).append(suppert(5) ? "支持" : "不支持").append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.senor_fil)).append(suppert(2) ? "支持" : "不支持").append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.senor_pro)).append(suppert(8) ? "支持" : "不支持").append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.senor_gyr)).append(suppert(4) ? "支持" : "不支持").append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.senor_tem)).append(suppert(7) ? "支持" : "不支持");
        lock.release();
        return buffer.toString();
    }
}
