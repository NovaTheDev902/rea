package com.lenovo.safecenter.utils;

import android.content.ContentResolver;
import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.database.Cursor;
import android.net.Uri;
import android.provider.ContactsContract;
import android.util.Log;
import java.io.FileInputStream;
import java.io.FileOutputStream;

/* JADX INFO: loaded from: classes.dex */
public class BackUpContact {

    /* JADX INFO: renamed from: a */
    private Context f5707a;

    /* JADX INFO: renamed from: b */
    private StringBuilder f5708b;

    public BackUpContact(Context context) {
        this.f5707a = context;
    }

    public void backup() {
        Log.i("info", "in the contact backup");
        this.f5708b = new StringBuilder();
        ContentResolver cr = this.f5707a.getContentResolver();
        Cursor cur = cr.query(ContactsContract.Contacts.CONTENT_URI, null, null, null, null);
        for (int i = 0; i < cur.getCount(); i++) {
            cur.moveToPosition(i);
            String lookupKey = cur.getString(cur.getColumnIndex("lookup"));
            Uri uri = Uri.withAppendedPath(ContactsContract.Contacts.CONTENT_VCARD_URI, lookupKey);
            try {
                AssetFileDescriptor fd = this.f5707a.getContentResolver().openAssetFileDescriptor(uri, "r");
                FileInputStream fis = fd.createInputStream();
                String str = m2361a(fis);
                this.f5708b.append(str);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        String string = this.f5708b.toString();
        try {
            Context context = this.f5707a;
            Context context2 = this.f5707a;
            FileOutputStream fileOutputStreamOpenFileOutput = context.openFileOutput("Contacts.vcf", 0);
            fileOutputStreamOpenFileOutput.write(string.getBytes());
            fileOutputStreamOpenFileOutput.close();
        } catch (Exception e2) {
            e2.printStackTrace();
        }
        cur.close();
    }

    /* JADX INFO: renamed from: a */
    private static String m2361a(FileInputStream fis) {
        try {
            byte[] buffer = new byte[fis.available()];
            fis.read(buffer);
            return new String(buffer);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}
