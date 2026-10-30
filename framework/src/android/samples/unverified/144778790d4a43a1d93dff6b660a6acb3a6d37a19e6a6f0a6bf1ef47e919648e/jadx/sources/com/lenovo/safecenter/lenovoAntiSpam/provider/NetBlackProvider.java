package com.lenovo.safecenter.lenovoAntiSpam.provider;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.content.UriMatcher;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;
import com.lenovo.safecenter.lenovoAntiSpam.database.NetAppDatabase;

/* JADX INFO: loaded from: classes.dex */
public class NetBlackProvider extends ContentProvider {

    /* JADX INFO: renamed from: a */
    private static final UriMatcher f3981a = new UriMatcher(-1);

    /* JADX INFO: renamed from: b */
    private NetAppDatabase f3982b;

    static {
        f3981a.addURI("com.lenovo.safecenter.netBlackProvider", "netblack", 1);
    }

    @Override // android.content.ContentProvider
    public boolean onCreate() {
        this.f3982b = new NetAppDatabase(getContext());
        return true;
    }

    @Override // android.content.ContentProvider
    public String getType(Uri uri) {
        switch (f3981a.match(uri)) {
            case 1:
                return "vnd.android.cursor.dir/netblack";
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        SQLiteDatabase db = this.f3982b.getReadableDatabase();
        switch (f3981a.match(uri)) {
            case 1:
                return db.query("netblack", projection, selection, selectionArgs, null, null, sortOrder);
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public Uri insert(Uri uri, ContentValues values) {
        return null;
    }

    @Override // android.content.ContentProvider
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        SQLiteDatabase db = this.f3982b.getWritableDatabase();
        switch (f3981a.match(uri)) {
            case 1:
                int num = db.delete("netblack", selection, selectionArgs);
                return num;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        return 0;
    }
}
