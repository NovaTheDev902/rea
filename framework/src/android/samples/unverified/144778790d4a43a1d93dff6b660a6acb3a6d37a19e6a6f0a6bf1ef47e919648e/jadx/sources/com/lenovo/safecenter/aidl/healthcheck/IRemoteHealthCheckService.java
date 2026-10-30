package com.lenovo.safecenter.aidl.healthcheck;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IRemoteHealthCheckService extends IInterface {
    void receiveCommand(String str) throws RemoteException;

    void registerCallback(IRemoteHealthCheckCallback iRemoteHealthCheckCallback) throws RemoteException;

    void unregisterCallback(IRemoteHealthCheckCallback iRemoteHealthCheckCallback) throws RemoteException;

    public static abstract class Stub extends Binder implements IRemoteHealthCheckService {
        public Stub() {
            attachInterface(this, "com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService");
        }

        public static IRemoteHealthCheckService asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService");
            if (iin != null && (iin instanceof IRemoteHealthCheckService)) {
                return (IRemoteHealthCheckService) iin;
            }
            return new C0426a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService");
                    String _arg0 = data.readString();
                    receiveCommand(_arg0);
                    reply.writeNoException();
                    return true;
                case 2:
                    data.enforceInterface("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService");
                    IRemoteHealthCheckCallback _arg1 = IRemoteHealthCheckCallback.Stub.asInterface(data.readStrongBinder());
                    registerCallback(_arg1);
                    reply.writeNoException();
                    return true;
                case 3:
                    data.enforceInterface("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService");
                    IRemoteHealthCheckCallback _arg2 = IRemoteHealthCheckCallback.Stub.asInterface(data.readStrongBinder());
                    unregisterCallback(_arg2);
                    reply.writeNoException();
                    return true;
                case 1598968902:
                    reply.writeString("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService$Stub$a */
        private static class C0426a implements IRemoteHealthCheckService {

            /* JADX INFO: renamed from: a */
            private IBinder f2937a;

            C0426a(IBinder remote) {
                this.f2937a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f2937a;
            }

            @Override // com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService
            public final void receiveCommand(String command) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService");
                    _data.writeString(command);
                    this.f2937a.transact(1, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService
            public final void registerCallback(IRemoteHealthCheckCallback cb) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService");
                    _data.writeStrongBinder(cb != null ? cb.asBinder() : null);
                    this.f2937a.transact(2, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService
            public final void unregisterCallback(IRemoteHealthCheckCallback cb) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService");
                    _data.writeStrongBinder(cb != null ? cb.asBinder() : null);
                    this.f2937a.transact(3, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
