package com.lenovo.safecenter.utils;

import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import android.text.TextUtils;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.support.SecurityService;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/* JADX INFO: loaded from: classes.dex */
public class SmsUtil {
    public static final String[] THREADS_PROJECTION = {"_id", "message_count"};
    public static final Pattern NAME_ADDR_EMAIL_PATTERN = Pattern.compile("\\s*(\"[^\"]*\"|[^<>\"]+)\\s*<([^<>]+)>\\s*");
    public static final Pattern EMAIL_ADDRESS_PATTERN = Pattern.compile("[a-zA-Z0-9\\+\\.\\_\\%\\-]{1,256}\\@[a-zA-Z0-9][a-zA-Z0-9\\-]{0,64}(\\.[a-zA-Z0-9][a-zA-Z0-9\\-]{0,25})+");
    public static final String[] SMS_ONLY_COLUMNS = {"_id", "thread_id"};

    public static void statisticsSmsSent(Context context) {
        Cursor c;
        long statisticsTime = Const.getSmsSendNumStatisticsTime();
        long nextMonth = WflUtils.getNextMonthStartTime();
        if (statisticsTime <= WflUtils.parseMonthStartTime(Long.valueOf(System.currentTimeMillis())).longValue()) {
            c = m2435a(context.getContentResolver(), WflUtils.parseMonthStartTime(Long.valueOf(System.currentTimeMillis())).longValue(), nextMonth);
            Log.i("wu0wu", "sms first Statistics");
            if (c != null) {
                Const.setSmsSendNumCurrMonth(c.getCount());
            }
        } else if (statisticsTime > nextMonth) {
            c = m2435a(context.getContentResolver(), WflUtils.parseMonthStartTime(Long.valueOf(System.currentTimeMillis())).longValue(), nextMonth);
            Log.i("wu0wu", "statisticsTime > nextMonth");
            Log.i("wu0wu", "c.getCount()=" + c.getCount());
            Const.setSmsSendNumCurrMonth(c.getCount());
        } else {
            c = m2435a(context.getContentResolver(), statisticsTime, nextMonth);
            Log.i("wu0wu", "statisticsTime < nextMonth");
            Const.setSmsSendNumCurrMonth(c.getCount() + Const.getSmsSendNumCurrMonth());
            Log.i("wu0wu", "c.getCount()=" + c.getCount());
        }
        if (c != null) {
            if (c.getCount() != 0) {
                c.moveToFirst();
                Const.setSmsSendNumStatisticsTime(Long.valueOf(c.getString(c.getColumnIndexOrThrow("date"))).longValue());
                LeSafeObservable.get(context).noticeRefreshSmsSentNumCurrMonth();
                if (Const.isOutMonthLimitSMSWarn() && Const.getSmsSendNumCurrMonth() > Const.getMonthLimitSMS()) {
                    WflUtils.showTariffOutLimitNotification(context, context.getString(C0415R.string.lesafe_tariff_warn_text), context.getString(C0415R.string.curr_month_sms_out_limit_warm_text), 4096);
                }
            }
            c.close();
        }
        Log.i("wu0wu", "smsSendNumStatisticsTime=" + Const.getSmsSendNumStatisticsTime());
        Log.i("wu0wu", "smsSendNumCurrMonth=" + Const.getSmsSendNumCurrMonth());
    }

