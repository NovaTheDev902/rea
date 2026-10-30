package ledroid.services;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface ILedroidPackageMoveObserver extends IInterface {
    void packageMoved(String str, int i) throws RemoteException;

    public static abstract class Stub extends Binder implements ILedroidPackageMoveObserver {
        public Stub() {
            attachInterface(this, "ledroid.services.ILedroidPackageMoveObserver");
        }

        public static ILedroidPackageMoveObserver asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("ledroid.services.ILedroidPackageMoveObserver");
            if (iin != null && (iin instanceof ILedroidPackageMoveObserver)) {
                return (ILedroidPackageMoveObserver) iin;
            }
            return new C1105a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("ledroid.services.ILedroidPackageMoveObserver");
                    String _arg0 = data.readString();
                    int _arg1 = data.readInt();
                    packageMoved(_arg0, _arg1);
                    return true;
                case 1598968902:
                    reply.writeString("ledroid.services.ILedroidPackageMoveObserver");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: ledroid.services.ILedroidPackageMoveObserver$Stub$a */
        private static class C1105a implements ILedroidPackageMoveObserver {

            /* JADX INFO: renamed from: a */
            private IBinder f6359a;

            C1105a(IBinder remote) {
                this.f6359a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f6359a;
            }

            @Override // ledroid.services.ILedroidPackageMoveObserver
            public final void packageMoved(String packageName, int returnCode) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidPackageMoveObserver");
                    _data.writeString(packageName);
                    _data.writeInt(returnCode);
                    this.f6359a.transact(1, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }
        }
    }
}
