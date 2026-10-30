package com.lenovo.safecenter.lenovoAntiSpam.utils;

import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.net.Uri;
import android.preference.PreferenceManager;
import android.provider.Settings;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.lenovoAntiSpam.domain.ContractHelpUtils;
import com.tencent.tmsecure.module.update.UpdateConfig;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class CheckCenter {
    public static String ACTION_NETBLACK = "action_netblack";
    public static String ACTION_LOCALBLACK = "action_localblack";
    public static String ACTION_HARASS = "action_harss";

    public static boolean modWhitePerson(Context context, String number, String name) {
        try {
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.WhitePersonProvider/whiteperson");
            ContentValues values = new ContentValues();
            values.put("name", name);
            int i = resolver.update(uri, values, " phonenumber =? ", new String[]{number});
            return i > 0;
        } catch (Exception e) {
            return false;
        }
    }

    public static boolean modLocalBlack(Context context, String name, String number) {
        try {
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            ContentValues values = new ContentValues();
            values.put("name", name);
            int i = resolver.update(uri, values, " phonenumber=?  ", new String[]{number});
            return i > 0;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public static void updateSys(Context context, InputStream is) throws Throwable {
        FileOutputStream fos = null;
        try {
            try {
                String rulePath = context.getFilesDir().getAbsolutePath() + CookieSpec.PATH_DELIM + UpdateConfig.SMS_CHECKER_NAME;
                File file = new File(rulePath);
                if (file.exists()) {
                    file.delete();
                }
                file.createNewFile();
                FileOutputStream fos2 = new FileOutputStream(file);
                try {
                    byte[] buf = new byte[1024];
                    while (true) {
                        int len = is.read(buf);
                        if (len == -1) {
                            break;
                        } else {
                            fos2.write(buf, 0, len);
                        }
                    }
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                    try {
                        fos2.close();
                    } catch (IOException e2) {
                        e2.printStackTrace();
                    }
                } catch (IOException e3) {
                    e = e3;
                    fos = fos2;
                    e.printStackTrace();
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e4) {
                            e4.printStackTrace();
                        }
                    }
                    if (fos != null) {
                        try {
                            fos.close();
                        } catch (IOException e5) {
                            e5.printStackTrace();
                        }
                    }
                } catch (Throwable th) {
                    th = th;
                    fos = fos2;
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e6) {
                            e6.printStackTrace();
                        }
                    }
                    if (fos != null) {
                        try {
                            fos.close();
                        } catch (IOException e7) {
                            e7.printStackTrace();
                        }
                    }
                    throw th;
                }
            } catch (IOException e8) {
                e = e8;
            }
        } catch (Throwable th2) {
            th = th2;
        }
    }

    public static boolean getHarssAction(Context context, String preName) {
        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(context);
        boolean isOn = prefs.getBoolean(preName, false);
        if (preName.equals("openlocalsmsharass") || preName.equals("openintellectharass")) {
            boolean isOn2 = prefs.getBoolean(preName, true);
            return isOn2;
        }
        return isOn;
    }

    public static boolean isNetBlack(Context context, int type, String number) {
        try {
            ContractHelpUtils help = new ContractHelpUtils();
            if (help.isMobileNO(number)) {
                number = help.optNUmber(number);
            }
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.netBlackProvider/netblack");
            Cursor cursor = resolver.query(uri, null, "PHONE_NUMBERS_EQUAL(number,'" + number + "',0) and type=?", new String[]{String.valueOf(type)}, null);
            int count = cursor.getCount();
            cursor.close();
            return count > 0;
        } catch (Exception e) {
            return false;
        }
    }

    public static boolean SysBlack(Context context, String number) {
        try {
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            Cursor cursor = resolver.query(uri, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0)", null, null);
            int count = cursor.getCount();
            cursor.close();
            return count > 0;
        } catch (Exception e) {
            return false;
        }
    }

    public static boolean isLocalBlack(Context context, int type, String number) {
        try {
            ContentResolver resolver = context.getContentResolver();
            ContractHelpUtils help = new ContractHelpUtils();
            if (help.isMobileNO(number)) {
                number = help.optNUmber(number);
            }
            Uri uri = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            Cursor cursor = resolver.query(uri, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0) and (type=? or type=?)", new String[]{String.valueOf(type), String.valueOf(2)}, null);
            int count = cursor.getCount();
            cursor.close();
            return count > 0;
        } catch (Exception e) {
            return false;
        }
    }

    public static boolean isWhitePerson(Context context, String number) {
        try {
            ContractHelpUtils help = new ContractHelpUtils();
            if (help.isMobileNO(number)) {
                number = help.optNUmber(number);
            }
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.WhitePersonProvider/whiteperson");
            Cursor cursor = resolver.query(uri, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0) ", null, null);
            int count = cursor.getCount();
            cursor.close();
            return count > 0;
        } catch (Exception e) {
            return false;
        }
    }

    public static int getHarassCount(Context context, String type) {
        ContentResolver resolver = context.getContentResolver();
        Uri uri = Uri.parse("content://com.lenovo.safecenter.HarassProvider/safe_log_harass");
        Cursor cursor = resolver.query(uri, null, " type=? and hassee=1", new String[]{type}, null);
        int count = cursor.getCount();
        cursor.close();
        return count;
    }

    public static boolean Judge(int bh, int bm, int eh, int em) {
        SimpleDateFormat df = new SimpleDateFormat("HH:mm");
        Date date = new Date(Long.parseLong(String.valueOf(System.currentTimeMillis())));
        String[] times = df.format(date).split(C0092c.f1283N);
        int curH = Integer.parseInt(times[0]);
        int curM = Integer.parseInt(times[1]);
        if (bh > eh) {
            if (curH > bh || curH < eh) {
                return true;
            }
            if (curH == bh && curM >= bm) {
                return true;
            }
            if (curH == eh && curM <= em) {
                return true;
            }
        } else if (bh < eh) {
            if (curH > bh && eh > curH) {
                return true;
            }
            if (curH == bh && curM >= bm) {
                return true;
            }
            if (curH == eh && curM <= em) {
                return true;
            }
        } else if (bh == eh && curH == bh && bm < curM && em > curM) {
            return true;
        }
        return false;
    }

    public static boolean judgeNightHarass(Context context) {
        if (Settings.System.getInt(context.getContentResolver(), "nightharss_switch", 0) == 0) {
            return false;
        }
        int beginHour = Settings.System.getInt(context.getContentResolver(), "nightharss_BH", 23);
        int endhour = Settings.System.getInt(context.getContentResolver(), "nightharss_EH", 7);
        int beginMinute = Settings.System.getInt(context.getContentResolver(), "nightharss_BM", 0);
        int endMinute = Settings.System.getInt(context.getContentResolver(), "nightharss_EM", 30);
        return Judge(beginHour, beginMinute, endhour, endMinute);
    }

    public static boolean insertLocalBlack(Context context, int type, String number) {
        try {
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            ContentValues values = new ContentValues();
            values.put("type", Integer.valueOf(type));
            values.put("phonenumber", number);
            return resolver.insert(uri, values) != null;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public static boolean insertWhitePerson(Context context, String number) {
        try {
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.WhitePersonProvider/whiteperson");
            ContentValues values = new ContentValues();
            values.put("phonenumber", number);
            return resolver.insert(uri, values) != null;
        } catch (Exception e) {
            return false;
        }
    }
}
