package android.app;

import android.content.Intent;
import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IActivityController extends IInterface {
    boolean activityResuming(String str) throws RemoteException;

    boolean activityStarting(Intent intent, String str) throws RemoteException;

    boolean appCrashed(String str, int i, String str2, String str3, long j, String str4) throws RemoteException;

    int appEarlyNotResponding(String str, int i, String str2) throws RemoteException;

    int appNotResponding(String str, int i, String str2) throws RemoteException;

    public static abstract class Stub extends Binder implements IActivityController {
        public Stub() {
            attachInterface(this, "android.app.IActivityController");
        }

        public static IActivityController asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("android.app.IActivityController");
            if (iin != null && (iin instanceof IActivityController)) {
                return (IActivityController) iin;
            }
            return new C0001a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            Intent _arg0;
            switch (code) {
                case 1:
                    data.enforceInterface("android.app.IActivityController");
                    if (data.readInt() != 0) {
                        _arg0 = (Intent) Intent.CREATOR.createFromParcel(data);
                    } else {
                        _arg0 = null;
                    }
                    String _arg1 = data.readString();
                    boolean _result = activityStarting(_arg0, _arg1);
                    reply.writeNoException();
                    reply.writeInt(_result ? 1 : 0);
                    return true;
                case 2:
                    data.enforceInterface("android.app.IActivityController");
                    String _arg2 = data.readString();
                    boolean _result2 = activityResuming(_arg2);
                    reply.writeNoException();
                    reply.writeInt(_result2 ? 1 : 0);
                    return true;
                case 3:
                    data.enforceInterface("android.app.IActivityController");
                    String _arg3 = data.readString();
                    int _arg4 = data.readInt();
                    String _arg5 = data.readString();
                    String _arg6 = data.readString();
                    long _arg7 = data.readLong();
                    String _arg8 = data.readString();
                    boolean _result3 = appCrashed(_arg3, _arg4, _arg5, _arg6, _arg7, _arg8);
                    reply.writeNoException();
                    reply.writeInt(_result3 ? 1 : 0);
                    return true;
                case 4:
                    data.enforceInterface("android.app.IActivityController");
                    String _arg9 = data.readString();
                    int _arg10 = data.readInt();
                    String _arg11 = data.readString();
                    int _result4 = appEarlyNotResponding(_arg9, _arg10, _arg11);
                    reply.writeNoException();
                    reply.writeInt(_result4);
                    return true;
                case 5:
                    data.enforceInterface("android.app.IActivityController");
                    String _arg12 = data.readString();
                    int _arg13 = data.readInt();
                    String _arg14 = data.readString();
                    int _result5 = appNotResponding(_arg12, _arg13, _arg14);
                    reply.writeNoException();
                    reply.writeInt(_result5);
                    return true;
                case 1598968902:
                    reply.writeString("android.app.IActivityController");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: android.app.IActivityController$Stub$a */
        private static class C0001a implements IActivityController {

            /* JADX INFO: renamed from: a */
            private IBinder f631a;

            C0001a(IBinder remote) {
                this.f631a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f631a;
            }

            @Override // android.app.IActivityController
            public final boolean activityStarting(Intent intent, String pkg) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.app.IActivityController");
                    if (intent != null) {
                        _data.writeInt(1);
                        intent.writeToParcel(_data, 0);
                    } else {
                        _data.writeInt(0);
                    }
                    _data.writeString(pkg);
                    this.f631a.transact(1, _data, _reply, 0);
                    _reply.readException();
                    boolean _result = _reply.readInt() != 0;
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.app.IActivityController
            public final boolean activityResuming(String pkg) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.app.IActivityController");
                    _data.writeString(pkg);
                    this.f631a.transact(2, _data, _reply, 0);
                    _reply.readException();
                    boolean _result = _reply.readInt() != 0;
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.app.IActivityController
            public final boolean appCrashed(String processName, int pid, String shortMsg, String longMsg, long timeMillis, String stackTrace) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.app.IActivityController");
                    _data.writeString(processName);
                    _data.writeInt(pid);
                    _data.writeString(shortMsg);
                    _data.writeString(longMsg);
                    _data.writeLong(timeMillis);
                    _data.writeString(stackTrace);
                    this.f631a.transact(3, _data, _reply, 0);
                    _reply.readException();
                    boolean _result = _reply.readInt() != 0;
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.app.IActivityController
            public final int appEarlyNotResponding(String processName, int pid, String annotation) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.app.IActivityController");
                    _data.writeString(processName);
                    _data.writeInt(pid);
                    _data.writeString(annotation);
                    this.f631a.transact(4, _data, _reply, 0);
                    _reply.readException();
                    int _result = _reply.readInt();
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.app.IActivityController
            public final int appNotResponding(String processName, int pid, String processStats) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.app.IActivityController");
                    _data.writeString(processName);
                    _data.writeInt(pid);
                    _data.writeString(processStats);
                    this.f631a.transact(5, _data, _reply, 0);
                    _reply.readException();
                    int _result = _reply.readInt();
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
