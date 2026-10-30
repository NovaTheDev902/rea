package com.lenovo.safecenter.platform;

import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.PowerManager;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.provider.MultiSIMUtils;
import android.telephony.SmsManager;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.widget.Toast;
import com.android.internal.statusbar.IStatusBarService;
import com.lenovo.safecenter.C0415R;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class DoubleCardUtils {
    public static final String DELIVERED_SMS_ACTION = "DELIVERED_SMS_ACTION";
    public static final String SENT_SMS_ACTION = "SENT_SMS_ACTION";
    public static boolean info;
    public static boolean isAlarm;
    public static boolean isAll;
    public static boolean isDestroy;
    public static boolean isLocate;
    public static boolean isLocked;
    public static double lat;
    public static double lon;

    /* JADX INFO: renamed from: d */
    private static ArrayList<PendingIntent> f4944d = null;

    /* JADX INFO: renamed from: e */
    private static ArrayList<PendingIntent> f4945e = null;

    /* JADX INFO: renamed from: f */
    private static BroadcastReceiver f4946f = null;

    /* JADX INFO: renamed from: g */
    private static int f4947g = 0;

    /* JADX INFO: renamed from: h */
    private static int f4948h = 0;

    /* JADX INFO: renamed from: i */
    private static int f4949i = 0;

    /* JADX INFO: renamed from: a */
    static boolean f4941a = false;

    /* JADX INFO: renamed from: b */
    static boolean f4942b = false;

    /* JADX INFO: renamed from: j */
    private static PowerManager.WakeLock f4950j = null;

    /* JADX INFO: renamed from: c */
    static final Object f4943c = new Object();

    /* JADX INFO: renamed from: e */
    static /* synthetic */ int m2046e() {
        int i = f4948h;
        f4948h = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: g */
    static /* synthetic */ int m2048g() {
        int i = f4949i;
        f4949i = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: i */
    static /* synthetic */ int m2050i() {
        int i = f4947g;
        f4947g = i + 1;
        return i;
    }

    public static void cleanNotifications() {
        IStatusBarService mBarService = IStatusBarService.Stub.asInterface(ServiceManager.getService("statusbar"));
        try {
            mBarService.onClearAllNotifications();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    public static void beginStartingService(Context context) {
        synchronized (f4943c) {
            if (f4950j == null) {
                PowerManager pm = (PowerManager) context.getSystemService("power");
                f4950j = pm.newWakeLock(268435482, "StartingAlertService");
                f4950j.setReferenceCounted(false);
            }
            f4950j.acquire();
        }
    }

    public static void finishStartingService() {
        synchronized (f4943c) {
            if (f4950j != null) {
                f4950j.release();
            }
        }
    }

    public static void sendSMS(final Context context, final String phoneNumber, String message) {
        Log.i("test", "in the sendSMS");
        if (MyMultiSIMUtils.isMultiSim(context)) {
            int[] states = MyMultiSIMUtils.getAllSimState(context);
            if (states[0] == 5 || states[0] == 2 || states[0] == 3) {
                f4941a = true;
            } else if (states[1] == 5 || states[1] == 2 || states[1] == 3) {
                f4942b = true;
            }
            Log.d("test", "sendSMS simState0: " + states[0] + " simState1: " + states[1]);
            final ArrayList<String> msgs = SmsManager.getDefault().divideMessage(message);
            f4944d = new ArrayList<>();
            f4945e = new ArrayList<>();
            Intent sentIntent = new Intent("SENT_SMS_ACTION");
            PendingIntent sentPI = PendingIntent.getBroadcast(context, 0, sentIntent, 0);
            Intent deliverIntent = new Intent("DELIVERED_SMS_ACTION");
            PendingIntent deliverPI = PendingIntent.getBroadcast(context, 0, deliverIntent, 0);
            f4944d.add(sentPI);
            f4945e.add(deliverPI);
            f4946f = new BroadcastReceiver() { // from class: com.lenovo.safecenter.platform.DoubleCardUtils.1
                @Override // android.content.BroadcastReceiver
                public final void onReceive(Context _context, Intent _intent) {
                    int code = getResultCode();
                    Log.d("test", "code: " + code);
                    switch (code) {
                        case -1:
                            Log.d("test", context.getString(C0415R.string.sendsms_success));
                            _context.unregisterReceiver(DoubleCardUtils.f4946f);
                            DoubleCardUtils.finishStartingService();
                            break;
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            if (DoubleCardUtils.f4941a && DoubleCardUtils.f4948h <= 3) {
                                try {
                                    Thread.sleep(30000L);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                DoubleCardUtils.beginStartingService(context);
                                try {
                                    Thread.sleep(5000L);
                                } catch (InterruptedException e2) {
                                    e2.printStackTrace();
                                }
                                Log.d("test", "card1 sendSMS");
                                MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, DoubleCardUtils.f4944d, DoubleCardUtils.f4945e, 0);
                                DoubleCardUtils.m2046e();
                                break;
                            } else if (DoubleCardUtils.f4942b && DoubleCardUtils.f4949i <= 3) {
                                try {
                                    Thread.sleep(30000L);
                                } catch (InterruptedException e3) {
                                    e3.printStackTrace();
                                }
                                DoubleCardUtils.beginStartingService(context);
                                try {
                                    Thread.sleep(5000L);
                                } catch (InterruptedException e4) {
                                    e4.printStackTrace();
                                }
                                Log.d("test", "card2 sendSMS");
                                MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, DoubleCardUtils.f4944d, DoubleCardUtils.f4945e, 1);
                                DoubleCardUtils.m2048g();
                                break;
                            }
                            break;
                    }
                }
            };
            context.registerReceiver(f4946f, new IntentFilter("SENT_SMS_ACTION"));
            if (f4941a) {
                beginStartingService(context);
                try {
                    Thread.sleep(5000L);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, f4944d, f4945e, 0);
                f4948h++;
                return;
            }
            if (f4942b) {
                beginStartingService(context);
                try {
                    Thread.sleep(5000L);
                } catch (InterruptedException e2) {
                    e2.printStackTrace();
                }
                MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, f4944d, f4945e, 1);
                f4949i++;
                return;
            }
            return;
        }
        TelephonyManager mTelephonyMgr = (TelephonyManager) context.getSystemService("phone");
        int state = mTelephonyMgr.getSimState();
        final SmsManager sms = SmsManager.getDefault();
        final ArrayList<String> msgs2 = sms.divideMessage(message);
        f4944d = new ArrayList<>();
        f4945e = new ArrayList<>();
        Intent sentIntent2 = new Intent("SENT_SMS_ACTION");
        PendingIntent sentPI2 = PendingIntent.getBroadcast(context, 0, sentIntent2, 0);
        Intent deliverIntent2 = new Intent("DELIVERED_SMS_ACTION");
        PendingIntent deliverPI2 = PendingIntent.getBroadcast(context, 0, deliverIntent2, 0);
        f4944d.add(sentPI2);
        f4945e.add(deliverPI2);
        f4946f = new BroadcastReceiver() { // from class: com.lenovo.safecenter.platform.DoubleCardUtils.2
            @Override // android.content.BroadcastReceiver
            public final void onReceive(Context _context, Intent _intent) {
                int code = getResultCode();
                Log.d("test", "code: " + code);
                switch (code) {
                    case -1:
                        Log.d("test", context.getString(C0415R.string.sendsms_success));
                        _context.unregisterReceiver(DoubleCardUtils.f4946f);
                        DoubleCardUtils.finishStartingService();
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        if (DoubleCardUtils.f4947g <= 3) {
                            try {
                                Thread.sleep(60000L);
                            } catch (InterruptedException e3) {
                                e3.printStackTrace();
                            }
                            DoubleCardUtils.beginStartingService(context);
                            try {
                                Thread.sleep(5000L);
                            } catch (InterruptedException e4) {
                                e4.printStackTrace();
                            }
                            sms.sendMultipartTextMessage(phoneNumber, null, msgs2, DoubleCardUtils.f4944d, DoubleCardUtils.f4945e);
                            DoubleCardUtils.m2050i();
                        }
                        break;
                }
            }
        };
        context.registerReceiver(f4946f, new IntentFilter("SENT_SMS_ACTION"));
        if (state == 5) {
            beginStartingService(context);
            try {
                Thread.sleep(5000L);
            } catch (InterruptedException e3) {
                e3.printStackTrace();
            }
            sms.sendMultipartTextMessage(phoneNumber, null, msgs2, f4944d, f4945e);
            f4947g++;
        }
    }

    public static void sendMessage(Context context, String phoneNumber, String message, boolean isInfo) {
        info = isInfo;
        Log.i("test", "in the sendmessage info:" + isInfo);
        if (MyMultiSIMUtils.isMultiSim(context)) {
            SmsManager sms = SmsManager.getDefault();
            PendingIntent sentPI = PendingIntent.getBroadcast(context, 0, new Intent("SENT_SMS_ACTION"), 0);
            PendingIntent deliverPI = PendingIntent.getBroadcast(context, 0, new Intent("DELIVERED_SMS_ACTION"), 0);
            ArrayList<String> msgs = sms.divideMessage(message);
            ArrayList<PendingIntent> sentIntents = new ArrayList<>();
            sentIntents.add(sentPI);
            ArrayList<PendingIntent> deliveryIntents = new ArrayList<>();
            deliveryIntents.add(deliverPI);
            int[] states = MyMultiSIMUtils.getAllSimState(context);
            if (states[0] == 5 || states[0] == 2 || states[0] == 3) {
                MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, sentIntents, deliveryIntents, 0);
                return;
            } else if (states[1] == 5 || states[1] == 2 || states[1] == 3) {
                MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, sentIntents, deliveryIntents, 1);
                return;
            } else {
                Toast.makeText(context, context.getString(C0415R.string.net_notavilable), 0).show();
                return;
            }
        }
        TelephonyManager mTelephonyMgr = (TelephonyManager) context.getSystemService("phone");
        int state = mTelephonyMgr.getSimState();
        SmsManager sms2 = SmsManager.getDefault();
        PendingIntent sentPI2 = PendingIntent.getBroadcast(context, 0, new Intent("SENT_SMS_ACTION"), 0);
        PendingIntent deliverPI2 = PendingIntent.getBroadcast(context, 0, new Intent("DELIVERED_SMS_ACTION"), 0);
        ArrayList<String> msgs2 = sms2.divideMessage(message);
        ArrayList<PendingIntent> sentIntents2 = new ArrayList<>();
        sentIntents2.add(sentPI2);
        ArrayList<PendingIntent> deliveryIntents2 = new ArrayList<>();
        deliveryIntents2.add(deliverPI2);
        if (state == 5) {
            sms2.sendMultipartTextMessage(phoneNumber, null, msgs2, sentIntents2, deliveryIntents2);
        } else {
            Toast.makeText(context, context.getString(C0415R.string.net_notavilable), 0).show();
        }
    }

    public static void privateSendMessage(Context context, String phoneNumber, String message, boolean isInfo, int simCardNum) {
        info = isInfo;
        Log.i("test", "in the sendmessage info:" + isInfo);
        if (MyMultiSIMUtils.isMultiSim(context)) {
            SmsManager sms = SmsManager.getDefault();
            PendingIntent sentPI = PendingIntent.getBroadcast(context, 0, new Intent("SENT_SMS_ACTION"), 0);
            PendingIntent deliverPI = PendingIntent.getBroadcast(context, 0, new Intent("DELIVERED_SMS_ACTION"), 0);
            ArrayList<String> msgs = sms.divideMessage(message);
            ArrayList<PendingIntent> sentIntents = new ArrayList<>();
            sentIntents.add(sentPI);
            ArrayList<PendingIntent> deliveryIntents = new ArrayList<>();
            deliveryIntents.add(deliverPI);
            int[] states = MyMultiSIMUtils.getAllSimState(context);
            if (simCardNum == 0) {
                if (states[0] == 5 || states[0] == 2 || states[0] == 3) {
                    MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, sentIntents, deliveryIntents, 0);
                    return;
                } else {
                    Toast.makeText(context, context.getString(C0415R.string.net_notavilable), 0).show();
                    return;
                }
            }
            if (simCardNum == 1) {
                if (states[1] == 5 || states[1] == 2 || states[1] == 3) {
                    MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, sentIntents, deliveryIntents, 1);
                    return;
                } else {
                    Toast.makeText(context, context.getString(C0415R.string.net_notavilable), 0).show();
                    return;
                }
            }
            return;
        }
        TelephonyManager mTelephonyMgr = (TelephonyManager) context.getSystemService("phone");
        int state = mTelephonyMgr.getSimState();
        SmsManager sms2 = SmsManager.getDefault();
        PendingIntent sentPI2 = PendingIntent.getBroadcast(context, 0, new Intent("SENT_SMS_ACTION"), 0);
        PendingIntent deliverPI2 = PendingIntent.getBroadcast(context, 0, new Intent("DELIVERED_SMS_ACTION"), 0);
        ArrayList<String> msgs2 = sms2.divideMessage(message);
        ArrayList<PendingIntent> sentIntents2 = new ArrayList<>();
        sentIntents2.add(sentPI2);
        ArrayList<PendingIntent> deliveryIntents2 = new ArrayList<>();
        deliveryIntents2.add(deliverPI2);
        if (state == 5) {
            sms2.sendMultipartTextMessage(phoneNumber, null, msgs2, sentIntents2, deliveryIntents2);
        } else {
            Toast.makeText(context, context.getString(C0415R.string.net_notavilable), 0).show();
        }
    }

    public static void sendInfoMessage(Context context, String phoneNumber, String message, boolean isInfo) {
        info = isInfo;
        SmsManager sms = SmsManager.getDefault();
        PendingIntent sentPI = PendingIntent.getBroadcast(context, 0, new Intent("SENT_SMS_ACTION"), 0);
        PendingIntent deliverPI = PendingIntent.getBroadcast(context, 0, new Intent("DELIVERED_SMS_ACTION"), 0);
        ArrayList<String> msgs = sms.divideMessage(message);
        ArrayList<PendingIntent> sentIntents = new ArrayList<>();
        sentIntents.add(sentPI);
        ArrayList<PendingIntent> deliveryIntents = new ArrayList<>();
        deliveryIntents.add(deliverPI);
        if (MyMultiSIMUtils.isMultiSim(context)) {
            int[] states = MyMultiSIMUtils.getAllSimState(context);
            if (states[0] == 5 || states[0] == 2 || states[0] == 3) {
                MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, sentIntents, deliveryIntents, 0);
                return;
            } else {
                if (states[1] == 5 || states[1] == 2 || states[1] == 3) {
                    MultiSIMUtils.getDefault(context).sendMultipartTextMessage(phoneNumber, (String) null, msgs, sentIntents, deliveryIntents, 1);
                    return;
                }
                return;
            }
        }
        sms.sendMultipartTextMessage(phoneNumber, null, msgs, sentIntents, deliveryIntents);
    }
}
