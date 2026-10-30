package com.lenovo.performancecenter.performance;

import android.content.Context;
import android.os.Message;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class ClearAllAppGarbage {

    /* JADX INFO: renamed from: a */
    private ArrayList<String> f1676a = new ArrayList<>();

    /* JADX INFO: renamed from: b */
    private Context f1677b;

    public ClearAllAppGarbage(Context context) {
        this.f1677b = context;
    }

    public int[] getAllRunningAppInfo(Message msg) {
        int appCount = 0;
        int memoryRelease = 0;
        HashMap<String, int[]> map = ScanApplicationInfo.getRunningAppInfoJustInLauncher(this.f1677b);
        for (Map.Entry<String, int[]> element : map.entrySet()) {
            if (element.getValue()[2] == 1) {
                appCount++;
                memoryRelease += element.getValue()[1];
            }
            this.f1676a.add(element.getKey());
        }
        int[] arr = {appCount, memoryRelease};
        return arr;
    }

    public void clearAllApp(Message msg) {
        if (this.f1676a != null && this.f1676a.size() > 0) {
            RootPassage.execRootCmd(null, this.f1676a, " -fs ", this.f1677b);
        }
    }
}
