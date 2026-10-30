package com.android.internal.telephony;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface ITelephony extends IInterface {
    void answerRingingCall() throws RemoteException;

    void cancelMissedCallsNotification() throws RemoteException;

    boolean endCall() throws RemoteException;

    void silenceRinger() throws RemoteException;

    public static abstract class Stub extends Binder implements ITelephony {
        public Stub() {
            attachInterface(this, "com.android.internal.telephony.ITelephony");
        }

        public static ITelephony asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("com.android.internal.telephony.ITelephony");
            if (iin != null && (iin instanceof ITelephony)) {
                return (ITelephony) iin;
            }
            return new C0043a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            switch (code) {
                case 1:
                    data.enforceInterface("com.android.internal.telephony.ITelephony");
                    boolean _result = endCall();
                    reply.writeNoException();
                    reply.writeInt(_result ? 1 : 0);
                    return true;
                case 2:
                    data.enforceInterface("com.android.internal.telephony.ITelephony");
                    answerRingingCall();
                    reply.writeNoException();
                    return true;
                case 3:
                    data.enforceInterface("com.android.internal.telephony.ITelephony");
                    silenceRinger();
                    reply.writeNoException();
                    return true;
                case 4:
                    data.enforceInterface("com.android.internal.telephony.ITelephony");
                    cancelMissedCallsNotification();
                    reply.writeNoException();
                    return true;
                case 1598968902:
                    reply.writeString("com.android.internal.telephony.ITelephony");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: com.android.internal.telephony.ITelephony$Stub$a */
        private static class C0043a implements ITelephony {

            /* JADX INFO: renamed from: a */
            private IBinder f918a;

            C0043a(IBinder remote) {
                this.f918a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f918a;
            }

            @Override // com.android.internal.telephony.ITelephony
            public final boolean endCall() throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.android.internal.telephony.ITelephony");
                    this.f918a.transact(1, _data, _reply, 0);
                    _reply.readException();
                    boolean _result = _reply.readInt() != 0;
                    return _result;
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // com.android.internal.telephony.ITelephony
            public final void answerRingingCall() throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.android.internal.telephony.ITelephony");
                    this.f918a.transact(2, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // com.android.internal.telephony.ITelephony
            public final void silenceRinger() throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.android.internal.telephony.ITelephony");
                    this.f918a.transact(3, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override // com.android.internal.telephony.ITelephony
            public final void cancelMissedCallsNotification() throws RemoteException {
                Parcel _data = Parcel.obtain();
                Parcel _reply = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("com.android.internal.telephony.ITelephony");
                    this.f918a.transact(4, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }
    }
}
