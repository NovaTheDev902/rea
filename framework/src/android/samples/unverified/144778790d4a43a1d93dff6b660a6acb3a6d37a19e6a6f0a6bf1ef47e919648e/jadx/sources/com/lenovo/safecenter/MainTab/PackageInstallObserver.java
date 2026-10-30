package com.lenovo.safecenter.MainTab;

import android.content.Context;
import android.content.pm.IPackageInstallObserver;
import android.os.Looper;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class PackageInstallObserver extends IPackageInstallObserver.Stub {

    /* JADX INFO: renamed from: a */
    private Context f2782a;

    public PackageInstallObserver(Context c) {
        this.f2782a = c;
    }

    public void packageInstalled(String packageName, int returnCode) {
        Looper.prepare();
        if (returnCode == 1) {
            Toast.makeText(this.f2782a, C0415R.string.install_succeeded, 1).show();
        } else {
            Toast.makeText(this.f2782a, C0415R.string.install_failed, 1).show();
        }
        Looper.loop();
    }
}
