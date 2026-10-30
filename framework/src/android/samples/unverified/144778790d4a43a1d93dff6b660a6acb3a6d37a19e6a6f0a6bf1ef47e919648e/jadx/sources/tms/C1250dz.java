package tms;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Handler;
import com.lenovo.lps.sus.p008c.C0092c;
import com.tencent.tmsecure.module.plugin.AbsPluginDatabaseFactor;
import com.tencent.tmsecure.module.plugin.IPluginDatabase;

/* JADX INFO: renamed from: tms.dz */
/* JADX INFO: loaded from: classes.dex */
final class C1250dz implements IPluginDatabase {

    /* JADX INFO: renamed from: a */
    private AbsPluginDatabaseFactor f7224a;

    /* JADX INFO: renamed from: b */
    private Handler f7225b;

    /* JADX INFO: renamed from: c */
    private SQLiteOpenHelper f7226c;

    /* JADX INFO: renamed from: d */
    private Runnable f7227d = new RunnableC1253eb(this);

    public C1250dz(Context context, AbsPluginDatabaseFactor absPluginDatabaseFactor) {
        this.f7224a = absPluginDatabaseFactor;
        this.f7225b = new Handler(context.getApplicationContext().getMainLooper());
        this.f7226c = new C1254ec(this, context, this.f7224a.getName(), this.f7224a.getVersion());
    }

    @Override // com.tencent.tmsecure.module.plugin.IPluginDatabase
    public final void close() {
        this.f7225b.removeCallbacks(this.f7227d);
        this.f7225b.postDelayed(this.f7227d, C0092c.f1328ap);
    }

    @Override // com.tencent.tmsecure.module.plugin.IPluginDatabase
    public final int delete(String str, String str2, String[] strArr) {
        int iDelete;
        synchronized (this.f7224a) {
            iDelete = this.f7226c.getWritableDatabase().delete(str, str2, strArr);
        }
        return iDelete;
    }

    @Override // com.tencent.tmsecure.module.plugin.IPluginDatabase
    public final boolean deleteTable(String str) {
        synchronized (this.f7224a) {
            this.f7226c.getWritableDatabase().delete(str, null, null);
        }
        return true;
    }

    @Override // com.tencent.tmsecure.module.plugin.IPluginDatabase
    public final void execSQL(String str) {
        synchronized (this.f7224a) {
            this.f7226c.getWritableDatabase().execSQL(str);
        }
    }

    @Override // com.tencent.tmsecure.module.plugin.IPluginDatabase
    public final void execTransaction(Runnable runnable) {
        synchronized (this.f7224a) {
            SQLiteDatabase writableDatabase = this.f7226c.getWritableDatabase();
            writableDatabase.beginTransaction();
            try {
                runnable.run();
                writableDatabase.setTransactionSuccessful();
                writableDatabase.endTransaction();
                close();
            } catch (Throwable th) {
                writableDatabase.endTransaction();
                close();
                throw th;
            }
        }
    }

    @Override // com.tencent.tmsecure.module.plugin.IPluginDatabase
    public final long insert(String str, String str2, ContentValues contentValues) {
        long jInsert;
        synchronized (this.f7224a) {
            jInsert = this.f7226c.getWritableDatabase().insert(str, str2, contentValues);
        }
        return jInsert;
    }

    @Override // com.tencent.tmsecure.module.plugin.IPluginDatabase
    public final Cursor query(String str, String[] strArr, String str2, String[] strArr2, String str3, String str4, String str5) {
        Cursor cursorQuery;
        synchronized (this.f7224a) {
            cursorQuery = this.f7226c.getWritableDatabase().query(str, strArr, str2, strArr2, str3, str4, str5);
        }
        return cursorQuery;
    }

    @Override // com.tencent.tmsecure.module.plugin.IPluginDatabase
    public final int update(String str, ContentValues contentValues, String str2, String[] strArr) {
        int iUpdate;
        synchronized (this.f7224a) {
            iUpdate = this.f7226c.getWritableDatabase().update(str, contentValues, str2, strArr);
        }
        return iUpdate;
    }
}