    public static void monitorSmsState(Context context) {
        Contract con;
        Log.i("ReceiveSendSMS", "onChange");
        String number = null;
        int id = 0;
        int type = 0;
        long time = 0;
        String smsContent = null;
        Cursor allCursor = context.getContentResolver().query(Uri.parse("content://sms"), null, null, null, "_id desc limit 1");
        if (allCursor.moveToFirst()) {
            StringBuilder sb = new StringBuilder();
            id = allCursor.getInt(allCursor.getColumnIndex("_id"));
            sb.append("_id=").append(id);
            int thread_id = allCursor.getInt(allCursor.getColumnIndex("thread_id"));
            sb.append("thread_id=").append(thread_id);
            number = allCursor.getString(allCursor.getColumnIndex("address"));
            sb.append(",address=").append(number);
            smsContent = allCursor.getString(allCursor.getColumnIndex(PushReceiver.BODY));
            sb.append(";body=").append(smsContent);
            time = allCursor.getLong(allCursor.getColumnIndex("date"));
            sb.append(";time=").append(time);
            sb.append(";beginTime=").append(SecurityService.beginTime);
            type = allCursor.getInt(allCursor.getColumnIndex("type"));
            sb.append(";type=").append(type);
            Log.i("ReceiveSendSMS", sb.toString());
        }
        allCursor.close();
        Cursor sentCursor = null;
        try {
            long statisticsTime = Const.getSmsSendNumStatisticsTime();
            Log.i("wu0wu", "statisticsTime=" + statisticsTime);
            long nextMonth = WflUtils.getNextMonthStartTime();
            if (statisticsTime <= WflUtils.parseMonthStartTime(Long.valueOf(System.currentTimeMillis())).longValue()) {
                sentCursor = m2435a(context.getContentResolver(), WflUtils.parseMonthStartTime(Long.valueOf(System.currentTimeMillis())).longValue(), nextMonth);
                Log.i("wu0wu", "sms first Statistics");
                if (sentCursor.getCount() != 0) {
                    onHasSendSmsEvent(context, Long.valueOf(m2433a(context)), sentCursor.getCount());
                }
            } else if (statisticsTime > nextMonth) {
                sentCursor = m2435a(context.getContentResolver(), WflUtils.parseMonthStartTime(Long.valueOf(System.currentTimeMillis())).longValue(), nextMonth);
                Log.i("wu0wu", "statisticsTime > nextMonth");
                Log.i("wu0wu", "c.getCount()=" + sentCursor.getCount());
                if (sentCursor.getCount() != 0) {
                    onHasSendSmsEvent(context, Long.valueOf(m2433a(context)), sentCursor.getCount());
                }
            } else {
                long lastSentTime = m2433a(context);
                if (lastSentTime > statisticsTime) {
                    Log.i("wu0wu", "statisticsTime < nextMonth sms+=1");
                    onHasSendSmsEvent(context, Long.valueOf(lastSentTime), Const.getSmsSendNumCurrMonth() + 1);
                }
            }
            if (time >= SecurityService.beginTime) {
                SecurityService.beginTime = time;
                if (number != null && ((type == 2 || type == 5) && (con = DataHelpUtils.getContractModel(context, number)) != null)) {
                    con.setSmstype(type);
                    con.setSmsContent(smsContent);
                    con.setDate(String.valueOf(SecurityService.beginTime));
                    con.setIsRead(0);
                    AppDatabase db = new AppDatabase(context);
                    db.insertSms(con);
                    context.getContentResolver().delete(ContentUris.withAppendedId(Uri.parse("content://sms"), id), null, null);
                    Log.i("ReceiveSendSMS", "delete==" + SecurityService.beginTime);
                }
            }
            if (sentCursor != null) {
                sentCursor.close();
            }
        } catch (Exception e) {
            if (sentCursor != null) {
                sentCursor.close();
            }
            e.printStackTrace();
            Log.i("wu0wu", "monitorSmsState Exception!!!");
        }
    }

    /* JADX INFO: renamed from: a */
    private static long m2433a(Context context) {
        Cursor lastSentCursor = context.getContentResolver().query(Uri.parse("content://sms/sent"), null, null, null, "_id desc limit 1");
        long lastSentTime = 0;
        if (lastSentCursor.moveToFirst()) {
            StringBuilder sb = new StringBuilder();
            int id = lastSentCursor.getInt(lastSentCursor.getColumnIndex("_id"));
            sb.append("_id=").append(id);
            lastSentTime = lastSentCursor.getLong(lastSentCursor.getColumnIndex("date"));
            sb.append(";time=").append(lastSentTime);
            int lastSentType = lastSentCursor.getInt(lastSentCursor.getColumnIndex("type"));
            sb.append(";type=").append(lastSentType);
            Log.i("wu0wu", "sms=" + sb.toString() + "  lastSentType=" + lastSentType);
        }
        lastSentCursor.close();
        return lastSentTime;
    }

