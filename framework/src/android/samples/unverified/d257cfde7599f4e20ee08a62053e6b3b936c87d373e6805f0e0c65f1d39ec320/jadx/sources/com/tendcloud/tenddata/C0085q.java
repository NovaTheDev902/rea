package com.tendcloud.tenddata;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.DatabaseUtils;
import android.database.sqlite.SQLiteDatabase;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

/* JADX INFO: renamed from: com.tendcloud.tenddata.q */
/* JADX INFO: loaded from: classes.dex */
final class C0085q {

    /* JADX INFO: renamed from: a */
    protected static final String f164a = "TD";

    /* JADX INFO: renamed from: b */
    private static final int f165b = 5;

    /* JADX INFO: renamed from: c */
    private static final String f166c = "10";

    /* JADX INFO: renamed from: d */
    private static final String f167d = "TDtcagent.db";

    /* JADX INFO: renamed from: e */
    private static SQLiteDatabase f168e;

    /* JADX INFO: renamed from: f */
    private static int f169f;

    C0085q() {
    }

    /* JADX INFO: renamed from: a */
    static long m126a(long j) throws Throwable {
        Cursor cursor;
        Cursor cursor2 = null;
        try {
            Cursor cursorQuery = f168e.query(C0073e.f108g, C0073e.f109h, "_id=?", new String[]{String.valueOf(j)}, null, null, "_id");
            try {
                if (cursorQuery.moveToFirst() && !cursorQuery.isAfterLast()) {
                    long j2 = cursorQuery.getLong(6);
                    if (cursorQuery == null) {
                        return j2;
                    }
                    cursorQuery.close();
                    return j2;
                }
                if (cursorQuery != null) {
                    cursorQuery.close();
                }
            } catch (Exception e) {
                cursor = cursorQuery;
                if (cursor != null) {
                    cursor.close();
                }
            } catch (Throwable th) {
                th = th;
                cursor2 = cursorQuery;
                if (cursor2 != null) {
                    cursor2.close();
                }
                throw th;
            }
        } catch (Exception e2) {
            cursor = null;
        } catch (Throwable th2) {
            th = th2;
        }
        return 0L;
    }

