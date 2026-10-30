package com.lenovo.safecenter.mmsutils;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.widget.Toast;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import java.io.UnsupportedEncodingException;

/* JADX INFO: loaded from: classes.dex */
public class MMSReciver extends BroadcastReceiver {
    public static final String TAG = "Push Receiver";

    /* JADX INFO: renamed from: a */
    Context f4309a;

    /* JADX INFO: renamed from: b */
    Intent f4310b;

    /* JADX WARN: Type inference failed for: r0v6, types: [com.lenovo.safecenter.mmsutils.MMSReciver$1] */
    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        Log.v("Push Receiver", "Intent recieved: " + intent.getAction());
        if (intent.getAction().equals("android.provider.Telephony.SMS_RECEIVED")) {
            Log.i("Push Receiver", "SMS: " + intent.getAction());
            Toast.makeText(context, "SMS_RECEIVED", 1).show();
        }
        if (intent.getAction().equals("android.provider.Telephony.WAP_PUSH_RECEIVED")) {
            Log.v("Push Receiver", "PUSH: " + intent.getAction());
            Toast.makeText(context, "PUSH MSG", 1).show();
        }
        Log.v("Push Receiver", "MMSReciver abortBroadcast();");
        this.f4309a = context;
        this.f4310b = intent;
        new Thread() { // from class: com.lenovo.safecenter.mmsutils.MMSReciver.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                byte[] pushData = MMSReciver.this.f4310b.getByteArrayExtra(SettingUtil.DATA);
                TyuMMSParser parser = new TyuMMSParser(pushData);
                GenericPdu pdu = parser.parse();
                if (pdu == null) {
                    Log.e("Push Receiver", "Invalid PUSH data");
                    return;
                }
                try {
                    String all_data = new String(pushData, InterfaceC0079b.f1213a);
                    Log.v("Push Receiver", all_data);
                } catch (UnsupportedEncodingException e2) {
                    e2.printStackTrace();
                }
                String val_from = pdu.getFrom().getString();
                switch (pdu.getMessageType()) {
                    case 130:
                        NotificationInd npdu = (NotificationInd) pdu;
                        try {
                            String location = new String(npdu.getContentLocation(), InterfaceC0079b.f1213a);
                            Log.v("Push Receiver", location);
                        } catch (UnsupportedEncodingException e) {
                            e.printStackTrace();
                        }
                        try {
                            String subject = npdu.getSubject().getString();
                            Log.v("Push Receiver", subject);
                        } catch (Exception e1) {
                            e1.printStackTrace();
                        }
                        try {
                            String transactionId = new String(npdu.getTransactionId(), InterfaceC0079b.f1213a);
                            Log.v("Push Receiver", transactionId);
                        } catch (UnsupportedEncodingException e3) {
                            e3.printStackTrace();
                        }
                        try {
                            String messageType = new String(npdu.getMessageClass(), InterfaceC0079b.f1213a);
                            Log.v("Push Receiver", messageType);
                        } catch (UnsupportedEncodingException e4) {
                            e4.printStackTrace();
                        }
                        break;
                }
                Log.v("Push Receiver", val_from);
                MMSReciver.this.f4309a = null;
                MMSReciver.this.f4310b = null;
            }
        }.start();
        abortBroadcast();
    }
}
