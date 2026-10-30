package com.lenovo.performancecenter.framework;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/* JADX INFO: loaded from: classes.dex */
public class PerformanceDatabaseHelper extends SQLiteOpenHelper {
    public PerformanceDatabaseHelper(Context mContext) {
        super(mContext, "perf_leemcenter.db", (SQLiteDatabase.CursorFactory) null, 7);
    }

    @Override // android.database.sqlite.SQLiteOpenHelper
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(DatabaseTables.Create_UsedAppInfo_Table);
        db.execSQL(DatabaseTables.Create_applications_Table);
        db.execSQL(DatabaseTables.Create_WhiteListInfo_Table);
        db.execSQL(DatabaseTables.Create_BootCompleted_Table);
        db.execSQL(DatabaseTables.Create_Log_Table);
    }

    @Override // android.database.sqlite.SQLiteOpenHelper
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        Cursor p_cur = db.query(DatabaseTables.UsedAppInfo_TABLE_NAME, null, null, null, null, null, null);
        if (p_cur.getCount() <= 1) {
            db.execSQL("drop table if exists UsedApplication");
            db.execSQL(DatabaseTables.Create_UsedAppInfo_Table);
        }
        Cursor process_cur = db.query(DatabaseTables.APPLICATIONS_TABLE_NAME, null, null, null, null, null, null);
        if (process_cur.getCount() <= 1) {
            db.execSQL("drop table if exists ApplicationsInfo");
            db.execSQL(DatabaseTables.Create_applications_Table);
        }
        db.execSQL("drop table if exists WhiteList");
        db.execSQL(DatabaseTables.Create_WhiteListInfo_Table);
        Cursor boot_cur = db.query(DatabaseTables.BOOTCOMPLETED_TABLE_NAME, null, null, null, null, null, null);
        if (boot_cur.getCount() <= 1) {
            db.execSQL("drop table if exists BootCom");
            db.execSQL(DatabaseTables.Create_BootCompleted_Table);
        }
        Cursor log_cur = db.query(DatabaseTables.LOG_TABLE_NAME, null, null, null, null, null, null);
        if (log_cur.getCount() <= 1) {
            db.execSQL("drop table if exists LogData");
            db.execSQL(DatabaseTables.Create_Log_Table);
        }
        if (oldVersion <= 6) {
            db.execSQL("drop table if exists BootCom");
            db.execSQL(DatabaseTables.Create_BootCompleted_Table);
        }
    }
}
