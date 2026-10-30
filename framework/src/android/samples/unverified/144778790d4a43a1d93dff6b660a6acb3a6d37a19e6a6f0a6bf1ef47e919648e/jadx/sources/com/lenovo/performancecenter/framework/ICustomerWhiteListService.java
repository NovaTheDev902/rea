package com.lenovo.performancecenter.framework;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public interface ICustomerWhiteListService extends IInterface {
    List<String> getCustomerWhiteList() throws RemoteException;

    public static abstract class Stub extends Binder implements ICustomerWhiteListService {
        public Stub() {
            attachInterface(this, "com.lenovo.performancecenter.framework.ICustomerWhiteListService");
        }

        public static ICustomerWhiteListService asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("com.lenovo.performancecenter.framework.ICustomerWhiteListService");
            if (iin != null && (iin instanceof ICustomerWhiteListService)) {
                return (ICustomerWhiteListService) iin;
            }
            return new C0158a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("com.lenovo.performancecenter.framework.ICustomerWhiteListService");
                    List<String> _result = getCustomerWhiteList();
                    reply.writeNoException();
                    reply.writeStringList(_result);
                    return true;
                case 1598968902:
                    reply.writeString("com.lenovo.performancecenter.framework.ICustomerWhiteListService");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: com.lenovo.performancecenter.framework.ICustomerWhiteListService$Stub$a */
        private static class C0158a implements ICustomerWhiteListService {

            /* JADX INFO: renamed from: a */
            private IBinder f1637a;

            C0158a(IBinder remote) {
                this.f1637a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f1637a;
            }

            @Override // com.lenovo.performancecenter.framework.ICustomerWhiteListService
            public final List<String> getCustomerWhiteList() throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.performancecenter.framework.ICustomerWhiteListService");
                    this.f1637a.transact(1, _data, _reply, 0);
                    _reply.readException();
                    List<String> _result = _reply.createStringArrayList();
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
