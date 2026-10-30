package com.tendcloud.tenddata;

import android.database.sqlite.SQLiteDatabase;
import android.provider.BaseColumns;

/* JADX INFO: renamed from: com.tendcloud.tenddata.d */
/* JADX INFO: loaded from: classes.dex */
final class C0072d implements BaseColumns {

    /* JADX INFO: renamed from: a */
    public static final String f94a = "session_id";

    /* JADX INFO: renamed from: b */
    public static final String f95b = "start_time";

    /* JADX INFO: renamed from: c */
    public static final String f96c = "duration";

    /* JADX INFO: renamed from: g */
    public static final String f100g = "session";

    /* JADX INFO: renamed from: d */
    public static final String f97d = "is_launch";

    /* JADX INFO: renamed from: e */
    public static final String f98e = "interval";

    /* JADX INFO: renamed from: f */
    public static final String f99f = "is_connected";

    /* JADX INFO: renamed from: h */
    public static final String[] f101h = {"_id", "session_id", "start_time", "duration", f97d, f98e, f99f};

    C0072d() {
    }

    /* JADX INFO: renamed from: a */
    public static final void m67a(SQLiteDatabase sQLiteDatabase) {
        sQLiteDatabase.execSQL("CREATE TABLE session (_id INTEGER PRIMARY KEY autoincrement,session_id TEXT,start_time LONG,duration INTEGER,is_launch INTEGER,interval LONG, is_connected INTEGER)");
    }

    /* JADX INFO: renamed from: b */
    public static final void m68b(SQLiteDatabase sQLiteDatabase) {
        sQLiteDatabase.execSQL("DROP TABLE IF EXISTS session");
    }
}
