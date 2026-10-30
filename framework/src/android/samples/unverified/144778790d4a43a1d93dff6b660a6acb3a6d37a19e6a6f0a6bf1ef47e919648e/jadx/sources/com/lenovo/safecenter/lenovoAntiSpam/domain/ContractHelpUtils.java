package com.lenovo.safecenter.lenovoAntiSpam.domain;

import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.provider.CallLog;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.utils.Untils;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/* JADX INFO: loaded from: classes.dex */
public class ContractHelpUtils {
    public static final int From_CALL = 1;
    public static final int From_SMS = 0;
    public static final int HAS_NOUPLOAD = 0;
    public static final int HAS_UPLOAD = 1;

    public boolean isMobileNO(String mobiles) {
        try {
            String number = mobiles.replaceAll("-", "").replaceAll(" ", "");
            String number2 = number.substring(number.length() - 11, number.length());
            Pattern p = Pattern.compile("^((13[0-9])|(15[^4,\\D])|(18[0,2,5-9]))\\d{8}$");
            Matcher m = p.matcher(number2);
            return m.matches();
        } catch (Exception e) {
            return false;
        }
    }

    public String optNUmber(String mobiles) {
        String number = mobiles.replaceAll("-", "").replaceAll(" ", "");
        return number.substring(number.length() - 11, number.length());
    }

    public String getRealPhoneNumber(String number) {
        return isMobileNO(number) ? optNUmber(number) : number.replaceAll("-", "").replaceAll(" ", "");
    }

