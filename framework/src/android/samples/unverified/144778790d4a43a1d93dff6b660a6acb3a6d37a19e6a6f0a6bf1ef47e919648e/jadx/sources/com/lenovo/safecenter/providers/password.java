package com.lenovo.safecenter.providers;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.content.UriMatcher;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.Untils;

/* JADX INFO: loaded from: classes.dex */
public class password extends ContentProvider {

    /* JADX INFO: renamed from: a */
    private static final UriMatcher f4997a = new UriMatcher(-1);

    /* JADX INFO: renamed from: b */
    private AppDatabase f4998b;

    static {
        f4997a.addURI("com.lenovo.safecenter.password", "password", 1);
    }

    @Override // android.content.ContentProvider
    public boolean onCreate() {
        this.f4998b = new AppDatabase(getContext());
        return true;
    }

    @Override // android.content.ContentProvider
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        SQLiteDatabase db = this.f4998b.getReadableDatabase();
        switch (f4997a.match(uri)) {
            case 1:
                Cursor cursor = null;
                if (selectionArgs != null) {
                    if (db.isDbLockedByCurrentThread() || db.isDbLockedByOtherThreads()) {
                        return null;
                    }
                    Cursor newCursor = db.query("passwordNew", null, null, null, null, null, null);
                    if (newCursor.moveToFirst()) {
                        String pwd = Untils.jieMi(newCursor.getString(1), PwdUtil.key);
                        cursor = db.query("checkpwd", projection, "result=" + (selectionArgs[0].equals(pwd) ? 1 : 0), null, null, null, sortOrder);
                    }
                }
                return cursor;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public String getType(Uri uri) {
        switch (f4997a.match(uri)) {
            case 1:
                return "vnd.android.cursor.dir/password";
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        return 0;
    }

    @Override // android.content.ContentProvider
    public Uri insert(Uri uri, ContentValues values) {
        return null;
    }

    @Override // android.content.ContentProvider
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        return 0;
    }
}
