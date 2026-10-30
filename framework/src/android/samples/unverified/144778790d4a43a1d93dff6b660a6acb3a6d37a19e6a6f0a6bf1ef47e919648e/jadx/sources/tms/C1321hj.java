package tms;

import android.util.Log;
import java.text.SimpleDateFormat;
import java.util.Date;

/* JADX INFO: renamed from: tms.hj */
/* JADX INFO: loaded from: classes.dex */
public class C1321hj implements InterfaceC1317hd {
    @Override // tms.InterfaceC1317hd
    /* JADX INFO: renamed from: a */
    public void mo3502a(String str, String str2) {
        if (str2 != null) {
            Log.i(str, str2);
        }
    }

    @Override // tms.InterfaceC1317hd
    /* JADX INFO: renamed from: b */
    public void mo3503b(String str, String str2) {
        if (str2 != null) {
            Log.e(str, str2);
        }
    }

    @Override // tms.InterfaceC1317hd
    /* JADX INFO: renamed from: c */
    public void mo3504c(String str, String str2) {
        if (str2 != null) {
            Log.d(str, str2);
            com.tencent.tmsecure.utils.Log.writeLog(new SimpleDateFormat("yyyy-MM-dd_HH:mm:ss").format(new Date(System.currentTimeMillis())) + " " + str + " " + str2 + "\r\n");
        }
    }
}
