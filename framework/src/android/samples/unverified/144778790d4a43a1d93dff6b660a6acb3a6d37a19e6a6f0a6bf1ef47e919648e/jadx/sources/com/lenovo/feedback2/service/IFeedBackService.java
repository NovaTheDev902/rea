package com.lenovo.feedback2.service;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;
import com.lenovo.feedback2.agent.IFeedBackAgent;
import com.lenovo.feedback2.message.Message;

/* JADX INFO: loaded from: classes.dex */
public interface IFeedBackService extends IInterface {
    Message callAgent(int i, String str, Message message) throws RemoteException;

    Message send(Message message) throws RemoteException;

    void setAgentCallBack(int i, String str, IFeedBackAgent iFeedBackAgent) throws RemoteException;

    public static abstract class Stub extends Binder implements IFeedBackService {
        public Stub() {
            attachInterface(this, "com.lenovo.feedback2.service.IFeedBackService");
        }

        public static IFeedBackService asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("com.lenovo.feedback2.service.IFeedBackService");
            if (iin != null && (iin instanceof IFeedBackService)) {
                return (IFeedBackService) iin;
            }
            return new C0051a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            Message _arg2;
            Message _arg0;
            switch (code) {
                case 1:
                    data.enforceInterface("com.lenovo.feedback2.service.IFeedBackService");
                    if (data.readInt() != 0) {
                        _arg0 = Message.CREATOR.createFromParcel(data);
                    } else {
                        _arg0 = null;
                    }
                    Message _result = send(_arg0);
                    reply.writeNoException();
                    if (_result != null) {
                        reply.writeInt(1);
                        _result.writeToParcel(reply, 1);
                    } else {
                        reply.writeInt(0);
                    }
                    if (_arg0 != null) {
                        reply.writeInt(1);
                        _arg0.writeToParcel(reply, 1);
                        return true;
                    }
                    reply.writeInt(0);
                    return true;
                case 2:
                    data.enforceInterface("com.lenovo.feedback2.service.IFeedBackService");
                    int _arg1 = data.readInt();
                    String _arg3 = data.readString();
                    IFeedBackAgent _arg4 = IFeedBackAgent.Stub.asInterface(data.readStrongBinder());
                    setAgentCallBack(_arg1, _arg3, _arg4);
                    reply.writeNoException();
                    return true;
                case 3:
                    data.enforceInterface("com.lenovo.feedback2.service.IFeedBackService");
                    int _arg5 = data.readInt();
                    String _arg6 = data.readString();
                    if (data.readInt() != 0) {
                        _arg2 = Message.CREATOR.createFromParcel(data);
                    } else {
                        _arg2 = null;
                    }
                    Message _result2 = callAgent(_arg5, _arg6, _arg2);
                    reply.writeNoException();
                    if (_result2 != null) {
                        reply.writeInt(1);
                        _result2.writeToParcel(reply, 1);
                    } else {
                        reply.writeInt(0);
                    }
                    if (_arg2 != null) {
                        reply.writeInt(1);
                        _arg2.writeToParcel(reply, 1);
                        return true;
                    }
                    reply.writeInt(0);
                    return true;
                case 1598968902:
                    reply.writeString("com.lenovo.feedback2.service.IFeedBackService");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: com.lenovo.feedback2.service.IFeedBackService$Stub$a */
        private static class C0051a implements IFeedBackService {

            /* JADX INFO: renamed from: a */
            private IBinder f966a;

            C0051a(IBinder remote) {
                this.f966a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f966a;
            }

            @Override // com.lenovo.feedback2.service.IFeedBackService
            public final Message send(Message message) throws RemoteException {
                Message _result;
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.feedback2.service.IFeedBackService");
                    if (message != null) {
                        _data.writeInt(1);
                        message.writeToParcel(_data, 0);
                    } else {
                        _data.writeInt(0);
                    }
                    this.f966a.transact(1, _data, _reply, 0);
                    _reply.readException();
                    if (_reply.readInt() != 0) {
                        _result = Message.CREATOR.createFromParcel(_reply);
                    } else {
                        _result = null;
                    }
                    if (_reply.readInt() != 0) {
                        message.readFromParcel(_reply);
                    }
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // com.lenovo.feedback2.service.IFeedBackService
            public final void setAgentCallBack(int pid, String packageName, IFeedBackAgent callback) throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.feedback2.service.IFeedBackService");
                    _data.writeInt(pid);
                    _data.writeString(packageName);
                    _data.writeStrongBinder(callback != null ? callback.asBinder() : null);
                    this.f966a.transact(2, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // com.lenovo.feedback2.service.IFeedBackService
            public final Message callAgent(int pid, String packageName, Message message) throws RemoteException {
                Message _result;
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.lenovo.feedback2.service.IFeedBackService");
                    _data.writeInt(pid);
                    _data.writeString(packageName);
                    if (message != null) {
                        _data.writeInt(1);
                        message.writeToParcel(_data, 0);
                    } else {
                        _data.writeInt(0);
                    }
                    this.f966a.transact(3, _data, _reply, 0);
                    _reply.readException();
                    if (_reply.readInt() != 0) {
                        _result = Message.CREATOR.createFromParcel(_reply);
                    } else {
                        _result = null;
                    }
                    if (_reply.readInt() != 0) {
                        message.readFromParcel(_reply);
                    }
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
