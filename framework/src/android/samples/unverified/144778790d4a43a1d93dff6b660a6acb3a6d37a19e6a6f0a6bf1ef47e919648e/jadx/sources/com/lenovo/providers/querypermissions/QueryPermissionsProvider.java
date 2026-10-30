package com.lenovo.providers.querypermissions;

import android.content.ContentProvider;
import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.UriMatcher;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.net.Uri;
import com.lenovo.safecenter.C0415R;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class QueryPermissionsProvider extends ContentProvider {

    /* JADX INFO: renamed from: b */
    private static final String[] f1959b = {QueryPermissions.RECOMMENDEDACTION};

    /* JADX INFO: renamed from: e */
    private static final UriMatcher f1960e = new UriMatcher(-1);

    /* JADX INFO: renamed from: a */
    private final String f1961a = "QueryPermissionsProvider";

    /* JADX INFO: renamed from: c */
    private SQLiteDatabase f1962c = null;

    /* JADX INFO: renamed from: d */
    private ContentResolver f1963d;

    static {
        f1960e.addURI(QueryPermissions.AUTHORITY, "pkgname/*", 2);
        f1960e.addURI(QueryPermissions.AUTHORITY, "pkgname/*/permission/*", 1);
        f1960e.addURI(QueryPermissions.AUTHORITY, "pkgname/*/type/*", 3);
        f1960e.addURI(QueryPermissions.AUTHORITY, "pkgname/*/startup", 4);
    }

    @Override // android.content.ContentProvider
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        switch (f1960e.match(uri)) {
            case 2:
                int num = this.f1962c.delete("PermissionsTable", selection, selectionArgs);
                return num;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    @Override // android.content.ContentProvider
    public String getType(Uri uri) {
        return null;
    }

    @Override // android.content.ContentProvider
    public Uri insert(Uri uri, ContentValues values) {
        switch (f1960e.match(uri)) {
            case 2:
                long rowid = this.f1962c.insert("PermissionsTable", "_id", values);
                if (rowid > -1) {
                    return ContentUris.withAppendedId(uri, rowid);
                }
                return null;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }

    /* JADX WARN: Code duplicated, block: B:27:0x0083 A[Catch: IOException -> 0x0087, TRY_LEAVE, TryCatch #2 {IOException -> 0x0087, blocks: (B:25:0x007e, B:27:0x0083), top: B:57:0x007e }] */
    /* JADX WARN: Code duplicated, block: B:36:0x0097 A[Catch: IOException -> 0x009b, TRY_LEAVE, TryCatch #8 {IOException -> 0x009b, blocks: (B:34:0x0092, B:36:0x0097), top: B:63:0x0092 }] */
    /* JADX WARN: Code duplicated, block: B:44:0x00a8 A[Catch: IOException -> 0x00ac, TRY_LEAVE, TryCatch #9 {IOException -> 0x00ac, blocks: (B:42:0x00a3, B:44:0x00a8), top: B:65:0x00a3 }] */
    @Override // android.content.ContentProvider
    public boolean onCreate() throws Throwable {
        File dbPath = new File("/data/data/com.lenovo.safecenter/databases");
        InputStream isDB = null;
        FileOutputStream osDB = null;
        if (!dbPath.exists()) {
            dbPath.mkdirs();
        }
        File dbFile = new File("/data/data/com.lenovo.safecenter/databases/permissions.db");
        if (dbFile.exists()) {
            dbFile.delete();
        }
        File oldDb = new File("/data/data/com.lenovo.safecenter/databases/permissions_1.db");
        if (oldDb.exists()) {
            oldDb.delete();
        }
        try {
            try {
                isDB = getContext().getResources().openRawResource(C0415R.raw.permissions);
                FileOutputStream osDB2 = new FileOutputStream(dbFile);
                try {
                    byte[] buffer = new byte[isDB.available()];
                    isDB.read(buffer);
                    osDB2.write(buffer);
                    if (isDB != null) {
                        try {
                            isDB.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                    osDB2.close();
                } catch (FileNotFoundException e2) {
                    e = e2;
                    osDB = osDB2;
                    e.printStackTrace();
                    if (isDB != null) {
                        try {
                            isDB.close();
                            if (osDB != null) {
                                osDB.close();
                            }
                        } catch (IOException e3) {
                            e3.printStackTrace();
                        }
                    } else if (osDB != null) {
                        osDB.close();
                    }
                } catch (IOException e4) {
                    e = e4;
                    osDB = osDB2;
                    e.printStackTrace();
                    if (isDB != null) {
                        try {
                            isDB.close();
                            if (osDB != null) {
                                osDB.close();
                            }
                        } catch (IOException e5) {
                            e5.printStackTrace();
                        }
                    } else if (osDB != null) {
                        osDB.close();
                    }
                } catch (Throwable th) {
                    th = th;
                    osDB = osDB2;
                    if (isDB != null) {
                        try {
                            isDB.close();
                            if (osDB != null) {
                                osDB.close();
                            }
                        } catch (IOException e6) {
                            e6.printStackTrace();
                            throw th;
                        }
                    } else if (osDB != null) {
                        osDB.close();
                    }
                    throw th;
                }
            } catch (Throwable th2) {
                th = th2;
            }
        } catch (FileNotFoundException e7) {
            e = e7;
        } catch (IOException e8) {
            e = e8;
        }
        try {
            this.f1962c = SQLiteDatabase.openDatabase("/data/data/com.lenovo.safecenter/databases/permissions.db", null, 16);
        } catch (SQLiteException e9) {
            e9.printStackTrace();
        }
        this.f1963d = getContext().getContentResolver();
        return true;
    }

    @Override // android.content.ContentProvider
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        Cursor cursor;
        switch (f1960e.match(uri)) {
            case 1:
                if (this.f1962c.isDbLockedByCurrentThread() || this.f1962c.isDbLockedByOtherThreads()) {
                    return null;
                }
                List<String> pathSegments = uri.getPathSegments();
                cursor = this.f1962c.query("PermissionsTable", null, "pkgname = ? AND permission = ?", new String[]{pathSegments.get(1), pathSegments.get(3)}, null, null, null);
                break;
                break;
            case 2:
                if (this.f1962c.isDbLockedByCurrentThread() || this.f1962c.isDbLockedByOtherThreads()) {
                    return null;
                }
                cursor = this.f1962c.query("PermissionsTable", null, "pkgname = ?", new String[]{uri.getPathSegments().get(1)}, null, null, null);
                break;
                break;
            case 3:
                if (this.f1962c.isDbLockedByCurrentThread() || this.f1962c.isDbLockedByOtherThreads()) {
                    return null;
                }
                List<String> pathSegments2 = uri.getPathSegments();
                cursor = this.f1962c.query("PermissionsTable", null, "pkgname = ? AND type = ?", new String[]{pathSegments2.get(1), pathSegments2.get(3)}, null, null, null);
                break;
                break;
            case 4:
                if (this.f1962c.isDbLockedByCurrentThread() || this.f1962c.isDbLockedByOtherThreads()) {
                    return null;
                }
                cursor = this.f1962c.query("PermissionsTable", new String[]{"boot_auto_start"}, "pkgname = ?", new String[]{uri.getPathSegments().get(1)}, null, null, null);
                break;
                break;
            default:
                throw new IllegalArgumentException("Error Uri: " + uri);
        }
        cursor.setNotificationUri(this.f1963d, uri);
        return cursor;
    }

    @Override // android.content.ContentProvider
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        switch (f1960e.match(uri)) {
            case 2:
                int num = this.f1962c.update("PermissionsTable", values, selection, selectionArgs);
                return num;
            default:
                throw new IllegalArgumentException("Unknown Uri:" + uri);
        }
    }
}
