package com.tendcloud.tenddata;

import android.database.sqlite.SQLiteDatabase;
import android.provider.BaseColumns;

/* JADX INFO: renamed from: com.tendcloud.tenddata.e */
/* JADX INFO: loaded from: classes.dex */
final class C0073e implements BaseColumns {

    /* JADX INFO: renamed from: b */
    public static final String f103b = "start_time";

    /* JADX INFO: renamed from: c */
    public static final String f104c = "duration";

    /* JADX INFO: renamed from: d */
    public static final String f105d = "session_id";

    /* JADX INFO: renamed from: g */
    public static final String f108g = "activity";

    /* JADX INFO: renamed from: a */
    public static final String f102a = "name";

    /* JADX INFO: renamed from: e */
    public static final String f106e = "refer";

    /* JADX INFO: renamed from: f */
    public static final String f107f = "realtime";

    /* JADX INFO: renamed from: h */
    public static final String[] f109h = {"_id", f102a, "start_time", "duration", "session_id", f106e, f107f};

    C0073e() {
    }

    /* JADX INFO: renamed from: a */
    public static final void m69a(SQLiteDatabase sQLiteDatabase) {
        sQLiteDatabase.execSQL("CREATE TABLE activity (_id INTEGER PRIMARY KEY autoincrement,name TEXT,start_time LONG,duration INTEGER,session_id TEXT,refer TEXT,realtime LONG)");
    }

    /* JADX INFO: renamed from: b */
    public static final void m70b(SQLiteDatabase sQLiteDatabase) {
        sQLiteDatabase.execSQL("DROP TABLE IF EXISTS activity");
    }
}
