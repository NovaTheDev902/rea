package com.tencent.tmsecure.module.permission;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;
import java.util.Arrays;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public interface IFirewallService extends IInterface {

    /* JADX INFO: renamed from: a */
    public static final String f6162a = "tms_firewall";

    /* JADX INFO: renamed from: b */
    public static final String f6163b = "com.tencent.tmsecure.IFirewallService";

    /* JADX INFO: renamed from: c */
    public static final int f6164c = 1;

    /* JADX INFO: renamed from: d */
    public static final int f6165d = 2;

    /* JADX INFO: renamed from: e */
    public static final int f6166e = 3;

    public static class Proxy implements IFirewallService {

        /* JADX INFO: renamed from: f */
        private IBinder f6167f;

        Proxy(IBinder iBinder) {
            this.f6167f = iBinder;
        }

        public static IFirewallService asInterface(IBinder iBinder) {
            return new Proxy(iBinder);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this.f6167f;
        }

        public String getInterfaceDescriptor() {
            return IFirewallService.f6163b;
        }

        @Override // com.tencent.tmsecure.module.permission.IFirewallService
        public boolean isNetEnable(String str) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                parcelObtain.writeInterfaceToken(IFirewallService.f6163b);
                parcelObtain.writeString(str);
                this.f6167f.transact(3, parcelObtain, parcelObtain2, 0);
                parcelObtain2.readException();
                return parcelObtain2.readInt() != 0;
            } finally {
                parcelObtain2.recycle();
                parcelObtain.recycle();
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IFirewallService
        public void setNetEnable(String str, boolean z) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                parcelObtain.writeInterfaceToken(IFirewallService.f6163b);
                parcelObtain.writeString(str);
                parcelObtain.writeInt(z ? 1 : 0);
                this.f6167f.transact(1, parcelObtain, parcelObtain2, 1);
                parcelObtain2.readException();
            } finally {
                parcelObtain2.recycle();
                parcelObtain.recycle();
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IFirewallService
        public void setNetEnable(List<String> list, boolean z) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                parcelObtain.writeInterfaceToken(IFirewallService.f6163b);
                parcelObtain.writeStringList(list);
                parcelObtain.writeInt(z ? 1 : 0);
                this.f6167f.transact(2, parcelObtain, parcelObtain2, 1);
                parcelObtain2.readException();
            } finally {
                parcelObtain2.recycle();
                parcelObtain.recycle();
            }
        }
    }

    public static abstract class Stub extends Binder implements IFirewallService {
        public Stub() {
            attachInterface(this, IFirewallService.f6163b);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder, android.os.IBinder
        public String getInterfaceDescriptor() {
            return IFirewallService.f6163b;
        }

        @Override // android.os.Binder
        protected boolean onTransact(int i, Parcel parcel, Parcel parcel2, int i2) throws RemoteException {
            parcel.enforceInterface(IFirewallService.f6163b);
            switch (i) {
                case 1:
                    setNetEnable(parcel.readString(), parcel.readInt() == 1);
                    parcel2.writeNoException();
                    return true;
                case 2:
                    setNetEnable(Arrays.asList(parcel.createStringArray()), parcel.readInt() == 1);
                    parcel2.writeNoException();
                    return true;
                case 3:
                    boolean zIsNetEnable = isNetEnable(parcel.readString());
                    parcel2.writeNoException();
                    parcel2.writeInt(zIsNetEnable ? 1 : 0);
                    return true;
                default:
                    return super.onTransact(i, parcel, parcel2, i2);
            }
        }
    }

    boolean isNetEnable(String str) throws RemoteException;

    void setNetEnable(String str, boolean z) throws RemoteException;

    void setNetEnable(List<String> list, boolean z) throws RemoteException;
}
