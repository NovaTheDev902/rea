package com.lenovo.safecenter.lenovoAntiSpam.provider;

import android.content.ContentProvider;
import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Context;
import android.content.UriMatcher;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;
import android.provider.Settings;
import android.util.Log;
import com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.database.NetAppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.domain.BlackInfo;
import com.lenovo.safecenter.lenovoAntiSpam.domain.ContractHelpUtils;
import com.lenovo.safecenter.utils.Untils;

/* JADX INFO: loaded from: classes.dex */
public class LocalBlackProvider extends ContentProvider {

    /* JADX INFO: renamed from: a */
    private static final UriMatcher f3978a = new UriMatcher(-1);

    /* JADX INFO: renamed from: b */
    private AppDatabase f3979b;

    /* JADX INFO: renamed from: c */
    private NetAppDatabase f3980c;

    static {
        f3978a.addURI("com.lenovo.safecenter.LocalBlackProvider", "localblack", 1);
        f3978a.addURI("com.lenovo.safecenter.LocalBlackProvider", "localblack/#", 2);
        f3978a.addURI("com.lenovo.safecenter.LocalBlackProvider", "signnet", 3);
        f3978a.addURI("com.lenovo.safecenter.LocalBlackProvider", "signlocal", 4);
    }

    @Override // android.content.ContentProvider
    public boolean onCreate() {
        this.f3979b = new AppDatabase(getContext());
        this.f3980c = new NetAppDatabase(getContext());
        return true;
    }

    @Override // android.content.ContentProvider
    public String getType(Uri uri) {
        switch (f3978a.match(uri)) {
            case 1:
                return "vnd.android.cursor.dir/localblack";
            case 2:
                return "vnd.android.cursor.item/localblack";
            case 3:
                return "vnd.android.cursor.item/netlocalsign";
            case 4:
                return "vnd.android.cursor.item/signcall";
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        SQLiteDatabase db = this.f3979b.getReadableDatabase();
        switch (f3978a.match(uri)) {
            case 1:
                return db.query("localblack", projection, selection, selectionArgs, null, null, sortOrder);
            case 2:
                long id = ContentUris.parseId(uri);
                String where = "_id=" + id;
                if (selection != null && !"".equals(selection.trim())) {
                    where = where + " and " + selection;
                }
                return db.query("localblack", projection, where, selectionArgs, null, null, sortOrder);
            case 3:
                return this.f3980c.getReadableDatabase().rawQuery("select _id as id,phonenumber as phonenumber,signtype as signtype,signcount as signcount from netlocalsign where phonenumber=?  UNION ALL select _id as id,phonenumber as phonenumber,signtype as signtype,signcount as signcount from netsigntable where phonenumber=?", new String[]{selectionArgs[0], selectionArgs[0]});
            case 4:
                return db.query("signcall", projection, selection, selectionArgs, null, null, sortOrder);
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    public BlackInfo isLocalBlack(Context context, String number) {
        BlackInfo info = null;
        try {
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            Cursor cursor = resolver.query(uri, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0)", null, null);
            int count = cursor.getCount();
            if (count > 0) {
                cursor.moveToFirst();
                BlackInfo info2 = new BlackInfo();
                try {
                    info2.setType(cursor.getInt(cursor.getColumnIndex("type")));
                    info2.setId(cursor.getInt(cursor.getColumnIndex("_id")));
                    Log.i("demo", "type>>>>>" + cursor.getInt(cursor.getColumnIndex("type")) + "==id>>>>" + cursor.getInt(cursor.getColumnIndex("_id")));
                    info = info2;
                } catch (Exception e) {
                    return info2;
                }
            }
            cursor.close();
            return info;
        } catch (Exception e2) {
            return info;
        }
    }

    @Override // android.content.ContentProvider
    public Uri insert(Uri uri, ContentValues values) {
        SQLiteDatabase db = this.f3979b.getWritableDatabase();
        switch (f3978a.match(uri)) {
            case 1:
                if (Settings.System.getInt(getContext().getContentResolver(), "guest_mode_on", 0) == 1) {
                    return null;
                }
                if (!values.containsKey("isupload")) {
                    values.put("isupload", (Integer) 0);
                }
                if (!values.containsKey("addtime")) {
                    values.put("addtime", Long.valueOf(System.currentTimeMillis()));
                }
                String number = values.getAsString("phonenumber");
                int type = values.getAsInteger("type").intValue();
                BlackInfo cur_info = isLocalBlack(getContext(), number);
                ContractHelpUtils utils = new ContractHelpUtils();
                String realNumber = utils.getRealPhoneNumber(number);
                boolean isnumber = Untils.isPhoneNUmber(number);
                if (cur_info != null) {
                    if (type == cur_info.getType()) {
                        return null;
                    }
                    if (type == 2) {
                        type = 2;
                    } else if (type == 0) {
                        if (cur_info.getType() == 1) {
                            type = 2;
                        } else {
                            if (cur_info.getType() == 2) {
                                return null;
                            }
                            if (cur_info.getType() == 4) {
                                type = 0;
                            }
                        }
                    } else if (type == 1) {
                        if (cur_info.getType() == 0) {
                            type = 2;
                        } else {
                            if (cur_info.getType() == 2) {
                                return null;
                            }
                            if (cur_info.getType() == 4) {
                                type = 1;
                            }
                        }
                    }
                    ContentValues val = new ContentValues();
                    val.put("type", Integer.valueOf(type));
                    db.update("localblack", val, "_id=?", new String[]{String.valueOf(cur_info.getId())});
                    Log.i("demo", "type=" + type + "==id==" + cur_info.getId());
                    ContractHelpUtils.sendBraodcast(getContext(), "com.lenovo.antispam.blackperson.change");
                    return ContentUris.withAppendedId(uri, 3L);
                }
                if (isnumber) {
                    String contract_name = new ContractHelpUtils().Contacts_Name(getContext(), number);
                    if (contract_name != null) {
                        values.put("name", contract_name);
                    } else if (!values.containsKey("name")) {
                        values.putNull("name");
                    }
                    values.put("intercepttype", (Integer) 0);
                    values.put("realnumber", realNumber);
                    long rowid = db.insert("localblack", "_id", values);
                    ContractHelpUtils.sendBraodcast(getContext(), "com.lenovo.antispam.blackperson.change");
                    return ContentUris.withAppendedId(uri, rowid);
                }
                return null;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        SQLiteDatabase db = this.f3979b.getWritableDatabase();
        switch (f3978a.match(uri)) {
            case 1:
                if (Settings.System.getInt(getContext().getContentResolver(), "guest_mode_on", 0) == 1) {
                    return 0;
                }
                int iDelete = db.delete("localblack", selection, selectionArgs);
                ContractHelpUtils.sendBraodcast(getContext(), "com.lenovo.antispam.blackperson..provider.change");
                return iDelete;
            case 2:
                long id = ContentUris.parseId(uri);
                String where = "_id=" + id;
                if (selection != null && !"".equals(selection.trim())) {
                    where = where + " and " + selection;
                }
                return db.delete("localblack", where, selectionArgs);
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        SQLiteDatabase db = this.f3979b.getWritableDatabase();
        switch (f3978a.match(uri)) {
            case 1:
                int num = db.update("localblack", values, selection, selectionArgs);
                return num;
            case 2:
                long id = ContentUris.parseId(uri);
                String where = "_id=" + id;
                if (selection != null && !"".equals(selection.trim())) {
                    where = where + " and " + selection;
                }
                int num2 = db.update("localblack", values, where, selectionArgs);
                return num2;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }
}
