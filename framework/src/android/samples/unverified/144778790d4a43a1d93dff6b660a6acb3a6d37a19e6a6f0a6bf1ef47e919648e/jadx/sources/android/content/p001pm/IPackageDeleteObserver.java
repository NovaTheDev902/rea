package android.content.p001pm;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IPackageDeleteObserver extends IInterface {
    void packageDeleted(boolean z) throws RemoteException;

    public static abstract class Stub extends Binder implements IPackageDeleteObserver {
        public Stub() {
            attachInterface(this, "android.content.pm.IPackageDeleteObserver");
        }

        public static IPackageDeleteObserver asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("android.content.pm.IPackageDeleteObserver");
            if (iin != null && (iin instanceof IPackageDeleteObserver)) {
                return (IPackageDeleteObserver) iin;
            }
            return new Proxy(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("android.content.pm.IPackageDeleteObserver");
                    boolean _arg0 = data.readInt() != 0;
                    packageDeleted(_arg0);
                    return true;
                case 1598968902:
                    reply.writeString("android.content.pm.IPackageDeleteObserver");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        private static class Proxy implements IPackageDeleteObserver {

            /* JADX INFO: renamed from: a */
            private IBinder f635a;

            Proxy(IBinder remote) {
                this.f635a = remote;
            }

            @Override // android.os.IInterface
            public IBinder asBinder() {
                return this.f635a;
            }

            @Override // android.content.p001pm.IPackageDeleteObserver
            public void packageDeleted(boolean succeeded) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.content.pm.IPackageDeleteObserver");
                    _data.writeInt(succeeded ? 1 : 0);
                    this.f635a.transact(1, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }
        }
    }
}
