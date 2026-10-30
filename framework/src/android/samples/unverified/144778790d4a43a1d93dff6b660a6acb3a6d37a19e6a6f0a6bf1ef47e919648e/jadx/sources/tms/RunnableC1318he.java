package tms;

import com.tencent.tmsecure.utils.PhoneInfoUtil;

/* JADX INFO: renamed from: tms.he */
/* JADX INFO: loaded from: classes.dex */
public final class RunnableC1318he implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ PhoneInfoUtil.CPUScaleListener f7446a;

    public RunnableC1318he(PhoneInfoUtil.CPUScaleListener cPUScaleListener) {
        this.f7446a = cPUScaleListener;
    }

    @Override // java.lang.Runnable
    public final void run() {
        PhoneInfoUtil.CPUScaleListener cPUScaleListener;
        String str;
        String str2;
        int i = 0;
        try {
            try {
                try {
                    String[] strArrSplit = C1336v.m3606i("/proc/stat").split("\\n");
                    int length = strArrSplit.length;
                    int i2 = 0;
                    while (true) {
                        if (i2 >= length) {
                            str = null;
                            break;
                        }
                        str = strArrSplit[i2];
                        if (str != null && !str.equals("")) {
                            break;
                        } else {
                            i2++;
                        }
                    }
                    if (str == null) {
                        cPUScaleListener = this.f7446a;
                    } else {
                        String[] strArrSplit2 = str.split("\\s+");
                        Thread.sleep(500L);
                        String[] strArrSplit3 = C1336v.m3606i("/proc/stat").split("\\n");
                        int length2 = strArrSplit3.length;
                        int i3 = 0;
                        while (true) {
                            if (i3 >= length2) {
                                str2 = null;
                                break;
                            }
                            str2 = strArrSplit3[i3];
                            if (str2 != null && !str2.equals("")) {
                                break;
                            } else {
                                i3++;
                            }
                        }
                        if (str2 != null) {
                            String[] strArrSplit4 = str2.split("\\s+");
                            int i4 = 0;
                            for (int i5 = 1; i5 < strArrSplit2.length; i5++) {
                                i4 += Integer.parseInt(strArrSplit2[i5]);
                            }
                            for (int i6 = 1; i6 < strArrSplit4.length; i6++) {
                                i += Integer.parseInt(strArrSplit4[i6]);
                            }
                            int i7 = i - i4;
                            this.f7446a.onFinish((((i7 - (Integer.parseInt(strArrSplit4[4]) - Integer.parseInt(strArrSplit2[4]))) * 1000) / i7) / 10.0f);
                            return;
                        }
                        cPUScaleListener = this.f7446a;
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                    cPUScaleListener = this.f7446a;
                }
            } catch (ArrayIndexOutOfBoundsException e2) {
                e2.printStackTrace();
                cPUScaleListener = this.f7446a;
            }
            cPUScaleListener.onFinish(0.0f);
        } catch (Throwable th) {
            this.f7446a.onFinish(0.0f);
            throw th;
        }
    }
}
