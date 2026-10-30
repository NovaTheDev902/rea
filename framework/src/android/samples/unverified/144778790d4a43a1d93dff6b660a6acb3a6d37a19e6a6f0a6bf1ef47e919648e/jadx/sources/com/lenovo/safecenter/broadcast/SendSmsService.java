package com.lenovo.safecenter.broadcast;

import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.IBinder;
import android.os.PowerManager;
import android.provider.MultiSIMUtils;
import android.telephony.SmsManager;
import android.telephony.TelephonyManager;
import android.util.Log;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class SendSmsService extends Service {
    public static final String DELIVERED_SMS_ACTION = "DELIVERED_SMS_ACTION";
    public static final String SENT_SMS_ACTION = "SENT_SMS_ACTION";

    /* JADX INFO: renamed from: d */
    private String f3462d;

    /* JADX INFO: renamed from: e */
    private String f3463e;

    /* JADX INFO: renamed from: a */
    static boolean f3456a = false;

    /* JADX INFO: renamed from: b */
    static boolean f3457b = false;

    /* JADX INFO: renamed from: f */
    private static ArrayList<PendingIntent> f3459f = null;

    /* JADX INFO: renamed from: g */
    private static ArrayList<PendingIntent> f3460g = null;

    /* JADX INFO: renamed from: c */
    static final Object f3458c = new Object();

    /* JADX INFO: renamed from: h */
    private static PowerManager.WakeLock f3461h = null;

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    /* JADX WARN: Type inference failed for: r0v1, types: [com.lenovo.safecenter.broadcast.SendSmsService$1] */
    @Override // android.app.Service
    public void onStart(final Intent intent, int startId) {
        super.onStart(intent, startId);
        Log.i("test", "in the SendSmsService sendSMS");
        new Thread() { // from class: com.lenovo.safecenter.broadcast.SendSmsService.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                SendSmsService.this.f3462d = intent.getStringExtra(PushReceiver.PHONE_NUMBER);
                SendSmsService.this.f3463e = intent.getStringExtra(DatabaseTables.LOG_MESSAGE);
                SendSmsService.this.sendSMS(SendSmsService.this.f3462d, SendSmsService.this.f3463e);
            }
        }.start();
    }

    public void sendSMS(String phoneNumber, String message) {
        Log.i("test", "in the SendSmsService sendSMS----Thread");
        if (MyMultiSIMUtils.isMultiSim(this)) {
            int[] states = MyMultiSIMUtils.getAllSimState(this);
            if (states[0] == 5 || states[0] == 2 || states[0] == 3) {
                f3456a = true;
            } else if (states[1] == 5 || states[1] == 2 || states[1] == 3) {
                f3457b = true;
            }
            ArrayList<String> msgs = SmsManager.getDefault().divideMessage(message);
            f3459f = new ArrayList<>();
            f3460g = new ArrayList<>();
            Intent sentIntent = new Intent("SENT_SMS_ACTION");
            PendingIntent sentPI = PendingIntent.getBroadcast(this, 0, sentIntent, 0);
            Intent deliverIntent = new Intent("DELIVERED_SMS_ACTION");
            PendingIntent deliverPI = PendingIntent.getBroadcast(this, 0, deliverIntent, 0);
            f3459f.add(sentPI);
            f3460g.add(deliverPI);
            if (f3456a) {
                Log.i("test", "sim1 ready send sms");
                try {
                    Thread.sleep(30000L);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                beginStartingService(this);
                try {
                    Thread.sleep(5000L);
                } catch (InterruptedException e2) {
                    e2.printStackTrace();
                }
                MultiSIMUtils.getDefault(this).sendMultipartTextMessage(phoneNumber, (String) null, msgs, f3459f, f3460g, 0);
                sendMsgService.f3470a++;
            } else if (f3457b) {
                Log.i("test", "sim2 ready send sms");
                try {
                    Thread.sleep(30000L);
                } catch (InterruptedException e3) {
                    e3.printStackTrace();
                }
                beginStartingService(this);
                try {
                    Thread.sleep(5000L);
                } catch (InterruptedException e4) {
                    e4.printStackTrace();
                }
                MultiSIMUtils.getDefault(this).sendMultipartTextMessage(phoneNumber, (String) null, msgs, f3459f, f3460g, 1);
                sendMsgService.f3470a++;
            }
        } else {
            TelephonyManager mTelephonyMgr = (TelephonyManager) getSystemService("phone");
            int state = mTelephonyMgr.getSimState();
            SmsManager sms = SmsManager.getDefault();
            ArrayList<String> msgs2 = sms.divideMessage(message);
            f3459f = new ArrayList<>();
            f3460g = new ArrayList<>();
            Intent sentIntent2 = new Intent("SENT_SMS_ACTION");
            PendingIntent sentPI2 = PendingIntent.getBroadcast(this, 0, sentIntent2, 0);
            Intent deliverIntent2 = new Intent("DELIVERED_SMS_ACTION");
            PendingIntent deliverPI2 = PendingIntent.getBroadcast(this, 0, deliverIntent2, 0);
            f3459f.add(sentPI2);
            f3460g.add(deliverPI2);
            if (state == 5) {
                try {
                    Thread.sleep(30000L);
                } catch (InterruptedException e5) {
                    e5.printStackTrace();
                }
                beginStartingService(this);
                try {
                    Thread.sleep(5000L);
                } catch (InterruptedException e6) {
                    e6.printStackTrace();
                }
                sms.sendMultipartTextMessage(phoneNumber, null, msgs2, f3459f, f3460g);
                sendMsgService.f3471b++;
            }
        }
        stopSelf();
    }

    public static void finishStartingService() {
        synchronized (f3458c) {
            if (f3461h != null) {
                f3461h.release();
            }
        }
    }

    public static void beginStartingService(Context context) {
        synchronized (f3458c) {
            if (f3461h == null) {
                PowerManager pm = (PowerManager) context.getSystemService("power");
                f3461h = pm.newWakeLock(268435482, "StartingAlertService");
                f3461h.setReferenceCounted(false);
            }
            f3461h.acquire();
        }
    }

    @Override // android.app.Service
    public void onDestroy() {
        Log.i("test", "SendSmsService onDestroy");
        super.onDestroy();
    }
}
