package ledroid.root;

import android.os.IBinder;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;
import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import ledroid.app.LedroidApplication;
import ledroid.root.res.NBJarFile;
import ledroid.services.ILedroidService;
import ledroid.utils.AndroidResources;
import ledroid.utils.MountPoint;

/* JADX INFO: loaded from: classes.dex */
public final class LedroidServiceLauncher {
    public static final String SERVICE_NAME = "lenovo";

    /* JADX INFO: renamed from: a */
    private static LedroidApplication f6307a = null;

    /* JADX INFO: renamed from: b */
    private static ILedroidService f6308b = null;

    /* JADX INFO: renamed from: c */
    private static long f6309c = -1;

    /* JADX INFO: renamed from: d */
    private static NBJarFile f6310d = null;

    /* JADX INFO: renamed from: e */
    private static String f6311e;

    /* JADX INFO: renamed from: b */
    static /* synthetic */ ILedroidService m2652b() {
        f6308b = null;
        return null;
    }

    private LedroidServiceLauncher() {
    }

    public static synchronized void initialize(LedroidApplication application) {
        f6307a = application;
        f6311e = application.getFilesDir() + File.separator + "LedroidServiceLauncherError";
        new Thread(new Runnable() { // from class: ledroid.root.LedroidServiceLauncher.1
            @Override // java.lang.Runnable
            public final void run() {
                try {
                    LedroidServiceLauncher.launchLedroidService();
                } catch (RootPermissionException e) {
                    Log.w("LedroidApplication", "No Root Permission: " + e.getLocalizedMessage());
                }
            }
        }).start();
    }

    public static synchronized void launchLedroidService() throws RootPermissionException {
        synchronized (LedroidServiceLauncher.class) {
            if (f6307a == null) {
                Log.w("LedroidApplication", "LedroidApplication is Null! Cannot launch Ledroid Service.");
            } else {
                if (!f6307a.hasRootPermission()) {
                    throw new RootPermissionException("Need Root Permission to lauch ledroid service.");
                }
                AndroidResources androidResources = new AndroidResources(f6307a.getResources(), f6307a.getPackageName());
                f6310d = new NBJarFile(f6307a, androidResources.getIdentifier("raw", "nb"), f6307a.getFilesDir());
                long currentTimeMillis = System.currentTimeMillis();
                if (f6309c == -1 && currentTimeMillis - f6309c >= 1000) {
                    if (getLedroidService() != null) {
                        if (!m2655e()) {
                            final int newVersionCode = f6310d.getNewVersionCode();
                            String[] list = new File("/data/dalvik-cache/").list(new FilenameFilter() { // from class: ledroid.root.LedroidServiceLauncher.2
                                @Override // java.io.FilenameFilter
                                public final boolean accept(File dir, String filename) {
                                    int v;
                                    return filename.contains("@nb.") && (v = LedroidServiceLauncher.f6310d.getNbJarFileVersion(filename.split("@")[4])) > 0 && v < newVersionCode;
                                }
                            });
                            if (list != null) {
                                StringBuffer stringBuffer = new StringBuffer();
                                for (String str : list) {
                                    stringBuffer.append(str).append(" ");
                                }
                                ShellTerminalController shellTerminalController = f6307a.getShellTerminalController();
                                if (shellTerminalController.hasRootPermission()) {
                                    try {
                                        new ShellCommand(shellTerminalController.getRootTransport()).addCommand("mount -oremount,rw /data /data").addCommand("mount -oremount,rw", MountPoint.getDeviceName("/data"), "/data").addCommand("rm ", stringBuffer.toString()).addCommand("mount -oremount,ro /data /data").addCommand("mount -oremount,ro", MountPoint.getDeviceName("/data"), "/data").exec();
                                    } catch (IOException e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                            m2651a("--stop-lenovo-server");
                        }
                    }
                    f6309c = System.currentTimeMillis();
                    File errFile = new File(f6311e);
                    if (errFile.exists()) {
                        errFile.delete();
                    }
                    try {
                        errFile.createNewFile();
                    } catch (IOException e2) {
                        e2.printStackTrace();
                    }
                    m2651a("--start-lenovo-server");
                    m2650a(m2654d());
                    if (errFile.exists() && errFile.length() > 0) {
                        f6307a.onLedroidServiceLaunchFailed(errFile);
                    }
                }
            }
        }
    }

    /* JADX INFO: renamed from: c */
    private static void m2653c() {
        while (true) {
            try {
                Thread.sleep(200L);
                return;
            } catch (InterruptedException e) {
            }
        }
    }

    /* JADX INFO: renamed from: d */
    private static IBinder m2654d() {
        m2653c();
        IBinder binder = null;
        for (int cnt = 0; cnt < 5 && (binder = ServiceManager.getService(SERVICE_NAME)) == null; cnt++) {
            m2653c();
        }
        return binder;
    }

    /* JADX INFO: renamed from: a */
    private static void m2651a(String arg) {
        try {
            ShellTerminalController shellTerminalController = f6307a.getShellTerminalController();
            if (shellTerminalController.hasRootPermission()) {
                ShellCommand cmd = new ShellCommand(shellTerminalController.getRootTransport());
                String ldLibraryPath = System.getenv("LD_LIBRARY_PATH");
                if (ldLibraryPath == null) {
                    cmd.addCommand("export", "LD_LIBRARY_PATH=/vendor/lib:/system/lib");
                } else {
                    cmd.addCommand("export", "LD_LIBRARY_PATH=" + ldLibraryPath);
                }
                cmd.addCommand("export", "CLASSPATH=" + f6310d.getAbsolutePath()).addCommand("/system/bin/app_process", f6307a.getFilesDir().getAbsolutePath(), "ledroid.server.LenovoServer", arg, "2>", f6311e).exec();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: e */
    private static synchronized boolean m2655e() {
        boolean z = false;
        synchronized (LedroidServiceLauncher.class) {
            if (f6308b != null) {
                int runningVersion = 0;
                try {
                    runningVersion = f6308b.getVersionCode();
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
                f6310d.updateIfNeed();
                if (runningVersion >= f6310d.getNewVersionCode()) {
                    z = true;
                }
            }
        }
        return z;
    }

    /* JADX INFO: renamed from: a */
    private static void m2650a(IBinder svrBinder) {
        Log.i("liubin", "initNativeLedroidService: [" + (svrBinder == null ? "NULL" : String.valueOf(svrBinder.hashCode())) + "]");
        if (svrBinder != null) {
            f6308b = ILedroidService.Stub.asInterface(svrBinder);
            try {
                svrBinder.linkToDeath(new C1094a((byte) 0), 0);
            } catch (RemoteException e) {
            }
        }
    }

    public static synchronized ILedroidService getLedroidService() {
        ILedroidService iLedroidService;
        if (f6308b != null) {
            iLedroidService = f6308b;
        } else {
            IBinder svrBinder = ServiceManager.getService(SERVICE_NAME);
            m2650a(svrBinder);
            iLedroidService = f6308b;
        }
        return iLedroidService;
    }

    /* JADX INFO: renamed from: ledroid.root.LedroidServiceLauncher$a */
    private static class C1094a implements IBinder.DeathRecipient {
        private C1094a() {
        }

        /* synthetic */ C1094a(byte b) {
            this();
        }

        @Override // android.os.IBinder.DeathRecipient
        public final void binderDied() {
            LedroidServiceLauncher.m2652b();
            try {
                LedroidServiceLauncher.launchLedroidService();
            } catch (RootPermissionException e) {
            }
        }
    }
}
