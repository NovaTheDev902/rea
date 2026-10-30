package ledroid.app;

import android.app.Application;
import android.content.Context;
import android.util.Log;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import ledroid.root.LedroidServiceLauncher;
import ledroid.root.RootPermissionException;
import ledroid.root.ShellTerminalController;
import ledroid.services.ILedroidService;
import ledroid.services.LedroidActivityManager;
import ledroid.services.LedroidPackageManager;
import ledroid.services.LedroidSettings;
import ledroid.services.LedroidStatusBarManager;
import ledroid.utils.FileUtils;

/* JADX INFO: loaded from: classes.dex */
public class LedroidApplication extends Application implements LedroidContext {

    /* JADX INFO: renamed from: a */
    private LedroidContextImpl f6302a;

    @Override // android.app.Application
    public void onCreate() {
        super.onCreate();
        if (this.f6302a == null) {
            this.f6302a = new LedroidContextImpl(this);
        }
        LedroidServiceLauncher.initialize(this);
    }

    @Override // android.content.ContextWrapper, android.content.Context, ledroid.app.LedroidContext, android.view.ContextThemeWrapper
    public Object getSystemService(String name) {
        Object service = this.f6302a.getSystemService(name);
        return service != null ? service : super.getSystemService(name);
    }

    public void onLedroidServiceLaunchFailed(File errFile) throws Throwable {
        BufferedReader errReader = null;
        try {
            try {
                BufferedReader errReader2 = new BufferedReader(new InputStreamReader(new FileInputStream(errFile)));
                while (true) {
                    try {
                        String errInfo = errReader2.readLine();
                        if (errInfo == null) {
                            break;
                        } else {
                            Log.w("LedroidApplication", "Error: " + errInfo);
                        }
                    } catch (FileNotFoundException e) {
                        e = e;
                        errReader = errReader2;
                        e.printStackTrace();
                        FileUtils.closeIOCloseable(errReader);
                    } catch (IOException e2) {
                        e = e2;
                        errReader = errReader2;
                        e.printStackTrace();
                        FileUtils.closeIOCloseable(errReader);
                    } catch (Throwable th) {
                        th = th;
                        errReader = errReader2;
                        FileUtils.closeIOCloseable(errReader);
                        throw th;
                    }
                }
                errFile.delete();
                FileUtils.closeIOCloseable(errReader2);
                errReader = errReader2;
            } catch (Throwable th2) {
                th = th2;
            }
        } catch (FileNotFoundException e3) {
            e = e3;
        } catch (IOException e4) {
            e = e4;
        }
    }

    @Override // ledroid.app.LedroidContext
    public boolean hasRootPermission() {
        return this.f6302a.hasRootPermission();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidSettings getLedroidSettings() {
        return this.f6302a.getLedroidSettings();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidActivityManager getLedroidActivityManager() {
        return this.f6302a.getLedroidActivityManager();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidPackageManager getLedroidPackageManager() {
        return this.f6302a.getLedroidPackageManager();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidStatusBarManager getLedroidStatusBarManager() {
        return this.f6302a.getLedroidStatusBarManager();
    }

    @Override // ledroid.app.LedroidContext
    public ShellTerminalController getShellTerminalController() {
        return this.f6302a.getShellTerminalController();
    }

    @Override // ledroid.app.LedroidContext
    public Context getContext() {
        return this;
    }

    public ILedroidService getLedroidService() {
        return LedroidServiceLauncher.getLedroidService();
    }

    public void tryToLaunchLedroidService() throws RootPermissionException {
        LedroidServiceLauncher.launchLedroidService();
    }
}
