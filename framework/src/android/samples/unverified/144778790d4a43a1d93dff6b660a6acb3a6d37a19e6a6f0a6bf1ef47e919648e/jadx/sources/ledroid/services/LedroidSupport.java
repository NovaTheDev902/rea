package ledroid.services;

import android.content.Context;
import ledroid.app.LedroidApplication;
import ledroid.app.LedroidContext;
import ledroid.app.LedroidContextException;
import ledroid.root.RootPermissionException;
import ledroid.root.ShellTerminalController;

/* JADX INFO: loaded from: classes.dex */
public class LedroidSupport {

    /* JADX INFO: renamed from: a */
    private Context f6369a;

    public LedroidSupport(Context ctx) {
        this.f6369a = ctx;
    }

    public Context getContext() {
        return this.f6369a;
    }

    public boolean hasRootPermission() {
        ShellTerminalController shellController = (ShellTerminalController) this.f6369a.getSystemService(LedroidContext.LEDROID_ROOT_TIMINAL);
        return shellController.hasRootPermission();
    }

    protected ILedroidService getLenovoManager() throws RootPermissionException {
        if (!hasRootPermission()) {
            throw new RootPermissionException();
        }
        LedroidApplication ledroidApplication = null;
        if (this.f6369a instanceof LedroidApplication) {
            ledroidApplication = (LedroidApplication) this.f6369a;
        } else {
            Context application = this.f6369a.getApplicationContext();
            if (application instanceof LedroidApplication) {
                ledroidApplication = (LedroidApplication) application;
            }
        }
        if (ledroidApplication == null) {
            throw new LedroidContextException("Application must be LedroidApplication Instance!");
        }
        ILedroidService service = ledroidApplication.getLedroidService();
        if (service == null) {
            ledroidApplication.tryToLaunchLedroidService();
            service = ledroidApplication.getLedroidService();
            if (service == null) {
                throw new RootPermissionException("Cannt get Ledroid Service");
            }
        }
        return service;
    }
}
