package com.lenovo.safecenter.aidl.killvirus;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IRemoteScanVirusService extends IInterface {
    void receiveCommand(String str) throws RemoteException;

    void registerCallback(IRemoteScanVirusCallback iRemoteScanVirusCallback) throws RemoteException;

    void unregisterCallback(IRemoteScanVirusCallback iRemoteScanVirusCallback) throws RemoteException;

    public static abstract class Stub extends Binder implements IRemoteScanVirusService {
        public Stub() {
            attachInterface(this, "com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService");
        }

        public static IRemoteScanVirusService asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService");
            if (iin != null && (iin instanceof IRemoteScanVirusService)) {
                return (IRemoteScanVirusService) iin;
            }
            return new C0430a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService");
                    String _arg0 = data.readString();
                    receiveCommand(_arg0);
                    reply.writeNoException();
                    return true;
                case 2:
                    data.enforceInterface("com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService");
                    IRemoteScanVirusCallback _arg1 = IRemoteScanVirusCallback.Stub.asInterface(data.readStrongBinder());
                    registerCallback(_arg1);
                    reply.writeNoException();
                    return true;
                case 3:
                    data.enforceInterface("com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService");
                    IRemoteScanVirusCallback _arg2 = IRemoteScanVirusCallback.Stub.asInterface(data.readStrongBinder());
                    unregisterCallback(_arg2);
                    reply.writeNoException();
                    return true;
                case 1598968902:
                    reply.writeString("com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService$Stub$a */
        private static class C0430a implements IRemoteScanVirusService {

            /* JADX INFO: renamed from: a */
            private IBinder f2947a;

            C0430a(IBinder remote) {
                this.f2947a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f2947a;
            }

            @Override // com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService
            public final void receiveCommand(String command) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService");
                    _data.writeString(command);
                    this.f2947a.transact(1, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService
            public final void registerCallback(IRemoteScanVirusCallback cb) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService");
                    _data.writeStrongBinder(cb != null ? cb.asBinder() : null);
                    this.f2947a.transact(2, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService
            public final void unregisterCallback(IRemoteScanVirusCallback cb) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService");
                    _data.writeStrongBinder(cb != null ? cb.asBinder() : null);
                    this.f2947a.transact(3, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
