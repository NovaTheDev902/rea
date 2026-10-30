package com.lenovo.safecenter.broadcast;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;

/* JADX INFO: loaded from: classes.dex */
public class UpdateTrafficReceiver extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    private long f3466a = -1;

    /* JADX INFO: renamed from: b */
    private long f3467b = -1;

    /* JADX INFO: renamed from: c */
    private String f3468c = null;

    /* JADX INFO: renamed from: d */
    private LeSafeObservable f3469d;

    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        this.f3469d = LeSafeObservable.get(context);
        String action = intent.getAction();
        if (Const.INIT_BAR_ACTION_RTC.equals(action)) {
            Log.i("wu0wu", "UpdateTrafficReceiver initTraffic");
            this.f3466a = intent.getLongExtra("todayData", 0L);
            this.f3467b = intent.getLongExtra("monthfree", 0L);
            int intExtra = intent.getIntExtra("progress", 0);
            this.f3468c = intent.getStringExtra("month_limit");
            Log.i("wu0wu", "initTraffic progress=" + intExtra);
            Const.setTodayUsedTraffic(this.f3466a);
            Const.setMonthFreeTraffic(this.f3467b);
            Const.setMonthLimitTraffic(this.f3468c);
            Const.setProgressTrafficMonthUsed(intExtra);
            this.f3469d.noticeRefreshTrafficInfo();
        }
        if ("com.lenovo.safecenter.updatetrafficbar.broadcast".equals(action)) {
            Log.i("wu0wu", "UpdateTrafficReceiver updateTraffic");
            if (this.f3466a == -1) {
                this.f3466a = Const.getTodayUsedTraffic();
            }
            if (this.f3467b == -1) {
                this.f3467b = Const.getMonthFreeTraffic();
            }
            if (this.f3468c == null) {
                this.f3468c = Const.getMonthLimitTraffic();
            }
            long jLongValue = Long.valueOf(this.f3468c).longValue() * 1024 * 1024;
            long longExtra = intent.getLongExtra("changed", 0L);
            this.f3466a += longExtra;
            this.f3467b -= longExtra;
            int i = (int) (((jLongValue - this.f3467b) * 100) / jLongValue);
            Log.i("wu0wu", "updateTraffic progress=" + i);
            Const.setTodayUsedTraffic(this.f3466a);
            Const.setMonthFreeTraffic(this.f3467b);
            Const.setProgressTrafficMonthUsed(i);
            this.f3469d.noticeRefreshTrafficInfo();
        }
    }
}
