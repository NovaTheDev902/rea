package tms;

import android.os.IBinder;
import android.os.Parcel;
import android.os.RemoteException;

/* JADX INFO: renamed from: tms.d */
/* JADX INFO: loaded from: classes.dex */
final class C1224d implements InterfaceC1197c {

    /* JADX INFO: renamed from: a */
    private String f7058a;

    /* JADX INFO: renamed from: b */
    private String f7059b;

    /* JADX INFO: renamed from: c */
    private int f7060c;

    /* JADX INFO: renamed from: d */
    private int f7061d;

    /* JADX INFO: renamed from: e */
    private int f7062e;

    public C1224d(String str) {
        this.f7059b = str;
        try {
            IBinder iBinderM2904a = C1152ai.m2904a(this.f7059b);
            if (iBinderM2904a == null) {
                return;
            } else {
                this.f7058a = iBinderM2904a.getInterfaceDescriptor();
            }
        } catch (RemoteException e) {
            e.printStackTrace();
        }
        C1151ah.m2902a(this.f7058a + "$Stub");
        this.f7060c = C1151ah.m2897a("TRANSACTION_call", 2);
        this.f7061d = C1151ah.m2897a("TRANSACTION_endCall", 5);
        this.f7062e = C1151ah.m2897a("TRANSACTION_cancelMissedCallsNotification", 13);
    }

    @Override // tms.InterfaceC1197c
    /* JADX INFO: renamed from: a */
    public final void mo3038a(String str) {
        Parcel parcelObtain = Parcel.obtain();
        Parcel parcelObtain2 = Parcel.obtain();
        try {
            try {
                parcelObtain.writeInterfaceToken(this.f7058a);
                parcelObtain.writeString(str);
                C1152ai.m2904a(this.f7059b).transact(this.f7060c, parcelObtain, parcelObtain2, 0);
                parcelObtain2.readException();
                parcelObtain2.recycle();
            } catch (RemoteException e) {
                e.printStackTrace();
                parcelObtain2.recycle();
            } catch (Exception e2) {
                e2.printStackTrace();
                parcelObtain2.recycle();
            }
            parcelObtain.recycle();
        } catch (Throwable th) {
            parcelObtain2.recycle();
            parcelObtain.recycle();
            throw th;
        }
    }

    @Override // tms.InterfaceC1197c
    /* JADX INFO: renamed from: a */
    public final boolean mo3039a() {
        boolean z = false;
        Parcel parcelObtain = Parcel.obtain();
        Parcel parcelObtain2 = Parcel.obtain();
        try {
            try {
                parcelObtain.writeInterfaceToken(this.f7058a);
                C1152ai.m2904a(this.f7059b).transact(this.f7061d, parcelObtain, parcelObtain2, 0);
                parcelObtain2.readException();
                z = parcelObtain2.readInt() != 0;
                parcelObtain2.recycle();
            } catch (RemoteException e) {
                e.printStackTrace();
                parcelObtain2.recycle();
            } catch (Exception e2) {
                e2.printStackTrace();
                parcelObtain2.recycle();
            }
            parcelObtain.recycle();
            return z;
        } catch (Throwable th) {
            parcelObtain2.recycle();
            parcelObtain.recycle();
            throw th;
        }
    }

    @Override // tms.InterfaceC1197c
    /* JADX INFO: renamed from: b */
    public final void mo3040b() {
        Parcel parcelObtain = Parcel.obtain();
        Parcel parcelObtain2 = Parcel.obtain();
        try {
            try {
                parcelObtain.writeInterfaceToken(this.f7058a);
                C1152ai.m2904a(this.f7059b).transact(this.f7062e, parcelObtain, parcelObtain2, 0);
                parcelObtain2.readException();
                parcelObtain2.recycle();
            } catch (RemoteException e) {
                e.printStackTrace();
                parcelObtain2.recycle();
            } catch (Exception e2) {
                e2.printStackTrace();
                parcelObtain2.recycle();
            }
            parcelObtain.recycle();
        } catch (Throwable th) {
            parcelObtain2.recycle();
            parcelObtain.recycle();
            throw th;
        }
    }
}
