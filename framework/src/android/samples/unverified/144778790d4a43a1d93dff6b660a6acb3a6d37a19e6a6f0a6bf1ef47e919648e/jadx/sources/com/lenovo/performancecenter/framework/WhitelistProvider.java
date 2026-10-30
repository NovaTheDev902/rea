package com.lenovo.performancecenter.framework;

import android.content.ContentProvider;
import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.UriMatcher;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;
import android.util.Log;

/* JADX INFO: loaded from: classes.dex */
public class WhitelistProvider extends ContentProvider {

    /* JADX INFO: renamed from: a */
    private static final UriMatcher f1649a = new UriMatcher(-1);

    /* JADX INFO: renamed from: b */
    private ContentResolver f1650b;

    static {
        f1649a.addURI(WhitelistAuth.AUTHORITY, "queryWhitelistApps", 1);
        f1649a.addURI(WhitelistAuth.AUTHORITY, "updateWhitelistApp", 2);
    }

    @Override // android.content.ContentProvider
    public boolean onCreate() {
        this.f1650b = getContext().getContentResolver();
        return true;
    }

    @Override // android.content.ContentProvider
    public String getType(Uri uri) {
        return null;
    }

    @Override // android.content.ContentProvider
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        Log.i("ContentProvider", "uri == " + uri);
        int code = f1649a.match(uri);
        switch (code) {
            case 1:
                PerformanceDatabaseHelper perfDatabaseHelper = new PerformanceDatabaseHelper(getContext());
                SQLiteDatabase database = perfDatabaseHelper.getReadableDatabase();
                Cursor cursor = database.rawQuery("SELECT * FROM ApplicationsInfo where state = 1 ", null);
                cursor.setNotificationUri(this.f1650b, uri);
                return cursor;
            default:
                throw new IllegalArgumentException("Error Uri: " + uri);
        }
    }

    @Override // android.content.ContentProvider
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        Log.i("ContentProvider", "uri == " + uri);
        int code = f1649a.match(uri);
        switch (code) {
            case 2:
                PerformanceDatabaseHelper perfDatabaseHelper = new PerformanceDatabaseHelper(getContext());
                SQLiteDatabase database = perfDatabaseHelper.getReadableDatabase();
                int effectRow = database.update(DatabaseTables.APPLICATIONS_TABLE_NAME, values, selection, selectionArgs);
                return effectRow;
            default:
                throw new IllegalArgumentException("Error Uri: " + uri);
        }
    }

    @Override // android.content.ContentProvider
    public Uri insert(Uri uri, ContentValues values) {
        return null;
    }

    @Override // android.content.ContentProvider
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        return 0;
    }
}
