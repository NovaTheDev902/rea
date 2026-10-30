package android.content.p001pm;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IPackageMoveObserver extends IInterface {
    void packageMoved(String str, int i) throws RemoteException;

    public static abstract class Stub extends Binder implements IPackageMoveObserver {
        public Stub() {
            attachInterface(this, "android.content.pm.IPackageMoveObserver");
        }

        public static IPackageMoveObserver asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("android.content.pm.IPackageMoveObserver");
            if (iin != null && (iin instanceof IPackageMoveObserver)) {
                return (IPackageMoveObserver) iin;
            }
            return new IPackageMoveObserverC0005a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("android.content.pm.IPackageMoveObserver");
                    String _arg0 = data.readString();
                    int _arg1 = data.readInt();
                    packageMoved(_arg0, _arg1);
                    return true;
                case 1598968902:
                    reply.writeString("android.content.pm.IPackageMoveObserver");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: android.content.pm.IPackageMoveObserver$Stub$a */
        private static class IPackageMoveObserverC0005a implements IPackageMoveObserver {

            /* JADX INFO: renamed from: a */
            private IBinder f636a;

            IPackageMoveObserverC0005a(IBinder remote) {
                this.f636a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f636a;
            }

            @Override // android.content.p001pm.IPackageMoveObserver
            public final void packageMoved(String packageName, int returnCode) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.content.pm.IPackageMoveObserver");
                    _data.writeString(packageName);
                    _data.writeInt(returnCode);
                    this.f636a.transact(1, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }
        }
    }
}
