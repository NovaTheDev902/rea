package com.lenovo.safecenter.providers;

import android.content.ContentProvider;
import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.UriMatcher;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;
import com.lenovo.safecenter.database.AppDatabase;

/* JADX INFO: loaded from: classes.dex */
public class AppsPermissionProvider extends ContentProvider {
    public static final String AUTHORITY = "com.lenovo.safecenter.AppsPermission";

    /* JADX INFO: renamed from: a */
    private static final UriMatcher f4989a = new UriMatcher(-1);

    /* JADX INFO: renamed from: b */
    private SQLiteDatabase f4990b;

    /* JADX INFO: renamed from: c */
    private ContentResolver f4991c;

    static {
        f4989a.addURI(AUTHORITY, AppDatabase.DB_APP, 1);
        f4989a.addURI(AUTHORITY, "appname/#", 2);
    }

    @Override // android.content.ContentProvider
    public boolean onCreate() {
        AppDatabase appDatabase = new AppDatabase(getContext());
        this.f4990b = appDatabase.getReadableDatabase();
        this.f4991c = getContext().getContentResolver();
        return true;
    }

    @Override // android.content.ContentProvider
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        switch (f4989a.match(uri)) {
            case 1:
                Cursor cursor = this.f4990b.query(AppDatabase.DB_APP, projection, selection, selectionArgs, null, null, sortOrder);
                cursor.setNotificationUri(this.f4991c, uri);
                return cursor;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public String getType(Uri uri) {
        switch (f4989a.match(uri)) {
            case 1:
                return "vnd.android.cursor.dir/appname";
            case 2:
                return "vnd.android.cursor.item/appname";
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        switch (f4989a.match(uri)) {
            case 1:
                int num = this.f4990b.delete(AppDatabase.DB_APP, selection, selectionArgs);
                return num;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public Uri insert(Uri uri, ContentValues values) {
        switch (f4989a.match(uri)) {
            case 1:
                if (!values.containsKey("isupload")) {
                    values.put("isupload", (Integer) 0);
                }
                long rowid = this.f4990b.insert(AppDatabase.DB_APP, "_id", values);
                if (rowid > -1) {
                    return ContentUris.withAppendedId(uri, rowid);
                }
                return null;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        switch (f4989a.match(uri)) {
            case 1:
                int num = this.f4990b.update(AppDatabase.DB_APP, values, selection, selectionArgs);
                return num;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }
}
