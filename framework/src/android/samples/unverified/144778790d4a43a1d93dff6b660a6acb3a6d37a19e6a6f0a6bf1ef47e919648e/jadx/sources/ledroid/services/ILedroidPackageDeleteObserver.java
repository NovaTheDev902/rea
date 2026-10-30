package ledroid.services;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface ILedroidPackageDeleteObserver extends IInterface {
    void packageDeleted(String str, int i) throws RemoteException;

    void packageDeletedCompatible(boolean z) throws RemoteException;

    public static abstract class Stub extends Binder implements ILedroidPackageDeleteObserver {
        public Stub() {
            attachInterface(this, "ledroid.services.ILedroidPackageDeleteObserver");
        }

        public static ILedroidPackageDeleteObserver asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("ledroid.services.ILedroidPackageDeleteObserver");
            if (iin != null && (iin instanceof ILedroidPackageDeleteObserver)) {
                return (ILedroidPackageDeleteObserver) iin;
            }
            return new C1103a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("ledroid.services.ILedroidPackageDeleteObserver");
                    boolean _arg0 = data.readInt() != 0;
                    packageDeletedCompatible(_arg0);
                    return true;
                case 2:
                    data.enforceInterface("ledroid.services.ILedroidPackageDeleteObserver");
                    String _arg1 = data.readString();
                    int _arg2 = data.readInt();
                    packageDeleted(_arg1, _arg2);
                    return true;
                case 1598968902:
                    reply.writeString("ledroid.services.ILedroidPackageDeleteObserver");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: ledroid.services.ILedroidPackageDeleteObserver$Stub$a */
        private static class C1103a implements ILedroidPackageDeleteObserver {

            /* JADX INFO: renamed from: a */
            private IBinder f6357a;

            C1103a(IBinder remote) {
                this.f6357a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f6357a;
            }

            @Override // ledroid.services.ILedroidPackageDeleteObserver
            public final void packageDeletedCompatible(boolean succeeded) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidPackageDeleteObserver");
                    _data.writeInt(succeeded ? 1 : 0);
                    this.f6357a.transact(1, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }

            @Override // ledroid.services.ILedroidPackageDeleteObserver
            public final void packageDeleted(String packageName, int returnCode) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidPackageDeleteObserver");
                    _data.writeString(packageName);
                    _data.writeInt(returnCode);
                    this.f6357a.transact(2, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }
        }
    }
}
