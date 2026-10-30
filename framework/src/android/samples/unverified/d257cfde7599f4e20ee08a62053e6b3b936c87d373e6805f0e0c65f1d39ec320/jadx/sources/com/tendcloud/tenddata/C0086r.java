package com.tendcloud.tenddata;

import android.database.sqlite.SQLiteDatabase;
import android.provider.BaseColumns;

/* JADX INFO: renamed from: com.tendcloud.tenddata.r */
/* JADX INFO: loaded from: classes.dex */
final class C0086r implements BaseColumns {

    /* JADX INFO: renamed from: e */
    public static final String f174e = "error_report";

    /* JADX INFO: renamed from: a */
    public static final String f170a = "error_time";

    /* JADX INFO: renamed from: b */
    public static final String f171b = "message";

    /* JADX INFO: renamed from: c */
    public static final String f172c = "repeat";

    /* JADX INFO: renamed from: d */
    public static final String f173d = "shorthashcode";

    /* JADX INFO: renamed from: f */
    public static final String[] f175f = {"_id", f170a, f171b, f172c, f173d};

    C0086r() {
    }

    /* JADX INFO: renamed from: a */
    public static final void m154a(SQLiteDatabase sQLiteDatabase) {
        sQLiteDatabase.execSQL("CREATE TABLE error_report (_id INTEGER PRIMARY KEY autoincrement,error_time LONG,message BLOB,repeat INTERGER,shorthashcode TEXT)");
    }

    /* JADX INFO: renamed from: b */
    public static final void m155b(SQLiteDatabase sQLiteDatabase) {
        sQLiteDatabase.execSQL("DROP TABLE IF EXISTS error_report");
    }
}
