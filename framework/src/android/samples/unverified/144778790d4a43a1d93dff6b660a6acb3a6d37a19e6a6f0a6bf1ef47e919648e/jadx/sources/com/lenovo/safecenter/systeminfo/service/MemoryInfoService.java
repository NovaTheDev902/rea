package com.lenovo.safecenter.systeminfo.service;

import android.app.ActivityManager;
import android.content.Context;
import android.os.Build;
import android.os.Environment;
import android.os.StatFs;
import android.os.StrictMode;
import android.text.TextUtils;
import android.text.format.Formatter;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.utils.Const;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class MemoryInfoService {

    /* JADX INFO: renamed from: a */
    private static final String f5622a = MemoryInfoService.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static MemoryInfoService f5623b = new MemoryInfoService();

    private MemoryInfoService() {
    }

    public static MemoryInfoService getInstance() {
        return f5623b;
    }

    public long getFreeMem(Context context) {
        ActivityManager manager = (ActivityManager) Const.mContext.getSystemService("activity");
        ActivityManager.MemoryInfo info = new ActivityManager.MemoryInfo();
        manager.getMemoryInfo(info);
        long free = info.availMem;
        return free;
    }

    public long getTotalMem(Context context) throws Throwable {
        FileReader fReader = null;
        BufferedReader bReader = null;
        try {
            try {
                FileReader fReader2 = new FileReader("/proc/meminfo");
                try {
                    BufferedReader bReader2 = new BufferedReader(fReader2);
                    try {
                        String text = bReader2.readLine();
                        if (!TextUtils.isEmpty(text)) {
                            String[] array = text.split("\\s+");
                            Log.w(f5622a, text);
                            long jLongValue = Long.valueOf(array[1]).longValue() / 1024;
                            if (bReader2 != null) {
                                try {
                                    bReader2.close();
                                } catch (IOException e) {
                                    Log.e(f5622a, e.getMessage());
                                }
                            }
                            if (fReader2 != null) {
                                try {
                                    fReader2.close();
                                } catch (IOException e2) {
                                    Log.e(f5622a, e2.getMessage());
                                }
                            }
                            return jLongValue;
                        }
                        if (bReader2 != null) {
                            try {
                                bReader2.close();
                            } catch (IOException e3) {
                                Log.e(f5622a, e3.getMessage());
                            }
                        }
                        if (fReader2 != null) {
                            try {
                                fReader2.close();
                                bReader = bReader2;
                                fReader = fReader2;
                            } catch (IOException e4) {
                                Log.e(f5622a, e4.getMessage());
                                bReader = bReader2;
                                fReader = fReader2;
                            }
                        } else {
                            bReader = bReader2;
                            fReader = fReader2;
                        }
                    } catch (FileNotFoundException e5) {
                        e = e5;
                        bReader = bReader2;
                        fReader = fReader2;
                        Log.e(f5622a, e.getMessage());
                        if (bReader != null) {
                            try {
                                bReader.close();
                            } catch (IOException e6) {
                                Log.e(f5622a, e6.getMessage());
                            }
                        }
                        if (fReader != null) {
                            try {
                                fReader.close();
                            } catch (IOException e7) {
                                Log.e(f5622a, e7.getMessage());
                            }
                        }
                    } catch (IOException e8) {
                        e = e8;
                        bReader = bReader2;
                        fReader = fReader2;
                        Log.e(f5622a, e.getMessage());
                        if (bReader != null) {
                            try {
                                bReader.close();
                            } catch (IOException e9) {
                                Log.e(f5622a, e9.getMessage());
                            }
                        }
                        if (fReader != null) {
                            try {
                                fReader.close();
                            } catch (IOException e10) {
                                Log.e(f5622a, e10.getMessage());
                            }
                        }
                    } catch (Throwable th) {
                        th = th;
                        bReader = bReader2;
                        fReader = fReader2;
                        if (bReader != null) {
                            try {
                                bReader.close();
                            } catch (IOException e11) {
                                Log.e(f5622a, e11.getMessage());
                            }
                        }
                        if (fReader != null) {
                            try {
                                fReader.close();
                            } catch (IOException e12) {
                                Log.e(f5622a, e12.getMessage());
                            }
                        }
                        throw th;
                    }
                } catch (FileNotFoundException e13) {
                    e = e13;
                    fReader = fReader2;
                } catch (IOException e14) {
                    e = e14;
                    fReader = fReader2;
                } catch (Throwable th2) {
                    th = th2;
                    fReader = fReader2;
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (FileNotFoundException e15) {
            e = e15;
        } catch (IOException e16) {
            e = e16;
        }
        return -1L;
    }

    public static float SystemVersion() {
        String v = Build.VERSION.RELEASE.trim();
        if (v == null || v.length() < 3) {
            return 0.0f;
        }
        return Float.parseFloat(v.substring(0, 3));
    }

    public synchronized long readAvailMem(String value) {
        long returnValue;
        float version = SystemVersion();
        StrictMode.ThreadPolicy savedPolicy = version > 3.0f ? StrictMode.allowThreadDiskReads() : null;
        returnValue = 0;
        FileInputStream is = null;
        byte[] mBuffer = new byte[1024];
        try {
            try {
                FileInputStream is2 = new FileInputStream("/proc/meminfo");
                long memFree = 0;
                long memCached = 0;
                long memTotal = 0;
                long memBuffers = 0;
                try {
                    int len = is2.read(mBuffer);
                    int BUFLEN = mBuffer.length;
                    int i = 0;
                    while (i < len && (memFree == 0 || memCached == 0)) {
                        if (m2304a(mBuffer, i, "MemTotal")) {
                            i += 8;
                            memTotal = m2302a(mBuffer, i);
                        } else if (m2304a(mBuffer, i, "MemFree")) {
                            i += 7;
                            memFree = m2302a(mBuffer, i);
                        } else if (m2304a(mBuffer, i, "Cached")) {
                            i += 6;
                            memCached = m2302a(mBuffer, i);
                        } else if (m2304a(mBuffer, i, "Buffers")) {
                            i += 6;
                            memBuffers = m2302a(mBuffer, i);
                        }
                        while (i < BUFLEN && mBuffer[i] != 10) {
                            i++;
                        }
                        i++;
                    }
                    if (TrafficStatsService.TOTAL.equals(value)) {
                        Log.i(f5622a, "readAvailMem()...total=" + memTotal);
                        returnValue = memTotal;
                    } else if ("used".equals(value)) {
                        returnValue = ((memTotal - memFree) - memCached) - memBuffers;
                        Log.i(f5622a, "readAvailMem()...used=" + returnValue);
                    } else if ("cache".equals(value)) {
                        Log.i(f5622a, "readAvailMem()...cache=" + memCached);
                        returnValue = memCached;
                    }
                    try {
                        is2.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    if (savedPolicy != null) {
                        StrictMode.setThreadPolicy(savedPolicy);
                        is = is2;
                    } else {
                        is = is2;
                    }
                } catch (FileNotFoundException e2) {
                    is = is2;
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e3) {
                            e3.printStackTrace();
                        }
                    }
                    if (savedPolicy != null) {
                        StrictMode.setThreadPolicy(savedPolicy);
                    }
                    return returnValue;
                } catch (IOException e4) {
                    e = e4;
                    is = is2;
                    e.printStackTrace();
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e5) {
                            e5.printStackTrace();
                        }
                    }
                    if (savedPolicy != null) {
                        StrictMode.setThreadPolicy(savedPolicy);
                    }
                } catch (Throwable th) {
                    th = th;
                    is = is2;
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e6) {
                            e6.printStackTrace();
                        }
                    }
                    if (savedPolicy != null) {
                        StrictMode.setThreadPolicy(savedPolicy);
                    }
                    throw th;
                }
            } catch (Throwable th2) {
                th = th2;
            }
        } catch (FileNotFoundException e7) {
        } catch (IOException e8) {
            e = e8;
        }
        return returnValue;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2304a(byte[] buffer, int index, String text) {
        int N = text.length();
        if (index + N >= buffer.length) {
            return false;
        }
        for (int i = 0; i < N; i++) {
            if (buffer[index + i] != text.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    /* JADX INFO: renamed from: a */
    private static long m2302a(byte[] buffer, int index) {
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
                return ((long) Integer.parseInt(str)) * 1024;
            }
            index++;
        }
        return 0L;
    }

    public String getMemeryInfo() throws Throwable {
        Context c = Const.mContext;
        FileReader fReader = null;
        BufferedReader bReader = null;
        try {
            try {
                StringBuffer strBuffer = new StringBuffer();
                FileReader fReader2 = new FileReader("/proc/meminfo");
                try {
                    BufferedReader bReader2 = new BufferedReader(fReader2);
                    try {
                        String text = bReader2.readLine();
                        if (!TextUtils.isEmpty(text)) {
                            long totalMem = readAvailMem(TrafficStatsService.TOTAL);
                            long usedMem = readAvailMem("used");
                            long freeMem = totalMem - usedMem;
                            strBuffer.append(c.getString(C0415R.string.sysinfo_mem_total, Formatter.formatFileSize(c, totalMem), Formatter.formatFileSize(c, freeMem)));
                            String string = strBuffer.toString();
                            if (bReader2 != null) {
                                try {
                                    bReader2.close();
                                } catch (IOException e) {
                                    Log.e(f5622a, e.getMessage());
                                }
                            }
                            if (fReader2 != null) {
                                try {
                                    fReader2.close();
                                } catch (IOException e2) {
                                    Log.e(f5622a, e2.getMessage());
                                }
                            }
                            return string;
                        }
                        if (bReader2 != null) {
                            try {
                                bReader2.close();
                            } catch (IOException e3) {
                                Log.e(f5622a, e3.getMessage());
                            }
                        }
                        if (fReader2 != null) {
                            try {
                                fReader2.close();
                                bReader = bReader2;
                                fReader = fReader2;
                            } catch (IOException e4) {
                                Log.e(f5622a, e4.getMessage());
                                bReader = bReader2;
                                fReader = fReader2;
                            }
                        } else {
                            bReader = bReader2;
                            fReader = fReader2;
                        }
                    } catch (FileNotFoundException e5) {
                        e = e5;
                        bReader = bReader2;
                        fReader = fReader2;
                        Log.e(f5622a, e.getMessage());
                        if (bReader != null) {
                            try {
                                bReader.close();
                            } catch (IOException e6) {
                                Log.e(f5622a, e6.getMessage());
                            }
                        }
                        if (fReader != null) {
                            try {
                                fReader.close();
                            } catch (IOException e7) {
                                Log.e(f5622a, e7.getMessage());
                            }
                        }
                    } catch (IOException e8) {
                        e = e8;
                        bReader = bReader2;
                        fReader = fReader2;
                        Log.e(f5622a, e.getMessage());
                        if (bReader != null) {
                            try {
                                bReader.close();
                            } catch (IOException e9) {
                                Log.e(f5622a, e9.getMessage());
                            }
                        }
                        if (fReader != null) {
                            try {
                                fReader.close();
                            } catch (IOException e10) {
                                Log.e(f5622a, e10.getMessage());
                            }
                        }
                    } catch (Throwable th) {
                        th = th;
                        bReader = bReader2;
                        fReader = fReader2;
                        if (bReader != null) {
                            try {
                                bReader.close();
                            } catch (IOException e11) {
                                Log.e(f5622a, e11.getMessage());
                            }
                        }
                        if (fReader != null) {
                            try {
                                fReader.close();
                            } catch (IOException e12) {
                                Log.e(f5622a, e12.getMessage());
                            }
                        }
                        throw th;
                    }
                } catch (FileNotFoundException e13) {
                    e = e13;
                    fReader = fReader2;
                } catch (IOException e14) {
                    e = e14;
                    fReader = fReader2;
                } catch (Throwable th2) {
                    th = th2;
                    fReader = fReader2;
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (FileNotFoundException e15) {
            e = e15;
        } catch (IOException e16) {
            e = e16;
        }
        return null;
    }

    public String getRomAndSDcardSizeInfo(Context c) {
        String info = "";
        try {
            try {
                ArrayList<String> extendStorageList = m2303a();
                if (extendStorageList != null && extendStorageList.size() == 2) {
                    StatFs extraStatFs = new StatFs(extendStorageList.get(0));
                    long extraBlockSize = extraStatFs.getBlockSize();
                    long extraBlockCount = extraStatFs.getBlockCount();
                    long extraAvailCount = extraStatFs.getAvailableBlocks();
                    String info2 = c.getString(C0415R.string.sysinfo_size_sd_extra, Formatter.formatFileSize(c, extraBlockCount * extraBlockSize), Formatter.formatFileSize(c, extraAvailCount * extraBlockSize));
                    StatFs innerStatFs = new StatFs(extendStorageList.get(1));
                    long inblockSize = innerStatFs.getBlockSize();
                    long inblockCount = innerStatFs.getBlockCount();
                    long inavailCount = innerStatFs.getAvailableBlocks();
                    info = c.getString(C0415R.string.sysinfo_size_sd_inner, Formatter.formatFileSize(c, inblockCount * inblockSize), Formatter.formatFileSize(c, inavailCount * inblockSize)) + "\n" + info2;
                } else if (extendStorageList.size() == 1) {
                    StatFs innerStatFs2 = new StatFs(extendStorageList.get(0).toString());
                    long blockSize = innerStatFs2.getBlockSize();
                    long blockCount = innerStatFs2.getBlockCount();
                    long availCount = innerStatFs2.getAvailableBlocks();
                    info = c.getString(C0415R.string.sysinfo_size_sd_inner, Formatter.formatFileSize(c, blockCount * blockSize), Formatter.formatFileSize(c, availCount * blockSize));
                }
                if (!info.equals("")) {
                    return c.getString(C0415R.string.sysinfo_rom_total, Formatter.formatFileSize(c, getRomTotalSize()), Formatter.formatFileSize(c, getRomAvailableSize())) + "\n" + info;
                }
                String info3 = c.getString(C0415R.string.sysinfo_rom_total, Formatter.formatFileSize(c, getRomTotalSize()), Formatter.formatFileSize(c, getRomAvailableSize()));
                return info3;
            } catch (Exception localException) {
                localException.printStackTrace();
                if ("".equals("")) {
                    String info4 = c.getString(C0415R.string.sysinfo_rom_total, Formatter.formatFileSize(c, getRomTotalSize()), Formatter.formatFileSize(c, getRomAvailableSize()));
                    return info4;
                }
                String info5 = c.getString(C0415R.string.sysinfo_rom_total, Formatter.formatFileSize(c, getRomTotalSize()), Formatter.formatFileSize(c, getRomAvailableSize())) + "\n";
                return info5;
            }
        } catch (Throwable th) {
            if ("".equals("")) {
                c.getString(C0415R.string.sysinfo_rom_total, Formatter.formatFileSize(c, getRomTotalSize()), Formatter.formatFileSize(c, getRomAvailableSize()));
            } else {
                String str = c.getString(C0415R.string.sysinfo_rom_total, Formatter.formatFileSize(c, getRomTotalSize()), Formatter.formatFileSize(c, getRomAvailableSize())) + "\n";
            }
            throw th;
        }
    }

    /* JADX INFO: renamed from: a */
    private static ArrayList<String> m2303a() {
        ArrayList<String> extendStorageList = new ArrayList<>();
        try {
            BufferedReader localBufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(new File("/proc/mounts"))));
            while (true) {
                String buffer = localBufferedReader.readLine();
                if (buffer == null) {
                    break;
                }
                if (buffer.contains("uid=1000") && buffer.contains("gid=1015") && !buffer.contains("asec")) {
                    String[] arrayOfString = buffer.split(" ");
                    if (arrayOfString.length >= 4 && !extendStorageList.contains(arrayOfString[1])) {
                        extendStorageList.add(arrayOfString[1]);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return extendStorageList;
    }

    public long getRomTotalSize() {
        StatFs localStatFs = new StatFs(Environment.getDataDirectory().getPath());
        long total = localStatFs.getBlockCount();
        return ((long) localStatFs.getBlockSize()) * total;
    }

    public long getRomAvailableSize() {
        StatFs localStatFs = new StatFs(Environment.getDataDirectory().getPath());
        long available = localStatFs.getAvailableBlocks();
        return ((long) localStatFs.getBlockSize()) * available;
    }
}
