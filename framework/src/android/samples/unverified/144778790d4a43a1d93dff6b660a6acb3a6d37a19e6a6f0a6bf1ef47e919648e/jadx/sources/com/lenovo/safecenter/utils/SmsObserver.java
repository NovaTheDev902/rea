package com.lenovo.safecenter.utils;

import android.content.Context;
import android.database.ContentObserver;
import android.os.Handler;
import android.util.Log;

/* JADX INFO: loaded from: classes.dex */
public class SmsObserver extends ContentObserver {

    /* JADX INFO: renamed from: b */
    private static int f5806b = 0;

    /* JADX INFO: renamed from: a */
    private Context f5807a;

    public SmsObserver(Context context, Handler handler) {
        super(handler);
        this.f5807a = context;
        Log.i("wu0wu", "Lesafe SmsObserver on create");
    }

    @Override // android.database.ContentObserver
    public void onChange(boolean selfChange) {
        Log.i("wu0wu", "==sms onChange  start==count=" + f5806b);
        SmsUtil.monitorSmsState(this.f5807a);
        Log.i("wu0wu", "==sms onChange  end==count=" + f5806b);
        f5806b++;
    }
}
