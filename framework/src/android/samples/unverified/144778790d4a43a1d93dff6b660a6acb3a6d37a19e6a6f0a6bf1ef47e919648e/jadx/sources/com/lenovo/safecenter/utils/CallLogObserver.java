package com.lenovo.safecenter.utils;

import android.content.Context;
import android.database.ContentObserver;
import android.os.Handler;
import android.util.Log;

/* JADX INFO: loaded from: classes.dex */
public class CallLogObserver extends ContentObserver {

    /* JADX INFO: renamed from: a */
    private Context f5712a;

    public CallLogObserver(Context context, Handler handler) {
        super(handler);
        this.f5712a = context;
        Log.i("wu0wu", "Lesafe CallLogObserver on create");
    }

    @Override // android.database.ContentObserver
    public void onChange(boolean selfChange) {
        Log.i("wu0wu", "============CallLog onChange============");
        CallUtil.statisticsCallDurationByType(this.f5712a);
    }
}
