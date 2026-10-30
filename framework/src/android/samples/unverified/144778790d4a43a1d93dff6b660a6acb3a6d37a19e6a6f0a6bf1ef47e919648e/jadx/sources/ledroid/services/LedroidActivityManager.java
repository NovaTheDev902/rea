package ledroid.services;

import android.app.ActivityManager;
import android.app.ActivityManagerNative;
import android.app.IActivityManager;
import android.content.Context;
import android.os.Build;
import android.os.RemoteException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.List;
import ledroid.root.RootPermissionException;
import ledroid.utils.ReflectClass;

/* JADX INFO: loaded from: classes.dex */
public class LedroidActivityManager extends LedroidSupport {

    /* JADX INFO: renamed from: a */
    private IActivityManager f6361a;

    /* JADX INFO: renamed from: b */
    private ReflectClass f6362b;

    public LedroidActivityManager(Context ctx) {
        super(ctx);
        this.f6362b = new ReflectClass((Class<?>) IActivityManager.class);
        try {
            this.f6362b.setInstance(getAndroidActivityManager());
        } catch (RemoteException e) {
        }
    }

    public IActivityManager getAndroidActivityManager() throws RemoteException {
        if (this.f6361a == null) {
            this.f6361a = ActivityManagerNative.getDefault();
        }
        return this.f6361a;
    }

    public List<ActivityManager.RecentTaskInfo> getRecentTasks(int maxNum, int flags) throws SecurityException {
        List<ActivityManager.RecentTaskInfo> recentTasks = null;
        Method getRecentTasks = this.f6362b.getDeclaredMethod("getRecentTasks", Integer.TYPE, Integer.TYPE);
        try {
            if (getRecentTasks != null) {
                recentTasks = (List) this.f6362b.invoke(getRecentTasks, Integer.valueOf(maxNum), 0);
            } else {
                Method getRecentTasks2 = this.f6362b.getDeclaredMethod("getRecentTasks", Integer.TYPE, Integer.TYPE, Integer.TYPE);
                if (getRecentTasks2 != null) {
                    recentTasks = (List) this.f6362b.invoke(getRecentTasks2, Integer.valueOf(maxNum), 0, 0);
                }
            }
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e2) {
            e2.printStackTrace();
        }
        return recentTasks;
    }

    public void clearRecentTask(int flags) throws RootPermissionException {
        try {
            getLenovoManager().clearRecentTask(flags);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    public void forceStopPackage(String pkgName) {
        try {
            try {
                getLenovoManager().forceStopPackage(pkgName);
            } catch (RootPermissionException e) {
                try {
                    if (Build.VERSION.SDK_INT > 16) {
                        Method declaredMethod = this.f6362b.getDeclaredMethod("killBackgroundProcesses", String.class, Integer.TYPE);
                        if (declaredMethod != null) {
                            this.f6362b.invoke(declaredMethod, pkgName, 0);
                        }
                    } else {
                        Method declaredMethod2 = this.f6362b.getDeclaredMethod("killBackgroundProcesses", String.class);
                        if (declaredMethod2 != null) {
                            this.f6362b.invoke(declaredMethod2, pkgName);
                        }
                    }
                } catch (Exception e2) {
                }
            }
        } catch (RemoteException e3) {
            e3.printStackTrace();
        }
    }
}
