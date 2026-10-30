package com.lenovo.safecenter.systeminfo.util;

import android.util.Log;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class BatteryUtil {
    public static int getCapacity() {
        int capacity = Integer.parseInt(m2344a("/sys/class/power_supply/battery/capacity"));
        return capacity;
    }

    public static String getBatteryType() {
        return m2344a("/sys/class/power_supply/battery/technology");
    }

    public static int getVoltage() throws Throwable {
        String resultString = m2344a("/sys/class/power_supply/battery/voltage_now");
        if (resultString == null || "".equals(resultString)) {
            return 0;
        }
        return Integer.parseInt(resultString);
    }

    public static int getCurrent() throws Throwable {
        String resultString = m2344a("/sys/class/power_supply/battery/current_now");
        if (resultString == null || "".equals(resultString)) {
            return 0;
        }
        return Integer.parseInt(resultString);
    }

    public static int getTemperature() throws Throwable {
        String resultString = m2344a("/sys/class/power_supply/battery/temp");
        if (resultString == null || "".equals(resultString)) {
            return 0;
        }
        return Integer.parseInt(resultString);
    }

    /* JADX INFO: renamed from: a */
    private static String m2344a(String path) throws Throwable {
        String str;
        String message;
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
                            Log.i("BatteryUtil", e.getMessage());
                            if (fReader != null) {
                                try {
                                    fReader.close();
                                } catch (IOException e2) {
                                    Log.i("BatteryUtil", e2.getMessage());
                                }
                            }
                            if (bReader != null) {
                                try {
                                    bReader.close();
                                } catch (IOException e3) {
                                    str = "BatteryUtil";
                                    message = e3.getMessage();
                                    Log.i(str, message);
                                }
                            }
                        } catch (IOException e4) {
                            e = e4;
                            bReader = bReader2;
                            fReader = fReader2;
                            Log.i("BatteryUtil", e.getMessage());
                            if (fReader != null) {
                                try {
                                    fReader.close();
                                } catch (IOException e5) {
                                    Log.i("BatteryUtil", e5.getMessage());
                                }
                            }
                            if (bReader != null) {
                                try {
                                    bReader.close();
                                } catch (IOException e6) {
                                    str = "BatteryUtil";
                                    message = e6.getMessage();
                                    Log.i(str, message);
                                }
                            }
                        } catch (NumberFormatException e7) {
                            e = e7;
                            bReader = bReader2;
                            fReader = fReader2;
                            Log.i("BatteryUtil", e.getMessage());
                            if (fReader != null) {
                                try {
                                    fReader.close();
                                } catch (IOException e8) {
                                    Log.i("BatteryUtil", e8.getMessage());
                                }
                            }
                            if (bReader != null) {
                                try {
                                    bReader.close();
                                } catch (IOException e9) {
                                    str = "BatteryUtil";
                                    message = e9.getMessage();
                                    Log.i(str, message);
                                }
                            }
                        } catch (Throwable th) {
                            th = th;
                            bReader = bReader2;
                            fReader = fReader2;
                            if (fReader != null) {
                                try {
                                    fReader.close();
                                } catch (IOException e10) {
                                    Log.i("BatteryUtil", e10.getMessage());
                                }
                            }
                            if (bReader != null) {
                                try {
                                    bReader.close();
                                } catch (IOException e11) {
                                    Log.i("BatteryUtil", e11.getMessage());
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
                if (fReader != null) {
                    try {
                        fReader.close();
                    } catch (IOException e15) {
                        Log.i("BatteryUtil", e15.getMessage());
                    }
                }
                if (bReader != null) {
                    try {
                        bReader.close();
                    } catch (IOException e16) {
                        str = "BatteryUtil";
                        message = e16.getMessage();
                        Log.i(str, message);
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
}
