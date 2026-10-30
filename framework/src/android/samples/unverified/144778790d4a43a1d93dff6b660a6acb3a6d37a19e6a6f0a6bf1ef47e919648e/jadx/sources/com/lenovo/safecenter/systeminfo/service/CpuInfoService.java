package com.lenovo.safecenter.systeminfo.service;

import android.content.Context;
import android.text.TextUtils;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: loaded from: classes.dex */
public class CpuInfoService {

    /* JADX INFO: renamed from: a */
    private static final String f5620a = CpuInfoService.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static CpuInfoService f5621b = new CpuInfoService();

    private CpuInfoService() {
    }

    public static CpuInfoService getInstance() {
        return f5621b;
    }

    public String getCpuInfo(Context c) throws Throwable {
        String cpu_max_freq;
        String cpu_min_freq;
        FileReader fReader = null;
        BufferedReader bReader = null;
        try {
            try {
                FileReader fReader2 = new FileReader("/proc/cpuinfo");
                try {
                    BufferedReader bReader2 = new BufferedReader(fReader2);
                    try {
                        StringBuffer stringBuffer = new StringBuffer();
                        String text = bReader2.readLine();
                        if (!TextUtils.isEmpty(text)) {
                            if (TextUtils.isEmpty(Const.mDefaultPreference.getString("cpuinfo", null)) || !Const.mDefaultPreference.getString("cpuinfo", null).contains("intel")) {
                                stringBuffer.append(c.getString(C0415R.string.sysinfo_cpu_type)).append(text.split(":\\s+", 2)[1]).append("\n");
                            } else {
                                stringBuffer.append(c.getString(C0415R.string.intel_cpu)).append("\n");
                            }
                        }
                        String text2 = bReader2.readLine();
                        if (!TextUtils.isEmpty(text2)) {
                            String[] array = text2.split(":\\s+", 2);
                            String cpu_max_freq2 = getMaxCpuFreq();
                            if ("N/A".equals(cpu_max_freq2) || "".equals(cpu_max_freq2)) {
                                cpu_max_freq = array[1] + c.getString(C0415R.string.sysinfo_cpu_speed_unit);
                            } else {
                                Log.e("##", "cpu_max_freq :" + cpu_max_freq2);
                                cpu_max_freq = "" + (Long.parseLong(cpu_max_freq2) / 1000) + c.getString(C0415R.string.sysinfo_cpu_speed_unit);
                            }
                            String cpu_min_freq2 = getMinCpuFreq();
                            if ("N/A".equals(cpu_min_freq2) || "".equals(cpu_min_freq2)) {
                                cpu_min_freq = array[1] + c.getString(C0415R.string.sysinfo_cpu_speed_unit);
                            } else {
                                Log.e("##", "cpu_min_freq :" + cpu_min_freq2);
                                cpu_min_freq = "" + (Long.parseLong(cpu_min_freq2) / 1000) + c.getString(C0415R.string.sysinfo_cpu_speed_unit);
                            }
                            stringBuffer.append(c.getString(C0415R.string.sysinfo_cpu_max_speed)).append(cpu_max_freq).append("\n");
                            stringBuffer.append(c.getString(C0415R.string.sysinfo_cpu_min_speed)).append(cpu_min_freq);
                        }
                        String string = stringBuffer.toString();
                        if (bReader2 != null) {
                            try {
                                bReader2.close();
                            } catch (IOException e) {
                                Log.e(f5620a, e.getMessage());
                            }
                        }
                        if (fReader2 != null) {
                            try {
                                fReader2.close();
                            } catch (IOException e2) {
                                Log.e(f5620a, e2.getMessage());
                            }
                        }
                        return string;
                    } catch (FileNotFoundException e3) {
                        e = e3;
                        bReader = bReader2;
                        fReader = fReader2;
                        Log.i(f5620a, e.getMessage());
                        if (bReader != null) {
                            try {
                                bReader.close();
                            } catch (IOException e4) {
                                Log.e(f5620a, e4.getMessage());
                            }
                        }
                        if (fReader != null) {
                            try {
                                fReader.close();
                            } catch (IOException e5) {
                                Log.e(f5620a, e5.getMessage());
                            }
                        }
                        return null;
                    } catch (IOException e6) {
                        e = e6;
                        bReader = bReader2;
                        fReader = fReader2;
                        Log.i(f5620a, e.getMessage());
                        if (bReader != null) {
                            try {
                                bReader.close();
                            } catch (IOException e7) {
                                Log.e(f5620a, e7.getMessage());
                            }
                        }
                        if (fReader != null) {
                            try {
                                fReader.close();
                            } catch (IOException e8) {
                                Log.e(f5620a, e8.getMessage());
                            }
                        }
                        return null;
                    } catch (Throwable th) {
                        th = th;
                        bReader = bReader2;
                        fReader = fReader2;
                        if (bReader != null) {
                            try {
                                bReader.close();
                            } catch (IOException e9) {
                                Log.e(f5620a, e9.getMessage());
                            }
                        }
                        if (fReader != null) {
                            try {
                                fReader.close();
                            } catch (IOException e10) {
                                Log.e(f5620a, e10.getMessage());
                            }
                        }
                        throw th;
                    }
                } catch (FileNotFoundException e11) {
                    e = e11;
                    fReader = fReader2;
                } catch (IOException e12) {
                    e = e12;
                    fReader = fReader2;
                } catch (Throwable th2) {
                    th = th2;
                    fReader = fReader2;
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (FileNotFoundException e13) {
            e = e13;
        } catch (IOException e14) {
            e = e14;
        }
    }

    public static String getMaxCpuFreq() {
        String result = "";
        try {
            String[] args = {"/system/bin/cat", "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq"};
            ProcessBuilder cmd = new ProcessBuilder(args);
            Process process = cmd.start();
            InputStream in = process.getInputStream();
            byte[] re = new byte[24];
            while (in.read(re) != -1) {
                result = result + new String(re);
            }
            in.close();
        } catch (IOException ex) {
            ex.printStackTrace();
            result = "N/A";
        }
        return result.trim();
    }

    public static String getMinCpuFreq() {
        String result = "";
        try {
            String[] args = {"/system/bin/cat", "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq"};
            ProcessBuilder cmd = new ProcessBuilder(args);
            Process process = cmd.start();
            InputStream in = process.getInputStream();
            byte[] re = new byte[24];
            while (in.read(re) != -1) {
                result = result + new String(re);
            }
            in.close();
        } catch (IOException ex) {
            ex.printStackTrace();
            result = "N/A";
        }
        return result.trim();
    }

    public static String getCurCpuFreq() {
        try {
            FileReader fr = new FileReader("/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq");
            BufferedReader br = new BufferedReader(fr);
            String text = br.readLine();
            if (TextUtils.isEmpty(text)) {
                return "N/A";
            }
            String result = text.trim();
            return result;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return "N/A";
        } catch (IOException e2) {
            e2.printStackTrace();
            return "N/A";
        }
    }

    public static String getCpuName() {
        try {
            FileReader fr = new FileReader("/proc/cpuinfo");
            BufferedReader br = new BufferedReader(fr);
            String text = br.readLine();
            if (!TextUtils.isEmpty(text)) {
                String[] array = text.split(":\\s+", 2);
                return array[1];
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e2) {
            e2.printStackTrace();
        }
        return null;
    }
}
