package com.tencent.tmsecure.module.permission;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;
import tms.AbstractC1284ff;
import tms.C1152ai;

/* JADX INFO: loaded from: classes.dex */
public interface IDummyService extends IInterface {

    /* JADX INFO: renamed from: a */
    public static final int f6136a = 20100404;

    /* JADX INFO: renamed from: b */
    public static final int f6137b = 1;

    /* JADX INFO: renamed from: c */
    public static final int f6138c = 2;

    /* JADX INFO: renamed from: d */
    public static final int f6139d = 3;

    /* JADX INFO: renamed from: e */
    public static final int f6140e = 4;

    /* JADX INFO: renamed from: f */
    public static final int f6141f = 5;

    /* JADX INFO: renamed from: g */
    public static final int f6142g = 6;

    /* JADX INFO: renamed from: h */
    public static final int f6143h = 7;

    /* JADX INFO: renamed from: i */
    public static final int f6144i = 8;

    /* JADX INFO: renamed from: j */
    public static final int f6145j = -1;

    /* JADX INFO: renamed from: k */
    public static final int f6146k = 7777;

    /* JADX INFO: renamed from: l */
    public static final int f6147l = 8888;

    /* JADX INFO: renamed from: m */
    public static final int f6148m = 9999;

    /* JADX INFO: renamed from: n */
    public static final int f6149n = 1111;

    public static class Proxy implements IDummyService {

        /* JADX INFO: renamed from: o */
        private String f6150o;

        /* JADX INFO: renamed from: p */
        private IBinder f6151p;

        Proxy(IBinder iBinder) throws RemoteException {
            this.f6151p = iBinder;
            this.f6150o = this.f6151p.getInterfaceDescriptor();
        }

