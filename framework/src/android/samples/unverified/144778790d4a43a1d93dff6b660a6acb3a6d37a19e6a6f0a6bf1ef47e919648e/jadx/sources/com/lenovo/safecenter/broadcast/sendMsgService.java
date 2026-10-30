package com.lenovo.safecenter.broadcast;

import android.app.PendingIntent;
import android.app.Service;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.IBinder;
import android.os.PowerManager;
import android.provider.MultiSIMUtils;
import android.telephony.SmsManager;
import android.telephony.TelephonyManager;
import android.util.Log;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.platform.DoubleCardUtils;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.PwdUtil;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class sendMsgService extends Service {
    public static final String DELIVERED_SMS_ACTION = "DELIVERED_SMS_ACTION";
    public static final String SENT_SMS_ACTION = "SENT_SMS_ACTION";

    /* JADX INFO: renamed from: f */
    private int f3479f;

    /* JADX INFO: renamed from: g */
    private String f3480g;

    /* JADX INFO: renamed from: h */
    private String f3481h;

    /* JADX INFO: renamed from: a */
    static int f3470a = 0;

    /* JADX INFO: renamed from: i */
    private static ArrayList<PendingIntent> f3475i = null;

    /* JADX INFO: renamed from: j */
    private static ArrayList<PendingIntent> f3476j = null;

    /* JADX INFO: renamed from: k */
    private static BroadcastReceiver f3477k = null;

    /* JADX INFO: renamed from: b */
    static int f3471b = 0;

    /* JADX INFO: renamed from: c */
    static final Object f3472c = new Object();

    /* JADX INFO: renamed from: l */
    private static PowerManager.WakeLock f3478l = null;

    /* JADX INFO: renamed from: d */
    static boolean f3473d = false;

    /* JADX INFO: renamed from: e */
    static boolean f3474e = false;

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    /* JADX WARN: Type inference failed for: r0v2, types: [com.lenovo.safecenter.broadcast.sendMsgService$1] */
    @Override // android.app.Service
    public void onStart(final Intent intent, int startId) {
        super.onStart(intent, startId);
        if (intent != null) {
            this.f3479f = intent.getIntExtra("type", 0);
            new Thread() { // from class: com.lenovo.safecenter.broadcast.sendMsgService.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    try {
                        sendMsgService.this.f3480g = intent.getStringExtra(PushReceiver.PHONE_NUMBER);
                        sendMsgService.this.f3481h = intent.getStringExtra(DatabaseTables.LOG_MESSAGE);
                        Log.e("test", "phoneNumber: " + sendMsgService.this.f3480g + " smsMessage: " + sendMsgService.this.f3481h);
                        if (sendMsgService.this.f3480g != null && sendMsgService.this.f3480g.length() != 0) {
                            if (sendMsgService.this.f3479f > 0) {
                                sendMsgService.this.sendSMS(sendMsgService.this, sendMsgService.this.f3480g, sendMsgService.this.f3481h);
                            } else {
                                DoubleCardUtils.sendMessage(sendMsgService.this, sendMsgService.this.f3480g, sendMsgService.this.f3481h, false);
                            }
                            Const.isTariff = false;
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }.start();
            if (this.f3479f <= 0) {
                Log.i("test", "type <= 0");
                stopSelf();
            }
        }
    }

    public void sendSMS(final Context context, final String phoneNumber, String message) {
        Log.i("test", "in the sendSMS");
        if (MyMultiSIMUtils.isMultiSim(context)) {
            int[] states = MyMultiSIMUtils.getAllSimState(context);
            if (states[0] == 5 || states[0] == 2 || states[0] == 3) {
                f3473d = true;
            } else if (states[1] == 5 || states[1] == 2 || states[1] == 3) {
                f3474e = true;
            }
            Log.d("test", "sendSMS simState0: " + states[0] + " simState1: " + states[1]);
            ArrayList<String> msgs = SmsManager.getDefault().divideMessage(message);
            f3475i = new ArrayList<>();
            f3476j = new ArrayList<>();
            Intent sentIntent = new Intent("SENT_SMS_ACTION");
            PendingIntent sentPI = PendingIntent.getBroadcast(context, 0, sentIntent, 0);
            Intent deliverIntent = new Intent("DELIVERED_SMS_ACTION");
            PendingIntent deliverPI = PendingIntent.getBroadcast(context, 0, deliverIntent, 0);
            f3475i.add(sentPI);
            f3476j.add(deliverPI);
            f3477k = new BroadcastReceiver() { // from class: com.lenovo.safecenter.broadcast.sendMsgService.2
                @Override // android.content.BroadcastReceiver
                public final void onReceive(Context _context, Intent _intent) {
                    int code = getResultCode();
                    Log.d("test", "code: " + code);
                    switch (code) {
                        case -1:
                            Log.d("test", context.getString(C0415R.string.sendsms_success));
                            _context.unregisterReceiver(sendMsgService.f3477k);
                            sendMsgService.finishStartingService();
                            sendMsgService.this.stopSelf();
                            break;
                        case 1:
                            Log.d("test", "SMS generic failure actions");
                            break;
                        case 2:
                            Log.d("test", "SMS radio off failure actions");
                            break;
                        case 3:
                            Log.d("test", "SMS null PDU failure actions");
                            if (sendMsgService.f3470a <= 3) {
                                sendMsgService.this.sendSMS(phoneNumber);
                            }
                            break;
                        case 4:
                            Log.d("test", context.getString(C0415R.string.sendsms_no_service));
                            break;
                    }
                }
            };
            context.registerReceiver(f3477k, new IntentFilter("SENT_SMS_ACTION"));
            if (f3473d) {
                beginStartingService(context);
                try {
                    Thread.sleep(5000L);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, f3475i, f3476j, 0);
                f3470a++;
                return;
            }
            if (f3474e) {
                beginStartingService(context);
                try {
                    Thread.sleep(5000L);
                } catch (InterruptedException e2) {
                    e2.printStackTrace();
                }
                MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, f3475i, f3476j, 1);
                f3470a++;
                return;
            }
            return;
        }
        TelephonyManager mTelephonyMgr = (TelephonyManager) context.getSystemService("phone");
        int state = mTelephonyMgr.getSimState();
        SmsManager sms = SmsManager.getDefault();
        ArrayList<String> msgs2 = sms.divideMessage(message);
        f3475i = new ArrayList<>();
        f3476j = new ArrayList<>();
        Intent sentIntent2 = new Intent("SENT_SMS_ACTION");
        PendingIntent sentPI2 = PendingIntent.getBroadcast(context, 0, sentIntent2, 0);
        Intent deliverIntent2 = new Intent("DELIVERED_SMS_ACTION");
        PendingIntent deliverPI2 = PendingIntent.getBroadcast(context, 0, deliverIntent2, 0);
        f3475i.add(sentPI2);
        f3476j.add(deliverPI2);
        f3477k = new BroadcastReceiver() { // from class: com.lenovo.safecenter.broadcast.sendMsgService.3
            @Override // android.content.BroadcastReceiver
            public final void onReceive(Context _context, Intent _intent) {
                int code = getResultCode();
                Log.d("test", "code: " + code);
                switch (code) {
                    case -1:
                        Log.d("test", context.getString(C0415R.string.sendsms_success));
                        _context.unregisterReceiver(sendMsgService.f3477k);
                        sendMsgService.finishStartingService();
                        sendMsgService.this.stopSelf();
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        if (sendMsgService.f3471b <= 3) {
                            sendMsgService.this.sendSMS(phoneNumber);
                            sendMsgService.f3471b++;
                        }
                        break;
                }
            }
        };
        context.registerReceiver(f3477k, new IntentFilter("SENT_SMS_ACTION"));
        if (state == 5) {
            beginStartingService(context);
            try {
                Thread.sleep(5000L);
            } catch (InterruptedException e3) {
                e3.printStackTrace();
            }
            sms.sendMultipartTextMessage(phoneNumber, null, msgs2, f3475i, f3476j);
            f3471b++;
        }
    }

    public static void finishStartingService() {
        synchronized (f3472c) {
            if (f3478l != null) {
                f3478l.release();
            }
        }
    }

    public static void beginStartingService(Context context) {
        synchronized (f3472c) {
            if (f3478l == null) {
                PowerManager pm = (PowerManager) context.getSystemService("power");
                f3478l = pm.newWakeLock(268435482, "StartingAlertService");
                f3478l.setReferenceCounted(false);
            }
            f3478l.acquire();
        }
    }

    public void sendSMS(String safeNumber) {
        Log.i("test", "sendMSG sendSMS:" + f3470a);
        Intent it = new Intent(this, (Class<?>) SendSmsService.class);
        it.putExtra(PushReceiver.PHONE_NUMBER, safeNumber);
        it.putExtra(DatabaseTables.LOG_MESSAGE, getString(C0415R.string.simSerialNumber_changed) + PwdUtil.getPasswordWithJieMi(getApplicationContext()) + getString(C0415R.string.command_content));
        startService(it);
    }

    @Override // android.app.Service
    public void onDestroy() {
        Log.i("test", "sendMsgService onDestroy");
        super.onDestroy();
    }
}
