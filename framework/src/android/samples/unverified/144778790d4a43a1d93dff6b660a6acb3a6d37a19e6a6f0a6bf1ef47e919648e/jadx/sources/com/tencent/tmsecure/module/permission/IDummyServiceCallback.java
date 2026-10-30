package com.tencent.tmsecure.module.permission;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: Access modifiers changed from: package-private */
/* JADX INFO: loaded from: classes.dex */
public interface IDummyServiceCallback extends IInterface {

    public static abstract class Stub extends Binder implements IDummyServiceCallback {

        /* JADX INFO: renamed from: a */
        static final int f6159a = 1;

        /* JADX INFO: renamed from: b */
        private static final String f6160b = "com.tencent.tmsecure.service.manager.permission.IServiceControllerCallback";

        /* JADX INFO: renamed from: com.tencent.tmsecure.module.permission.IDummyServiceCallback$Stub$a */
        static class C1077a implements IDummyServiceCallback {

            /* JADX INFO: renamed from: a */
            private IBinder f6161a;

            C1077a(IBinder iBinder) {
                this.f6161a = iBinder;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f6161a;
            }

            @Override // com.tencent.tmsecure.module.permission.IDummyServiceCallback
            public final int onRequest(PermissionRequestInfo permissionRequestInfo) throws RemoteException {
                Parcel parcelObtain = Parcel.obtain();
                Parcel parcelObtain2 = Parcel.obtain();
                try {
                    parcelObtain.writeInterfaceToken(Stub.f6160b);
                    if (permissionRequestInfo != null) {
                        parcelObtain.writeInt(1);
                        permissionRequestInfo.writeToParcel(parcelObtain, 0);
                    } else {
                        parcelObtain.writeInt(0);
                    }
                    this.f6161a.transact(1, parcelObtain, parcelObtain2, 0);
                    parcelObtain2.readException();
                    return parcelObtain2.readInt();
                } finally {
                    parcelObtain2.recycle();
                    parcelObtain.recycle();
                }
            }
        }

        public Stub() {
            attachInterface(this, f6160b);
        }

        public static IDummyServiceCallback asInterface(IBinder iBinder) {
            return new C1077a(iBinder);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int i, Parcel parcel, Parcel parcel2, int i2) throws RemoteException {
            switch (i) {
                case 1:
                    parcel.enforceInterface(f6160b);
                    int iOnRequest = onRequest(parcel.readInt() != 0 ? PermissionRequestInfo.createFromParcel(parcel) : null);
                    parcel2.writeInt(0);
                    parcel2.writeInt(iOnRequest);
                    return true;
                case 1598968902:
                    parcel2.writeString(f6160b);
                    return true;
                default:
                    return super.onTransact(i, parcel, parcel2, i2);
            }
        }
    }

    int onRequest(PermissionRequestInfo permissionRequestInfo) throws RemoteException;
}
