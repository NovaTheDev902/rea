package ledroid.services;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface ILedroidPackageInstallObserver extends IInterface {
    void packageInstalled(String str, int i) throws RemoteException;

    public static abstract class Stub extends Binder implements ILedroidPackageInstallObserver {
        public Stub() {
            attachInterface(this, "ledroid.services.ILedroidPackageInstallObserver");
        }

        public static ILedroidPackageInstallObserver asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("ledroid.services.ILedroidPackageInstallObserver");
            if (iin != null && (iin instanceof ILedroidPackageInstallObserver)) {
                return (ILedroidPackageInstallObserver) iin;
            }
            return new C1104a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("ledroid.services.ILedroidPackageInstallObserver");
                    String _arg0 = data.readString();
                    int _arg1 = data.readInt();
                    packageInstalled(_arg0, _arg1);
                    return true;
                case 1598968902:
                    reply.writeString("ledroid.services.ILedroidPackageInstallObserver");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: ledroid.services.ILedroidPackageInstallObserver$Stub$a */
        private static class C1104a implements ILedroidPackageInstallObserver {

            /* JADX INFO: renamed from: a */
            private IBinder f6358a;

            C1104a(IBinder remote) {
                this.f6358a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f6358a;
            }

            @Override // ledroid.services.ILedroidPackageInstallObserver
            public final void packageInstalled(String packageName, int returnCode) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidPackageInstallObserver");
                    _data.writeString(packageName);
                    _data.writeInt(returnCode);
                    this.f6358a.transact(1, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }
        }
    }
}
