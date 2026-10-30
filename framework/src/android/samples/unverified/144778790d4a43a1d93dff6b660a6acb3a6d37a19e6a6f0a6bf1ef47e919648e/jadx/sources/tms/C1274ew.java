package tms;

import android.os.Parcel;

/* JADX INFO: renamed from: tms.ew */
/* JADX INFO: loaded from: classes.dex */
final class C1274ew {

    /* JADX INFO: renamed from: a */
    private static int f7289a;

    /* JADX INFO: renamed from: b */
    private static int f7290b;

    static {
        f7289a = 43;
        f7290b = 41;
        try {
            f7289a = ((Integer) C1151ah.m2900a("android.view.IWindowManager$Stub", "TRANSACTION_setAnimationScales")).intValue();
            f7290b = ((Integer) C1151ah.m2900a("android.view.IWindowManager$Stub", "TRANSACTION_getAnimationScales")).intValue();
        } catch (Exception e) {
            e.printStackTrace();
            f7289a = 43;
            f7290b = 41;
        }
    }

    C1274ew() {
    }

    /* JADX INFO: renamed from: a */
    public static void m3270a(float[] fArr) {
        Parcel parcelObtain = Parcel.obtain();
        Parcel parcelObtain2 = Parcel.obtain();
        try {
            try {
                parcelObtain.writeInterfaceToken("android.view.IWindowManager");
                parcelObtain.writeFloatArray(fArr);
                C1152ai.m2904a("window").transact(f7289a, parcelObtain, parcelObtain2, 0);
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

    /* JADX INFO: renamed from: a */
    public static float[] m3271a() {
        Parcel parcelObtain = Parcel.obtain();
        Parcel parcelObtain2 = Parcel.obtain();
        float[] fArrCreateFloatArray = null;
        try {
            try {
                parcelObtain.writeInterfaceToken("android.view.IWindowManager");
                C1152ai.m2904a("window").transact(f7290b, parcelObtain, parcelObtain2, 0);
                parcelObtain2.readException();
                fArrCreateFloatArray = parcelObtain2.createFloatArray();
                parcelObtain2.recycle();
            } catch (Exception e) {
                e.printStackTrace();
                parcelObtain2.recycle();
            }
            parcelObtain.recycle();
            return fArrCreateFloatArray;
        } catch (Throwable th) {
            parcelObtain2.recycle();
            parcelObtain.recycle();
            throw th;
        }
    }
}
