package com.lenovo.safecenter.adapter;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;
import com.lenovo.safecenter.support.SafePaymentApp;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class DaoImpl implements Dao {

    /* JADX INFO: renamed from: a */
    DbAdapter f2870a;

    /* JADX INFO: renamed from: b */
    SQLiteDatabase f2871b;

    /* JADX INFO: renamed from: c */
    List<SafePaymentApp> f2872c;

    /* JADX INFO: renamed from: d */
    SafePaymentApp f2873d;

    public DaoImpl(DbAdapter adapter) {
        this.f2870a = adapter;
    }

    public void insterForNet(String app_name, String app_packagename, String app_md5) {
        this.f2873d = queryByPackageNameForSafeApp(app_packagename);
        try {
            if (this.f2873d == null) {
                if (this.f2871b == null || !this.f2871b.isOpen()) {
                    this.f2871b = this.f2870a.open();
                }
                ContentValues values = new ContentValues();
                values.put(DbAdapter.APP_NAME, app_name);
                values.put(DbAdapter.APP_PACKAGENAME, app_packagename);
                values.put(DbAdapter.APP_MD5, app_md5);
                values.put(DbAdapter.APP_FILE_SIZE, "");
                values.put(DbAdapter.APP_SHA1, "");
                this.f2871b.insert(DbAdapter.TABLE_NAME_SAFEAPP, null, values);
                this.f2870a.close();
                return;
            }
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            ContentValues values2 = new ContentValues();
            values2.put(DbAdapter.APP_MD5, this.f2873d.getApp_md5() + "," + app_md5);
            this.f2871b.update(DbAdapter.TABLE_NAME_SAFEAPP, values2, "app_packagename=?", new String[]{app_packagename});
            this.f2870a.close();
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public void insterForSafeApp(String app_name, String app_packagename, String app_md5, String app_file_size, String app_sha1) {
        try {
            if (queryByPackageNameForSafeApp(app_packagename) == null) {
                if (this.f2871b == null || !this.f2871b.isOpen()) {
                    this.f2871b = this.f2870a.open();
                }
                ContentValues values = new ContentValues();
                values.put(DbAdapter.APP_NAME, app_name);
                values.put(DbAdapter.APP_PACKAGENAME, app_packagename);
                values.put(DbAdapter.APP_MD5, app_md5);
                values.put(DbAdapter.APP_FILE_SIZE, app_file_size);
                values.put(DbAdapter.APP_SHA1, app_sha1);
                this.f2871b.insert(DbAdapter.TABLE_NAME_SAFEAPP, null, values);
                this.f2870a.close();
            }
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
        }
    }

    public void updataMD5ByPackageName(String app_packagename, String MD5) {
        try {
            if (queryByPackageNameForSafeApp(app_packagename) != null) {
                if (this.f2871b == null || !this.f2871b.isOpen()) {
                    this.f2871b = this.f2870a.open();
                }
                ContentValues values = new ContentValues();
                values.put(DbAdapter.APP_MD5, MD5);
                this.f2871b.update(DbAdapter.TABLE_NAME_SAFEAPP, values, "app_packagename=?", new String[]{app_packagename});
                this.f2870a.close();
            }
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public void deleByPackageNameForSafeApp(String app_packagename) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            this.f2871b.delete(DbAdapter.TABLE_NAME_SAFEAPP, "app_packagename=?", new String[]{app_packagename});
            this.f2870a.close();
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public List<SafePaymentApp> queryAllForSafeApp() {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            Cursor cursor = this.f2871b.query(DbAdapter.TABLE_NAME_SAFEAPP, null, null, null, null, null, null);
            this.f2872c = new ArrayList();
            for (int i = 0; i < cursor.getCount(); i++) {
                cursor.moveToNext();
                this.f2873d = new SafePaymentApp();
                this.f2873d.setId(cursor.getInt(cursor.getColumnIndexOrThrow("_id")));
                this.f2873d.setApp_name(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_NAME)));
                this.f2873d.setApp_md5(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_MD5)));
                this.f2873d.setApp_packagename(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PACKAGENAME)));
                this.f2873d.setApp_file_size(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_FILE_SIZE)));
                this.f2873d.setApp_sha1(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_SHA1)));
                this.f2872c.add(this.f2873d);
            }
            cursor.close();
            this.f2870a.close();
            return this.f2872c;
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
            return new ArrayList();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public SafePaymentApp queryByPackageNameForSafeApp(String app_packagename) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            Cursor cursor = this.f2871b.query(DbAdapter.TABLE_NAME_SAFEAPP, null, "app_packagename=? ", new String[]{app_packagename}, null, null, null);
            if (cursor.moveToNext()) {
                this.f2873d = new SafePaymentApp();
                this.f2873d.setId(cursor.getInt(cursor.getColumnIndexOrThrow("_id")));
                this.f2873d.setApp_name(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_NAME)));
                this.f2873d.setApp_md5(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_MD5)));
                this.f2873d.setApp_packagename(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PACKAGENAME)));
                this.f2873d.setApp_file_size(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_FILE_SIZE)));
                this.f2873d.setApp_sha1(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_SHA1)));
                cursor.close();
                this.f2870a.close();
                return this.f2873d;
            }
            cursor.close();
            this.f2870a.close();
            return null;
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
            return null;
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public SafePaymentApp queryByAppNameForSafeApp(String app_name) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            Cursor cursor = this.f2871b.query(DbAdapter.TABLE_NAME_SAFEAPP, null, " app_name=?", new String[]{app_name}, null, null, null);
            if (cursor.moveToNext()) {
                this.f2873d = new SafePaymentApp();
                this.f2873d.setId(cursor.getInt(cursor.getColumnIndexOrThrow("_id")));
                this.f2873d.setApp_name(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_NAME)));
                this.f2873d.setApp_md5(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_MD5)));
                this.f2873d.setApp_packagename(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PACKAGENAME)));
                this.f2873d.setApp_file_size(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_FILE_SIZE)));
                this.f2873d.setApp_sha1(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_SHA1)));
                cursor.close();
                this.f2870a.close();
                return this.f2873d;
            }
            cursor.close();
            this.f2870a.close();
            return null;
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
            return null;
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public void insterForUserApp(String app_name, String app_packagename, String app_md5, String app_file_size, String app_state, String app_protection) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            if (this.f2871b.isDbLockedByOtherThreads()) {
                this.f2870a.close();
                Log.e("ydp", "lock!!!");
                return;
            }
            ContentValues values = new ContentValues();
            values.put(DbAdapter.APP_NAME, app_name);
            values.put(DbAdapter.APP_PACKAGENAME, app_packagename);
            values.put(DbAdapter.APP_MD5, app_md5);
            values.put(DbAdapter.APP_FILE_SIZE, app_file_size);
            values.put(DbAdapter.APP_STATE, app_state);
            values.put(DbAdapter.APP_PROTECTION, app_protection);
            Cursor cursor = this.f2871b.query(DbAdapter.TABLE_NAME_USERAPP, null, "app_packagename=?", new String[]{app_packagename}, null, null, null);
            try {
                if (cursor.getCount() > 0) {
                    this.f2871b.update(DbAdapter.TABLE_NAME_USERAPP, values, "app_packagename=?", new String[]{app_packagename});
                } else {
                    this.f2871b.insert(DbAdapter.TABLE_NAME_USERAPP, null, values);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            cursor.close();
            this.f2870a.close();
        } catch (Exception e2) {
            Log.i("ydp", "db error:-->" + e2.getMessage());
            e2.getStackTrace();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public void deleByPackageNameForUserApp(String app_packagename) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            this.f2871b.delete(DbAdapter.TABLE_NAME_USERAPP, "app_packagename=?", new String[]{app_packagename});
            this.f2870a.close();
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public void updataProtectionByPackageName(String app_packagename, String app_protection) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            ContentValues values = new ContentValues();
            values.put(DbAdapter.APP_PROTECTION, app_protection);
            this.f2871b.update(DbAdapter.TABLE_NAME_USERAPP, values, "app_packagename=?", new String[]{app_packagename});
            this.f2870a.close();
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public void updataStateByPackageName(String app_packagename, String app_state) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            ContentValues values = new ContentValues();
            values.put(DbAdapter.APP_STATE, app_state);
            this.f2871b.update(DbAdapter.TABLE_NAME_USERAPP, values, "app_packagename=?", new String[]{app_packagename});
            this.f2870a.close();
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public void updataStateAll(String app_state) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            ContentValues values = new ContentValues();
            values.put(DbAdapter.APP_STATE, app_state);
            this.f2871b.update(DbAdapter.TABLE_NAME_USERAPP, values, null, null);
            this.f2870a.close();
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public List<SafePaymentApp> queryAllForUserApp() {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            Cursor cursor = this.f2871b.query(DbAdapter.TABLE_NAME_USERAPP, null, null, null, null, null, null);
            this.f2872c = new ArrayList();
            for (int i = 0; i < cursor.getCount(); i++) {
                cursor.moveToNext();
                this.f2873d = new SafePaymentApp();
                this.f2873d.setId(cursor.getInt(cursor.getColumnIndexOrThrow("_id")));
                this.f2873d.setApp_name(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_NAME)));
                this.f2873d.setApp_md5(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_MD5)));
                this.f2873d.setApp_packagename(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PACKAGENAME)));
                this.f2873d.setApp_file_size(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_FILE_SIZE)));
                this.f2873d.setApp_state(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_STATE)));
                this.f2873d.setApp_protection(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PROTECTION)));
                this.f2872c.add(this.f2873d);
            }
            cursor.close();
            this.f2870a.close();
            return this.f2872c;
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
            return new ArrayList();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public SafePaymentApp queryByPackageNameForUserApp(String app_packagename) {
        SafePaymentApp safePaymentApp;
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            if (this.f2871b.isDbLockedByOtherThreads()) {
                this.f2870a.close();
                Log.e("ydp", "lock!!!");
                return new SafePaymentApp();
            }
            Cursor cursor = this.f2871b.query(DbAdapter.TABLE_NAME_USERAPP, null, "app_packagename=? ", new String[]{app_packagename}, null, null, null);
            try {
                if (cursor.moveToNext()) {
                    this.f2873d = new SafePaymentApp();
                    this.f2873d.setId(cursor.getInt(cursor.getColumnIndexOrThrow("_id")));
                    this.f2873d.setApp_name(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_NAME)));
                    this.f2873d.setApp_md5(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_MD5)));
                    this.f2873d.setApp_packagename(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PACKAGENAME)));
                    this.f2873d.setApp_file_size(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_FILE_SIZE)));
                    this.f2873d.setApp_state(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_STATE)));
                    this.f2873d.setApp_protection(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PROTECTION)));
                    cursor.close();
                    this.f2870a.close();
                    safePaymentApp = this.f2873d;
                } else {
                    cursor.close();
                    this.f2870a.close();
                    safePaymentApp = null;
                }
                return safePaymentApp;
            } catch (IllegalStateException e) {
                Log.i("ydp", "db error:-->" + e.getMessage());
                e.getStackTrace();
                cursor.close();
                this.f2870a.close();
                return null;
            }
        } catch (Exception e2) {
            Log.i("ydp", "db error:-->" + e2.getMessage());
            e2.getStackTrace();
            return new SafePaymentApp();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public SafePaymentApp queryByAppNameForUserApp(String app_name) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            Cursor cursor = this.f2871b.query(DbAdapter.TABLE_NAME_USERAPP, null, " app_name LIKE ? OR ? LIKE '%'+app_name+'%'", new String[]{"%" + app_name + "%", app_name}, null, null, null);
            if (cursor.moveToNext()) {
                this.f2873d = new SafePaymentApp();
                this.f2873d.setId(cursor.getInt(cursor.getColumnIndexOrThrow("_id")));
                this.f2873d.setApp_name(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_NAME)));
                this.f2873d.setApp_md5(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_MD5)));
                this.f2873d.setApp_packagename(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PACKAGENAME)));
                this.f2873d.setApp_file_size(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_FILE_SIZE)));
                this.f2873d.setApp_state(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_STATE)));
                this.f2873d.setApp_protection(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PROTECTION)));
                cursor.close();
                this.f2870a.close();
                return this.f2873d;
            }
            cursor.close();
            this.f2870a.close();
            return null;
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
            return new SafePaymentApp();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public List<SafePaymentApp> queryByStateForUserApp(String app_state) {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            Cursor cursor = this.f2871b.query(DbAdapter.TABLE_NAME_USERAPP, null, "app_state=?", new String[]{app_state}, null, null, null);
            this.f2873d = new SafePaymentApp();
            this.f2872c = new ArrayList();
            for (int i = 0; i < cursor.getCount(); i++) {
                cursor.moveToNext();
                this.f2873d = new SafePaymentApp();
                this.f2873d.setId(cursor.getInt(cursor.getColumnIndexOrThrow("_id")));
                this.f2873d.setApp_name(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_NAME)));
                this.f2873d.setApp_md5(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_MD5)));
                this.f2873d.setApp_packagename(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PACKAGENAME)));
                this.f2873d.setApp_file_size(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_FILE_SIZE)));
                this.f2873d.setApp_state(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_STATE)));
                this.f2873d.setApp_protection(cursor.getString(cursor.getColumnIndexOrThrow(DbAdapter.APP_PROTECTION)));
                this.f2872c.add(this.f2873d);
            }
            cursor.close();
            this.f2870a.close();
            return this.f2872c;
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
            return new ArrayList();
        }
    }

    @Override // com.lenovo.safecenter.adapter.Dao
    public int queryCount() {
        try {
            if (this.f2871b == null || !this.f2871b.isOpen()) {
                this.f2871b = this.f2870a.open();
            }
            Cursor cursor = this.f2871b.query(DbAdapter.TABLE_NAME_SAFEAPP, null, null, null, null, null, null);
            int count = cursor.getCount();
            cursor.close();
            this.f2870a.close();
            return count;
        } catch (Exception e) {
            Log.i("ydp", "db error:-->" + e.getMessage());
            e.getStackTrace();
            return 99;
        }
    }
}