        public static IDummyService asInterface(IBinder iBinder) {
            try {
                return new Proxy(iBinder);
            } catch (RemoteException e) {
                e.printStackTrace();
                return null;
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public void addPermissionTableItem(PermissionTableItem permissionTableItem) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                try {
                    parcelObtain.writeInt(IDummyService.f6136a);
                    parcelObtain.writeInterfaceToken(this.f6150o);
                    permissionTableItem.writeToParcel(parcelObtain, 0);
                    this.f6151p.transact(7, parcelObtain, parcelObtain2, 1);
                    parcelObtain2.readException();
                    parcelObtain2.recycle();
                } catch (Exception e) {
                    e.printStackTrace();
                    parcelObtain2.recycle();
                }
                parcelObtain.recycle();
            } catch (Throwable th) {
                parcelObtain2.recycle();
                parcelObtain.recycle();
                throw th;
            }
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this.f6151p;
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public int pingDummyService(int i, String str) {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            int i2 = -1;
            try {
                try {
                    parcelObtain.writeInt(IDummyService.f6136a);
                    parcelObtain.writeInterfaceToken(this.f6150o);
                    parcelObtain.writeInt(i);
                    parcelObtain.writeString(str);
                    this.f6151p.transact(6, parcelObtain, parcelObtain2, 0);
                    parcelObtain2.readException();
                    i2 = parcelObtain2.readInt();
                    parcelObtain2.recycle();
                } catch (Exception e) {
                    e.printStackTrace();
                    parcelObtain2.recycle();
                }
                parcelObtain.recycle();
                return i2;
            } catch (Throwable th) {
                parcelObtain2.recycle();
                parcelObtain.recycle();
                throw th;
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public void removePermissionTableItem(PermissionTableItem permissionTableItem) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                try {
                    parcelObtain.writeInt(IDummyService.f6136a);
                    parcelObtain.writeInterfaceToken(this.f6150o);
                    permissionTableItem.writeToParcel(parcelObtain, 0);
                    this.f6151p.transact(8, parcelObtain, parcelObtain2, 1);
                    parcelObtain2.readException();
                    parcelObtain2.recycle();
                } catch (Exception e) {
                    e.printStackTrace();
                    parcelObtain2.recycle();
                }
                parcelObtain.recycle();
            } catch (Throwable th) {
                parcelObtain2.recycle();
                parcelObtain.recycle();
                throw th;
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public void setDummyServiceCallback(IDummyServiceCallback iDummyServiceCallback) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                parcelObtain.writeInt(IDummyService.f6136a);
                parcelObtain.writeInterfaceToken(this.f6150o);
                parcelObtain.writeStrongBinder(iDummyServiceCallback != null ? iDummyServiceCallback.asBinder() : null);
                this.f6151p.transact(1, parcelObtain, parcelObtain2, 1);
                parcelObtain2.readException();
            } finally {
                parcelObtain2.recycle();
                parcelObtain.recycle();
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public void setEnable(boolean z) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                parcelObtain.writeInt(IDummyService.f6136a);
                parcelObtain.writeInterfaceToken(this.f6150o);
                parcelObtain.writeInt(z ? 1 : 0);
                this.f6151p.transact(2, parcelObtain, parcelObtain2, 1);
                parcelObtain2.readException();
            } finally {
                parcelObtain2.recycle();
                parcelObtain.recycle();
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public void setPermissionTable(PermissionControlConfig permissionControlConfig) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                parcelObtain.writeInt(IDummyService.f6136a);
                parcelObtain.writeInterfaceToken(this.f6150o);
                if (permissionControlConfig != null) {
                    parcelObtain.writeInt(1);
                    permissionControlConfig.writeToParcel(parcelObtain, 0);
                } else {
                    parcelObtain.writeInt(0);
                }
                this.f6151p.transact(3, parcelObtain, parcelObtain2, 1);
                parcelObtain2.readException();
            } finally {
                parcelObtain2.recycle();
                parcelObtain.recycle();
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public void updatePermissionTable(int i, int i2, int i3) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                parcelObtain.writeInt(IDummyService.f6136a);
                parcelObtain.writeInterfaceToken(this.f6150o);
                parcelObtain.writeInt(i);
                parcelObtain.writeInt(i2);
                parcelObtain.writeInt(i3);
                this.f6151p.transact(4, parcelObtain, parcelObtain2, 1);
                parcelObtain2.readException();
            } finally {
                parcelObtain2.recycle();
                parcelObtain.recycle();
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public void updatePermissionTable(PermissionTableItem permissionTableItem) throws RemoteException {
            Parcel parcelObtain = Parcel.obtain();
            Parcel parcelObtain2 = Parcel.obtain();
            try {
                parcelObtain.writeInt(IDummyService.f6136a);
                parcelObtain.writeInterfaceToken(this.f6150o);
                permissionTableItem.writeToParcel(parcelObtain, 0);
                this.f6151p.transact(5, parcelObtain, parcelObtain2, 1);
                parcelObtain2.readException();
            } finally {
                parcelObtain2.recycle();
                parcelObtain.recycle();
            }
        }
    }

    public static abstract class Stub extends Binder implements IDummyService {

        /* JADX INFO: renamed from: o */
        private String f6152o;

        /* JADX INFO: renamed from: p */
        private String f6153p;

        /* JADX INFO: renamed from: q */
        private PermissionControlConfig f6154q;

        /* JADX INFO: renamed from: r */
        private IDummyServiceCallback f6155r;

        /* JADX INFO: renamed from: s */
        private IBinder f6156s;

        /* JADX INFO: renamed from: t */
        private Stub f6157t;

        /* JADX INFO: renamed from: u */
        private boolean f6158u;

        public Stub() {
            this(null);
        }

        public Stub(Stub stub) {
            this.f6157t = stub;
            String serviceName = getServiceName();
            IBinder iBinderM2910c = C1152ai.m2910c(serviceName);
            if (iBinderM2910c == null) {
                iBinderM2910c = C1152ai.m2911d(serviceName);
                C1152ai.m2909b(serviceName, iBinderM2910c);
            }
            this.f6156s = iBinderM2910c;
            try {
                this.f6153p = this.f6156s.getInterfaceDescriptor();
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }

        /* JADX INFO: renamed from: a */
        private IDummyServiceCallback m2614a() {
            return this.f6157t == null ? this.f6155r : this.f6157t.f6155r;
        }

        /* JADX INFO: renamed from: a */
        private String m2615a(int i) {
            String[] packagesForUid = AbstractC1284ff.m3306d().getPackageManager().getPackagesForUid(i);
            if (packagesForUid == null || packagesForUid.length <= 0) {
                return null;
            }
            return packagesForUid[0];
        }

        /* JADX INFO: renamed from: a */
        private boolean m2616a(int i, Parcel parcel, Parcel parcel2, int i2) throws RemoteException {
            PermissionRequestInfo permissionRequestInfo;
            int value;
            boolean z = true;
            PermissionControlConfig permissionTable = getPermissionTable();
            IDummyServiceCallback iDummyServiceCallbackM2614a = m2614a();
            if (m2617b() && permissionTable != null && iDummyServiceCallbackM2614a != null && (permissionRequestInfo = getPermissionRequestInfo(i, parcel, parcel2, i2)) != null && (value = permissionTable.getValue(Binder.getCallingUid(), permissionRequestInfo.mRid)) != 65535) {
                permissionRequestInfo.mValue = value;
                int iOnRequest = (iDummyServiceCallbackM2614a.asBinder().pingBinder() && value == 2) ? iDummyServiceCallbackM2614a.onRequest(permissionRequestInfo) : value;
                switch (value) {
                    case 0:
                        z = false;
                        break;
                    case 1:
                        break;
                    case 2:
                        if (iOnRequest == 0) {
                            z = false;
                        }
                        break;
                    case PermissionControlConfig.PERMISSION_MODE_NULL /* 65535 */:
                        z = false;
                        break;
                    default:
                        z = false;
                        break;
                }
                if (z) {
                    parcel.setDataPosition(0);
                    return onHookHappen(i, parcel, parcel2, i2);
                }
            }
            return innerOnTransact(i, parcel, parcel2, i2);
        }

        /* JADX INFO: renamed from: b */
        private boolean m2617b() {
            return this.f6157t == null ? this.f6158u : this.f6157t.f6158u;
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public final void addPermissionTableItem(PermissionTableItem permissionTableItem) throws RemoteException {
            if (this.f6154q != null) {
                this.f6154q.addItem(permissionTableItem);
            }
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        public boolean execTransactForOwn(int i, Parcel parcel, Parcel parcel2, int i2) throws RemoteException {
            parcel.enforceInterface(this.f6153p);
            synchronized (this) {
                if (this.f6152o == null) {
                    this.f6152o = m2615a(Binder.getCallingUid());
                    AbstractC1284ff.m3304a(this.f6152o);
                }
            }
            switch (i) {
                case 1:
                    this.f6155r = IDummyServiceCallback.Stub.asInterface(parcel.readStrongBinder());
                    parcel2.writeNoException();
                    return true;
                case 2:
                    this.f6158u = parcel.readInt() == 1;
                    parcel2.writeNoException();
                    return true;
                case 3:
                    this.f6154q = parcel.readInt() != 0 ? PermissionControlConfig.createFromParcel(parcel) : null;
                    parcel2.writeNoException();
                    return true;
                case 4:
                    updatePermissionTable(parcel.readInt(), parcel.readInt(), parcel.readInt());
                    parcel2.writeNoException();
                    return true;
                case 5:
                    updatePermissionTable(PermissionTableItem.createFromParcel(parcel));
                    parcel2.writeNoException();
                    return true;
                case 6:
                    int iPingDummyService = pingDummyService(parcel.readInt(), parcel.readString());
                    parcel2.writeNoException();
                    parcel2.writeInt(iPingDummyService);
                    return true;
                case 7:
                    addPermissionTableItem(PermissionTableItem.createFromParcel(parcel));
                    parcel2.writeNoException();
                    return true;
                case 8:
                    removePermissionTableItem(PermissionTableItem.createFromParcel(parcel));
                    parcel2.writeNoException();
                    return true;
                default:
                    return false;
            }
        }

        public final IBinder getInnerBinder() {
            return this.f6156s;
        }

        @Override // android.os.Binder, android.os.IBinder
        public String getInterfaceDescriptor() {
            return this.f6153p;
        }

        protected abstract PermissionRequestInfo getPermissionRequestInfo(int i, Parcel parcel, Parcel parcel2, int i2) throws RemoteException;

        protected PermissionControlConfig getPermissionTable() {
            return this.f6157t == null ? this.f6154q : this.f6157t.f6154q;
        }

        public abstract String getServiceName();

        protected boolean innerOnTransact(int i, Parcel parcel, Parcel parcel2, int i2) throws RemoteException {
            parcel.setDataPosition(0);
            return this.f6156s.transact(i, parcel, parcel2, i2);
        }

        protected abstract boolean onHookHappen(int i, Parcel parcel, Parcel parcel2, int i2) throws RemoteException;

        @Override // android.os.Binder
        protected boolean onTransact(int i, Parcel parcel, Parcel parcel2, int i2) throws RemoteException {
            if (parcel.readInt() == 20100404) {
                return execTransactForOwn(i, parcel, parcel2, i2);
            }
            parcel.setDataPosition(0);
            return m2616a(i, parcel, parcel2, i2);
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public int pingDummyService(int i, String str) {
            if (this.f6157t != null) {
                return this.f6157t.pingDummyService(i, str);
            }
            if (!this.f6152o.equals(str)) {
                return IDummyService.f6149n;
            }
            if (i == 8) {
                return IDummyService.f6146k;
            }
            return 8 > i ? IDummyService.f6147l : IDummyService.f6148m;
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public final void removePermissionTableItem(PermissionTableItem permissionTableItem) throws RemoteException {
            if (this.f6154q != null) {
                this.f6154q.removeItem(permissionTableItem);
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public final void setDummyServiceCallback(IDummyServiceCallback iDummyServiceCallback) throws RemoteException {
            this.f6155r = iDummyServiceCallback;
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public final void setEnable(boolean z) throws RemoteException {
            this.f6158u = z;
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public final void setPermissionTable(PermissionControlConfig permissionControlConfig) throws RemoteException {
            this.f6154q = permissionControlConfig;
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public final void updatePermissionTable(int i, int i2, int i3) throws RemoteException {
            if (this.f6154q != null) {
                this.f6154q.update(i, i2, i3);
            }
        }

        @Override // com.tencent.tmsecure.module.permission.IDummyService
        public final void updatePermissionTable(PermissionTableItem permissionTableItem) throws RemoteException {
            if (this.f6154q != null) {
                this.f6154q.update(permissionTableItem);
            }
        }
    }

    void addPermissionTableItem(PermissionTableItem permissionTableItem) throws RemoteException;

    int pingDummyService(int i, String str);

    void removePermissionTableItem(PermissionTableItem permissionTableItem) throws RemoteException;

    void setDummyServiceCallback(IDummyServiceCallback iDummyServiceCallback) throws RemoteException;

    void setEnable(boolean z) throws RemoteException;

    void setPermissionTable(PermissionControlConfig permissionControlConfig) throws RemoteException;

    void updatePermissionTable(int i, int i2, int i3) throws RemoteException;

    void updatePermissionTable(PermissionTableItem permissionTableItem) throws RemoteException;
}
