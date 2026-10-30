package com.lenovo.safecenter.broadcast;

import android.content.BroadcastReceiver;
import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.util.Log;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.platform.DoubleCardUtils;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.SmsUtil;

/* JADX INFO: loaded from: classes.dex */
public class SmsBroadcast extends BroadcastReceiver {
    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        intent.getAction().equals("lenovo.backgroud.sendsms");
        if (intent.getAction().equals("SENT_SMS_ACTION")) {
            int code = getResultCode();
            switch (code) {
                case -1:
                    AppDatabase database = new AppDatabase(context);
                    SafeLog sendsmsLog = database.getLastTariffLog();
                    if (sendsmsLog != null && Const.isTariff) {
                        String str = sendsmsLog.number;
                        String str2 = sendsmsLog.time;
                        String str3 = sendsmsLog.content;
                        ContentValues contentValues = new ContentValues();
                        contentValues.put("address", str);
                        contentValues.put("date", str2);
                        contentValues.put(PushReceiver.READ, (Integer) 1);
                        contentValues.put("status", (Integer) (-1));
                        contentValues.put("type", (Integer) 2);
                        contentValues.put(PushReceiver.BODY, str3);
                        Log.d("handmes", "insertToInbox uri:" + context.getContentResolver().insert(Uri.parse("content://sms"), contentValues));
                    } else {
                        SmsUtil.onHasSendSmsEvent(context, Long.valueOf(System.currentTimeMillis()), Const.getSmsSendNumCurrMonth() + 1);
                    }
                    if (DoubleCardUtils.info) {
                        Toast.makeText(context, context.getString(C0415R.string.sendsms_success), 0).show();
                    }
                    break;
                default:
                    Toast.makeText(context, context.getString(C0415R.string.sendsms_fail), 0).show();
                    break;
            }
        }
    }
}
