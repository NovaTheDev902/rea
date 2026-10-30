package com.lenovo.performancecenter.service.object;

import android.content.Context;
import android.content.p001pm.IPackageDataObserver;
import android.content.p001pm.IPackageStatsObserver;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageStats;
import android.graphics.Bitmap;
import android.graphics.drawable.Drawable;
import android.os.Environment;
import android.os.RemoteException;
import android.os.StatFs;
import android.text.format.Formatter;
import android.util.Log;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.framework.DataLayerManager;
import java.io.File;
import java.lang.ref.SoftReference;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ApplicationDataInfo {

    /* JADX INFO: renamed from: h */
    private int f1939h;

    /* JADX INFO: renamed from: b */
    private int f1933b = 0;

    /* JADX INFO: renamed from: c */
    private long f1934c = -1;

    /* JADX INFO: renamed from: d */
    private long f1935d = -1;

    /* JADX INFO: renamed from: e */
    private long f1936e = -1;

    /* JADX INFO: renamed from: f */
    private long f1937f = -1;

    /* JADX INFO: renamed from: g */
    private int f1938g = -1;

    /* JADX INFO: renamed from: i */
    private final IPackageStatsObserver.Stub f1940i = new IPackageStatsObserver.Stub() { // from class: com.lenovo.performancecenter.service.object.ApplicationDataInfo.1
        @Override // android.content.p001pm.IPackageStatsObserver
        public final void onGetStatsCompleted(PackageStats pStats, boolean succeeded) throws RemoteException {
            ApplicationDataInfo.this.f1932a.add(pStats);
            ApplicationDataInfo.m784b(ApplicationDataInfo.this);
            Log.i("ClearCache", "pStats.packageName == " + pStats.packageName + " listSize == " + ApplicationDataInfo.this.f1938g + " " + ApplicationDataInfo.this.f1939h);
            Log.i("ClearCache", "pStats succeeded == " + succeeded + " listSize == " + ApplicationDataInfo.this.f1938g + " " + ApplicationDataInfo.this.f1939h);
        }
    };

    /* JADX INFO: renamed from: a */
    private List<PackageStats> f1932a = new ArrayList();

    /* JADX INFO: renamed from: b */
    static /* synthetic */ int m784b(ApplicationDataInfo x0) {
        int i = x0.f1939h;
        x0.f1939h = i + 1;
        return i;
    }

    public class DataInfo {
        public long cachesize;
        public long codesize;
        public long datasize;
        public long totalsize;

        /* synthetic */ DataInfo(ApplicationDataInfo x0, long x1, long x2, long x3, long x4, byte b) {
            this(x1, x2, x3, x4);
        }

        private DataInfo(long cachesize, long datasize, long codesize, long totalsize) {
            this.cachesize = -1L;
            this.datasize = -1L;
            this.codesize = -1L;
            this.totalsize = -1L;
            this.cachesize = cachesize;
            this.datasize = datasize;
            this.codesize = codesize;
            this.totalsize = totalsize;
        }
    }

    public ApplicationDataInfo(Context context) {
        m783a(context);
    }

    public DataInfo getDataInfo() {
        m782a();
        this.f1934c = 0L;
        this.f1935d = 0L;
        this.f1936e = 0L;
        this.f1937f = 0L;
        for (PackageStats ps : this.f1932a) {
            this.f1934c += ps.cacheSize;
            this.f1935d += ps.dataSize;
            this.f1936e += ps.codeSize;
        }
        this.f1937f = this.f1934c + this.f1935d + this.f1936e;
        return new DataInfo(this, this.f1934c, this.f1935d, this.f1936e, this.f1937f, (byte) 0);
    }

    public ArrayList<DataLayerManager.CacheInfo> getCacheInfo(Context context, PackageManager pm) {
        ArrayList<DataLayerManager.CacheInfo> list = new ArrayList<>();
        m782a();
        for (PackageStats ps : this.f1932a) {
            if (ps.cacheSize > 0) {
                try {
                    ApplicationInfo info = pm.getApplicationInfo(ps.packageName, 0);
                    String lable = ((Object) info.loadLabel(pm)) + "";
                    Drawable icon = info.loadIcon(pm);
                    SoftReference<Bitmap> bitmap = new SoftReference<>(DataLayerManager.drawableToBitmap(icon));
                    DataLayerManager.CacheInfo appInfo = new DataLayerManager.CacheInfo(ps.packageName, lable, bitmap.get(), Formatter.formatFileSize(context, ps.cacheSize));
                    appInfo.appCacheSize = ps.cacheSize;
                    list.add(appInfo);
                } catch (PackageManager.NameNotFoundException e) {
                    e.printStackTrace();
                }
            }
        }
        return list;
    }

    /* JADX INFO: renamed from: a */
    private final void m783a(Context context) {
        List<PackageInfo> installedPackages = context.getPackageManager().getInstalledPackages(0);
        Iterator<PackageInfo> it = installedPackages.iterator();
        ArrayList<String> packageList = new ArrayList<>();
        while (it.hasNext()) {
            packageList.add(it.next().packageName);
        }
        installedPackages.clear();
        packageList.trimToSize();
        this.f1938g = packageList.size();
        this.f1939h = 0;
        for (String packageName : packageList) {
            PackageManager packageManager = context.getPackageManager();
            if (packageName != null) {
                packageManager.getPackageSizeInfo(packageName, this.f1940i);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private void m782a() {
        while (this.f1932a.size() != this.f1938g) {
            Log.i("ClearCache", System.currentTimeMillis() + " ---> waitCallBack");
            try {
                Thread.sleep(50L);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void clearSeperateCache(Context cotext, String pkgName) {
        RootPassage.execRootCmdInJar(pkgName, " -cc ", cotext);
    }

    public static void clearAllCache(PackageManager pm) {
        long blockCount = 0;
        try {
            Method localMethod = pm.getClass().getMethod("freeStorageAndNotify", Long.TYPE, IPackageDataObserver.class);
            File dataDirectory = Environment.getDataDirectory();
            if (dataDirectory == null) {
            }
            if (dataDirectory != null) {
                StatFs statFs = new StatFs(dataDirectory.getPath());
                blockCount = ((long) statFs.getBlockCount()) * ((long) statFs.getBlockSize());
            }
            Long localLong = Long.valueOf(blockCount - 1);
            localMethod.invoke(pm, localLong, new IPackageDataObserver.Stub() { // from class: com.lenovo.performancecenter.service.object.ApplicationDataInfo.2
                @Override // android.content.p001pm.IPackageDataObserver
                public final void onRemoveCompleted(String packageName, boolean succeeded) throws RemoteException {
                }
            });
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
