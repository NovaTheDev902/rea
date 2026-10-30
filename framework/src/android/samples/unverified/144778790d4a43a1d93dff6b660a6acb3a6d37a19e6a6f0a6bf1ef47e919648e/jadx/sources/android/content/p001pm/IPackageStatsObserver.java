package android.content.p001pm;

import android.content.pm.PackageStats;
import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: loaded from: classes.dex */
public interface IPackageStatsObserver extends IInterface {
    void onGetStatsCompleted(PackageStats packageStats, boolean z) throws RemoteException;

    public static abstract class Stub extends Binder implements IPackageStatsObserver {
        public Stub() {
            attachInterface(this, "android.content.pm.IPackageStatsObserver");
        }

        public static IPackageStatsObserver asInterface(IBinder obj) {
            if (obj == null) {
                return null;
            }
            IInterface iin = obj.queryLocalInterface("android.content.pm.IPackageStatsObserver");
            if (iin != null && (iin instanceof IPackageStatsObserver)) {
                return (IPackageStatsObserver) iin;
            }
            return new IPackageStatsObserverC0006a(obj);
        }

        @Override // android.os.IInterface
        public IBinder asBinder() {
            return this;
        }

        @Override // android.os.Binder
        public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
            PackageStats _arg0;
            switch (code) {
                case 1:
                    data.enforceInterface("android.content.pm.IPackageStatsObserver");
                    if (data.readInt() != 0) {
                        _arg0 = (PackageStats) PackageStats.CREATOR.createFromParcel(data);
                    } else {
                        _arg0 = null;
                    }
                    boolean _arg1 = data.readInt() != 0;
                    onGetStatsCompleted(_arg0, _arg1);
                    return true;
                case 1598968902:
                    reply.writeString("android.content.pm.IPackageStatsObserver");
                    return true;
                default:
                    return super.onTransact(code, data, reply, flags);
            }
        }

        /* JADX INFO: renamed from: android.content.pm.IPackageStatsObserver$Stub$a */
        private static class IPackageStatsObserverC0006a implements IPackageStatsObserver {

            /* JADX INFO: renamed from: a */
            private IBinder f637a;

            IPackageStatsObserverC0006a(IBinder remote) {
                this.f637a = remote;
            }

            @Override // android.os.IInterface
            public final IBinder asBinder() {
                return this.f637a;
            }

            @Override // android.content.p001pm.IPackageStatsObserver
            public final void onGetStatsCompleted(PackageStats pStats, boolean succeeded) throws RemoteException {
                Parcel _data = Parcel.obtain();
                try {
                    _data.writeInterfaceToken("android.content.pm.IPackageStatsObserver");
                    if (pStats != null) {
                        _data.writeInt(1);
                        pStats.writeToParcel(_data, 0);
                    } else {
                        _data.writeInt(0);
                    }
                    _data.writeInt(succeeded ? 1 : 0);
                    this.f637a.transact(1, _data, null, 1);
                } finally {
                    _data.recycle();
                }
            }
        }
    }
}
