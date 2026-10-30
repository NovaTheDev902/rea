package com.lenovo.safecenter.utils;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.ComponentName;
import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.location.LocationManager;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.os.Environment;
import android.os.StatFs;
import android.provider.ContactsContract;
import android.provider.MultiSIMUtils;
import android.provider.Settings;
import android.telephony.TelephonyManager;
import android.text.SpannableString;
import android.text.format.Formatter;
import android.text.style.AbsoluteSizeSpan;
import android.text.style.ForegroundColorSpan;
import android.util.Log;
import android.widget.RemoteViews;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.AppsManager.DialogActivity;
import com.lenovo.safecenter.AppsManager.DisplayLog;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.SplashActivity;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.net.TrafficStatistics;
import com.lenovo.safecenter.net.cache.NetCache;
import com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.systeminfo.p011ui.activity.DailyTools;
import java.io.File;
import java.net.URLEncoder;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Map;
import org.apache.commons.httpclient.cookie.Cookie2;
import org.apache.commons.httpclient.params.HttpConnectionParams;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.EntityUtils;

/* JADX INFO: loaded from: classes.dex */
public class MyUtils {
    public static final int INFO_NOTI_ID = 257;
    public static final int LONG_NOTI_ID = 256;
    public static final int NOTIFICATION_CHILD_MODE = 1;
    public static final int NOTIFICATION_GUEST_MODE = 17;
    public static final int NOTIFI_HARASS_CALL = 3;
    public static final int NOTIFI_HARASS_SMS = 4;
    public static final int NOTIFI_LESEC = 0;
    public static final int NOTIFI_PRIVACY = 2;
    public static final int NOTIFI_TARIFF = 1;
    public static final int NOTIFI_TRAFFIC_CORRECT = 5;
    public static final int SMS_OUT_NOTI_ID = 4096;
    public static final int TRAFFIC_OUT_NOTI_ID = 273;
    public static final int UNREAD_SMS_ID = 273;
    public static final int VIRUS_NOTI_ID = 272;

    /* JADX INFO: renamed from: a */
    private static LocationManager f5752a;
    public static boolean info;
    public static boolean isRead = true;
    public static boolean isLocked = false;