    /* JADX INFO: renamed from: a */
    static long m127a(long j, String str) throws Throwable {
        long jUpdate = 0;
        ContentValues contentValues = new ContentValues();
        contentValues.put(C0086r.f170a, Long.valueOf(j));
        try {
            C0091w c0091w = new C0091w();
            StringBuffer stringBuffer = new StringBuffer("");
            long jM129a = m129a(str, c0091w, stringBuffer);
            if (0 == jM129a) {
                contentValues.put(C0086r.f171b, str.getBytes("UTF-8"));
                contentValues.put(C0086r.f172c, (Integer) 1);
                contentValues.put(C0086r.f173d, stringBuffer.toString());
                jUpdate = f168e.insert(C0086r.f174e, null, contentValues);
            } else {
                contentValues.put(C0086r.f172c, Integer.valueOf(c0091w.f190b + 1));
                jUpdate = f168e.update(C0086r.f174e, contentValues, "_id=?", new String[]{String.valueOf(jM129a)});
            }
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return jUpdate;
    }

    /* JADX INFO: renamed from: a */
    static long m128a(String str, long j, long j2, int i) {
        try {
            ContentValues contentValues = new ContentValues();
            contentValues.put("session_id", str);
            contentValues.put("start_time", Long.valueOf(j));
            contentValues.put("duration", (Integer) 0);
            contentValues.put(C0072d.f97d, (Integer) 0);
            contentValues.put(C0072d.f98e, Long.valueOf(j2));
            contentValues.put(C0072d.f99f, Integer.valueOf(i));
            f168e.insert(C0072d.f100g, null, contentValues);
            return 0L;
        } catch (Exception e) {
            return 0L;
        }
    }

    /* JADX WARN: Code duplicated, block: B:36:0x00e9  */
    /* JADX INFO: renamed from: a */
    static long m129a(String str, C0091w c0091w, StringBuffer stringBuffer) throws Throwable {
        Cursor cursorQuery;
        Cursor cursor;
        try {
            cursorQuery = f168e.query(C0086r.f174e, C0086r.f175f, null, null, null, null, "_id");
            try {
                String[] strArrSplit = str.split("\r\n");
                if (strArrSplit.length < 3) {
                    if (cursorQuery == null) {
                        return 0L;
                    }
                    cursorQuery.close();
                    return 0L;
                }
                String str2 = strArrSplit[0] + "\r\n" + strArrSplit[1] + "\r\n" + strArrSplit[2];
                stringBuffer.append(C0089u.m179b(str2));
                if (cursorQuery.moveToFirst()) {
                    while (!cursorQuery.isAfterLast()) {
                        c0091w.f189a = cursorQuery.getLong(1);
                        c0091w.f192d = cursorQuery.getBlob(2);
                        c0091w.f190b = cursorQuery.getInt(3);
                        String str3 = new String(c0091w.f192d, "UTF-8");
                        if (str3.length() >= str2.length()) {
                            String[] strArrSplit2 = str3.split("\r\n");
                            if (strArrSplit2.length < 3) {
                                continue;
                            } else {
                                if ((strArrSplit2[0] + "\r\n" + strArrSplit2[1] + "\r\n" + strArrSplit2[2]).equals(str2)) {
                                    long j = cursorQuery.getLong(0);
                                    if (cursorQuery == null) {
                                        return j;
                                    }
                                    cursorQuery.close();
                                    return j;
                                }
                                cursorQuery.moveToNext();
                            }
                        }
                    }
                }
                if (cursorQuery != null) {
                    cursorQuery.close();
                }
            } catch (Exception e) {
                e = e;
                cursor = cursorQuery;
                try {
                    e.printStackTrace();
                    if (cursor != null) {
                        cursor.close();
                    }
                } catch (Throwable th) {
                    th = th;
                    cursorQuery = cursor;
                    if (cursorQuery != null) {
                        cursorQuery.close();
                    }
                    throw th;
                }
            } catch (Throwable th2) {
                th = th2;
                if (cursorQuery != null) {
                    cursorQuery.close();
                }
                throw th;
            }
        } catch (Exception e2) {
            e = e2;
            cursor = null;
        } catch (Throwable th3) {
            th = th3;
            cursorQuery = null;
        }
        return 0L;
    }

    /* JADX INFO: renamed from: a */
    static long m130a(String str, String str2, long j, int i, String str3, long j2) {
        try {
            ContentValues contentValues = new ContentValues();
            contentValues.put("session_id", str);
            contentValues.put(C0073e.f102a, str2);
            contentValues.put("start_time", Long.valueOf(j));
            contentValues.put("duration", Integer.valueOf(i));
            contentValues.put(C0073e.f106e, str3);
            contentValues.put(C0073e.f107f, Long.valueOf(j2));
            return f168e.insert(C0073e.f108g, null, contentValues);
        } catch (Exception e) {
            return -1L;
        }
    }

    /* JADX INFO: renamed from: a */
    static long m131a(List list) throws Throwable {
        Cursor cursor;
        int size = list.size();
        if (size == 0) {
            return 0L;
        }
        long j = 0;
        for (int i = size - 1; i >= 0; i--) {
            try {
                try {
                    Cursor cursorRawQuery = f168e.rawQuery("SELECT MAX(_id) from activity where duration != 0 and session_id =?", new String[]{((C0070b) list.get(i)).f76a});
                    try {
                        if (cursorRawQuery.moveToFirst()) {
                            long j2 = cursorRawQuery.getLong(0);
                            if (j2 != 0) {
                                if (cursorRawQuery == null) {
                                    return j2;
                                }
                                try {
                                    cursorRawQuery.close();
                                    return j2;
                                } catch (Exception e) {
                                    return j2;
                                }
                            }
                            j = j2;
                        }
                        if (cursorRawQuery != null) {
                            cursorRawQuery.close();
                        }
                    } catch (Throwable th) {
                        th = th;
                        cursor = cursorRawQuery;
                        if (cursor != null) {
                            cursor.close();
                        }
                        throw th;
                    }
                } catch (Throwable th2) {
                    th = th2;
                    cursor = null;
                }
            } catch (Exception e2) {
                return j;
            }
        }
        return j;
    }

    /* JADX INFO: renamed from: a */
    static List m132a(String str, long j) throws Throwable {
        Cursor cursorQuery;
        Cursor cursor = null;
        ArrayList arrayList = new ArrayList();
        try {
            cursorQuery = f168e.query(C0073e.f108g, C0073e.f109h, "session_id=? AND duration != 0 ", new String[]{str}, null, null, "_id");
            try {
                if (cursorQuery.moveToFirst()) {
                    while (!cursorQuery.isAfterLast()) {
                        C0094z c0094z = new C0094z();
                        c0094z.f220a = cursorQuery.getString(1);
                        c0094z.f221b = cursorQuery.getLong(2);
                        c0094z.f222c = cursorQuery.getInt(3);
                        c0094z.f223d = cursorQuery.getString(5);
                        arrayList.add(c0094z);
                        cursorQuery.moveToNext();
                    }
                }
                if (cursorQuery != null) {
                    cursorQuery.close();
                }
            } catch (Exception e) {
                if (cursorQuery != null) {
                    cursorQuery.close();
                }
            } catch (Throwable th) {
                cursor = cursorQuery;
                th = th;
                if (cursor != null) {
                    cursor.close();
                }
                throw th;
            }
        } catch (Exception e2) {
            cursorQuery = null;
        } catch (Throwable th2) {
            th = th2;
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    private static Map m133a(byte[] bArr) throws Throwable {
        DataInputStream dataInputStream;
        ByteArrayInputStream byteArrayInputStream;
        Throwable th;
        DataInputStream dataInputStream2;
        ByteArrayInputStream byteArrayInputStream2;
        Object utf;
        if (bArr == null || bArr.length == 0) {
            return null;
        }
        try {
            HashMap map = new HashMap();
            byteArrayInputStream = new ByteArrayInputStream(bArr);
            try {
                dataInputStream = new DataInputStream(byteArrayInputStream);
                try {
                    int i = dataInputStream.readInt();
                    for (int i2 = 0; i2 < i; i2++) {
                        String utf2 = dataInputStream.readUTF();
                        int i3 = dataInputStream.readInt();
                        if (i3 == 66) {
                            utf = Double.valueOf(dataInputStream.readDouble());
                        } else {
                            if (i3 != 88) {
                                TCAgent.m9a(byteArrayInputStream);
                                TCAgent.m9a(dataInputStream);
                                return null;
                            }
                            utf = dataInputStream.readUTF();
                        }
                        map.put(utf2, utf);
                    }
                    TCAgent.m9a(byteArrayInputStream);
                    TCAgent.m9a(dataInputStream);
                    return map;
                } catch (Exception e) {
                    dataInputStream2 = dataInputStream;
                    byteArrayInputStream2 = byteArrayInputStream;
                    TCAgent.m9a(byteArrayInputStream2);
                    TCAgent.m9a(dataInputStream2);
                    return null;
                } catch (Throwable th2) {
                    th = th2;
                    TCAgent.m9a(byteArrayInputStream);
                    TCAgent.m9a(dataInputStream);
                    throw th;
                }
            } catch (Exception e2) {
                dataInputStream2 = null;
                byteArrayInputStream2 = byteArrayInputStream;
            } catch (Throwable th3) {
                dataInputStream = null;
                th = th3;
            }
        } catch (Exception e3) {
            dataInputStream2 = null;
            byteArrayInputStream2 = null;
        } catch (Throwable th4) {
            dataInputStream = null;
            byteArrayInputStream = null;
            th = th4;
        }
    }

    /* JADX INFO: renamed from: a */
    static void m134a() {
        f168e.setVersion(5);
        C0072d.m67a(f168e);
        C0073e.m69a(f168e);
        C0082n.m72a(f168e);
        C0086r.m154a(f168e);
    }

    /* JADX INFO: renamed from: a */
    static void m135a(long j, long j2) {
        long jM126a = (j2 - m126a(j)) / 1000;
        ContentValues contentValues = new ContentValues();
        contentValues.put("duration", Long.valueOf(jM126a));
        try {
            f168e.update(C0073e.f108g, contentValues, "_id=?", new String[]{String.valueOf(j)});
        } catch (Exception e) {
        }
    }

    /* JADX INFO: renamed from: a */
    static synchronized void m136a(Context context) {
        if (f168e == null) {
            File file = new File(context.getFilesDir(), f167d);
            boolean zExists = file.exists();
            if (!file.getParentFile().exists()) {
                file.getParentFile().mkdirs();
            }
            f168e = SQLiteDatabase.openOrCreateDatabase(file, (SQLiteDatabase.CursorFactory) null);
            f168e.setLockingEnabled(true);
            f168e.setMaximumSize(1000000L);
            f169f = 1;
            if (!zExists) {
                m134a();
            } else if (5 > f168e.getVersion()) {
                f168e.execSQL("DROP TABLE IF EXISTS error_report");
                f168e.execSQL("DROP TABLE IF EXISTS app_event");
                f168e.execSQL("DROP TABLE IF EXISTS session");
                f168e.execSQL("DROP TABLE IF EXISTS activity");
                m134a();
            }
        } else {
            f169f++;
        }
    }

    /* JADX INFO: renamed from: a */
    static void m137a(String str) {
        ContentValues contentValues = new ContentValues();
        contentValues.put(C0072d.f97d, (Integer) 1);
        f168e.update(C0072d.f100g, contentValues, "session_id=?", new String[]{str});
    }

    /* JADX INFO: renamed from: a */
    static void m138a(String str, int i) {
        ContentValues contentValues = new ContentValues();
        contentValues.put("duration", Integer.valueOf(i));
        try {
            f168e.update(C0072d.f100g, contentValues, "session_id=?", new String[]{str});
        } catch (Exception e) {
        }
    }

    /* JADX INFO: renamed from: a */
    static boolean m139a(String str, String str2, String str3, long j, Map map) {
        try {
            ContentValues contentValues = new ContentValues();
            contentValues.put(C0082n.f151a, str2);
            contentValues.put(C0082n.f152b, str3);
            contentValues.put("session_id", str);
            contentValues.put(C0082n.f154d, Long.valueOf(j));
            contentValues.put(C0082n.f155e, m140a(map));
            return f168e.insert(C0082n.f156f, null, contentValues) != -1;
        } catch (Exception e) {
            return false;
        }
    }

    /* JADX INFO: renamed from: a */
    private static byte[] m140a(Map map) throws Throwable {
        DataOutputStream dataOutputStream;
        ByteArrayOutputStream byteArrayOutputStream;
        DataOutputStream dataOutputStream2;
        ByteArrayOutputStream byteArrayOutputStream2;
        if (map == null || map.size() == 0) {
            return null;
        }
        int size = map.size();
        if (size > 10) {
            size = 10;
        }
        try {
            byteArrayOutputStream = new ByteArrayOutputStream();
            try {
                dataOutputStream = new DataOutputStream(byteArrayOutputStream);
                try {
                    dataOutputStream.writeInt(size);
                    int i = 0;
                    Iterator it = map.entrySet().iterator();
                    do {
                        int i2 = i;
                        if (!it.hasNext()) {
                            break;
                        }
                        Map.Entry entry = (Map.Entry) it.next();
                        dataOutputStream.writeUTF((String) entry.getKey());
                        Object value = entry.getValue();
                        if (value instanceof Number) {
                            dataOutputStream.writeInt(66);
                            dataOutputStream.writeDouble(((Number) value).doubleValue());
                        } else {
                            if (!(value instanceof String)) {
                                TCAgent.m9a(byteArrayOutputStream);
                                TCAgent.m9a(dataOutputStream);
                                return null;
                            }
                            dataOutputStream.writeInt(88);
                            dataOutputStream.writeUTF((String) value);
                        }
                        i = i2 + 1;
                    } while (i != 10);
                    byte[] byteArray = byteArrayOutputStream.toByteArray();
                    TCAgent.m9a(byteArrayOutputStream);
                    TCAgent.m9a(dataOutputStream);
                    return byteArray;
                } catch (Exception e) {
                    dataOutputStream2 = dataOutputStream;
                    byteArrayOutputStream2 = byteArrayOutputStream;
                    TCAgent.m9a(byteArrayOutputStream2);
                    TCAgent.m9a(dataOutputStream2);
                    return null;
                } catch (Throwable th) {
                    th = th;
                    TCAgent.m9a(byteArrayOutputStream);
                    TCAgent.m9a(dataOutputStream);
                    throw th;
                }
            } catch (Exception e2) {
                dataOutputStream2 = null;
                byteArrayOutputStream2 = byteArrayOutputStream;
            } catch (Throwable th2) {
                th = th2;
                dataOutputStream = null;
            }
        } catch (Exception e3) {
            dataOutputStream2 = null;
            byteArrayOutputStream2 = null;
        } catch (Throwable th3) {
            th = th3;
            dataOutputStream = null;
            byteArrayOutputStream = null;
        }
    }

    /* JADX INFO: renamed from: b */
    static long m141b(List list) throws Throwable {
        int size = list.size();
        if (size == 0) {
            return 0L;
        }
        for (int i = size - 1; i >= 0; i--) {
            try {
                Cursor cursor = null;
                try {
                    Cursor cursorRawQuery = f168e.rawQuery("SELECT MAX(_id) from app_event where session_id =?", new String[]{((C0070b) list.get(i)).f76a});
                    try {
                        if (cursorRawQuery.moveToFirst()) {
                            long j = cursorRawQuery.getLong(0);
                            if (j != 0) {
                                if (cursorRawQuery == null) {
                                    return j;
                                }
                                cursorRawQuery.close();
                                return j;
                            }
                        }
                        if (cursorRawQuery != null) {
                            cursorRawQuery.close();
                        }
                    } catch (Throwable th) {
                        th = th;
                        cursor = cursorRawQuery;
                        if (cursor != null) {
                            cursor.close();
                        }
                        throw th;
                    }
                } catch (Throwable th2) {
                    th = th2;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return 0L;
    }

    /* JADX INFO: renamed from: b */
    static List m142b(String str, long j) throws Throwable {
        Cursor cursor;
        Throwable th;
        Cursor cursor2 = null;
        ArrayList arrayList = new ArrayList();
        try {
            try {
                Cursor cursorRawQuery = f168e.rawQuery("SELECT COUNT(_id), event_id, event_label, occurtime, paramap from app_event where session_id = ? group by event_id, event_label, paramap", new String[]{str});
                try {
                    if (cursorRawQuery.moveToFirst()) {
                        while (!cursorRawQuery.isAfterLast()) {
                            C0067af c0067af = new C0067af();
                            c0067af.f57c = cursorRawQuery.getInt(0);
                            c0067af.f55a = cursorRawQuery.getString(1);
                            c0067af.f56b = cursorRawQuery.getString(2);
                            c0067af.f58d = cursorRawQuery.getLong(3);
                            c0067af.f59e = null;
                            c0067af.f59e = m133a(cursorRawQuery.getBlob(4));
                            arrayList.add(c0067af);
                            cursorRawQuery.moveToNext();
                        }
                    }
                    if (cursorRawQuery != null) {
                        cursorRawQuery.close();
                    }
                } catch (Throwable th2) {
                    cursor = cursorRawQuery;
                    th = th2;
                    if (cursor == null) {
                        throw th;
                    }
                    cursor.close();
                    throw th;
                }
            } catch (Exception e) {
                if (0 != 0) {
                    cursor2.close();
                }
            }
            return arrayList;
        } catch (Throwable th3) {
            cursor = null;
            th = th3;
        }
    }

    /* JADX INFO: renamed from: b */
    static synchronized void m143b() {
        f169f--;
        f169f = Math.max(0, f169f);
        if (f169f == 0 && f168e != null) {
            f168e.close();
            f168e = null;
        }
    }

    /* JADX INFO: renamed from: b */
    static void m144b(long j) {
        f168e.delete(C0073e.f108g, "_id<=? AND duration != 0 ", new String[]{String.valueOf(j)});
    }

    /* JADX INFO: renamed from: b */
    static void m145b(String str) {
        f168e.delete(C0072d.f100g, "session_id=?", new String[]{str});
    }

    /* JADX INFO: renamed from: c */
    static long m146c() {
        return DatabaseUtils.queryNumEntries(f168e, C0072d.f100g);
    }

    /* JADX INFO: renamed from: c */
    static void m147c(long j) {
        f168e.delete(C0082n.f156f, "_id<=? ", new String[]{String.valueOf(j)});
    }

    /* JADX INFO: renamed from: c */
    static void m148c(String str) {
        f168e.delete(C0073e.f108g, "session_id=? ", new String[]{str});
    }

    /* JADX INFO: renamed from: d */
    static List m149d() {
        Cursor cursorQuery;
        Cursor cursor = null;
        ArrayList arrayList = new ArrayList();
        try {
            cursorQuery = f168e.query(C0072d.f100g, C0072d.f101h, null, null, null, null, "_id", f166c);
            try {
                if (cursorQuery.moveToFirst()) {
                    while (!cursorQuery.isAfterLast()) {
                        C0070b c0070b = new C0070b();
                        c0070b.f76a = cursorQuery.getString(1);
                        c0070b.f77b = cursorQuery.getLong(2);
                        c0070b.f79g = cursorQuery.getInt(3);
                        if (cursorQuery.getInt(4) == 0) {
                            c0070b.f78c = 1;
                        } else {
                            c0070b.f78c = c0070b.f79g != 0 ? 3 : 2;
                        }
                        if (1 == c0070b.f78c) {
                            c0070b.f82j = cursorQuery.getInt(5);
                            if (c0070b.f82j < 0) {
                                c0070b.f82j = 0;
                            }
                            c0070b.f79g = c0070b.f82j / 1000;
                        }
                        c0070b.f83k = cursorQuery.getInt(6);
                        arrayList.add(c0070b);
                        cursorQuery.moveToNext();
                    }
                }
                if (cursorQuery != null) {
                    cursorQuery.close();
                }
            } catch (Exception e) {
                if (cursorQuery != null) {
                    cursorQuery.close();
                }
            } catch (Throwable th) {
                cursor = cursorQuery;
                th = th;
                if (cursor != null) {
                    cursor.close();
                }
                throw th;
            }
        } catch (Exception e2) {
            cursorQuery = null;
        } catch (Throwable th2) {
            th = th2;
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: d */
    static void m150d(long j) {
        f168e.delete(C0086r.f174e, "_id<=?", new String[]{String.valueOf(j)});
    }

    /* JADX INFO: renamed from: d */
    static void m151d(String str) {
        f168e.delete(C0082n.f156f, "session_id=? ", new String[]{str});
    }

    /* JADX INFO: renamed from: e */
    static long m152e(String str) throws Throwable {
        Cursor cursorRawQuery;
        Throwable th;
        Cursor cursor = null;
        try {
            cursorRawQuery = f168e.rawQuery("SELECT MAX(_id) from " + str, null);
            try {
                if (cursorRawQuery.moveToFirst() && !cursorRawQuery.isAfterLast()) {
                    long j = cursorRawQuery.getLong(0);
                    if (cursorRawQuery == null) {
                        return j;
                    }
                    cursorRawQuery.close();
                    return j;
                }
                if (cursorRawQuery != null) {
                    cursorRawQuery.close();
                }
            } catch (Exception e) {
                cursor = cursorRawQuery;
                if (cursor != null) {
                    cursor.close();
                }
            } catch (Throwable th2) {
                th = th2;
                if (cursorRawQuery != null) {
                    cursorRawQuery.close();
                }
                throw th;
            }
        } catch (Exception e2) {
        } catch (Throwable th3) {
            cursorRawQuery = null;
            th = th3;
        }
        return 0L;
    }

    /* JADX INFO: renamed from: e */
    static List m153e(long j) {
        ArrayList arrayList = new ArrayList();
        Cursor cursorRawQuery = null;
        try {
            try {
                cursorRawQuery = f168e.rawQuery("SELECT error_time,message,repeat, shorthashcode from error_report where _id<=?", new String[]{String.valueOf(j)});
                if (cursorRawQuery.moveToFirst()) {
                    while (!cursorRawQuery.isAfterLast()) {
                        C0068ag c0068ag = new C0068ag();
                        c0068ag.f60a = 3;
                        C0091w c0091w = new C0091w();
                        c0091w.f189a = cursorRawQuery.getLong(0);
                        c0091w.f192d = cursorRawQuery.getBlob(1);
                        c0091w.f190b = cursorRawQuery.getInt(2);
                        c0091w.f193e = cursorRawQuery.getString(3);
                        c0091w.f191c = C0089u.m207s();
                        c0068ag.f63d = c0091w;
                        arrayList.add(c0068ag);
                        cursorRawQuery.moveToNext();
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            return arrayList;
        } finally {
            if (cursorRawQuery != null) {
                cursorRawQuery.close();
            }
        }
    }
}
