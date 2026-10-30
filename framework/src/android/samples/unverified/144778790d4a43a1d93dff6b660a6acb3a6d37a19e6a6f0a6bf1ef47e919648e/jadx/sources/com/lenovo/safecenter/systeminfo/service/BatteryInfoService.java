package com.lenovo.safecenter.systeminfo.service;

import android.content.Context;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.systeminfo.util.BatteryUtil;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class BatteryInfoService {

    /* JADX INFO: renamed from: a */
    private static final String f5615a = BatteryInfoService.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static BatteryInfoService f5616b = null;

    private BatteryInfoService() {
    }

    public static BatteryInfoService getInstance() {
        if (f5616b == null) {
            synchronized (BatteryInfoService.class) {
                f5616b = new BatteryInfoService();
            }
        }
        return f5616b;
    }

    public int getCapacity() {
        int capacity = Integer.parseInt(m2301a("/sys/class/power_supply/battery/capacity"));
        return capacity;
    }

    public String getBatteryType() {
        return m2301a("/sys/class/power_supply/battery/technology");
    }

    public int getVoltage() throws Throwable {
        String resultString = m2301a("/sys/class/power_supply/battery/voltage_now");
        if (resultString == null || "".equals(resultString)) {
            return 0;
        }
        return Integer.parseInt(resultString);
    }

    public int getCurrent() throws Throwable {
        String resultString = m2301a("/sys/class/power_supply/battery/current_now");
        if (resultString == null || "".equals(resultString)) {
            return 0;
        }
        return Integer.parseInt(resultString);
    }

    public int getTemperature() throws Throwable {
        String resultString = m2301a("/sys/class/power_supply/battery/temp");
        if (resultString == null || "".equals(resultString)) {
            return 0;
        }
        return Integer.parseInt(resultString);
    }

    /* JADX INFO: renamed from: a */
    private static String m2301a(String path) throws Throwable {
        File file = new File(path);
        FileReader fReader = null;
        BufferedReader bReader = null;
        String resultString = null;
        try {
            try {
                if (file.exists()) {
                    FileReader fReader2 = new FileReader(file);
                    try {
                        BufferedReader bReader2 = new BufferedReader(fReader2);
                        try {
                            resultString = bReader2.readLine();
                            bReader = bReader2;
                            fReader = fReader2;
                        } catch (FileNotFoundException e) {
                            e = e;
                            bReader = bReader2;
                            fReader = fReader2;
                            Log.e(f5615a, e.getMessage());
                            if (bReader != null) {
                                try {
                                    bReader.close();
                                } catch (IOException e2) {
                                    Log.e(f5615a, e2.getMessage());
                                }
                            }
                            if (fReader != null) {
                                try {
                                    fReader.close();
                                } catch (IOException e3) {
                                    Log.e(f5615a, e3.getMessage());
                                }
                            }
                        } catch (IOException e4) {
                            e = e4;
                            bReader = bReader2;
                            fReader = fReader2;
                            Log.e(f5615a, e.getMessage());
                            if (bReader != null) {
                                try {
                                    bReader.close();
                                } catch (IOException e5) {
                                    Log.e(f5615a, e5.getMessage());
                                }
                            }
                            if (fReader != null) {
                                try {
                                    fReader.close();
                                } catch (IOException e6) {
                                    Log.e(f5615a, e6.getMessage());
                                }
                            }
                        } catch (NumberFormatException e7) {
                            e = e7;
                            bReader = bReader2;
                            fReader = fReader2;
                            Log.e(f5615a, e.getMessage());
                            if (bReader != null) {
                                try {
                                    bReader.close();
                                } catch (IOException e8) {
                                    Log.e(f5615a, e8.getMessage());
                                }
                            }
                            if (fReader != null) {
                                try {
                                    fReader.close();
                                } catch (IOException e9) {
                                    Log.e(f5615a, e9.getMessage());
                                }
                            }
                        } catch (Throwable th) {
                            th = th;
                            bReader = bReader2;
                            fReader = fReader2;
                            if (bReader != null) {
                                try {
                                    bReader.close();
                                } catch (IOException e10) {
                                    Log.e(f5615a, e10.getMessage());
                                }
                            }
                            if (fReader != null) {
                                try {
                                    fReader.close();
                                } catch (IOException e11) {
                                    Log.e(f5615a, e11.getMessage());
                                }
                            }
                            throw th;
                        }
                    } catch (FileNotFoundException e12) {
                        e = e12;
                        fReader = fReader2;
                    } catch (IOException e13) {
                        e = e13;
                        fReader = fReader2;
                    } catch (NumberFormatException e14) {
                        e = e14;
                        fReader = fReader2;
                    } catch (Throwable th2) {
                        th = th2;
                        fReader = fReader2;
                    }
                }
                if (bReader != null) {
                    try {
                        bReader.close();
                    } catch (IOException e15) {
                        Log.e(f5615a, e15.getMessage());
                    }
                }
                if (fReader != null) {
                    try {
                        fReader.close();
                    } catch (IOException e16) {
                        Log.e(f5615a, e16.getMessage());
                    }
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (FileNotFoundException e17) {
            e = e17;
        } catch (IOException e18) {
            e = e18;
        } catch (NumberFormatException e19) {
            e = e19;
        }
        return resultString;
    }

    public String getBatteryInfo(Context c) {
        StringBuffer strInfo = new StringBuffer();
        strInfo.append(c.getString(C0415R.string.sysinfo_battery_power, Integer.valueOf(BatteryUtil.getCapacity()))).append("\n");
        strInfo.append(c.getString(C0415R.string.sysinfo_battery_voltage, Integer.valueOf(BatteryUtil.getVoltage()))).append("\n");
        strInfo.append(c.getString(C0415R.string.sysinfo_battery_temperature, Integer.valueOf(BatteryUtil.getTemperature()))).append("℃\n");
        strInfo.append(c.getString(C0415R.string.sysinfo_battery_type, BatteryUtil.getBatteryType()));
        return strInfo.toString();
    }
}
