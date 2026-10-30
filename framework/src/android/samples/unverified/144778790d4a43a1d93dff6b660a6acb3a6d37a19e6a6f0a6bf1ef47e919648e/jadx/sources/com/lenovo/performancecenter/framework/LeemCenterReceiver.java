package com.lenovo.performancecenter.framework;

import android.app.ActivityManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import com.lenovo.performancecenter.LeemCenterTools;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.performancecenter.performance.DataLayerManageBoot;
import com.lenovo.performancecenter.performance.ScanApplicationInfo;
import com.lenovo.safecenter.utils.AppCheck;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Timer;
import java.util.TimerTask;

/* JADX INFO: loaded from: classes.dex */
public class LeemCenterReceiver extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    private ActivityManager f1638a;

    /* JADX INFO: renamed from: b */
    private Timer f1639b;

    /* JADX INFO: renamed from: c */
    private long f1640c;

    /* JADX INFO: renamed from: d */
    private C0159a f1641d;

    /* JADX INFO: renamed from: e */
    private Context f1642e;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m578a(Context x1) {
        ArrayList<String> bootForbidedList = new DataLayerManageBoot().getBootForbidedList(x1);
        ArrayList<String> recordPkgList = Utils.getRecordPkgList();
        for (int i = 0; i < bootForbidedList.size(); i++) {
            if (recordPkgList.contains(bootForbidedList.get(i))) {
                bootForbidedList.remove(i);
            }
        }
        Iterator<String> it = bootForbidedList.iterator();
        while (it.hasNext()) {
            Log.i("LeemCenterReceiver", "Boot KillProcess ---> " + it.next());
        }
        if (bootForbidedList.size() != 0) {
            ScanApplicationInfo.killAllProcess(null, x1, bootForbidedList);
        }
    }

    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        Log.i("LeemCenterReceiver", "onReceive()");
        this.f1642e = context;
        String action = intent.getAction();
        this.f1640c = System.nanoTime();
        if (this.f1641d == null) {
            this.f1641d = new C0159a();
        }
        if (this.f1638a == null) {
            this.f1638a = (ActivityManager) context.getSystemService("activity");
        }
        if (this.f1639b == null) {
            this.f1639b = new Timer(true);
        }
        "android.hardware.usb.action.USB_STATE".equals(action);
        if ("android.intent.action.BOOT_COMPLETED".equals(action)) {
            Utils.recordBootTime(System.currentTimeMillis());
            LeemCenterTools.writeBootStartTime(context);
            Log.i("LeemCenterReceiver", System.currentTimeMillis() + "---> Intent.ACTION_BOOT_COMPLETED");
            if (Utils.getIsRoot()) {
                Log.i("LeemCenterReceiver", System.currentTimeMillis() + "isRoot, exec kill process");
                this.f1639b.schedule(this.f1641d, 20000L);
            }
        }
        if (AppCheck.ACTION_ACTIVITY_SWITCH.equals(action)) {
            long openTime = System.currentTimeMillis();
            long interval = openTime - Utils.getLastKillTime(this.f1642e);
            Log.i("LeemCenterReceiver", "newPkg interval == " + interval);
            if (interval <= Utils.CLICK_INTERVAL && interval > 0) {
                String newPkg = intent.getStringExtra("newPkg");
                Log.i("LeemCenterReceiver", "newPkg interval == " + newPkg);
                ArrayList<String> noResetList = DataLayerManager.getListForResetKillTime(this.f1642e);
                if (!noResetList.contains(newPkg)) {
                    Utils.recordKillTimeAndPosition(this.f1642e, 1L, 5);
                    Log.i("LeemCenterReceiver", "newPkg resetKillTime");
                }
            }
            long time = openTime - Utils.getBootTime();
            Log.i("LeemCenterReceiver", "cur == " + System.currentTimeMillis() + " bootTime == " + Utils.getBootTime() + " time == " + time);
            if (time <= 20000 && time >= 0) {
                String newPkg2 = intent.getStringExtra("newPkg");
                Log.i("LeemCenterReceiver", "newPkg == " + newPkg2);
                Utils.recordOpenPkgList(newPkg2);
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.framework.LeemCenterReceiver$a */
    class C0159a extends TimerTask {
        C0159a() {
        }

        @Override // java.util.TimerTask, java.lang.Runnable
        public final void run() {
            long endTime = System.nanoTime();
            Log.i("LeemCenterReceiver", "KillProcessTimerTask run...cost=" + (endTime - LeemCenterReceiver.this.f1640c));
            LeemCenterReceiver leemCenterReceiver = LeemCenterReceiver.this;
            LeemCenterReceiver.m578a(LeemCenterReceiver.this.f1642e);
        }
    }
}
