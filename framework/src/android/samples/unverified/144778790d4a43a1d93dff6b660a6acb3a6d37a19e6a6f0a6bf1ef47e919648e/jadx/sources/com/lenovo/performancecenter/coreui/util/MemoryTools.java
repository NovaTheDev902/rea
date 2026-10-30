package com.lenovo.performancecenter.coreui.util;

import android.app.ActivityManager;
import android.content.Context;
import android.os.Debug;
import android.text.format.Formatter;
import android.util.Log;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class MemoryTools {

    /* JADX INFO: renamed from: a */
    private byte[] f1594a = new byte[1024];

    /* JADX INFO: renamed from: b */
    private long f1595b;

    public long getTotalMemory() {
        try {
            this.f1595b = 0L;
            FileInputStream is = new FileInputStream("/proc/meminfo");
            int len = is.read(this.f1594a);
            is.close();
            int BUF_LEN = this.f1594a.length;
            int i = 0;
            while (i < len && this.f1595b == 0) {
                if (m562a(this.f1594a, i, "MemTotal")) {
                    i += 7;
                    this.f1595b = m561a(this.f1594a, i);
                }
                while (i < BUF_LEN && this.f1594a[i] != 10) {
                    i++;
                }
                i++;
            }
            return this.f1595b;
        } catch (FileNotFoundException e) {
            return 0L;
        } catch (IOException e2) {
            Log.e("zzj", "[getTotalMemory] " + e2);
            return 0L;
        }
    }

    /* JADX INFO: renamed from: a */
    private static long m559a() throws Throwable {
        long availMemory = 0;
        BufferedReader buf = null;
        try {
            BufferedReader buf2 = new BufferedReader(new FileReader("/proc/meminfo"));
            int i = 0;
            long freeMem = 0;
            long buffers = 0;
            long buffermem = 0;
            while (true) {
                try {
                    String line = buf2.readLine();
                    if (line == null) {
                        break;
                    }
                    if (i != 0) {
                        if (i != 1) {
                            if (i != 2) {
                                buffermem = m560a(line);
                                break;
                            }
                            buffers = m560a(line);
                        } else {
                            freeMem = m560a(line);
                        }
                    }
                    i++;
                } catch (FileNotFoundException e) {
                    buf = buf2;
                    if (buf != null) {
                        try {
                            buf.close();
                        } catch (Exception e2) {
                            e2.printStackTrace();
                        }
                    }
                } catch (IOException e3) {
                    buf = buf2;
                    if (buf != null) {
                        try {
                            buf.close();
                        } catch (Exception e4) {
                            e4.printStackTrace();
                        }
                    }
                } catch (Throwable th) {
                    th = th;
                    buf = buf2;
                    if (buf != null) {
                        try {
                            buf.close();
                        } catch (Exception e5) {
                            e5.printStackTrace();
                        }
                    }
                    throw th;
                }
            }
            availMemory = freeMem + buffermem + buffers;
            try {
                buf2.close();
            } catch (Exception e6) {
                e6.printStackTrace();
            }
        } catch (FileNotFoundException e7) {
        } catch (IOException e8) {
        } catch (Throwable th2) {
            th = th2;
        }
        return availMemory;
    }

    /* JADX INFO: renamed from: a */
    private static long m560a(String readLine) {
        String[] array = readLine.split("\\s+");
        try {
            return Long.parseLong(array[1]);
        } catch (Exception e) {
            return 0L;
        }
    }

    /* JADX INFO: renamed from: a */
    private static boolean m562a(byte[] buffer, int index, String text) {
        int LEN = text.length();
        if (index + LEN >= buffer.length) {
            return false;
        }
        for (int i = 0; i < LEN; i++) {
            if (buffer[index + i] != text.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    /* JADX INFO: renamed from: a */
    private static long m561a(byte[] buffer, int index) {
        while (index < buffer.length && buffer[index] != 10) {
            if (buffer[index] >= 48 && buffer[index] <= 57) {
                int start = index;
                do {
                    index++;
                    if (index >= buffer.length || buffer[index] < 48) {
                        break;
                    }
                } while (buffer[index] <= 57);
                String str = new String(buffer, 0, start, index - start);
                return Integer.parseInt(str);
            }
            index++;
        }
        return 0L;
    }

    public int getSystemMeminfo() throws Throwable {
        int scale = 0;
        BufferedReader buf = null;
        try {
            BufferedReader buf2 = new BufferedReader(new FileReader("/proc/meminfo"));
            int i = 0;
            long totalMem = 0;
            long freeMem = 0;
            long buffermem = 0;
            long buffers = 0;
            while (true) {
                try {
                    String line = buf2.readLine();
                    if (line == null) {
                        break;
                    }
                    if (i != 0) {
                        if (i != 1) {
                            if (i != 2) {
                                buffermem = m560a(line);
                                break;
                            }
                            buffers = m560a(line);
                        } else {
                            freeMem = m560a(line);
                        }
                    } else {
                        totalMem = m560a(line);
                    }
                    i++;
                } catch (FileNotFoundException e) {
                    buf = buf2;
                    if (buf != null) {
                        try {
                            buf.close();
                        } catch (Exception e2) {
                            e2.printStackTrace();
                        }
                    }
                } catch (IOException e3) {
                    buf = buf2;
                    if (buf != null) {
                        try {
                            buf.close();
                        } catch (Exception e4) {
                            e4.printStackTrace();
                        }
                    }
                } catch (Throwable th) {
                    th = th;
                    buf = buf2;
                    if (buf != null) {
                        try {
                            buf.close();
                        } catch (Exception e5) {
                            e5.printStackTrace();
                        }
                    }
                    throw th;
                }
            }
            if (totalMem - freeMem > 0) {
                long t = ((totalMem - freeMem) - buffermem) - buffers;
                Log.i("MemoryTools", "used == " + t);
                scale = (int) ((100 * t) / totalMem);
            }
            try {
                buf2.close();
            } catch (Exception e6) {
                e6.printStackTrace();
            }
        } catch (FileNotFoundException e7) {
        } catch (IOException e8) {
        } catch (Throwable th2) {
            th = th2;
        }
        return scale;
    }

    public int getSystemMeminfoFree() throws Throwable {
        long freeMemory = m559a();
        long scale = (100 * freeMemory) / getTotalMemory();
        return (int) scale;
    }

    public static String getMemInfo(Context context, int pid) {
        return Formatter.formatFileSize(context, getMemInfoForPid(context, pid));
    }

    public static String getMemInfos(Context context, int[] pids) {
        return Formatter.formatFileSize(context, getMemInfoForPid(context, pids));
    }

    public static int getMemInfoForPid(Context context, int pid) {
        int[] pids = {pid};
        ActivityManager am = (ActivityManager) context.getSystemService("activity");
        Debug.MemoryInfo[] mem = am.getProcessMemoryInfo(pids);
        int totalClear = 0;
        if (mem.length > 0) {
            int pidsSize = pids.length;
            for (int i = 0; i < pidsSize; i++) {
                int totalPss = mem[i].getTotalPss();
                if (totalPss > 0) {
                    totalClear += totalPss * 1024;
                }
            }
        }
        return totalClear;
    }

    public static int getMemInfoForPid(Context context, int[] pids) {
        ActivityManager am = (ActivityManager) context.getSystemService("activity");
        Debug.MemoryInfo[] mem = am.getProcessMemoryInfo(pids);
        int totalClear = 0;
        if (mem.length > 0) {
            int pidsSize = pids.length;
            for (int i = 0; i < pidsSize; i++) {
                int totalPss = mem[i].getTotalPss();
                if (totalPss > 0) {
                    totalClear += totalPss * 1024;
                }
            }
        }
        return totalClear;
    }
}
