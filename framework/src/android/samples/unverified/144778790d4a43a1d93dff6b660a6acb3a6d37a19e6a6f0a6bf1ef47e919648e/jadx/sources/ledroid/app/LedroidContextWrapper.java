package ledroid.app;

import android.content.Context;
import ledroid.root.ShellTerminalController;
import ledroid.services.LedroidActivityManager;
import ledroid.services.LedroidPackageManager;
import ledroid.services.LedroidSettings;
import ledroid.services.LedroidStatusBarManager;

/* JADX INFO: loaded from: classes.dex */
public class LedroidContextWrapper implements LedroidContext {

    /* JADX INFO: renamed from: a */
    private LedroidContext f6306a;

    public LedroidContextWrapper(LedroidContext context) {
        this.f6306a = context;
    }

    @Override // ledroid.app.LedroidContext, android.view.ContextThemeWrapper, android.content.ContextWrapper, android.content.Context
    public Object getSystemService(String name) {
        return this.f6306a.getSystemService(name);
    }

    @Override // ledroid.app.LedroidContext
    public boolean hasRootPermission() {
        return this.f6306a.hasRootPermission();
    }

    @Override // ledroid.app.LedroidContext
    public Context getContext() {
        return this.f6306a.getContext();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidActivityManager getLedroidActivityManager() {
        return this.f6306a.getLedroidActivityManager();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidPackageManager getLedroidPackageManager() {
        return this.f6306a.getLedroidPackageManager();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidStatusBarManager getLedroidStatusBarManager() {
        return this.f6306a.getLedroidStatusBarManager();
    }

    @Override // ledroid.app.LedroidContext
    public ShellTerminalController getShellTerminalController() {
        return this.f6306a.getShellTerminalController();
    }

    @Override // ledroid.app.LedroidContext
    public LedroidSettings getLedroidSettings() {
        return this.f6306a.getLedroidSettings();
    }
}
