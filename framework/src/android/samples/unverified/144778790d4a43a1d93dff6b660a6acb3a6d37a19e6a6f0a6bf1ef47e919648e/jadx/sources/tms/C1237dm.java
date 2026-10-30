package tms;

import android.app.ActivityManager;
import android.content.Context;
import android.content.p001pm.IPackageDataObserver;
import android.content.p001pm.IPackageStatsObserver;
import android.content.pm.PackageManager;
import android.content.pm.PackageStats;
import android.os.Debug;
import android.os.Environment;
import android.os.StatFs;
import com.tencent.tmsecure.module.optimize.IMemoryHelper;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicReference;

/* JADX INFO: renamed from: tms.dm */
/* JADX INFO: loaded from: classes.dex */
final class C1237dm implements IMemoryHelper {

    /* JADX INFO: renamed from: a */
    private static Method f7139a;

    /* JADX INFO: renamed from: b */
    private static Method f7140b;

    /* JADX INFO: renamed from: c */
    private static long f7141c;

    /* JADX INFO: renamed from: d */
    private Context f7142d;

    /* JADX INFO: renamed from: e */
    private PackageManager f7143e;

    /* JADX INFO: renamed from: f */
    private ActivityManager f7144f;

    static {
        try {
            f7139a = PackageManager.class.getDeclaredMethod("freeStorageAndNotify", Long.TYPE, IPackageDataObserver.class);
            f7139a.setAccessible(true);
            f7140b = PackageManager.class.getDeclaredMethod("getPackageSizeInfo", String.class, IPackageStatsObserver.class);
            f7140b.setAccessible(true);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
        f7141c = -1L;
    }

    public C1237dm(Context context) {
        this.f7142d = context;
        this.f7143e = this.f7142d.getPackageManager();
        this.f7144f = (ActivityManager) this.f7142d.getSystemService("activity");
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final boolean clearAllCacheData() {
        long j = 1024888192;
        Object obj = new Object();
        AtomicBoolean atomicBoolean = new AtomicBoolean(false);
        File dataDirectory = Environment.getDataDirectory();
        if (dataDirectory != null) {
            StatFs statFs = new StatFs(dataDirectory.getPath());
            long blockCount = ((long) statFs.getBlockCount()) * ((long) statFs.getBlockSize());
            if (blockCount >= 1024) {
                j = blockCount;
            }
        }
        BinderC1238dn binderC1238dn = new BinderC1238dn(this, atomicBoolean, obj);
        try {
            if (f7139a == null) {
                throw new NullPointerException();
            }
            f7139a.invoke(this.f7143e, Long.valueOf(j), binderC1238dn);
            synchronized (obj) {
                try {
                    obj.wait(5000L);
                } catch (InterruptedException e) {
                }
            }
            return atomicBoolean.get();
        } catch (Exception e2) {
            e2.printStackTrace();
            atomicBoolean.set(false);
        }
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final boolean clearCacheData(String str) {
        return false;
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final ArrayList<PackageStats> getAllAppPackageStats(List<String> list) {
        ArrayList<PackageStats> arrayList = new ArrayList<>();
        Iterator<String> it = list.iterator();
        while (it.hasNext()) {
            arrayList.add(getAppPackageStats(it.next()));
        }
        return arrayList;
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final PackageStats getAppPackageStats(String str) {
        Object obj = new Object();
        AtomicReference atomicReference = new AtomicReference(null);
        BinderC1240dp binderC1240dp = new BinderC1240dp(this, atomicReference, obj);
        try {
            if (f7140b == null) {
                throw new NullPointerException();
            }
            f7140b.invoke(this.f7143e, str, binderC1240dp);
            synchronized (obj) {
                try {
                    obj.wait(1000L);
                } catch (InterruptedException e) {
                }
            }
        } catch (Exception e2) {
            atomicReference.set(null);
        }
        return (PackageStats) atomicReference.get();
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final long getFreeMemery() {
        ActivityManager.MemoryInfo memoryInfo = new ActivityManager.MemoryInfo();
        this.f7144f.getMemoryInfo(memoryInfo);
        return (long) (memoryInfo.availMem / 1024.0f);
    }

    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final Debug.MemoryInfo[] getRamSize(String[] strArr) {
        List<ActivityManager.RunningAppProcessInfo> runningAppProcesses = this.f7144f.getRunningAppProcesses();
        ArrayList arrayList = new ArrayList();
        List listAsList = Arrays.asList(strArr);
        for (ActivityManager.RunningAppProcessInfo runningAppProcessInfo : runningAppProcesses) {
            for (String str : runningAppProcessInfo.pkgList) {
                if (listAsList.contains(str)) {
                    arrayList.add(Integer.valueOf(runningAppProcessInfo.pid));
                    break;
                }
            }
        }
        if (arrayList.size() <= 0) {
            return null;
        }
        int[] iArr = new int[arrayList.size()];
        for (int i = 0; i < iArr.length; i++) {
            iArr[i] = ((Integer) arrayList.get(i)).intValue();
        }
        return this.f7144f.getProcessMemoryInfo(iArr);
    }

    /* JADX WARN: Code duplicated, block: B:17:0x003f  */
    /* JADX WARN: Code duplicated, block: B:46:0x0082 A[RETURN, SYNTHETIC] */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r1v1, types: [boolean] */
    /* JADX WARN: Type inference failed for: r1v4 */
    @Override // com.tencent.tmsecure.module.optimize.IMemoryHelper
    public final long getTotalMemery() throws Throwable {
        DataInputStream dataInputStream;
        if (f7141c == -1) {
            File file = new File("/proc/meminfo");
            DataInputStream dataInputStreamExists = file.exists();
            try {
                if (dataInputStreamExists != 0) {
                    try {
                        dataInputStream = new DataInputStream(new FileInputStream(file));
                        try {
                            String line = dataInputStream.readLine();
                            if (line == null) {
                                throw new IOException("/proc/meminfo is empty!");
                            }
                            f7141c = Long.parseLong(line.trim().split("[\\s]+")[1]);
                            if (dataInputStream != null) {
                                try {
                                    dataInputStream.close();
                                } catch (IOException e) {
                                    e = e;
                                    e.printStackTrace();
                                }
                            }
                        } catch (FileNotFoundException e2) {
                            e = e2;
                            e.printStackTrace();
                            if (dataInputStream != null) {
                                try {
                                    dataInputStream.close();
                                } catch (IOException e3) {
                                    e = e3;
                                    e.printStackTrace();
                                }
                            }
                            if (f7141c > 0) {
                                return f7141c;
                            }
                            return 1L;
                        } catch (IOException e4) {
                            e = e4;
                            e.printStackTrace();
                            if (dataInputStream != null) {
                                try {
                                    dataInputStream.close();
                                } catch (IOException e5) {
                                    e = e5;
                                    e.printStackTrace();
                                }
                            }
                            if (f7141c > 0) {
                                return f7141c;
                            }
                            return 1L;
                        } catch (NumberFormatException e6) {
                            e = e6;
                            e.printStackTrace();
                            if (dataInputStream != null) {
                                try {
                                    dataInputStream.close();
                                } catch (IOException e7) {
                                    e = e7;
                                    e.printStackTrace();
                                }
                            }
                            if (f7141c > 0) {
                                return f7141c;
                            }
                            return 1L;
                        }
                    } catch (FileNotFoundException e8) {
                        e = e8;
                        dataInputStream = null;
                    } catch (IOException e9) {
                        e = e9;
                        dataInputStream = null;
                    } catch (NumberFormatException e10) {
                        e = e10;
                        dataInputStream = null;
                    } catch (Throwable th) {
                        th = th;
                        dataInputStreamExists = 0;
                        if (dataInputStreamExists != 0) {
                            try {
                                dataInputStreamExists.close();
                            } catch (IOException e11) {
                                e11.printStackTrace();
                            }
                        }
                        throw th;
                    }
                }
            } catch (Throwable th2) {
                th = th2;
            }
        }
        if (f7141c > 0) {
            return f7141c;
        }
        return 1L;
    }
}
