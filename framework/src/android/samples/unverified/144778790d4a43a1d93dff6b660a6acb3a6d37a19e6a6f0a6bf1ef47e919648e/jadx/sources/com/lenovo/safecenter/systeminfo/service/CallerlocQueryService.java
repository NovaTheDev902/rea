package com.lenovo.safecenter.systeminfo.service;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;
import com.lenovo.safecenter.systeminfo.p010db.DBHelper;

/* JADX INFO: loaded from: classes.dex */
public class CallerlocQueryService {

    /* JADX INFO: renamed from: a */
    private static final String f5617a = CallerlocQueryService.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static CallerlocQueryService f5618b = new CallerlocQueryService();

    private CallerlocQueryService() {
    }

    public static CallerlocQueryService getInstance() {
        return f5618b;
    }

    public String queryByAreaCode(String areaCode) {
        String result = null;
        if (areaCode == null || "".equals(areaCode)) {
            return null;
        }
        SQLiteDatabase db = DBHelper.getInstance().getReadableDatabase();
        Cursor cursor = db.query(" numdata ", null, " area_code=? ", new String[]{areaCode}, null, null, null);
        if (cursor.moveToNext()) {
            String result2 = cursor.getString(cursor.getColumnIndex("province"));
            result = result2 + cursor.getString(cursor.getColumnIndex("city"));
        }
        cursor.close();
        db.close();
        return result;
    }

    public String queryByNumberSegment(String numberSegment) {
        String result = null;
        if (numberSegment == null || "".equals(numberSegment) || numberSegment.length() < 7) {
            return null;
        }
        if (numberSegment.length() > 7) {
            numberSegment = numberSegment.substring(0, 7);
            Log.i(f5617a, numberSegment);
        }
        SQLiteDatabase db = DBHelper.getInstance().getReadableDatabase();
        Cursor cursor = db.query(" numdata ", null, " num_segment=? ", new String[]{numberSegment}, null, null, null);
        if (cursor.moveToNext()) {
            String result2 = cursor.getString(cursor.getColumnIndex("province"));
            result = (result2 + " " + cursor.getString(cursor.getColumnIndex("city"))) + cursor.getString(cursor.getColumnIndex("carry"));
        }
        cursor.close();
        db.close();
        return result;
    }
}
