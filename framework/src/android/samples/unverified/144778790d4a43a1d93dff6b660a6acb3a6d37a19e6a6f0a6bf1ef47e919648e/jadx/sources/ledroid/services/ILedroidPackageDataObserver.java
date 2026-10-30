package ledroid.services;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface ILedroidPackageDataObserver extends IInterface {
    void onRemoveCompleted(String str, boolean z) throws RemoteException;

    public static abstract class Stub extends Binder implements ILedroidPackageDataObserver {
        public Stub() {
            attachInterface(this, "ledroid.services.ILedroidPackageDataObserver");
        }

        public static ILedroidPackageDataObserver asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("ledroid.services.ILedroidPackageDataObserver");
            if (iin != null && (iin instanceof ILedroidPackageDataObserver)) {
                return (ILedroidPackageDataObserver) iin;
            }
            return new C1102a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("ledroid.services.ILedroidPackageDataObserver");
                    String _arg0 = data.readString();
                    boolean _arg1 = data.readInt() != 0;
                    onRemoveCompleted(_arg0, _arg1);
                    return true;
                case 1598968902:
                    reply.writeString("ledroid.services.ILedroidPackageDataObserver");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: ledroid.services.ILedroidPackageDataObserver$Stub$a */
        private static class C1102a implements ILedroidPackageDataObserver {

            /* JADX INFO: renamed from: a */
            private IBinder f6356a;

            C1102a(IBinder remote) {
                this.f6356a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f6356a;
            }

            @Override // ledroid.services.ILedroidPackageDataObserver
            public final void onRemoveCompleted(String packageName, boolean succeeded) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("ledroid.services.ILedroidPackageDataObserver");
                    _data.writeString(packageName);
                    _data.writeInt(succeeded ? 1 : 0);
                    this.f6356a.transact(1, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }
        }
    }
}