    public static void deleteUnsendSMS(Context context, String message) {
        try {
            ContentResolver contentResolver = context.getContentResolver();
            Uri uri = Uri.parse("content://sms");
            Cursor cursor = contentResolver.query(uri, new String[]{"_id", "thread_id"}, "body like ? and (type!=0 and type!=1 and type!=2)", new String[]{"%" + message + "%"}, null);
            while (cursor.moveToNext()) {
                String _id = cursor.getString(0);
                String thread_id = cursor.getString(1);
                contentResolver.delete(Uri.parse("content://sms/conversations/" + thread_id), "_id= " + _id, null);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static String sendGETRequest(String path, Map<String, String> params, String encoding) {
        try {
            StringBuilder sb = new StringBuilder();
            sb.append(path);
            if (params != null && !params.isEmpty()) {
                sb.append('?');
                for (Map.Entry<String, String> entry : params.entrySet()) {
                    sb.append(entry.getKey()).append('=').append(URLEncoder.encode(entry.getValue(), encoding)).append('&');
                }
                sb.deleteCharAt(sb.length() - 1);
            }
            Log.i(Cookie2.PATH, sb.toString());
            HttpGet httpGet = new HttpGet(sb.toString());
            DefaultHttpClient httpClient = new DefaultHttpClient();
            httpClient.getParams().setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 6000);
            httpClient.getParams().setParameter("http.socket.timeout", 6000);
            HttpResponse response = httpClient.execute(httpGet);
            HttpEntity httpEntity = response.getEntity();
            Log.i("StatusCode", response.getStatusLine().getStatusCode() + ">>>>>>>>>>");
            if (response.getStatusLine().getStatusCode() == 200) {
                String msg = EntityUtils.toString(httpEntity);
                Log.i("ydp", "dw ok msg:" + msg);
                return msg;
            }
            Log.i("ydp", "-1 :" + response.getStatusLine().getStatusCode() + "  " + EntityUtils.toString(httpEntity));
            return "SC_ERROR";
        } catch (Exception e) {
            e.printStackTrace();
            Log.i("ydp", "catch -1");
            return "ERROR";
        }
    }

    public static void lockedScreen(Context context, String phoneNumber) {
        Log.i("test", "locked screen--->");
        Intent i = new Intent("com.lenovo.safecenter.lockscreenservice");
        i.putExtra("phonenumber", phoneNumber);
        context.startService(i);
    }

    public static String getSimSerialNumber(int id, boolean state, Context context) {
        if (!state) {
            return null;
        }
        String number = MultiSIMUtils.getDefault(context).getSubscriberId(id);
        while (true) {
            if (number == null || "".equals(number)) {
                number = MultiSIMUtils.getDefault(context).getSubscriberId(id);
                if (MultiSIMUtils.getDefault(context).getSimState(id) == 1) {
                    return null;
                }
                Log.e("test", "......get sim " + id + ": " + number);
            } else {
                return number;
            }
        }
    }

    public static void sendMsgToSafeNumber(Context context, String phoneNumber, String msg) {
        Intent it = new Intent("com.lenovo.antitheft.SENDMESSAGE");
        it.putExtra(PushReceiver.PHONE_NUMBER, phoneNumber);
        it.putExtra(DatabaseTables.LOG_MESSAGE, msg);
        it.putExtra("type", -1);
        context.startService(it);
    }

    public static void alarming(Context context) {
        Log.e("test", "==============>checking alarm");
        context.startService(new Intent("com.lenovo.antitheft.ALARM"));
    }

    public static int backupToMail(Context context, String phoneNumber, String safeMailAddress) {
        Log.i("test", "in the backup");
        int type = 0;
        if (safeMailAddress.equals("")) {
            if (!"".equals(phoneNumber)) {
                sendMsgToSafeNumber(context, phoneNumber, context.getString(C0415R.string.backup_no_mail) + context.getString(C0415R.string.from_lesecurity));
                return 0;
            }
            return 2;
        }
        if (getNetWorksState(context)) {
            new BackUpSms(context).backup();
            new BackUpContact(context).backup();
            SendEmail se = new SendEmail(context, safeMailAddress);
            if (se.send()) {
                if (!"".equals(phoneNumber)) {
                    sendMsgToSafeNumber(context, phoneNumber, context.getString(C0415R.string.backup_to_phone_ok) + safeMailAddress + context.getString(C0415R.string.backup_to_phone_ok_) + context.getString(C0415R.string.from_lesecurity));
                } else {
                    type = 1;
                }
            } else if (!"".equals(phoneNumber)) {
                sendMsgToSafeNumber(context, phoneNumber, context.getString(C0415R.string.backup_to_phone_no) + context.getString(C0415R.string.from_lesecurity));
            } else {
                type = 2;
            }
            String[] filesName = {"Contacts.vcf", "smsbackup.txt"};
            for (String str : filesName) {
                File f = new File(context.getFilesDir().getPath(), str);
                f.delete();
            }
            return type;
        }
        if (!"".equals(phoneNumber)) {
            sendMsgToSafeNumber(context, phoneNumber, context.getString(C0415R.string.backup_to_phone_no) + context.getString(C0415R.string.from_lesecurity));
            return 0;
        }
        return 2;
    }

    public static boolean getNetWorksState(Context context) {
        boolean success = false;
        ConnectivityManager connManager = (ConnectivityManager) context.getSystemService("connectivity");
        NetworkInfo.State stateWIFI = connManager.getNetworkInfo(1).getState();
        NetworkInfo.State stateMOBILE = connManager.getNetworkInfo(0).getState();
        Log.i("info", "getNetWorksState state-wifi: " + stateWIFI + "state-mobile:" + stateMOBILE);
        if (NetworkInfo.State.CONNECTED == stateWIFI) {
            success = true;
        }
        if (NetworkInfo.State.CONNECTED == stateMOBILE) {
            success = true;
        }
        Log.i("test", "in the getNetWorks State is:" + success);
        return success;
    }

    public static void deleteContactsItemInPhone(ContentResolver contentResolver) {
        Cursor cursor = contentResolver.query(ContactsContract.Contacts.CONTENT_URI, null, null, null, null);
        if (cursor.moveToFirst()) {
            do {
                int contact_id = cursor.getInt(cursor.getColumnIndex("_id"));
                contentResolver.delete(ContactsContract.Data.CONTENT_URI, "raw_contact_id=" + contact_id, null);
                contentResolver.delete(ContactsContract.RawContacts.CONTENT_URI, "contact_id=" + contact_id, null);
            } while (cursor.moveToNext());
        }
        cursor.close();
    }

    public static void deleteWhiteAndBlackContacts(ContentResolver contentResolver) {
        try {
            Uri uri = Uri.parse("content://com.lenovo.safecenter.WhitePersonProvider/whiteperson");
            contentResolver.delete(uri, null, null);
            Uri uri2 = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            contentResolver.delete(uri2, null, null);
            Uri uri3 = Uri.parse("content://com.lenovo.safecenter.netBlackProvider/netblack");
            contentResolver.delete(uri3, null, null);
            Log.d("test", "delete white and black contacts end");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void clearSMS(ContentResolver contentResolver) {
        Uri uri = Uri.parse("content://sms");
        Cursor cursor = contentResolver.query(uri, null, null, null, null);
        int numcount = cursor.getCount();
        for (int i = 0; i < numcount; i++) {
            cursor.moveToPosition(i);
            String _id = cursor.getString(cursor.getColumnIndexOrThrow("_id"));
            try {
                contentResolver.delete(Uri.parse("content://sms"), "_id = " + _id, null);
            } catch (Exception e) {
            }
        }
        cursor.close();
        Log.d("test", "clear sms end");
    }

    public static void clearMMS(ContentResolver contentResolver) {
        try {
            Uri uri = Uri.parse("content://mms");
            Cursor cursor = contentResolver.query(uri, null, null, null, null);
            if (cursor != null) {
                while (cursor.moveToNext()) {
                    int id = cursor.getInt(cursor.getColumnIndex("_id"));
                    contentResolver.delete(uri, "_id=" + id, null);
                    contentResolver.delete(Uri.parse("content://mms/part"), "mid=" + id, null);
                }
                cursor.close();
            }
            Log.d("test", "clear mms end");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void clearCalendar(ContentResolver contentResolver) {
        try {
            Uri uri = Uri.parse("content://com.android.calendar/events");
            Cursor cursor = contentResolver.query(uri, null, null, null, null);
            if (cursor.moveToFirst()) {
                do {
                    int id = cursor.getInt(cursor.getColumnIndex("_id"));
                    contentResolver.delete(uri, "_id=" + id, null);
                } while (cursor.moveToNext());
            }
            cursor.close();
            Log.d("test", "clearCalendar end");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void deleteCallLog(ContentResolver contentResolver) {
        try {
            Uri uri = Uri.parse("content://call_log/calls");
            contentResolver.delete(uri, null, null);
            Log.d("test", "delete callLog end");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void deleteBrowserRecord(Context context) {
    }

    public static void deleteMail(Context context) {
        Intent it = new Intent("com.android.mails.intent.action.deleteall");
        context.sendBroadcast(it);
        try {
            CMDHelper.deleMail(context);
        } catch (Exception e) {
            Log.e("test", "delete Mail error:" + e);
        }
        Log.d("test", "delete Mail end");
    }

    public static void deletePushAccount(ContentResolver contentResolver) {
        try {
            Uri uri = Uri.parse("content://com.android.provider.pushsetting/userdata");
            ContentValues values = new ContentValues();
            values.put("confvalue", "");
            contentResolver.update(uri, values, "confname=? or confname=?", new String[]{"UserName", "Password"});
            Log.d("test", "delete pushAccount end");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void deleteSimContacts(Context context) {
        ContentResolver contentResolver = context.getContentResolver();
        Uri.parse("content://icc/adn");
        Uri uri = null;
        Cursor cursor = null;
        TelephonyManager tm = (TelephonyManager) context.getSystemService("phone");
        String operator = tm.getSimOperator();
        if (operator != null) {
            if (operator.equals("46000") || operator.equals("46002")) {
                uri = Uri.parse("content://icc/adn");
                cursor = contentResolver.query(uri, null, null, null, null);
            } else if (operator.equals("46001")) {
                uri = Uri.parse("content://icc/pbr");
                try {
                    cursor = contentResolver.query(uri, null, null, null, null);
                } catch (Exception e) {
                    uri = Uri.parse("content://icc/adn");
                    cursor = contentResolver.query(uri, null, null, null, null);
                }
            } else if (operator.equals("46003")) {
                return;
            }
            if (cursor != null) {
                cursor.moveToPosition(-1);
                while (cursor.moveToNext()) {
                    String name = cursor.getString(cursor.getColumnIndex("name"));
                    String phoneNumber = cursor.getString(cursor.getColumnIndex(AppDatabase.NUMBER));
                    String where = "tag='" + name + "'";
                    int i = contentResolver.delete(uri, where + " AND number='" + phoneNumber + "'", null);
                    if (i == 0) {
                        Log.d("test", "delete simContacts error");
                    }
                }
                cursor.close();
            }
            Log.d("test", "delete simContacts end");
        }
    }

    public static void openGPSSettings(Context context) {
        f5752a = (LocationManager) context.getSystemService("location");
        if (f5752a.isProviderEnabled("gps")) {
            Toast.makeText(context, "GPS模块正常", 0).show();
            return;
        }
        Settings.Secure.setLocationProviderEnabled(context.getContentResolver(), "gps", true);
        if (f5752a.isProviderEnabled("gps")) {
            Toast.makeText(context, "GPS开启", 0).show();
        }
    }

    public static void sendBackMessage(Context context, String phoneNumber, String msg) {
        Intent it = new Intent("com.lenovo.antitheft.SENDMESSAGE");
        it.putExtra(PushReceiver.PHONE_NUMBER, phoneNumber);
        it.putExtra("type", -1);
        it.putExtra(DatabaseTables.LOG_MESSAGE, msg);
        context.startService(it);
    }

    public static Notification getNotification(Context context, String notiInfo, boolean LesecVisible, Intent netFilter, int notiIcon, String tickerText) {
        Notification notification = null;
        try {
            Notification notification2 = new Notification();
            try {
                RemoteViews mContentView = m2392a(context);
                if (LesecVisible) {
                    mContentView.setViewVisibility(C0415R.id.txt_lesec, 0);
                    mContentView.setTextColor(C0415R.id.txt_lesec_des, context.getResources().getColor(C0415R.color.black2));
                    if (Const.getScreenHeight() < 800) {
                        mContentView.setTextViewText(C0415R.id.txt_lesec_des, context.getResources().getString(C0415R.string.defend));
                    } else {
                        mContentView.setTextViewText(C0415R.id.txt_lesec_des, notiInfo);
                    }
                } else {
                    mContentView.setViewVisibility(C0415R.id.txt_lesec, 8);
                    mContentView.setTextColor(C0415R.id.txt_lesec_des, context.getResources().getColor(C0415R.color.blue_btn));
                    mContentView.setTextViewText(C0415R.id.txt_lesec_des, notiInfo);
                }
                PendingIntent appIntent = PendingIntent.getActivity(context, 0, netFilter, 0);
                notification2.icon = notiIcon;
                notification2.flags = 10;
                notification2.tickerText = tickerText;
                notification2.contentView = mContentView;
                notification2.contentIntent = appIntent;
                return notification2;
            } catch (Exception e) {
                e = e;
                notification = notification2;
                e.printStackTrace();
                return notification;
            }
        } catch (Exception e2) {
            e = e2;
        }
    }

    public static Notification getForegroundNotification(Context context) {
        if (context == null) {
            throw new IllegalArgumentException();
        }
        Notification notification = new Notification();
        Intent i = new Intent(context, (Class<?>) SplashActivity.class);
        i.setAction("android.intent.action.MAIN");
        i.addCategory("android.intent.category.LAUNCHER");
        i.setFlags(268435456);
        notification.contentIntent = PendingIntent.getActivity(context.getApplicationContext(), 0, i, 268435456);
        notification.flags = 18;
        return notification;
    }

    public static synchronized void showNotification(Context context, int notiId, int notiType) {
        String notiInfo;
        NotificationManager manager = (NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION);
        Intent mIntent = new Intent();
        switch (notiId) {
            case 1:
                RemoteViews childView = new RemoteViews(context.getPackageName(), C0415R.layout.guestmode_notify);
                childView.setTextViewText(C0415R.id.guestmode_title, context.getString(C0415R.string.child_mode));
                childView.setTextViewText(C0415R.id.guestmode_summary, context.getString(C0415R.string.child_mode) + context.getString(C0415R.string.opend));
                mIntent.setClass(context, DialogActivity.class);
                mIntent.setFlags(536870912);
                PendingIntent intent = PendingIntent.getActivity(context, 0, mIntent, 0);
                Notification mNotification = new Notification();
                mNotification.flags = 10;
                mNotification.tickerText = context.getText(C0415R.string.switch_to_child_mode);
                mNotification.icon = C0415R.drawable.child_noti;
                mNotification.contentView = childView;
                mNotification.contentIntent = intent;
                manager.notify(1, mNotification);
                break;
            case 17:
                RemoteViews guestView = new RemoteViews(context.getPackageName(), C0415R.layout.guestmode_notify);
                guestView.setTextViewText(C0415R.id.guestmode_title, context.getString(C0415R.string.guest_mode));
                guestView.setTextViewText(C0415R.id.guestmode_summary, context.getString(C0415R.string.guest_mode) + context.getString(C0415R.string.opend));
                mIntent.setClass(context, DailyTools.class);
                mIntent.setFlags(536870912);
                PendingIntent intent2 = PendingIntent.getActivity(context, 0, mIntent, 0);
                Notification mNotification2 = new Notification();
                mNotification2.flags = 10;
                mNotification2.tickerText = context.getString(C0415R.string.switch_to_guest_mode);
                mNotification2.icon = C0415R.drawable.guest_noti;
                mNotification2.contentView = guestView;
                mNotification2.contentIntent = intent2;
                manager.notify(17, mNotification2);
                break;
            case 256:
                switch (notiType) {
                    case 0:
                        mIntent.setClass(context, SplashActivity.class);
                        mIntent.setAction("android.intent.action.MAIN");
                        mIntent.addCategory("android.intent.category.LAUNCHER");
                        Notification mNotification3 = getNotification(context, context.getString(C0415R.string.protecting), true, mIntent, C0415R.drawable.atat_safe_icon, null);
                        if (mNotification3 != null) {
                            manager.notify(256, mNotification3);
                        }
                        break;
                    case 1:
                        mIntent.setClass(context, DisplayLog.class);
                        mIntent.putExtra("key", "key");
                        String notiInfo2 = SafeCenterService.getChargeLogs(context);
                        Notification mNotification4 = getNotification(context, notiInfo2, false, mIntent, C0415R.drawable.notify_new_tariff, null);
                        if (mNotification4 != null) {
                            manager.notify(256, mNotification4);
                        }
                        break;
                    case 2:
                        mIntent.setClass(context, DisplayLog.class);
                        mIntent.putExtra("key", "key");
                        String notiInfo3 = SafeCenterService.getPrivacyLogs(context);
                        Notification mNotification5 = getNotification(context, notiInfo3, false, mIntent, C0415R.drawable.notify_new_privacy, null);
                        if (mNotification5 != null) {
                            manager.notify(256, mNotification5);
                        }
                        break;
                    case 3:
                        mIntent.setClass(context, AntiSpamMain.class);
                        mIntent.putExtra("key", "key");
                        mIntent.putExtra("type", 1);
                        String notiInfo4 = SafeCenterService.getHarassLogs(context);
                        Notification mNotification6 = getNotification(context, notiInfo4, false, mIntent, C0415R.drawable.notify_new_call, null);
                        if (mNotification6 != null) {
                            manager.notify(256, mNotification6);
                        }
                        break;
                    case 4:
                        mIntent.setClass(context, AntiSpamMain.class);
                        mIntent.putExtra("key", "key");
                        mIntent.putExtra("type", 0);
                        String notiInfo5 = SafeCenterService.getHarassLogs(context);
                        Notification mNotification7 = getNotification(context, notiInfo5, false, mIntent, C0415R.drawable.notify_new_sms, null);
                        if (mNotification7 != null) {
                            manager.notify(256, mNotification7);
                        }
                        break;
                    case 5:
                        if (MyMultiSIMUtils.isMultiSim(context) && TrafficStatsService.getTrafficMode(context) == 12) {
                            mIntent.putExtra("key", "key");
                            mIntent.setClass(context, TrafficStatisticsDoubleMode.class);
                        } else {
                            mIntent.setClass(context, TrafficStatistics.class);
                            mIntent.putExtra("key", "key");
                        }
                        String format = context.getString(C0415R.string.net_traffic_correct_sucess);
                        if (TrafficStatsService.getTrafficMode(context) == 12) {
                            if (NetCache.lastCorrectCard == 0) {
                                notiInfo = String.format(format, context.getString(C0415R.string.net_card1));
                            } else {
                                notiInfo = String.format(format, context.getString(C0415R.string.net_card2));
                            }
                        } else {
                            notiInfo = String.format(format, "");
                        }
                        Notification mNotification8 = getNotification(context, notiInfo, false, mIntent, C0415R.drawable.atat_safe_icon, notiInfo);
                        if (mNotification8 != null) {
                            manager.notify(256, mNotification8);
                        }
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }

    public static void showUnreadSmsNotification(Context context) {
        ContentResolver contentResolver = context.getContentResolver();
        Uri uri = Uri.parse("content://sms");
        Cursor cursor = contentResolver.query(uri, new String[]{"_id"}, "read=? and thread_id>0", new String[]{"0"}, null);
        int num = cursor.getCount();
        if (num > 0) {
            NotificationManager manager = (NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION);
            Notification mNotification = new Notification();
            Intent mIntent = new Intent();
            try {
                context.getPackageManager().getApplicationIcon("com.lenovo.ideafriend");
                mIntent.setComponent(new ComponentName("com.lenovo.ideafriend", "com.lenovo.ideafriend.alias.MmsActivity"));
            } catch (Exception e) {
                mIntent.setComponent(new ComponentName("com.android.mms", "com.android.mms.ui.ConversationList"));
            }
            PendingIntent intent = PendingIntent.getActivity(context, 0, mIntent, 0);
            mNotification.flags = 16;
            mNotification.tickerText = context.getString(C0415R.string.newsms);
            mNotification.icon = C0415R.drawable.sms;
            mNotification.when = System.currentTimeMillis();
            mNotification.contentIntent = intent;
            mNotification.setLatestEventInfo(context, String.format(context.getString(C0415R.string.unread_sms), Integer.valueOf(num)), context.getString(C0415R.string.look_unread_sms), intent);
            manager.notify(273, mNotification);
        }
    }

    public static synchronized void showLeSecNotification(Context context) {
        Notification notification = null;
        Intent netFilter = new Intent();
        if (SafeCenterService.privacy_count == 0 && SafeCenterService.charge_count == 0 && SafeCenterService.harass_call_count == 0 && SafeCenterService.harass_msg_count == 0) {
            netFilter.setClass(context, SplashActivity.class);
            netFilter.setAction("android.intent.action.MAIN");
            netFilter.addCategory("android.intent.category.LAUNCHER");
            notification = getNotification(context, context.getString(C0415R.string.protecting), true, netFilter, C0415R.drawable.atat_safe_icon, null);
        } else {
            long[] times = {-1, -1, -1, -1};
            long tariffTime = 0;
            long privacyTime = 0;
            long smsTime = 0;
            long callTime = 0;
            if (SafeCenterService.charge_count > 0 && Const.lastSafeLogs.get("tariff") != null) {
                tariffTime = Long.parseLong(Const.lastSafeLogs.get("tariff").time);
                times[0] = tariffTime;
            }
            if (SafeCenterService.privacy_count > 0 && Const.lastSafeLogs.get(AppDatabase.PERM_TYPE_PRIVCY) != null) {
                privacyTime = Long.parseLong(Const.lastSafeLogs.get(AppDatabase.PERM_TYPE_PRIVCY).time);
                times[1] = privacyTime;
            }
            if (SafeCenterService.harass_call_count > 0 && Const.lastSafeLogs.get(AppDatabase.HARASS_CALL) != null) {
                callTime = Long.parseLong(Const.lastSafeLogs.get(AppDatabase.HARASS_CALL).time);
                times[2] = callTime;
            }
            if (SafeCenterService.harass_msg_count > 0 && Const.lastSafeLogs.get(AppDatabase.HARASS_SMS) != null) {
                smsTime = Long.parseLong(Const.lastSafeLogs.get(AppDatabase.HARASS_SMS).time);
                times[3] = smsTime;
            }
            Arrays.sort(times);
            if (tariffTime == times[3]) {
                netFilter.setClass(context, DisplayLog.class);
                netFilter.putExtra("key", "key");
                String notiInfo = SafeCenterService.getChargeLogs(context);
                notification = getNotification(context, notiInfo, false, netFilter, C0415R.drawable.notify_new_tariff, null);
                LeSafeObservable.get(context).noticeRefreshChargeLogs();
            } else if (callTime == times[3]) {
                netFilter.setClass(context, AntiSpamMain.class);
                netFilter.putExtra("key", "key");
                netFilter.putExtra("type", 1);
                String notiInfo2 = SafeCenterService.getHarassLogs(context);
                notification = getNotification(context, notiInfo2, false, netFilter, C0415R.drawable.notify_new_call, null);
                LeSafeObservable.get(context).noticeRefreshHarassLogs();
            } else if (smsTime == times[3]) {
                netFilter.setClass(context, AntiSpamMain.class);
                netFilter.putExtra("key", "key");
                netFilter.putExtra("type", 0);
                String notiInfo3 = SafeCenterService.getHarassLogs(context);
                notification = getNotification(context, notiInfo3, false, netFilter, C0415R.drawable.notify_new_sms, null);
                LeSafeObservable.get(context).noticeRefreshHarassLogs();
            } else if (privacyTime == times[3]) {
                netFilter.setClass(context, DisplayLog.class);
                netFilter.putExtra("key", "key");
                String notiInfo4 = SafeCenterService.getPrivacyLogs(context);
                notification = getNotification(context, notiInfo4, false, netFilter, C0415R.drawable.notify_new_privacy, null);
                LeSafeObservable.get(context).noticeRefreshPrivacyLogs();
            }
        }
        NotificationManager manager = (NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION);
        if (notification != null) {
            manager.notify(256, notification);
        }
    }

    /* JADX INFO: renamed from: a */
    private static RemoteViews m2392a(Context context) {
        RemoteViews mContentView;
        RemoteViews mContentView2 = null;
        int progress = 0;
        long todayUsed = 0;
        long monthFree = 0;
        String monthLImit = null;
        try {
            int dataPostion = TrafficStatsService.getDataCardPosition(context);
            if (dataPostion == 0) {
                todayUsed = Const.getTodayUsedTraffic();
                monthFree = Const.getMonthFreeTraffic();
                progress = Const.getProgressTrafficMonthUsed();
                monthLImit = Const.getMonthLimitTraffic();
            } else if (dataPostion == 1) {
                todayUsed = Const.getTodayUsedTraffic2();
                monthFree = Const.getMonthFreeTraffic2();
                progress = Const.getProgressTrafficMonthUsed2();
                monthLImit = Const.getMonthLimitTraffic2();
            }
            String strTodayUsed = Formatter.formatShortFileSize(context, todayUsed);
            try {
                if ("-1".equals(monthLImit)) {
                    mContentView = new RemoteViews(context.getPackageName(), C0415R.layout.notify);
                    mContentView.setTextViewText(C0415R.id.notify_traffic_info, context.getString(C0415R.string.traffic_limit_set));
                    mContentView2 = mContentView;
                } else if (monthFree < 0) {
                    mContentView = new RemoteViews(context.getPackageName(), C0415R.layout.notify_red);
                    String strMonthFree = Formatter.formatShortFileSize(context, -monthFree);
                    String stoday = String.format(context.getString(C0415R.string.net_traffic), strTodayUsed) + " ,";
                    String decribe = stoday + context.getString(C0415R.string.exceed_text) + strMonthFree;
                    mContentView.setTextViewText(C0415R.id.notify_traffic_info, decribe);
                    mContentView2 = mContentView;
                } else if (progress >= 90) {
                    mContentView = new RemoteViews(context.getPackageName(), C0415R.layout.notify_orange);
                    String strMonthFree2 = Formatter.formatShortFileSize(context, monthFree);
                    mContentView.setTextViewText(C0415R.id.notify_traffic_info, String.format(context.getString(C0415R.string.net_traffic), strTodayUsed) + " ," + context.getString(C0415R.string.remaining_text) + strMonthFree2);
                    mContentView2 = mContentView;
                } else {
                    mContentView = new RemoteViews(context.getPackageName(), C0415R.layout.notify);
                    String strMonthFree3 = Formatter.formatShortFileSize(context, monthFree);
                    mContentView.setTextViewText(C0415R.id.notify_traffic_info, String.format(context.getString(C0415R.string.net_traffic), strTodayUsed) + " ," + context.getString(C0415R.string.remaining_text) + strMonthFree3);
                    mContentView2 = mContentView;
                }
                mContentView2.setProgressBar(C0415R.id.traffic_progress_bar, 100, progress, false);
                int color = context.getResources().getColor(C0415R.color.orange);
                if (SafeCenterService.charge_count > 0) {
                    mContentView2.setTextColor(C0415R.id.notify_tariff, color);
                } else {
                    mContentView2.setTextColor(C0415R.id.notify_tariff, context.getResources().getColor(C0415R.color.black5));
                }
                if (SafeCenterService.privacy_count > 0) {
                    mContentView2.setTextColor(C0415R.id.notify_privacy, color);
                } else {
                    mContentView2.setTextColor(C0415R.id.notify_privacy, context.getResources().getColor(C0415R.color.black5));
                }
                if (SafeCenterService.harass_msg_count > 0) {
                    mContentView2.setTextColor(C0415R.id.notify_message, color);
                } else {
                    mContentView2.setTextColor(C0415R.id.notify_message, context.getResources().getColor(C0415R.color.black5));
                }
                if (SafeCenterService.harass_call_count > 0) {
                    mContentView2.setTextColor(C0415R.id.notify_call, color);
                } else {
                    mContentView2.setTextColor(C0415R.id.notify_call, context.getResources().getColor(C0415R.color.black5));
                }
                mContentView2.setTextViewText(C0415R.id.notify_tariff, Integer.toString(SafeCenterService.charge_count));
                mContentView2.setTextViewText(C0415R.id.notify_privacy, Integer.toString(SafeCenterService.privacy_count));
                mContentView2.setTextViewText(C0415R.id.notify_message, Integer.toString(SafeCenterService.harass_msg_count));
                mContentView2.setTextViewText(C0415R.id.notify_call, Integer.toString(SafeCenterService.harass_call_count));
            } catch (Exception e) {
                e = e;
                mContentView2 = mContentView;
                e.printStackTrace();
            }
        } catch (Exception e2) {
            e = e2;
        }
        return mContentView2;
    }

    public static void cancelNotification(Context context, int notiId) {
        NotificationManager manager = (NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION);
        manager.cancel(notiId);
    }

    public static void showScanVirusNotification(Context context, String type, String pkgName, String appName) {
        NotificationManager manager = (NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION);
        Notification mNotification = new Notification();
        mNotification.flags = 16;
        mNotification.when = System.currentTimeMillis();
        if (type.equals("0")) {
            mNotification.tickerText = appName + context.getString(C0415R.string.install_safe);
            mNotification.icon = C0415R.drawable.safe_icon;
            PendingIntent intent = PendingIntent.getActivity(context, 0, new Intent(), 0);
            mNotification.setLatestEventInfo(context, context.getString(C0415R.string.test_report), appName + context.getString(C0415R.string.install_safe), intent);
        } else if (type.equals(DatabaseTables.SYSTEM_MARK)) {
            mNotification.tickerText = String.format(context.getString(C0415R.string.virus_scaning), appName);
            mNotification.icon = C0415R.drawable.safe_icon;
            Intent intentunsure = new Intent();
            intentunsure.setAction("com.lenovo.antivirus.notice");
            intentunsure.putExtra("packageName", pkgName);
            intentunsure.putExtra("virustype", type);
            intentunsure.putExtra("pname", appName);
            PendingIntent intent2 = PendingIntent.getActivity(context, 0, new Intent(), 0);
            mNotification.setLatestEventInfo(context, String.format(context.getString(C0415R.string.virus_scaning), appName), String.format(context.getString(C0415R.string.virus_scaning), appName), intent2);
        }
        manager.notify(VIRUS_NOTI_ID, mNotification);
    }

    public static String getPreMType(String type) {
        if (type.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
            return "0";
        }
        if (type.equals(AppDatabase.DB_APP_CALL)) {
            return DatabaseTables.SYSTEM_MARK;
        }
        if (type.equals(AppDatabase.DB_APP_CANTACT)) {
            return "3";
        }
        if (type.equals(AppDatabase.DB_APP_MESSAGE)) {
            return "4";
        }
        if (type.equals(AppDatabase.DB_APP_CALENDAR)) {
            return "5";
        }
        if (type.equals(AppDatabase.DB_APP_HISTORY)) {
            return "6";
        }
        if (type.equals("location")) {
            return "7";
        }
        if (type.equals(AppDatabase.DB_APP_RECORD)) {
            return "8";
        }
        if (type.equals(AppDatabase.DB_APP_CAMERA)) {
            return "9";
        }
        if (type.equals(AppDatabase.DB_APP_PHONE)) {
            return "10";
        }
        return null;
    }

    public static String formatTime(String time, Context context) {
        SimpleDateFormat sdf = new SimpleDateFormat("MM-dd HH:mm");
        String dateValue = sdf.format(Long.valueOf(Long.parseLong(time)));
        return dateValue;
    }

    public static String formatAllTime(String time, Context context) {
        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");
        String dateValue = sdf.format(Long.valueOf(Long.parseLong(time)));
        return dateValue;
    }

    public static String formatReportTime(String time, Context context) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String dateValue = sdf.format(Long.valueOf(Long.parseLong(time)));
        return dateValue;
    }

    public static String replaceString(String str) {
        return (str == null || str.trim().equals("")) ? "N/A" : str.replace("|", "\\|");
    }

    public static void setSpannableString(TextView tv, String source, int start, int end, int color) {
        SpannableString spannable = new SpannableString(source);
        spannable.setSpan(new ForegroundColorSpan(color), start, end, 0);
        tv.setText(spannable);
    }

    public static void setSpannableString(TextView tv, String source, int start, int end, int color, int textSize) {
        SpannableString spannable = new SpannableString(source);
        spannable.setSpan(new AbsoluteSizeSpan(textSize), start, end, 33);
        spannable.setSpan(new ForegroundColorSpan(color), start, end, 0);
        tv.setText(spannable);
    }

    public static float getDataDirectorySize() {
        StatFs stat = new StatFs(Environment.getDataDirectory().getPath());
        float totalBlocks = stat.getBlockCount();
        float availableBlocks = stat.getAvailableBlocks();
        float size = (totalBlocks - availableBlocks) / totalBlocks;
        Log.i("ydp", "DataDirectorySize:" + size);
        return size;
    }

    public static void alert(Context ctx, int title, String msg) {
        try {
            new CustomDialog.Builder(ctx).setNeutralButton(C0415R.string.ok, (DialogInterface.OnClickListener) null).setMessage(msg).setTitle(title).show();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void showToast(Context ctx, String msg) {
        Toast.makeText(ctx, msg, 0).show();
    }
}
