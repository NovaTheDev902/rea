package tms;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/* JADX INFO: renamed from: tms.ec */
/* JADX INFO: loaded from: classes.dex */
final class C1254ec extends SQLiteOpenHelper {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1250dz f7232a;

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    C1254ec(C1250dz c1250dz, Context context, String str, int i) {
        super(context, str, (SQLiteDatabase.CursorFactory) null, i);
        this.f7232a = c1250dz;
    }

    @Override // android.database.sqlite.SQLiteOpenHelper
    public final void onCreate(SQLiteDatabase sQLiteDatabase) {
        this.f7232a.f7224a.onCreate(this.f7232a, sQLiteDatabase);
    }

    @Override // android.database.sqlite.SQLiteOpenHelper
    public final void onUpgrade(SQLiteDatabase sQLiteDatabase, int i, int i2) {
        this.f7232a.f7224a.onUpgrade(this.f7232a, sQLiteDatabase, i, i2);
    }
}
