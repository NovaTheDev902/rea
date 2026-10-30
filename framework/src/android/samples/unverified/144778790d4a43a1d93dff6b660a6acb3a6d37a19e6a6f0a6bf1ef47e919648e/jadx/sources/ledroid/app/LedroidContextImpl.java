package ledroid.app;

import android.content.Context;
import java.util.HashMap;
import ledroid.root.ShellTerminalController;
import ledroid.services.LedroidActivityManager;
import ledroid.services.LedroidPackageManager;
import ledroid.services.LedroidSettings;
import ledroid.services.LedroidStatusBarManager;

/* JADX INFO: loaded from: classes.dex */
public class LedroidContextImpl implements LedroidContext {

    /* JADX INFO: renamed from: b */
    private static final HashMap<String, AbstractC1091a> f6303b = new HashMap<>();

    /* JADX INFO: renamed from: a */
    private Context f6304a;

    public LedroidContextImpl(Context context) {
        this.f6304a = context;
    }

    static {
        m2646a(LedroidContext.LEDROID_SETTINGS_WRAPPER, new AbstractC1091a() { // from class: ledroid.app.LedroidContextImpl.1
            @Override // ledroid.app.LedroidContextImpl.AbstractC1091a
            /* JADX INFO: renamed from: a */
            public final Object mo2647a(Context context) {
                return new LedroidSettings(context);
            }
        });
        m2646a(LedroidContext.LEDROID_ACTIVITY_MANAGER, new AbstractC1091a() { // from class: ledroid.app.LedroidContextImpl.2
            @Override // ledroid.app.LedroidContextImpl.AbstractC1091a
            /* JADX INFO: renamed from: a */
            public final Object mo2647a(Context context) {
                return new LedroidActivityManager(context);
            }
        });
        m2646a(LedroidContext.LEDROID_PACKAGE_MANAGER, new AbstractC1091a() { // from class: ledroid.app.LedroidContextImpl.3
            @Override // ledroid.app.LedroidContextImpl.AbstractC1091a
            /* JADX INFO: renamed from: a */
            public final Object mo2647a(Context context) {
                return new LedroidPackageManager(context);
            }
        });
        m2646a(LedroidContext.LEDROID_STATUSBAR_MANAGER, new AbstractC1091a() { // from class: ledroid.app.LedroidContextImpl.4
            @Override // ledroid.app.LedroidContextImpl.AbstractC1091a
            /* JADX INFO: renamed from: a */
            public final Object mo2647a(Context context) {
                return new LedroidStatusBarManager(context);
            }
        });
        m2646a(LedroidContext.LEDROID_ROOT_TIMINAL, new AbstractC1091a() { // from class: ledroid.app.LedroidContextImpl.5
            @Override // ledroid.app.LedroidContextImpl.AbstractC1091a
            /* JADX INFO: renamed from: a */
            public final Object mo2647a(Context context) {
                return new ShellTerminalController(context);
            }
        });
    }

    /* JADX INFO: renamed from: ledroid.app.LedroidContextImpl$a */
    static abstract class AbstractC1091a {

        /* JADX INFO: renamed from: a */
        private Object f6305a = null;

        /* JADX INFO: renamed from: a */
        public abstract Object mo2647a(Context context);

        AbstractC1091a() {
        }

        /* JADX INFO: renamed from: b */
        public final Object m2648b(Context context) {
            if (this.f6305a == null) {
                this.f6305a = mo2647a(context);
            }
            return this.f6305a;
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m2646a(String name, AbstractC1091a fetcher) {
        f6303b.put(name, fetcher);
    }

    @Override // ledroid.app.LedroidContext, android.view.ContextThemeWrapper, android.content.ContextWrapper, android.content.Context
    public Object getSystemService(String name) {
        AbstractC1091a fetcher = f6303b.get(name);
        if (fetcher != null) {
            return fetcher.m2648b(this.f6304a);
        }
        return null;
    }

    @Override // ledroid.app.LedroidContext
    public boolean hasRootPermission() {
        return getShellTerminalController().hasRootPermission();
    }

    @Override // ledroid.app.LedroidContext
    public Context getContext() {
        return this.f6304a;
    }

    @Override // ledroid.app.LedroidContext
    public LedroidActivityManager getLedroidActivityManager() {
        return (LedroidActivityManager) getSystemService(LedroidContext.LEDROID_ACTIVITY_MANAGER);
    }

    @Override // ledroid.app.LedroidContext
    public LedroidPackageManager getLedroidPackageManager() {
        return (LedroidPackageManager) getSystemService(LedroidContext.LEDROID_PACKAGE_MANAGER);
    }

    @Override // ledroid.app.LedroidContext
    public LedroidStatusBarManager getLedroidStatusBarManager() {
        return (LedroidStatusBarManager) getSystemService(LedroidContext.LEDROID_STATUSBAR_MANAGER);
    }

    @Override // ledroid.app.LedroidContext
    public ShellTerminalController getShellTerminalController() {
        return (ShellTerminalController) getSystemService(LedroidContext.LEDROID_ROOT_TIMINAL);
    }

    @Override // ledroid.app.LedroidContext
    public LedroidSettings getLedroidSettings() {
        return (LedroidSettings) getSystemService(LedroidContext.LEDROID_SETTINGS_WRAPPER);
    }
}
