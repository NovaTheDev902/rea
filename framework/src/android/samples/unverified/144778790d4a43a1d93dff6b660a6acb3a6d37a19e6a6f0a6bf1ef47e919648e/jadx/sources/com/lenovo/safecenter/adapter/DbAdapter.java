package com.lenovo.safecenter.adapter;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import java.util.Locale;

/* JADX INFO: loaded from: classes.dex */
public class DbAdapter {
    public static final String APP_FILE_SIZE = "app_file_size";
    public static final String APP_MD5 = "app_md5";
    public static final String APP_NAME = "app_name";
    public static final String APP_PACKAGENAME = "app_packagename";
    public static final String APP_PROTECTION = "app_protection";
    public static final String APP_SHA1 = "app_sha1";
    public static final String APP_STATE = "app_state";
    public static final String DB_NAME = "safepayment.db";

    /* JADX INFO: renamed from: ID */
    public static final String f2874ID = "_id";
    public static final String TABLE_NAME_SAFEAPP = "safeAppTbl";
    public static final String TABLE_NAME_USERAPP = "userAppTbl";
    public static final int VERSION = 2;

    /* JADX INFO: renamed from: a */
    Context f2875a;

    /* JADX INFO: renamed from: b */
    SQLiteDatabase f2876b;

    /* JADX INFO: renamed from: c */
    C0417a f2877c;

    public DbAdapter(Context context) {
        this.f2875a = context;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.adapter.DbAdapter$a */
    class C0417a extends SQLiteOpenHelper {
        public C0417a() {
            super(DbAdapter.this.f2875a, DbAdapter.DB_NAME, (SQLiteDatabase.CursorFactory) null, 2);
        }

        @Override // android.database.sqlite.SQLiteOpenHelper
        public final void onCreate(SQLiteDatabase db) {
            db.execSQL("drop table if exists safeAppTbl");
            db.execSQL("drop table if exists userAppTbl");
            db.execSQL("create table safeAppTbl (_id integer primary key autoincrement,app_name text,app_packagename text,app_md5 text,app_file_size text,app_sha1 text)");
            db.execSQL("create table userAppTbl (_id integer primary key autoincrement,app_name text,app_packagename text,app_md5 text,app_file_size text,app_state text,app_protection text)");
        }

        @Override // android.database.sqlite.SQLiteOpenHelper
        public final void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        }
    }

    public SQLiteDatabase open() throws Exception {
        this.f2877c = new C0417a();
        this.f2877c.close();
        this.f2876b = this.f2877c.getReadableDatabase();
        this.f2876b.setLocale(Locale.getDefault());
        return this.f2876b;
    }

    public void close() {
        if (this.f2877c != null) {
            this.f2877c.close();
            this.f2876b.close();
        }
    }
}
