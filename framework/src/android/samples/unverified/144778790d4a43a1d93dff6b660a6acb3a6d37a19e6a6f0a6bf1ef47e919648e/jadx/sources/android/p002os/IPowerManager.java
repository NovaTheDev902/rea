package android.p002os;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IPowerManager extends IInterface {
    void acquireWakeLock(int i, IBinder iBinder, String str) throws RemoteException;

    void crash(String str) throws RemoteException;

    int getSupportedWakeLockFlags() throws RemoteException;

    void goToSleep(long j) throws RemoteException;

    void goToSleepWithReason(long j, int i) throws RemoteException;

    boolean isScreenOn() throws RemoteException;

    void preventScreenOn(boolean z) throws RemoteException;

    void reboot(String str) throws RemoteException;

    void releaseWakeLock(IBinder iBinder, int i) throws RemoteException;

    void setAttentionLight(boolean z, int i) throws RemoteException;

    void setBacklightBrightness(int i) throws RemoteException;

    void setMaximumScreenOffTimeount(int i) throws RemoteException;

    void setPokeLock(int i, IBinder iBinder, String str) throws RemoteException;

    void setStayOnSetting(int i) throws RemoteException;

    void userActivity(long j, boolean z) throws RemoteException;

    void userActivityWithForce(long j, boolean z, boolean z2) throws RemoteException;

    public static abstract class Stub extends Binder implements IPowerManager {
        public Stub() {
            attachInterface(this, "android.os.IPowerManager");
        }

        public static IPowerManager asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("android.os.IPowerManager");
            if (iin != null && (iin instanceof IPowerManager)) {
                return (IPowerManager) iin;
            }
            return new C0007a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("android.os.IPowerManager");
                    int _arg0 = data.readInt();
                    IBinder _arg1 = data.readStrongBinder();
                    String _arg2 = data.readString();
                    acquireWakeLock(_arg0, _arg1, _arg2);
                    reply.writeNoException();
                    return true;
                case 2:
                    data.enforceInterface("android.os.IPowerManager");
                    long _arg3 = data.readLong();
                    goToSleep(_arg3);
                    reply.writeNoException();
                    return true;
                case 3:
                    data.enforceInterface("android.os.IPowerManager");
                    long _arg4 = data.readLong();
                    int _arg5 = data.readInt();
                    goToSleepWithReason(_arg4, _arg5);
                    reply.writeNoException();
                    return true;
                case 4:
                    data.enforceInterface("android.os.IPowerManager");
                    IBinder _arg6 = data.readStrongBinder();
                    int _arg7 = data.readInt();
                    releaseWakeLock(_arg6, _arg7);
                    reply.writeNoException();
                    return true;
                case 5:
                    data.enforceInterface("android.os.IPowerManager");
                    long _arg8 = data.readLong();
                    boolean _arg9 = data.readInt() != 0;
                    userActivity(_arg8, _arg9);
                    reply.writeNoException();
                    return true;
                case 6:
                    data.enforceInterface("android.os.IPowerManager");
                    long _arg10 = data.readLong();
                    boolean _arg11 = data.readInt() != 0;
                    boolean _arg12 = data.readInt() != 0;
                    userActivityWithForce(_arg10, _arg11, _arg12);
                    reply.writeNoException();
                    return true;
                case 7:
                    data.enforceInterface("android.os.IPowerManager");
                    int _arg13 = data.readInt();
                    IBinder _arg14 = data.readStrongBinder();
                    String _arg15 = data.readString();
                    setPokeLock(_arg13, _arg14, _arg15);
                    reply.writeNoException();
                    return true;
                case 8:
                    data.enforceInterface("android.os.IPowerManager");
                    int _result = getSupportedWakeLockFlags();
                    reply.writeNoException();
                    reply.writeInt(_result);
                    return true;
                case 9:
                    data.enforceInterface("android.os.IPowerManager");
                    int _arg16 = data.readInt();
                    setStayOnSetting(_arg16);
                    reply.writeNoException();
                    return true;
                case 10:
                    data.enforceInterface("android.os.IPowerManager");
                    int _arg17 = data.readInt();
                    setMaximumScreenOffTimeount(_arg17);
                    reply.writeNoException();
                    return true;
                case 11:
                    data.enforceInterface("android.os.IPowerManager");
                    boolean _arg18 = data.readInt() != 0;
                    preventScreenOn(_arg18);
                    reply.writeNoException();
                    return true;
                case 12:
                    data.enforceInterface("android.os.IPowerManager");
                    boolean _result2 = isScreenOn();
                    reply.writeNoException();
                    reply.writeInt(_result2 ? 1 : 0);
                    return true;
                case 13:
                    data.enforceInterface("android.os.IPowerManager");
                    String _arg19 = data.readString();
                    reboot(_arg19);
                    reply.writeNoException();
                    return true;
                case 14:
                    data.enforceInterface("android.os.IPowerManager");
                    String _arg20 = data.readString();
                    crash(_arg20);
                    reply.writeNoException();
                    return true;
                case 15:
                    data.enforceInterface("android.os.IPowerManager");
                    int _arg21 = data.readInt();
                    setBacklightBrightness(_arg21);
                    reply.writeNoException();
                    return true;
                case 16:
                    data.enforceInterface("android.os.IPowerManager");
                    boolean _arg22 = data.readInt() != 0;
                    int _arg23 = data.readInt();
                    setAttentionLight(_arg22, _arg23);
                    reply.writeNoException();
                    return true;
                case 1598968902:
                    reply.writeString("android.os.IPowerManager");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: android.os.IPowerManager$Stub$a */
        private static class C0007a implements IPowerManager {

            /* JADX INFO: renamed from: a */
            private IBinder f638a;

            C0007a(IBinder remote) {
                this.f638a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f638a;
            }

            @Override // android.p002os.IPowerManager
            public final void acquireWakeLock(int flags, IBinder lock, String tag) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeInt(flags);
                    _data.writeStrongBinder(lock);
                    _data.writeString(tag);
                    this.f638a.transact(1, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void goToSleep(long time) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeLong(time);
                    this.f638a.transact(2, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void goToSleepWithReason(long time, int reason) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeLong(time);
                    _data.writeInt(reason);
                    this.f638a.transact(3, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void releaseWakeLock(IBinder lock, int flags) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeStrongBinder(lock);
                    _data.writeInt(flags);
                    this.f638a.transact(4, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void userActivity(long when, boolean noChangeLights) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeLong(when);
                    _data.writeInt(noChangeLights ? 1 : 0);
                    this.f638a.transact(5, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void userActivityWithForce(long when, boolean noChangeLights, boolean force) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeLong(when);
                    _data.writeInt(noChangeLights ? 1 : 0);
                    _data.writeInt(force ? 1 : 0);
                    this.f638a.transact(6, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void setPokeLock(int pokey, IBinder lock, String tag) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeInt(pokey);
                    _data.writeStrongBinder(lock);
                    _data.writeString(tag);
                    this.f638a.transact(7, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final int getSupportedWakeLockFlags() throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    this.f638a.transact(8, _data, _reply, 0);
                    _reply.readException();
                    int _result = _reply.readInt();
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void setStayOnSetting(int val) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeInt(val);
                    this.f638a.transact(9, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void setMaximumScreenOffTimeount(int timeMs) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeInt(timeMs);
                    this.f638a.transact(10, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void preventScreenOn(boolean prevent) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeInt(prevent ? 1 : 0);
                    this.f638a.transact(11, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final boolean isScreenOn() throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    this.f638a.transact(12, _data, _reply, 0);
                    _reply.readException();
                    boolean _result = _reply.readInt() != 0;
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void reboot(String reason) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeString(reason);
                    this.f638a.transact(13, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void crash(String message) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeString(message);
                    this.f638a.transact(14, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void setBacklightBrightness(int brightness) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeInt(brightness);
                    this.f638a.transact(15, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // android.p002os.IPowerManager
            public final void setAttentionLight(boolean on, int color) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.os.IPowerManager");
                    _data.writeInt(on ? 1 : 0);
                    _data.writeInt(color);
                    this.f638a.transact(16, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
