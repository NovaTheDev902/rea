package com.lenovo.safecenter.aidl.healthcheck;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IRemoteHealthCheckCallback extends IInterface {
    void onResult(String str) throws RemoteException;

    public static abstract class Stub extends Binder implements IRemoteHealthCheckCallback {
        public Stub() {
            attachInterface(this, "com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckCallback");
        }

        public static IRemoteHealthCheckCallback asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckCallback");
            if (iin != null && (iin instanceof IRemoteHealthCheckCallback)) {
                return (IRemoteHealthCheckCallback) iin;
            }
            return new C0425a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckCallback");
                    String _arg0 = data.readString();
                    onResult(_arg0);
                    reply.writeNoException();
                    return true;
                case 1598968902:
                    reply.writeString("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckCallback");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckCallback$Stub$a */
        private static class C0425a implements IRemoteHealthCheckCallback {

            /* JADX INFO: renamed from: a */
            private IBinder f2936a;

            C0425a(IBinder remote) {
                this.f2936a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f2936a;
            }

            @Override // com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckCallback
            public final void onResult(String result) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckCallback");
                    _data.writeString(result);
                    this.f2936a.transact(1, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
