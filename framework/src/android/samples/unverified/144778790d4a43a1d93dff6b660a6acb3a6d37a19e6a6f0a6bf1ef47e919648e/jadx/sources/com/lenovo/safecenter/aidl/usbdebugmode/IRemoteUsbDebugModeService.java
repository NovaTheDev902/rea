package com.lenovo.safecenter.aidl.usbdebugmode;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IRemoteUsbDebugModeService extends IInterface {
    boolean setUsbDebugMode(boolean z) throws RemoteException;

    public static abstract class Stub extends Binder implements IRemoteUsbDebugModeService {
        public Stub() {
            attachInterface(this, "com.lenovo.safecenter.aidl.usbdebugmode.IRemoteUsbDebugModeService");
        }

        public static IRemoteUsbDebugModeService asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("com.lenovo.safecenter.aidl.usbdebugmode.IRemoteUsbDebugModeService");
            if (iin != null && (iin instanceof IRemoteUsbDebugModeService)) {
                return (IRemoteUsbDebugModeService) iin;
            }
            return new C0433a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("com.lenovo.safecenter.aidl.usbdebugmode.IRemoteUsbDebugModeService");
                    boolean _arg0 = data.readInt() != 0;
                    boolean _result = setUsbDebugMode(_arg0);
                    reply.writeNoException();
                    reply.writeInt(_result ? 1 : 0);
                    return true;
                case 1598968902:
                    reply.writeString("com.lenovo.safecenter.aidl.usbdebugmode.IRemoteUsbDebugModeService");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.aidl.usbdebugmode.IRemoteUsbDebugModeService$Stub$a */
        private static class C0433a implements IRemoteUsbDebugModeService {

            /* JADX INFO: renamed from: a */
            private IBinder f2956a;

            C0433a(IBinder remote) {
                this.f2956a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f2956a;
            }

            @Override // com.lenovo.safecenter.aidl.usbdebugmode.IRemoteUsbDebugModeService
            public final boolean setUsbDebugMode(boolean isEnable) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.safecenter.aidl.usbdebugmode.IRemoteUsbDebugModeService");
                    _data.writeInt(isEnable ? 1 : 0);
                    this.f2956a.transact(1, _data, _reply, 0);
                    _reply.readException();
                    boolean _result = _reply.readInt() != 0;
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
