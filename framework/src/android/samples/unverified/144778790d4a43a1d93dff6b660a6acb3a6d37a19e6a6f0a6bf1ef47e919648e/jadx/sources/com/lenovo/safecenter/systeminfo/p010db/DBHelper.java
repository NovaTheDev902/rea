package com.lenovo.safecenter.systeminfo.p010db;

import android.content.Context;
import android.content.res.Resources;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: loaded from: classes.dex */
public class DBHelper {
    public static final String DATABASE_FILENAME = "numinfo.db";
    public static final int DATABASE_VERSION = 1;

    /* JADX INFO: renamed from: a */
    private static final String f5594a = DBHelper.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static final String f5595b = "/data/data/" + Const.mContext.getPackageName() + "/databases";

    /* JADX INFO: renamed from: f */
    private static DBHelper f5596f = new DBHelper();

    /* JADX INFO: renamed from: c */
    private SQLiteDatabase f5597c = null;

    /* JADX INFO: renamed from: d */
    private String f5598d = DATABASE_FILENAME;

    /* JADX INFO: renamed from: e */
    private Context f5599e = Const.mContext;

    private DBHelper() {
    }

    public static DBHelper getInstance() {
        DBHelper dBHelper = f5596f;
        if (!(new File(m2299a()).exists())) {
            synchronized (f5596f) {
                DBHelper dBHelper2 = f5596f;
                m2300b();
            }
        }
        return f5596f;
    }

    public SQLiteDatabase getReadableDatabase() {
        try {
            SQLiteDatabase db = getWritableDatabase();
            return db;
        } catch (SQLiteException e) {
            Log.e(f5594a, e.getMessage());
            SQLiteDatabase db2 = SQLiteDatabase.openDatabase(m2299a(), null, 1);
            return db2;
        }
    }

    public synchronized SQLiteDatabase getWritableDatabase() {
        SQLiteDatabase db;
        if (this.f5598d == null) {
            db = SQLiteDatabase.create(null);
        } else {
            db = this.f5599e.openOrCreateDatabase(this.f5598d, 0, null);
        }
        if (db != null) {
            this.f5597c = db;
        }
        return db;
    }

    /* JADX INFO: renamed from: a */
    private static String m2299a() {
        return f5595b + '/' + DATABASE_FILENAME;
    }

    /* JADX INFO: renamed from: b */
    private static void m2300b() throws Throwable {
        InputStream inStream = null;
        FileOutputStream fileOutStream = null;
        String dbFilePath = m2299a();
        File dir = new File(f5595b);
        if (!dir.exists()) {
            dir.mkdir();
        }
        try {
            try {
                if (!new File(dbFilePath).exists()) {
                    Log.i(f5594a, "Coping database file ... ");
                    inStream = Const.mContext.getResources().openRawResource(C0415R.raw.numinfo);
                    FileOutputStream fileOutStream2 = new FileOutputStream(dbFilePath);
                    try {
                        byte[] buffer = new byte[8192];
                        while (true) {
                            int count = inStream.read(buffer);
                            if (count <= 0) {
                                break;
                            } else {
                                fileOutStream2.write(buffer, 0, count);
                            }
                        }
                        fileOutStream2.flush();
                        fileOutStream = fileOutStream2;
                    } catch (Resources.NotFoundException e) {
                        e = e;
                        fileOutStream = fileOutStream2;
                        Log.e(f5594a, e.getMessage());
                        if (fileOutStream != null) {
                            try {
                                fileOutStream.close();
                            } catch (IOException e2) {
                                Log.e(f5594a, e2.getMessage());
                            }
                        }
                        if (inStream != null) {
                            try {
                                inStream.close();
                                return;
                            } catch (IOException e3) {
                                Log.e(f5594a, e3.getMessage());
                                return;
                            }
                        }
                        return;
                    } catch (FileNotFoundException e4) {
                        e = e4;
                        fileOutStream = fileOutStream2;
                        Log.e(f5594a, e.getMessage());
                        if (fileOutStream != null) {
                            try {
                                fileOutStream.close();
                            } catch (IOException e5) {
                                Log.e(f5594a, e5.getMessage());
                            }
                        }
                        if (inStream != null) {
                            try {
                                inStream.close();
                                return;
                            } catch (IOException e6) {
                                Log.e(f5594a, e6.getMessage());
                                return;
                            }
                        }
                        return;
                    } catch (IOException e7) {
                        e = e7;
                        fileOutStream = fileOutStream2;
                        Log.e(f5594a, e.getMessage());
                        if (fileOutStream != null) {
                            try {
                                fileOutStream.close();
                            } catch (IOException e8) {
                                Log.e(f5594a, e8.getMessage());
                            }
                        }
                        if (inStream != null) {
                            try {
                                inStream.close();
                                return;
                            } catch (IOException e9) {
                                Log.e(f5594a, e9.getMessage());
                                return;
                            }
                        }
                        return;
                    } catch (Throwable th) {
                        th = th;
                        fileOutStream = fileOutStream2;
                        if (fileOutStream != null) {
                            try {
                                fileOutStream.close();
                            } catch (IOException e10) {
                                Log.e(f5594a, e10.getMessage());
                            }
                        }
                        if (inStream != null) {
                            try {
                                inStream.close();
                            } catch (IOException e11) {
                                Log.e(f5594a, e11.getMessage());
                            }
                        }
                        throw th;
                    }
                }
                if (fileOutStream != null) {
                    try {
                        fileOutStream.close();
                    } catch (IOException e12) {
                        Log.e(f5594a, e12.getMessage());
                    }
                }
                if (inStream != null) {
                    try {
                        inStream.close();
                    } catch (IOException e13) {
                        Log.e(f5594a, e13.getMessage());
                    }
                }
            } catch (Throwable th2) {
                th = th2;
            }
        } catch (Resources.NotFoundException e14) {
            e = e14;
        } catch (FileNotFoundException e15) {
            e = e15;
        } catch (IOException e16) {
            e = e16;
        }
    }
}
