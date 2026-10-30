package android.content.p001pm;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IPackageDataObserver extends IInterface {
    void onRemoveCompleted(String str, boolean z) throws RemoteException;

    public static abstract class Stub extends Binder implements IPackageDataObserver {
        public Stub() {
            attachInterface(this, "android.content.pm.IPackageDataObserver");
        }

        public static IPackageDataObserver asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("android.content.pm.IPackageDataObserver");
            if (iin != null && (iin instanceof IPackageDataObserver)) {
                return (IPackageDataObserver) iin;
            }
            return new IPackageDataObserverC0004a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("android.content.pm.IPackageDataObserver");
                    String _arg0 = data.readString();
                    boolean _arg1 = data.readInt() != 0;
                    onRemoveCompleted(_arg0, _arg1);
                    return true;
                case 1598968902:
                    reply.writeString("android.content.pm.IPackageDataObserver");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: android.content.pm.IPackageDataObserver$Stub$a */
        private static class IPackageDataObserverC0004a implements IPackageDataObserver {

            /* JADX INFO: renamed from: a */
            private IBinder f634a;

            IPackageDataObserverC0004a(IBinder remote) {
                this.f634a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f634a;
            }

            @Override // android.content.p001pm.IPackageDataObserver
            public final void onRemoveCompleted(String packageName, boolean succeeded) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.content.pm.IPackageDataObserver");
                    _data.writeString(packageName);
                    _data.writeInt(succeeded ? 1 : 0);
                    this.f634a.transact(1, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }
        }
    }
}
