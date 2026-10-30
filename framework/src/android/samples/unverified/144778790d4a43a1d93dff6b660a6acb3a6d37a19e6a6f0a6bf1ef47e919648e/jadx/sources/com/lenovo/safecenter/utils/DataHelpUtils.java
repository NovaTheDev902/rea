package com.lenovo.safecenter.utils;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Context;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.graphics.drawable.BitmapDrawable;
import android.net.Uri;
import android.preference.PreferenceManager;
import android.util.Log;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.safemode.SofeModeMain;
import com.lenovo.safecenter.support.Contract;
import java.util.ArrayList;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class DataHelpUtils {
    public static ArrayList<Activity> allActivity = new ArrayList<>();
    public static HashMap<Integer, BitmapDrawable> alluserIcon = new HashMap<>();

    public String updateTadHost_Str(SofeModeMain act, AppDatabase db) {
        String str = act.getString(C0415R.string.safemode_sms);
        int count = db.getNotReadSms(1);
        if (count > 0) {
            String str_2 = act.getString(C0415R.string.record_count);
            return str + String.format(str_2, Integer.valueOf(count));
        }
        return str;
    }

    public String updateTadHostcall_Str(SofeModeMain act, AppDatabase db) {
        String str = act.getString(C0415R.string.safemode_call);
        int count = db.getNotReadCallCount();
        if (count > 0) {
            String str_2 = act.getString(C0415R.string.record_count);
            return str + String.format(str_2, Integer.valueOf(count));
        }
        return str;
    }

    public static String execService(String method, Context context) {
        SharedPreferences preferences = context.getSharedPreferences("contract_seetings", 1);
        return preferences.getString(method, "");
    }

    public static void UpdateConfig(String method, String value, Context context) {
        SharedPreferences preferences = context.getSharedPreferences("contract_seetings", 1);
        SharedPreferences.Editor editor = preferences.edit();
        editor.putString(method, value);
        editor.commit();
    }

    public static Contract getContractModel(Context context, String number) {
        Contract white = null;
        try {
            ContentResolver resolver = context.getContentResolver();
            ContractHelpUtils help = new ContractHelpUtils();
            if (help.isMobileNO(number)) {
                number = help.optNUmber(number);
            }
            Uri uri = Uri.parse("content://com.lenovo.safecenter.whiteperson/whiteperson");
            Cursor cursor = resolver.query(uri, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0) ", null, null);
            if (cursor.moveToFirst()) {
                Contract white2 = new Contract();
                try {
                    white2.setId(cursor.getInt(cursor.getColumnIndex("_id")));
                    white2.setPhoneNumber(cursor.getString(cursor.getColumnIndex("phonenumber")));
                    white2.setName(cursor.getString(cursor.getColumnIndex("name")));
                    white2.setDate(cursor.getString(cursor.getColumnIndex("addtime")));
                    white = white2;
                } catch (Exception e) {
                    return white2;
                }
            }
            cursor.close();
            return white;
        } catch (Exception e2) {
            return white;
        }
    }

    public static int isInWhiteContact(Context context, String number) {
        try {
            long time3 = System.currentTimeMillis();
            ContentResolver resolver = context.getContentResolver();
            ContractHelpUtils help = new ContractHelpUtils();
            if (help.isMobileNO(number)) {
                number = help.optNUmber(number);
            }
            long time4 = System.currentTimeMillis() - time3;
            Log.v("safemode", "help.isMobileNO(number)==" + time4);
            Uri uri = Uri.parse("content://com.lenovo.safecenter.whiteperson/whiteperson");
            long time = System.currentTimeMillis();
            Cursor cursor = resolver.query(uri, new String[]{"phonenumber"}, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0) ", null, null);
            int count = cursor.getCount();
            cursor.close();
            long time1 = System.currentTimeMillis() - time;
            Log.v("safemode", "cursor.getCount()==" + time1);
            if (count > 0) {
                return count;
            }
            return 0;
        } catch (Exception e) {
        }
    }

    public static int isInWhiteContactCall(Context context, String number) {
        try {
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.whiteperson/whiteperson");
            Cursor cursor = resolver.query(uri, new String[]{"phonenumber"}, "realnumber=?", new String[]{number}, null);
            int count = cursor.getCount();
            cursor.close();
            if (count > 0) {
                return count;
            }
        } catch (Exception e) {
        }
        return 0;
    }

    public static String getHarssAction(Context context, String preName) {
        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(context);
        String type = prefs.getString(preName, "0");
        if (preName.equals("sms_mode")) {
            String type2 = prefs.getString(preName, DatabaseTables.SYSTEM_MARK);
            return type2;
        }
        return type;
    }

    public static Activity getActivityByName(String name) {
        Activity getac = null;
        for (Activity ac : allActivity) {
            if (ac.getClass().getSimpleName().equals(name)) {
                getac = ac;
            }
        }
        return getac;
    }
}
