package com.tencent.tmsecure.common;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface ISDKClient extends IInterface {
    public static final String DESCRIPTOR = "com.tencent.tmsecure.common.ISDKClient";
    public static final int TRANSACTION_SENDMESSAGE = 20100405;

    public static class Proxy implements ISDKClient {

        /* JADX INFO: renamed from: a */
        private IBinder f6033a;

        /* JADX INFO: renamed from: b */
        private int f6034b = Binder.getCallingUid();

        Proxy(IBinder iBinder) {
            this.f6033a = iBinder;
        }

        public static ISDKClient asInterface(IBinder iBinder) {
            if (iBinder == null) {
                return null;
            }
            IInterface iInterfaceQueryLocalInterface = iBinder.queryLocalInterface(ISDKClient.DESCRIPTOR);
            return (iInterfaceQueryLocalInterface == null || !(iInterfaceQueryLocalInterface instanceof ISDKClient)) ? new Proxy(iBinder) : (ISDKClient) iInterfaceQueryLocalInterface;
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this.f6033a;
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof Proxy)) {
                return false;
            }
            Proxy proxy = (Proxy) obj;
            return this.f6033a == proxy.f6033a && this.f6034b == proxy.f6034b;
        }

        public String getInterfaceDescriptor() {
            return ISDKClient.DESCRIPTOR;
        }

        public int hashCode() {
            return this.f6034b;
        }

        @Override // com.tencent.tmsecure.common.ISDKClient
        public DataEntity sendMessage(DataEntity dataEntity) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            parcelObtain.writeInterfaceToken(ISDKClient.DESCRIPTOR);
            parcelObtain.writeParcelable(dataEntity, 0);
            try {
                this.f6033a.transact(ISDKClient.TRANSACTION_SENDMESSAGE, parcelObtain, parcelObtain2, 0);
                parcelObtain2.readException();
                return (DataEntity) parcelObtain2.readParcelable(DataEntity.class.getClassLoader());
            } finally {
                parcelObtain.recycle();
                parcelObtain2.recycle();
            }
        }
    }

    public static abstract class Stub extends Binder implements ISDKClient {
        public Stub() {
            attachInterface(this, ISDKClient.DESCRIPTOR);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        public boolean equals(Object obj) {
            if (obj instanceof Stub) {
                return super.equals((Stub) obj);
            }
            return false;
        }

        @Override // android.os.Binder, android.os.IBinder
        public String getInterfaceDescriptor() {
            return ISDKClient.DESCRIPTOR;
        }

        @Override // android.os.Binder
        public boolean onTransact(int i, Parcel parcel, Parcel parcel2, int i2) throws RemoteException {
            if (i != 20100405) {
                return super.onTransact(i, parcel, parcel2, i2);
            }
            parcel.enforceInterface(ISDKClient.DESCRIPTOR);
            DataEntity dataEntitySendMessage = sendMessage((DataEntity) parcel.readParcelable(DataEntity.class.getClassLoader()));
            parcel2.writeNoException();
            parcel2.writeParcelable(dataEntitySendMessage, 0);
            return true;
        }
    }

    DataEntity sendMessage(DataEntity dataEntity) throws RemoteException;
}
