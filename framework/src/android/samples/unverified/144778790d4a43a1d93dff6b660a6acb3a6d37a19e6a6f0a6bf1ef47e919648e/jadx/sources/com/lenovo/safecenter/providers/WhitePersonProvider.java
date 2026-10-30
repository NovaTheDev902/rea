package com.lenovo.safecenter.providers;

import android.content.ContentProvider;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.UriMatcher;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;
import com.lenovo.safecenter.database.AppDatabase;

/* JADX INFO: loaded from: classes.dex */
public class WhitePersonProvider extends ContentProvider {

    /* JADX INFO: renamed from: a */
    private static final UriMatcher f4995a = new UriMatcher(-1);

    /* JADX INFO: renamed from: b */
    private AppDatabase f4996b;

    static {
        f4995a.addURI("com.lenovo.safecenter.whiteperson", "whiteperson", 1);
    }

    @Override // android.content.ContentProvider
    public boolean onCreate() {
        this.f4996b = new AppDatabase(getContext());
        return true;
    }

    @Override // android.content.ContentProvider
    public String getType(Uri uri) {
        switch (f4995a.match(uri)) {
            case 1:
                return "vnd.android.cursor.dir/whiteperson";
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        SQLiteDatabase db = this.f4996b.getReadableDatabase();
        switch (f4995a.match(uri)) {
            case 1:
                return db.query("whiteperson", projection, selection, selectionArgs, null, null, sortOrder);
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        SQLiteDatabase db = this.f4996b.getWritableDatabase();
        switch (f4995a.match(uri)) {
            case 1:
                int num = db.delete("whiteperson", selection, selectionArgs);
                return num;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        return 0;
    }

    @Override // android.content.ContentProvider
    public Uri insert(Uri uri, ContentValues values) {
        SQLiteDatabase db = this.f4996b.getWritableDatabase();
        switch (f4995a.match(uri)) {
            case 1:
                long rowid = db.insert("whiteperson", "_id", values);
                return ContentUris.withAppendedId(uri, rowid);
            default:
                return null;
        }
    }
}
