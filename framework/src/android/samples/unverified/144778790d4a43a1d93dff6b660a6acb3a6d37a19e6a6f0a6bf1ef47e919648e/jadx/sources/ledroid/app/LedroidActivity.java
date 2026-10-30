package ledroid.app;

import android.app.Activity;
import android.content.ComponentCallbacks2;
import android.content.Context;
import android.os.Bundle;
import ledroid.root.ShellTerminalController;
import ledroid.services.LedroidActivityManager;
import ledroid.services.LedroidPackageManager;
import ledroid.services.LedroidSettings;
import ledroid.services.LedroidStatusBarManager;

/* JADX INFO: loaded from: classes.dex */
public class LedroidActivity extends Activity implements LedroidContext {

    /* JADX INFO: renamed from: a */
    private LedroidContext f6301a = null;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        m2645a();
    }

    @Override // android.app.Activity, android.view.ContextThemeWrapper, android.content.ContextWrapper, android.content.Context, ledroid.app.LedroidContext
    public Object getSystemService(String name) {
        m2645a();
        if (this.f6301a == null) {
            return super.getSystemService(name);
        }
        Object service = super.getSystemService(name);
        return service == null ? this.f6301a.getSystemService(name) : service;
    }

    /* JADX INFO: renamed from: a */
    private void m2645a() {
        if (this.f6301a == null) {
            try {
                ComponentCallbacks2 application = getApplication();
                if (application != null) {
                    this.f6301a = (LedroidContext) application;
                }
            } catch (ClassCastException e) {
                throw new LedroidContextException("Are you sure that your application is implemented LedroidApplication and configured in AndroidManifest.xml.", e);
            }
        }
    }

    @Override // ledroid.app.LedroidContext
    public boolean hasRootPermission() {
        return this.f6301a.hasRootPermission();
    }

    @Override // ledroid.app.LedroidContext
    public Context getContext() {
        return this;
    }

    public LedroidContext getLedroidContext() {
        return this.f6301a;
    }

    @Override // ledroid.app.LedroidContext
    public LedroidActivityManager getLedroidActivityManager() {
        return this.f6301a.getLedroidActivityManager();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidPackageManager getLedroidPackageManager() {
        return this.f6301a.getLedroidPackageManager();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidStatusBarManager getLedroidStatusBarManager() {
        return this.f6301a.getLedroidStatusBarManager();
    }

    @Override // ledroid.app.LedroidContext
    public ShellTerminalController getShellTerminalController() {
        return this.f6301a.getShellTerminalController();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidSettings getLedroidSettings() {
        return this.f6301a.getLedroidSettings();
    }
}
