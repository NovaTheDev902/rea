package com.tendcloud.tenddata;

import android.database.sqlite.SQLiteDatabase;
import android.provider.BaseColumns;

/* JADX INFO: renamed from: com.tendcloud.tenddata.n */
/* JADX INFO: loaded from: classes.dex */
final class C0082n implements BaseColumns {

    /* JADX INFO: renamed from: c */
    public static final String f153c = "session_id";

    /* JADX INFO: renamed from: f */
    public static final String f156f = "app_event";

    /* JADX INFO: renamed from: a */
    public static final String f151a = "event_id";

    /* JADX INFO: renamed from: b */
    public static final String f152b = "event_label";

    /* JADX INFO: renamed from: d */
    public static final String f154d = "occurtime";

    /* JADX INFO: renamed from: e */
    public static final String f155e = "paramap";

    /* JADX INFO: renamed from: g */
    public static final String[] f157g = {"_id", f151a, f152b, "session_id", f154d, f155e};

    C0082n() {
    }

    /* JADX INFO: renamed from: a */
    public static final void m72a(SQLiteDatabase sQLiteDatabase) {
        sQLiteDatabase.execSQL("CREATE TABLE app_event (_id INTEGER PRIMARY KEY autoincrement,event_id TEXT,event_label TEXT,session_id TEXT,occurtime LONG,paramap BLOB)");
    }

    /* JADX INFO: renamed from: b */
    public static final void m73b(SQLiteDatabase sQLiteDatabase) {
        sQLiteDatabase.execSQL("DROP TABLE IF EXISTS app_event");
    }
}
