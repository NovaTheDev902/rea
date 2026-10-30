package com.tencent.tmsecure.module.plugin;

import android.database.sqlite.SQLiteDatabase;

/* JADX INFO: loaded from: classes.dex */
public abstract class AbsPluginDatabaseFactor {

    /* JADX INFO: renamed from: a */
    private String f6192a;

    /* JADX INFO: renamed from: b */
    private int f6193b;

    public AbsPluginDatabaseFactor(String str, int i) {
        this.f6192a = str;
        this.f6193b = i;
    }

    public final String getName() {
        return this.f6192a;
    }

    public final int getVersion() {
        return this.f6193b;
    }

    public abstract void onCreate(IPluginDatabase iPluginDatabase, SQLiteDatabase sQLiteDatabase);

    public void onUpgrade(IPluginDatabase iPluginDatabase, SQLiteDatabase sQLiteDatabase, int i, int i2) {
    }
}