    public static int getWordCount(String s) {
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            int ascii = Character.codePointAt(s, i);
            if (ascii >= 0 && ascii <= 255) {
                length++;
            } else {
                length += 2;
            }
        }
        return length;
    }

    public static String getDate(String longtime) {
        SimpleDateFormat sfd = new SimpleDateFormat("MM/dd HH:mm");
        Date date = new Date(Long.parseLong(longtime));
        String time = sfd.format(date);
        return time;
    }

    public static String getType(Context context, int type) {
        switch (type) {
            case 1:
                String status = context.getString(C0415R.string.antispamlocalblack_becall);
                return status;
            case 2:
                String status2 = context.getString(C0415R.string.antispamlocalblack_call);
                return status2;
            case 3:
                String status3 = context.getString(C0415R.string.antispamlocalblack_misscall);
                return status3;
            default:
                return "";
        }
    }

    public List<Contract> GetMyContacts(Context act) {
        ArrayList arrayList = new ArrayList();
        ContentResolver resolver = act.getContentResolver();
        String[] projection = {"data1", "display_name"};
        String prePhone = null;
        Uri uri1 = Uri.parse("content://com.android.contacts/data/phones");
        Cursor phoneCursor = resolver.query(uri1, projection, null, null, " sort_key asc");
        Log.i("count", phoneCursor.getCount() + "===phoneCursor");
        while (phoneCursor.moveToNext()) {
            String phone = phoneCursor.getString(phoneCursor.getColumnIndex("data1"));
            String name = phoneCursor.getString(phoneCursor.getColumnIndex("display_name"));
            if (phone != null && Untils.isPhoneNUmber(phone) && !phone.equals(prePhone)) {
                prePhone = phone;
                Contract con = new Contract();
                con.setName(name);
                con.setPhoneNumber(phone);
                arrayList.add(con);
            }
        }
        phoneCursor.close();
        if (arrayList.size() > 0) {
            return arrayList;
        }
        return null;
    }

    public List<Contract> noContractRepeatList(List<Contract> repeatelist) {
        List<Contract> list = new ArrayList<>();
        if (repeatelist != null) {
            for (Contract con : repeatelist) {
                if (list.size() <= 0) {
                    list.add(con);
                } else {
                    boolean isExist = false;
                    String opt_number = con.getPhoneNumber();
                    if (isMobileNO(opt_number)) {
                        opt_number = optNUmber(opt_number);
                    }
                    for (Contract contract : list) {
                        if (Untils.compare(contract.getPhoneNumber(), opt_number, false)) {
                            isExist = true;
                            break;
                        }
                    }
                    if (!isExist) {
                        list.add(con);
                    }
                }
            }
            if (list.size() > 0) {
                return list;
            }
        }
        return null;
    }

    public List<Contract> getSimContacts(Context context) {
        Uri uri = Uri.parse("content://icc/adn");
        Log.i("code", "content://icc/adn");
        Cursor mCursor = context.getContentResolver().query(uri, null, null, null, null);
        if (mCursor == null) {
            return null;
        }
        List<Contract> list = new ArrayList<>();
        while (mCursor.moveToNext()) {
            Contract con = new Contract();
            int nameFieldColumnIndex = mCursor.getColumnIndex("name");
            con.setName(mCursor.getString(nameFieldColumnIndex));
            int numberFieldColumnIndex = mCursor.getColumnIndex(AppDatabase.NUMBER);
            con.setPhoneNumber(mCursor.getString(numberFieldColumnIndex));
            list.add(con);
        }
        mCursor.close();
        if (list.size() > 0) {
            return list;
        }
        return null;
    }

    public boolean isInContacts(Context act, String number, List<Contract> list) {
        if (isMobileNO(number)) {
            number = optNUmber(number);
        }
        for (Contract con : list) {
            boolean bool = Untils.compare(number, con.getPhoneNumber(), false);
            if (bool) {
                return true;
            }
        }
        return false;
    }

    public boolean isInContactsdia(Context act, String number) {
        if (isMobileNO(number)) {
            number = optNUmber(number);
        }
        Uri uri1 = Uri.parse("content://com.android.contacts/data/phones");
        Cursor phoneCursor = act.getContentResolver().query(uri1, null, "PHONE_NUMBERS_EQUAL(data1,'" + number + "',0)", null, null);
        int count = phoneCursor.getCount();
        phoneCursor.close();
        return count > 0;
    }

    public boolean isInSmsdia(Context act, String number) {
        if (isMobileNO(number)) {
            number = optNUmber(number);
        }
        com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase dataHelper = new com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase(act);
        List<BlackInfo> list = dataHelper.getSmsWhitePersonList();
        dataHelper.close();
        if (list != null && list.size() > 0) {
            for (BlackInfo con : list) {
                if (con.getPhoneNumber().equals(number)) {
                    return true;
                }
            }
        }
        return false;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.domain.ContractHelpUtils$a */
    class C0589a implements Comparator {
        public C0589a() {
        }

        @Override // java.util.Comparator
        public final int compare(Object o1, Object o2) {
            Contract c1 = (Contract) o1;
            Contract c2 = (Contract) o2;
            long installed1 = Long.parseLong(c1.getDate());
            long installed2 = Long.parseLong(c2.getDate());
            if (installed1 > installed2) {
                return -1;
            }
            if (installed1 == installed2) {
                return 0;
            }
            return 1;
        }
    }

    public List<Contract> getcallContractList_calling(Context act) {
        String[] projection = {AppDatabase.NUMBER, "name", "date", "type"};
        Cursor cursor = act.getContentResolver().query(CallLog.Calls.CONTENT_URI, projection, "type=?", new String[]{String.valueOf(1)}, " number,date desc ");
        List<Contract> contractList = new ArrayList<>();
        String preNum = "";
        while (cursor.moveToNext()) {
            String number = cursor.getString(cursor.getColumnIndex(AppDatabase.NUMBER));
            if (Untils.isPhoneNUmber(number)) {
                String name = cursor.getString(cursor.getColumnIndex("name"));
                if (!number.equals(preNum)) {
                    preNum = number;
                    Contract con = new Contract(name, number, 1, cursor.getString(cursor.getColumnIndex("date")), cursor.getInt(cursor.getColumnIndex("type")));
                    contractList.add(con);
                }
            }
        }
        cursor.close();
        if (contractList.size() <= 0) {
            return null;
        }
        C0589a comp = new C0589a();
        Collections.sort(contractList, comp);
        return contractList;
    }

    public List<Contract> getcallContractList(Context act) {
        String[] projection = {AppDatabase.NUMBER, "name", "date", "type"};
        Cursor cursor = act.getContentResolver().query(CallLog.Calls.CONTENT_URI, projection, null, null, " number,date desc ");
        List<Contract> contractList = new ArrayList<>();
        String preNum = "";
        while (cursor.moveToNext()) {
            String number = cursor.getString(cursor.getColumnIndex(AppDatabase.NUMBER));
            if (Untils.isPhoneNUmber(number)) {
                String name = cursor.getString(cursor.getColumnIndex("name"));
                if (!number.equals(preNum)) {
                    preNum = number;
                    Contract con = new Contract(name, number, 1, cursor.getString(cursor.getColumnIndex("date")), cursor.getInt(cursor.getColumnIndex("type")));
                    contractList.add(con);
                }
            }
        }
        cursor.close();
        if (contractList.size() <= 0) {
            return null;
        }
        C0589a comp = new C0589a();
        Collections.sort(contractList, comp);
        return contractList;
    }

    public List<Contract> getSmsContractList(Context act) {
        String name;
        List<Contract> list = new ArrayList<>();
        String[] projection = {"_id", "address", "person", PushReceiver.BODY, "date", "type"};
        String[] projectionIn = {"display_name"};
        Cursor myCursor = act.getContentResolver().query(Uri.parse("content://sms"), projection, null, null, "address,date desc");
        String preNum = "";
        for (int i = 0; i < myCursor.getCount(); i++) {
            myCursor.moveToPosition(i);
            int phoneColumn = myCursor.getColumnIndex("address");
            int smsColumn = myCursor.getColumnIndex(PushReceiver.BODY);
            int dateColumn = myCursor.getColumnIndex("date");
            String phoneNumber = myCursor.getString(phoneColumn);
            String smsContent = myCursor.getString(smsColumn);
            String date = myCursor.getString(dateColumn);
            if (phoneNumber != null && !phoneNumber.equals("wappush") && Untils.isPhoneNUmber(phoneNumber) && !phoneNumber.equals(preNum)) {
                preNum = phoneNumber;
                Uri uri1 = Uri.parse("content://com.android.contacts/data/phones");
                Cursor phoneCursor = act.getContentResolver().query(uri1, projectionIn, "PHONE_NUMBERS_EQUAL(data1,'" + phoneNumber + "',0)", null, null);
                if (!phoneCursor.moveToFirst() || phoneCursor.getCount() <= 0) {
                    name = null;
                } else {
                    name = phoneCursor.getString(phoneCursor.getColumnIndex("display_name"));
                }
                phoneCursor.close();
                Contract sms = new Contract(name, phoneNumber, 0, date, smsContent);
                list.add(sms);
            }
        }
        myCursor.close();
        Log.i("conlist", "==++++++++++++++list.size()");
        Log.i("conlist", list + "==" + list.size());
        if (list.size() <= 0) {
            return null;
        }
        C0589a comp = new C0589a();
        Collections.sort(list, comp);
        return list;
    }

    public List<Contract> getwhiteSmsContractList(Context act) {
        List<Contract> list = new ArrayList<>();
        String[] projection = {"_id", "type", AppDatabase.TIME, AppDatabase.NUMBER, AppDatabase.CONTENT};
        Cursor myCursor = act.getContentResolver().query(Uri.parse("content://com.lenovo.safecenter.HarassProvider/safe_log_harass"), projection, " type =?  and fromtype=?", new String[]{"0", "3"}, " number,time desc");
        String preNum = "";
        for (int i = 0; i < myCursor.getCount(); i++) {
            myCursor.moveToPosition(i);
            int phoneColumn = myCursor.getColumnIndex(AppDatabase.NUMBER);
            int smsColumn = myCursor.getColumnIndex(AppDatabase.CONTENT);
            int dateColumn = myCursor.getColumnIndex(AppDatabase.TIME);
            String phoneNumber = myCursor.getString(phoneColumn);
            String smsContent = myCursor.getString(smsColumn);
            String date = myCursor.getString(dateColumn);
            if (phoneNumber != null && !phoneNumber.equals("wappush") && Untils.isPhoneNUmber(phoneNumber) && !phoneNumber.equals(preNum)) {
                preNum = phoneNumber;
                Contract sms = new Contract();
                sms.setPhoneNumber(phoneNumber);
                sms.setSmsContent(smsContent);
                sms.setDate(date);
                list.add(sms);
            }
        }
        myCursor.close();
        if (list.size() <= 0) {
            return null;
        }
        C0589a comp = new C0589a();
        Collections.sort(list, comp);
        return list;
    }

    public List<Contract> getConNotInBlackList(List<Contract> list, Context context, int type) {
        List<Contract> newList = new ArrayList<>();
        if (list != null) {
            com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase DBhelper = new com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase(context);
            List<BlackInfo> balckList = DBhelper.getLocalBlackList(type);
            DBhelper.close();
            if (balckList == null) {
                return list;
            }
            long time1 = System.currentTimeMillis();
            for (Contract conn : list) {
                boolean isExist = false;
                String optNumber = conn.getPhoneNumber();
                if (isMobileNO(optNumber)) {
                    optNumber = optNUmber(optNumber);
                }
                for (BlackInfo black : balckList) {
                    if (Untils.compare(optNumber, black.getPhoneNumber(), false)) {
                        isExist = true;
                        break;
                    }
                }
                if (!isExist) {
                    newList.add(conn);
                }
            }
            long timemc = System.currentTimeMillis();
            long tinmmcend = timemc - time1;
            Log.i("timespare", "getConNotInBlackListooooo>>>" + tinmmcend);
            if (newList.size() > 0) {
                return newList;
            }
        }
        return null;
    }

    public List<Contract> getSmsNotInWhiteList(List<Contract> list, Context context) {
        List<Contract> newList = new ArrayList<>();
        if (list != null) {
            com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase DBhelper = new com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase(context);
            List<BlackInfo> balckList = DBhelper.getSmsWhitePersonList();
            DBhelper.close();
            if (balckList == null) {
                return list;
            }
            long time1 = System.currentTimeMillis();
            for (Contract conn : list) {
                boolean isExist = false;
                String optNumber = conn.getPhoneNumber();
                if (isMobileNO(optNumber)) {
                    optNumber = optNUmber(optNumber);
                }
                for (BlackInfo black : balckList) {
                    if (Untils.compare(optNumber, black.getPhoneNumber(), false)) {
                        isExist = true;
                        break;
                    }
                }
                if (!isExist) {
                    newList.add(conn);
                }
            }
            long timemc = System.currentTimeMillis();
            long tinmmcend = timemc - time1;
            Log.i("timespare", "getConNotInBlackListooooo>>>" + tinmmcend);
            if (newList.size() > 0) {
                return newList;
            }
        }
        return null;
    }

    public List<Contract> getConNotInWhiteList(List<Contract> list, Context context) {
        List<Contract> newList = new ArrayList<>();
        if (list != null) {
            com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase DBhelper = new com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase(context);
            List<BlackInfo> balckList = DBhelper.getWhitePersonList();
            DBhelper.close();
            if (balckList == null) {
                return list;
            }
            for (Contract conn : list) {
                boolean isExist = false;
                String optNumber = conn.getPhoneNumber();
                if (isMobileNO(optNumber)) {
                    optNumber = optNUmber(optNumber);
                }
                for (BlackInfo black : balckList) {
                    if (Untils.compare(optNumber, black.getPhoneNumber(), false)) {
                        isExist = true;
                        break;
                    }
                }
                if (!isExist) {
                    newList.add(conn);
                }
            }
            if (newList.size() > 0) {
                return newList;
            }
        }
        return null;
    }

    public List<BlackInfo> updateListName(List<BlackInfo> list, Context cxt, String tableName, List<Contract> contractList) {
        List<Contract> conList = GetMyContacts(cxt);
        if (conList != null) {
            Log.i("conList", conList.size() + "==updateListName");
            if (contractList != null) {
                Iterator<Contract> it = conList.iterator();
                while (it.hasNext()) {
                    contractList.add(it.next());
                }
            }
            List<BlackInfo> uList = new ArrayList<>();
            for (BlackInfo info : list) {
                String optNumber = info.getPhoneNumber();
                if (isMobileNO(optNumber)) {
                    optNumber = optNUmber(optNumber);
                }
                for (Contract con : conList) {
                    if (info.getName() == null) {
                        if (Untils.compare(con.getPhoneNumber(), optNumber, false)) {
                            if (con.getName() == null) {
                                break;
                            }
                            info.setName(con.getName());
                            uList.add(info);
                            break;
                        }
                    } else if (Untils.compare(con.getPhoneNumber(), optNumber, false)) {
                        if (!info.getName().equals(con.getName())) {
                            info.setName(con.getName());
                            uList.add(info);
                            break;
                        }
                        break;
                    }
                }
            }
            if (uList.size() > 0) {
                com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase db = new com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase(cxt);
                db.syncConName(uList, tableName.trim());
            }
        }
        return list;
    }

    public List<BlackInfo> updateSimName(List<BlackInfo> list, Context cxt, String tableName) {
        List<Contract> conList = getSimContacts(cxt);
        if (conList != null) {
            List<BlackInfo> uList = new ArrayList<>();
            for (BlackInfo info : list) {
                for (Contract con : conList) {
                    if (info.getPhoneNumber().equals(con.getPhoneNumber())) {
                        if (!info.getName().equals(con.getName())) {
                            info.setName(con.getName());
                            uList.add(info);
                            break;
                        }
                        break;
                    }
                }
                if (uList.size() > 0) {
                    com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase db = new com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase(cxt);
                    db.syncConName(uList, tableName.trim());
                }
            }
        }
        return list;
    }

    public List<BlackInfo> getBlackoutCon(List<BlackInfo> B_list, List<Contract> C_list) {
        List<BlackInfo> newList = new ArrayList<>();
        for (BlackInfo info : B_list) {
            boolean isCon = false;
            String optNumber = info.getPhoneNumber();
            if (isMobileNO(optNumber)) {
                optNumber = optNUmber(optNumber);
            }
            for (Contract con : C_list) {
                isCon = Untils.compare(con.getPhoneNumber(), optNumber, false);
                if (isCon) {
                    break;
                }
            }
            Log.i("isnull", isCon + "==" + info.getPhoneNumber());
            if (!isCon && info.getIsUpload() != 1) {
                newList.add(info);
            }
        }
        if (newList.size() > 0) {
            return newList;
        }
        return null;
    }

    public List<Contract> getInSmsContractList(Context act) {
        List<Contract> list = new ArrayList<>();
        String[] projection = {"address", "date"};
        Cursor myCursor = act.getContentResolver().query(Uri.parse("content://sms/inbox"), projection, null, null, "date desc");
        while (myCursor.moveToNext()) {
            String phoneNumber = myCursor.getString(myCursor.getColumnIndex("address"));
            if (!phoneNumber.equals("wappush") && Untils.isPhoneNUmber(phoneNumber)) {
                Contract sms = new Contract();
                sms.setPhoneNumber(phoneNumber);
                list.add(sms);
            }
        }
        myCursor.close();
        if (list.size() > 0) {
            return list;
        }
        return null;
    }

    public List<Contract> getIncallContractList(Context act) {
        String[] projection = {"type", AppDatabase.NUMBER};
        Cursor cursor = act.getContentResolver().query(CallLog.Calls.CONTENT_URI, projection, null, null, "date DESC");
        List<Contract> contractList = new ArrayList<>();
        while (cursor.moveToNext()) {
            String number = cursor.getString(cursor.getColumnIndex(AppDatabase.NUMBER));
            int type = cursor.getInt(cursor.getColumnIndex("type"));
            if (Untils.isPhoneNUmber(number) && type == 1) {
                Contract con = new Contract();
                con.setPhoneNumber(number);
                contractList.add(con);
            }
        }
        cursor.close();
        if (contractList.size() > 0) {
            return contractList;
        }
        return null;
    }

    public List<BlackInfo> judgeNum_upload(int type, List<BlackInfo> list, Context context) {
        long time1 = System.currentTimeMillis();
        List<BlackInfo> newList = new ArrayList<>();
        List<Contract> conList = getInSmsContractList(context);
        if (conList != null) {
            for (BlackInfo info : list) {
                boolean isUpload = false;
                for (Contract con : conList) {
                    if (con.getPhoneNumber().equals(info.getPhoneNumber())) {
                        isUpload = true;
                        break;
                    }
                }
                if (isUpload) {
                    newList.add(info);
                }
            }
        }
        Log.i("timespare", "timespare==" + (System.currentTimeMillis() - time1));
        if (newList.size() > 0) {
            return newList;
        }
        return null;
    }

    public String Contacts_Name(Context act, String number) {
        String name = null;
        if (isMobileNO(number)) {
            number = optNUmber(number);
        }
        ContentResolver resolver = act.getContentResolver();
        String[] projection = {"display_name"};
        Uri uri1 = Uri.parse("content://com.android.contacts/data/phones");
        Cursor phoneCursor = resolver.query(uri1, projection, "PHONE_NUMBERS_EQUAL(data1,'" + number + "',0)", null, null);
        if (phoneCursor.moveToFirst()) {
            name = phoneCursor.getString(phoneCursor.getColumnIndex("display_name"));
        }
        phoneCursor.close();
        return name;
    }

    public List<Contract> getWhiteFromadd(List<Contract> list, Context context) {
        List<Contract> W_con = new ArrayList<>();
        for (int i = list.size() - 1; i >= 0; i--) {
            Contract con = list.get(i);
            con.setRealnumber(getRealPhoneNumber(con.getPhoneNumber()));
            if (isInPrivate(context, con.getRealnumber())) {
                W_con.add(con);
            }
        }
        return W_con;
    }

    public List<Contract> getBlackFromadd(List<Contract> list, Context context) {
        List<Contract> W_con = new ArrayList<>();
        for (int i = list.size() - 1; i >= 0; i--) {
            Contract con = list.get(i);
            con.setRealnumber(getRealPhoneNumber(con.getPhoneNumber()));
            if (isBlack(context, con.getRealnumber())) {
                W_con.add(con);
            }
        }
        return W_con;
    }

    public boolean hasWhite(List<Contract> list, Context context) {
        for (int i = list.size() - 1; i >= 0; i--) {
            Contract con = list.get(i);
            con.setRealnumber(getRealPhoneNumber(con.getPhoneNumber()));
            if (isInPrivate(context, con.getRealnumber())) {
                return true;
            }
        }
        return false;
    }

    public boolean hasblack(List<Contract> list, Context context) {
        for (int i = list.size() - 1; i >= 0; i--) {
            Contract con = list.get(i);
            con.setRealnumber(getRealPhoneNumber(con.getPhoneNumber()));
            if (isBlack(context, con.getRealnumber())) {
                return true;
            }
        }
        return false;
    }

    public boolean isBlack(Context context, String number) {
        Uri uri1 = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
        Cursor phoneCursor = context.getContentResolver().query(uri1, new String[]{"_id"}, "realnumber=?", new String[]{number}, null);
        int count = phoneCursor.getCount();
        phoneCursor.close();
        return count > 0;
    }

    public boolean isInPrivate(Context context, String number) {
        Uri uri1 = Uri.parse("content://com.lenovo.safecenter.WhitePersonProvider/whiteperson");
        Cursor phoneCursor = context.getContentResolver().query(uri1, new String[]{"_id"}, "realnumber=?", new String[]{number}, null);
        int count = phoneCursor.getCount();
        phoneCursor.close();
        return count > 0;
    }

    public void deleteWhite(Context context, List<Contract> list) {
        Uri uri1 = Uri.parse("content://com.lenovo.safecenter.whiteperson/whiteperson");
        for (Contract con : list) {
            context.getContentResolver().delete(uri1, "realnumber=?", new String[]{con.getRealnumber()});
        }
    }

    public List<Contract> getAddlist(List<Contract> list, List<Contract> wList) {
        for (int i = list.size() - 1; i >= 0; i--) {
            for (Contract con : wList) {
                if (con.getRealnumber().equals(list.get(i).getRealnumber())) {
                    list.remove(i);
                    break;
                }
            }
        }
        return list;
    }

    public static void sendBraodcast(Context cxt, String intentfilter) {
        Intent intent = new Intent();
        intent.setAction(intentfilter);
        cxt.sendBroadcast(intent);
    }
}
