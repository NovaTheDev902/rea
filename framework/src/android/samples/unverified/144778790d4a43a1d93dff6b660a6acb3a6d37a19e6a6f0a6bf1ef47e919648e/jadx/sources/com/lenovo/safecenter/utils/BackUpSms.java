package com.lenovo.safecenter.utils;

import android.content.ContentResolver;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteException;
import android.net.Uri;
import android.provider.ContactsContract;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.text.SimpleDateFormat;
import java.util.Date;

/* JADX INFO: loaded from: classes.dex */
public class BackUpSms {

    /* JADX INFO: renamed from: a */
    private ContentResolver f5709a;

    /* JADX INFO: renamed from: b */
    private Context f5710b;

    /* JADX INFO: renamed from: c */
    private StringBuilder f5711c = new StringBuilder();

    public BackUpSms(Context context) {
        this.f5710b = context;
        this.f5709a = context.getContentResolver();
    }

    public void backup() {
        String type;
        String personName;
        Log.i("info", "in the smsbackup");
        try {
            String[] projection = {"_id", "address", "person", PushReceiver.BODY, "date", "type"};
            Uri uri = Uri.parse("content://sms/");
            Cursor cur = this.f5709a.query(uri, projection, null, null, "date desc");
            if (cur.moveToFirst()) {
                int phoneNumberColumn = cur.getColumnIndex("address");
                int smsbodyColumn = cur.getColumnIndex(PushReceiver.BODY);
                int dateColumn = cur.getColumnIndex("date");
                int typeColumn = cur.getColumnIndex("type");
                do {
                    String phoneNumber = cur.getString(phoneNumberColumn);
                    String smsbody = cur.getString(smsbodyColumn);
                    SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
                    Date d = new Date(Long.parseLong(cur.getString(dateColumn)));
                    String date = dateFormat.format(d);
                    int typeId = cur.getInt(typeColumn);
                    if (typeId == 1) {
                        type = this.f5710b.getString(C0415R.string.receive);
                    } else if (typeId == 2) {
                        type = this.f5710b.getString(C0415R.string.send);
                    } else {
                        type = "";
                    }
                    String[] projections = {"display_name"};
                    Uri uri1 = ContactsContract.CommonDataKinds.Phone.CONTENT_URI;
                    if (phoneNumber == null) {
                        personName = this.f5710b.getString(C0415R.string.stranger);
                    } else {
                        Cursor c1 = this.f5709a.query(uri1, projections, "data1=?", new String[]{phoneNumber}, null);
                        if (c1.getCount() == 0) {
                            if (phoneNumber.contains("+86")) {
                                Log.i("ydp", "oldNumber:" + phoneNumber);
                                String newNumber = phoneNumber.substring(3);
                                Log.i("ydp", "newNumber:" + newNumber);
                                Cursor c2 = this.f5709a.query(uri1, projections, "data1=?", new String[]{newNumber}, null);
                                if (c2.getCount() == 0) {
                                    personName = this.f5710b.getString(C0415R.string.stranger);
                                } else {
                                    c2.moveToPosition(0);
                                    personName = c2.getString(0);
                                }
                                c2.close();
                            } else {
                                personName = this.f5710b.getString(C0415R.string.stranger);
                            }
                        } else {
                            c1.moveToPosition(0);
                            personName = c1.getString(0);
                        }
                        c1.close();
                    }
                    String[] strArr = {personName, phoneNumber, type, date, smsbody};
                    this.f5711c.append(this.f5710b.getString(C0415R.string.name) + strArr[0] + "  " + strArr[1] + "(" + strArr[2] + ")\r\n" + this.f5710b.getString(C0415R.string.date) + strArr[3] + "\r\n" + this.f5710b.getString(C0415R.string.smsbody) + strArr[4] + "\r\n\r\n");
                } while (cur.moveToNext());
            }
            cur.close();
        } catch (SQLiteException ex) {
            Log.d("SQLiteException in getSmsInPhone", ex.getMessage());
        }
        String string = this.f5711c.toString();
        try {
            Context context = this.f5710b;
            Context context2 = this.f5710b;
            FileOutputStream fileOutputStreamOpenFileOutput = context.openFileOutput("smsbackup.txt", 0);
            OutputStreamWriter outputStreamWriter = new OutputStreamWriter(fileOutputStreamOpenFileOutput, "gb2312");
            outputStreamWriter.write(string);
            outputStreamWriter.close();
            fileOutputStreamOpenFileOutput.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
