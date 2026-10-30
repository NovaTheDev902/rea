package ledroid.services;

import android.content.ComponentName;
import android.content.Context;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.RemoteException;
import ledroid.root.RootPermissionException;

/* JADX INFO: loaded from: classes.dex */
public class LedroidPackageManager extends LedroidSupport {

    /* JADX INFO: renamed from: a */
    private PackageManager f6363a;

    public LedroidPackageManager(Context ctx) {
        super(ctx);
        this.f6363a = ctx.getPackageManager();
    }

    public PackageManager getAndroidPackageManager() {
        return this.f6363a;
    }

    public void setApplicationEnabledSetting(String packageName, int newState, int flags) throws RootPermissionException {
        try {
            getLenovoManager().setApplicationEnabledSetting(packageName, newState, flags);
        } catch (RemoteException e1) {
            e1.printStackTrace();
        }
    }

    public void setComponentEnabledSetting(ComponentName componentName, int newState, int flags) throws RootPermissionException {
        try {
            getLenovoManager().setComponentEnabledSetting(componentName, newState, flags);
        } catch (RemoteException e1) {
            e1.printStackTrace();
        }
    }

    public void addPreferredActivity(IntentFilter filter, int match, ComponentName[] set, ComponentName activity) throws RootPermissionException {
        try {
            getLenovoManager().addPreferredActivity(filter, match, set, activity);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    /* JADX WARN: Code duplicated, block: B:33:0x00e3  */
    /*  JADX ERROR: JadxRuntimeException in pass: RegionMakerVisitor
        jadx.core.utils.exceptions.JadxRuntimeException: Not found exit edge by exit block: B:34:0x00f6
        	at jadx.core.dex.visitors.regions.maker.LoopRegionMaker.checkLoopExits(LoopRegionMaker.java:272)
        	at jadx.core.dex.visitors.regions.maker.LoopRegionMaker.makeLoopRegion(LoopRegionMaker.java:237)
        	at jadx.core.dex.visitors.regions.maker.LoopRegionMaker.process(LoopRegionMaker.java:80)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.traverse(RegionMaker.java:92)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.makeRegion(RegionMaker.java:69)
        	at jadx.core.dex.visitors.regions.maker.IfRegionMaker.process(IfRegionMaker.java:117)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.traverse(RegionMaker.java:109)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.makeRegion(RegionMaker.java:69)
        	at jadx.core.dex.visitors.regions.maker.IfRegionMaker.process(IfRegionMaker.java:111)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.traverse(RegionMaker.java:109)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.makeRegion(RegionMaker.java:69)
        	at jadx.core.dex.visitors.regions.maker.IfRegionMaker.process(IfRegionMaker.java:111)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.traverse(RegionMaker.java:109)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.makeRegion(RegionMaker.java:69)
        	at jadx.core.dex.visitors.regions.maker.LoopRegionMaker.process(LoopRegionMaker.java:162)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.traverse(RegionMaker.java:92)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.makeRegion(RegionMaker.java:69)
        	at jadx.core.dex.visitors.regions.maker.RegionMaker.makeMthRegion(RegionMaker.java:49)
        	at jadx.core.dex.visitors.regions.RegionMakerVisitor.visit(RegionMakerVisitor.java:25)
        */
    public void addPreferredActivity(android.content.Intent r27, android.content.ComponentName r28) throws ledroid.root.RootPermissionException {
        /*
            Method dump skipped, instruction units count: 435
            To view this dump add '--comments-level debug' option
        */
        throw new UnsupportedOperationException("Method not decompiled: ledroid.services.LedroidPackageManager.addPreferredActivity(android.content.Intent, android.content.ComponentName):void");
    }

    public void clearPackagePreferredActivities(String packageName) throws RootPermissionException {
        try {
            getLenovoManager().clearPackagePreferredActivities(packageName);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    public void installPackage(Uri packageURI, ILedroidPackageInstallObserver observer, int flags, String installerPackageName) throws RootPermissionException {
        try {
            getLenovoManager().installPackage(packageURI, observer, flags, installerPackageName);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    public void deleteApplicationCacheFiles(String packageName, ILedroidPackageDataObserver observer) throws RootPermissionException {
        try {
            getLenovoManager().deleteApplicationCacheFiles(packageName, observer);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    public void freeStorageAndNotify(long freeStorageSize, ILedroidPackageDataObserver observer) throws RootPermissionException {
        try {
            getLenovoManager().freeStorageAndNotify(freeStorageSize, observer);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    public void movePackage(String packageName, ILedroidPackageMoveObserver observer, int flags) throws RootPermissionException {
        try {
            getLenovoManager().movePackage(packageName, observer, flags);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    public void deletePackage(String packageName, ILedroidPackageDeleteObserver observer, int flags) throws RootPermissionException {
        try {
            getLenovoManager().deletePackage(packageName, observer, flags);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
