package android.app;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IProcessObserver extends IInterface {
    void onForegroundActivitiesChanged(int i, int i2, boolean z) throws RemoteException;

    void onProcessDied(int i, int i2) throws RemoteException;

    public static abstract class Stub extends Binder implements IProcessObserver {
        public Stub() {
            attachInterface(this, "android.app.IProcessObserver");
        }

        public static IProcessObserver asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("android.app.IProcessObserver");
            if (iin != null && (iin instanceof IProcessObserver)) {
                return (IProcessObserver) iin;
            }
            return new C0003a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("android.app.IProcessObserver");
                    int _arg0 = data.readInt();
                    int _arg1 = data.readInt();
                    boolean _arg2 = data.readInt() != 0;
                    onForegroundActivitiesChanged(_arg0, _arg1, _arg2);
                    return true;
                case 2:
                    data.enforceInterface("android.app.IProcessObserver");
                    int _arg3 = data.readInt();
                    int _arg4 = data.readInt();
                    onProcessDied(_arg3, _arg4);
                    return true;
                case 1598968902:
                    reply.writeString("android.app.IProcessObserver");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: android.app.IProcessObserver$Stub$a */
        private static class C0003a implements IProcessObserver {

            /* JADX INFO: renamed from: a */
            private IBinder f633a;

            C0003a(IBinder remote) {
                this.f633a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f633a;
            }

            @Override // android.app.IProcessObserver
            public final void onForegroundActivitiesChanged(int pid, int uid, boolean foregroundActivities) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.app.IProcessObserver");
                    _data.writeInt(pid);
                    _data.writeInt(uid);
                    _data.writeInt(foregroundActivities ? 1 : 0);
                    this.f633a.transact(1, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }

            @Override // android.app.IProcessObserver
            public final void onProcessDied(int pid, int uid) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.app.IProcessObserver");
                    _data.writeInt(pid);
                    _data.writeInt(uid);
                    this.f633a.transact(2, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }
        }
    }
}