    public static void onHasSendSmsEvent(Context context, Long date, int countSentSms) {
        Const.setSmsSendNumCurrMonth(countSentSms);
        Log.i("wu0wu", "countSentSms=" + countSentSms);
        Const.setSmsSendNumStatisticsTime(date.longValue());
        LeSafeObservable.get(context).noticeRefreshSmsSentNumCurrMonth();
        if (Const.isOutMonthLimitSMSWarn()) {
            WflUtils.Log("d", "wu0wu", "onHasSendSmsEvent() isOutMonthLimitSMSWarn=true");
            if (Const.getSmsSendNumCurrMonth() > Const.getMonthLimitSMS()) {
                WflUtils.Log("d", "wu0wu", "=====showTariffOutLimitNotification SMS_OUT_NOTI=====");
                WflUtils.showTariffOutLimitNotification(context, context.getString(C0415R.string.lesafe_tariff_warn_text), context.getString(C0415R.string.curr_month_sms_out_limit_warm_text), 4096);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private static Cursor m2435a(ContentResolver resolver, long from_time, long to_time) {
        return resolver.query(Uri.parse("content://sms/sent"), null, String.format("%s > ? AND %s < ? ", "date", "date"), new String[]{String.valueOf(from_time), String.valueOf(to_time)}, "date DESC");
    }

    public void backupThread(String recipient, Context context) {
        long threadId = m2434a(Uri.parse("content://mms-sms/threadID"), recipient, context);
        Uri.Builder uriBuilder = Uri.withAppendedPath(Uri.parse("content://mms-sms/"), "conversations").buildUpon();
        uriBuilder.appendQueryParameter("simple", "true");
        Uri uri = uriBuilder.build();
        Cursor cursor = context.getContentResolver().query(uri, THREADS_PROJECTION, "_id=" + threadId, null, null);
        if (cursor != null) {
            try {
                if (cursor.moveToFirst()) {
                    long threadId2 = cursor.getLong(0);
                    if (cursor.getInt(1) > 0) {
                        m2436a(threadId2, context);
                    }
                }
            } finally {
                cursor.close();
            }
        }
    }

    public static boolean isEmailAddress(String address) {
        if (TextUtils.isEmpty(address)) {
            return false;
        }
        String s = extractAddrSpec(address);
        Matcher match = EMAIL_ADDRESS_PATTERN.matcher(s);
        return match.matches();
    }

    public static String extractAddrSpec(String address) {
        Matcher match = NAME_ADDR_EMAIL_PATTERN.matcher(address);
        if (match.matches()) {
            return match.group(2);
        }
        return address;
    }

    /* JADX INFO: renamed from: a */
    private static long m2434a(Uri contentURI, String address, Context context) {
        Uri.Builder uriBuilder = contentURI.buildUpon();
        Set<String> recipients = new HashSet<>();
        recipients.add(address);
        for (String recipient : recipients) {
            if (isEmailAddress(recipient)) {
                recipient = extractAddrSpec(recipient);
            }
            uriBuilder.appendQueryParameter("recipient", recipient);
        }
        Uri uri = uriBuilder.build();
        Cursor cursor = context.getContentResolver().query(uri, new String[]{"_id"}, null, null, null);
        if (cursor != null) {
            try {
                if (cursor.moveToFirst()) {
                    return cursor.getLong(0);
                }
            } finally {
                cursor.close();
            }
        }
        return -1L;
    }

    /* JADX INFO: renamed from: a */
    private static void m2436a(long j, Context context) {
        Cursor cursorQuery = context.getContentResolver().query(ContentUris.withAppendedId(Uri.withAppendedPath(Uri.parse("content://mms-sms/"), "conversations"), j), SMS_ONLY_COLUMNS, null, null, null);
        ArrayList arrayList = new ArrayList();
        if (cursorQuery != null) {
            try {
                if (cursorQuery.moveToFirst()) {
                    do {
                        arrayList.add(Long.valueOf(cursorQuery.getLong(0)));
                    } while (cursorQuery.moveToNext());
                }
            } finally {
                cursorQuery.close();
                Iterator it = arrayList.iterator();
                while (it.hasNext()) {
                    context.getContentResolver().delete(ContentUris.withAppendedId(Uri.parse("content://sms"), ((Long) it.next()).longValue()), null, null);
                }
            }
        }
    }
}
