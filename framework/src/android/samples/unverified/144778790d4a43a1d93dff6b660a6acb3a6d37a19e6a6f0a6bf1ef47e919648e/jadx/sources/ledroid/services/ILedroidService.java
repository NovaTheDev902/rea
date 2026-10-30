package ledroid.services;

import android.content.ComponentName;
import android.content.IntentFilter;
import android.net.Uri;
import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface ILedroidService extends IInterface {
    void addPreferredActivity(IntentFilter intentFilter, int i, ComponentName[] componentNameArr, ComponentName componentName) throws RemoteException;

    void clearPackagePreferredActivities(String str) throws RemoteException;

    void clearRecentTask(int i) throws RemoteException;

    void deleteApplicationCacheFiles(String str, ILedroidPackageDataObserver iLedroidPackageDataObserver) throws RemoteException;

    void deletePackage(String str, ILedroidPackageDeleteObserver iLedroidPackageDeleteObserver, int i) throws RemoteException;

    void forceStopPackage(String str) throws RemoteException;

    void freeStorageAndNotify(long j, ILedroidPackageDataObserver iLedroidPackageDataObserver) throws RemoteException;

    String getSettingsSecureString(String str) throws RemoteException;

    String getSettingsSystemString(String str) throws RemoteException;

    int getVersionCode() throws RemoteException;

    void installPackage(Uri uri, ILedroidPackageInstallObserver iLedroidPackageInstallObserver, int i, String str) throws RemoteException;

    void killProcess(int i) throws RemoteException;

    void killProcesses(int[] iArr) throws RemoteException;

    void movePackage(String str, ILedroidPackageMoveObserver iLedroidPackageMoveObserver, int i) throws RemoteException;

    boolean putSettingsSecureString(String str, String str2) throws RemoteException;

    boolean putSettingsSystemString(String str, String str2) throws RemoteException;

    boolean removeRecentTask(int i, int i2) throws RemoteException;

    void setApplicationEnabledSetting(String str, int i, int i2) throws RemoteException;

    void setComponentEnabledSetting(ComponentName componentName, int i, int i2) throws RemoteException;

    void setStatusBarUsable(boolean z) throws RemoteException;

    public static abstract class Stub extends Binder implements ILedroidService {
        public Stub() {
            attachInterface(this, "ledroid.services.ILedroidService");
        }

        public static ILedroidService asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("ledroid.services.ILedroidService");
            if (iin != null && (iin instanceof ILedroidService)) {
                return (ILedroidService) iin;
            }
            return new C1106a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            Uri _arg0;
            ComponentName _arg1;
            IntentFilter _arg2;
            ComponentName _arg3;
            switch (code) {
                case 1:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    int _result = getVersionCode();
                    reply.writeNoException();
                    reply.writeInt(_result);
                    return true;
                case 2:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    boolean _arg4 = data.readInt() != 0;
                    setStatusBarUsable(_arg4);
                    reply.writeNoException();
                    return true;
                case 3:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    int _arg5 = data.readInt();
                    int _arg6 = data.readInt();
                    boolean _result2 = removeRecentTask(_arg5, _arg6);
                    reply.writeNoException();
                    reply.writeInt(_result2 ? 1 : 0);
                    return true;
                case 4:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    int _arg7 = data.readInt();
                    clearRecentTask(_arg7);
                    reply.writeNoException();
                    return true;
                case 5:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg8 = data.readString();
                    forceStopPackage(_arg8);
                    reply.writeNoException();
                    return true;
                case 6:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    if (data.readInt() != 0) {
                        _arg2 = (IntentFilter) IntentFilter.CREATOR.createFromParcel(data);
                    } else {
                        _arg2 = null;
                    }
                    int _arg9 = data.readInt();
                    ComponentName[] _arg10 = (ComponentName[]) data.createTypedArray(ComponentName.CREATOR);
                    if (data.readInt() != 0) {
                        _arg3 = (ComponentName) ComponentName.CREATOR.createFromParcel(data);
                    } else {
                        _arg3 = null;
                    }
                    addPreferredActivity(_arg2, _arg9, _arg10, _arg3);
                    reply.writeNoException();
                    return true;
                case 7:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg11 = data.readString();
                    clearPackagePreferredActivities(_arg11);
                    reply.writeNoException();
                    return true;
                case 8:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    if (data.readInt() != 0) {
                        _arg1 = (ComponentName) ComponentName.CREATOR.createFromParcel(data);
                    } else {
                        _arg1 = null;
                    }
                    int _arg12 = data.readInt();
                    int _arg13 = data.readInt();
                    setComponentEnabledSetting(_arg1, _arg12, _arg13);
                    reply.writeNoException();
                    return true;
                case 9:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg14 = data.readString();
                    int _arg15 = data.readInt();
                    int _arg16 = data.readInt();
                    setApplicationEnabledSetting(_arg14, _arg15, _arg16);
                    reply.writeNoException();
                    return true;
                case 10:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg17 = data.readString();
                    ILedroidPackageDataObserver _arg18 = ILedroidPackageDataObserver.Stub.asInterface(data.readStrongBinder());
                    deleteApplicationCacheFiles(_arg17, _arg18);
                    reply.writeNoException();
                    return true;
                case 11:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    long _arg19 = data.readLong();
                    ILedroidPackageDataObserver _arg20 = ILedroidPackageDataObserver.Stub.asInterface(data.readStrongBinder());
                    freeStorageAndNotify(_arg19, _arg20);
                    reply.writeNoException();
                    return true;
                case 12:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    if (data.readInt() != 0) {
                        _arg0 = (Uri) Uri.CREATOR.createFromParcel(data);
                    } else {
                        _arg0 = null;
                    }
                    ILedroidPackageInstallObserver _arg21 = ILedroidPackageInstallObserver.Stub.asInterface(data.readStrongBinder());
                    int _arg22 = data.readInt();
                    String _arg23 = data.readString();
                    installPackage(_arg0, _arg21, _arg22, _arg23);
                    reply.writeNoException();
                    return true;
                case 13:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg24 = data.readString();
                    ILedroidPackageDeleteObserver _arg25 = ILedroidPackageDeleteObserver.Stub.asInterface(data.readStrongBinder());
                    int _arg26 = data.readInt();
                    deletePackage(_arg24, _arg25, _arg26);
                    reply.writeNoException();
                    return true;
                case 14:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg27 = data.readString();
                    ILedroidPackageMoveObserver _arg28 = ILedroidPackageMoveObserver.Stub.asInterface(data.readStrongBinder());
                    int _arg29 = data.readInt();
                    movePackage(_arg27, _arg28, _arg29);
                    reply.writeNoException();
                    return true;
                case 15:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg30 = data.readString();
                    String _result3 = getSettingsSystemString(_arg30);
                    reply.writeNoException();
                    reply.writeString(_result3);
                    return true;
                case 16:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg31 = data.readString();
                    String _arg32 = data.readString();
                    boolean _result4 = putSettingsSystemString(_arg31, _arg32);
                    reply.writeNoException();
                    reply.writeInt(_result4 ? 1 : 0);
                    return true;
                case 17:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg33 = data.readString();
                    String _result5 = getSettingsSecureString(_arg33);
                    reply.writeNoException();
                    reply.writeString(_result5);
                    return true;
                case 18:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    String _arg34 = data.readString();
                    String _arg35 = data.readString();
                    boolean _result6 = putSettingsSecureString(_arg34, _arg35);
                    reply.writeNoException();
                    reply.writeInt(_result6 ? 1 : 0);
                    return true;
                case 19:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    int _arg36 = data.readInt();
                    killProcess(_arg36);
                    reply.writeNoException();
                    return true;
                case 20:
                    data.enforceInterface("ledroid.services.ILedroidService");
                    int[] _arg37 = data.createIntArray();
                    killProcesses(_arg37);
                    reply.writeNoException();
                    return true;
                case 1598968902:
                    reply.writeString("ledroid.services.ILedroidService");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: ledroid.services.ILedroidService$Stub$a */
        private static class C1106a implements ILedroidService {

            /* JADX INFO: renamed from: a */
            private IBinder f6360a;

            C1106a(IBinder remote) {
                this.f6360a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f6360a;
            }

            @Override // ledroid.services.ILedroidService
            public final int getVersionCode() throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    this.f6360a.transact(1, _data, _reply, 0);
                    _reply.readException();
                    int _result = _reply.readInt();
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void setStatusBarUsable(boolean usable) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeInt(usable ? 1 : 0);
                    this.f6360a.transact(2, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final boolean removeRecentTask(int taskId, int flags) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeInt(taskId);
                    _data.writeInt(flags);
                    this.f6360a.transact(3, _data, _reply, 0);
                    _reply.readException();
                    boolean _result = _reply.readInt() != 0;
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void clearRecentTask(int flags) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeInt(flags);
                    this.f6360a.transact(4, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void forceStopPackage(String pkgs) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(pkgs);
                    this.f6360a.transact(5, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void addPreferredActivity(IntentFilter filter, int match, ComponentName[] set, ComponentName activity) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    if (filter != null) {
                        _data.writeInt(1);
                        filter.writeToParcel(_data, 0);
                    } else {
                        _data.writeInt(0);
                    }
                    _data.writeInt(match);
                    _data.writeTypedArray(set, 0);
                    if (activity != null) {
                        _data.writeInt(1);
                        activity.writeToParcel(_data, 0);
                    } else {
                        _data.writeInt(0);
                    }
                    this.f6360a.transact(6, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void clearPackagePreferredActivities(String packageName) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(packageName);
                    this.f6360a.transact(7, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void setComponentEnabledSetting(ComponentName componentName, int newState, int flags) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    if (componentName != null) {
                        _data.writeInt(1);
                        componentName.writeToParcel(_data, 0);
                    } else {
                        _data.writeInt(0);
                    }
                    _data.writeInt(newState);
                    _data.writeInt(flags);
                    this.f6360a.transact(8, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void setApplicationEnabledSetting(String packageName, int newState, int flags) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(packageName);
                    _data.writeInt(newState);
                    _data.writeInt(flags);
                    this.f6360a.transact(9, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void deleteApplicationCacheFiles(String packageName, ILedroidPackageDataObserver observer) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(packageName);
                    _data.writeStrongBinder(observer != null ? observer.asBinder() : null);
                    this.f6360a.transact(10, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void freeStorageAndNotify(long freeStorageSize, ILedroidPackageDataObserver observer) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeLong(freeStorageSize);
                    _data.writeStrongBinder(observer != null ? observer.asBinder() : null);
                    this.f6360a.transact(11, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void installPackage(Uri packageURI, ILedroidPackageInstallObserver observer, int flags, String installerPackageName) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    if (packageURI != null) {
                        _data.writeInt(1);
                        packageURI.writeToParcel(_data, 0);
                    } else {
                        _data.writeInt(0);
                    }
                    _data.writeStrongBinder(observer != null ? observer.asBinder() : null);
                    _data.writeInt(flags);
                    _data.writeString(installerPackageName);
                    this.f6360a.transact(12, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void deletePackage(String packageName, ILedroidPackageDeleteObserver observer, int flags) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(packageName);
                    _data.writeStrongBinder(observer != null ? observer.asBinder() : null);
                    _data.writeInt(flags);
                    this.f6360a.transact(13, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void movePackage(String packageName, ILedroidPackageMoveObserver observer, int flags) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(packageName);
                    _data.writeStrongBinder(observer != null ? observer.asBinder() : null);
                    _data.writeInt(flags);
                    this.f6360a.transact(14, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final String getSettingsSystemString(String name) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(name);
                    this.f6360a.transact(15, _data, _reply, 0);
                    _reply.readException();
                    String _result = _reply.readString();
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final boolean putSettingsSystemString(String name, String value) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(name);
                    _data.writeString(value);
                    this.f6360a.transact(16, _data, _reply, 0);
                    _reply.readException();
                    boolean _result = _reply.readInt() != 0;
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final String getSettingsSecureString(String name) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(name);
                    this.f6360a.transact(17, _data, _reply, 0);
                    _reply.readException();
                    String _result = _reply.readString();
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final boolean putSettingsSecureString(String name, String value) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeString(name);
                    _data.writeString(value);
                    this.f6360a.transact(18, _data, _reply, 0);
                    _reply.readException();
                    boolean _result = _reply.readInt() != 0;
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void killProcess(int pid) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeInt(pid);
                    this.f6360a.transact(19, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidService
            public final void killProcesses(int[] pids) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidService");
                    _data.writeIntArray(pids);
                    this.f6360a.transact(20, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
